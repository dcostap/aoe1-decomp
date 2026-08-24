#include "../../include/task_lst_context.h"

// VA: 00509050 RGE_Task_List::delete_list
// PDB source: task_lst.cpp, lines 124-142

void RGE_Task_List::delete_list()
{
    short i = 0;

    if (list != 0) {
        if (list_num > 0) {
            do {
                RGE_Task* task = list[i];
                if (task != 0) {
                    delete task;
                    list[i] = 0;
                }
                ++i;
            } while (i < list_num);
        }

        free(list);
        list = 0;
    }

    list_num = 0;
}
