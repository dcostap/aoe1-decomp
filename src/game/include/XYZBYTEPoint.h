#pragma once
#include "common.h"

struct XYZBYTEPoint {
    uchar x;
    uchar y;
    uchar z;
};
static_assert(sizeof(XYZBYTEPoint) == 0x3, "Size mismatch");
