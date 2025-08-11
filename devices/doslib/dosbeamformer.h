#pragma once

#include "../deviceinterfaceuser.h"

/// Подсистема управления формированием луча (Beamformer).
/// Предоставляет интерфейс для установки коэффициентов.
class DosBeamformer : public DeviceInterfaceUser
{
public:
    explicit DosBeamformer(DeviceInterface *device = nullptr);

    /// Устанавливает коэффициенты формирования луча для указанного канала.
    /// Безопасно обрабатывает некорректные индексы и неподключённое устройство.
    void setDosBfCoe(int chan, const QVector<quint16> &coefs);
};
