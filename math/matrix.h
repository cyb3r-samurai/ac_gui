#ifndef TMatrix_H
#define TMatrix_H
#include <complex>
#include <iostream>
#include <math.h>
//Класс, описывающий матричные опреации

template<typename Tp, int Ds = 64>
class TMatrix
{
private:
    int rows, cols; //Количество строк и столбцов, соответственно
    int size;

    Tp *m;
    Tp dummy;
    Tp mlocal[Ds];

    inline Tp *operator[](const int n) const
    { //Индексация строки
        return m + n * cols;
    }

    inline float fabs(const float &s) { return std::abs(s); }
    inline double fabs(const double &s) { return std::abs(s); }
    inline double fabs(const std::complex<double> &s) { return std::abs(s); }
    inline float fabs(const std::complex<float> &s) { return std::abs(s); }
    inline void alloc_mem()
    {
        int _size = rows * cols;

        if (_size > size) {
            if (!m || m == mlocal)
                m = reinterpret_cast<Tp *>(calloc((size_t) _size, sizeof(Tp)));
            else
                m = reinterpret_cast<Tp *>(realloc(m, (size_t) _size * sizeof(Tp)));

            if (!m)
                size = rows = cols = 0, error++;
            else
                size = _size;
        }
    }

protected:
    unsigned error;

public:
    inline Tp *data() { return m; }
    ~TMatrix()
    {
        if (m && m != mlocal)
            free(m);
    }

    TMatrix(int _rows = 0, int _cols = 0, Tp *v = nullptr) //Конструктор с инициализацией
        : rows(_rows)
        , cols(_cols)
        , size(Ds)
        , m(mlocal)
        , error(0)
    {
        init(rows, cols, v);
    }

    TMatrix(const TMatrix<Tp, Ds> &s) //Конструктор копии
        : rows(s.rows)
        , cols(s.cols)
        , size(Ds)
        , m(mlocal)
        , error(s.error)
    {
        init(rows, cols, s.m);
    }

    TMatrix(TMatrix<Tp, Ds> &&s) //Конструктор перемещения
        : rows(s.rows)
        , cols(s.cols)
        , size(Ds)
        , m(mlocal)
        , error(s.error)
    {
        if (s.m != s.mlocal) {
            size = s.size;
            m = s.m;
            s.m = nullptr;
            s.size = 0;
        } else
            init(rows, cols, s.m);

        s.rows = s.cols = 0;
    }

    TMatrix(std::initializer_list<std::initializer_list<Tp>> l) //Конструктор с списком инициализации l
        : rows(l.size())
        , cols(l.begin()->size())
        , size(Ds)
        , m(mlocal)
        , error(0)
    {
        alloc_mem();
        if (m) {
            int i = 0;

            for (auto &t : l)
                for (auto &s : t)
                    m[i++] = s;
        }
    }

    TMatrix<Tp, Ds> &resize(int _rows, int _cols)
    { //Изменение размера
        rows = _rows, cols = _cols;
        alloc_mem();
        return *this;
    }

    void init(const int _rows, const int _cols, const Tp *v = nullptr)
    {
        rows = _rows;
        cols = _cols ? _cols : !!rows;
        resize(rows, cols);

        if (v)
            for (int i = 0; i < rows * cols; i++)
                m[i] = v[i];
        else
            for (int i = 0; i < rows * cols; i++)
                m[i] = Tp(0);
    }

    TMatrix<Tp, Ds> &operator=(const TMatrix<Tp, Ds> &s) //Присваивание
    {                                                    //Присваивание
        if (this != &s) {
            rows = s.rows;
            cols = s.cols;
            error = s.error;
            alloc_mem();

            for (int i = 0; i < rows * cols; i++)
                m[i] = s.m[i];
        }

        return *this;
    }

    TMatrix<Tp, Ds> &operator=(TMatrix<Tp, Ds> &&s) //Присваивание с перемещением
    { //Присваивание c перемещением
        if (this != &s) {
            rows = s.rows;
            cols = s.cols;
            error = s.error;

            if (s.m != s.mlocal) {
                size = s.size;
                m = s.m;
                s.m = nullptr;
                s.size = 0;
            } else {
                alloc_mem();

                for (int i = 0; i < rows * cols; i++)
                    m[i] = s.m[i];
            }

            s.rows = s.cols = 0;
        }

        return *this;
    }

    inline int Size() const { return cols * rows; }
    inline int Cols() const { return cols; }
    inline int Rows() const { return rows; }
    unsigned WasError() const { return error; }

