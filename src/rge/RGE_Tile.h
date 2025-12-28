#pragma once
#include "RGE_Object_List.h"

// RGE_Tile - 24 bytes per layout.json
struct RGE_Tile {
    /* 0x00 */ short screen_xpos;
    /* 0x02 */ short screen_ypos;
    /* 0x04 */ uchar tile_type;
    
    // Bitfields (MSVC bitfield packing: these occupy the same byte offset 0x05)
    /* 0x05 */ uchar terrain_type : 5;
    /* 0x05 */ uchar height : 3;
    
    // bitfield at offset 0x06
    /* 0x06 */ uchar border_type : 4;
    /* 0x06 */ uchar border_shape : 4;
    
    /* 0x07 */ uchar last_drawn_as;
    /* 0x08 */ uchar last_drawn_shape;
    /* 0x09 */ uchar draw_as;
    /* 0x0A */ uchar draw_attribute;
    /* 0x0B */ uchar last_drawn_shape2;
    
    /* 0x0C */ struct RGE_Object_List objects; // size 12
};

// MANDATORY VERIFICATION
static_assert(sizeof(RGE_Tile) == 0x18, "RGE_Tile size mismatch");
static_assert(offsetof(RGE_Tile, objects) == 0x0C, "objects offset mismatch");
