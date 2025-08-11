#pragma once

#include "../deviceinterfaceuser.h"

/// Пространство имён с константами источников данных для ПЦО
namespace Pco {
constexpr int ADC = 0 << 5;     ///< Аналого-цифровой преобразователь
constexpr int BF = 1 << 5;      ///< Формирователь луча (Beamformer)
constexpr int DDS_MIX = 2 << 5; ///< DDS-смеситель
constexpr int FIR_DEC = 3 << 5; ///< FIR-дециматор
constexpr int DDS = 4 << 5;     ///< DDS-сигнал
} // namespace Pco

/// Класс управления сбором данных из подсистемы ПЦО
class PcoAcqu : public DeviceInterfaceUser
{
public:
    PcoAcqu();

    /// Устанавливает длину записи (в отсчётах). base = 8, 16 или 32 (по умолчанию 32).
    CallbackTask *setLength(int size, int base = 32);

    /// Назначает источник данных для одного из буферов (0–3).
    CallbackTask *setDataSource(int bufferNumber, int source);

    /// Устанавливает флаг запуска сбора с опциональной задержкой.
    /// delay в единицах 9.1нс (1 такт), use1HzSync включает внешнюю синхронизацию.
    CallbackTask *setStartFlag(bool use1HzSync = false, uint delay = 0);

    /// Запрашивает статус сбора данных (готовность и ошибки).
    CallbackTask *getStatus();

    /// Считывает собранные данные (по каналу, размеру и базовому шагу).
    CallbackTask *getData(int size, int chan = 0, int base = 32);
};
