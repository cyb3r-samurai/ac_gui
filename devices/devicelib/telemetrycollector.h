#pragma once

#include "telemetrytypes.h"

/// Интерфейс сбора телеметрии с устройств
class TelemetryCollector
{
public:
    virtual ~TelemetryCollector() = default;

    /// Сохранить новый срез телеметрии
    virtual void submitTelemetry(int deviceId, const TelemetryEntry &entry) = 0;

    /// Сохранить новый статус
    virtual void submitStatus(int deviceId, const StatusFlagsEntry &entry) = 0;

    /// Сохранить событие
    virtual void submitEvent(int deviceId, const EventEntry &entry) = 0;
};
