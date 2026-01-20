#pragma once
#include "common.h"

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};
static_assert(sizeof(RGE_TOB_Picts) == 0x6, "Size mismatch");
