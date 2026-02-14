#pragma once
#include "common.h"
#include "RGE_Land_Data_Entry.h"

struct RGE_Land_Data {
    long map_edge_buffer[4];
    long map_edge_fade;
    long land_placement_edge;
    long base_terrain;
    long grown_land_percent;
    long id;
    long land_num;
    RGE_Land_Data_Entry* land;
};
static_assert(sizeof(RGE_Land_Data) == 0x2C, "Size mismatch");
