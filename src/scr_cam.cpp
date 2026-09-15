#include "../include/scr_cam.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/Pnl_txt.h"
#include "../include/pnl_drop.h"
#include "../include/pnl_edit.h"
#include "../include/mystring.h"
#include "../include/campaign.h"
#include "../include/scr_sedm.h"
#include "../include/main.h"
#include "../include/resource_ids.h"
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen()
    : TScreenPanel("Campaign Editor Screen") {
    this->title = 0;
    this->scenarios_title = 0;
    this->scenarios = 0;
    this->scenarios_bar = 0;
    this->campaign_scenarios_title = 0;
    this->campaign_scenarios = 0;
    this->campaign_scenarios_bar = 0;
    this->filename_title = 0;
    this->filename = 0;
    this->cancel_button = 0;
    this->save_button = 0;
    this->ok_button = 0;
    this->campaign = 0;
    this->filename_drop = 0;
    this->add_button = 0;
    this->remove_button = 0;
    this->move_scenario_up_button = 0;
    this->move_scenario_down_button = 0;

    if (!this->setup(rge_base_game->draw_area, "scr4", 0xC386, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    this->create_text(this, &this->title, 0x2BC1,
                      10, 10, 0x26C, 0x32, 1, 3, 0, 0);
    this->create_text(this, &this->filename_title, 0x2BC2,
                      0x14, 0x28, 0x104, 0x14, 4, 0, 0, 0);
    this->create_drop_down(this, &this->filename_drop,
                           0x17C, 0xC8, 0x14, 0x3C, 0x17C,
                           (this->ideal_height * 30) / this->pnl_hgt, 0xB);

    this->create_edit(this->filename_drop, &this->filename,
                      this->get_string(0x2BCA),
                      100, TEditPanel::FormatFileNoExt,
                      0, 0, 0x168, 0x1E, 0xB, 1, 1);

    this->create_button(this, &this->save_button, 0x2BC4,
                        0, 0x1A4, 0x3C, 0xC8, 0x1E, 0, 0, 0);
    this->create_button(this, &this->add_button, 0x2BC5,
                        0, 0x118, 0x104, 0xA0, 0x1E, 0, 0, 0);
    this->create_button(this, &this->remove_button, 0x2BC6,
                        0, 0x1CC, 0x104, 0xA0, 0x1E, 0, 0, 0);
    this->create_text(this, &this->scenarios_title, 0x2BC7,
                      0x14, 0x64, 0xC8, 0x14, 4, 0, 0, 0);
    this->create_list(this, &this->scenarios,
                      0x14, 0x78, 0x258, 0x82, 0xB);
    this->create_auto_scrollbar(&this->scenarios_bar,
                                this->scenarios, 0x14);
    this->create_text(this, &this->campaign_scenarios_title, 0x2BC8,
                      0x14, 0x118, 0xC8, 0x14, 4, 0, 0, 0);
    this->create_list(this, &this->campaign_scenarios,
                      0x14, 0x12C, 0x1F4, 0x82, 0xB);
    this->create_auto_scrollbar(&this->campaign_scenarios_bar,
                                this->campaign_scenarios, 0x14);

    this->create_button(this, &this->ok_button, IDS_BUTTON_OK,
                        0, 0x14, 0x1BD, 0x118, 0x1E, 0, 0, 0);
    this->create_button(this, &this->cancel_button, IDS_BUTTON_CANCEL,
                        0, 0x154, 0x1BD, 0x118, 0x1E, 0, 0, 0);
    TButtonPanel* cancel = this->cancel_button;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    this->create_button(this, &this->move_scenario_up_button, 0x2BD5,
                        0, 0x212, 0x12C, 0x5A, 0x1E, 0, 0, 0);
    this->create_button(this, &this->move_scenario_down_button, 0x2BD6,
                        0, 0x212, 0x154, 0x5A, 0x1E, 0, 0, 0);

    TPanel* tabList[8];
    tabList[0] = this->filename_drop;
    tabList[1] = this->save_button;
    tabList[2] = this->scenarios;
    tabList[3] = this->add_button;
    tabList[4] = this->remove_button;
    tabList[5] = this->campaign_scenarios;
    tabList[6] = this->ok_button;
    tabList[7] = this->cancel_button;
    this->set_tab_order(tabList, 8);

    this->filename_drop->set_curr_child(this->filename);
    this->set_curr_child(this->filename_drop);
    this->fill_scenario_list();
    this->fill_campaign_drop();
    this->campaign_scenarios->empty_list();
    this->load_campaign();
    this->need_to_save = 0;
}

TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen() {
    panel_system.destroyPanel("Cancel Dialog");
    panel_system.destroyPanel("Load Dialog");

    delete this->title;
    delete this->scenarios_title;
    delete this->campaign_scenarios_title;
    delete this->scenarios;
    delete this->scenarios_bar;
    delete this->campaign_scenarios;
    delete this->campaign_scenarios_bar;
    delete this->filename_title;
    delete this->filename;
    delete this->filename_drop;
    delete this->cancel_button;
    delete this->save_button;
    delete this->ok_button;
    delete this->add_button;
    delete this->remove_button;
    delete this->move_scenario_up_button;
    delete this->move_scenario_down_button;
}

void TRIBE_Campaign_Editor_Screen::fill_campaign_drop() {
    char file_name[256];
    _finddata_t file_info;
    long handle;
    int len;

    this->filename_drop->set_sorted(1);
    this->filename_drop->empty_list();

    sprintf(file_name, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name, &file_info);
    while (handle != -1) {
        len = strlen(file_info.name) - 4;
        strncpy(file_name, file_info.name, len);
        file_name[len] = 0;
        this->filename_drop->append_line(file_name, 0);
        if (_findnext(handle, &file_info) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name, &file_info);
    while (handle != -1) {
        len = strlen(file_info.name) - 4;
        strncpy(file_name, file_info.name, len);
        file_name[len] = 0;
        this->filename_drop->append_line(file_name, 0);
        if (_findnext(handle, &file_info) == -1) {
            break;
        }
    }
}

void TRIBE_Campaign_Editor_Screen::fill_scenario_list() {
    char file_name[256];
    _finddata_t file_info;
    long handle;
    int len;

    this->scenarios->sorted = 1;
    this->scenarios->empty_list();

    sprintf(file_name, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &file_info);
    while (handle != -1) {
        len = strlen(file_info.name) - 4;
        strncpy(file_name, file_info.name, len);
        file_name[len] = 0;
        this->scenarios->append_line(file_name, 0);
        if (_findnext(handle, &file_info) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &file_info);
    while (handle != -1) {
        len = strlen(file_info.name) - 4;
        strncpy(file_name, file_info.name, len);
        file_name[len] = 0;
        this->scenarios->append_line(file_name, 0);
        if (_findnext(handle, &file_info) == -1) {
            break;
        }
    }
}

void TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list() {
    if (this->campaign == 0)
        return;

    this->campaign_scenarios->empty_list();

    char** scenario_names;
    long count = this->campaign->scenario_info(&scenario_names);

    if (scenario_names != 0) {
        long i;
        for (i = 0; i < count; i++) {
            this->campaign_scenarios->append_line(scenario_names[i], 0);
            free(scenario_names[i]);
        }
        free(scenario_names);
    }
}

unsigned char TRIBE_Campaign_Editor_Screen::check_lists() {
    int count = campaign_scenarios->numberLines();

    for (int i = 0; i < count; i++) {
        char* text = campaign_scenarios->get_text(i);
        if (scenarios->get_line(text) == -1) {
            return 0;
        }
    }

    {
        for (int i = 0; i < count; i++) {
            char* text = campaign_scenarios->get_text(i);
            long index = scenarios->get_line(text);
            scenarios->delete_line(index);
        }
    }

    return 1;
}

void TRIBE_Campaign_Editor_Screen::load_campaign() {
    char* text = 0;
    char* text2 = 0;
    _finddata_t file_info;

    addstring(&text, this->filename->get_text(), ".cpn");
    addstring(&text2, rge_base_game->prog_info->campaign_dir, text);
    long found = _findfirst(text2, &file_info);
    unsigned char ok;
    if (found == -1) {
        addstring(&text, this->filename->get_text(), ".cpx");
        addstring(&text2, rge_base_game->prog_info->campaign_dir, text);
        found = _findfirst(text2, &file_info);
    }

    if (found != -1) {
        this->campaign = new RGE_Campaign(text);
        this->fill_scenario_list();
        this->fill_campaign_scenario_list();
        ok = this->check_lists();
        if (this->campaign != 0) {
            delete this->campaign;
        }
        this->campaign = 0;
    } else {
        ok = 0;
    }

    if (!ok) {
        this->campaign_scenarios->empty_list();
    }
    free(text);
    free(text2);
    this->need_to_save = 0;
}

void TRIBE_Campaign_Editor_Screen::make_campaign() {
    char* campaign_filename;
    char* text = 0;
    char** scenarios_filenames;
    char** scenarios_text;
    char test[260];
    _finddata_t file_info;
    int count;
    int i;
    RGE_Campaign* new_campaign;

    campaign_filename = this->filename->get_text();
    if (campaign_filename != 0) {
        if (*campaign_filename == 0 || *campaign_filename == ' ') {
            this->popupOKDialog(0x2BCC, 0, 0x1C2, 100);
            // An invalid name returns without clearing need_to_save.
            return;
        } else {
            addstring(&text, campaign_filename, ".cpx");
            count = this->campaign_scenarios->numberLines();
            if (count > 0) {
                scenarios_text = static_cast<char**>(calloc(count, 4));
                scenarios_filenames = static_cast<char**>(calloc(count, 4));
                for (i = 0; i < count; ++i) {
                    getstring(&scenarios_text[i],
                              this->campaign_scenarios->get_text(i));
                    getstring(&scenarios_filenames[i],
                              this->campaign_scenarios->get_text(i));
                    sprintf(test, "%s%s.scn",
                            rge_base_game->prog_info->scenario_dir,
                            scenarios_filenames[i]);
                    if (_findfirst(test, &file_info) == -1) {
                        addstring(&scenarios_filenames[i], scenarios_filenames[i],
                                  ".scx");
                    } else {
                        addstring(&scenarios_filenames[i], scenarios_filenames[i],
                                  ".scn");
                    }
                }

                new_campaign = new RGE_Campaign(
                    text, campaign_filename, count, scenarios_filenames,
                    scenarios_text);
                this->campaign = new_campaign;
                if (new_campaign != 0) {
                    delete new_campaign;
                }
                this->campaign = 0;

                for (i = 0; i < count; ++i) {
                    free(scenarios_text[i]);
                    free(scenarios_filenames[i]);
                }
                free(scenarios_text);
                free(scenarios_filenames);
            } else {
                this->popupOKDialog(0x2BCB, 0, 0x1C2, 100);
            }
            free(text);
            this->fill_campaign_drop();
            rge_base_game->find_campaigns();
        }
    }
    this->need_to_save = 0;
}

void TRIBE_Campaign_Editor_Screen::add_scenario() {
    char* text = this->scenarios->get_text();

    if (text != 0 && *text != '\0') {
        this->campaign_scenarios->append_line(text, 0);

        long line = this->campaign_scenarios->get_line(text);
        this->campaign_scenarios->set_line(line);

        long line2 = this->scenarios->get_line();
        this->scenarios->delete_line(line2);

        this->campaign_scenarios->scroll_cur_line(
            1, this->campaign_scenarios->get_line(), 1);
    }

    this->need_to_save = 1;
}

void TRIBE_Campaign_Editor_Screen::remove_scenario() {
    char* text = this->campaign_scenarios->get_text();
    if (text != 0 && text[0] != 0) {
        this->scenarios->append_line(text, 0);
        long line = this->scenarios->get_line(text);
        this->scenarios->set_line(line);
        line = this->campaign_scenarios->get_line();
        this->campaign_scenarios->delete_line(line);
        this->scenarios->scroll_cur_line(
            1, this->scenarios->get_line(), 1);
    }
    this->need_to_save = 1;
}

void TRIBE_Campaign_Editor_Screen::move_scenario_up() {
    if (this->campaign_scenarios->get_line() <= 0) {
        return;
    }

    char* text = this->campaign_scenarios->get_text();
    if (text != 0 && text[0] != 0) {
        this->campaign_scenarios->insert_line(
            this->campaign_scenarios->get_line() - 1, text, 0);

        this->campaign_scenarios->delete_line(
            this->campaign_scenarios->get_line() + 1);

        this->campaign_scenarios->set_line(
            this->campaign_scenarios->get_line() - 1);

        this->campaign_scenarios->scroll_cur_line(
            1, this->campaign_scenarios->get_line(), 1);
    }

    this->need_to_save = 1;
}

void TRIBE_Campaign_Editor_Screen::move_scenario_down() {
    int last_line = this->campaign_scenarios->numberLines() - 1;
    long line = this->campaign_scenarios->get_line();

    if (line < last_line) {
        char* text = this->campaign_scenarios->get_text();
        if (text != 0 && text[0] != 0) {
            this->campaign_scenarios->insert_line(
                this->campaign_scenarios->get_line() + 2, text, 0);
            this->campaign_scenarios->delete_line(
                this->campaign_scenarios->get_line());
            this->campaign_scenarios->set_line(
                this->campaign_scenarios->get_line() + 1);
            this->campaign_scenarios->scroll_cur_line(
                1, this->campaign_scenarios->get_line(), 1);
        }
        this->need_to_save = 1;
    }
}

long TRIBE_Campaign_Editor_Screen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    char str[256];
    char text[300];

    if (fromPanel == 0)
        return this->TEasy_Panel::action(fromPanel, actionIn, a1, a2);

    if (fromPanel == this->filename_drop && actionIn == 2) {
        this->filename_drop->set_curr_child(this->filename);
        this->set_curr_child(this->filename_drop);
    }

    if (actionIn == 3) {
        if (fromPanel == this->scenarios) {
            this->add_scenario();
        } else if (fromPanel == this->campaign_scenarios) {
            this->remove_scenario();
        }
    }

    if (fromPanel == this->filename_drop && actionIn == 0) {
        if (this->need_to_save > 0 && this->campaign_scenarios->numberLines() > 0) {
            this->get_string(0x2bc9, str, 0x100);
            sprintf(text, str, this->filename->get_text());
            this->popupYesNoCancelDialog(text, "Load Dialog", 0x1c2, 100);
        } else {
            this->filename->set_text(this->filename_drop->get_text());
            this->load_campaign();
        }
    }

    if (actionIn == 1) {
        if (fromPanel == this->ok_button) {
            if (this->need_to_save > 0 && this->campaign_scenarios->numberLines() > 0) {
                this->get_string(0x2bc9, str, 0x100);
                sprintf(text, str, this->filename->get_text());
                this->popupYesNoCancelDialog(text, "Cancel Dialog", 0x1c2, 100);
            } else {
                new TRIBE_Screen_Sed_Menu;
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
                panel_system.destroyPanel("Campaign Editor Screen");
                return 1;
            }
        } else if (fromPanel == this->save_button) {
            this->make_campaign();
        } else if (fromPanel == this->cancel_button) {
            new TRIBE_Screen_Sed_Menu;
            panel_system.setCurrentPanel("Scenario Editor Menu", 0);
            panel_system.destroyPanel("Campaign Editor Screen");
            return 1;
        } else if (fromPanel == this->add_button) {
            this->add_scenario();
        } else if (fromPanel == this->remove_button) {
            this->remove_scenario();
        } else if (fromPanel == this->move_scenario_up_button) {
            this->move_scenario_up();
        } else if (fromPanel == this->move_scenario_down_button) {
            this->move_scenario_down();
        }
    }

    if (fromPanel->panelName() &&
        strcmp(fromPanel->panelName(), "Cancel Dialog") == 0) {
        panel_system.destroyPanel("Cancel Dialog");
        if (actionIn == 0) {
            this->make_campaign();
        }
        if (actionIn == 0 || actionIn == 1) {
            new TRIBE_Screen_Sed_Menu;
            panel_system.setCurrentPanel("Scenario Editor Menu", 0);
            panel_system.destroyPanel("Campaign Editor Screen");
        }
        return 1;
    }

    if (fromPanel->panelName() &&
        strcmp(fromPanel->panelName(), "Load Dialog") == 0) {
        panel_system.destroyPanel("Load Dialog");
        if (actionIn == 0) {
            this->make_campaign();
        }
        if (actionIn == 0 || actionIn == 1) {
            this->filename->set_text(this->filename_drop->get_text());
            this->load_campaign();
        }
        return 1;
    }

    return this->TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}
