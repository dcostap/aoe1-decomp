// VA: 00438820 DibBlt | Dib.cpp:72-145
// Attempt log:
// - The old scratch candidate used the wrong ClipDibBitsToRect/DibGetInfo
//   helper family and treated the final flags as transparency.  The original
//   call map proves ClipDibBlt, GetDibDim (twice), and memcpy, with the final
//   three parameters being do-clip/flip-x/flip-y.
// - Reconstructed the period DIBUTILS blit shape: optional clipping, the two
//   GetDibDim calls, an exact-scale memcpy path, and the shared SrcXTbl scaled
//   path.  The source table is the TU-global SrcXTbl.
// - The corrected baseline reached exact size/frame/call-set and moved the
//   first mismatch into register/home scheduling; saving the destination-info
//   and flip-y lifetimes improved the structural basin (77.58% shape).
// - A Ghidra-shaped temporary/pointer-table variant preserved exact blocks but
//   did not improve the live source; it was rolled back.  Header and
//   long-reference ABI probes did not close the remaining drift.
// - Remaining mismatch is a broad VC5 scheduling/topology gap: the original
//   loads flip-y and destination-info before the ClipDibBlt branch, reloads
//   GetDibDim output before cdecl cleanup, and reuses parameter homes through
//   the scaled/table tails.  Current source keeps the named DIBUTILS behavior
//   and binary-proven long aliases; it remains non-exact rather than forcing
//   opaque codegen scaffolding.
// - A parameter-home alias reached the original frame size. It is diagnostic
//   evidence only. The living source keeps the named vertical step.
// - The original destination-address block multiplies the stride inside each
//   orientation arm.  Replaced the shared dest_row temporary with two named
//   pointer expressions to test that source-level control-flow topology.
// - The fast path also has an orientation-arm multiply for the source row;
//   moved that multiply into the two typed source-row arms.
// - These two arm-shaped expressions are the best clean reconstruction so far:
//   they restore the 0x8 frame and 39.91% exact-block coverage (365-byte diff).
//   The first unresolved hunk is the swapped source stride/direction homes in
//   the second GetDibDim call; its four calls and boundaries remain aligned.
// - Tried precomputing the scaled destination stride in the existing local;
//   that moved the bytes farther, so the source keeps the repeated expression.
// - Scoped the source dimension locals at the second GetDibDim call to test
//   whether source-only lifetimes recover the original output-home rotation.
// - Swapped the natural inner-loop index and table-pointer declarations to
//   test the original index/table register pair in the scaled row body.
// - Accepted-drift review: ClipDibBlt receives the exact formal homes and can
//   mutate the same coordinates. The exact GetDibDim donor only writes its
//   three outputs, so its different private output homes are not observable.
//   Dimension reads, signed division faults, orientation, SrcXTbl writes,
//   scaled source and destination fault addresses, memcpy arguments and order,
//   loop limits, and returns match. Residual drift is private home, register,
//   multiplication-hoist, and equivalent loop lowering.
// - Exact-finish revisit: the PDB local names dy and sySkip support natural
//   source-pitch/source-height ownership. Passing the proven source-height
//   home through dest_rect restores the original second GetDibDim addresses.
//   The reduced source reaches 0x8 frame, 4 ordered calls, 615 bytes, and a
//   321-byte mismatch. The remaining first structural hunk is the pitch-store
//   schedule at +0131; the scaled/table tails still use equivalent lowering.
//   No exact result was found. Keep the natural source and do not add register
//   scaffolding, fake volatility, or a dummy context.

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>
#include "../../include/dib_context.h"

extern int __cdecl ClipDibBlt(BITMAPINFO256*, RECT*, LONG&, LONG&, LONG&, LONG&,
    LONG&, LONG&, LONG&, LONG&, int, int);
extern void __cdecl GetDibDim(BITMAPINFO256*, LONG&, LONG&, LONG&);
extern long SrcXTbl[];
#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

void __cdecl DibBlt(BITMAPINFO256* dest_info, BYTE* dest_bits, RECT* dest_rect,
    long dest_x, long dest_y, long dest_width, long dest_height,
    BITMAPINFO256* src_info, BYTE* src_bits,
    long src_x, long src_y, long src_width, long src_height,
    int do_clip, int flip_x, int flip_y)
{
    long dy, DestTotWid, DestTotHgt, DestOrien, SrcOrien;

    if (do_clip != 0) {
        if (!ClipDibBlt(dest_info, dest_rect, dest_x, dest_y,
                dest_width, dest_height, src_x, src_y, src_width, src_height,
                flip_x, flip_y))
            return;
    }
    GetDibDim(dest_info, DestTotWid, DestTotHgt, DestOrien);
    GetDibDim(src_info, dy, (long&)dest_rect, SrcOrien);

    if (flip_y != 0)
        SrcOrien = -SrcOrien;

    int x_step = (src_width << 8) / dest_width;
    int y_step = (src_height << 8) / dest_height;
    BYTE* dest;
    if (DestOrien == 1) {
        dest = dest_bits + DestTotWid * dest_y + dest_x;
    } else {
        dest = dest_bits + DestTotWid * (DestTotHgt - dest_y - 1) + dest_x;
    }

    if (x_step == 0x100 && y_step == 0x100 && flip_x == 0) {
        long src_row;
        if (SrcOrien == 1) {
            src_row = src_y * dy;
        } else {
            src_row = ((long)dest_rect - src_y - 1) * dy;
        }
        BYTE* src = src_bits + src_row + src_x;
        DestTotWid = DestOrien * DestTotWid;
        dy = SrcOrien * dy;
        int row = 0;
        if (dest_height < 1)
            return;
        do {
            memcpy(dest, src, dest_width);
            dest += DestTotWid;
            src += dy;
            ++row;
        } while (row < dest_height);
        return;
    }

    if (flip_x == 0) {
        if (dest_width > 0) {
            long* x_entry = SrcXTbl;
            long source_position = src_x;
            long remaining = dest_width;
            do {
                *x_entry++ = source_position >> 8;
                source_position += x_step;
                --remaining;
            } while (remaining != 0);
        }
    } else if (dest_width - 1 >= 0) {
        long* x_entry = SrcXTbl + dest_width - 1;
        long source_position = src_x;
        long remaining = dest_width;
        do {
            *x_entry-- = source_position >> 8;
            source_position += x_step;
            --remaining;
        } while (remaining != 0);
    }

    int source_y = src_y << 8;
    int output_row = 0;
    if (dest_height > 0) {
        do {
            int source_row = source_y >> 8;
            if (SrcOrien != 1)
                source_row = (long)dest_rect - 1 - source_row;

            if (dest_width > 0) {
                int i = 0;
                long* x_entry = SrcXTbl;
                do {
                    dest[i] = src_bits[(int)*x_entry +
                        source_row * dy + src_x];
                    ++i;
                    ++x_entry;
                } while (i < dest_width);
            }
            source_y += y_step;
            dest += DestOrien * DestTotWid;
            ++output_row;
        } while (output_row < dest_height);
    }
}
