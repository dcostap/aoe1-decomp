// 004BB280 TShape::shape_mirror_shadow_clipped
// Shape.cpp
// Attempt log:
// Previous workers reconstructed the RLE state machine with the wrong formal
// argument order and compiler-steering cursor forms. This pass starts again
// from the exact mirror and shadow siblings.
//
// fresh shape pass:
// - restored the period clipped-renderer ABI: shape origin, then four clip
//   bounds, with the shadow table last;
// - used the same signed-pitch destination and vertical skip structure as the
//   exact mirror siblings;
// - kept one shared byte count and ordinary inline shadow loops for each RLE
//   band. No raw offsets, fake volatility, or inline assembly remain.
// Probe notes:
// - Correcting the ABI and row ownership changed the 1073-byte first build
//   into a 998-byte candidate with the proven single AlignedWidth call.
// - Moving command/state to shared locals recovered the original 0x8 frame.
// - Advancing literal source spans before shadow branches reduced the body to
//   941 bytes and aligned the repeated shadow loops.
// - Reusing shape_y1 as the row counter was source-plausible but codegen
//   neutral. The typed SHADOW_BACK idiom then reached 928 bytes and 867
//   strict differing bytes, the retained codegen best.
// - A single byte overlay and split pitch assignment were rolled back. They
//   worsened shape or setup allocation. No behavior or call uncertainty
//   remains; the unresolved gap is the VC5 prologue/register and home basin.
// - Restored the donor-shaped positive guard and post-decrement shadow loop.
//   This reduced the build to 908 bytes and 858 strict differing bytes. The
//   current source remains a typed clipped shadow decoder; the open gap is
//   still structural block placement and local-home allocation.
// - Reading orientation first, splitting the width assignment, delaying the
//   shadow-table alias, and using signed state were codegen duplicates.
// - A byte shadow-loop counter reached 878 bytes/823 differing bytes, but it
//   added repeated counter homes and was rolled back as a codegen-only basin.
// - Moving literal source advances after the clipped branch enlarged the
//   frame to 0xC and 884 differing bytes; delaying source setup reached 853
//   differing bytes but lost shape and was also rolled back.

typedef unsigned char byte;

#define SHADOW_BACK(dst_, table_, count_) do { \
    if ((count_) > 0) { \
        unsigned int shadow_count_ = (unsigned int)(count_); \
        do { \
            --(dst_); \
            --shadow_count_; \
            *(dst_) = (table_)[*(dst_)]; \
        } while (shadow_count_ != 0); \
    } \
} while (0)

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
    byte* Bits;
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
    byte* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;

    byte shape_mirror_shadow_clipped(TDrawArea*, long, long, long, long,
                                     long, long, byte*);
};

byte TShape::shape_mirror_shadow_clipped(TDrawArea* draw_area,
                                         long shape_x1, long shape_y1,
                                         long clip_x0, long clip_y0,
                                         long clip_x1, long clip_y1,
                                         byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* save_buffer;
    byte* dst;
    byte count;
    byte state;

    if (draw_area->Orien < 1)
        save_buffer = draw_area->Bits
            + (clip_y0 - draw_area->Height + 1) * pitch + clip_x1 + 1;
    else
        save_buffer = draw_area->Bits + clip_y0 * pitch + clip_x1 + 1;

    if (shape_y1 < clip_y0) {
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    count = command >> 1;
                    if (count == 0)
                        ++src;
                    else
                        src += count;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (shape_y1 > clip_y1)
        return 1;

    dst = save_buffer;
    shape_y1 = clip_y1 - shape_y1 + 1;
    do {
        long xpos = shape_x1;
        if (clip_x1 < xpos) {
            state = 0;
            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    count = command >> 1;
                    if (count == 0) {
                        count = *src++;
                        xpos -= count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                state = 2;
                            } else {
                                dst += xpos - clip_x1;
                                state = 1;
                            }
                        }
                    } else {
                        xpos -= count;
                        src += count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                count = (byte)(clip_x1 - clip_x0 + 1);
                                state = 2;
                                SHADOW_BACK(dst, table,
                                            (byte)(clip_x1 - clip_x0 + 1));
                            } else {
                                count = (byte)(clip_x1 - xpos);
                                state = 1;
                                SHADOW_BACK(dst, table,
                                            (byte)(clip_x1 - xpos));
                            }
                        }
                    }
                } else {
                    count = command >> 1;
                    if (count == 0) {
                        state = 3;
                    } else {
                        xpos -= count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                count = (byte)(clip_x1 - clip_x0 + 1);
                                state = 2;
                            } else {
                                count = (byte)(clip_x1 - xpos);
                                state = 1;
                            }
                            SHADOW_BACK(dst, table, count);
                        }
                        ++src;
                    }
                }
            } while (state == 0);
        } else {
            state = 1;
        }

        state--;
        while (state == 0) {
            byte command = *src++;
            if ((command & 1) == 1) {
                count = command >> 1;
                if (count == 0) {
                    count = *src++;
                    xpos -= count;
                    dst -= count;
                    if (xpos < clip_x0)
                        state = 1;
                } else {
                    xpos -= count;
                    src += count;
                    if (xpos < clip_x0) {
                        count = (byte)(xpos - clip_x0 + count);
                        state = 1;
                        SHADOW_BACK(dst, table, count);
                    } else {
                        SHADOW_BACK(dst, table, count);
                    }
                }
            } else {
                count = command >> 1;
                if (count == 0) {
                    state = 3;
                } else {
                    xpos -= count;
                    if (xpos < clip_x0) {
                        count = (byte)(xpos - clip_x0 + count);
                        state = 1;
                    }
                    SHADOW_BACK(dst, table, count);
                    ++src;
                }
            }
        }

        state--;
        while (state == 0) {
            byte command = *src++;
            if ((command & 1) == 1) {
                count = command >> 1;
                if (count != 0)
                    src += count;
                else
                    ++src;
            } else {
                if ((command & 0xfe) == 0)
                    state = 2;
                else
                    ++src;
            }
        }

        save_buffer += pitch;
        dst = save_buffer;
    } while (--shape_y1 != 0);

    return 1;
}
