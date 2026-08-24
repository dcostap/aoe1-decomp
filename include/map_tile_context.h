#ifndef MAP_TILE_CONTEXT_H
#define MAP_TILE_CONTEXT_H

// RGE_Tile is the 0x18-byte map.cpp record. The packed terrain byte is +5.

#ifndef MAP_CONTEXT_TU
struct RGE_Tile {
    short screen_xpos_word;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_elevation;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    unsigned char gap_0C[0x0C];
};
#endif

typedef char map_tile_size_check[(sizeof(RGE_Tile) == 0x18) ? 1 : -1];

#endif
