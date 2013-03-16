#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"

struct ParticleState
{
	float r,g,b,a;
	float x,y;
	float rotation;
	float scale;
	int t;// Refers to tick time when ParticleStates switches;

	ParticleState();
	ParticleState(sf::Color ,int _x,int _y,float _rotation,float _scale,int _t);
	ParticleState operator +(ParticleState &rhp);
	ParticleState operator += (ParticleState &rhp);
	ParticleState operator -(ParticleState &rhp);
	ParticleState operator -=(ParticleState &rhp);
	ParticleState operator /= (float rhp);
	ParticleState operator /(float rhp);

	static ParticleState Lerp(ParticleState &first,ParticleState &second,float amount);
	operator sf::Color();
	//inverts all values.
	ParticleState operator !();
};


class Particle
{
public :
	Particle(Displayable *);
	virtual ~Particle();


	void AddState(ParticleState *);
	void SetStates(std::vector<ParticleState *>);


	virtual void Step();
	virtual void Render(sf::RenderWindow*);
	bool End(); //return true if particle completed all states;

	Particle* Copy(); //Copy the contents to create next particle that will behaviour
	//in the same way from t=0

protected :
	Displayable *image;
	std::vector<ParticleState *> states;
	ParticleState currentState,*changeState;
	int stage; // refers to current stance
	int currentTime;

	bool SwitchStage(); //false if not possible

private :
};