#include "Animation.h"
#include "stdafx.h"

void Animation::SetAnimationTime(int time)
{
	animationTime = time;
	timePerFrame = animationTime / frameCount;
}

void Animation::StartAnimation()
{
	currentTime = 0;
}

void Animation::StartAnimation(int time)
{
	SetAnimationTime(time);
	currentTime = 0;
}
void Animation::StartAnimation(int time,int frame)
{
	SetAnimationTime(time);

}