#pragma once
#include "common.h"
#include "XYPoint.h"

struct RGE_Zone_Map {
    RGE_Zone_Map(int param_1, RGE_Map* param_2);
    RGE_Zone_Map(RGE_Map* param_1, float* param_2, long param_3);
    ~RGE_Zone_Map();

    void save(int param_1);
    uchar do_zone_map();
    RGE_Zone_Map* check_info(float* param_1, long param_2);
    uchar get_zone_info(long param_1, long param_2);
    int withinRange(XYPoint param_1, XYPoint param_2, float param_3);
    int withinRange(uchar param_1, XYPoint param_2, float param_3);
    int numberTilesInZone(uchar param_1);
    int findClosestPointInTerrainType(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5);

private:
    void do_zone_map_area(long param_1, long param_2, uchar param_3, uchar param_4);

    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;
};
static_assert(sizeof(RGE_Zone_Map) == 0x51C, "Size mismatch");
