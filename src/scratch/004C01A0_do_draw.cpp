// VA: 004C01A0 RGE_Sprite::do_draw
// PDB source: sprite.cpp, lines 475-590
//
// Attempt log:
// - Prior scratch was a decompiler-shaped placeholder: it used the wrong
//   helper/global surfaces (`get_frame`, malloc, and draw_trans) and was not a
//   useful source reconstruction.  The executable proves get_facetindex,
//   _ASMSet_Color_Xform, shape_draw/shape_mirror, SDI_List, and the two draw
//   logging globals instead.
// - baseline: restore the period-shaped sprite.cpp body and the typed
//   RGE_Color_Table/TShape/RGE_Base_Game surfaces.  This keeps the lazy shape
//   construction, facet selection, logging, color-table selection, and the
//   normal/mirror call families as ordinary C++.
// - behavior: the executable's first get_facetindex arm is the mirror family
//   (two shape_mirror sites, format `m`), while the late arm is one shared
//   shape_draw site (format `u`).  The ABI evidence also proves that the
//   first do_draw argument is the facet and the second is the frame.  The
//   source now passes those values to get_facetindex in that order, and uses
//   the nonzero result for the mirror family.
// - liveness/ABI: bind the draw-level comparison to SDI_Draw_Level, use the
//   direct TShape new-expression, and use signed int promotion for the uchar
//   draw-level parameter.  These moved the diff from 497 to 440 bytes.
// - control-flow: positive non-null color-table arms reproduce the oracle's
//   `je` null blocks.  A prior branch-local color byte preserved the second
//   mirror call site, but it read color_flag before _ASMSet_Color_Xform.  The
//   executable reads color_flag after that call.  The cache was removed to
//   preserve call-mutation and member-fault behavior.
// - follow-up: delaying the typed filename initialization until the lazy-load
//   arm changed the EH prologue and widened the result to 765 bytes; restored.
// - follow-up: a direct get_facetindex predicate and swapped natural local
//   declaration order were codegen duplicates of the clean source.
// - follow-up: passing color_flag directly merged the two mirror calls and
//   lost one binary call site (421 bytes); restored the branch-local color.
// - layout: use the typed draw-log buffer directly instead of s + 4; this
//   matches the original local-base LEAs and improves the structural basin to
//   390 differing bytes / 88.60% shape similarity.  The prologue allocation
//   remains the first structural mismatch.
// - revisit: direct fixed-table shape calls in both mirror and draw arms
//   recover the original 270-instruction CFG and raise shape similarity to
//   93.70%; the best clean basin is 826 bytes and 375 differing bytes.
//   A function-scope table pointer is retained because the binary has one
//   repeated pointer lifetime across the dynamic color arms.  Twenty distinct
//   source, ABI, context, layout, and lifetime probes did not recover the
//   original EBX/EBP color or the remaining dynamic-table blocks.  No inline
//   assembly or compiler-only source remains.
// - Accepted-drift blocker: with the required direct color_flag read, VC5
//   merges mirror call sites.  Keeping separate sites requires the early cache
//   that changes behavior across _ASMSet_Color_Xform.  Keep the natural direct
//   member source in scratch.
// - worker pass (sa-73e7a070-r1): restoring branch-local table declarations and
//   the early mirror color byte recovered the prior codegen frontier: 826 bytes,
//   270 instructions, all 23 ordered calls, and 375 differing bytes.  The
//   original reads color_flag after _ASMSet_Color_Xform, so this cache is not
//   retained in the policy-safe source.
// - worker probes: a frame local copy widened the mismatch to 763 bytes;
//   `register frame`, declaration-order changes, a shape alias, an explicit
//   uchar cast, and stdlib header context were duplicates or worse.  Moving the
//   color assignment after ASMSet restored direct behavior but merged one call.
// - final worker state: restored the direct-member, function-scope-table source
//   at 788 bytes and 415 differing bytes.  The remaining first mismatch is the
//   EBX/EBP frame-zero register basin; no natural source lead recovered it.

#include <stdio.h>

typedef unsigned char uchar;

class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;
class RGE_Picture_List;
class RGE_Sound;
class RGE_Sound_List;

class TShape {
public:
    char data[0x20];

    TShape(char* filename, long resource_id);
    ~TShape();
    uchar shape_draw(TDrawArea*, long, long, long, uchar, uchar*);
    uchar shape_mirror(TDrawArea*, long, long, long, uchar, uchar*);
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
    uchar table[0x100];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    void add_to_timing(int index, unsigned long value);
};

