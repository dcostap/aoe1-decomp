#pragma once
#include "common.h"

struct VISIBLE_UNIT_REC {
    int object_id;
    uchar distance;
    uchar player;
    uchar pos_x;
    uchar pos_y;
};
static_assert(sizeof(VISIBLE_UNIT_REC) == 0x8, "Size mismatch");
