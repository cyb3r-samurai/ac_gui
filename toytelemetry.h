#ifndef TOYTELEMETRY_H
#define TOYTELEMETRY_H

#include <QObject>
#include <QTimer>
#include <QtGlobal>
#include <QDebug>

#include <vector>
#include <cstdint>
#include <random>

struct identifires_ {
    quint8 unitid_;
    quint8 sector_; // 1, 2, 3, 4 (0 - 90 градусов, 90-180 градусов ...)

};

/////////////////////////////////////////////////////////////////////////
//Данные для обновления состояний устройств
//
struct device {
    identifires_ ident_;
                          // для дос(бцдо)
    quint8 state_ =  0; 	// 0 - в норме (зеленный)
                        // Желтый:
                        // 1 – не подается опорная частота 10 МГц;
                        // 2 – не подается сигнал 1 сек;
                        // 3 – нет синхронизации с опорной частотой;
                        // 4 – сбой при передаче комплексных отсчетов;
                        // 255 - отсутвует соединение (крассный)

                        // для PCO (цам)
                        // Зеленый:
                        //  0 – в норме;
                        //  Желтый:
                        //  1 – не подается опорная частота 10 МГц;
                        //  2 – не подается сигнал 1 сек;
                        //  3 – нет синхронизации с опорной частотой;
                        //  4 – сбой при передаче комплексных отсчетов;
                        //  5 – амплитудное распределение вне нормы;
                        //  6 – фазовое распределение вне нормы;
                        //  7 – прием отсутствует;
                        //  8 – присутствует помеха в полосе 1543-1546 МГц;
                        //  Красный:
                        //  255 – недоступен.

    // в будущем будут добавлены коды ошибок.
    // при несиправности одного из pco -dos будет в сосотояние идетнтифицирующем несиправность в одномо из pco.

    device() = default;
    virtual ~device() {}

};

struct PCO :public device {

    PCO() : device()  {

    }
};

struct DOS : public device {
    DOS() : device(){
    }


    std::vector<PCO> child_devices_;
};

////////////////////////////////////////////////////////////////////////
// Примерный список данных телеметри. будут еще
// Toчно появятся регистры состяояния SYNC и что то в таком духе


struct common_registers_ {
    qint16 temp_fpga = 540;
    qint16 temp_board = 560;
    quint32 counter_rx = 0;
    quint32 counter_tx = 0;
    quint32 counter_crc_error = 0;
    quint32 counter_cmd_error = 0;
    quint16 module_state = 0 ;
    quint16 module_led_state = 0;
};

struct dos_telemetry {
    identifires_ ident_;
    common_registers_ common_;
    quint32 module_ports_state_ =0;
    quint16 pwr_bus_voltage_ =  142;
    quint16 pwr_DOS_current = 147;
};

struct pco_telemetry {
    identifires_ ident_;
    common_registers_ common_;
};

struct sector_telemetry {
    quint8 sector_number_;
    dos_telemetry dos_telem_;
    std::vector<pco_telemetry> pcos_telem_;
};

////////////////////////////////////////////////////////////////////////

class ToyTelemetry : public QObject
{
    Q_OBJECT
public:
    explicit ToyTelemetry(QObject *parent = nullptr);

public slots:
    void startPolling(quint8 probability);
    void stop();

private slots:
    void onStateTimer();
    void onTelemetryTimer();

signals:
    void telemetryRecieved(const std::vector<sector_telemetry>&);
    void startingDeviceStatesRecieved(const std::vector<DOS>&);
    void deviceStateChanged(const device&);


private:
    std::vector<DOS> m_stateVec;
    std::vector<sector_telemetry> m_telemetryVec;
    quint8 probability_ = 4; //chance to crash device in every  5 seconds (possible value [1- 10])

    QTimer* stateTimer;
    QTimer* telemetryTimer;

    std::random_device dev_;
    std::mt19937 rng_;
    std::uniform_int_distribution<std::mt19937::result_type> dist10_;
    std::uniform_int_distribution<std::mt19937::result_type> dist68_;

    void init();
};

#endif // TOYTELEMETRY_H
