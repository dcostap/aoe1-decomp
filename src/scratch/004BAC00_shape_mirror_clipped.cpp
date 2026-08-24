// 004BAC00 TShape::shape_mirror_clipped
// Attempt log:
// try 1: reconstructed mirrored clipped RLE draw from original asm: compute mirrored dest pointer, skip top rows, process left/right clipping bands and middle rows.
// try 2: modeled TDrawArea fields Bits +8, Height +0x1c, Orien +0x24 and AlignedWidth call; prologue/call surface compile.
// try 3: modeled source start as shape_header +0x18 from asm load of this+0xc then add 0x18.
// try 4: modeled mirrored destination pointer for positive/negative orientation using x+1 and y/height adjustment.
// try 5: implemented top-row RLE skip loop with odd literal runs, even fill/end packets, and zero-length extended literal.
// try 6: implemented vertical clipping count max_y-row+1 and early max_y rejection.
// try 7: implemented left/right horizontal clipping states 1/2/3 corresponding to original bl state transitions.
// try 8: used memcpy-like byte loops for mirrored literal copies (*--save_buffer = *src++), matching behavioral direction.
// try 9: used memset for fill packets to match original memset calls at 0x54DA60.
// try 10: /GX probe had no effect; removed. Current reconstruction compiles 640B vs original 799B, meaning several source branches/loops are still over-factored or behavior missing.
// try 11: corrected the member ABI to put TDrawArea* first, followed by the
// six stack arguments proven by the callee's homes; retained the same decoder
// body for an isolated ABI probe.
// try 12: restored the full natural clipped mirror state machine: clip-right /
// clip-top / clip-left / y / x / clip-bottom ownership, visible literal and
// fill runs, and the post-visible end-of-line drain.
// try 13: restored the binary-proven partial literal copies in the initial
// horizontal clip band; runs crossing the visible window copy their in-range
// bytes before entering the middle or end-of-line state.
// try 14: a do/while top-row skip was structurally closer in isolation but
// shifted the best positional basin from 690 to 696 strict bytes; restored.
// try 15: mutating one command byte in the Shape.cpp sibling idiom reached the
// original size and better edit islands, but removed the required frame and
// worsened positional bytes to 770; restored the 690-byte best candidate.
// try 16: tested a direct typed Shape_Header reconstruction with do/while top-
// row and visible-row loops. It emitted 736B/766 strict bytes versus the
// pinned 764B/690 candidate, so it was rolled back.
// try 17: confirmed the pinned typed reconstruction as this claim's baseline;
// it remains 764B/690 strict bytes with all three calls aligned.
// try 18: reordered the setup locals; output worsened to 762B/763 and was
// restored.
// try 19: shared the command byte only across visible and drain states; this
// removed the frame but worsened output to 760B/764 and was restored.
// try 20: added a separate per-row destination cursor; size and edit islands
// improved, but strict output worsened to 781B/712, so it was restored.
// try 21: hoisted that cursor declaration; codegen was unchanged.
// try 22: changed the visible-row loop to do/while from binary topology;
// output worsened to 751B/696 and was restored.
// try 23: inlined the proven clipped-literal source offset expression; VC5
// emitted the same 764B/690 code. The simpler expression is retained.
// try 24: inverted the initial horizontal guard to `xpos > x`, matching the
// original jge skip over the pre-band decoder; this reached 763B/686.
// try 25: translated the Ghidra-proven partial literal loops to explicit
// unsigned-byte guards and do/while decrements; this reached 763B/684.
// try 26: fixed the middle literal branch for xpos >= clip_left to copy only
// x-xpos bytes from the count-copy_count source offset. This improved raw
// resynchronization and restores the binary-proven clipped behavior.
// try 27: changed the top-row skip to a do/while loop after the behavior fix;
// this reached 764B/669 and 71.02% instruction shape.
// try 28: restored full donor-supported TDrawArea/TShape/Shape_Header surfaces;
// codegen stayed at 764B/669, so typed ownership is retained.
// Final bounded pass: 764B rebuilt versus 799B original, 669 strict bytes,
// 71.02% shape, three ordered calls aligned, and a 0xC versus 0x8 frame.
// The remaining gap is the original local-home/parameter allocation basin and
// related state layout; this source is not exact or accepted_drift-safe.
//
// sa-70d977cd-r1 claim probes (2026-08-22):
// - Directly mutating the top-row parameter worsened the basin to 698 bytes.
// - The Ghidra-shaped sequential state decrements improved strict bytes to
//   665, but reduced shape and increased the size gap; it was not retained.
// - Explicit `((code & 1) == 1)` parity tests in all four RLE phases reached
//   the original 799-byte size and 76.34% shape, but 693 strict bytes.
// - Combining those explicit tests with the guarded visible-row do/while
//   reached 799 bytes, 74.69% shape, and 669 strict bytes. This is retained
//   because it follows the original parity and loop topology.
// - A separate row-start pointer, function-scope count, and state signedness
//   probes did not improve strict output. The row pointer worsened frame and
//   shape; the function-scope count removed the frame but reached 764 bytes.
// - The retained source still has a 0xC versus 0x8 frame. All three calls are
//   ordered and aligned. No accepted-drift claim is supported.

#include <string.h>
#pragma function(memset)

