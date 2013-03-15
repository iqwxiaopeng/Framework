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
	static EventsMgr *pEM;
	Event(int _type);

	EventResults::result result;
	int type;

	void allow(); // allow event
	void deny(); // deny event
	virtual void setDefault();
	void propagate();
};
