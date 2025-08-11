#pragma once

#include <QDebug>
#include <QModbusDataUnit>
#include <QObject>
#include <QString>
#include <QVector>
#include <functional>

class Device;

// Асинхронная задача с поддержкой коллбеков
class CallbackTask
{
public:
    CallbackTask();

    // Устанавливает обработчик успешного завершения
    CallbackTask *onComplete(std::function<void(const QVector<quint16> &)> f);

    // Устанавливает обработчик ошибки
    CallbackTask *onFailed(std::function<void(const QString &)> f);

    // Сброс состояния (для повторного использования)
    void reset();

    // Сигнализирует об успешном завершении с результатом
    void emitSuccess(const QVector<quint16> &result);

    // Сигнализирует об ошибке с сообщением
    void emitFailure(const QString &error = "");

    // Возвращает полученные данные (если успешно)
    const QVector<quint16> &getData() const;

    // Возвращает строку ошибки
    const QString &getErrStr() const;

    // Признак ошибки
    bool isFail() const;

private:
    bool isCompleteNow = false;
    bool isFailNow = false;
    QVector<quint16> dataNow;
    QString errStr;

    std::function<void(const QVector<quint16> &)> completeTask;
    std::function<void(const QString &)> failTask;
};

// Абстрактный тип для параметров адресации устройства
class DeviceAddressOption
{
public:
    virtual ~DeviceAddressOption() {}

    // Преобразует тип к нужному (динамически)
    template<typename T>
    T to()
    {
        return dynamic_cast<T>(this);
    }
};

// Интерфейс для устройств Modbus
class DeviceInterface
{
public:
    virtual ~DeviceInterface() {}

    // Устанавливает параметры адресации
    virtual bool setAddr(DeviceAddressOption *options) = 0;

    // Устанавливает unit ID для запроса
    virtual void setUnitId(quint16 unitid) = 0;

    // Открывает соединение (асинхронно)
    virtual CallbackTask *openConnection() = 0;

    // Закрывает соединение
    virtual bool closeConnection() = 0;

    // Проверяет доступность устройства
    virtual bool isAvailable() = 0;

    // Отправляет запись данных (асинхронно)
    virtual CallbackTask *writeRequest(int startAddr, const QVector<quint16> &data) = 0;

    // Отправляет чтение данных (асинхронно)
    virtual CallbackTask *readRequest(int startAddr, int quantity) = 0;

    /// Назначает связанный объект модели устройства (например, PCO/DOS)
    void setModel(Device *device) { deviceModel_ = device; }

    /// Возвращает указатель на объект модели устройства
    Device *model() const { return deviceModel_; }

private:
    Device *deviceModel_ = nullptr; // Не владеем
};

// Глобальные счётчики передачи и ошибок
class TxRxCounter
{
public:
    static void reset() { txCount = rxCount = txErrCount = rxErrCount = 0; }

    static int txCount;    // Успешные передачи
    static int rxCount;    // Успешные приёмы
    static int txErrCount; // Ошибки передачи
    static int rxErrCount; // Ошибки приёма
};

// Обёртка: разделение длинных запросов на сегменты
class InterfaceRequestSeparator : public DeviceInterface
{
public:
    InterfaceRequestSeparator(DeviceInterface *device, int dataSizeLimit);

    bool setAddr(DeviceAddressOption *options) override;
    void setUnitId(quint16 unitid) override;
    CallbackTask *openConnection() override;
    bool closeConnection() override;
    bool isAvailable() override;
    CallbackTask *writeRequest(int startAddr, const QVector<quint16> &data) override;
    CallbackTask *readRequest(int startAddr, int quantity) override;

private:
    DeviceInterface *device = nullptr;
    int dataSizeLimit = 0;
};

// Задача: выполнение сегментированных запросов
class RequestSeparatorTask : public QObject
{
    Q_OBJECT

public:
    explicit RequestSeparatorTask(DeviceInterface *device, int startAddr, int segmentSize);

    // Асинхронная запись по сегментам
    CallbackTask *startWrite(const QVector<quint16> &data);

    // Асинхронное чтение по сегментам
    CallbackTask *startRead(int quantity);

private slots:
    void tryComplete();

private:
    DeviceInterface *device = nullptr;
    int startAddr = 0;
    int segmentSize = 0;
    int remainingSegments = 0;
    bool anySegmentFailed = false;

    QVector<quint16> data;
    CallbackTask task;
};
