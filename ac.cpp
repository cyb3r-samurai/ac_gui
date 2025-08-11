#include "ac.h"

AC::AC(std::shared_ptr<PlanStorage> p_s, QObject *parent) :
    QObject{parent}
{
    m_planStoragePtr = p_s;
    m_chanel_plans = m_planStoragePtr->data_chanels_plans();
    m_sector_plans = m_planStoragePtr->sector_plans();


    m_timer = new QTimer();
    m_timer->setTimerType(Qt::PreciseTimer);
    startAtNextSecond();
    connect(m_timer, &QTimer::timeout, this, &AC::CheckTime);
    connect(this, &AC::set, this, &AC::setCoe);

    loadCorrCoe();
}

AC::~AC()
{
    //delete m_timer;
    //if (connection) {
    //    delete connection;
    // }
}


void AC::onStopRecieve(long long packet_id)
{
    m_planStoragePtr->lockWrite();
    m_chanel_plans->clear();
    m_sector_plans->clear();
    m_planStoragePtr->unloock();
    emit messageHandled(packet_id, 0);
    emit stopSending();
    qDebug() << "Вызвана остановка приема";
}

void AC::start()
{
    connectToModBus();
}

void AC::stop()
{
    m_timer->deleteLater();
    delete connection;

    emit stopped();
}


void AC::CheckTime()
{
    m_planStoragePtr->lockWrite();
    auto sector_it =  m_sector_plans->begin();

    QDateTime now = QDateTime::currentDateTime();

    while(sector_it != m_sector_plans->end()) {
        bool sector_erased = false;
        auto segment_list = sector_it->second.getSegment_plan();
        auto segment_it = segment_list->begin();
        while (segment_it != segment_list->end()) {
            bool segment_erased = false;
            //auto segment_ptr = segment_it->get();
            auto segment_ptr = *segment_it;
            auto first_time_it = segment_ptr->time_cel.time.begin();
            if (first_time_it != segment_ptr->time_cel.time.end()) {
                QDateTime first_time = *first_time_it;
                while (first_time <= now) {
                   // qint64 sec2 = (first_time - 25569) * 86400;
                   // QDateTime time = QDateTime::fromSecsSinceEpoch(sec2);
                    segment_ptr->current_angle = segment_ptr->time_cel.angle.front();
                    segment_ptr->current_az = segment_ptr->time_cel.az.front();
                    if(m_chanel_plans->at(segment_ptr->data_chanel_number).size() != 1){
                        m_chanel_plans->at(segment_ptr->data_chanel_number).active = true;
                    qInfo() << "Целеукозание применено: канал данных"<< segment_ptr->data_chanel_number << ", сектор приема" << sector_it->first
                            << ", азимут" << segment_ptr->time_cel.az.front() << "угол" << segment_ptr->time_cel.angle.front() << '\n'
                            << "номер физического канала данных:"<<segment_ptr->chanel_number <<"Запланированное время: " << first_time.time();
                    if (segment_ptr ->sector_number == 1){
                        emit set(segment_ptr->sector_number, segment_ptr->chanel_number,segment_ptr->time_cel.az.front(), segment_ptr->time_cel.angle.front(),segment_ptr->freq, segment_ptr->pol);
                    }
                    emit accept_cell(segment_ptr->data_chanel_number, segment_ptr->chanel_number,
                                     segment_ptr->sector_number, QDateTime::currentDateTime(),segment_ptr->ka_number,
                                     segment_ptr->time_cel.az.front(),segment_ptr->time_cel.angle.front());
                    }
                    ++first_time_it;
                    segment_ptr->time_cel.time.pop_front();
                    segment_ptr->time_cel.angle.pop_front();
                    segment_ptr->time_cel.az.pop_front();
                    if(first_time_it == segment_ptr->time_cel.time.end()) {
                        m_chanel_plans->at(segment_ptr->data_chanel_number).pop();
                        m_chanel_plans->at(segment_ptr->data_chanel_number).active = false;
                            qInfo() << "В канале" << segment_ptr->data_chanel_number << "выолнен сегмент плана. Количество оставшихся планов в канале данных" << m_chanel_plans->at(segment_ptr->data_chanel_number).segments().size();
                        qInfo()<< "Количество активных каналов данных:"<< m_chanel_plans->size()<<". Количестов активных секторов"<< m_sector_plans->size();
                        if(m_chanel_plans->at(segment_ptr->data_chanel_number).is_empty()) {
                            qInfo() << "Планы слежения в канале данных:"<< segment_ptr->data_chanel_number << "выполнены.";
                            m_chanel_plans->erase(segment_ptr->data_chanel_number);
                            emit finish_data_chanel(segment_ptr->data_chanel_number, segment_ptr->chanel_number, segment_ptr->sector_number);
                        }
                        else {
                            emit finish_segment(segment_ptr->data_chanel_number, segment_ptr->chanel_number, segment_ptr->sector_number);
                        }
                        segment_list->erase(segment_it++);
                        segment_erased = true;
                        if (segment_list->empty()) {
                            qInfo() << "Планы слежения в секторе" << sector_it->first << "выполнены.";
                            m_sector_plans->erase(sector_it++);
                            sector_erased = true;
                        }
                        qInfo() << m_chanel_plans->size()<< m_sector_plans->size();
                        break;
                    }
                    first_time = *first_time_it;
                }
            }

            if (!segment_erased) {
                ++segment_it;
            }
        }
        if(!sector_erased) {
            ++sector_it;
        }
    }
    m_planStoragePtr->unloock();
}

