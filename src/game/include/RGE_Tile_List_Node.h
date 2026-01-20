#pragma once
#include "common.h"

struct RGE_Tile_List_Node {
    int col;
    int row;
};
static_assert(sizeof(RGE_Tile_List_Node) == 0x8, "Size mismatch");
