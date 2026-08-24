// Attempt log for 0051D4F0 TRIBE_Panel_Pop::render_to_image_buffer
// baseline: typed TPanel-owned fields, TDrawArea calls, GDI calls, and natural
// pop text plus five DrawTextA passes. Frame and early setup match.
// ABI probe: inherited one-argument TPanel::get_string is the correct period
// source surface. It leaves all 23 calls aligned, but sprintf starts 4 bytes high.
// layout probe: PDB local declaration order did not move the string destination.
// liveness probe: direct pop/max members and no named copies were codegen-neutral.
// control-flow probe: reordered Used* tail stores improved resync only; restored.
// rectangle probe: width/height update spelling improved resync but grew the frame;
// restored the natural direct bounds form.
// liveness probe: using str as the old-font spill was an unsupported compiler hack;
// it changed the frame and was restored.
// layout probe: original RECT/old_font/str declaration order was a codegen duplicate;
// restored the clean source.
// layout probe: using str instead of the decompiler's str+4 moved the first hunk
// four bytes earlier and improved shape. The simpler base form is retained.
// ABI probe: a normal imported SetRect reproduces the original repeated EBX call
// surface and reduced the positional diff from 419 to 234 bytes.
// PDB ABI: this is the protected owner
// ?render_to_image_buffer@TRIBE_Panel_Pop@@IAEHXZ, not a public QAE method.
// exact-finish probe: the original stack listing and decompiler show a
// contiguous rect/old-font/text window and text through str + 4. Natural
// str + 4 forms did not reproduce the VC5 stack overlap; they stayed 0x118.
// exact-finish probe: char str[252] with the natural dimension order restored
// the 0x114 frame and reduced the diff to 230, but it conflicts with the
// binary char[256] local evidence and is not retained.
// exact-finish probe: typed local aggregates, unions, old-font aliases,
// declaration scopes, Windows-header declarations, and explicit bound-update
// forms did not improve the supported source. The clean 234-byte candidate is
// restored.
// layout probe: str[252] restored the 0x114 frame and reduced the diff to 230,
// but the smaller buffer is not supported by the local evidence; restored str[256].
// Fresh hard pass: the PDB/Ghidra local window is RECT, old_font, char[256].
// Ghidra also proves that sprintf and all DrawTextA calls use str + 4. Keep
// that partial-output behavior even though the emitted bytes remain in the
// 234-byte basin.
// Fresh hard pass: the exact same-TU TPanel and TRIBE_Panel_Pop surfaces from
// 0051D060 restore canonical pnl_wid/pnl_hgt and render_rect ownership without
// changing output. The SDK Win32 header/API basin was tested and worsened the
// result to 430 bytes, so the narrow imported-call declarations remain.
// Fresh hard pass: Time-panel minus-one bounds, explicit pre-adjustment,
// direct tail member rereads, and a render-phase dimension scope were tested.
// The first two and direct rereads worsened the result; the scope was a codegen
// duplicate. The natural direct-bound form remains the smallest source.
// Exact-finish context pass: PDB symbols prove the protected owner
// ?render_to_image_buffer@TRIBE_Panel_Pop@@IAEHXZ and locals old_font at -0x104,
// str as char[256] at -0x100, and RECT at -0x114. The tagRECT alias retains this
// period SDK type without changing codegen.
// Exact-finish probes: moving dimension declarations, changing local order,
// declaring old_font at initialization, and using the analogous time-panel
// integer or minus-one bounds were duplicate or worse. Direct canonical field
// rereads worsened the body to 644 bytes. One-local width or height forms did
// reach the 0x114 frame, but changed the sprintf home and worsened the body to
// 393 or 420 bytes. All probes preserved the 23-call sequence and cleanup.
// Exact-finish probe H15: reversing the RECT, old_font, and str declarations
// was codegen-neutral. H16: a natural union for the proven old-font/string
// overlap reached the 0x114 frame and 232-byte diff, but did not reach exact
// output and did not match the separate PDB local surface. H17: reversing that
// union and RECT was duplicate. H18: grouping RECT and the union worsened the
// body to 236 bytes. H19: pre-adjusted bounds grew the body to 420 bytes and
// seven bytes past the target boundary. Restore the direct PDB-shaped source.
// BLOCKER: exact 668B remains blocked by the four-byte local-frame placement
// and downstream rectangle scheduling. Calls, ABI, pixel layout, cleanup, and
// fault order are understood.
// TU PASS: the authentic tpnl_pop.cpp wrapper uses PDB owner order and the
// /O2 /Oy /GX response file. It compiled 10 entries: 7/8 exact owners match,
// the generated deleting destructor matches, and the observed target is 430
// bytes different with one boundary escape. The grouped set_rect owner is
// 228 bytes different under shared context. No exact tuning follows this pass.

