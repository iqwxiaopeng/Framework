#pragma once

#include <vector>
class TasksMgr;
class TaskData;

class TasksVector : public std::vector<TaskData*>
{
    public:
        TasksVector(TasksMgr*);
        ~TasksVector();

        void addTask(TaskData*); // alias for push_back
    protected:
    private:
        TasksMgr *m_TM;
};
