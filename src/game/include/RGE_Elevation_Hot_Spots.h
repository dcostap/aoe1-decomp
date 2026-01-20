#pragma once
#include "common.h"

struct RGE_Elevation_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};
static_assert(sizeof(RGE_Elevation_Hot_Spots) == 0x10, "Size mismatch");
