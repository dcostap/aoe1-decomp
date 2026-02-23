#include "../include/TRIBE_Screen_Sed_Menu.h"

#include "../include/TRIBE_Campaign_Editor_Screen.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/TRIBE_Screen_Sed_Open.h"
#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/globals.h"

// Fully verified. Source of truth: scr_sedm.cpp.decomp @ 0x004B2EF0
TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu() : TScreenPanel((char*)"Scenario Editor Menu") {
    this->title = nullptr;
    for (int i = 0; i < 4; ++i) {
        this->button[i] = nullptr;
    }
    this->close_button = nullptr;

    if (rge_base_game == nullptr) {
        this->error_code = 1;
        return;
    }

    long ok = TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr4", 0xc386, 1);
    if (ok == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1e0);
    if (this->create_text((TPanel*)this, &this->title, 0x242d, 0x14, 0x14, 600, 0x1e, 1, 1, 0, 0) == 0) {
        return;
    }

    long y = 0xaa;
    for (int i = 0; i < 4; ++i) {
        if (this->create_button((TPanel*)this, &this->button[i], (char*)"", (char*)nullptr, 0xaa, y, 300, 0x28, 0, 0, 0) == 0) {
            return;
        }
        y += 0x32;
    }

    if (this->create_button((TPanel*)this, &this->close_button, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0) != 0) {
        this->close_button->set_active(1);
        this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, nullptr, nullptr, nullptr, nullptr);
    }

    if (this->button[0] != nullptr) this->button[0]->set_text(0, 0x242e);
    if (this->button[1] != nullptr) this->button[1]->set_text(0, 0x242f);
    if (this->button[2] != nullptr) this->button[2]->set_text(0, 0x2431);
    if (this->button[3] != nullptr) this->button[3]->set_text(0, 0x2430);

    if (this->button[3] != nullptr) {
        this->button[3]->hotkey = 0x1b;
        this->button[3]->hotkey_shift = 0;
    }

    this->set_tab_order((TPanel**)this->button, 4);
    this->set_curr_child((TPanel*)this->button[0]);
}

// Fully verified. Source of truth: scr_sedm.cpp.decomp @ 0x004B3110
TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu() {
    this->delete_panel((TPanel**)&this->title);
    for (int i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->button[i]);
    }
    this->delete_panel((TPanel**)&this->close_button);
}

// Fully verified. Source of truth: scr_sedm.cpp.decomp @ 0x004B31A0
long TRIBE_Screen_Sed_Menu::handle_idle() {
    if (rge_base_game != nullptr && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

// Fully verified. Source of truth: scr_sedm.cpp.decomp @ 0x004B31D0
long TRIBE_Screen_Sed_Menu::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 != nullptr && param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->button[0]) {
            if (rge_base_game != nullptr) {
                ((TRIBE_Game*)rge_base_game)->start_scenario_editor(nullptr, 0);
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[1]) {
            new TRIBE_Screen_Sed_Open();
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Scenario Editor Open", 0);
                panel_system->destroyPanel((char*)"Scenario Editor Menu");
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[2]) {
            new TRIBE_Campaign_Editor_Screen();
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Campaign Editor Screen", 0);
                panel_system->destroyPanel((char*)"Scenario Editor Menu");
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->button[3]) {
            if (rge_base_game != nullptr) {
                rge_base_game->disable_input();
            }
            new TRIBE_Screen_Main_Menu();
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Main Menu", 0);
                panel_system->destroyPanel((char*)"Scenario Editor Menu");
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->close_button) {
            if (rge_base_game != nullptr) {
                rge_base_game->close();
            }
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TRIBE_Screen_Sed_Menu::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Sed_Menu::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Sed_Menu::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Menu::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Sed_Menu::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Sed_Menu::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Sed_Menu::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Menu::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Sed_Menu::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Menu::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Sed_Menu::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Sed_Menu::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Sed_Menu::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Sed_Menu::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Menu::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Sed_Menu::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Menu::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Sed_Menu::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Sed_Menu::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Sed_Menu::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Menu::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Sed_Menu::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Sed_Menu::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Sed_Menu::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Sed_Menu::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Sed_Menu::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Menu::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Menu::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Menu::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Menu::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Menu::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Sed_Menu::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Sed_Menu::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Sed_Menu::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Sed_Menu::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Sed_Menu::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Sed_Menu::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Menu::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Sed_Menu::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Sed_Menu::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Sed_Menu::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Sed_Menu::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Sed_Menu::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Sed_Menu::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Menu::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Menu::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Menu::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Menu::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Menu::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Menu::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Menu::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Sed_Menu::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Sed_Menu::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed_Menu::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Sed_Menu::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Menu::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Sed_Menu::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed_Menu::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Sed_Menu::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

