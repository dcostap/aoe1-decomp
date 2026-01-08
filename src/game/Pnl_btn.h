#pragma once
#include "../common.h"

enum ActionType : unsigned int {
    ActionSelect = 1,
    ActionDown = 2,
    ActionUp = 3,
    ActionRightSelect = 4,
    ActionRightDown = 5,
    ActionRightUp = 6,
};

enum ButtonType : unsigned int {
    Normal = 1,
    Radio = 2,
    State = 3,
};

enum DrawType : unsigned int {
    DrawClear = 1,
    DrawPicture = 2,
    DrawTextA = 3,
    DrawPictureAndText = 4,
    DrawFillAndText = 5,
    DrawBevelPicture = 6,
};

enum NotifyType : unsigned int {
    NotifyAction = 1,
    NotifyCommand = 2,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};

class TButtonPanel : public TPanel       {
public:
    char _pad_0x4[0xF0];
    long id[9];                              // 0xF4
    long id2[9];                             // 0x118
    ButtonType buttonTypeValue;              // 0x13C
    DrawType drawTypeValue;                  // 0x140
    NotifyType notifyTypeValue;              // 0x144
    TDigital* sound;                         // 0x148
    TShape* pic[9];                          // 0x14C
    short pic_index[9];                      // 0x170
    int auto_pic_pos;                        // 0x184
    long pic_x;                              // 0x188
    long pic_y;                              // 0x18C
    int all_hot;                             // 0x190
    int draw_reverse;                        // 0x194
    char* text1[9];                          // 0x198
    char* text2[9];                          // 0x1BC
    long text_x;                             // 0x1E0
    long text_y;                             // 0x1E4
    void* font;                              // 0x1E8
    long font_wid;                           // 0x1EC
    long font_hgt;                           // 0x1F0
    short num_states;                        // 0x1F4
    short cur_state;                         // 0x1F6
    int is_down;                             // 0x1F8
    TButtonPanel** radio_buttons;            // 0x1FC
    short num_radio_buttons;                 // 0x200
    ulong button_down_time;                  // 0x204
    ulong text_color1[9];                    // 0x208
    ulong text_color2[9];                    // 0x22C
    ulong highlight_text_color1[9];          // 0x250
    ulong highlight_text_color2[9];          // 0x274
    long hotkey;                             // 0x298
    int hotkey_shift;                        // 0x29C
    int bevel_type;                          // 0x2A0
    uchar bevel_color1;                      // 0x2A4
    uchar bevel_color2;                      // 0x2A5
    uchar bevel_color3;                      // 0x2A6
    uchar bevel_color4;                      // 0x2A7
    uchar bevel_color5;                      // 0x2A8
    uchar bevel_color6;                      // 0x2A9
    long key_down;                           // 0x2AC
    int disabled;                            // 0x2B0
    int sound_number;                        // 0x2B4

    TButtonPanel();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TButtonPanel() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

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

    // [Slot 18] Offset 0x48 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 22] Offset 0x58 (Override)
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: handle_key_down

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

    // [Slot 33] Offset 0x84 (Override)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_down_action

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 35] Offset 0x8C (Override)
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_move_action

    // [Slot 36] Offset 0x90 (Override)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_up_action

    // [Slot 37] Offset 0x94 (Override)
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_dbl_click_action

    // [Slot 38] Offset 0x98 (Override)
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_down_action

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

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

    // [Slot 52] Offset 0xD0 (Override)
    virtual void stop_sound_system(); // Ghidra: stop_sound_system

    // [Slot 53] Offset 0xD4 (Override)
    virtual int restart_sound_system(); // Ghidra: restart_sound_system

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 56] Offset 0xE0 (Override)
    virtual void set_state(short param_1); // Ghidra: set_state

    // [Slot 57] Offset 0xE4 (Override)
    virtual int hit_button(long param_1, long param_2); // Ghidra: hit_button

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 193] Offset 0x304 (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 202] Offset 0x328 (Override)
    virtual void draw(); // Ghidra: draw

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 208] Offset 0x340 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 212] Offset 0x350 (Override)
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: handle_key_down

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 218] Offset 0x368 (Override)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // Ghidra: handle_mouse_down

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 223] Offset 0x37C (Override)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_down_action

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 225] Offset 0x384 (Override)
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_move_action

    // [Slot 226] Offset 0x388 (Override)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_up_action

    // [Slot 227] Offset 0x38C (Override)
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_dbl_click_action

    // [Slot 228] Offset 0x390 (Override)
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_down_action

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 230] Offset 0x398 (Override)
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_move_action

    // [Slot 231] Offset 0x39C (Override)
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_up_action

    // [Slot 232] Offset 0x3A0 (Override)
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_right_dbl_click_action

    // [Slot 233] Offset 0x3A4 (Override)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: key_down_action

    // [Slot 234] Offset 0x3A8 (Override)
    virtual long char_action(long param_1, short param_2); // Ghidra: char_action

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 242] Offset 0x3C8 (Override)
    virtual void stop_sound_system(); // Ghidra: stop_sound_system

    // [Slot 243] Offset 0x3CC (Override)
    virtual int restart_sound_system(); // Ghidra: restart_sound_system

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 246] Offset 0x3D8 (Override)
    virtual void set_state(short param_1); // Ghidra: set_state

    // [Slot 247] Offset 0x3DC (Override)
    virtual int hit_button(long param_1, long param_2); // Ghidra: hit_button

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void set_bevel_info();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void set_bevel_info();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void set_font();

    // --- Non-Virtual Members ---
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, DrawType param_7, TDigital* param_8, NotifyType param_9, long param_10);
    ButtonType buttonType();
    DrawType drawType();
    NotifyType notifyType();
    void setDrawType(DrawType param_1);
    void setButtonType(ButtonType param_1);
    void set_picture_info(TShape* param_1, short param_2, long param_3, long param_4, int param_5, int param_6);
    void set_text_info(char* param_1, void* param_2, long param_3, long param_4, long param_5, long param_6);
    void set_text_info(long param_1, void* param_2, long param_3, long param_4, long param_5, long param_6);
    void set_text_pos(long param_1, long param_2);
    void set_radio_info(TButtonPanel** param_1, short param_2);
    void set_state_info(short param_1);
    void set_id(short param_1, long param_2, long param_3);
    void set_picture(short param_1, TShape* param_2, short param_3);
    void set_text(short param_1, char* param_2);
    void set_text(short param_1, char* param_2, char* param_3);
    void set_text(short param_1, long param_2);
    void set_text(short param_1, long param_2, long param_3);
    void set_font(void* param_1, long param_2, long param_3);
    void set_text_color(int param_1, ulong param_2, ulong param_3);
    void set_highlight_text_color(int param_1, ulong param_2, ulong param_3);
    void set_sound(TDigital* param_1);
    void set_radio_button();
    void set_state_by_id(long param_1);
    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    void set_disabled(int param_1);
    int get_state();
    long get_id();
    long get_id2();
    int get_text(short param_1, char** param_2, char** param_3);
    void get_text_color(short param_1, ulong* param_2, ulong* param_3);
    void do_action();
    void do_right_action(int param_1);
    void reset();
    void set_sound_number(int param_1);
};

static_assert(sizeof(TButtonPanel) == 0x2B8, "TButtonPanel Size Mismatch");
static_assert(offsetof(TButtonPanel, sound_number) == 0x2B4, "TButtonPanel Offset Mismatch");