#ifndef AOE1_SHAPE_CONTEXT_H
typedef unsigned char uchar;
extern "C" void* __cdecl memset(void*, int, unsigned int);

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
    char tail_38[0xC8];
    long AlignedWidth();
};

class TShape {
public:
    uchar* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    void* head;
    void* offsets;
    void* FShape;
    void* shape_info;
    unsigned char shape_mirror_clipped(TDrawArea*,long,long,long,long,long,long);
};
#endif

unsigned char TShape::shape_mirror_clipped(TDrawArea* area,long clip_right,long clip_top,long clip_left,long y,long x,long clip_bottom)
{
    long pitch = area->AlignedWidth() * area->Orien;
    uchar* src = (uchar*)(this->shape_header + 1);
    uchar* save_buffer;
    if (area->Orien < 1)
        save_buffer = area->Bits + (y - area->Height + 1) * pitch + x + 1;
    else
        save_buffer = area->Bits + y * pitch + x + 1;

    long row = clip_top;
    if (row < y) {
        long skip = y - row;
        row += skip;
        do {
            uchar done = 0;
            while (!done) {
                uchar code = *src++;
                if ((code & 1) == 1) {
                    uchar count = code >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    uchar count = code >> 1;
                    if (count == 0)
                        done = 1;
                    else
                        ++src;
                }
            }
        } while (--skip != 0);
    }

    if (row <= clip_bottom) {
        long rows = clip_bottom - row + 1;
        do {
            long xpos = clip_right;
            uchar state;

            state = 1;
            if (xpos > x) {
                state = 0;
                while (state == 0) {
                    uchar code = *src++;
                    if ((code & 1) == 1) {
                        uchar count = code >> 1;
                        if (count == 0) {
                            count = *src++;
                            xpos -= count;
                            if (xpos <= x) {
                                if (xpos < clip_left) {
                                    state = 2;
                                } else {
                                    state = 1;
                                    save_buffer += xpos - x;
                                }
                            }
                        } else {
                            xpos -= count;
                            if (xpos <= x) {
                                if (xpos < clip_left) {
                                    unsigned int copy_count = x - clip_left + 1;
                                    state = 2;
                                    src += xpos - x + count - 1;
                                    if ((unsigned char)copy_count > 0) {
                                        copy_count &= 0xff;
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--copy_count != 0);
                                    }
                                    src += clip_left - xpos;
                                } else {
                                    unsigned int copy_count = x;
                                    copy_count -= xpos;
                                    state = 1;
                                    src += count - copy_count;
                                    if ((unsigned char)copy_count > 0) {
                                        copy_count &= 0xff;
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--copy_count != 0);
                                    }
                                }
                            } else {
                                src += count;
                            }
                        }
                    } else {
                        uchar count = code >> 1;
                        if (count == 0) {
                            state = 3;
                        } else {
                            xpos -= count;
                            if (xpos <= x) {
                                if (xpos < clip_left) {
                                    long visible = x - clip_left + 1;
                                    state = 2;
                                    save_buffer -= visible;
                                    memset(save_buffer, *src, visible);
                                } else {
                                    long visible = x - xpos;
                                    state = 1;
                                    save_buffer -= visible;
                                    memset(save_buffer, *src, visible);
                                }
                            }
                            ++src;
                        }
                    }
                }
            }

            if (state != 0) {
                --state;
                if (state == 0) {
                    while (state == 0) {
                        uchar code = *src++;
                        if ((code & 1) == 1) {
                            uchar count = code >> 1;
                            if (count == 0) {
                                count = *src++;
                                xpos -= count;
                                save_buffer -= count;
                                if (xpos < clip_left)
                                    state = 1;
                            } else {
                                xpos -= count;
                                if (xpos < clip_left) {
                                    unsigned int visible = xpos;
                                    visible -= clip_left;
                                    visible += count;
                                    state = 1;
                                    if ((unsigned char)visible > 0) {
                                        visible &= 0xff;
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--visible != 0);
                                    }
                                    src += count - (xpos - clip_left + count);
                                } else {
                                    unsigned int copy_count = x - xpos;
                                    state = 1;
                                    src += count - copy_count;
                                    if ((unsigned char)copy_count > 0) {
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--copy_count != 0);
                                    }
                                }
                            }
                        } else {
                            uchar count = code >> 1;
                            if (count == 0) {
                                state = 3;
                            } else {
                                xpos -= count;
                                if (xpos < clip_left) {
                                    long visible = xpos - clip_left + count;
                                    state = 1;
                                    save_buffer -= visible;
                                    memset(save_buffer, *src, visible);
                                } else {
                                    save_buffer -= count;
                                    memset(save_buffer, *src, count);
                                }
                                ++src;
                            }
                        }
                    }
                } else {
                    --state;
                    if (state == 0) {
                        while (state == 0) {
                            uchar code = *src++;
                            if ((code & 1) == 1) {
                                uchar count = code >> 1;
                                if (count)
                                    src += count;
                                else
                                    ++src;
                            } else {
                                uchar count = code >> 1;
                                if (count == 0)
                                    state = 2;
                                else
                                    ++src;
                            }
                        }
                    }
                }
            }

            save_buffer += pitch;
        } while (--rows);
    }
    return 1;
}
