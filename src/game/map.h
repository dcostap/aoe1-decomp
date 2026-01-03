#pragma once
#include "../common.h"
#include "rmm_dbct.h"

class RGE_Map {
public:
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

    RGE_Map(int param_1, RGE_Sound** param_2, uchar param_3);
    RGE_Map(char* param_1, char* param_2, char* param_3, short param_4, short param_5, short param_6, RGE_Sound** param_7);
    virtual ~RGE_Map();
    virtual void init_tile_sizes();
    virtual void data_load_random_map(int param_1);
    virtual void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4);
    virtual void set_map_visible(uchar param_1);
    virtual void set_map_fog(uchar param_1);
    virtual void clear_map(RGE_Player* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, long param_5);
    virtual void new_map(long param_1, long param_2);
    virtual void clear_map(uchar param_1, uchar param_2);
    virtual void request_redraw(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    virtual void clear_map_view_info();
    virtual void coordinate_map();
    virtual void set_map_screen_pos(int param_1, int param_2, int param_3, int param_4);
    virtual void scenario_save(int param_1);
    virtual void scenario_load(int param_1, uchar* param_2);
    virtual RGE_Tile** give_up_map_offsets();
    virtual long get_map_width();
    virtual long get_map_height();
    virtual uchar postclean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    virtual void preclean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    virtual void clean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    virtual void clean_terrain(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    virtual void clean_borders(long param_1, long param_2, long param_3, long param_4);
    virtual long clean_border_tile(long param_1, long param_2, long* param_3);
    virtual uchar do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4);
    virtual uchar do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6);
    virtual uchar do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4);
    virtual uchar do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6);
    virtual uchar do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4);
    virtual uchar do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
    virtual void map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4);
    virtual void map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5);
    virtual void load_map(int param_1);
    virtual void save_map(int param_1);
    virtual void save(int param_1);
    virtual void load_terrain_types(RGE_Sound** param_1);
    virtual void load_terrain_types(char* param_1, RGE_Sound** param_2);
    virtual void load_border_types(RGE_Sound** param_1);
    virtual void load_border_types(char* param_1, RGE_Sound** param_2);
    virtual void load_terrain_obj_types(char* param_1);
    virtual void delete_objects_on_tile(RGE_Player* param_1, RGE_Game_World* param_2, int param_3, int param_4, int param_5, int param_6);
    virtual void delete_all_objects_on_tile(int param_1, int param_2);
    virtual void create_terrain_object(RGE_Player* param_1, RGE_Game_World* param_2, short param_3, short param_4, short param_5, int param_6, int param_7, int param_8);
    virtual int clear_terrain_object(RGE_Game_World* param_1, short param_2, short param_3, short param_4, int param_5, int param_6, int param_7);
    virtual void place_terrain_object(RGE_Player* param_1, RGE_Game_World* param_2, short param_3, short param_4, int param_5, int param_6);
    virtual void create_terrain_objects(RGE_Player* param_1, RGE_Game_World* param_2);
    virtual void set_tile_size(uchar param_1, short param_2, short param_3, short param_4);
    virtual void tile_map_coords(short param_1, short param_2, RGE_Tile* param_3, float* param_4, float* param_5);
    virtual uchar check_map_coords(short param_1, short param_2);
    virtual uchar get_elev(short param_1, short param_2);
    virtual uchar get_terrain(short param_1, short param_2);
    virtual uchar get_border(short param_1, short param_2);
    virtual void set_terrain_passablity(short param_1, short param_2, short param_3, short param_4, uchar param_5);
    virtual void set_elev(short param_1, short param_2, short param_3, short param_4, uchar param_5, short param_6, uchar param_7);
    virtual void set_terrain(RGE_Game_World* param_1, short param_2, short param_3, uchar param_4, int param_5, int param_6);
    virtual void set_terrain_absolute(RGE_Game_World* param_1, short param_2, short param_3, uchar param_4, int param_5, int param_6);
    virtual void set_terrain(RGE_Player* param_1, RGE_Game_World* param_2, short param_3, short param_4, short param_5, short param_6, uchar param_7, uchar param_8, int param_9);
    virtual uchar get_tile_type(short param_1, short param_2);
    virtual void get_border_type(short param_1, short param_2);
    virtual void check_for_border(uchar param_1, uchar* param_2);
    virtual void update(ulong param_1);
    virtual void get_point(short* param_1, short* param_2, float param_3, float param_4, float param_5, short param_6, short param_7);
};

static_assert(sizeof(RGE_Map) == 0x8DD0, "RGE_Map Size Mismatch");
static_assert(offsetof(RGE_Map, unit_manager) == 0x8DCC, "RGE_Map Offset Mismatch");

