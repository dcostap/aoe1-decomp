#ifndef AOE1_ZONE_MAP_H
#define AOE1_ZONE_MAP_H

#include "map.h"

typedef unsigned char uchar;

struct Zone_Queue {
    long x;
    long y;
    Zone_Queue* next;
};

#ifndef AOE1_XYPOINT_DEFINED
#define AOE1_XYPOINT_DEFINED
struct XYPoint {
    int x;
    int y;
};
#endif

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    RGE_Zone_Map(int file, RGE_Map* map);
    RGE_Zone_Map(RGE_Map* map, float* terrain_info, long terrain_info_num);
    ~RGE_Zone_Map();
    void save(int file);
    uchar do_zone_map();
    RGE_Zone_Map* check_info(float* terrain_info, long terrain_info_num);
    uchar get_zone_info(long x, long y);
    int withinRange(XYPoint point, XYPoint from, float range);
    int withinRange(uchar zone, XYPoint from, float range);
    int numberTilesInZone(uchar zone);
    int findClosestPointInTerrainType(XYPoint point, XYPoint& out,
                                      int a, int b, int c);

private:
    void do_zone_map_area(long x, long y, uchar passable, uchar zone);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;

    RGE_Zone_Map_List(int file, RGE_Map* map);
    RGE_Zone_Map_List(RGE_Map* map);
    ~RGE_Zone_Map_List();
    void save(int file);
    long create_zone_map(float* terrain_info, long terrain_info_num);
    RGE_Zone_Map* get_zone_map(float* terrain_info, long terrain_info_num,
                               int& zone_map_index);
    RGE_Zone_Map* get_zone_map(long index);
    void delete_zone_maps();
};

typedef char rge_zone_map_size_check[
    (sizeof(RGE_Zone_Map) == 0x51C) ? 1 : -1];
typedef char rge_zone_map_list_size_check[
    (sizeof(RGE_Zone_Map_List) == 0x0C) ? 1 : -1];

#endif
