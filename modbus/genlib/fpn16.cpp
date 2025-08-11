#include "fpn16.h"
#include "fpm/fixed.hpp"

// Формат фиксированной запятой Q1.15 (1 знак, 15 дробных бит)
using fpnFormat = fpm::fixed<int16_t, int32_t, 15>;

namespace gen {

/// Преобразует значение с плавающей точкой в фиксированное 16-битное представление (Q1.15).
/// Значения за пределами [-1, 0.99997] будут обрезаны при преобразовании.
uint16_t toFpn16(double val)
{
    return static_cast<uint16_t>(fpnFormat(val).raw_value());
}

/// Преобразует значение из 16-битного фиксированного формата (Q1.15) обратно в double.
double fromFpn16(uint16_t val)
{
    return static_cast<double>(fpnFormat().from_raw_value(static_cast<int16_t>(val)));
}

} // namespace gen
