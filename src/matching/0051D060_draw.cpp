// 0051D060 TRIBE_Panel_Pop::draw
// tpnl_pop.cpp
//
// Attempt log:
// try 1: broad reconstruction from packet: guard surfaces, animation-state update, optional backing panel draw, text/rect drawing and restore.
// try 2: modeled early guards for screen(+0x20), palette(+0x70), surface(+0x6C), frame increment, and virtual draw/postDraw calls.
// try 3: modeled current-player lookup through global panel manager and cached object at +0x10C.
// try 4: modeled animMode +0x118 transition from player/font metric table and animTime +0x11C accumulation/reset cycle.
// try 5: modeled coordinate calculation via camera floats at +0x50/+0x2C/+0x10/+0x80 using roundFloat.
// try 6: modeled redraw/rebuild path controlled by image +0x124, changed flag, needsRedraw +0xF3, lastX +0x110, lastY +0x114.
// try 7: modeled overlay/image fast path with lock/draw/unlock and early virtual postDraw.
// try 8: modeled main drawing setup: lock, SelectObject, SetTextColor, SetBkMode, sprintf label from coord helper.
// try 9: modeled border text as repeated SetRect + DrawTextA around panel bounds (+8C/+90/+18/+14), then foreground text and GDI restore.
// try 10: default compile produced .text 928B vs original 1033B, no full diff.
// try 11: /GX probe produced identical 928B, removed flag file.
// try 12: restored the same-TU TPanel/TRIBE_Panel_Pop layout and real DrawArea/GDI/member-call surfaces from exact tpnl_pop donors; replaced fake lock/roundFloat helpers with draw_setup, get_player, __ftol, SetTrans/Copy, GetDc/ReleaseDc, and imported GDI calls.
// try 13: changed the byte-mode gate from != 0 to > 0; test/jbe now matches the oracle, with no other structural movement.
// try 14: tested function-scope rect bounds, height/width declaration order, and in-place right/bottom updates; VC5 stayed in the same LEA family (the oracle uses sub/sub/add/add).
// try 15: tested foreground color-area assignment/declaration order and a 25-variant focused rect/color lab; no exact variant, with all size/frame/call-set gates stable.
// try 16: modeled the canonical same-TU TPanel render bounds as one RECT; VC5 emitted identical code, so the typed aggregate is retained.
// try 17: reused adjusted width/height as right/bottom, following the original EBX/EAX sub/sub/add/add block and the decompiler's lack of named right/bottom locals; emitted duplicate bytes, so restored.
// try 18: spelled width/height decrements as explicit assignments to test compound-assignment lowering; emitted duplicate bytes, so restored.
// try 19: changed the binary-proven one-byte changed_mode flag to bool, following the decompiler's bool source candidate; emitted duplicate bytes, so restored.
// r5 probe: function-scoped rectangle locals, reordered color declarations, and hoisted color locals were codegen duplicates.
// r5 probe: reversed bound expression order improved shape only (97.55%) but worsened positional diff; restored clean source.
// r5 probe: branch-local duplicate SetTextColor calls reproduced the oracle's branch-specific push shape but changed early register coloring; restored.
// r5 probe: int rectangle/panel fields, direct bound expressions, and direct right/bottom accumulators were codegen duplicates.
// Probe 20-plan checkpoint: H1 cross-assigned right/bottom aliases worsened the
// metric. H2 removed those aliases and reused the adjusted dimensions directly;
// it reduced the diff from 419 to 142 bytes. H3 swapped only the dimension
// initializer ownership; it reduced the diff to 140 bytes and restored the
// rectangle field-register pair. H4 declaration order was codegen-neutral. H5
// reversed assignment order and worsened the tail. H6 used direct
// SetTextColor calls in each branch and reached MATCH.
// Exact-finish retrospective: first exact checkpoint was probe-007-control-flow
// (0.0000%). R1 reverted H6 and returned to 140 bytes. R2 reverted H3 and
// returned to a 2-byte field-load mismatch. R3 restored right/bottom aliases
// and returned to 429 bytes. H2, H3, and H6 are decisive. H4 was incidental
// and disappeared with H6. C1 renamed the dimensions to natural ownership
// names; it preserved MATCH. The remaining crossed SetRect bounds preserve the
// original binary behavior and are required by exact output.
// final validated scratch state: exact typed reconstruction; source and default
// flags pass the authoritative checker at 1033/1033 bytes and 0.0000% diff.
// Canonical cleanup pass: C1-C7 replaced every pre-draw fake virtual slot with
// the named TPanel methods from Panel.cpp and exact panel donors. C8-C13 used
// RedrawMode, set_overlapped_redraw, draw_setup, draw_finish, draw, and the
// complete post-draw TPanel virtual surface. D1-D4 replaced used placeholder
// fields with panel.h ownership names. Each cleanup passed independently and
// the complete cleanup also remains MATCH.
// ORIGINAL BUG: In the mode==1 color arm, original 0051D3D4-0051D3F1 loads
// color3 and ImageBuffer, then calls SetTextColor(ImageBuffer->DrawDc,...).
// The following DrawText calls reload render_area at 0051D40C-0051D421.
// The constructor and set_rect evidence show ImageBuffer is a separate
// TDrawArea from render_area. This proves a shipped receiver mismatch: mode==1
// leaves render-area text at color2 instead of applying color3.
// Canonical cleanup retrospective: every C1-C13 and D1-D4 probe stayed exact.
// These changes are required for source policy and ABI ownership, but are
// incidental to emitted bytes. No inseparable cleanup group was found.

