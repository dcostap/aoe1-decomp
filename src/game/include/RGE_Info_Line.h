#pragma once
#include "common.h"

struct RGE_Info_Line {
    float clump_num;
    short percent_of_tiles_covered;
    short percent_updown;
    short min_elevation;
    short max_elevation;
    short terrain_type;
    short terrain_base;
    char obj_id;
};
static_assert(sizeof(RGE_Info_Line) == 0x14, "Size mismatch");
