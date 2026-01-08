#pragma once
#include "../common.h"
#include "player.h"

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions       {
public:
    char _pad_0x4[0x1C];

    TRIBE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4);
    TRIBE_Victory_Conditions(RGE_Player* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 WARNING: Function body missing in analysis
    // virtual void handle_point_condition();

    // [Slot 01] Offset 0x04 (Override)
    virtual void handle_condition(RGE_Victory_Entry* param_1); // Ghidra: handle_condition

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void condition_description();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void draw_selected_area();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void draw_objects();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void draw_visible_object();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void draw_object();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void draw_view_rect();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void command_make_do();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void command_make_move();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void command_make_work();

    // --- Non-Virtual Destructor ---
    ~TRIBE_Victory_Conditions() noexcept(false);
    // --- Non-Virtual Members ---
    void handle_tech(RGE_Victory_Entry* param_1);
    uchar add_tech(uchar param_1, long param_2);
};

static_assert(sizeof(TRIBE_Victory_Conditions) == 0x20, "TRIBE_Victory_Conditions Size Mismatch");

