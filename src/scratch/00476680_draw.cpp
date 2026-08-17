// VA 00476680 TEditPanel::draw
// pnl_edit.cpp:859-973
// Attempt log:
// 1: Natural implementation from packet/decompiler with local TDrawArea/vtable and Win32 imports.
// 2: First compiling pass had exact 940-byte size but field offsets after rect were 4 bytes early; fixed TEditPanel gap so dirty is +0x38, visible +0x70, brush +0x108, bevel_type +0x150, colors +0x154..+0x159.
// 3: Fixed TDrawArea virtual surface: background border call is vtable +0x34 and high-bevel background call is +0x3c; inserted unused +0x38 slot.
// 4: Recovered the palette access through the typed DrawSystem ownership,
// matching the original GetNearestPaletteIndex argument load.
// 5: Implemented top draw_setup/draw_finish flow, dirty clear, Clear/fill background path, background image/border path, bevel switch cases 1..7, Lock/Unlock calls, and edit HWND show/hide/DrawTextEx path.
// 6: Bevel switch now uses original offsets/order for bevel_type and six colors; switch body is close enough that edit diff dropped to 18.8298% while size stayed exact.
// 7: Restructured early visible test from early return to `if (visible != 0) { body }`; no codegen change, rolled form kept harmless.
// 8: Probed /Ob0: no change. Probed /Og-: much worse (91.2766% positional, first mismatch 0), flag removed.
// 9: Remaining first mismatch is at offset 3: rebuilt saves EBX and EDI in the prologue, while original shrink-wraps them until after the visible/null check (`push edi; push ebx` at 00476697/98).
// 10: Current default validation: exact 940 bytes, positional 696 / 74.0426%, edit 177 / 18.8298%, first mismatch offset 3. Drift is broad positional due early callee-save scheduling and shifted branch distances, not accepted-drift quality.
// GIVEUP: left in scratch for future source-shape/context work to recover VC5 shrink-wrapped EBX/EDI saves and exact branch distances.
// Current bounded pass:
// 11: <windows.h> import declarations fixed all 13 indirect API relocations;
//     current checker result is 940B exact size, 27/27 calls, 38 differing bytes.
// 12-16: branch/lifetime, virtual draw declaration, and done-label variants
//     left the emitted code unchanged; canonical TPanel inheritance restored.
// 17: typed DrawArea->DrawSystem->Pal ownership replaced the diagnostic raw
//     vtable read with identical bytes. Final gap is prologue shrink-wrapping:
//     original delays push edi/ebx until the visible path, while VC5 saves them
//     at entry in this TU; the body is otherwise a 98.19% resynchronized match.
// New claim: baseline revalidated the 940-byte/38-byte-diff clean source.
// Probes 1-6 scoped RECT/old_font, tried positive visible nesting, removed the
// redundant panel receiver, reordered stack-local declarations, and completed
// the same-TU virtual surface; all were codegen duplicates.  Restore clean
// source for the documented shrink-wrap blocker.
// New claim probes: a focused guard/receiver variant lab (4 cases), a TPanel
// reference receiver, a shared hidden-exit goto label, and a braced invisible
// guard all preserved the 940-byte/38-byte-diff result.  Restored the clean
// pointer receiver and early-return source.  The only lead remains VC5's
// entry-save choice versus the original delayed EBX/EDI saves.
// Latest pass: 20 meaningful hypotheses. Header/context, class-surface,
// receiver/lifetime, guard, flag, and declaration variants did not change the
// prologue basin. A narrow offset overlay corrected the proven +0x12C font,
// +0x134 RECT, and +0x144 format accesses; diff improved 38 -> 30 bytes.
// Final clean source remains unresolved only at VC5 entry-save placement and
// its two epilogues. Ambient and risky/small flag labs found no exact variant.
// New claim #2: analyzed all three strict spans before probing. Span
// +0003..+0018 (00476683..00476698) is the entry-save and branch-span hunk.
// The original saves only EBP/ESI, then conditionally pushes EDI/EBX after
// the visible test. VC5 saves EBX/EBP/ESI at entry and EDI before that test.
// Spans +0297..+029A (00476917..0047691A) and +03A4..+03A7
// (00476A24..00476A27) are the matching pop-order hunks. The original pops
// EBX, EDI, ESI, EBP. The rebuilt code pops EDI, ESI, EBP, EBX.
// These three spans account for all 30 strict bytes. Calls, owner identity,
// frame size, and all body bytes outside the spans match after relocation
// masking. Twenty new natural hypotheses covered class ownership, full
// declarations, receiver and local lifetimes, control flow, local types,
// same-TU method declarations, and header context. The best result stayed
// 30 bytes in three spans. The canonical clean source is restored.
// BLOCKER: the remaining difference is VC5 callee-save shrink wrapping in
// this standalone TU. Prior flags and context probes did not recover it.
// Bounded original-TU follow-up: exact RGE_Panel_Time::draw and
// TInputPanel::draw donors both delay EDI/EBX until after real guards.
// Restoring their draw_setup/draw_finish names, full TPanel virtual names,
// draw_rect ownership, RedrawMode, local declaration points, and the exact
// view include order did not change the 30-byte result. A positive outer
// visible guard also did not change it. All probes were restored. The
// standalone source has no evidence-backed prologue allocation change.
// Source-gate audit: removed the artificial TPanel receiver lifetime and
// replaced the generic virtual slots with the canonical panel surface.
// Replaced the raw this-relative GDI field cursors with named fields at the
// executable-proven +0x12C, +0x134, and +0x144 offsets. The clean validation
// remains 940 bytes with 30 differing bytes and all 27 calls aligned.
// New claim follow-up: restored the reviewed TPanel, TDrawArea, TDrawSystem,
// and TEditPanel field and method surfaces, including parent_panel, just_drawn,
// clip_rect, color, the full virtual panel names, and the real edit helpers.
// Revalidated after each ownership, layout, ABI, lifetime, control-flow, and
// header change. All twelve natural probes remained a 30-byte mismatch.
// The remaining spans stay limited to the VC5 delayed EBX/EDI saves and the
// two corresponding pop orders. No natural source evidence changes them.
// Claim follow-up: twenty additional natural probes covered reviewed class
// method surfaces, method constness, declaration order, guard switch scopes,
// local lifetimes, named field access, and period header context.
// BINARY NOTE: all supported class and context changes stayed at 940 bytes,
// 27 ordered calls, and the same 30-byte three-span mismatch.
// BINARY NOTE: a render_area alias in the background path extended receiver
// liveness and worsened the result to 143 bytes; direct field access is kept.
// BINARY NOTE: branch scopes, declaration points, unqualified member calls,
// full TPanel/TDrawArea/TDrawSystem surfaces, and exact sibling header context
// did not move the delayed EBX/EDI saves.
// The canonical clean source is restored after this bounded pass.

