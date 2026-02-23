#include "../include/TribeSelectTribeScreen.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TPanelSystem.h"
#include "../include/TPicturePanel.h"
#include "../include/TTextPanel.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>

// Fully verified. Source of truth: scr_trb.cpp.decomp @ 0x004B75A0
TribeSelectTribeScreen::TribeSelectTribeScreen()
    : TScreenPanel((char*)"Select Tribe Screen") {
    this->background = nullptr;
    this->title = nullptr;
    this->tribeText = nullptr;
    for (int i = 0; i < 9; ++i) {
        this->tribeButton[i] = nullptr;
    }
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->screenText = nullptr;
    this->numLines = 0;

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

    this->title->setup(
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
        (char*)"Civilization Selection");

    TDigital* buttonSound = rge_base_game->get_sound(0);
    RGE_Font* font = rge_base_game->get_font(0);

    int secondWidth = 0;
    int secondHeight = 0;
    int i = 0;
    do {
        this->tribeButton[i] = new TButtonPanel();
        if (this->tribeButton[i] == nullptr) {
            this->error_code = 1;
            return;
        }

        this->tribeButton[i]->setup(
            rge_base_game->draw_area,
            (TPanel*)this->background,
            (this->pnl_wid * 0x14) / 0x280 + (secondWidth * this->pnl_wid) / 0x280,
            (this->pnl_hgt * 0x32) / 0x1e0 + (secondHeight * this->pnl_hgt * 0x73) / 0x1e0,
            (this->pnl_wid * 200) / 0x280,
            (this->pnl_hgt * 0x6e) / 0x1e0,
            TButtonPanel::DrawType::DrawTextA,
            buttonSound,
            TButtonPanel::NotifyType::NotifyAction,
            0);

        this->tribeButton[i]->set_text_info(
            this->tribeName(i),
            font ? font->font : nullptr,
            font ? font->font_wid : 0,
            font ? font->font_hgt : 0,
            -1,
            -1);

        if ((i == 2) || (i == 5)) {
            secondHeight = -1;
            secondWidth = secondWidth + 200;
        }

        i = i + 1;
        secondHeight = secondHeight + 1;
    } while (i < 9);

    RGE_Font* body_font = rge_base_game->get_font(0xb);
    this->tribeText = new TTextPanel();
    if (this->tribeText == nullptr) {
        this->error_code = 1;
        return;
    }

    this->tribeText->setup(
        rge_base_game->draw_area,
        (TPanel*)this->background,
        (this->pnl_wid * 0x14) / 0x280,
        (this->pnl_hgt * 400) / 0x1e0,
        (this->pnl_wid * 0x1fe) / 0x280,
        (this->pnl_hgt * 0x3c) / 0x1e0,
        body_font ? body_font->font : nullptr,
        body_font ? body_font->font_wid : 0,
        body_font ? body_font->font_hgt : 0,
        (char*)0,
        0,
        '\0',
        0,
        '\0',
        0,
        (char*)"");

    this->tribeText->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignWordwrap);

    this->okButton = new TButtonPanel();
    if (this->okButton == nullptr) {
        this->error_code = 1;
        return;
    }

    this->okButton->setup(
        rge_base_game->draw_area,
        (TPanel*)this->background,
        (this->pnl_wid * 500) / 0x280,
        (this->pnl_hgt * 400) / 0x1e0,
        (this->pnl_wid * 0x78) / 0x280,
        (this->pnl_hgt * 0x1e) / 0x1e0,
        TButtonPanel::DrawType::DrawTextA,
        buttonSound,
        TButtonPanel::NotifyType::NotifyAction,
        0);

    this->okButton->set_text_info(
        (char*)"Previous Screen",
        body_font ? body_font->font : nullptr,
        body_font ? body_font->font_wid : 0,
        body_font ? body_font->font_hgt : 0,
        -1,
        -1);

    this->cancelButton = new TButtonPanel();
    if (this->cancelButton == nullptr) {
        this->error_code = 1;
        return;
    }

    this->cancelButton->setup(
        rge_base_game->draw_area,
        (TPanel*)this->background,
        (this->pnl_wid * 500) / 0x280,
        (this->pnl_hgt * 0x1b8) / 0x1e0,
        (this->pnl_wid * 0x78) / 0x280,
        (this->pnl_hgt * 0x1e) / 0x1e0,
        TButtonPanel::DrawType::DrawTextA,
        buttonSound,
        TButtonPanel::NotifyType::NotifyAction,
        0);

    this->cancelButton->set_text_info(
        (char*)"Cancel",
        body_font ? body_font->font : nullptr,
        body_font ? body_font->font_wid : 0,
        body_font ? body_font->font_hgt : 0,
        -1,
        -1);

    this->set_curr_child((TPanel*)this->background);
    this->background->set_curr_child((TPanel*)this->tribeButton[0]);
    this->fillTribeText(0);

    TPanel* tabList[10];
    for (int j = 0; j < 9; ++j) {
        tabList[j] = (TPanel*)this->tribeButton[j];
    }
    tabList[9] = (TPanel*)this->okButton;
    this->set_tab_order((TPanel**)tabList, 10);
}

