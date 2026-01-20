#pragma once
#include "common.h"

struct DDCOLORKEY {
    ulong dwColorSpaceLowValue;
    ulong dwColorSpaceHighValue;
};
static_assert(sizeof(DDCOLORKEY) == 0x8, "Size mismatch");
