#ifndef AOE1_ZONE_MAP_H
#define AOE1_ZONE_MAP_H

#include "map.h"
#include "xy_point.h"

typedef unsigned char uchar;

struct Zone_Queue {
    long x;
    long y;
    Zone_Queue* next;
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    RGE_Zone_Map(int infile, RGE_Map* new_map);
    RGE_Zone_Map(RGE_Map* new_map, float* new_terrain_rules, long new_terrain_rules_num);
    ~RGE_Zone_Map();
    void save(int outfile);
    uchar do_zone_map();
    RGE_Zone_Map* check_info(float* new_terrain_rules, long new_terrain_rules_num);
    uchar get_zone_info(long x, long y);
    int withinRange(XYPoint start, XYPoint goal, float range);
    int withinRange(uchar startZone, XYPoint goal, float range);
    int numberTilesInZone(uchar zone);
    int findClosestPointInTerrainType(XYPoint p, XYPoint& rVal, int type1, int type2, int range);

private:
    void do_zone_map_area(long x, long y, uchar group, uchar zone);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;

    RGE_Zone_Map_List(int infile, RGE_Map* in_map);
    RGE_Zone_Map_List(RGE_Map* in_map);
    ~RGE_Zone_Map_List();
    void save(int outfile);
    long create_zone_map(float* new_terrain_rules, long new_terrain_rules_num);
    RGE_Zone_Map* get_zone_map(float* new_terrain_rules, long new_terrain_rules_num, int& zoneMapIndex);
    RGE_Zone_Map* get_zone_map(long id);
    void delete_zone_maps();
};

typedef char rge_zone_map_size_check[
    (sizeof(RGE_Zone_Map) == 0x51C) ? 1 : -1];
typedef char rge_zone_map_list_size_check[
    (sizeof(RGE_Zone_Map_List) == 0x0C) ? 1 : -1];

#endif
