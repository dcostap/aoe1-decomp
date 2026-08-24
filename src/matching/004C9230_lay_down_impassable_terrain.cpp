// 004C9230 TRIBE_Building_Object::lay_down_impassable_terrain (t_b_obj.cpp:704-744, 292B)
// Lays down impassable terrain under a building by modifying tile terrain types (values 0, 1, 6).
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Baseline reconstructed the canonical terrain/building/map ownership, FPU
//   evaluation order, field offsets, and typed row/column tile loops.
// - A natural switch on the masked terrain codes 0, 1, and 6 reproduces the
//   original VC5 `sub; je; dec; je; sub; jne` dispatch exactly.
// - FPU eval order: x_start→x_end→y_start→y_end (matched by declaration order)
// - Terrain type map: 0→(b&0xF0)|0x10, 1→(b&0xEF)|0x0F, 6→(b&0xEE)|0x0E
// - Three-level indirection: building→obj→map (same as lay_down_passable_terrain)
// - Tile access: `*(tile_data + row*4) + col*24` at byte offset 5
// - Main-agent audit restored typed master/owner/world/map/tile ownership. The
//   row cursor remains byte-offset-shaped because the binary proves this exact
//   access schedule; emitted code remains exact.

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::lay_down_impassable_terrain() {
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
                    case 0:
                        tile->terrain = (b & 0xF0) | 0x10;
                        break;
                    case 1:
                        tile->terrain = (b & 0xEF) | 0x0F;
                        break;
                    case 6:
                        tile->terrain = (b & 0xEE) | 0x0E;
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
