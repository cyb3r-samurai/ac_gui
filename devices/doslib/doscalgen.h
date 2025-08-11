#pragma once

#include "../deviceinterfaceuser.h"

/// Класс управления генератором калибровки ДОС.
/// Позволяет установить амплитуду сигнала, включать/выключать каналы,
/// а также управлять частотой гетеродина.
class DosCalGen : public DeviceInterfaceUser
{
public:
    DosCalGen();

    /// Устанавливает амплитуду генератора калибровки.
    CallbackTask *setAmpl(quint16 ampl);

    /// Включает или отключает каналы генерации сигнала.
    CallbackTask *setChnlOnOff(bool signal1_Hp_On, bool signal2_Vp_On);

    /// Считывает текущую частоту гетеродина (в Гц).
    CallbackTask *getGeterodyneFreqHz(quint32 &freq);

    /// Устанавливает частоту гетеродина (в Гц).
    CallbackTask *setGeterodyneFreqHz(const quint32 &freq);

private:
    CallbackTask retTask; // Локальный объект задачи, используемый при ошибках или простых ответах

    enum CalGenChannelMask : quint16 { CH_NONE = 0, CH_H_ONLY = 1, CH_V_ONLY = 2, CH_BOTH = 3 };
};
