#pragma once
#include "common.h"

struct XYPoint {
    int x;
    int y;
};
static_assert(sizeof(XYPoint) == 0x8, "Size mismatch");
