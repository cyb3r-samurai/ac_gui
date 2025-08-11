#pragma once

#include "../deviceinterfaceuser.h"

/// Режимы синхронизации ПЦО
enum PcoSyncMode : quint16 {
    SYNC_MODE_AUTO = 0, ///< Автоматический режим (TODO: проверить после обновления ПЦО)
    // Можно добавить другие режимы, если появятся
};

/// Управление синхронизацией ПЦО
class PcoSync : public DeviceInterfaceUser
{
public:
    PcoSync();

    /// Устанавливает режим синхронизации.
    CallbackTask *setSyncMode(PcoSyncMode mode);

private:
    CallbackTask retTask;
};
