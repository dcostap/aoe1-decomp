#pragma once
#include "common.h"

struct VISIBLE_RESOURCE_REC {
    int object_id;
    uchar distance;
    uchar zone;
    uchar pos_x;
    uchar pos_y;
};
static_assert(sizeof(VISIBLE_RESOURCE_REC) == 0x8, "Size mismatch");
