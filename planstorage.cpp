#include "planstorage.h"


PlanStorage::PlanStorage() {
    m_sector_plans = new std::map<int, SectorPlan>;
    m_data_chanels_plans  = new std::map<int, DataChanel>;
}

bool PlanStorage::changePlans(const std::map<int, SectorPlan> &new_sector_plan,
                              const std::map<int, DataChanel> &new_chanel_plan)
{
    m_lock.lockForWrite();
    delete m_sector_plans;
    delete m_data_chanels_plans;
    *m_sector_plans =  new_sector_plan;
    *m_data_chanels_plans =  new_chanel_plan;
    m_lock.unlock();
    return true;
}

std::map<int, SectorPlan> *PlanStorage::sector_plans() const
{
    return m_sector_plans;
}

bool PlanStorage::lockRead()
{
    m_lock.lockForRead();
    return true;
}

bool PlanStorage::unloock()
{
    m_lock.unlock();
    return true;
}

std::map<int, DataChanel> *PlanStorage::data_chanels_plans() const
{
    return m_data_chanels_plans;
}

std::map<int, DataChanel> PlanStorage::get_data_chanel_copy() const
{
    return *m_data_chanels_plans;
}

std::map<int, DataChanelNoPtr> PlanStorage::get_data_chanel_no_ptr() const
{
    std::map<int,  DataChanelNoPtr> result;
    for  (auto pair : *m_data_chanels_plans){
        DataChanelNoPtr item(pair.second);
        result.insert({pair.first, item});
    }
    return result;

}

bool PlanStorage::lockWrite()
{
    m_lock.lockForWrite();
    return true;
}
