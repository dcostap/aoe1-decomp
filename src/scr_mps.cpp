
#include "../include/scr_mps.h"
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




TribeMPSetupScreen::TribeMPSetupScreen()
    : TScreenPanel("MP Setup Screen")
{
    int row;
    char str[256];
    int y;
    int button_id;

    L->Log("$$$ CHAT SCREEN: CONSTRUCTOR BEGIN");
    init_vars();
    chat->ClearChat();
    for (int i = 1; i < 9; i++) {
        chat->setInChatGroup(i, 1);
    }

    char* setup_file;
    if (rge_base_game->multiplayerGame()) {
        setup_file = "scr3";
    } else {
        setup_file = "scr2";
    }

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (this->TEasy_Panel::setup(
            draw_area, 0, setup_file,
            (rge_base_game->multiplayerGame() != 0) + 0xC384,
            1, 0, 0, 0, 0, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title,
                          0x25CF + (rge_base_game->multiplayerGame() ? -1 : 0),
                          0x14, 6, 600, 0x1E, 1, 1, 0, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->playerTitle, 0x25D0,
                          0x1A, 0x32, 0xA0, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->civTitle, 0x25D1,
                          0xBD, 0x32, 0xA0, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }

    if (!rge_base_game->singlePlayerGame() && !comm->IsHost()) {
        if (this->create_text(this, &this->settingsTitle, 0x25D2,
                              0x1A4, 0x32, 0xD2, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
    }

    if (this->create_text(this, &this->colorTitle, 0x25AE,
                          0xF0, 0x32, 100, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    this->colorTitle->set_alignment(TTextPanel::AlignCenter,
                                    TTextPanel::AlignRight);
    if (this->create_text(this, &this->teamTitle, 0x25AF,
                          0x136, 0x32, 100, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    this->teamTitle->set_alignment(TTextPanel::AlignCenter,
                                   TTextPanel::AlignRight);

    y = 0x55;
    row = 0;
    for (; y < 0x115; ++row, y += 0x18) {
        if (this->create_drop_down(this, &this->playerNameDrop[row],
                                   0x9E, 100, 7, y - 1,
                                   0x9E, 0x18, 0x0B) == 0) {
            return;
        }
        this->playerNameDrop[row]->set_draw_style(
            TDropDownPanel::DrawStyleLeftButton);
        this->playerNameDrop[row]->set_draw_val_rect(0);
        this->playerNameDrop[row]->set_help_info(0x75F9, -1);
        this->playerNameDrop[row]->empty_list();
        if (rge_base_game->multiplayerGame()) {
            this->playerNameDrop[row]->append_line(0x25D3, 4);
            this->playerNameDrop[row]->append_line(0x25D4, 1);
            this->playerNameDrop[row]->append_line(0x25D5, 0);
        } else {
            this->playerNameDrop[row]->append_line(0x25D3, 4);
            this->playerNameDrop[row]->append_line(0x25D6, 0);
        }

        if (this->create_drop_down(this, &this->playerCivDrop[row],
                                   0x80, 100, 0xAA, y - 1,
                                   0x80, 0x18, 0x0B) == 0) {
            return;
        }
        this->playerCivDrop[row]->set_draw_style(
            TDropDownPanel::DrawStyleLeftButton);
        this->playerCivDrop[row]->set_draw_val_rect(0);
        this->playerCivDrop[row]->set_help_info(0x75FA, 0x25F09);
        this->playerCivDrop[row]->empty_list();
        this->playerCivDrop[row]->append_line(0x27F7, 1);
        this->playerCivDrop[row]->append_line(0x27F8, 2);
        this->playerCivDrop[row]->append_line(0x27F9, 3);
        this->playerCivDrop[row]->append_line(0x27FA, 4);
        this->playerCivDrop[row]->append_line(0x27FB, 5);
        this->playerCivDrop[row]->append_line(0x27FC, 6);
        this->playerCivDrop[row]->append_line(0x27FD, 7);
        this->playerCivDrop[row]->append_line(0x27FE, 8);
        this->playerCivDrop[row]->append_line(0x27FF, 9);
        this->playerCivDrop[row]->append_line(0x2800, 10);
        this->playerCivDrop[row]->append_line(0x2801, 0x0B);
        this->playerCivDrop[row]->append_line(0x2802, 0x0C);
        this->playerCivDrop[row]->append_line(0x2806, 0x0D);
        this->playerCivDrop[row]->append_line(0x2807, 0x0E);
        this->playerCivDrop[row]->append_line(0x2809, 0x0F);
        this->playerCivDrop[row]->append_line(0x2808, 0x10);
        this->playerCivDrop[row]->append_line(0x280A, 0x11);

        if (this->create_drop_down(this, &this->scenarioPlayerDrop[row],
                                   0x28, 100, 0x144, y - 1,
                                   0x28, 0x18, 0x0B) == 0) {
            return;
        }
        this->scenarioPlayerDrop[row]->set_draw_style(
            TDropDownPanel::DrawStyleLeftButton);
        this->scenarioPlayerDrop[row]->set_draw_val_rect(0);
        this->scenarioPlayerDrop[row]->set_help_info(0x75FB, -1);

        if (this->create_button(this, &this->playerColor[row], "", 0,
                                0x136, y, 0x1E, 0x14, 0x0B, 0, 1) == 0) {
            return;
        }
        this->playerColor[row]->set_help_info(0x7604, -1);

        if (this->create_text(this, &this->playerColorText[row], "",
                              0x131, y, 0x28, 0x16, 0x0B, 1, 1, 0) == 0) {
            return;
        }

        TButtonPanel** team = &this->playerTeam[row];
        if (this->create_button(this, team, 0x25B0,
                                0, 0x17C, y, 0x1E, 0x14, 0x0B, 0, 1) == 0) {
            return;
        }
        (*team)->set_help_info(0x7603, -1);
        (*team)->set_state_info(5);

        button_id = 1;
        do {
            sprintf(str, "%d", button_id);
            (*team)->set_text(static_cast<short>(button_id), str);
            int next_button_id = button_id + 1;
            (*team)->set_id(static_cast<short>(button_id), next_button_id, 0);
            button_id = next_button_id;
        } while (button_id < 5);

        int text_y = y + 2;
        if (this->create_text(this, &this->playerTeamText[row], "",
                              0x177, y, 0x28, 0x16, 0x0B, 1, 1, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerNameText[row], "",
                              0x1C, text_y, 0x8B, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerCivText[row], "",
                              0xBF, text_y, 0x6D, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->scenarioPlayerText[row], "",
                              0x159, text_y, 0x28, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        TTextPanel** player_cd = &this->playerCDText[row];
        if (this->create_text(this, player_cd, 0x25DF,
                              0x151, text_y + 1, 0x14, 0x16, 6, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerVersionText[row], "",
                              0x161, text_y + 1, 0x1D, 0x16, 6, 0, 0, 0) == 0) {
            return;
        }

        (*player_cd)->set_active(0);
    }

    if (rge_base_game->singlePlayerGame() || comm->IsHost()) {
        if (this->create_button(this, &this->gameSettingsButton, 0x25D2,
                                0, 0x1A4, 0x32, 0xD2, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->gameSettingsButton->set_help_info(0x75FC, -1);
    }

    if (this->create_text(this, &this->scenarioName, "",
                          0x1A4, 0x54, 0xDC, 0x44, 0x0B, 0, 0, 1) == 0) {
        return;
    }

    y = 0x53;
    TTextPanel** setting = this->settingText;
    for (; y < 0x233; ++setting, y += 0x18) {
        if (this->create_text(this, setting, "",
                              0x1A4, y, 0xDC, 0x14, 0x0B, 0, 0, 0) == 0) {
            return;
        }
    }

    if (rge_base_game->multiplayerGame()) {
        if (this->create_text(this, &this->chatTitle, 0x25D7,
                              10, 0x118, 100, 0x14, 4, 0, 1, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->chatBox, "",
                              10, 300, 400, 0x60, 10, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_auto_scrollbar(&this->chatScrollbar,
                                        this->chatBox, 0x14) == 0) {
            return;
        }
        if (this->create_edit(this, &this->chatInput, "", 0xF7,
                              TEditPanel::FormatText,
                              10, 0x192, 400, 0x17, 10, 1, 0) == 0) {
            return;
        }
        this->chatInput->set_help_info(0x75FE, -1);
        this->chatBox->set_bevel_info(3,
                                      this->bevel_color1,
                                      this->bevel_color2,
                                      this->bevel_color3,
                                      this->bevel_color4,
                                      this->bevel_color5,
                                      this->bevel_color6);
        this->chatBox->set_help_info(0x75FD, -1);
        this->chatBox->empty_list();
    }

    if (rge_base_game->singlePlayerGame()) {
        if (this->create_text(this, &this->numberPlayersTitle, 0x25D8,
                              0x1A, 0x127, 0x14F, 0x14, 0, 0, 1, 0) == 0) {
            return;
        }
        if (this->create_drop_down(this, &this->numberPlayersDrop,
                                   0x46, 100, 0x1F, 0x142,
                                   0x46, 0x18, 0x0B) == 0) {
            return;
        }
        this->numberPlayersDrop->set_help_info(0x7600, -1);
    }

    this->i_am_ready = 0;

    if (rge_base_game->singlePlayerGame()) {
        if (this->create_button(this, &this->startButton, "", 0,
                                0x46, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->startButton->set_text(0, 0x25EE);
        this->startButton->set_help_info(0x75FF, -1);
        this->set_curr_child(this->startButton);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
    } else if (comm->IsHost()) {
        if (this->create_check_box(this, &this->ready_button,
                                   10, 0x1B8, 0x1E, 0x1E, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->ready_button_label, 0x25BF,
                              0x2D, 0x1B8, 0x96, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
        this->ready_button->set_help_info(0x7602, -1);
        if (this->create_button(this, &this->startButton, "", 0,
                                0xC3, 0x1B8, 200, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->startButton->set_text(0, 0x25EE);
        this->startButton->set_help_info(0x75FF, -1);
        this->startButton->set_disabled(1);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x195, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
        if (this->create_button(this, &this->netInfoButton, 0x25EF,
                                0, 600, 400, 0x1E, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->netInfoButton->set_help_info(0x7601, -1);
        comm->SetMyReadiness(0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        if (this->create_check_box(this, &this->ready_button,
                                   100, 0x1B8, 0x1E, 0x1E, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->ready_button_label, 0x25BF,
                              0x87, 0x1B8, 0x96, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
        this->ready_button->set_help_info(0x7602, -1);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
    }

    if (this->create_button(this, &this->help_button, 0xFA9,
                            0, 600, 0x1B8, 0x1E, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button(this, &this->close_button, 0x3EA,
                            0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4,
                                        4, 0x11, 0x11, 0x11, 0x11,
                                        0, 0, 0, 0);
    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;
    this->setupTabOrder();
    L->Log("$$$ CHAT SCREEN: UPDATE SUMMARY");
    this->updateSummary();
    if (rge_base_game->singlePlayerGame()) {
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
            "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x243);
        debug_srand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x243, now);

        for (i = 0; i < 8; ++i) {
            this->defaultColor[i] = static_cast<unsigned char>(i + 1);
            static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(
                i,
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x248) %
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
                                  "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x26A) %
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




TribeMPSetupScreen::~TribeMPSetupScreen()
{
    if (this->scenarioInfo != 0) {
        delete this->scenarioInfo;
        this->scenarioInfo = 0;
    }

    panel_system.destroyPanel("Game Settings Screen");
    panel_system.destroyPanel("Select Tribe Screen");
    panel_system.destroyPanel("Kick Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");

    delete this->title;
    delete this->playerTitle;
    delete this->civTitle;
    delete this->settingsTitle;
    delete this->colorTitle;
    delete this->teamTitle;

    for (int i = 0; i < 8; i++) {
        delete this->playerNameDrop[i];
        delete this->playerCivDrop[i];
        delete this->scenarioPlayerDrop[i];
        delete this->playerColor[i];
        delete this->playerTeam[i];
        delete this->playerNameText[i];
        delete this->playerCivText[i];
        delete this->scenarioPlayerText[i];
        delete this->playerCDText[i];
        delete this->playerVersionText[i];
        delete this->playerColorText[i];
        delete this->playerTeamText[i];
    }

    delete this->chatInput;
    delete this->chatTitle;
    delete this->chatBox;
    delete this->gameSettingsButton;
    delete this->scenarioName;
    delete this->victoryFixedText;

    for (int j = 0; j < 20; j++) {
        delete this->settingText[j];
        delete this->settingValue[j];
    }

    delete this->mapSizeLabel;
    delete this->mapSizeDrop;
    delete this->mapTypeLabel;
    delete this->mapTypeDrop;
    delete this->numberPlayersTitle;
    delete this->numberPlayersDrop;
    delete this->numberPlayersText;
    delete this->hiddenMapButton;
    delete this->hiddenMapText;
    delete this->victoryTypeLabel;
    delete this->victoryTypeDrop;
    delete this->victoryAmountLabel;
    delete this->victoryAmountInput;
    delete this->startButton;
    delete this->cancelButton;
    delete this->close_button;
    delete this->ready_button;
    delete this->ready_button_label;
    delete this->netInfoButton;
    delete this->help_button;
}




long TribeMPSetupScreen::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    if (rge_base_game->multiplayerGame()) {
        if (last_send_shared == 0) {
            last_send_shared = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x2FE);
        }
        else {
            unsigned long t = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x301);
            if (t - last_send_shared != 0) {
                comm->SendSharedData(0);
                last_send_shared = debug_timeGetTime(
                    "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x304);
            }
        }
    }
    return TPanel::handle_idle();
}


long TribeMPSetupScreen::key_down_action(long p0, short p1, int p2, int p3, int p4) { return 0; }



long TribeMPSetupScreen::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    char file_name[260];
    _finddata_t file_info;

    if (param_1 != 0) {
        if (param_1 == this->startButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->startGame();
            return 1;
        }

        if (param_1 == this->ready_button && param_2 == 1) {
            if (this->ready_button->get_state() != 0) {
                L->Log("$$$ SELECTED I'M READY");
                if (comm->IsHost()) {
                    comm->SetMyReadiness(1, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    if (rge_base_game->playerVersion(0) != 1) {
                        this->ready_button->set_state(0);
                        this->TEasy_Panel::popupOKDialog(0x25E3, 0, 0x1C2, 100);
                        return 1;
                    }
                    int me = comm->WhoAmI() - 1;
                    L->Log("$$$ SAVING MYCIV & MYTEAM");
                    this->myCivilization = this->playerCivDrop[me]->get_id();
                    this->myScenarioPlayer = this->scenarioPlayerDrop[me]->get_id();
                    this->myPlayerColor = this->playerColor[me]->get_id();
                    this->myPlayerTeam = this->playerTeam[me]->get_state() + 1;
                    if (rge_base_game->scenarioGame()) {
                        char* dir = rge_base_game->prog_info->scenario_dir;
                        sprintf(file_name, "%s%s.scn", dir,
                                rge_base_game->scenarioName());
                        if (_findfirst(file_name, &file_info) == -1) {
                            sprintf(file_name, "%s.scx", rge_base_game->scenarioName());
                        } else {
                            sprintf(file_name, "%s.scn", rge_base_game->scenarioName());
                        }
                        this->myScenarioChecksum = rge_base_game->get_scenario_checksum(file_name);
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
                int cd = 0;
                if (!comm->IsHost()) {
                    cd = rge_base_game->check_for_cd(0) + 1;
                }
                comm->SetMyReadiness(0, 0, 0, cd, 0, 0, 0, 0);
                if (this->chatInput != 0 && this->chatInput->active != 0) {
                    this->set_curr_child(this->chatInput);
                }
                this->i_am_ready = 0;
            }
            this->fillPlayers();
            if (comm->IsHost()) {
                this->gameSettingsButton->set_disabled(this->i_am_ready);
                this->startButton->set_disabled(this->i_am_ready == 0);
                rge_base_game->send_game_options();
                this->resend_game_options = 0;
                comm->SendSharedData(1);
                return 1;
            }
            return 1;
        }

        if (param_1 == this->gameSettingsButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            if (panel_system.panel("Game Settings Screen") == 0) {
                rge_base_game->disable_input();
                new TribeGameSettingsScreen();
            }
            panel_system.setCurrentPanel("Game Settings Screen", 0);
            return 1;
        }

        if (param_1 == this->help_button && param_2 == 1) {
            this->setup_popup_help();
            return 1;
        }

        if (param_1 == this->close_button && param_2 == 1) {
            rge_base_game->close();
            return 1;
        }

        if (param_1 == this->cancelButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->cancelScreen(0);
            return 1;
        }

        if (param_1 == this->netInfoButton) {
            if (param_2 == 1) {
                this->showNetInfo();
                return 1;
            }
        } else if (param_2 == 1) {
            for (int i = 0; i < 8; i++) {
                if (param_1 == this->playerColor[i]) {
                    static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(i, this->playerColor[i]->get_id());
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerColor = this->playerColor[i]->get_id();
                        return 1;
                    }
                    return 1;
                }
                if (param_1 == this->playerTeam[i]) {
                    rge_base_game->setPlayerTeam(i, this->playerTeam[i]->get_state() + 1);
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerTeam = this->playerTeam[i]->get_state() + 1;
                        return 1;
                    }
                    return 1;
                }
            }
        }

        if (param_1 == this->chatInput && param_2 == 0 &&
            this->chatInput->currentLine() != 0 && this->chatInput->currentLine()[0] != 0) {
            comm->SendChatMsgAll(this->chatInput->currentLine());
            this->chatInput->set_text("");
            return 1;
        }

        if (param_1 == this->numberPlayersDrop && param_2 == 0) {
            rge_base_game->setNumberPlayers(this->numberPlayersDrop->get_id());
            this->updateSummary();
            return 1;
        }

        if (param_1->panelName() != 0 && strcmp(param_1->panelName(), "Game Settings Screen") == 0) {
            if (param_2 != 0) {
                this->updateSummary();
                if (!rge_base_game->singlePlayerGame()) {
                    rge_base_game->send_game_options();
                    this->resend_game_options = 0;
                }
            }
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            return 1;
        }

        if (param_1->panelName() != 0 && strcmp(param_1->panelName(), "Kick Dialog") == 0) {
            if (param_2 == 0) {
                long id = this->playerNameDrop[this->playerToKick - 1]->get_id();
                comm->Kick(this->playerToKick);
            comm->SetPlayerHumanity(this->playerToKick,
                                    static_cast<PLAYERHUMANITY>(id));
                this->playerNameDrop[this->playerToKick - 1]->set_line(
                    this->playerNameDrop[this->playerToKick - 1]->get_line(id));
            } else {
                this->playerNameDrop[this->playerToKick - 1]->set_line(0);
            }
            delete param_1;
            return 1;
        }

        if (param_2 == 0 && rge_base_game->numberPlayers() > 0) {
            int i = 0;
            do {
                if (param_1 == this->playerNameDrop[i]) {
                    if (rge_base_game->multiplayerGame() &&
                        this->playerNameDrop[i]->get_line() > 0 &&
                        comm->IsPlayerHuman(i + 1)) {
                        this->kickPlayer(i + 1);
                        return 1;
                    }
                    comm->SetPlayerHumanity(
                        i + 1,
                        static_cast<PLAYERHUMANITY>(
                            this->playerNameDrop[i]->get_id()));
                    return 1;
                }
                if (param_1 == this->playerCivDrop[i]) {
                    static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(i, this->playerCivDrop[i]->get_id());
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myCivilization = this->playerCivDrop[i]->get_id();
                        return 1;
                    }
                    return 1;
                }
                if (param_1 == this->scenarioPlayerDrop[i]) {
                    if (rge_base_game->multiplayerGame()) {
                        static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(i, this->scenarioPlayerDrop[i]->get_id());
                        if (!comm->IsHost()) {
                            this->myScenarioPlayer = this->scenarioPlayerDrop[i]->get_id();
                            return 1;
                        }
                        return 1;
                    }
                    static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(0, this->scenarioPlayerDrop[0]->get_id());
                    int sp = 1;
                    int player = 0;
                    do {
                        if (player != static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(0) &&
                            this->scenarioInfo->Get_player_Active(player) != 0) {
                            static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(sp, player);
                            sp++;
                            if (sp >= rge_base_game->numberPlayers()) break;
                        }
                        player++;
                        } while (player < 8);
                    this->fillPlayers();
                    return 1;
                }
                i++;
            } while (i < rge_base_game->numberPlayers());
        }
        return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
    }
    return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
}




int TribeMPSetupScreen::startGame()
{
    int send_options = 0;

    if (rge_base_game->multiplayerGame()) {
        char msg[1024];
        if (!comm->IsHost()) {
            return 0;
        }
        if (!comm->AllPlayersReady()) {
            this->popupOKDialog(0x25c1, 0, 0x1c2, 100);
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
                        sprintf(msg, this->get_string(0x25e1), comm->GetPlayerName(i3 + 1));
                        this->popupOKDialog(msg, 0, 0x1c2, 100);
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
                    sprintf(msg, this->get_string(0x25e2), comm->GetPlayerName(u12 + 1));
                    this->popupOKDialog(msg, 0, 0x1c2, 100);
                    return 0;
                }
            }
        }
    }

    if (rge_base_game->scenarioGame() && this->scenarioInfo == 0) {
        this->popupOKDialog(0x25c2, 0, 0x1c2, 100);
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
            this->popupOKDialog(0x25c6, 0, 0x1c2, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && i5 > this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(0x25c3), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, 0x1c2, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && this->settingsFixed != 0 &&
            i5 != this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(0x25c5), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, 0x1c2, 100);
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
            this->popupOKDialog(0x7d9, 0, 0x1c2, 100);
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
        this->popupOKDialog(0x961, 0, 0x1c2, 100);
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
                            (debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x5E4) * count) /
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




void TribeMPSetupScreen::showNetInfo()
{
    char message[1024];
    char temp_str[256];

    RGE_Communications_Addresses* addresses = new RGE_Communications_Addresses(comm);
    if (addresses) {
        unsigned int num_addr = addresses->AddressesAvailable;
        message[0] = 0;
        if (num_addr > 0) {
            strcat(message, "\n\n");
            sprintf(temp_str, this->get_string(0x238c), addresses->GetHostName());
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
                message, "OKDialog", 0x1c2, num_addr * 18 + 100);
        } else {
            this->TEasy_Panel::popupOKDialog(0x238d, 0, 0x1c2, 100);
        }
        delete addresses;
    }
}




void TribeMPSetupScreen::cancelScreen(int timed_out) {
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
        if (timed_out != 0) {
            TRIBE_Screen_Main_Error* error = new TRIBE_Screen_Main_Error;
            if (error != 0 && error->error_code == 0) {
                error->set_text(0x96A);
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




long TribeMPSetupScreen::handle_user_command(unsigned int command, long param)
{
    char message[260];
    int player_ready;
    unsigned long scenario_checksum;
    unsigned long user6, user2, user7, user3, user1, user4;

    if (rge_base_game->singlePlayerGame()) {
        return 1;
    }

    switch (command) {
    case 0x17BB:  // COMM_SHARED_DATA_SENT
        L->Log("$$$ USER_COMMAND: COMM_SHARED_DATA_SENT (%d,%d)", command, param);
        if (comm->IsHost()) {
            int i = 0;
            if (rge_base_game->numberPlayers() > 0) {
                do {
                    if (static_cast<TRIBE_Game*>(rge_base_game)->civilization(i) >= 0x32) {
                        L->Log("$$$ HOST RESET CIV+50");
                        static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(i,
                            static_cast<TRIBE_Game*>(rge_base_game)->civilization(i) - 0x32);
                        this->resend_game_options = 1;
                    }
                    if (rge_base_game->playerTeam(i) >= 0x32) {
                        L->Log("$$$ HOST RESET TEAM+50");
                        rge_base_game->setPlayerTeam(i, rge_base_game->playerTeam(i) - 0x32);
                        this->resend_game_options = 1;
                    }
                    ++i;
                } while (i < rge_base_game->numberPlayers());
            }
        }
        return 1;

    case 0x17A4:  // COMM_UPDATE_PLAYERS
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PLAYERS (%d,%d)", command, param);
        {
            int changed = 0;
            if (comm->IsHost() && this->sent_cd_status == 0) {
                this->sent_cd_status = 1;
                if (rge_base_game->check_for_cd(0)) {
                    changed = 1;
                    rge_base_game->setPlayerHasCD(comm->WhoAmI() - 1, 1);
                }
            }
            if (comm->IsHost()) {
                int i = 0;
                long* checksum = this->scenarioCheckSum;
                int player;
                do {
                    player = i + 1;
                    int humanity = comm->GetPlayerHumanity(player);
                    if (comm->WhoAmI() != player && humanity == 2) {
                        comm->GetClientReadiness(player, &player_ready,
                                                 &user3, &user6, &user7,
                                                 &user1, &user4,
                                                 &scenario_checksum, &user2);
                        if (user3 != 0 && user3 != static_cast<TRIBE_Game*>(rge_base_game)->civilization(i)) {
                            static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(i, user3);
                            changed = 1;
                        }
                        if (user6 != 0) {
                            int sp = user6 - 1;
                            if (sp != static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(i)) {
                                static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(i, sp);
                                changed = 1;
                            }
                        }
                        if (user7 != 0) {
                            if (user7 == 1) {
                                if (rge_base_game->playerHasCD(i) == 1) {
                                    rge_base_game->setPlayerHasCD(i, 0);
                                    changed = 1;
                                }
                            } else if (user7 == 2) {
                                if (rge_base_game->playerHasCD(i) == 0) {
                                    rge_base_game->setPlayerHasCD(i, 1);
                                    changed = 1;
                                }
                            }
                        }
                        if (user1 != 0 && user1 != static_cast<TRIBE_Game*>(rge_base_game)->playerColor(i)) {
                            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(i, user1);
                            changed = 1;
                        }
                        if (user4 != 0 && user4 != rge_base_game->playerTeam(i)) {
                            rge_base_game->setPlayerTeam(i, user4);
                            changed = 1;
                        }
                        if (scenario_checksum != 0) {
                            *checksum = scenario_checksum;
                        }
                        if (user2 != 0) {
                            rge_base_game->setPlayerVersion(
                                i, static_cast<unsigned char>(user2));
                            changed = 1;
                        }
                    } else if (humanity != 2 && humanity != 4) {
                        int r = debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x6D6) % 16 + 1;
                        if (static_cast<TRIBE_Game*>(rge_base_game)->civilization(i) != r) {
                            static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(i, r);
                            changed = 1;
                        }
                        if (static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(i) != i) {
                            static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(i, i);
                            changed = 1;
                        }
                        if (rge_base_game->playerHasCD(i)) {
                            rge_base_game->setPlayerHasCD(i, 0);
                            changed = 1;
                        }
                        if (static_cast<TRIBE_Game*>(rge_base_game)->playerColor(i) != this->defaultColor[i]) {
                            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(i, this->defaultColor[i]);
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
                        *checksum = 0;
                    }
                    checksum++;
                    i = player;
                } while (player < 8);
                if (changed) {
                    rge_base_game->send_game_options();
                    this->resend_game_options = 0;
                }
            }
            this->fillPlayers();
            this->set_redraw(TPanel::RedrawNormal);
            return 1;
        }

    case 0x17D5:  // CHAT_RECEIVED
        L->Log("$$$ USER_COMMAND: CHAT_RECEIVED (%d,%d)", command, param);
        this->fillChat(param);
        return 1;

    case 0x17A6:  // COMM_UPDATE_PARAMS
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PARAMS (%d,%d)", command, param);
        rge_base_game->receive_game_options();
        {
            int i = 0;
            if (rge_base_game->numberPlayers() > 0) {
                do {
                    if (static_cast<TRIBE_Game*>(rge_base_game)->civilization(i) >= 0x32) {
                        L->Log("$$$ CIV2>50");
                        static_cast<TRIBE_Game*>(rge_base_game)->setCivilization(i,
                            static_cast<TRIBE_Game*>(rge_base_game)->civilization(i) - 0x32);
                        if (i + 1 == comm->WhoAmI()) {
                            this->myCivilization = 0;
                            L->Log("$$$ RESETTING MYCIV2");
                        }
                    }
                    if (rge_base_game->playerTeam(i) >= 0x32) {
                        L->Log("$$$ TEAM2>50");
                        rge_base_game->setPlayerTeam(i, rge_base_game->playerTeam(i) - 0x32);
                        if (i + 1 == comm->WhoAmI()) {
                            this->myPlayerTeam = 0;
                            L->Log("$$$ RESETTING MYTEAM2");
                        }
                    }
                    ++i;
                } while (i < rge_base_game->numberPlayers());
            }
        }
        if (this->myScenarioPlayer != 0) {
            if (strcmp(this->saveScenarioName, rge_base_game->scenarioName()) != 0) {
                this->myScenarioPlayer = -1;
            }
        }
        this->updateSummary();
        if (!comm->IsHost()) {
            if (!(this->sent_cd_status != 0 &&
                  this->myScenarioChecksum == this->saveScenarioChecksum &&
                  comm->IsPlayerReady(comm->WhoAmI()) == this->i_am_ready)) {
                int checksum = this->myScenarioChecksum;
                this->sent_cd_status = 1;
                this->saveScenarioChecksum = checksum;
                comm->SetMyReadiness(this->i_am_ready, 0, 0,
                                     rge_base_game->check_for_cd(0) + 1, 0, 0, checksum, 1);
            }
        }
        return 1;

    case 0x17A7:  // COMM_LAUNCH_GAME
        L->Log("$$$ USER_COMMAND: COMM_LAUNCH_GAME (%d,%d)", command, param);
        chat->setWindowHandle(AppWnd);
        comm->SetWindowHandle(AppWnd);
        static_cast<TRIBE_Game*>(rge_base_game)->start_game(0);
        return 1;

    case 0x17A8:  // COMM_CANCEL_GAME
        L->Log("$$$ USER_COMMAND: COMM_CANCEL_GAME (%d,%d)", command, param);
        this->handleKickedPlayer(0);
        return 1;

    case 0x17A9:  // COMM_HOST_EXITED
        L->Log("$$$ USER_COMMAND: COMM_HOST_EXITED (%d,%d)", command, param);
        this->handleKickedPlayer(0);
        return 1;

    case 0x17B2:  // COMM_PLAYER_DROPPED
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_DROPPED (%d,%d)", command, param);
        this->handleKickedPlayer(1);
        return 1;

    case 0x17AA:  // COMM_PLAYER_KICKED
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_KICKED (%d,%d)", command, param);
        this->handleKickedPlayer(1);
        return 1;

    case 0x17B3:  // COMM_OTHER_PLAYER_DROPPED
        L->Log("$$$ USER_COMMAND: COMM_OTHER_PLAYER_DROPPED (%d,%d)", command, param);
        this->fillPlayers();
        return 1;

    case 0x17B7:  // COMM_PLAYER_SERVICE_ERROR
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_SERVICE_ERROR (%d,%d)", command, param);
        sprintf(message + 4, this->get_string(0x25DE), comm->GetPlayerName(param));
        this->popupOKDialog(message + 4, 0, 0x1C2, 100);
        return 1;

    case 0x17B6:  // COMM_BAD_VERSION
        L->Log("$$$ USER_COMMAND: COMM_BAD_VERSION (%d,%d)", command, param);
        sprintf(message + 4, this->get_string(0x25DD), comm->GetPlayerName(param));
        this->popupOKDialog(message + 4, 0, 0x1C2, 100);
        return 1;

    case 0x17B9:  // COMM_HOST_BUSY
        L->Log("$$$ USER_COMMAND: COMM_HOST_BUSY (%d,%d)", command, param);
        if (comm->IsLobbyLaunched()) {
            this->cancelScreen(1);
        } else {
            this->handleKickedPlayer(0);
        }
        return 1;

    case 0x17AE:  // COMM_NO_LINK
        L->Log("$$$ USER_COMMAND: COMM_NO_LINK (%d,%d)", command, param);
        this->cancelScreen(0);
        return 1;

    default:
        L->Log("$$$ USER_COMMAND: UNKNOWN (%d, %d)", command, param);
        return 1;
    }
}


long TribeMPSetupScreen::handle_timer_command(unsigned int p0, long p1) { return 1; }




void TribeMPSetupScreen::fillPlayers()
{
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
                    this->playerNameText[i]->set_text(0x25B3L);
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




void TribeMPSetupScreen::fillChat(int n) {
    if (!rge_base_game->singlePlayerGame()) {
        int lines = this->chatBox->numberLines();
        int need_scroll = (lines > 0 && this->chatBox->bot_line == lines - 1);
        if (lines >= 100) {
            this->chatBox->delete_line(0);
        }
        this->chatBox->word_wrap_append(chat->GetChatMsg(n));
        if (need_scroll) {
            this->chatBox->scroll(7, 0, 1);
        }
    }
}




void TribeMPSetupScreen::updateSummary()
{
    int changed = 0;
    char str1[256];
    char str2[256];
    char file_name[0x118];
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
            long handle = _findfirst(str1, &file_info);
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
            sprintf(file_name, "%s%s.scn", scenario_dir, scenario_name);
            long handle = _findfirst(file_name, &file_info);
            if (handle == -1) {
                sprintf(file_name, "%s.scx",
                        rge_base_game->scenarioName());
            } else {
                sprintf(file_name, "%s.scn",
                        rge_base_game->scenarioName());
            }
            this->myScenarioChecksum = rge_base_game->get_scenario_checksum(file_name);
        } else {
            this->myScenarioChecksum = 0;
        }
    }

    int setting;
    for (int i = 0; i < 20; ++i) {
        this->settingText[i]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, this->get_string(0x25ED),
                rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        setting = 3;
    } else {
        if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch()) {
            this->get_string(0x2617, str1, 0x100);
        } else {
            this->get_string(0x25B5, str1, 0x100);
        }
        sprintf(str2, this->get_string(0x25ED), str1);
        this->scenarioName->set_text(str2);
        setting = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapSize()) {
        case 0: strcpy(str1, this->get_string(0x2973)); break;
        case 1: strcpy(str1, this->get_string(0x2974)); break;
        case 2: strcpy(str1, this->get_string(0x2975)); break;
        case 3: strcpy(str1, this->get_string(0x2976)); break;
        case 4: strcpy(str1, this->get_string(0x2977)); break;
        case 5: strcpy(str1, this->get_string(0x2978)); break;
        }
        sprintf(str2, this->get_string(0x25DA), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;

        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
        case 0: strcpy(str1, this->get_string(0x296A)); break;
        case 1: strcpy(str1, this->get_string(0x296B)); break;
        case 2: strcpy(str1, this->get_string(0x296C)); break;
        case 3: strcpy(str1, this->get_string(0x296D)); break;
        case 4: strcpy(str1, this->get_string(0x296E)); break;
        case 5: strcpy(str1, this->get_string(0x296F)); break;
        case 6: strcpy(str1, this->get_string(0x2970)); break;
        case 7: strcpy(str1, this->get_string(0x2971)); break;
        case 8: strcpy(str1, this->get_string(0x2972)); break;
        }
        sprintf(str2, this->get_string(0x25B6), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->scenarioGame()) {
        if (this->settingsFixed == 0 && this->scenarioPlayerCount != 2) {
            sprintf(str2, "%s %d - %d", this->get_string(0x25B7),
                    2, this->scenarioPlayerCount);
        } else {
            sprintf(str2, "%s %d", this->get_string(0x25B7),
                    this->scenarioPlayerCount);
        }
    } else {
        sprintf(str2, "%s 2 - 8", this->get_string(0x25B7));
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
    case 7:
        strcpy(str1, this->get_string(0x10E9));
        sprintf(str2, this->get_string(0x25BE), str1,
                static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount());
        break;
    case 8:
        strcpy(str1, this->get_string(0x10EA));
        sprintf(str2, this->get_string(0x25BE), str1,
                static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount());
        break;
    case 1:
        strcpy(str1, this->get_string(0x10E1));
        sprintf(str2, this->get_string(0x25BC), str1);
        break;
    case 9:
        strcpy(str1, this->get_string(0x10EC));
        sprintf(str2, this->get_string(0x25BC), str1);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, this->get_string(0x10EC));
        } else {
            strcpy(str1, this->get_string(0x10E7));
        }
        sprintf(str2, this->get_string(0x25BC), str1);
        break;
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int age = static_cast<TRIBE_Game*>(rge_base_game)->startingAge();
    if (age == 0) {
        this->get_string(0x10E7, str1, 0x100);
    } else if (age == 1) {
        this->get_string(0x106E, str1, 0x100);
    } else {
        this->get_string(age + 0x1067, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E4), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int resources = static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel();
    if (resources == 0) {
        this->get_string(0x10E7, str1, 0x100);
    } else {
        this->get_string(resources + 0x25E5, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E5), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    rge_base_game->difficulty();
    this->get_string(rge_base_game->difficulty() + 0x2BD0, str1, 0x100);
    this->get_string(0x25E0, str2, 0x100);
    sprintf(str3, str2, str1);
    this->settingText[setting]->set_text(str3);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions()) {
        this->get_string(0xFA4, str1, 0x100);
    } else {
        this->get_string(0xFA3, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E9), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, this->get_string(0xFA3));
    } else {
        strcpy(str1, this->get_string(0xFA4));
    }
    sprintf(str2, this->get_string(0x25B8), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree()) {
        this->get_string(0xFA3, str1, 0x100);
    } else {
        this->get_string(0xFA4, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25EC), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, this->get_string(0xFA3));
        } else {
            strcpy(str1, this->get_string(0xFA4));
        }
        sprintf(str2, this->get_string(0x25BB), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->multiplayerGame()) {
        this->get_string(static_cast<TRIBE_Game*>(rge_base_game)->mpPathFinding() + 0x260E,
                         str1, 0x100);
    } else {
        this->get_string(rge_base_game->pathFinding() + 0x260E,
                         str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25F1), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    sprintf(str2, this->get_string(0x25F0),
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



void TribeMPSetupScreen::kickPlayer(int param_1) {
    char text[256];

    this->playerToKick = param_1;
    sprintf(text, this->get_string(0x25C8), comm->GetPlayerName(param_1));
    this->popupYesNoDialog(text, "Kick Dialog", 0x1C2, 0x64);
}




void TribeMPSetupScreen::handleKickedPlayer(int player_index) {
    this->cancelScreen(0);
    TEasy_Panel* panel = static_cast<TEasy_Panel*>(
        panel_system.currentPanel());
    if (panel != 0) {
        panel->popupOKDialog(0x25CA + (player_index != 0 ? -1 : 0),
                             0, 0x1C2, 100);
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
            victoryAmountLabel->set_text(0x25CB);
            return;
        case 3:
        case 4:
        case 5:
            victoryAmountLabel->set_text(0x25CC);
            return;
        case 6:
            victoryAmountLabel->set_text(0x25CD);
            return;
        }
    }
}




void TribeMPSetupScreen::setupTabOrder()
{
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
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0xB31) %
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




TRIBE_Screen_Wait::TRIBE_Screen_Wait() : TScreenPanel("Multiplayer Wait Screen")
{
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

    this->set_ideal_size(0x280, 0x1E0);

    this->create_text(this, &this->message, "",
                     0x14, 0x28, 0x17C, 0x190, 4, 1, 1, 1);
    if (this->create_button(this, &this->close_button, 0x3EA,
                            0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4,
                                        4, 0x11, 0x11, 0x11,
                                        0x11, 0, 0, 0, 0);

    if (this->create_text(this, &this->scenarioName, "",
                          0x1A4, 0x54, 0xDC, 0x44, 0xB, 0, 0, 1) == 0) {
        return;
    }

    int y = 0x53;
    int k = 0;
    for (; y < 0x233; y += 0x18, k++) {
        if (this->create_text(this, &this->settingText[k], "",
                              0x1A4, y, 0xDC, 0x14, 0xB, 0, 0, 0) == 0) {
            return;
        }
    }

    for (k = 0; k < 20; k++) {
        this->settingText[k]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, get_string(0x25ED), rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        i = 3;
    } else {
        if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch()) {
            get_string(0x2617, str1, 0x100);
        } else {
            get_string(0x25B5, str1, 0x100);
        }
        sprintf(str2, get_string(0x25ED), str1);
        this->scenarioName->set_text(str2);
        i = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapSize()) {
        case 0: strcpy(str1, get_string(0x2973)); break;   // Tiny
        case 1: strcpy(str1, get_string(0x2974)); break;   // Small
        case 2: strcpy(str1, get_string(0x2975)); break;   // Medium
        case 3: strcpy(str1, get_string(0x2976)); break;   // Large
        case 4: strcpy(str1, get_string(0x2977)); break;   // Huge
        case 5: strcpy(str1, get_string(0x2978)); break;   // Gigantic
        }
        sprintf(str2, get_string(0x25DA), str1);           // "Map Size: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;

        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
        case 0: strcpy(str1, get_string(0x296A)); break;   // All Water
        case 1: strcpy(str1, get_string(0x296B)); break;   // Mostly Water
        case 2: strcpy(str1, get_string(0x296C)); break;   // Water & Land
        case 3: strcpy(str1, get_string(0x296D)); break;   // Mostly Land
        case 4: strcpy(str1, get_string(0x296E)); break;   // All Land
        case 5: strcpy(str1, get_string(0x296F)); break;   // Continental
        case 6: strcpy(str1, get_string(0x2970)); break;   // Lake
        case 7: strcpy(str1, get_string(0x2971)); break;   // Hilly
        case 8: strcpy(str1, get_string(0x2972)); break;   // Narrows
        }
        sprintf(str2, get_string(0x25B6), str1);           // "Map Type: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }
    i++;

    switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
    case 7:                            // Time
        strcpy(str1, get_string(0x10E9));
        sprintf(str2, get_string(0x25BE), str1,
                static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount()); // "Victory: %s (%d)"
        break;
    case 8:                            // Score
        strcpy(str1, get_string(0x10EA));
        sprintf(str2, get_string(0x25BE), str1,
                static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount()); // "Victory: %s (%d)"
        break;
    case 1:                            // Conquest
        strcpy(str1, get_string(0x10E1));
        sprintf(str2, get_string(0x25BC), str1);            // "Victory: %s"
        break;
    case 9:                            // Standard
        strcpy(str1, get_string(0x10E7));
        sprintf(str2, get_string(0x25BC), str1);            // "Victory: %s"
        break;
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, get_string(0x10EC));
        } else {
            strcpy(str1, get_string(0x10E7));
        }
        sprintf(str2, get_string(0x25BC), str1);            // "Victory: %s"
        break;
    }
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int age = static_cast<TRIBE_Game*>(rge_base_game)->startingAge();
    if (age == 0) {
        get_string(0x10E7, str1, 0x100);                    // Default
    } else if (age == 1) {
        get_string(0x106E, str1, 0x100);                    // Nomad
    } else {
        get_string(age + 0x1067, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E4), str1);                // "Age: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int level = static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel();
    if (level == 0) {
        get_string(0x10E7, str1, 0x100);                    // Default
    } else {
        get_string(level + 0x25E5, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E5), str1);                // "Resources: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    rge_base_game->difficulty();
    get_string(rge_base_game->difficulty() + 0x2BD0, str1, 0x100);
    get_string(0x25E0, str2, 0x100);                        // "Difficulty Level: %s"
    sprintf(str3, str2, str1);
    this->settingText[i]->set_text(str3);
    this->settingText[i]->set_active(1);
    i++;

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions()) {
        get_string(0xFA4, str1, 0x100);
    } else {
        get_string(0xFA3, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E9), str1);                // "Fixed Positions: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, get_string(0xFA3));
    } else {
        strcpy(str1, get_string(0xFA4));
    }
    sprintf(str2, get_string(0x25B8), str1);                // "Reveal Map: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree()) {
        get_string(0xFA3, str1, 0x100);
    } else {
        get_string(0xFA4, str1, 0x100);
    }
    sprintf(str2, get_string(0x25EC), str1);                // "Full Tech Tree: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, get_string(0xFA3));
        } else {
            strcpy(str1, get_string(0xFA4));
        }
        sprintf(str2, get_string(0x25BB), str1);            // "Enable Cheating: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }

    if (rge_base_game->multiplayerGame()) {
        get_string(rge_base_game->mpPathFinding() + 0x260E, str1, 0x100);
    } else {
        get_string(rge_base_game->pathFinding() + 0x260E, str1, 0x100);
    }
    sprintf(str2, get_string(0x25F1), str1);                // "Path Finding: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    sprintf(str2, get_string(0x25F0),
            static_cast<TRIBE_Game*>(rge_base_game)->popLimit());
    this->settingText[i]->set_text(str2);                   // "Population Limit: %d"
    this->settingText[i]->set_active(1);
}


TRIBE_Screen_Wait::~TRIBE_Screen_Wait() {
    delete this->message;
    delete this->close_button;
    delete this->scenarioName;
    for (int i = 0; i < 20; ++i) {
        delete this->settingText[i];
    }
}


void TRIBE_Screen_Wait::set_text(char* param) {
    this->message->set_text(param);
}


void TRIBE_Screen_Wait::set_text(long param) {
    this->message->set_text(param);
}


long TRIBE_Screen_Wait::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if ((param_1 != 0) && (param_1 == this->close_button) &&
        (param_2 == 1)) {
        rge_base_game->close();
        return 1;
    }
    return this->TScreenPanel::action(param_1, param_2, param_3, param_4);
}


long TRIBE_Screen_Wait::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}





TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int mode)
    : TScreenPanel("Multiplayer Disconnect Screen")
{
    this->mode = mode;
    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;

    if (this->setup(rge_base_game->draw_area, "scr3", 0xC385, 0) == 0) {
        this->error_code = 1;
    } else {
        this->set_ideal_size(0x280, 0x1E0);
        this->create_text(this, &this->message, 0x4C0,
                          0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}


TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect() {
    delete this->message;
}


void TRIBE_Screen_Disconnect::set_text(char* param) {
    this->message->set_text(param);
}


void TRIBE_Screen_Disconnect::set_text(long param) {
    this->message->set_text(param);
}




long TRIBE_Screen_Disconnect::action(TPanel* p1, long p2, unsigned long p3, unsigned long p4) {
    if (p1 != 0) {
        if (p1 == this->cancel_button && p2 == 1) {
            static_cast<TRIBE_Game*>(rge_base_game)->quit_game();
            panel_system.destroyPanel("Multiplayer Disconnect Screen");
            panel_system.destroyPanel("Status Screen");
            return 1;
        }
        if (p1 == this->close_button && p2 == 1) {
            rge_base_game->close();
            return 1;
        }
    }
    return TEasy_Panel::action(p1, p2, p3, p4);
}


long TRIBE_Screen_Disconnect::handle_idle() { return TPanel::handle_idle(); }
