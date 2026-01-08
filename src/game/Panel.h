#pragma once
#include "../common.h"
#include "Drawarea.h"
#include "Panel.h"

// ----------------------------------------------------------------
// PanelNode
// Size: 0xC
struct PanelNode {
    TPanel * panel; // 0x0
    PanelNode * prev_node; // 0x4
    PanelNode * next_node; // 0x8
};

enum MouseAction : unsigned int {
    MouseActionNone = 0,
    MouseActionDown = 1,
    MouseActionHold = 2,
    MouseActionMove = 3,
};

enum MouseButton : unsigned int {
    MouseButtonNone = 0,
    LeftMouseButton = 1,
    RightMouseButton = 2,
};

enum PositionMode : unsigned int {
    PositionFixed = 0,
    PositionVariable = 1,
    PositionCentered = 2,
    PositionLeft = 3,
    PositionTop = 4,
    PositionRight = 5,
    PositionBottom = 6,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9,
    PositionRightBottom = 10,
};

enum RedrawMode : unsigned int {
    RedrawNone = 0,
    RedrawNormal = 1,
    RedrawFull = 2,
};

enum ZOrder : unsigned int {
    ZOrderPosition = 0,
    ZOrderTop = 1,
    ZOrderBottom = 2,
};


class TPanel       {
public:
    TPanel* previousPanelValue;              // 0x4
    TPanel* previousModalPanelValue;         // 0x8
    long pnl_x;                              // 0xC
    long pnl_y;                              // 0x10
    long pnl_wid;                            // 0x14
    long pnl_hgt;                            // 0x18
    char* panelNameValue;                    // 0x1C
    TDrawArea* render_area;                  // 0x20
    tagRECT clip_rect;                       // 0x24
    PositionMode position_mode;              // 0x34
    RedrawMode need_redraw;                  // 0x38
    TPanel* curr_child;                      // 0x3C
    TPanel* parent_panel;                    // 0x40
    TPanel* left_panel;                      // 0x44
    TPanel* top_panel;                       // 0x48
    TPanel* right_panel;                     // 0x4C
    TPanel* bottom_panel;                    // 0x50
    PanelNode* node;                         // 0x54
    PanelNode* first_child_node;             // 0x58
    PanelNode* last_child_node;              // 0x5C
    TPanel* tab_prev_panel;                  // 0x60
    TPanel* tab_next_panel;                  // 0x64
    int mouse_captured;                      // 0x68
    int active;                              // 0x6C
    int visible;                             // 0x70
    int tab_stop;                            // 0x74
    int have_focus;                          // 0x78
    int overlapping_children;                // 0x7C
    int handle_mouse_input;                  // 0x80
    int just_drawn;                          // 0x84
    void* clip_rgn;                          // 0x88
    tagRECT render_rect;                     // 0x8C
    long left_border;                        // 0x9C
    long top_border;                         // 0xA0
    long right_border;                       // 0xA4
    long bottom_border;                      // 0xA8
    long min_wid;                            // 0xAC
    long max_wid;                            // 0xB0
    long min_hgt;                            // 0xB4
    long max_hgt;                            // 0xB8
    long mouse_hold_interval;                // 0xBC
    long mouse_move_tolerance;               // 0xC0
    long mouse_down_x;                       // 0xC4
    long mouse_down_y;                       // 0xC8
    int mouse_down_ctrl;                     // 0xCC
    int mouse_down_shift;                    // 0xD0
    ulong mouse_down_time;                   // 0xD4
    int error_code;                          // 0xD8
    int z_order;                             // 0xDC
    int display_changed_count;               // 0xE0
    long help_string_id;                     // 0xE4
    long help_page_id;                       // 0xE8
    uchar mouse_action;                      // 0xEC
    uchar mouse_down_button;                 // 0xED
    uchar panel_type;                        // 0xEE
    uchar color;                             // 0xEF
    uchar fill_in_background;                // 0xF0
    uchar clip_to_parent;                    // 0xF1
    uchar draw_rect2_flag;                   // 0xF2
    uchar need_restore;                      // 0xF3

