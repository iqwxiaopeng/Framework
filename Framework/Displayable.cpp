#include "stdafx.h"
#include "Displayable.h"
#include "ResourcesMgr.h"

Displayable::Displayable() : sprite(new sf::Sprite)
{

}


Displayable::Displayable(sf::Sprite *_sprite) : sprite(_sprite)
{
}

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
}