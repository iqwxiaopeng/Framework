#pragma once

class TaskTimer
{
public:
	TaskTimer(float _interval, float _time) : interval(_interval), time(_time)
	{}

	float interval; // how much time to wait before run the task
	float time; // how much time passed
};