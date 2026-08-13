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
//   and binary-proven long aliases; it remains in scratch rather than forcing
//   opaque codegen scaffolding.
// - A parameter-home alias reached the original frame size. It is diagnostic
//   evidence only. The living source keeps the named vertical step.

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

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
    long dest_direction;
    long dest_bitmap_height;
    long dest_stride;
    long src_direction;
    long src_bitmap_height;
    long src_stride;

    if (do_clip != 0) {
        if (!ClipDibBlt(dest_info, dest_rect, dest_x, dest_y,
                dest_width, dest_height, src_x, src_y, src_width, src_height,
                flip_x, flip_y))
            return;
    }
    GetDibDim(dest_info, dest_stride, dest_bitmap_height, dest_direction);
    GetDibDim(src_info, src_stride, src_bitmap_height, src_direction);

    if (flip_y != 0)
        src_direction = -src_direction;

    int x_step = (src_width << 8) / dest_width;
    int y_step = (src_height << 8) / dest_height;
    int dest_row = dest_y;
    if (dest_direction != 1)
        dest_row = (dest_bitmap_height - dest_y) - 1;
    BYTE* dest = dest_bits + dest_stride * dest_row + dest_x;

    if (x_step == 0x100 && y_step == 0x100 && flip_x == 0) {
        int src_row = src_y;
        if (src_direction != 1)
            src_row = src_bitmap_height - 1 - src_y;
        src_row = src_stride * src_row;
        dest_stride = dest_direction * dest_stride;
        src_stride = src_direction * src_stride;
        BYTE* src = src_bits + src_row + src_x;
        int row = 0;
        if (dest_height < 1)
            return;
        do {
            memcpy(dest, src, dest_width);
            dest += dest_stride;
            src += src_stride;
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
            if (src_direction != 1)
                source_row = src_bitmap_height - 1 - source_row;

            if (dest_width > 0) {
                long* x_entry = SrcXTbl;
                int i = 0;
                do {
                    dest[i] = src_bits[(int)*x_entry +
                        source_row * src_stride + src_x];
                    ++i;
                    ++x_entry;
                } while (i < dest_width);
            }
            source_y += y_step;
            dest += dest_direction * dest_stride;
            ++output_row;
        } while (output_row < dest_height);
    }
}
