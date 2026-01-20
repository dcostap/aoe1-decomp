#pragma once
#include "common.h"

struct RGE_Command_Add_Waypoint {
    uchar command;
    uchar player_id;
    int recipient;
    uchar numberWaypoints;
    XYZBYTEPoint waypoint[5];
};
static_assert(sizeof(RGE_Command_Add_Waypoint) == 0x18, "Size mismatch");
