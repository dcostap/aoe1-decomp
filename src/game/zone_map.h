#pragma once
#include "../common.h"

class RGE_Zone_Map       {
public:
    int numberTilesInZoneValue[257];         // 0x0
    uchar* zone_map;                         // 0x404
    uchar** zone_map_rows;                   // 0x408
    uchar zone_info[257];                    // 0x40C
    float* terrain_passability_rules;        // 0x510
    long terrain_passability_rules_num;      // 0x514
    RGE_Map* map;                            // 0x518

    RGE_Zone_Map(int param_1, RGE_Map* param_2);
    RGE_Zone_Map(RGE_Map* param_1, float* param_2, long param_3);

    // --- Non-Virtual Destructor ---
    ~RGE_Zone_Map() noexcept(false);
    // --- Non-Virtual Members ---
    void save(int param_1);
    uchar do_zone_map();
    void do_zone_map_area(long param_1, long param_2, uchar param_3, uchar param_4);
    RGE_Zone_Map* check_info(float* param_1, long param_2);
    uchar get_zone_info(long param_1, long param_2);
    int withinRange(XYPoint param_1, XYPoint param_2, float param_3);
    int withinRange(uchar param_1, XYPoint param_2, float param_3);
    int numberTilesInZone(uchar param_1);
    int findClosestPointInTerrainType(XYPoint param_1, XYPoint* param_2, int param_3, int param_4, int param_5);
};

static_assert(sizeof(RGE_Zone_Map) == 0x51C, "RGE_Zone_Map Size Mismatch");
static_assert(offsetof(RGE_Zone_Map, map) == 0x518, "RGE_Zone_Map Offset Mismatch");

class RGE_Zone_Map_List       {
public:
    RGE_Zone_Map** zone_maps;                // 0x0
    long zone_map_num;                       // 0x4
    RGE_Map* map;                            // 0x8

    RGE_Zone_Map_List(int param_1, RGE_Map* param_2);
    RGE_Zone_Map_List(RGE_Map* param_1);

    // --- Non-Virtual Destructor ---
    ~RGE_Zone_Map_List() noexcept(false);
    // --- Non-Virtual Members ---
    void save(int param_1);
    long create_zone_map(float* param_1, long param_2);
    RGE_Zone_Map* get_zone_map(float* param_1, long param_2, int* param_3);
    RGE_Zone_Map* get_zone_map(long param_1);
    void delete_zone_maps();
};

static_assert(sizeof(RGE_Zone_Map_List) == 0xC, "RGE_Zone_Map_List Size Mismatch");
static_assert(offsetof(RGE_Zone_Map_List, map) == 0x8, "RGE_Zone_Map_List Offset Mismatch");

