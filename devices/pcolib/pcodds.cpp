#include "pcodds.h"

#include "modbus/genlib/generic.h"
#include "pcoregmap.h"

PcoDds::PcoDds(DeviceInterface *device)
{
    useConnection(device);
}

/// Отправляет данные частоты в DDS-канал.
/// Требуется вектор из двух слов (младшее и старшее).
void PcoDds::setDdsFreq(int chan, const QVector<quint16> &data)
{
    if (!device_)
        return;

    if (chan < 0 || chan >= pcoReg::DDS_FREQ.quantity)
        return;

    gen::regmap::Reg reg = pcoReg::DDS_FREQ[chan];
    device_->writeRequest(reg.addr, data);
}
