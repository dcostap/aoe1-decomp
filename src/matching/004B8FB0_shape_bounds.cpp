// VA: 004B8FB0 TShape::shape_bounds()
// Source: Shape.cpp lines 285-304
// Size: 132 bytes, __thiscall, ret 0Ch (3 params)
// Returns: unsigned char in AL
// Params: long index, short& out_width, short& out_height

struct Shape_Header {
    long bounds;    // +0x00
    long origin;    // +0x04
    long xmin;      // +0x08
    long ymin;      // +0x0C
    long xmax;      // +0x10
    long ymax;      // +0x14
};

struct Shape_Offsets {
    long shape;     // +0x00
    long palette;   // +0x04
};

struct Shape_Info {
    unsigned long Shape_Data_Offsets;  // +0x00
    unsigned long Shape_Outline_Offset; // +0x04
    long Reserved1;                    // +0x08
    long Reserved2;                    // +0x0C
    long Width;                        // +0x10
    long Height;                       // +0x14
    long Hotspot_X;                    // +0x18
    long Hotspot_Y;                    // +0x1C
};

struct SLhape_File_Header;
struct Shape_File_Header;

class TShape {
public:
    unsigned char* shape;           // +0x00
    int load_type;                  // +0x04
    int load_size;                  // +0x08
    Shape_Header* shape_header;     // +0x0C
    Shape_File_Header* head;        // +0x10
    Shape_Offsets* offsets;         // +0x14
    SLhape_File_Header* FShape;     // +0x18
    Shape_Info* shape_info;         // +0x1C

    unsigned char Check_shape(long index, const char* name);
    unsigned char shape_bounds(long index, short& out_width, short& out_height);
};

unsigned char TShape::shape_bounds(long index, short& out_width, short& out_height) {
    if (this->FShape != 0) {
        out_width = (short)this->shape_info[index].Width;
        out_height = (short)this->shape_info[index].Height;
        return 1;
    }

    if (index >= 0) {
        unsigned char result = Check_shape(index, "RGL_shape_resolution");
        if (result == 0) {
            this->shape_header = (Shape_Header*)(this->shape + this->offsets[index].shape);
            out_width = (short)(this->shape_header->bounds >> 16);
            out_height = (short)this->shape_header->bounds;
            return 1;
        }
    }

    return 0;
}
