#pragma once

#include <vector>
class EventsMgr;
class EventData;

class EventsVector : public std::vector<EventData*>
{
    public:
        EventsVector(EventsMgr*);
        ~EventsVector();

        void addEvent(EventData*); // alias for push_back
    protected:
    private:
        EventsMgr *m_EM;
};
