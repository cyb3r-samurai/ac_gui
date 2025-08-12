#include "toytelemetry.h"
#include <QDebug>

ToyTelemetry::ToyTelemetry(QObject *parent)
    : QObject{parent}
{
    init();
    connect(stateTimer, &QTimer::timeout, this, &ToyTelemetry::onStateTimer);
    connect(telemetryTimer, &QTimer::timeout, this, &ToyTelemetry::onTelemetryTimer);
}

void ToyTelemetry::startPolling(quint8 probability)
{
    probability_ = probability;
    telemetryTimer->start(1000);
    stateTimer->start(5000);
    emit startingDeviceStatesRecieved(m_stateVec);
}

void ToyTelemetry::stop()
{
    telemetryTimer->stop();
    stateTimer->stop();
}

void ToyTelemetry::onStateTimer()
{
    //починка ранне сломаных устройстЖцв
    std::for_each(m_stateVec.begin(), m_stateVec.end(), [this](DOS& dos) {
        if(dos.state_ != 0) {
            dos.state_ = 0;
            emit deviceStateChanged(dos);
        }
        std::for_each(dos.child_devices_.begin(), dos.child_devices_.end(), [this](PCO& pco) {
            if(pco.state_ != 0) {
                pco.state_ =0;
                emit deviceStateChanged(pco);
            }
        });

    });


    //probability * 10  процентов поломка хотябы одног устройства
    if(dist10_(rng_) < probability_) {
        int amount = 1;
        int amount_rand = dist10_(rng_);
        amount +=  amount_rand / 4;

        for (int i = 0; i < amount; ++i) {
            int crash_id = dist68_(rng_);
            int sector = crash_id / 17; // sector number - 1
            int unit_id = crash_id % 17;
            device* device;
            if(unit_id == 0) {
                device = &m_stateVec[sector];
            }
            else {
                device = &m_stateVec[sector].child_devices_[unit_id - 1];
            }

            if(dist10_(rng_) / 5) {
                device->state_ = 1;
            }
            else {
                device->state_ = 255;
            }
            emit deviceStateChanged(*device);
        }

    }
}

void ToyTelemetry::onTelemetryTimer()
{
    quint8 delta = dist10_(rng_);
    delta -= 5;
    std::for_each(m_telemetryVec.begin(), m_telemetryVec.end(), [delta](sector_telemetry& sector) {
        sector.dos_telem_.common_.counter_rx  += 2;
        sector.dos_telem_.common_.counter_tx  += 2;
        sector.dos_telem_.common_.temp_board += delta;
        sector.dos_telem_.common_.temp_fpga += delta;
        sector.dos_telem_.pwr_DOS_current += delta;
        sector.dos_telem_.pwr_bus_voltage_ += delta;

        std::for_each(sector.pcos_telem_.begin(), sector.pcos_telem_.end(), [delta](pco_telemetry& pco) {
            pco.common_.counter_rx += 1;
            pco.common_.counter_tx += 1;
            pco.common_.temp_board += delta;
            pco.common_.temp_fpga += delta;
        });

    });

    emit telemetryRecieved(m_telemetryVec);

}

void ToyTelemetry::init()
{
    //init stateVecо
    for (int i = 1 ; i < 5; i++) {

        m_stateVec.emplace_back();
        qDebug() << i << &i;
        DOS& dos = m_stateVec.back();
        qDebug() << i << &i;
        dos.ident_.sector_ = i;
        dos.ident_.unitid_ = 0;
        dos.state_ = 0;

        for (int j = 1;  j < 17; j++) {
            dos.child_devices_.emplace_back();
            PCO & pco = dos.child_devices_.back();
            pco.ident_.sector_ = i;
            pco.ident_.unitid_ = j;
            pco.state_= 0;
        }
        qDebug() << i;
    }

    //init telemetryVec
    for (int sector = 1; sector < 5; ++sector) {
        sector_telemetry sec_telem;
        sec_telem.sector_number_ = sector;
        sec_telem.dos_telem_.ident_.sector_ = sector;
        sec_telem.dos_telem_.ident_.unitid_ = 0;

        for (int pcoId = 1; pcoId < 17; ++pcoId) {
            pco_telemetry pco_telem;
            pco_telem.ident_.sector_ = sector;
            pco_telem.ident_.unitid_ = pcoId;
            sec_telem.pcos_telem_.push_back(pco_telem);
        }
    }

    //intit generator
    std::mt19937 rng(dev_());
    rng_ = rng;
    std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10);
    std::uniform_int_distribution<std::mt19937::result_type> dist68(0, 67);
    dist10_ = dist10;
    dist68_ = dist68;

    //init timers
    stateTimer = new QTimer();
    telemetryTimer = new QTimer();
}
