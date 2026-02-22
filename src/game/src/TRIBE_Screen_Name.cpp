#include "../include/TRIBE_Screen_Name.h"
#include "../include/TRIBE_Dialog_Name.h"
#include "../include/TRIBE_Screen_Campaign_Selection.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_Info.h"
#include "../include/TButtonPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TTextPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void screen_name_init_vars(TRIBE_Screen_Name* this_) {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A67C0
    this_->title = nullptr;
    this_->name_text = nullptr;
    this_->name_list = nullptr;
    this_->name_scrollbar = nullptr;
    this_->new_button = nullptr;
    this_->remove_button = nullptr;
    this_->ok_button = nullptr;
    this_->cancel_button = nullptr;
    this_->close_button = nullptr;
}

static void screen_name_get_player_names(TRIBE_Screen_Name* this_) {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A6800
    if (!this_->name_list) return;
    this_->name_list->empty_list();

    char** players = nullptr;
    long curr_index = 0;
    const long count = (rge_base_game && rge_base_game->player_game_info)
        ? rge_base_game->player_game_info->get_people_list(&players, &curr_index)
        : 0;

    if (count != 0 && players) {
        this_->name_list->handle_mouse_input = 1;
        for (long i = 0; i < count; ++i) {
            this_->name_list->append_line(players[i], i);
        }

        const long line = this_->name_list->get_line(curr_index);
        this_->name_list->set_line(line);

        for (long i = 0; i < count; ++i) {
            free(players[i]);
        }
        free(players);
    }
}

static void screen_name_setup_tab_order(TRIBE_Screen_Name* this_) {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A68C0
    const int lines = this_->name_list ? this_->name_list->numberLines() : 0;
    const int empty = (lines == 0);

    if (this_->remove_button) {
        this_->remove_button->disabled = empty ? 1 : 0;
        this_->remove_button->set_redraw(TPanel::RedrawMode::RedrawFull);
    }
    if (this_->ok_button) {
        this_->ok_button->disabled = empty ? 1 : 0;
        this_->ok_button->set_redraw(TPanel::RedrawMode::RedrawFull);
    }

    TPanel* tab_list[6];
    int count = 0;
    tab_list[count++] = (TPanel*)this_->name_list;
    tab_list[count++] = (TPanel*)this_->new_button;
    if (!empty) {
        tab_list[count++] = (TPanel*)this_->remove_button;
        tab_list[count++] = (TPanel*)this_->ok_button;
    }
    tab_list[count++] = (TPanel*)this_->cancel_button;

    this_->set_tab_order(tab_list, (short)count);

    if (empty) {
        this_->set_curr_child((TPanel*)this_->new_button);
    } else {
        this_->set_curr_child((TPanel*)this_->name_list);
    }
}

