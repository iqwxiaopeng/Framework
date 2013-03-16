#include "stdafx.h"
#include "ParticleMaster.h"

ParticleMaster::ParticleMaster()
{
}

void ParticleMaster::Add(Particle *part)
{
	particles.push_back(part);
}

void ParticleMaster::Delete(int index)
{
	delete particles[index];
	particles[index] = particles[particles.size()-1];
	particles.pop_back();
}

void ParticleMaster::Delete(Particle *wut)
{
	for(int i = 0;i < particles.size();i++)
		if(particles[i] == wut)
		{
			Delete(i);
			return;
		}
}

void ParticleMaster::Step()
{
	for(int i = 0;i < particles.size();i++)
	{
		particles[i]->Step();
		if(particles[i]->End())
		Delete(i);
	}
}

void ParticleMaster::Render(sf::RenderWindow *pRW)
{
	for(int i = 0; i < particles.size();i++)
	{
		particles[i]->Render(pRW);
	}
}