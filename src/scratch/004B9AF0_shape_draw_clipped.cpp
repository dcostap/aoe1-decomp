// 004B9AF0 TShape::shape_draw_clipped
// Attempt log:
// try 1: reconstructed non-mirrored clipped RLE draw from asm, analogous to shape_mirror_clipped but forward destination/copies.
// try 2: modeled TDrawArea fields Bits +8, Height +0x1c, Orien +0x24 and AlignedWidth call; call surface compiles.
// try 3: modeled source start as shape_header +0x18 from asm `mov edi,[this+0xc]; add edi,18h`.
// try 4: modeled destination pointer for positive/negative orientation using x/y and height adjustment; source still allocates too many locals.
// try 5: implemented top-row RLE skip loop with odd literal runs, even fill/end packets, and zero-length extended literal.
// try 6: modeled vertical clip count rewrite `rows = max_y - cur_y + 1` and early `cur_y > max_y` return.
// try 7: implemented left-clipped pre-band using state byte 0/1/2/3 and memcpy/memset calls matching original helper families.
// try 8: implemented middle visible band with literal memcpy and fill memset, including right-edge truncation.
// try 9: implemented right-side skip band after state transition, preserving packet consumption until end-of-line.
// try 10: /GX probe had no effect; removed. Current source reaches exact configured size 813B but prologue/frame/local topology is wrong (0x1c frame vs original 0x08), with broad mismatch from offset 2.
// try 11: restored the Shape.cpp CRT intrinsic context with <string.h> and
// #pragma function(memcpy)/#pragma function(memset), so the binary-proven
// memcpy/memset call sites remain out-of-line instead of being inlined.
// try 12: corrected the period call-site ownership to shape_x/shape_y followed
// by clip_left/clip_top/clip_right/clip_bottom; the destination and three
// clipping bands now use the proven argument roles instead of shifted names.
// try 13: rewrote the loop state to mutate the proven incoming parameter homes
// (clip_top and clip_bottom) and carried the persistent row destination through
// save_buffer, matching the period source/decompiler ownership rather than
// separate skip/row/state locals.
// try 14: shared one byte command/count local across all RLE bands, mirroring
// the donor's repeated parameter-home byte reloads instead of block-scoped
// count declarations.
// final bounded pass: shared byte state recovered the original 8-byte frame,
// exact effective size, and all conditional CFG signals. Ten hypotheses are
// exhausted; the remaining gap is one merged right-band memcpy call plus the
// broad VC5 register/prologue basin. The goto label was a codegen duplicate
// and was removed from the retained natural source.
// left in scratch: behavior and call surface are plausible, but the VC5 frame
// and register topology still need validation against the 8-byte oracle.
//
// sa-e83dab42 claim pass (2026-08-22):
// - Reversed only the inner horizontal bound comparisons to match the
//   original `cmp xpos,left` and `cmp xpos,right` directions. This kept the
//   813-byte body, 0x8 frame, and 5/6 ordered calls, while improving shape
//   from 64.77% to 68.12% and exact-block coverage from 17.45% to 27.85%.
// - Explicit odd-packet comparisons improved shape to 73.83% and exact
//   blocks to 38.59%, but added 28 bytes and reduced strict alignment. The
//   natural truth tests remain retained.
// - Direct save_buffer cursor ownership aligned all six calls but removed
//   the original frame and worsened strict bytes. The separate row cursor
//   remains retained.
// - Header aliases, area aliases, register qualifiers, declaration order,
//   split width arithmetic, same-line call records, and in-place command
//   mutation were duplicate or worse codegen basins.
// shardE-4B9AF0 pass: moving the shared right-band cursor increments after
// both memcpy arms worsened to 787 bytes and duplicated the prior basin.
// A separate row source cursor was codegen-identical and was rolled back.
// Explicit `(code & 1) == 1` tests improved shape but grew the function by
// 28 bytes; the binary-compatible CRT memcpy prototype was also required.
// A harmless `count + 0` spelling was codegen-identical. Restored clean.
//
// sa-ac5b3de6 claim pass (2026-08-17; 20 meaningful probes plus one 64-case
// ambient-declaration family):
// - Split the middle literal memcpy into two source arms. Factoring the
//   cursor updates still emitted one call; duplicating those updates restored
//   the 813-byte/741-diff clean basin, but the call count stayed 2/3.
// - A widened copy-length local, orientation/width declaration splits, header
//   aliases, local declaration reorders, reversed bound spelling, and a
//   function-scope packet byte were duplicate or worse basins.
// - One explicit top parity comparison grew the function by 10 bytes. Four
//   explicit parity comparisons grew it by 28 bytes. The natural truth tests
//   remain pinned despite better shape in those diagnostic variants.
// - A 64-case ambient declaration lab produced one 813-byte group with no
//   movement. It did not alter the unresolved allocator basin.
// - Using save_buffer as the working destination aligned all six calls, but
//   removed the original frame and fell to 776 strict bytes. The separate
//   typed row destination remains the cleaner 813-byte reconstruction.
// - Windows.h, memory.h, operand-order, command declaration, early destination
//   declaration, and direct left-band source-expression probes were duplicate
//   or worse. The direct left-band form reached six calls but was 818 bytes
//   and 787 strict bytes.
// - Final validation after restore: 813-byte rebuilt body, 0x8 frame, 33/33
//   conditional signals, 5/6 ordered calls, 741 strict differing bytes.
//   The remaining blocker is the Shape.cpp VC5 register/local basin and one
//   merged middle-band memcpy call. No inline assembly or compiler steering
//   was retained.

