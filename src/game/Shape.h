#pragma once
#include "common.h"


// ----------------------------------------------------------------
// Ov_Sprite_Draw_Rec
// Size: 0x30
struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec * next; // 0x0
    Ov_Sprite_Draw_Rec * prev; // 0x4
    TShape * theShape; // 0x8
    int thefacet; // 0xC
    int world_x; // 0x10
    int world_y; // 0x14
    int flags; // 0x18
    int drawLevel; // 0x1C
    int displayfunction; // 0x20
    ulong LastDrawTime; // 0x24
    ulong DrawTimeInterval; // 0x28
    uchar * colortable; // 0x2C
};


// ----------------------------------------------------------------
// RGE_Border_Set
// Size: 0x5A0
struct RGE_Border_Set {
    uchar loaded; // 0x0
    uchar random; // 0x1
    char name[13]; // 0x2
    char pict_name[13]; // 0xF
    long resource_id; // 0x1C
    TShape * shape; // 0x20
    RGE_Sound * sound; // 0x24
    uchar map_hi_color; // 0x28
    uchar map_med_color; // 0x29
    uchar map_low_color; // 0x2A
    uchar is_animated; // 0x2B
    short animation_frames; // 0x2C
    short pause_frames; // 0x2E
    float interval; // 0x30
    float pause_between_loops; // 0x34
    short frame; // 0x38
    short draw_frame; // 0x3A
    float animate_last; // 0x3C
    uchar frame_changed; // 0x40
    uchar drawn; // 0x41
    RGE_TOB_Picts borders[19][12]; // 0x42
    uchar draw_tile; // 0x59A
    short underlay_terrain; // 0x59C
    short border_style; // 0x59E
};


class TShape {
public:
    uchar* shape;                            // 0x0
    int load_type;                           // 0x4
    int load_size;                           // 0x8
    Shape_Header* shape_header;              // 0xC
    Shape_File_Header* head;                 // 0x10
    Shape_Offsets* offsets;                  // 0x14
    SLhape_File_Header* FShape;              // 0x18
    Shape_Info* shape_info;                  // 0x1C

    TShape();
    TShape(char* param_1, long param_2);
    ~TShape();
    uchar Check_shape(long param_1, char* param_2);
    int is_loaded();
    uchar shape_bounds(long param_1, short* param_2, short* param_3);
    long shape_count();
    uchar shape_minmax(long* param_1, long* param_2, long* param_3, long* param_4, long param_5);
    uchar shape_check(long param_1, long param_2, long param_3);
    uchar shape_draw(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar param_5, uchar* param_6);
    uchar shape_draw_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4);
    uchar shape_color_trans_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar* param_5);
    uchar shape_shadow_unclipped(TDrawArea* param_1, long param_2, long param_3, uchar* param_4);
    uchar shape_draw_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    uchar shape_color_trans_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9);
    uchar shape_shadow_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, uchar* param_8);
    uchar shape_mirror(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar param_5, uchar* param_6);
    uchar shape_mirror_unclipped(TDrawArea* param_1, long param_2, long param_3);
    uchar shape_mirror_color_trans_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar* param_5);
    uchar shape_mirror_shadow_unclipped(TDrawArea* param_1, long param_2, long param_3, uchar* param_4);
    uchar shape_mirror_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    uchar shape_mirror_color_trans_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9);
    uchar shape_mirror_shadow_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, uchar* param_8);
    uchar shape_dither(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6);
    uchar shape_dithered_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5);
    uchar shape_dithered_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9);
};

static_assert(sizeof(TShape) == 0x20, "TShape Size Mismatch");

