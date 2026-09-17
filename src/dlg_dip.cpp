// This file owns every normal function in the compiland.

#include "../include/dlg_dip.h"
#include "../include/asm_draw.h"
#include "../include/tcommand.h"
#include "../include/com_hand.h"
#include "../include/game_globals.h"
#include "../include/chat.h"
#include "../include/debuglog.h"
#include "../include/pnl_lst.h"
#include "../include/resource_ids.h"
#include <stdio.h>

TribeDiplomacyDialog::TribeDiplomacyDialog(TScreenPanel* parentPanel)
    : TDialogPanel("Diplomacy Dialog") {
    PALETTEENTRY paletteColor;
    char temp_str[100];
    TPanel* tabList[35];
    int tabCount = 0;
    int i;

    for (i = 0; i < 8; ++i) {
        this->title[i] = 0;
        this->playerName[i] = 0;
        this->playerVictoryScores[i] = 0;
        this->playerCivilization[i] = 0;
        this->goldTributeButton[i] = 0;
        this->foodTributeButton[i] = 0;
        this->woodTributeButton[i] = 0;
        this->stoneTributeButton[i] = 0;
        this->goldTributeAmount[i] = 0.0f;
        this->foodTributeAmount[i] = 0.0f;
        this->stoneTributeAmount[i] = 0.0f;
        this->woodTributeAmount[i] = 0.0f;
    }
    for (i = 0; i < 24; ++i) {
        this->allyButton[i] = 0;
    }

    this->allianceButton = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->clearButton = 0;
    this->help_button = 0;
    this->needMarket = 0;
    this->buttonPics = 0;
    this->backgroundPics = 0;
    this->playerWood = 0;
    this->playerStone = 0;
    this->playerGold = 0;
    this->playerFood = 0;
    this->woodTotal = 0.0f;
    this->stoneTotal = 0.0f;
    this->foodTotal = 0.0f;
    this->goldTotal = 0.0f;
    this->tribute_flag = 0;

    if (!this->setup(parentPanel->renderArea(), parentPanel, 625, 405,
                     parentPanel->get_popup_info_file(),
                     parentPanel->get_popup_info_id(), 1)) {
        return;
    }

    this->buttonPics = new TShape("tradicon.shp", 0xC62C);
    if (this->buttonPics == 0) {
        return;
    }
    this->backgroundPics = new TShape("dlg_plbn.shp", 0xC63A);
    if (this->backgroundPics == 0) {
        return;
    }

    rge_base_game->get_font(1);

    if (!this->create_text(this, &this->title[0], IDS_DIPLOMACY_TITLE, 72, 5,
                           500, 30, 1, 1, 1, 0)) {
        return;
    }
    if (!this->create_text(this, &this->needMarket, IDS_DIPLOMACY_NEED_MARKET, 440, 110,
                           175, 60, RGE_FONT_STANDARD, 1, 1, 1)) {
        return;
    }
    if (!this->create_text(this, &this->title[1], IDS_DIPLOMACY_NAME, 5, 50,
                           130, 30, RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    if (!this->create_text(this, &this->title[2], IDS_DIPLOMACY_CIVILIZATION, 137, 50,
                           80, 30, RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    if (!this->create_text(this, &this->title[3], IDS_DIPLOMACY_ALLY, 235, 50,
                           70, 30, RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    if (!this->create_text(this, &this->title[4], IDS_DIPLOMACY_NEUTRAL, 290, 50,
                           70, 30, RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    if (!this->create_text(this, &this->title[5], IDS_DIPLOMACY_ENEMY, 360, 50,
                           70, 30, RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }

    sprintf(temp_str, this->get_string(IDS_DIPLOMACY_PAY_TRIBUTE_FORMAT),
            static_cast<long>(rge_base_game->get_player()->attributes[46] *
                              DAT_0056f880));
    if (!this->create_text(this, &this->title[6], temp_str, 440, 50,
                           180, 30, RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    if (!this->create_text(this, &this->title[7], IDS_DIPLOMACY_ALLIED_VICTORY, 318, 330,
                           300, 30, RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }

    this->cur_player_row = -1;
    RGE_Game_World* world = rge_base_game->world;
    int player_id = 1;
    int row = 0;
    int a = 80;
    while (player_id < world->player_num) {
        GetPaletteEntries(this->palette,
                          world->players[player_id]->color_table->map_color,
                          1, &paletteColor);

        int disable_buttons;
        if (rge_base_game->prog_mode == 5 ||
            player_id == world->curr_player ||
            world->players[player_id]->game_status != 0) {
            disable_buttons = 1;
        } else {
            disable_buttons = 0;
        }

        if (player_id == world->curr_player) {
            this->cur_player_row = player_id - 1;
        }

        int computer_font = 0;
        if (world->players[player_id]->game_status == 2) {
            computer_font = 1;
        } else if (rge_base_game->multiplayerGame()) {
            int humanity = 0;
            int player_number;
            for (player_number = 1;
                 player_number <= rge_base_game->numberPlayers();
                 ++player_number) {
                if (rge_base_game->playerID(player_number) == player_id) {
                    int value = comm->GetPlayerHumanity(player_number);
                    if (value == 2 || value == 4) {
                        humanity = value;
                    }
                }
            }
            if (humanity != 2 && humanity != 4) {
                computer_font = 1;
            }
        }

        if (!this->create_text(this, &this->playerName[row],
                               world->players[player_id]->name, 5, a, 130,
                               30, computer_font ? RGE_FONT_STRIKEOUT : RGE_FONT_STANDARD,
                               0, 1, 0)) {
            return;
        }

        rge_base_game->get_string2(RGE_STRING_TYPE_CIVILIZATION,
                                   world->players[player_id]->master_player_id,
                                   0, temp_str, 100);
        if (!this->create_text(this, &this->playerCivilization[row],
                               temp_str, 137, a, 100, 30, RGE_FONT_STANDARD,
                               0, 1, 0)) {
            return;
        }

        if (player_id != world->curr_player) {
            TButtonPanel** buttons = &this->allyButton[row * 3];
            if (!this->create_radio_button(this, &buttons[0], 240, a,
                                           30, 30, 0, 0)) {
                return;
            }
            buttons[0]->set_help_info(IDS_HELP_DIPLOMACY_ALLY, -1);
            if (!this->create_radio_button(this, &buttons[1], 310, a,
                                           30, 30, 0, 0)) {
                return;
            }
            buttons[1]->set_help_info(IDS_HELP_DIPLOMACY_NEUTRAL, -1);
            if (!this->create_radio_button(this, &buttons[2], 380, a,
                                           30, 30, 0, 0)) {
                return;
            }
            buttons[2]->set_help_info(IDS_HELP_DIPLOMACY_ENEMY, -1);

            for (i = 0; i < 3; ++i) {
                buttons[i]->set_radio_info(buttons, 3);
                if (rge_base_game->prog_mode == 5) {
                    buttons[i]->set_disabled(1);
                }
            }

            unsigned char relation =
                rge_base_game->get_player()->relation(player_id);
            if (player_id == world->curr_player || relation == 0) {
                buttons[0]->set_radio_button();
            } else if (relation == 1) {
                buttons[1]->set_radio_button();
            } else {
                buttons[2]->set_radio_button();
            }
        }

        if (disable_buttons == 0) {
            if (!this->create_button(this, &this->woodTributeButton[row],
                                     -1, 0, 440, a, 40, 30,
                                     RGE_FONT_STANDARD, 0, 0)) {
                return;
            }
            if (!this->create_button(this, &this->foodTributeButton[row],
                                     -1, 0, 480, a, 40, 30,
                                     RGE_FONT_STANDARD, 0, 0)) {
                return;
            }
            if (!this->create_button(this, &this->goldTributeButton[row],
                                     -1, 0, 520, a, 40, 30,
                                     RGE_FONT_STANDARD, 0, 0)) {
                return;
            }
            if (!this->create_button(this, &this->stoneTributeButton[row],
                                     -1, 0, 560, a, 40, 30,
                                     RGE_FONT_STANDARD, 0, 0)) {
                return;
            }

            this->woodTributeButton[row]->set_picture(
                0, this->buttonPics, 0);
            this->foodTributeButton[row]->set_picture(
                0, this->buttonPics, 2);
            this->goldTributeButton[row]->set_picture(
                0, this->buttonPics, 3);
            this->stoneTributeButton[row]->set_picture(
                0, this->buttonPics, 1);

            this->woodTributeButton[row]->setDrawType(
                TButtonPanel::DrawPictureAndText);
            this->foodTributeButton[row]->setDrawType(
                TButtonPanel::DrawPictureAndText);
            this->goldTributeButton[row]->setDrawType(
                TButtonPanel::DrawPictureAndText);
            this->stoneTributeButton[row]->setDrawType(
                TButtonPanel::DrawPictureAndText);

            this->woodTributeButton[row]->set_help_info(
                IDS_HELP_DIPLOMACY_TRIBUTE_WOOD, -1);
            this->foodTributeButton[row]->set_help_info(
                IDS_HELP_DIPLOMACY_TRIBUTE_FOOD, -1);
            this->goldTributeButton[row]->set_help_info(
                IDS_HELP_DIPLOMACY_TRIBUTE_GOLD, -1);
            this->stoneTributeButton[row]->set_help_info(
                IDS_HELP_DIPLOMACY_TRIBUTE_STONE, -1);
        }

        ++player_id;
        ++row;
        a += 30;
    }

    if (!this->create_check_box(this, &this->allianceButton, 282, 327,
                                30, 30, 0, 0)) {
        return;
    }
    this->allianceButton->set_state(
        rge_base_game->get_player()->get_allied_victory());
    this->allianceButton->set_help_info(IDS_HELP_DIPLOMACY_ALLIED_VICTORY, -1);
    if (rge_base_game->prog_mode == 5) {
        this->allianceButton->set_disabled(1);
    }

    if (rge_base_game->prog_mode != 5) {
        if (!this->create_button(this, &this->okButton, IDS_BUTTON_OK, 0, 10,
                                 367, 190, 30, 0, 0, 0)) {
            return;
        }
        this->okButton->set_help_info(IDS_HELP_OK, -1);

        if (!this->create_button(this, &this->clearButton,
                                 IDS_DIPLOMACY_CLEAR_TRIBUTES, 0, 215,
                                 367, 190, 30, 0, 0, 0)) {
            return;
        }
        this->clearButton->set_help_info(IDS_HELP_DIPLOMACY_CLEAR_TRIBUTES, -1);
    }

    if (!this->create_button(this, &this->cancelButton, IDS_BUTTON_CANCEL, 0, 420,
                             367, 190, 30, 0, 0, 0)) {
        return;
    }
    this->cancelButton->set_help_info(IDS_HELP_CANCEL, -1);
    this->cancelButton->hotkey = VK_ESCAPE;
    this->cancelButton->hotkey_shift = 0;

    if (!this->create_button(this, &this->help_button, IDS_BUTTON_HELP, 0, 500,
                             327, 30, 30, 0, 0, 0)) {
        return;
    }

    sprintf(temp_str, "%ld", static_cast<long>(
        rge_base_game->get_player()->attributes[1] - this->woodTotal));
    if (!this->create_text(this, &this->playerWood, temp_str, 440,
                           this->cur_player_row * 30 + 80, 40, 30,
                           RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    sprintf(temp_str, "%ld", static_cast<long>(
        rge_base_game->get_player()->attributes[0] - this->foodTotal));
    if (!this->create_text(this, &this->playerFood, temp_str, 480,
                           this->cur_player_row * 30 + 80, 40, 30,
                           RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    sprintf(temp_str, "%ld", static_cast<long>(
        rge_base_game->get_player()->attributes[3] - this->goldTotal));
    if (!this->create_text(this, &this->playerGold, temp_str, 520,
                           this->cur_player_row * 30 + 80, 40, 30,
                           RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }
    sprintf(temp_str, "%ld", static_cast<long>(
        rge_base_game->get_player()->attributes[2] - this->stoneTotal));
    if (!this->create_text(this, &this->playerStone, temp_str, 560,
                           this->cur_player_row * 30 + 80, 40, 30,
                           RGE_FONT_STANDARD, 0, 1, 0)) {
        return;
    }

    RGE_Static_Object* market =
        rge_base_game->get_player()->objects->find_by_master_id(
            0x54, -1.0f, -1.0f, 1, 2, 0);
    if (market != 0) {
        this->tribute_flag = 1;
        this->needMarket->set_active(0);
        this->title[6]->set_active(1);
        this->playerWood->set_active(1);
        this->playerFood->set_active(1);
        this->playerGold->set_active(1);
        this->playerStone->set_active(1);
    } else {
        this->tribute_flag = 0;
        this->needMarket->set_active(1);
        this->title[6]->set_active(0);
        this->playerWood->set_active(0);
        this->playerFood->set_active(0);
        this->playerGold->set_active(0);
        this->playerStone->set_active(0);
    }

    if (static_cast<TRIBE_Player*>(rge_base_game->get_player())
            ->tech_tree->get_tech_state(0x1E) == 3) {
        this->title[6]->set_active(0);
    }

    this->check_gold();
    this->check_wood();
    this->check_food();
    this->check_stone();

    this->set_curr_child(this->okButton);
    if (this->okButton != 0) {
        tabList[tabCount] = this->okButton;
        ++tabCount;
    }
    if (this->clearButton != 0) {
        tabList[tabCount] = this->clearButton;
        ++tabCount;
    }
    if (this->cancelButton != 0) {
        tabList[tabCount] = this->cancelButton;
        ++tabCount;
    }
    this->set_tab_order(tabList, static_cast<short>(tabCount));
}

TribeDiplomacyDialog::~TribeDiplomacyDialog() {
    int i;

    for (i = 0; i < 8; ++i) {
        if (this->title[i] != 0) {
            delete this->title[i];
        }
        if (this->playerVictoryScores[i] != 0) {
            delete this->playerVictoryScores[i];
        }
        if (this->playerName[i] != 0) {
            delete this->playerName[i];
        }
        if (this->playerCivilization[i] != 0) {
            delete this->playerCivilization[i];
        }
        if (this->woodTributeButton[i] != 0) {
            delete this->woodTributeButton[i];
        }
        if (this->foodTributeButton[i] != 0) {
            delete this->foodTributeButton[i];
        }
        if (this->goldTributeButton[i] != 0) {
            delete this->goldTributeButton[i];
        }
        if (this->stoneTributeButton[i] != 0) {
            delete this->stoneTributeButton[i];
        }
    }

    for (i = 0; i < 24; ++i) {
        if (this->allyButton[i] != 0) {
            delete this->allyButton[i];
        }
    }

    if (this->allianceButton != 0) {
        delete this->allianceButton;
    }
    if (this->okButton != 0) {
        delete this->okButton;
    }
    if (this->cancelButton != 0) {
        delete this->cancelButton;
    }
    if (this->clearButton != 0) {
        delete this->clearButton;
    }
    if (this->help_button != 0) {
        delete this->help_button;
    }
    if (this->playerFood != 0) {
        delete this->playerFood;
    }
    if (this->playerGold != 0) {
        delete this->playerGold;
    }
    if (this->playerWood != 0) {
        delete this->playerWood;
    }
    if (this->playerStone != 0) {
        delete this->playerStone;
    }
    if (this->needMarket != 0) {
        delete this->needMarket;
    }

    delete this->buttonPics;
    delete this->backgroundPics;
}

long TribeDiplomacyDialog::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    char temp_str[256];
    float cost;

    if (fromPanel == 0 || actionIn != 1) {
        return TPanel::action(fromPanel, actionIn, a1, a2);
    }

    if (fromPanel == this->okButton) {
        TRIBE_Command* tc =
            static_cast<TRIBE_Command*>(rge_base_game->world->commands);

        if (allow_user_commands != 0) {
            unsigned char allied_victory =
                rge_base_game->get_player()->get_allied_victory();
            if (this->allianceButton->get_state() != allied_victory) {
                int state = this->allianceButton->get_state();
                tc->command_allied_victory(
                    rge_base_game->get_player()->id,
                    static_cast<unsigned char>(state));
            }
        }

        RGE_Game_World* world = rge_base_game->world;
        if (world->player_num - 1 > 0) {
            int player_id = 1;
            int row = 0;
            do {
                if (player_id != world->curr_player &&
                    this->allyButton[row * 3] != 0) {
                    unsigned char relation;
                    if (this->allyButton[row * 3]->get_state() == 1) {
                        relation = 0;
                    } else if (this->allyButton[row * 3 + 1]->get_state() == 1) {
                        relation = 1;
                    } else {
                        relation = 3;
                    }

                    if (allow_user_commands != 0) {
                        if (rge_base_game->get_player()->relation(player_id) !=
                            relation) {
                            tc->command_relation(
                                rge_base_game->get_player()->id,
                                static_cast<short>(player_id),
                                static_cast<short>(relation));
                        }

                        if (this->goldTributeAmount[row] > 0.0f) {
                            TRIBE_Player* player = static_cast<TRIBE_Player*>(
                                rge_base_game->get_player());
                            player->command_give_attribute(
                                player_id, 3, this->goldTributeAmount[row],
                                rge_base_game->get_player()->attributes[46]);
                        }
                        if (this->woodTributeAmount[row] > 0.0f) {
                            TRIBE_Player* player = static_cast<TRIBE_Player*>(
                                rge_base_game->get_player());
                            player->command_give_attribute(
                                player_id, 1, this->woodTributeAmount[row],
                                rge_base_game->get_player()->attributes[46]);
                        }
                        if (this->foodTributeAmount[row] > 0.0f) {
                            TRIBE_Player* player = static_cast<TRIBE_Player*>(
                                rge_base_game->get_player());
                            player->command_give_attribute(
                                player_id, 0, this->foodTributeAmount[row],
                                rge_base_game->get_player()->attributes[46]);
                        }
                        if (this->stoneTributeAmount[row] > 0.0f) {
                            TRIBE_Player* player = static_cast<TRIBE_Player*>(
                                rge_base_game->get_player());
                            player->command_give_attribute(
                                player_id, 2, this->stoneTributeAmount[row],
                                rge_base_game->get_player()->attributes[46]);
                        }
                    }
                }

                ++row;
                ++player_id;
                world = rge_base_game->world;
            } while (player_id < world->player_num);
        }

        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Diplomacy Dialog");
        return 1;
    }

    if (fromPanel == this->cancelButton) {
        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Diplomacy Dialog");
        return 1;
    }

    if (fromPanel == this->help_button) {
        this->setup_popup_help();
        return 1;
    }

    if (fromPanel == this->clearButton) {
        this->foodTotal = 0.0f;
        this->goldTotal = 0.0f;
        this->stoneTotal = 0.0f;
        this->woodTotal = 0.0f;

        for (int i = 0; i < 8; ++i) {
            if (this->goldTributeButton[i] != 0) {
                this->goldTributeButton[i]->set_text(0, "");
            }
            if (this->foodTributeButton[i] != 0) {
                this->foodTributeButton[i]->set_text(0, "");
            }
            if (this->woodTributeButton[i] != 0) {
                this->woodTributeButton[i]->set_text(0, "");
            }
            if (this->stoneTributeButton[i] != 0) {
                this->stoneTributeButton[i]->set_text(0, "");
            }
            this->goldTributeAmount[i] = 0.0f;
            this->foodTributeAmount[i] = 0.0f;
            this->stoneTributeAmount[i] = 0.0f;
            this->woodTributeAmount[i] = 0.0f;
        }

        sprintf(temp_str, "%ld", static_cast<long>(
            rge_base_game->get_player()->attributes[3]));
        this->playerGold->set_text(temp_str);
        sprintf(temp_str, "%ld", static_cast<long>(
            rge_base_game->get_player()->attributes[0]));
        this->playerFood->set_text(temp_str);
        sprintf(temp_str, "%ld", static_cast<long>(
            rge_base_game->get_player()->attributes[1]));
        this->playerWood->set_text(temp_str);
        sprintf(temp_str, "%ld", static_cast<long>(
            rge_base_game->get_player()->attributes[2]));
        this->playerStone->set_text(temp_str);

        this->check_gold();
        this->check_wood();
        this->check_stone();
        this->check_food();
        return 1;
    }

    cost = 0.0f;
    if (rge_base_game->get_player()->attributes[46] > 0.0) {
        cost = rge_base_game->get_player()->attributes[46];
    }

    int player_count = rge_base_game->world->player_num - 1;
    for (int row = 0; row < player_count; ++row) {
        if (fromPanel == this->goldTributeButton[row]) {
            if (this->check_gold() == 0) {
                cost += 1.0f;
                if (!(rge_base_game->get_player()->attributes[3] -
                          this->goldTotal <
                      cost * 100.0f)) {
                    this->goldTributeAmount[row] += 100.0f;
                    this->goldTotal += cost * 100.0f;
                } else {
                    float amount =
                        (rge_base_game->get_player()->attributes[3] -
                         this->goldTotal) /
                        cost;
                    this->goldTributeAmount[row] += amount;
                    this->goldTotal += amount * cost;
                }

                sprintf(temp_str, "%ld", static_cast<long>(
                    rge_base_game->get_player()->attributes[3] -
                    this->goldTotal));
                this->playerGold->set_text(temp_str);
                sprintf(temp_str, "%ld", static_cast<long>(
                    this->goldTributeAmount[row]));
                this->goldTributeButton[row]->set_text(0, temp_str);
            } else {
                float available =
                    rge_base_game->get_player()->attributes[3] - this->goldTotal;
                if (!(available >= 0.0f)) {
                    available = 0.0f;
                }
                sprintf(temp_str, "%ld", static_cast<long>(available));
                this->playerGold->set_text(temp_str);
            }
            this->check_gold();
            return 1;
        }

        if (fromPanel == this->woodTributeButton[row]) {
            if (this->check_wood() == 0) {
                cost += 1.0f;
                if (!(rge_base_game->get_player()->attributes[1] -
                          this->woodTotal <
                      cost * 100.0f)) {
                    this->woodTributeAmount[row] += 100.0f;
                    this->woodTotal += cost * 100.0f;
                } else {
                    float amount =
                        (rge_base_game->get_player()->attributes[1] -
                         this->woodTotal) /
                        cost;
                    this->woodTributeAmount[row] += amount;
                    this->woodTotal += amount * cost;
                }

                sprintf(temp_str, "%ld", static_cast<long>(
                    rge_base_game->get_player()->attributes[1] -
                    this->woodTotal));
                this->playerWood->set_text(temp_str);
                sprintf(temp_str, "%ld", static_cast<long>(
                    this->woodTributeAmount[row]));
                this->woodTributeButton[row]->set_text(0, temp_str);
            } else {
                float available =
                    rge_base_game->get_player()->attributes[1] - this->woodTotal;
                if (!(available >= 0.0f)) {
                    available = 0.0f;
                }
                sprintf(temp_str, "%ld", static_cast<long>(available));
                this->playerWood->set_text(temp_str);
            }
            this->check_wood();
            return 1;
        }

        if (fromPanel == this->foodTributeButton[row]) {
            if (this->check_food() == 0) {
                cost += 1.0f;
                if (!(rge_base_game->get_player()->attributes[0] -
                          this->foodTotal <
                      cost * 100.0f)) {
                    this->foodTributeAmount[row] += 100.0f;
                    this->foodTotal += cost * 100.0f;
                } else {
                    float amount =
                        (rge_base_game->get_player()->attributes[0] -
                         this->foodTotal) /
                        cost;
                    this->foodTributeAmount[row] += amount;
                    this->foodTotal += amount * cost;
                }

                sprintf(temp_str, "%ld", static_cast<long>(
                    rge_base_game->get_player()->attributes[0] -
                    this->foodTotal));
                this->playerFood->set_text(temp_str);
                sprintf(temp_str, "%ld", static_cast<long>(
                    this->foodTributeAmount[row]));
                this->foodTributeButton[row]->set_text(0, temp_str);
            } else {
                float available =
                    rge_base_game->get_player()->attributes[0] - this->foodTotal;
                if (!(available >= 0.0f)) {
                    available = 0.0f;
                }
                sprintf(temp_str, "%ld", static_cast<long>(available));
                this->playerFood->set_text(temp_str);
            }
            this->check_food();
            return 1;
        }

        if (fromPanel == this->stoneTributeButton[row]) {
            if (this->check_stone() == 0) {
                cost += 1.0f;
                if (!(rge_base_game->get_player()->attributes[2] -
                          this->stoneTotal <
                      cost * 100.0f)) {
                    this->stoneTributeAmount[row] += 100.0f;
                    this->stoneTotal += cost * 100.0f;
                } else {
                    float amount =
                        (rge_base_game->get_player()->attributes[2] -
                         this->stoneTotal) /
                        cost;
                    this->stoneTributeAmount[row] += amount;
                    this->stoneTotal += amount * cost;
                }

                sprintf(temp_str, "%ld", static_cast<long>(
                    rge_base_game->get_player()->attributes[2] -
                    this->stoneTotal));
                this->playerStone->set_text(temp_str);
                sprintf(temp_str, "%ld", static_cast<long>(
                    this->stoneTributeAmount[row]));
                this->stoneTributeButton[row]->set_text(0, temp_str);
            } else {
                float available =
                    rge_base_game->get_player()->attributes[2] - this->stoneTotal;
                if (!(available >= 0.0f)) {
                    available = 0.0f;
                }
                sprintf(temp_str, "%ld", static_cast<long>(available));
                this->playerStone->set_text(temp_str);
            }
            this->check_stone();
            return 1;
        }
    }

    return TPanel::action(fromPanel, actionIn, a1, a2);
}

int TribeDiplomacyDialog::check_gold() {
    int gold_ok;

    if (rge_base_game->prog_mode != 5) {
        RGE_Player* player = rge_base_game->get_player();
        if (player->attributes[3] - this->goldTotal <= 0.0f) {
            gold_ok = 1;
        } else {
            gold_ok = 0;
        }
    } else {
        gold_ok = 1;
    }

    for (int i = 0; i < 8; ++i) {
        TButtonPanel* button = this->goldTributeButton[i];
        if (button != 0) {
            if (i == this->cur_player_row) {
                button->set_disabled(1);
            } else {
                button->set_disabled(gold_ok);
            }
            button = this->goldTributeButton[i];
            if (this->tribute_flag != 0) {
                button->set_active(1);
            } else {
                button->set_active(0);
            }
        }
    }

    return gold_ok;
}

int TribeDiplomacyDialog::check_wood() {
    int result;

    if (rge_base_game->prog_mode == 5) {
        result = 1;
    } else {
        RGE_Player* player = rge_base_game->get_player();
        float available = player->attributes[1] - this->woodTotal;
        if (available > 0.0f) {
            result = 0;
        } else {
            result = 1;
        }
    }

    int i = 0;
    do {
        TButtonPanel* button = this->woodTributeButton[i];
        if (button != 0) {
            if (i == this->cur_player_row) {
                button->set_disabled(1);
            } else {
                button->set_disabled(result);
            }

            button = this->woodTributeButton[i];
            if (this->tribute_flag != 0) {
                button->set_active(1);
            } else {
                button->set_active(0);
            }
        }
        ++i;
    } while (i < 8);

    return result;
}

int TribeDiplomacyDialog::check_food() {
    int has_food;
    int i;
    TButtonPanel** buttons;
    RGE_Player* player;

    if (rge_base_game->prog_mode == 5) {
        has_food = 1;
    } else {
        player = rge_base_game->get_player();
        if (player->attributes[0] - this->foodTotal > 0.0f) {
            has_food = 0;
        } else {
            has_food = 1;
        }
    }

    i = 0;
    buttons = this->foodTributeButton;
    do {
        if (*buttons != 0) {
            if (i == this->cur_player_row) {
                (*buttons)->set_disabled(1);
            } else {
                (*buttons)->set_disabled(has_food);
            }

            if (this->tribute_flag != 0) {
                (*buttons)->set_active(1);
            } else {
                (*buttons)->set_active(0);
            }
        }
        ++i;
        ++buttons;
    } while (i < 8);

    return has_food;
}

int TribeDiplomacyDialog::check_stone() {
    int result;
    int i;
    TButtonPanel** buttons;
    RGE_Player* player;

    if (rge_base_game->prog_mode == 5) {
        result = 1;
    } else {
        player = rge_base_game->get_player();
        if (player->attributes[2] - this->stoneTotal > 0.0f) {
            result = 0;
        } else {
            result = 1;
        }
    }

    i = 0;
    buttons = this->stoneTributeButton;
    do {
        if (*buttons != 0) {
            if (i == this->cur_player_row) {
                (*buttons)->set_disabled(1);
            } else {
                (*buttons)->set_disabled(result);
            }

            if (this->tribute_flag != 0) {
                (*buttons)->set_active(1);
            } else {
                (*buttons)->set_active(0);
            }
        }
        ++i;
        ++buttons;
    } while (i < 8);

    return result;
}

void TribeDiplomacyDialog::draw() {
    int y;

    TEasy_Panel::draw();
    y = 0;
    if (this->backgroundPics != 0) {
        RGE_Game_World* world = rge_base_game->world;
        this->draw_setup(0);

        if (world->player_num - 1 > 0) {
            int i = 0;
            do {
                RGE_Player* player = world->players[i + 1];
                RGE_Color_Table* colors = player->color_table;
                if (colors != 0) {
                    ASMSet_Color_Xform((colors->id + 1) * 16);
                    this->backgroundPics->shape_draw(
                        this->render_area,
                        this->pnl_x + 10,
                        this->pnl_y + y + 80,
                        0, 1, world->players[i + 1]->color_table->table);
                }
                y += 30;
                ++i;
            } while (i < world->player_num - 1);
        }

        this->draw_finish();
    }
}
