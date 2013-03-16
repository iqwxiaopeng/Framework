#pragma once
#include "Displayable.h"
#include <SFML\Graphics.hpp>


class Animation : public Displayable
{
public:
	Animation(Displayable *img, int _frameCountX, int _frameCountY);
	Animation(Displayable *img, int _frameCountX, int _frameCountY, int _frameWidth, int _frameHeight);
	virtual ~Animation();
	//Starts animation functions
	//Start Animation with current AnimationTime
	void start();
	//Starts Animation and sets AnimationTime
	void start(int); 
	//Arg1 - AnimationTime
	//Arg2 - from which frame does animation start
	void start(int,int); 

	void stop(); //Return to 0 frame.
	void setAnimationTime(int);
	void setAnimationFrame(int);
	void setPosition(int, int);
	void setFrameSize(int, int);
	//set spaces between frames.
	void setSpaces(int, int);
	//Pause/Unpause animation. Returns the actual state of Pausing
	bool pause();

	//Frame time is now ignored.
	void tick(float frameTime);
	void render(sf::RenderWindow *pRW);

	bool paused;

protected:
	int frameWidth, frameHeight;
	int frameCountX, frameCountY, frameCount;
	int animationTime, currentTime, timePerFrame, currentFrame;
	int spaceX, spaceY;

	void setFrameBounds();

private:
};