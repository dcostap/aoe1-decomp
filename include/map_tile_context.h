#ifndef MAP_TILE_CONTEXT_H
#define MAP_TILE_CONTEXT_H

// RGE_Tile is the 0x18-byte map.cpp record. Its terrain and height fields share +5.

#ifndef MAP_CONTEXT_TU
struct RGE_Tile {
    short screen_xpos_word;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char height : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
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
