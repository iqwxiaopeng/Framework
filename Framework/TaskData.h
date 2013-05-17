#pragma once
#include <functional>
#include <list>

class TaskData
{
private:
	typedef std::function<void(TaskData*)> functor;
	typedef std::list<TaskData>* funcs;
	TaskData(float _interval, functor _executor) : interval(_interval), executor(_executor)
	{}

	funcs listPtr;
	std::list<TaskData>::iterator ptr;
	float interval;
	functor executor;

	friend class TasksMgr; // Only Tasks needs using this...
};