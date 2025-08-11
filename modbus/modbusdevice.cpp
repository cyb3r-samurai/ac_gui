#include "modbusdevice.h"

#include <QDebug>
#include <QEventLoop>
#include <QModbusRtuSerialClient>
#include <QModbusTcpClient>
#include <QNetworkProxy>
#include <QSerialPort>

// Настройки по умолчанию
constexpr int kTimeoutMs = 100;
constexpr int kRetries = 1;
constexpr int kBaudRate = 921600;

// Конструктор
ModbusDevice::ModbusDevice(QObject *parent)
    : QObject(parent)
{}

// Деструктор
ModbusDevice::~ModbusDevice()
{
    if (modbus && modbus->state() == QModbusDevice::ConnectedState)
        modbus->disconnectDevice();
}

// Создание клиента (RTU или TCP)
void ModbusDevice::createModbusClient(bool isRtu)
{
    modbus.reset(isRtu ? static_cast<QModbusClient *>(new QModbusRtuSerialClient(this))
                       : static_cast<QModbusClient *>(new QModbusTcpClient(this)));

    modbus->setTimeout(kTimeoutMs);
    modbus->setNumberOfRetries(kRetries);

    if (!connectedErrorOccurred) {
        connect(modbus.get(), &QModbusClient::errorOccurred, this, [this](QModbusDevice::Error) {
            qCritical() << "ModbusClient error:" << modbus->errorString();
        });
        connectedErrorOccurred = true;
    }

    if (!connectedStateChanged) {
        connect(modbus.get(),
                &QModbusClient::stateChanged,
                this,
                &ModbusDevice::onModbusStateChanged);
        connectedStateChanged = true;
    }
}

// Настройка параметров подключения
bool ModbusDevice::setAddr(DeviceAddressOption *base)
{
    auto *opt = base->to<ModbusOption *>();
    if (!opt)
        return false;

    if (opt->unitId < 0 || opt->unitId > 254) {
        qCritical() << "Incorrect unitId!";
        return false;
    }

    if (!opt->comPortName.isEmpty()) {
        // Простейшая проверка корректности COM-порта
        //if (opt->comPortName.contains(QRegExp(R"([-`~!@#$%^&*()_€”+=|:;<>«»,.?/{}'"\\[\]])"))) {
        //    qCritical() << "Incorrect comPortName!";
        //    return false;
       //}

        addrStr = opt->comPortName;
        createModbusClient(true); // RTU
    } else if (opt->port > 0) {
        addrStr = opt->ip + ":" + QString::number(opt->port);
        createModbusClient(false); // TCP
    } else {
        qCritical() << "Incomplete Modbus configuration.";
        return false;
    }

    unitStr = ":Unit" + QString::number(opt->unitId);
    options = *opt; // копирование всех полей

    return true;
}

// Установка Unit ID
void ModbusDevice::setUnitId(quint16 unitid)
{
    options.unitId = unitid;
    unitStr = ":Unit" + QString::number(unitid);
}

// Открытие соединения с устройством
CallbackTask *ModbusDevice::openConnection()
{
    if (!modbus) {
        connectTask.emitFailure("Modbus client is not initialized.");
        return &connectTask;
    }

    if (options.port > 0) {
        QNetworkProxyFactory::setUseSystemConfiguration(false);
        modbus->setConnectionParameter(QModbusDevice::NetworkAddressParameter, options.ip);
        modbus->setConnectionParameter(QModbusDevice::NetworkPortParameter, options.port);
    } else {
        modbus->setConnectionParameter(QModbusDevice::SerialPortNameParameter, options.comPortName);
        modbus->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
        modbus->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);
        modbus->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
        modbus->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, kBaudRate);
    }

    if (modbus->connectDevice())
        return &connectTask;

    connectTask.emitFailure("Failed to connect to" + addrStr);
    return &connectTask;
}

// Закрытие соединения
bool ModbusDevice::closeConnection()
{
    if (modbus)
        modbus->disconnectDevice();
    return true;
}

// Проверка доступности соединения
bool ModbusDevice::isAvailable()
{
    return modbus && modbus->state() == QModbusDevice::ConnectedState;
}

