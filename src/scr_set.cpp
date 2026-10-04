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
#include "../include/resource_ids.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TribeGameSettingsScreen::TribeGameSettingsScreen()
    : TScreenPanel("Game Settings Screen") {
    char num_str[5];
    char* setup_file;
    int multiplayer;
    TDrawArea* draw_area;

    this->init_vars();
    this->chat_scr = static_cast<TribeMPSetupScreen*>(panel_system.panel("MP Setup Screen"));

    multiplayer = rge_base_game->multiplayerGame();
    setup_file = "scr3";
    if (multiplayer == 0)
        setup_file = "scr2";

    draw_area = rge_base_game->draw_area;

    if (!this->TEasy_Panel::setup(draw_area, 0, setup_file, (rge_base_game->multiplayerGame() != 0) + 0xC384,
                                  1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(640, 480);

    if (!this->create_text(this, &this->title, STRING_ID_SCENARIO_SETTINGS_TITLE, 20, 10, 600, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 0, 1))
        return;

    if (!this->create_text(this, &this->mapSizeLabel, STRING_ID_MAP_SIZE_LABEL, 20, 216, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->mapSizeDrop, 180, 100, 20, 236, 180, 24, RGE_FONT_STANDARD))
        return;
    this->mapSizeDrop->empty_list();
    this->mapSizeDrop->append_line(STRING_ID_MAP_SIZE_TINY, TRIBE_Game::Tiny);
    this->mapSizeDrop->append_line(STRING_ID_MAP_SIZE_SMALL, TRIBE_Game::Small);
    this->mapSizeDrop->append_line(STRING_ID_MAP_SIZE_MEDIUM, TRIBE_Game::Medium);
    this->mapSizeDrop->append_line(STRING_ID_MAP_SIZE_LARGE, TRIBE_Game::Large);
    this->mapSizeDrop->append_line(STRING_ID_MAP_SIZE_HUGE, TRIBE_Game::Huge);
    this->mapSizeDrop->append_line(STRING_ID_MAP_SIZE_HUMONGOUS, TRIBE_Game::Humongous);
    this->mapSizeDrop->set_help_info(STRING_ID_HELP_MAP_SIZE, -1);

    if (!this->create_text(this, &this->mapTypeLabel, STRING_ID_MAP_TYPE_LABEL, 220, 216, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->mapTypeDrop, 180, 100, 220, 236, 180, 24, RGE_FONT_STANDARD))
        return;
    this->mapTypeDrop->empty_list();
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_ALL_WATER, TRIBE_Game::AllWater);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_MOSTLY_WATER, TRIBE_Game::MostlyWater);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_WATER_AND_LAND, TRIBE_Game::WaterAndLand);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_MOSTLY_LAND, TRIBE_Game::MostlyLand);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_ALL_LAND, TRIBE_Game::AllLand);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_CONTINENTAL, TRIBE_Game::Continental);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_LAKE, TRIBE_Game::Lake);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_HILLY, TRIBE_Game::Hilly);
    this->mapTypeDrop->append_line(STRING_ID_MAP_TYPE_ISTHMAS, TRIBE_Game::Isthmas);
    this->mapTypeDrop->set_help_info(STRING_ID_HELP_MAP_TYPE, -1);

    if (!this->create_text(this, &this->victoryTypeLabel, STRING_ID_VICTORY_CONDITION_LABEL,
                           20, 264, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->victoryTypeDrop, 180, 100, 20, 284, 180, 24, RGE_FONT_STANDARD))
        return;
    this->victoryTypeDrop->empty_list();
    if (rge_base_game->scenarioGame() != 0) {
        this->victoryTypeDrop->append_line(STRING_ID_OPTION_DEFAULT, TRIBE_Game::VictoryDefault);
        this->victoryTypeDrop->append_line(STRING_ID_VICTORY_STANDARD, TRIBE_Game::VictoryStandard);
    } else {
        this->victoryTypeDrop->append_line(STRING_ID_VICTORY_STANDARD, TRIBE_Game::VictoryDefault);
    }
    this->victoryTypeDrop->append_line(STRING_ID_VICTORY_CONQUEST, TRIBE_Game::VictoryConquest);
    this->victoryTypeDrop->append_line(STRING_ID_VICTORY_TIME_LIMIT, TRIBE_Game::VictoryTime);
    this->victoryTypeDrop->append_line(STRING_ID_VICTORY_SCORE, TRIBE_Game::VictoryScore);
    this->victoryTypeDrop->set_help_info(STRING_ID_HELP_VICTORY_CONDITION, STRING_ID_HELP_VICTORY_CONDITION_MORE);

    if (!this->create_text(this, &this->timeLabel, STRING_ID_VICTORY_TIME_LIMIT, 20, 312, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->timeDrop, 180, 100, 20, 332, 180, 24, RGE_FONT_STANDARD))
        return;
    this->timeDrop->empty_list();
    this->timeDrop->append_line(STRING_ID_TIME_LIMIT_15000, 15000);
    this->timeDrop->append_line(STRING_ID_TIME_LIMIT_13000, 13000);
    this->timeDrop->append_line(STRING_ID_TIME_LIMIT_11000, 11000);
    this->timeDrop->append_line(STRING_ID_TIME_LIMIT_9000, 9000);
    this->timeDrop->append_line(STRING_ID_TIME_LIMIT_7000, 7000);
    this->timeDrop->append_line(STRING_ID_TIME_LIMIT_5000, 5000);
    this->timeDrop->append_line(STRING_ID_TIME_LIMIT_3000, 3000);
    this->timeDrop->set_help_info(STRING_ID_HELP_TIME_LIMIT, -1);

    if (!this->create_text(this, &this->scoreLabel, STRING_ID_VICTORY_SCORE, 20, 312, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->scoreDrop, 180, 100, 20, 332, 180, 24, RGE_FONT_STANDARD))
        return;
    this->scoreDrop->empty_list();
    this->scoreDrop->append_line("3000", 3000);
    this->scoreDrop->append_line("2700", 2700);
    this->scoreDrop->append_line("2400", 2400);
    this->scoreDrop->append_line("2100", 2100);
    this->scoreDrop->append_line("1800", 1800);
    this->scoreDrop->append_line("1500", 1500);
    this->scoreDrop->append_line("1200", 1200);
    this->scoreDrop->append_line("900", 900);
    this->scoreDrop->append_line("800", 800);
    this->scoreDrop->append_line("700", 700);
    this->scoreDrop->append_line("600", 600);
    this->scoreDrop->append_line("500", 500);
    this->scoreDrop->append_line("400", 400);
    this->scoreDrop->append_line("300", 300);
    this->scoreDrop->set_help_info(STRING_ID_HELP_SCORE, -1);

    if (!this->create_text(this, &this->victoryFixedText, STRING_ID_FIXED_VICTORY_INSTRUCTIONS,
                           20, 264, 180, 92, RGE_FONT_STANDARD, 1, 1, 1))
        return;
    this->victoryFixedText->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3,
                                           this->bevel_color4, this->bevel_color5, this->bevel_color6);

    if (!this->create_text(this, &this->ageLabel, STRING_ID_STARTING_AGE_LABEL, 220, 264, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->ageDrop, 180, 100, 220, 284, 180, 24, RGE_FONT_STANDARD))
        return;
    this->ageDrop->empty_list();
        this->ageDrop->append_line(STRING_ID_OPTION_DEFAULT, TRIBE_Game::DefaultAge);
    this->ageDrop->append_line(STRING_ID_AGE_NOMAD, TRIBE_Game::NomadAge);
    this->ageDrop->append_line(STRING_ID_AGE_STONE, TRIBE_Game::StoneAge);
    this->ageDrop->append_line(STRING_ID_AGE_TOOL, TRIBE_Game::ToolAge);
    this->ageDrop->append_line(STRING_ID_AGE_BRONZE, TRIBE_Game::BronzeAge);
    this->ageDrop->append_line(STRING_ID_AGE_IRON, TRIBE_Game::IronAge);
    this->ageDrop->set_help_info(STRING_ID_HELP_STARTING_AGE, -1);

    if (!this->create_text(this, &this->resourcesLabel, STRING_ID_RESOURCES_LABEL, 220, 312, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->resourcesDrop, 180, 100, 220, 332, 180, 24, RGE_FONT_STANDARD))
        return;
    this->resourcesDrop->empty_list();
        this->resourcesDrop->append_line(STRING_ID_OPTION_DEFAULT, TRIBE_Game::DefaultResources);
    this->resourcesDrop->append_line(STRING_ID_RESOURCES_MEDIUM, TRIBE_Game::MediumResources);
    this->resourcesDrop->append_line(STRING_ID_RESOURCES_HIGH, TRIBE_Game::HighResources);
    this->resourcesDrop->set_help_info(STRING_ID_HELP_RESOURCES, -1);

    if (!this->create_text(this, &this->pathingLabel, STRING_ID_PATH_FINDING_LABEL,
                           420, 312, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->pathingDrop, 180, 100, 420, 332, 180, 24, RGE_FONT_STANDARD))
        return;
    this->pathingDrop->empty_list();
    this->pathingDrop->append_line(STRING_ID_PATH_FINDING_DEFAULT, RGE_PATH_FINDING_DEFAULT);
    this->pathingDrop->append_line(STRING_ID_PATH_FINDING_MEDIUM, RGE_PATH_FINDING_MEDIUM);
    this->pathingDrop->append_line(STRING_ID_PATH_FINDING_HIGH, RGE_PATH_FINDING_HIGH);
    this->pathingDrop->set_help_info(STRING_ID_HELP_PATH_FINDING, -1);

    if (rge_base_game->multiplayerGame() != 0) {
        if (!this->create_text(this, &this->limitLabel, STRING_ID_POPULATION_LIMIT_LABEL,
                               420, 216, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
            return;
        if (!this->create_drop_down(this, &this->limitDrop, 180, 100, 420, 236, 180, 24, RGE_FONT_STANDARD))
            return;
        this->limitDrop->empty_list();
        for (int limit = 25; limit <= 200; limit += 25) {
            sprintf(num_str, "%d", limit);
            this->limitDrop->append_line(num_str, limit);
        }
        this->limitDrop->set_help_info(STRING_ID_HELP_POPULATION_LIMIT, -1);
    }

    if (!this->create_text(this, &this->difficultyLabel, STRING_ID_DIFFICULTY_LABEL,
                           420, 264, 180, 20, RGE_FONT_STANDARD, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->difficultyDrop, 180, 100, 420, 284, 180, 24, RGE_FONT_STANDARD))
        return;
    this->difficultyDrop->empty_list();
    this->difficultyDrop->append_line(STRING_ID_DIFFICULTY_EASIEST, RGE_DIFFICULTY_EASIEST);
    this->difficultyDrop->append_line(STRING_ID_DIFFICULTY_EASY, RGE_DIFFICULTY_EASY);
    this->difficultyDrop->append_line(STRING_ID_DIFFICULTY_MODERATE, RGE_DIFFICULTY_MODERATE);
    this->difficultyDrop->append_line(STRING_ID_DIFFICULTY_HARD, RGE_DIFFICULTY_HARD);
    this->difficultyDrop->append_line(STRING_ID_DIFFICULTY_HARDEST, RGE_DIFFICULTY_HARDEST);
    this->difficultyDrop->set_help_info(STRING_ID_HELP_DIFFICULTY, -1);

    if (!this->create_check_box(this, &this->optionButton[0], 10, 360, 30, 30, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[0], STRING_ID_FIXED_POSITIONS_LABEL,
                           40, 360, 170, 30, RGE_FONT_STANDARD, 0, 1, 0))
        return;
    this->optionButton[0]->set_help_info(STRING_ID_HELP_FIXED_POSITIONS, -1);

    if (!this->create_check_box(this, &this->optionButton[2], 220, 360, 30, 30, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[2], STRING_ID_FULL_TECH_TREE_LABEL,
                           250, 360, 170, 30, RGE_FONT_STANDARD, 0, 1, 0))
        return;
    this->optionButton[2]->set_help_info(STRING_ID_HELP_FULL_TECH_TREE, -1);

    if (!this->create_check_box(this, &this->optionButton[1], 430, 360, 30, 30, 0, 0))
        return;
        if (!this->create_text(this, &this->optionText[1], STRING_ID_REVEAL_MAP_LABEL,
                               460, 360, 170, 30, RGE_FONT_STANDARD, 0, 1, 0))
        return;
        this->optionButton[1]->set_help_info(STRING_ID_HELP_REVEAL_MAP, -1);

    if (rge_base_game->multiplayerGame() != 0) {
        if (!this->create_check_box(this, &this->optionButton[3], 430, 395, 30, 30, 0, 0))
            return;
        if (!this->create_text(this, &this->optionText[3], STRING_ID_CHEATING_LABEL,
                               460, 395, 165, 30, RGE_FONT_STANDARD, 0, 1, 0))
            return;
        this->optionButton[3]->set_help_info(STRING_ID_HELP_CHEATING, -1);
    }

    this->scenarioListX = 20;
    this->scenarioListY = 60;
    this->scenarioListWidth = 600;
    if (rge_base_game->multiplayerGame() != 0)
        this->scenarioListHeight = 111;
    else
        this->scenarioListHeight = 24;

    if (!this->create_list(this, &this->scenarioList, this->scenarioListX, this->scenarioListY,
                           this->scenarioListWidth, this->scenarioListHeight, RGE_FONT_STANDARD))
        return;

    // The executable computes this position before it reloads
    // scenarioList, then uses signed divide by ideal_width.
    long second_column_pos;
    second_column_pos = this->scenarioListWidth;
    second_column_pos -= 60;
    second_column_pos *= this->pnl_wid;
    second_column_pos /= this->ideal_width;
    this->scenarioList->set_second_column_pos(second_column_pos);

    if (rge_base_game->multiplayerGame() != 0) {
        this->scenarioList->set_text(STRING_ID_SCENARIO_LIST_LOADING);
        this->scenarioList->set_help_info(STRING_ID_HELP_SCENARIO_SELECTION, -1);
        if (!this->create_auto_scrollbar(&this->scenarioScrollbar, this->scenarioList, 20))
            return;
    } else {
        this->scenarioList->handle_mouse_input = 0;
        this->scenarioList->setDrawHighlightBar(0);
        this->scenarioList->set_spacer_size(0);
    }

    if (!this->create_text(this, &this->scenarioTitle, rge_base_game->multiplayerGame() ? STRING_ID_SCENARIO_LIST_TITLE
                           : STRING_ID_SCENARIO_TITLE, this->scenarioListX, this->scenarioListY - 20, 300, 20, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 0, 0, 0))
        return;

    if (!this->create_text(this, &this->scenarioPlayersTitle, STRING_ID_SCENARIO_PLAYERS_TITLE,
                           this->scenarioListWidth - 220 + this->scenarioListX, this->scenarioListY - 20,
                           220, 20, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 0, 0, 0))
        return;
    this->scenarioPlayersTitle->set_alignment(TTextPanel::AlignTop, TTextPanel::AlignRight);

    this->missionTextX = this->scenarioListX;
    this->missionTextY = this->scenarioListHeight + this->scenarioListY + 24;
    this->missionTextWidth = this->scenarioListWidth;
    this->missionTextHeight = 260 - this->missionTextY;

    if (!this->create_text(this, &this->missionTitle, STRING_ID_SCENARIO_INSTRUCTIONS_TITLE,
                           this->missionTextX, this->missionTextY - 20, 300, 20, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 0, 0, 0))
        return;

    if (!this->create_text(this, &this->missionText, s_empty_string, this->missionTextX, this->missionTextY,
                           this->missionTextWidth, this->missionTextHeight, RGE_FONT_STANDARD, 0, 0, 1))
        return;
    this->missionText->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4,
                                      this->bevel_color5, this->bevel_color6);

    if (!this->create_auto_scrollbar(&this->missionScrollbar, this->missionText, 20))
        return;
    this->missionScrollbar->set_help_info(STRING_ID_HELP_SCENARIO_INSTRUCTIONS, -1);

    if (!this->create_button(this, &this->okButton, STRING_ID_BUTTON_OK, 0, 60, 440, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0))
        return;
    this->okButton->set_help_info(STRING_ID_HELP_OK, -1);

    if (!this->create_button(this, &this->cancelButton, STRING_ID_BUTTON_CANCEL, 0, 320, 440, 240, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0))
        return;
    TButtonPanel* cancel_button = this->cancelButton;
    cancel_button->hotkey = VK_ESCAPE;
    cancel_button->hotkey_shift = 0;
    this->cancelButton->set_help_info(STRING_ID_HELP_CANCEL, -1);

    if (!this->create_button(this, &this->help_button, STRING_ID_BUTTON_HELP, 0, 580, 440, 30, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0))
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

TribeGameSettingsScreen::~TribeGameSettingsScreen() {
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
            last_send_shared = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 570);
        } else {
            unsigned long cur_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 573);
            if ((cur_time - last_send_shared) != 0) {
                comm->SendSharedData(0);
                last_send_shared = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_set.cpp", 576);
            }
        }
    }

    return TPanel::handle_idle();
}


