#include "stdafx.h"
#include "Animation.h"

Animation::Animation(Displayable *img, int _frameCountX, int _frameCountY) : 
	Displayable(*img),
	frameCountX(_frameCountX),
	frameCountY(_frameCountY),
	frameCount(_frameCountX*_frameCountY),
	spaceX(0),
	spaceY(0),
	paused(true),
	animationTime(0)
{
}

Animation::Animation(Displayable *img, int _frameCountX, int _frameCountY, int _frameWidth, int _frameHeight)
	: 
	Displayable(*img),
	frameCountX(_frameCountX),
	frameCountY(_frameCountY),
	frameCount(_frameCountX*_frameCountY),
	spaceX(0),
	spaceY(0),
	paused(true),
	animationTime(0),
	frameWidth(_frameWidth),
	frameHeight(_frameHeight)
{
}


void Animation::setAnimationTime(int time)
{
	animationTime = time;
	timePerFrame = animationTime / frameCount;
}

void Animation::start()
{
	if(animationTime == 0)
		return;
	currentTime = 0;
	paused = false;
}

void Animation::start(int time)
{
	setAnimationTime(time);
	currentTime = 0;
	paused = false;
}
void Animation::start(int time, int frame)
{
	setAnimationTime(time);
	setAnimationFrame(frame);
	paused = false;
}

void Animation::setAnimationFrame(int frame)
{
	currentTime = timePerFrame * frame;
	currentFrame = frame;
}

bool Animation::pause()
{
	paused = !paused;
	return paused;
}

void Animation::tick()
{
	if(paused) 
		return;
	currentTime++;
	currentFrame = currentTime / timePerFrame;
	currentTime %= animationTime;
	setFrameBounds();
}

void Animation::setFrameBounds()
{
	int frameX = currentFrame % frameCountX;
	int frameY = currentFrame / frameCountX;
	sprite->setTextureRect(sf::IntRect( (frameWidth+spaceX) * frameX,(frameHeight+spaceY) * frameY,frameWidth,frameHeight)); //can be deleted, not sure.
}

void Animation::render(sf::RenderWindow *pRW)
{
	pRW->draw(*sprite);
}

void Animation::setPosition(int _x, int _y)
{
	sprite->setPosition((float)_x,(float)_y);
}

void Animation::setFrameSize(int width, int height)
{
	frameHeight = height;
	frameWidth = width;
}