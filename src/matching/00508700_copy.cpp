#include "../../include/task_context.h"

// VA: 00508700 RGE_Task::copy
// PDB source: task.cpp

void RGE_Task::copy(RGE_Task* src)
{
    is_default = src->is_default;
    action_type = src->action_type;
    object_group = src->object_group;
    object_id = src->object_id;
    terrain_id = src->terrain_id;
    attribute_type = src->attribute_type;
    attribute_type2 = src->attribute_type2;
    attribute_type3 = src->attribute_type3;
    attribute_type4 = src->attribute_type4;
    work_val1 = src->work_val1;
    work_val2 = src->work_val2;
    work_range = src->work_range;
    search_flag = src->search_flag;
    search_wait_time = src->search_wait_time;
    combat_level = src->combat_level;
    combat_level_flag = src->combat_level_flag;
    work_flag = src->work_flag;
    work_flag2 = src->work_flag2;
    owner_type = src->owner_type;
    holding_attr = src->holding_attr;
    state_building = src->state_building;
    move_sprite = src->move_sprite;
    work_sprite = src->work_sprite;
    work_sprite2 = src->work_sprite2;
    carry_sprite = src->carry_sprite;
    work_sound = src->work_sound;
    work_sound2 = src->work_sound2;
}
