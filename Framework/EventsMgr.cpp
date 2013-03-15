#include "stdafx.h"

#include "EventsMgr.h"

EventsMgr::~EventsMgr()
{
	for(auto it : funcs)
		delete it; // std::list<EventData>*
}

void EventsMgr::removeEvent(EventData* ed)
{
	funcs[ed->eventType]->erase(ed->ptr);
}