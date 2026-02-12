#pragma once
#include "common.h"

struct RGE_Border_Set {
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
    RGE_TOB_Picts borders[19][12];
    uchar draw_tile;
    short underlay_terrain;
    short border_style;
};
static_assert(sizeof(RGE_Border_Set) == 0x5A0, "Size mismatch");
