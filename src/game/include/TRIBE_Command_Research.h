#pragma once
#include "common.h"

struct TRIBE_Command_Research {
    uchar command;
    int unit_id;
    uchar unit_player_id;
    short tech_id;
    int unique_id;
};
static_assert(sizeof(TRIBE_Command_Research) == 0x10, "Size mismatch");
