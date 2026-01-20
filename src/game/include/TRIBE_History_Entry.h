#pragma once
#include "common.h"

struct TRIBE_History_Entry {
    uchar population;
};
static_assert(sizeof(TRIBE_History_Entry) == 0x1, "Size mismatch");