long TribeGameSettingsScreen::handle_user_command(unsigned int wParam, long lParam) {
    if (this->chat_scr != 0) {
        long result = this->chat_scr->handle_user_command(wParam, lParam);
        if (result != 0) {
            return result;
        }
    }
    return this->TPanel::handle_user_command(wParam, lParam);
}


long TribeGameSettingsScreen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel == 0)
        goto def;

    if (this->scenariosLoaded == 0)
        goto def;

    if (fromPanel == this->okButton && actionIn == 1) {
        this->set_curr_child(this->scenarioList);
        this->sendSettings();
        this->chat_scr->action(this, 1, 0, 0);
        return 1;
    }

    if (fromPanel == this->cancelButton && actionIn == 1) {
        this->set_curr_child(this->scenarioList);
        this->getSettings();
        this->chat_scr->action(this, 0, 0, 0);
        return 1;
    }

    if (fromPanel == this->help_button && actionIn == 1) {
        this->setup_popup_help();
        return 1;
    }

    if (fromPanel == this->victoryTypeDrop && actionIn == 0) {
        switch (this->victoryTypeDrop->get_id()) {
        case TRIBE_Game::VictoryTime:
            this->timeDrop->set_line(3);
            break;
        case TRIBE_Game::VictoryScore:
            this->scoreDrop->set_line(7);
            break;
        default:
            goto activate_and_return;
        }
        this->activatePanels();
        return 1;
    }

    if (fromPanel == this->scenarioList) {
        if (actionIn == 3)
            return 1;
        if (actionIn == 1) {
            this->fillMissionText();
            goto activate_and_return;
        }
    }

    goto def;

