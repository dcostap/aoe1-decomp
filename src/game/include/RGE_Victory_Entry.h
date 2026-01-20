#pragma once
#include "common.h"

struct RGE_Victory_Entry {
    uchar command;
    long obj_type;
    RGE_Player* target_player;
    float x0;
    float y0;
    float x1;
    float y1;
    long number;
    long count;
    RGE_Static_Object* this_obj;
    RGE_Static_Object* target_obj;
    uchar victory_group;
    uchar ally_flag;
    uchar state;
    uchar checked_flag;
    RGE_Victory_Entry* next;
};
static_assert(sizeof(RGE_Victory_Entry) == 0x34, "Size mismatch");
