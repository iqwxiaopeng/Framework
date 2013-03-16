#include "stdafx.h"
#include "ParticleMaster.h"

ParticleMaster::ParticleMaster()
{
}

void ParticleMaster::add(Particle *part)
{
	particles.push_back(part);
}

void ParticleMaster::remove(int index)
{
	delete particles[index];
	particles[index] = particles[particles.size()-1];
	particles.pop_back();
}

void ParticleMaster::remove(Particle *wut)
{
	for(int i = 0;i < particles.size();i++)
		if(particles[i] == wut)
		{
			remove(i);
			return;
		}
}

void ParticleMaster::step()
{
	for(int i = 0;i < particles.size();i++)
	{
		particles[i]->step();
		if(particles[i]->end())
			remove(i);
	}
}

void ParticleMaster::render(sf::RenderWindow *pRW)
{
	for(int i = 0; i < particles.size();i++)
	{
		particles[i]->render(pRW);
	}
}