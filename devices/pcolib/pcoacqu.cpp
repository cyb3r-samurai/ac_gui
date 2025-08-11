#include "pcoacqu.h"
#include "pcoregmap.h"

PcoAcqu::PcoAcqu() {}

/// Устанавливает длину записи данных (в словах base*size).
/// base — кратность одного семпла: 8, 16 или 32 (по умолчанию 32).
CallbackTask *PcoAcqu::setLength(int size, int base)
{
    if (!device_)
        return nullptr;

    const int totalWords = size * base;
    const int registerCount = (totalWords + 31) / 32; // округление вверх до кратного 32

    QVector<quint16> data = {static_cast<quint16>(registerCount), 0};
    return device_->writeRequest(pcoReg::ACQU_LENGTH.addr, data);
}

/// Назначает источник данных для указанного буфера (0–3).
/// source должен быть кодом из пространства имён Pco.
CallbackTask *PcoAcqu::setDataSource(int bufferNumber, int source)
{
    if (!device_)
        return nullptr;

    QVector<quint16> data = {static_cast<quint16>(source), 0};
    return device_->writeRequest(pcoReg::ACQU_CHSIGIDX[bufferNumber].addr, data);
}

/// Устанавливает флаг запуска сбора с опциональной задержкой и 1Гц-синхронизацией.
/// delay — в тактах (1 такт = 9.1 нс).
CallbackTask *PcoAcqu::setStartFlag(bool use1HzSync, uint delay)
{
    if (!device_)
        return nullptr;

    quint16 ctrlValue = 0;

    if (use1HzSync) {
        ctrlValue |= (1 << 1); // включить синхронизацию 1 Гц

        QVector<quint16> offset = {static_cast<quint16>(delay & 0xFFFF),
                                   static_cast<quint16>((delay >> 16) & 0xFFFF)};
        device_->writeRequest(pcoReg::ACQU_OFFSET.addr, offset);
    }

    ctrlValue |= 0x01; // бит запуска

    QVector<quint16> data = {ctrlValue, 0};
    return device_->writeRequest(pcoReg::ACQU_CONTROL.addr, data);
}

/// Запрашивает статус подсистемы сбора данных (готовность, ошибки).
CallbackTask *PcoAcqu::getStatus()
{
    if (!device_)
        return nullptr;

    return device_->readRequest(pcoReg::ACQU_STATUS.addr, pcoReg::ACQU_STATUS.size);
}

/// Считывает данные из указанного канала с заданным масштабом base (по умолчанию 32).
CallbackTask *PcoAcqu::getData(int size, int chan, int base)
{
    if (!device_)
        return nullptr;

    const int totalWords = size * base;
    const int registerCount = (totalWords + 31) / 32;

    return device_->readRequest(pcoReg::ACQU_CHDATA[chan].addr, registerCount);
}
