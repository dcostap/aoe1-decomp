#pragma once
#include "common.h"

struct RGE_Command_Destroy_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
};
static_assert(sizeof(RGE_Command_Destroy_Group) == 0x8, "Size mismatch");
