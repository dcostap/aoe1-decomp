// Shape.cpp:180-203, 107 bytes
// attempt 1: compile error, type mismatch
// attempt 2: 57.0%, first probe
// attempt 3: 6.5%, fixed RESFILE args to match asm
// attempt 4: 3.7%, swapped second block args
// attempt 5: 3.7%, confirmed, tried swapping back (25.2% worse)
// variant lab: second-decommit argument plus vc5_store_order4 over zero stores found exact match
// winning shape uses shape_header for the second decommit and zeroes shape/head/offsets/load_size before FShape
typedef unsigned char uchar;
extern void __cdecl free(void*);
extern int __cdecl RESFILE_Decommit_Mapped_Memory(uchar*, uchar*);

class TShape {
public:
    uchar* shape;       // +0x00
    int load_type;      // +0x04
    uchar* shape_header; // +0x08
    void* head;         // +0x0C
    void* offsets;      // +0x10
    uchar* load_size;   // +0x14
    uchar* FShape;      // +0x18

    ~TShape();
};

TShape::~TShape() {
    if (FShape != 0) {
        if (load_type == 1) {
            free(FShape);
        }
        if (load_type == 0) {
            RESFILE_Decommit_Mapped_Memory(FShape, shape_header);
        }
    }
    if (shape != 0) {
        if (load_type == 1) {
            free(shape);
        }
        if (load_type == 0) {
            RESFILE_Decommit_Mapped_Memory(shape, shape_header);
        }
    }
    shape = 0;
    head = 0;
    offsets = 0;
    load_size = 0;
    FShape = 0;
}
