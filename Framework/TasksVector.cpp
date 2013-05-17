#include "stdafx.h"
#include "TasksVector.h"

#include "TasksMgr.h"

TasksVector::TasksVector(TasksMgr* TM)
    :
    std::vector<TaskData*>(),
    m_TM(TM)
{
}

TasksVector::~TasksVector()
{
    for(auto TD : *this)
        m_TM->removeTask(TD);
}


void TasksVector::addTask(TaskData *TD)
{
    push_back(TD);
}