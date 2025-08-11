#pragma once

// Адресное пространство Modbus по функциональным блокам
// Формат: OFFSET, SIZE (в регистрах Modbus = 16 бит)

#define MODBUS_REGS         0x0000, 52        // Основные регистры (прошивка, серийник, температура и т.д.)
#define MODBUS_ADC          0x0100, 512       // 16 блоков ADC_iface (16x32)
#define MODBUS_FIR          0x0500, 256       // FIR-фильтры
#define MODBUS_MUX          0x0600, 256       // Блок мультиплексора
#define MODBUS_SYNC         0x0700, 256       // Блок синхронизации
#define MODBUS_CAL_REC_CTRL 0x0800, 256       // Управление калибровкой CAL_REC
#define MODBUS_ACQU_CTRL    0x0900, 256       // Управление сбором данных
#define MODBUS_BEAMFORMER   0x0B00, 2048      // 6 блоков BeamFormer по 256 байт
#define MODBUS_DDS          0x0C00, 256       // 6 DDS по 32 байта
#define MODBUS_CAL_REC      0x0C00, 1024      // CAL_REC: результат (перекрытие адреса с DDS!)
#define MODBUS_ACQU         0x8000, 32768     // Результаты сбора данных (до 4 каналов, 2047 сэмплов на канал)
