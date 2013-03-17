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
	friend class Event; // Event can access to propagateEvent()

	public:
		~EventsMgr();

		std::vector<std::list<EventData>*> funcs; // List of events

		#define registerEventMacro(eventName, type, ptr) \
			registerEvent<eventName> (type, std::bind(&ptr, std::placeholders::_1, std::placeholders::_2))
		#define registerEventMacroForClass(eventName, type, ptr, callerClass) \
			registerEvent<eventName> (type, std::bind(&callerClass::ptr, this, std::placeholders::_1, std::placeholders::_2))

		template <typename EVENT_TYPE>
		EventData* registerEvent(unsigned eventType, std::function<void(const EVENT_TYPE&, int)> funcPtr)
		{
			// Fit array size for new events
			while(funcs.size() <= eventType)
				funcs.push_back(new std::list<EventData>());

			// Cast from std::function<void(EVENT_TYPE*)> 
			// to		 std::function<void(   Event*  )>
			// by casting to void* then to target (used in inappriopriate way may be dangerous)
			functor fptr = *((functor*)((void*)(&funcPtr)));
			EventData ed(eventType, fptr);
			funcs[eventType]->push_back(ed); // Add event to list
			funcs[eventType]->rbegin()->ptr = --funcs[eventType]->rbegin().base();
			return &*funcs[eventType]->rbegin();
		}

		void removeEvent(EventData* ed);

	private:
		typedef std::function<void(const Event&, EventData*)> functor;
		template <typename EVENT_TYPE>
		void propagateEvent(const EVENT_TYPE &e)
		{
			// Iterate through all pointers for event and call them
			if(funcs.size() > (unsigned)e.type)
			{
				std::list<EventData>* funcList = funcs[e.type];
				for(auto it = funcList->begin(), next = it; it != funcList->end(); it = next++)
					it->executor(e, &*it);
			}
		}
};