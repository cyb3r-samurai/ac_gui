#pragma once

// Карта Modbus-регистров модуля ДОС (Диаграммообразующая схема)
// Отображает регистры прошивки и AXI-модулей в адресное пространство Modbus

#include "modbus/genlib/generic.h"
#include "modbus/modbus_literals.h"

namespace dosReg {

using gen::regmap::Reg;
using gen::regmap::RegV;

// ===================================================
// Основные Modbus-регистры (0x0000 — 0x0053)
// ===================================================

// --- Версии и идентификация ---
const Reg FW_VERSION_PROC      (0x0000, 1);
const Reg FW_VERSION_FPGA      (0x0001, 1);
const Reg SERIAL_NUMBER        (0x0002, 5);  // char[10]
const Reg IDENTIFIER           (0x0007, 4);  // uint64

// --- Температура ---
const Reg TEMP_FPGA            (0x000B, 1);  // °C
const Reg TEMP_BOARD           (0x000C, 1);  // °C

// --- Питание и состояния портов ---
const Reg MODULE_PORTS_STATE   (0x0030, 2);  // Состояние портов (битовая маска)
const Reg PWR_PG_STATES        (0x0032, 2);  // Power Good (битовая маска)
const Reg PWR_CH_ENABLE        (0x0034, 2);  // Включение каналов питания
const Reg PWR_CURRENTS_MIN     (0x0036, 1);  // Минимальный ток, мА
const Reg PWR_CURRENTS_MAX     (0x0037, 1);  // Максимальный ток, мА
const RegV PWR_CURRENTS        (0x0038, 1, 20);  // Токи по 20 каналам, мА

// --- Сеть и частота ---
const Reg FREQ_GETERODYNE_HZ   (0x004C, 1_axisz2mod);  // Гетеродин, Гц (uint32)
const Reg IP_ADDRESS           (0x004E, 2);            // IP-адрес (uint8[4])
const Reg NET_MASK             (0x0050, 2);            // Маска подсети (uint8[4])

// --- Диагностика питания ---
const Reg PWR_BUS_VOLTAGE      (0x0052, 1);  // Напряжение шины, мВ
const Reg PWR_DOS_CURRENT      (0x0053, 1);  // Ток потребления ДОС, мА

// ===================================================
// AXI-модули, отображённые в адресное пространство Modbus
// ===================================================

const Reg SYNC                 (0x0100, 256_bytes2mod);      // Синхронизация
const Reg BF                   (0x0200, 256_bytes2mod);      // BeamFormer
const Reg DEMUX                (0x0300, 256_bytes2mod);      // Демультиплексор
const Reg CAL_GEN              (0x0400, 256_bytes2mod);      // Генератор калибровки
const Reg BUF_CTR              (0x0500, 256_bytes2mod);      // Управление буфером
const Reg USBVIEWER            (0x0600, 256_bytes2mod);      // USB мониторинг
const Reg BUF_DATA             (0x8000, 32768_bytes2mod);    // Буфер данных, 32KB

// ===================================================
// AXI: CAL_GEN
// ===================================================

const Reg CAL_GEN_CONTROL      (CAL_GEN + 0x0000_axi2mod, 1_axisz2mod);  // Управление генератором
const Reg CAL_GEN_GAIN         (CAL_GEN + 0x0008_axi2mod, 1_axisz2mod);  // Коэффициент усиления

// ===================================================
// AXI: BEAMFORMER (BF)
// ===================================================

const Reg BF_STATUS            (BF + 0x0004_axi2mod, 1_axisz2mod);       // Статус: биты 0–5 — переполнение
const RegV BF_COE              (BF + 0x0010_axi2mod, 1_axisz2mod, 6, 0x4_axi2mod);  // Коэффициенты 6 каналов

// Именованные каналы для удобства
const Reg BF1_COE = BF_COE[0];
const Reg BF2_COE = BF_COE[1];
const Reg BF3_COE = BF_COE[2];
const Reg BF4_COE = BF_COE[3];
const Reg BF5_COE = BF_COE[4];
const Reg BF6_COE = BF_COE[5];

// ===================================================
// AXI: BUF_CTR — управление кольцевым буфером
// ===================================================

const Reg BUF_CTR_CTRL         (BUF_CTR + 0x0000_axi2mod, 1_axisz2mod);  // Старт/сброс
const Reg BUF_CTR_STATUS       (BUF_CTR + 0x0004_axi2mod, 1_axisz2mod);  // Статус: готовность/ошибки
const Reg BUF_CTR_WRITE_PTR    (BUF_CTR + 0x0008_axi2mod, 1_axisz2mod);  // Указатель записи
const Reg BUF_CTR_READ_PTR     (BUF_CTR + 0x000C_axi2mod, 1_axisz2mod);  // Указатель чтения

} // namespace dosReg
