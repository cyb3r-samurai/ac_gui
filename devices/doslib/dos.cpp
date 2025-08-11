#include "dos.h"
#include <QtGlobal>

DosApi::DosApi() {}

DosApi::DosApi(DeviceInterface *device)
{
    useConnection(device);
}

/// Устанавливает соединение и передаёт его во все подсистемы.
/// Если передан nullptr — соединение и в подсистемах будет сброшено.
void DosApi::useConnection(DeviceInterface *device)
{
    device_ = device;

    calGen.useConnection(device);
    beamformer.useConnection(device);
}

/// Возвращает true, если устройство подключено
bool DosApi::isConnected() const
{
    return device_ != nullptr;
}

/// Возвращает текущий указатель на устройство (может быть nullptr)
DeviceInterface *DosApi::connection() const
{
    return device_;
}
