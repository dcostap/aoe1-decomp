// PDB source order: dlg_dip.cpp lines 77-903.
// This file owns every normal function in the compiland.

#include "../include/dlg_dip.h"
#include "../include/tcommand.h"
#include "../include/com_hand.h"
#include "../include/game_globals.h"
#include "../include/chat.h"
#include "../include/debuglog.h"
#include "../include/pnl_lst.h"
#include <stdio.h>

TribeDiplomacyDialog::TribeDiplomacyDialog(TScreenPanel* parent)
    : TDialogPanel("Diplomacy Dialog")
{
    int y;
    RGE_Game_World* world;
    int humanity;
    int player_id;
    int i;
    int disable_buttons;
    tagPALETTEENTRY palette_color;
    char temp_str[100];
    TPanel* tab_list[35];
    int tab_count = 0;

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

    if (this->setup(parent->renderArea(), parent, 0x271, 0x195,
                    parent->get_popup_info_file(), parent->get_popup_info_id(), 1) == 0) {
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
    if (this->create_text(this, &this->title[0], 0x267B,
                          0x48, 5, 0x1F4, 0x1E, 1, 1, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->needMarket, 0x2687,
                          0x1B8, 0x6E, 0xAF, 0x3C, 0x0B, 1, 1, 1) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[1], 0x2686,
                          5, 0x32, 0x82, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[2], 0x267C,
                          0x89, 0x32, 0x50, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[3], 0x267D,
                          0xEB, 0x32, 0x46, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[4], 0x267E,
                          0x122, 0x32, 0x46, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[5], 0x267F,
                          0x168, 0x32, 0x46, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }

    sprintf(temp_str, this->get_string(0x2680),
            static_cast<long>(rge_base_game->get_player()->attributes[46] *
                              100.0f));
    if (this->create_text(this, &this->title[6], temp_str,
                          0x1B8, 0x32, 0xB4, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->title[7], 0x2681,
                          0x13E, 0x14A, 300, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }

    this->cur_player_row = -1;
    world = rge_base_game->world;
    if (world->player_num - 1 > 0) {
        y = 0x50;
        for (player_id = 1; player_id < world->player_num; ++player_id, y += 0x1E) {
            const int row = player_id - 1;
            RGE_Player* player = world->players[player_id];

            GetPaletteEntries(this->palette, player->color_table->id,
                              1, &palette_color);
            disable_buttons = 0;

            if (rge_base_game->prog_mode == 5 ||
                player_id == world->curr_player || player->game_status != 0) {
                humanity = 1;
            } else {
                humanity = 0;
            }

            if (player_id == world->curr_player) {
                this->cur_player_row = row;
            }

            if (player->game_status == 2) {
                disable_buttons = 1;
            } else if (rge_base_game->multiplayerGame()) {
                int humanity_result = 0;
                int j = 1;
                int humanity_count = rge_base_game->numberPlayers();
                if (j <= humanity_count) {
                    do {
                        if (rge_base_game->playerID(j) == player_id) {
                            int h = comm->GetPlayerHumanity(j);
                            if (h == 2 || h == 4) {
                                humanity_result = h;
                            }
                        }
                        ++j;
                        humanity_count = rge_base_game->numberPlayers();
                    } while (j <= humanity_count);
                }
                if (humanity_result != 2 && humanity_result != 4) {
                    disable_buttons = 1;
                }
            }

            if (this->create_text(this, &this->playerName[row], player->name,
                                  5, y, 0x82, 0x1E,
                                  disable_buttons ? 8 : 0x0B, 0, 1, 0) == 0) {
                return;
            }
            rge_base_game->get_string2(0x69, player->master_player_id, 0,
                                       temp_str, 100);
            if (this->create_text(this, &this->playerCivilization[row], temp_str,
                                  0x89, y, 0x64, 0x1E, 0x0B, 0, 1, 0) == 0) {
                return;
            }

            if (player_id != world->curr_player) {
                TButtonPanel** group = &this->allyButton[row * 3];
                if (this->create_radio_button(this, &group[0],
                                              0xF0, y, 0x1E, 0x1E, 0, 0) == 0) {
                    return;
                }
                group[0]->set_help_info(0x7684, -1);
                if (this->create_radio_button(this, &group[1],
                                              0x136, y, 0x1E, 0x1E, 0, 0) == 0) {
                    return;
                }
                group[1]->set_help_info(0x7685, -1);
                if (this->create_radio_button(this, &group[2],
                                              0x17C, y, 0x1E, 0x1E, 0, 0) == 0) {
                    return;
                }
                group[2]->set_help_info(0x7686, -1);

                for (i = 0; i < 3; ++i) {
                    group[i]->set_radio_info(group, 3);
                    if (rge_base_game->prog_mode == 5) {
                        group[i]->set_disabled(1);
                    }
                }

                unsigned char relation =
                    rge_base_game->get_player()->relation(player_id);
                if (relation == 0) {
                    group[0]->set_radio_button();
                } else if (relation == 1) {
                    group[1]->set_radio_button();
                } else {
                    group[2]->set_radio_button();
                }
            }

            if (humanity == 0) {
                if (this->create_button(this, &this->woodTributeButton[row],
                                        -1, 0, 0x1B8, y, 0x28, 0x1E,
                                        0x0B, 0, 0) == 0) {
                    return;
                }
                if (this->create_button(this, &this->foodTributeButton[row],
                                        -1, 0, 0x1E0, y, 0x28, 0x1E,
                                        0x0B, 0, 0) == 0) {
                    return;
                }
                if (this->create_button(this, &this->goldTributeButton[row],
                                        -1, 0, 0x208, y, 0x28, 0x1E,
                                        0x0B, 0, 0) == 0) {
                    return;
                }
                if (this->create_button(this, &this->stoneTributeButton[row],
                                        -1, 0, 0x230, y, 0x28, 0x1E,
                                        0x0B, 0, 0) == 0) {
                    return;
                }

                this->woodTributeButton[row]->set_picture(0, this->buttonPics, 0);
                this->foodTributeButton[row]->set_picture(0, this->buttonPics, 2);
                this->goldTributeButton[row]->set_picture(0, this->buttonPics, 3);
                this->stoneTributeButton[row]->set_picture(0, this->buttonPics, 1);
                this->woodTributeButton[row]->setDrawType(
                    TButtonPanel::DrawPictureAndText);
                this->foodTributeButton[row]->setDrawType(
                    TButtonPanel::DrawPictureAndText);
                this->goldTributeButton[row]->setDrawType(
                    TButtonPanel::DrawPictureAndText);
                this->stoneTributeButton[row]->setDrawType(
                    TButtonPanel::DrawPictureAndText);
                this->woodTributeButton[row]->set_help_info(0x7687, -1);
                this->foodTributeButton[row]->set_help_info(0x7688, -1);
                this->goldTributeButton[row]->set_help_info(0x7689, -1);
                this->stoneTributeButton[row]->set_help_info(0x768A, -1);
            }
        }
    }

    if (this->create_check_box(this, &this->allianceButton,
                               0x11A, 0x147, 0x1E, 0x1E, 0, 0) == 0) {
        return;
    }
    this->allianceButton->set_state(
        rge_base_game->get_player()->get_allied_victory());
    this->allianceButton->set_help_info(0x768C, -1);
    if (rge_base_game->prog_mode == 5) {
        this->allianceButton->set_disabled(1);
    }

    if (rge_base_game->prog_mode != 5) {
        if (this->create_button(this, &this->okButton,
                                0xFA1, 0, 0x0A, 0x16F, 0xBE, 0x1E,
                                0, 0, 0) == 0) {
            return;
        }
        this->okButton->set_help_info(0x7531, -1);
        if (this->create_button(this, &this->clearButton,
                                0x2683, 0, 0xD7, 0x16F, 0xBE, 0x1E,
                                0, 0, 0) == 0) {
            return;
        }
        this->clearButton->set_help_info(0x768B, -1);
    }

    if (this->create_button(this, &this->cancelButton,
                            0xFA2, 0, 0x1A4, 0x16F, 0xBE, 0x1E,
                            0, 0, 0) == 0) {
        return;
    }
    this->cancelButton->set_help_info(0x7532, -1);
    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;

    if (this->create_button(this, &this->help_button,
                            0xFA9, 0, 0x1F4, 0x147, 0x1E, 0x1E,
                            0, 0, 0) == 0) {
        return;
    }

    sprintf(temp_str, "%ld",
            static_cast<long>(rge_base_game->get_player()->attributes[1] -
                              this->woodTotal));
    if (this->create_text(this, &this->playerWood, temp_str,
                          0x1B8, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    sprintf(temp_str, "%ld",
            static_cast<long>(rge_base_game->get_player()->attributes[0] -
                              this->foodTotal));
    if (this->create_text(this, &this->playerFood, temp_str,
                          0x1E0, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    sprintf(temp_str, "%ld",
            static_cast<long>(rge_base_game->get_player()->attributes[3] -
                              this->goldTotal));
    if (this->create_text(this, &this->playerGold, temp_str,
                          0x208, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }
    sprintf(temp_str, "%ld",
            static_cast<long>(rge_base_game->get_player()->attributes[2] -
                              this->stoneTotal));
    if (this->create_text(this, &this->playerStone, temp_str,
                          0x230, this->cur_player_row * 0x1E + 0x50,
                          0x28, 0x1E, 0x0B, 0, 1, 0) == 0) {
        return;
    }

    RGE_Static_Object* market =
        rge_base_game->get_player()->objects->find_by_master_id(
            0x54, -1.0f, -1.0f, 1, 2, 0);
    if (market == 0) {
        this->tribute_flag = 0;
        this->needMarket->set_active(1);
        this->title[6]->set_active(0);
        this->playerWood->set_active(0);
        this->playerFood->set_active(0);
        this->playerGold->set_active(0);
        this->playerStone->set_active(0);
    } else {
        this->tribute_flag = 1;
        this->needMarket->set_active(0);
        this->title[6]->set_active(1);
        this->playerWood->set_active(1);
        this->playerFood->set_active(1);
        this->playerGold->set_active(1);
        this->playerStone->set_active(1);
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
        tab_list[tab_count++] = this->okButton;
    }
    if (this->clearButton != 0) {
        tab_list[tab_count++] = this->clearButton;
    }
    if (this->cancelButton != 0) {
        tab_list[tab_count++] = this->cancelButton;
    }
    this->set_tab_order(tab_list, static_cast<short>(tab_count));
}

TribeDiplomacyDialog::~TribeDiplomacyDialog()
{
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
        if (this->goldTributeButton[i] != 0) {
            delete this->goldTributeButton[i];
        }
        if (this->woodTributeButton[i] != 0) {
            delete this->woodTributeButton[i];
        }
        if (this->foodTributeButton[i] != 0) {
            delete this->foodTributeButton[i];
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

long TribeDiplomacyDialog::action(TPanel* panel, long event,
                                  unsigned long param_3, unsigned long param_4)
{
    char temp_str[256];

    if (panel != 0) {
        if (event == 1) {
            if (panel == this->okButton) {
                TRIBE_Command* commands = static_cast<TRIBE_Command*>(
                    rge_base_game->world->commands);
                if (allow_user_commands != 0) {
                    unsigned char allied =
                        rge_base_game->get_player()->get_allied_victory();
                    if (this->allianceButton->get_state() != allied) {
                        commands->command_allied_victory(
                            rge_base_game->get_player()->id,
                            this->allianceButton->get_state());
                    }
                }

                int player_id = 1;
                if (rge_base_game->world->player_num - 1 > 0) {
                    for (int row = 0;
                         row < rge_base_game->world->player_num - 1;
                         ++row, ++player_id) {
                        if (player_id != rge_base_game->world->curr_player &&
                            this->allyButton[row * 3] != 0) {
                            unsigned char relation;
                            if (this->allyButton[row * 3]->get_state() == 1) {
                                relation = 0;
                            } else if (this->allyButton[row * 3 + 1]->get_state() != 1) {
                                relation = 3;
                            } else {
                                relation = 1;
                            }

                            if (allow_user_commands != 0) {
                                if (rge_base_game->get_player()->relation(player_id) != relation) {
                                    commands->command_relation(
                                        rge_base_game->get_player()->id,
                                        static_cast<short>(player_id),
                                        static_cast<short>(relation));
                                }

                                if (this->goldTributeAmount[row] > 0.0f) {
                                    static_cast<TRIBE_Player*>(
                                        rge_base_game->get_player())
                                        ->command_give_attribute(
                                            player_id, 3,
                                            this->goldTributeAmount[row],
                                            rge_base_game->get_player()->attributes[0x2e]);
                                }
                                if (this->woodTributeAmount[row] > 0.0f) {
                                    static_cast<TRIBE_Player*>(
                                        rge_base_game->get_player())
                                        ->command_give_attribute(
                                            player_id, 1,
                                            this->woodTributeAmount[row],
                                            rge_base_game->get_player()->attributes[0x2e]);
                                }
                                if (this->foodTributeAmount[row] > 0.0f) {
                                    static_cast<TRIBE_Player*>(
                                        rge_base_game->get_player())
                                        ->command_give_attribute(
                                            player_id, 0,
                                            this->foodTributeAmount[row],
                                            rge_base_game->get_player()->attributes[0x2e]);
                                }
                                if (this->stoneTributeAmount[row] > 0.0f) {
                                    static_cast<TRIBE_Player*>(
                                        rge_base_game->get_player())
                                        ->command_give_attribute(
                                            player_id, 2,
                                            this->stoneTributeAmount[row],
                                            rge_base_game->get_player()->attributes[0x2e]);
                                }
                            }
                        }
                    }
                }

                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                    panel_system.setCurrentPanel("Game Screen", 0);
                    panel_system.destroyPanel("Diplomacy Dialog");
                    return 1;
                }
                goto close_dialog;
            }

            if (panel == this->cancelButton) {
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
                goto close_dialog;
            }

            if (panel == this->help_button) {
                this->setup_popup_help();
                return 1;
            }

            if (panel == this->clearButton) {
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

                sprintf(temp_str, "%ld",
                        static_cast<long>(rge_base_game->get_player()->attributes[3]));
                this->playerGold->set_text(temp_str);
                sprintf(temp_str, "%ld",
                        static_cast<long>(rge_base_game->get_player()->attributes[0]));
                this->playerFood->set_text(temp_str);
                sprintf(temp_str, "%ld",
                        static_cast<long>(rge_base_game->get_player()->attributes[1]));
                this->playerWood->set_text(temp_str);
                sprintf(temp_str, "%ld",
                        static_cast<long>(rge_base_game->get_player()->attributes[2]));
                this->playerStone->set_text(temp_str);
                this->check_gold();
                this->check_wood();
                this->check_stone();
                this->check_food();
                return 1;
            }

            float cost = 0.0f;
            if (rge_base_game->get_player()->attributes[0x2e] > 0.0) {
                cost = rge_base_game->get_player()->attributes[0x2e];
            }

            int player_count = rge_base_game->world->player_num - 1;
            for (int index = 0; index < player_count; ++index) {
                const int player_id = index + 1;

                if (panel == this->goldTributeButton[index]) {
                    if (this->check_gold() == 0) {
                        cost = cost - -1.0f;
                        if (rge_base_game->get_player()->attributes[3] -
                                this->goldTotal >= cost * 100.0f) {
                            this->goldTributeAmount[index] =
                                this->goldTributeAmount[index] - -100.0f;
                            this->goldTotal =
                                this->goldTotal - cost * -100.0f;
                        } else {
                            float amount =
                                (rge_base_game->get_player()->attributes[3] -
                                 this->goldTotal) / cost;
                            this->goldTributeAmount[index] =
                                amount + this->goldTributeAmount[index];
                            this->goldTotal = amount * cost + this->goldTotal;
                        }
                        sprintf(temp_str, "%ld",
                                static_cast<long>(
                                    rge_base_game->get_player()->attributes[3] -
                                    this->goldTotal));
                        this->playerGold->set_text(temp_str);
                        sprintf(temp_str, "%ld",
                                static_cast<long>(this->goldTributeAmount[index]));
                        this->goldTributeButton[index]->set_text(0, temp_str);
                        this->check_gold();
                        return 1;
                    }
                    sprintf(temp_str, "%ld",
                            static_cast<long>(
                                rge_base_game->get_player()->attributes[3] -
                                this->goldTotal));
                    this->playerGold->set_text(temp_str);
                    this->check_gold();
                    return 1;
                }

                if (panel == this->woodTributeButton[index]) {
                    if (this->check_wood() == 0) {
                        cost = cost - -1.0f;
                        if (rge_base_game->get_player()->attributes[4] -
                                this->woodTotal >= cost * 100.0f) {
                            this->woodTributeAmount[index] =
                                this->woodTributeAmount[index] - -100.0f;
                            this->woodTotal =
                                this->woodTotal - cost * -100.0f;
                        } else {
                            float amount =
                                (rge_base_game->get_player()->attributes[4] -
                                 this->woodTotal) / cost;
                            this->woodTributeAmount[index] =
                                amount + this->woodTributeAmount[index];
                            this->woodTotal = amount * cost + this->woodTotal;
                        }
                        sprintf(temp_str, "%ld",
                                static_cast<long>(
                                    rge_base_game->get_player()->attributes[4] -
                                    this->woodTotal));
                        this->playerWood->set_text(temp_str);
                        sprintf(temp_str, "%ld",
                                static_cast<long>(this->woodTributeAmount[index]));
                        this->woodTributeButton[index]->set_text(0, temp_str);
                        this->check_wood();
                        return 1;
                    }
                    sprintf(temp_str, "%ld",
                            static_cast<long>(
                                rge_base_game->get_player()->attributes[4] -
                                this->woodTotal));
                    this->playerWood->set_text(temp_str);
                    this->check_wood();
                    return 1;
                }

                if (panel == this->foodTributeButton[index]) {
                    if (this->check_food() == 0) {
                        cost = cost - -1.0f;
                        if (rge_base_game->get_player()->attributes[0] -
                                this->foodTotal >= cost * 100.0f) {
                            this->foodTributeAmount[index] =
                                this->foodTributeAmount[index] - -100.0f;
                            this->foodTotal =
                                this->foodTotal - cost * -100.0f;
                        } else {
                            float amount =
                                (rge_base_game->get_player()->attributes[0] -
                                 this->foodTotal) / cost;
                            this->foodTributeAmount[index] =
                                amount + this->foodTributeAmount[index];
                            this->foodTotal = amount * cost + this->foodTotal;
                        }
                        sprintf(temp_str, "%ld",
                                static_cast<long>(
                                    rge_base_game->get_player()->attributes[0] -
                                    this->foodTotal));
                        this->playerFood->set_text(temp_str);
                        sprintf(temp_str, "%ld",
                                static_cast<long>(this->foodTributeAmount[index]));
                        this->foodTributeButton[index]->set_text(0, temp_str);
                        this->check_food();
                        return 1;
                    }
                    sprintf(temp_str, "%ld",
                            static_cast<long>(
                                rge_base_game->get_player()->attributes[0] -
                                this->foodTotal));
                    this->playerFood->set_text(temp_str);
                    this->check_food();
                    return 1;
                }

                if (panel == this->stoneTributeButton[index]) {
                    if (this->check_stone() == 0) {
                        cost = cost - -1.0f;
                        if (rge_base_game->get_player()->attributes[2] -
                                this->stoneTotal >= cost * 100.0f) {
                            this->stoneTributeAmount[index] =
                                this->stoneTributeAmount[index] - -100.0f;
                            this->stoneTotal =
                                this->stoneTotal - cost * -100.0f;
                        } else {
                            float amount =
                                (rge_base_game->get_player()->attributes[2] -
                                 this->stoneTotal) / cost;
                            this->stoneTributeAmount[index] =
                                amount + this->stoneTributeAmount[index];
                            this->stoneTotal = amount * cost + this->stoneTotal;
                        }
                        sprintf(temp_str, "%ld",
                                static_cast<long>(
                                    rge_base_game->get_player()->attributes[2] -
                                    this->stoneTotal));
                        this->playerStone->set_text(temp_str);
                        sprintf(temp_str, "%ld",
                                static_cast<long>(this->stoneTributeAmount[index]));
                        this->stoneTributeButton[index]->set_text(0, temp_str);
                        this->check_stone();
                        return 1;
                    }
                    sprintf(temp_str, "%ld",
                            static_cast<long>(
                                rge_base_game->get_player()->attributes[2] -
                                this->stoneTotal));
                    this->playerStone->set_text(temp_str);
                    this->check_stone();
                    return 1;
                }
            }
        }
    }

    return TPanel::action(panel, event, param_3, param_4);

close_dialog:
    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Diplomacy Dialog");
    return 1;
}

int TribeDiplomacyDialog::check_gold()
{
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

int TribeDiplomacyDialog::check_wood()
{
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

int TribeDiplomacyDialog::check_food()
{
    int has_food;

    if (rge_base_game->prog_mode == 5 ||
        (rge_base_game->get_player()->attributes[0] - this->foodTotal <= 0.0f)) {
        has_food = 1;
    } else {
        has_food = 0;
    }

    int i = 0;
    do {
        TButtonPanel* button = this->foodTributeButton[i];
        if (button != 0) {
            if (i == this->cur_player_row) {
                button->set_disabled(1);
            } else {
                button->set_disabled(has_food);
            }

            if (this->tribute_flag != 0) {
                button->set_active(1);
            } else {
                button->set_active(0);
            }
        }
        ++i;
    } while (i < 8);

    return has_food;
}

int TribeDiplomacyDialog::check_stone()
{
    int result;

    if (rge_base_game->prog_mode == 5) {
        result = 1;
    } else {
        RGE_Player* player = rge_base_game->get_player();
        if (player->attributes[2] - this->stoneTotal > 0.0f) {
            result = 0;
        } else {
            result = 1;
        }
    }

    int i = 0;
    do {
        TButtonPanel* button = this->stoneTributeButton[i];
        if (button != 0) {
            if (i == this->cur_player_row) {
                button->set_disabled(1);
            } else {
                button->set_disabled(result);
            }

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

void TribeDiplomacyDialog::draw()
{
    int y = 0;

    TEasy_Panel::draw();
    if (this->backgroundPics != 0) {
        RGE_Game_World* world = rge_base_game->world;
        this->draw_setup(0);

        for (int i = 1; i < world->player_num; ++i) {
            RGE_Player* player = world->players[i];
            RGE_Color_Table* colors = player->color_table;
            if (colors != 0) {
                _ASMSet_Color_Xform((colors->id + 1) * 16);
                this->backgroundPics->shape_draw(
                    this->render_area,
                    this->pnl_x + 0x0A,
                    this->pnl_y + y + 0x50,
                    0, 1, colors->table);
            }
            y += 0x1E;
        }

        this->draw_finish();
    }
}
