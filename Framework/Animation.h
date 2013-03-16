#pragma once

#include <SFML\Graphics.hpp>

class Displayable;

class Animation
{
public :
	Animation(Displayable *img,int _frameCountX,int _frameCountY);

	//Starts animation functions
	//Start Animation with current AnimationTime
	void Start();
	//Starts Animation and sets AnimationTime
	void Start(int); 
	//Arg1 - AnimationTime
	//Arg2 - from which frame does animation start
	void Start(int,int); 

	void Stop(); //Return to 0 frame.
	void SetAnimationTime(int);
	void SetAnimationFrame(int);
	void SetPosition(float,float);
	//set spaces between frames.
	void SetSpaces(int,int);
	//Pause/Unpause animation. Returns the actual state of Pausing
	bool Pause();

	//Frame time is now ignored.
	void Tick(float frameTime);
	void Render(sf::RenderWindow *pRW);

	bool pause;

protected:
	Displayable *image;
	float posX,posY;
	int frameWidth,frameHeight;
	int frameCountX,frameCountY,frameCount;
	int animationTime,currentTime,timePerFrame,currentFrame;
	int spaceX,spaceY;

	void SetFrameBounds();

private:
};