
#include "../include/scr_mps.h"
#include "../include/resource_ids.h"
#include "../include/scr_set_screen.h"
#include "../include/scr_main.h"
#include "../include/scr_sing.h"
#include "../include/scr_sels.h"
#include "../include/scr_cj.h"
#include "../include/main.h"
#include "../include/pnl_dlg.h"
#include "../include/panel_ez.h"
#include "../include/panel.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/drawarea.h"
#include "../include/Shape.h"
#include "../include/Picture.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_txt.h"
#include "../include/Pnl_scbr.h"
#include "../include/pnl_drop.h"
#include "../include/pnl_edit.h"
#include "../include/chat.h"
#include "../include/debuglog.h"
#include "../include/com_hand.h"
#include "../include/com_addr.h"
#include "../include/scenario.h"
#include "../include/tscenaro.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/rge_base_game_global.h"
#include <stdio.h>
#include <string.h>
#include <io.h>

extern TChat* chat;
extern TDebuggingLog* L;
extern TCommunications_Handler* comm;




TribeMPSetupScreen::TribeMPSetupScreen() : TScreenPanel("MP Setup Screen") {
    char str[256];
    char* setup_file;
    TDrawArea* draw_area;
    int i;
    int y;

    L->Log("$$$ CHAT SCREEN: CONSTRUCTOR BEGIN");
    this->init_vars();

    chat->ClearChat();
    for (i = 1; i < 9; ++i) {
        chat->setInChatGroup(i, 1);
    }

    if (rge_base_game->multiplayerGame() != 0) {
        setup_file = "scr3";
    } else {
        setup_file = "scr2";
    }
    draw_area = rge_base_game->draw_area;

    if (!this->TEasy_Panel::setup(
            draw_area, 0, setup_file,
            0xC384 + (rge_base_game->multiplayerGame() != 0),
            1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(640, 480);

    if (!this->create_text(
            this, &this->title,
            0x25CF - (rge_base_game->multiplayerGame() != 0),
            20, 6, 600, 30, 1, 1, 0, 0)) {
        return;
    }
    if (!this->create_text(this, &this->playerTitle, IDS_MP_PLAYER_NAME_LABEL,
                           26, 50, 160, 30, 0, 0, 1, 0)) {
        return;
    }
    if (!this->create_text(this, &this->civTitle, IDS_MP_CIV_LABEL,
                           189, 50, 160, 30, 0, 0, 1, 0)) {
        return;
    }
    if (rge_base_game->singlePlayerGame() == 0 && !comm->IsHost()) {
        if (!this->create_text(this, &this->settingsTitle, IDS_MP_SETTINGS_LABEL,
                               420, 50, 210, 30, 0, 0, 1, 0)) {
            return;
        }
    }
    if (!this->create_text(this, &this->colorTitle, IDS_MP_PLAYER_COLOR_LABEL,
                           240, 50, 100, 30, 0, 0, 1, 0)) {
        return;
    }
    this->colorTitle->set_alignment(TTextPanel::AlignCenter,
                                     TTextPanel::AlignRight);
    if (!this->create_text(this, &this->teamTitle, IDS_MP_TEAM_LABEL,
                           310, 50, 100, 30, 0, 0, 1, 0)) {
        return;
    }
    this->teamTitle->set_alignment(TTextPanel::AlignCenter,
                                    TTextPanel::AlignRight);

    y = 0x55;
    for (i = 0; y < 0x115; ++i, y += 0x18) {
        if (!this->create_drop_down(
                this, &this->playerNameDrop[i],
                158, 100, 7, y - 1, 0x9E, 0x18, 0x0B)) {
            return;
        }
        this->playerNameDrop[i]->set_draw_style(
            TDropDownPanel::DrawStyleLeftButton);
        this->playerNameDrop[i]->set_draw_val_rect(0);
        this->playerNameDrop[i]->set_help_info(IDS_HELP_MP_PLAYER_POSITIONS, -1);
        this->playerNameDrop[i]->empty_list();
        if (rge_base_game->multiplayerGame() != 0) {
            this->playerNameDrop[i]->append_line(IDS_MP_COMPUTER_LABEL, 4);
            this->playerNameDrop[i]->append_line(IDS_MP_CLOSED_LABEL, 1);
            this->playerNameDrop[i]->append_line(IDS_MP_OPEN_LABEL, 0);
        } else {
            this->playerNameDrop[i]->append_line(IDS_MP_COMPUTER_LABEL, 4);
            this->playerNameDrop[i]->append_line(IDS_MP_NONE_LABEL, 0);
        }

        if (!this->create_drop_down(
                this, &this->playerCivDrop[i],
                128, 100, 170, y - 1, 0x80, 0x18, 0x0B)) {
            return;
        }
        this->playerCivDrop[i]->set_draw_style(
            TDropDownPanel::DrawStyleLeftButton);
        this->playerCivDrop[i]->set_draw_val_rect(0);
        this->playerCivDrop[i]->set_help_info(IDS_HELP_MP_CIVILIZATION,
                                               IDS_HELP_MP_CIVILIZATION_MORE);
        this->playerCivDrop[i]->empty_list();
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_EGYPTIAN, 1);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_GREEK, 2);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_BABYLONIAN, 3);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_ASSYRIAN, 4);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_MINOAN, 5);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_HITTITE, 6);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_PHOENICIAN, 7);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_SUMERIAN, 8);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_PERSIAN, 9);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_SHANG, 10);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_YAMATO, 11);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_CHOSON, 12);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_ROMAN, 13);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_CARTHAGINIAN, 14);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_PALMYRAN, 15);
        this->playerCivDrop[i]->append_line(IDS_CIVILIZATION_MACEDONIAN, 16);
        // This empty resource slot has no verified civilization name.
        this->playerCivDrop[i]->append_line(0x280A, 17);

        if (!this->create_drop_down(
                this, &this->scenarioPlayerDrop[i],
                40, 100, 324, y - 1, 0x28, 0x18, 0x0B)) {
            return;
        }
        this->scenarioPlayerDrop[i]->set_draw_style(
            TDropDownPanel::DrawStyleLeftButton);
        this->scenarioPlayerDrop[i]->set_draw_val_rect(0);
        this->scenarioPlayerDrop[i]->set_help_info(IDS_HELP_MP_SCENARIO_PLAYER, -1);

        if (!this->create_button(
                this, &this->playerColor[i], "", 0,
                310, y, 30, 20, 0x0B, 0, 1)) {
            return;
        }
        this->playerColor[i]->set_help_info(IDS_HELP_MP_PLAYER_COLOR, -1);
        if (!this->create_text(
                this, &this->playerColorText[i], "",
                305, y, 40, 22, 0x0B, 1, 1, 0)) {
            return;
        }

        if (!this->create_button(
                this, &this->playerTeam[i], 0x25B0, 0,
                380, y, 30, 20, 0x0B, 0, 1)) {
            return;
        }
        this->playerTeam[i]->set_help_info(IDS_HELP_MP_TEAM, -1);
        this->playerTeam[i]->set_state_info(5);
        for (int state = 1; state < 5; ++state) {
            sprintf(str, "%d", state);
            this->playerTeam[i]->set_text((short)state, str);
            this->playerTeam[i]->set_id((short)state, state + 1, 0);
        }

        if (!this->create_text(
                this, &this->playerTeamText[i], "",
                375, y, 40, 22, 0x0B, 1, 1, 0)) {
            return;
        }
        if (!this->create_text(
                this, &this->playerNameText[i], "",
                28, y + 2, 139, 22, 0x0B, 0, 0, 0)) {
            return;
        }
        if (!this->create_text(
                this, &this->playerCivText[i], "",
                191, y + 2, 109, 22, 0x0B, 0, 0, 0)) {
            return;
        }
        if (!this->create_text(
                this, &this->scenarioPlayerText[i], "",
                345, y + 2, 40, 22, 0x0B, 0, 0, 0)) {
            return;
        }
        if (!this->create_text(
                this, &this->playerCDText[i], 0x25DF,
                337, y + 3, 20, 22, 6, 0, 0, 0)) {
            return;
        }
        if (!this->create_text(
                this, &this->playerVersionText[i], "",
                353, y + 3, 29, 22, 6, 0, 0, 0)) {
            return;
        }
        this->playerCDText[i]->set_active(0);
    }

    if (rge_base_game->singlePlayerGame() != 0 || comm->IsHost()) {
        if (!this->create_button(
                this, &this->gameSettingsButton, IDS_MP_SETTINGS_LABEL, 0,
                420, 50, 210, 30, 0, 0, 0)) {
            return;
        }
        this->gameSettingsButton->set_help_info(IDS_HELP_MP_SETTINGS, -1);
    }

    if (!this->create_text(this, &this->scenarioName, "",
                           420, 84, 220, 68,
                           0x0B, 0, 0, 1)) {
        return;
    }
    y = 0x53;
    for (i = 0; y < 0x233; ++i, y += 0x18) {
        if (!this->create_text(this, &this->settingText[i], "",
                               420, y, 220, 20,
                               0x0B, 0, 0, 0)) {
            return;
        }
    }

    if (rge_base_game->multiplayerGame() != 0) {
        if (!this->create_text(this, &this->chatTitle, IDS_MP_CHAT_LABEL,
                               10, 280, 100, 20,
                               4, 0, 1, 0)) {
            return;
        }
        if (!this->create_text(this, &this->chatBox, "",
                               10, 300, 400, 96,
                               10, 0, 0, 0)) {
            return;
        }
        if (!this->create_auto_scrollbar(
                &this->chatScrollbar, this->chatBox, 20)) {
            return;
        }
        if (!this->create_edit(
                this, &this->chatInput, "", 0xF7,
                TEditPanel::FormatText, 10, 402, 400, 23,
                10, 1, 0)) {
            return;
        }
        this->chatInput->set_help_info(IDS_HELP_MP_CHAT_INPUT, -1);
        this->chatBox->set_bevel_info(
            3, this->bevel_color1, this->bevel_color2,
            this->bevel_color3, this->bevel_color4,
            this->bevel_color5, this->bevel_color6);
        this->chatBox->set_help_info(IDS_HELP_MP_CHAT_BOX, -1);
        this->chatBox->empty_list();
    }

    if (rge_base_game->singlePlayerGame() != 0) {
        if (!this->create_text(
                this, &this->numberPlayersTitle, IDS_MP_NUMBER_PLAYERS_LABEL,
                26, 295, 335, 20, 0, 0, 1, 0)) {
            return;
        }
        if (!this->create_drop_down(
                this, &this->numberPlayersDrop,
                70, 100, 31, 322, 0x46, 0x18, 0x0B)) {
            return;
        }
        this->numberPlayersDrop->set_help_info(IDS_HELP_MP_PLAYER_COUNT, -1);
    }

    this->i_am_ready = 0;
    if (rge_base_game->singlePlayerGame() != 0) {
        if (!this->create_button(
                this, &this->startButton, "", 0,
                70, 440, 240, 30, 0, 0, 0)) {
            return;
        }
        this->startButton->set_text(0, IDS_START_GAME);
        this->startButton->set_help_info(IDS_HELP_MP_START, -1);
        this->set_curr_child(this->startButton);
        if (!this->create_button(
                this, &this->cancelButton, IDS_BUTTON_CANCEL, 0,
                330, 440, 240, 30, 0, 0, 0)) {
            return;
        }
        this->cancelButton->set_help_info(IDS_HELP_CANCEL, -1);
    } else if (comm->IsHost()) {
        if (!this->create_check_box(
                this, &this->ready_button,
                10, 440, 30, 30, 0, 0)) {
            return;
        }
        if (!this->create_text(
                this, &this->ready_button_label, IDS_MP_READY_LABEL,
                45, 440, 150, 30, 0, 0, 1, 0)) {
            return;
        }
        this->ready_button->set_help_info(IDS_HELP_MP_READY, -1);
        if (!this->create_button(
                this, &this->startButton, "", 0,
                195, 440, 200, 30, 0, 0, 0)) {
            return;
        }
        this->startButton->set_text(0, IDS_START_GAME);
        this->startButton->set_help_info(IDS_HELP_MP_START, -1);
        this->startButton->set_disabled(1);
        if (!this->create_button(
                this, &this->cancelButton, IDS_BUTTON_CANCEL, 0,
                405, 440, 180, 30, 0, 0, 0)) {
            return;
        }
        this->cancelButton->set_help_info(IDS_HELP_CANCEL, -1);
        if (!this->create_button(
                this, &this->netInfoButton, IDS_IP_LABEL, 0,
                600, 400, 30, 30, 0, 0, 0)) {
            return;
        }
        this->netInfoButton->set_help_info(IDS_HELP_MP_NETWORK_INFO, -1);
        comm->SetMyReadiness(0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        if (!this->create_check_box(
                this, &this->ready_button,
                100, 440, 30, 30, 0, 0)) {
            return;
        }
        if (!this->create_text(
                this, &this->ready_button_label, IDS_MP_READY_LABEL,
                135, 440, 150, 30, 0, 0, 1, 0)) {
            return;
        }
        this->ready_button->set_help_info(IDS_HELP_MP_READY, -1);
        if (!this->create_button(
                this, &this->cancelButton, IDS_BUTTON_CANCEL, 0,
                330, 440, 240, 30, 0, 0, 0)) {
            return;
        }
        this->cancelButton->set_help_info(IDS_HELP_CANCEL, -1);
    }

    if (!this->create_button(
            this, &this->help_button, IDS_BUTTON_HELP, 0,
            600, 440, 30, 30, 0, 0, 0)) {
        return;
    }
    if (!this->create_button(
            this, &this->close_button, IDS_BUTTON_CLOSE, 0,
            0, 0, 0, 0, -1, -1, 0)) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning(
        TPanel::PositionRightTop, 4, 4, 4, 4,
        17, 17, 17, 17, 0, 0, 0, 0);

    TButtonPanel* cancel = this->cancelButton;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;
    this->setupTabOrder();
    L->Log("$$$ CHAT SCREEN: UPDATE SUMMARY");
    this->updateSummary();
    if (rge_base_game->singlePlayerGame() != 0) {
        this->setupSinglePlayerPlayers();
        this->fillPlayers();
    }
    L->Log("$$$ CHAT SCREEN: CONSTRUCTOR DONE");
}




