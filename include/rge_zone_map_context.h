#ifndef RGE_ZONE_MAP_CONTEXT_H
#define RGE_ZONE_MAP_CONTEXT_H

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
    void save(int file);
    unsigned char do_zone_map();
    RGE_Zone_Map* check_info(float* terrain_info, long terrain_info_num);

private:
    void do_zone_map_area(long x, long y, unsigned char passable,
                          unsigned char zone);
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
