#include "datachanelnoptr.h"

DataChanelNoPtr::DataChanelNoPtr()
{

}

DataChanelNoPtr::DataChanelNoPtr(const DataChanel& d_ch) {

    for(const auto & item : d_ch.m_segments){
        // auto ptr = std::make_shared<SegmentPlan>();
        // ptr = item;
        SegmentPlan a = *item;
        m_segments.push_back(a);
    }
    active = d_ch.active;
    empty = d_ch.empty;
}

std::list<SegmentPlan> DataChanelNoPtr::segments() const
{
    return m_segments;
}
