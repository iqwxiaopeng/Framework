#include "stdafx.h"

#include "Event.h"
#include "EventsMgr.h"

Event::Event(int _type) : result(EventResults::DEFAULT), type(_type)
{}

// allow event
void Event::allow()
{
	result = EventResults::ALLOW;
}

// deny event
void Event::deny()
{
	result = EventResults::DENY;
}

void Event::setDefault()
{
	allow();
}

void Event::propagate(EventsMgr* pEM)
{
	pEM->propagateEvent(*this);
}