#include <windows.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;
struct PanelNode;
struct TDrawArea;

struct TDrawSystem {
    void* Inst;
    void* Wnd;
    HPALETTE Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    void* DrawAreaList;
    void* DirDraw;
    void* PrimarySurface;
    void* Clipper;
    void* DirDrawPal;
    unsigned long Flags;
    int ScreenWidth;
    int ScreenHeight;
    int ColorBits;
    int ErrorCode;
    int ChangedMode;
    int IsBanked;
    int CanSrcBlt;
    int Restored;
    int ModeAvail640;
    int ModeAvail800;
    int ModeAvail1024;
    int ModeAvail1280;
    int ModeAvail320_200;
    int ModeAvail320_240;
    int ModeAvail320_200_16;
    int ModeAvail320_240_16;
    int ModeAvail640_16;
    int ModeAvail800_16;
    int ModeAvail1024_16;
    unsigned char palette[0x400];
    uchar DrawType;
    uchar ScreenMode;
    uchar _pad_end[2];
};

struct TDrawArea {
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
    RECT ClipRect;
    void* DrawDc;
    void* DrawSurface;
    char SurfaceDesc[0x6C];
    void* Node;
    char* Name;
    uchar* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    void* shadow_color_table;
    void* SpanList;
    void* CurSpanList;
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
    uchar _pad_end[3];
    void Clear(RECT* r, int color);
    uchar* Lock(char* name, int wait);
    void Unlock(char* name);
    HDC GetDc(char* name);
    void ReleaseDc(char* name);
    void DrawRect(long x1,long y1,long x2,long y2,uchar c1);
    void DrawBevel(long x1,long y1,long x2,long y2,uchar c1,uchar c2);
    void DrawBevel2(long x1,long y1,long x2,long y2,uchar c1,uchar c2,uchar c3,uchar c4);
    void DrawBevel3(long x1,long y1,long x2,long y2,uchar c1,uchar c2,uchar c3,uchar c4,uchar c5,uchar c6);
};

