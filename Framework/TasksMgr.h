#pragma once
#include <vector>
#include <functional>
#include <list>

#include "TaskData.h"
#include "TaskTimer.h"
#include "TasksVector.h"


class TasksMgr
{
private:
	typedef std::function<void(TaskData*)> functor;
	typedef std::list<TaskData>* funcs;
	typedef std::vector<std::pair<TaskTimer*, funcs>>::iterator iterator;
	typedef std::list<TaskData>::iterator tasksIterator;

public:
	~TasksMgr();

	// time - time passed since last step
	void step(float time);

	template<class Class>
	TaskData* registerTask(void(Class::*functionPointer)(TaskData*), Class* object, float interval)
	{
		return registerTask(std::bind(functionPointer, object, std::placeholders::_1), interval);
	}
	TaskData* registerTask(void(*functionPointer)(TaskData*), float interval)
	{
		return registerTask(std::bind(functionPointer, std::placeholders::_1), interval);
	}
	TaskData* registerTask(functor funcPointer, float interval);

	void removeTask(TaskData *td);

private:
	std::vector<std::pair<TaskTimer*, std::list<TaskData>*>> tasks;
};