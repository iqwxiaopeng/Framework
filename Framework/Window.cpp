#include "StdAfx.h"
#include "Window.h"

Window::Window()
{
}

Window::~Window()
{
}

sf::Vector2f Window::GetMousePos(const sf::RenderWindow& App) const
{
	// Get the local mouse position (relatively to a window)
	sf::Vector2i mousePos(sf::Mouse::getPosition(App));
	// Return global mouse position
	return App.mapPixelToCoords(mousePos);
}