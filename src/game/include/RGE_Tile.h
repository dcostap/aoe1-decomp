#pragma once
#include "common.h"
#include "RGE_Object_List.h"

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type : 5;
    uchar height : 3;
    uchar border_type : 4;
    uchar border_shape : 4;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    RGE_Object_List objects;
};
static_assert(sizeof(RGE_Tile) == 0x18, "Size mismatch");
