#pragma once
#include "common.h"

struct RGE_SPick_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
    RGE_SPick_Info* next;
    RGE_SPick_Info* prev;
};
static_assert(sizeof(RGE_SPick_Info) == 0x14, "Size mismatch");
