#pragma once

#include "stdafx.h"
class Displayable;

class Animation
{
public :
	Animation(Displayable img,int frameCountX,int frameCountY) :image(img)
		//Starts animation functions
		//Start Animation with current AnimationTime
	void StartAnimation();
	//Starts Animation and sets AnimationTime
	void StartAnimation(int); 
	//Arg1 - AnimationTime
	//Arg2 - from which frame does animation start
	void StartAnimation(int,int); 


	void StopAnimation(); //Return to 0 frame.
	void SetAnimationTime(int);
	//Pause/Unpause animation. Returns the actual state of Pausing
	bool PauseAnimation();



	bool pause;

private :
Displayable image;
int frameWidth,frameHeight;
int frameCountX,frameCountY,frameCount;
int animationTime,currentTime,timePerFrame;
protected :
};