// VA: 004B98E0, TShape::shape_color_trans_unclipped, 268 bytes
// Source: Shape.cpp lines 841-905
// Status: SCRATCH — remaining mismatch is pervasive register allocation,
// prologue structure, and memset inlining differences.
//
// Known correct: function behavior, RLE decoding logic, parameter mapping,
// field offsets (TShape+0x0C, TDrawArea+0x08/0x1C/0x24), AlignedWidth call,
// memset library address.
//
// Remaining issues:
// 1. Prologue: original uses `sub esp, 8` (8B locals) + `push ebx; push ebp;
//    push esi; push edi`. Modern compiler generates different prologue with
//    `push ecx` equivalence or reordered register saves.
// 2. Register allocation: completely different register assignments (edi=src,
//    esi=dst in original; different in rebuilt).
// 3. Orien loading order: original loads td->Orien into esi BEFORE AlignedWidth
//    call, but still after ymin/ymax loads. My compiler moves it around.
// 4. memset inlining: modern MSVC inlines small memset calls as `rep stosd`
//    instead of calling the library. Manual byte-fill loops generate different
//    patterns.
// 5. Copy loop instruction pattern: original uses pre-increment on dst
//    (`inc esi; mov [esi-1], cl`), modern compiler uses post-increment.
// 6. Stack slot reuse: original reuses param slots ([esp+1Ch], [esp+20h],
//    [esp+24h]) for local variables. Compiler allocates independent slots.
//
// Attempt log:
// - v1: wrong Orien order (loaded after AlignedWidth), memset inlined as rep stosd
// - v2: fixed Orien order, function pointer for memset → 256 bytes, wrong prologue
// - v3: manual byte loops → 208 bytes, prologue completely restructured
// - v4: bound-checked copy loop (while dst < end) → same as v3 (208 bytes)
// - Conclusion: modern VC5 (VS2022) generates fundamentally different
//   optimization for this function compared to original VC5. Multiple
//   independent axes (prologue, register alloc, memset, loop pattern) differ
//   simultaneously, making incremental matching impractical without deeper
//   compiler version analysis.
// FLAGS: /nologo /c /O2 /Oy

#include <memory.h>

typedef unsigned char uchar;

struct TDrawArea {
    char _pad_00[0x08];
    uchar* Bits;           // +0x08
    char _pad_0C[0x10];
    int Height;            // +0x1C
    int Pitch;             // +0x20
    int Orien;             // +0x24

    long AlignedWidth();
};

struct TShape {
    char _pad_00[0x0C];
    void* shape_header;    // +0x0C

    uchar shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal);
};

uchar TShape::shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal)
{
    int* hdr = (int*)this->shape_header;
    long ymax = hdr[5];
    long ymin = hdr[3];
    long height = (ymax - ymin) + 1;
    uchar* src = (uchar*)this->shape_header + 0x18;

    long Orien = td->Orien;
    long alw = td->AlignedWidth();
    long stride = alw * Orien;

    long dest_off;
    if (Orien >= 1) {
        dest_off = p3 * stride;
    } else {
        dest_off = (p3 - td->Height + 1) * stride;
    }
    uchar* dst = td->Bits + p2 + dest_off;

    long remaining = height;
    while (remaining > 0) {
        uchar done = 0;
        do {
            uchar b = *src++;
            if ((b & 1) == 1) {
                uchar cnt = b >> 1;
                if (cnt == 0) {
                    dst += *src;
                    src++;
                } else {
                    uchar* end = dst + cnt;
                    do {
                        *dst = pal[*src++];
                        dst++;
                    } while (dst < end);
                }
            } else {
                uchar cnt = b >> 1;
                if (cnt == 0) {
                    done = 1;
                } else {
                    uchar val = pal[*src];
                    src++;
                    do {
                        *dst++ = val;
                    } while (--cnt != 0);
                }
            }
        } while (!done);

        dst += stride;
        remaining--;
    }

    return 1;
}
