#pragma once
#include "Particle.h"
class ParticleMaster
{
public :
	ParticleMaster();

	void Add(Particle *);
	void Delete(int index);
	void Delete(Particle *what);

	void Step();
	void Render(sf::RenderWindow *pRW);

	bool pause; //pauses the Step()
protected :
	std::vector<Particle*> particles;
private :

}