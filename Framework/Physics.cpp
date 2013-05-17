#include "stdafx.h"
#include "Physics.h"


bool Utils::collision(const sf::IntRect& first, const sf::IntRect& second)
{
	return first.intersects(second);
}