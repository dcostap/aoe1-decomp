#include "../include/TRIBE_Campaign_Editor_Screen.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Campaign.h"
#include "../include/TRIBE_Screen_Sed_Menu.h"
#include "../include/TButtonPanel.h"
#include "../include/TDropDownPanel.h"
#include "../include/TEditPanel.h"
#include "../include/TListPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TTextPanel.h"
#include "../include/globals.h"
#include "../include/mystring.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace {
static const char kCancelDialogName[] = "Cancel Dialog";
static const char kLoadDialogName[] = "Load Dialog";

static void drop_set_sorted(TDropDownPanel* drop, int sorted) {
    if (drop != nullptr && drop->list_panel != nullptr) {
        ((TTextPanel*)drop->list_panel)->sorted = sorted ? 1 : 0;
    }
}

static char* drop_get_text(TDropDownPanel* drop) {
    if (drop != nullptr && drop->val_panel != nullptr) {
        char* text = drop->val_panel->get_text(0);
        if (text != nullptr) {
            return text;
        }
    }
    return (char*)"";
}
} // namespace

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x0048F5D0
TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen() : TScreenPanel((char*)"Campaign Editor Screen") {
    this->need_to_save = 0;
    this->title = nullptr;
    this->filename_title = nullptr;
    this->scenarios_title = nullptr;
    this->campaign_scenarios_title = nullptr;
    this->scenarios = nullptr;
    this->campaign_scenarios = nullptr;
    this->scenarios_bar = nullptr;
    this->campaign_scenarios_bar = nullptr;
    this->filename = nullptr;
    this->ok_button = nullptr;
    this->cancel_button = nullptr;
    this->save_button = nullptr;
    this->add_button = nullptr;
    this->remove_button = nullptr;
    this->move_scenario_up_button = nullptr;
    this->move_scenario_down_button = nullptr;
    this->filename_drop = nullptr;
    this->campaign = nullptr;

    if (TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr4", 0xc386, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    this->create_text((TPanel*)this, &this->title, 0x2bc1, 10, 10, 0x26c, 0x32, 1, 3, 0, 0);
    this->create_text((TPanel*)this, &this->filename_title, 0x2bc2, 0x14, 0x28, 0x104, 0x14, 4, 0, 0, 0);
    this->create_drop_down((TPanel*)this, &this->filename_drop, 0x17c, 200, 0x14, 0x3c, 0x17c, 0x1e, 0xb);

    char* default_name = this->get_string(0x2bca);
    this->create_edit((TPanel*)this->filename_drop, &this->filename, default_name, 100, FormatFileNoExt, 0, 0, 0x168, 0x1e, 0xb, 1, 1);

    this->create_button((TPanel*)this, &this->save_button, 0x2bc4, 0, 0x1a4, 0x3c, 200, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->add_button, 0x2bc5, 0, 0x118, 0x104, 0xa0, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->remove_button, 0x2bc6, 0, 0x1cc, 0x104, 0xa0, 0x1e, 0, 0, 0);

    this->create_text((TPanel*)this, &this->scenarios_title, 0x2bc7, 0x14, 100, 200, 0x14, 4, 0, 0, 0);
    this->create_list((TPanel*)this, &this->scenarios, 0x14, 0x78, 600, 0x82, 0xb);
    this->create_auto_scrollbar(&this->scenarios_bar, (TTextPanel*)this->scenarios, 0x14);

    this->create_text((TPanel*)this, &this->campaign_scenarios_title, 0x2bc8, 0x14, 0x118, 200, 0x14, 4, 0, 0, 0);
    this->create_list((TPanel*)this, &this->campaign_scenarios, 0x14, 300, 500, 0x82, 0xb);
    this->create_auto_scrollbar(&this->campaign_scenarios_bar, (TTextPanel*)this->campaign_scenarios, 0x14);

    this->create_button((TPanel*)this, &this->ok_button, 0xfa1, 0, 0x14, 0x1bd, 0x118, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->cancel_button, 0xfa2, 0, 0x154, 0x1bd, 0x118, 0x1e, 0, 0, 0);
    if (this->cancel_button != nullptr) {
        this->cancel_button->hotkey = 0x1b;
        this->cancel_button->hotkey_shift = 0;
    }

    this->create_button((TPanel*)this, &this->move_scenario_up_button, 0x2bd5, 0, 0x212, 300, 0x5a, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->move_scenario_down_button, 0x2bd6, 0, 0x212, 0x154, 0x5a, 0x1e, 0, 0, 0);

    TPanel* tab_list[8];
    tab_list[0] = (TPanel*)this->filename_drop;
    tab_list[1] = (TPanel*)this->save_button;
    tab_list[2] = (TPanel*)this->scenarios;
    tab_list[3] = (TPanel*)this->add_button;
    tab_list[4] = (TPanel*)this->remove_button;
    tab_list[5] = (TPanel*)this->campaign_scenarios;
    tab_list[6] = (TPanel*)this->ok_button;
    tab_list[7] = (TPanel*)this->cancel_button;
    this->set_tab_order(tab_list, 8);

    if (this->filename_drop != nullptr && this->filename != nullptr) {
        this->filename_drop->set_curr_child((TPanel*)this->filename);
        this->set_curr_child((TPanel*)this->filename_drop);
    }

    this->fill_scenario_list();
    this->fill_campaign_drop();
    if (this->campaign_scenarios != nullptr) {
        ((TTextPanel*)this->campaign_scenarios)->empty_list();
    }
    this->load_campaign();
    this->need_to_save = '\0';
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x0048FA40
TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen() {
    if (panel_system != nullptr) {
        panel_system->destroyPanel((char*)kCancelDialogName);
        panel_system->destroyPanel((char*)kLoadDialogName);
    }

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->scenarios_title);
    this->delete_panel((TPanel**)&this->campaign_scenarios_title);
    this->delete_panel((TPanel**)&this->scenarios);
    this->delete_panel((TPanel**)&this->scenarios_bar);
    this->delete_panel((TPanel**)&this->campaign_scenarios);
    this->delete_panel((TPanel**)&this->campaign_scenarios_bar);
    this->delete_panel((TPanel**)&this->filename_title);
    this->delete_panel((TPanel**)&this->filename);
    this->delete_panel((TPanel**)&this->filename_drop);
    this->delete_panel((TPanel**)&this->cancel_button);
    this->delete_panel((TPanel**)&this->save_button);
    this->delete_panel((TPanel**)&this->ok_button);
    this->delete_panel((TPanel**)&this->add_button);
    this->delete_panel((TPanel**)&this->remove_button);
    this->delete_panel((TPanel**)&this->move_scenario_up_button);
    this->delete_panel((TPanel**)&this->move_scenario_down_button);
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x0048FBC0
void TRIBE_Campaign_Editor_Screen::fill_campaign_drop() {
    if (this->filename_drop == nullptr || rge_base_game == nullptr || rge_base_game->prog_info == nullptr) {
        return;
    }

    drop_set_sorted(this->filename_drop, 1);
    this->filename_drop->empty_list();

    char pattern[512];
    _finddata_t info;
    intptr_t handle = -1;

    sprintf(pattern, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(pattern, &info);
    while (handle != -1) {
        const char* name = info.name;
        if (name != nullptr) {
            size_t len = strlen(name);
            if (len > 4) {
                char out[256];
                size_t body_len = len - 4;
                if (body_len >= sizeof(out)) body_len = sizeof(out) - 1;
                memcpy(out, name, body_len);
                out[body_len] = '\0';
                this->filename_drop->append_line(out, 0);
            }
        }
        if (_findnext(handle, &info) != 0) {
            handle = -1;
        }
    }

    sprintf(pattern, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(pattern, &info);
    while (handle != -1) {
        const char* name = info.name;
        if (name != nullptr) {
            size_t len = strlen(name);
            if (len > 4) {
                char out[256];
                size_t body_len = len - 4;
                if (body_len >= sizeof(out)) body_len = sizeof(out) - 1;
                memcpy(out, name, body_len);
                out[body_len] = '\0';
                this->filename_drop->append_line(out, 0);
            }
        }
        if (_findnext(handle, &info) != 0) {
            handle = -1;
        }
    }
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x0048FD20
void TRIBE_Campaign_Editor_Screen::fill_scenario_list() {
    if (this->scenarios == nullptr || rge_base_game == nullptr || rge_base_game->prog_info == nullptr) {
        return;
    }

    this->scenarios->sorted = 1;
    ((TTextPanel*)this->scenarios)->empty_list();

    char pattern[512];
    _finddata_t info;
    intptr_t handle = -1;

    sprintf(pattern, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(pattern, &info);
    while (handle != -1) {
        const char* name = info.name;
        if (name != nullptr) {
            size_t len = strlen(name);
            if (len > 4) {
                char out[256];
                size_t body_len = len - 4;
                if (body_len >= sizeof(out)) body_len = sizeof(out) - 1;
                memcpy(out, name, body_len);
                out[body_len] = '\0';
                ((TTextPanel*)this->scenarios)->append_line(out, 0);
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
                char out[256];
                size_t body_len = len - 4;
                if (body_len >= sizeof(out)) body_len = sizeof(out) - 1;
                memcpy(out, name, body_len);
                out[body_len] = '\0';
                ((TTextPanel*)this->scenarios)->append_line(out, 0);
            }
        }
        if (_findnext(handle, &info) != 0) {
            handle = -1;
        }
    }
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x0048FE80
void TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list() {
    if (this->campaign == nullptr || this->campaign_scenarios == nullptr) {
        return;
    }

    ((TTextPanel*)this->campaign_scenarios)->empty_list();

    char** scenario_names = nullptr;
    long count = this->campaign->scenario_info(&scenario_names);
    if (scenario_names != nullptr) {
        for (long i = 0; i < count; ++i) {
            ((TTextPanel*)this->campaign_scenarios)->append_line(scenario_names[i], 0);
            free(scenario_names[i]);
        }
        free(scenario_names);
    }
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x0048FF00
uchar TRIBE_Campaign_Editor_Screen::check_lists() {
    if (this->scenarios == nullptr || this->campaign_scenarios == nullptr) {
        return '\0';
    }

    const int lines = ((TTextPanel*)this->campaign_scenarios)->numberLines();
    for (int i = 0; i < lines; ++i) {
        char* text = ((TTextPanel*)this->campaign_scenarios)->get_text(i);
        long line = ((TTextPanel*)this->scenarios)->get_line(text);
        if (line == -1) {
            return '\0';
        }
    }

    for (int i = 0; i < lines; ++i) {
        char* text = ((TTextPanel*)this->campaign_scenarios)->get_text(i);
        long line = ((TTextPanel*)this->scenarios)->get_line(text);
        ((TTextPanel*)this->scenarios)->delete_line(line);
    }
    return '\x01';
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x0048FF80
void TRIBE_Campaign_Editor_Screen::load_campaign() {
    char* text = nullptr;
    char* full_path = nullptr;

    const char* base = this->filename->get_text();
    addstring(&text, (char*)base, (char*)".cpn");
    addstring(&full_path, rge_base_game->prog_info->campaign_dir, text);

    _finddata_t info;
    intptr_t h = _findfirst(full_path, &info);
    if (h == -1) {
        free(text);
        free(full_path);
        text = nullptr;
        full_path = nullptr;
        addstring(&text, (char*)base, (char*)".cpx");
        addstring(&full_path, rge_base_game->prog_info->campaign_dir, text);
        h = _findfirst(full_path, &info);
        if (h == -1) {
            ((TTextPanel*)this->campaign_scenarios)->empty_list();
            free(text);
            free(full_path);
            this->need_to_save = '\0';
            return;
        }
    }

    this->campaign = new RGE_Campaign(text);
    this->fill_scenario_list();
    this->fill_campaign_scenario_list();
    uchar ok = this->check_lists();
    delete this->campaign;
    this->campaign = nullptr;

    if (ok == '\0') {
        ((TTextPanel*)this->campaign_scenarios)->empty_list();
    }

    free(text);
    free(full_path);
    this->need_to_save = '\0';
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x00490120
void TRIBE_Campaign_Editor_Screen::make_campaign() {
    if (this->filename == nullptr || this->campaign_scenarios == nullptr) {
        this->need_to_save = '\0';
        return;
    }

    char* campaign_name = this->filename->get_text();
    if (campaign_name == nullptr) {
        this->need_to_save = '\0';
        return;
    }

    const char first = campaign_name[0];
    if (first == '\0' || first == ' ') {
        this->popupOKDialog(0x2bcc, (char*)nullptr, 0x1c2, 100);
        this->need_to_save = '\0';
        return;
    }

    char* campaign_filename = nullptr;
    addstring(&campaign_filename, campaign_name, (char*)".cpx");

    const int count = ((TTextPanel*)this->campaign_scenarios)->numberLines();
    if (count < 1) {
        this->popupOKDialog(0x2bcb, (char*)nullptr, 0x1c2, 100);
        free(campaign_filename);
        this->need_to_save = '\0';
        return;
    }

    char** scenario_text = (char**)calloc((size_t)count, sizeof(char*));
    char** scenario_files = (char**)calloc((size_t)count, sizeof(char*));
    if (scenario_text == nullptr || scenario_files == nullptr) {
        free(scenario_text);
        free(scenario_files);
        free(campaign_filename);
        this->need_to_save = '\0';
        return;
    }

    for (int i = 0; i < count; ++i) {
        char* line = ((TTextPanel*)this->campaign_scenarios)->get_text(i);
        getstring(&scenario_text[i], line);
        getstring(&scenario_files[i], line);

        char test[512];
        _finddata_t info;
        snprintf(test, sizeof(test), "%s%s.scn", rge_base_game->prog_info->scenario_dir, scenario_files[i]);
        test[sizeof(test) - 1] = '\0';
        intptr_t h = _findfirst(test, &info);
        const char* ext = (h == -1) ? ".scx" : ".scn";

        addstring(&scenario_files[i], scenario_files[i], (char*)ext);
    }

    this->campaign = new RGE_Campaign(campaign_filename, campaign_name, count, scenario_files, scenario_text);
    delete this->campaign;
    this->campaign = nullptr;

    for (int i = 0; i < count; ++i) {
        free(scenario_text[i]);
        free(scenario_files[i]);
    }
    free(scenario_text);
    free(scenario_files);
    free(campaign_filename);

    this->fill_campaign_drop();
    rge_base_game->find_campaigns();

    this->need_to_save = '\0';
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x00490380
void TRIBE_Campaign_Editor_Screen::add_scenario() {
    if (this->scenarios == nullptr || this->campaign_scenarios == nullptr) {
        return;
    }

    char* text = ((TTextPanel*)this->scenarios)->currentLine();
    if (text != nullptr && text[0] != '\0') {
        ((TTextPanel*)this->campaign_scenarios)->append_line(text, 0);
        long line = ((TTextPanel*)this->campaign_scenarios)->get_line(text);
        ((TTextPanel*)this->campaign_scenarios)->set_line(line);
        line = ((TTextPanel*)this->scenarios)->get_line();
        ((TTextPanel*)this->scenarios)->delete_line(line);
        line = ((TTextPanel*)this->campaign_scenarios)->get_line();
        this->campaign_scenarios->scroll_cur_line('\x01', (short)line, 1);
    }
    this->need_to_save = '\x01';
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x00490400
void TRIBE_Campaign_Editor_Screen::remove_scenario() {
    if (this->scenarios == nullptr || this->campaign_scenarios == nullptr) {
        return;
    }

    char* text = ((TTextPanel*)this->campaign_scenarios)->currentLine();
    if (text != nullptr && text[0] != '\0') {
        ((TTextPanel*)this->scenarios)->append_line(text, 0);
        long line = ((TTextPanel*)this->scenarios)->get_line(text);
        ((TTextPanel*)this->scenarios)->set_line(line);
        line = ((TTextPanel*)this->campaign_scenarios)->get_line();
        ((TTextPanel*)this->campaign_scenarios)->delete_line(line);
        line = ((TTextPanel*)this->scenarios)->get_line();
        this->scenarios->scroll_cur_line('\x01', (short)line, 1);
    }
    this->need_to_save = '\x01';
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x00490480
void TRIBE_Campaign_Editor_Screen::move_scenario_up() {
    if (this->campaign_scenarios == nullptr) {
        return;
    }

    long line = ((TTextPanel*)this->campaign_scenarios)->get_line();
    if (line > 0) {
        char* text = ((TTextPanel*)this->campaign_scenarios)->currentLine();
        if (text != nullptr && text[0] != '\0') {
            ((TTextPanel*)this->campaign_scenarios)->insert_line(line - 1, text, 0);
            line = ((TTextPanel*)this->campaign_scenarios)->get_line();
            ((TTextPanel*)this->campaign_scenarios)->delete_line(line + 1);
            line = ((TTextPanel*)this->campaign_scenarios)->get_line();
            ((TTextPanel*)this->campaign_scenarios)->set_line(line - 1);
            line = ((TTextPanel*)this->campaign_scenarios)->get_line();
            this->campaign_scenarios->scroll_cur_line('\x01', (short)line, 1);
        }
        this->need_to_save = '\x01';
    }
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x00490520
void TRIBE_Campaign_Editor_Screen::move_scenario_down() {
    if (this->campaign_scenarios == nullptr) {
        return;
    }

    const int total = ((TTextPanel*)this->campaign_scenarios)->numberLines();
    long line = ((TTextPanel*)this->campaign_scenarios)->get_line();
    if (line < total - 1) {
        char* text = ((TTextPanel*)this->campaign_scenarios)->currentLine();
        if (text != nullptr && text[0] != '\0') {
            ((TTextPanel*)this->campaign_scenarios)->insert_line(line + 2, text, 0);
            line = ((TTextPanel*)this->campaign_scenarios)->get_line();
            ((TTextPanel*)this->campaign_scenarios)->delete_line(line);
            line = ((TTextPanel*)this->campaign_scenarios)->get_line();
            ((TTextPanel*)this->campaign_scenarios)->set_line(line + 1);
            line = ((TTextPanel*)this->campaign_scenarios)->get_line();
            this->campaign_scenarios->scroll_cur_line('\x01', (short)line, 1);
        }
        this->need_to_save = '\x01';
    }
}

// Fully verified. Source of truth: scr_cam.cpp.decomp @ 0x004905D0
long TRIBE_Campaign_Editor_Screen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 != nullptr) {
        if ((TDropDownPanel*)param_1 == this->filename_drop && param_2 == 2) {
            this->filename_drop->set_curr_child((TPanel*)this->filename);
            this->set_curr_child((TPanel*)this->filename_drop);
        }

        if (param_2 == 3) {
            if ((TListPanel*)param_1 == this->scenarios) {
                this->add_scenario();
            } else if ((TListPanel*)param_1 == this->campaign_scenarios) {
                this->remove_scenario();
            }
        }

        if ((TDropDownPanel*)param_1 == this->filename_drop && param_2 == 0) {
            if (this->need_to_save == '\0' || ((TTextPanel*)this->campaign_scenarios)->numberLines() < 1) {
                char* drop_text = drop_get_text(this->filename_drop);
                this->filename->set_text(drop_text);
                this->load_campaign();
            } else {
                char fmt[256];
                this->get_string(0x2bc9, fmt, sizeof(fmt));
                char msg[300];
                char* cur = this->filename->get_text();
                sprintf(msg, fmt, cur);
                this->popupYesNoCancelDialog((char*)msg, (char*)kLoadDialogName, 0x1c2, 100);
            }
        }

        if (param_2 == 1) {
            if ((TButtonPanel*)param_1 != this->ok_button) {
                if ((TButtonPanel*)param_1 == this->save_button) {
                    this->make_campaign();
                } else {
                    if ((TButtonPanel*)param_1 == this->cancel_button) {
                        new TRIBE_Screen_Sed_Menu();
                        if (panel_system != nullptr) {
                            panel_system->setCurrentPanel((char*)"Scenario Editor Menu", 0);
                            panel_system->destroyPanel((char*)"Campaign Editor Screen");
                        }
                        return 1;
                    }
                    if ((TButtonPanel*)param_1 == this->add_button) {
                        this->add_scenario();
                    } else if ((TButtonPanel*)param_1 == this->remove_button) {
                        this->remove_scenario();
                    } else if ((TButtonPanel*)param_1 == this->move_scenario_up_button) {
                        this->move_scenario_up();
                    } else if ((TButtonPanel*)param_1 == this->move_scenario_down_button) {
                        this->move_scenario_down();
                    }
                }
            } else {
                if (this->need_to_save != '\0' && ((TTextPanel*)this->campaign_scenarios)->numberLines() > 0) {
                    char fmt[256];
                    this->get_string(0x2bc9, fmt, sizeof(fmt));
                    char msg[300];
                    char* cur = this->filename->get_text();
                    sprintf(msg, fmt, cur);
                    this->popupYesNoCancelDialog((char*)msg, (char*)kCancelDialogName, 0x1c2, 100);
                    return 1;
                }
                new TRIBE_Screen_Sed_Menu();
                if (panel_system != nullptr) {
                    panel_system->setCurrentPanel((char*)"Scenario Editor Menu", 0);
                    panel_system->destroyPanel((char*)"Campaign Editor Screen");
                }
                return 1;
            }
        }

        const char* panel_name = param_1->panelName();
        if (panel_name != nullptr && strcmp(panel_name, kCancelDialogName) == 0) {
            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)kCancelDialogName);
            }
            if (param_2 == 0) {
                this->make_campaign();
                new TRIBE_Screen_Sed_Menu();
                if (panel_system != nullptr) {
                    panel_system->setCurrentPanel((char*)"Scenario Editor Menu", 0);
                    panel_system->destroyPanel((char*)"Campaign Editor Screen");
                }
            } else if (param_2 == 1) {
                new TRIBE_Screen_Sed_Menu();
                if (panel_system != nullptr) {
                    panel_system->setCurrentPanel((char*)"Scenario Editor Menu", 0);
                    panel_system->destroyPanel((char*)"Campaign Editor Screen");
                }
            }
            return 1;
        }

        if (panel_name != nullptr && strcmp(panel_name, kLoadDialogName) == 0) {
            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)kLoadDialogName);
            }
            if (param_2 == 0) {
                this->make_campaign();
            } else if (param_2 != 1) {
                return 1;
            }

            char* drop_text = drop_get_text(this->filename_drop);
            this->filename->set_text(drop_text);
            this->load_campaign();
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Campaign_Editor_Screen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Campaign_Editor_Screen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Campaign_Editor_Screen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Campaign_Editor_Screen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Campaign_Editor_Screen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Campaign_Editor_Screen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Campaign_Editor_Screen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Campaign_Editor_Screen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Campaign_Editor_Screen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Campaign_Editor_Screen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Campaign_Editor_Screen::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Campaign_Editor_Screen::draw() { TScreenPanel::draw(); }
void TRIBE_Campaign_Editor_Screen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Campaign_Editor_Screen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Campaign_Editor_Screen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Campaign_Editor_Screen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Campaign_Editor_Screen::paint() { TScreenPanel::paint(); }
long TRIBE_Campaign_Editor_Screen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::handle_idle() { return TScreenPanel::handle_idle(); }
long TRIBE_Campaign_Editor_Screen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Campaign_Editor_Screen::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Campaign_Editor_Screen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Campaign_Editor_Screen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Campaign_Editor_Screen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Campaign_Editor_Screen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Campaign_Editor_Screen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Campaign_Editor_Screen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Campaign_Editor_Screen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Campaign_Editor_Screen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Campaign_Editor_Screen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Campaign_Editor_Screen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Campaign_Editor_Screen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Campaign_Editor_Screen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Campaign_Editor_Screen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Campaign_Editor_Screen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Campaign_Editor_Screen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Campaign_Editor_Screen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Campaign_Editor_Screen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Campaign_Editor_Screen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Campaign_Editor_Screen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Campaign_Editor_Screen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Campaign_Editor_Screen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Campaign_Editor_Screen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Campaign_Editor_Screen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Campaign_Editor_Screen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Campaign_Editor_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Campaign_Editor_Screen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Campaign_Editor_Screen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Campaign_Editor_Screen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Campaign_Editor_Screen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Campaign_Editor_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Campaign_Editor_Screen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Campaign_Editor_Screen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Campaign_Editor_Screen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Campaign_Editor_Screen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Campaign_Editor_Screen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Campaign_Editor_Screen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Campaign_Editor_Screen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Campaign_Editor_Screen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Campaign_Editor_Screen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Campaign_Editor_Screen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