void TribeMPSetupScreen::init_vars() {
    int i;

    this->title = 0;
    this->playerTitle = 0;
    this->civTitle = 0;
    this->settingsTitle = 0;
    this->colorTitle = 0;
    this->teamTitle = 0;

    for (i = 0; i < 8; ++i) {
        this->playerNameDrop[i] = 0;
        this->playerCivDrop[i] = 0;
        this->scenarioPlayerDrop[i] = 0;
        this->playerColor[i] = 0;
        this->playerTeam[i] = 0;
        this->playerNameText[i] = 0;
        this->playerCivText[i] = 0;
        this->scenarioPlayerText[i] = 0;
        this->playerCDText[i] = 0;
        this->playerVersionText[i] = 0;
        this->playerColorText[i] = 0;
        this->playerTeamText[i] = 0;
    }

    this->chatInput = 0;
    this->chatTitle = 0;
    this->chatScrollbar = 0;
    this->chatBox = 0;
    this->gameSettingsButton = 0;
    this->scenarioName = 0;
    this->victoryFixedText = 0;

    for (i = 0; i < 20; ++i) {
        this->settingText[i] = 0;
        this->settingValue[i] = 0;
    }

    this->mapSizeLabel = 0;
    this->mapSizeDrop = 0;
    this->mapTypeLabel = 0;
    this->mapTypeDrop = 0;
    this->numberPlayersTitle = 0;
    this->numberPlayersDrop = 0;
    this->numberPlayersText = 0;
    this->hiddenMapButton = 0;
    this->hiddenMapText = 0;
    this->victoryTypeLabel = 0;
    this->victoryTypeDrop = 0;
    this->victoryAmountLabel = 0;
    this->victoryAmountInput = 0;
    this->ready_button_label = 0;
    this->startButton = 0;
    this->readyButtons[0] = 0;
    this->readyButtons[1] = 0;
    this->cancelButton = 0;
    this->help_button = 0;
    this->ready_button = 0;
    this->close_button = 0;
    this->cancelMode = 0;
    this->playerToKick = 0;
    this->myCivilization = 0;
    this->myScenarioPlayer = -1;
    this->myPlayerColor = 0;
    this->myPlayerTeam = 0;
    this->myScenarioChecksum = 0;
    this->saveScenarioName[0] = 0;
    this->saveRandomGame = rge_base_game->randomGame();
    long* zero_block = this->scenarioCheckSum;
    this->saveScenarioChecksum = 0;
    this->scenarioInfo = 0;
    this->numberAnyPlayers = 8;
    this->scenarioPlayerCount = 8;
    this->settingsFixed = 0;
    this->sent_cd_status = 0;
    this->netInfoButton = 0;
    this->i_am_ready = 0;
    for (i = 0; i < 8; ++i) {
        zero_block[i] = 0;
    }
    this->last_send_shared = 0;
    this->resend_game_options = 0;

    if (rge_base_game->multiplayerGame() != 0) {
        rge_base_game->setCampaignGame(0);
        rge_base_game->setSavedGame(0);
        rge_base_game->setScenarioGame(0);
        rge_base_game->setScenarioName("");
        static_cast<TRIBE_Game*>(rge_base_game)->setMapSize(
            static_cast<TRIBE_Game::MapSize>(3));
        static_cast<TRIBE_Game*>(rge_base_game)->setMapType(
            static_cast<TRIBE_Game::MapType>(3));
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(
            static_cast<TRIBE_Game::VictoryType>(0), 0);
        static_cast<TRIBE_Game*>(rge_base_game)->setAnimals(1);
        static_cast<TRIBE_Game*>(rge_base_game)->setPredators(1);
        rge_base_game->setNumberPlayers(8);
        rge_base_game->setFullVisibility(0);
        rge_base_game->setFogOfWar(1);
        rge_base_game->setAllowCheatCodes(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setRandomizePositions(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setLongCombat(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setAllowTrading(1);
        static_cast<TRIBE_Game*>(rge_base_game)->setFullTechTree(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setResourceLevel(
            static_cast<TRIBE_Game::ResourceLevel>(0));
        static_cast<TRIBE_Game*>(rge_base_game)->setStartingAge(
            static_cast<TRIBE_Game::Age>(0));
        static_cast<TRIBE_Game*>(rge_base_game)->setStartingUnits(0);
        rge_base_game->setDifficulty(
            rge_base_game->get_single_player_difficulty());
        static_cast<TRIBE_Game*>(rge_base_game)->setDeathMatch(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setQuickStartGame(0);
        unsigned long now = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 579);
        debug_srand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 579, now);

        for (i = 0; i < 8; ++i) {
            this->defaultColor[i] = static_cast<unsigned char>(i + 1);
            static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                i,
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 584) %
                        16 +
                    1);
            static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(i, i);
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerHasCD(i, 0);
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerVersion(i, 0);
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                i, this->defaultColor[i]);
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerTeam(i, 1);
            static_cast<TRIBE_Game*>(rge_base_game)->setComputerName(i, 0);
        }

        if (comm->IsHost() != 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerVersion(0, 1);
            rge_base_game->send_game_options();
            this->resend_game_options = 0;
            return;
        }
    } else {
        if (rge_base_game->scenarioGame() == 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->setMapSize(
                static_cast<TRIBE_Game::MapSize>(3));
            int random_map = debug_rand(
                                  "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 618) %
                              10;
            int map_type;
            if (random_map < 2) {
                map_type = 4;
            } else if (random_map == 2) {
                map_type = 3;
            } else if (random_map == 3) {
                map_type = 2;
            } else if (random_map == 4) {
                map_type = 1;
            } else if (random_map == 5) {
                map_type = random_map;
            } else if (random_map == 6) {
                map_type = random_map;
            } else if (random_map == 7) {
                map_type = random_map;
            } else {
                map_type = (random_map == 8) ? 8 : 0;
            }
            static_cast<TRIBE_Game*>(rge_base_game)->setMapType(
                static_cast<TRIBE_Game::MapType>(map_type));
        }
        static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(
            static_cast<TRIBE_Game::VictoryType>(0), 0);
        rge_base_game->setNumberPlayers(4);
        rge_base_game->setCampaignGame(0);
        rge_base_game->setSavedGame(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setAnimals(1);
        static_cast<TRIBE_Game*>(rge_base_game)->setPredators(1);
        rge_base_game->setFullVisibility(0);
        rge_base_game->setFogOfWar(1);
        rge_base_game->setAllowCheatCodes(1);
        static_cast<TRIBE_Game*>(rge_base_game)->setRandomizePositions(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setLongCombat(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setAllowTrading(1);
        static_cast<TRIBE_Game*>(rge_base_game)->setFullTechTree(0);
        static_cast<TRIBE_Game*>(rge_base_game)->setResourceLevel(
            static_cast<TRIBE_Game::ResourceLevel>(0));
        static_cast<TRIBE_Game*>(rge_base_game)->setStartingAge(
            static_cast<TRIBE_Game::Age>(0));
        static_cast<TRIBE_Game*>(rge_base_game)->setStartingUnits(0);
        rge_base_game->setDifficulty(
            rge_base_game->get_single_player_difficulty());
        static_cast<TRIBE_Game*>(rge_base_game)->setQuickStartGame(0);
    }
}




TribeMPSetupScreen::~TribeMPSetupScreen() {
    if (this->scenarioInfo != 0) {
        delete this->scenarioInfo;
        this->scenarioInfo = 0;
    }

    panel_system.destroyPanel("Game Settings Screen");
    panel_system.destroyPanel("Select Tribe Screen");
    panel_system.destroyPanel("Kick Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->playerTitle);
    this->delete_panel((TPanel**)&this->civTitle);
    this->delete_panel((TPanel**)&this->settingsTitle);
    this->delete_panel((TPanel**)&this->colorTitle);
    this->delete_panel((TPanel**)&this->teamTitle);

    for (int i = 0; i < 8; i++) {
        this->delete_panel((TPanel**)&this->playerNameDrop[i]);
        this->delete_panel((TPanel**)&this->playerCivDrop[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerDrop[i]);
        this->delete_panel((TPanel**)&this->playerColor[i]);
        this->delete_panel((TPanel**)&this->playerTeam[i]);
        this->delete_panel((TPanel**)&this->playerNameText[i]);
        this->delete_panel((TPanel**)&this->playerCivText[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerText[i]);
        this->delete_panel((TPanel**)&this->playerCDText[i]);
        this->delete_panel((TPanel**)&this->playerVersionText[i]);
        this->delete_panel((TPanel**)&this->playerColorText[i]);
        this->delete_panel((TPanel**)&this->playerTeamText[i]);
    }

    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->chatBox);
    this->delete_panel((TPanel**)&this->gameSettingsButton);
    this->delete_panel((TPanel**)&this->scenarioName);
    this->delete_panel((TPanel**)&this->victoryFixedText);

    for (int j = 0; j < 20; j++) {
        this->delete_panel((TPanel**)&this->settingText[j]);
        this->delete_panel((TPanel**)&this->settingValue[j]);
    }

    this->delete_panel((TPanel**)&this->mapSizeLabel);
    this->delete_panel((TPanel**)&this->mapSizeDrop);
    this->delete_panel((TPanel**)&this->mapTypeLabel);
    this->delete_panel((TPanel**)&this->mapTypeDrop);
    this->delete_panel((TPanel**)&this->numberPlayersTitle);
    this->delete_panel((TPanel**)&this->numberPlayersDrop);
    this->delete_panel((TPanel**)&this->numberPlayersText);
    this->delete_panel((TPanel**)&this->hiddenMapButton);
    this->delete_panel((TPanel**)&this->hiddenMapText);
    this->delete_panel((TPanel**)&this->victoryTypeLabel);
    this->delete_panel((TPanel**)&this->victoryTypeDrop);
    this->delete_panel((TPanel**)&this->victoryAmountLabel);
    this->delete_panel((TPanel**)&this->victoryAmountInput);
    this->delete_panel((TPanel**)&this->startButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->ready_button);
    this->delete_panel((TPanel**)&this->ready_button_label);
    this->delete_panel((TPanel**)&this->netInfoButton);
    this->delete_panel((TPanel**)&this->help_button);
}




long TribeMPSetupScreen::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    if (rge_base_game->multiplayerGame()) {
        if (last_send_shared == 0) {
            last_send_shared = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 766);
        } else {
            unsigned long t = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 769);
            if (t - last_send_shared != 0) {
                comm->SendSharedData(0);
                last_send_shared = debug_timeGetTime(
                    "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 772);
            }
        }
    }
    return TPanel::handle_idle();
}


long TribeMPSetupScreen::key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key) {
    return 0;
}



long TribeMPSetupScreen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel != 0) {
        if (fromPanel == this->startButton && actionIn == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->startGame();
            return 1;
        }

        if (fromPanel == this->ready_button && actionIn == 1) {
            if (this->ready_button->get_state() != 0) {
                L->Log("$$$ SELECTED I'M READY");
                if (comm->IsHost()) {
                    comm->SetMyReadiness(1, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    if (rge_base_game->playerVersion(0) != 1) {
                        this->ready_button->set_state(0);
                        this->popupOKDialog(IDS_HOST_VERSION_ERROR, 0, TEASY_POPUP_WIDTH, 100);
                        return 1;
                    }

                    int player = comm->WhoAmI() - 1;
                    L->Log("$$$ SAVING MYCIV & MYTEAM");
                    this->myCivilization =
                        this->playerCivDrop[player]->get_id();
                    this->myScenarioPlayer =
                        this->scenarioPlayerDrop[player]->get_id();
                    this->myPlayerColor =
                        this->playerColor[player]->get_id();
                    this->myPlayerTeam =
                        this->playerTeam[player]->get_state() + 1;

                    if (rge_base_game->scenarioGame()) {
                        char file_name[260];
                        struct _finddata_t file_info;
                        char* scenario_dir =
                            rge_base_game->prog_info->scenario_dir;
                        sprintf(file_name, "%s%s.scn", scenario_dir,
                                rge_base_game->scenarioName());
                        if (_findfirst(file_name, &file_info) == -1) {
                            sprintf(file_name, "%s.scx",
                                    rge_base_game->scenarioName());
                        } else {
                            sprintf(file_name, "%s.scn",
                                    rge_base_game->scenarioName());
                        }
                        this->myScenarioChecksum =
                            rge_base_game->get_scenario_checksum(file_name);
                    } else {
                        this->myScenarioChecksum = 0;
                    }

                    comm->SetMyReadiness(
                        1, this->myCivilization,
                        this->myScenarioPlayer + 1,
                        rge_base_game->check_for_cd(0) + 1,
                        this->myPlayerColor, this->myPlayerTeam,
                        this->myScenarioChecksum, 1);
                }

                if (this->chatInput != 0 && this->chatInput->active != 0) {
                    this->set_curr_child(this->chatInput);
                }
                this->i_am_ready = 1;
            } else {
                L->Log("$$$ SELECTED NOT READY");
                int cd_status;
                if (comm->IsHost()) {
                    cd_status = 0;
                } else {
                    cd_status = rge_base_game->check_for_cd(0) + 1;
                }
                comm->SetMyReadiness(0, 0, 0, cd_status, 0, 0, 0, 0);
                if (this->chatInput != 0 && this->chatInput->active != 0) {
                    this->set_curr_child(this->chatInput);
                }
                this->i_am_ready = 0;
            }

            this->fillPlayers();
            if (comm->IsHost()) {
                this->gameSettingsButton->set_disabled(this->i_am_ready);
                this->startButton->set_disabled(!this->i_am_ready);
                rge_base_game->send_game_options();
                this->resend_game_options = 0;
                comm->SendSharedData(1);
            }
            return 1;
        }

        if (fromPanel == this->gameSettingsButton && actionIn == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            if (panel_system.panel("Game Settings Screen") == 0) {
                rge_base_game->disable_input();
                new TribeGameSettingsScreen;
            }
            panel_system.setCurrentPanel("Game Settings Screen", 0);
            return 1;
        }

        if (fromPanel == this->help_button && actionIn == 1) {
            this->setup_popup_help();
            return 1;
        }

        if (fromPanel == this->close_button && actionIn == 1) {
            rge_base_game->close();
            return 1;
        }

        if (fromPanel == this->cancelButton && actionIn == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->cancelScreen(0);
            return 1;
        }

        if (fromPanel == this->netInfoButton) {
            if (actionIn == 1) {
                this->showNetInfo();
                return 1;
            }
        } else if (actionIn == 1) {
            for (int i = 0; i < 8; ++i) {
                if (fromPanel == this->playerColor[i]) {
                    int color = this->playerColor[i]->get_id();
                    static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                        i, color);
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerColor =
                            this->playerColor[i]->get_id();
                    }
                    return 1;
                }

                if (fromPanel == this->playerTeam[i]) {
                    int team = this->playerTeam[i]->get_state() + 1;
                    rge_base_game->setPlayerTeam(i, team);
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerTeam =
                            this->playerTeam[i]->get_state() + 1;
                    }
                    return 1;
                }
            }
        }

        if (fromPanel == this->chatInput && actionIn == 0 &&
            this->chatInput->currentLine() != 0 &&
            this->chatInput->currentLine()[0] != 0) {
            comm->SendChatMsgAll(this->chatInput->currentLine());
            this->chatInput->set_text("");
            return 1;
        }

        if (fromPanel == this->numberPlayersDrop && actionIn == 0) {
            rge_base_game->setNumberPlayers(
                this->numberPlayersDrop->get_id());
            this->updateSummary();
            return 1;
        }

        if (fromPanel->panelName() != 0 &&
            strcmp(fromPanel->panelName(), "Game Settings Screen") == 0) {
            if (actionIn != 0) {
                this->updateSummary();
                if (!rge_base_game->singlePlayerGame()) {
                    rge_base_game->send_game_options();
                    this->resend_game_options = 0;
                }
            }
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            return 1;
        }

        if (fromPanel->panelName() != 0 &&
            strcmp(fromPanel->panelName(), "Kick Dialog") == 0) {
            if (actionIn == 0) {
                PLAYERHUMANITY humanity =
                    static_cast<PLAYERHUMANITY>(
                        this->playerNameDrop[this->playerToKick - 1]
                            ->get_id());
                comm->Kick(this->playerToKick);
                comm->SetPlayerHumanity(this->playerToKick, humanity);
                long line =
                    this->playerNameDrop[this->playerToKick - 1]
                        ->get_line(humanity);
                this->playerNameDrop[this->playerToKick - 1]->set_line(line);
            } else {
                this->playerNameDrop[this->playerToKick - 1]->set_line(0);
            }
            delete fromPanel;
            return 1;
        }

        if (actionIn == 0 && rge_base_game->numberPlayers() > 0) {
            int i = 0;
            do {
                if (fromPanel == this->playerNameDrop[i]) {
                    if (rge_base_game->multiplayerGame() &&
                        this->playerNameDrop[i]->get_line() > 0 &&
                        comm->IsPlayerHuman(i + 1)) {
                        this->kickPlayer(i + 1);
                    } else {
                        comm->SetPlayerHumanity(
                            i + 1,
                            static_cast<PLAYERHUMANITY>(
                                this->playerNameDrop[i]->get_id()));
                    }
                    return 1;
                }

                if (fromPanel == this->playerCivDrop[i]) {
                    int civilization = this->playerCivDrop[i]->get_id();
                    static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                        i, civilization);
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myCivilization =
                            this->playerCivDrop[i]->get_id();
                    }
                    return 1;
                }

                if (fromPanel == this->scenarioPlayerDrop[i]) {
                    if (rge_base_game->multiplayerGame()) {
                        int scenario_player =
                            this->scenarioPlayerDrop[i]->get_id();
                        static_cast<TRIBE_Game*>(rge_base_game)
                            ->setScenarioPlayer(i, scenario_player);
                        if (!comm->IsHost()) {
                            this->myScenarioPlayer =
                                this->scenarioPlayerDrop[i]->get_id();
                        }
                        return 1;
                    }

                    int scenario_player =
                        this->scenarioPlayerDrop[0]->get_id();
                    static_cast<TRIBE_Game*>(rge_base_game)
                        ->setScenarioPlayer(0, scenario_player);
                    int player = 1;
                    int position = 0;
                    do {
                        if (position !=
                                static_cast<TRIBE_Game*>(rge_base_game)
                                    ->scenarioPlayer(0) &&
                            this->scenarioInfo->Get_player_Active(position)) {
                            static_cast<TRIBE_Game*>(rge_base_game)
                                ->setScenarioPlayer(player, position);
                            ++player;
                            if (player >= rge_base_game->numberPlayers()) {
                                break;
                            }
                        }
                        ++position;
                    } while (position < 8);
                    this->fillPlayers();
                    return 1;
                }

                ++i;
            } while (i < rge_base_game->numberPlayers());
        }
    }

    return this->TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}




