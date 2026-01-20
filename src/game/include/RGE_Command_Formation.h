#pragma once
#include "common.h"

struct RGE_Command_Formation {
    uchar command;
    int unitNum;
    int formationID;
};
static_assert(sizeof(RGE_Command_Formation) == 0xC, "Size mismatch");
