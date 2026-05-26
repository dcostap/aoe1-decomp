// 004BA1C0 TShape::shape_shadow_clipped
// Attempt log:
// 1: direct Ghidra-structured clipped shadow decoder with TDrawArea/TShape offsets; helper-call baseline compiled to 864 bytes, too short.
// 2: macro-inlined copy loops reached exact 906-byte size but 90.07% positional / 66.23% edit diff; first mismatch is frame size sub esp,10 vs original sub esp,8.
// 3: root issue appears source topology/local allocation: original reuses incoming stack homes for stream pointer/count byte and keeps only two explicit locals, while this clean source keeps extra locals and holds stream pointer in EBP.
// left in scratch: behavior model is close to Ghidra but not an exact/accepted-drift candidate; needs a parameter-home-reuse rewrite mirroring original stack slots.

typedef unsigned char byte;

struct TDrawArea {
    char gap_00[8];
    byte* Bits;
    char gap_0C[0x10];
    int Height;
    char gap_20[4];
    int Orien;
    int AlignedWidth();
};

struct TShapeHeader {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

class TShape {
public:
    byte* shape;
    int load_type;
    int load_size;
    TShapeHeader* shape_header;

    byte shape_shadow_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1,
                              long clip_x0, long clip_y0, long clip_x1, long clip_y1,
                              byte* table);
};

#define SHADOW_COPY(dst_, end_, table_) \
    while ((dst_) < (end_)) { \
        *(dst_) = (table_)[*(dst_)]; \
        ++(dst_); \
    }

byte TShape::shape_shadow_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1,
                                  long clip_x0, long clip_y0, long clip_x1, long clip_y1,
                                  byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* p = (byte*)(this->shape_header + 1);
    long y = shape_y1;
    long x = shape_x1;

    byte* dst;
    if (draw_area->Orien < 1) {
        dst = draw_area->Bits + (clip_y0 - draw_area->Height + 1) * pitch + clip_x0;
    } else {
        dst = draw_area->Bits + clip_y0 * pitch + clip_x0;
    }

    if (y < clip_y0) {
        long skip_rows = clip_y0 - y;
        y += skip_rows;
        do {
            byte done = 0;
            do {
                byte cmd = *p++;
                if ((cmd & 1) == 1) {
                    byte count = (byte)(cmd >> 1);
                    if (count) p += count;
                    else ++p;
                } else {
                    if ((cmd & 0xfe) != 0) ++p;
                    else done = 1;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (y <= clip_y1) {
        long rows = clip_y1 - y + 1;
        do {
            byte* cur = dst;
            long sx = shape_x1;
            byte state;
            if (shape_x1 < clip_x0) {
                state = 0;
                do {
                    byte cmd = *p++;
                    byte count = (byte)(cmd >> 1);
                    if ((cmd & 1) == 1) {
                        if (count == 0) {
                            sx += *p++;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1) state = 2;
                                else { state = 1; cur += sx - clip_x0; }
                            }
                        } else {
                            sx += count;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1) {
                                    state = 2;
                                    byte* end = cur + (clip_x1 - clip_x0) + 1;
                                    SHADOW_COPY(cur, end, table);
                                } else {
                                    state = 1;
                                    byte* end = cur + (sx - clip_x0);
                                    SHADOW_COPY(cur, end, table);
                                }
                            }
                            p += count;
                        }
                    } else {
                        if (count == 0) state = 3;
                        else {
                            sx += count;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1) {
                                    state = 2;
                                    byte* end = cur + (clip_x1 - clip_x0) + 1;
                                    SHADOW_COPY(cur, end, table);
                                } else {
                                    state = 1;
                                    byte* end = cur + (sx - clip_x0);
                                    SHADOW_COPY(cur, end, table);
                                }
                            }
                            ++p;
                        }
                    }
                } while (state == 0);
            } else {
                state = 1;
            }

            --state;
            while (state == 0) {
                byte cmd = *p++;
                byte count = (byte)(cmd >> 1);
                if ((cmd & 1) == 1) {
                    if (count == 0) {
                        byte n = *p++;
                        sx += n;
                        cur += n;
                        if (sx > clip_x1) state = 1;
                    } else {
                        sx += count;
                        if (sx > clip_x1) {
                            state = 1;
                            byte* end = cur + count + (clip_x1 - sx) + 1;
                            SHADOW_COPY(cur, end, table);
                        } else {
                            byte* end = cur + count;
                            SHADOW_COPY(cur, end, table);
                        }
                        p += count;
                    }
                } else {
                    if (count == 0) state = 3;
                    else {
                        sx += count;
                        if (sx > clip_x1) {
                            state = 1;
                            byte* end = cur + count + (clip_x1 - sx) + 1;
                            SHADOW_COPY(cur, end, table);
                        } else {
                            byte* end = cur + count;
                            SHADOW_COPY(cur, end, table);
                        }
                        ++p;
                    }
                }
            }

            --state;
            while (state == 0) {
                byte cmd = *p++;
                if ((cmd & 1) == 1) {
                    byte count = (byte)(cmd >> 1);
                    if (count) p += count;
                    else ++p;
                } else {
                    if ((cmd & 0xfe) != 0) ++p;
                    else state = 2;
                }
            }

            dst += pitch;
        } while (--rows != 0);
    }
    return 1;
}
