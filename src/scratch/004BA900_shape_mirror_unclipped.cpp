// 004BA900 shape_mirror_unclipped (Shape.cpp:1809-1874)
// PDB source: Shape.cpp (TShape::shape_mirror_unclipped)
//
// uchar __thiscall TShape::shape_mirror_unclipped(TDrawArea*, long param_2, long param_3)
// ret 0Ch cleanup (3 params, thiscall)
//
// === Attempt log ===
// attempts 1-13: all produce 208-byte functions vs required 220.
// Remaining diff: extra `push ecx` (51) in prologue, 4-byte stack offset shift.
// Root cause: original reuses param_1/param_2/param_3 stack slots for local
//   variables (rows_remaining, dest_ptr, temp_count). My C++ introduces a 4th
//   stack slot (pitch ends up on stack, h in ebp) because register allocator
//   chooses a different layout (ebp=h vs original's ebp=pitch).
// Tried: member functions, __fastcall, goto-based loops, while/do-while/for,
//   extern memset, parameter reuse, variable ordering.
// All produce 208-byte family with identical extra stack slot.
// This is a VC5 register allocation / stack slot reuse difference that
// appears to be TU-context dependent (Shape.cpp with full TShape class).
//
// Best variant retained below.

extern void* my_memset(void*, int, unsigned int);

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct TDrawArea_Shape {
    char _gap_00[8];
    unsigned char* Bits;
    char _gap_0C[0x10];
    int Height;
    char _gap_20[4];
    int Orien;
    int AlignedWidth();
};

struct TShape_Caller {
    unsigned char* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    unsigned char shape_mirror_unclipped(TDrawArea_Shape*, long, long);
};

unsigned char TShape_Caller::shape_mirror_unclipped(TDrawArea_Shape* da, long p2, long p3)
{
    int orien = da->Orien;
    int pitch = da->AlignedWidth() * orien;
    unsigned char* p = (unsigned char*)shape_header + 0x18;
    unsigned char* d;
    int m;
    int h = shape_header->ymax - shape_header->ymin + 1;
    if (orien < 1)
        m = ((p3 - da->Height) + 1) * pitch;
    else
        m = p3 * pitch;
    d = da->Bits + m + p2 + 1;

    if (h <= 0) return 1;

    // Mirror RLE decode: copy rows from FShape to dest with backward write
    goto begin_row;
next_row:
    d += pitch;
begin_row:
    {
        int done = 0;
        goto decode_byte;
next_byte:
        done = 0;
decode_byte:
        {
            unsigned char b = *p++;
            unsigned char c;

            if (b & 1) {
                c = b >> 1;
                if (c) {
                    do {
                        unsigned char t = *p;
                        d--; p++; c--;
                        *d = t;
                    } while (c);
                    goto check_done;
                }
                d -= *p++;
                goto check_done;
            }

            c = b >> 1;
            if (c) {
                unsigned char t = *p++;
                d -= c;
                my_memset(d, t, c);
            } else {
                done = 1;
            }
check_done:
            if (!done) goto decode_byte;
        }
    }
    if (--h) goto next_row;

    return 1;
}
