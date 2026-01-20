#pragma once
#include "common.h"

struct RGE_Shallows_Info {
    RGE_Shallows_Info_Line shallows[99];
    long shallows_num;
};
static_assert(sizeof(RGE_Shallows_Info) == 0x31C, "Size mismatch");
