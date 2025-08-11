#pragma once

#include <QObject>
#include <QModbusDataUnit>
#include <QModbusRtuSerialClient>
#include <QModbusTcpClient>
#include <QDebug>
#include <QEventLoop>

#include "devices/deviceinterface.h"

/// Обработчик ответа на Modbus-запрос (выполняет коллбек и завершает задачу)
class ModbusReplyHandler : public QObject
{
    Q_OBJECT
public:
    explicit ModbusReplyHandler(QModbusReply *reply);

    /// Установить отладочную информацию (используется для логгирования)
    void setDebugData(const QString &devName, int addr, int size, const QString &cmd = QString());

    CallbackTask task;

private slots:
    void handler();

signals:
    /// Сигнал об успешной обработке
    void complete(const QVector<quint16> &data);

private:
    QModbusReply *reply = nullptr;

    QString debugMsgStart;
    std::string debugMsgStartStd;
    QEventLoop eventLoop;
};

/// Настройки подключения к Modbus-устройству (TCP или RTU)
class ModbusOption : public DeviceAddressOption
{
public:
    QString comPortName;
    int unitId = 0;
    QString ip;
    int port = 0;
};

/// Устройство на базе протокола Modbus (RTU/TCP)
class ModbusDevice : public QObject, public DeviceInterface
{
    Q_OBJECT

public:
    explicit ModbusDevice(QObject *parent = nullptr);
    ~ModbusDevice() override;

    // Реализация DeviceInterface
    CallbackTask *openConnection() override;
    bool closeConnection() override;
    bool isAvailable() override;
    CallbackTask *writeRequest(int startAddr, const QVector<quint16> &data) override;
    CallbackTask *readRequest(int startAddr, int quantity) override;
    bool setAddr(DeviceAddressOption *options) override;
    void setUnitId(quint16 unitid) override;

private slots:
    /// Слот: обработка смены состояния клиента (connected, disconnected и т.д.)
    void onModbusStateChanged(QModbusDevice::State state);

private:
    /// Создание клиента (RTU или TCP)
    void createModbusClient(bool isRtu);

private:
    std::unique_ptr<QModbusClient> modbus; ///< Указатель на клиента Modbus (RTU или TCP)

    QString addrStr; ///< Строка адреса для отладочного вывода
    QString unitStr; ///< Строка Unit ID для отладочного вывода
    ModbusOption options;

    QModbusReply *lastReply = nullptr; ///< Последний активный запрос

    CallbackTask connectTask;
    CallbackTask prepareRwTask;

    bool connectedErrorOccurred = false;
    bool connectedStateChanged = false;
};
