// VA: 004B8E40, TShape::Check_shape, 324 bytes
// Source: Shape.cpp lines 207-263
// FLAGS: default

#include <stddef.h>

typedef unsigned char uchar;

extern "C" void __cdecl addstring(char** dest, const char* prefix, const char* str);
extern "C" void __cdecl free(void* ptr);

// "1.10" DWORD value for version comparison
extern int shape_version_110;  // at 57FB58h

struct Shape_File_Header {
    int version;     // +0x00
    int shape_num;   // +0x04
};

struct SLhape_File_Header {
    char pad_00[4];
    int Num_Shapes;  // +0x04
};

class TShape {
public:
    uchar* shape;                // +0x00
    char pad_04[0x0C];
    Shape_File_Header* head;     // +0x10
    char pad_14[0x04];
    SLhape_File_Header* FShape;  // +0x18

    uchar Check_shape(long param_1, char* param_2);
};

uchar TShape::Check_shape(long param_1, char* param_2)
{
    char* msg = 0;

    if (this->shape == 0 && this->FShape == 0) {
        return 1;
    }

    if (this->shape != 0) {
        Shape_File_Header* h = this->head;
        if (h == 0) {
            // No head — bad shape
            addstring(&msg, "ERROR: (", param_2);
            addstring(&msg, msg, ") Bad shape");
            free(msg);
            return 1;
        }

        // Check bounds and version
        if (param_1 < 0 || param_1 < h->shape_num) {
            // param_1 is either negative or in valid range
            // Either way, check version
            if (h->version != shape_version_110) {
                // Version wrong
                addstring(&msg, "ERROR: (", param_2);
                addstring(&msg, msg, ") shape version wrong");
                free(msg);
                return 1;
            }
            // Version matches or negative param — continue to FShape
        } else {
            // Out of bounds (param_1 >= 0 && param_1 >= shape_num)
            addstring(&msg, "ERROR: (", param_2);
            addstring(&msg, msg, ") shape number out of bounds");
            free(msg);
            return 1;
        }
    }

    // FShape check
    if (this->FShape != 0 && param_1 >= 0 && param_1 >= this->FShape->Num_Shapes) {
        addstring(&msg, "ERROR: (", param_2);
        addstring(&msg, msg, ") Fshape number out of bounds");
        free(msg);
        return 1;
    }

    return 0;
}
