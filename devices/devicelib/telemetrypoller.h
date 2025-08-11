#pragma once

#include <QObject>
#include <QTimer>
#include <memory>

class DeviceManager;
struct TelemetryEntry;
struct StatusFlagsEntry;
struct EventEntry;

/**
 * @brief Класс для асинхронного опроса устройств и сбора телеметрии.
 * Работает в отдельном потоке и уведомляет при получении новых данных.
 */
class TelemetryPoller : public QObject
{
    Q_OBJECT

public:
    explicit TelemetryPoller(std::shared_ptr<DeviceManager> manager, QObject *parent = nullptr);

    /// Запускает периодический опрос устройств
    void startPolling(int intervalMs = 1000);

signals:
    /// Сигнал при получении новой телеметрии
    void telemetryReceived(int deviceId, const TelemetryEntry &entry);

    /// Сигнал при получении нового статусного флага
    void statusReceived(int deviceId, const StatusFlagsEntry &entry);

    /// Сигнал при получении нового события
    void eventReceived(int deviceId, const EventEntry &entry);

private slots:
    /// Метод, вызываемый по таймеру — опрашивает устройства
    void pollDevices();

private:
    QTimer timer;
    std::shared_ptr<DeviceManager> deviceManager;
};
