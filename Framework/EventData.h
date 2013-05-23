#pragma once
#include <functional>
#include <list>

#include "Event.h"

class EventData
{
	public:
		typedef std::function<void(Event&, EventData*)> functor;

	private:
		EventData(unsigned _eventType, functor _executor) : eventType(_eventType), executor(_executor)
		{}

		std::list<EventData>::iterator ptr;
		unsigned eventType;
		functor executor;

		friend class EventsMgr; // Only EventManager needs using this...
};