    TPanel(char* param_1);
    TPanel();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TPanel() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7); // Ghidra: setup

    // [Slot 02] Offset 0x08 (Override)
    virtual void set_rect(tagRECT param_1); // Ghidra: set_rect

    // [Slot 03] Offset 0x0C (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

    // [Slot 04] Offset 0x10 (Override)
    virtual void set_color(uchar param_1); // Ghidra: set_color

    // [Slot 05] Offset 0x14 (Override)
    virtual void set_active(int param_1); // Ghidra: set_active

    // [Slot 06] Offset 0x18 (Override)
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13); // Ghidra: set_positioning

    // [Slot 07] Offset 0x1C (Override)
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_fixed_position

    // [Slot 08] Offset 0x20 (Override)
    virtual void set_redraw(RedrawMode param_1); // Ghidra: set_redraw

    // [Slot 09] Offset 0x24 (Override)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // Ghidra: set_overlapped_redraw

    // [Slot 10] Offset 0x28 (Override)
    virtual void draw_setup(int param_1); // Ghidra: draw_setup

    // [Slot 11] Offset 0x2C (Override)
    virtual void draw_finish(); // Ghidra: draw_finish

    // [Slot 12] Offset 0x30 (Override)
    virtual void draw(); // Ghidra: draw

    // [Slot 13] Offset 0x34 (Override)
    virtual void draw_rect(tagRECT* param_1); // Ghidra: draw_rect

    // [Slot 14] Offset 0x38 (Override)
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3); // Ghidra: draw_offset

    // [Slot 15] Offset 0x3C (Override)
    virtual void draw_rect2(tagRECT* param_1); // Ghidra: draw_rect2

    // [Slot 16] Offset 0x40 (Override)
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3); // Ghidra: draw_offset2

    // [Slot 17] Offset 0x44 (Override)
    virtual void paint(); // Ghidra: paint

    // [Slot 18] Offset 0x48 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

    // [Slot 19] Offset 0x4C (Override)
    virtual long handle_idle(); // Ghidra: handle_idle

    // [Slot 20] Offset 0x50 (Override)
    virtual long handle_size(long param_1, long param_2); // Ghidra: handle_size

    // [Slot 21] Offset 0x54 (Override)
    virtual long handle_paint(); // Ghidra: handle_paint

    // [Slot 22] Offset 0x58 (Override)
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: handle_key_down

    // [Slot 23] Offset 0x5C (Override)
    virtual long handle_char(long param_1, short param_2); // Ghidra: handle_char

    // [Slot 24] Offset 0x60 (Override)
    virtual long handle_command(uint param_1, long param_2); // Ghidra: handle_command

    // [Slot 25] Offset 0x64 (Override)
    virtual long handle_user_command(uint param_1, long param_2); // Ghidra: handle_user_command

    // [Slot 26] Offset 0x68 (Override)
    virtual long handle_timer_command(uint param_1, long param_2); // Ghidra: handle_timer_command

    // [Slot 27] Offset 0x6C (Override)
    virtual long handle_scroll(long param_1, long param_2); // Ghidra: handle_scroll

    // [Slot 28] Offset 0x70 (Override)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_down

    // [Slot 29] Offset 0x74 (Override)
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // Ghidra: handle_mouse_move

    // [Slot 30] Offset 0x78 (Override)
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_up

    // [Slot 31] Offset 0x7C (Override)
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_dbl_click

    // [Slot 32] Offset 0x80 (Override)
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_move_action

    // [Slot 33] Offset 0x84 (Override)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_down_action

    // [Slot 34] Offset 0x88 (Override)
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_hold_action

    // [Slot 35] Offset 0x8C (Override)
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_move_action

    // [Slot 36] Offset 0x90 (Override)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_up_action

    // [Slot 37] Offset 0x94 (Override)
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_dbl_click_action

    // [Slot 38] Offset 0x98 (Override)
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_down_action

    // [Slot 39] Offset 0x9C (Override)
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_hold_action

    // [Slot 40] Offset 0xA0 (Override)
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_move_action

    // [Slot 41] Offset 0xA4 (Override)
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_up_action

    // [Slot 42] Offset 0xA8 (Override)
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_dbl_click_action

    // [Slot 43] Offset 0xAC (Override)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: key_down_action

    // [Slot 44] Offset 0xB0 (Override)
    virtual long char_action(long param_1, short param_2); // Ghidra: char_action

    // [Slot 45] Offset 0xB4 (Override)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // Ghidra: action

    // [Slot 46] Offset 0xB8 (Override)
    virtual void get_true_render_rect(tagRECT* param_1); // Ghidra: get_true_render_rect

    // [Slot 47] Offset 0xBC (Override)
    virtual int is_inside(long param_1, long param_2); // Ghidra: is_inside

    // [Slot 48] Offset 0xC0 (Override)
    virtual void set_focus(int param_1); // Ghidra: set_focus

    // [Slot 49] Offset 0xC4 (Override)
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2); // Ghidra: set_tab_order

    // [Slot 50] Offset 0xC8 (Override)
    virtual void set_tab_order(TPanel** param_1, short param_2); // Ghidra: set_tab_order

    // [Slot 51] Offset 0xCC (Override)
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // Ghidra: get_help_info

    // [Slot 52] Offset 0xD0 (Override)
    virtual void stop_sound_system(); // Ghidra: stop_sound_system

    // [Slot 53] Offset 0xD4 (Override)
    virtual int restart_sound_system(); // Ghidra: restart_sound_system

    // [Slot 54] Offset 0xD8 (Override)
    virtual void take_snapshot(); // Ghidra: take_snapshot

    // [Slot 55] Offset 0xDC (Override)
    virtual void handle_reactivate(); // Ghidra: handle_reactivate

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 (Override)
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7); // Ghidra: setup

    // [Slot 58] Offset 0xE8 (Override)
    virtual void set_rect(tagRECT param_1); // Ghidra: set_rect

    // [Slot 59] Offset 0xEC (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

    // [Slot 60] Offset 0xF0 (Override)
    virtual void set_color(uchar param_1); // Ghidra: set_color

    // [Slot 61] Offset 0xF4 (Override)
    virtual void set_active(int param_1); // Ghidra: set_active

    // [Slot 62] Offset 0xF8 (Override)
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13); // Ghidra: set_positioning

    // [Slot 63] Offset 0xFC (Override)
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_fixed_position

    // [Slot 64] Offset 0x100 (Override)
    virtual void set_redraw(RedrawMode param_1); // Ghidra: set_redraw

    // [Slot 65] Offset 0x104 (Override)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // Ghidra: set_overlapped_redraw

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 67] Offset 0x10C (Override)
    virtual void draw_finish(); // Ghidra: draw_finish

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 69] Offset 0x114 (Override)
    virtual void draw_rect(tagRECT* param_1); // Ghidra: draw_rect

    // [Slot 70] Offset 0x118 (Override)
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3); // Ghidra: draw_offset

    // [Slot 71] Offset 0x11C (Override)
    virtual void draw_rect2(tagRECT* param_1); // Ghidra: draw_rect2

    // [Slot 72] Offset 0x120 (Override)
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3); // Ghidra: draw_offset2

    // [Slot 73] Offset 0x124 (Override)
    virtual void paint(); // Ghidra: paint

    // [Slot 74] Offset 0x128 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

    // [Slot 75] Offset 0x12C (Override)
    virtual long handle_idle(); // Ghidra: handle_idle

    // [Slot 76] Offset 0x130 (Override)
    virtual long handle_size(long param_1, long param_2); // Ghidra: handle_size

    // [Slot 77] Offset 0x134 (Override)
    virtual long handle_paint(); // Ghidra: handle_paint

    // [Slot 78] Offset 0x138 (Override)
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: handle_key_down

    // [Slot 79] Offset 0x13C (Override)
    virtual long handle_char(long param_1, short param_2); // Ghidra: handle_char

    // [Slot 80] Offset 0x140 (Override)
    virtual long handle_command(uint param_1, long param_2); // Ghidra: handle_command

    // [Slot 81] Offset 0x144 (Override)
    virtual long handle_user_command(uint param_1, long param_2); // Ghidra: handle_user_command

    // [Slot 82] Offset 0x148 (Override)
    virtual long handle_timer_command(uint param_1, long param_2); // Ghidra: handle_timer_command

    // [Slot 83] Offset 0x14C (Override)
    virtual long handle_scroll(long param_1, long param_2); // Ghidra: handle_scroll

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 85] Offset 0x154 (Override)
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // Ghidra: handle_mouse_move

    // [Slot 86] Offset 0x158 (Override)
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_up

    // [Slot 87] Offset 0x15C (Override)
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_dbl_click

    // [Slot 88] Offset 0x160 (Override)
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_move_action

    // [Slot 89] Offset 0x164 (Override)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_down_action

    // [Slot 90] Offset 0x168 (Override)
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_hold_action

    // [Slot 91] Offset 0x16C (Override)
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_move_action

    // [Slot 92] Offset 0x170 (Override)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_up_action

    // [Slot 93] Offset 0x174 (Override)
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_dbl_click_action

    // [Slot 94] Offset 0x178 (Override)
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_down_action

    // [Slot 95] Offset 0x17C (Override)
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_hold_action

    // [Slot 96] Offset 0x180 (Override)
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_move_action

    // [Slot 97] Offset 0x184 (Override)
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_up_action

    // [Slot 98] Offset 0x188 (Override)
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_dbl_click_action

    // [Slot 99] Offset 0x18C (Override)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: key_down_action

    // [Slot 100] Offset 0x190 (Override)
    virtual long char_action(long param_1, short param_2); // Ghidra: char_action

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 102] Offset 0x198 (Override)
    virtual void get_true_render_rect(tagRECT* param_1); // Ghidra: get_true_render_rect

    // [Slot 103] Offset 0x19C (Override)
    virtual int is_inside(long param_1, long param_2); // Ghidra: is_inside

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 105] Offset 0x1A4 (Override)
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2); // Ghidra: set_tab_order

    // [Slot 106] Offset 0x1A8 (Override)
    virtual void set_tab_order(TPanel** param_1, short param_2); // Ghidra: set_tab_order

    // [Slot 107] Offset 0x1AC (Override)
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // Ghidra: get_help_info

    // [Slot 108] Offset 0x1B0 (Override)
    virtual void stop_sound_system(); // Ghidra: stop_sound_system

    // [Slot 109] Offset 0x1B4 (Override)
    virtual int restart_sound_system(); // Ghidra: restart_sound_system

    // [Slot 110] Offset 0x1B8 (Override)
    virtual void take_snapshot(); // Ghidra: take_snapshot

    // [Slot 111] Offset 0x1BC (Override)
    virtual void handle_reactivate(); // Ghidra: handle_reactivate

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void position_panel();

    // --- Non-Virtual Members ---
    void add_panel_node(PanelNode* param_1, PanelNode* param_2, int param_3);
    void remove_panel_node(PanelNode* param_1);
    void set_any_overlapping_redraw(TPanel* param_1, RedrawMode param_2);
    void get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5);
    void get_mouse_pos(tagPOINT* param_1);
    int capture_mouse();
    void release_mouse();
    uchar is_redraw_needed();
    int is_inside_rect(long param_1, long param_2, tagRECT* param_3);
    int bound_point(long* param_1, long* param_2);
    void set_curr_child(TPanel* param_1);
    int get_focus();
    void set_z_order(uchar param_1, short param_2);
    void set_child_z_order(TPanel* param_1, uchar param_2, short param_3);
    TPanel* previousPanel();
    void setPreviousPanel(TPanel* param_1);
    TPanel* previousModalPanel();
    void setPreviousModalPanel(TPanel* param_1);
    char* panelName();
    void setPanelName(char* param_1);
    long xPosition();
    long yPosition();
    long width();
    long height();
    TDrawArea* renderArea();
    tagRECT* clipRectangle(tagRECT* __return_storage_ptr__);
    void setClipRectangle(tagRECT param_1);
    void delete_panel(TPanel** param_1);
    int get_string(int param_1, char* param_2, int param_3);
    char* get_string(int param_1);
    long get_help_message();
    long get_help_page();
    void set_help_info(long param_1, long param_2);
};

