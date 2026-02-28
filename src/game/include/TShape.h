#pragma once
#include "common.h"
#include "Shape_Info.h"

class SLhape_File_Header {
public:
    char Version[4]; // +0x0 (Size: 0x4)
    long Num_Shapes; // +0x4 (Size: 0x4)
    char Comment[24]; // +0x8 (Size: 0x18)
};

class Shape_File_Header {
public:
    long version; // +0x0 (Size: 0x4)
    long shape_num; // +0x4 (Size: 0x4)
};

class Shape_Header {
public:
    long bounds; // +0x0 (Size: 0x4)
    long origin; // +0x4 (Size: 0x4)
    long xmin; // +0x8 (Size: 0x4)
    long ymin; // +0xC (Size: 0x4)
    long xmax; // +0x10 (Size: 0x4)
    long ymax; // +0x14 (Size: 0x4)
};

class Shape_Offsets {
public:
    long shape; // +0x0 (Size: 0x4)
    long palette; // +0x4 (Size: 0x4)
};

class TDrawArea;

class TShape {
public:
    // Constructor/Destructor
    TShape();
    TShape(char* filename, int file_id);
    ~TShape();
    
    // Methods
    int is_loaded();
    unsigned char shape_bounds(long shape_idx, short* width, short* height);
    long shape_count();

    // Source of truth: `src/game/src/Panel_ez.cpp.asm` / `.decomp` call sites use `shape_minmax` to
    // query bounds for centering/tiling.
    unsigned char shape_minmax(long* x_min, long* y_min, long* x_max, long* y_max, int shape_idx);
    unsigned char shape_check(long x, long y, long shape_idx);
    
    // Fully verified. Source of truth: shape.cpp.asm @ 0x004B9440
    unsigned char shape_draw(TDrawArea* draw_area, long x, long y, long shape_idx, unsigned char color_flag, unsigned char* color_table);

    // Fully verified. Source of truth: shape.cpp.asm @ 0x004BA550
    unsigned char shape_mirror(TDrawArea* draw_area, long x, long y, long shape_idx, unsigned char color_flag, unsigned char* color_table);

    // Fully verified. Source of truth: shape.cpp.asm @ 0x004BB5E0
    unsigned char shape_dither(TDrawArea* draw_area, long x, long y, long shape_idx, long param_5, long param_6);
    
    // Members
    unsigned char* shape; // +0x0 (Size: 0x4)
    int load_type; // +0x4 (Size: 0x4)
    int load_size; // +0x8 (Size: 0x4)
    Shape_Header* shape_header; // +0xC (Size: 0x4)
    Shape_File_Header* head; // +0x10 (Size: 0x4)
    Shape_Offsets* offsets; // +0x14 (Size: 0x4)
    SLhape_File_Header* FShape; // +0x18 (Size: 0x4)
    Shape_Info* shape_info; // +0x1C (Size: 0x4)
    
private:
    friend unsigned char shape_bounds(TShape* this_, long param_2, short* param_3, short* param_4);
    friend long shape_count(TShape* this_);
    friend unsigned char shape_minmax(TShape* this_, long* param_2, long* param_3, long* param_4, long* param_5, long param_6);
    friend unsigned char shape_check(TShape* this_, long param_2, long param_3, long param_4);
    friend unsigned char shape_draw(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, unsigned char param_6, unsigned char* param_7);
    friend unsigned char shape_draw_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5);
    friend unsigned char shape_color_trans_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, unsigned char* param_6);
    friend unsigned char shape_shadow_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, unsigned char* param_5);
    friend unsigned char shape_draw_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8);
    friend unsigned char shape_color_trans_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, unsigned char* param_10);
    friend unsigned char shape_shadow_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, unsigned char* param_9);
    friend unsigned char shape_mirror(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, unsigned char param_6, unsigned char* param_7);
    friend unsigned char shape_mirror_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4);
    friend unsigned char shape_mirror_color_trans_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, unsigned char* param_6);
    friend unsigned char shape_mirror_shadow_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, unsigned char* param_5);
    friend unsigned char shape_mirror_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8);
    friend unsigned char shape_mirror_color_trans_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, unsigned char* param_10);
    friend unsigned char shape_mirror_shadow_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, unsigned char* param_9);
    friend unsigned char shape_dither(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    friend unsigned char shape_dithered_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6);
    friend unsigned char shape_dithered_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10);

    unsigned char Check_shape(long param_1, char* param_2);

    unsigned char shape_draw_unclipped(TDrawArea* draw_area, long x, long y, long shape_idx);
    unsigned char shape_color_trans_unclipped(TDrawArea* draw_area, long x, long y, long shape_idx, unsigned char* table);
    unsigned char shape_shadow_unclipped(TDrawArea* draw_area, long x, long y, unsigned char* table);
    unsigned char shape_draw_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long clip_x0, long clip_y0, long clip_x1, long clip_y1);
    unsigned char shape_color_trans_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long shape_idx, long clip_x0, long clip_y0, long clip_x1, long clip_y1, unsigned char* table);
    unsigned char shape_shadow_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long clip_x0, long clip_y0, long clip_x1, long clip_y1, unsigned char* table);

    unsigned char shape_mirror_unclipped(TDrawArea* draw_area, long x, long y);
    unsigned char shape_mirror_color_trans_unclipped(TDrawArea* draw_area, long x, long y, long shape_idx, unsigned char* table);
    unsigned char shape_mirror_shadow_unclipped(TDrawArea* draw_area, long x, long y, unsigned char* table);
    unsigned char shape_mirror_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long clip_x0, long clip_y0, long clip_x1, long clip_y1);
    unsigned char shape_mirror_color_trans_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long shape_idx, long clip_x0, long clip_y0, long clip_x1, long clip_y1, unsigned char* table);
    unsigned char shape_mirror_shadow_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long clip_x0, long clip_y0, long clip_x1, long clip_y1, unsigned char* table);

    unsigned char shape_dithered_unclipped(TDrawArea* draw_area, long x, long y, long param_4, long param_5);
    unsigned char shape_dithered_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long clip_x0, long clip_y0, long clip_x1, long clip_y1, long param_8, long param_9);
};
static_assert(sizeof(TShape) == 0x20, "Size mismatch");