    TMatrix<Tp, Ds> T() const //Транспонирование
    {                         //Транспонирование
        TMatrix<Tp, Ds> t(cols, rows);
        t.error = error;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                t[j][i] = m[i * cols + j];

        return t;
    }

    TMatrix<Tp, Ds> H(); //Эрмитово сопряжение
    TMatrix<Tp, Ds> I(); //Обращение
    inline Tp &operator()(int i, int j)
    { //Индексация элемента
        if (i < rows && j < cols)
            return m[j + i * cols];

        error++;
        return dummy;
    }

    inline const Tp &operator()(int i, int j) const
    { //Индексация элемента
        if (i < rows && j < cols)
            return m[j + i * cols];

        //error++;
        return dummy;
    }

    inline Tp &operator()(int i)
    { //Индексация элемента
        if (i < rows * cols)
            return m[i];

        error++;
        return dummy;
    }

    inline const Tp &operator()(int i) const
    { //Индексация элемента
        if (i < rows * cols)
            return m[i];

        //error++;
        return dummy;
    }

    Tp Norm() //Длина вектора
    {
        Tp d = 0;

        for (int i = 0; i < rows * cols; i++)
            d += m[i] * m[i];

        return sqrt(d);
    }

    Tp Sum() //Сумма всех элементов
    {
        Tp d = 0;

        for (int i = 0; i < rows * cols; i++)
            d += m[i];

        return d;
    }

    static TMatrix<Tp, Ds> VProd(const TMatrix<Tp, Ds> &l,
                                 const TMatrix<Tp, Ds> &r) //Векторное произведение
    {
        if (l.rows * l.cols != 3 || r.rows * r.cols != 3)
            return TMatrix<Tp>(0, 0);

        TMatrix<Tp> prod(l.rows, l.cols);
        prod.m[0] = l.m[1] * r.m[2] - l.m[2] * r.m[1];
        prod.m[1] = l.m[2] * r.m[0] - l.m[0] * r.m[2];
        prod.m[2] = l.m[0] * r.m[1] - l.m[1] * r.m[0];

        return prod;
    }

    static Tp CProd(const TMatrix<Tp, Ds> &l, const TMatrix<Tp, Ds> &r) //Скалярное произведение
    {
        Tp prod = 0;
        int size = l.rows * l.cols;

        if (size == r.rows * r.cols)
            for (int i = 0; i < size; i++)
                prod += l.m[i] * r.m[i];

        return prod;
    }

    static TMatrix<Tp, Ds> Prod(const TMatrix<Tp, Ds> &l,
                                const TMatrix<Tp, Ds> &r) //<Обычное произведение
    {                                                     //<Бинарная операция *
        TMatrix<Tp, Ds> t(l.rows, r.cols);
        if (l.cols != r.rows) {
            t.error++;
            return t;
        }

        t.error = l.error + r.error;

        for (int i = 0, j, k; i < l.rows; i++) {
            for (j = 0; j < r.cols; j++) {
                t[i][j] = 0;

                for (k = 0; k < l.cols; k++)
                    t[i][j] += l.m[i * l.cols + k] * r.m[k * r.cols + j];
            }
        }
        return t;
    }

    TMatrix<Tp, Ds> operator-() //Унарная операция -
    {                           //Унарная операция -
        TMatrix<Tp, Ds> t(rows, cols, error);

        for (int i = 0; i < rows * cols; i++)
            t.m[i] = -m[i];

        return t;
    }

    TMatrix<Tp, Ds> operator+(const TMatrix<Tp, Ds> &s) //<Бинарная операция +
    {                                                   //<Бинарная операция +
        if (rows != s.rows || cols != s.cols) {
            error++;
            return *this;
        }

        TMatrix<Tp, Ds> t(*this);

        for (int i = 0; i < rows * cols; i++)
            t.m[i] += s.m[i];

        return t;
    }

    TMatrix<Tp, Ds> operator-(const TMatrix<Tp, Ds> &s) //<Бинарная операция -
    {                                                   //<Бинарная операция -
        if (rows != s.rows || cols != s.cols) {
            error++;
            return *this;
        }

        TMatrix<Tp, Ds> t(*this);

        for (int i = 0; i < rows * cols; i++)
            t.m[i] -= s.m[i];

        return t;
    }

    TMatrix<Tp, Ds> &operator+=(const Tp &s) //<Бинарная операция *
    {                                        //<Бинарная операция *
        for (int i = 0; i < rows * cols; i++)
            m[i] += s;

        return *this;
    }

    TMatrix<Tp, Ds> &operator+=(const TMatrix<Tp, Ds> &s) //<Бинарная операция +
    {                                                     //<Бинарная операция +
        if (rows != s.rows || cols != s.cols) {
            error++;
            return *this;
        }

        for (int i = 0; i < rows * cols; i++)
            this->m[i] += s.m[i];

        return *this;
    }

