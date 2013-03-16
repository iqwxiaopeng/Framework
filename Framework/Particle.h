#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"

struct ParticleState
{
	sf::Color color;
	int x,y;
	float rotation;
	float scale;
};


class Particle
{
public :
	Particle();
	

protected :
	std::vector<ParticleState> stances;

private :
};