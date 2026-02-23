#include "../include/TribeLoadSavedGameScreen.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TEasy_Panel.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/globals.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace {

void load_enable_input() {
    if (rge_base_game) {
        rge_base_game->enable_input();
    }
}

void load_set_button_disabled(TButtonPanel* button, int disabled) {
    if (!button) return;
    button->disabled = disabled ? 1 : 0;
    button->set_redraw(TPanel::RedrawMode::Redraw);
}

void load_sync_buttons(TribeLoadSavedGameScreen* owner) {
    if (!owner || !owner->list) {
        load_set_button_disabled(owner ? owner->okButton : nullptr, 1);
        load_set_button_disabled(owner ? owner->deleteButton : nullptr, 1);
        return;
    }

    char* cur = ((TTextPanel*)owner->list)->currentLine();
    const int no_selection = (cur == nullptr || cur[0] == '\0');
    load_set_button_disabled(owner->okButton, no_selection);
    load_set_button_disabled(owner->deleteButton, no_selection);
}

static const char* load_selected_name(TribeLoadSavedGameScreen* owner) {
    if (!owner || !owner->list) return nullptr;
    char* cur = ((TTextPanel*)owner->list)->currentLine();
    if (!cur || cur[0] == '\0') return nullptr;
    return cur;
}

void load_delete_selected_files(TribeLoadSavedGameScreen* owner) {
    if (!owner || !rge_base_game || !rge_base_game->prog_info) return;
    const char* selected = load_selected_name(owner);
    if (!selected) return;

    char confirm_fmt[512];
    confirm_fmt[0] = '\0';
    owner->get_string(0x24ca, confirm_fmt, sizeof(confirm_fmt));
    if (confirm_fmt[0] == '\0') {
        strncpy(confirm_fmt, "Are you sure you want to delete the file\n'%s'?", sizeof(confirm_fmt) - 1);
        confirm_fmt[sizeof(confirm_fmt) - 1] = '\0';
    }

    char confirm_msg[1024];
    snprintf(confirm_msg, sizeof(confirm_msg), confirm_fmt, selected);
    confirm_msg[sizeof(confirm_msg) - 1] = '\0';

    HWND wnd = (rge_base_game->prog_window) ? (HWND)rge_base_game->prog_window : nullptr;
    if (MessageBoxA(wnd, confirm_msg, "Age of Empires", MB_ICONQUESTION | MB_YESNO) != IDYES) {
        return;
    }

    char file_name[512];
    snprintf(file_name, sizeof(file_name), "%s%s.gam", rge_base_game->prog_info->save_dir, selected);
    file_name[sizeof(file_name) - 1] = '\0';
    _unlink(file_name);

    snprintf(file_name, sizeof(file_name), "%s%s.gmx", rge_base_game->prog_info->save_dir, selected);
    file_name[sizeof(file_name) - 1] = '\0';
    _unlink(file_name);

    long line_num = ((TTextPanel*)owner->list)->get_line();
    ((TTextPanel*)owner->list)->delete_line(line_num);
    load_sync_buttons(owner);
}

int load_selected_game(TribeLoadSavedGameScreen* owner) {
    if (!owner || !rge_base_game || !rge_base_game->prog_info) return 0;
    const char* selected = load_selected_name(owner);
    if (!selected || selected[0] == '\0') return 0;

    char check_name[512];
    _finddata_t info;

    snprintf(check_name, sizeof(check_name), "%s%s.gmx", rge_base_game->prog_info->save_dir, selected);
    check_name[sizeof(check_name) - 1] = '\0';
    intptr_t h = _findfirst(check_name, &info);

    char load_name[300];
    if (h == -1) {
        snprintf(load_name, sizeof(load_name), "%s.gam", selected);
    } else {
        _findclose(h);
        snprintf(load_name, sizeof(load_name), "%s.gmx", selected);
    }
    load_name[sizeof(load_name) - 1] = '\0';

    return ((TRIBE_Game*)rge_base_game)->load_game(load_name);
}

} // namespace

