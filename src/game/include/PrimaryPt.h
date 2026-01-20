#pragma once
#include "common.h"

struct PrimaryPt {
    int x;
    int y;
};
static_assert(sizeof(PrimaryPt) == 0x8, "Size mismatch");