// Отправка запроса записи
CallbackTask *ModbusDevice::writeRequest(int addr, const QVector<quint16> &data)
{
    prepareRwTask.reset();

    if (!isAvailable()) {
        prepareRwTask.emitFailure("Device unavailable!");
        return &prepareRwTask;
    }

#ifdef QT_DEBUG
    qDebug() << "WRITE REQUEST:" << addrStr << unitStr << "0x" << QString::number(addr, 16)
             << "[" << data.size() * 2 << "]" << data;
#endif

    auto unit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, addr, data);
    lastReply = modbus->sendWriteRequest(unit, options.unitId);
    auto *handler = new ModbusReplyHandler(lastReply);
    handler->setDebugData(addrStr, addr, data.size(), "write");

    return &handler->task;
}

// Отправка запроса чтения
CallbackTask *ModbusDevice::readRequest(int addr, int quantity)
{
    prepareRwTask.reset();

    if (!isAvailable()) {
        prepareRwTask.emitFailure("Device unavailable!");
        return &prepareRwTask;
    }

#ifdef QT_DEBUG
    qDebug() << "READ REQUEST:" << addrStr << unitStr << "0x" << QString::number(addr, 16) << "["
             << quantity * 2 << "]";
#endif

    auto unit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters,
                                addr,
                                static_cast<quint16>(quantity));
    lastReply = modbus->sendReadRequest(unit, options.unitId);
    auto *handler = new ModbusReplyHandler(lastReply);
    handler->setDebugData(addrStr, addr, quantity, "read");

    return &handler->task;
}

// Обработка смены состояния соединения
void ModbusDevice::onModbusStateChanged(QModbusDevice::State state)
{
#ifdef QT_DEBUG
    qDebug() << "Modbus state changed:" << addrStr << "->" << state;
#endif

    static bool connecting = false;

    switch (state) {
    case QModbusDevice::UnconnectedState:
        if (connecting)
            connectTask.emitFailure("Connection failed:" + addrStr);
        connecting = false;
        break;

    case QModbusDevice::ConnectingState:
        connecting = true;
        break;

    case QModbusDevice::ConnectedState:
        if (connecting) {
            qInfo() << "Connected to" << addrStr;
            connectTask.emitSuccess({});
        }
        connecting = false;
        break;

    case QModbusDevice::ClosingState:
        break;
    }
}

// ------------------ ModbusReplyHandler ------------------

ModbusReplyHandler::ModbusReplyHandler(QModbusReply *reply)
    : QObject(nullptr)
    , reply(reply)
{
    if (!reply) {
        TxRxCounter::txErrCount++;
        qCritical() << "[ERROR] null reply";
        deleteLater();
        return;
    }

    TxRxCounter::txCount++;

    if (!reply->isFinished()) {
        auto conn = connect(reply, &QModbusReply::finished, this, &ModbusReplyHandler::handler);
        eventLoop.exec();
        disconnect(conn);
    } else {
        reply->deleteLater();
        deleteLater();
    }
}

void ModbusReplyHandler::setDebugData(const QString &devName, int addr, int size, const QString &cmd)
{
    debugMsgStart
        = QString("REPLY: %1 0x%2 [%3] %4").arg(devName).arg(addr, 0, 16).arg(size * 2).arg(cmd);
    debugMsgStartStd = debugMsgStart.toStdString();
}

void ModbusReplyHandler::handler()
{
    eventLoop.quit();

    if (reply->error() != QModbusDevice::NoError) {
        TxRxCounter::rxErrCount++;
        task.emitFailure("[ERROR] " + reply->errorString());
    } else {
        TxRxCounter::rxCount++;
        if (reply->rawResult().functionCode() == 0x03) {
            qDebug() << debugMsgStartStd.c_str() << "[OK]" << reply->result().values();
            task.emitSuccess(reply->result().values());
        } else {
            qDebug() << debugMsgStartStd.c_str() << "[OK]";
            task.emitSuccess({});
        }
    }

    reply->deleteLater();
    reply = nullptr;
    deleteLater();
}
