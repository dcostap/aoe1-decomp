// 004C9360 TRIBE_Building_Object::lay_down_passable_terrain (t_b_obj.cpp:748-788, 288B)
// Lays down passable terrain under the building by modifying tile terrain types.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Baseline reconstructed the canonical terrain/building/map ownership and
//   matched the frame, calls, loops, FPU order, and tile accesses; only the
//   terrain-state dispatch differed by an extra `test edx,edx`.
// - A natural switch on the three passable terrain codes (0x0E, 0x0F, 0x10)
//   reproduces the original `sub; je; dec; je; dec; jne` dispatch exactly.
// - FPU eval order: x_start → x_end → y_start → y_end (matched by declaration order)
// - Tile access uses byte offsets (row*4 for pointer array, col*24 per tile)
// - State updates: 14→(b&0xE6)|6, 15→(b&0xE1)|1, 16→b&0xE0 (others unchanged)
// - Main-agent audit restored typed master/owner/world/map/tile ownership. The
//   byte-offset row cursor remains because the binary proves that exact access
//   schedule; emitted code remains exact.

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::lay_down_passable_terrain() {
    GameMap* map = this->owner->world->map;

    if (this->master_obj->passable_terrain > -1) {
        return;
    }

    short x_start = (short)(x - this->master_obj->footprint_x);
    short x_end = (short)(this->master_obj->footprint_x + x - 10.0f);
    short y_start = (short)(y - this->master_obj->footprint_y);
    short y_end_val = (short)(this->master_obj->footprint_y + y - 10.0f);

    if (x_start < 0) x_start = 0;
    if (y_start < 0) y_start = 0;

    if (x_end >= map->width) x_end = (short)(map->width - 1);
    if (y_end_val >= map->height) y_end_val = (short)(map->height - 1);

    if (y_start <= y_end_val) {
        int row_offset = (int)y_start * 4;
        int row_count = (int)y_end_val - (int)y_start + 1;

        do {
            if (x_start <= x_end) {
                int col_offset = (int)x_start * 24;
                int col_count = (int)x_end - (int)x_start + 1;

                do {
                    RGE_Tile* tile = (RGE_Tile*)((char*)*(RGE_Tile**)
                        ((char*)map->tile_data + row_offset) + col_offset);
                    unsigned char b = tile->terrain;
                    switch (b & 0x1F) {
                    case 0x0E:
                        tile->terrain = (b & 0xE6) | 6;
                        break;
                    case 0x0F:
                        tile->terrain = (b & 0xE1) | 1;
                        break;
                    case 0x10:
                        tile->terrain = b & 0xE0;
                        break;
                    default:
                        break;
                    }
                    col_offset += 24;
                    col_count--;
                } while (col_count != 0);
            }
            row_offset += 4;
            row_count--;
        } while (row_count != 0);
    }
}
