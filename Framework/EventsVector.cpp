#include "stdafx.h"
#include "EventsVector.h"

#include "EventsMgr.h"

#include "Utils.h"

EventsVector::EventsVector(EventsMgr* EM)
    :
    m_EM(EM)
{
}

EventsVector::~EventsVector()
{
	clear();
}


void EventsVector::addEvent(EventData *ED)
{
    container.push_back(ED);
}


void EventsVector::removeEvent(EventData *ED)
{
	for(auto it = container.begin(); it != container.end(); ++it)
		if(ED == *it)
		{
			container.erase(it);
			break;
		}
}


void EventsVector::clear()
{
	for(auto ED : container)
		m_EM->removeEvent(ED);
	container.clear();
}