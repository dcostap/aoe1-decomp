#pragma once
#include "common.h"

struct RGE_Command_Stop {
    uchar command;
    uchar unit_num;
};
static_assert(sizeof(RGE_Command_Stop) == 0x2, "Size mismatch");
