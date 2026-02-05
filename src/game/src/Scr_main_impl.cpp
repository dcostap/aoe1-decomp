#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/TTextPanel.h"
#include "../include/TPicturePanel.h"
#include "../include/globals.h"
#include "../include/RGE_Base_Game.h"

#include <string.h>
#include <stdio.h>

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu() : TScreenPanel((char*)"Main Menu") {
    this->title1 = nullptr;
    this->title2 = nullptr;
    for (int i = 0; i < 7; ++i) this->button[i] = nullptr;
    this->ms_title_text = nullptr;
    this->ms_copy_text1 = nullptr;
    this->ms_copy_text2 = nullptr;
    this->warning_text = nullptr;
    this->circle_p_pic = nullptr;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr1", 0xc383, 1)) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);

    int y = 0xb2;
    for (int i = 0; i < 5; ++i) {
        if (!this->create_button((TPanel*)this, &this->button[i], (char*)"", (char*)0, 0xaa, y, 0x12c, 0x28, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }
        y += 0x32;
    }

    if (this->button[0]) this->button[0]->set_text(0, 0x23f2);
    if (this->button[1]) this->button[1]->set_text(0, 0x23f3);
    if (this->button[2]) this->button[2]->set_text(0, 0x23f5);
    if (this->button[3]) this->button[3]->set_text(0, 0x23f6);
    if (this->button[4]) this->button[4]->set_text(0, 0x23f7);

    // Bottom Microsoft / copyright text. Match Scr_main.cpp.asm argument patterns.
    this->create_text((TPanel*)this, &this->ms_title_text, 0x2419, 0x5, this->ideal_height - 0x3c, this->ideal_width - 0xa, 0x12, 0xa, 1, 0, 0);

    char temp[512];
    temp[0] = '\0';
    this->get_string(0x2424, temp, sizeof(temp));
    if (temp[0] == '\0') {
        // Branch that draws a circle-P picture between two text panels.
        this->create_text((TPanel*)this, &this->ms_copy_text1, 0x241b, 0x5, this->ideal_height - 0x2a, 0x32, 0x12, 0xa, 0, 0, 0);
        if (this->ms_copy_text1) {
            tagRECT r;
            if (this->ms_copy_text1->get_text_rect(&r)) {
                this->circle_p_pic = new TPicturePanel();
                if (this->circle_p_pic) {
                    long circle_x = r.right + 1;
                    long circle_y = (r.bottom - this->pnl_y) + 3;
                    this->circle_p_pic->setup(this->render_area, (TPanel*)this, circle_x, circle_y, 0xf, 0xe, (char*)"circlep2", 0xc4e6, 0, 1);
                }
            }
        }
        if (this->circle_p_pic) {
            long x2 = this->circle_p_pic->xPosition() - this->pnl_x + this->circle_p_pic->width();
            long y2 = this->ideal_height - 0x2a;
            this->create_text((TPanel*)this, &this->ms_copy_text2, 0x241c, x2, y2, 500, 0x12, 0xa, 0, 0, 0);
        }
    } else {
        // Else branch: build a combined string and center it.
        char combined[512];
        combined[0] = '\0';
        char* s1 = this->get_string(0x241b);
        char* s2 = this->get_string(0x2424);
        if (s1) strncat(combined, s1, sizeof(combined) - 1);
        if (s2) strncat(combined, s2, sizeof(combined) - 1 - strlen(combined));
        this->create_text((TPanel*)this, &this->ms_copy_text1, combined, 0x5, this->ideal_height - 0x2a, this->ideal_width - 0xa, 0x12, 0xa, 1, 0, 0);
    }

    // Warning line: `0x2425` ("This program is protected by U.S. and international copyright laws...").
    // Match `Scr_main.cpp.decomp` call shape: x=5, y=ideal_h-0x18, w=ideal_w-10, h=0x12, font=10, center_h=1.
    this->create_text((TPanel*)this, &this->warning_text, 0x2425, 0x5, this->ideal_height - 0x18, this->ideal_width - 0xa, 0x12, 0xa, 1, 0, 0);

    // Best-effort: set current child to the first button (used for keyboard focus in the original).
    this->curr_child = (TPanel*)this->button[0];
}

TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Screen_Main_Menu::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Main_Menu::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Main_Menu::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Main_Menu::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Main_Menu::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Main_Menu::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Main_Menu::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Main_Menu::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Main_Menu::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Main_Menu::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Main_Menu::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Main_Menu::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Main_Menu::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Main_Menu::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Main_Menu::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Main_Menu::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Main_Menu::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Main_Menu::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::handle_idle() { return TScreenPanel::handle_idle(); }
long TRIBE_Screen_Main_Menu::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Main_Menu::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Main_Menu::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Main_Menu::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Main_Menu::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }

long TRIBE_Screen_Main_Menu::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: `src/game/src/Scr_main.cpp.asm` / `.decomp` for pointer comparisons on `param_2 == 1`.
    if (param_2 != 1) {
        return TScreenPanel::action(param_1, param_2, param_3, param_4);
    }

    // Button dispatch (menu build path currently only creates the first five).
    if ((TButtonPanel*)param_1 == this->button[2]) {
        // Help: open the WinHelp file (original shows a confirm dialog in some paths).
        if (rge_base_game && rge_base_game->prog_window) {
            WinHelpA((HWND)rge_base_game->prog_window, "empires.hlp", HELP_FINDER, 0);
        }
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->button[4]) {
        if (rge_base_game) rge_base_game->close();
        return 1;
    }

    // TODO: Implement transitions for Single Player / Multiplayer / Scenario Builder as the
    // corresponding screens are reimplemented accurately.
    return 1;
}

void TRIBE_Screen_Main_Menu::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Main_Menu::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Main_Menu::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Main_Menu::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Main_Menu::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Main_Menu::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Main_Menu::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Main_Menu::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Main_Menu::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Main_Menu::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Main_Menu::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Main_Menu::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Main_Menu::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Main_Menu::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Main_Menu::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Main_Menu::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Main_Menu::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Main_Menu::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Main_Menu::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Main_Menu::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Main_Menu::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Main_Menu::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Main_Menu::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Main_Menu::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
