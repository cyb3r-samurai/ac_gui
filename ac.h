// Класс управляет планми примема АС.

//TODO :: добавить класс шадулер с адекватным интерфейсом.

#ifndef AC_H
#define AC_H

#include "Message.h"
#include "datachanel.h"
#include "planfactory.h"
#include "sectorplan.h"
#include "planstorage.h"

#include "devices/deviceinterface.h"
#include "devices/devicefactory.h"
#include "modbus/modbusdevice.h"
#include "devices/pcolib/pcoapi.h"
#include "devices/doslib/dos.h"
#include "fpm/fixed.hpp"
#include "planfactory.h"


#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QThread>
#include <QDebug>
#include <QFile>
#include "pthread.h"
#include "sched.h"
#include "unistd.h"

#include <map>
#include <memory>
#include <atomic>


class AC : public QObject
{
    Q_OBJECT
public:
    explicit AC(std::shared_ptr<PlanStorage> p_s, QObject* parent = nullptr);
    ~AC() override;

signals:
    void plans_changed();
    void sector_plan_chanhed(const std::map<int, SectorPlan>&);
    void chanel_plan_chnaged(const std::map<int, DataChanel>&);
    void messageHandled(long long, quint8);
    void modbusTcp_coonnect();

    void accept_cell(int data_chanel_number, int real_chanel_number, int sector,
                     const QDateTime& current_time, int ka_number, int az, int angle);
    void finish_data_chanel(int data_chanel_number, int real_chanal_number, int sector);
    void stopSending();
    void finish_segment(int data_chanel_number, int real_chanel_number, int sector);
    void set(int sector_num, int chan, int az, int angle, uint32_t freq, int pol);


    void stopped();

public slots:
    void onStopRecieve(long long);
    void start();
    void stop();
    void setCoe(int sector_num, int chan, int az, int angle, uint32_t freq, int pol);
    void connectToModBus();

private slots:
    void CheckTime();
    void loadCorrCoe();

private:
    // Планы приема по секторам
    std::map<int, SectorPlan>* m_sector_plans;
    bool calibr_loaded;

    // Каналы данных
    std::map<int, DataChanel>* m_chanel_plans;

    int curr_az{};
    int curr_angle{};
    uint32_t curr_freq{};
    int curr_pol{};

    const int  AntAz = 450;
    const int AntAngle = 520;


    QVector<double> bfCoeCorr;

    void startAtNextSecond();
    bool setAffinity(int cpuCore);

    std::shared_ptr<PlanStorage> m_planStoragePtr;

    PcoApi pco;
    DosApi dos;
    DeviceInterface* connection = nullptr;
    QVector<double> bfcoeCorr;

    QTimer* m_timer;
    std::atomic<bool> started_;
};

#endif // AC_H
