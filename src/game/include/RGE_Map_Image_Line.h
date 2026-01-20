#pragma once
#include "common.h"

struct RGE_Map_Image_Line {
    short tile_row;
    short start_x;
    short line_len;
};
static_assert(sizeof(RGE_Map_Image_Line) == 0x6, "Size mismatch");
