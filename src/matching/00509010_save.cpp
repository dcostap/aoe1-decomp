#include "../../include/task_lst_context.h"

// VA: 00509010 RGE_Task_List::save
// PDB source: task_lst.cpp, lines 112-119

void RGE_Task_List::save(int fd)
{
    rge_write(fd, &list_num, 2);
    for (short i = 0; i < list_num; ++i)
        list[i]->save(fd);
}
