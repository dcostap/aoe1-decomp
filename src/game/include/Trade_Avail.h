#pragma once
#include "common.h"

struct Trade_Avail {
    RGE_Player* player;
    RGE_Static_Object* dock;
    float inventory;
};
static_assert(sizeof(Trade_Avail) == 0xC, "Size mismatch");
