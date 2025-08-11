#pragma once

namespace gen::regmap {

/// Представляет один Modbus-регистр или диапазон регистров.
/// addr — начальный адрес, size — длина в 16-битных словах.
class Reg
{
public:
    Reg(int addr_, int size_)
        : addr(addr_)
        , size(size_)
        , end(addr_ + size_)
    {}

    /// Смещение от начального адреса.
    int operator+(int offset) const { return addr + offset; }

    int addr; // Начальный адрес регистра
    int size; // Количество Modbus-регистров (16-битных слов)
    int end;  // Конечный адрес (не включительно)
};

/// Представляет вектор одинаковых регистров с шагом или без.
/// Например: массив каналов или коэффициентов.
class RegV : public Reg
{
public:
    RegV(int addr, int size, int quantity, int step = 0)
        : Reg(addr, size)
        , quantity(quantity)
        , step(step)
    {}

    /// Возвращает i-й элемент вектора как отдельный Reg.
    Reg operator[](int i) const
    {
        if (i < 0 || i >= quantity)
            return Reg(0, 0); // Возвращаем пустой регистр при ошибке
        int offset = (step > 0) ? step * i : size * i;
        return Reg(addr + offset, size);
    }

    int quantity; // Количество элементов
    int step;     // Смещение между элементами в регистрах
};

} // namespace gen::regmap
