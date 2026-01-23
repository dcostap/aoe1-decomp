#pragma once
#include "common.h"

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

class Shape_Info {
public:
    unsigned long Shape_Data_Offsets; // +0x0 (Size: 0x4)
    unsigned long Shape_Outline_Offset; // +0x4 (Size: 0x4)
    long Reserved1; // +0x8 (Size: 0x4)
    long Reserved2; // +0xC (Size: 0x4)
    long Width; // +0x10 (Size: 0x4)
    long Height; // +0x14 (Size: 0x4)
    long Hotspot_X; // +0x18 (Size: 0x4)
    long Hotspot_Y; // +0x1C (Size: 0x4)
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
    TShape(char* filename, int file_id);
    ~TShape();
    
    // Methods
    int is_loaded();
    long shape_count();
    
    unsigned char shape_draw(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, unsigned char param_6, unsigned char* param_7);
    
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
    unsigned char Check_shape(long param_1, char* param_2);
};
static_assert(sizeof(TShape) == 0x20, "Size mismatch");
