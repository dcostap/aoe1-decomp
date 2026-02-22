#include "../include/TribeSaveGameScreen.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Scenario.h"
#include "../include/TRIBE_Game.h"
#include "../include/TEasy_Panel.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/globals.h"

#include <io.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

namespace {

static const char kSaveGameScreenName[] = "Save Game Screen";
static const char kGameScreenName[] = "Game Screen";
static const char kScenarioEditorScreenName[] = "Scenario Editor Screen";
static const char kScenarioEditorOpenName[] = "Scenario Editor Open";
static const char kStatusScreenName[] = "Status Screen";

void save_set_button_disabled(TButtonPanel* button, int disabled) {
    if (button == nullptr) {
        return;
    }
    button->disabled = (disabled != 0) ? 1 : 0;
    button->set_redraw(TPanel::RedrawMode::Redraw);
}

TTextPanel* save_input_panel(TribeSaveGameScreen* owner) {
    if (owner == nullptr || owner->input == nullptr) {
        return nullptr;
    }
    return dynamic_cast<TTextPanel*>((TPanel*)owner->input);
}

void save_set_input_text(TribeSaveGameScreen* owner, const char* text) {
    TTextPanel* input = save_input_panel(owner);
    if (input == nullptr) {
        return;
    }
    input->set_text((char*)((text != nullptr) ? text : ""));
}

void save_get_input_trimmed(TribeSaveGameScreen* owner, char* out_text, int out_len) {
    if (out_text == nullptr || out_len <= 0) {
        return;
    }
    out_text[0] = '\0';

    const char* src = "";
    TTextPanel* input = save_input_panel(owner);
    if (input != nullptr) {
        const char* text = input->get_text(0);
        if (text != nullptr) {
            src = text;
        }
    }

    strncpy(out_text, src, (size_t)(out_len - 1));
    out_text[out_len - 1] = '\0';

    int start = 0;
    while (out_text[start] == ' ' || out_text[start] == '\t') {
        start++;
    }

    int end = (int)strlen(out_text);
    while (end > start && (out_text[end - 1] == ' ' || out_text[end - 1] == '\t')) {
        end--;
    }

    if (start > 0) {
        memmove(out_text, out_text + start, (size_t)(end - start));
    }
    out_text[end - start] = '\0';
}

const char* save_selected_line(TribeSaveGameScreen* owner) {
    if (owner == nullptr || owner->list == nullptr) {
        return "";
    }
    char* line = ((TTextPanel*)owner->list)->currentLine();
    if (line == nullptr) {
        return "";
    }
    return line;
}

void save_get_string_or_default(TPanel* panel, int id, char* out_text, int out_len, const char* fallback) {
    if (out_text == nullptr || out_len <= 0) {
        return;
    }
    out_text[0] = '\0';
    if (panel != nullptr) {
        panel->get_string(id, out_text, out_len);
    }
    if (out_text[0] == '\0' && fallback != nullptr) {
        strncpy(out_text, fallback, (size_t)(out_len - 1));
        out_text[out_len - 1] = '\0';
    }
}

int save_show_message_id(TribeSaveGameScreen* owner, int string_id, const char* fallback) {
    char text[512];
    save_get_string_or_default((TPanel*)owner, string_id, text, sizeof(text), fallback);
    HWND wnd = (rge_base_game != nullptr && rge_base_game->prog_window != nullptr) ? (HWND)rge_base_game->prog_window : nullptr;
    return MessageBoxA(wnd, text, "Age of Empires", MB_OK | MB_ICONINFORMATION);
}

int save_confirm_text(TribeSaveGameScreen* owner, const char* text) {
    HWND wnd = (rge_base_game != nullptr && rge_base_game->prog_window != nullptr) ? (HWND)rge_base_game->prog_window : nullptr;
    return MessageBoxA(wnd, text, "Age of Empires", MB_ICONQUESTION | MB_YESNO) == IDYES;
}

void save_update_delete_button_from_list(TribeSaveGameScreen* owner) {
    const char* line = save_selected_line(owner);
    save_set_button_disabled(owner->deleteButton, (line[0] == '\0') ? 1 : 0);
}

int save_execute_mode_save(TribeSaveGameScreen* owner) {
    if (owner->modeValue == TribeSaveGameScreen::SaveGame) {
        int ok = (rge_base_game != nullptr && rge_base_game->world != nullptr) ? rge_base_game->world->save_game(owner->fileName) : 0;
        if (ok == 0) {
            save_show_message_id(owner, 0x962, "The game could not be saved. Free some disk space, and then try again.");
            return 0;
        }
        return 1;
    }
    if (owner->modeValue == TribeSaveGameScreen::SaveScenario) {
        int ok = (rge_base_game != nullptr && rge_base_game->world != nullptr) ? rge_base_game->world->save_scenario(owner->fileName) : 0;
        if (ok == 0) {
            save_show_message_id(owner, 0x963, "The scenario could not be saved. Free some disk space, and then try again.");
            return 0;
        }
        return 1;
    }
    if (owner->modeValue == TribeSaveGameScreen::SaveScenarioEdit) {
        owner->save_for_scenario_editor();
        return 1;
    }
    return 1;
}

void save_set_scenario_name(RGE_Scenario* scenario, const char* name) {
    if (scenario == nullptr || scenario->scenario_name == nullptr) {
        return;
    }
    if (name == nullptr) {
        scenario->scenario_name[0] = '\0';
        return;
    }
    strcpy(scenario->scenario_name, name);
}

} // namespace

