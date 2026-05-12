// VA: 00455C20 RGE_Map::clear_map
// Source: map.cpp lines 382-410
// 136 bytes, 59 asm instructions
// __thiscall, void, params: unsigned char param_1, unsigned char param_2 (ret 8)
// Attempt 1: natural reconstruction with proper struct definitions

#include "..\..\include\game_globals.h"

struct RGE_Tile {
    short screen_xpos;              // +0x00
    short screen_ypos;              // +0x02
    unsigned char tile_type;         // +0x04
    unsigned char terrain_type;      // +0x05 (5-bit field)
    unsigned char border_type;       // +0x06 (4-bit field)
    unsigned char last_drawn_as;     // +0x07
    unsigned char last_drawn_shape;  // +0x08
    unsigned char draw_as;           // +0x09
    unsigned char draw_attribute;    // +0x0A
    unsigned char last_drawn_shape2; // +0x0B
    char gap_0C[0x0C];              // +0x0C objects
};

struct RGE_Map {
    char gap_00[0x08];
    int map_width;                   // +0x08
    int map_height;                  // +0x0C
    char gap_10[0x8D7C];            // +0x10 to +0x8D8B
    RGE_Tile** map_row_offset;       // +0x8D8C
    char gap_8D90[0x40];            // skip to end-ish

    void clear_map(unsigned char param_1, unsigned char param_2);
    void set_map_screen_pos(int arg1, int arg2, int arg3, int arg4);
};

void RGE_Map::clear_map(unsigned char param_1, unsigned char param_2)
{
    if (this->map_height > 0) {
        int y = 0;
        do {
            RGE_Tile* row = this->map_row_offset[y];
            if (this->map_width > 0) {
                int x = 0;
                do {
                    row->screen_xpos = 0;
                    row->screen_ypos = 0;
                    row->tile_type = 0;
                    row->terrain_type = (unsigned char)((param_1 & 0x1F) | (param_2 << 5));
                    row->border_type = 0;
                    row->last_drawn_as = 0;
                    row->last_drawn_shape = 0xFF;
                    row->draw_as = 0;
                    row->draw_attribute = 0;
                    row->last_drawn_shape2 = 0xFF;
                    row++;
                    x++;
                } while (x < this->map_width);
            }
            y++;
        } while (y < this->map_height);
    }
    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
}
