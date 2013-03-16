#include "stdafx.h"
#include "ParticleGun.h"
#include "Other.h"
ParticleGun::ParticleGun(Displayable disp) :
	amount(0), interval(0), currentTime(0),
	deathTask(nullptr),
	isDead(false),
	image(disp)
{
}


void ParticleGun::addParticleLink(ParticleLink &link)
{
	particleChain.push_back(link);
}


void ParticleGun::addParticleLink(ParticleState &first,ParticleState &second)
{
	particleChain.push_back(ParticleLink(first,second));
}


void ParticleGun::setParameters(int _amount,int _interval)
{
	amount = _amount;
	interval = _interval;
	currentTime = 0;
}


void ParticleGun::step(ParticleMaster *pM)
{
	if(isDead) return; //it's dead so no action.
	if(interval == currentTime)
		for(int i = 0;i < amount;i++)
		{
			
			std::vector<ParticleState *>states = std::vector<ParticleState*>
				(particleChain.size(),nullptr);
			
			for(int x = 0;x < particleChain.size();x++)
			{
				float value = (float)(utils::GetRandom() % 100) / 100.f;

				ParticleState *nowy = new ParticleState(
					ParticleState::lerp(particleChain[x].min,particleChain[x].max,value));
				states[x] = nowy;
			}
			
			Particle *particle = new Particle(new Displayable(image));
			particle->setStates(states);
			pM->add(particle);
			currentTime=0;
		}
	currentTime++;
}

void ParticleGun::setDeathTime(TasksMgr *taskMgr,float time)
{
	deathTask = taskMgr->registerTask(std::bind(&ParticleGun::death,this),time);
}

void ParticleGun::death()
{
	isDead = true;
}





