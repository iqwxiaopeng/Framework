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
		: min(first), max(second)
	{
	}
		ParticleState min, max;
};

class ParticleGun
{
public:
	ParticleGun(Displayable disp);

	//Chain
	void addParticleLink(ParticleLink&);
	void addParticleLink(ParticleState first, ParticleState second);

	//Params
	void setParameters(int _amount, int _interval);

	//Work
	void step(ParticleMaster *pM);

	//Position
	void setPosition(float x,float y);

	//Death
	void setDeathTime(TasksMgr *taskMgr, float time);
	void death(TaskData*);


protected:
	float x,y; // Position where gun is located
	Displayable image;
	std::vector<ParticleLink> particleChain;
	int amount, interval, currentTime;  // <amount> defines amount of particles created per <interval>
	TaskData *deathTask;
	bool isDead;
	
private:
};