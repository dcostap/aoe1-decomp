// 00475F40 TEditPanel::wnd_proc(void*, unsigned int, unsigned int, long)
// Source: pnl_edit.cpp lines 524-598
// Size: 242 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PAUSED — 8-byte VC5 register-color drift in two base forwarding sites
//
// Attempt log:
// 1: Early if/goto reconstruction was 221 bytes with direct Win32 calls; this
//    established the guards/fields but had the wrong dispatch and call surface.
// 2: Natural sparse switch plus dllimport APIs restored 88/88 instructions,
//    all six ordered calls, and the original 242-byte boundary.
// 3: Signed short high-word notification test restored the original cmp cx,400.
// 4-7: Virtual/base layout, canonical active/visible ownership, and register
//    local aliases were tested; the emitted bytes stayed unchanged.
// 8: A 20-variant forwarding-call lab (casts, declaration order, and base
//    aliases) produced one codegen group, all with the same 8-byte drift.
// 9-10: Combined positive guard and the same-TU TPanel virtual surface were
//    restored as the final period-plausible source; no emitted-code change.
// New claim: baseline revalidated the clean source at 242 bytes/8-byte diff.
// Probes 1-8 added donor destructor/method declarations, a shared result local,
// explicit qualified/base-pointer receivers, nonvirtual-base and windows.h API
// surfaces; all were codegen duplicates, so the clean source was restored.
// Fresh lane: PDB source-order swap (0x133 before 0x111), forwarding result/
// receiver/first-argument forms, a named edit HWND, typed Win32 parameters,
// canonical full panel/edit fields and virtual declarations, extra period
// headers, and parameter-qualifier variants were tested. All plain/context
// forms stayed at the same 8-byte drift; volatile param_1 alone changed the
// frame and broad code, so it was rejected.
// Latest lane: explicit PDB ABI spellings, full donor-header virtual surfaces,
// result/edit-window declaration order, canonical WNDPROC field type, and a
// 16-variant forwarding-argument alias lab all stayed in the same 242-byte
// codegen group. No natural source form changed the forwarding-only coloring.
// New claim (sa-f1bb5619-r1, 10 probes): explicit this-qualified/cast base
// receivers, scoped case-7 forwarding, register-qualified parameters, a
// decompiler-shaped void* edit-window local, Win32 LOWORD/HIWORD macros, and
// an HDC receiver local were tested; all ordinary forms were duplicates, while
// the macros were structurally worse. A 7200-variant all-argument alias lab
// found no exact output (best diagnostic group was 6 bytes off, with volatile
// param_1 and aliases); a parameter-qualifier lab likewise found no lead.
// Restored the pinned clean result-local/TPanel source; the remaining gap is
// still only the two forwarding-call register-color families.
//
// Canonical facts:
// - TPanel owns active(+0x6C), visible(+0x70), and has size +0xF4.
// - TEditPanel owns edit_wnd(+0xF4), hidden(+0x104), brush(+0x108),
//   highlight_text_color1(+0x11C), and back_color(+0x124).
// - A sparse switch handles 7, 0x133, and 0x111 in that source order; the
//   default forwards to the qualified TPanel::wnd_proc. Win32 calls use the
//   original IAT surfaces.
//
// Final evidence: 242/242 bytes, 100% instruction/CFG/call/block shape, six
// relocations safely masked, and 8 positional bytes differ. The first drift
// is the default forward at +0xBE: original loads param_1 to ECX, while VC5
// chooses EDX. The case-7 forward also colors its three reloads differently
// (original ECX/EDX/EAX, rebuilt EAX/ECX/EDX). The fresh bounded lane exhausted
// the bounded lane without a productive emitted-code lead; keep this canonical
// readable source in scratch for a later worker.

#include <windows.h>

struct PanelNode;
struct TDrawArea;
typedef int PositionMode;
typedef int RedrawMode;

