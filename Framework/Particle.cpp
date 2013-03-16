#include "stdafx.h"
#include "Particle.h"


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
		*changeState = *state - *states[0];
	}
	states.push_back(state);
}
bool Particle::End()
{
	if(stage == states.size() - 1 
		&& currentTime == states[stage]->t)
		return true;
	return false;
}

bool Particle::SwitchStage()
{
	if(End())return false;
	if(currentTime == states[stage]->t)
	{//Time for next state
		stage++;
		currentState = *states[stage];
		*changeState = (*states[stage] - *states[stage-1])/ (float)(states[stage]->t - states[stage-1]->t);
		return true;
	}
	return false;
}

void Particle::Step()
{
	if(currentTime == states[stage]->t)
		if(!SwitchStage()) return; //End of animation
	currentState += *changeState;
	currentTime++;
}