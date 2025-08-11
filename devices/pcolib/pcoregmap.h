#pragma once

// Карта Modbus-регистров модуля ПЦО (Плата цифровой обработки)
// Включает определение Reg/RegV, структуры для работы с Modbus/AXI и битовые поля

#include <QVector>
#include <cstdint>
#include "modbus/genlib/generic.h"
#include "modbus/modbus_literals.h"

namespace pcoReg {

using gen::regmap::Reg;
using gen::regmap::RegV;

// ===================================================
// Основные регистры (0x0000 — ...)
// ===================================================

// --- Версии и идентификация ---
const Reg FW_VERSION_PROC   {0x0000, 1};
const Reg FW_VERSION_FPGA   {0x0001, 1};
const Reg SERIAL_NUMBER     {0x0002, 5};  // char[10]
const Reg IDENTIFIER        {0x0007, 4};  // uint64

// --- Температура ---
const Reg TEMP_FPGA         {0x000B, 1};  // °C
const Reg TEMP_BOARD        {0x000C, 1};  // °C

// ===================================================
// AXI-модули (в Modbus-пространстве)
// ===================================================

const Reg SYNC              {0x0100, 256_bytes2mod};
const Reg ADC               {0x0200, 512_bytes2mod};
const Reg BF                {0x0400, 2048_bytes2mod};
const Reg DDS               {0x0C00, 32_bytes2mod};
const Reg MUX               {0x0D00, 256_bytes2mod};
const Reg CAL_REC           {0x0E00, 2048_bytes2mod};
const Reg ACQU_CTRL         {0x1600, 256_bytes2mod};
const Reg USBVIEWER         {0x1700, 256_bytes2mod};
const Reg ACQU_DATA         {0x8000, 32768_bytes2mod};

// ===================================================
// AXI: BEAMFORMER
// ===================================================

const Reg BF_CONTROL        {BF + 0x0000_axi2mod, 1_axisz2mod};  // Управление
const Reg BF_STATUS         {BF + 0x0004_axi2mod, 1_axisz2mod};  // Статус
const Reg BF_SCALE          {BF + 0x0010_axi2mod, 1_axisz2mod};  // Масштабирование FIR

const Reg BF1_COE           {BF + 0x0100_axi2mod, 32_axisz2mod};
const RegV BF_COE           {BF1_COE.addr, 32_axisz2mod, 6, 0x80_axi2mod};

const Reg BF1_BFCOE         {BF + 0x0400_axi2mod, 32_axisz2mod};
const RegV BF_BFCOE         {BF1_BFCOE.addr, 32_axisz2mod, 6, 0x80_axi2mod};

// ===================================================
// AXI: DDS
// ===================================================

const RegV DDS_FREQ         {DDS + 0x0000, 2, 6, 2};  // Частоты DDS, по 32 бита

// ===================================================
// AXI: ACQU_CTRL
// ===================================================

const Reg ACQU_CONTROL      {ACQU_CTRL + 0x0000, 1_axisz2mod};
const Reg ACQU_STATUS       {ACQU_CTRL + 0x0004_axi2mod, 1_axisz2mod};
const Reg ACQU_LENGTH       {ACQU_CTRL + 0x0008_axi2mod, 1_axisz2mod};
const Reg ACQU_OFFSET       {ACQU_CTRL + 0x000C_axi2mod, 1_axisz2mod};
const Reg ACQU_CHSIGIDX0    {ACQU_CTRL + 0x0010_axi2mod, 1_axisz2mod};
const RegV ACQU_CHSIGIDX    {ACQU_CHSIGIDX0.addr, 1_axisz2mod, 4, 0x4_axi2mod};

const RegV ACQU_CHDATA      {ACQU_DATA + 0x0000, 0x1FFC_axi2mod, 4, 0x2000_axi2mod};

// ===================================================
// AXI: CAL_REC
// ===================================================

const Reg CAL_REC_CONTROL   {CAL_REC + 0x0000, 1_axisz2mod};
const Reg CAL_REC_STATUS    {CAL_REC + 0x0004_axi2mod, 1_axisz2mod};
const Reg CAL_REC_DELAY     {CAL_REC + 0x0008_axi2mod, 1_axisz2mod};

const RegV CAL_REC_RSLTI_CH {CAL_REC + 0x0400_axi2mod, 1_axisz2mod, 32, 0x4_axi2mod};
const RegV CAL_REC_RSLTQ_CH {CAL_REC + 0x0600_axi2mod, 1_axisz2mod, 32, 0x4_axi2mod};

// ===================================================
// Структуры битовых полей
// ===================================================

struct BF_CONTROL_STRUCT
{
    uint32_t doUpdate : 6;
    uint32_t _reserved : 26;
};
struct BF_STATUS_STRUCT
{
    uint32_t overflow : 6;
    uint32_t _reserved : 26;
};
struct BF_SCALE_STRUCT
{
    uint32_t scale : 5;
    uint32_t _reserved : 27;
};

struct BF_COE_STRUCT
{
    uint16_t re;
    uint16_t im;
};

struct ACQU_CONTROL_STRUCT
{
    uint32_t doWrite : 1;
    uint32_t use1pps : 1;
    uint32_t _reserved : 30;
};
struct ACQU_STATUS_STRUCT
{
    uint32_t ready : 1;
    uint32_t _reserved : 31;
};
struct ACQU_LENGTH_STRUCT
{
    uint16_t length;
    uint16_t _reserved;
};
struct ACQU_OFFSET_STRUCT
{
    uint32_t offset;
};
struct ACQU_CHSIGIDX_STRUCT
{
    uint8_t selIdx;
    uint8_t _reserved[3];
};

struct ACQU_CHDATA_ELEMENT_STRUCT
{
    uint16_t re;
    uint16_t im;
};

struct ACQU_CHDATA_STRUCT
{
    ACQU_CHDATA_ELEMENT_STRUCT chData[4][2047];
};

// ===================================================
// Расширенные RegInfo (для абстракций, если нужно)
// ===================================================

struct RegInfo
{
    RegInfo() = default;
    RegInfo(std::size_t base, std::size_t shift, std::size_t sizeB)
        : base(base)
        , shift(shift)
        , addr(base + shift / 2)
        , sizeB(sizeB)
        , size16(sizeB / 2)
        , size32(sizeB / 4)
    {}

    std::size_t base = 0;
    std::size_t shift = 0;
    std::size_t addr = 0;
    std::size_t sizeB = 0;
    std::size_t size16 = 0;
    std::size_t size32 = 0;
};

struct RegVectInfo
{
    QVector<RegInfo> vect;
    std::size_t quantity;
    std::size_t step;

    RegVectInfo(std::size_t base,
                std::size_t startShift,
                std::size_t sizeB,
                std::size_t quantity,
                std::size_t axiStep)
        : quantity(quantity)
        , step(axiStep / 2)
    {
        for (std::size_t i = 0; i < quantity; ++i)
            vect.append(RegInfo(base, startShift + i * axiStep, sizeB));
    }

    const RegInfo &operator[](std::size_t i) const { return vect[i]; }
};

} // namespace pcoReg
