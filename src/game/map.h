#pragma once
#include "common.h"

class RGE_Map {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Tile* map;                           // 0x4
    long map_width;                          // 0x8
    long map_height;                         // 0xC
    long world_width;                        // 0x10
    long world_height;                       // 0x14
    RGE_Tile_Size tilesizes[19];             // 0x18
    RGE_Tile_Set terrain_types[32];          // 0x8C
    RGE_Border_Set border_types[16];         // 0x338C
    RGE_Tile** map_row_offset;               // 0x8D8C
    short num_terrain;                       // 0x8D90
    short num_borders;                       // 0x8D92
    short max_terrain;                       // 0x8D94
    short tile_width;                        // 0x8D96
    short tile_height;                       // 0x8D98
    short tile_half_height;                  // 0x8D9A
    short tile_half_width;                   // 0x8D9C
    short elev_height;                       // 0x8D9E
    short cur_row;                           // 0x8DA0
    short cur_col;                           // 0x8DA2
    short block_beg_row;                     // 0x8DA4
    short block_end_row;                     // 0x8DA6
    short block_beg_col;                     // 0x8DA8
    short block_end_col;                     // 0x8DAA
    uchar any_frame_change;                  // 0x8DAC
    uchar* search_map;                       // 0x8DB0
    uchar** search_map_rows;                 // 0x8DB4
    uchar map_visible_flag;                  // 0x8DB8
    uchar fog_flag;                          // 0x8DB9
    RGE_RMM_Database_Controller* random_map; // 0x8DBC
    RGE_Game_World* game_world;              // 0x8DC0
    RGE_Zone_Map_List* map_zones;            // 0x8DC4
    RGE_Unified_Visible_Map* unified_vis_map; // 0x8DC8
    Visible_Unit_Manager* unit_manager;      // 0x8DCC

    virtual void data_load_random_map(int param_1);         // vt0[1]+0x4=0x4557C0
    virtual void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4); // vt0[2]+0x8=0x455820
    virtual uchar do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4); // vt0[3]+0xC=0x457320
    virtual uchar do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt0[4]+0x10=0x4573C0
    virtual uchar do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4); // vt0[5]+0x14=0x457510
    virtual uchar do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt0[6]+0x18=0x4575C0
    virtual uchar do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4); // vt0[7]+0x1C=0x457750
    virtual uchar do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6); // vt0[8]+0x20=0x457760
    virtual void map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4); // vt0[9]+0x24=0x4578A0
    virtual void map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5); // vt0[10]+0x28=0x4578B0
    virtual void save(int param_1);                         // vt0[11]+0x2C=0x457DF0
    RGE_Map(int param_1, RGE_Sound** param_2, uchar param_3);
    RGE_Map(char* param_1, char* param_2, char* param_3, short param_4, short param_5, short param_6, RGE_Sound** param_7);
    ~RGE_Map();
    void init_tile_sizes();
    void set_map_visible(uchar param_1);
    void set_map_fog(uchar param_1);
    void clear_map(RGE_Player* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, long param_5);
    void new_map(long param_1, long param_2);
    void clear_map(uchar param_1, uchar param_2);
    void request_redraw(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    void clear_map_view_info();
    void coordinate_map();
    void set_map_screen_pos(int param_1, int param_2, int param_3, int param_4);
    void scenario_save(int param_1);
    void scenario_load(int param_1, uchar* param_2);
    RGE_Tile** give_up_map_offsets();
    long get_map_width();
    long get_map_height();
    uchar postclean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    void preclean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    void clean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    void clean_terrain(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    void clean_borders(long param_1, long param_2, long param_3, long param_4);
    long clean_border_tile(long param_1, long param_2, long* param_3);
    void load_map(int param_1);
    void save_map(int param_1);
    void load_terrain_types(RGE_Sound** param_1);
    void load_terrain_types(char* param_1, RGE_Sound** param_2);
    void load_border_types(RGE_Sound** param_1);
    void load_border_types(char* param_1, RGE_Sound** param_2);
    void load_terrain_obj_types(char* param_1);
    void delete_objects_on_tile(RGE_Player* param_1, RGE_Game_World* param_2, int param_3, int param_4, int param_5, int param_6);
    void delete_all_objects_on_tile(int param_1, int param_2);
    void create_terrain_object(RGE_Player* param_1, RGE_Game_World* param_2, short param_3, short param_4, short param_5, int param_6, int param_7, int param_8);
    int clear_terrain_object(RGE_Game_World* param_1, short param_2, short param_3, short param_4, int param_5, int param_6, int param_7);
    void place_terrain_object(RGE_Player* param_1, RGE_Game_World* param_2, short param_3, short param_4, int param_5, int param_6);
    void create_terrain_objects(RGE_Player* param_1, RGE_Game_World* param_2);
    void set_tile_size(uchar param_1, short param_2, short param_3, short param_4);
    void tile_map_coords(short param_1, short param_2, RGE_Tile* param_3, float* param_4, float* param_5);
    uchar check_map_coords(short param_1, short param_2);
    uchar get_elev(short param_1, short param_2);
    uchar get_terrain(short param_1, short param_2);
    uchar get_border(short param_1, short param_2);
    void set_terrain_passablity(short param_1, short param_2, short param_3, short param_4, uchar param_5);
    void set_elev(short param_1, short param_2, short param_3, short param_4, uchar param_5, short param_6, uchar param_7);
    void set_terrain(RGE_Game_World* param_1, short param_2, short param_3, uchar param_4, int param_5, int param_6);
    void set_terrain_absolute(RGE_Game_World* param_1, short param_2, short param_3, uchar param_4, int param_5, int param_6);
    void set_terrain(RGE_Player* param_1, RGE_Game_World* param_2, short param_3, short param_4, short param_5, short param_6, uchar param_7, uchar param_8, int param_9);
    uchar get_tile_type(short param_1, short param_2);
    void get_border_type(short param_1, short param_2);
    void check_for_border(uchar param_1, uchar* param_2);
    void update(ulong param_1);
    void get_point(short* param_1, short* param_2, float param_3, float param_4, float param_5, short param_6, short param_7);
};

static_assert(sizeof(RGE_Map) == 0x8DD0, "RGE_Map Size Mismatch");

