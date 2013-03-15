#pragma once

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class EventData;
class TaskData;

class Window
{
public:
	Window();
	virtual ~Window();

	std::vector<EventData*> events;
	std::vector<TaskData*> tasks;

	virtual void Step(float frameTime);
	virtual void Render(sf::RenderWindow *pRW);

	sf::Vector2f GetMousePos(const sf::RenderWindow& App) const;
};