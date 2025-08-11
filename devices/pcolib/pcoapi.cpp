#include "pcoapi.h"

/// Конструктор: при наличии указателя на устройство сразу подключаем его
PcoApi::PcoApi(DeviceInterface *device)
{
    useConnection(device);
}

/// Устанавливает общее подключение к устройству для всех подсистем ПЦО
void PcoApi::useConnection(DeviceInterface *device)
{
    if (!device)
        return;

    acqu.useConnection(device);
    beamformer.useConnection(device);
    dds.useConnection(device);
    calRec.useConnection(device);
    pcoSync.useConnection(device);
}
