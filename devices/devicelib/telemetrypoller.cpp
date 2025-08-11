#include "telemetrypoller.h"
#include "devicemanager.h"

TelemetryPoller::TelemetryPoller(std::shared_ptr<DeviceManager> manager, QObject* parent)
    : QObject(parent),
    deviceManager(std::move(manager))
{
    connect(&timer, &QTimer::timeout, this, &TelemetryPoller::pollDevices);
}

void TelemetryPoller::startPolling(int intervalMs)
{
    timer.setInterval(intervalMs);
    timer.start();
}

void TelemetryPoller::pollDevices()
{
    // Пока заглушка
}
