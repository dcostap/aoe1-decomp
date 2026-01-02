#pragma once
#include "../common.h"

class TShape {
public:
    int load_type;                           // 0x4
    int load_size;                           // 0x8
    Shape_Header* shape_header;              // 0xC
    Shape_File_Header* head;                 // 0x10
    Shape_Offsets* offsets;                  // 0x14
    SLhape_File_Header* FShape;              // 0x18
    Shape_Info* shape_info;                  // 0x1C

    TShape();
    TShape(char* param_1, long param_2);
    virtual ~TShape();
    virtual uchar Check_shape(long param_1, char* param_2);
    virtual int is_loaded();
    virtual uchar shape_bounds(long param_1, short* param_2, short* param_3);
    virtual long shape_count();
    virtual uchar shape_minmax(long* param_1, long* param_2, long* param_3, long* param_4, long param_5);
    virtual uchar shape_check(long param_1, long param_2, long param_3);
    virtual uchar shape_draw(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar param_5, uchar* param_6);
    virtual uchar shape_draw_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4);
    virtual uchar shape_color_trans_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar* param_5);
    virtual uchar shape_shadow_unclipped(TDrawArea* param_1, long param_2, long param_3, uchar* param_4);
    virtual uchar shape_draw_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    virtual uchar shape_color_trans_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9);
    virtual uchar shape_shadow_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, uchar* param_8);
    virtual uchar shape_mirror(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar param_5, uchar* param_6);
    virtual uchar shape_mirror_unclipped(TDrawArea* param_1, long param_2, long param_3);
    virtual uchar shape_mirror_color_trans_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4, uchar* param_5);
    virtual uchar shape_mirror_shadow_unclipped(TDrawArea* param_1, long param_2, long param_3, uchar* param_4);
    virtual uchar shape_mirror_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    virtual uchar shape_mirror_color_trans_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9);
    virtual uchar shape_mirror_shadow_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, uchar* param_8);
    virtual uchar shape_dither(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6);
    virtual uchar shape_dithered_unclipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5);
    virtual uchar shape_dithered_clipped(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9);
};

static_assert(sizeof(TShape) == 0x20, "TShape Size Mismatch");
static_assert(offsetof(TShape, shape_info) == 0x1C, "TShape Offset Mismatch");