activate_and_return:
    this->activatePanels();
    return 1;

def:
    return this->TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}


void TribeGameSettingsScreen::fillScenarios() {
    RGE_Scenario_File_Info* scenario_info_file;
    char* name;
    int i;
    int len;
    char player_str[20];
    char file_name[260];
    char scenario_file[260];

    this->scenarioList->empty_list();
    this->scenario_line_offset = 0;

    if (rge_base_game->multiplayerGame() || rge_base_game->scenarioGame()) {
        scenario_info_file = rge_base_game->scenario_info;
        scenario_info_file->reload_scenarios();
        i = 0;
        this->scenarioList->sorted = 1;
        this->scenarioCount = 0;
        while (1) {
            name = scenario_info_file->get_scenario_name(i);
            if (name == 0) {
                break;
            }
            len = (int)strlen(name) - 4;
            strncpy(file_name, name, len);
            file_name[len] = 0;

            if (rge_base_game->multiplayerGame() || strcmp(file_name, rge_base_game->scenarioName()) == 0) {
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
                        static_cast<TRIBE_Scenario_Header*>(scenario_info_file->get_scenario_info(
                                this->scenarioList->get_id(i)));
                    if (entry != 0) {
                        this->scenarioMission[i] = (char*)calloc(4096, 1);
                        if (this->scenarioMission[i] != 0 && entry->description != 0) {
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
                            strcpy(scenario_file, this->scenarioList->get_text(i));
                            this->scenarioList->change_line(i, scenario_file, player_str, 0);
                        }
                    }
                    i++;
                } while (i < this->scenarioCount);
            }
        }
    }

    this->scenarioList->sorted = 0;

    if (rge_base_game->multiplayerGame() || (rge_base_game->randomGame() &&
         static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0)) {
        this->scenarioList->insert_line(0, this->get_string(STRING_ID_RANDOM_MAP), "2 - 8", -2);
        this->scenario_line_offset--;
    }

    if (rge_base_game->multiplayerGame() || (rge_base_game->randomGame() &&
         static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() != 0)) {
        this->scenarioList->insert_line(1, this->get_string(STRING_ID_DEATH_MATCH), "2 - 8", -1);
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
        this->missionText->set_text(STRING_ID_RANDOM_MAP_INSTRUCTIONS);
    } else if (id == -1) {
        this->missionText->set_text(STRING_ID_DEATH_MATCH_DESCRIPTION);
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

    this->mapSizeDrop->set_line(this->mapSizeDrop->get_line(static_cast<TRIBE_Game*>(rge_base_game)->mapSize()));
    this->mapTypeDrop->set_line(this->mapTypeDrop->get_line(static_cast<TRIBE_Game*>(rge_base_game)->mapType()));
    this->victoryTypeDrop->set_line(this->victoryTypeDrop->get_line(
        static_cast<TRIBE_Game*>(rge_base_game)->victoryType()));

    if (this->optionButton[3] != 0) {
        this->optionButton[3]->set_state(rge_base_game->allowCheatCodes());
    }
    this->optionButton[1]->set_state(rge_base_game->fullVisibility());
    this->optionButton[0]->set_state(static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions() == 0);
    this->optionButton[2]->set_state(static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree());

    this->resourcesDrop->set_line(this->resourcesDrop->get_line(static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel()));
    this->ageDrop->set_line(this->ageDrop->get_line(static_cast<TRIBE_Game*>(rge_base_game)->startingAge()));
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

    if (static_cast<TRIBE_Game*>(rge_base_game)->victoryType() == TRIBE_Game::VictoryTime) {
        this->timeDrop->set_line(this->timeDrop->get_line(static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount()));
    } else if (static_cast<TRIBE_Game*>(rge_base_game)->victoryType() == TRIBE_Game::VictoryScore) {
        this->scoreDrop->set_line(this->scoreDrop->get_line(static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount()));
    }
}


