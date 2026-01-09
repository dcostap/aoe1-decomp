#pragma once
#include "common.h"

class RGE_Timeline {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Game_World* world;                   // 0x4
    RGE_Time_Entry* time_list;               // 0x8
    short list_num;                          // 0xC
    short avail_id;                          // 0xE
    float old_time;                          // 0x10

    RGE_Timeline(int param_1, RGE_Game_World* param_2);
    RGE_Timeline(RGE_Game_World* param_1);
    ~RGE_Timeline();
    void save(int param_1);
    void update();
    void mock_update(float param_1);
    short find_id(RGE_Static_Object* param_1);
    RGE_Time_Entry* add(float param_1);
    RGE_Time_Entry* add_attack(float param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3);
    RGE_Time_Entry* add_create(float param_1, short param_2, uchar param_3, float param_4, float param_5, float param_6);
    RGE_Time_Entry* add_move(float param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5);
    RGE_Time_Entry* add_delete(float param_1, RGE_Static_Object* param_2);
    void sub(RGE_Time_Entry* param_1);
};

static_assert(sizeof(RGE_Timeline) == 0x14, "RGE_Timeline Size Mismatch");

