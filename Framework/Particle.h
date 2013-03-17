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
	ParticleState(sf::Color, int _x, int _y, float _rotation, float _scale, int _t);
	ParticleState operator +  (ParticleState &rhp);
	ParticleState operator += (ParticleState &rhp);
	ParticleState operator -  (ParticleState &rhp);
	ParticleState operator -= (ParticleState &rhp);
	ParticleState operator /= (float rhp);
	ParticleState operator /  (float rhp);

	static ParticleState lerp(ParticleState &first, ParticleState &second, float amount);
	operator sf::Color();
	//inverts all values.
	ParticleState operator !();
};


class Particle
{
public:
	Particle(Displayable *);
	virtual ~Particle();


	void addState(ParticleState *);
	void setStates(std::vector<ParticleState *>);


	virtual void step();
	virtual void render(sf::RenderWindow*);
	bool end(); //return true if particle completed all states;

	Particle* copy(); //Copy the contents to create next particle that will behaviour
	//in the same way from t=0

protected:
	Displayable *image;
	std::vector<ParticleState *> states;
	ParticleState currentState, *changeState;
	int stage; // refers to current stance
	int currentTime;

	bool switchStage(); //false if not possible

private:
};