void TribeGameSettingsScreen::sendSettings() {
    if (this->scenarioList->get_id() >= 0) {
        rge_base_game->setScenarioGame(1);
        rge_base_game->setScenarioName(this->scenarioList->get_text());
    } else {
        rge_base_game->setScenarioGame(0);
        rge_base_game->setScenarioName("");
    }

    static_cast<TRIBE_Game*>(rge_base_game)->setDeathMatch(this->scenarioList->get_id() == -1);

    switch (this->victoryTypeDrop->get_id()) {
    case TRIBE_Game::VictoryTime:
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(TRIBE_Game::VictoryTime, this->timeDrop->get_id());
        break;
    case TRIBE_Game::VictoryScore:
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(TRIBE_Game::VictoryScore, this->scoreDrop->get_id());
        break;
    default:
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(static_cast<TRIBE_Game::VictoryType>(
                this->victoryTypeDrop->get_id()), 1);
        break;
    }

    if (rge_base_game->randomGame()) {
        static_cast<TRIBE_Game*>(rge_base_game)->setMapSize(static_cast<TRIBE_Game::MapSize>(this->mapSizeDrop->get_id()));
        static_cast<TRIBE_Game*>(rge_base_game)->setMapType(static_cast<TRIBE_Game::MapType>(this->mapTypeDrop->get_id()));
    }
    if (this->optionButton[3] != 0) {
        rge_base_game->setAllowCheatCodes(this->optionButton[3]->get_state());
    }
    rge_base_game->setFullVisibility(this->optionButton[1]->get_state());
    static_cast<TRIBE_Game*>(rge_base_game)->setRandomizePositions(this->optionButton[0]->get_state() == 0);
    static_cast<TRIBE_Game*>(rge_base_game)->setFullTechTree(this->optionButton[2]->get_state());

    if (this->scenarioList->get_id() == -1) {
        static_cast<TRIBE_Game*>(rge_base_game)->setResourceLevel(TRIBE_Game::DefaultResources);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->setResourceLevel(static_cast<TRIBE_Game::ResourceLevel>(
                this->resourcesDrop->get_id()));
    }

    if (rge_base_game->multiplayerGame()) {
        rge_base_game->setMpPathFinding(this->pathingDrop->get_id());
    } else {
        rge_base_game->setPathFinding(this->pathingDrop->get_id());
    }
    if (rge_base_game->multiplayerGame()) {
        static_cast<TRIBE_Game*>(rge_base_game)->setPopLimit(this->limitDrop->get_id());
    }
    static_cast<TRIBE_Game*>(rge_base_game)->setStartingAge(static_cast<TRIBE_Game::Age>(this->ageDrop->get_id()));
    rge_base_game->setDifficulty(this->difficultyDrop->get_id());
    if (rge_base_game->singlePlayerGame()) {
        rge_base_game->set_single_player_difficulty(this->difficultyDrop->get_id());
    }
}


