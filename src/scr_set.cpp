#include "../include/scr_set.h"
#include "../include/tribegam.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/pnl_drop.h"
#include "../include/scr_mps.h"
#include "../include/scenario.h"
#include "../include/sceninfo.h"
#include "../include/tscenaro.h"
#include "../include/com_hand.h"
#include "../include/rge_base_game_global.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TribeGameSettingsScreen::TribeGameSettingsScreen()
    : TScreenPanel("Game Settings Screen")
{
    char num_str[5];
    char* setup_file;
    int multiplayer;
    TDrawArea* draw_area;

    this->init_vars();
    this->chat_scr = static_cast<TribeMPSetupScreen*>(
        panel_system.panel("MP Setup Screen"));

    multiplayer = rge_base_game->multiplayerGame();
    setup_file = "scr3";
    if (multiplayer == 0)
        setup_file = "scr2";

    draw_area = rge_base_game->draw_area;

    if (!this->TEasy_Panel::setup(
            draw_area, 0, setup_file,
            (rge_base_game->multiplayerGame() != 0) + 0xC384,
            1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (!this->create_text(this, &this->title, 0x2616,
                           0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 1))
        return;

    if (!this->create_text(this, &this->mapSizeLabel, 0x29A0,
                           0x14, 0xD8, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->mapSizeDrop,
                                0xB4, 100, 0x14, 0xEC, 0xB4, 0x18, 0x0B))
        return;
    this->mapSizeDrop->empty_list();
    this->mapSizeDrop->append_line(0x2973, 0);
    this->mapSizeDrop->append_line(0x2974, 1);
    this->mapSizeDrop->append_line(0x2975, 2);
    this->mapSizeDrop->append_line(0x2976, 3);
    this->mapSizeDrop->append_line(0x2977, 4);
    this->mapSizeDrop->append_line(0x2978, 5);
    this->mapSizeDrop->set_help_info(0x762A, -1);

    if (!this->create_text(this, &this->mapTypeLabel, 0x25DB,
                           0xDC, 0xD8, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->mapTypeDrop,
                                0xB4, 100, 0xDC, 0xEC, 0xB4, 0x18, 0x0B))
        return;
    this->mapTypeDrop->empty_list();
    this->mapTypeDrop->append_line(0x296A, 0);
    this->mapTypeDrop->append_line(0x296B, 1);
    this->mapTypeDrop->append_line(0x296C, 2);
    this->mapTypeDrop->append_line(0x296D, 3);
    this->mapTypeDrop->append_line(0x296E, 4);
    this->mapTypeDrop->append_line(0x296F, 5);
    this->mapTypeDrop->append_line(0x2970, 6);
    this->mapTypeDrop->append_line(0x2971, 7);
    this->mapTypeDrop->append_line(0x2972, 8);
    this->mapTypeDrop->set_help_info(0x762B, -1);

    if (!this->create_text(this, &this->victoryTypeLabel, 0x2A34,
                           0x14, 0x108, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->victoryTypeDrop,
                                0xB4, 100, 0x14, 0x11C, 0xB4, 0x18, 0x0B))
        return;
    this->victoryTypeDrop->empty_list();
    if (rge_base_game->scenarioGame() != 0) {
        this->victoryTypeDrop->append_line(0x10E7, 0);
        this->victoryTypeDrop->append_line(0x10EC, 9);
    } else {
        this->victoryTypeDrop->append_line(0x10EC, 0);
    }
    this->victoryTypeDrop->append_line(0x10E1, 1);
    this->victoryTypeDrop->append_line(0x10E9, 7);
    this->victoryTypeDrop->append_line(0x10EA, 8);
    this->victoryTypeDrop->set_help_info(0x762C, 0x25F0A);

    if (!this->create_text(this, &this->timeLabel, 0x10E9,
                           0x14, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->timeDrop,
                                0xB4, 100, 0x14, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->timeDrop->empty_list();
    this->timeDrop->append_line(0x2634, 15000);
    this->timeDrop->append_line(0x2635, 13000);
    this->timeDrop->append_line(0x2636, 11000);
    this->timeDrop->append_line(0x2637, 9000);
    this->timeDrop->append_line(0x2638, 7000);
    this->timeDrop->append_line(0x2639, 5000);
    this->timeDrop->append_line(0x263A, 3000);
    this->timeDrop->set_help_info(0x763B, -1);

    if (!this->create_text(this, &this->scoreLabel, 0x10EA,
                           0x14, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->scoreDrop,
                                0xB4, 100, 0x14, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->scoreDrop->empty_list();
    this->scoreDrop->append_line("3000", 3000);
    this->scoreDrop->append_line("2700", 2700);
    this->scoreDrop->append_line("2400", 0x960);
    this->scoreDrop->append_line("2100", 0x834);
    this->scoreDrop->append_line("1800", 0x708);
    this->scoreDrop->append_line("1500", 0x5DC);
    this->scoreDrop->append_line("1200", 0x4B0);
    this->scoreDrop->append_line("900", 900);
    this->scoreDrop->append_line("800", 800);
    this->scoreDrop->append_line("700", 700);
    this->scoreDrop->append_line("600", 600);
    this->scoreDrop->append_line("500", 500);
    this->scoreDrop->append_line("400", 400);
    this->scoreDrop->append_line("300", 300);
    this->scoreDrop->set_help_info(0x763C, -1);

    if (!this->create_text(this, &this->victoryFixedText, 0x25D9,
                           0x14, 0x108, 0xB4, 0x5C, 0x0B, 1, 1, 1))
        return;
    this->victoryFixedText->set_bevel_info(3, this->bevel_color1,
                                           this->bevel_color2,
                                           this->bevel_color3,
                                           this->bevel_color4,
                                           this->bevel_color5,
                                           this->bevel_color6);

    if (!this->create_text(this, &this->ageLabel, 0x2606,
                           0xDC, 0x108, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->ageDrop,
                                0xB4, 100, 0xDC, 0x11C, 0xB4, 0x18, 0x0B))
        return;
    this->ageDrop->empty_list();
    this->ageDrop->append_line(0x10E7, 0);
    this->ageDrop->append_line(0x106E, 1);
    this->ageDrop->append_line(0x1069, 2);
    this->ageDrop->append_line(0x106A, 3);
    this->ageDrop->append_line(0x106B, 4);
    this->ageDrop->append_line(0x106C, 5);
    this->ageDrop->set_help_info(0x7631, -1);

    if (!this->create_text(this, &this->resourcesLabel, 0x2607,
                           0xDC, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->resourcesDrop,
                                0xB4, 100, 0xDC, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->resourcesDrop->empty_list();
    this->resourcesDrop->append_line(0x10E7, 0);
    this->resourcesDrop->append_line(0x2609, 2);
    this->resourcesDrop->append_line(0x260A, 3);
    this->resourcesDrop->set_help_info(0x7632, -1);

    if (!this->create_text(this, &this->pathingLabel, 0x260D,
                           0x1A4, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->pathingDrop,
                                0xB4, 100, 0x1A4, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->pathingDrop->empty_list();
    this->pathingDrop->append_line(0x260E, 0);
    this->pathingDrop->append_line(0x260F, 1);
    this->pathingDrop->append_line(0x2610, 2);
    this->pathingDrop->set_help_info(0x763E, -1);

    if (rge_base_game->multiplayerGame() != 0) {
        if (!this->create_text(this, &this->limitLabel, 0x2613,
                               0x1A4, 0xD8, 0xB4, 0x14, 0x0B, 0, 0, 0))
            return;
        if (!this->create_drop_down(this, &this->limitDrop,
                                    0xB4, 100, 0x1A4, 0xEC, 0xB4, 0x18,
                                    0x0B))
            return;
        this->limitDrop->empty_list();
        for (int limit = 25; limit <= 0xC8; limit += 25) {
            sprintf(num_str, "%d", limit);
            this->limitDrop->append_line(num_str, limit);
        }
        this->limitDrop->set_help_info(0x763F, -1);
    }

    if (!this->create_text(this, &this->difficultyLabel, 0x2BCF,
                           0x1A4, 0x108, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->difficultyDrop,
                                0xB4, 100, 0x1A4, 0x11C, 0xB4, 0x18,
                                0x0B))
        return;
    this->difficultyDrop->empty_list();
    this->difficultyDrop->append_line(0x2BD4, 4);
    this->difficultyDrop->append_line(0x2BD3, 3);
    this->difficultyDrop->append_line(0x2BD2, 2);
    this->difficultyDrop->append_line(0x2BD1, 1);
    this->difficultyDrop->append_line(0x2BD0, 0);
    this->difficultyDrop->set_help_info(0x763D, -1);

    if (!this->create_check_box(this, &this->optionButton[0],
                                10, 0x168, 0x1E, 0x1E, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[0], 0x2601,
                           0x28, 0x168, 0xAA, 0x1E, 0x0B, 0, 1, 0))
        return;
    this->optionButton[0]->set_help_info(0x7633, -1);

    if (!this->create_check_box(this, &this->optionButton[2],
                                0xDC, 0x168, 0x1E, 0x1E, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[2], 0x2604,
                           0xFA, 0x168, 0xAA, 0x1E, 0x0B, 0, 1, 0))
        return;
    this->optionButton[2]->set_help_info(0x7637, -1);

    if (!this->create_check_box(this, &this->optionButton[1],
                                0x1AE, 0x168, 0x1E, 0x1E, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[1], 0x25FC,
                           0x1CC, 0x168, 0xAA, 0x1E, 0x0B, 0, 1, 0))
        return;
    this->optionButton[1]->set_help_info(0x7634, -1);

    if (rge_base_game->multiplayerGame() != 0) {
        if (!this->create_check_box(this, &this->optionButton[3],
                                    0x1AE, 0x18B, 0x1E, 0x1E, 0, 0))
            return;
        if (!this->create_text(this, &this->optionText[3], 0x25FB,
                               0x1CC, 0x18B, 0xA5, 0x1E, 0x0B, 0, 1, 0))
            return;
        this->optionButton[3]->set_help_info(0x7638, -1);
    }

    this->scenarioListX = 0x14;
    this->scenarioListY = 0x3C;
    this->scenarioListWidth = 600;
    if (rge_base_game->multiplayerGame() != 0)
        this->scenarioListHeight = 0x6F;
    else
        this->scenarioListHeight = 0x18;

    if (!this->create_list(this, &this->scenarioList,
                           this->scenarioListX, this->scenarioListY,
                           this->scenarioListWidth, this->scenarioListHeight,
                           0x0B))
        return;

    // BINARY NOTE: The executable computes this position before it reloads
    // scenarioList, then uses signed divide by ideal_width.
    long second_column_pos;
    second_column_pos = this->scenarioListWidth;
    second_column_pos -= 0x3C;
    second_column_pos *= this->pnl_wid;
    second_column_pos /= this->ideal_width;
    // LIKELY INTENT: Scale the list's player column with the panel width.
    this->scenarioList->set_second_column_pos(second_column_pos);

    if (rge_base_game->multiplayerGame() != 0) {
        this->scenarioList->set_text(0x25FD);
        this->scenarioList->set_help_info(0x7639, -1);
        if (!this->create_auto_scrollbar(&this->scenarioScrollbar,
                                         this->scenarioList, 0x14))
            return;
    } else {
        this->scenarioList->handle_mouse_input = 0;
        this->scenarioList->setDrawHighlightBar(0);
        this->scenarioList->set_spacer_size(0);
    }

    if (!this->create_text(this, &this->scenarioTitle,
                           rge_base_game->multiplayerGame() ? 0x25FE : 0x2620,
                           this->scenarioListX,
                           this->scenarioListY - 0x14,
                           300, 0x14, 4, 0, 0, 0))
        return;

    if (!this->create_text(this, &this->scenarioPlayersTitle, 0x25FF,
                           this->scenarioListWidth - 0xDC + this->scenarioListX,
                           this->scenarioListY - 0x14,
                           0xDC, 0x14, 4, 0, 0, 0))
        return;
    this->scenarioPlayersTitle->set_alignment(TTextPanel::AlignTop,
                                              TTextPanel::AlignRight);

    this->missionTextX = this->scenarioListX;
    this->missionTextY = this->scenarioListHeight + this->scenarioListY + 0x18;
    this->missionTextWidth = this->scenarioListWidth;
    this->missionTextHeight = 0x104 - this->missionTextY;

    if (!this->create_text(this, &this->missionTitle, 0x2600,
                           this->missionTextX, this->missionTextY - 0x14,
                           300, 0x14, 4, 0, 0, 0))
        return;

    if (!this->create_text(this, &this->missionText, s_592A40,
                           this->missionTextX, this->missionTextY,
                           this->missionTextWidth, this->missionTextHeight,
                           0x0B, 0, 0, 1))
        return;
    this->missionText->set_bevel_info(3, this->bevel_color1,
                                      this->bevel_color2,
                                      this->bevel_color3,
                                      this->bevel_color4,
                                      this->bevel_color5,
                                      this->bevel_color6);

    if (!this->create_auto_scrollbar(&this->missionScrollbar,
                                     this->missionText, 0x14))
        return;
    this->missionScrollbar->set_help_info(0x763A, -1);

    if (!this->create_button(this, &this->okButton, 0xFA1,
                             0, 0x3C, 0x1B8, 0xF0, 0x1E, 0, 0, 0))
        return;
    this->okButton->set_help_info(0x7531, -1);

    if (!this->create_button(this, &this->cancelButton, 0xFA2,
                             0, 0x140, 0x1B8, 0xF0, 0x1E, 0, 0, 0))
        return;
    TButtonPanel* cancel_button = this->cancelButton;
    cancel_button->hotkey = 0x1B;
    cancel_button->hotkey_shift = 0;
    this->cancelButton->set_help_info(0x7532, -1);

    if (!this->create_button(this, &this->help_button, 0xFA9,
                             0, 0x244, 0x1B8, 0x1E, 0x1E, 0, 0, 0))
        return;

    this->fillScenarios();
    this->scenariosLoaded = 1;
    this->getSettings();
    this->fillMissionText();
    this->activatePanels();
    this->set_curr_child(this->okButton);
}


void TribeGameSettingsScreen::init_vars(void) {
    this->title = 0;
    this->mapSizeLabel = 0;
    this->mapSizeDrop = 0;
    this->mapTypeLabel = 0;
    this->mapTypeDrop = 0;
    this->victoryTypeLabel = 0;
    this->victoryTypeDrop = 0;
    this->scoreLabel = 0;
    this->scoreDrop = 0;
    this->timeLabel = 0;
    this->timeDrop = 0;
    this->victoryFixedText = 0;
    this->difficultyLabel = 0;
    this->difficultyDrop = 0;
    this->ageLabel = 0;
    this->ageDrop = 0;
    this->limitLabel = 0;
    this->limitDrop = 0;
    this->resourcesLabel = 0;
    this->resourcesDrop = 0;
    this->pathingLabel = 0;
    this->pathingDrop = 0;
    this->scenarioTitle = 0;
    this->scenarioPlayersTitle = 0;
    this->scenarioList = 0;
    this->scenarioScrollbar = 0;
    this->scenarioCount = 0;
    this->scenarioMission = 0;
    this->scenarioFixed = 0;
    this->scenariosLoaded = 0;
    this->missionTitle = 0;
    this->missionText = 0;
    this->missionScrollbar = 0;

    {
        int i;
        for (i = 0; i < 4; i++) {
            this->optionButton[i] = 0;
            this->optionText[i] = 0;
        }
    }

    this->okButton = 0;
    this->cancelButton = 0;
    this->help_button = 0;
    this->chat_scr = 0;
    this->last_scenario_line = -1;
    this->scenario_line_offset = 0;
    this->last_send_shared = 0;
}

TribeGameSettingsScreen::~TribeGameSettingsScreen()
{
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->mapSizeLabel);
    this->delete_panel((TPanel**)&this->mapSizeDrop);
    this->delete_panel((TPanel**)&this->mapTypeLabel);
    this->delete_panel((TPanel**)&this->mapTypeDrop);
    this->delete_panel((TPanel**)&this->victoryTypeLabel);
    this->delete_panel((TPanel**)&this->victoryTypeDrop);
    this->delete_panel((TPanel**)&this->timeDrop);
    this->delete_panel((TPanel**)&this->timeLabel);
    this->delete_panel((TPanel**)&this->scoreDrop);
    this->delete_panel((TPanel**)&this->scoreLabel);
    this->delete_panel((TPanel**)&this->victoryFixedText);
    this->delete_panel((TPanel**)&this->difficultyLabel);
    this->delete_panel((TPanel**)&this->difficultyDrop);
    this->delete_panel((TPanel**)&this->ageLabel);
    this->delete_panel((TPanel**)&this->ageDrop);
    this->delete_panel((TPanel**)&this->resourcesLabel);
    this->delete_panel((TPanel**)&this->resourcesDrop);
    this->delete_panel((TPanel**)&this->scenarioTitle);
    this->delete_panel((TPanel**)&this->scenarioPlayersTitle);
    this->delete_panel((TPanel**)&this->scenarioList);
    this->delete_panel((TPanel**)&this->scenarioScrollbar);
    this->delete_panel((TPanel**)&this->missionTitle);
    this->delete_panel((TPanel**)&this->missionText);
    this->delete_panel((TPanel**)&this->missionScrollbar);
    this->delete_panel((TPanel**)&this->pathingLabel);
    this->delete_panel((TPanel**)&this->pathingDrop);
    this->delete_panel((TPanel**)&this->limitLabel);
    this->delete_panel((TPanel**)&this->limitDrop);

    char* p = (char*)this + 0x534;
    int n = 4;
    do {
        this->delete_panel((TPanel**)(p - 0x10));
        this->delete_panel((TPanel**)p);
        p += 4;
        --n;
    } while (n != 0);

    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);

    if (this->scenarioMission != 0) {
        int i = 0;
        if (this->scenarioCount > 0) {
            do {
                if (this->scenarioMission[i] != 0)
                    free(this->scenarioMission[i]);
                ++i;
            } while (i < this->scenarioCount);
        }
        free(this->scenarioMission);
    }
    if (this->scenarioFixed != 0)
        free(this->scenarioFixed);
}


long TribeGameSettingsScreen::handle_idle() {
    if (scenariosLoaded == 0) {
        fillScenarios();
        fillMissionText();
        scenariosLoaded = 1;
        activatePanels();
        set_curr_child(scenarioList);
    }

    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }

    if (rge_base_game->multiplayerGame() != 0) {
        if (last_send_shared == 0) {
            last_send_shared = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 0x23A);
        } else {
            unsigned long cur_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 0x23D);
            if ((cur_time - last_send_shared) != 0) {
                comm->SendSharedData(0);
                last_send_shared = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 0x240);
            }
        }
    }

    return TPanel::handle_idle();
}


long TribeGameSettingsScreen::handle_user_command(unsigned int command, long param) {
    if (this->chat_scr != 0) {
        long result = this->chat_scr->handle_user_command(command, param);
        if (result != 0) {
            return result;
        }
    }
    return this->TPanel::handle_user_command(command, param);
}


long TribeGameSettingsScreen::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    if (param_1 == 0)
        goto def;

    if (this->scenariosLoaded == 0)
        goto def;

    if (param_1 == this->okButton && param_2 == 1) {
        this->set_curr_child(this->scenarioList);
        this->sendSettings();
        this->chat_scr->action(this, 1, 0, 0);
        return 1;
    }

    if (param_1 == this->cancelButton && param_2 == 1) {
        this->set_curr_child(this->scenarioList);
        this->getSettings();
        this->chat_scr->action(this, 0, 0, 0);
        return 1;
    }

    if (param_1 == this->help_button && param_2 == 1) {
        this->setup_popup_help();
        return 1;
    }

    if (param_1 == this->victoryTypeDrop && param_2 == 0) {
        switch (this->victoryTypeDrop->get_id()) {
        case 7:
            this->timeDrop->set_line(3);
            break;
        case 8:
            this->scoreDrop->set_line(7);
            break;
        default:
            goto activate_and_return;
        }
        this->activatePanels();
        return 1;
    }

    if (param_1 == this->scenarioList) {
        if (param_2 == 3)
            return 1;
        if (param_2 == 1) {
            this->fillMissionText();
            goto activate_and_return;
        }
    }

    goto def;

activate_and_return:
    this->activatePanels();
    return 1;

def:
    return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
}


void TribeGameSettingsScreen::fillScenarios()
{
    RGE_Scenario_File_Info* info;
    char* name;
    int i;
    int len;
    char player_str[20];
    char file_name[260];
    char scenario_file[260];

    this->scenarioList->empty_list();
    this->scenario_line_offset = 0;

    if (rge_base_game->multiplayerGame() || rge_base_game->scenarioGame()) {
        info = rge_base_game->scenario_info;
        info->reload_scenarios();
        i = 0;
        this->scenarioList->sorted = 1;
        this->scenarioCount = 0;
        while (1) {
            name = info->get_scenario_name(i);
            if (name == 0) {
                break;
            }
            len = (int)strlen(name) - 4;
            strncpy(file_name, name, len);
            file_name[len] = 0;

            if (rge_base_game->multiplayerGame() ||
                strcmp(file_name, rge_base_game->scenarioName()) == 0) {
                this->scenarioList->append_line(file_name, i);
                this->scenarioCount++;
            }
            i++;
        }

        this->scenarioMission = (char**)calloc(this->scenarioCount, 4);
        this->scenarioFixed = (int*)calloc(this->scenarioCount, 4);

        if (this->scenarioMission != 0 && this->scenarioFixed != 0) {
            i = 0;
            if (this->scenarioCount > 0) {
                do {
                    TRIBE_Scenario_Header* entry =
                        static_cast<TRIBE_Scenario_Header*>(
                            info->get_scenario_info(
                                this->scenarioList->get_id(i)));
                    if (entry != 0) {
                        this->scenarioMission[i] = (char*)calloc(0x1000, 1);
                        if (this->scenarioMission[i] != 0 &&
                            entry->description != 0) {
                            strcpy(this->scenarioMission[i], entry->description);
                        }

                        this->scenarioFixed[i] = entry->any_sp_victory;
                        int players = entry->active_player_count;
                        if (players > 0) {
                            if (this->scenarioFixed[i] == 0 && players >= 3) {
                                sprintf(player_str, "%d - %d", 2, players);
                            } else {
                                sprintf(player_str, "%d", players);
                            }
                            strcpy(scenario_file,
                                   this->scenarioList->get_text(i));
                            this->scenarioList->change_line(
                                i, scenario_file, player_str, 0);
                        }
                    }
                    i++;
                } while (i < this->scenarioCount);
            }
        }
    }

    this->scenarioList->sorted = 0;

    if (rge_base_game->multiplayerGame() ||
        (rge_base_game->randomGame() &&
         static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0)) {
        this->scenarioList->insert_line(
            0, this->get_string(0x25B5), "2 - 8", -2);
        this->scenario_line_offset--;
    }

    if (rge_base_game->multiplayerGame() ||
        (rge_base_game->randomGame() &&
         static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() != 0)) {
        this->scenarioList->insert_line(
            1, this->get_string(0x2617), "2 - 8", -1);
        this->scenario_line_offset--;
    }
}

void TribeGameSettingsScreen::fillMissionText(void) {
    long line;
    int id;
    this->missionText->set_text("");
    line = this->scenarioList->get_line();
    id = this->scenarioList->get_id();

    if (id == -2) {
        this->missionText->set_text(0x25DC);
    } else if (id == -1) {
        this->missionText->set_text(0x2618);
    } else {
        this->missionText->set_text(this->scenarioMission[this->scenario_line_offset + line]);
    }

    if (line != this->last_scenario_line) {
        this->victoryTypeDrop->set_line(0);
    }

    if (id < 0) {
        this->state = 1;
        this->last_scenario_line = line;
        return;
    }

    this->last_scenario_line = line;
    this->state = 0;
}


void TribeGameSettingsScreen::getSettings() {
    if (rge_base_game->scenarioGame() != 0) {
        this->state = 0;
    } else {
        this->state = 1;
    }

    this->last_scenario_line = 0;
    if (this->state == 1) {
        if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() != 0) {
            this->scenarioList->scroll_cur_line(1, 1, 1);
        } else {
            this->scenarioList->scroll_cur_line(1, 0, 1);
        }
    } else {
        long line = this->scenarioList->get_line(rge_base_game->scenarioName());
        if (line != -1) {
            this->scenarioList->scroll_cur_line(1, (short)line, 1);
            this->last_scenario_line = line - 1;
        } else {
            this->scenarioList->scroll_cur_line(1, 0, 1);
        }
    }

    this->mapSizeDrop->set_line(this->mapSizeDrop->get_line(
        static_cast<TRIBE_Game*>(rge_base_game)->mapSize()));
    this->mapTypeDrop->set_line(this->mapTypeDrop->get_line(
        static_cast<TRIBE_Game*>(rge_base_game)->mapType()));
    this->victoryTypeDrop->set_line(this->victoryTypeDrop->get_line(
        static_cast<TRIBE_Game*>(rge_base_game)->victoryType()));

    if (this->optionButton[3] != 0) {
        this->optionButton[3]->set_state(rge_base_game->allowCheatCodes());
    }
    this->optionButton[1]->set_state(rge_base_game->fullVisibility());
    this->optionButton[0]->set_state(
        static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions() == 0);
    this->optionButton[2]->set_state(
        static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree());

    this->resourcesDrop->set_line(this->resourcesDrop->get_line(
        static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel()));
    this->ageDrop->set_line(this->ageDrop->get_line(
        static_cast<TRIBE_Game*>(rge_base_game)->startingAge()));
    this->difficultyDrop->set_line(this->difficultyDrop->get_line(rge_base_game->difficulty()));

    if (rge_base_game->multiplayerGame() != 0) {
        this->pathingDrop->set_line(this->pathingDrop->get_line((unsigned int)rge_base_game->mpPathFinding()));
    } else {
        this->pathingDrop->set_line(this->pathingDrop->get_line((unsigned int)rge_base_game->pathFinding()));
    }

    if (rge_base_game->multiplayerGame() != 0) {
        this->limitDrop->set_line(this->limitDrop->get_line(
            (unsigned int)static_cast<TRIBE_Game*>(rge_base_game)->popLimit()));
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->victoryType() == 7) {
        this->timeDrop->set_line(this->timeDrop->get_line(
            static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount()));
    } else if (static_cast<TRIBE_Game*>(rge_base_game)->victoryType() == 8) {
        this->scoreDrop->set_line(this->scoreDrop->get_line(
            static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount()));
    }
}


void TribeGameSettingsScreen::sendSettings()
{
    if (this->scenarioList->get_id() >= 0) {
        rge_base_game->setScenarioGame(1);
        rge_base_game->setScenarioName(this->scenarioList->get_text());
    } else {
        rge_base_game->setScenarioGame(0);
        rge_base_game->setScenarioName("");
    }

    static_cast<TRIBE_Game*>(rge_base_game)->setDeathMatch(
        this->scenarioList->get_id() == -1);

    switch (this->victoryTypeDrop->get_id()) {
    case 7:
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(
            TRIBE_Game::VictoryTime, this->timeDrop->get_id());
        break;
    case 8:
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(
            TRIBE_Game::VictoryScore, this->scoreDrop->get_id());
        break;
    default:
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(
            static_cast<TRIBE_Game::VictoryType>(
                this->victoryTypeDrop->get_id()), 1);
        break;
    }

    if (rge_base_game->randomGame()) {
        static_cast<TRIBE_Game*>(rge_base_game)->setMapSize(
            static_cast<TRIBE_Game::MapSize>(this->mapSizeDrop->get_id()));
        static_cast<TRIBE_Game*>(rge_base_game)->setMapType(
            static_cast<TRIBE_Game::MapType>(this->mapTypeDrop->get_id()));
    }
    if (this->optionButton[3] != 0) {
        rge_base_game->setAllowCheatCodes(this->optionButton[3]->get_state());
    }
    rge_base_game->setFullVisibility(this->optionButton[1]->get_state());
    static_cast<TRIBE_Game*>(rge_base_game)->setRandomizePositions(
        this->optionButton[0]->get_state() == 0);
    static_cast<TRIBE_Game*>(rge_base_game)->setFullTechTree(
        this->optionButton[2]->get_state());

    if (this->scenarioList->get_id() == -1) {
        static_cast<TRIBE_Game*>(rge_base_game)->setResourceLevel(
            TRIBE_Game::DefaultResources);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->setResourceLevel(
            static_cast<TRIBE_Game::ResourceLevel>(
                this->resourcesDrop->get_id()));
    }

    if (rge_base_game->multiplayerGame()) {
        rge_base_game->setMpPathFinding(this->pathingDrop->get_id());
    } else {
        rge_base_game->setPathFinding(this->pathingDrop->get_id());
    }
    if (rge_base_game->multiplayerGame()) {
        static_cast<TRIBE_Game*>(rge_base_game)->setPopLimit(
            this->limitDrop->get_id());
    }
    static_cast<TRIBE_Game*>(rge_base_game)->setStartingAge(
        static_cast<TRIBE_Game::Age>(this->ageDrop->get_id()));
    rge_base_game->setDifficulty(this->difficultyDrop->get_id());
    if (rge_base_game->singlePlayerGame()) {
        rge_base_game->set_single_player_difficulty(this->difficultyDrop->get_id());
    }
}


void TribeGameSettingsScreen::activatePanels() {
    TPanel* tabList[3];
    int isScenario;
    int count;

    isScenario = (state == 0);
    if (isScenario) {
        missionTitle->set_active(1);
        missionText->set_active(1);
    } else {
        missionTitle->set_active(0);
        missionText->set_active(0);
    }

    mapSizeDrop->set_active(isScenario == 0);
    mapTypeDrop->set_active(isScenario == 0);
    mapSizeLabel->set_active(isScenario == 0);
    mapTypeLabel->set_active(isScenario == 0);

    if (scenarioList->get_id() == -1) {
        resourcesDrop->set_active(0);
        resourcesLabel->set_active(0);
    } else {
        resourcesDrop->set_active(1);
        resourcesLabel->set_active(1);
    }

    activateVictoryPanels();
    count = 0;
    if (rge_base_game->multiplayerGame() != 0) {
        tabList[0] = scenarioList;
        count = 1;
    }
    tabList[count] = okButton;
    count++;
    tabList[count] = cancelButton;
    count++;
    this->set_tab_order(tabList, (short)count);

    if (this->curr_child == 0 || this->curr_child->active == 0) {
        set_curr_child(okButton);
    }
}


void TribeGameSettingsScreen::activateVictoryPanels() {
    timeLabel->set_active(0);
    timeDrop->set_active(0);
    scoreLabel->set_active(0);
    scoreDrop->set_active(0);

    if (state == 0) {
        long firstLine = scenarioList->get_line();
        long secondLine = scenarioList->get_line();

        if (scenariosLoaded != 0 && secondLine >= 0 &&
            scenarioFixed[scenario_line_offset + firstLine] != 0) {
            victoryFixedText->set_active(1);
            victoryTypeLabel->set_active(0);
            victoryTypeDrop->set_active(0);
            return;
        }
    }

    victoryFixedText->set_active(0);
    victoryTypeLabel->set_active(1);
    victoryTypeDrop->set_active(1);

    if (victoryTypeDrop->get_id() == 7) {
        timeLabel->set_active(1);
        timeDrop->set_active(1);
    }

    if (victoryTypeDrop->get_id() == 8) {
        scoreLabel->set_active(1);
        scoreDrop->set_active(1);
    }
}
