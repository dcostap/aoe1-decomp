#pragma once
#include "common.h"

struct XYZPoint {
    int x;
    int y;
    int z;
};
static_assert(sizeof(XYZPoint) == 0xC, "Size mismatch");