int TribeMPSetupScreen::startGame() {
    int send_options = 0;

    if (rge_base_game->multiplayerGame()) {
        char msg[1024];
        if (!comm->IsHost()) {
            return 0;
        }
        if (!comm->AllPlayersReady()) {
            this->popupOKDialog(IDS_ERROR_PLAYERS_NOT_READY, 0, TEASY_POPUP_WIDTH, 100);
            return 0;
        }
        int u12;
        if (rge_base_game->scenarioGame()) {
            int i3;
            long* pl;
            for (i3 = 0, u12 = 1, pl = this->scenarioCheckSum; u12 < 9; i3++, pl++, u12++) {
                if (u12 != comm->WhoAmI() &&
                    comm->GetPlayerHumanity(u12) == 2) {
                    if (*pl != this->myScenarioChecksum) {
                        sprintf(msg, this->get_string(IDS_SCENARIO_VERSION_ERROR), comm->GetPlayerName(i3 + 1));
                        this->popupOKDialog(msg, 0, TEASY_POPUP_WIDTH, 100);
                        return 0;
                    }
                }
            }
        }
        int u4;
        for (u12 = 0; u12 < 8; u12 = u4) {
            u4 = u12 + 1;
            if (u4 != comm->WhoAmI() &&
                comm->GetPlayerHumanity(u4) == 2) {
                if (rge_base_game->playerVersion(u12) != 1) {
                    sprintf(msg, this->get_string(IDS_PLAYER_VERSION_ERROR), comm->GetPlayerName(u12 + 1));
                    this->popupOKDialog(msg, 0, TEASY_POPUP_WIDTH, 100);
                    return 0;
                }
            }
        }
    }

    if (rge_base_game->scenarioGame() && this->scenarioInfo == 0) {
        this->popupOKDialog(IDS_ERROR_INVALID_SCENARIO, 0, TEASY_POPUP_WIDTH, 100);
        return 0;
    }

    if (rge_base_game->multiplayerGame() && rge_base_game->scenarioGame()) {
        int i3 = 0;
        int u12 = 0;
        int u4b;
        do {
            u4b = u12 + 1;
            int hum = comm->GetPlayerHumanity(u4b);
            if (hum == 2 || hum == 4) {
                long id = this->scenarioPlayerDrop[0]->get_id(i3);
                static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(u12, id);
                i3++;
                if (i3 >= this->scenarioPlayerDrop[0]->list_panel->numberLines()) {
                    i3 = 0;
                }
            }
            u12 = u4b;
        } while (u4b < 8);
    }

    if (rge_base_game->multiplayerGame()) {
        int playerColorUsed[8];
        char msg[256];
        memset(playerColorUsed, 0, sizeof(playerColorUsed));
        int i5 = 0;
        int u12 = 0;
        int num = rge_base_game->numberPlayers();
        if (num > 0) {
            int u4c;
            do {
                u4c = u12 + 1;
                int hum = comm->GetPlayerHumanity(u4c);
                if (hum == 2 || hum == 4) {
                    if (hum == 2) {
                        int c = static_cast<TRIBE_Game*>(rge_base_game)->playerColor(u12);
                        if (playerColorUsed[c - 1] == 0) {
                            i5++;
                            c = static_cast<TRIBE_Game*>(rge_base_game)->playerColor(u12);
                            playerColorUsed[c - 1] = 1;
                        }
                    } else {
                        i5++;
                    }
                }
                u12 = u4c;
            } while (u4c < rge_base_game->numberPlayers());
        }
        if (i5 < 2) {
            this->popupOKDialog(IDS_ERROR_ONE_PLAYER, 0, TEASY_POPUP_WIDTH, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && i5 > this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(IDS_SCENARIO_MAX_PLAYERS), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, TEASY_POPUP_WIDTH, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && this->settingsFixed != 0 &&
            i5 != this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(IDS_SCENARIO_EXACT_PLAYERS), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, TEASY_POPUP_WIDTH, 100);
            return 0;
        }

        int i5h = 0;
        int u12c = 0;
        int nump = rge_base_game->numberPlayers();
        if (nump > 0) {
            do {
                u12c++;
                if (comm->GetPlayerHumanity(u12c) == 2) {
                    i5h++;
                }
            } while (u12c < rge_base_game->numberPlayers());
        }
        int cd = rge_base_game->check_for_cd(0);
        rge_base_game->setPlayerHasCD(comm->WhoAmI() - 1, cd);
        int cd2 = rge_base_game->check_for_cd(i5h);
        if (cd2 == 0) {
            this->popupOKDialog(IDS_ERROR_CD_REQUIRED, 0, TEASY_POPUP_WIDTH, 100);
            return 0;
        }
    }

    if (rge_base_game->scenarioGame() && static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions()) {
        this->calcRandomPositions();
        if (rge_base_game->multiplayerGame()) {
            send_options = 1;
        }
    }

    if (rge_base_game->singlePlayerGame()) {
        int num = rge_base_game->numberPlayers();
        if (num < 8) {
            int u12 = num + 1;
            do {
                comm->SetPlayerHumanity(u12, ME_ABSENT);
                u12++;
            } while (u12 < 9);
        }
    }

    if (rge_base_game->multiplayerGame()) {
        int i5 = 0;
        int num = rge_base_game->numberPlayers();
        if (num > 0) {
            do {
                int civ = static_cast<TRIBE_Game*>(rge_base_game)->civilization(i5);
                if (civ >= 0x32) {
                    L->Log("$$$ HOST RESET2 CIV+50");
                    civ = static_cast<TRIBE_Game*>(rge_base_game)->civilization(i5);
                    static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(i5, civ - 0x32);
                    send_options = 1;
                }
                int team = rge_base_game->playerTeam(i5);
                if (team >= 0x32) {
                    L->Log("$$$ HOST RESET2 TEAM+50");
                    team = rge_base_game->playerTeam(i5);
                    rge_base_game->setPlayerTeam(i5, team - 0x32);
                    send_options = 1;
                }
                i5++;
            } while (i5 < rge_base_game->numberPlayers());
        }
    }

    if (rge_base_game->multiplayerGame()) {
        int temp_team[8];
        int temp_color[8];
        int temp_civ[8];
        int idx = 0;
        for (int i = 0; i < 8; i++) temp_team[i] = 1;
        for (int j = 0; j < 8; j++) temp_civ[j] = 1;
        do {
            int val = idx + 1;
            temp_color[idx] = val;
            idx = val;
        } while (idx < 8);
        int cnt = 0;
        for (int u12 = 1; u12 < 9; u12++) {
            int hum = comm->GetPlayerHumanity(u12);
            if (hum == 2 || hum == 4) {
                int p = u12 - 1;
                temp_color[cnt] = static_cast<TRIBE_Game*>(rge_base_game)->playerColor(p);
                temp_civ[cnt] = static_cast<TRIBE_Game*>(rge_base_game)->civilization(p);
                temp_team[cnt] = rge_base_game->playerTeam(p);
                cnt++;
            }
        }
        if (cnt > 0) {
            for (int i = 0; i < 8; i++) {
                static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(i, temp_color[i]);
                static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(i, temp_civ[i]);
                rge_base_game->setPlayerTeam(i, temp_team[i]);
            }
            send_options = 1;
        }
    }

    panel_system.destroyPanel("Status Screen");

    if (rge_base_game->multiplayerGame()) {
        if (send_options || this->resend_game_options != 0) {
            rge_base_game->send_game_options();
            this->resend_game_options = 0;
        }
        comm->LaunchMultiplayerGame();
        chat->setWindowHandle(AppWnd);
        comm->SetWindowHandle(AppWnd);
    }

    if (!static_cast<TRIBE_Game*>(rge_base_game)->start_game(0)) {
        this->popupOKDialog(IDS_ERROR_START_GAME, 0, TEASY_POPUP_WIDTH, 100);
        return 0;
    }
    return 1;
}




