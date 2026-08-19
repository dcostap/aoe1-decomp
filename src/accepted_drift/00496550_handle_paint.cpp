// VA: 00496550 handle_paint (425B)
// scr_game.cpp:1440-1521
//
// Natural reconstruction of the game-screen paint gate, child-panel refresh,
// and per-child timing accumulation.  The base-panel fields below preserve
// the proven offsets from the executable.
// Attempt log:
// - baseline matched size/frame/call set but kept this in ESI, the draw flag in
//   EDI, and a broad block/register drift (361 differing bytes).
// - materialized gate pointers, self/register aliases, and declaration-order
//   variants were duplicate or worse codegen; restored named direct fields.
// - explicit positive/else draw-all assignment recovered the oracle prologue,
//   42 exact leading instructions, and 369/428 resynchronized bytes.  The
//   remaining gap is a three-byte size shift around the Help-panel zero-store
//   and later local/register scheduling.  Further variants exhausted the
//   current worker budget; source remains the clean typed reconstruction.
//
// Fresh bounded pass (orch-scrgame-fresh-04):
// - naming the Help-dialog lookup result and assigning draw_all_children = 0
//   after that call reproduced the oracle's delayed zero-store and reduced the
//   positional diff to 158 bytes; VC5 consistently colors this local basin as
//   ESI=this/EDI=child cursor instead of the oracle's EDI=this/ESI cursor.
// - moving declarations, reusing a panel local, reversing comparisons,
//   explicit inequality arms, and pointer/reference spelling were duplicate
//   or worse codegen.  The named pointer form is retained as the most natural
//   source model supported by the PDB line order; the remaining gap is the
//   entry callee-save swap plus the resulting 5-byte size drift.
// - restored the period TPanel virtual slots, including its destructor and
//   named redraw/draw/paint methods; the output stayed unchanged.
// - tested donor-supported windows.h and stdio.h context; both were neutral.
// - reused one function-scope panel/node pair with while loops; output was a
//   duplicate, so the ordinary scoped for loops remain authoritative.
// - tested the natural loop-continue spelling for the per-child paint gate;
//   it reduced the mismatch from 158 to 133 bytes, but it skips the oracle's
//   child-end timing call and is not behavior-preserving.  It remains only a
//   diagnostic codegen result, not the authoritative source model.
//
// Fresh bounded pass (sa-4bac357f):
// - revalidated the original call set, virtual slots, frame, and boundary.
// - tested cursor and timestamp declaration scope/order, positive versus
//   nested paint guards, a proven skip label, and register-qualified locals.
//   These variants were duplicate or worse codegen.
// - restored the positive paint guard.  It preserves the oracle's unconditional
//   child-end timing call when a child is not painted.  It remains nonexact at
//   430 bytes with 158 differing bytes; no source variant reached MATCH.
//
// Fresh bounded pass (sa-cfede6b5-r1):
// - binding child_end - child_start to a typed elapsed local before the
//   main/map exclusion restored the original 425-byte size and instruction
//   order.  The behavior-preserving result is 34 differing bytes with all
//   calls, frame, and CFG signals exact; the remaining difference is register
//   coloring of this and the child cursors.
// - typed the proven TRIBE_Screen_Game fields and tested receiver aliases,
//   loop forms, declaration scope, and period helper declarations.  They were
//   unchanged or worse.  Keep the elapsed form as the clean natural source.
// Fresh final pass: function-scope node and shared node/panel lifetime probes
// both reproduced the same 34-byte output. The scoped source remains simplest.
// ACCEPTED DRIFT: All 34 changed bytes exchange ESI and EDI for `this` and the
// active child pointer. One register move shifts across the unchanged EDI save.
// Every field access, argument, flag use, call, branch, timing update, stack
// save, restore, cleanup, and possible fault stays in the same order.

#include <windows.h>
#include <stdio.h>

extern unsigned long debug_timeGetTime(const char* file, int line);

class TDrawArea {
public:
    void* draw_system;
    void* hwnd;
};

