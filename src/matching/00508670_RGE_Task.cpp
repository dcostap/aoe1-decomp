#include "../../include/task_context.h"

// VA: 00508670 RGE_Task::RGE_Task (short ctor)
// PDB source: task.cpp

RGE_Task::RGE_Task(short param_1)
{
    id = param_1;
    task_type = 1;
    is_default = 0;
    action_type = 0;
    object_group = 0;
    object_id = 0;
    terrain_id = -1;
    attribute_type = -1;
    attribute_type2 = -1;
    attribute_type3 = -1;
    attribute_type4 = -1;
    work_val1 = 0.0f;
    work_val2 = 0.0f;
    work_range = 0.0f;
    search_flag = 0;
    search_wait_time = 0.0f;
    combat_level = 0;
    combat_level_flag = 0;
    work_flag = 0;
    work_flag2 = 0;
    owner_type = 0;
    holding_attr = 0;
    state_building = 0;
    move_sprite = 0;
    work_sprite = 0;
    work_sprite2 = 0;
    carry_sprite = 0;
    work_sound = 0;
    work_sound2 = 0;
}