void TribeMPSetupScreen::calcRandomPositions() {
    int selected_position;
    int position_used[9];
    int human_players = 0;
    int i = 0;
    int players = rge_base_game->numberPlayers();

    if (players > 0) {
        do {
            ++i;
            int humanity = comm->GetPlayerHumanity(i);
            if (humanity == 2 || humanity == 4) {
                ++human_players;
            }
            players = rge_base_game->numberPlayers();
        } while (i < players);
    }

    int available = 0;
    i = 0;
    do {
        long line = this->scenarioPlayerDrop[0]->get_line(i);
        if (line == -1) {
            position_used[i + 1] = -2;
        } else {
            position_used[i + 1] = -1;
            ++available;
        }
        ++i;
    } while (i < 8);

    if (human_players <= available) {
        int player = 0;
        for (; player < rge_base_game->numberPlayers(); player = position_used[0]) {
                position_used[0] = player + 1;
                int humanity = comm->GetPlayerHumanity(position_used[0]);
                if (humanity == 2 || humanity == 4) {
                    int j = 0;
                    int count = this->scenarioPlayerCount;
                    if (count > 0) {
                        int* position = &position_used[1];
                        do {
                            if (*position != -1) {
                                ++j;
                                ++position;
                            } else {
                                selected_position = j;
                                break;
                            }
                        } while (j < count);
                    }

                    int tries = 0;
                    int new_position;
                    for (; tries < 1000; ++tries) {
                        int count = this->scenarioPlayerCount;
                        new_position =
                            (debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 1508) * count) /
                            0x7FFF;
                        if (new_position >= count) {
                            new_position = count - 1;
                        } else if (new_position < 0) {
                            new_position = 0;
                        }
                        if (position_used[new_position + 1] == -1) {
                            selected_position = new_position;
                            break;
                        }
                    }

                    static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(player, selected_position);
                    position_used[selected_position + 1] = player;
                }
        }
    }
}




void TribeMPSetupScreen::showNetInfo() {
    char message[1024];
    char temp_str[256];

    RGE_Communications_Addresses* addresses = new RGE_Communications_Addresses(comm);
    if (addresses) {
        unsigned int num_addr = addresses->AddressesAvailable;
        message[0] = 0;
        if (num_addr > 0) {
            strcat(message, "\n\n");
            sprintf(temp_str, this->get_string(IDS_HOST_NAME_FORMAT), addresses->GetHostName());
            strcat(message, temp_str);
            strcat(message, "\n");
            for (unsigned int i = 0; i < num_addr; i++) {
                if (addresses->GetAddress(i)) {
                    strcat(message, addresses->GetAddress(i));
                    strcat(message, " ");
                }
                if (addresses->GetAlias(i)) {
                    strcat(message, addresses->GetAlias(i));
                }
                strcat(message, "\n");
            }
            this->TEasy_Panel::popupOKDialog(
                message, "OKDialog", TEASY_POPUP_WIDTH, num_addr * 18 + 100);
        } else {
            this->TEasy_Panel::popupOKDialog(IDS_NO_IP_INFO_ERROR, 0, TEASY_POPUP_WIDTH, 100);
        }
        delete addresses;
    }
}




void TribeMPSetupScreen::cancelScreen(int lobbyTimeout) {
    if (rge_base_game->singlePlayerGame() != 0) {
        rge_base_game->disable_input();
        if (rge_base_game->scenarioGame() != 0) {
            new TribeSelectScenarioScreen;
            panel_system.setCurrentPanel("Select Scenario Screen", 0);
        } else {
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel("Single Player Menu", 0);
        }
    } else if (comm->IsLobbyLaunched() != 0) {
        if (lobbyTimeout != 0) {
            TRIBE_Screen_Main_Error* error = new TRIBE_Screen_Main_Error;
            if (error != 0 && error->error_code == 0) {
                error->set_text(IDS_ERROR_CONNECTION_TIMEOUT);
                panel_system.setCurrentPanel("Main Error Screen", 0);
            } else {
                rge_base_game->close();
                return;
            }
        } else {
            rge_base_game->close();
            return;
        }
    } else {
        rge_base_game->disable_input();
        comm->UnlinkToLevel(SERVICE_AVAILABLE);
        new TribeJoinScreen;
        panel_system.setCurrentPanel("Join Screen", 0);
    }

    panel_system.destroyPanel("MP Setup Screen");
}




