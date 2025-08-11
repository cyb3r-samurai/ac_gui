#include "pcocalrec.h"
#include <QDebug>
#include <QThread>
#include "fpm/fixed.hpp"
#include "modbus/genlib/generic.h"
#include "apd/apd.h"
#include "math/antmodel.h"
#include "pcoregmap.h"

PcoCalRec::PcoCalRec() = default;

/// Получение данных измерений от устройства CAL_REC
CallbackTask *PcoCalRec::getData(PcoCalRecData &calRecData, quint8 base)
{
    retTask.reset();
    const int totalSize = 32 * base;

    QVector<qint32> resI(128), resQ(128);
    QVector<quint16> resStat;
    QVector<quint16> vtmp;

    calRecData.clear();
    int attempts = 0;

    try {
        // Инициация сбора данных
        CallbackTask *devRet = device_->writeRequest(pcoReg::CAL_REC_CONTROL.addr, {1, 0});
        if (devRet->isFail())
            return devRet;

        // Ожидание флага готовности
        while (true) {
            resStat.clear();
            devRet = device_->readRequest(pcoReg::CAL_REC_STATUS.addr, pcoReg::CAL_REC_STATUS.size);

            devRet->onComplete([&](const QVector<quint16> &data) {
                resStat = data;
                qDebug() << "PcoCalRec::getData: status.len =" << data.size();
            });

            devRet->onFailed([this](const QString &msg) {
                retTask.emitFailure(msg);
                qCritical() << "PcoCalRec::getData: error:" << msg;
            });

            if (resStat.isEmpty()) {
                retTask.emitFailure("CAL_REC status is empty.");
                return &retTask;
            }

            if (resStat[0] == 1)
                break;

            if (++attempts >= 500) {
                retTask.emitFailure("Timeout waiting for CAL_REC ready.");
                return &retTask;
            }
        }

        // Чтение результатов I-канала
        vtmp = device_->readRequest(pcoReg::CAL_REC_RSLTI_CH.addr, 256)->getData();
        for (int i = 0; i < 128; ++i)
            resI[i] = (vtmp[i * 2 + 1] << 16) | vtmp[i * 2];

        // Чтение результатов Q-канала
        vtmp = device_->readRequest(pcoReg::CAL_REC_RSLTQ_CH.addr, 256)->getData();
        for (int i = 0; i < 128; ++i)
            resQ[i] = (vtmp[i * 2 + 1] << 16) | vtmp[i * 2];

        if (resI.isEmpty() || resQ.isEmpty()) {
            retTask.emitFailure("CAL_REC data is empty.");
            return &retTask;
        }

        // Формирование структурированного результата
        for (int i = 0; i < resI.size(); i += 4) {
            calRecData.append({resI[i],
                               resI[i + 1],
                               resI[i + 2],
                               resI[i + 3],
                               resQ[i],
                               resQ[i + 1],
                               resQ[i + 2],
                               resQ[i + 3]});
        }

    } catch (const std::exception &ex) {
        retTask.emitFailure(ex.what());
        return &retTask;
    }

    return &retTask;
}

/// Вычисление коэффициентов по данным из CAL_REC
CallbackTask *PcoCalRec::getCoe(const PcoCalRecData &calRecData,
                                QVector<qint16> &coef,
                                double geterodyneFreqHz)
{
    retTask.reset();

    if (calRecData.size() != ChannelsNumber) {
        retTask.emitFailure(QString("PcoCalRec::getCoe: Invalid input size: %1 != %2")
                                .arg(calRecData.size())
                                .arg(ChannelsNumber));
        return &retTask;
    }

    Apd *apd = ApdSingle::instance();
    apd->calculate();

    const QVector<QVector3D> coords = apd->getModel()->getGrid();
    const QVector<quint16> Cx = apd->getCoeRegBlock();

    using cplx = std::complex<double>;
    cplx u[ChannelsNumber], Cxcoef[ChannelsNumber];
    const cplx j(0.0, 1.0);

    // Формирование комплексных сигналов по каналам
    for (int i = 0; i < calRecData.size(); ++i) {
        if ((i + 1) % 2 == 0) {
            u[i] = {static_cast<double>(calRecData[i].i1), static_cast<double>(calRecData[i].i2)};
        } else {
            u[i] = {static_cast<double>(calRecData[i].i3), static_cast<double>(calRecData[i].i4)};
        }
    }

    // Расчет фазовых и амплитудных искажений
    for (int r = 1; r <= ChannelsNumber / 2; ++r) {
        int r2 = r * 2 - 1;
        int r1 = r * 2 - 2;

        cplx U = u[r1] * std::conj(u[r2]);
        cplx dPhivh = std::atan2(U.real(), U.imag());
        U *= std::exp(-j * dPhivh);

        double mag1 = std::abs(u[r1]);
        double mag2 = std::abs(u[r2]);
        double tmp1 = (mag2 == 0.0) ? 0.0 : (mag1 * mag1) / (mag2 * mag2);
        double tmp2 = (mag1 + mag2) / 2.0;
        double Avh = (tmp2 == 0.0) ? 0.0 : tmp1 / tmp2;

        double dx = coords[r - 1].x() - CalAntElementCoord.x;
        double dy = coords[r - 1].y() - CalAntElementCoord.y;
        double dz = coords[r - 1].z() - CalAntElementCoord.z;
        double dPhiR = 2.0 * M_PI * geterodyneFreqHz * std::sqrt(dx * dx + dy * dy + dz * dz);

        cplx gamma = U * std::exp(-j * dPhiR);
        cplx dKsi = std::atan2(gamma.real(), gamma.imag());

        // Применение компенсации к базовым коэффициентам
        Cxcoef[r1] = Cx[r1] * (1.0 / (1.0 - 0.5 * Avh)) * std::exp(j * dKsi);
        Cxcoef[r2] = Cx[r2] * (1.0 / (1.0 + 0.5 * Avh)) * std::exp(-j * (dPhivh - dKsi));
    }

    // Запись результата в выходной вектор
    coef.resize(ChannelsNumber * 2);
    for (int i = 0; i < ChannelsNumber; ++i) {
        coef[2 * i] = static_cast<qint16>(Cxcoef[i].real());
        coef[2 * i + 1] = static_cast<qint16>(Cxcoef[i].imag());
    }

    return &retTask;
}

/// Установка значения задержки (0..2047)
CallbackTask *PcoCalRec::setDelay(quint16 delay)
{
    retTask.reset();
    static constexpr quint16 kMaxDelay = 2047;

    if (delay > kMaxDelay) {
        retTask.emitFailure("Delay value > 2047.");
        return &retTask;
    }

    if (!device_) {
        retTask.emitFailure("Connection is absent.");
        return &retTask;
    }

    return device_->writeRequest(pcoReg::CAL_REC_DELAY.addr, {delay, 0});
}
