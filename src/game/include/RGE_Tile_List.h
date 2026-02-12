#pragma once
#include "common.h"

struct RGE_Tile_List {
    RGE_Tile_List() : list_size(0), num_active(0), new_count(0), collapse_list(0), list(nullptr) {}
    RGE_Tile_List(int param_1);
    void add_node(int param_1, int param_2);
    void del_list();

    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};
static_assert(sizeof(RGE_Tile_List) == 0x14, "Size mismatch");
