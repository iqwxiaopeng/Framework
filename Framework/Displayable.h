#pragma once
class ResourcesMgr;
#include <SFML\Graphics.hpp>

class Displayable
{
	public:
		Displayable(sf::Sprite *);
		virtual ~Displayable();
		int x, y;
		sf::Sprite *sprite;

		virtual void draw(sf::RenderWindow* pRW)
		{
			pRW->draw(*sprite);
		}
		virtual void setSprite(std::string filename,ResourcesMgr *rMgr,bool resetRect = false);
};