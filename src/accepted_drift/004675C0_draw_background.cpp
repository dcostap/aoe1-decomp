// VA 004675C0 TEasy_Panel::draw_background
// Panel_ez.cpp:402-530
// Attempt log:
// 1: Natural source from packet/decompiler, local TDrawArea/TShape surfaces.
// 2: First natural build compiled but was size-short: configured 979 exceeds .text 976.
// 3: Initial layout scaffold used +0x38 as background_pos and +0x318 as picture_style, with the remaining TEasy_Panel fields at their proven offsets.
// 4: Implemented the shadow-area path with clear/copy/center/tile modes, fallback pic selection, background clear colors, shape Lock/minmax/draw, shadow-table/DrawShadowBox, and bevel Lock/DrawBevel3/Unlock.
// 5: Probed /GX and /Ob0: still size-short 976 bytes. Probed /Og- and /Od: exact 979 bytes but broad mismatch (~91.6% positional, first mismatch offset 0); flags removed.
// 6: Added temporary volatile pad to recover exact size under /O2 for diagnostics; got exact 979 bytes but first mismatch offset 4 and broad 87.0% positional due artificial early stores; removed before final because it is not a valid match path.
// 7: Remaining blocker is broad VC5 frame/local topology: natural C has the right field offsets and broad call surface but compiles 3 bytes short; exact-size diagnostic forms are broad from prologue.
// 8: Reconstructed named TPanel -> TEasy_Panel ownership and typed TDrawArea/TShape/RGE_Color_Table surfaces. Corrected need_redraw at +0x38 and background_pos at +0x318, and renamed draw_setup/draw_finish virtual slots. Baseline is 973 bytes with the original control flow preserved.
// 9: Direct typed shadow_area member access improved positional diff by 36 bytes and exact-block coverage, but widened the size gap to 14 bytes; restored.
// 10: Split the clear-color conditional into explicit use_alt branches recovered original clear blocks and shape, but remained non-exact; restored.
// GIVEUP: left in scratch; no accepted_drift because natural build is size-short and diagnostic exact-size variants are broad/prologue-different.
// shardE-4675C0: direct shadow_area calls plus reuse of pic_hgt as the shadow tile height improved structural coverage; centered-width swap was rolled back.
// luna-4675C0-r1: donor-proven ten-slot TPanel virtual prefix, named y/x loop temporaries,
// centered y-before-x declarations, and offset-plus-field additions were codegen duplicates.
// An explicit clear-color branch moved to diff 826 and size 964; restored the clean source.
// luna-4675C0-r1: remaining structural lead is the shadow/picture tiled-call scheduling;
// the clean typed reconstruction remains best at diff 786, size 965/979, frame 0x1C.
// luna-4675C0-r4: added the period Windows SDK/RECT context from exact same-TU donors;
// diff improved to 763 with 73.37% exact-block coverage and a 973-byte body.
// luna-4675C0-r4: the full TShape 0x20-byte surface and shape_minmax pointer/int ABI
// emitted the same code.  Kept the proven declarations; no ABI mismatch was found.
// luna-4675C0-r4: with the Windows context active, explicit alternate/background clear
// branches reached the original 979-byte size, diff 760, and 77.62% exact-block coverage.
// Centered short expressions, shadow dimension order, local background_pos, and a
// short-circuit picture fallback were neutral or regressed; restored the best natural form.
// luna-4675C0-r4: current best is size/frame/call/CFG aligned; remaining structural drift
// starts in centered shadow Copy scheduling at +0xC6 and stays localized to code shape.
// sa-dbc4a910 H1-H19 and H21-H24: direct shadow-width rereads, cached selectors, inline centers,
// four center permutations, short/int/long coordinate locals, dimension declaration
// order, two switch-to-if rewrites, a named panel-height local, and an added standard
// header were tested and restored.  The swapped shadow Copy basin reached 135 differing
// bytes and 80.45% exact-block coverage, but it reverses the proven Copy(x,y) ABI and
// was not retained.  The clean canonical source remains 762 differing bytes, 979 bytes,
// 0x1C frame, 20 aligned calls, and 80.45% exact-block coverage.
// sa-dbc4a910 validation: unchanged clean source checked at 762 differing bytes;
// paused because the remaining lead is VC5 register allocation in the centered Copy
// block, not behavior, call order, layout, frame, or control-flow reconstruction.
// Accepted drift: centered shadow Copy uses the same signed-short x/y values
// and argument order. shape_minmax receives the same four writable stack
// addresses. All 20 calls, lock/unlock paths, shadow and bevel state, tile
// order, cleanup, faults, and return match. Remaining drift is private center
// coordinate scheduling.
// sa-6b4afaac exact-finish: H25 restored the default-case scope and was a
// codegen duplicate. H26 cached background_pos before the shadow dimensions
// and was a duplicate. H27 declared shadow Height before Width and worsened
// the body; all three forms were restored. Fresh clean validation kept the
// 20 ordered calls, frame, owner, and anchors, but rebuilt 977 bytes versus
// the 979-byte oracle. No natural source form produced an exact result.

// Panel_ez.cpp used the period Windows SDK surface.  Keep that TU context
// visible while retaining the local class declarations below.
#include <windows.h>

typedef unsigned char uchar;

typedef RECT tagRECT;

