#include "reportstatechecker.h"

ReportStateChecker::ReportStateChecker(std::shared_ptr<PlanStorage> p_s, QObject *parent)
    : QObject{parent}, m_planStoragePtr{p_s}
{
}

void ReportStateChecker::onTimer()
{
    m_planStoragePtr->lockRead();

    m_data_chanel_plans.clear();
    m_data_chanel_plans = m_planStoragePtr->get_data_chanel_copy();

    m_planStoragePtr->unloock();
    //TODO:: получить телеметрию
    if(!m_data_chanel_plans.empty()) {
        create_recieve_state();
    }
}

void ReportStateChecker::onRequest(long long)
{
    //update data in class
    m_planStoragePtr->lockRead();
    m_data_chanel_plans.clear();
    m_data_chanel_plans = m_planStoragePtr->get_data_chanel_copy();
    m_planStoragePtr->unloock();

    //if(!m_data_chanel_plans.empty()) {
        create_session_info();
   // }
}

void ReportStateChecker::onAcStateRequest(long long)
{
    create_ac_state();
}

void ReportStateChecker::onStartingServer()
{
    create_ac_state();
}

void ReportStateChecker::create_ac_state()
{
    auto ac_state_ptr = std::make_shared<AcState>();
    emit acStateCreated(ac_state_ptr);
}

// Создание сообщения о каналах данных. Учавствеют все планы(активные и не активные).
void ReportStateChecker::create_session_info()
{
    quint8 active_chanels_count = m_data_chanel_plans.size();

    auto sessionInfoPtr = std::make_shared<SessionInfo>();
    sessionInfoPtr->active_data_chanel_count = active_chanels_count;
    if (active_chanels_count != 0)
    sessionInfoPtr->m_chanel_data = new ChanelData[active_chanels_count];

    int chanel_mas_count = 0;
    auto plans_it = m_data_chanel_plans.begin();
    while (plans_it != m_data_chanel_plans.end()) {
        int chanel_number = plans_it->first;
        size_t segment_mas_count = 0;
        if(chanel_mas_count <= active_chanels_count){
            ChanelData *current_chanel =
                &(sessionInfoPtr->m_chanel_data[chanel_mas_count]);
            std::list<std::shared_ptr<SegmentPlan>> segments =
                m_data_chanel_plans[chanel_number].segments();

            current_chanel->chanel_number = chanel_number;
            current_chanel->segment_count = segments.size();
            current_chanel->segment_plan = new MessageSegmentPlan *[segments.size()];

            auto segment_it = segments.begin();

            while (segment_it != segments.end()) {
                if(segment_mas_count  <= segments.size()) {
                    current_chanel->segment_plan[segment_mas_count] = new MessageSegmentPlan;
                    current_chanel->segment_plan[segment_mas_count] =  segment_it->get()->toMessage();
                    ++segment_mas_count;
                    ++segment_it;
                }
                else {
                    qWarning() << "Wrong segment index in session info creation";
                    continue;
                }
            }
        ++chanel_mas_count;
        ++plans_it;
        }
        else {
            qWarning() << "wrong index in session info creation";
            continue;
        }
    }
    emit sessionInfoCreated(sessionInfoPtr);
}
void ReportStateChecker::create_recieve_state()
{
    auto recievedStatePtr = std::make_shared<RecieveState>();
    quint8 active_chanels_count = 0;
    std::for_each(m_data_chanel_plans.begin(), m_data_chanel_plans.end(), [&active_chanels_count](auto pair) {
        if(pair.second.active) {
            active_chanels_count++;
        }
    });

    recievedStatePtr->initializeChanelMas(active_chanels_count);
    recievedStatePtr->n = active_chanels_count;

    int chanel_mas_count = 0;

    //iterate over chanel plans and segments to form recivestate message
    // Учавствуют только активыные каналы данныхжц.
    auto plans_it = m_data_chanel_plans.begin();
    while(plans_it != m_data_chanel_plans.end()){
        if(plans_it->second.active){
            int chanel_number = plans_it->first;
            if(chanel_mas_count > active_chanels_count +1){
                qDebug() << "wrong chanel calculation in recive state creation";
                ++plans_it;
                ++chanel_mas_count;
                continue;
            }
            ChanelInfo *current_chanel =
                &(recievedStatePtr->chanel_mas[chanel_mas_count]);

            if(m_data_chanel_plans.find(chanel_number)!= m_data_chanel_plans.end()){
                auto segments_it = m_data_chanel_plans[chanel_number].m_segments.begin();
                while(segments_it != m_data_chanel_plans[chanel_number].m_segments.end()) {
                    auto current_segment = *segments_it;
                    current_chanel->freq = current_segment->freq;
                    current_chanel->ka_number = current_segment->ka_number;
                    current_chanel->vec[0] = current_segment->current_az; // must be calculated
                    current_chanel->vec[1] = current_segment->current_angle; // must be calculated
                    current_chanel->real_chanel_number = current_segment->chanel_number;
                    current_chanel->pol = current_segment->pol;
                    current_chanel->signal_level = 1.125; // must be calculated
                    current_chanel->sector_number = current_segment->sector_number;
                    current_chanel->sector_state = 1; // must be calculated
                    current_chanel->sector_start = current_segment->sector_start; // must be taken from sector plan
                    current_chanel->sector_end = current_segment->sector_end; // must be taken from sector plan
                    break;
                }
            }
            else {
                qDebug() << "chanel number not found" ;
            }
            ++chanel_mas_count;
        }

        ++plans_it;
    }

    emit reciveStateCreated(recievedStatePtr);
}
