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
					ParticleState::Lerp(particleChain[x].min,particleChain[x].max,value));
				states[x] = nowy;
			}
			
			Particle *particle = new Particle(new Displayable(image));
			particle->SetStates(states);
			pM->Add(particle);
			currentTime=0;
		}
	currentTime++;
}

void ParticleGun::SetDeathTime(TasksMgr *taskMgr,float time)
{
	deathTask = taskMgr->registerTask(std::bind(Death),time);
}

void ParticleGun::Death()
{
	isDead = true;
}





