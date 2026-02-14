#pragma once
#include "common.h"
#include "RGE_Tile.h"
#include "RGE_Tile_Size.h"
#include "RGE_Tile_Set.h"
#include "RGE_Border_Set.h"
#include "RGE_TOB_Picts.h"

class RGE_Map {
public:
    // Constructors
    RGE_Map(); // Default — zero-init
    RGE_Map(int file_handle, RGE_Sound** sounds, uchar load_map); // Binary path (empires.dat)
    RGE_Map(RGE_Game_World* world, long w, long h);
    RGE_Map(char* terrain_file, char* border_file, char* terrain_obj_file,
            short tile_w, short tile_h, short elev_h, RGE_Sound** sounds); // Text file path

    // Virtuals (best-effort)
    virtual ~RGE_Map(); // vt[0] (0x0)
    virtual void data_load_random_map(int param_1); // vt[1] (0x4)
    virtual void load_random_map(char* param_1, char* param_2, char* param_3, char* param_4); // vt[2] (0x8)
    virtual uchar do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4); // vt[3] (0xC)
    virtual uchar do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt[4] (0x10)
    virtual uchar do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4); // vt[5] (0x14)
    virtual uchar do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6); // vt[6] (0x18)
    virtual uchar do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4); // vt[7] (0x1C)
    virtual uchar do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6); // vt[8] (0x20)
    virtual void map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4); // vt[9] (0x24)
    virtual void map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5); // vt[10] (0x28)
    virtual void save(int param_1); // vt[11] (0x2C)

    // Non-virtual methods — transliterated from map.cpp.decomp
    void init_tile_sizes();
    void set_tile_size(uchar index, short width, short height, short y_delta);
    void load_terrain_types(RGE_Sound** sounds); // Binary path: construct TShape from pict_name+resource_id
    void load_border_types(RGE_Sound** sounds); // Binary path
    void load_terrain_types(char* filename, RGE_Sound** sounds); // Text file path
    void load_border_types(char* filename, RGE_Sound** sounds); // Text file path
    void new_map(long width, long height);
    RGE_Tile* get_tile(int col, int row);
    void set_map_screen_pos(int col0, int row0, int col1, int row1);
    void clear_map(RGE_Player* player, RGE_Game_World* world, uchar terrain, long w, long h);
    void clear_map(uchar terrain, uchar height);
    void set_terrain(RGE_Player* player, RGE_Game_World* world, short col, short row, uchar terrain, uchar unknown1, uchar unknown2);
    void coordinate_map();
    void set_map_visible(uchar flag);
    void set_map_fog(uchar flag);
    void request_redraw(int col0, int row0, int col1, int row1, uchar attr);
    void clear_map_view_info();
    uchar get_border_type(short col, short row);
    void load_terrain_obj_types(char* param_1);

    // Data members — layout must match empires.dat binary format
    // The RGE_Map constructor reads 0x8DD0 bytes into this struct starting at offset 0
    // (including vtable pointer), then re-sets vtable and pointer fields afterward.
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;
    short max_terrain;
    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    short cur_row;
    short cur_col;
    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;
    unsigned char any_frame_change;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;
};
// static_assert(sizeof(RGE_Map) == 0x8DD0, "Size mismatch");
