#include "stdafx.h"
#include "Particle.h"

Particle::Particle(Displayable *img) : image(img),stage(-1),currentTime(-1)
{
}

Particle::~Particle()
{
	for(int i = 0;i < states.size();i++)
		delete states[i];
}

void Particle::AddState(ParticleState *state)
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
		*changeState = (*state - *states[0]) / state->t;
	}
	states.push_back(state);
}
bool Particle::End()
{
	if(stage == states.size() - 2 
		&& currentTime == states[stage+1]->t)
		return true;
	return false;
}

bool Particle::SwitchStage()
{
	if(End())return false;
	if(currentTime == states[stage+1]->t)
	{//Time for next state
		stage++;
		currentState = *states[stage];
		*changeState = (*states[stage+1] - *states[stage])/ (states[stage+1]->t - states[stage]->t);
		return true;
	}
	return false;
}

void Particle::Step()
{
	if(currentTime == states[stage+1]->t)
		if(!SwitchStage()) return; //End of animation
	currentState += *changeState;
	image->sprite->setPosition(currentState.x,currentState.y);
	image->sprite->setScale(currentState.scale,currentState.scale);
	image->sprite->setColor(currentState);
	image->sprite->setRotation(currentState.rotation);
	currentTime++;
}

void Particle::Render(sf::RenderWindow *pRW)
{
	pRW->draw(*image->sprite);
}