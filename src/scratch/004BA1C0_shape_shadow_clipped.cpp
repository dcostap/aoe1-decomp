// 004BA1C0 TShape::shape_shadow_clipped
// Attempt log:
// 1: direct Ghidra-structured clipped shadow decoder with TDrawArea/TShape offsets; helper-call baseline compiled to 864 bytes, too short.
// 2: macro-inlined copy loops reached exact 906-byte size but 90.07% positional / 66.23% edit diff; first mismatch is frame size sub esp,10 vs original sub esp,8.
// 3: root issue appears source topology/local allocation: original reuses incoming stack homes for stream pointer/count byte and keeps only two explicit locals, while this clean source keeps extra locals and holds stream pointer in EBP.
// 4 (shared eager-count diagnostic): keep the original eager count spelling but reuse one command/count pair across all RLE phases, testing a smaller source-local set before any further control-flow tuning.
// 7 (retained best basin): shared eager command/count/state locals restore the oracle-sized 0x08 frame and improve shape to 78.61%; the remaining gap is the early cursor/home/register schedule.
// 5 (formal-row probe, rolled back): direct shape_y1 reuse improved shape similarity but shortened the body and worsened positional drift; the clean source retains its explicit current-row copy.
// 6 (destination-offset probe, rolled back): a separate row-offset temporary improved setup shape but shortened the body and worsened the authoritative positional diff.
// 10 (delayed named-header probe, rolled back): the named owner was a codegen duplicate of the retained source and did not change the EBX/EBP cursor basin.
// shardB3-BA1C0 probe 12 (natural row topology, rolled back): reusing shape_y1 for the vertical skip and save_buffer for the persistent row destination improved block shape but shortened the body by 11 bytes and worsened the strict diff to 836 bytes.
// shardB3-BA1C0 probe 14 (named owner, retained): naming a TShapeHeader owner before deriving p was codegen-identical and keeps the stream ownership period-plausible; no ABI or call change resulted.
// shardE-4BA1C0 probe 16 (ABI, rolled back): retyped the draw-area formal as a byte stream home and used a typed area alias; 861 diff, worse.
// shardE-4BA1C0 probe 18 (control-flow, retained): delayed the current-row assignment until after destination setup; 805 diff, 79.77% shape.
// shardE-4BA1C0 probe 19 (ABI, rolled back): reused the draw-area formal itself as the stream cursor; 856 diff and lost call relocation identity.
// shardE-4BA1C0 probe 21 (liveness, duplicate): declared the current-row local before pitch but assigned it after setup; same 805-byte output.
// shardE-4BA1C0 probe 22 (liveness, duplicate): hoisted a typed table alias into the visible-row phase; same 805-byte output.
// shardE-4BA1C0 probe 23 (layout, duplicate): removed the separate header owner and derived the stream directly from shape_header; same 805-byte output.
// shardE-4BA1C0 probe 24 (liveness, rolled back): restored early row initialization; 900 diff and +21 bytes.
// shardE-4BA1C0 probe 26 (liveness, rolled back): removed the unused x local; restored the 812-byte clean basin.
// shardE-4BA1C0 probe 28 (layout, retained): direct stream derivation plus delayed row declaration and table alias; 805 diff, 79.77% shape.
// final retained: shared eager command/count/state plus direct stream derivation, delayed row declaration, and explicit destination locals; 906 bytes, exact 0x08 frame, 1/1 call identity, 805 strict differing bytes. Remaining evidence-backed blocker is the original p/clip-parameter home and early register schedule.
// left in scratch: behavior model is close to Ghidra but not an exact/accepted-drift candidate; needs a parameter-home-reuse rewrite mirroring original stack slots.
// managed claim probes (sa-df68f809, 2026-08-17):
// - Table alias declaration order, delayed table assignment, direct table use,
//   typed Byte_Table views, and full TShape member context were duplicate 906B
//   basins; the p cursor remained EBP and table reloads remained in copy loops.
// - Moving command shifts into visible odd arms alone reached 879B/857 diff;
//   initializing both arms reached 936B with a 0xC frame. Both were rolled back.
// - p-before-pitch and state-first declaration orders were worse or duplicate.
//   Long-return AlignedWidth, register table forms, row-local order, and an
//   explicit zero-guarded do-loop were duplicate codegen basins.
// - A dead draw-area assignment from p reached 856 diff. Reusing draw_area as
//   the typed stream cursor reached 892B/861 diff. Both confirm the home lead
//   but are not clean retained source forms.
// - Final clean validation remains 906B, 0x08 frame, one alignedwidth call,
//   79.77% shape, and 805 strict differing bytes. Calls and ownership are set;
//   the open lead is a natural source form that gives p the draw-area home and
//   table EBP without raw aliases or compiler-steering constructs.

#ifndef AOE1_SHAPE_CONTEXT_H
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
#endif

#define SHADOW_COPY(dst_, end_, table_) \
    while ((dst_) < (end_)) { \
        *(dst_) = (table_)[*(dst_)]; \
        ++(dst_); \
    }

byte TShape::shape_shadow_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1,
                                  long clip_x0, long clip_y0, long clip_x1, long clip_y1,
                                  byte* table)
{
    byte cmd;
    byte count;
    byte state;
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* p = (byte*)(this->shape_header + 1);
    byte* shadow_table = table;

    byte* dst;
    if (draw_area->Orien < 1) {
        dst = draw_area->Bits + (clip_y0 - draw_area->Height + 1) * pitch + clip_x0;
    } else {
        dst = draw_area->Bits + clip_y0 * pitch + clip_x0;
    }

    long y = shape_y1;

    if (y < clip_y0) {
        long skip_rows = clip_y0 - y;
        y += skip_rows;
        do {
            byte done = 0;
            do {
                cmd = *p++;
                if ((cmd & 1) == 1) {
                    count = (byte)(cmd >> 1);
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
            if (shape_x1 < clip_x0) {
                state = 0;
                do {
                    cmd = *p++;
                    count = (byte)(cmd >> 1);
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
                                    SHADOW_COPY(cur, end, shadow_table);
                                } else {
                                    state = 1;
                                    byte* end = cur + (sx - clip_x0);
                                    SHADOW_COPY(cur, end, shadow_table);
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
                                    SHADOW_COPY(cur, end, shadow_table);
                                } else {
                                    state = 1;
                                    byte* end = cur + (sx - clip_x0);
                                    SHADOW_COPY(cur, end, shadow_table);
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
                cmd = *p++;
                count = (byte)(cmd >> 1);
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
                            SHADOW_COPY(cur, end, shadow_table);
                        } else {
                            byte* end = cur + count;
                            SHADOW_COPY(cur, end, shadow_table);
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
                            SHADOW_COPY(cur, end, shadow_table);
                        } else {
                            byte* end = cur + count;
                            SHADOW_COPY(cur, end, shadow_table);
                        }
                        ++p;
                    }
                }
            }

            --state;
            while (state == 0) {
                cmd = *p++;
                if ((cmd & 1) == 1) {
                    count = (byte)(cmd >> 1);
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
