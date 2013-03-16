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

	virtual void step(float frameTime) = 0;
	virtual void render(sf::RenderWindow *pRW) = 0;

	sf::Vector2f getMousePos(const sf::RenderWindow& App) const;
};