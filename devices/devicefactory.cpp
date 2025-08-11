#include "devicefactory.h"

/// Создание устройства с моделью данных из файла/// Создание Modbus RTU-устройства (через COM-порт)
DeviceInterface *DeviceFactory::createModbusRtuDevice(int unitId, const QString &port)
{
    auto *modbus = new ModbusDevice();

    // Обертка, разделяющая большие запросы на части
    auto *wrappedDev = new InterfaceRequestSeparator(modbus, 124);

    ModbusOption option;
    option.unitId = unitId;
    option.comPortName = port;

    wrappedDev->setAddr(&option);
    return wrappedDev;
}

/// Создание Modbus TCP-устройства (по IP и порту)
DeviceInterface *DeviceFactory::createModbusTcpDevice(int unitId, const QString &ip, int port)
{
    auto *modbus = new ModbusDevice();

    // Обертка, разделяющая большие запросы на части
    auto *wrappedDev = new InterfaceRequestSeparator(modbus, 124);

    ModbusOption option;
    option.unitId = unitId;
    option.ip = ip;
    option.port = port;

    wrappedDev->setAddr(&option);
    return wrappedDev;
}