TribeSaveGameScreen::TribeSaveGameScreen(Mode mode, char* file_name, int quit_after_save)
    : TScreenPanel((char*)kSaveGameScreenName) {
    // Source of truth: scr_save.cpp.decomp @ 0x004A71F0
    this->quit_after_save = quit_after_save;
    this->modeValue = mode;
    this->title = nullptr;
    this->input = nullptr;
    this->list = nullptr;
    this->scrollbar = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->deleteButton = nullptr;
    this->fileName[0] = '\0';
    this->fileNameNoExt[0] = '\0';

    if (file_name == nullptr && mode == SaveGame) {
        file_name = ((TRIBE_Game*)rge_base_game)->get_save_game_name();
    }

    char info_file[260];
    strncpy(info_file, "scr2", sizeof(info_file) - 1);
    info_file[sizeof(info_file) - 1] = '\0';
    long info_id = 0xc384;

    TEasy_Panel* from_panel = nullptr;
    if (panel_system != nullptr && panel_system->currentPanelValue != nullptr) {
        from_panel = dynamic_cast<TEasy_Panel*>(panel_system->currentPanelValue);
    }
    if (from_panel != nullptr) {
        char* popup_info_file = from_panel->get_popup_info_file();
        if (popup_info_file != nullptr && popup_info_file[0] != '\0') {
            strncpy(info_file, popup_info_file, sizeof(info_file) - 1);
            info_file[sizeof(info_file) - 1] = '\0';
        }
        info_id = from_panel->get_popup_info_id();
    }

    if (rge_base_game == nullptr || rge_base_game->draw_area == nullptr ||
        TScreenPanel::setup(rge_base_game->draw_area, info_file, info_id, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    if (this->create_text((TPanel*)this, &this->title, (this->modeValue != SaveGame) + 0x24c3, 0x14, 0x14, 600, 0x1e, 1, 1, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    short max_name_len = 0x50;
    if (rge_base_game != nullptr && rge_base_game->work_dir != nullptr) {
        const int work_len = (int)strlen(rge_base_game->work_dir);
        if (0x7a - work_len < 0x51) {
            max_name_len = (short)(0x7a - work_len);
        }
    }

    if (this->create_edit((TPanel*)this, &this->input, file_name, max_name_len, FormatFileNoExt, 0x14, 0x46, 600, 0x17, 0xb, 1, 1) == 0) {
        this->error_code = 1;
        return;
    }
    ((TPanel*)this->input)->set_help_info(0x7670, -1);

    if (this->create_list((TPanel*)this, &this->list, 0x14, 0x6e, 600, 300, 0xb) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->create_auto_scrollbar(&this->scrollbar, (TTextPanel*)this->list, 0x14) == 0) {
        this->error_code = 1;
        return;
    }
    ((TPanel*)this->scrollbar)->set_help_info(0x7671, -1);

    if (this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x1e, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->create_button((TPanel*)this, &this->deleteButton, 0x24c9, 0, 0xe6, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }
    if (this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x1ae, 0x1b8, 0xb4, 0x1e, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    ((TPanel*)this->okButton)->set_help_info(0x7531, -1);
    ((TPanel*)this->cancelButton)->set_help_info(0x7532, -1);
    this->cancelButton->hotkey = 0x1b;
    this->cancelButton->hotkey_shift = 0;
    this->deleteButton->hotkey_shift = 0;
    this->deleteButton->hotkey = 0x2e;

    this->fillList();
    save_update_delete_button_from_list(this);

    this->set_curr_child((TPanel*)this->input);
    TPanel* tab_list[5];
    tab_list[0] = (TPanel*)this->input;
    tab_list[1] = (TPanel*)this->list;
    tab_list[2] = (TPanel*)this->okButton;
    tab_list[3] = (TPanel*)this->cancelButton;
    tab_list[4] = (TPanel*)this->deleteButton;
    this->set_tab_order(tab_list, 5);
}

TribeSaveGameScreen::~TribeSaveGameScreen() {
    // Source of truth: scr_save.cpp.decomp @ 0x004A75C0
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->input);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

void TribeSaveGameScreen::fillList() {
    // Source of truth: scr_save.cpp.decomp @ 0x004A7670
    if (this->list == nullptr || rge_base_game == nullptr || rge_base_game->prog_info == nullptr) {
        return;
    }

    TTextPanel* list_text = (TTextPanel*)this->list;
    list_text->empty_list();
    this->list->sorted = 1;

    char pattern[520];
    _finddata_t info;
    intptr_t handle = -1;

    if (this->modeValue == SaveGame) {
        sprintf(pattern, "%s*.gam", rge_base_game->prog_info->save_dir);
    } else {
        sprintf(pattern, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    }
    handle = _findfirst(pattern, &info);
    while (handle != -1) {
        const char* name = info.name;
        if (name != nullptr) {
            size_t len = strlen(name);
            if (len > 8) {
                char out[260];
                size_t body_len = len - 8;
                if (body_len >= sizeof(out)) {
                    body_len = sizeof(out) - 1;
                }
                memcpy(out, name + 4, body_len);
                out[body_len] = '\0';
                list_text->append_line(out, 0);
            }
        }
        if (_findnext(handle, &info) != 0) {
            _findclose(handle);
            handle = -1;
        }
    }

    if (this->modeValue == SaveGame) {
        sprintf(pattern, "%s*.gmx", rge_base_game->prog_info->save_dir);
    } else {
        sprintf(pattern, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    }
    handle = _findfirst(pattern, &info);
    while (handle != -1) {
        const char* name = info.name;
        if (name != nullptr) {
            size_t len = strlen(name);
            if (len > 8) {
                char out[260];
                size_t body_len = len - 8;
                if (body_len >= sizeof(out)) {
                    body_len = sizeof(out) - 1;
                }
                memcpy(out, name + 4, body_len);
                out[body_len] = '\0';
                list_text->append_line(out, 0);
            }
        }
        if (_findnext(handle, &info) != 0) {
            _findclose(handle);
            handle = -1;
        }
    }
}

long TribeSaveGameScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: scr_save.cpp.decomp @ 0x004A7850
    if (param_1 != nullptr) {
        if ((TButtonPanel*)param_1 == this->deleteButton && param_2 == 1 && save_selected_line(this)[0] != '\0') {
            char fmt[512];
            save_get_string_or_default((TPanel*)this, 0x24ca, fmt, sizeof(fmt), "Are you sure you want to delete the file\n'%s'?");

            char text[1024];
            sprintf(text, fmt, save_selected_line(this));
            if (save_confirm_text(this, text)) {
                char path[600];
                if (this->modeValue == SaveGame) {
                    sprintf(path, "%s%s.gam", rge_base_game->prog_info->save_dir, save_selected_line(this));
                    _unlink(path);
                    sprintf(path, "%s%s.gmx", rge_base_game->prog_info->save_dir, save_selected_line(this));
                    _unlink(path);
                } else {
                    sprintf(path, "%s%s.scn", rge_base_game->prog_info->scenario_dir, save_selected_line(this));
                    _unlink(path);
                    sprintf(path, "%s%s.scx", rge_base_game->prog_info->scenario_dir, save_selected_line(this));
                    _unlink(path);
                }

                long line = ((TTextPanel*)this->list)->get_line();
                ((TTextPanel*)this->list)->delete_line(line);
                save_set_input_text(this, save_selected_line(this));
                save_update_delete_button_from_list(this);
            }
            return 1;
        }

        if ((TListPanel*)param_1 == this->list && param_2 == 1) {
            save_set_input_text(this, save_selected_line(this));
            return 1;
        }

        if ((((TButtonPanel*)param_1 == this->okButton) && (param_2 == 1)) ||
            ((((TEditPanel*)param_1 == this->input) && (param_2 == 0)) ||
             (((TListPanel*)param_1 == this->list) && (param_2 == 3)))) {
            save_get_input_trimmed(this, this->fileNameNoExt, sizeof(this->fileNameNoExt));

            if (this->fileNameNoExt[0] == '\0') {
                if (this->modeValue != SaveGame) {
                    save_show_message_id(this, 0x24c7, "You must enter a name to save the scenario.");
                } else {
                    save_show_message_id(this, 0x24c6, "You must enter a name to save the game.");
                }
                return 1;
            }

            char path[600];
            char exist_flag = 0;

            if (this->modeValue == SaveGame) {
                sprintf(this->fileName, "%s.gam", this->fileNameNoExt);
                sprintf(path, "%s%s", rge_base_game->prog_info->save_dir, this->fileName);
            } else {
                sprintf(this->fileName, "%s.scn", this->fileNameNoExt);
                sprintf(path, "%s%s", rge_base_game->prog_info->scenario_dir, this->fileName);
            }
            FILE* f = fopen(path, "rb");
            if (f != nullptr) {
                exist_flag = 1;
                fclose(f);
            }

            if (this->modeValue == SaveGame) {
                sprintf(this->fileName, "%s.gmx", this->fileNameNoExt);
                sprintf(path, "%s%s", rge_base_game->prog_info->save_dir, this->fileName);
            } else {
                sprintf(this->fileName, "%s.scx", this->fileNameNoExt);
                sprintf(path, "%s%s", rge_base_game->prog_info->scenario_dir, this->fileName);
            }
            if (exist_flag == 0) {
                f = fopen(path, "rb");
                if (f != nullptr) {
                    exist_flag = 1;
                    fclose(f);
                }
            }

            if (exist_flag == 0) {
                save_execute_mode_save(this);
                return 1;
            }

            char overwrite_text[256];
            save_get_string_or_default((TPanel*)this, 0x24c8, overwrite_text, sizeof(overwrite_text), "That file exists. Overwrite it?");
            if (save_confirm_text(this, overwrite_text)) {
                save_get_input_trimmed(this, this->fileNameNoExt, sizeof(this->fileNameNoExt));
                if (this->modeValue == SaveGame) {
                    sprintf(path, "%s%s.gam", rge_base_game->prog_info->save_dir, this->fileNameNoExt);
                } else {
                    sprintf(path, "%s%s.scn", rge_base_game->prog_info->scenario_dir, this->fileNameNoExt);
                }
                _unlink(path);
                save_execute_mode_save(this);
            } else {
                this->set_curr_child((TPanel*)this->input);
            }
            return 1;
        }

        if ((((TButtonPanel*)param_1 == this->cancelButton) && (param_2 == 1)) ||
            (((TEditPanel*)param_1 == this->input) && (param_2 == 1))) {
            if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            if (this->modeValue == SaveScenarioEdit) {
                panel_system->setCurrentPanel((char*)kScenarioEditorScreenName, 0);
            } else {
                panel_system->setCurrentPanel((char*)kGameScreenName, 0);
            }
            panel_system->destroyPanel((char*)kSaveGameScreenName);
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

void TribeSaveGameScreen::save_for_scenario_editor() {
    // Source of truth: scr_save.cpp.decomp @ 0x004A8060
    ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, (char*)0, -1);
    if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
        save_set_scenario_name(rge_base_game->world->scenario, this->fileName);
        if (rge_base_game->world->save_scenario(this->fileName) == 0) {
            save_show_message_id(this, 0x963, "The scenario could not be saved. Free some disk space, and then try again.");
            return;
        }
    }

    TPanel* sed_panel = panel_system->panel((char*)kScenarioEditorScreenName);
    if (sed_panel != nullptr) {
        sed_panel->fill_in_background = 0;
    }

    if (this->quit_after_save == 1) {
        if (((TRIBE_Game*)rge_base_game)->start_menu() == 0) {
            rge_base_game->close();
            return;
        }
        panel_system->destroyPanel((char*)kScenarioEditorScreenName);
    } else if (this->quit_after_save == 2) {
        panel_system->setCurrentPanel((char*)kScenarioEditorOpenName, 0);
    } else if (this->quit_after_save == 3) {
        panel_system->setCurrentPanel((char*)kScenarioEditorScreenName, 0);
    } else {
        panel_system->setCurrentPanel((char*)kScenarioEditorScreenName, 0);
    }

    panel_system->destroyPanel((char*)kStatusScreenName);
    panel_system->destroyPanel((char*)kSaveGameScreenName);
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TribeSaveGameScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeSaveGameScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeSaveGameScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeSaveGameScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeSaveGameScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeSaveGameScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeSaveGameScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeSaveGameScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeSaveGameScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeSaveGameScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeSaveGameScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeSaveGameScreen::draw() { TScreenPanel::draw(); }
void TribeSaveGameScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeSaveGameScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeSaveGameScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeSaveGameScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeSaveGameScreen::paint() { TScreenPanel::paint(); }
long TribeSaveGameScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::handle_idle() { return TScreenPanel::handle_idle(); }
long TribeSaveGameScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeSaveGameScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeSaveGameScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSaveGameScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeSaveGameScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeSaveGameScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeSaveGameScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeSaveGameScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeSaveGameScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSaveGameScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeSaveGameScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeSaveGameScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSaveGameScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeSaveGameScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeSaveGameScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeSaveGameScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeSaveGameScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeSaveGameScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeSaveGameScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeSaveGameScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeSaveGameScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeSaveGameScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeSaveGameScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeSaveGameScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeSaveGameScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeSaveGameScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeSaveGameScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSaveGameScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSaveGameScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSaveGameScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSaveGameScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSaveGameScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSaveGameScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSaveGameScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeSaveGameScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeSaveGameScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSaveGameScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeSaveGameScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSaveGameScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeSaveGameScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSaveGameScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeSaveGameScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
