#pragma once
#include "../common.h"

class TRIBE_Dialog_List : public RGE_Dialog_List       {
public:
    char _pad_0x4[0x4B8];

    TRIBE_Dialog_List(char* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Dialog_List() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void get_list_id();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void get_list_name();

    // [Slot 78] Offset 0x138 (Override)
    virtual int create_list(); // Ghidra: create_list

    // [Slot 79] Offset 0x13C (Override)
    virtual short get_cur_id(); // Ghidra: get_cur_id

    // --- Non-Virtual Members ---
    int create_build_list();
    int create_train_list();
    int create_research_list();
};

static_assert(sizeof(TRIBE_Dialog_List) == 0x4BC, "TRIBE_Dialog_List Size Mismatch");

