#pragma once

namespace gen {

/// Частотные диапазоны для различных навигационных систем
struct RFConstants {
    static constexpr double MIN      = 1544e6;     // Нижняя граница допустимого диапазона, Гц
    static constexpr double MAX      = 1545e6;     // Верхняя граница допустимого диапазона, Гц
    static constexpr double GALILEO  = 1544.1e6;   // Частота Galileo, Гц
    static constexpr double GLONASS  = 1544.9e6;   // Частота ГЛОНАСС, Гц
    static constexpr double BEIDOU   = 1544.21e6;  // Частота BeiDou, Гц
    static constexpr double GPS      = 1544.79e6;  // Частота GPS, Гц
};

/// Частоты дискретизации и гетеродина
struct FreqConstants {
    static constexpr double SAMPLING  = 4.4e6;     // Частота дискретизации, Гц
    static constexpr double HETERODYN = 1544.5e6;  // Частота гетеродина, Гц
};

// Глобально доступные константы
static const RFConstants RF;
static const FreqConstants FREQ;

} // namespace gen
