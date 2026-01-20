#pragma once
#include "common.h"

struct LOSTBL {
    int y_delta;
    int x_left;
    int x_right;
};
static_assert(sizeof(LOSTBL) == 0xC, "Size mismatch");
