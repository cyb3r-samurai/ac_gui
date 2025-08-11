#pragma once

// Общие определения и типы для работы с Modbus и DSP

#include "fpn16.h"         // Фиксированная арифметика Q1.15: toFpn16, fromFpn16
#include "modbus_layout.h" // Адресные пространства Modbus (offset + size)
#include "regmap.h"        // Структуры описания регистров: Reg, RegV
#include "rf_constants.h"  // Частотные константы систем GNSS и приёмника
#include "types.h"         // Общие типы: ValueT, Complex, Rot, Size2D, Polarization

// Всё содержимое находится в namespace gen
