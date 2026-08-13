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
// shardE-4B9AF0 pass: moving the shared right-band cursor increments after
// both memcpy arms worsened to 787 bytes and duplicated the prior basin.
// A separate row source cursor was codegen-identical and was rolled back.
// Explicit `(code & 1) == 1` tests improved shape but grew the function by
// 28 bytes; the binary-compatible CRT memcpy prototype was also required.
// A harmless `count + 0` spelling was codegen-identical. Restored clean.

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
                            if (clip_left <= xpos) {
                                if (clip_right < xpos)
                                    clip_top = 2;
                                else {
                                    clip_top = 1;
                                    dst += xpos - clip_left;
                                }
                            }
                        } else {
                            xpos += count;
                            if (clip_left <= xpos) {
                                long copy_count;
                                uchar* copy_source;
                                if (clip_right < xpos) {
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
                            if (clip_left <= xpos) {
                                long fill_count;
                                if (clip_right < xpos) {
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
                        if (clip_right < xpos)
                            clip_top = 1;
                    } else {
                        xpos += count;
                        if (clip_right < xpos) {
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
                        if (clip_right < xpos) {
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
