// VA: 004BB910 TShape::shape_dithered_clipped
// Shape.cpp lines 2902-3243
// Attempt log:
// try 1: adapted shape_dithered_unclipped skeleton with clipping bounds and packet-observed RLE/dither phases; default /O2 too small (.text 656 vs 1321), because helper stayed out-of-line/logic under-modeled.
// try 2: macro-expanded ZERO_DITHER; default /O2 still too small (.text 624), worse due optimization.
// try 3: /Od reached only .text 1179 vs 1321, still too small; rolled back.
// try 4: /O1 much too small (.text 498), rolled back.
// try 5: no /Oy (/O2 only) unchanged at .text 624, rolled back.
// try 6: restored the binary-supported clipped origin (clip_left/clip_top),
//   corrected the pre-row RLE skip semantics, and expanded the three natural
//   left/middle/tail raster phases instead of hiding them in ZERO_DITHER.
// try 7: coalesced command/count/state updates onto the observed byte/formal
//   parameter homes; frame fell from 0x3c to 0x0c and output stabilized at
//   1387 bytes (original 1321), with all RLE phase blocks and AlignedWidth
//   call present.  A natural left-phase loop without the observed shared exit
//   was worse, so the shared exit is retained.
// try 8: replaced the synthetic save_y local with direct orientation-specific
//   destination arms, following the exact Shape.cpp sibling topology.  This
//   improved the structural basin to 1398 bytes, 1314 differing bytes, and
//   59.66% shape; it remains a natural source-model lead, not codegen tuning.
// try 9: used the exact Shape donor's direct member expression for orientation
//   and width, removing the synthetic orientation local; this tests the first
//   setup hunk without changing the typed clipped RLE phases.
// try 10: modeled the persistent dither state as the binary-supported bool
//   shown by the decompiler; VC5 emitted the unchanged 1398-byte candidate,
//   so the width hypothesis was rolled back.
// try 11: mutated the packed RLE command byte before assigning its count;
//   original uses narrow SHR and byte parameter-home stores in every phase,
//   so this tests the source shape without changing typed ownership.
// left in scratch: canonical typed RLE/dither behavior is reconstructed, but
//   VC5 still chooses a different early register/local-home basin (first
//   mismatch is the prologue; 1344 strict bytes differ, 56.24% resync).

typedef unsigned char uchar;
struct Shape_Header { long bounds; long origin; long xmin; long ymin; long xmax; long ymax; };
class TDrawArea { public: char gap_00[8]; uchar* Bits; char gap_0C[0x10]; long Height; char gap_20[4]; long Orien; long AlignedWidth(); };
class TShape { public: uchar* shape; int load_type; int load_size; Shape_Header* shape_header; uchar shape_dithered_clipped(TDrawArea* area, long x, long y, long clip_left, long clip_top, long clip_right, long clip_bottom, long p8, long p9); };

