#include "../include/TRIBE_Mission_Screen.h"

#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/globals.h"

#include <string.h>

// Best-effort transliteration of the mission dialog screen sufficient for the
// stop_video(video=3) post-intro branch.
TRIBE_Mission_Screen::TRIBE_Mission_Screen(char* description, unsigned char game_flag, TPicture* mission_picture)
    : TScreenPanel((char*)"Mission Dialog") {
    this->title = nullptr;
    this->list = nullptr;
    this->scroll_bar = nullptr;
    this->ok_button = nullptr;
    this->text_buttons[0] = nullptr;
    this->text_buttons[1] = nullptr;
    this->text_buttons[2] = nullptr;
    this->game_flag = game_flag;
    this->vc_back_bmp = mission_picture;

    if (rge_base_game == nullptr || rge_base_game->draw_area == nullptr) {
        this->error_code = 1;
        return;
    }

    // Source of truth: scr_vc.cpp.decomp uses "scr9" (0xC38C).
    if (this->TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr9", 0xc38c, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);

    // Title: "Instructions" (0x2655)
    this->create_text((TPanel*)this, &this->title, 0x2655, 10, 0xf, 0x26c, 0x14, 4, 1, 1, 0);

    const char* body = (description != nullptr) ? description : "";
    this->create_text((TPanel*)this, &this->list, (char*)body, 0xf, 0x46, 300, 0x154, 0xb, 0, 0, 1);
    if (this->list != nullptr) {
        this->create_auto_scrollbar(&this->scroll_bar, this->list, 0x14);
    }

    // OK button (0xFA1)
    this->create_button((TPanel*)this, &this->ok_button, 0xfa1, 0, 200, 0x1b8, 0xf0, 0x1e, 0, 0, 0);

    if (this->ok_button != nullptr) {
        this->ok_button->hotkey = 0x0d; // VK_RETURN
        this->ok_button->hotkey_shift = 0;
        this->curr_child = (TPanel*)this->ok_button;
    }
}

TRIBE_Mission_Screen::~TRIBE_Mission_Screen() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scroll_bar);
    this->delete_panel((TPanel**)&this->ok_button);
    for (int i = 0; i < 3; ++i) {
        this->delete_panel((TPanel**)&this->text_buttons[i]);
    }
}

long TRIBE_Mission_Screen::action(TPanel* panel, long action_id, ulong param_3, ulong param_4) {
    if (action_id == 1 && panel != nullptr && panel == (TPanel*)this->ok_button) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        if (game != nullptr) {
            game->create_game_screen();
        }
        return 1;
    }

    return TScreenPanel::action(panel, action_id, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TRIBE_Mission_Screen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Mission_Screen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Mission_Screen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Mission_Screen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Mission_Screen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Mission_Screen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Mission_Screen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Mission_Screen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Mission_Screen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Mission_Screen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Mission_Screen::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Mission_Screen::draw() { TScreenPanel::draw(); }
void TRIBE_Mission_Screen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Mission_Screen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Mission_Screen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Mission_Screen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Mission_Screen::paint() { TScreenPanel::paint(); }
long TRIBE_Mission_Screen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::handle_idle() { return TScreenPanel::handle_idle(); }
long TRIBE_Mission_Screen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Mission_Screen::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Mission_Screen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Mission_Screen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Mission_Screen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Mission_Screen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Mission_Screen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Mission_Screen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Mission_Screen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Mission_Screen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Mission_Screen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Mission_Screen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Mission_Screen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Mission_Screen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Mission_Screen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Mission_Screen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Mission_Screen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Mission_Screen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Mission_Screen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Mission_Screen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Mission_Screen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Mission_Screen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Mission_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Mission_Screen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Mission_Screen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Mission_Screen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Mission_Screen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Mission_Screen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Mission_Screen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Mission_Screen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Mission_Screen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Mission_Screen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Mission_Screen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Mission_Screen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

