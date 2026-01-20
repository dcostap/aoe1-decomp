#pragma once
#include "common.h"

struct RGE_Time_Entry {
    float time;
    uchar command;
    short obj_type;
    uchar player;
    float x;
    float y;
    float z;
    short task;
    RGE_Static_Object* this_obj;
    short this_obj_id;
    RGE_Static_Object* target_obj;
    short target_obj_id;
    RGE_Time_Entry* next;
};
static_assert(sizeof(RGE_Time_Entry) == 0x30, "Size mismatch");
