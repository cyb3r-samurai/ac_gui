#pragma once

#include "deviceinterface.h"
#include "devicelib/telemetrycollector.h"
#include "../apd/apd.h"

/**
 * @brief Интерфейсный базовый класс для компонентов, работающих с DeviceInterface.
 *
 * - Позволяет назначить подключение к устройству.
 * - Поддерживает привязку к системе сбора телеметрии.
 */
class DeviceInterfaceUser
{
public:
    /// Инлайн-конструктор с опциональной инициализацией устройства
    explicit DeviceInterfaceUser(DeviceInterface *device = nullptr)
        : device_(device)
    {}

    /// Установить новое устройство (не передаёт владение)
    virtual void useConnection(DeviceInterface *device) { device_ = device; }

    /// Получить текущее подключённое устройство
    DeviceInterface *connection() const { return device_; }

    /// Установить сборщик телеметрии
    virtual void setTelemetryCollector(TelemetryCollector *collector) { collector_ = collector; }

protected:
    DeviceInterface *device_ = nullptr;
    TelemetryCollector *collector_ = nullptr;
};
