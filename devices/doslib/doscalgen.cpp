#include "doscalgen.h"
#include "../pcolib/pcoregmap.h"
#include "dosregmap.h"
#include "modbus/genlib/generic.h"

DosCalGen::DosCalGen() {}

/// Устанавливает амплитуду сигнала генератора.
CallbackTask *DosCalGen::setAmpl(quint16 ampl)
{
    retTask.reset();

    if (!device_) {
        retTask.emitFailure("Connection is absent.");
        return &retTask;
    }

    const gen::regmap::Reg reg = dosReg::CAL_GEN_GAIN;
    return device_->writeRequest(reg.addr, QVector<quint16>({ampl, 0}));
}

/// Управляет включением каналов генератора (H и V поляризации).
CallbackTask *DosCalGen::setChnlOnOff(bool signal1_Hp_On, bool signal2_Vp_On)
{
    retTask.reset();

    if (!device_) {
        retTask.emitFailure("Connection is absent.");
        return &retTask;
    }

    quint16 data = CH_NONE;
    if (signal2_Vp_On)
        data = signal1_Hp_On ? CH_BOTH : CH_V_ONLY;
    else if (signal1_Hp_On)
        data = CH_H_ONLY;

    const gen::regmap::Reg reg = dosReg::CAL_GEN_CONTROL;
    return device_->writeRequest(reg.addr, QVector<quint16>({data, 0}));
}

/// Считывает частоту гетеродина из устройства.
CallbackTask *DosCalGen::getGeterodyneFreqHz(quint32 &freq)
{
    retTask.reset();
    freq = 0;

    if (!device_) {
        retTask.emitFailure("Connection is absent.");
        return &retTask;
    }

    CallbackTask *devRet = device_->readRequest(dosReg::FREQ_GETERODYNE_HZ.addr,
                                                dosReg::FREQ_GETERODYNE_HZ.size);
    if (devRet->isFail())
        return devRet;

    const QVector<quint16> data = devRet->getData();
    if (data.size() < 2) {
        retTask.emitFailure("Invalid response size.");
        return &retTask;
    }

    freq = (static_cast<quint32>(data[1]) << 16) | data[0];
    return &retTask;
}

/// Записывает значение частоты гетеродина в устройство.
CallbackTask *DosCalGen::setGeterodyneFreqHz(const quint32 &freq)
{
    retTask.reset();

    if (!device_) {
        retTask.emitFailure("Connection is absent.");
        return &retTask;
    }

    QVector<quint16> data(2);
    data[0] = static_cast<quint16>(freq & 0xFFFF);
    data[1] = static_cast<quint16>((freq >> 16) & 0xFFFF);

    CallbackTask *devRet = device_->writeRequest(dosReg::FREQ_GETERODYNE_HZ.addr, data);
    if (devRet->isFail())
        return devRet;

    return &retTask;
}
