#pragma once
#include "common.h"

struct TRIBE_Command_Build_Wall {
    uchar command;
    uchar unit_num;
    uchar unit_player_id;
    uchar x1;
    uchar y1;
    uchar x2;
    uchar y2;
    short obj_id;
    int unique_id;
};
static_assert(sizeof(TRIBE_Command_Build_Wall) == 0x10, "Size mismatch");
