#pragma once
#include "common.h"

struct TRIBE_Cliff_Info {
    long info[4];
};
static_assert(sizeof(TRIBE_Cliff_Info) == 0x10, "Size mismatch");
