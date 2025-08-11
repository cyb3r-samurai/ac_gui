#pragma once

#include "../deviceinterfaceuser.h"
#include <complex>

/// Класс управления формирователем луча ПЦО.
/// Позволяет загружать коэффициенты и устанавливать масштаб FIR-фильтра.
class PcoBeamformer : public DeviceInterfaceUser
{
public:
    /// Конструктор с возможностью передачи устройства сразу
    explicit PcoBeamformer(DeviceInterface *device = nullptr);

    /// Устанавливает коэффициенты формирователя луча для указанного канала.
    /// coefs — массив из 32 комплексных коэффициентов, упакованных в Modbus-совместимый формат (quint16).
    void setBfCoe(int chan, const QVector<quint16> &coefs);

    /// Устанавливает коэффициент масштабирования FIR-фильтра (1–32).
    void setScaleFirFactor(int scale);
};
