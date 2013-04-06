#pragma once
#include <string>

class EventResults
{
public:
	enum result
	{
		DENY, ALLOW, DEFAULT
	};
};

class EventsMgr;

class Event
{
public:
	Event(int _type);

	EventResults::result result;
	int type;

	void allow(); // allow event
	void deny(); // deny event
	virtual void setDefault();

	void propagate(EventsMgr *pEM);
	
private:
	// DO NOT IMPLEMENT
	Event(const Event&);
	Event& operator=(const Event&);
};
