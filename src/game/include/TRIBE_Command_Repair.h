#pragma once
#include "common.h"

struct TRIBE_Command_Repair {
    uchar command;
    uchar unit_num;
    RGE_Obj_Info target;
};
static_assert(sizeof(TRIBE_Command_Repair) == 0x8, "Size mismatch");
