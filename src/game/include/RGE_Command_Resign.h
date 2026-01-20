#pragma once
#include "common.h"

struct RGE_Command_Resign {
    uchar command;
    uchar player_id;
    uchar comm_player_id;
    uchar dropped;
};
static_assert(sizeof(RGE_Command_Resign) == 0x4, "Size mismatch");