    TMatrix<Tp, Ds> &operator-=(const Tp &s) //<Бинарная операция *
    {                                        //<Бинарная операция *
        for (int i = 0; i < rows * cols; i++)
            m[i] -= s;

        return *this;
    }

    TMatrix<Tp, Ds> &operator-=(const TMatrix<Tp, Ds> &s) //<Бинарная операция -
    {                                                     //<Бинарная операция -
        if (rows != s.rows || cols != s.cols) {
            error++;
            return *this;
        }

        for (int i = 0; i < rows * cols; i++)
            this->m[i] -= s.m[i];

        return *this;
    }

    TMatrix<Tp, Ds> operator*(const Tp &s) //<Бинарная операция *
    {                                      //<Бинарная операция *
        TMatrix<Tp, Ds> t(*this);

        for (int i = 0; i < rows * cols; i++)
            t.m[i] *= s;

        return t;
    }

    TMatrix<Tp, Ds> operator*(const TMatrix<Tp, Ds> &s) //<Матричная операция *
    {                                                   //<Бинарная операция *
        return TMatrix<Tp, Ds>::Prod(*this, s);
    }

    TMatrix<Tp, Ds> &operator*=(const Tp &s) //<Бинарная операция *
    {                                        //<Бинарная операция *
        for (int i = 0; i < rows * cols; i++)
            m[i] *= s;

        return *this;
    }

    TMatrix<Tp, Ds> &operator*=(const TMatrix<Tp, Ds> &s) //<Матричная операция *
    {
        *this = TMatrix<Tp, Ds>::Prod(*this, s);
        return *this;
    }

    TMatrix<Tp, Ds> operator/=(const Tp &s) //<Бинарная операция /
    {                                       //<Бинарная операция *
        for (int i = 0; i < rows * cols; i++)
            m[i] /= s;

        return *this;
    }

    template<typename U, int SS>
    friend std::ostream &operator<<(std::ostream &, const TMatrix<U, SS> &);
};

template<typename Tp, int Ds>
std::ostream &operator<<(std::ostream &os, const TMatrix<Tp, Ds> &s)
{
    for (int i = 0; i < s.rows; i++) {
        if (i != 0)
            os << std::endl;

        for (int j = 0; j < s.cols; j++) {
            os.width(5);

            if (j != 0)
                os << " ";

            os << s.m[j + i * s.cols];
        }
    }

    return os;
}

template<typename Tp, int Ds>
TMatrix<Tp, Ds> TMatrix<Tp, Ds>::H()
{ //Эрмитово сопряжение
    TMatrix<Tp, Ds> t(cols, rows);
    t.error = error;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t[j][i] = std::conj(m[i * cols + j]);

    return t;
}

template<typename Tp, int Ds>
TMatrix<Tp, Ds> TMatrix<Tp, Ds>::I()
{ //Обращение
    if (rows != cols || rows == 0) {
        error++;
        return *this;
    }

    TMatrix<Tp, Ds> t(rows, 2 * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            t[i][j] = (*this)[i][j];

        for (int j = cols; j < 2 * cols; j++)
            t[i][j] = 0;

        t[i][i + cols] = 1.;
    }

    Tp r, s = 0;

    for (int k = 0; k < cols; k++) {
        int k1 = k;
        s = t[k][k];

        for (int i = k + 1; i < rows; i++) {
            r = t[i][k];

            if (fabs(r) > fabs(s)) {
                s = r;
                k1 = i;
            }
        }

        if (s == 0.)
            break; //ошибка

        if (k1 != k) {
            for (int i = k; i < 2 * cols; i++) {
                r = t[k][i];
                t[k][i] = t[k1][i];
                t[k1][i] = r;
            }
        }

        for (int i = k + 1; i < 2 * cols; i++)
            t[k][i] /= s;

        for (int i = k + 1; i < rows; i++) {
            r = t[i][k];

            for (int j = k + 1; j < 2 * cols; j++)
                t[i][j] -= t[k][j] * r;
        }
    }

    if (fabs(s) != 0.) {
        for (int j = cols; j < 2 * cols; j++) {
            for (int i = rows - 2; i >= 0; i--) {
                r = t[i][j];

                for (int k = i + 1; k < rows; k++)
                    r -= t[k][j] * t[i][k];

                t[i][j] = r;
            }
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                t.m[i * cols + j] = t.m[i * 2 * cols + j + cols];
    } else
        t.error++;

    t.resize(rows, cols);
    return t;
}

#endif
