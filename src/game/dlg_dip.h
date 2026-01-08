#pragma once
#include "../common.h"

class TribeDiplomacyDialog : public TDialogPanel       {
public:
    char _pad_0x4[0x48C];
    TTextPanel* title[8];                    // 0x490
    TTextPanel* playerName[8];               // 0x4B0
    TTextPanel* playerVictoryScores[8];      // 0x4D0
    TTextPanel* playerCivilization[8];       // 0x4F0
    TTextPanel* needMarket;                  // 0x510
    TButtonPanel* goldTributeButton[8];      // 0x514
    TButtonPanel* woodTributeButton[8];      // 0x534
    TButtonPanel* foodTributeButton[8];      // 0x554
    TButtonPanel* stoneTributeButton[8];     // 0x574
    TButtonPanel* allyButton[24];            // 0x594
    TButtonPanel* allianceButton;            // 0x5F4
    TButtonPanel* okButton;                  // 0x5F8
    TButtonPanel* clearButton;               // 0x5FC
    TButtonPanel* cancelButton;              // 0x600
    TButtonPanel* help_button;               // 0x604
    TShape* buttonPics;                      // 0x608
    TShape* backgroundPics;                  // 0x60C
    float foodTotal;                         // 0x610
    float woodTotal;                         // 0x614
    float goldTotal;                         // 0x618
    float stoneTotal;                        // 0x61C
    TTextPanel* playerFood;                  // 0x620
    TTextPanel* playerGold;                  // 0x624
    TTextPanel* playerWood;                  // 0x628
    TTextPanel* playerStone;                 // 0x62C
    float goldTributeAmount[8];              // 0x630
    float foodTributeAmount[8];              // 0x650
    float stoneTributeAmount[8];             // 0x670
    float woodTributeAmount[8];              // 0x690
    int cur_player_row;                      // 0x6B0
    int tribute_flag;                        // 0x6B4

    TribeDiplomacyDialog(TScreenPanel* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeDiplomacyDialog() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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
    // virtual void `vector_deleting_destructor'();

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
    // virtual void get_list_id();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void get_list_name();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // --- Non-Virtual Members ---
    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();
};

static_assert(sizeof(TribeDiplomacyDialog) == 0x6B8, "TribeDiplomacyDialog Size Mismatch");
static_assert(offsetof(TribeDiplomacyDialog, tribute_flag) == 0x6B4, "TribeDiplomacyDialog Offset Mismatch");