TRIBE_Screen_Name::TRIBE_Screen_Name() : TScreenPanel((char*)"Name Selection Screen") {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A63D0
    screen_name_init_vars(this);

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr2", 0xC384, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    if (!this->create_text((TPanel*)this, &this->title, 0x29FE, 0x14, 0x14, 600, 0x1e, 1, 1, 0, 0)) return;
    if (!this->create_text((TPanel*)this, &this->name_text, 0x29FF, 0x3c, 0x50, 0x8c, 0x14, 4, 0, 0, 0)) return;
    if (!this->create_list((TPanel*)this, &this->name_list, 0x3c, 100, 0x14a, 300, 0xb)) return;
    if (!this->create_auto_scrollbar(&this->name_scrollbar, (TTextPanel*)this->name_list, 0x14)) return;

    this->name_scrollbar->set_help_info(0x765C, -1);

    if (!this->create_button((TPanel*)this, &this->new_button, 0x2A00, 0, 400, 100, 0xb4, 0x1e, 0, 0, 0)) return;
    this->new_button->set_help_info(0x765D, -1);

    if (!this->create_button((TPanel*)this, &this->remove_button, 0x2A01, 0, 400, 0x8c, 0xb4, 0x1e, 0, 0, 0)) return;
    this->remove_button->set_help_info(0x765E, -1);

    if (!this->create_button((TPanel*)this, &this->ok_button, 0xFA1, 0, 0x46, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) return;
    this->ok_button->set_help_info(0x7531, -1);

    if (!this->create_button((TPanel*)this, &this->cancel_button, 0xFA2, 0, 0x14a, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) return;
    this->cancel_button->set_help_info(0x7532, -1);
    this->cancel_button->hotkey = 0x1B;
    this->cancel_button->hotkey_shift = 0;

    // Close button ("X")
    if (!this->create_button((TPanel*)this, &this->close_button, 0x3EA, 0, 0, 0, 0, 0, -1, -1, 0)) return;

    screen_name_setup_tab_order(this);
    screen_name_get_player_names(this);
    this->started_input = 0;
}

TRIBE_Screen_Name::~TRIBE_Screen_Name() {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A66E0
    if (panel_system) {
        panel_system->setCurrentPanel((char*)"New Name Dialog", 0);
    }

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->name_text);
    this->delete_panel((TPanel**)&this->name_list);
    this->delete_panel((TPanel**)&this->name_scrollbar);
    this->delete_panel((TPanel**)&this->new_button);
    this->delete_panel((TPanel**)&this->remove_button);
    this->delete_panel((TPanel**)&this->ok_button);
    this->delete_panel((TPanel**)&this->cancel_button);
    this->delete_panel((TPanel**)&this->close_button);
}

long TRIBE_Screen_Name::handle_idle() {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A6980
    if (rge_base_game && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TRIBE_Screen_Name::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Fully verified. Source of truth: scr_name.cpp.decomp @ 0x004A69B0
    (void)param_3;
    (void)param_4;

    if (param_1) {
        if ((TButtonPanel*)param_1 == this->ok_button && param_2 == 1) {
            const long line = this->name_list ? this->name_list->get_line() : -1;
            if (line != -1) {
                if (rge_base_game) rge_base_game->disable_input();
                if (rge_base_game && rge_base_game->player_game_info) {
                    const long id = this->name_list->get_id();
                    rge_base_game->player_game_info->set_current_person(id);
                }
                TRIBE_Screen_Campaign_Selection* scr = new TRIBE_Screen_Campaign_Selection();
                if (panel_system) {
                    if (scr) panel_system->add_panel((TPanel*)scr);
                    panel_system->setCurrentPanel((char*)"Campaign Selection Screen", 0);
                    panel_system->destroyPanel((char*)"Name Selection Screen");
                }
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->cancel_button && param_2 == 1) {
            if (rge_base_game) rge_base_game->disable_input();
            TribeSPMenuScreen* menu = new TribeSPMenuScreen();
            if (panel_system) {
                if (menu) panel_system->add_panel((TPanel*)menu);
                panel_system->setCurrentPanel((char*)"Single Player Menu", 0);
                panel_system->destroyPanel((char*)"Name Selection Screen");
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->close_button) {
            if (rge_base_game) rge_base_game->close();
            return 1;
        }

        if ((TListPanel*)param_1 == this->name_list && param_2 == 3) {
            return this->action((TPanel*)this->ok_button, 1, 0, 0);
        }

        if ((TButtonPanel*)param_1 == this->new_button && param_2 == 1) {
            (void)new TRIBE_Dialog_Name((TScreenPanel*)this);
            if (panel_system) {
                panel_system->setCurrentPanel((char*)"New Name Dialog", 0);
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->remove_button && param_2 == 1) {
            const long line = this->name_list ? this->name_list->get_line() : -1;
            if (line != -1) {
                char str[256];
                const char* name = this->name_list->get_text(line);
                char* fmt = this->get_string(0x2A02); // "Are you sure you want to remove player %s?"
                if (!fmt) fmt = (char*)"%s";
                sprintf(str, fmt, name ? name : "");
                this->popupYesNoDialog(str, (char*)0, 0x1c2, 100);
                return 1;
            }
        }

        const char* panel_name = param_1->panelName();
        if (panel_name && strcmp(panel_name, "New Name Dialog") == 0) {
            if (param_2 == 1) {
                screen_name_get_player_names(this);
            }
            if (panel_system) {
                panel_system->setCurrentPanel((char*)"Name Selection Screen", 0);
                panel_system->destroyPanel((char*)"New Name Dialog");
            }
            screen_name_setup_tab_order(this);
            return 1;
        }

        if (panel_name && strcmp(panel_name, "YesNoDialog") == 0) {
            if (param_2 == 0) {
                const long line = this->name_list ? this->name_list->get_line() : -1;
                if (line != -1 && rge_base_game && rge_base_game->player_game_info) {
                    const long id = this->name_list->get_id(line);
                    rge_base_game->player_game_info->remove_player(id);
                    screen_name_get_player_names(this);
                }
            }
            if (panel_system) {
                panel_system->destroyPanel((char*)"YesNoDialog");
            }
            screen_name_setup_tab_order(this);
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Screen_Name::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Name::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Name::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Name::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Name::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Name::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Name::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Name::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Name::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Name::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Name::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Name::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Name::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Name::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Name::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Name::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Name::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Name::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Name::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Name::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Name::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Name::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Name::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Name::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Name::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Name::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Name::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Name::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Name::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Name::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Name::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Name::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Name::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Name::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Name::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Name::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Name::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Name::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Name::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Name::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Name::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Name::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Name::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Name::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Name::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Name::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Name::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Name::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Name::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Name::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Name::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Name::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Name::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Name::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Name::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Name::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Name::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Name::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Name::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

