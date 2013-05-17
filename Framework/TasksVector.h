#pragma once

#include <vector>
class TasksMgr;
class TaskData;

class TasksVector
{
    public:
        TasksVector(TasksMgr*);
        ~TasksVector();

        void addTask(TaskData*); // alias for push_back
		void removeTask(TaskData*);

		void clear();
    protected:
    private:
		std::vector<TaskData*> container;
        TasksMgr *m_TM;
};
