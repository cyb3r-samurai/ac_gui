#include "pcobeamformer.h"

#include "modbus/genlib/generic.h"
#include "pcoregmap.h"

PcoBeamformer::PcoBeamformer(DeviceInterface *device)
{
    useConnection(device);
}

// Устанавливает коэффициенты формирователя луча для канала.
// Выполняет запись самих коэффициентов и установку флага "готово".
void PcoBeamformer::setBfCoe(int chan, const QVector<quint16> &coefs)
{
    if (!device_)
        return;

    const gen::regmap::Reg reg = pcoReg::BF_COE[chan];
    const gen::regmap::Reg regControl = pcoReg::BF_CONTROL;

    device_->writeRequest(reg.addr, coefs);

    // Установка бита "готово" для соответствующего канала
    const quint16 controlValue = static_cast<quint16>(1 << chan);
    device_->writeRequest(regControl.addr, {controlValue, 0});
}

// Устанавливает коэффициент масштабирования FIR-фильтра (1–32)
void PcoBeamformer::setScaleFirFactor(int scale)
{
    if (!device_)
        return;

    const quint16 value = static_cast<quint16>(scale);
    device_->writeRequest(pcoReg::BF_SCALE.addr, {value, 0});
}
