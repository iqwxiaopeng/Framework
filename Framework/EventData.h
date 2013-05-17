#pragma once
#include <functional>
#include <list>

#include "Event.h"

class EventData
{
	private:
		typedef std::function<void(const Event&, EventData*)> functor;
		EventData(unsigned _eventType, functor _executor) : eventType(_eventType), executor(_executor)
		{}

		std::list<EventData>::iterator ptr;
		unsigned eventType;
		functor executor;

		friend class EventsMgr; // Only EventManager needs using this...
};