long TribeMPSetupScreen::handle_user_command(unsigned int wParam, long lParam) {
    char message[256];

    if (rge_base_game->singlePlayerGame()) {
        return 1;
    }

    switch (wParam) {
    case COMM_SHARED_DATA_SENT: {
        L->Log("$$$ USER_COMMAND: COMM_SHARED_DATA_SENT (%d,%d)", wParam,
               lParam);
        if (comm->IsHost()) {
            for (int i = 0; i < rge_base_game->numberPlayers(); ++i) {
                int civilization =
                    static_cast<TRIBE_Game*>(rge_base_game)->civilization(i);
                if (civilization >= 0x32) {
                    L->Log("$$$ HOST RESET CIV+50");
                    civilization =
                        static_cast<TRIBE_Game*>(rge_base_game)->civilization(i);
                    static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                        i, civilization - 0x32);
                    this->resend_game_options = 1;
                }

                int team = rge_base_game->playerTeam(i);
                if (team >= 0x32) {
                    L->Log("$$$ HOST RESET TEAM+50");
                    team = rge_base_game->playerTeam(i);
                    rge_base_game->setPlayerTeam(i, team - 0x32);
                    this->resend_game_options = 1;
                }
            }
        }
        return 1;
    }

    case COMM_UPDATE_PLAYERS: {
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PLAYERS (%d,%d)", wParam,
               lParam);
        int changed = 0;

        if (comm->IsHost() && this->sent_cd_status == 0) {
            this->sent_cd_status = 1;
            if (rge_base_game->check_for_cd(0) != 0) {
                changed = 1;
                rge_base_game->setPlayerHasCD(comm->WhoAmI() - 1, 1);
            }
        }

        if (comm->IsHost()) {
            long* scenario_checksum = this->scenarioCheckSum;
            for (int i = 0; i < 8; ++i, ++scenario_checksum) {
                int player = i + 1;
                int humanity = comm->GetPlayerHumanity(player);
                if (comm->WhoAmI() == player) {
                    if (humanity == ME_HUMAN) {
                        continue;
                    }
                } else if (humanity == ME_HUMAN) {
                    int ready;
                    unsigned long user3;
                    unsigned long user6;
                    unsigned long user7;
                    unsigned long user1;
                    unsigned long user4;
                    unsigned long checksum;
                    unsigned long user2;

                    comm->GetClientReadiness(
                        player, &ready, &user3, &user6,
                        &user7, &user1, &user4, &checksum, &user2);

                    if (user3 != 0 &&
                        user3 != static_cast<unsigned long>(
                                            static_cast<TRIBE_Game*>(
                                                rge_base_game)
                                                ->civilization(i))) {
                        static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                            i, user3);
                        changed = 1;
                    }
                    if (user6 != 0) {
                        int value = static_cast<int>(user6) - 1;
                        if (value != static_cast<TRIBE_Game*>(rge_base_game)
                                        ->scenarioPlayer(i)) {
                            static_cast<TRIBE_Game*>(rge_base_game)
                                ->setScenarioPlayer(i, value);
                            changed = 1;
                        }
                    }
                    if (user7 != 0) {
                        if (user7 == 1) {
                            if (rge_base_game->playerHasCD(i) == 1) {
                                rge_base_game->setPlayerHasCD(i, 0);
                                changed = 1;
                            }
                        } else if (user7 == 2 &&
                                   rge_base_game->playerHasCD(i) == 0) {
                            rge_base_game->setPlayerHasCD(i, 1);
                            changed = 1;
                        }
                    }
                    if (user1 != 0 &&
                        user1 != static_cast<unsigned long>(
                                    static_cast<TRIBE_Game*>(rge_base_game)
                                        ->playerColor(i))) {
                        static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                            i, user1);
                        changed = 1;
                    }
                    if (user4 != 0 &&
                        user4 != static_cast<unsigned long>(
                                    rge_base_game->playerTeam(i))) {
                        rge_base_game->setPlayerTeam(i, user4);
                        changed = 1;
                    }
                    if (checksum != 0) {
                        *scenario_checksum = checksum;
                    }
                    if (user2 != 0) {
                        rge_base_game->setPlayerVersion(
                            i, static_cast<unsigned char>(user2));
                        changed = 1;
                    }
                    continue;
                }

                if (humanity == ME_COMPUTER) {
                    continue;
                }

                int civilization =
                    debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp",
                               1750) %
                        16 +
                    1;
                if (static_cast<TRIBE_Game*>(rge_base_game)->civilization(i) !=
                    civilization) {
                    static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                        i, civilization);
                    changed = 1;
                }
                if (static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(i) !=
                    i) {
                    static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(
                        i, i);
                    changed = 1;
                }
                if (rge_base_game->playerHasCD(i) != 0) {
                    rge_base_game->setPlayerHasCD(i, 0);
                    changed = 1;
                }
                if (static_cast<TRIBE_Game*>(rge_base_game)->playerColor(i) !=
                    this->defaultColor[i]) {
                    static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                        i, this->defaultColor[i]);
                    changed = 1;
                }
                if (rge_base_game->playerTeam(i) != 1) {
                    rge_base_game->setPlayerTeam(i, 1);
                    changed = 1;
                }
                if (rge_base_game->playerVersion(i) != 0) {
                    rge_base_game->setPlayerVersion(i, 0);
                    changed = 1;
                }
                *scenario_checksum = 0;
            }

            if (changed != 0) {
                rge_base_game->send_game_options();
                this->resend_game_options = 0;
            }
        }

        this->fillPlayers();
        this->set_redraw(TPanel::RedrawNormal);
        return 1;
    }

    case COMM_UPDATE_PARAMS: {
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PARAMS (%d,%d)", wParam,
               lParam);
        rge_base_game->receive_game_options();
        for (int i = 0; i < rge_base_game->numberPlayers(); ++i) {
            int civilization =
                static_cast<TRIBE_Game*>(rge_base_game)->civilization(i);
            if (civilization >= 0x32) {
                L->Log("$$$ CIV2>50");
                civilization =
                    static_cast<TRIBE_Game*>(rge_base_game)->civilization(i);
                static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                    i, civilization - 0x32);
                if (i + 1 == comm->WhoAmI()) {
                    this->myCivilization = 0;
                    L->Log("$$$ RESETTING MYCIV2");
                }
            }

            int team = rge_base_game->playerTeam(i);
            if (team >= 0x32) {
                L->Log("$$$ TEAM2>50");
                team = rge_base_game->playerTeam(i);
                rge_base_game->setPlayerTeam(i, team - 0x32);
                if (i + 1 == comm->WhoAmI()) {
                    this->myPlayerTeam = 0;
                    L->Log("$$$ RESETTING MYTEAM2");
                }
            }
        }

        if (this->myScenarioPlayer != 0 &&
            strcmp(this->saveScenarioName, rge_base_game->scenarioName()) != 0) {
            this->myScenarioPlayer = -1;
        }
        this->updateSummary();

        if (!comm->IsHost()) {
            if (this->sent_cd_status != 0 &&
                this->myScenarioChecksum == this->saveScenarioChecksum &&
                comm->IsPlayerReady(comm->WhoAmI()) == this->i_am_ready) {
                return 1;
            }

            this->sent_cd_status = 1;
            this->saveScenarioChecksum = this->myScenarioChecksum;
            comm->SetMyReadiness(
                this->i_am_ready, 0, 0,
                rge_base_game->check_for_cd(0) + 1, 0, 0,
                this->myScenarioChecksum, 1);
        }
        return 1;
    }

    case COMM_LAUNCH_GAME:
        L->Log("$$$ USER_COMMAND: COMM_LAUNCH_GAME (%d,%d)", wParam,
               lParam);
        chat->setWindowHandle(AppWnd);
        comm->SetWindowHandle(AppWnd);
        static_cast<TRIBE_Game*>(rge_base_game)->start_game(0);
        return 1;

    case COMM_CANCEL_GAME:
        L->Log("$$$ USER_COMMAND: COMM_CANCEL_GAME (%d,%d)", wParam, lParam);
        this->handleKickedPlayer(0);
        return 1;

    case COMM_HOST_EXITED:
        L->Log("$$$ USER_COMMAND: COMM_HOST_EXITED (%d,%d)", wParam, lParam);
        this->handleKickedPlayer(0);
        return 1;

    case COMM_PLAYER_KICKED:
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_KICKED (%d,%d)", wParam,
               lParam);
        this->handleKickedPlayer(1);
        return 1;

    case COMM_NO_LINK:
        L->Log("$$$ USER_COMMAND: COMM_NO_LINK (%d,%d)", wParam, lParam);
        this->cancelScreen(0);
        return 1;

    case COMM_PLAYER_DROPPED:
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_DROPPED (%d,%d)", wParam,
               lParam);
        this->handleKickedPlayer(1);
        return 1;

    case COMM_OTHER_PLAYER_DROPPED:
        L->Log("$$$ USER_COMMAND: COMM_OTHER_PLAYER_DROPPED (%d,%d)",
               wParam, lParam);
        this->fillPlayers();
        return 1;

    case COMM_PLAYER_BAD_VERSION:
        L->Log("$$$ USER_COMMAND: COMM_BAD_VERSION (%d,%d)", wParam, lParam);
        sprintf(message, this->get_string(IDS_GAME_VERSION_MISMATCH),
                comm->GetPlayerName(lParam));
        this->popupOKDialog(message, 0, TEASY_POPUP_WIDTH, 100);
        return 1;

    case COMM_PLAYER_SERVICE_ERROR:
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_SERVICE_ERROR (%d,%d)", wParam,
               lParam);
        sprintf(message, this->get_string(IDS_CONNECTION_TYPE_MISMATCH),
                comm->GetPlayerName(lParam));
        this->popupOKDialog(message, 0, TEASY_POPUP_WIDTH, 100);
        return 1;

    case COMM_HOST_BUSY:
        L->Log("$$$ USER_COMMAND: COMM_HOST_BUSY (%d,%d)", wParam, lParam);
        if (comm->IsLobbyLaunched()) {
            this->cancelScreen(1);
        } else {
            this->handleKickedPlayer(0);
        }
        return 1;

    case CHAT_RECEIVED:
        L->Log("$$$ USER_COMMAND: CHAT_RECEIVED (%d,%d)", wParam, lParam);
        this->fillChat(lParam);
        return 1;

    default:
        L->Log("$$$ USER_COMMAND: UNKNOWN (%d, %d)", wParam, lParam);
        return 1;
    }
}


long TribeMPSetupScreen::handle_timer_command(unsigned int wParam, long lParam) {
    return 1;
}




