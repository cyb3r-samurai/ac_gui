#pragma once

#include <QDateTime>
#include <QString>
#include <QVector>
#include <memory>

/**
 * @brief Базовое устройство в системе — DOS или PCO
 */
class Device
{
public:
    enum class Type { DOS, PCO };

    int id = -1;
    QString serialNumber;
    quint64 identifier = 0;
    Type type = Type::PCO;
    int modbusAddress = -1;
    QString ipAddress;
    QString firmwareVersion;

    virtual ~Device() = default;
};

/**
 * @brief Приемо-цифровой модуль (ПЦО)
 */
class PcoModule : public Device
{
public:
    PcoModule() { type = Type::PCO; }
};

/**
 * @brief Блок цифрового диаграммообразования (БЦДО)
 */
class DosUnit : public Device
{
public:
    QVector<std::shared_ptr<PcoModule>> connectedPcos;

    DosUnit() { type = Type::DOS; }
};
