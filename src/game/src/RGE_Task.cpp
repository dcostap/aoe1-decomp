#include "../include/RGE_Task.h"

#include "../include/RGE_Sound.h"
#include "../include/RGE_Sprite.h"
#include "../include/globals.h"

#include <stdio.h>

RGE_Task::RGE_Task(short param_1) {
    this->id = param_1;
    this->task_type = 1;
    this->is_default = 0;
    this->action_type = 0;
    this->object_group = 0;
    this->object_id = 0;
    this->terrain_id = -1;
    this->attribute_type = -1;
    this->attribute_type2 = -1;
    this->attribute_type3 = -1;
    this->attribute_type4 = -1;
    this->work_val1 = 0.0f;
    this->work_val2 = 0.0f;
    this->work_range = 0.0f;
    this->search_flag = 0;
    this->search_wait_time = 0.0f;
    this->combat_level = 0;
    this->combat_level_flag = 0;
    this->work_flag = 0;
    this->work_flag2 = 0;
    this->owner_type = 0;
    this->holding_attr = 0;
    this->state_building = 0;
    this->move_sprite = nullptr;
    this->work_sprite = nullptr;
    this->work_sprite2 = nullptr;
    this->carry_sprite = nullptr;
    this->work_sound = nullptr;
    this->work_sound2 = nullptr;
}

RGE_Task::~RGE_Task() {}

void RGE_Task::copy(RGE_Task* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    this->is_default = param_1->is_default;
    this->action_type = param_1->action_type;
    this->object_group = param_1->object_group;
    this->object_id = param_1->object_id;
    this->terrain_id = param_1->terrain_id;
    this->attribute_type = param_1->attribute_type;
    this->attribute_type2 = param_1->attribute_type2;
    this->attribute_type3 = param_1->attribute_type3;
    this->attribute_type4 = param_1->attribute_type4;
    this->work_val1 = param_1->work_val1;
    this->work_val2 = param_1->work_val2;
    this->work_range = param_1->work_range;
    this->search_flag = param_1->search_flag;
    this->search_wait_time = param_1->search_wait_time;
    this->combat_level = param_1->combat_level;
    this->combat_level_flag = param_1->combat_level_flag;
    this->work_flag = param_1->work_flag;
    this->work_flag2 = param_1->work_flag2;
    this->owner_type = param_1->owner_type;
    this->holding_attr = param_1->holding_attr;
    this->state_building = param_1->state_building;
    this->move_sprite = param_1->move_sprite;
    this->work_sprite = param_1->work_sprite;
    this->work_sprite2 = param_1->work_sprite2;
    this->carry_sprite = param_1->carry_sprite;
    this->work_sound = param_1->work_sound;
    this->work_sound2 = param_1->work_sound2;
}

void RGE_Task::load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    short idx = -1;

    rge_read(param_1, &this->id, 2);
    rge_read(param_1, &this->is_default, 1);
    rge_read(param_1, &this->action_type, 2);
    rge_read(param_1, &this->object_group, 2);
    rge_read(param_1, &this->object_id, 2);
    rge_read(param_1, &this->terrain_id, 2);
    rge_read(param_1, &this->attribute_type, 2);
    rge_read(param_1, &this->attribute_type2, 2);
    rge_read(param_1, &this->attribute_type3, 2);
    rge_read(param_1, &this->attribute_type4, 2);
    rge_read(param_1, &this->work_val1, 4);
    rge_read(param_1, &this->work_val2, 4);
    rge_read(param_1, &this->work_range, 4);
    rge_read(param_1, &this->search_flag, 1);
    rge_read(param_1, &this->search_wait_time, 4);
    rge_read(param_1, &this->combat_level, 1);
    rge_read(param_1, &this->combat_level_flag, 1);
    rge_read(param_1, &this->work_flag, 2);
    rge_read(param_1, &this->work_flag2, 2);
    rge_read(param_1, &this->owner_type, 1);
    rge_read(param_1, &this->holding_attr, 1);
    rge_read(param_1, &this->state_building, 1);

    rge_read(param_1, &idx, 2);
    this->move_sprite = (idx >= 0 && param_2 != nullptr) ? param_2[idx] : nullptr;
    rge_read(param_1, &idx, 2);
    this->work_sprite = (idx >= 0 && param_2 != nullptr) ? param_2[idx] : nullptr;
    rge_read(param_1, &idx, 2);
    this->work_sprite2 = (idx >= 0 && param_2 != nullptr) ? param_2[idx] : nullptr;
    rge_read(param_1, &idx, 2);
    this->carry_sprite = (idx >= 0 && param_2 != nullptr) ? param_2[idx] : nullptr;
    rge_read(param_1, &idx, 2);
    this->work_sound = (idx >= 0 && param_3 != nullptr) ? param_3[idx] : nullptr;
    rge_read(param_1, &idx, 2);
    this->work_sound2 = (idx >= 0 && param_3 != nullptr) ? param_3[idx] : nullptr;
}

