#pragma once

#include <cstdint>

namespace gen {

// Преобразует значение double в фиксированный формат Q1.15 (uint16_t)
uint16_t toFpn16(double val);

// Преобразует значение из фиксированного формата Q1.15 (uint16_t) в double
double fromFpn16(uint16_t val);

} // namespace gen
