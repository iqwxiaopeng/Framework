#pragma once
#include "Window.h"

class EmptyWindow : public Window
{
	public:
		void step(float frameTime) override {}
		void render(sf::RenderWindow *pRW) override {}
};