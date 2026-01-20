#pragma once
#include "common.h"

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;
    uchar base_terrain;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
};
static_assert(sizeof(RGE_Land_Info) == 0x1438, "Size mismatch");
