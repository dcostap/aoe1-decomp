#pragma once
#include "common.h"

struct RGE_Command_Add_To_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
    float groupRange;
    int newUnit;
};
static_assert(sizeof(RGE_Command_Add_To_Group) == 0x10, "Size mismatch");
