#pragma once
#include "common.h"

struct RGE_Command_Create {
    uchar command;
    short obj_catagory;
    uchar player_id;
    float location_x;
    float location_y;
    float location_z;
};
static_assert(sizeof(RGE_Command_Create) == 0x14, "Size mismatch");
