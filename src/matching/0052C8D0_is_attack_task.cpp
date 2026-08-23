// ttsk_lst.cpp:299-304, exact anchor at 0052C8D0.
// The canonical task-list context is shared with get_target_task.
#include "..\..\include\ttsk_lst_context.h"

int TRIBE_Task_List::is_attack_task(RGE_Task* task) {
    if (task->action_type == 0x68) {
        return 1;
    }
    return RGE_Task_List::is_attack_task(task);
}
