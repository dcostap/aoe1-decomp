#ifndef AOE1_SHAPE_H
#define AOE1_SHAPE_H

#include "drawarea.h"
#include "Res_file.h"

typedef unsigned char byte;

typedef struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
} Shape_Header;

typedef struct Shape_File_Header {
    long version;
    long shape_num;
} Shape_File_Header;

typedef struct Shape_Offsets {
    long shape;
    long palette;
} Shape_Offsets;

typedef struct SLhape_File_Header {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
} SLhape_File_Header;

typedef struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
} Shape_Info;

struct Shape_Payload {
    byte value;
};

struct Byte_Table {
    union {
        byte table[256];
        byte value[256];
    };
};

struct Shape_Byte_Table {
    byte table[256];
};

typedef tagRECT Rect;
typedef Shape_File_Header ShapeFile;
typedef Shape_Header TShapeHeader;

extern unsigned char shape_file_first;
extern int Shape_Loads;
extern int ASM_Fast_Count;

class DClipInfo_List;

class TShape {
public:
    byte* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;

    TShape();
    TShape(char* filename, long resource_file_id);
    ~TShape();

private:
    byte Check_shape(long shape_num, char* proc);

public:
    int is_loaded();
    byte shape_bounds(long shape_num, short& width, short& height);
    long shape_count();
    byte shape_minmax(long& x_min, long& y_min, long& x_max, long& y_max, long shape_num);
    byte shape_check(long check_x, long check_y, long shape_num);

private:
    byte shape_draw_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long shape_num);
    byte shape_color_trans_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long shape_num, byte* color_table);
    byte shape_shadow_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, byte* color_table);
    byte shape_draw_clipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long clip_x0, long clip_y0, long clip_x1, long clip_y1);
    byte shape_color_trans_clipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long shape_num, long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* color_table);
    byte shape_shadow_clipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* color_table);

public:
    byte shape_draw(TDrawArea* drawarea, long x, long y, long shape_num, byte flags, byte* color_table);

private:
    byte shape_mirror_unclipped(TDrawArea* drawarea, long shape_x1, long shape_y0);
    byte shape_mirror_color_trans_unclipped(TDrawArea* drawarea, long shape_x1, long shape_y0, long shape_num, byte* color_table);
    byte shape_mirror_shadow_unclipped(TDrawArea* drawarea, long shape_x1, long shape_y0, byte* color_table);
    byte shape_mirror_clipped(TDrawArea* drawarea, long shape_x1, long shape_y0, long clip_x0, long clip_y0, long clip_x1, long clip_y1);
    byte shape_mirror_color_trans_clipped(TDrawArea* drawarea, long shape_x1, long shape_y0, long shape_num, long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* color_table);
    byte shape_mirror_shadow_clipped(TDrawArea* drawarea, long shape_x1, long shape_y0, long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* color_table);

public:
    byte shape_mirror(TDrawArea* drawarea, long x, long y, long shape_num, byte flags, byte* color_table);

private:
    byte shape_dithered_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long dx, long dy);
    byte shape_dithered_clipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long clip_x0, long clip_y0, long clip_x1, long clip_y1, long dx, long dy);

public:
    byte shape_dither(TDrawArea* drawarea, long x, long y, long shape_num, long dx, long dy);
};

#endif
