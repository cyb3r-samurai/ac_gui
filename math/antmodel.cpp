#include "antmodel.h"
#include <cmath>
#include <complex>

AntModel::AntModel()
    : Mt({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}})
{}

// Установка ориентации антенной решетки относительно ENU (векторная модель Эйлера)
bool AntModel::setDirection(double az, double el, double rot)
{
    // Углы Эйлера (в радианах)
    const double a = -az;             // Прецессия (вокруг Z)
    const double b = el - M_PI / 2.0; // Нутация (вокруг X')
    const double g = M_PI - rot;      // Вращение (вокруг Z')

    // Матрица поворота (ENU → Grid)
    Mt = TMatrix<double>({{cos(a) * cos(g) - sin(a) * cos(b) * sin(g),
                           -cos(a) * sin(g) - sin(a) * cos(b) * cos(g),
                           sin(a) * sin(b)},
                          {sin(a) * cos(g) + cos(a) * cos(b) * sin(g),
                           -sin(a) * sin(g) + cos(a) * cos(b) * cos(g),
                           -cos(a) * sin(b)},
                          {sin(b) * sin(g), sin(b) * cos(g), cos(b)}})
             .T();

    return Mt.WasError();
}

// Генерация прямоугольной сетки антенн с возможным сдвигом по Y (offset)
bool AntModel::setGrid(int cntX, int cntY, double stepX, double stepY, double shiftY)
{
    const int num = cntX * cntY;
    grid.init(num, 3);

    for (int i = 0; i < cntX; ++i) {
        const double shift = (i % 2) * shiftY;

        for (int j = 0; j < cntY; ++j) {
            const int idx = i * cntY + j;
            grid(idx, 0) = i * stepX;
            grid(idx, 1) = j * stepY + shift;
            grid(idx, 2) = 0.0;
        }
    }

    sizeX = (cntX - 1) * stepX;
    sizeY = (cntY - 1) * stepY + shiftY;

    return grid.WasError();
}

// Расчет амплитудно-фазового распределения для заданного направления и частоты
bool AntModel::calcDist(double az, double el, double centralFreq)
{
    constexpr double SPEED_OF_LIGHT = 299792458.0;
    const double wn = 2.0 * M_PI / SPEED_OF_LIGHT * centralFreq;

    // Направляющие косинусы в ENU
    TMatrix<double> V = {{sin(az) * cos(el)}, {cos(az) * cos(el)}, {sin(el)}};

    // Проекция вектора луча в систему координат решетки
    TMatrix<double> Va = Mt * V;
    TMatrix<double> proj = grid * Va;

    // Начальное распределение
    TMatrix<std::complex<double>> A(proj.Size());
    for (int i = 0; i < proj.Size(); ++i)
        A(i) = std::exp(std::complex<double>(0, -wn * proj(i)));

    // Применение амплитудного окна (опционально, прямоугольное окно)
    const double T = 1.0, Tx = 1.0, Ty = 1.0;
    std::complex<double> sum = 0.0;

    for (int i = 0; i < grid.Rows(); ++i) {
        const double Ax = Tx
                          + (1.0 - Tx)
                                * std::pow(std::cos(M_PI * (grid(i, 0) - sizeX / 2.0) / sizeX), 2);
        const double Ay = Ty
                          + (1.0 - Ty)
                                * std::pow(std::cos(M_PI * (grid(i, 1) - sizeY / 2.0) / sizeY), 2);
        const double apodization = T + (1.0 - T) * Ax * Ay;

        const auto weighted = std::conj(A(i)) * apodization;
        sum += A(i) * weighted;
        A(i) = weighted;
    }

    // Нормировка
    dist = A * (1.0 / sum);

    return dist.WasError();
}

// Возвращает координаты элементов решетки
QVector<QVector3D> AntModel::getGrid() const
{
    QVector<QVector3D> out;
    out.reserve(grid.Rows());

    for (int i = 0; i < grid.Rows(); ++i) {
        out.append(QVector3D(static_cast<float>(grid(i, 0)),
                             static_cast<float>(grid(i, 1)),
                             static_cast<float>(grid(i, 2))));
    }

    return out;
}

// Возвращает нормированное амплитудно-фазовое распределение
QVector<std::complex<double>> AntModel::getDist() const
{
    QVector<std::complex<double>> out;
    out.reserve(dist.Size());

    for (int i = 0; i < dist.Size(); ++i)
        out.append(dist(i));

    return out;
}
