#pragma once
#include "Particle.h"
class ParticleMaster
{
public :
	ParticleMaster();

	void add(Particle *);
	void remove(int index);
	void remove(Particle *what);

	void step();
	void render(sf::RenderWindow *pRW);
protected :
	std::vector<Particle*> particles;
private :
};