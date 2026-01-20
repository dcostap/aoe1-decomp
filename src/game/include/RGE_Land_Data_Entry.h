#pragma once
#include "common.h"

struct RGE_Land_Data_Entry {
    long land_id;
    uchar terrain_type;
    long land_avoidance_tiles;
    long base_square_radius;
    uchar zone;
    uchar placement_type;
    long x;
    long y;
    uchar amount_of_land_used_percent;
    uchar by_player_flag;
    long radius;
    long fade;
    long clumpiness_factor;
};
static_assert(sizeof(RGE_Land_Data_Entry) == 0x2C, "Size mismatch");
