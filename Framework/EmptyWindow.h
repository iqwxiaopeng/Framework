#pragma once
#include "Window.h"

class EmptyWindow : public Window
{
public:
	void Step(float32 frameTime) override {}
	void Render(sf::RenderWindow *pRW) override {}
};