void RGE_Task::load(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    short tmp = 0;
    short move_sprite_id = -1;
    short work_sprite_id = -1;
    short work_sprite2_id = -1;
    short carry_sprite_id = -1;
    short work_sound_id = -1;
    short work_sound2_id = -1;
    short ignored0 = 0;
    short ignored1 = 0;

    fscanf(param_1, " %hd", &this->id);

    fscanf(param_1, " %hd", &tmp);
    this->is_default = (uchar)tmp;

    fscanf(param_1, " %hd", &this->action_type);
    fscanf(param_1, " %hd", &this->object_group);
    fscanf(param_1, " %hd", &this->object_id);
    fscanf(param_1, " %hd", &this->terrain_id);
    fscanf(param_1, " %hd", &this->attribute_type);
    fscanf(param_1, " %hd", &this->attribute_type2);
    fscanf(param_1, " %hd", &this->attribute_type3);
    fscanf(param_1, " %hd", &this->attribute_type4);
    fscanf(param_1, " %f", &this->work_val1);
    fscanf(param_1, " %f", &this->work_val2);
    fscanf(param_1, " %f", &this->work_range);

    fscanf(param_1, " %hd", &tmp);
    this->search_flag = (uchar)tmp;

    fscanf(param_1, " %f", &this->search_wait_time);

    fscanf(param_1, " %hd", &tmp);
    this->combat_level = (uchar)tmp;

    fscanf(param_1, " %hd", &tmp);
    this->combat_level_flag = (uchar)tmp;

    fscanf(param_1, " %hd", &this->work_flag);
    fscanf(param_1, " %hd", &this->work_flag2);

    fscanf(param_1, " %hd", &tmp);
    this->owner_type = (uchar)tmp;

    fscanf(param_1, " %hd", &tmp);
    this->holding_attr = (uchar)tmp;

    fscanf(param_1, " %hd", &tmp);
    this->state_building = (uchar)tmp;

    fscanf(param_1, " %hd", &move_sprite_id);
    fscanf(param_1, " %hd", &work_sprite_id);
    fscanf(param_1, " %hd", &work_sprite2_id);
    fscanf(param_1, " %hd", &carry_sprite_id);
    fscanf(param_1, " %hd", &work_sound_id);
    fscanf(param_1, " %hd", &work_sound2_id);
    fscanf(param_1, " %hd", &ignored0);
    fscanf(param_1, " %hd", &ignored1);

    this->move_sprite = (move_sprite_id >= 0 && param_2 != nullptr) ? param_2[move_sprite_id] : nullptr;
    this->work_sprite = (work_sprite_id >= 0 && param_2 != nullptr) ? param_2[work_sprite_id] : nullptr;
    this->work_sprite2 = (work_sprite2_id >= 0 && param_2 != nullptr) ? param_2[work_sprite2_id] : nullptr;
    this->carry_sprite = (carry_sprite_id >= 0 && param_2 != nullptr) ? param_2[carry_sprite_id] : nullptr;
    this->work_sound = (work_sound_id >= 0 && param_3 != nullptr) ? param_3[work_sound_id] : nullptr;
    this->work_sound2 = (work_sound2_id >= 0 && param_3 != nullptr) ? param_3[work_sound2_id] : nullptr;
}

void RGE_Task::save(int param_1) {
    short idx = -1;

    rge_write(param_1, &this->task_type, 2);
    rge_write(param_1, &this->id, 2);
    rge_write(param_1, &this->is_default, 1);
    rge_write(param_1, &this->action_type, 2);
    rge_write(param_1, &this->object_group, 2);
    rge_write(param_1, &this->object_id, 2);
    rge_write(param_1, &this->terrain_id, 2);
    rge_write(param_1, &this->attribute_type, 2);
    rge_write(param_1, &this->attribute_type2, 2);
    rge_write(param_1, &this->attribute_type3, 2);
    rge_write(param_1, &this->attribute_type4, 2);
    rge_write(param_1, &this->work_val1, 4);
    rge_write(param_1, &this->work_val2, 4);
    rge_write(param_1, &this->work_range, 4);
    rge_write(param_1, &this->search_flag, 1);
    rge_write(param_1, &this->search_wait_time, 4);
    rge_write(param_1, &this->combat_level, 1);
    rge_write(param_1, &this->combat_level_flag, 1);
    rge_write(param_1, &this->work_flag, 2);
    rge_write(param_1, &this->work_flag2, 2);
    rge_write(param_1, &this->owner_type, 1);
    rge_write(param_1, &this->holding_attr, 1);
    rge_write(param_1, &this->state_building, 1);

    idx = (this->move_sprite != nullptr) ? this->move_sprite->id : (short)-1;
    rge_write(param_1, &idx, 2);
    idx = (this->work_sprite != nullptr) ? this->work_sprite->id : (short)-1;
    rge_write(param_1, &idx, 2);
    idx = (this->work_sprite2 != nullptr) ? this->work_sprite2->id : (short)-1;
    rge_write(param_1, &idx, 2);
    idx = (this->carry_sprite != nullptr) ? this->carry_sprite->id : (short)-1;
    rge_write(param_1, &idx, 2);
    idx = (this->work_sound != nullptr) ? this->work_sound->id : (short)-1;
    rge_write(param_1, &idx, 2);
    idx = (this->work_sound2 != nullptr) ? this->work_sound2->id : (short)-1;
    rge_write(param_1, &idx, 2);
}
