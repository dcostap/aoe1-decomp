#include "../../include/task_lst_context.h"

// VA: 00508EC0 RGE_Task_List::load(int, RGE_Sprite**, RGE_Sound**)
// PDB source: task_lst.cpp, lines 63-81

void RGE_Task_List::load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short task_type;
    RGE_Task_List* self = this;

    if (self->list)
        self->delete_list();

    rge_read(handle, &self->list_num, 2);
    if (self->list_num <= 0)
        return;

    self->list = (RGE_Task**)calloc(self->list_num, 4);
    for (int i = 0; (short)i < self->list_num; i++) {
        rge_read(handle, &task_type, 2);
        self->list[(short)i] = self->create_task(task_type, i);
        self->list[(short)i]->load(handle, sprites, sounds);
    }
}
