#ifndef DATACHANELNOPTR_H
#define DATACHANELNOPTR_H

#include <list>
#include <segmentplan.h>
#include <datachanel.h>


class DataChanelNoPtr
{
public:
    DataChanelNoPtr();
    DataChanelNoPtr(const DataChanel& d_ch);

    bool active = false;
    std::list<SegmentPlan> segments() const;

public:
    bool empty = true;
    std::list<SegmentPlan> m_segments;
};

#endif // DATACHANELNOPTR_H
