#pragma once

#include "../deviceinterfaceuser.h"

/// Управление DDS-модулями (Direct Digital Synthesis)
class PcoDds : public DeviceInterfaceUser
{
public:
    /// Создаёт экземпляр и устанавливает подключение, если передано
    explicit PcoDds(DeviceInterface *device = nullptr);

    /// Устанавливает частоту DDS по подготовленным данным (2 слова: младшее и старшее)
    void setDdsFreq(int chan, const QVector<quint16> &data);
};
