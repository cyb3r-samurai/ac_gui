#include "pcosync.h"
#include "modbus/genlib/generic.h"
#include "pcoregmap.h"

// Конструктор по умолчанию
PcoSync::PcoSync() = default;

/// Устанавливает режим синхронизации устройства.
/// Возвращает CallbackTask с результатом запроса.
CallbackTask *PcoSync::setSyncMode(PcoSyncMode mode)
{
    retTask.reset();

    // Проверка диапазона допустимых значений (0–3)
    if (mode > 3) {
        retTask.emitFailure("Mode value > 3.");
        return &retTask;
    }

    // Проверка подключения к устройству
    if (!device_) {
        retTask.emitFailure("Connection is absent.");
        return &retTask;
    }

    // Отправка команды установки режима
    const gen::regmap::Reg reg = pcoReg::SYNC;
    return device_->writeRequest(reg.addr, QVector<quint16>{static_cast<quint16>(mode), 0});
}