class TPanel;

struct PanelNode {
    TPanel* panel;
    char gap_04[4];
    PanelNode* next;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect2(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel* first, TPanel* second, int mode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();

    char gap_004[0x14 - 4];
    long width;                         // +0x14
    long height;                        // +0x18
    char gap_01C[4];
    TDrawArea* render_area;             // +0x20
    RECT rect;                            // +0x24
    char gap_034[4];
    int panel_mode;                     // +0x38
    TPanel* curr_child;                 // +0x3C
    TPanel* panel_40;                   // +0x40
    char gap_044[0x14];
    PanelNode* child_list;              // +0x58
    char gap_05C[0x10];
    void* field_6C;                     // +0x6C
    void* field_70;                     // +0x70
    char gap_074[4];
    int have_focus;                     // +0x78
    int field_7C;                       // +0x7C
    int field_80;                       // +0x80
    int redraw_needed;                  // +0x84
    char gap_088[0x6C];

    int get_focus();
};

class TPanelSystem {
public:
    TPanel* panel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_000[0x18];
    int prog_active;                    // +0x18

    void add_to_timing(int slot, unsigned long value);
};

extern RGE_Base_Game* rge_base_game;

extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hwnd);

static const char s_scr_game_cpp[] =
    "C:\\msdev\\work\\age1_x1\\scr_game.cpp";
static char s_Send_Quick_Message_Dialog[] = "Send Quick Message Dialog";
static char s_Help_Dialog[] = "Help Dialog";

class TScreenPanel : public TPanel {
public:
    char gap_0F4[0x384];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x40];
    TPanel* main_view;                   // +0x4B8
    TPanel* map_view;                    // +0x4BC

    virtual long handle_paint();
};

long TRIBE_Screen_Game::handle_paint() {
    if (this->render_area == 0) {
        return 0;
    }
    if (this->field_70 == 0) {
        return 0;
    }
    if (this->field_6C == 0) {
        return 0;
    }
    if (rge_base_game->prog_active == 0) {
        return 0;
    }
    if (IsIconic(this->render_area->hwnd) != 0) {
        return 0;
    }

    unsigned long first_time =
        debug_timeGetTime(s_scr_game_cpp, 0x5AA);

    int draw_all_children;
    if (this->panel_mode == 2 ||
        this->main_view->get_focus() != 0 ||
        this->curr_child == panel_system.panel(s_Send_Quick_Message_Dialog)) {
        draw_all_children = 1;
    } else {
        TPanel* help_dialog = panel_system.panel(s_Help_Dialog);
        draw_all_children = 0;
        if (this->curr_child == help_dialog) {
            draw_all_children = 1;
        }
    }

    if (this->panel_mode != 0) {
        if (draw_all_children) {
            for (PanelNode* node = this->child_list;
                 node != 0;
                 node = node->next) {
                node->panel->set_redraw(this->panel_mode);
            }

            TPanel* panel = this->panel_40;
            if (panel != 0 && panel->field_7C != 0) {
                panel->set_overlapped_redraw(this, this, this->panel_mode);
            }
            this->draw();
        }
        this->panel_mode = 0;
        this->redraw_needed = 1;
    }

    unsigned long other_time =
        debug_timeGetTime(s_scr_game_cpp, 0x5C2) - first_time;

    for (PanelNode* node = this->child_list;
         node != 0;
         node = node->next) {
        unsigned long child_start =
            debug_timeGetTime(s_scr_game_cpp, 0x5C9);
        TPanel* panel = node->panel;

        if (draw_all_children || panel == this->curr_child) {
            panel->handle_paint();
        }

        unsigned long child_end =
            debug_timeGetTime(s_scr_game_cpp, 0x5D0);
        unsigned long elapsed = child_end - child_start;
        if (panel != this->main_view && panel != this->map_view) {
            other_time += elapsed;
        }
    }

    rge_base_game->add_to_timing(0x11, other_time);
    this->redraw_needed = 0;
    return 0;
}
