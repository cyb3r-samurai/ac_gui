#pragma once

#include <QString>
#include "deviceinterface.h"
#include "modbus/modbusdevice.h"

/// Фабрика устройств. Предоставляет статические методы для создания подключений.
class DeviceFactory
{
public:

    /// Создание устройства по протоколу Modbus RTU (через COM-порт)
    static DeviceInterface *createModbusRtuDevice(int unitId, const QString &port);

    /// Создание устройства по протоколу Modbus TCP
    static DeviceInterface *createModbusTcpDevice(int unitId, const QString &ip, int port = 502);
};
