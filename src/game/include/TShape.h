#pragma once
#include "common.h"

struct TShape {
    uchar* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;
};
static_assert(sizeof(TShape) == 0x20, "Size mismatch");
