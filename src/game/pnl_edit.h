#pragma once
#include "../common.h"

enum ActionType : unsigned int {
    ActionEnter = 0,
    ActionEscape = 1,
    ActionTab = 2,
};

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

enum FormatType : unsigned int {
    FormatText = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};

class TEditPanel : public TPanel       {
public:
    char _pad_0x4[0xF0];
    void* edit_wnd;                          // 0xF4
    short fixed_len;                         // 0xF8
    char* text;                              // 0xFC
    int text_len;                            // 0x100
    int hidden;                              // 0x104
    void* brush;                             // 0x108
    int stock_brush;                         // 0x10C
    void* old_sub_wnd_proc;                  // 0x110
    ulong text_color1;                       // 0x114
    ulong text_color2;                       // 0x118
    ulong highlight_text_color1;             // 0x11C
    ulong highlight_text_color2;             // 0x120
    ulong back_color;                        // 0x124
    FormatType format;                       // 0x128
    void* font;                              // 0x12C
    int multi_line;                          // 0x130
    tagRECT draw_rect;                       // 0x134
    uint draw_format;                        // 0x144
    int auto_sel;                            // 0x148
    int sel_len;                             // 0x14C
    int bevel_type;                          // 0x150
    uchar bevel_color1;                      // 0x154
    uchar bevel_color2;                      // 0x155
    uchar bevel_color3;                      // 0x156
    uchar bevel_color4;                      // 0x157
    uchar bevel_color5;                      // 0x158
    uchar bevel_color6;                      // 0x159
    int bevel_size;                          // 0x15C
    ulong imc;                               // 0x160
    int enable_ime;                          // 0x164
    int turn_ime_on;                         // 0x168

    TEditPanel();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TEditPanel() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 05] Offset 0x14 (Override)
    virtual void set_active(int param_1); // Ghidra: set_active

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 08] Offset 0x20 (Override)
    virtual void set_redraw(RedrawMode param_1); // Ghidra: set_redraw

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

    // [Slot 17] Offset 0x44 (Override)
    virtual void paint(); // Ghidra: paint

    // [Slot 18] Offset 0x48 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

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

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void action();

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

    // [Slot 55] Offset 0xDC (Override)
    virtual void handle_reactivate(); // Ghidra: handle_reactivate

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void set_bevel_info();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void set_bevel_info();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void set_font();

    // --- Non-Virtual Members ---
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, short param_8, char* param_9, FormatType param_10, int param_11);
    void set_text(char* param_1);
    void update_text();
    char* get_text();
    char* get_input_buffer();
    char* currentLine();
    void set_text_color(ulong param_1, ulong param_2);
    void set_highlight_text_color(ulong param_1, ulong param_2);
    void set_back_color(void* param_1, ulong param_2, uchar param_3);
    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    void set_ime_info(int param_1, int param_2);
    long sub_wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    int verify_char(int param_1);
    int is_blank();
    char* get_trimmed_str(char* param_1, int param_2);
};

static_assert(sizeof(TEditPanel) == 0x16C, "TEditPanel Size Mismatch");
static_assert(offsetof(TEditPanel, turn_ime_on) == 0x168, "TEditPanel Offset Mismatch");

