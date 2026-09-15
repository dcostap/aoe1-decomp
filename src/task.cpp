#include "../include/task.h"
#include "../include/rge_fio.h"
#include "../include/sound.h"
#include "../include/sprite.h"



RGE_Task::RGE_Task(short id_in) {
    id = id_in;
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


RGE_Task::~RGE_Task() {
}


void RGE_Task::copy(RGE_Task* other_task) {
    is_default = other_task->is_default;
    action_type = other_task->action_type;
    object_group = other_task->object_group;
    object_id = other_task->object_id;
    terrain_id = other_task->terrain_id;
    attribute_type = other_task->attribute_type;
    attribute_type2 = other_task->attribute_type2;
    attribute_type3 = other_task->attribute_type3;
    attribute_type4 = other_task->attribute_type4;
    work_val1 = other_task->work_val1;
    work_val2 = other_task->work_val2;
    work_range = other_task->work_range;
    search_flag = other_task->search_flag;
    search_wait_time = other_task->search_wait_time;
    combat_level = other_task->combat_level;
    combat_level_flag = other_task->combat_level_flag;
    work_flag = other_task->work_flag;
    work_flag2 = other_task->work_flag2;
    owner_type = other_task->owner_type;
    holding_attr = other_task->holding_attr;
    state_building = other_task->state_building;
    move_sprite = other_task->move_sprite;
    work_sprite = other_task->work_sprite;
    work_sprite2 = other_task->work_sprite2;
    carry_sprite = other_task->carry_sprite;
    work_sound = other_task->work_sound;
    work_sound2 = other_task->work_sound2;
}


void RGE_Task::load(int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    short short_val;
    RGE_Sprite* selected_sprite;
    RGE_Sound* selected_sound;

    rge_read(infile, &id, 2);
    rge_read(infile, &is_default, 1);
    rge_read(infile, &action_type, 2);
    rge_read(infile, &object_group, 2);
    rge_read(infile, &object_id, 2);
    rge_read(infile, &terrain_id, 2);
    rge_read(infile, &attribute_type, 2);
    rge_read(infile, &attribute_type2, 2);
    rge_read(infile, &attribute_type3, 2);
    rge_read(infile, &attribute_type4, 2);
    rge_read(infile, &work_val1, 4);
    rge_read(infile, &work_val2, 4);
    rge_read(infile, &work_range, 4);
    rge_read(infile, &search_flag, 1);
    rge_read(infile, &search_wait_time, 4);
    rge_read(infile, &combat_level, 1);
    rge_read(infile, &combat_level_flag, 1);
    rge_read(infile, &work_flag, 2);
    rge_read(infile, &work_flag2, 2);
    rge_read(infile, &owner_type, 1);
    rge_read(infile, &holding_attr, 1);
    rge_read(infile, &state_building, 1);

    rge_read(infile, &short_val, 2);
    if (short_val == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[short_val];
    move_sprite = selected_sprite;

    rge_read(infile, &short_val, 2);
    if (short_val == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[short_val];
    work_sprite = selected_sprite;

    rge_read(infile, &short_val, 2);
    if (short_val == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[short_val];
    work_sprite2 = selected_sprite;

    rge_read(infile, &short_val, 2);
    if (short_val == -1)
        selected_sprite = (RGE_Sprite*)0;
    else
        selected_sprite = sprites[short_val];
    carry_sprite = selected_sprite;

    rge_read(infile, &short_val, 2);
    if (short_val == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[short_val];
    work_sound = selected_sound;

    rge_read(infile, &short_val, 2);
    if (short_val == -1)
        selected_sound = (RGE_Sound*)0;
    else
        selected_sound = sounds[short_val];
    work_sound2 = selected_sound;
}


extern int __cdecl fscanf(FILE* file, const char* format, ...);

void RGE_Task::load(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
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

    fscanf(infile, "%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %f %f %f %hd %f %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd",
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


void RGE_Task::save(int outfile) {
    short short_val;

    rge_write(outfile, &task_type, 2);
    rge_write(outfile, &id, 2);
    rge_write(outfile, &is_default, 1);
    rge_write(outfile, &action_type, 2);
    rge_write(outfile, &object_group, 2);
    rge_write(outfile, &object_id, 2);
    rge_write(outfile, &terrain_id, 2);
    rge_write(outfile, &attribute_type, 2);
    rge_write(outfile, &attribute_type2, 2);
    rge_write(outfile, &attribute_type3, 2);
    rge_write(outfile, &attribute_type4, 2);
    rge_write(outfile, &work_val1, 4);
    rge_write(outfile, &work_val2, 4);
    rge_write(outfile, &work_range, 4);
    rge_write(outfile, &search_flag, 1);
    rge_write(outfile, &search_wait_time, 4);
    rge_write(outfile, &combat_level, 1);
    rge_write(outfile, &combat_level_flag, 1);
    rge_write(outfile, &work_flag, 2);
    rge_write(outfile, &work_flag2, 2);
    rge_write(outfile, &owner_type, 1);
    rge_write(outfile, &holding_attr, 1);
    rge_write(outfile, &state_building, 1);

    // move_sprite ID
    if (move_sprite == 0) {
        short_val = -1;
    } else {
        short_val = move_sprite->id;
    }
    rge_write(outfile, &short_val, 2);

    // work_sprite ID
    if (work_sprite == 0) {
        short_val = -1;
    } else {
        short_val = work_sprite->id;
    }
    rge_write(outfile, &short_val, 2);

    // work_sprite2 ID
    if (work_sprite2 == 0) {
        short_val = -1;
    } else {
        short_val = work_sprite2->id;
    }
    rge_write(outfile, &short_val, 2);

    // carry_sprite ID
    if (carry_sprite == 0) {
        short_val = -1;
    } else {
        short_val = carry_sprite->id;
    }
    rge_write(outfile, &short_val, 2);

    // work_sound ID
    if (work_sound == 0) {
        short_val = -1;
    } else {
        short_val = work_sound->id;
    }
    rge_write(outfile, &short_val, 2);

    // work_sound2 ID
    if (work_sound2 == 0) {
        short_val = -1;
    } else {
        short_val = work_sound2->id;
    }
    rge_write(outfile, &short_val, 2);
}
