#include "stdafx.h"
#include "Particle.h"
Particle::Particle(Displayable *img) : image(img),stage(-1),currentTime(-1)
{
}

Particle::~Particle()
{
	for(unsigned int i = 0;i < states.size();i++)
		delete states[i];
}

void Particle::addState(ParticleState *state)
{
	if(stage == -1)
	{
		stage = 0;
		currentTime = 0;
		currentState =  *state;
	}
	else if(stage == 0 && changeState == NULL)
	{
		changeState = new ParticleState();
		*changeState = (*state - *states[0]) / (float)state->t;
	}
	states.push_back(state);
}
bool Particle::end()
{
	if(stage == (int)states.size() - 2 
		&& currentTime == states[stage+1]->t)
		return true;
	return false;
}

bool Particle::switchStage()
{
	if(end())return false;
	if(currentTime == states[stage+1]->t)
	{//Time for next state
		stage++;
		*changeState = (*states[stage+1] - *states[stage])/ (float)(states[stage+1]->t - states[stage]->t);
		return true;
	}
	return false;
}

void Particle::step()
{
	if(currentTime == states[stage+1]->t)
		if(!switchStage()) return; //End of animation
	currentState += *changeState;
	image->sprite->setPosition(currentState.x,currentState.y);
	image->sprite->setScale(currentState.scale,currentState.scale);
	image->sprite->setColor(currentState);
	image->sprite->setRotation(currentState.rotation);
	currentTime++;
}

void Particle::render(sf::RenderWindow *pRW)
{
	pRW->draw(*image->sprite);
}



void Particle::setStates(std::vector<ParticleState*> _states)
{
	 states = _states;
	 if(states.size() >= 1)
	{
		stage = 0;
		currentTime = 0;
		currentState =  *states[0];
	}
	if(states.size() >= 2)
	{
		changeState = new ParticleState();
		*changeState = (*states[1] - * states[0]) / (float)states[1]->t;
	}
}