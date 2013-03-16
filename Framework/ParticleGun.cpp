#include "ParticleGun.h"

ParticleGun::ParticleGun() :
	amount(0), interval(0), currentTime(0),
	deathTask(nullptr),
	isDead(false)
{
}

void ParticleGun::AddParticleLink(ParticleLink &link)
{
	particleChain.push_back(link);
}

void ParticleGun::AddParticleLink(ParticleState &first,ParticleState &second)
{
	particleChain.push_back(ParticleLink(first,second));
}

void ParticleGun::SetParameters(int _amount,int _interval)
{
	amount = _amount;
	interval = _interval;
	currentTime = 0;
}

void ParticleGun::Step(ParticleMaster *pM)
{
	if(interval == currentTime)
	for(int i = 0;i < amount;i++)
	{
		std::vector<ParticleState *>states = std::vector<ParticleState*>
			(particleChain.size(),nullptr);
		for(int x = 0;x < particleChain.size();x++)
		{
			ParticleState *nowy = new ParticleState(
				(particleChain[x].min.x + particleChain[x].min.y) / 2
		}
	}
}

