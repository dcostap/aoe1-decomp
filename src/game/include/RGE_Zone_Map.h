#pragma once
#include "common.h"

struct RGE_Zone_Map {
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;
};
static_assert(sizeof(RGE_Zone_Map) == 0x51C, "Size mismatch");
