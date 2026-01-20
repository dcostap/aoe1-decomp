#pragma once
#include "common.h"

struct Shape_Offsets {
    long shape;
    long palette;
};
static_assert(sizeof(Shape_Offsets) == 0x8, "Size mismatch");
