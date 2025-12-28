#pragma once

#include "../types.h"
#include "RGE_Object_List.h"
#include "RGE_Tile.h"

// Forward declarations
class TDrawArea;
struct TShape;
struct RGE_Sound;
struct RGE_RMM_Database_Controller;
struct RGE_Zone_Map_List;
struct RGE_Unified_Visible_Map;
struct Visible_Unit_Manager;
class RGE_Game_World;
struct RGE_Player;
struct RGE_Player_Info;
struct RGE_Sprite;

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
    // Offset 28 (Naturally 4-byte aligned)
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
    // Offset 28
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
    // Offset 1436 (Naturally 2-byte aligned)
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    // ========================================================================
    // Virtual Table (Strictly following layout.json)
    // ========================================================================
    
    // Index 0: vector_deleting_destructor
    virtual ~RGE_Map();

    // Index 1: data_load_random_map
    virtual void data_load_random_map(int param_1);

    // Index 2: load_random_map
    virtual void load_random_map(char *param_1, char *param_2, char *param_3, char *param_4);

    // Index 3: do_terrain_brush
    virtual uchar do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4);

    // Index 4: do_terrain_brush_stroke
    virtual uchar do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6);

    // Index 5: do_elevation_brush
    virtual uchar do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4);

    // Index 6: do_elevation_brush_stroke
    virtual uchar do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6);

    // Index 7: do_cliff_brush
    virtual uchar do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4);

    // Index 8: do_cliff_brush_stroke
    virtual uchar do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);

    // Index 9: map_generate
    virtual void map_generate(struct RGE_Player *param_1, struct RGE_Game_World *param_2, struct RGE_Player_Info *param_3, uchar *param_4);

    // Index 10: map_generate2
    virtual void map_generate2(struct RGE_Game_World *param_1, long param_2, long param_3, uchar param_4, long param_5);

    // Index 11: save
    virtual void save(int param_1);


    // ========================================================================
    // Members (Offsets MUST match layout.json)
    // ========================================================================
    
    /* 0x0000 */ // vptr
    /* 0x0004 */ struct RGE_Tile *map;
    /* 0x0008 */ long map_width;
    /* 0x000C */ long map_height;
    /* 0x0010 */ long world_width;
    /* 0x0014 */ long world_height;
    /* 0x0018 */ struct RGE_Tile_Size tilesizes[19]; // size 114
    // 0x0018 + 114 = 0x008A (138)
    // 2 bytes implicit padding to align RGE_Tile_Set to 4 bytes
    /* 0x008C */ struct RGE_Tile_Set terrain_types[32]; // size 13056
    // 0x008C + 13056 = 0x338C (13196)
    /* 0x338C */ struct RGE_Border_Set border_types[16]; // size 23040
    // 0x338C + 23040 = 0x8D8C (36236)
    /* 0x8D8C */ struct RGE_Tile **map_row_offset;
    /* 0x8D90 */ short num_terrain;
    /* 0x8D92 */ short num_borders;
    /* 0x8D94 */ short max_terrain;
    /* 0x8D96 */ short tile_width;
    /* 0x8D98 */ short tile_height;
    /* 0x8D9A */ short tile_half_height;
    /* 0x8D9C */ short tile_half_width;
    /* 0x8D9E */ short elev_height;
    /* 0x8DA0 */ short cur_row;
    /* 0x8DA2 */ short cur_col;
    /* 0x8DA4 */ short block_beg_row;
    /* 0x8DA6 */ short block_end_row;
    /* 0x8DA8 */ short block_beg_col;
    /* 0x8DAA */ short block_end_col;
    /* 0x8DAC */ uchar any_frame_change;
    // 3 bytes implicit padding to align pointers
    /* 0x8DB0 */ uchar *search_map;
    /* 0x8DB4 */ uchar **search_map_rows;
    /* 0x8DB8 */ uchar map_visible_flag;
    /* 0x8DB9 */ uchar fog_flag;
    // 2 bytes implicit padding
    /* 0x8DBC */ struct RGE_RMM_Database_Controller *random_map;
    /* 0x8DC0 */ struct RGE_Game_World *game_world;
    /* 0x8DC4 */ struct RGE_Zone_Map_List *map_zones;
    /* 0x8DC8 */ struct RGE_Unified_Visible_Map *unified_vis_map;
    /* 0x8DCC */ struct Visible_Unit_Manager *unit_manager;

    // ========================================================================
    // Non-virtual Methods
    // ========================================================================
    
    RGE_Map();

    void new_map(long width, long height);
    void draw(TDrawArea *render_area, int x, int y, int width, int height);

    void load_terrain_types(struct RGE_Sound **sounds);
    void load_border_types(struct RGE_Sound **sounds);
};

// MANDATORY VERIFICATION
static_assert(sizeof(RGE_Map) == 0x8DD0, "RGE_Map size mismatch");
static_assert(offsetof(RGE_Map, terrain_types) == 0x8C, "terrain_types offset mismatch");
static_assert(offsetof(RGE_Map, border_types) == 0x338C, "border_types offset mismatch");
static_assert(offsetof(RGE_Map, map_row_offset) == 0x8D8C, "map_row_offset offset mismatch");
static_assert(offsetof(RGE_Map, unit_manager) == 0x8DCC, "unit_manager offset mismatch");
static_assert(sizeof(RGE_Tile_Set) == 408, "RGE_Tile_Set size mismatch");
static_assert(sizeof(RGE_Border_Set) == 1440, "RGE_Border_Set size mismatch");
