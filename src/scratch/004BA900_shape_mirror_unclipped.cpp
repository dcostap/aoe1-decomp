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
//
// attempt 14 (sa-1016b854): clean rewrite. Key changes vs prior best:
//   - rows is a SEPARATE local from height so `height` dies before the row
//     loop; the original keeps pitch in ebp (long-lived) and the row counter
//     in the dead param_1 home slot [esp+14h].
//   - done is `unsigned char` (xor bl,bl / mov bl,1 / test bl,bl), c is
//     `unsigned char` (byte store to [esp+1Ch], dword reload + and 0FFh).
//   - real `memset` symbol (extern "C" void* __cdecl memset) so the direct
//     call relocation identity matches 0054DA60 (toolchain-supplied memset).
//   RESULT: prologue + first 0x32 bytes EXACT, calls 100% aligned (memset
//   symbol works). But rebuilt 187 vs 220 (33 short): (a) literal loop is a
//   do-while (no entry `test al,al; jbe`, no c home reload+mask) instead of
//   original while-loop; (b) branch layout of odd/even inner ifs is reversed
//   (then-inline vs original else-inline): original uses `jne` to out-of-line
//   non-zero bodies, so source should test `c == 0` first; (c) rows/d/c stack
//   homes assigned differently (rows->[esp+1Ch] instead of [esp+14h]) and d
//   got no home at all; (d) p++ not tail-merged into shared `inc esi`.
//
// attempt 15 (sa-1016b854): structural fixes:
//   - rows assigned BEFORE d in source (original PDB: 1826 rows, 1828 d) so
//     stack-home order matches (rows->param_1, d->param_2, c->param_3).
//   - inner ifs spelled `if (c == 0) {..} else {..}` so the zero-case is
//     inline and the non-zero body (literal loop / fill) is the out-of-line
//     jump target, matching the original `jne` layout and enabling the shared
//     `inc esi` tail merge.
//   - literal run as `while (c > 0) { *--d = *p++; c--; }` to reproduce the
//     entry `test al,al; jbe` guard and the masked c home reload in eax.
//   RESULT: 202 bytes (vs 220); loop body 004BA95C+ now byte-identical;
//   calls 100%% aligned; shape similarity 90.2%%; first mismatch +0032.
//
// attempt 16 (sa-1016b854): declared `unsigned char c` ONCE at function
//   scope (shared odd/even paths) instead of two block-scoped c locals.
//   RESULT: c now stores to [esp+1Ch] in both paths (was split across
//   [esp+14h]/[esp+18h]) matching the original; rows->[esp+14h] correct.
//   Same 202-byte size, identical loop.
//
// attempt 17 (sa-1016b854): swapped declaration order (d before rows).
//   RESULT: byte-identical output to 16; no change. Reverted to rows-before-d
//   (PDB-plausible 1826/1828 order).
//
// Remaining 18-byte gap (all in setup + row-end, loop is exact):
//   (a) rows store: rebuilt emits `mov [esp+14h],eax` at +0046 (right after
//       Bits load); original sinks it to +0058 (first instr of loop entry,
//       after the h<=0 branch). This cascades into the Bits+m accumulator
//       register choice: original `add ecx,edx; lea edi,[ecx+edx+1]` (m in
//       ecx), rebuilt `add edx,ecx; lea edi,[edx+ecx+1]` (SIB base/index
//       swapped, 1 byte + shift).
//   (b) d memory home: original stores d to [esp+18h] at setup and does
//       `mov edi,[esp+18h]; add edi,ebp; mov [esp+18h],edi` at the row end
//       (+8 bytes); rebuilt keeps d register-only (`add edi,ebp`).
//   Both are VC5 local-home/scheduling artifacts; the loop itself matches.
//   Next leads: force the d home via x-param slot reuse (LESSONS.md
//   parameter-slot-reuse pattern), or sink rows store by restructuring the
//   `if (height > 0)` guard / rows assignment site.
//
// fresh claim (sa-b1dcad27-shape, 2026-08-09; 10 meaningful hypotheses):
// - A named odd-byte flag / direct `(b & 1) == 1` comparison changed the
//   branch basin but did not improve strict bytes; the direct truth test is
//   retained. A second direct-comparison rerun was codegen-identical.
// - Moving `rows = height` inside the positive height guard preserved the
//   natural source model and moved the row-home store to the loop entry;
//   retained result improved the checker to 136 differing bytes (202/220).
// - Splitting the destination declaration from its assignment was codegen
//   identical. A Ghidra-supported row-base/working-destination pair, with and
//   without the full Shape class surface, added `push ecx` and spilled pitch;
//   both were rolled back as a worse basin. Mutating x as an address cursor
//   was optimized to the same code and was rolled back as noncanonical.
// - The local TShape/TDrawArea declarations now expose the proven full field
//   surfaces; this did not change codegen, but keeps ownership/layout explicit.
// - Final retained gap is structural: original stores destination through
//   [esp+18h] and uses `mov cl,al; and cl,1; cmp cl,1`; rebuilt keeps d in EDI
//   and lowers the odd test directly. Calls are ordered/aligned (AlignedWidth,
//   memset), and no behavior-changing source scaffold is retained.
// - Main-agent normalization restored the canonical TShape/TDrawArea class
//   names; emitted code is unchanged.
//
// sa-78979d2a-shape probes (2026-08-09):
// - Explicit `(b & 1) == 1` restored the original branch idiom but moved the
//   candidate to a 208-byte family (143 strict bytes); rolled back.
// - Splitting a persistent row base from a per-row working destination matched
//   the size but destroyed the donor prologue/block basin (217 strict bytes);
//   rolled back.
// - Reordering/splitting destination address terms and assigning the computed
//   destination through the dead x parameter were codegen duplicates; rolled
//   back as noncanonical.
// - Retained natural typed RLE source. Remaining blocker is the original VC5
//   local-home schedule: destination is written/reloaded through x's home and
//   rows through da's home, while this clean candidate keeps destination in EDI.
// sa-43841f2d-shape-mirror-unclipped probes (2026-08-09):
// - Matched the same-TU CRT source family with <string.h>, #pragma function,
//   and extern-C memset; this restored the original _memset relocation while
//   preserving the 202-byte/136-diff candidate.
// - Restored the proven full TDrawArea clip/tail layout; emitted code was
//   unchanged. The remaining gap is the documented row-base/home and setup
//   accumulator schedule, not header or clip ownership.
// - Direct donor 00444B40 was rechecked: AlignedWidth is long-returning, not
//   the earlier provisional int stub; correcting it preserved bytes and fixes
//   the mangled call identity to the original TDrawArea method.

