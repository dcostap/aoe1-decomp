#include "../include/TribeEndScreen.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TPanelSystem.h"
#include "../include/TPicturePanel.h"
#include "../include/TTextPanel.h"
#include "../include/TribeAchievementsScreen.h"
#include "../include/globals.h"

#include <string.h>

// Fully verified. Source of truth: scr_end.cpp.decomp @ 0x004936D0
TribeEndScreen::TribeEndScreen(char* title_text, char** text_list, int text_count)
    : TScreenPanel((char*)"End Screen") {
    this->background = nullptr;
    this->title = nullptr;
    this->text = nullptr;
    this->okButton = nullptr;

    if (this->TScreenPanel::setup(rge_base_game->draw_area, (char*)0, 0, 1) == 0) {
        this->error_code = 1;
        return;
    }

    const int screen_wid = rge_base_game->draw_area->Width;
    const char* bg_name = (screen_wid < 800) ? "bgA640" : ((screen_wid < 1024) ? "bgA800" : "bgA1024");

    char backgroundName[16];
    strcpy(backgroundName, bg_name);

    this->background = new TPicturePanel();
    if (this->background == nullptr) {
        this->error_code = 1;
        return;
    }

    if (this->background->setup(rge_base_game->draw_area, (TPanel*)this, 0, 0, 0, 0, backgroundName, -1, 0, 1) == 0) {
        this->error_code = 1;
        return;
    }

    // Center/stretch to the current screen rect (truth uses Center positioning mode = 2).
    this->background->set_positioning(TPanel::PositionMode::Center,
        0, 0, 0, 0,
        this->pnl_wid, this->pnl_wid,
        this->pnl_hgt, this->pnl_hgt,
        nullptr, nullptr, nullptr, nullptr);

    RGE_Font* title_font = rge_base_game->get_font(1);
    this->title = new TTextPanel();
    if (this->title == nullptr) {
        this->error_code = 1;
        return;
    }

    if (this->title->setup(
            rge_base_game->draw_area,
            (TPanel*)this->background,
            (this->pnl_wid * 0x14) / 0x280,
            (this->pnl_hgt * 0x14) / 0x1e0,
            (this->pnl_wid * 600) / 0x280,
            (this->pnl_hgt * 0x1e) / 0x1e0,
            title_font ? title_font->font : nullptr,
            title_font ? title_font->font_wid : 0,
            title_font ? title_font->font_hgt : 0,
            (char*)0,
            0,
            '\0',
            0,
            '\0',
            0,
            title_text) == 0) {
        this->error_code = 1;
        return;
    }

    this->text = new TTextPanel();
    if (this->text == nullptr) {
        this->error_code = 1;
        return;
    }

    RGE_Font* body_font = rge_base_game->get_font(0xb);
    if (this->text->setup(
            rge_base_game->draw_area,
            (TPanel*)this->background,
            (this->pnl_wid * 0x14) / 0x280,
            (this->pnl_hgt * 0x46) / 0x1e0,
            (this->pnl_wid * 600) / 0x280,
            (this->pnl_hgt * 0x154) / 0x1e0,
            body_font ? body_font->font : nullptr,
            body_font ? body_font->font_wid : 0,
            body_font ? body_font->font_hgt : 0,
            (char*)0,
            0,
            '\0',
            0,
            '\0',
            0,
            (char*)0) == 0) {
        this->error_code = 1;
        return;
    }

    this->text->set_text(text_list, (short)text_count);
    this->text->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignCenter);
    this->text->scroll('\x06', 0, 1);

    TDigital* snd = rge_base_game->get_sound(0);
    RGE_Font* btn_font = rge_base_game->get_font(0);
    this->okButton = new TButtonPanel();
    if (this->okButton == nullptr) {
        this->error_code = 1;
        return;
    }

    this->okButton->setup(
        rge_base_game->draw_area,
        (TPanel*)this->background,
        (this->pnl_wid * 0xaa) / 0x280,
        (this->pnl_hgt * 0x1ae) / 0x1e0,
        (this->pnl_wid * 300) / 0x280,
        (this->pnl_hgt * 0x28) / 0x1e0,
        TButtonPanel::DrawType::DrawTextA,
        snd,
        TButtonPanel::NotifyType::NotifyAction,
        0);

    this->okButton->set_text_info((char*)"OK",
        btn_font ? btn_font->font : nullptr,
        btn_font ? btn_font->font_wid : 0,
        btn_font ? btn_font->font_hgt : 0,
        -1, -1);

    this->set_curr_child((TPanel*)this->background);
    this->background->set_curr_child((TPanel*)this->text);
}

// Fully verified. Source of truth: scr_end.cpp.decomp @ 0x00493C00
TribeEndScreen::~TribeEndScreen() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->text);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->background);
}

// Fully verified. Source of truth: scr_end.cpp.decomp @ 0x00493C90
long TribeEndScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 != nullptr && param_2 == 1) {
        TribeAchievementsScreen* ach = new TribeAchievementsScreen(this->get_string(0x269e), 1);
        (void)ach;

        if (panel_system != nullptr) {
            panel_system->setCurrentPanel((char*)"Achievements Screen", 0);
            panel_system->destroyPanel((char*)"End Screen");
        }
        return 1;
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TribeEndScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeEndScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeEndScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeEndScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeEndScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeEndScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeEndScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeEndScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeEndScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeEndScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeEndScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeEndScreen::draw() { TScreenPanel::draw(); }
void TribeEndScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeEndScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeEndScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeEndScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeEndScreen::paint() { TScreenPanel::paint(); }
long TribeEndScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeEndScreen::handle_idle() { return TScreenPanel::handle_idle(); }
long TribeEndScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeEndScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeEndScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeEndScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeEndScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeEndScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeEndScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeEndScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeEndScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeEndScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeEndScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeEndScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeEndScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeEndScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeEndScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeEndScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeEndScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeEndScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeEndScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeEndScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeEndScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeEndScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeEndScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeEndScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeEndScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeEndScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeEndScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeEndScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeEndScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeEndScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeEndScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeEndScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeEndScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeEndScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeEndScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeEndScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeEndScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeEndScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeEndScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeEndScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeEndScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeEndScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeEndScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

