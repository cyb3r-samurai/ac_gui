#include "deviceinterface.h"

// ==============================
// Глобальные счётчики передачи
// ==============================

int TxRxCounter::txCount = 0;
int TxRxCounter::rxCount = 0;
int TxRxCounter::txErrCount = 0;
int TxRxCounter::rxErrCount = 0;

// ==============================
// CallbackTask — Асинхронный результат
// ==============================

CallbackTask::CallbackTask()
{
    reset();
}

// Сброс текущего состояния и установка обработчиков по умолчанию
void CallbackTask::reset()
{
    isCompleteNow = false;
    isFailNow = false;
    dataNow.clear();
    errStr.clear();

    completeTask = [this](const QVector<quint16> &result) {
        isCompleteNow = true;
        dataNow = result;
    };

    failTask = [this](const QString &error) {
        isFailNow = true;
        errStr = error.isEmpty() ? QStringLiteral("Unknown error.") : error;
    };
}

// Установка обработчика успешного завершения
CallbackTask *CallbackTask::onComplete(std::function<void(const QVector<quint16> &)> f)
{
    if (isCompleteNow) {
        f(dataNow);
        isCompleteNow = false;
    } else {
        completeTask = f;
    }
    return this;
}

// Установка обработчика ошибки
CallbackTask *CallbackTask::onFailed(std::function<void(const QString &)> f)
{
    if (isFailNow) {
        f(errStr);
        isFailNow = false;
    } else {
        failTask = f;
    }
    return this;
}

// Вызывает обработчик успешного завершения
void CallbackTask::emitSuccess(const QVector<quint16> &result)
{
    if (completeTask)
        completeTask(result);
}

// Вызывает обработчик ошибки
void CallbackTask::emitFailure(const QString &error)
{
    if (failTask) {
        qWarning() << "CallbackTask failure:" << error;
        failTask(error);
    }
}

// Возвращает сохранённый результат
const QVector<quint16> &CallbackTask::getData() const
{
    return dataNow;
}

// Возвращает сохранённую строку ошибки
const QString &CallbackTask::getErrStr() const
{
    return errStr;
}

// Возвращает true, если задача завершилась ошибкой
bool CallbackTask::isFail() const
{
    return isFailNow;
}

// ==============================
// InterfaceRequestSeparator — Обёртка, разбивающая запросы
// ==============================

InterfaceRequestSeparator::InterfaceRequestSeparator(DeviceInterface *device, int dataSizeLimit)
    : device(device)
    , dataSizeLimit(dataSizeLimit)
{}

// Проксирование вызовов к базовому интерфейсу
bool InterfaceRequestSeparator::setAddr(DeviceAddressOption *options)
{
    return device ? device->setAddr(options) : false;
}

void InterfaceRequestSeparator::setUnitId(quint16 unitid)
{
    if (device)
        device->setUnitId(unitid);
}

CallbackTask *InterfaceRequestSeparator::openConnection()
{
    return device ? device->openConnection() : nullptr;
}

bool InterfaceRequestSeparator::closeConnection()
{
    return device ? device->closeConnection() : false;
}

bool InterfaceRequestSeparator::isAvailable()
{
    return device && device->isAvailable();
}

// Разбивает запись на части, если превышает лимит
CallbackTask *InterfaceRequestSeparator::writeRequest(int startAddr, const QVector<quint16> &data)
{
    if (!device) {
        qWarning() << "writeRequest: device is nullptr!";
        return nullptr;
    }

    if (data.size() > dataSizeLimit) {
        auto *task = new RequestSeparatorTask(device, startAddr, dataSizeLimit);
        return task->startWrite(data);
    }
    return device->writeRequest(startAddr, data);
}

// Разбивает чтение на части, если превышает лимит
CallbackTask *InterfaceRequestSeparator::readRequest(int startAddr, int quantity)
{
    if (!device) {
        qWarning() << "readRequest: device is nullptr!";
        return nullptr;
    }

    if (quantity > dataSizeLimit) {
        auto *task = new RequestSeparatorTask(device, startAddr, dataSizeLimit);
        return task->startRead(quantity);
    }
    return device->readRequest(startAddr, quantity);
}

// ==============================
// RequestSeparatorTask — Многосегментные запросы
// ==============================

RequestSeparatorTask::RequestSeparatorTask(DeviceInterface *device, int startAddr, int segmentSize)
    : QObject(nullptr)
    , device(device)
    , startAddr(startAddr)
    , segmentSize(segmentSize)
{}

// Запускает запись данных в нескольких сегментах
CallbackTask *RequestSeparatorTask::startWrite(const QVector<quint16> &data)
{
    int addr = startAddr;
    remainingSegments = (data.size() + segmentSize - 1) / segmentSize;

    for (int i = 0; i < remainingSegments; ++i) {
        QVector<quint16> segment = data.mid(i * segmentSize, segmentSize);

        // Отправка одного сегмента на запись
        device->writeRequest(addr, segment)
            ->onComplete([this](const QVector<quint16> &) {
                // Сегмент успешно записан
                tryComplete();
            })
            ->onFailed([this](const QString &) {
                // Ошибка при записи сегмента
                anySegmentFailed = true;
                tryComplete();
            });

        addr += segmentSize;
    }

    return &task;
}

// Запускает чтение данных в нескольких сегментах
CallbackTask *RequestSeparatorTask::startRead(int quantity)
{
    int addr = startAddr;
    data.reserve(quantity);
    remainingSegments = (quantity + segmentSize - 1) / segmentSize;

    for (int i = 0; i < remainingSegments; ++i) {
        int count = (i == remainingSegments - 1) ? (quantity - i * segmentSize) : segmentSize;

        // Отправка одного сегмента на чтение
        device->readRequest(addr, count)
            ->onComplete([this](const QVector<quint16> &result) {
                data += result; // Добавление данных
                tryComplete();
            })
            ->onFailed([this](const QString &) {
                anySegmentFailed = true;
                tryComplete();
            });

        addr += segmentSize;
    }

    return &task;
}

// Проверка завершения всех сегментов
void RequestSeparatorTask::tryComplete()
{
    --remainingSegments;

    if (remainingSegments == 0) {
        if (anySegmentFailed) {
            task.emitFailure();
        } else {
            task.emitSuccess(data);
        }
        deleteLater();
    }
}
