#pragma once

#include <QVector2D>
#include <QVector3D>
#include <QVector>
#include <complex>
#include <memory>

#include "../modbus/genlib/generic.h"
#include "../math/antmodel.h"

class Apd
{
public:
    using Angles = gen::Rot;
    using Complex = std::complex<gen::ValueT>;
    using OutCoeRegBlock = QVector<quint16>;

    /// Конструктор по умолчанию
    explicit Apd();

    /// Установка ориентации антенной решетки (глобальные углы)
    bool setGridGlobalRot(const Angles &angles);

    /// Установка направления луча (глобальные углы)
    bool setBeamGlobalRot(const Angles &angles);

    /// Установка размера решетки Rx (в элементах)
    bool setGridSize(const gen::Size2D &size);

    /// Установка шага между приёмниками в плоскости XY
    bool setRxStep(const QVector2D &delta);

    /// Установка смещения решетки по оси Y
    bool setRxShift(gen::ValueT shift);

    /// Установка центральной частоты в Гц
    bool setCentralFrequency(gen::ValueT freq);

    /// Установка типа поляризации
    bool setPolarityType(gen::Polarization type);

    /// Выполнение расчета коэффициентов
    bool calculate(const QVector<double> *bfCoeCorr = nullptr);

    /// Получение полного блока коэффициентов
    [[nodiscard]] OutCoeRegBlock getCoeRegBlock() const;

    /// Получение коэффициентов для указанного ПЦО и антенны
    [[nodiscard]] OutCoeRegBlock getCoeRegBlockFor(int pcoIndex, int antIndex = -1) const;

    /// Получение указателя на внутреннюю модель
    [[nodiscard]] const AntModel *getMath() const { return math.get(); }

    /// Получение сгенерированной решетки антенн
    [[nodiscard]] QVector<QVector3D> getAntGrid() const { return math->getGrid(); }

    /// Расширение коэффициентов до мультиполяризации
    bool extendToMultipolarization(const QVector<Complex> &dist, QVector<Complex> &out);

    /// Ремап коэффициентов в структуру регистра
    bool remapToRegBlock(const QVector<Complex> &dist, QVector<Complex> &out);

    /// Упаковка комплексных коэффициентов в 16-битные значения
    bool unpackComplex(const QVector<Complex> &dist, QVector<quint16> &out);

    /// Перестановка компонент поляризации
    void swapPolarizations(const QVector<Complex> &in, QVector<Complex> &out);

    /// Возвращает указатель на внутреннюю модель антенны
    AntModel *getModel() const { return math.get(); }

private:
    std::unique_ptr<AntModel> math;

    // Входные параметры
    Angles inGridGlobalRot;
    Angles inBeamGlobalRot;
    gen::Size2D inGridSize{16, 16};
    gen::Size2D inPcoSize{8, 8};
    gen::Size2D inAmSize{2, 2};
    QVector2D inRxStep{0.105f, 0.105f};
    gen::ValueT inRxShift = 0.105 / 2;
    gen::ValueT inCentralFreq = 1544.5e6;
    gen::Polarization inPolarityType = gen::V_POLARITY;

    // Выходные данные
    OutCoeRegBlock outCoeRegBlock;

    // Вспомогательные буферы
    QVector<Complex> prExtension;
};

class ApdSingle
{
public:
    static Apd *instance();

private:
    ApdSingle() = default;
    ApdSingle(const ApdSingle &) = delete;
    ApdSingle &operator=(const ApdSingle &) = delete;

    static Apd *instance_;
};
