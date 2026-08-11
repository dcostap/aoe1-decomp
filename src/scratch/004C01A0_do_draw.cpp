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
//   shape_draw site (format `u`); swapping the decompiler labels restored the
//   ordered call families.
// - liveness/ABI: bind the draw-level comparison to SDI_Draw_Level, use the
//   direct TShape new-expression, and use signed int promotion for the uchar
//   draw-level parameter.  These moved the diff from 497 to 440 bytes.
// - control-flow: positive non-null color-table arms reproduce the oracle's
//   `je` null blocks.  A branch-local color byte in the fixed-table mirror arm
//   preserves the binary-proven second mirror call site; this is ordinary
//   typed source, not a register/asm workaround.  Best validated basin is
//   821 emitted bytes / 393 differing bytes, with all 23 ordered calls and
//   the 0x10C frame matching.  Remaining drift begins in saved-register/zero
//   coloring, local buffer placement, and block spans.  No inline asm.

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

    uchar get_facetindex(long frame, long facet, long& frame_out);
    void do_draw(long frame, long facet, long x, long y,
                 RGE_Color_Table* color_table, TDrawArea* draw_area,
                 uchar draw_level);
};

void RGE_Sprite::do_draw(long frame, long facet, long x, long y,
                         RGE_Color_Table* color_table,
                         TDrawArea* draw_area, uchar draw_level)
{
    char s[256];
    long facetindex;
    char* fname = 0;

    if (facet >= this->frame_num) {
        facet = 0;
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

    uchar mirrored = this->get_facetindex(frame, facet, facetindex);
    if (mirrored == 0) {
        if (do_draw_log != 0) {
            sprintf(s + 4, "<%s,%d,%d,%d,%d,m", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(s + 4);
            }
            else {
                write_draw_log(s + 4);
            }
        }

        if (this->color_table < 0) {
            uchar* table;
            if (color_table != 0) {
                _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                table = color_table->table;
            }
            else {
                table = 0;
            }
            this->shape->shape_mirror(draw_area, x, y, facetindex,
                                      this->color_flag, table);
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
            sprintf(s + 4, "<%s,%d,%d,%d,%d,u", this, x, y,
                    facetindex, this->color_flag);
            if (safe_draw_log != 0) {
                write_draw_log2(s + 4);
            }
            else {
                write_draw_log(s + 4);
            }
        }

        if (this->color_table < 0) {
            uchar* table;
            if (color_table != 0) {
                _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                table = color_table->table;
            }
            else {
                table = 0;
            }
            this->shape->shape_draw(draw_area, x, y, facetindex,
                                    this->color_flag, table);
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
