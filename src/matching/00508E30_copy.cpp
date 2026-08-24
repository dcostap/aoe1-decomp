#include "../../include/task_lst_context.h"

// VA: 00508E30 RGE_Task_List::copy
// PDB source: task_lst.cpp, lines 42-58
//
// The loop index remains an ordinary short.  The original promotes the task
// type for the virtual create_task call and uses the short index for the list.

void RGE_Task_List::copy(RGE_Task_List* src)
{
    if (list)
        delete_list();

    list_num = src->list_num;
    if (list_num > 0) {
        list = (RGE_Task**)calloc((int)list_num, 4);
        for (short i = 0; i < list_num; i++) {
            list[i] = create_task(src->list[i]->task_type, i);
            list[i]->copy(src->list[i]);
        }
    }
}
