#pragma once
#include "common.h"

struct TRIBE_Command_Explore {
    uchar command;
    uchar numUnits;
    uchar unit_player_id;
    float targetXPosition;
    float targetYPosition;
};
static_assert(sizeof(TRIBE_Command_Explore) == 0xC, "Size mismatch");
