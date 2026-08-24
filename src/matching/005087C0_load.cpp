#include "../../include/task_context.h"

// VA: 005087C0 RGE_Task::load
// PDB source: task.cpp, lines 103-149
// Attempt log:
// - Baseline reconstruction: typed RGE_Task layout, sequential rge_read field
//   loads, and sprite/sound ID resolution from the supplied tables.
// - Probe 2: kept one selected pointer per sprite/sound table and stored the
//   selected value after each ID branch, matching the binary's common stores.

void RGE_Task::load(int fd, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short id_value;
    RGE_Sprite* selected_sprite;
    RGE_Sound* selected_sound;

    rge_read(fd, &id, 2);
    rge_read(fd, &is_default, 1);
    rge_read(fd, &action_type, 2);
    rge_read(fd, &object_group, 2);
    rge_read(fd, &object_id, 2);
    rge_read(fd, &terrain_id, 2);
    rge_read(fd, &attribute_type, 2);
    rge_read(fd, &attribute_type2, 2);
    rge_read(fd, &attribute_type3, 2);
    rge_read(fd, &attribute_type4, 2);
    rge_read(fd, &work_val1, 4);
    rge_read(fd, &work_val2, 4);
    rge_read(fd, &work_range, 4);
    rge_read(fd, &search_flag, 1);
    rge_read(fd, &search_wait_time, 4);
    rge_read(fd, &combat_level, 1);
    rge_read(fd, &combat_level_flag, 1);
    rge_read(fd, &work_flag, 2);
    rge_read(fd, &work_flag2, 2);
    rge_read(fd, &owner_type, 1);
    rge_read(fd, &holding_attr, 1);
    rge_read(fd, &state_building, 1);

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    move_sprite = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    work_sprite = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    work_sprite2 = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[id_value];
    carry_sprite = selected_sprite;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[id_value];
    work_sound = selected_sound;

    rge_read(fd, &id_value, 2);
    if (id_value == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[id_value];
    work_sound2 = selected_sound;
}
