#pragma once

#include "../deviceinterface.h"
#include "pcoacqu.h"
#include "pcobeamformer.h"
#include "pcocalrec.h"
#include "pcodds.h"
#include "pcosync.h"

/// Высокоуровневый API для управления модулями ПЦО
class PcoApi
{
public:
    /// Конструктор с необязательным подключением к устройству
    explicit PcoApi(DeviceInterface *device = nullptr);

    /// Назначить подключение к устройству
    void useConnection(DeviceInterface *device);

    /// Модуль управления захватом данных
    PcoAcqu acqu;

    /// Модуль формирования луча
    PcoBeamformer beamformer;

    /// DDS-генератор
    PcoDds dds;

    /// Модуль калибровки (CAL_REC)
    PcoCalRec calRec;

    /// Модуль синхронизации
    PcoSync pcoSync;
};
