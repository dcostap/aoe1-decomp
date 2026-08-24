#include "../../include/task_context.h"

// VA: 00508BB0 RGE_Task::save
// PDB source: task.cpp, lines 223-267
// Branch inversion fix: use if (ptr == 0) for move/work/work2 sprites.

void RGE_Task::save(int fd)
{
    short id_val;

    rge_write(fd, &task_type, 2);
    rge_write(fd, &id, 2);
    rge_write(fd, &is_default, 1);
    rge_write(fd, &action_type, 2);
    rge_write(fd, &object_group, 2);
    rge_write(fd, &object_id, 2);
    rge_write(fd, &terrain_id, 2);
    rge_write(fd, &attribute_type, 2);
    rge_write(fd, &attribute_type2, 2);
    rge_write(fd, &attribute_type3, 2);
    rge_write(fd, &attribute_type4, 2);
    rge_write(fd, &work_val1, 4);
    rge_write(fd, &work_val2, 4);
    rge_write(fd, &work_range, 4);
    rge_write(fd, &search_flag, 1);
    rge_write(fd, &search_wait_time, 4);
    rge_write(fd, &combat_level, 1);
    rge_write(fd, &combat_level_flag, 1);
    rge_write(fd, &work_flag, 2);
    rge_write(fd, &work_flag2, 2);
    rge_write(fd, &owner_type, 1);
    rge_write(fd, &holding_attr, 1);
    rge_write(fd, &state_building, 1);

    // move_sprite ID
    if (move_sprite == 0) {
        id_val = -1;
    } else {
        id_val = *(short*)((char*)move_sprite + 0x72);
    }
    rge_write(fd, &id_val, 2);

    // work_sprite ID
    if (work_sprite == 0) {
        id_val = -1;
    } else {
        id_val = *(short*)((char*)work_sprite + 0x72);
    }
    rge_write(fd, &id_val, 2);

    // work_sprite2 ID
    if (work_sprite2 == 0) {
        id_val = -1;
    } else {
        id_val = *(short*)((char*)work_sprite2 + 0x72);
    }
    rge_write(fd, &id_val, 2);

    // carry_sprite ID
    if (carry_sprite == 0) {
        id_val = -1;
    } else {
        id_val = *(short*)((char*)carry_sprite + 0x72);
    }
    rge_write(fd, &id_val, 2);

    // work_sound ID
    if (work_sound == 0) {
        id_val = -1;
    } else {
        id_val = *(short*)((char*)work_sound + 0x0C);
    }
    rge_write(fd, &id_val, 2);

    // work_sound2 ID
    if (work_sound2 == 0) {
        id_val = -1;
    } else {
        id_val = *(short*)((char*)work_sound2 + 0x0C);
    }
    rge_write(fd, &id_val, 2);
}
