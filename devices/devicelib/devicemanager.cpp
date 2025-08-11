#include "devicemanager.h"

namespace {
int nextDeviceId = 1;
}

std::shared_ptr<DosUnit> DeviceManager::createDos(const QString &serial, const QString &ip)
{
    auto dos = std::make_shared<DosUnit>();
    dos->id = nextDeviceId++;
    dos->serialNumber = serial;
    dos->ipAddress = ip;

    dosMap[serial] = dos;
    dosUnits.append(dos);
    return dos;
}

std::shared_ptr<PcoModule> DeviceManager::createPco(const QString &serial, int modbusAddress)
{
    auto pco = std::make_shared<PcoModule>();
    pco->id = nextDeviceId++;
    pco->serialNumber = serial;
    pco->modbusAddress = modbusAddress;

    pcoMap[modbusAddress] = pco;
    return pco;
}

std::shared_ptr<DosUnit> DeviceManager::getDosBySerial(const QString &serial)
{
    return dosMap.value(serial, nullptr);
}

std::shared_ptr<PcoModule> DeviceManager::getPcoByAddress(int address)
{
    return pcoMap.value(address, nullptr);
}

const QVector<std::shared_ptr<DosUnit>> &DeviceManager::allDosUnits() const
{
    return dosUnits;
}

const QVector<TelemetryEntry> &DeviceManager::getTelemetry(int deviceId) const
{
    static const QVector<TelemetryEntry> empty;
    return telemetryLogs.contains(deviceId) ? telemetryLogs[deviceId] : empty;
}

const QVector<StatusFlagsEntry> &DeviceManager::getStatus(int deviceId) const
{
    static const QVector<StatusFlagsEntry> empty;
    return statusFlags.contains(deviceId) ? statusFlags[deviceId] : empty;
}

const QVector<EventEntry> &DeviceManager::getEvents(int deviceId) const
{
    static const QVector<EventEntry> empty;
    return deviceEvents.contains(deviceId) ? deviceEvents[deviceId] : empty;
}

CalibrationSettings DeviceManager::getCalibration(int deviceId) const
{
    return calibrationSettings.value(deviceId, CalibrationSettings{});
}

void DeviceManager::submitTelemetry(int deviceId, const TelemetryEntry &entry)
{
    telemetryLogs[deviceId].append(entry);
}

void DeviceManager::submitStatus(int deviceId, const StatusFlagsEntry &entry)
{
    statusFlags[deviceId].append(entry);
}

void DeviceManager::submitEvent(int deviceId, const EventEntry &entry)
{
    deviceEvents[deviceId].append(entry);
}
