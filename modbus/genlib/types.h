#pragma once

#include <complex>

namespace gen {

/// Базовый числовой тип, используемый в вычислениях
using ValueT = double;

/// Комплексное число, основанное на ValueT
using Complex = std::complex<ValueT>;

/// Поляризация сигнала
enum Polarization : char {
    V_POLARITY = 'V', // Вертикальная
    H_POLARITY = 'H', // Горизонтальная
    R_POLARITY = 'R', // Правая круговая
    L_POLARITY = 'L'  // Левая круговая
};

/// Пара углов: азимут и угол места (например, для антенны)
struct Rot
{
    ValueT az = 0; ///< Азимут, градусы
    ValueT el = 0; ///< Угол места, градусы

    Rot() = default;

    Rot(ValueT az_, ValueT el_)
        : az(az_)
        , el(el_)
    {}

    /// Устанавливает новое значение азимута и угла места
    void set(ValueT az_, ValueT el_)
    {
        az = az_;
        el = el_;
    }
};

/// Размер двумерной области (ширина и высота), аналогично QSize
struct Size2D
{
public:
    Size2D() = default;

    Size2D(int width, int height)
        : _x(width)
        , _y(height)
    {}

    int x() const { return _x; }
    int x(int value)
    {
        _x = value;
        return _x;
    }

    int y() const { return _y; }
    int y(int value)
    {
        _y = value;
        return _y;
    }

    /// Общее количество элементов (x * y)
    int total() const { return _x * _y; }

    /// Проверяет, является ли размер нулевым
    bool isEmpty() const { return _x == 0 || _y == 0; }

    /// Проверяет, являются ли оба измерения положительными
    bool isValid() const { return _x > 0 && _y > 0; }

    /// Сравнение двух размеров
    bool operator==(const Size2D &other) const { return _x == other._x && _y == other._y; }

    bool operator!=(const Size2D &other) const { return !(*this == other); }

private:
    int _x = 0;
    int _y = 0;
};

} // namespace gen
