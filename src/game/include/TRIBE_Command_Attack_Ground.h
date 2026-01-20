#pragma once
#include "common.h"

struct TRIBE_Command_Attack_Ground {
    uchar command;
    uchar unit_num;
    float location_x;
    float location_y;
};
static_assert(sizeof(TRIBE_Command_Attack_Ground) == 0xC, "Size mismatch");