#include <windows.h>
#include <stdio.h>

class RGE_Game_World {
public:
    char gap_000[0x84];
    float world_time_delta_seconds;
};

class RGE_Player {
public:
    char gap_000[0x3C];
    RGE_Game_World* world;
    char gap_040[0x0A];
    short player_id;
    char gap_04C[4];
    float* attributes;
};

class RGE_Base_Game {
public:
    char gap_000[0x3F4];
    RGE_Game_World* world;
    char gap_3F8[0x63C];
    int need_counts[0x100];

    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    char gap_000[0x38];
    HDC DrawDc;

    void* GetDc(char* name);
    void ReleaseDc(char* name);
    void SetTrans(int enabled, unsigned char color);
    void Copy(TDrawArea* area, long x, long y, RECT* rect, int mode);
};

typedef int PositionMode;
typedef int RedrawMode;
struct PanelNode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                 long, long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
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

    char* get_string(int string_id);
};

class TRIBE_Panel_Pop : public TPanel {
public:
    void* font;
    unsigned long color1;
    unsigned long color2;
    unsigned long color3;
    int player_id;
    RGE_Game_World* world;
    RGE_Player* player;
    int pop;
    int max_pop;
    unsigned char mode;
    unsigned char gap_119[3];
    float timer;
    HRGN image_clip_region;
    TDrawArea* ImageBuffer;
    RECT ImageRect;
    RECT UsedImageRect;
    RECT UsedScreenRect;
    int ImageTextActive;
    long LastIBWidth;
    long LastIBHeight;

    int render_to_image_buffer();
    virtual void draw();
};

void TRIBE_Panel_Pop::draw()
{
    char str[256];
    HGDIOBJ old_font;
    RECT rect;
    unsigned char changed_mode;

    if (this->render_area == 0)
        return;
    if (this->visible == 0)
        return;
    if (this->active == 0)
        return;

    this->display_changed_count++;
    this->draw_setup(0);

    RGE_Player* player = rge_base_game->get_player();
    this->player = player;
    changed_mode = 0;

    if (this->mode == 0) {
        if (rge_base_game->need_counts[player->player_id] > 0) {
            this->mode = 1;
            this->timer = 0.0f;
            changed_mode = 1;
        }
    }

    if (this->mode > 0) {
        this->timer += player->world->world_time_delta_seconds;
        if (this->timer > 1.0f) {
            changed_mode = 1;
            this->timer = 0.0f;
            if (++this->mode > 2)
                this->mode = 0;
        }
    }

    {
        int pop = (int)player->attributes[0x2C / 4];
        int max_pop = pop + (int)player->attributes[0x10 / 4];
        int max_available = (int)player->attributes[0x80 / 4];
        if (max_pop > max_available)
            max_pop = max_available;

        if (this->ImageBuffer != 0 &&
            (changed_mode != 0 || this->need_restore != 0 ||
             this->pop != pop || this->max_pop != max_pop)) {
            this->pop = pop;
            this->max_pop = max_pop;
            this->render_to_image_buffer();
            if (this->need_restore != 0) {
                this->need_restore = 0;
                goto finish;
            }
        }
    }

    if (this->ImageTextActive != 0 && this->ImageBuffer != 0) {
        this->ImageBuffer->SetTrans(1, 1);
        this->ImageBuffer->Copy(this->render_area,
                                this->UsedScreenRect.left,
                                this->UsedScreenRect.top,
                                &this->UsedImageRect, 1);
        this->ImageBuffer->SetTrans(0, 1);
        goto finish;
    }

    if (this->render_area->GetDc((char*)"tpnl_tim::draw") != 0) {
        SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
        old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);
        SetBkMode(this->render_area->DrawDc, 1);
        sprintf(str, "%s%ld/%ld", this->get_string(0x2B2A),
                this->pop, this->max_pop);

        SetTextColor(this->render_area->DrawDc, this->color2);

        long left = this->render_rect.left;
        long top = this->render_rect.top;
        long height = this->pnl_hgt;
        long width = this->pnl_wid;
        ++left;
        ++top;
        width -= 2;
        height -= 2;
        SetRect(&rect, left - 1, top - 1, width + left - 2, height + top - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left - 1, top + 1, width + left - 2, height + top);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left + 1, top - 1, width + left, height + top - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left + 1, top + 1, width + left, height + top);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);

        if (this->mode == 1) {
            // Preserve the original receiver mismatch documented above.
            SetTextColor(this->ImageBuffer->DrawDc, this->color3);
        } else {
            SetTextColor(this->render_area->DrawDc, this->color1);
        }

        SetRect(&rect, left, top, width + left - 1, height + top - 1);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);

        SelectObject(this->render_area->DrawDc, old_font);
        SelectClipRgn(this->render_area->DrawDc, 0);
        this->render_area->ReleaseDc((char*)"tpnl_tim::draw");
    }

finish:
    this->draw_finish();
}
