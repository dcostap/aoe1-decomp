// VA: 004B8FB0 TShape::shape_bounds()
// Source: Shape.cpp lines 285-304
// Size: 132 bytes, __thiscall, ret 0Ch (3 params)
// Returns: unsigned char in AL
// Params: long index, short& out_width, short& out_height

#include "../../include/shape_context.h"

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
