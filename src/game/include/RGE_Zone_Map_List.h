#pragma once
#include "common.h"

struct RGE_Zone_Map_List {
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;
};
static_assert(sizeof(RGE_Zone_Map_List) == 0xC, "Size mismatch");
