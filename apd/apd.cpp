#include "apd.h"
#include "fpm/fixed.hpp"

#include <QDebug>
#include <complex>

using namespace gen;

/// Пользовательский литерал для мнимой единицы (_i)
constexpr std::complex<ValueT> operator""_i(long double d)
{
    return {0.0, static_cast<ValueT>(d)};
}

/// Конструктор: инициализация всех параметров по умолчанию
Apd::Apd()
    : math(std::make_unique<AntModel>())
    , inGridGlobalRot(0, 0)
    , inBeamGlobalRot(0, 0)
    , inGridSize(16, 16)
    , inPcoSize(8, 8)
    , inAmSize(2, 2)
    , inRxStep(0.105f, 0.105f)
    , inRxShift(0.105 / 2)
    , inCentralFreq(1544.5e6)
    , inPolarityType(V_POLARITY)
{}

/// Установка ориентации решетки в глобальной СК
bool Apd::setGridGlobalRot(const Angles &angles)
{
    inGridGlobalRot = angles;
    return true;
}

/// Установка направления формирования луча в глобальной СК
bool Apd::setBeamGlobalRot(const Angles &angles)
{
    inBeamGlobalRot = angles;
    return true;
}

/// Задание размера антенной решетки (в Rx-элементах)
bool Apd::setGridSize(const Size2D &size)
{
    inGridSize = size;
    return true;
}

/// Установка вертикального смещения решетки
bool Apd::setRxShift(ValueT shift)
{
    inRxShift = shift;
    return true;
}

/// Установка шага между Rx-элементами в плоскости XY
bool Apd::setRxStep(const QVector2D &delta)
{
    inRxStep = delta;
    return true;
}

/// Установка центральной частоты, Гц
bool Apd::setCentralFrequency(ValueT freq)
{
    inCentralFreq = freq;
    return true;
}

/// Установка типа поляризации (V, H, R, L)
bool Apd::setPolarityType(Polarization type)
{
    inPolarityType = type;
    return true;
}

/// Основной метод вычисления коэффициентов управления
bool Apd::calculate(const QVector<double> *bfCoeCorr)
{
    if (math->setDirection(inGridGlobalRot.az, inGridGlobalRot.el)) {
        qCritical() << "setDirection failed";
        return false;
    }

    if (math->setGrid(inGridSize.x(), inGridSize.y(), inRxStep.x(), inRxStep.y(), inRxShift)) {
        qCritical() << "setGrid failed";
        return false;
    }

    if (math->calcDist(inBeamGlobalRot.az, inBeamGlobalRot.el, inCentralFreq)) {
        qCritical() << "calcDist failed";
        return false;
    }

    QVector<Complex> remap;
    if (!remapToRegBlock(math->getDist(), remap)) {
        qCritical() << "remapToRegBlock failed";
        return false;
    }

    if (!extendToMultipolarization(remap, prExtension)) {
        qCritical() << "extendToMultipolarization failed";
        return false;
    }

    // (Опционально) Модификация коэффициентов внешней коррекцией
    if (bfCoeCorr) {
        for (int i = 0; i < 32 && (2 * i + 1) < bfCoeCorr->size(); ++i) {
            Complex corr(bfCoeCorr->at(2 * i), bfCoeCorr->at(2 * i + 1));
            prExtension[i] *= corr;
        }
    }

    if (!unpackComplex(prExtension, outCoeRegBlock)) {
        qCritical() << "unpackComplex failed";
        return false;
    }

    return true;
}

/// Получение полного блока коэффициентов (все ПОЦ)
Apd::OutCoeRegBlock Apd::getCoeRegBlock() const
{
    return outCoeRegBlock;
}

/// Получение блока коэффициентов для конкретного ПЦО или антенны
Apd::OutCoeRegBlock Apd::getCoeRegBlockFor(int pcoIndex, int antIndex) const
{
    const int pcoSize = 64;
    const int antSize = 4;
    int offset = pcoSize * pcoIndex + (antIndex < 0 ? 0 : antIndex * antSize);
    int size = (antIndex < 0 ? pcoSize : antSize);
    return outCoeRegBlock.mid(offset, size);
}

/// Расширение коэффициентов до двух поляризаций по типу inPolarityType
bool Apd::extendToMultipolarization(const QVector<Complex> &dist, QVector<Complex> &out)
{
    out.resize(dist.size() * 2);
    auto it = out.begin();
    const Complex Zero(0.0, 0.0);

    for (const auto &coe : dist) {
        switch (inPolarityType) {
        case V_POLARITY:
            *it++ = coe;
            *it++ = Zero;
            break;
        case H_POLARITY:
            *it++ = Zero;
            *it++ = coe;
            break;
        case R_POLARITY:
            *it++ = coe * Complex(0, -1); // E^(-iπ/2)
            *it++ = coe;
            break;
        case L_POLARITY:
            *it++ = coe * Complex(0, 1); // E^(+iπ/2)
            *it++ = coe;
            break;
        }
    }
    return true;
}

/// Преобразование из матрицы расчетов в формат, совместимый с загрузкой в регистры
bool Apd::remapToRegBlock(const QVector<Complex> &dist, QVector<Complex> &out)
{
    out.resize(dist.size());
    QVector<Complex> buffer(dist.size());
    auto it = buffer.begin();

    // Перемешивание элементов по схеме PCO и Rx
    for (int pcoIx = 0; pcoIx < 16; ++pcoIx) {
        int base = (pcoIx / 4) * 64 + (pcoIx % 4) * 4;
        for (int shift = 0; shift < 64; shift += 16) {
            for (int rx = 0; rx < 4; ++rx) {
                *it++ = dist[base + shift + rx];
            }
        }
    }

    // Дополнительная перестановка по маске
    const QVector<int> mapMask = {13, 15, 4, 2, 14, 16, 3, 1, 9, 11, 8, 6, 10, 12, 7, 5};
    for (int pcoIx = 0; pcoIx < 16; ++pcoIx) {
        int base = pcoIx * 16;
        for (int i = 0; i < 16; ++i) {
            out[base + mapMask[i] - 1] = buffer[base + i];
        }
    }

    return true;
}

/// Преобразование комплексных коэффициентов в 16-битный формат: [Re, Im]
bool Apd::unpackComplex(const QVector<Complex> &dist, QVector<quint16> &out)
{
    using fpmTrans = fpm::fixed<int16_t, int32_t, 15>;

    out.resize(dist.size() * 2);
    auto it = out.begin();

    for (const auto &c : dist) {
        *it++ = static_cast<quint16>(fpmTrans(c.real() * 16).raw_value());
        *it++ = static_cast<quint16>(fpmTrans(c.imag() * 16).raw_value());
    }

    return true;
}

/// Перестановка поляризаций: H↔V для нечетных ADC
void Apd::swapPolarizations(const QVector<Complex> &in, QVector<Complex> &out)
{
    for (int i = 0; i < in.size(); i += 4) {
        out[i] = in[i + 1];
        out[i + 1] = in[i];
    }
}

/// Singleton-реализация: получение экземпляра
Apd *ApdSingle::instance_ = nullptr;

Apd *ApdSingle::instance()
{
    if (!instance_)
        instance_ = new Apd();
    return instance_;
}