TribeLoadSavedGameScreen::TribeLoadSavedGameScreen() : TScreenPanel((char*)"Load Saved Game Screen") {
    this->screenTitle = nullptr;
    this->listTitle = nullptr;
    this->list = nullptr;
    this->scrollbar = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->deleteButton = nullptr;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    char info_file[260];
    strncpy(info_file, "scr2", sizeof(info_file) - 1);
    info_file[sizeof(info_file) - 1] = '\0';
    long info_id = 0xc384;

    // TODO(accuracy): Best-effort parity with `scr_load`: copy setup file/id from current screen.
    TEasy_Panel* from_panel = nullptr;
    if (panel_system && panel_system->currentPanelValue) {
        from_panel = dynamic_cast<TEasy_Panel*>(panel_system->currentPanelValue);
    }
    if (from_panel) {
        if (from_panel->info_file_name[0] != '\0') {
            strncpy(info_file, from_panel->info_file_name, sizeof(info_file) - 1);
            info_file[sizeof(info_file) - 1] = '\0';
        }
        if (from_panel->info_id >= 0) {
            info_id = from_panel->info_id;
        }
    }

    if (!TScreenPanel::setup(rge_base_game->draw_area, info_file, info_id, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    if (!this->create_text((TPanel*)this, &this->screenTitle, 0x24ff, 0x14, 0x0a, 600, 0x1e, 1, 1, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_text((TPanel*)this, &this->listTitle, 0x2502, 0x14, 0x2d, 600, 0x14, 4, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_list((TPanel*)this, &this->list, 0x14, 0x41, 600, 0x160, 0xb)) {
        this->error_code = 1;
        return;
    }
    if (!this->create_auto_scrollbar(&this->scrollbar, (TTextPanel*)this->list, 0x14)) {
        this->error_code = 1;
        return;
    }
    if (this->scrollbar) {
        this->scrollbar->set_help_info(0x7670, -1);
    }

    if (!this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x1e, 0x1b8, 0xb4, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_button((TPanel*)this, &this->deleteButton, 0x24c9, 0, 0xe6, 0x1b8, 0xb4, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x1ae, 0x1b8, 0xb4, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    this->cancelButton->hotkey = 0x1b;
    this->cancelButton->hotkey_shift = 0;
    this->deleteButton->hotkey = 0x2e;
    this->deleteButton->hotkey_shift = 0;

    // Source of truth: scr_load.cpp.decomp - set help info for buttons
    this->okButton->set_help_info(0x7531, -1);
    this->cancelButton->set_help_info(0x7532, -1);
    this->deleteButton->set_help_info(0x7533, -1);

    this->fillList();

    // Source of truth: scr_load.cpp.decomp - disable buttons if list is empty
    load_sync_buttons(this);

    // Source of truth: scr_load.cpp.decomp - attempt to restore current save selection
    if (this->list) {
        char* save_name = ((TRIBE_Game*)rge_base_game)->get_save_game_name();
        long line = ((TTextPanel*)this->list)->get_line(save_name);
        if (line != -1) {
            this->list->scroll_cur_line(1, (short)line, 1);
        }
    }

    this->set_curr_child((TPanel*)this->list);
    TPanel* tab_list[4];
    tab_list[0] = (TPanel*)this->list;
    tab_list[1] = (TPanel*)this->okButton;
    tab_list[2] = (TPanel*)this->cancelButton;
    tab_list[3] = (TPanel*)this->deleteButton;
    this->set_tab_order(tab_list, 4);
}

TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen() {
    // Source of truth: scr_load.cpp.decomp @ 0x0049E0A0
    // Delete all child panels before base destructor runs
    this->delete_panel((TPanel**)&this->screenTitle);
    this->delete_panel((TPanel**)&this->listTitle);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

void TribeLoadSavedGameScreen::fillList() {
    // Source of truth: scr_load.cpp.decomp @ 0x0049E150
    if (!this->list || !rge_base_game || !rge_base_game->prog_info) {
        return;
    }

    TTextPanel* list_text = (TTextPanel*)this->list;
    list_text->empty_list();
    list_text->sorted = 1;

    char pattern[512];
    snprintf(pattern, sizeof(pattern), "%s*.gam", rge_base_game->prog_info->save_dir);
    pattern[sizeof(pattern) - 1] = '\0';
    {
        _finddata_t info;
        intptr_t h = _findfirst(pattern, &info);
        if (h != -1) {
            do {
                const char* name = info.name;
                if (!name) continue;
                const size_t len = strlen(name);
                if (len <= 8) continue;

                char out[260];
                const size_t body_len = len - 8;
                if (body_len + 1 >= sizeof(out)) continue;
                memcpy(out, name + 4, body_len);
                out[body_len] = '\0';
                list_text->append_line(out, 0);
            } while (_findnext(h, &info) == 0);
            _findclose(h);
        }
    }

    snprintf(pattern, sizeof(pattern), "%s*.gmx", rge_base_game->prog_info->save_dir);
    pattern[sizeof(pattern) - 1] = '\0';
    {
        _finddata_t info;
        intptr_t h = _findfirst(pattern, &info);
        if (h != -1) {
            do {
                const char* name = info.name;
                if (!name) continue;
                const size_t len = strlen(name);
                if (len <= 8) continue;

                char out[260];
                const size_t body_len = len - 8;
                if (body_len + 1 >= sizeof(out)) continue;
                memcpy(out, name + 4, body_len);
                out[body_len] = '\0';
                list_text->append_line(out, 0);
            } while (_findnext(h, &info) == 0);
            _findclose(h);
        }
    }

    load_sync_buttons(this);
}

long TribeLoadSavedGameScreen::handle_idle() {
    // Source of truth: scr_load.cpp.decomp @ 0x0049E2B0
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeLoadSavedGameScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4);
}

long TribeLoadSavedGameScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4);
}

long TribeLoadSavedGameScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1) {
        if ((TPanel*)this->list == param_1 && param_2 == 3) {
            return this->action((TPanel*)this->okButton, 1, 0, 0);
        }

        if ((TButtonPanel*)param_1 == this->deleteButton && param_2 == 1) {
            load_delete_selected_files(this);
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->okButton && param_2 == 1) {
            if (!load_selected_game(this)) {
                char text[512];
                text[0] = '\0';
                this->get_string(0x2501, text, sizeof(text));
                if (text[0] == '\0') {
                    strncpy(text, "Cannot load that saved game.", sizeof(text) - 1);
                    text[sizeof(text) - 1] = '\0';
                }
                HWND wnd = (rge_base_game && rge_base_game->prog_window) ? (HWND)rge_base_game->prog_window : nullptr;
                MessageBoxA(wnd, text, "Age of Empires", MB_OK | MB_ICONINFORMATION);
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->cancelButton && param_2 == 1) {
            // Fully verified. Source of truth: scr_load.cpp.decomp (cancel path) @ 0x0049E5F7
            const char* return_panel = "Game Screen";
            TPanel* game_screen = (panel_system != nullptr) ? panel_system->panel((char*)"Game Screen") : nullptr;
            if (game_screen == nullptr) {
                rge_base_game->disable_input();
                TribeSPMenuScreen* menu = new TribeSPMenuScreen();
                (void)menu;
                return_panel = "Single Player Menu";
            } else {
                if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
                return_panel = "Game Screen";
            }

            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)return_panel, 0);
                panel_system->destroyPanel((char*)"Load Saved Game Screen");
            }
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TribeLoadSavedGameScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeLoadSavedGameScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeLoadSavedGameScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeLoadSavedGameScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeLoadSavedGameScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeLoadSavedGameScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeLoadSavedGameScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeLoadSavedGameScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeLoadSavedGameScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeLoadSavedGameScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeLoadSavedGameScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeLoadSavedGameScreen::draw() { TScreenPanel::draw(); }
void TribeLoadSavedGameScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeLoadSavedGameScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeLoadSavedGameScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeLoadSavedGameScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeLoadSavedGameScreen::paint() { TScreenPanel::paint(); }
long TribeLoadSavedGameScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeLoadSavedGameScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeLoadSavedGameScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeLoadSavedGameScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeLoadSavedGameScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeLoadSavedGameScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeLoadSavedGameScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeLoadSavedGameScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeLoadSavedGameScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeLoadSavedGameScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeLoadSavedGameScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeLoadSavedGameScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeLoadSavedGameScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeLoadSavedGameScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeLoadSavedGameScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeLoadSavedGameScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeLoadSavedGameScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeLoadSavedGameScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeLoadSavedGameScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeLoadSavedGameScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeLoadSavedGameScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeLoadSavedGameScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeLoadSavedGameScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeLoadSavedGameScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeLoadSavedGameScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeLoadSavedGameScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeLoadSavedGameScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeLoadSavedGameScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeLoadSavedGameScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeLoadSavedGameScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeLoadSavedGameScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeLoadSavedGameScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeLoadSavedGameScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeLoadSavedGameScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeLoadSavedGameScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeLoadSavedGameScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeLoadSavedGameScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeLoadSavedGameScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeLoadSavedGameScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeLoadSavedGameScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeLoadSavedGameScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeLoadSavedGameScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

