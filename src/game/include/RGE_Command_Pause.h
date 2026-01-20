#pragma once
#include "common.h"

struct RGE_Command_Pause {
    uchar command;
    uchar unit_num;
};
static_assert(sizeof(RGE_Command_Pause) == 0x2, "Size mismatch");
