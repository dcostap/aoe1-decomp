#pragma once
#include "common.h"

struct RGE_Tile_List {
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};
static_assert(sizeof(RGE_Tile_List) == 0x14, "Size mismatch");
