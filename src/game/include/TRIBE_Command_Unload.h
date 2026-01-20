#pragma once
#include "common.h"

struct TRIBE_Command_Unload {
    uchar command;
    uchar unit_num;
    float location_x;
    float location_y;
};
static_assert(sizeof(TRIBE_Command_Unload) == 0xC, "Size mismatch");
