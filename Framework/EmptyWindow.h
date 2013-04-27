#pragma once
#include "Window.h"

class EmptyWindow : public Window
{
	public:
		void step(float frameTime)         override { frameTime; }
		void render(sf::RenderWindow *pRW) override { pRW;       }
		void deactivate()                  override {            }
};