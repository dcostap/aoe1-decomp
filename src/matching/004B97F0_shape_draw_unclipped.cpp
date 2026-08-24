// 004B97F0 TShape::shape_draw_unclipped
// Shape.cpp:777-836, 232 bytes
//
// Attempt log:
// (prior worker) parked claiming VC5 always inlines memcpy/memset with /O2 and
// no pragma prevents it — contradicted by DibWriteClipped (00439BE0, exact)
// which uses #pragma function(memcpy), and by shape_mirror_unclipped
// (004BA900) which emits a real memset call via a plain extern declaration.
//
// sa-8a05ceeb rewrite: forward RLE draw, modeled on the mirror sibling plus
// the observed memcpy(0054DAC0)/memset(0054DA60) call surface. No CRT headers
// are included so the /Oi intrinsic pragma never activates; manual extern
// declarations keep memcpy/memset as real calls with matching relocations.
//
// orch2-4B97F0-row (2026-08-12): adapted the exact 004BA900 donor pattern.
// One d cursor carries the row start through incoming y's home; the row-end
// reload advances y and restores d. Declaring rows before d preserves the
// target homes while keeping typed forward RLE operations.
//
// baseline (kind=baseline): two-pointer reconstruction (outer d + inner w
//   cursor), (b&1)==1 idiom, TShape_Caller local class. 239B rebuilt vs 232
//   orig, shape 68.09%, prologue has sub esp,8 (extra c slot) and
//   da->ebp/height->edi coloring vs orig da->ebx/height->ebp.
// probe (context): real TShape/TDrawArea class surfaces from matched donors
//   -> byte-identical code (class surface irrelevant here).
// probe (layout): single shared `unsigned char c` declared before the two
//   branches -> extra slot gone (frame none, push ecx), shape 76.60%,
//   diff 215/232, exact-blocks 37%. Inner loop matches (and cl,1 / cmp cl,1,
//   c home [esp+20h], w/d row-end reload). REMAINING (localized): prologue
//   register coloring (da->ebp/Orien->ebx/height->edi/p->esi vs orig
//   da->ebx/height->ebp/Orien->esi/p->edi) and rows/d stack-home swap
//   (rebuilt rows->param_2,d->param_1 vs orig rows->param_1,d->param_2).
//   Calls 3/3 aligned (alignedwidth/memcpy/memset). Next lead: probe source
//   declaration order rows-before-d and single height counter to flip the
//   allocator basin; consider variant_lab on the prologue scheduling.
// sa-a6e9af4c-r1 probes: rows-before-d and height-as-counter were worse;
//   split header temporaries, delayed declaration/assignment, cursor-before-
//   height, and named orientation were duplicate/no-op basins. A focused
//   setup/home variant lab found no better family.
// sa-a6e9af4c-r1 control-flow probe: spelling both run tests as c == 0 first
//   put the zero cases inline and nonzero memcpy/memset arms out of line,
//   matching the original branch topology (232B, 84.21% shape, 212 diff).
// sa-a6e9af4c-r1 control-flow probe: initializing rows inside the positive
//   height guard recovered the original parameter homes (rows -> da slot,
//   d -> y slot) and improved to 234B, 87.10% shape, 208 diff. Register
//   qualifiers were a duplicate and were removed.
// Left in scratch: best natural source has aligned RLE blocks/calls/stack
//   homes; remaining drift is the early callee-save coloring/setup and a
//   two-byte size/epilogue difference.
//
// sa-78979d2a-draw probes (2026-08-09):
// - Reordered orientation/payload declarations, used direct orientation
//   members, split destination declaration, and hoisted the working cursor;
//   all were codegen duplicates of the clean source.
// - A split ymax/ymin height calculation was also a duplicate. The best
//   natural source remains 234B/208 strict bytes with all three calls and the
//   RLE block topology aligned; the unresolved gap is VC5 prologue/register
//   coloring plus swapped destination/row parameter-home assignment.
// sa-43841f2d-shape-draw-unclipped probes (2026-08-09):
// - Used the binary-supported int span count; VC5 emitted the same 234-byte
//   candidate as long height.
// - Matched exact Shape.cpp donor ABI with <string.h>, pragma function, C-linkage
//   memcpy/memset, and long-return AlignedWidth; call relocations now identify the
//   original _memcpy/_memset and TDrawArea::AlignedWidth symbols.
// - Restored the full proven TDrawArea clip/tail layout; emitted code was
//   unchanged. Remaining drift is the known early register/local-home basin.
// - Direct donor 00444B40 was rechecked after the provisional int trial:
//   AlignedWidth is long-returning, and the living declaration now matches it.

