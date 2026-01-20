#pragma once
#include "common.h"

struct RGE_Command_Remove_From_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
    int unit;
};
static_assert(sizeof(RGE_Command_Remove_From_Group) == 0xC, "Size mismatch");