void TribeGameSettingsScreen::activatePanels() {
    TPanel* tabList[3];
    int is_scenario;
    int count;

    is_scenario = (state == 0);
    if (is_scenario) {
        missionTitle->set_active(1);
        missionText->set_active(1);
    } else {
        missionTitle->set_active(0);
        missionText->set_active(0);
    }

    mapSizeDrop->set_active(is_scenario == 0);
    mapTypeDrop->set_active(is_scenario == 0);
    mapSizeLabel->set_active(is_scenario == 0);
    mapTypeLabel->set_active(is_scenario == 0);

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
        long first_line = scenarioList->get_line();
        long second_line = scenarioList->get_line();

        if (scenariosLoaded != 0 && second_line >= 0 && scenarioFixed[scenario_line_offset + first_line] != 0) {
            victoryFixedText->set_active(1);
            victoryTypeLabel->set_active(0);
            victoryTypeDrop->set_active(0);
            return;
        }
    }

    victoryFixedText->set_active(0);
    victoryTypeLabel->set_active(1);
    victoryTypeDrop->set_active(1);

    if (victoryTypeDrop->get_id() == TRIBE_Game::VictoryTime) {
        timeLabel->set_active(1);
        timeDrop->set_active(1);
    }

    if (victoryTypeDrop->get_id() == TRIBE_Game::VictoryScore) {
        scoreLabel->set_active(1);
        scoreDrop->set_active(1);
    }
}
