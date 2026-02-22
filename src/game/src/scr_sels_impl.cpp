#include "../include/TribeSelectScenarioScreen.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/TribeMPSetupScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/RGE_Scenario_File_Info.h"
#include "../include/RGE_Scenario_File_Entry.h"
#include "../include/RGE_Scenario_Header.h"
#include "../include/TTextPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace {

void sels_enable_input() {
    if (!rge_base_game) return;
    rge_base_game->enable_input();
}

void sels_free_cached_scenarios(TribeSelectScenarioScreen* owner) {
    if (!owner) return;
    if (owner->scenarioMission) {
        for (int i = 0; i < owner->scenarioCount; ++i) {
            if (owner->scenarioMission[i]) {
                free(owner->scenarioMission[i]);
            }
        }
        free(owner->scenarioMission);
        owner->scenarioMission = nullptr;
    }

    if (owner->scenarioFixed) {
        free(owner->scenarioFixed);
        owner->scenarioFixed = nullptr;
    }

    owner->scenarioCount = 0;
}

void sels_set_mission_text(TribeSelectScenarioScreen* owner) {
    if (!owner || !owner->missionText) return;

    if (!owner->scenarioMission || owner->scenarioCount <= 0) {
        owner->missionText->set_text((char*)"");
        owner->last_scenario_line = -1;
        return;
    }

    int idx = 0;
    if (owner->scenarioList) {
        long line = ((TTextPanel*)owner->scenarioList)->get_line();
        if (line >= 0 && line < owner->scenarioCount) {
            idx = (int)line;
        }
    } else if (owner->last_scenario_line >= 0 && owner->last_scenario_line < owner->scenarioCount) {
        idx = owner->last_scenario_line;
    }

    owner->missionText->set_text(owner->scenarioMission[idx]);
    owner->last_scenario_line = idx;
}

void sels_fill_scenario_list(TribeSelectScenarioScreen* owner) {
    if (!owner || !owner->scenarioList || !rge_base_game || !rge_base_game->scenario_info) {
        return;
    }

    TTextPanel* list_text = (TTextPanel*)owner->scenarioList;
    list_text->empty_list();
    list_text->sorted = 1;

    RGE_Scenario_File_Info* info = rge_base_game->scenario_info;
    if (!info->scenarios || info->scenario_num <= 0) {
        list_text->append_line((long)0x25fd, 0); // "Loading list of scenarios..."
        return;
    }

    for (int i = 0; i < (int)info->scenario_num; ++i) {
        RGE_Scenario_File_Entry* entry = &info->scenarios[i];
        const char* scen_name = (entry->name[0] != '\0') ? entry->name : "(unnamed scenario)";
        list_text->append_line((char*)scen_name, i);
    }
}

int sels_load_scenarios(TribeSelectScenarioScreen* owner) {
    if (!owner || !rge_base_game || !rge_base_game->scenario_info) {
        return 0;
    }

    sels_free_cached_scenarios(owner);

    RGE_Scenario_File_Info* info = rge_base_game->scenario_info;
    if (!info->scenarios || info->scenario_num <= 0) {
        return 0;
    }

    owner->scenarioCount = (int)info->scenario_num;
    owner->scenarioMission = (char**)calloc(owner->scenarioCount, sizeof(char*));
    owner->scenarioFixed = (int*)calloc(owner->scenarioCount, sizeof(int));
    if (!owner->scenarioMission || !owner->scenarioFixed) {
        sels_free_cached_scenarios(owner);
        return 0;
    }

    owner->last_scenario_line = 0;
    for (int i = 0; i < owner->scenarioCount; ++i) {
        owner->scenarioFixed[i] = i;
        RGE_Scenario_File_Entry* entry = &info->scenarios[i];
        const char* scen_name = entry->name;
        if (!scen_name || scen_name[0] == '\0') {
            scen_name = "(unnamed scenario)";
        }

        const char* desc = "";
        if (entry->scenario_header && entry->scenario_header->description) {
            desc = entry->scenario_header->description;
        }

        char text[4096];
        text[0] = '\0';
        if (desc && desc[0] != '\0') {
            snprintf(text, sizeof(text), "%s\r\n\r\n%s", scen_name, desc);
        } else {
            snprintf(text, sizeof(text), "%s", scen_name);
        }
        text[sizeof(text) - 1] = '\0';

        size_t len = strlen(text);
        owner->scenarioMission[i] = (char*)calloc(len + 1, 1);
        if (owner->scenarioMission[i]) {
            memcpy(owner->scenarioMission[i], text, len + 1);
        }
    }

    // Best-effort current selection recovery.
    owner->last_scenario_line = 0;
    if (rge_base_game->rge_game_options.scenarioNameValue[0] != '\0') {
        const char* wanted = rge_base_game->rge_game_options.scenarioNameValue;
        for (int i = 0; i < owner->scenarioCount; ++i) {
            if (_stricmp(info->scenarios[i].name, wanted) == 0) {
                owner->last_scenario_line = i;
                break;
            }
        }
    }

    sels_fill_scenario_list(owner);
    if (owner->scenarioList) {
        owner->scenarioList->scroll_cur_line(1, (short)owner->last_scenario_line, 1);
    }
    return 1;
}

