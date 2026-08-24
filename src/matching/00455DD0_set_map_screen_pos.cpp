// RGE_Map::set_map_screen_pos
// VA: 00455DD0
// Attempt log:
// 1 baseline: canonical RGE_Map/RGE_Tile ownership with natural clipping and
//    nested row/column screen-position loops; exact-sized, 4 differing bytes.
// 2 control-flow: put the tile-pointer increment before the column increment
//    in the inner loop update, matching the original add-eax/inc-esi order;
//    exact 266-byte match.
// Main-agent audit restored canonical RGE_Map virtual ownership and its map
// field at +0x04; emitted code remains exact.

#include "../../include/game_globals.h"

#ifndef MAP_CONTEXT_H

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char gap_0C[0x0C];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x0A];
    short tile_half_height;
    short tile_half_width;
    short elev_height;

    void set_map_screen_pos(int col0, int row0, int col1, int row1);
};

#endif

void RGE_Map::set_map_screen_pos(int col0, int row0, int col1, int row1)
{
    if (col0 < 0) {
        col0 = 0;
    } else if (col0 > this->map_width - 1) {
        col0 = this->map_width - 1;
    }

    if (row0 < 0) {
        row0 = 0;
    } else if (row0 > this->map_height - 1) {
        row0 = this->map_height - 1;
    }

    if (col1 < 0) {
        col1 = 0;
    } else if (col1 > this->map_width - 1) {
        col1 = this->map_width - 1;
    }

    if (row1 < 0) {
        row1 = 0;
    } else if (row1 > this->map_height - 1) {
        row1 = this->map_height - 1;
    }

    for (; row0 <= row1; ++row0) {
        RGE_Tile* tile = this->map_row_offset[row0] + col0;
        for (int col = col0; col <= col1; ++tile, ++col) {
            tile->screen_xpos = (short)(row0 + col) * this->tile_half_width;
            tile->screen_ypos = (short)(row0 - col) * this->tile_half_height
                              - (short)(tile->terrain_type >> 5) * this->elev_height;

            switch (tile->tile_type) {
            case 2:
            case 6:
            case 8:
            case 10:
            case 14:
            case 15:
            case 16:
                tile->screen_ypos -= this->elev_height;
                break;
            }
        }
    }
}
