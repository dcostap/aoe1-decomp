#pragma once
#include "common.h"

struct RGE_Sprite {
    char pict_name[13];
    long resource_id;
    uchar loaded;
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    uchar color_flag;
    uchar draw_level;
    short color_table;
    uchar transparent_picking_flag;
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    RGE_Sound* main_sound;
    uchar micro_man_sound;
    RGE_Sound_List* sound_list;
    char name[21];
    short frame_num;
    short facet_num;
    float base_speed;
    float duration;
    float pause_between_loops;
    uchar flag;
    short id;
    uchar mirror_flag;
};
static_assert(sizeof(RGE_Sprite) == 0x78, "Size mismatch");