void AC::loadCorrCoe()
{
    QString filename{"../../grubo_calibration.dat"};
    QFile file(filename);


    if (file.open(QFile::OpenModeFlag::ReadOnly | QFile::OpenModeFlag::Text)) {
        this->bfCoeCorr.clear();
        QTextStream ts(&file);
        QString ss = "";
        QStringList dataline;
        ts.readLine();
        int cnt = 1;

        while (!ts.atEnd()) {
            ss = ts.readLine();
            cnt++;

            if (ss.trimmed().length() > 0) {
                dataline = ss.split(";");

                if (dataline.length() < 2) {
                    qCritical() << "Number of data elements < 2 in strnum: " << cnt
                                << ", file: " << file.fileName();
                    calibr_loaded = false;
                    return;
                }

                this->bfCoeCorr.append(dataline[0].toDouble());
                this->bfCoeCorr.append(dataline[1].toDouble());
            }
        }

        file.close();
        calibr_loaded = true;
    }
    else {
        qCritical() << file.fileName() << ": " << "failed to open file";
        calibr_loaded = false;
    }
}

inline double deg2rad(int deg)
{
    double d =  deg/10;
    const double K = M_PI / 180.;
    return d * K;
}
// временный интерфейс для управления одним устройство в дольнейшем будет использоваться  devicelib реализации Матвея.
void AC::setCoe(int sector_num, int chan, int az, int angle, uint32_t freq, int pol)
{
    if(sector_num  != 1) {
        qDebug() << "only sector 1 available";

    }
    else {

        double antAz = deg2rad(AntAz);
        double antEl = deg2rad(AntAngle);
        double beamAz = deg2rad(az);
        double beamEl = deg2rad(angle);
        double centralFreq = 1544.500 *1e6;


        CallbackTask *rettsk = pco.pcoSync.setSyncMode(SYNC_MODE_AUTO);

        if (rettsk->isFail())
            qCritical() << "pcoSync.setSyncMode() Error: " << rettsk->getErrStr();
        Apd *apd = ApdSingle::instance();
        //calc->setup
        apd->setGridGlobalRot(gen::Rot(antAz, antEl));
        apd->setBeamGlobalRot(gen::Rot(beamAz, beamEl));

        static const QHash<int, gen::Polarization> polMap{{3, gen::Polarization::V_POLARITY},
                                                          {4, gen::Polarization::H_POLARITY},
                                                          {1, gen::Polarization::R_POLARITY},
                                                          {2, gen::Polarization::L_POLARITY}};

        gen::Polarization polType = polMap.value(pol,
                                                 gen::Polarization::V_POLARITY); // значение по умолчанию
        apd->setPolarityType(polType);
        apd->setCentralFrequency(centralFreq);
        apd->calculate();

        QVector<quint16> Cx = apd->getCoeRegBlockFor(0);

        if (calibr_loaded) {
            if (this->bfCoeCorr.length() == 0)
                qCritical() << "Correcting coefficients for BfCoe not loaded.";
            else {
                QVector<double> Cx015(Cx.length());
                qint16 signed16 = 0;
                using FpmDouble = fpm::fixed<int16_t, int32_t, 15>;

                for (int i = 0; i < Cx.length(); i++) {
                    signed16 = static_cast<qint16>(Cx[i]);
                    Cx015[i] = static_cast<double>(FpmDouble().from_raw_value(signed16));
                }

                std::complex<double> cx015, bfcoe;

                for (int i = 1; i <= 32; i++) {
                    cx015.real(Cx015[2 * i - 2]);
                    cx015.imag(Cx015[2 * i - 1]);
                    bfcoe.real(this->bfCoeCorr[2 * i - 2]);
                    bfcoe.imag(this->bfCoeCorr[2 * i - 1]);
                    cx015 = cx015 * bfcoe;
                    Cx015[2 * i - 2] = cx015.real();
                    Cx015[2 * i - 1] = cx015.imag();
                }

                for (int i = 0; i < 64; i++)
                    Cx[i] = gen::toFpn16(Cx015[i]);
            }
        }
        pco.beamformer.setBfCoe(chan, Cx);

        double geterodyneFreqHz = freq * 1e3;
        quint16 DDS_FREQ = static_cast<quint16>((geterodyneFreqHz - centralFreq) / 100);
        pco.dds.setDdsFreq(chan, {DDS_FREQ, 0});

        this->connection->setUnitId(0);

        //  for (int i = 0; i <= 5; i++) {
        double testDosCoe = 0.9;

        //     if (i == chan)
        //        testDosCoe = (0.1);

        quint16 CXd;
        CXd = gen::toFpn16(testDosCoe);
        dos.beamformer.setDosBfCoe(chan, {CXd, 0});
        // }

        this->connection->setUnitId(1);
    }
}

