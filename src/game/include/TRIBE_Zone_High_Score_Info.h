#pragma once
#include "common.h"

struct TRIBE_Zone_High_Score_Info {
    long score;
    uchar civ;
    char player_name[16];
    uchar num_allies;
};
static_assert(sizeof(TRIBE_Zone_High_Score_Info) == 0x18, "Size mismatch");
