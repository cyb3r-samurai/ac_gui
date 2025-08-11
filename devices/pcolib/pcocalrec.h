#pragma once

#include <QVector>
#include "../deviceinterfaceuser.h"
#include <complex>
#include <cstdint>

/// Данные одного канала, содержит 4 значения I и 4 значения Q
struct PcoCalRecDataCh
{
    int32_t i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    int32_t q1 = 0, q2 = 0, q3 = 0, q4 = 0;
};

/// Массив всех каналов
using PcoCalRecData = QVector<PcoCalRecDataCh>;

/// Трёхмерные координаты антенного элемента
struct AntElemCoords
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    constexpr AntElemCoords() = default;

    constexpr AntElemCoords(double x, double y, double z)
        : x(x)
        , y(y)
        , z(z)
    {}
};

/// Работа с модулем CAL_REC
class PcoCalRec : public DeviceInterfaceUser
{
public:
    PcoCalRec();

    // Получение данных измерений с устройства
    CallbackTask *getData(PcoCalRecData &calRecData, quint8 base = 32);

    // Вычисление коэффициентов по полученным данным
    CallbackTask *getCoe(const PcoCalRecData &calRecData,
                         QVector<qint16> &coef,
                         double geterodyneFreqHz);

    // Установка задержки
    CallbackTask *setDelay(quint16 delay);

    // Постоянные параметры
    static constexpr quint16 ChannelsNumber = 32;
    static constexpr AntElemCoords CalAntElementCoord{0.0, 0.0, 0.673};

private:
    CallbackTask retTask;
};