struct TPanel {
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
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
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    TPanel* previous_panel;       // +0x04
    TPanel* previous_modal_panel; // +0x08
    long pnl_x;                   // +0x0C
    long pnl_y;                   // +0x10
    long pnl_wid;                 // +0x14
    long pnl_hgt;                 // +0x18
    char* panel_name;             // +0x1C
    void* render_area;            // +0x20
    tagRECT clip_rect;            // +0x24
    int position_mode;            // +0x34
    int need_redraw;              // +0x38
    TPanel* curr_child;           // +0x3C
    TPanel* parent_panel;         // +0x40
    TPanel* left_panel;           // +0x44
    TPanel* top_panel;            // +0x48
    TPanel* right_panel;          // +0x4C
    TPanel* bottom_panel;         // +0x50
    PanelNode* node;              // +0x54
    PanelNode* first_child_node;  // +0x58
    PanelNode* last_child_node;   // +0x5C
    TPanel* tab_prev_panel;       // +0x60
    TPanel* tab_next_panel;       // +0x64
    int mouse_captured;           // +0x68
    int active;                  // +0x6C
    int visible;                 // +0x70
    int tab_stop;                 // +0x74
    int have_focus;               // +0x78
    int overlapping_children;     // +0x7C
    int handle_mouse_input;       // +0x80
    int just_drawn;               // +0x84
    void* clip_rgn;               // +0x88
    tagRECT render_rect;          // +0x8C
    long left_border;             // +0x9C
    long top_border;              // +0xA0
    long right_border;            // +0xA4
    long bottom_border;           // +0xA8
    long min_wid;                 // +0xAC
    long max_wid;                 // +0xB0
    long min_hgt;                 // +0xB4
    long max_hgt;                 // +0xB8
    long mouse_hold_interval;     // +0xBC
    long mouse_move_tolerance;    // +0xC0
    long mouse_down_x;            // +0xC4
    long mouse_down_y;            // +0xC8
    int mouse_down_ctrl;          // +0xCC
    int mouse_down_shift;         // +0xD0
    unsigned long mouse_down_time;// +0xD4
    int error_code;               // +0xD8
    int z_order;                  // +0xDC
    int display_changed_count;    // +0xE0
    long help_string_id;          // +0xE4
    long help_page_id;            // +0xE8
    unsigned char mouse_action;   // +0xEC
    unsigned char mouse_down_button; // +0xED
    unsigned char panel_type;     // +0xEE
    unsigned char color;          // +0xEF
    unsigned char fill_in_background; // +0xF0
    unsigned char clip_to_parent; // +0xF1
    unsigned char draw_rect2_flag;// +0xF2
    unsigned char need_restore;   // +0xF3
};

struct TEditPanel : TPanel {
    virtual ~TEditPanel();
    HWND edit_wnd;               // +0x0F4
    short fixed_len;             // +0x0F8
    unsigned char pad_FA[2];
    char* text;                  // +0x0FC
    int text_len;                // +0x100
    int hidden;                  // +0x104
    HBRUSH brush;                // +0x108
    int stock_brush;             // +0x10C
    WNDPROC old_sub_wnd_proc;     // +0x110
    unsigned long text_color1;   // +0x114
    unsigned long text_color2;   // +0x118
    unsigned long highlight_text_color1; // +0x11C
    unsigned long highlight_text_color2; // +0x120
    unsigned long back_color;    // +0x124
    int format;                  // +0x128
    void* font;                  // +0x12C
    int multi_line;              // +0x130
    tagRECT draw_rect;            // +0x134
    unsigned int draw_format;    // +0x144
    int auto_sel;                // +0x148
    int sel_len;                 // +0x14C
    int bevel_type;              // +0x150
    unsigned char bevel_color1;  // +0x154
    unsigned char bevel_color2;  // +0x155
    unsigned char bevel_color3;  // +0x156
    unsigned char bevel_color4;  // +0x157
    unsigned char bevel_color5;  // +0x158
    unsigned char bevel_color6;  // +0x159
    unsigned char pad_15A[2];    // +0x15A
    int bevel_size;              // +0x15C
    unsigned long imc;           // +0x160
    int enable_ime;              // +0x164
    int turn_ime_on;             // +0x168

    virtual long wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
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
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
};

long TEditPanel::wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4)
{
    HWND edit_window = edit_wnd;
    long result;

    if (edit_window != 0 && active != 0 && visible != 0 && hidden == 0) {
        switch (param_2) {
        case 7:
            result = TPanel::wnd_proc(param_1, 7, param_3, param_4);
            return result;

        case 0x133:
            if (brush != 0 && (void*)(param_4 & 0xFFFF) == edit_window) {
                SetBkColor((HDC)param_3, back_color);
                SetBkMode((HDC)param_3, 2);
                SetTextColor((HDC)param_3, highlight_text_color1);
                return (long)brush;
            }
            break;

        case 0x111:
            if ((void*)param_4 == edit_window && (short)(param_3 >> 16) == 0x400)
                InvalidateRect(edit_window, 0, 1);
            break;
        }
    }

    result = TPanel::wnd_proc(param_1, param_2, param_3, param_4);
    return result;
}
