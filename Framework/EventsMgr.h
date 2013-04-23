#pragma once

#include <vector>
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


class EventsMgr
{
private:
	typedef std::function<void(const Event&, EventData*)> functor;
	friend class Event; // Event can access to propagateEvent()

	public:
		~EventsMgr();

		std::vector<std::list<EventData>*> funcs; // List of events

		#define registerEventMacro(eventName, type, ptr) \
			registerEvent<eventName> ((unsigned)type, std::bind(&ptr, std::placeholders::_1, std::placeholders::_2))
		#define registerEventMacroForClass(eventName, type, ptr, callerClass) \
			registerEvent<eventName> ((unsigned)type, std::bind(&callerClass::ptr, this, std::placeholders::_1, std::placeholders::_2))

		template <typename EVENT_TYPE>
		EventData* registerEvent(unsigned eventType, std::function<void(const EVENT_TYPE&, EventData*)> funcPtr);
		EventData* registerEvent(unsigned eventType, functor funcPtr);
		
		/** Function removes event from event manager but does not destroy the array
		  * @param is used to specify which event remove from the list
		  */
		void removeEvent(EventData* ed);
		void propagateEvent(const Event &e);
};


template <typename EVENT_TYPE>
EventData* EventsMgr::registerEvent(unsigned eventType, std::function<void(const EVENT_TYPE&, EventData*)> funcPtr)
{
	// Cast from std::function<void(EVENT_TYPE&, EventData*)> 
	// to		 std::function<void(   Event&  , EventData*)>
	// by casting to void* then to target (used in inappriopriate way may be dangerous)
	functor fptr = *((functor*)((void*)(&funcPtr)));
	return registerEvent(eventType, fptr);
}