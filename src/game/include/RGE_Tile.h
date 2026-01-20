#pragma once
#include "common.h"

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar:5 terrain_type;
    uchar:3 height;
    uchar:4 border_type;
    uchar:4 border_shape;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    RGE_Object_List objects;
};
static_assert(sizeof(RGE_Tile) == 0x18, "Size mismatch");
