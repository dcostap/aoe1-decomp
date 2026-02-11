#include "../include/TribeSPMenuScreen.h"
#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/TribeMPSetupScreen.h"
#include "../include/TribeSelectScenarioScreen.h"
#include "../include/TribeLoadSavedGameScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TPanelSystem.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

#include <stdio.h>
#include <string.h>

namespace {

void sp_enable_input() {
    if (!rge_base_game) return;
    rge_base_game->enable_input();
}

void sp_popup_resid(TribeSPMenuScreen* owner, int resid, const char* fallback) {
    char text[512];
    text[0] = '\0';
    if (owner) {
        owner->get_string(resid, text, sizeof(text));
    } else if (rge_base_game) {
        rge_base_game->get_string(resid, text, sizeof(text));
    }

    if (text[0] == '\0') {
        if (fallback && fallback[0] != '\0') {
            strncpy(text, fallback, sizeof(text) - 1);
            text[sizeof(text) - 1] = '\0';
        } else {
            sprintf(text, "Missing UI string %d", resid);
        }
    }

    HWND wnd = (rge_base_game && rge_base_game->prog_window) ? (HWND)rge_base_game->prog_window : NULL;
    MessageBoxA(wnd, text, "Age of Empires", MB_OK | MB_ICONINFORMATION);
}

} // namespace

TribeSPMenuScreen::TribeSPMenuScreen() : TScreenPanel((char*)"Single Player Menu") {
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("SP ctor: begin this=%p", this);
CUSTOM_DEBUG_END

    this->title = nullptr;
    for (int i = 0; i < 7; ++i) this->button[i] = nullptr;
    this->close_button = nullptr;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    rge_base_game->setSinglePlayerGame(1);
    rge_base_game->setScenarioName((char*)"");

    if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr2", 0xc384, 1)) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("SP ctor: TScreenPanel::setup failed");
CUSTOM_DEBUG_END
        this->error_code = 1;
        return;
    }
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("SP ctor: setup ok");
CUSTOM_DEBUG_END

    this->set_ideal_size(0x280, 0x1e0);
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("SP ctor: set_ideal_size ok");
CUSTOM_DEBUG_END

    if (!this->create_text((TPanel*)this, &this->title, 0x2404, 0x14, 0x14, 0x258, 0x1e, 1, 1, 0, 0)) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("SP ctor: create title failed");
CUSTOM_DEBUG_END
        this->error_code = 1;
        return;
    }
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("SP ctor: title ok title=%p", this->title);
CUSTOM_DEBUG_END

    int y = 0x76;
    for (int i = 0; i < 6; ++i) {
        if (!this->create_button((TPanel*)this, &this->button[i], (char*)"", (char*)0, 0xaa, y, 0x12c, 0x28, 0, 0, 0)) {
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT("SP ctor: button[%d] create failed", i);
CUSTOM_DEBUG_END
            this->error_code = 1;
            return;
        }
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("SP ctor: button[%d] ok ptr=%p", i, this->button[i]);
CUSTOM_DEBUG_END
        y += 0x32;
    }

    if (!this->create_button((TPanel*)this, &this->close_button, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0)) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("SP ctor: close_button create failed");
CUSTOM_DEBUG_END
        this->error_code = 1;
        return;
    }
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("SP ctor: close_button ok ptr=%p", this->close_button);
CUSTOM_DEBUG_END

    this->close_button->set_active(1);
    this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, (TPanel*)0, (TPanel*)0, (TPanel*)0, (TPanel*)0);

    this->button[0]->set_text(0, 0x240a);
    this->button[1]->set_text(0, 0x2408);
    this->button[2]->set_text(0, 0x240b);
    this->button[3]->set_text(0, 0x2405);
    this->button[4]->set_text(0, 0x2407);
    this->button[5]->set_text(0, 0x2409);

    this->button[5]->hotkey = 0x1b;
    this->button[5]->hotkey_shift = 0;

    this->set_curr_child((TPanel*)this->button[0]);

    TPanel* tab_list[6];
    for (int i = 0; i < 6; ++i) {
        tab_list[i] = (TPanel*)this->button[i];
    }
    // Source of truth: scr_sing.cpp.decomp - skip first button in tab order
    // but pass count as 6 (the original passes all 6 buttons starting from index 1)
    this->set_tab_order(tab_list + 1, 5);

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("SP ctor: completed");
CUSTOM_DEBUG_END
}

TribeSPMenuScreen::~TribeSPMenuScreen() {
    // Source of truth: scr_sing.cpp.decomp @ 0x004B6C00
    // Delete all child panels before base destructor runs
    this->delete_panel((TPanel**)&this->title);
    for (int i = 0; i < 7; ++i) {
        this->delete_panel((TPanel**)&this->button[i]);
    }
    this->delete_panel((TPanel**)&this->close_button);
}

