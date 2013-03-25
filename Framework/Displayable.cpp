#include "stdafx.h"
#include "Displayable.h"
#include "ResourcesMgr.h"

Displayable::Displayable(std::string texture, ResourcesMgr *pRM) : sprite(new sf::Sprite)
{
	setSprite(texture, pRM);
}


Displayable::Displayable(sf::Sprite *_sprite) : sprite(_sprite)
{
}

//Displayable::Displayable() : sprite(new sf::Sprite) {}

Displayable::~Displayable()
{
	delete sprite;
}

/* Set sprites texture to texture defined in provided ResourceManager.
 * It's only keeping reference to texture.
 * You can also reset origin and size of the rectangle defined in sprite by setting resetRect to true
 */
void Displayable::setSprite(std::string filename, ResourcesMgr *rMgr, bool resetRect)
{
	sprite->setTexture(*rMgr->textures[filename], resetRect);

	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin((float)bounds.width / 2.f,(float)bounds.height / 2.f);
}