#include <string.h>
#pragma function(memcpy)
#pragma function(memset)

extern "C" void* __cdecl memcpy(void* dest, const void* src, unsigned int count);
extern "C" void* __cdecl memset(void* dest, int c, unsigned int count);

typedef unsigned char uchar;

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

class TDrawArea {
public:
    char gap_00[8];
    uchar* Bits;
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

class TShape {
public:
    uchar* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;

    uchar shape_draw_clipped(TDrawArea*, long, long, long, long, long, long);
};

uchar TShape::shape_draw_clipped(TDrawArea* area, long shape_x, long shape_y,
                                  long clip_left, long clip_top,
                                  long clip_right, long clip_bottom)
{
    long pitch = area->AlignedWidth() * area->Orien;
    uchar* src = (uchar*)(this->shape_header + 1);
    uchar* save_buffer;
    uchar count;


    if (area->Orien < 1)
        save_buffer = area->Bits + (clip_top - area->Height + 1) * pitch;
    else
        save_buffer = area->Bits + clip_top * pitch;
    save_buffer += clip_left;

    if (shape_y < clip_top) {
        clip_top = clip_top - shape_y;
        shape_y = shape_y + clip_top;
        do {
            uchar done = 0;
            do {
                uchar code = *src++;
                if (code & 1) {
                    count = code >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    if ((code & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
            --clip_top;
        } while (clip_top != 0);
    }

    if (shape_y <= clip_bottom) {
        clip_bottom = clip_bottom - shape_y + 1;
        do {
            long xpos = shape_x;
            uchar* dst = save_buffer;

            if (shape_x < clip_left) {
                clip_top = 0;
                do {
                    uchar code = *src++;
                    if (code & 1) {
                        count = code >> 1;
                        if (count == 0) {
                            xpos += *src++;
                            if (xpos >= clip_left) {
                                if (xpos > clip_right)
                                    clip_top = 2;
                                else {
                                    clip_top = 1;
                                    dst += xpos - clip_left;
                                }
                            }
                        } else {
                            xpos += count;
                            if (xpos >= clip_left) {
                                long copy_count;
                                uchar* copy_source;
                                if (xpos > clip_right) {
                                    clip_top = 2;
                                    copy_count = clip_right - clip_left + 1;
                                    copy_source = src + count + clip_left - xpos;
                                } else {
                                    clip_top = 1;
                                    copy_count = xpos - clip_left;
                                    copy_source = src + count - copy_count;
                                }
                                memcpy(dst, copy_source, copy_count);
                                dst += copy_count;
                            }
                            src += count;
                        }
                    } else {
                        count = code >> 1;
                        if (count == 0) {
                            clip_top = 3;
                        } else {
                            xpos += count;
                            if (xpos >= clip_left) {
                                long fill_count;
                                if (xpos > clip_right) {
                                    clip_top = 2;
                                    fill_count = clip_right - clip_left + 1;
                                } else {
                                    clip_top = 1;
                                    fill_count = xpos - clip_left;
                                }
                                memset(dst, *src, fill_count);
                                dst += fill_count;
                            }
                            ++src;
                        }
                    }
                } while ((uchar)clip_top == 0);
            } else {
                clip_top = 1;
            }

            clip_top = (uchar)clip_top - 1;
            while ((uchar)clip_top == 0) {
                uchar code = *src++;
                if (code & 1) {
                    count = code >> 1;
                    if (count == 0) {
                        count = *src++;
                        xpos += count;
                        dst += count;
                        if (xpos > clip_right)
                            clip_top = 1;
                    } else {
                        xpos += count;
                        if (xpos > clip_right) {
                            clip_top = 1;
                            memcpy(dst, src, clip_right - xpos + 1 + count);
                            dst += count;
                            src += count;
                        } else {
                            memcpy(dst, src, count);
                            dst += count;
                            src += count;
                        }
                    }
                } else {
                    count = code >> 1;
                    if (count == 0) {
                        clip_top = 3;
                    } else {
                        long fill_count = count;
                        xpos += count;
                        if (xpos > clip_right) {
                            fill_count = count + clip_right - xpos + 1;
                            clip_top = 1;
                        }
                        memset(dst, *src, fill_count);
                        dst += count;
                        ++src;
                    }
                }
            }

            clip_top = (uchar)clip_top - 1;
            while ((uchar)clip_top == 0) {
                uchar code = *src++;
                if (code & 1) {
                    count = code >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    if ((code & 0xfe) == 0)
                        clip_top = 2;
                    else
                        ++src;
                }
            }

            save_buffer += pitch;
            --clip_bottom;
        } while (clip_bottom != 0);
    }

    return 1;
}
