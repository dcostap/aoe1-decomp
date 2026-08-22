#ifndef RGE_ZONE_MAP_CONTEXT_H
#define RGE_ZONE_MAP_CONTEXT_H

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    unsigned char* zone_map;
    unsigned char** zone_map_rows;
    unsigned char zone_info[257];
    char gap_50D[3];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    RGE_Zone_Map(RGE_Map* map, float* terrain_info, long terrain_info_num);
    ~RGE_Zone_Map();
    unsigned char do_zone_map();
    RGE_Zone_Map* check_info(float* terrain_info, long terrain_info_num);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;

    long create_zone_map(float* terrain_info, long terrain_info_num);
    RGE_Zone_Map* get_zone_map(float* terrain_info, long terrain_info_num,
                               int& zone_map_index);
};

#endif
