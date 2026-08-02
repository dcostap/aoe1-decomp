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

void* __cdecl memset(void* dest, int c, unsigned int count);

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

unsigned char TShape_Caller::shape_mirror_unclipped(TDrawArea_Shape* da, long x, long y)
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
    long rows = height;
    unsigned char* d = da->Bits + m + x + 1;
    unsigned char c;

    if (height > 0) {
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
