#include "../include/TribeAchievementsScreen.h"

#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Scenario.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/globals.h"

#include <string.h>
#include <stdio.h>

// Best-effort implementation sufficient for the stop_video(video=4) post-game-over branch.
TribeAchievementsScreen::TribeAchievementsScreen(char* summary_text, int end_game_flag)
    : TScreenPanel((char*)"Achievements Screen") {
    this->end_game_flag = end_game_flag;
    this->current_mode = 0;
    this->size = 0;

    this->title = nullptr;
    this->summary_text = nullptr;
    this->instruction = nullptr;
    this->win_loss_text = nullptr;
    this->time = nullptr;
    for (int i = 0; i < 7; ++i) {
        this->title_bar[i] = nullptr;
    }
    for (int i = 0; i < 5; ++i) {
        this->achievement_choice[i] = nullptr;
    }
    for (int i = 0; i < 8; ++i) {
        this->player_names[i] = nullptr;
        for (int j = 0; j < 7; ++j) {
            this->statistics[i][j] = nullptr;
        }
    }
    this->summary_text_bar = nullptr;
    this->instruction_bar = nullptr;
    this->win_loss_text_bar = nullptr;
    this->okButton = nullptr;
    this->backButton = nullptr;
    this->backButton2 = nullptr;
    this->timelineButton = nullptr;
    this->aftermathButton = nullptr;
    this->restartButton = nullptr;
    this->close_button = nullptr;
    this->win_decal = nullptr;
    this->time_line = nullptr;

    if (rge_base_game == nullptr || rge_base_game->draw_area == nullptr) {
        this->error_code = 1;
        return;
    }

    // Source of truth: scr_ach.cpp.decomp chooses among scr10/scr7/scr8.
    char info_file[16];
    long info_id = 0xc38d;
    strcpy(info_file, "scr10");

    if (end_game_flag != 0) {
        RGE_Player* player = rge_base_game->get_player();
        if (player != nullptr && player->game_status == 1) {
            strcpy(info_file, "scr7");
            info_id = 0xc389;
        } else {
            strcpy(info_file, "scr8");
            info_id = 0xc38a;
        }
    }

    if (this->TScreenPanel::setup(rge_base_game->draw_area, info_file, info_id, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);

    // Title: "Achievements" (0x269E)
    this->create_text((TPanel*)this, &this->title, 0x269e, 0, 5, 0x280, 0x1e, 1, 1, 0, 0);

    const char* body = (summary_text != nullptr) ? summary_text : "";
    this->create_text((TPanel*)this, &this->summary_text, (char*)body, 10, 0x23, 0x26c, 0x14a, 0xb, 0, 0, 1);

    // OK button (0xFA1)
    this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 200, 0x1b8, 0xf0, 0x1e, 0, 0, 0);
    if (this->okButton != nullptr) {
        this->okButton->hotkey = 0x0d; // VK_RETURN
        this->okButton->hotkey_shift = 0;
        this->curr_child = (TPanel*)this->okButton;
    }
}

TribeAchievementsScreen::~TribeAchievementsScreen() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->summary_text);
    this->delete_panel((TPanel**)&this->instruction);
    this->delete_panel((TPanel**)&this->win_loss_text);
    this->delete_panel((TPanel**)&this->time);
    this->delete_panel((TPanel**)&this->summary_text_bar);
    this->delete_panel((TPanel**)&this->instruction_bar);
    this->delete_panel((TPanel**)&this->win_loss_text_bar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->backButton);
    this->delete_panel((TPanel**)&this->backButton2);
    this->delete_panel((TPanel**)&this->timelineButton);
    this->delete_panel((TPanel**)&this->aftermathButton);
    this->delete_panel((TPanel**)&this->restartButton);
    this->delete_panel((TPanel**)&this->close_button);
}

long TribeAchievementsScreen::action(TPanel* panel, long action_id, ulong param_3, ulong param_4) {
    if (action_id == 1 && panel != nullptr && panel == (TPanel*)this->okButton) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        if (game != nullptr) {
            game->start_menu();
        }
        return 1;
    }

    return TScreenPanel::action(panel, action_id, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TribeAchievementsScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeAchievementsScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeAchievementsScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeAchievementsScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeAchievementsScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeAchievementsScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeAchievementsScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeAchievementsScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeAchievementsScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeAchievementsScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeAchievementsScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeAchievementsScreen::draw() { TScreenPanel::draw(); }
void TribeAchievementsScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeAchievementsScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeAchievementsScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeAchievementsScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeAchievementsScreen::paint() { TScreenPanel::paint(); }
long TribeAchievementsScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::handle_idle() { return TScreenPanel::handle_idle(); }
long TribeAchievementsScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeAchievementsScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeAchievementsScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeAchievementsScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeAchievementsScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeAchievementsScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeAchievementsScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeAchievementsScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeAchievementsScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeAchievementsScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeAchievementsScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeAchievementsScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeAchievementsScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeAchievementsScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeAchievementsScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeAchievementsScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeAchievementsScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeAchievementsScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeAchievementsScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeAchievementsScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeAchievementsScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeAchievementsScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeAchievementsScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeAchievementsScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeAchievementsScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeAchievementsScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeAchievementsScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeAchievementsScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeAchievementsScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeAchievementsScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeAchievementsScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeAchievementsScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeAchievementsScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeAchievementsScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

