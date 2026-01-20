#pragma once
#include "common.h"

struct XYZ {
    int xValue;
    int yValue;
    int zValue;
};
static_assert(sizeof(XYZ) == 0xC, "Size mismatch");
