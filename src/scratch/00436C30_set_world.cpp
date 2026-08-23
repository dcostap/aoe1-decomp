// 00436C30 RGE_Diamond_Map::set_world (diam_map.cpp:227-354)
// Attempt log:
// - PDB evidence owns this method to diam_map.cpp after set_bitmap and before
//   set_player. The shared diam_map declarations provide the class and slot.
// - The PDB locals are line, tile_row, draw_wid, tot_draw_wid, and col_step.
//   Their source order restores the original stack homes.
// - Repeating row_len_tiles/line_len for draw_step lets VC5 keep the quotient
//   live. This reduced the mismatch from 690 bytes to 148 bytes.
// - The current build has exact size, frame, saved registers, and all 7 calls.
//   Bytes are exact through +0x147 and again from +0x22A to the boundary.
// - BLOCKER: the target materializes row length before line length, duplicates
//   ST1, and keeps the quotient in extended precision. VC5 instead spills the
//   quotient as float and reloads it. This can change rounded map geometry.
// - A raw-row field interpretation increased the frame to 0x18. The source
//   keeps the simpler ratio ownership until stronger source evidence exists.
// - BINARY NOTE: each image line publishes tile_row before row-table writes.
// - BINARY NOTE: the second pass updates source_row only for a drawn row.

#include <stdlib.h>

#include "../../include/diam_map_context.h"

extern "C" long __cdecl __ftol(void);
extern const float DAT_0056f5fc;
extern const float DAT_0056f600;
extern const float DAT_0056f604;

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

void RGE_Diamond_Map::set_world(RGE_Game_World* world)
{
    short line;
    float tile_row;
    short draw_wid;
    short tot_draw_wid;
    float col_step;

    this->world = world;
    if (world != 0 && this->map_image_lines != 0) {
    this->map = world->map;
    this->map_wid = (short)this->map->map_width;
    this->map_tile_row_cnt =
        this->map_wid +
        (this->map_hgt = (short)this->map->map_height) - 1;

    if (this->map_tile_rows != 0) {
        free(this->map_tile_rows);
    }
    this->map_tile_rows = (RGE_Map_Tile_Row*)calloc(this->map_tile_row_cnt, 0x24);

    tile_row = 0;
    this->map_row_step = (float)this->map_tile_row_cnt /
                         (float)this->map_image_hgt;
    if (this->map_tile_row_cnt > this->map_image_hgt) {
        tile_row = ((float)this->map_tile_row_cnt /
                    (float)this->map_image_hgt) * 0.5f;
    }

    float ratio_sum = 0.0f;
    tot_draw_wid = 0;
    line = 0;
    if (this->map_image_hgt > 0) {
        do {
            short line_len =
                this->map_image_lines[line].line_len;
            short row = (short)tile_row;

            if (row >= this->map_tile_row_cnt) {
                row = this->map_tile_row_cnt - 1;
            }

            this->map_image_lines[line].tile_row = row;

            short row_len_tiles;
            if (row < this->map_wid) {
                row_len_tiles = this->map_hgt;
                if (row < row_len_tiles) {
                    row_len_tiles = row + 1;
                }
            } else {
                row_len_tiles = this->map_hgt - row - 1 + this->map_wid;
            }

            col_step = (float)row_len_tiles / (float)line_len;
            float draw_step =
                DAT_0056f604 /
                ((float)row_len_tiles / (float)line_len);
            draw_wid = (short)draw_step;
            if ((float)draw_wid != draw_step) {
                ++draw_wid;
            }

            this->map_tile_rows[row].image_line = line;
            this->map_tile_rows[row].draw = 1;
            this->map_tile_rows[row].row_len = row_len_tiles;
            this->map_tile_rows[row].col_step = col_step;
            this->map_tile_rows[row].draw_wid = draw_wid;
            this->map_tile_rows[row].draw_step = draw_step;
            this->map_tile_rows[row].num_tiles =
                (short)((float)line_len / draw_step);
            this->map_tile_rows[row].ratio = draw_step / (float)line_len;
            this->map_tile_rows[row].col_extra =
                this->map_tile_rows[row].ratio < DAT_0056f604
                    ? col_step * DAT_0056f600
                    : DAT_0056f5fc;

            if (row < this->map_wid) {
                this->map_tile_rows[row].map_row = 0;
                this->map_tile_rows[row].map_col = this->map_wid - row - 1;
            } else {
                this->map_tile_rows[row].map_row = row - this->map_wid + 1;
                this->map_tile_rows[row].map_col = 0;
            }

            tot_draw_wid += draw_wid;
            ratio_sum += this->map_tile_rows[row].ratio;
            ++line;
            tile_row += this->map_row_step;
        } while (line < this->map_image_hgt);
    }

    float draw_height = DAT_0056f604 / this->map_row_step;
    this->map_tile_draw_hgt = (short)draw_height;
    if ((float)this->map_tile_draw_hgt != draw_height) {
        ++this->map_tile_draw_hgt;
    }

    this->map_tile_draw_wid = tot_draw_wid / this->map_image_hgt;
    if (this->map_tile_draw_wid == 0) {
        this->map_tile_draw_wid = 1;
    }

    this->map_col_ratio = ratio_sum / (float)this->map_image_hgt;
    this->map_row_ratio = (float)this->map_image_hgt /
                          (float)this->map_tile_row_cnt;

    short row = 0;
    short source_row = 0;
    if (this->map_tile_row_cnt > 0) {
        do {
            unsigned char draw = this->map_tile_rows[row].draw;
            if (draw != 0) {
                source_row = row;
            } else {
                this->map_tile_rows[row].image_line = this->map_tile_rows[source_row].image_line;
                this->map_tile_rows[row].row_len = this->map_tile_rows[source_row].row_len;
                this->map_tile_rows[row].col_step = this->map_tile_rows[source_row].col_step;
                this->map_tile_rows[row].draw_wid = this->map_tile_rows[source_row].draw_wid;
                this->map_tile_rows[row].draw_step = this->map_tile_rows[source_row].draw_step;
                this->map_tile_rows[row].num_tiles = this->map_tile_rows[source_row].num_tiles;
                this->map_tile_rows[row].ratio = this->map_tile_rows[source_row].ratio;
                this->map_tile_rows[row].col_extra = this->map_tile_rows[source_row].col_extra;
            }
            ++row;
        } while (row < this->map_tile_row_cnt);
    }

    this->view_col = -1;
    this->view_row = -1;
        this->set_redraw(TPanel::redraw_all);
        return;
    }

    this->map = 0;
}