uchar TShape::shape_dithered_clipped(TDrawArea* area, long x, long y, long clip_left, long clip_top, long clip_right, long clip_bottom, long p8, long p9)
{
    long width = area->AlignedWidth() * area->Orien;
    Shape_Header* header = this->shape_header;
    uchar* src = (uchar*)(header + 1);
    long skip_rows;
    uchar* save_buffer;
    if (area->Orien < 1)
        save_buffer = area->Bits + clip_left + (clip_top - area->Height + 1) * width;
    else
        save_buffer = area->Bits + clip_left + clip_top * width;
    uchar dither;
    uchar b;
    uchar* end;
    dither = (uchar)((p8 + (char)clip_left) & 1);
    if (((p9 + clip_top) & 1U) != 0)
        dither = (uchar)(dither != 1);

    long row = y;
    if (y < clip_top) {
        skip_rows = clip_top - y;
        row = y + skip_rows;
        do {
            uchar end_line = 0;
            do {
                b = *src++;
                if ((b & 1) == 1) {
                    y = (long)(b >> 1);
                    if (y == 0)
                        ++src;
                    else
                        src += (unsigned int)y;
                } else {
                    y = (long)(b >> 1);
                    if (y == 0)
                        end_line = 1;
                    else
                        ++src;
                }
            } while (end_line == 0);
            --skip_rows;
        } while (skip_rows != 0);
    }

    do {
        if (clip_bottom < row)
            return 1;

        bool row_dither = (dither != 1);
        uchar* dst = save_buffer;
        p9 = x;

        if (x < clip_left) {
            clip_top = 0;
            do {
                b = *src++;
                if ((b & 1) == 1) {
                    y = (long)(b >> 1);
                    if (y == 0) {
                        p9 += (unsigned int)*src;
                        src += 2;
                        if (clip_left <= p9) {
                            if (clip_right < p9) {
                                clip_top = 2;
                            } else {
                                clip_top = 1;
                                b = (uchar)((char)p9 - (char)clip_left);
                                p8 = (long)b;
                                dst += b;
                                if ((b & 1) != 0)
                                    dither = (uchar)(dither != 1);
                            }
                        }
                    } else {
                        p9 += y;
                        if (clip_left < p9) {
                            if (clip_right < p9) {
                                clip_top = 2;
                                b = (uchar)((char)clip_right - (char)clip_left + 1);
                                if (dither != 0) {
                                    ++dst;
                                    b = (uchar)((char)clip_right - (char)clip_left);
                                }
                                p8 = (long)b;
                                dither = (uchar)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                                src += (unsigned int)y;
                                goto left_done;
                            } else {
                                clip_top = 1;
                                b = (uchar)((char)p9 - (char)clip_left);
                                if (dither != 0) {
                                    --b;
                                    ++dst;
                                }
                                p8 = (long)b;
                                dither = (uchar)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                            }
                        }
                        src += (unsigned int)y;
                    }
                } else {
                    y = (long)(b >> 1);
                    if (y == 0) {
                        clip_top = 3;
                    } else {
                        p9 += y;
                        if (clip_left < p9) {
                            if (clip_right < p9) {
                                clip_top = 2;
                                b = (uchar)((char)clip_right - (char)clip_left + 1);
                                if (dither != 0) {
                                    ++dst;
                                    b = (uchar)((char)clip_right - (char)clip_left);
                                }
                                p8 = (long)b;
                                dither = (uchar)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                            } else {
                                clip_top = 1;
                                b = (uchar)((char)p9 - (char)clip_left);
                                if (dither != 0) {
                                    --b;
                                    ++dst;
                                }
                                p8 = (long)b;
                                dither = (uchar)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                            }
                        }
                        ++src;
                    }
                }
            left_done:
                if (clip_top != 0)
                    break;
            } while (true);
        }

        if (x >= clip_left)
            clip_top = 1;
        clip_top = (uchar)clip_top - 1;
        while (clip_top == 0) {
            b = *src++;
            if ((b & 1) == 1) {
                y = (long)(b >> 1);
                if (y == 0) {
                    b = *src;
                    p9 += (unsigned int)b;
                    if ((b & 1) != 0)
                        dither = (uchar)(dither != 1);
                    dst += b;
                    src += 2;
                    if (clip_right < p9)
                        clip_top = 1;
                } else {
                    p9 += y;
                    if (clip_right < p9) {
                        clip_top = 1;
                        b = (uchar)((char)clip_right - (char)p9 + 1 + y);
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        p8 = (long)b;
                        dither = (uchar)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    } else {
                        b = (uchar)y;
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        p8 = (long)b;
                        dither = (uchar)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    }
                    src += (unsigned int)y;
                }
            } else {
                y = (long)(b >> 1);
                if (y == 0) {
                    clip_top = 3;
                } else {
                    p9 += y;
                    if (clip_right < p9) {
                        clip_top = 1;
                        b = (uchar)((char)clip_right - (char)p9 + 1 + y);
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        p8 = (long)b;
                        dither = (uchar)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    } else {
                        b = (uchar)y;
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        p8 = (long)b;
                        dither = (uchar)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    }
                    ++src;
                }
            }
        }

        clip_top = (uchar)(clip_top - 1);
        while (clip_top == 0) {
            b = *src++;
            if ((b & 1) == 1) {
                y = (long)(b >> 1);
                if (y == 0)
                    ++src;
                else
                    src += (unsigned int)y;
            } else {
                y = (long)(b >> 1);
                if (y == 0)
                    clip_top = 2;
                else
                    ++src;
            }
        }

        save_buffer += width;
        ++row;
        dither = row_dither;
    } while (true);

    return 1;
}
