#pragma once
#include "Displayable.h"
#include <SFML\Graphics.hpp>


class Animation
{
public :
	Animation(Displayable *img,int _frameCountX,int _frameCountY);
	Animation(Displayable *img,int _frameCountX,int _frameCountY,int _frameWidth,int _frameHeight);
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
	void SetPosition(int,int);
	void SetFrameSize(int,int);
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
	int frameWidth,frameHeight;
	int frameCountX,frameCountY,frameCount;
	int animationTime,currentTime,timePerFrame,currentFrame;
	int spaceX,spaceY;

	void SetFrameBounds();

private:
};