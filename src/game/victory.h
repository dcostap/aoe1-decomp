#pragma once
#include "../common.h"

class RGE_Victory_Conditions       {
public:
    RGE_Victory_Entry* victory_list;         // 0x4
    long list_num;                           // 0x8
    RGE_Player* player;                      // 0xC
    uchar victory;                           // 0x10
    RGE_Victory_Point_Entry* victory_point_list; // 0x14
    long point_list_num;                     // 0x18
    long tot_victory_points;                 // 0x1C

    RGE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4);
    RGE_Victory_Conditions(RGE_Player* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual void handle_point_condition(RGE_Victory_Point_Entry* param_1); // Ghidra: handle_point_condition

    // [Slot 01] Offset 0x04 (Override)
    virtual void handle_condition(RGE_Victory_Entry* param_1); // Ghidra: handle_condition

    // [Slot 02] Offset 0x08 (Override)
    virtual char* condition_description(RGE_Victory_Entry* param_1); // Ghidra: condition_description

    // [Slot 03] Offset 0x0C (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

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
    // virtual void pick_through_fog();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void pick_weight();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void start_scroll_view();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void handle_scroll_view();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void end_scroll_view();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void do_paint();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void draw_multi_object_outline();

    // --- Non-Virtual Destructor ---
    ~RGE_Victory_Conditions() noexcept(false);
    // --- Non-Virtual Members ---
    void check_for_victory();
    uchar update();
    void update_for_object(RGE_Static_Object* param_1);
    void handle_capture(RGE_Victory_Entry* param_1);
    void handle_create(RGE_Victory_Entry* param_1);
    void handle_create_in_area(RGE_Victory_Entry* param_1);
    void handle_destroy(RGE_Victory_Entry* param_1);
    void handle_destroy_multiple(RGE_Victory_Entry* param_1);
    void handle_destroy_all(RGE_Victory_Entry* param_1);
    void handle_destroy_player(RGE_Victory_Entry* param_1);
    void handle_bring_area(RGE_Victory_Entry* param_1);
    void handle_bring_object(RGE_Victory_Entry* param_1);
    void handle_attribute(RGE_Victory_Entry* param_1);
    void handle_explore(RGE_Victory_Entry* param_1);
    void handle_victory_points(RGE_Victory_Entry* param_1);
    RGE_Victory_Entry* add(uchar param_1, uchar param_2);
    uchar add_capture(uchar param_1, RGE_Static_Object* param_2, uchar param_3);
    uchar add_create(uchar param_1, long param_2, long param_3, uchar param_4);
    uchar add_create(uchar param_1, long param_2, long param_3, float param_4, float param_5, float param_6, float param_7, uchar param_8);
    uchar add_destroy(uchar param_1, RGE_Static_Object* param_2);
    uchar add_destroy(uchar param_1, long param_2, long param_3, RGE_Player* param_4);
    uchar add_destroy(uchar param_1, long param_2, RGE_Player* param_3);
    uchar add_destroy(uchar param_1, RGE_Player* param_2);
    uchar add_bring(uchar param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3);
    uchar add_bring(uchar param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5, float param_6);
    uchar add_attributes(uchar param_1, long param_2, long param_3, uchar param_4);
    uchar add_explore(uchar param_1, long param_2, uchar param_3);
    uchar add_victory_points(uchar param_1, long param_2, uchar param_3);
    void sub(RGE_Victory_Entry* param_1);
    void destroy_all();
    uchar condition_info(long param_1, char** param_2, uchar* param_3);
    RGE_Victory_Entry* condition_raw_info(long param_1);
    long condition_number(long param_1);
    uchar victory_achieved();
    uchar remove_condition(long param_1);
    RGE_Victory_Point_Entry* add_point(uchar param_1, uchar param_2);
    void sub_point(RGE_Victory_Point_Entry* param_1);
    uchar add_points_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    uchar add_points_attribute_first(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    uchar add_points_highest_attribute(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    uchar add_points_high_attribute_once(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    uchar add_points_high_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    void handle_points_attribute_amount(RGE_Victory_Point_Entry* param_1);
    void handle_points_attribute_first(RGE_Victory_Point_Entry* param_1);
    void handle_points_highest_attribute(RGE_Victory_Point_Entry* param_1);
    void handle_points_high_attribute_once(RGE_Victory_Point_Entry* param_1);
    void handle_points_high_attribute_amount(RGE_Victory_Point_Entry* param_1);
    long get_victory_points();
    long get_victory_points_group(uchar param_1);
    long get_victory_points_id(uchar param_1);
    long get_attribute_id(uchar param_1);
};

static_assert(sizeof(RGE_Victory_Conditions) == 0x20, "RGE_Victory_Conditions Size Mismatch");
static_assert(offsetof(RGE_Victory_Conditions, tot_victory_points) == 0x1C, "RGE_Victory_Conditions Offset Mismatch");

