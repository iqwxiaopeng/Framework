#include "stdafx.h"
#include "Animation.h"

Animation::Animation(Displayable *img, int _frameCountX, int _frameCountY) : 
	base(img),
	frameCountX(_frameCountX),
	frameCountY(_frameCountY),
	frameCount(_frameCountX*_frameCountY),
	spaceX(0),
	spaceY(0),
	pause(true),
	animationTime(0)
{
}

Animation::Animation(Displayable *img,int _frameCountX,int _frameCountY,int _frameWidth,int _frameHeight)
	: 
	image(img),
	frameCountX(_frameCountX),
	frameCountY(_frameCountY),
	frameCount(_frameCountX*_frameCountY),
	spaceX(0),
	spaceY(0),
	pause(true),
	animationTime(0),
	frameWidth(_frameWidth),
	frameHeight(_frameHeight)
{
}


void Animation::SetAnimationTime(int time)
{
	animationTime = time;
	timePerFrame = animationTime / frameCount;
}

void Animation::Start()
{
	if(animationTime == 0)
		return;
	currentTime = 0;
	pause = false;
}

void Animation::Start(int time)
{
	SetAnimationTime(time);
	currentTime = 0;
	pause = false;
}
void Animation::Start(int time,int frame)
{
	SetAnimationTime(time);
	SetAnimationFrame(frame);
	pause = false;
}

void Animation::SetAnimationFrame(int frame)
{
	currentTime = timePerFrame * frame;
	currentFrame = frame;
}

bool Animation::Pause()
{
	pause=pause?false:true;
	return pause;
}

void Animation::Tick(float frameTime)
{
	if(pause)return;
	currentTime++;
	currentFrame = currentTime / timePerFrame;
	currentTime %= animationTime;
	SetFrameBounds();
}

void Animation::SetFrameBounds()
{
	int frameX = currentFrame % frameCountX;
	int frameY = currentFrame / frameCountX;
	image->sprite->setTextureRect(sf::IntRect( (frameWidth+spaceX) * frameX,(frameHeight+spaceY) * frameY,frameWidth,frameHeight)); //can be deleted, not sure.
}

void Animation::Render(sf::RenderWindow *pRW)
{
	pRW->draw(*image->sprite);
}

void Animation::SetPosition(int _x,int _y)
{
	image->x = _x;
	image->y = _y;
	image->sprite->setPosition(_x,_y);
}

void Animation::SetFrameSize(int width,int height)
{
	frameHeight = height;
	frameWidth = width;
}