#pragma once
#include "common.h"

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};
static_assert(sizeof(RGE_Tile_Size) == 0x6, "Size mismatch");