void TribeMPSetupScreen::fillPlayers() {
    if (rge_base_game->multiplayerGame() && comm->IsHost()) {
        int color2 = 0;
        TTextPanel** text1 = 0;
        int i = 0;
        if (rge_base_game->numberPlayers() > 0) {
            text1 = this->playerNameText;
            do {
                int player = i + 1;
                if (comm->IsPlayerReady(player) && text1[0]->text_color1 == 0xFF) {
                    int j = 0;
                    int inner_players = rge_base_game->numberPlayers();
                    if (inner_players > 0) {
                        do {
                            if (i != j && comm->IsPlayerReady(j + 1)) {
                                int other_color = static_cast<TRIBE_Game*>(rge_base_game)->playerColor(j);
                                int player_color = static_cast<TRIBE_Game*>(rge_base_game)->playerColor(i);
                                if (other_color == player_color) {
                                    L->Log("$$$ SETTING CIV/TEAM+50 (%d,%d)", i, j);
                                    int civ = static_cast<TRIBE_Game*>(rge_base_game)->civilization(i);
                                    static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(j, civ + 0x32);
                                    int team = rge_base_game->playerTeam(i);
                                    rge_base_game->setPlayerTeam(j, team + 0x32);
                                    color2 = 1;
                                }
                            }
                            ++j;
                            inner_players = rge_base_game->numberPlayers();
                        } while (j < inner_players);
                    }
                }
                ++i;
                ++text1;
            } while (i < rge_base_game->numberPlayers());
        }
        if (color2 != 0) {
            rge_base_game->send_game_options();
        }
    }

    int i = 0;
    int players = rge_base_game->numberPlayers();
    if (players > 0) {
        do {
            int is_me;
            int humanity;
            if (rge_base_game->multiplayerGame()) {
                int player = i + 1;
                humanity = comm->GetPlayerHumanity(player);
                is_me = comm->WhoAmI() == player;
            } else if (i == 0) {
                humanity = 2;
                is_me = 1;
            } else {
                humanity = this->playerNameDrop[i]->get_id();
                is_me = 0;
            }

            if (!rge_base_game->multiplayerGame() || humanity != 2) {
                this->playerCDText[i]->set_active(0);
                this->playerVersionText[i]->set_active(0);
            } else {
                this->playerCDText[i]->set_active(rge_base_game->playerHasCD(i));
                if (comm->IsHost() || rge_base_game->playerVersion(0) != 0) {
                    this->playerVersionText[i]->set_text(rge_base_game->playerVersionString(i));
                    this->playerVersionText[i]->set_active(1);
                } else if (i == 0) {
                    this->playerVersionText[0]->set_text(rge_base_game->playerVersionString(0));
                    this->playerVersionText[0]->set_active(1);
                } else if (is_me) {
                    rge_base_game->setPlayerVersion(i, 1);
                    this->playerVersionText[i]->set_text(rge_base_game->playerVersionString(i));
                    this->playerVersionText[i]->set_active(1);
                } else {
                    this->playerVersionText[i]->set_active(0);
                }
            }

            int color;
            if (is_me == 1 && this->myPlayerColor != 0) {
                color = this->myPlayerColor;
            } else {
                color = static_cast<TRIBE_Game*>(rge_base_game)->playerColor(i);
            }
            this->playerColor[i]->set_state_by_id(color);
            int state = this->playerColor[i]->get_state();
            char* text1;
            char* text2;
            unsigned long color1;
            unsigned long color2;
            this->playerColor[i]->get_text(static_cast<short>(state),
                                           &text1, &text2);
            this->playerColor[i]->get_text_color(static_cast<short>(state),
                                                 &color1, &color2);
            this->playerColorText[i]->set_text(text1);
            this->playerColorText[i]->set_text_color(color1, color2);
            this->playerColor[i]->set_active(0);
            this->playerColorText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() && is_me && this->i_am_ready == 0) ||
                (rge_base_game->singlePlayerGame() && is_me && this->numberAnyPlayers > 1)) {
                this->playerColor[i]->set_active(1);
                this->playerColor[i]->set_disabled(0);
            } else if (humanity == 2) {
                this->playerColorText[i]->set_active(1);
            }

            if (is_me == 1 && this->myPlayerTeam != 0) {
                this->playerTeam[i]->set_state(
                    static_cast<short>(this->myPlayerTeam - 1));
            } else {
                int team = rge_base_game->playerTeam(i);
                if (team >= 0x32) {
                    team -= 0x32;
                }
                this->playerTeam[i]->set_state(team - 1);
            }

            state = this->playerTeam[i]->get_state();
            this->playerTeam[i]->get_text(static_cast<short>(state),
                                          &text1, &text2);
            this->playerTeamText[i]->set_text(text1);
            this->playerTeam[i]->set_active(0);
            this->playerTeamText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() &&
                 ((is_me && this->i_am_ready == 0) ||
                  (comm->IsHost() && humanity == 4 && this->i_am_ready == 0))) ||
                (rge_base_game->singlePlayerGame() && (is_me || humanity == 4))) {
                this->playerTeam[i]->set_active(1);
                this->playerTeam[i]->set_disabled(0);
            } else if (humanity == 2 || humanity == 4) {
                this->playerTeamText[i]->set_active(1);
            }

            if (rge_base_game->multiplayerGame()) {
                int name_color;
                if (humanity == 2 && !comm->IsPlayerReady(i + 1)) {
                    name_color = 0xFF;
                } else {
                    name_color = 0xFF00;
                }
                this->playerNameDrop[i]->set_val_text_color(name_color, 0);
                this->playerNameText[i]->set_text_color(name_color, 0);
            }

            if (rge_base_game->multiplayerGame()) {
                if (this->playerNameDrop[i]->get_id(0) == 2) {
                    this->playerNameDrop[i]->delete_line(0);
                }
                if (humanity == 2) {
                    this->playerNameDrop[i]->insert_line(0, comm->GetPlayerName(i + 1), humanity);
                }
                this->playerNameDrop[i]->set_line(this->playerNameDrop[i]->get_line(humanity));
                this->playerNameText[i]->set_text(this->playerNameDrop[i]->get_text());
            } else {
                if (is_me == 1) {
                    this->playerNameText[i]->set_text(IDS_PLAYER_NAME_YOU_SETUP);
                } else {
                    this->playerNameText[i]->set_text(this->playerNameDrop[i]->get_text());
                }
            }

            if (this->playerCivDrop[i]->mode != 2) {
                if (is_me == 1 && this->myCivilization != 0) {
                    this->playerCivDrop[i]->set_line(
                        this->playerCivDrop[i]->get_line(this->myCivilization));
                } else {
                    int civ = static_cast<TRIBE_Game*>(rge_base_game)->civilization(i);
                    if (civ >= 0x32) {
                        civ -= 0x32;
                    }
                    this->playerCivDrop[i]->set_line(
                        this->playerCivDrop[i]->get_line(civ));
                }
            }
            this->playerCivText[i]->set_text(this->playerCivDrop[i]->get_text());

            if (this->scenarioPlayerDrop[i]->mode != 2) {
                if (is_me == 1 && this->myScenarioPlayer != -1) {
                    this->scenarioPlayerDrop[i]->set_line(
                        this->scenarioPlayerDrop[i]->get_line(this->myScenarioPlayer));
                } else {
                    int scenario_player = static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(i);
                    this->scenarioPlayerDrop[i]->set_line(
                        this->scenarioPlayerDrop[i]->get_line(scenario_player));
                }
            }
            this->scenarioPlayerText[i]->set_text(this->scenarioPlayerDrop[i]->get_text());

            if (rge_base_game->multiplayerGame() && comm->IsHost() && !is_me) {
                this->playerNameDrop[i]->set_active(1);
                this->playerNameText[i]->set_active(0);
            } else {
                this->playerNameDrop[i]->set_active(0);
                this->playerNameText[i]->set_active(1);
            }
            this->playerCivDrop[i]->set_active(0);
            this->playerCivText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() &&
                 ((is_me && this->i_am_ready == 0) ||
                  (comm->IsHost() && humanity == 4 && this->i_am_ready == 0))) ||
                (rge_base_game->singlePlayerGame() && (is_me || humanity == 4))) {
                this->playerCivDrop[i]->set_active(1);
            } else if (humanity == 2 || humanity == 4) {
                this->playerCivText[i]->set_active(1);
            }
            this->scenarioPlayerDrop[i]->set_active(0);
            this->scenarioPlayerText[i]->set_active(0);

            ++i;
            players = rge_base_game->numberPlayers();
        } while (i < players);
    }

    if (i < 8) {
        for (; i < 8; ++i) {
            this->playerNameDrop[i]->set_active(0);
            this->playerCivDrop[i]->set_active(0);
            this->scenarioPlayerDrop[i]->set_active(0);
            this->playerColor[i]->set_active(0);
            this->playerColorText[i]->set_active(0);
            this->playerTeam[i]->set_active(0);
            this->playerTeamText[i]->set_active(0);
            this->playerNameText[i]->set_active(0);
            this->playerCivText[i]->set_active(0);
            this->scenarioPlayerText[i]->set_active(0);
            this->playerCDText[i]->set_active(0);
            this->playerVersionText[i]->set_active(0);
        }
    }

    this->fillPlayerColors();
}




void TribeMPSetupScreen::fillChat(int line_no) {
    if (!rge_base_game->singlePlayerGame()) {
        int lines = this->chatBox->numberLines();
        int need_scroll = (lines > 0 && this->chatBox->bot_line == lines - 1);
        if (lines >= 100) {
            this->chatBox->delete_line(0);
        }
        this->chatBox->word_wrap_append(chat->GetChatMsg(line_no));
        if (need_scroll) {
            this->chatBox->scroll(7, 0, 1);
        }
    }
}




