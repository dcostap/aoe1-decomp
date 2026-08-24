#include "../../include/task_lst_context.h"

// VA: 00508E20 RGE_Task_List::~RGE_Task_List
// PDB source: task_lst.cpp, lines 35-36

RGE_Task_List::~RGE_Task_List()
{
    delete_list();
}