long TribeSPMenuScreen::handle_idle() {
    // Source of truth: scr_sing.cpp.decomp @ 0x004B6C90
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeSPMenuScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 && (param_2 == 1)) {
        if ((TButtonPanel*)param_1 == this->button[0]) {
            rge_base_game->setCampaignGame(0);
            rge_base_game->setSavedGame(0);
            rge_base_game->setScenarioGame(0);
            ((TRIBE_Game*)rge_base_game)->setDeathMatch(0);
            ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
            rge_base_game->disable_input();

            TribeMPSetupScreen* setup = new TribeMPSetupScreen();
            if (setup && setup->error_code == 0) {
                panel_system->setCurrentPanel((TPanel*)setup, 0);
                panel_system->destroyPanel("Single_Player_Menu");
            } else {
                if (setup) delete setup;
                sp_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[2]) {
            rge_base_game->setCampaignGame(0);
            rge_base_game->setSavedGame(0);
            rge_base_game->setScenarioGame(0);
            ((TRIBE_Game*)rge_base_game)->setDeathMatch(1);
            ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
            rge_base_game->disable_input();

            TribeMPSetupScreen* setup = new TribeMPSetupScreen();
            if (setup && setup->error_code == 0) {
                panel_system->setCurrentPanel((TPanel*)setup, 0);
                panel_system->destroyPanel("Single_Player_Menu");
            } else {
                if (setup) delete setup;
                sp_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[3]) {
            rge_base_game->setCampaignGame(0);
            rge_base_game->setSavedGame(0);
            rge_base_game->setScenarioGame(1);
            ((TRIBE_Game*)rge_base_game)->setDeathMatch(0);
            ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
            rge_base_game->disable_input();

            TribeSelectScenarioScreen* scenario = new TribeSelectScenarioScreen();
            if (scenario && scenario->error_code == 0) {
                panel_system->setCurrentPanel((TPanel*)scenario, 0);
                panel_system->destroyPanel("Single_Player_Menu");
            } else {
                if (scenario) delete scenario;
                sp_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[4]) {
            rge_base_game->disable_input();

            TribeLoadSavedGameScreen* load_screen = new TribeLoadSavedGameScreen();
            if (load_screen && load_screen->error_code == 0) {
                panel_system->setCurrentPanel((TPanel*)load_screen, 0);
                panel_system->destroyPanel("Single_Player_Menu");
            } else {
                if (load_screen) delete load_screen;
                sp_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[1]) {
            rge_base_game->disable_input();

            // TODO(accuracy): source of truth uses `RGE_Game_Info::get_people_list` and then enters
            // `TRIBE_Screen_Name` or `TRIBE_Dialog_Name`. That path is still unimplemented here.
            sp_popup_resid(this, 0x2408, "Campaign menu is not implemented yet.");
            sp_enable_input();
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[5]) {
            rge_base_game->disable_input();

            TRIBE_Screen_Main_Menu* menu = new TRIBE_Screen_Main_Menu();
            if (menu && menu->error_code == 0) {
                panel_system->setCurrentPanel((TPanel*)menu, 0);
                panel_system->destroyPanel("Single_Player_Menu");
            } else {
                if (menu) delete menu;
                sp_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->close_button) {
            rge_base_game->close();
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TribeSPMenuScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeSPMenuScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeSPMenuScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeSPMenuScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeSPMenuScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeSPMenuScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeSPMenuScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeSPMenuScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeSPMenuScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeSPMenuScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeSPMenuScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeSPMenuScreen::draw() { TScreenPanel::draw(); }
void TribeSPMenuScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeSPMenuScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeSPMenuScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeSPMenuScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeSPMenuScreen::paint() { TScreenPanel::paint(); }
long TribeSPMenuScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeSPMenuScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeSPMenuScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSPMenuScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeSPMenuScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeSPMenuScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeSPMenuScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeSPMenuScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeSPMenuScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSPMenuScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeSPMenuScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeSPMenuScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSPMenuScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeSPMenuScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeSPMenuScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeSPMenuScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeSPMenuScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeSPMenuScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeSPMenuScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeSPMenuScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeSPMenuScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeSPMenuScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeSPMenuScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeSPMenuScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeSPMenuScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeSPMenuScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeSPMenuScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSPMenuScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSPMenuScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSPMenuScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSPMenuScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSPMenuScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSPMenuScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSPMenuScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeSPMenuScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeSPMenuScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSPMenuScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeSPMenuScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSPMenuScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeSPMenuScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSPMenuScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeSPMenuScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