class DClipInfo_List {
public:
    char gap_00[0x6C];
    short* Select_Box;
};

extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl free(void* block);
extern "C" void __cdecl _ASMSet_Color_Xform(int value);
extern void __cdecl write_draw_log(char* text);
extern void __cdecl write_draw_log2(char* text);

extern RGE_Base_Game* rge_base_game;
extern DClipInfo_List* SDI_List;
extern int SDI_Draw_Level;
extern int do_draw_log;
extern int safe_draw_log;

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    uchar loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    TShape* shape;
    long last_time;
    long delta_time;
    uchar color_flag;
    uchar draw_level;
    short color_table;
    uchar transparent_picking_flag;
    char gap_2D[1];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    RGE_Sound* main_sound;
    uchar micro_man_sound;
    char gap_41[3];
    RGE_Sound_List* sound_list;
    char name[21];
    char gap_5D[1];
    short frame_num;
    short facet_num;
    char gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    uchar flag;
    char gap_71[1];
    short id;
    uchar mirror_flag;
    char gap_75[3];

    uchar get_facetindex(long facet, long frame, long& frame_out);
    void do_draw(long facet, long frame, long x, long y,
                 RGE_Color_Table* color_table, TDrawArea* draw_area,
                 uchar draw_level);
};

void RGE_Sprite::do_draw(long facet, long frame, long x, long y,
                         RGE_Color_Table* color_table,
                         TDrawArea* draw_area, uchar draw_level)
{
    char s[256];
    long facetindex;
    uchar* table;
    char* fname = 0;

    if (frame >= this->frame_num) {
        frame = 0;
    }

    if (this->shape == 0) {
        if (this->loaded == 0) {
            return;
        }
        addstring(&fname, this->pict_name, ".shp");
        unsigned long start =
            debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x1E8);
        this->shape = new TShape(fname, this->resource_id);
        unsigned long end =
            debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x1EA);
        rge_base_game->add_to_timing(0x0B, end - start);
        free(fname);
    }

    this->delta_time = 0;
    SDI_Draw_Level = this->draw_level;
    if (SDI_Draw_Level < draw_level) {
        SDI_Draw_Level = draw_level;
    }
    SDI_List->Select_Box = 0;
    if (this->box_x1 != 0) {
        SDI_List->Select_Box = &this->box_x1;
    }

    uchar mirrored = this->get_facetindex(facet, frame, facetindex);
    if (mirrored != 0) {
        if (do_draw_log != 0) {
            sprintf(s, "<%s,%d,%d,%d,%d,m", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(s);
            }
            else {
                write_draw_log(s);
            }
        }

        if (this->color_table < 0) {
            if (color_table != 0) {
                _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                this->shape->shape_mirror(draw_area, x, y, facetindex,
                                          this->color_flag, color_table->table);
            }
            else {
                this->shape->shape_mirror(draw_area, x, y, facetindex,
                                          this->color_flag, 0);
            }
            goto draw_done;
        }
        else {
            if (this->color_tables[this->color_table] != 0) {
                _ASMSet_Color_Xform((this->color_table + 1) * 0x10);
                table = this->color_tables[this->color_table]->table;
            }
            else {
                table = 0;
            }
            this->shape->shape_mirror(draw_area, x, y, facetindex,
                                      this->color_flag, table);
        }
    }
    else {
        if (do_draw_log != 0) {
            sprintf(s, "<%s,%d,%d,%d,%d,u", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(s);
            }
            else {
                write_draw_log(s);
            }
        }

        if (this->color_table < 0) {
            if (color_table != 0) {
                _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                this->shape->shape_draw(draw_area, x, y, facetindex,
                                        this->color_flag, color_table->table);
            }
            else {
                this->shape->shape_draw(draw_area, x, y, facetindex,
                                        this->color_flag, 0);
            }
        }
        else {
            if (this->color_tables[this->color_table] != 0) {
                _ASMSet_Color_Xform((this->color_table + 1) * 0x10);
                table = this->color_tables[this->color_table]->table;
            }
            else {
                table = 0;
            }
            this->shape->shape_draw(draw_area, x, y, facetindex,
                                    this->color_flag, table);
        }
    }

draw_done:
    if (do_draw_log != 0) {
        if (safe_draw_log != 0) {
            write_draw_log2(">");
        }
        else {
            write_draw_log(">");
        }
    }
}
