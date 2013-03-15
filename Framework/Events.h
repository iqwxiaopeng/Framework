#pragma once
#include "Event.h"
#include "EventTypes.h"
#include <SFML\Window\Event.hpp>

class KeyPressEvent : public Event
{
public:
	KeyPressEvent(sf::Event &_event) : Event(EventTypes::KEY_PRESS), event(_event)
	{}
	sf::Event &event;

private:
	KeyPressEvent& operator=(const KeyPressEvent&);
};

class MousePressEvent : public Event
{
public:
	MousePressEvent(sf::Event &_event) : Event(EventTypes::MOUSE_PRESS), event(_event)
	{}
	sf::Event &event;
private:
	MousePressEvent& operator=(const MousePressEvent&);
};

class MouseMoveEvent : public Event
{
public:
	MouseMoveEvent(sf::Event &_event) : Event(EventTypes::MOUSE_MOVE), event(_event)
	{
		mousePos.x = event.mouseMove.x;
		mousePos.y = event.mouseMove.y;
	}
	sf::Event &event;
	sf::Vector2i mousePos;
private:
	MouseMoveEvent& operator=(const MouseMoveEvent&);
};

class MouseWheelMoveEvent : public Event
{
public:
	MouseWheelMoveEvent(sf::Event &_event) : Event(EventTypes::MOUSE_WHEEL_MOVE), event(_event)
	{}
	sf::Event &event;
private:
	MouseWheelMoveEvent& operator=(const MouseWheelMoveEvent&);
};

class LostFocusEvent : public Event
{
public:
	LostFocusEvent(sf::Event &_event) : Event(EventTypes::LOST_FOCUS), event(_event)
	{}
	sf::Event &event;
private:
	LostFocusEvent& operator=(const LostFocusEvent&);
};