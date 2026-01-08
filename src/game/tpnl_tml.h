#pragma once
#include "../common.h"

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};


enum Style : unsigned int {
    NormalStyle = 0,
    BeveledStyle = 1,
    ChiseledStyle = 2,
};

class Time_Line_Panel : public TEasy_Panel       {
public:
    char _pad_0x4[0x474];
    void* axis_font;                         // 0x478
    long axis_font_wid;                      // 0x47C
    long axis_font_hgt;                      // 0x480
    void* body_font;                         // 0x484
    long body_font_wid;                      // 0x488
    long body_font_hgt;                      // 0x48C
    Style text_style;                        // 0x490
    ulong text_color1;                       // 0x494
    ulong text_color2;                       // 0x498
    ulong highlightTextColor1;               // 0x49C
    ulong highlightTextColor2;               // 0x4A0
    long text_wid;                           // 0x4A4
    long text_hgt;                           // 0x4A8
    TShape* background_pic;                  // 0x4AC
    short background_pic_wid;                // 0x4B0
    short background_pic_hgt;                // 0x4B2
    int fill_back;                           // 0x4B4
    uchar back_color;                        // 0x4B8
    int outline;                             // 0x4BC
    uchar outline_color;                     // 0x4C0
    int sorted;                              // 0x4C4
    int bevel_type;                          // 0x4C8
    uchar bevel_color1;                      // 0x4CC
    uchar bevel_color2;                      // 0x4CD
    uchar bevel_color3;                      // 0x4CE
    uchar bevel_color4;                      // 0x4CF
    uchar bevel_color5;                      // 0x4D0
    uchar bevel_color6;                      // 0x4D1
    TShape* special_events_pic;              // 0x4D4
    short special_events_pic_wid;            // 0x4D8
    short special_events_pic_hgt;            // 0x4DA
    long X_start_line_pos;                   // 0x4DC
    long Y_start_line_pos;                   // 0x4E0
    long X_line_pos;                         // 0x4E4
    long Y_line_pos;                         // 0x4E8
    long X_line_max_width;                   // 0x4EC
    long Y_line_max_length;                  // 0x4F0
    long X_axis_length;                      // 0x4F4
    long Y_axis_length;                      // 0x4F8
    float bar_thickness;                     // 0x4FC
    long pop_reading_rate;                   // 0x500
    float time_slice_drop_rate;              // 0x504
    long total_slices_to_drop;               // 0x508
    uchar drop_flag;                         // 0x50C
    long num_entries_page;                   // 0x510
    long num_history_entries;                // 0x514
    Special_Events* time_slice_events;       // 0x518
    uchar timeline_flag;                     // 0x51C
    TTextPanel* legend_entry_text[3];        // 0x520

    Time_Line_Panel();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~Time_Line_Panel() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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

    // [Slot 12] Offset 0x30 (Override)
    virtual void draw(); // Ghidra: draw

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

    // --- Non-Virtual Members ---
    long create_timeline(TPanel* param_1, Time_Line_Panel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10);
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, void* param_10, long param_11, long param_12, char* param_13, char* param_14, int param_15, uchar param_16, int param_17, uchar param_18);
    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    int set_background(char* param_1);
    int set_background(char* param_1, long param_2);
    int set_special_events(char* param_1);
    int set_special_events(char* param_1, long param_2);
    void set_axis_font(void* param_1, long param_2, long param_3);
    void set_body_font(void* param_1, long param_2, long param_3);
    void set_back_color(int param_1, uchar param_2);
    void draw_border();
    void init_timeline();
    void add_pop_total_special_event(long param_1, long param_2, long param_3, int param_4);
    void record_special_event(uchar param_1, TRIBE_History_Info* param_2, uchar param_3, long param_4, long param_5, long param_6, long param_7);
    int calculate_icon_location(Special_Events* param_1, short param_2, uchar param_3);
    void draw_axis();
    void draw_special_events();
    void draw_background();
    void draw_civilization_names();
    void draw_timeline();
    void draw_icon(Special_Events* param_1, short param_2, uchar param_3);
    void draw_legend();
};

static_assert(sizeof(Time_Line_Panel) == 0x52C, "Time_Line_Panel Size Mismatch");
static_assert(offsetof(Time_Line_Panel, legend_entry_text) == 0x520, "Time_Line_Panel Offset Mismatch");

