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

	virtual void step(float frameTime) = 0;
	virtual void render(sf::RenderWindow *pRW) = 0;

	/* *There are performed operations that deactivate members of window that needs deactivation.
	   *For example GUI
	   */
	virtual void activate() = 0;
	virtual void deactivate() = 0;

	sf::Vector2f getMousePos(const sf::RenderWindow& App) const;
};