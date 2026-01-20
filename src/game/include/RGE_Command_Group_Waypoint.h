#pragma once
#include "common.h"

struct RGE_Command_Group_Waypoint {
    uchar command;
    uchar unit_num;
    uchar x;
    uchar y;
};
static_assert(sizeof(RGE_Command_Group_Waypoint) == 0x4, "Size mismatch");
