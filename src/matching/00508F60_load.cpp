#include "../../include/task_lst_context.h"

// VA: 00508F60 RGE_Task_List::load(FILE*, RGE_Sprite**, RGE_Sound**)
// PDB source: task_lst.cpp, lines 86-107

void RGE_Task_List::load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short task_type;

    if (list)
        delete_list();

    fscanf(file, "%hd", &list_num);
    if (list_num > 0) {
        list = (RGE_Task**)calloc((int)list_num, 4);
        for (int i = 0; (short)i < list_num; i++) {
            fscanf(file, "%hd", &task_type);
            list[(short)i] = create_task(task_type, i);
            list[(short)i]->load(file, sprites, sounds);
        }
    }
}
