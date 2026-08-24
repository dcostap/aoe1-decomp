#ifndef AOE1_SHAPE_TU_CONTEXT_H
#define AOE1_SHAPE_TU_CONTEXT_H

// Shape.cpp module context.  The reviewed shared Shape declarations provide
// the owner ABI; these declarations add only types used by this TU's bodies.
#include "../include/shape_context.h"

typedef unsigned char uchar;

class TSpan_List_Manager {
public:
    char gap_00[0x3c];
    void* Line_Head_Ptrs;
    void* Line_Tail_Ptrs;
    char gap_44[0x0c];
    int Num_Lines;
    char gap_54[8];
    int Max_Span_Px;
};

class DClipInfo_List {
public:
    void AddDrawNode(void* shape_base, Shape_Info* shape, int yline,
                     int draw_x, int draw_y, int draw_flag,
                     byte* color_table, int xform_mask,
                     int draw_level, int object_id);
};

typedef tagRECT Rect;
typedef Shape_File_Header ShapeFile;
typedef Shape_Header TShapeHeader;

struct Shape_Payload {
    byte value;
};

struct Byte_Table {
    union {
        byte table[256];
        byte value[256];
    };
};

extern int SDI_Capture_Info;
extern int SDI_Draw_Level;
extern long SDI_Object_ID;
extern int SDI_Draw_Line;
extern int fog_next_shape;
extern DClipInfo_List* SDI_List;
extern int ASM_Fast_Count;

extern "C" int __cdecl ASMGet_Color_Xform();
extern "C" void __cdecl ASMSet_Surface_Info(void*, void*, void*, int, int,
                                              int, int);
extern "C" void __cdecl ASMSet_Xlate_Table(void*);
extern "C" void __cdecl ASMDraw_Sprite(void*, long, long, long, long, long,
                                         long, int);

#endif
