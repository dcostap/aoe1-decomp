#include "../include/TRIBE_Screen_Sed_Open.h"

#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Screen_Sed_Menu.h"
#include "../include/TButtonPanel.h"
#include "../include/TEasy_Panel.h"
#include "../include/TListPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TTextPanel.h"
#include "../include/globals.h"

#include <io.h>
#include <stdio.h>
#include <string.h>

namespace {
static const char kCancelDialogName[] = "Cancel Dialog";

static void set_button_disabled(TButtonPanel* button, int disabled) {
    if (!button) return;
    button->disabled = disabled ? 1 : 0;
    button->set_redraw(TPanel::RedrawMode::Redraw);
}
} // namespace

// Fully verified. Source of truth: scr_sedo.cpp.decomp @ 0x004B33D0
TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open() : TScreenPanel((char*)"Scenario Editor Open") {
    this->title = nullptr;
    this->list = nullptr;
    this->scrollbar = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->deleteButton = nullptr;

    if (rge_base_game == nullptr || panel_system == nullptr) {
        this->error_code = 1;
        return;
    }

    TPanel* from = panel_system->currentPanel();
    char info_file[260];
    info_file[0] = '\0';
    long info_id = 0;
    if (from != nullptr) {
        char* src = ((TEasy_Panel*)from)->get_info_file();
        if (src != nullptr) {
            strncpy(info_file, src, sizeof(info_file) - 1);
            info_file[sizeof(info_file) - 1] = '\0';
        }
        info_id = ((TEasy_Panel*)from)->get_info_id();
    }

    if (TScreenPanel::setup(rge_base_game->draw_area, info_file, info_id, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    if (this->create_text((TPanel*)this, &this->title, 0x24cd, 0x14, 0x14, 600, 0x1e, 1, 1, 0, 0) == 0) {
        return;
    }
    if (this->create_list((TPanel*)this, &this->list, 0x14, 0x46, 600, 0x154, 0xb) == 0) {
        return;
    }
    if (this->create_auto_scrollbar(&this->scrollbar, (TTextPanel*)this->list, 0x14) == 0) {
        return;
    }
    if (this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x1e, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button((TPanel*)this, &this->deleteButton, 0x24c9, 0, 0xe6, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x1ae, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        return;
    }

    this->cancelButton->hotkey = 0x1b;
    this->cancelButton->hotkey_shift = 0;
    this->deleteButton->hotkey = 0x2e;
    this->deleteButton->hotkey_shift = 0;

    this->fillList();

    char* cur = ((TTextPanel*)this->list)->currentLine();
    if (cur != nullptr && cur[0] == '\0') {
        set_button_disabled(this->okButton, 1);
        set_button_disabled(this->deleteButton, 1);
    }

    this->set_curr_child((TPanel*)this->list);
    TPanel* tab_list[4];
    tab_list[0] = (TPanel*)this->list;
    tab_list[1] = (TPanel*)this->okButton;
    tab_list[2] = (TPanel*)this->cancelButton;
    tab_list[3] = (TPanel*)this->deleteButton;
    this->set_tab_order(tab_list, 4);
}

// Fully verified. Source of truth: scr_sedo.cpp.decomp @ 0x004B36A0
TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

// Fully verified. Source of truth: scr_sedo.cpp.decomp @ 0x004B3740
void TRIBE_Screen_Sed_Open::fillList() {
    if (this->list == nullptr || rge_base_game == nullptr || rge_base_game->prog_info == nullptr) {
        return;
    }

    TTextPanel* list_text = (TTextPanel*)this->list;
    list_text->empty_list();
    this->list->sorted = 1;

    char pattern[520];
    _finddata_t info;
    intptr_t handle = -1;

    sprintf(pattern, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(pattern, &info);
    while (handle != -1) {
        const char* name = info.name;
        if (name != nullptr) {
            size_t len = strlen(name);
            if (len > 4) {
                char out[260];
                size_t body_len = len - 4;
                if (body_len >= sizeof(out)) body_len = sizeof(out) - 1;
                memcpy(out, name, body_len);
                out[body_len] = '\0';
                list_text->append_line(out, 0);
            }
        }
        if (_findnext(handle, &info) != 0) {
            handle = -1;
        }
    }

    sprintf(pattern, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(pattern, &info);
    while (handle != -1) {
        const char* name = info.name;
        if (name != nullptr) {
            size_t len = strlen(name);
            if (len > 4) {
                char out[260];
                size_t body_len = len - 4;
                if (body_len >= sizeof(out)) body_len = sizeof(out) - 1;
                memcpy(out, name, body_len);
                out[body_len] = '\0';
                list_text->append_line(out, 0);
            }
        }
        if (_findnext(handle, &info) != 0) {
            handle = -1;
        }
    }
}

// Fully verified. Source of truth: scr_sedo.cpp.decomp @ 0x004B38A0
long TRIBE_Screen_Sed_Open::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 != nullptr) {
        const char* panel_name = param_1->panelName();
        if (panel_name != nullptr && strcmp(panel_name, kCancelDialogName) == 0) {
            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)kCancelDialogName);
            }

            if (param_2 == 0 && rge_base_game != nullptr && rge_base_game->prog_info != nullptr) {
                const char* selected = ((TTextPanel*)this->list)->currentLine();
                if (selected != nullptr) {
                    char file_name[512];
                    sprintf(file_name, "%s%s.scn", rge_base_game->prog_info->scenario_dir, selected);
                    _unlink(file_name);
                    sprintf(file_name, "%s%s.scx", rge_base_game->prog_info->scenario_dir, selected);
                    _unlink(file_name);
                }

                long line = ((TTextPanel*)this->list)->get_line();
                ((TTextPanel*)this->list)->delete_line(line);

                char* cur = ((TTextPanel*)this->list)->currentLine();
                if (cur != nullptr && cur[0] == '\0') {
                    set_button_disabled(this->okButton, 1);
                    set_button_disabled(this->deleteButton, 1);
                    return 1;
                }
            }

            return 1;
        }

        if (((TButtonPanel*)param_1 == this->deleteButton) && (param_2 == 1)) {
            char* cur = ((TTextPanel*)this->list)->currentLine();
            if (cur != nullptr && cur[0] != '\0') {
                char confirm_fmt[256];
                confirm_fmt[0] = '\0';
                this->get_string(0x24ca, confirm_fmt, 0x100);
                char confirm_msg[556];
                sprintf(confirm_msg, confirm_fmt, cur);
                this->popupYesNoDialog((char*)confirm_msg, (char*)kCancelDialogName, 0x1c2, 100);
            }
        }

        if ((TListPanel*)param_1 != this->list) {
            if ((TButtonPanel*)param_1 == this->okButton) {
                if (param_2 == 1) {
                    int num = ((TTextPanel*)this->list)->numberLines();
                    if (num > 0 && rge_base_game != nullptr && rge_base_game->prog_info != nullptr) {
                        _OFSTRUCT of;
                        char check_name[512];
                        const char* selected = ((TTextPanel*)this->list)->currentLine();
                        sprintf(check_name, "%s%s.scn", rge_base_game->prog_info->scenario_dir, selected);
                        int exist = OpenFile(check_name, &of, OF_EXIST);
                        const char* fmt = "%s.scn";
                        if (exist == -1) {
                            sprintf(check_name, "%s%s.scx", rge_base_game->prog_info->scenario_dir, selected);
                            exist = OpenFile(check_name, &of, OF_EXIST);
                            if (exist == -1) {
                                this->popupOKDialog(0x24cf, (char*)nullptr, 0x1c2, 100);
                                return 1;
                            }
                            fmt = "%s.scx";
                        }

                        char scenario_file[300];
                        sprintf(scenario_file, fmt, selected);
                        ((TRIBE_Game*)rge_base_game)->start_scenario_editor(scenario_file, 0);
                        return 1;
                    }
                }
            } else {
                if ((TButtonPanel*)param_1 == this->cancelButton && param_2 == 1) {
                    const char* next = "Scenario Editor Screen";
                    if (panel_system != nullptr && panel_system->panel((char*)"Scenario Editor Screen") == nullptr) {
                        new TRIBE_Screen_Sed_Menu();
                        next = "Scenario Editor Menu";
                    }
                    if (panel_system != nullptr) {
                        panel_system->setCurrentPanel((char*)next, 0);
                        panel_system->destroyPanel((char*)"Scenario Editor Open");
                    }
                }
            }
            return 1;
        }

        if (param_2 == 3) {
            return this->action((TPanel*)this->okButton, 1, 0, 0);
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Screen_Sed_Open::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Sed_Open::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Sed_Open::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Open::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Sed_Open::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Sed_Open::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Sed_Open::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Open::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Sed_Open::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Open::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Sed_Open::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Sed_Open::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Sed_Open::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Sed_Open::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Open::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Sed_Open::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Sed_Open::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Sed_Open::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::handle_idle() { return TScreenPanel::handle_idle(); }
long TRIBE_Screen_Sed_Open::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Sed_Open::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Sed_Open::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Sed_Open::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Sed_Open::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Sed_Open::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Sed_Open::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Sed_Open::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Sed_Open::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Sed_Open::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Sed_Open::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Sed_Open::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Sed_Open::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Sed_Open::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Sed_Open::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Sed_Open::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Sed_Open::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Sed_Open::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Open::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Sed_Open::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Sed_Open::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Sed_Open::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed_Open::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Sed_Open::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Sed_Open::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Sed_Open::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Sed_Open::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Sed_Open::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

