#pragma once
#include "common.h"

struct RGE_Shallows_Info_Line {
    long x;
    long y;
};
static_assert(sizeof(RGE_Shallows_Info_Line) == 0x8, "Size mismatch");