// orch-shape-01 fresh bounded pass (2026-08-10; 10 meaningful hypotheses):
// - Directly mutating x as an integer destination cursor changed only the
//   setup SIB byte (135 strict bytes); an ordinary address-taken x alias was
//   codegen-identical. A pointer reference overlaid on x was also identical.
// - Two persistent row/working cursors with a post-row handoff destroyed the
//   prologue/block basin (220B, 216 strict bytes); independently advancing
//   both cursors optimized back to the clean 202B candidate. A long integer
//   address local likewise produced the clean duplicate.
// - A diagnostic volatile x-home roundtrip reproduced the original 220-byte
//   size, x-home setup/row-end stores, and all block boundaries (129 strict
//   bytes). Adding the binary-proven explicit odd-byte compare reduced this
//   diagnostic to 11 strict bytes / 100% shape; naming the odd temp and
//   m-first destination expression were duplicates. Volatile home forcing is
//   not retained because it is compiler-steering scaffolding, not defensible
//   period source.
// - Restored the pinned natural typed RLE source. Remaining evidence-backed
//   blocker is the VC5 x-parameter home allocation plus localized setup
//   register coloring; loop/calls/relocations remain aligned.

#include <string.h>
#pragma function(memset)
extern "C" void* __cdecl memset(void* dest, int c, unsigned int count);

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct TDrawArea {
    char _gap_00[8];
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    char ClipRect[0x10];
    char _tail_38[0xC8];
    long AlignedWidth();
};

struct Shape_Offsets {
    long shape;
    long palette;
};

struct Shape_File_Header;
struct SLhape_File_Header;

struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

// Main-agent audit confirmed canonical non-polymorphic shape/draw-area ownership
// and retained the natural typed RLE decoder.
struct TShape {
    unsigned char* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;
    unsigned char shape_mirror_unclipped(TDrawArea*, long, long);
};

unsigned char TShape::shape_mirror_unclipped(TDrawArea* da, long x, long y)
{
    long pitch = da->AlignedWidth() * da->Orien;
    Shape_Header* sh = this->shape_header;
    long height = sh->ymax - sh->ymin + 1;
    unsigned char* p = (unsigned char*)(sh + 1);
    long m;
    if (da->Orien < 1)
        m = (y - da->Height + 1) * pitch;
    else
        m = y * pitch;
    long rows;
    unsigned char* d;
    d = da->Bits + m + x + 1;
    unsigned char c;

    if (height > 0) {
        rows = height;
        do {
            unsigned char done = 0;
            do {
                unsigned char b = *p++;
                if (b & 1) {
                    c = b >> 1;
                    if (c == 0) {
                        d -= *p;
                        p++;
                    } else {
                        while (c > 0) {
                            *--d = *p++;
                            c--;
                        }
                    }
                } else {
                    c = b >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        unsigned char t = *p;
                        d -= c;
                        memset(d, t, c);
                        p++;
                    }
                }
            } while (!done);
            d += pitch;
        } while (--rows);
    }

    return 1;
}
