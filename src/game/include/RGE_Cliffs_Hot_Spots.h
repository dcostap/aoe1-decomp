#pragma once
#include "common.h"

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};
static_assert(sizeof(RGE_Cliffs_Hot_Spots) == 0xC, "Size mismatch");
