#pragma once
#include "common.h"

struct RGE_Command_Order {
    uchar command;
    RGE_Obj_Info target;
    uchar unit_num;
    float location_x;
    float location_y;
};
static_assert(sizeof(RGE_Command_Order) == 0x14, "Size mismatch");
