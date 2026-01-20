#pragma once
#include "common.h"

struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};
static_assert(sizeof(RGE_Elevation_Info_Line) == 0x18, "Size mismatch");
