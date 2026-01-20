#pragma once
#include "common.h"

struct TRIBE_Command_Build {
    uchar command;
    uchar unit_num;
    uchar unit_player_id;
    float location_x;
    float location_y;
    short obj_id;
    int unique_id;
};
static_assert(sizeof(TRIBE_Command_Build) == 0x14, "Size mismatch");