class TDrawSystem;
class DrawAreaNode;
class IDirectDrawSurface;
class TSpan_List_Manager;
class RGE_Color_Table;
class TShape;
class TPanel;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    uchar* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;
    char SurfaceDesc[0x6C];
    DrawAreaNode* Node;
    char* Name;
    uchar* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    RGE_Color_Table* shadow_color_table;
    TSpan_List_Manager* SpanList;
    TSpan_List_Manager* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    uchar TransColor;
    uchar gap_FD[3];

    void Clear(tagRECT*, int);
    uchar* Lock(char*, int);
    void Unlock(char*);
    void Copy(TDrawArea*, long, long, tagRECT*, int);
    void SetShadowTable(RGE_Color_Table*);
    void DrawShadowBox(long, long, long, long);
    void DrawBevel3(long, long, long, long, uchar, uchar, uchar, uchar, uchar, uchar);
};

class TShape {
public:
    uchar* shape_data;
    int load_type;
    int load_size;
    void* shape_header;
    void* head;
    void* offsets;
    void* fshape;
    void* shape_info;

    uchar shape_minmax(long*, long*, long*, long*, int);
    uchar shape_draw(TDrawArea*, long, long, long, uchar, uchar*);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    DrawAreaNode* node;
    DrawAreaNode* first_child_node;
    DrawAreaNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    TShape* background_pic;
    TShape* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    uchar pad_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    long shadow_amount;
    uchar background_color1;
    uchar background_color2;
    uchar pad_456[2];
    int enable_ime;
    uchar help_mode;
    uchar pad_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    void draw_background(int use_alt);
};

void TEasy_Panel::draw_background(int use_alt)
{
    long y_max;
    long x_min;
    long y_min;
    long x_max;
    long pic_hgt;
    TShape* pic;

    this->draw_setup(0);

    if (use_alt && this->shadow_area) {
        if (this->need_redraw == 2)
            this->render_area->Clear(&this->clip_rect, this->background_color2);

        int tile_w = this->shadow_area->Width;
        pic_hgt = this->shadow_area->Height;
        // BINARY NOTE: +0x318 selects 0/1/2 shadow placement and +0x18/+0x1C
        // supply the proven width/height tile increments.
        switch (this->background_pos) {
        case 0:
            this->shadow_area->Copy(this->render_area, this->pnl_x, this->pnl_y, 0, 0);
            break;
        case 1: {
            short yy = this->pnl_y + this->pnl_hgt / 2 - pic_hgt / 2;
            short xx = this->pnl_x + this->pnl_wid / 2 - tile_w / 2;
            // BINARY NOTE: Copy receives the panel x coordinate before y.
            this->shadow_area->Copy(this->render_area, (long)xx, (long)yy, 0, 0);
            break;
        }
        case 2: {
            long yy = 0;
            if (this->pnl_hgt >= 0) {
                do {
                    long xx = 0;
                    if (this->pnl_wid >= 0) {
                        do {
                            this->shadow_area->Copy(this->render_area, this->pnl_x + xx, this->pnl_y + yy, 0, 0);
                            xx += tile_w;
                        } while (xx <= this->pnl_wid);
                    }
                    yy += pic_hgt;
                } while (yy <= this->pnl_hgt);
            }
            break;
        }
        }
        goto bevels;
    }

    if (use_alt && this->background_pic2)
        pic = this->background_pic2;
    else
        pic = this->background_pic;

    if (this->need_redraw == 2 || pic == 0) {
        if (use_alt)
            this->render_area->Clear(&this->clip_rect, this->background_color2);
        else
            this->render_area->Clear(&this->clip_rect, this->background_color1);
        if (pic == 0)
            goto bevels;
    }

    if (this->render_area->Lock("panel_ez::draw_background", 1)) {
        pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
        long pic_w = x_max - x_min + 1;
        pic_hgt = y_max - y_min + 1;
        switch (this->background_pos) {
        case 1: {
            short yy = this->pnl_y + this->pnl_hgt / 2 - pic_hgt / 2;
            short xx = this->pnl_x + this->pnl_wid / 2 - pic_w / 2;
            pic->shape_draw(this->render_area, (long)xx, (long)yy, 0, 0, 0);
            if (use_alt && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox((long)xx, (long)yy, xx + pic_w - 1, yy + pic_hgt - 1);
            }
            break;
        }
        case 2: {
            long yy = 0;
            if (this->pnl_hgt >= 0) {
                do {
                    long xx = 0;
                    if (this->pnl_wid >= 0) {
                        do {
                            pic->shape_draw(this->render_area, this->pnl_x + xx, this->pnl_y + yy, 0, 0, 0);
                            xx += pic_w;
                        } while (xx <= this->pnl_wid);
                    }
                    yy += pic_hgt;
                } while (yy <= this->pnl_hgt);
            }
            if (use_alt && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1);
            }
            break;
        }
        default:
            pic->shape_draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0, 0);
            if (use_alt && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(this->pnl_x, this->pnl_y, this->pnl_x + pic_w - 1, this->pnl_y + pic_hgt - 1);
            }
            break;
        }
        this->render_area->Unlock("panel_ez::draw_background");
    }

bevels:
    if (this->use_bevels) {
        if (this->render_area->Lock("panel_ez::draw_background2", 1)) {
            this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                                        this->bevel_color1, this->bevel_color2, this->bevel_color3,
                                        this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->render_area->Unlock("panel_ez::draw_background2");
        }
    }
    this->draw_finish();
}
