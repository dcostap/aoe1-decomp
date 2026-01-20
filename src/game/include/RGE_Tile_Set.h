#pragma once
#include "common.h"

struct RGE_Tile_Set {
    uchar loaded;
    uchar random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
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
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    uchar obj_placement_flag[30];
    short num_obj_type;
};
static_assert(sizeof(RGE_Tile_Set) == 0x198, "Size mismatch");
