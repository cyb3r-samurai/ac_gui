#include "dosbeamformer.h"
#include <QDebug>
#include "dosregmap.h"
#include "modbus/genlib/generic.h"

/// Конструктор — может сразу принять подключённое устройство.
DosBeamformer::DosBeamformer(DeviceInterface *device)
{
    useConnection(device);
}

/// Устанавливает коэффициенты формирования луча для указанного канала.
void DosBeamformer::setDosBfCoe(int chan, const QVector<quint16> &coefs)
{
    if (!device_) {
        qWarning() << "DosBeamformer: device not connected!";
        return;
    }

    if (chan < 0 || chan >= dosReg::BF_COE.quantity) {
        qWarning() << "DosBeamformer: invalid channel index:" << chan;
        return;
    }

    const gen::regmap::Reg reg = dosReg::BF_COE[chan];
    device_->writeRequest(reg.addr, coefs);
}
