#pragma once
#include "../common.h"
#include "Panel.h"

class TEasy_Panel : public TPanel       {
public:
    char _pad_0x4[0xF0];
    long ideal_width;                        // 0xF4
    long ideal_height;                       // 0xF8
    char info_file_name[260];                // 0xFC
    long info_id;                            // 0x200
    TShape* background_pic;                  // 0x204
    TShape* background_pic2;                 // 0x208
    void* palette;                           // 0x20C
    char cursor_file[260];                   // 0x210
    long cursor_id;                          // 0x314
    int background_pos;                      // 0x318
    int use_bevels;                          // 0x31C
    uchar bevel_color1;                      // 0x320
    uchar bevel_color2;                      // 0x321
    uchar bevel_color3;                      // 0x322
    uchar bevel_color4;                      // 0x323
    uchar bevel_color5;                      // 0x324
    uchar bevel_color6;                      // 0x325
    ulong text_color1;                       // 0x328
    ulong text_color2;                       // 0x32C
    ulong focus_color1;                      // 0x330
    ulong focus_color2;                      // 0x334
    ulong state_color1;                      // 0x338
    ulong state_color2;                      // 0x33C
    char popup_info_file_name[260];          // 0x340
    long popup_info_id;                      // 0x444
    TShape* button_pics;                     // 0x448
    RGE_Color_Table* shadow_color_table;     // 0x44C
    long shadow_amount;                      // 0x450
    uchar background_color1;                 // 0x454
    uchar background_color2;                 // 0x455
    int enable_ime;                          // 0x458
    uchar help_mode;                         // 0x45C
    int stock_brush;                         // 0x460
    void* brush;                             // 0x464
    ulong brush_color;                       // 0x468
    TDrawArea* shadow_area;                  // 0x46C
    int allow_shadow_area;                   // 0x470
    int saved_mouse_mode;                    // 0x474

    TEasy_Panel(char* param_1);
    TEasy_Panel();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TEasy_Panel() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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

    // [Slot 10] Offset 0x28 (Override)
    virtual void draw_setup(int param_1); // Ghidra: draw_setup

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

    // [Slot 28] Offset 0x70 (Override)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_down

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

    // [Slot 45] Offset 0xB4 (Override)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // Ghidra: action

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 48] Offset 0xC0 (Override)
    virtual void set_focus(int param_1); // Ghidra: set_focus

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

    // [Slot 56] Offset 0xE0 (Override)
    virtual void draw_background(int param_1); // Ghidra: draw_background

    // [Slot 57] Offset 0xE4 (Override)
    virtual void set_ideal_size(long param_1, long param_2); // Ghidra: set_ideal_size

    // [Slot 58] Offset 0xE8 (Override)
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11); // Ghidra: create_button

    // [Slot 59] Offset 0xEC (Override)
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11); // Ghidra: create_button

    // [Slot 60] Offset 0xF0 (Override)
    virtual int create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // Ghidra: create_check_box

    // [Slot 61] Offset 0xF4 (Override)
    virtual int create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // Ghidra: create_radio_button

    // [Slot 62] Offset 0xF8 (Override)
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11); // Ghidra: create_text

    // [Slot 63] Offset 0xFC (Override)
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11); // Ghidra: create_text

    // [Slot 64] Offset 0x100 (Override)
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11); // Ghidra: create_text

    // [Slot 65] Offset 0x104 (Override)
    virtual int create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10); // Ghidra: create_input

    // [Slot 66] Offset 0x108 (Override)
    virtual int create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12); // Ghidra: create_edit

    // [Slot 67] Offset 0x10C (Override)
    virtual int create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // Ghidra: create_drop_down

    // [Slot 68] Offset 0x110 (Override)
    virtual int create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7); // Ghidra: create_list

    // [Slot 69] Offset 0x114 (Override)
    virtual int create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // Ghidra: create_scrollbar

    // [Slot 70] Offset 0x118 (Override)
    virtual int create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3); // Ghidra: create_auto_scrollbar

    // [Slot 71] Offset 0x11C (Override)
    virtual int create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // Ghidra: create_vert_slider

    // [Slot 72] Offset 0x120 (Override)
    virtual int create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // Ghidra: create_horz_slider

    // [Slot 73] Offset 0x124 (Override)
    virtual void position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5); // Ghidra: position_panel

    // --- Non-Virtual Members ---
    long setup(TDrawArea* param_1, TPanel* param_2, char* param_3, long param_4, int param_5, long param_6, long param_7, long param_8, long param_9, int param_10);
    void init_vars();
    void prepare_for_close();
    void setup_shadow_area(int param_1);
    void set_info_file(char* param_1, long param_2);
    int set_background(char* param_1, long param_2);
    int set_background2(char* param_1, long param_2);
    void set_background_colors(uchar param_1, uchar param_2);
    int set_palette(char* param_1, long param_2);
    int set_cursor(char* param_1, long param_2);
    void set_use_bevels(int param_1);
    void set_background_pos(int param_1);
    void set_bevel_colors(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6);
    void set_text_colors(ulong param_1, ulong param_2);
    void set_focus_colors(ulong param_1, ulong param_2);
    void set_state_colors(ulong param_1, ulong param_2);
    void set_popup_info_file(char* param_1, long param_2);
    void set_button_pics(char* param_1, long param_2);
    void set_shadow_amount(long param_1);
    void set_enable_ime(int param_1);
    char* get_info_file();
    long get_info_id();
    TShape* get_background();
    TShape* get_background2();
    void* get_palette();
    char* get_cursor();
    int get_use_bevels();
    int get_background_pos();
    void get_bevel_colors(uchar* param_1, uchar* param_2, uchar* param_3, uchar* param_4, uchar* param_5, uchar* param_6);
    void get_text_colors(ulong* param_1, ulong* param_2);
    void get_focus_colors(ulong* param_1, ulong* param_2);
    long get_shadow_amount();
    void get_state_colors(ulong* param_1, ulong* param_2);
    char* get_popup_info_file();
    long get_popup_info_id();
    TShape* get_button_pics();
    RGE_Color_Table* get_shadow_color_table();
    int get_enable_ime();
    void popupOKDialog(long param_1, char* param_2, int param_3, int param_4);
    void popupOKDialog(char* param_1, char* param_2, int param_3, int param_4);
    void popupYesNoDialog(long param_1, char* param_2, int param_3, int param_4);
    void popupYesNoDialog(char* param_1, char* param_2, int param_3, int param_4);
    void popupYesNoCancelDialog(long param_1, char* param_2, int param_3, int param_4);
    void popupYesNoCancelDialog(char* param_1, char* param_2, int param_3, int param_4);
    void command_help(char* param_1, long param_2, long param_3, long param_4, long param_5);
    void command_help(char* param_1, char* param_2, long param_3, long param_4, long param_5);
    void setup_popup_help();
    void clear_popup_help();
    long command_do_popup_help(uchar param_1, long param_2, long param_3);
    void set_system_colors();
};

static_assert(sizeof(TEasy_Panel) == 0x478, "TEasy_Panel Size Mismatch");
static_assert(offsetof(TEasy_Panel, saved_mouse_mode) == 0x474, "TEasy_Panel Offset Mismatch");

