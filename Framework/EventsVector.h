#pragma once

#include <vector>
class EventsMgr;
class EventData;

class EventsVector
{
    public:
        EventsVector(EventsMgr*);
        ~EventsVector();

        void addEvent(EventData*); // alias for push_back
		void removeEvent(EventData*);

		void clear();
    protected:
    private:
		std::vector<EventData*> container;
        EventsMgr *m_EM;
};