// Fully verified. Source of truth: scr_trb.cpp.decomp @ 0x004B7DF0
TribeSelectTribeScreen::~TribeSelectTribeScreen() {
    if (this->title != nullptr) {
        delete this->title;
    }
    if (this->tribeText != nullptr) {
        delete this->tribeText;
    }
    for (int i = 0; i < 9; ++i) {
        if (this->tribeButton[i] != nullptr) {
            delete this->tribeButton[i];
        }
    }
    if (this->okButton != nullptr) {
        delete this->okButton;
    }
    if (this->cancelButton != nullptr) {
        delete this->cancelButton;
    }

    if (0 < this->numLines) {
        for (int i = 0; i < this->numLines; ++i) {
            free(this->screenText[i]);
        }
    }
    free(this->screenText);
}

// Fully verified. Source of truth: scr_trb.cpp.decomp @ 0x004B7EE0
long TribeSelectTribeScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (((TButtonPanel*)param_1 == this->okButton) || ((TButtonPanel*)param_1 == this->cancelButton)) {
        if (param_2 == 1) {
            panel_system->setCurrentPanel((char*)"MP Setup Screen", 0);
            panel_system->destroyPanel((char*)"Select Tribe Screen");
            return 1;
        }
    } else if (param_2 == 1) {
        for (int i = 0; i < 9; ++i) {
            if ((TButtonPanel*)param_1 == this->tribeButton[i]) {
                this->fillTribeText(i);
                return 1;
            }
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: scr_trb.cpp.decomp @ 0x004B7F70
void TribeSelectTribeScreen::fillTribeText(int tribe_id) {
    if (this->tribeText == nullptr) {
        return;
    }

    switch (tribe_id) {
    case 0:
        this->tribeText->set_text((char*)"Assyrian information here.");
        break;
    case 1:
        this->tribeText->set_text((char*)"Babylonian information here.");
        break;
    case 2:
        this->tribeText->set_text((char*)"Egyptian information here.");
        break;
    case 3:
        this->tribeText->set_text((char*)"Greek information here.");
        break;
    case 4:
        this->tribeText->set_text((char*)"Hittite information here.");
        break;
    case 5:
        this->tribeText->set_text((char*)"Isrealite information here.");
        break;
    case 6:
        this->tribeText->set_text((char*)"Minoan information here.");
        break;
    case 7:
        this->tribeText->set_text((char*)"Phoenician information here.");
        break;
    case 8:
        this->tribeText->set_text((char*)"Sumerian information here.");
        break;
    default:
        break;
    }

    this->tribeText->scroll('\x06', 0, 1);
}

// Fully verified. Source of truth: scr_trb.cpp.decomp @ 0x004B8070
char* TribeSelectTribeScreen::tribeName(int tribe_id) {
    switch (tribe_id) {
    case 0:
        return (char*)"Assyrian";
    case 1:
        return (char*)"Babylonian";
    case 2:
        return (char*)"Egyptian";
    case 3:
        return (char*)"Greek";
    case 4:
        return (char*)"Hittite";
    case 5:
        return (char*)"Isrealite";
    case 6:
        return (char*)"Minoan";
    case 7:
        return (char*)"Phoenician";
    case 8:
        return (char*)"Sumerian";
    default:
        return (char*)"No Culture";
    }
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TribeSelectTribeScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeSelectTribeScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeSelectTribeScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeSelectTribeScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeSelectTribeScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeSelectTribeScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeSelectTribeScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeSelectTribeScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeSelectTribeScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeSelectTribeScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeSelectTribeScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeSelectTribeScreen::draw() { TScreenPanel::draw(); }
void TribeSelectTribeScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeSelectTribeScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeSelectTribeScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeSelectTribeScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeSelectTribeScreen::paint() { TScreenPanel::paint(); }
long TribeSelectTribeScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::handle_idle() { return TScreenPanel::handle_idle(); }
long TribeSelectTribeScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeSelectTribeScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeSelectTribeScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectTribeScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeSelectTribeScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeSelectTribeScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeSelectTribeScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeSelectTribeScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeSelectTribeScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectTribeScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectTribeScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectTribeScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSelectTribeScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectTribeScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeSelectTribeScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeSelectTribeScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeSelectTribeScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeSelectTribeScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeSelectTribeScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeSelectTribeScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeSelectTribeScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeSelectTribeScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeSelectTribeScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeSelectTribeScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeSelectTribeScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeSelectTribeScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeSelectTribeScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectTribeScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectTribeScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSelectTribeScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSelectTribeScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectTribeScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectTribeScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectTribeScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeSelectTribeScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeSelectTribeScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSelectTribeScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeSelectTribeScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSelectTribeScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeSelectTribeScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSelectTribeScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeSelectTribeScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

