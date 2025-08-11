#pragma once

#include "dosbeamformer.h"
#include "doscalgen.h"

/// Класс DosApi предоставляет единый интерфейс доступа к подсистемам ДОС:
/// - генератор калибровки (DosCalGen)
/// - формирователь луча (DosBeamformer)
///
/// Поддерживает установку подключения к устройству.
/// Устройство передаётся как небезопасный указатель (без владения).
class DosApi
{
public:
    DosApi();

    /// Конструктор, позволяющий сразу установить подключение при создании.
    explicit DosApi(DeviceInterface *device);

    /// Устанавливает устройство подключения для API и всех его подсистем.
    /// Если передан nullptr — соединение будет сброшено.
    void useConnection(DeviceInterface *device);

    /// Проверка: подключено ли устройство.
    bool isConnected() const;

    /// Возвращает текущее подключённое устройство.
    DeviceInterface *connection() const;

    // API должен быть уникальным — запрещаем копирование
    DosApi(const DosApi &) = delete;
    DosApi &operator=(const DosApi &) = delete;

    /// Подсистемы ДОС
    DosCalGen calGen;
    DosBeamformer beamformer;

private:
    DeviceInterface *device_ = nullptr; // Указатель на подключённое устройство
};
