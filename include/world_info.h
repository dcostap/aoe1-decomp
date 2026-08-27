#ifndef AOE1_WORLD_INFO_H
#define AOE1_WORLD_INFO_H

// Shared World record owners. CodeView proves these plain struct layouts.

struct RGE_Info_Line {
    float clump_num;
    short percent_of_tiles_covered;
    short percent_updown;
    short min_elevation;
    short max_elevation;
    short terrain_type;
    short terrain_base;
    char obj_id;
};

typedef char rge_info_line_size_check[
    (sizeof(RGE_Info_Line) == 0x14) ? 1 : -1];

struct RGE_Map_Gen_Info {
    short base_terrain;
    RGE_Info_Line land;
    RGE_Info_Line elevation[20];
    short elevation_num;
    RGE_Info_Line terrain[20];
    short terrain_num;
    RGE_Info_Line objects[20];
    short objects_num;
    short player_num;
    short player_x[9];
    short player_y[9];
    short player_connect[9];
    short player_base_land[9];
    short space_between_islands_or_edge;
};

typedef char rge_map_gen_info_size_check[
    (sizeof(RGE_Map_Gen_Info) == 0x520) ? 1 : -1];

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    short color[9];
    long player_id_hash[9];
    short player_num;
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    unsigned char campaign;
};

typedef char rge_player_info_size_check[
    (sizeof(RGE_Player_Info) == 0x2AC) ? 1 : -1];

#endif