#ifndef TPNL_POP_SHARED_CONTEXT
#include <stdio.h>
struct tagRECT { long left, top, right, bottom; };
typedef tagRECT RECT;
class TDrawArea { public: char pad[0x38]; void* DrawDc; void PtrClear(RECT*, int); void* GetDc(char*); void SetClipRect(RECT*); void ReleaseDc(char*); };
typedef int PositionMode;
typedef int RedrawMode;
struct PanelNode;
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
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
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
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
    virtual unsigned char get_help_info(char**, long*, long, long);
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
    int clip_left;
    int clip_top;
    int clip_right;
    int clip_bottom;
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
    void* clip_rgn;
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
    long mouse_down_ctrl;
    long mouse_down_shift;
    unsigned long mouse_down_time;
    long error_code;
    long z_order;
    long display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
    char* get_string(int);
};
class TRIBE_Panel_Pop : public TPanel {
public:
    void* font;
    unsigned long color1;
    unsigned long color2;
    unsigned long color3;
    int player_id;
    void* world;
    void* player;
    int pop;
    int max_pop;
    unsigned char mode;
    unsigned char gap_119[3];
    float timer;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    RECT ImageRect;
    RECT UsedImageRect;
    RECT UsedScreenRect;
    int ImageTextActive;
protected:
    int render_to_image_buffer();
};
extern "C" int (__stdcall* const SelectClipRgn)(void*, void*);
extern "C" void* (__stdcall* const SelectObject)(void*, void*);
extern "C" int (__stdcall* const SetBkMode)(void*, int);
extern "C" unsigned long (__stdcall* const SetTextColor)(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetRect(RECT*, int, int, int, int);
extern "C" int (__stdcall* const DrawTextA)(void*, char*, int, RECT*, unsigned int);
#endif

static char tag[] = "tpnl_tim::render_to_image_buffer";

int TRIBE_Panel_Pop::render_to_image_buffer()
{
    RECT rect;
    void* old_font;
    char str[256];
    if (this->ImageBuffer == 0) return 0;
    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    if (this->ImageBuffer->GetDc(tag) == 0) return 0;
    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(this->ImageBuffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->ImageBuffer->DrawDc, this->font);
    SetBkMode(this->ImageBuffer->DrawDc, 1);
    sprintf(str + 4, "%s%ld/%ld", this->TPanel::get_string(0x2b2a), this->pop, this->max_pop);
    SetTextColor(this->ImageBuffer->DrawDc, this->color2);
    long width = this->pnl_wid;
    long height = this->pnl_hgt;
    SetRect(&rect, 0, 0, width - 3, height - 3); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 0, 2, width - 3, height - 1); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 2, 0, width - 1, height - 3); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 2, 2, width - 1, height - 1); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetTextColor(this->ImageBuffer->DrawDc, this->mode == 1 ? this->color3 : this->color1);
    --height; --width;
    SetRect(&rect, 1, 1, width, height); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SelectObject(this->ImageBuffer->DrawDc, old_font);
    SelectClipRgn(this->ImageBuffer->DrawDc, 0);
    this->ImageBuffer->ReleaseDc(tag);
    int right = this->pnl_wid - 1;
    int bottom = this->pnl_hgt - 1;
    this->UsedImageRect.left = 0; this->UsedImageRect.top = 0;
    this->UsedScreenRect.left = this->render_rect.left; this->UsedScreenRect.top = this->render_rect.top;
    this->UsedImageRect.right = right; this->UsedImageRect.bottom = bottom;
    this->UsedScreenRect.right = this->render_rect.left + right;
    this->UsedScreenRect.bottom = this->render_rect.top + bottom;
    this->ImageTextActive = 1;
    return 1;
}
