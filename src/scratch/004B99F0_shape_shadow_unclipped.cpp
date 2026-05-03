// 004B99F0 TShape::shape_shadow_unclipped
// Shape.cpp:909-972, 254 bytes
//
// uchar __thiscall TShape::shape_shadow_unclipped(TDrawArea* da, long x, long y, unsigned char* table)
// ret 10h cleanup (4 params on stack, this in ecx)
//
// === Attempt log ===
//
// 1-2: Wrong prologue order - compiler saved 'this' before reading shape_header
//      Fix: read shape_header fields BEFORE any da-> access
// 3: do-while pattern - 224 bytes after padding, 89% positional diff
// 4-5: Goto-based control flow attempts
// 6: extern AlignedWidth call - 240 bytes
// 7: AND/CMP pattern for bit test ((cmd & 1) == 1) - got shape_header read first!
//    256 bytes, prologue matches through offset 8 (push ecx; mov eax,[ecx+0Ch]; push ebx; push ebp; push esi)
//    First mismatch at offset 8: esi vs ebx for ymax register
// 8-11: Attempted to fix register allocation through:
//    - Separate ymax/ymin locals
//    - p-first declaration order
//    - ymax in-place mutation (ymax -= ymin; ymax++)
//    - Raw offset access ((byte*)sh + 0x14)
//    - declare-before-use order variations
//    All produce ymax→ebx, ymin→esi (original has ymax→esi, ymin→edi)
//
// Root cause: VC5 register allocator assigns variables to callee-saved regs
// differently when the function is compiled standalone vs within Shape.cpp TU.
// Original interleaves register saves with field reads:
//   push esi; mov esi,[eax+14h]; push edi; mov edi,[eax+0Ch]
// My version does all 5 pushes first, then all reads.
// The push-edi between ymax and ymin reads in the original pairs edi with ymin.
// No C-level declaration/use ordering technique can force this exact scheduling.
//
// Remaining diff: 89.37% positional, register allocation cascade throughout.
// Control flow, stack layout, and semantics are correct.
//
// Best source retained below (attempt 7 style, with ymax→ebx/ymin→esi).

typedef unsigned char byte;

struct SH {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct TDA {
    char gap_00[8];
    byte* Bits;
    char gap_0C[0x10];
    int Height;
    char gap_20[4];
    int Orien;
    int AlignedWidth();
};

struct TS {
    byte* shape;
    int load_type;
    int load_size;
    SH* shape_header;
    char _gap_10[0xC];

    byte shape_shadow_unclipped(TDA* da, long x, long y, byte* table);
};

byte TS::shape_shadow_unclipped(TDA* da, long x, long y, byte* table)
{
    SH* sh = shape_header;
    byte* p = (byte*)(sh + 1);
    long rows = sh->ymax - sh->ymin + 1;

    long orien = da->Orien;
    long pitch = da->AlignedWidth() * orien;

    long tmp;
    if (orien < 1)
        tmp = ((y - da->Height) + 1) * pitch;
    else
        tmp = y * pitch;

    byte* d = da->Bits + tmp + x;

    if (rows <= 0)
        return 1;

    byte done;

row_loop:
    done = 0;

    do {
        byte cmd = *p++;
        byte cnt;

        if ((cmd & 1) == 1) {
            cnt = cmd >> 1;
            if (cnt) {
                byte* e = d + (cnt & 0xFF);
                while (d < e) {
                    *d = table[*d];
                    d++;
                }
                p += cnt;
            } else {
                d += *p++;
            }
        } else {
            cnt = cmd >> 1;
            if (cnt) {
                byte* e = d + (cnt & 0xFF);
                while (d < e) {
                    *d = table[*d];
                    d++;
                }
                p++;
            } else {
                done = 1;
            }
        }
    } while (!done);

    d += pitch;
    if (--rows)
        goto row_loop;

    return 1;
}
