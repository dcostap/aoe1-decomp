#pragma once
#include "common.h"

struct RGE_Map_Tile_Row {
    short image_line;
    uchar draw;
    short row_len;
    float col_step;
    float col_extra;
    short map_col;
    short map_row;
    short draw_wid;
    float draw_step;
    short num_tiles;
    float ratio;
};
static_assert(sizeof(RGE_Map_Tile_Row) == 0x24, "Size mismatch");
