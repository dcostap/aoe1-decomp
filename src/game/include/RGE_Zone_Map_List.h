#pragma once
#include "common.h"
#include "RGE_Zone_Map.h"

struct RGE_Zone_Map_List {
    RGE_Zone_Map_List(int param_1, RGE_Map* param_2);
    RGE_Zone_Map_List(RGE_Map* param_1);
    ~RGE_Zone_Map_List();

    void save(int param_1);
    long create_zone_map(float* param_1, long param_2);
    RGE_Zone_Map* get_zone_map(float* param_1, long param_2, int* param_3);
    RGE_Zone_Map* get_zone_map(long param_1);
    void delete_zone_maps();

    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;
};
static_assert(sizeof(RGE_Zone_Map_List) == 0xC, "Size mismatch");
