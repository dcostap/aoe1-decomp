#pragma once

#include "../types.h"
#include "RGE_Object_List.h"
#include "RGE_Tile.h"

class TDrawArea;

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
    /* 0x0004 */ struct RGE_Tile *map;
    /* 0x0008 */ long map_width;
    /* 0x000c */ long map_height;
    /* 0x0010 */ long world_width;
    /* 0x0014 */ long world_height;
    /* 0x0018 */ struct RGE_Tile_Size tilesizes[19];
    /* 0x008a */ short _pad_8a;
    /* 0x008c */ struct RGE_Tile_Set terrain_types[32];
    /* 0x338c */ struct RGE_Border_Set border_types[16];
    /* 0x8d8c */ struct RGE_Tile **map_row_offset;
    /* 0x8d90 */ short num_terrain;
    /* 0x8d92 */ short num_borders;
    /* 0x8d94 */ short max_terrain;
    /* 0x8d96 */ short tile_width;
    /* 0x8d98 */ short tile_height;
    /* 0x8d9a */ short tile_half_height;
    /* 0x8d9c */ short tile_half_width;
    /* 0x8d9e */ short elev_height;
    /* 0x8da0 */ short cur_row;
    /* 0x8da2 */ short cur_col;
    /* 0x8da4 */ short block_beg_row;
    /* 0x8da6 */ short block_end_row;
    /* 0x8da8 */ short block_beg_col;
    /* 0x8daa */ short block_end_col;
    /* 0x8dac */ uchar any_frame_change;
    /* 0x8dad */ uchar _pad_8dad[3];
    /* 0x8db0 */ uchar *search_map;
    /* 0x8db4 */ uchar **search_map_rows;
    /* 0x8db8 */ uchar map_visible_flag;
    /* 0x8db9 */ uchar fog_flag;
    /* 0x8dba */ uchar _pad_8dba[2];
    /* 0x8dbc */ struct RGE_RMM_Database_Controller *random_map;
    /* 0x8dc0 */ struct RGE_Game_World *game_world;
    /* 0x8dc4 */ struct RGE_Zone_Map_List *map_zones;
    /* 0x8dc8 */ struct RGE_Unified_Visible_Map *unified_vis_map;
    /* 0x8dcc */ struct Visible_Unit_Manager *unit_manager;

    RGE_Map();
    virtual ~RGE_Map();

    void new_map(long width, long height);
    void draw(TDrawArea *render_area, int x, int y, int width, int height);

    void load_terrain_types(struct RGE_Sound **sounds);
    void load_border_types(struct RGE_Sound **sounds);
};

static_assert(sizeof(RGE_Map) == 0x8DD0, "RGE_Map size mismatch");

#pragma pack(pop)