// orch-shape-02 fresh bounded pass (2026-08-10; 10 meaningful hypotheses):
// - Reused the second long parameter as the outer destination address and
//   kept a row-local working cursor. This recovered the binary-proven
//   destination/row parameter homes and improved shape to 92.47%, but stayed
//   234B/208 strict bytes; natural x/y formal naming was a duplicate.
// - A named orientation local was a duplicate. Materializing aligned width
//   first and multiplying it in place improved the diagnostic to 206 strict
//   bytes with the same 234B size; a compound width update was identical.
// - Split height statements, payload-before-height declaration order, and a
//   hoisted working cursor were all duplicates. Declaring payload after the
//   width call worsened to 225 strict bytes. Widening height back to long was
//   identical.
// - Restored the pinned natural two-pointer forward RLE source. The direct
//   parameter-address form is retained only as diagnostic evidence: it is
//   decompiler-shaped and did not resolve the original EBP/ESI/EDI prologue
//   coloring or two-byte size gap. Calls and relocation identities remain
//   aligned; the blocker is the early VC5 register/local-home basin.

#include <string.h>
#pragma function(memcpy)
#pragma function(memset)

extern "C" void* __cdecl memcpy(void* dest, const void* src, unsigned int count);
extern "C" void* __cdecl memset(void* dest, int c, unsigned int count);

#ifndef AOE1_SHAPE_CONTEXT_H
struct Shape_Header {
    long bounds;    // +0x00
    long origin;    // +0x04
    long xmin;      // +0x08
    long ymin;      // +0x0C
    long xmax;      // +0x10
    long ymax;      // +0x14
};

class TDrawArea {
public:
    char gap_00[8];
    unsigned char* Bits;    // +0x08
    void* BitmapInfo;       // +0x0C
    void* Bitmap;           // +0x10
    void* OldBitmap;        // +0x14
    int Width;              // +0x18
    int Height;             // +0x1C
    int Pitch;              // +0x20
    int Orien;              // +0x24
    char ClipRect[0x10];    // +0x28
    char _tail_38[0xC8];
    long AlignedWidth();
};

// Main-agent audit confirmed canonical non-polymorphic shape/draw-area ownership
// and retained the natural typed RLE decoder.
class TShape {
public:
    unsigned char* shape;       // +0x00
    int load_type;              // +0x04
    int load_size;              // +0x08
    Shape_Header* shape_header; // +0x0C
    void* head;                 // +0x10
    void* offsets;              // +0x14
    void* FShape;               // +0x18
    void* shape_info;           // +0x1C

    unsigned char shape_draw_unclipped(TDrawArea*, long, long, long);
};
#endif

unsigned char TShape::shape_draw_unclipped(TDrawArea* da, long y, long x, long table)
{
    Shape_Header* sh = this->shape_header;
    int height = sh->ymax - sh->ymin + 1;
    unsigned char* p = (unsigned char*)(sh + 1);
    long pitch = da->AlignedWidth() * da->Orien;
    long rows;
    unsigned char* d;
    unsigned char c;

    if (da->Orien < 1)
        d = da->Bits + (x - da->Height + 1) * pitch + y;
    else
        d = da->Bits + x * pitch + y;

    y = (long)d;

    if (height > 0) {
        rows = height;
        do {
            unsigned char done = 0;
            do {
                unsigned char b = *p++;
                if ((b & 1) == 1) {
                    c = b >> 1;
                    if (c == 0) {
                        d += *p;
                        p++;
                    } else {
                        memcpy(d, p, c);
                        d += c;
                        p += c;
                    }
                } else {
                    c = b >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        unsigned char t = *p;
                        memset(d, t, c);
                        d += c;
                        p++;
                    }
                }
            } while (!done);
            y += pitch;
            d = (unsigned char*)y;
        } while (--rows);
    }

    return 1;
}