void sels_activate_panels(TribeSelectScenarioScreen* owner) {
    if (!owner) return;

    if (owner->missionTitle) owner->missionTitle->set_active(1);
    if (owner->missionText) owner->missionText->set_active(1);

    TPanel* tabs[3];
    tabs[0] = (TPanel*)owner->scenarioList;
    tabs[1] = (TPanel*)owner->okButton;
    tabs[2] = (TPanel*)owner->cancelButton;
    owner->set_tab_order(tabs, 3);
    if (owner->okButton) owner->curr_child = (TPanel*)owner->okButton;
}

void sels_send_settings(TribeSelectScenarioScreen* owner) {
    if (!owner || !rge_base_game || !rge_base_game->scenario_info) return;

    const char* scenario_name = "";
    if (owner->scenarioList) {
        TTextPanel* list_text = (TTextPanel*)owner->scenarioList;
        long line = list_text->get_line();
        char* text = (line >= 0) ? list_text->get_text(line) : nullptr;
        if (text && text[0] != '\0') {
            scenario_name = text;
        }
    }

    rge_base_game->setScenarioGame(1);
    rge_base_game->setScenarioName((char*)scenario_name);
    ((TRIBE_Game*)rge_base_game)->setDeathMatch(0);
}

} // namespace

TribeSelectScenarioScreen::TribeSelectScenarioScreen() : TScreenPanel((char*)"Select Scenario Screen") {
    this->last_scenario_line = -1;
    this->title = nullptr;
    this->scenarioTitle = nullptr;
    this->scenarioPlayersTitle = nullptr;
    this->scenarioListX = 0;
    this->scenarioListY = 0;
    this->scenarioListWidth = 0;
    this->scenarioListHeight = 0;
    this->scenarioList = nullptr;
    this->scenarioScrollbar = nullptr;
    this->scenarioCount = 0;
    this->scenarioMission = nullptr;
    this->scenarioFixed = nullptr;
    this->scenariosLoaded = 0;
    this->missionTitle = nullptr;
    this->missionTextX = 0;
    this->missionTextY = 0;
    this->missionTextWidth = 0;
    this->missionTextHeight = 0;
    this->missionText = nullptr;
    this->missionScrollbar = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->close_button = nullptr;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    char* setup_name = (rge_base_game->rge_game_options.multiplayerGameValue != 0) ? (char*)"scr3" : (char*)"scr2";
    long setup_id = (rge_base_game->rge_game_options.multiplayerGameValue != 0) ? 0xc385 : 0xc384;
    if (!TEasy_Panel::setup(rge_base_game->draw_area, (TPanel*)0, setup_name, setup_id, 1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    if (!this->create_text((TPanel*)this, &this->title, 0x25fa, 0x14, 0x0a, 600, 0x1e, 1, 1, 0, 0)) {
        this->error_code = 1;
        return;
    }

    this->scenarioListX = 0x14;
    this->scenarioListY = 0x46;
    this->scenarioListWidth = 600;
    this->scenarioListHeight = 0x107;

    if (!this->create_list((TPanel*)this, &this->scenarioList, this->scenarioListX, this->scenarioListY, this->scenarioListWidth, this->scenarioListHeight, 0xb)) {
        this->error_code = 1;
        return;
    }
    this->scenarioList->set_second_column_pos((this->pnl_wid * (this->scenarioListWidth - 0x3c)) / this->ideal_width);
    this->scenarioList->set_text((long)0x25fd); // "Loading list of scenarios..."
    if (!this->create_auto_scrollbar(&this->scenarioScrollbar, (TTextPanel*)this->scenarioList, 0x14)) {
        this->error_code = 1;
        return;
    }
    if (this->scenarioScrollbar) {
        this->scenarioScrollbar->set_help_info(-1, -1);
    }

    if (!this->create_text((TPanel*)this, &this->scenarioTitle, 0x25fe, this->scenarioListX, this->scenarioListY - 0x14, 300, 0x14, 4, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_text((TPanel*)this, &this->scenarioPlayersTitle, 0x25ff,
                           this->scenarioListX + this->scenarioListWidth - 0xdc, this->scenarioListY - 0x14,
                           200, 0x14, 4, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->scenarioPlayersTitle->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);

    this->missionTextX = this->scenarioListX;
    this->missionTextY = this->scenarioListY + this->scenarioListHeight + 0x19;
    this->missionTextWidth = this->scenarioListWidth;
    this->missionTextHeight = 0x3c;

    if (!this->create_text((TPanel*)this, &this->missionTitle, 0x2600, this->missionTextX, this->missionTextY - 0x14, 400, 0x14, 4, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_text((TPanel*)this, &this->missionText, (char*)"", this->missionTextX, this->missionTextY, this->missionTextWidth, this->missionTextHeight, 0xb, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }
    if (this->use_bevels) {
        this->missionText->set_bevel_info(3,
            (int)this->bevel_color1, (int)this->bevel_color2,
            (int)this->bevel_color3, (int)this->bevel_color4,
            (int)this->bevel_color5, (int)this->bevel_color6);
    }
    if (!this->create_auto_scrollbar(&this->missionScrollbar, this->missionText, 0x14)) {
        this->error_code = 1;
        return;
    }
    if (this->missionScrollbar) {
        this->missionScrollbar->set_help_info(0x7532, -1);
    }

    if (!this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x46, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->okButton->set_help_info(0x7531, -1);

    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x14a, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->cancelButton->set_help_info(0x7532, -1);
    this->cancelButton->hotkey = 0x1b;
    this->cancelButton->hotkey_shift = 0;

    if (!this->create_button((TPanel*)this, &this->close_button, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0)) {
        this->error_code = 1;
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, (TPanel*)0, (TPanel*)0, (TPanel*)0, (TPanel*)0);

    const int loaded = sels_load_scenarios(this);
    this->scenariosLoaded = 1; // Source of truth: scr_sels.cpp.decomp sets this after the first attempt.
    if (loaded) {
        sels_set_mission_text(this);
    } else {
        this->missionText->set_text((char*)"No scenarios available.");
    }
    sels_activate_panels(this);
    this->set_curr_child((TPanel*)this->scenarioList);
}

TribeSelectScenarioScreen::~TribeSelectScenarioScreen() {
    // Source of truth: Scr_sels.cpp.decomp @ 0x004B4190
    // Delete all child panels before base destructor runs
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->scenarioTitle);
    this->delete_panel((TPanel**)&this->scenarioPlayersTitle);
    this->delete_panel((TPanel**)&this->scenarioList);
    this->delete_panel((TPanel**)&this->scenarioScrollbar);
    this->delete_panel((TPanel**)&this->missionTitle);
    this->delete_panel((TPanel**)&this->missionText);
    this->delete_panel((TPanel**)&this->missionScrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->close_button);
    sels_free_cached_scenarios(this);
}

long TribeSelectScenarioScreen::handle_idle() {
    if (this->scenariosLoaded == 0) {
        const int loaded = sels_load_scenarios(this);
        if (loaded) {
            sels_set_mission_text(this);
        } else if (this->missionText) {
            this->missionText->set_text((char*)"No scenarios available.");
        }
        this->scenariosLoaded = 1;
        sels_activate_panels(this);
        this->set_curr_child((TPanel*)this->scenarioList);
    }

    if (rge_base_game && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeSelectScenarioScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: scr_sels.cpp.decomp @ 0x004B42E0
    if (param_1 && this->scenariosLoaded != 0) {
        if ((TButtonPanel*)param_1 == this->okButton && param_2 == 1) {
            this->set_curr_child((TPanel*)this->scenarioList);
            sels_send_settings(this);
            rge_base_game->disable_input();

            TribeMPSetupScreen* setup = new TribeMPSetupScreen();
            if (setup && setup->error_code == 0) {
                panel_system->setCurrentPanel((TPanel*)setup, 0);
                panel_system->destroyPanel("Select_Scenario_Screen");
            } else {
                if (setup) delete setup;
                sels_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->cancelButton && param_2 == 1) {
            this->set_curr_child((TPanel*)this->scenarioList);
            rge_base_game->disable_input();

            TribeSPMenuScreen* menu = new TribeSPMenuScreen();
            if (menu && menu->error_code == 0) {
                panel_system->setCurrentPanel((TPanel*)menu, 0);
                panel_system->destroyPanel("Select_Scenario_Screen");
            } else {
                if (menu) delete menu;
                sels_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->close_button && param_2 == 1) {
            rge_base_game->close();
            return 1;
        }

        // Handle scenario list interactions
        if ((TListPanel*)param_1 == this->scenarioList) {
            if (param_2 == 3) {
                // Double-click triggers OK action
                return this->action((TPanel*)this->okButton, 1, 0, 0);
            }
            if (param_2 == 1) {
                // Single click updates mission text
                sels_set_mission_text(this);
                sels_activate_panels(this);
                return 1;
            }
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TribeSelectScenarioScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeSelectScenarioScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeSelectScenarioScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeSelectScenarioScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeSelectScenarioScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeSelectScenarioScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeSelectScenarioScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeSelectScenarioScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeSelectScenarioScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeSelectScenarioScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeSelectScenarioScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeSelectScenarioScreen::draw() { TScreenPanel::draw(); }
void TribeSelectScenarioScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeSelectScenarioScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeSelectScenarioScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeSelectScenarioScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeSelectScenarioScreen::paint() { TScreenPanel::paint(); }
long TribeSelectScenarioScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeSelectScenarioScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeSelectScenarioScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectScenarioScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeSelectScenarioScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeSelectScenarioScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeSelectScenarioScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeSelectScenarioScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeSelectScenarioScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectScenarioScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectScenarioScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectScenarioScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeSelectScenarioScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeSelectScenarioScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeSelectScenarioScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeSelectScenarioScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeSelectScenarioScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeSelectScenarioScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeSelectScenarioScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeSelectScenarioScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeSelectScenarioScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeSelectScenarioScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeSelectScenarioScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeSelectScenarioScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeSelectScenarioScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeSelectScenarioScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeSelectScenarioScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectScenarioScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectScenarioScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSelectScenarioScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSelectScenarioScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectScenarioScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectScenarioScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeSelectScenarioScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeSelectScenarioScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeSelectScenarioScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSelectScenarioScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeSelectScenarioScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeSelectScenarioScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeSelectScenarioScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeSelectScenarioScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeSelectScenarioScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
