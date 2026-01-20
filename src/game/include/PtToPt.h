#pragma once
#include "common.h"

struct PtToPt {
    int x;
    int y;
};
static_assert(sizeof(PtToPt) == 0x8, "Size mismatch");
