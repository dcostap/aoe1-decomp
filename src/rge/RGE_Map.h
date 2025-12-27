#pragma once

#include "../types.h"
#include "RGE_Object_List.h"
#include "RGE_Tile.h"

#pragma pack(push, 1)

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

struct RGE_Tile_Set {
    uchar loaded;
    uchar random;
    char name[13];
    char pict_name[13];
    long resource_id;
    struct TShape *shape;
    struct RGE_Sound *sound;
    uchar map_hi_color;
    uchar map_med_color;
    uchar map_low_color;
    uchar map_lt_cliff_color;
    uchar map_rt_cliff_color;
    uchar passable_terrain;
    uchar impassable_terrain;
    uchar is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    uchar frame_changed;
    uchar drawn;
    struct RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    uchar obj_placement_flag[30];
    short num_obj_type;
    char padding[2];
};

struct RGE_Border_Set {
    uchar loaded;
    uchar random;
    char name[13];
    char pict_name[13];
    long resource_id;
    struct TShape *shape;
    struct RGE_Sound *sound;
    uchar map_hi_color;
    uchar map_med_color;
    uchar map_low_color;
    uchar is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    uchar frame_changed;
    uchar drawn;
    struct RGE_TOB_Picts borders[19][12];
    uchar draw_tile;
    short underlay_terrain;
    short border_style;
    char padding[1];
};

struct RGE_Map {
    void *vfptr;
    void *unused_04;
    struct RGE_Tile *map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    struct RGE_Tile_Size tilesizes[19];
    struct RGE_Tile_Set terrain_types[32];
    struct RGE_Border_Set border_types[16];
    struct RGE_Tile **map_row_offset;
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
    uchar any_frame_change;
    char padding_any_frame_change[3];
    uchar *search_map;
    uchar **search_map_rows;
    uchar map_visible_flag;
    uchar fog_flag;
    struct RGE_RMM_Database_Controller *random_map;
    struct RGE_Game_World *game_world;
    struct RGE_Zone_Map_List *map_zones;
    struct RGE_Unified_Visible_Map *unified_vis_map;
    struct Visible_Unit_Manager *unit_manager;

    RGE_Map();
    virtual ~RGE_Map();
};

#pragma pack(pop)
