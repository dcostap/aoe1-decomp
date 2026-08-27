#include "../include/scr_sels.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static const char s_fmt_range[] = "%d - %d";
static const char s_fmt_num[] = "%d";

TribeSelectScenarioScreen::TribeSelectScenarioScreen()
    : TScreenPanel(s_Select_Scenario_Screen)
{
    char* setup_file;
    TDrawArea* draw_area;
    int multiplayer;

    this->init_vars();

    multiplayer = rge_base_game->multiplayerGame();
    setup_file = s_scr3;
    if (multiplayer == 0)
        setup_file = s_scr2;

    draw_area = rge_base_game->draw_area;

    if (!this->TEasy_Panel::setup(draw_area, 0, setup_file,
                                  (rge_base_game->multiplayerGame() != 0) +
                                      0xC384,
                                  1, 0, 0, 0, 0, 1)) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x25FA,
                          0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 0)) {
        this->scenarioListX = 0x14;
        this->scenarioListY = 0x46;
        this->scenarioListWidth = 0x258;
        this->scenarioListHeight = 0x107;

        if (this->create_list(this, &this->scenarioList,
                              0x14, 0x46, 0x258, 0x107, 0x0B)) {
            this->scenarioList->set_second_column_pos(
                ((this->scenarioListWidth - 0x3C) * this->pnl_wid) /
                this->ideal_width);
            this->scenarioList->set_text((long)0x25FD);

            if (this->create_auto_scrollbar(&this->scenarioScrollbar,
                                            this->scenarioList, 0x14)) {
                this->scenarioScrollbar->set_help_info(-1, -1);

                if (this->create_text(this, &this->scenarioTitle, 0x25FE,
                                      this->scenarioListX,
                                      this->scenarioListY - 0x14,
                                      0x12C, 0x14, 4, 0, 0, 0)) {
                    if (this->create_text(this, &this->scenarioPlayersTitle,
                                          0x25FF,
                                          this->scenarioListWidth - 0xDC +
                                              this->scenarioListX,
                                          this->scenarioListY - 0x14,
                                          0xC8, 0x14, 4, 0, 0, 0)) {
                        this->scenarioPlayersTitle->set_alignment(3, 2);

                        this->missionTextX = this->scenarioListX;
                        this->missionTextY = this->scenarioListHeight +
                                             this->scenarioListY + 0x19;
                        this->missionTextWidth = this->scenarioListWidth;
                        this->missionTextHeight = 0x3C;

                        if (this->create_text(this, &this->missionTitle,
                                              0x2600, this->missionTextX,
                                              this->missionTextY - 0x14,
                                              0x190, 0x14, 4, 0, 0, 0)) {
                            if (this->create_text(
                                    this, &this->missionText,
                                    s_592A40, this->missionTextX,
                                    this->missionTextY,
                                    this->missionTextWidth,
                                    this->missionTextHeight,
                                    0x0B, 0, 0, 1)) {
                                this->missionText->set_bevel_info(
                                    3, this->desc[0], this->desc[1],
                                    this->desc[2], this->desc[3],
                                    this->desc[4], this->desc[5]);

                                if (this->create_auto_scrollbar(
                                        &this->missionScrollbar,
                                        this->missionText, 0x14)) {
                                    this->missionScrollbar->set_help_info(
                                        0x7532, -1);

                                    if (this->create_button(
                                            this, &this->okButton, 0x0FA1,
                                            0, 0x46, 0x1B8, 0xF0, 0x1E,
                                            0, 0, 0)) {
                                        this->okButton->set_help_info(
                                            0x7531, -1);

                                        if (this->create_button(
                                                this, &this->cancelButton,
                                                0x0FA2, 0, 0x14A, 0x1B8,
                                                0xF0, 0x1E, 0, 0, 0)) {
                                            this->cancelButton->set_help_info(
                                                0x7532, -1);
                                            TButtonPanel* cancel =
                                                this->cancelButton;
                                            cancel->hotkey = 0x1B;
                                            cancel->hotkey_shift = 0;

                                            if (this->create_button(
                                                    this, &this->close_button,
                                                    0x03EA, 0, 0, 0, 0, 0,
                                                    -1, -1, 0)) {
                                                this->close_button->set_active(1);
                                                this->close_button->set_positioning(
                                                    9, 4, 4, 4, 4, 0x11,
                                                    0x11, 0x11, 0x11, 0, 0,
                                                    0, 0);
                                                this->fillScenarios();
                                                this->scenariosLoaded = 1;
                                                this->getSettings();
                                                this->fillMissionText();
                                                this->activatePanels();
                                                this->set_curr_child(
                                                    this->scenarioList);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void TribeSelectScenarioScreen::init_vars() {
    last_scenario_line = -1;
    title = 0;
    scenarioTitle = 0;
    scenarioPlayersTitle = 0;
    scenarioList = 0;
    scenarioScrollbar = 0;
    scenarioCount = 0;
    scenarioMission = 0;
    scenarioFixed = 0;
    scenariosLoaded = 0;
    missionTitle = 0;
    missionText = 0;
    missionScrollbar = 0;
    okButton = 0;
    cancelButton = 0;
    close_button = 0;
}

TribeSelectScenarioScreen::~TribeSelectScenarioScreen() {
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
}

long TribeSelectScenarioScreen::handle_idle() {
    if (this->scenariosLoaded == 0) {
        this->fillScenarios();
        this->fillMissionText();
        this->scenariosLoaded = 1;
        this->activatePanels();
        this->set_curr_child(this->scenarioList);
    }
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeSelectScenarioScreen::action(TPanel* panel, long event,
                                        unsigned long p3, unsigned long p4)
{
    if (panel != 0 && this->scenariosLoaded != 0) {
        if (panel == this->okButton && event == 1) {
            this->set_curr_child(this->scenarioList);
            this->sendSettings();
            rge_base_game->disable_input();
            new TribeMPSetupScreen;
            panel_system.setCurrentPanel((char*)0x5861AC, 0);
            panel_system.destroyPanel((char*)0x5868B0);
            return 1;
        }
        if (panel == this->cancelButton && event == 1) {
            this->set_curr_child(this->scenarioList);
            rge_base_game->disable_input();
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel((char*)0x586638, 0);
            panel_system.destroyPanel((char*)0x5868B0);
            return 1;
        }
        if (panel == this->close_button && event == 1) {
            rge_base_game->close();
            return 1;
        }
        if (panel == this->scenarioList) {
            if (event == 3) {
                this->action(this->okButton, 1, 0, 0);
                return 1;
            }
            if (event == 1) {
                this->fillMissionText();
                this->activatePanels();
                return 1;
            }
        }
    }
    return TPanel::action(panel, event, p3, p4);
}

void TribeSelectScenarioScreen::fillScenarios()
{
    RGE_Scenario_File_Info* scenario_info_file;
    char* name;
    int i;
    int len;
    char player_str[20];
    char file_name[260];
    char scenario_file[260];

    scenario_info_file = rge_base_game->scenario_info;
    scenario_info_file->reload_scenarios();
    this->scenarioList->empty_list();
    this->scenarioList->field_15c = 1;
    this->scenarioCount = 0;
    while (1) {
        name = scenario_info_file->get_scenario_name(this->scenarioCount);
        if (name == 0) break;
        len = strlen(name) - 4;
        strncpy(file_name, name, len);
        file_name[len] = 0;
        this->scenarioList->append_line(file_name, this->scenarioCount);
        this->scenarioCount++;
    }
    this->scenarioMission = (char**)calloc(this->scenarioCount, 4);
    this->scenarioFixed = (int*)calloc(this->scenarioCount, 4);
    if (this->scenarioMission == 0 || this->scenarioFixed == 0) return;
    i = 0;
    if (this->scenarioCount <= 0) return;
    do {
        long id = this->scenarioList->get_id(i);
        RGE_Scenario_Header* hdr = scenario_info_file->get_scenario_info(id);
        if (hdr != 0) {
            this->scenarioMission[i] = (char*)calloc(0x1000, 1);
            if (this->scenarioMission[i] != 0 && hdr->description != 0) {
                strcpy(this->scenarioMission[i], hdr->description);
            }
            this->scenarioFixed[i] = hdr->fixed;
            int players = hdr->num_players;
            if (players > 0) {
                if (this->scenarioFixed[i] == 0 && players >= 3) {
                    sprintf(player_str, s_fmt_range, 2, players);
                } else {
                    sprintf(player_str, s_fmt_num, players);
                }
                strcpy(scenario_file, this->scenarioList->get_text(i));
                this->scenarioList->change_line(i, scenario_file, player_str, 0);
            }
        }
        i++;
    } while (i < this->scenarioCount);
}

void TribeSelectScenarioScreen::fillMissionText() {
    long line;

    this->missionText->set_text((char*)0x592A40);
    line = this->scenarioList->get_line();
    if (line >= 0) {
        this->missionText->set_text(this->scenarioMission[line]);
    }
    this->last_scenario_line = line;
}

void TribeSelectScenarioScreen::getSettings() {
    this->last_scenario_line = -1;

    char* scenarioName = rge_base_game->scenarioName();
    long line = this->scenarioList->get_line(scenarioName);

    if (line != -1) {
        this->scenarioList->scroll_cur_line(1, line, 1);
        this->last_scenario_line = line - 1;
    } else {
        this->scenarioList->scroll_cur_line(1, 0, 1);
    }
}

void TribeSelectScenarioScreen::sendSettings(void) {
    rge_base_game->setScenarioGame(1);
    rge_base_game->setScenarioName(this->scenarioList->get_text());
    rge_base_game->setDeathMatch(0);
}

void TribeSelectScenarioScreen::activatePanels() {
    this->missionTitle->set_active(1);
    this->missionText->set_active(1);

    TPanel* tabList[4];
    tabList[0] = this->scenarioList;
    tabList[1] = this->okButton;
    tabList[2] = this->cancelButton;

    this->set_tab_order(tabList, 3);

    TPanelState* state = this->field_3C;
    if (state == 0 || state->child == 0) {
        this->set_curr_child(this->okButton);
    }
}