void TribeMPSetupScreen::updateSummary() {
    int changed = 0;
    char str1[256];
    char str2[256];
    union {
        char file_name[0x118];
        struct _finddata_t file_info;
    } file_scratch;
    char str3[256];
    struct _finddata_t file_info;
    char* scenario_dir;
    char* scenario_name;

    if (rge_base_game->scenarioGame()) {
        if (this->saveRandomGame == 0) {
            if (strcmp(rge_base_game->scenarioName(), this->saveScenarioName) != 0) {
                changed = 1;
            }
        } else {
            changed = 1;
        }
    } else if (this->saveRandomGame == 0) {
        changed = 1;
    }

    if (changed != 0) {
        if (rge_base_game->scenarioGame()) {
            int player_index = 0;
            if (this->scenarioInfo != 0) {
                delete this->scenarioInfo;
                this->scenarioInfo = 0;
            }

            scenario_dir = rge_base_game->prog_info->scenario_dir;
            scenario_name = rge_base_game->scenarioName();
            sprintf(str1, "%s%s.scn", scenario_dir, scenario_name);
            long handle = _findfirst(str1, &file_scratch.file_info);
            if (handle == -1) {
                sprintf(str1, "%s.scx",
                        rge_base_game->scenarioName());
            } else {
                sprintf(str1, "%s.scn",
                        rge_base_game->scenarioName());
            }

            if (str1[0] != '.') {
                this->scenarioInfo = static_cast<T_Scenario*>(
                    rge_base_game->get_scenario_info(str1, 0));
            }

            if (this->scenarioInfo == 0) {
                rge_base_game->setScenarioGame(0);
            } else {
                for (int empty_index = 0; empty_index < 8; ++empty_index) {
                    this->scenarioPlayerDrop[empty_index]->empty_list();
                }

                this->settingsFixed = this->scenarioInfo->any_sp_victory();
                player_index = 0;
                this->numberAnyPlayers = 0;
                this->scenarioPlayerCount = 0;

                for (; player_index < 9; ++player_index) {
                    if (this->scenarioInfo->Get_player_Active(player_index) != 0) {
                        ++this->scenarioPlayerCount;
                        sprintf(str2, "%d", player_index + 1);
                        if (rge_base_game->multiplayerGame() ||
                            (rge_base_game->singlePlayerGame() &&
                             this->scenarioInfo->Get_player_Type(player_index) == 1)) {
                            ++this->numberAnyPlayers;
                            for (int append_index = 0; append_index < 8; ++append_index) {
                                this->scenarioPlayerDrop[append_index]->append_line(
                                    str2, player_index);
                            }
                        }
                    }
                }

                int player = -1;
                for (int color_index = 0; color_index < 8; ++color_index) {
                    do {
                        ++player;
                        if (player == 9) {
                            player = 0;
                        }
                    } while (this->scenarioInfo->Get_player_Active(player) == 0);

                    this->defaultColor[color_index] =
                        static_cast<unsigned char>(player + 1);
                    static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(color_index, player);
                    static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                        color_index, this->defaultColor[color_index]);
                    rge_base_game->setPlayerTeam(color_index, 1);
                }
            }
        }

        if (rge_base_game->randomGame()) {
            for (int random_empty_index = 0; random_empty_index < 8; ++random_empty_index) {
                this->scenarioPlayerDrop[random_empty_index]->empty_list();
            }
            this->settingsFixed = 0;
            this->scenarioPlayerCount = 8;
            this->numberAnyPlayers = 8;

            for (int random_index = 0; random_index < 8; ++random_index) {
                this->defaultColor[random_index] =
                    static_cast<unsigned char>(random_index + 1);
                static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(random_index, random_index);
                static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                    random_index, this->defaultColor[random_index]);
                rge_base_game->setPlayerTeam(random_index, 1);
                sprintf(str2, "%d", random_index + 1);
                for (int random_append_index = 0; random_append_index < 8;
                     ++random_append_index) {
                    this->scenarioPlayerDrop[random_append_index]->append_line(
                        str2, random_index);
                }
            }
        }

        if (rge_base_game->singlePlayerGame()) {
            this->setupSinglePlayerPlayers();
        }

        this->saveRandomGame = rge_base_game->randomGame();
        if (this->saveRandomGame != 0) {
            this->saveScenarioName[0] = 0;
        } else {
            strcpy(this->saveScenarioName, rge_base_game->scenarioName());
        }

        for (int checksum_index = 0; checksum_index < 8; ++checksum_index) {
            this->scenarioCheckSum[checksum_index] = 0;
        }

        if (rge_base_game->scenarioGame()) {
            scenario_dir = rge_base_game->prog_info->scenario_dir;
            scenario_name = rge_base_game->scenarioName();
            sprintf(file_scratch.file_name, "%s%s.scn", scenario_dir, scenario_name);
            long handle = _findfirst(file_scratch.file_name, &file_info);
            if (handle == -1) {
                sprintf(file_scratch.file_name, "%s.scx",
                        rge_base_game->scenarioName());
            } else {
                sprintf(file_scratch.file_name, "%s.scn",
                        rge_base_game->scenarioName());
            }
            this->myScenarioChecksum = rge_base_game->get_scenario_checksum(
                file_scratch.file_name);
        } else {
            this->myScenarioChecksum = 0;
        }
    }

    int setting;
    for (int i = 0; i < 20; ++i) {
        this->settingText[i]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, this->get_string(IDS_SCENARIO_FORMAT),
                rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        setting = 3;
    } else {
        if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch()) {
            this->get_string(IDS_DEATH_MATCH, str1, 256);
        } else {
            this->get_string(IDS_RANDOM_MAP, str1, 256);
        }
        sprintf(str2, this->get_string(IDS_SCENARIO_FORMAT), str1);
        this->scenarioName->set_text(str2);
        setting = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapSize()) {
        case 0: strcpy(str1, this->get_string(IDS_MAP_SIZE_BASE)); break;
        case 1: strcpy(str1, this->get_string(IDS_MAP_SIZE_BASE + 1)); break;
        case 2: strcpy(str1, this->get_string(IDS_MAP_SIZE_BASE + 2)); break;
        case 3: strcpy(str1, this->get_string(IDS_MAP_SIZE_BASE + 3)); break;
        case 4: strcpy(str1, this->get_string(IDS_MAP_SIZE_BASE + 4)); break;
        case 5: strcpy(str1, this->get_string(IDS_MAP_SIZE_BASE + 5)); break;
        }
        sprintf(str2, this->get_string(IDS_MAP_SIZE_FORMAT), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;

        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
        case 0: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE)); break;
        case 1: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 1)); break;
        case 2: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 2)); break;
        case 3: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 3)); break;
        case 4: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 4)); break;
        case 5: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 5)); break;
        case 6: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 6)); break;
        case 7: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 7)); break;
        case 8: strcpy(str1, this->get_string(IDS_MAP_TYPE_BASE + 8)); break;
        }
        sprintf(str2, this->get_string(IDS_MAP_TYPE_FORMAT), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->scenarioGame()) {
        if (this->settingsFixed == 0 && this->scenarioPlayerCount != 2) {
        sprintf(str2, "%s %d - %d", this->get_string(IDS_PLAYERS_LABEL),
                    2, this->scenarioPlayerCount);
        } else {
            sprintf(str2, "%s %d", this->get_string(IDS_PLAYERS_LABEL),
                    this->scenarioPlayerCount);
        }
    } else {
        sprintf(str2, "%s 2 - 8", this->get_string(IDS_PLAYERS_LABEL));
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
    case 1:
        strcpy(str1, this->get_string(IDS_VICTORY_CONQUEST));
        goto victory_plain;
    case 7:
        strcpy(str1, this->get_string(IDS_VICTORY_TIME_LIMIT));
        goto victory_amount;
    case 8:
        strcpy(str1, this->get_string(IDS_VICTORY_SCORE));
    victory_amount:
        sprintf(str2, this->get_string(IDS_VICTORY_AMOUNT_FORMAT), str1,
                static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount());
        goto victory_done;
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, this->get_string(IDS_VICTORY_STANDARD));
        } else {
            strcpy(str1, this->get_string(IDS_OPTION_DEFAULT));
        }
        goto victory_plain;
    case 9:
        strcpy(str1, this->get_string(IDS_VICTORY_STANDARD));
    victory_plain:
        sprintf(str2, this->get_string(IDS_VICTORY_FORMAT), str1);
    victory_done:
        break;
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int age = static_cast<TRIBE_Game*>(rge_base_game)->startingAge();
    if (age == 0) {
        this->get_string(IDS_OPTION_DEFAULT, str1, 256);
    } else if (age == 1) {
        this->get_string(IDS_AGE_NOMAD, str1, 256);
    } else {
        this->get_string(age + IDS_AGE_NAME_BASE, str1, 256);
    }
    sprintf(str2, this->get_string(IDS_STARTING_AGE_FORMAT), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int resources = static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel();
    if (resources == 0) {
        this->get_string(IDS_OPTION_DEFAULT, str1, 256);
    } else {
        this->get_string(resources + IDS_RESOURCE_LEVEL_BASE, str1, 256);
    }
    sprintf(str2, this->get_string(IDS_RESOURCE_LEVEL_FORMAT), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    rge_base_game->difficulty();
    this->get_string(rge_base_game->difficulty() + IDS_DIFFICULTY_BASE, str1, 256);
    this->get_string(IDS_DIFFICULTY_FORMAT, str2, 256);
    sprintf(str3, str2, str1);
    this->settingText[setting]->set_text(str3);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions()) {
        this->get_string(IDS_BUTTON_NO, str1, 256);
    } else {
        this->get_string(IDS_BUTTON_YES, str1, 256);
    }
    sprintf(str2, this->get_string(IDS_FIXED_POSITIONS_FORMAT), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, this->get_string(IDS_BUTTON_YES));
    } else {
        strcpy(str1, this->get_string(IDS_BUTTON_NO));
    }
        sprintf(str2, this->get_string(IDS_REVEAL_MAP_FORMAT), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree()) {
        this->get_string(IDS_BUTTON_YES, str1, 256);
    } else {
        this->get_string(IDS_BUTTON_NO, str1, 256);
    }
    sprintf(str2, this->get_string(IDS_FULL_TECH_TREE_FORMAT), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, this->get_string(IDS_BUTTON_YES));
        } else {
            strcpy(str1, this->get_string(IDS_BUTTON_NO));
        }
        sprintf(str2, this->get_string(IDS_CHEATING_ENABLED_FORMAT), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->multiplayerGame()) {
        this->get_string(static_cast<TRIBE_Game*>(rge_base_game)->mpPathFinding() + IDS_PATH_FINDING_OPTION_BASE,
                         str1, 256);
    } else {
        this->get_string(rge_base_game->pathFinding() + IDS_PATH_FINDING_OPTION_BASE,
                         str1, 256);
    }
    sprintf(str2, this->get_string(IDS_PATH_FINDING_FORMAT), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    sprintf(str2, this->get_string(IDS_POPULATION_LIMIT_FORMAT),
            static_cast<TRIBE_Game*>(rge_base_game)->popLimit());
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);

    if (rge_base_game->singlePlayerGame()) {
        if (rge_base_game->scenarioGame() == 0 ||
            (this->settingsFixed == 0 && this->scenarioPlayerCount >= 3)) {
            this->numberPlayersTitle->set_active(1);
            this->numberPlayersDrop->set_active(1);
        } else {
            this->numberPlayersTitle->set_active(0);
            this->numberPlayersDrop->set_active(0);
        }
    }

    this->fillPlayers();
}



void TribeMPSetupScreen::kickPlayer(int p) {
    char text[256];

    this->playerToKick = p;
    sprintf(text, this->get_string(IDS_KICK_PLAYER_PROMPT), comm->GetPlayerName(p));
    this->popupYesNoDialog(text, "Kick Dialog", TEASY_POPUP_WIDTH,
                           TEASY_POPUP_HEIGHT);
}




void TribeMPSetupScreen::handleKickedPlayer(int really_kicked) {
    this->cancelScreen(0);
    TEasy_Panel* panel = static_cast<TEasy_Panel*>(
        panel_system.currentPanel());
    if (panel != 0) {
        panel->popupOKDialog(IDS_GAME_CANCELED_NOTICE + (really_kicked != 0 ? -1 : 0),
                             0, TEASY_POPUP_WIDTH, 100);
    }
}




void TribeMPSetupScreen::activateVictoryPanels() {
    int id = victoryTypeDrop->get_id();
    if (id == 1 || victoryTypeDrop->get_id() == 0) {
        victoryAmountLabel->set_active(0);
        victoryAmountInput->set_active(0);
    } else {
        victoryAmountLabel->set_active(1);
        victoryAmountInput->set_active(1);
        switch (victoryTypeDrop->get_id()) {
        case 2:
            victoryAmountLabel->set_text(IDS_VICTORY_PERCENT_LABEL);
            return;
        case 3:
        case 4:
        case 5:
            victoryAmountLabel->set_text(IDS_VICTORY_COUNT_LABEL);
            return;
        case 6:
            victoryAmountLabel->set_text(IDS_VICTORY_QUANTITY_LABEL);
            return;
        }
    }
}




void TribeMPSetupScreen::setupTabOrder() {
    TPanel* tabList[4];

    if (rge_base_game->singlePlayerGame()) {
        tabList[0] = startButton;
        tabList[1] = cancelButton;
        tabList[2] = gameSettingsButton;
        set_tab_order(tabList, 3);
        set_curr_child(startButton);
        return;
    }

    tabList[0] = chatInput;
    if (gameSettingsButton) {
        tabList[1] = startButton;
        tabList[2] = cancelButton;
        tabList[3] = gameSettingsButton;
        set_tab_order(tabList, 4);
        set_curr_child(chatInput);
        return;
    }

    tabList[1] = ready_button;
    tabList[2] = cancelButton;
    set_tab_order(tabList, 3);
    set_curr_child(chatInput);
}




void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    int first_any_civ;
    int first_any_color;
    int first_any_color_index;
    if (rge_base_game->scenarioGame() != 0) {
        first_any_civ = -1;
        first_any_color = -1;
        first_any_color_index = -1;

        if (this->scenarioInfo != 0) {
            int player_count = 0;
            int scenario_player = 0;
            do {
                if (this->scenarioInfo->Get_player_Active(scenario_player) != 0) {
                    static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(
                        player_count, scenario_player);
                    int civilization =
                        this->scenarioInfo->Get_player_Civ(scenario_player);
                    static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                        player_count, civilization);
                    static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                        player_count, scenario_player + 1);

                    if (this->scenarioInfo->Get_player_Type(scenario_player) == 1 &&
                        first_any_civ == -1) {
                        first_any_civ = scenario_player;
                        first_any_color =
                            this->scenarioInfo->Get_player_Civ(scenario_player);
                        first_any_color_index = scenario_player + 1;
                    }
                    ++player_count;
                }
                ++scenario_player;
            } while (scenario_player < 9);
        }

        rge_base_game->setNumberPlayers(this->scenarioPlayerCount);
        if (first_any_civ != -1) {
            int player = 1;
            if (this->scenarioPlayerCount > 1) {
                while (player < this->scenarioPlayerCount) {
                    if (static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(player) ==
                        first_any_civ) {
                        int scenario_player =
                            static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(0);
                        static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(
                            player, scenario_player);
                        int civilization =
                            static_cast<TRIBE_Game*>(rge_base_game)->civilization(0);
                        static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                            player, civilization);
                        int color =
                            static_cast<TRIBE_Game*>(rge_base_game)->playerColor(0);
                        static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                            player, color);
                        break;
                    }
                    ++player;
                }
            }

            static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(0, first_any_civ);
            static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(0, first_any_color);
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                0, first_any_color_index);
        }
    } else {
        int player = 0;
        do {
            int civilization =
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 2865) %
                    16 + 1;
            static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(player, civilization);
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(
                player, player + 1);
            player = player + 1;
        } while (player < 8);
    }

    int player = 0;
    do {
        rge_base_game->setPlayerTeam(player, 1);
        ++player;
    } while (player < 8);

    comm->SetPlayerHumanity(1, ME_HUMAN);
    player = 2;
    do {
        comm->SetPlayerHumanity(player, ME_COMPUTER);
        ++player;
    } while (player <= 8);
    comm->SetPlayerHumanity(9, ME_ABSENT);
    this->fillNumberPlayers();
}





