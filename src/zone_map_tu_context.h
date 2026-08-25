#ifndef RGE_ZONE_MAP_CONTEXT_H
#define RGE_ZONE_MAP_CONTEXT_H

#include "../include/rge_zone_queue_context.h"

typedef unsigned char uchar;

void rge_read(int handle, void* buffer, int count);

struct RGE_Tile {
    short sx;
    short sy;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char height : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char objects[0x0c];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    long map_width;
    long map_height;
    char gap_10[0x8d7c];
    RGE_Tile** map_row_offset;

    unsigned char get_terrain(short x, short y);
};

struct XYPoint {
    int x;
    int y;
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    char gap_50D[3];
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
    int findClosestPointInTerrainType(XYPoint point, XYPoint* out,
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

#endif
