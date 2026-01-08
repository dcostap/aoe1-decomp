#pragma once
#include "../common.h"

enum Action : unsigned int {
    OK = 0,
    Cancel = 1,
    Other = 2,
};

enum Type : unsigned int {
    OKDialog = 0,
    OKCancelDialog = 1,
    YesNoDialog = 2,
    RetryAbortDialog = 3,
    YesNoCancelDialog = 4,
};

class TMessageDialog : public TDialogPanel       {
public:
    char _pad_0x4[0x48C];
    uchar dlg_type;                          // 0x490
    TTextPanel* text;                        // 0x494
    TButtonPanel* button[3];                 // 0x498

    TMessageDialog(char* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TMessageDialog() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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

    // [Slot 19] Offset 0x4C (Override)
    virtual long handle_idle(); // Ghidra: handle_idle

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

    // [Slot 43] Offset 0xAC (Override)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: key_down_action

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 45] Offset 0xB4 (Override)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // Ghidra: action

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
    // virtual void `scalar_deleting_destructor'();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void recycle_in_to_game();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void recycle_out_of_game();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void shadow_draw();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void normal_draw();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void draw_front_frame();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void draw_back_frame();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void draw_frame();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void check_damage_sprites();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void rehook();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void teleport();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void new_sprite();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void add_overlay_sprite();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void remove_overlay_sprite();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void change_ownership();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void transform();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void set_object_state();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void remove_visible_resource();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void create_doppleganger_when_dying();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void destroy_obj();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void die_die_die();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void damage();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void calculateDamage();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void rotate();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void can_attack();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void set_attribute();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void set_attribute_amount();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void heal();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void heal();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void canRepair();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void notify_of_relation();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void do_command();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void move_to();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void work();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void stop();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void set_attack();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void new_angle();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void spawn_death_obj();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void get_command_master();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void set_being_worked_on();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void release_being_worked_on();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void is_moving();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void get_target_obj();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void enter_obj();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void exit_obj();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void explore_terrain();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void unexplore_terrain();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void get_los_table();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void inAttackRange();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void underAttack();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void setUnderAttack();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void calc_attack_modifier();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void getSpeed();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void getAngle();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void maximumSpeed();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void rateOfFire();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void damageCapability();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void damageCapability();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void weaponRange();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void minimumWeaponRange();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void passableTile();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void facetToNextWaypoint();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void currentTargetID();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void currentTargetX();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void currentTargetY();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void currentTargetZ();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void setWaitingToMove();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void waitingToMove();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void actionState();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void keepGatheringWhenObjectIsOut();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void produceWhenKilledBy();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void useSameZoneDropsite();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void attack();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void attack();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void moveAwayFrom();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void hunt();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void gather();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void convert();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void repair();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void build();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void trade();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void enter();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void transport();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void stopAction();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void pause();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void canPath();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void canPath();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void canBidirectionPath();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void canPathWithObstructions();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void canPathWithAdditionalPassability();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void findFirstTerrainAlongExceptionPath();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void canLinePath();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void canLinePath();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void firstTileAlongLine();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void userDefinedWaypoint();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void addUserDefinedWaypoint();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void removeAllUserDefinedWaypoints();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void removeUserDefinedWaypoint();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void numberUserDefinedWaypoints();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void findAvoidancePath();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void get_action_checksum();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void get_waypoint_checksum();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void create_object_list();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void create_sprite_list();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void recycle_in_to_game();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void validate();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void setup();

    // --- Non-Virtual Members ---
    long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, uchar param_6, char* param_7, long param_8, long param_9);
    long setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, uchar param_6, int param_7, long param_8, long param_9);
};

static_assert(sizeof(TMessageDialog) == 0x4A4, "TMessageDialog Size Mismatch");
static_assert(offsetof(TMessageDialog, button) == 0x498, "TMessageDialog Offset Mismatch");

