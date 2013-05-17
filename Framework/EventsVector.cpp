#include "stdafx.h"
#include "EventsVector.h"

#include "EventsMgr.h"

EventsVector::EventsVector(EventsMgr* EM)
    :
    std::vector<EventData*>(),
    m_EM(EM)
{
}

EventsVector::~EventsVector()
{
    for(auto ED : *this)
		m_EM->removeEvent(ED);
}


void EventsVector::addEvent(EventData *ED)
{
    push_back(ED);
}