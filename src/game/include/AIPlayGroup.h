#pragma once
#include "common.h"

struct AIPlayGroup {
    uchar minValue[6];
    uchar maxValue[6];
};
static_assert(sizeof(AIPlayGroup) == 0xC, "Size mismatch");
