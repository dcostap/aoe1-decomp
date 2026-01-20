#pragma once
#include "common.h"

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};
static_assert(sizeof(RGE_Pick_Info) == 0x14, "Size mismatch");
