#pragma once
#include "common.h"

class RGE_Random_Map_Module {
public:
    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};
static_assert(sizeof(RGE_Random_Map_Module) == 0x30, "Size mismatch");
