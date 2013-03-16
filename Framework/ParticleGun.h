#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "Particle.h"
#include "ParticleMaster.h"
#include "TasksMgr.h"
//help struct
struct ParticleLink
{
	ParticleLink(ParticleState &first,ParticleState &second) 
		:min(first),max(second)
	{
	}
		ParticleState min,max;
};

class ParticleGun
{
public :
	ParticleGun();
	ParticleGun(float x,float y,float width,float height);
	ParticleGun(sf::FloatRect&);
	
	//start Rect
	void SetRectangle(sf::FloatRect );

	//Chain
	void AddParticleLink(ParticleLink&);
	void AddParticleLink(ParticleState &first,ParticleState &second);

	//Params
	void SetParameters(int _amount,int _interval);

	//Work
	void Step(ParticleMaster *pM);

	//Death
	void SetDeathTime(float time);


protected :
	sf::FloatRect particleStart;
	std::vector<ParticleLink> particleChain;
	int amount,interval,currentTime;  // <amount> defines amount of particles created per <interval>
	TaskData *deathTask;
	
private:
};