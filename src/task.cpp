#include "../include/task.h"
#include "../include/sprite.h"

// PDB source: C:\\msdev\\work\\age1_x1\\task.cpp
// The definitions follow the original task.cpp source order.

// PDB lines 26-57; VA 00508670.

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

// PDB lines 62-62; VA 005086F0.

RGE_Task::~RGE_Task()
{
}

// PDB lines 68-98; VA 00508700.

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

// PDB lines 103-149; VA 005087C0.

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

// PDB lines 154-218; VA 00508A20.

extern int __cdecl fscanf(FILE* file, const char* format, ...);

void RGE_Task::load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short temp_is_default;
    short temp_combat_level;
    short temp_combat_level_flag;
    short temp_search_flag;
    short temp_owner_type;
    short temp_holding_attr;
    short temp_state_building;
    short move_sprite_id;
    short work_sprite_id;
    short work_sprite2_id;
    short carry_sprite_id;
    short work_sound_id;
    short work_sound2_id;
    RGE_Sprite* selected_sprite;
    RGE_Sound* selected_sound;

    fscanf(file, "%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %f %hd %f %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd",
        &id, &temp_is_default, &action_type,
        &object_group, &object_id, &terrain_id,
        &attribute_type, &attribute_type2, &attribute_type3, &attribute_type4,
        &work_val1, &work_val2, &work_range,
        &temp_search_flag, &search_wait_time,
        &temp_combat_level, &temp_combat_level_flag,
        &work_flag, &work_flag2, &temp_owner_type,
        &temp_holding_attr, &temp_state_building,
        &move_sprite_id, &work_sprite_id, &work_sprite2_id, &carry_sprite_id,
        &work_sound_id, &work_sound2_id);

    is_default = (unsigned char)temp_is_default;
    combat_level = (unsigned char)temp_combat_level;
    combat_level_flag = (unsigned char)temp_combat_level_flag;
    search_flag = (unsigned char)temp_search_flag;
    owner_type = (unsigned char)temp_owner_type;
    holding_attr = (unsigned char)temp_holding_attr;
    state_building = (unsigned char)temp_state_building;

    if (move_sprite_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[move_sprite_id];
    move_sprite = selected_sprite;

    if (work_sprite_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[work_sprite_id];
    work_sprite = selected_sprite;

    if (work_sprite2_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[work_sprite2_id];
    work_sprite2 = selected_sprite;

    if (carry_sprite_id == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[carry_sprite_id];
    carry_sprite = selected_sprite;

    if (work_sound_id == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[work_sound_id];
    work_sound = selected_sound;

    if (work_sound2_id == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[work_sound2_id];
    work_sound2 = selected_sound;
}

// PDB lines 223-267; VA 00508BB0.

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
        id_val = move_sprite->id;
    }
    rge_write(fd, &id_val, 2);

    // work_sprite ID
    if (work_sprite == 0) {
        id_val = -1;
    } else {
        id_val = work_sprite->id;
    }
    rge_write(fd, &id_val, 2);

    // work_sprite2 ID
    if (work_sprite2 == 0) {
        id_val = -1;
    } else {
        id_val = work_sprite2->id;
    }
    rge_write(fd, &id_val, 2);

    // carry_sprite ID
    if (carry_sprite == 0) {
        id_val = -1;
    } else {
        id_val = carry_sprite->id;
    }
    rge_write(fd, &id_val, 2);

    // work_sound ID
    if (work_sound == 0) {
        id_val = -1;
    } else {
        id_val = work_sound->id;
    }
    rge_write(fd, &id_val, 2);

    // work_sound2 ID
    if (work_sound2 == 0) {
        id_val = -1;
    } else {
        id_val = work_sound2->id;
    }
    rge_write(fd, &id_val, 2);
}
