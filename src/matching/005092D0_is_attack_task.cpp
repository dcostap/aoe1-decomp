#include "../../include/task_lst_context.h"

// VA: 005092D0 RGE_Task_List::is_attack_task
// PDB source: task_lst.cpp, lines 242-247

int RGE_Task_List::is_attack_task(RGE_Task* task)
{
    return task->action_type == 7;
}
