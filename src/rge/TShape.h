#pragma once
#include "../types.h"

struct Shape_File_Header {
    long version;
    long shape_num;
};

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct Shape_Info {
    ulong Shape_Data_Offsets;
    ulong Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

struct Shape_Offsets {
    long shape;
    long palette;
};

struct SLhape_File_Header {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
};

struct TShape {
    /* 0x00 */ uchar *shape;
    /* 0x04 */ int load_type;
    /* 0x08 */ int load_size;
    /* 0x0C */ struct Shape_Header *shape_header;
    /* 0x10 */ struct Shape_File_Header *head;
    /* 0x14 */ struct Shape_Offsets *offsets;
    /* 0x18 */ struct SLhape_File_Header *FShape;
    /* 0x1C */ struct Shape_Info *shape_info;

    TShape(const char *file, int id);
    ~TShape();

    int is_loaded();
    void shape_draw(struct TDrawArea *dest, int x, int y, int frame);
};

// MANDATORY VERIFICATION
static_assert(sizeof(TShape) == 32, "TShape size mismatch");
