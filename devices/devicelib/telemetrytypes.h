#pragma once

#include <QDateTime>
#include <QString>

/**
 * @brief Запись телеметрии устройства
 */
struct TelemetryEntry
{
    QDateTime timestamp;
    int uptimeSec = 0;
    double temperatureFpga = 0.0;
    double temperatureBoard = 0.0;
    int pwrVoltage = 0;
    int pwrCurrent = 0;
    bool syncOk = false;
    int modbusRx = 0;
    int modbusTx = 0;
    int crcErrors = 0;
    int cmdErrors = 0;
};

/**
 * @brief Битовые флаги состояния устройства
 */
struct StatusFlagsEntry
{
    QDateTime timestamp;
    quint32 initStatus = 0;
    quint32 moduleStatus = 0;
    quint32 errorEvents = 0;
    QString ledFault;
    QString ledReady;
    QString ledSync;
};

/**
 * @brief Важное событие на устройстве
 */
struct EventEntry
{
    QDateTime timestamp;
    QString eventType;
    QString eventData;
};

/**
 * @brief Настройки калибровки для ПЦО/БЦДО
 */
struct CalibrationSettings
{
    QDateTime timestamp;
    int dac1_dc_i = 0, dac1_dc_q = 0;
    int dac2_dc_i = 0, dac2_dc_q = 0;
    int gain1_i = 0, gain1_q = 0;
    int gain2_i = 0, gain2_q = 0;
};
