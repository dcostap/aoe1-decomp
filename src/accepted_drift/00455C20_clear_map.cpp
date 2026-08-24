// VA: 00455C20 RGE_Map::clear_map
// Source: map.cpp lines 382-410
// 136 bytes, 59 asm instructions
// __thiscall, void, params: unsigned char param_1, unsigned char param_2 (ret 8)
//
// Attempt log:
// 1: natural struct types, for-loops, proper field assignments — 136/136, 89% diff
// 2: do-while loops — 128 bytes (8 short), missing stack slot
// 3: for-loop with function-scope y=0 — 136/136, 96% diff
// 4: raw pointer arithmetic — prologue matched perfectly (cmp [mem],reg), 36% diff
// 5: do-while with outer x=0 init, raw pointers — 27% diff, 113 equal bytes
// 6: field write order matching original asm — 25.7% diff, 122 equal bytes
// 7: struct members for inner writes — same 25.7% diff
//
// === ACCEPTED_DRIFT ===
// Remaining diff (35 positional / 23 edit bytes): all within the inner loop body.
// Prologue, outer loop, set_map_screen_pos tail, and epilogue match exactly.
// Specific differences:
// 1. Combined terrain value computed in DL (rebuilt) vs BL (original)
// 2. Param evaluation order: param_1 first (rebuilt) vs param_2 first (original)
// 3. Old terrain read/volatile store interleaved at different position
// 4. Field write order slightly different within loop body
// All differences are behavior-equivalent instruction scheduling/register choice —
// same values written to same tile fields, same combined result computed.

#include "..\..\include\game_globals.h"

#ifndef MAP_CONTEXT_H

struct RGE_Tile {
    short screen_xpos;              // +0x00
    short screen_ypos;              // +0x02
    unsigned char tile_type;         // +0x04
    unsigned char terrain_type;      // +0x05
    unsigned char border_type;       // +0x06
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
    void** map_row_offset;           // +0x8D8C
    char gap_8D90[0x40];

    void clear_map(unsigned char param_1, unsigned char param_2);
    void set_map_screen_pos(int arg1, int arg2, int arg3, int arg4);
};

#endif

void RGE_Map::clear_map(unsigned char param_1, unsigned char param_2)
{
    volatile unsigned char temp;
    int y = 0;

    if (*(int*)((char*)this + 0x0C) > 0) {
        do {
            RGE_Tile* row = ((RGE_Tile**)(*(char**)((char*)this + 0x8D8C)))[y];
            int x = 0;
            if (*(int*)((char*)this + 0x08) > 0) {
                do {
                    row->tile_type = 0;
                    temp = row->terrain_type;
                    row->border_type = 0;
                    row->screen_xpos = 0;
                    row->terrain_type = (unsigned char)((param_1 & 0x1F) | (param_2 << 5));
                    row->screen_ypos = 0;
                    row->last_drawn_as = 0;
                    row->last_drawn_shape = 0xFF;
                    row->draw_as = 0;
                    row->draw_attribute = 0;
                    row->last_drawn_shape2 = 0xFF;
                    row = (RGE_Tile*)((char*)row + 0x18);
                    x++;
                } while (x < *(int*)((char*)this + 0x08));
            }
            y++;
        } while (y < *(int*)((char*)this + 0x0C));
    }

    this->set_map_screen_pos(
        0, 0,
        *(int*)((char*)this + 0x08) - 1,
        *(int*)((char*)this + 0x0C) - 1
    );
}
