// Shape.cpp:180-203, 107 bytes
// attempt 1: compile error, type mismatch
// attempt 2: 57.0%, first probe
// attempt 3: 6.5%, fixed RESFILE args to match asm
// attempt 4: 3.7%, swapped second block args
// attempt 5: 3.7%, confirmed, tried swapping back (25.2% worse)
// variant lab: second-decommit argument plus vc5_store_order4 over zero stores found exact match
// Canonical TShape ownership places load_size at +08 and shape_header at +0C.
// The mapped-memory calls use load_size. The destructor clears shape_header,
// head, and offsets after cleanup, as shown by the original stores.
#include "../../include/shape_context.h"

typedef unsigned char uchar;
extern "C" void __cdecl free(void*);
extern int __cdecl RESFILE_Decommit_Mapped_Memory(uchar*, int);

TShape::~TShape() {
    if (FShape != 0) {
        if (load_type == 1) {
            free(FShape);
        }
        if (load_type == 0) {
            RESFILE_Decommit_Mapped_Memory((uchar*)FShape, load_size);
        }
    }
    if (shape != 0) {
        if (load_type == 1) {
            free(shape);
        }
        if (load_type == 0) {
            RESFILE_Decommit_Mapped_Memory(shape, load_size);
        }
    }
    shape = 0;
    shape_header = 0;
    head = 0;
    offsets = 0;
    FShape = 0;
}