static_assert(sizeof(TPanel) == 0xF4, "TPanel Size Mismatch");
static_assert(offsetof(TPanel, need_restore) == 0xF3, "TPanel Offset Mismatch");

class TPanelSystem       {
public:
    TPanel* mouseOwnerValue;                 // 0x0
    TPanel* keyboardOwnerValue;              // 0x4
    TPanel* modalPanelValue;                 // 0x8
    TPanel* currentPanelValue;               // 0xC
    PanelNode* panelListValue;               // 0x10
    int numberActivePanelsValue;             // 0x14
    TPanel* prevCurrentChildValue;           // 0x18
    void* palette[10];                       // 0x1C
    char palette_file[10][260];              // 0x44
    int palette_use_count[10];               // 0xA6C
    long palette_id[10];                     // 0xA94
    ulong Imc;                               // 0xABC
    int ImeEnabled;                          // 0xAC0
    int ImeOn;                               // 0xAC4
    int InputEnabled;                        // 0xAC8
    int saved_colors;                        // 0xACC
    ulong save_back_color;                   // 0xAD0
    ulong save_text_color;                   // 0xAD4

    TPanelSystem();

    // --- Non-Virtual Destructor ---
    ~TPanelSystem() noexcept(false);
    // --- Non-Virtual Members ---
    TPanel* currentPanel();
    TPanel* previousPanel();
    TPanel* mouseOwner();
    TPanel* keyboardOwner();
    TPanel* modalPanel();
    TPanel* panel(char* param_1);
    int numberActivePanels();
    int addPanel(TPanel* param_1, int param_2, int param_3);
    int removePanel(char* param_1);
    int setCurrentPanel(char* param_1, int param_2);
    int restorePreviousPanel(int param_1);
    void setMouseOwner(TPanel* param_1);
    void setKeyboardOwner(TPanel* param_1);
    void setModalPanel(TPanel* param_1);
    void setCurrentPanelModal();
    int restorePreviousModalPanel();
    int destroyPanel(char* param_1);
    int inSystem(char* param_1);
    int inSystem(TPanel* param_1);
    int setup();
    PanelNode* findPanelNode(char* param_1);
    void setCurrentPanel(TPanel* param_1, int param_2);
    void* get_palette(char* param_1, long param_2);
    void release_palette(void* param_1);
    void DisableIME();
    void EnableIME();
    int IsIMEEnabled();
    void TurnIMEOn();
    void TurnIMEOff();
    int IsIMEOn();
    int GetInputEnabled();
    void EnableInput();
    void DisableInput();
    void stop_sound_system();
    int restart_sound_system();
    void restore_system_colors();
    void set_restore();
};

static_assert(sizeof(TPanelSystem) == 0xAD8, "TPanelSystem Size Mismatch");
static_assert(offsetof(TPanelSystem, save_text_color) == 0xAD4, "TPanelSystem Offset Mismatch");

