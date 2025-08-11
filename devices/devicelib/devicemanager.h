#pragma once

#include <QMap>
#include <QString>
#include "QVector"
#include "devicemodel.h"
#include "telemetrycollector.h"
#include <memory>

/**
 * @brief Управляет коллекцией всех устройств, их состоянием и телеметрией
 */
class DeviceManager : public TelemetryCollector
{
public:
    DeviceManager() = default;

    std::shared_ptr<DosUnit> createDos(const QString &serial, const QString &ip);
    std::shared_ptr<PcoModule> createPco(const QString &serial, int modbusAddress);

    std::shared_ptr<DosUnit> getDosBySerial(const QString &serial);
    std::shared_ptr<PcoModule> getPcoByAddress(int address);
    const QVector<std::shared_ptr<DosUnit>> &allDosUnits() const;

    /// Получить телеметрию по ID устройства
    const QVector<TelemetryEntry> &getTelemetry(int deviceId) const;

    /// Получить статусные флаги по ID устройства
    const QVector<StatusFlagsEntry> &getStatus(int deviceId) const;

    /// Получить события по ID устройства
    const QVector<EventEntry> &getEvents(int deviceId) const;

    /// Получить текущие калибровочные параметры устройства
    CalibrationSettings getCalibration(int deviceId) const;

    // Реализация TelemetryCollector
    void submitTelemetry(int deviceId, const TelemetryEntry &entry) override;
    void submitStatus(int deviceId, const StatusFlagsEntry &entry) override;
    void submitEvent(int deviceId, const EventEntry &entry) override;

private:
    QVector<std::shared_ptr<DosUnit>> dosUnits;
    QMap<QString, std::shared_ptr<DosUnit>> dosMap;
    QMap<int, std::shared_ptr<PcoModule>> pcoMap;

    QMap<int, QVector<TelemetryEntry>> telemetryLogs;
    QMap<int, QVector<StatusFlagsEntry>> statusFlags;
    QMap<int, QVector<EventEntry>> deviceEvents;
    QMap<int, CalibrationSettings> calibrationSettings;
};
