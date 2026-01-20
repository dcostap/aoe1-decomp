#pragma once
#include "common.h"

struct TRIBE_Master_Cliff_Info {
    long id;
    long facet;
    long id2;
    long facet2;
    TRIBE_Cliff_Info info;
    float offset_x;
    float offset_y;
};
static_assert(sizeof(TRIBE_Master_Cliff_Info) == 0x28, "Size mismatch");
