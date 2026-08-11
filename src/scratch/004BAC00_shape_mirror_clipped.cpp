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
// left in scratch: major behavior surface is reconstructed but code is too compact and not diffable/exact; not accepted_drift-safe.

#include <string.h>
#pragma function(memset)

typedef unsigned char uchar;
extern "C" void* __cdecl memset(void*, int, unsigned int);

class TDrawArea { public: char pad0[8]; uchar* Bits; char padC[0x10]; long Height; char pad20[4]; long Orien; long AlignedWidth(); };
class TShape { public: void* shape; int load_type; int load_size; uchar* shape_header; unsigned char shape_mirror_clipped(TDrawArea*,long,long,long,long,long,long); };

unsigned char TShape::shape_mirror_clipped(TDrawArea* area,long clip_right,long clip_top,long clip_left,long y,long x,long clip_bottom)
{
    long pitch = area->AlignedWidth() * area->Orien;
    uchar* src = this->shape_header + 0x18;
    uchar* save_buffer;
    if (area->Orien < 1)
        save_buffer = area->Bits + (y - area->Height + 1) * pitch + x + 1;
    else
        save_buffer = area->Bits + y * pitch + x + 1;

    long row = clip_top;
    if (row < y) {
        long skip = y - row;
        row += skip;
        while (skip--) {
            uchar done = 0;
            while (!done) {
                uchar code = *src++;
                if (code & 1) {
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
        }
    }

    if (row <= clip_bottom) {
        long rows = clip_bottom - row + 1;
        while (rows--) {
            long xpos = clip_right;
            uchar state;

            if (xpos <= x) {
                state = 1;
            } else {
                state = 0;
                while (state == 0) {
                    uchar code = *src++;
                    if (code & 1) {
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
                                    long copy_count = x - clip_left + 1;
                                    long source_offset = xpos - x + count;
                                    state = 2;
                                    src += source_offset - 1;
                                    while (copy_count--)
                                        *--save_buffer = *src++;
                                    src += clip_left - xpos;
                                } else {
                                    long copy_count = x - xpos;
                                    state = 1;
                                    src += count - copy_count;
                                    while (copy_count--)
                                        *--save_buffer = *src++;
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
                        if (code & 1) {
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
                                    long visible = xpos - clip_left + count;
                                    state = 1;
                                    if (visible > 0) {
                                        while (visible--)
                                            *--save_buffer = *src++;
                                    }
                                    src += count - (xpos - clip_left + count);
                                } else {
                                    while (count--)
                                        *--save_buffer = *src++;
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
                            if (code & 1) {
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
        }
    }
    return 1;
}
