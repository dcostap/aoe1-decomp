// 00520080 Time_Line_Panel::draw_background
// Source: tpnl_tml.cpp lines 1062-1120
// Attempt log:
// 1: natural decompiler-shaped tiling/fill/bevel paths; behavior/call set close, edit diff ~86B.
// 2: fixed the height tile-count source to match the original's odd uninitialized-local fallthrough when pic_h < panel_h; edit diff improved to 76B.
// 3: tried y-coordinate named local before shape_draw; VC5 optimized to the same scheduling.
// 4: tried reversed x/y expression term order; no codegen change.
// 5: tried void return for TShape::shape_draw; no codegen change.
// 6: tried narrow unsigned-char zero args for shape_draw tail parameters; no codegen change.
// 7: tried explicit draw_x/draw_y locals; no codegen change.
// 8: tried compound assignment draw_y/draw_x spelling to force original register sequence; no codegen change.
// 9: tried swapping local declaration order; no codegen change.
// 10: tried short locals and for-loop spelling; worsened diff, reverted.
// 11: corrected TShape::shape_draw to the executable unsigned-char/long/uchar ABI;
//     emitted code was unchanged, but the living declaration now has the exact symbol surface.
// 12: mirrored the same-TU donor's y-then-x named temporaries; VC5 emitted the
//     same tiled loop, so the direct canonical expressions were restored.
// 13: made both tile-count locals short without casts; this worsened the height
//     branch and was restored to the int locals that preserve the observed stack stores.
// 14: fresh pass reversed the coordinate terms to the exact Pnl_txt donor form;
//     VC5 emitted the unchanged tiled loop.
// 15: fresh pass materialized long draw_y/draw_x locals with compound additions;
//     VC5 optimized them to the unchanged loop.
// 16: fresh pass declared draw_x before draw_y, following exact terrain-shape
//     register-coloring evidence; the emitted code was unchanged.
// 17: fresh pass declared typed int draw_y before draw_x in shape_draw, following
//     the exact Pnl_txt donor's source order; emitted code was unchanged.
// 18: natural typed lead from the exact Pnl_txt timeline donor: expose the
// period TShape data surface and SDK context while retaining the target ABI.
//    This moved the tiled loop to exact shape and reduced strict drift to 15
//    register-encoding bytes; the remaining hunk is count-setup register color.
// 19: narrowed the width tile-count local to short; VC5 emitted the same 15-byte
//     register-color drift, so the change was not retained as a codegen lead.
// 20: narrowed the height tile-count local to short; this added four bytes and
//     changed the loop shape, so it was restored.
// 21: removed temporary width/height locals and used direct panel members, as in
//     the exact Pnl_txt donor; this produced an exact 412-byte match.

#include <windows.h>

#ifndef TPNL_TML_WRAPPER
class TDrawArea {
public:
    unsigned char* Lock(char* tag, int flag);
    void Unlock(char* tag);
    void FillRect(long left, long top, long right, long bottom, unsigned char color);
};

class TShape {
public:
    unsigned char* shape_data;
    int load_type;
    int load_size;
    void* shape_header;
    void* head;
    void* offsets;
    void* fshape;
    void* shape_info;

    unsigned char shape_draw(TDrawArea* area, long x, long y, long a,
                             unsigned char b, unsigned char* c);
};

struct Rect4 { long left; long top; long right; long bottom; };

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(Rect4*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(Rect4*);     // +34
    virtual void draw_offset(long, long, Rect4*);
    virtual void draw_rect2(Rect4*);    // +3C
    char gap_04[0x80];
    int just_drawn;
};

class Time_Line_Panel {
public:
    virtual ~Time_Line_Panel();
    char gap_04[8];
    long pnl_x;                         // +0x0C
    long pnl_y;                         // +0x10
    long pnl_wid;                       // +0x14
    long pnl_hgt;                       // +0x18
    char gap_1C[4];
    TDrawArea* render_area;      // +0x20
    Rect4 clip_rect;              // +0x24
    char gap_34[0x0C];
    TPanel* parent_panel;         // +0x40
    char gap_44[0x468];
    TShape* background_pic;      // +0x4AC
    short background_pic_wid;    // +0x4B0
    short background_pic_hgt;    // +0x4B2
    int fill_back;               // +0x4B4
    unsigned char back_color;    // +0x4B8
    char gap_4B9[0x0F];
    int bevel_type;              // +0x4C8

    void draw_background();
};
#endif

void Time_Line_Panel::draw_background()
{
    int pic_rows;
    int tile_rows;

    if (this->background_pic != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background", 1) == 0) {
            return;
        }

        if (this->background_pic_wid >= this->pnl_wid) {
            pic_rows = 1;
        } else {
            pic_rows = this->pnl_wid / this->background_pic_wid;
            if ((short)pic_rows * this->background_pic_wid < this->pnl_wid) {
                pic_rows++;
            }
        }

        if (this->background_pic_hgt >= this->pnl_hgt) {
            tile_rows = this->pnl_hgt / this->background_pic_hgt;
            if ((short)tile_rows * this->background_pic_hgt < this->pnl_hgt) {
                tile_rows++;
            }
        }

        if ((short)tile_rows > 0) {
            int row = 0;
            tile_rows = (short)tile_rows;
            do {
                if ((short)pic_rows > 0) {
                    int col = 0;
                    int count = (short)pic_rows;
                    do {
                        this->background_pic->shape_draw(this->render_area,
                            col * this->background_pic_wid + this->pnl_x,
                            row * this->background_pic_hgt + this->pnl_y,
                            0, 0, 0);
                        col++;
                        count--;
                    } while (count != 0);
                }
                row++;
                tile_rows--;
            } while (tile_rows != 0);
        }

        this->render_area->Unlock("tpnl_tml::draw_background");
        return;
    }

    if (this->fill_back != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background2", 1) == 0) {
            return;
        }
        this->render_area->FillRect(this->pnl_x, this->pnl_y,
            this->pnl_x + this->pnl_wid - 1,
            this->pnl_y + this->pnl_hgt - 1,
            this->back_color);
        this->render_area->Unlock("tpnl_tml::draw_background2");
        return;
    }

    if (this->parent_panel != 0) {
        if (this->bevel_type >= 2 && this->bevel_type <= 7) {
            this->parent_panel->draw_rect2(&this->clip_rect);
            return;
        }
        if (this->parent_panel->just_drawn == 0) {
            this->parent_panel->draw_rect(&this->clip_rect);
        }
    }
}