void AC::startAtNextSecond()
{
    QDateTime now = QDateTime::currentDateTime();
    int msecToNextSecond = 1000 - now.time().msec();
    QTimer::singleShot(msecToNextSecond, [this](){
        m_timer->start(500);
    });
}

bool AC::setAffinity(int cpuCore)
{
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpuCore, &cpuset);

    pthread_t current_thread = pthread_self();
    return (pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset) == 0);
}

void AC::connectToModBus()
{
    QString addrIP  = "192.168.220.213";
    int addrPort = 502;
    int unitId = 1;

    connection = DeviceFactory::createModbusTcpDevice(unitId, addrIP, addrPort);
 //   connection->setPa

    connection->openConnection()->onComplete([this, addrIP,addrPort, unitId](QVector<quint16>){

        quint32 geterodyneFreqHz = 0;

        CallbackTask* retTask;
        this->connection->setUnitId(0);
        retTask = this->dos.calGen.getGeterodyneFreqHz(geterodyneFreqHz);
        if(retTask->isFail()) qWarning()<<"Cannot read GeterodyneFreq:  "<<retTask->getErrStr()<<Qt::endl;
        this->connection->setUnitId(unitId);
        qDebug() << "GeterodyneFreqHz" << geterodyneFreqHz<< Qt::endl;
//        curr_freq = geterodyneFreqHz;
        if(unitId > 0) {
            CallbackTask* rettsk = pco.pcoSync.setSyncMode(SYNC_MODE_AUTO);
            if(rettsk->isFail()) qCritical()<<"pcoSync.setSyncMode() Error: "<<rettsk->getErrStr()<<Qt::endl;
        }

        })->onFailed([](QString) {
            qDebug() << "fail To connect";
        });

    this->pco.useConnection(connection);
    this->dos.useConnection(connection);
}
