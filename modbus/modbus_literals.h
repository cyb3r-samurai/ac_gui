#pragma once

#include <cstddef>

/// Пользовательские литералы для преобразования адресов и размеров
/// из байтового AXI-пространства в 16-битные регистры Modbus

/// Перевод AXI-адреса (в байтах) в адрес Modbus (в 16-битных словах)
constexpr std::size_t operator""_axi2mod(unsigned long long x)
{
    return x / 2;
}

/// Перевод размера AXI (в байтах) в размер Modbus
constexpr std::size_t operator""_axisz2mod(unsigned long long x)
{
    return x * 2;
}

/// Перевод размера в байтах в Modbus-слова
constexpr std::size_t operator""_bytes2mod(unsigned long long x)
{
    return x / 2;
}