void TribeMPSetupScreen::fillNumberPlayers() {
    this->numberPlayersDrop->empty_list();

    int max_players = this->scenarioPlayerCount;
    if (max_players >= 2) {
        char str[16];
        int i = 2;
        do {
            sprintf(str, "%d", i);
            this->numberPlayersDrop->append_line(str, i);
            i++;
        } while (i <= this->scenarioPlayerCount);
    }

    int num = rge_base_game->numberPlayers();
    int line = this->numberPlayersDrop->get_line(num);
    this->numberPlayersDrop->set_line(line);
}





void TribeMPSetupScreen::fillPlayerColors() {
    TButtonPanel** buttons = this->playerColor;
    int remaining = 8;
    char str[16];

    do {
        int player = 0;
        int state = 0;

        do {
            if (rge_base_game->scenarioGame() == 0 ||
                this->scenarioInfo == 0 ||
                (this->scenarioInfo->Get_player_Active(player) != 0 &&
                 (rge_base_game->singlePlayerGame() == 0 ||
                  this->scenarioInfo->Get_player_Type(player) == 1))) {
                sprintf(str, "%d", player + 1);
                buttons[0]->set_text(static_cast<short>(state), str);
                buttons[0]->set_id(static_cast<short>(state), player + 1, 0);

                switch (player) {
                case 0:
                    buttons[0]->set_text_color(state, 0xFF0000, 0);
                    break;
                case 1:
                    buttons[0]->set_text_color(state, 0x0000FF, 0);
                    break;
                case 2:
                    buttons[0]->set_text_color(state, 0x00FFFF, 0);
                    break;
                case 3:
                    buttons[0]->set_text_color(state, 0x284673, 0);
                    break;
                case 4:
                    buttons[0]->set_text_color(state, 0x0764F0, 0);
                    break;
                case 5:
                    buttons[0]->set_text_color(state, 0x00FF00, 0);
                    break;
                case 6:
                    buttons[0]->set_text_color(state, 0xB4B4B4, 0);
                    break;
                case 7:
                    buttons[0]->set_text_color(state, 0x93BF2B, 0);
                    break;
                }
                state++;
            }
            player++;
        } while (player < 8);

        buttons[0]->set_state_info(static_cast<short>(state));
        buttons++;
    } while (--remaining != 0);
}




TRIBE_Screen_Wait::TRIBE_Screen_Wait() : TScreenPanel("Multiplayer Wait Screen") {
    char str1[0x100];
    char str2[0x100];
    char str3[0x100];
    int i;

    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;
    this->scenarioName = 0;
    for (i = 0; i < 20; i++) {
        this->settingText[i] = 0;
    }

    if (this->setup(rge_base_game->draw_area, "scr3", 0xC385, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(640, 480);

    this->create_text(this, &this->message, "",
                     20, 40, 380, 400, 4, 1, 1, 1);
    if (this->create_button(this, &this->close_button, 0x3EA,
                            0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4,
                                        4, 17, 17, 17,
                                        17, 0, 0, 0, 0);

    if (this->create_text(this, &this->scenarioName, "",
                          420, 84, 220, 68, 0xB, 0, 0, 1) == 0) {
        return;
    }

    int y = 0x53;
    int k = 0;
    for (; y < 0x233; y += 0x18, k++) {
        if (this->create_text(this, &this->settingText[k], "",
                              420, y, 220, 20, 0xB, 0, 0, 0) == 0) {
            return;
        }
    }

    for (k = 0; k < 20; k++) {
        this->settingText[k]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, get_string(IDS_SCENARIO_FORMAT), rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        i = 3;
    } else {
        if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch()) {
            get_string(IDS_DEATH_MATCH, str1, 256);
        } else {
            get_string(IDS_RANDOM_MAP, str1, 256);
        }
        sprintf(str2, get_string(IDS_SCENARIO_FORMAT), str1);
        this->scenarioName->set_text(str2);
        i = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapSize()) {
        case 0: strcpy(str1, get_string(IDS_MAP_SIZE_BASE)); break;       // Tiny
        case 1: strcpy(str1, get_string(IDS_MAP_SIZE_BASE + 1)); break;   // Small
        case 2: strcpy(str1, get_string(IDS_MAP_SIZE_BASE + 2)); break;   // Medium
        case 3: strcpy(str1, get_string(IDS_MAP_SIZE_BASE + 3)); break;   // Large
        case 4: strcpy(str1, get_string(IDS_MAP_SIZE_BASE + 4)); break;   // Huge
        case 5: strcpy(str1, get_string(IDS_MAP_SIZE_BASE + 5)); break;   // Gigantic
        }
        sprintf(str2, get_string(IDS_MAP_SIZE_FORMAT), str1);              // "Map Size: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;

        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
        case 0: strcpy(str1, get_string(IDS_MAP_TYPE_BASE)); break;       // All Water
        case 1: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 1)); break;   // Mostly Water
        case 2: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 2)); break;   // Water & Land
        case 3: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 3)); break;   // Mostly Land
        case 4: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 4)); break;   // All Land
        case 5: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 5)); break;   // Continental
        case 6: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 6)); break;   // Lake
        case 7: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 7)); break;   // Hilly
        case 8: strcpy(str1, get_string(IDS_MAP_TYPE_BASE + 8)); break;   // Narrows
        }
        sprintf(str2, get_string(IDS_MAP_TYPE_FORMAT), str1);              // "Map Type: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }
    i++;

    switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
    case 1:                            // Conquest
        strcpy(str1, get_string(IDS_VICTORY_CONQUEST));
        goto victory_plain_wait;
    case 7:                            // Time
        strcpy(str1, get_string(IDS_VICTORY_TIME_LIMIT));
        goto victory_amount_wait;
    case 8:                            // Score
        strcpy(str1, get_string(IDS_VICTORY_SCORE));
    victory_amount_wait:
        sprintf(str2, get_string(IDS_VICTORY_AMOUNT_FORMAT), str1,
                static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount()); // "Victory: %s (%d)"
        goto victory_done_wait;
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, get_string(IDS_VICTORY_STANDARD));
        } else {
            strcpy(str1, get_string(IDS_OPTION_DEFAULT));
        }
        goto victory_plain_wait;
    case 9:                            // Standard
        strcpy(str1, get_string(IDS_VICTORY_STANDARD));
    victory_plain_wait:
        sprintf(str2, get_string(IDS_VICTORY_FORMAT), str1); // "Victory: %s"
    victory_done_wait:
        break;
    }
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int age = static_cast<TRIBE_Game*>(rge_base_game)->startingAge();
    if (age == 0) {
        get_string(IDS_OPTION_DEFAULT, str1, 256);        // Default
    } else if (age == 1) {
        get_string(IDS_AGE_NOMAD, str1, 256);              // Nomad
    } else {
        get_string(age + IDS_AGE_NAME_BASE, str1, 256);
    }
    sprintf(str2, get_string(IDS_STARTING_AGE_FORMAT), str1); // "Age: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int level = static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel();
    if (level == 0) {
        get_string(IDS_OPTION_DEFAULT, str1, 256);        // Default
    } else {
        get_string(level + IDS_RESOURCE_LEVEL_BASE, str1, 256);
    }
    sprintf(str2, get_string(IDS_RESOURCE_LEVEL_FORMAT), str1); // "Resources: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    rge_base_game->difficulty();
    get_string(rge_base_game->difficulty() + IDS_DIFFICULTY_BASE, str1, 256);
    get_string(IDS_DIFFICULTY_FORMAT, str2, 256);          // "Difficulty Level: %s"
    sprintf(str3, str2, str1);
    this->settingText[i]->set_text(str3);
    this->settingText[i]->set_active(1);
    i++;

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions()) {
        get_string(IDS_BUTTON_NO, str1, 256);
    } else {
        get_string(IDS_BUTTON_YES, str1, 256);
    }
    sprintf(str2, get_string(IDS_FIXED_POSITIONS_FORMAT), str1); // "Fixed Positions: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, get_string(IDS_BUTTON_YES));
    } else {
        strcpy(str1, get_string(IDS_BUTTON_NO));
    }
    sprintf(str2, get_string(IDS_REVEAL_MAP_FORMAT), str1); // "Reveal Map: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree()) {
        get_string(IDS_BUTTON_YES, str1, 256);
    } else {
        get_string(IDS_BUTTON_NO, str1, 256);
    }
    sprintf(str2, get_string(IDS_FULL_TECH_TREE_FORMAT), str1); // "Full Tech Tree: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, get_string(IDS_BUTTON_YES));
        } else {
            strcpy(str1, get_string(IDS_BUTTON_NO));
        }
        sprintf(str2, get_string(IDS_CHEATING_ENABLED_FORMAT), str1); // "Enable Cheating: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }

    if (rge_base_game->multiplayerGame()) {
        get_string(rge_base_game->mpPathFinding() + IDS_PATH_FINDING_OPTION_BASE, str1, 256);
    } else {
        get_string(rge_base_game->pathFinding() + IDS_PATH_FINDING_OPTION_BASE, str1, 256);
    }
    sprintf(str2, get_string(IDS_PATH_FINDING_FORMAT), str1);                // "Path Finding: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    sprintf(str2, get_string(IDS_POPULATION_LIMIT_FORMAT),
            static_cast<TRIBE_Game*>(rge_base_game)->popLimit());
    this->settingText[i]->set_text(str2);                   // "Population Limit: %d"
    this->settingText[i]->set_active(1);
}


TRIBE_Screen_Wait::~TRIBE_Screen_Wait() {
    this->delete_panel((TPanel**)&this->message);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->scenarioName);
    for (int i = 0; i < 20; ++i) {
        this->delete_panel((TPanel**)&this->settingText[i]);
    }
}


void TRIBE_Screen_Wait::set_text(char* message_in) {
    this->message->set_text(message_in);
}


void TRIBE_Screen_Wait::set_text(long message_in) {
    this->message->set_text(message_in);
}


long TRIBE_Screen_Wait::action(TPanel* from_panel, long action_in, unsigned long val1, unsigned long val2) {
    if ((from_panel != 0) && (from_panel == this->close_button) &&
        (action_in == 1)) {
        rge_base_game->close();
        return 1;
    }
    return this->TScreenPanel::action(from_panel, action_in, val1, val2);
}


long TRIBE_Screen_Wait::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}





TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int mode_in) : TScreenPanel("Multiplayer Disconnect Screen") {
    this->mode = mode_in;
    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;

    if (this->setup(rge_base_game->draw_area, "scr3", 0xC385, 0) == 0) {
        this->error_code = 1;
    } else {
        this->set_ideal_size(640, 480);
        this->create_text(this, &this->message, IDS_STATUS_DISCONNECTING_MULTIPLAYER,
                          40, 40, 560, 400, 4, 1, 1, 1);
    }
}


TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect() {
    this->delete_panel((TPanel**)&this->message);
}


void TRIBE_Screen_Disconnect::set_text(char* message_in) {
    this->message->set_text(message_in);
}


void TRIBE_Screen_Disconnect::set_text(long message_in) {
    this->message->set_text(message_in);
}




long TRIBE_Screen_Disconnect::action(TPanel* from_panel, long action_in, unsigned long val1, unsigned long val2) {
    if (from_panel != 0) {
        if (from_panel == this->cancel_button && action_in == 1) {
            static_cast<TRIBE_Game*>(rge_base_game)->quit_game();
            panel_system.destroyPanel("Multiplayer Disconnect Screen");
            panel_system.destroyPanel("Status Screen");
            return 1;
        }
        if (from_panel == this->close_button && action_in == 1) {
            rge_base_game->close();
            return 1;
        }
    }
    return TEasy_Panel::action(from_panel, action_in, val1, val2);
}


long TRIBE_Screen_Disconnect::handle_idle() { return TPanel::handle_idle(); }
