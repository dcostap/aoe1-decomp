#include "../../include/task_lst_context.h"

// VA: 005090B0 RGE_Task_List::create_task
// PDB source: task_lst.cpp, lines 148-154
// Flags: config/flags/task_lst.rsp (/GX)

RGE_Task* RGE_Task_List::create_task(short task_type, short object_id)
{
    if (task_type != 1)
        return 0;

    RGE_Task* task = new RGE_Task(object_id);
    return task;
}
