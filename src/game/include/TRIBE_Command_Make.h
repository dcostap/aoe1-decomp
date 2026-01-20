#pragma once
#include "common.h"

struct TRIBE_Command_Make {
    uchar command;
    int unit_id;
    uchar unit_player_id;
    short obj_id;
    int unique_id;
};
static_assert(sizeof(TRIBE_Command_Make) == 0x10, "Size mismatch");