class TPanel {
public:
    enum PositionMode { POSITION_MODE_DEFAULT = 0 };
    enum RedrawMode { REDRAW_MODE_DEFAULT = 0 };

    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*);
    virtual void draw_rect2(RECT*);
    virtual void draw_offset2(long, long, RECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    RECT clip_rect;
    PositionMode position_mode;
    RedrawMode need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
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
    HRGN clip_rgn;
    RECT render_rect;
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

class TEditPanel : public TPanel {
public:
    enum FormatType { FORMAT_TYPE_DEFAULT = 0 };
    virtual ~TEditPanel();
    char* currentLine();
    char* get_input_buffer();
    char* get_text();
    char* get_trimmed_str(char*, int);
    int is_blank();
    void set_back_color(void*, unsigned long, uchar);
    void set_bevel_info(int, uchar, uchar, uchar, uchar, uchar, uchar);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_ime_info(int, int);
    void set_text(char*);
    void set_text_color(unsigned long, unsigned long);
    long setup(TDrawArea*, TPanel*, long, long, long, long,
               void*, short, char*, FormatType, int);
    long sub_wnd_proc(void*, unsigned int, unsigned int, long);
    void update_text();
    int verify_char(int);
    void* edit_wnd;
    short fixed_len;
    uchar pad_FA[2];
    char* text;
    int text_len;
    int hidden;
    void* brush;
    int stock_brush;
    int (__stdcall *old_sub_wnd_proc)();
    COLORREF text_color1;
    COLORREF text_color2;
    COLORREF highlight_text_color1;
    COLORREF highlight_text_color2;
    unsigned long back_color;
    FormatType format;
    HGDIOBJ font;
    int multi_line;
    RECT draw_rect;
    unsigned int draw_format;
    int auto_sel;
    int sel_len;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    uchar pad_15A[2];
    int bevel_size;
    unsigned long imc;
    int enable_ime;
    int turn_ime_on;

    virtual void draw();
};

void TEditPanel::draw()
{
    this->need_redraw = REDRAW_MODE_DEFAULT;
    if (this->visible == 0) return;
    RECT r;
    HGDIOBJ old_font;
    this->draw_setup(0);

    if (this->brush && this->active && this->have_focus) {
        uchar c = (uchar)GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, this->back_color);
        this->render_area->Clear(&this->clip_rect, c);
    } else {
        TPanel* bg = this->parent_panel;
        if (bg) {
            if (this->bevel_type >= 2 && this->bevel_type <= 7) {
                bg->draw_rect2(&this->clip_rect);
            } else if (bg->just_drawn == 0) {
                bg->draw_rect(&this->clip_rect);
            }
        } else {
            this->render_area->Clear(&this->clip_rect, this->color);
        }
    }

    if (this->bevel_type != 0) {
        if (this->render_area->Lock("pnl_edit::draw", 1)) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1);
                break;
            case 2:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock("pnl_edit::draw");
    }

    if (this->edit_wnd && this->active) {
        if (this->have_focus) {
            if (this->hidden) {
                ShowWindow(this->edit_wnd, 5);
                InvalidateRect(this->edit_wnd, 0, 1);
                this->hidden = 0;
                this->draw_finish();
                return;
            }
        } else {
            if (!this->hidden) {
                ShowWindow(this->edit_wnd, 0);
                this->hidden = 1;
            }
            HDC dc = this->render_area->GetDc("pnl_edit::draw");
            if (dc) {
                SelectClipRgn(dc, this->clip_rgn);
                old_font = SelectObject(dc, this->font);
                SetBkMode(dc, 1);
                SetTextColor(dc, this->text_color2);
                r.left = this->draw_rect.left - 1;
                r.top = this->draw_rect.top + 1;
                r.right = this->draw_rect.right - 1;
                r.bottom = this->draw_rect.bottom + 1;
                DrawTextExA(dc, this->text, -1, &r, this->draw_format, 0);
                SetTextColor(dc, this->text_color1);
                DrawTextExA(dc, this->text, -1, &this->draw_rect, this->draw_format, 0);
                SelectObject(dc, old_font);
                SelectClipRgn(dc, 0);
                this->render_area->ReleaseDc("pnl_edit::draw");
            }
        }
    }

    this->draw_finish();
}
