#pragma once
#include "common.h"

struct RGE_Task {
    RGE_Task(short param_1);
    ~RGE_Task();

    void copy(RGE_Task* param_1);
    void load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    void load(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    void save(int param_1);

    short task_type;
    short id;
    uchar is_default;
    short action_type;
    short object_group;
    short object_id;
    uchar combat_level;
    uchar combat_level_flag;
    short terrain_id;
    uchar owner_type;
    uchar holding_attr;
    uchar state_building;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    uchar search_flag;
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;
};
static_assert(sizeof(RGE_Task) == 0x4C, "Size mismatch");
