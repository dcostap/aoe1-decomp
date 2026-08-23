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
//   `je` null blocks.  The fixed mirror arm rereads color_flag after
//   _ASMSet_Color_Xform.  The dynamic mirror arm reads color_flag before its
//   color-table lookup, as the executable proves, so its local byte is kept.
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
//   93.70%; the best source basin is 826 bytes and 375 differing bytes.
//   The mirror call count and ordered call map are exact.  The remaining
//   differences are the EBX/EBP parameter-zero basin and dynamic table blocks.
//   No inline assembly or compiler-only source remains.
// - The target remains in scratch.  The fixed mirror member read stays after
//   ASMSet_Color_Xform, while the dynamic mirror byte stays before table lookup.
// - worker pass: branch-local table declarations plus the dynamic mirror byte
//   recover all 23 ordered calls.  The fixed mirror call still rereads the
//   member after ASMSet_Color_Xform.  This preserves fault order.
// - context pass: the reviewed full sprite_context.h owner surface and the
//   neighboring game_globals.h declaration context are codegen duplicates.
//   Local-order, zero-local, register-frame, and common-call CFG probes were
//   also duplicates or worse.  The common-call probe widened the frame to
//   0x110 and lost one shape_mirror site; it was restored.
// - final worker state: current source is the natural 826-byte, 23-call
//   reconstruction.  Fresh checks still report 375 differing bytes.  The
//   first mismatch is the callee-saved frame/zero register color at +001C.

#include <stdlib.h>
#include <stdio.h>
#include "../../include/sprite_context.h"
#include "../../include/game_globals.h"

typedef unsigned char uchar;

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
    uchar table[0x100];
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

void RGE_Sprite::do_draw(long facet, long frame, long x, long y,
                         RGE_Color_Table* color_table,
                         TDrawArea* draw_area, uchar draw_level)
{
    char s[256];
    long facetindex;
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
            uchar* table;
            uchar color = this->color_flag;
            if (this->color_tables[this->color_table] != 0) {
                _ASMSet_Color_Xform((this->color_table + 1) * 0x10);
                table = this->color_tables[this->color_table]->table;
            }
            else {
                table = 0;
            }
            this->shape->shape_mirror(draw_area, x, y, facetindex,
                                      color, table);
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
            uchar* table;
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
