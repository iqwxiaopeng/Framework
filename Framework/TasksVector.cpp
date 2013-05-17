#include "stdafx.h"
#include "TasksVector.h"

#include "TasksMgr.h"

#include "Utils.h"

TasksVector::TasksVector(TasksMgr* TM)
    :
    m_TM(TM)
{
}

TasksVector::~TasksVector()
{
	clear();
}


void TasksVector::addTask(TaskData *TD)
{
    container.push_back(TD);
}


void TasksVector::removeTask(TaskData *TD)
{
	for(auto it = container.begin(); it != container.end(); ++it)
		if(TD == *it)
		{
			container.erase(it);
			break;
		}
}


void TasksVector::clear()
{
	for(auto TD : container)
        m_TM->removeTask(TD);
	container.clear();
}