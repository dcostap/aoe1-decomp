#pragma once
#include "common.h"

struct RGE_Command_Create_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
    float groupRange;
    int unitsToGroup[25];
    uchar numberUnitsToGroup;
};
static_assert(sizeof(RGE_Command_Create_Group) == 0x74, "Size mismatch");
