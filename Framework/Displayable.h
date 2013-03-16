#pragma once

#include <SFML\Graphics.hpp>

class Displayable
{
	public:
		Displayable(sf::Sprite *);
		int x, y;
		sf::Sprite *sprite;

		virtual void draw(sf::RenderWindow* pRW)
		{
			pRW->draw(*sprite);
		}
};