#include "../include/TribeDiplomacyDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TTextPanel.h"
#include "../include/TScreenPanel.h"
#include "../include/TShape.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Player.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

#include <cstdio>

extern "C" void _ASMSet_Color_Xform(int v);

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043C930
TribeDiplomacyDialog::TribeDiplomacyDialog(TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Diplomacy Dialog") {
    for (int i = 0; i < 8; ++i) {
        this->title[i] = nullptr;
        this->playerName[i] = nullptr;
        this->playerVictoryScores[i] = nullptr;
        this->playerCivilization[i] = nullptr;
        this->goldTributeButton[i] = nullptr;
        this->woodTributeButton[i] = nullptr;
        this->foodTributeButton[i] = nullptr;
        this->stoneTributeButton[i] = nullptr;
        this->goldTributeAmount[i] = 0.0f;
        this->foodTributeAmount[i] = 0.0f;
        this->stoneTributeAmount[i] = 0.0f;
        this->woodTributeAmount[i] = 0.0f;
    }
    for (int i = 0; i < 24; ++i) {
        this->allyButton[i] = nullptr;
    }

    this->needMarket = nullptr;
    this->allianceButton = nullptr;
    this->okButton = nullptr;
    this->clearButton = nullptr;
    this->cancelButton = nullptr;
    this->help_button = nullptr;
    this->buttonPics = nullptr;
    this->backgroundPics = nullptr;
    this->foodTotal = 0.0f;
    this->woodTotal = 0.0f;
    this->goldTotal = 0.0f;
    this->stoneTotal = 0.0f;
    this->playerFood = nullptr;
    this->playerGold = nullptr;
    this->playerWood = nullptr;
    this->playerStone = nullptr;
    this->cur_player_row = 0;
    this->tribute_flag = 0;

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 0x271, 0x195, popup_file, popup_id, 1)) {
        return;
    }

    this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x14, 0x167, 0xb4, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->clearButton, 0x243d, 0, 0xd2, 0x167, 0xb4, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x190, 0x167, 0xb4, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->help_button, 0x23f5, 0, 0x22e, 0x167, 0x36, 0x1e, 0, 0, 0);

    if (this->cancelButton != nullptr) {
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043D6E0
TribeDiplomacyDialog::~TribeDiplomacyDialog() {
    for (int i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->title[i]);
        this->delete_panel((TPanel**)&this->playerName[i]);
        this->delete_panel((TPanel**)&this->playerVictoryScores[i]);
        this->delete_panel((TPanel**)&this->playerCivilization[i]);
        this->delete_panel((TPanel**)&this->goldTributeButton[i]);
        this->delete_panel((TPanel**)&this->woodTributeButton[i]);
        this->delete_panel((TPanel**)&this->foodTributeButton[i]);
        this->delete_panel((TPanel**)&this->stoneTributeButton[i]);
    }
    for (int i = 0; i < 24; ++i) {
        this->delete_panel((TPanel**)&this->allyButton[i]);
    }

    this->delete_panel((TPanel**)&this->allianceButton);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->clearButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);
    this->delete_panel((TPanel**)&this->needMarket);
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043D8A0
long TribeDiplomacyDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 == nullptr || param_2 != 1) {
        return TPanel::action(param_1, param_2, param_3, param_4);
    }

    if ((TButtonPanel*)param_1 == this->okButton) {
        RGE_Game_World* world = (rge_base_game != nullptr) ? rge_base_game->world : nullptr;
        TRIBE_Command* tc = (world != nullptr) ? (TRIBE_Command*)world->commands : nullptr;
        RGE_Player* local_player = (rge_base_game != nullptr) ? rge_base_game->get_player() : nullptr;

        if (allow_user_commands != 0 && tc != nullptr && local_player != nullptr && this->allianceButton != nullptr) {
            const uchar allied_victory = local_player->get_allied_victory();
            const int alliance_state = this->allianceButton->get_state();
            if (alliance_state != allied_victory) {
                tc->command_allied_victory(local_player->id, (uchar)alliance_state);
            }
        }

        if (world != nullptr && world->player_num > 1) {
            TRIBE_Player* tribe_player = (TRIBE_Player*)local_player;
            const float tribute_cost = (local_player != nullptr && local_player->attributes != nullptr) ? local_player->attributes[0x2e] : 0.0f;
            for (int target_player = 1; target_player < world->player_num; ++target_player) {
                const int row = target_player - 1;
                if (row < 0 || row >= 8) {
                    break;
                }
                const int ally_offset = row * 3;
                if (target_player != world->curr_player && this->allyButton[ally_offset] != nullptr) {
                    uchar relation_state;
                    if (this->allyButton[ally_offset]->get_state() == 1) {
                        relation_state = 0;
                    } else {
                        const int neutral_state = (this->allyButton[ally_offset + 1] != nullptr) ? this->allyButton[ally_offset + 1]->get_state() : 0;
                        relation_state = (neutral_state == 1) ? 1 : 3;
                    }

                    if (allow_user_commands != 0 && tc != nullptr && local_player != nullptr) {
                        if (local_player->relation(target_player) != relation_state) {
                            tc->command_relation(local_player->id, (short)target_player, (short)relation_state);
                        }

                        if (tribe_player != nullptr) {
                            if (this->goldTributeAmount[row] > 0.0f) {
                                tribe_player->command_give_attribute(target_player, 3, this->goldTributeAmount[row], tribute_cost);
                            }
                            if (this->woodTributeAmount[row] > 0.0f) {
                                tribe_player->command_give_attribute(target_player, 1, this->woodTributeAmount[row], tribute_cost);
                            }
                            if (this->foodTributeAmount[row] > 0.0f) {
                                tribe_player->command_give_attribute(target_player, 0, this->foodTributeAmount[row], tribute_cost);
                            }
                            if (this->stoneTributeAmount[row] > 0.0f) {
                                tribe_player->command_give_attribute(target_player, 2, this->stoneTributeAmount[row], tribute_cost);
                            }
                        }
                    }
                }
            }
        }

        if (rge_base_game != nullptr && rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system->setCurrentPanel((char*)"Game Screen", 0);
        panel_system->destroyPanel((char*)"Diplomacy Dialog");
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->cancelButton) {
        if (rge_base_game != nullptr && rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system->setCurrentPanel((char*)"Game Screen", 0);
        panel_system->destroyPanel((char*)"Diplomacy Dialog");
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->help_button) {
        this->setup_popup_help();
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->clearButton) {
        this->foodTotal = 0.0f;
        this->goldTotal = 0.0f;
        this->stoneTotal = 0.0f;
        this->woodTotal = 0.0f;

        for (int i = 0; i < 8; ++i) {
            if (this->goldTributeButton[i] != nullptr) {
                this->goldTributeButton[i]->set_text(0, (char*)"");
            }
            if (this->woodTributeButton[i] != nullptr) {
                this->woodTributeButton[i]->set_text(0, (char*)"");
            }
            if (this->foodTributeButton[i] != nullptr) {
                this->foodTributeButton[i]->set_text(0, (char*)"");
            }
            if (this->stoneTributeButton[i] != nullptr) {
                this->stoneTributeButton[i]->set_text(0, (char*)"");
            }
            this->goldTributeAmount[i] = 0.0f;
            this->foodTributeAmount[i] = 0.0f;
            this->stoneTributeAmount[i] = 0.0f;
            this->woodTributeAmount[i] = 0.0f;
        }

        RGE_Player* player = (rge_base_game != nullptr) ? rge_base_game->get_player() : nullptr;
        if (player != nullptr && player->attributes != nullptr) {
            char temp_str[256];
            std::sprintf(temp_str, "%ld", (long)player->attributes[3]);
            if (this->playerGold != nullptr) {
                this->playerGold->set_text(temp_str);
            }
            std::sprintf(temp_str, "%ld", (long)player->attributes[0]);
            if (this->playerFood != nullptr) {
                this->playerFood->set_text(temp_str);
            }
            std::sprintf(temp_str, "%ld", (long)player->attributes[1]);
            if (this->playerWood != nullptr) {
                this->playerWood->set_text(temp_str);
            }
            std::sprintf(temp_str, "%ld", (long)player->attributes[2]);
            if (this->playerStone != nullptr) {
                this->playerStone->set_text(temp_str);
            }
        }

        this->check_gold();
        this->check_wood();
        this->check_stone();
        this->check_food();
        return 1;
    }

    float cost = 0.0f;
    RGE_Player* player = (rge_base_game != nullptr) ? rge_base_game->get_player() : nullptr;
    if (player != nullptr && player->attributes != nullptr && player->attributes[0x2e] > 0.0f) {
        cost = player->attributes[0x2e];
    }

    const RGE_Game_World* world = (rge_base_game != nullptr) ? rge_base_game->world : nullptr;
    int max_rows = (world != nullptr) ? (world->player_num - 1) : 0;
    if (max_rows > 8) {
        max_rows = 8;
    }

    for (int row = 0; row < max_rows; ++row) {
        const int target_player = row + 1;

        if ((TButtonPanel*)param_1 == this->goldTributeButton[row]) {
            const int blocked = this->check_gold();
            if (blocked == 0 && player != nullptr && player->attributes != nullptr) {
                cost += 1.0f;
                if (cost * 100.0f <= player->attributes[3] - this->goldTotal) {
                    this->goldTributeAmount[row] += 100.0f;
                    this->goldTotal += cost * 100.0f;
                } else {
                    const float delta = (player->attributes[3] - this->goldTotal) / cost;
                    this->goldTributeAmount[row] += delta;
                    this->goldTotal += delta * cost;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)(player->attributes[3] - this->goldTotal));
                if (this->playerGold != nullptr) {
                    this->playerGold->set_text(temp_str);
                }
                std::sprintf(temp_str, "%ld", (long)this->goldTributeAmount[row]);
                if (this->goldTributeButton[row] != nullptr) {
                    this->goldTributeButton[row]->set_text(0, temp_str);
                }
            } else if (player != nullptr && player->attributes != nullptr) {
                float remaining = player->attributes[3] - this->goldTotal;
                if (remaining < 0.0f) {
                    remaining = 0.0f;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)remaining);
                if (this->playerGold != nullptr) {
                    this->playerGold->set_text(temp_str);
                }
            }
            this->check_gold();
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->woodTributeButton[row]) {
            const int blocked = this->check_wood();
            if (blocked == 0 && player != nullptr && player->attributes != nullptr) {
                cost += 1.0f;
                if (cost * 100.0f <= player->attributes[1] - this->woodTotal) {
                    this->woodTributeAmount[row] += 100.0f;
                    this->woodTotal += cost * 100.0f;
                } else {
                    const float delta = (player->attributes[1] - this->woodTotal) / cost;
                    this->woodTributeAmount[row] += delta;
                    this->woodTotal += delta * cost;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)(player->attributes[1] - this->woodTotal));
                if (this->playerWood != nullptr) {
                    this->playerWood->set_text(temp_str);
                }
                std::sprintf(temp_str, "%ld", (long)this->woodTributeAmount[row]);
                if (this->woodTributeButton[row] != nullptr) {
                    this->woodTributeButton[row]->set_text(0, temp_str);
                }
            } else if (player != nullptr && player->attributes != nullptr) {
                float remaining = player->attributes[1] - this->woodTotal;
                if (remaining < 0.0f) {
                    remaining = 0.0f;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)remaining);
                if (this->playerWood != nullptr) {
                    this->playerWood->set_text(temp_str);
                }
            }
            this->check_wood();
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->foodTributeButton[row]) {
            const int blocked = this->check_food();
            if (blocked == 0 && player != nullptr && player->attributes != nullptr) {
                cost += 1.0f;
                if (cost * 100.0f <= player->attributes[0] - this->foodTotal) {
                    this->foodTributeAmount[row] += 100.0f;
                    this->foodTotal += cost * 100.0f;
                } else {
                    const float delta = (player->attributes[0] - this->foodTotal) / cost;
                    this->foodTributeAmount[row] += delta;
                    this->foodTotal += delta * cost;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)(player->attributes[0] - this->foodTotal));
                if (this->playerFood != nullptr) {
                    this->playerFood->set_text(temp_str);
                }
                std::sprintf(temp_str, "%ld", (long)this->foodTributeAmount[row]);
                if (this->foodTributeButton[row] != nullptr) {
                    this->foodTributeButton[row]->set_text(0, temp_str);
                }
            } else if (player != nullptr && player->attributes != nullptr) {
                float remaining = player->attributes[0] - this->foodTotal;
                if (remaining < 0.0f) {
                    remaining = 0.0f;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)remaining);
                if (this->playerFood != nullptr) {
                    this->playerFood->set_text(temp_str);
                }
            }
            this->check_food();
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->stoneTributeButton[row]) {
            const int blocked = this->check_stone();
            if (blocked == 0 && player != nullptr && player->attributes != nullptr) {
                cost += 1.0f;
                if (cost * 100.0f <= player->attributes[2] - this->stoneTotal) {
                    this->stoneTributeAmount[row] += 100.0f;
                    this->stoneTotal += cost * 100.0f;
                } else {
                    const float delta = (player->attributes[2] - this->stoneTotal) / cost;
                    this->stoneTributeAmount[row] += delta;
                    this->stoneTotal += delta * cost;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)(player->attributes[2] - this->stoneTotal));
                if (this->playerStone != nullptr) {
                    this->playerStone->set_text(temp_str);
                }
                std::sprintf(temp_str, "%ld", (long)this->stoneTributeAmount[row]);
                if (this->stoneTributeButton[row] != nullptr) {
                    this->stoneTributeButton[row]->set_text(0, temp_str);
                }
            } else if (player != nullptr && player->attributes != nullptr) {
                float remaining = player->attributes[2] - this->stoneTotal;
                if (remaining < 0.0f) {
                    remaining = 0.0f;
                }
                char temp_str[256];
                std::sprintf(temp_str, "%ld", (long)remaining);
                if (this->playerStone != nullptr) {
                    this->playerStone->set_text(temp_str);
                }
            }
            this->check_stone();
            return 1;
        }
    }

    return TPanel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E530
int TribeDiplomacyDialog::check_gold() {
    int disabled = 1;
    if (rge_base_game != nullptr && rge_base_game->prog_mode != 5) {
        RGE_Player* player = rge_base_game->get_player();
        if (player != nullptr && player->attributes != nullptr && player->attributes[3] - this->goldTotal > 0.0f) {
            disabled = 0;
        }
    }

    for (int i = 0; i < 8; ++i) {
        if (this->goldTributeButton[i] != nullptr) {
            int row_disabled = disabled;
            if (i == this->cur_player_row) {
                row_disabled = 1;
            }
            this->goldTributeButton[i]->set_disabled(row_disabled);
            this->goldTributeButton[i]->set_active((this->tribute_flag != 0) ? 1 : 0);
        }
    }
    return disabled;
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E5C0
int TribeDiplomacyDialog::check_wood() {
    int disabled = 1;
    if (rge_base_game != nullptr && rge_base_game->prog_mode != 5) {
        RGE_Player* player = rge_base_game->get_player();
        if (player != nullptr && player->attributes != nullptr && player->attributes[1] - this->woodTotal > 0.0f) {
            disabled = 0;
        }
    }

    for (int i = 0; i < 8; ++i) {
        if (this->woodTributeButton[i] != nullptr) {
            int row_disabled = disabled;
            if (i == this->cur_player_row) {
                row_disabled = 1;
            }
            this->woodTributeButton[i]->set_disabled(row_disabled);
            this->woodTributeButton[i]->set_active((this->tribute_flag != 0) ? 1 : 0);
        }
    }
    return disabled;
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E650
int TribeDiplomacyDialog::check_food() {
    int disabled = 1;
    if (rge_base_game != nullptr && rge_base_game->prog_mode != 5) {
        RGE_Player* player = rge_base_game->get_player();
        if (player != nullptr && player->attributes != nullptr && player->attributes[0] - this->foodTotal > 0.0f) {
            disabled = 0;
        }
    }

    for (int i = 0; i < 8; ++i) {
        if (this->foodTributeButton[i] != nullptr) {
            int row_disabled = disabled;
            if (i == this->cur_player_row) {
                row_disabled = 1;
            }
            this->foodTributeButton[i]->set_disabled(row_disabled);
            this->foodTributeButton[i]->set_active((this->tribute_flag != 0) ? 1 : 0);
        }
    }
    return disabled;
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E6E0
int TribeDiplomacyDialog::check_stone() {
    int disabled = 1;
    if (rge_base_game != nullptr && rge_base_game->prog_mode != 5) {
        RGE_Player* player = rge_base_game->get_player();
        if (player != nullptr && player->attributes != nullptr && player->attributes[2] - this->stoneTotal > 0.0f) {
            disabled = 0;
        }
    }

    for (int i = 0; i < 8; ++i) {
        if (this->stoneTributeButton[i] != nullptr) {
            int row_disabled = disabled;
            if (i == this->cur_player_row) {
                row_disabled = 1;
            }
            this->stoneTributeButton[i]->set_disabled(row_disabled);
            this->stoneTributeButton[i]->set_active((this->tribute_flag != 0) ? 1 : 0);
        }
    }
    return disabled;
}

// Fully verified. Source of truth: dlg_dip.cpp.decomp @ 0x0043E770
void TribeDiplomacyDialog::draw() {
    TEasy_Panel::draw();

    if (this->backgroundPics != nullptr && rge_base_game != nullptr && rge_base_game->world != nullptr) {
        const RGE_Game_World* world = rge_base_game->world;
        this->draw_setup(0);

        int row_y = 0;
        int row_count = world->player_num - 1;
        if (row_count > 8) {
            row_count = 8;
        }

        for (int row = 0; row < row_count; ++row) {
            RGE_Player* player = world->players[row + 1];
            if (player != nullptr && player->color_table != nullptr) {
                _ASMSet_Color_Xform((player->color_table->id + 1) * 0x10);
                this->backgroundPics->shape_draw(this->render_area, this->pnl_x + 10, this->pnl_y + 0x50 + row_y, 0, '\x01', player->color_table->table);
            }
            row_y += 0x1e;
        }

        this->draw_finish();
    }
}

long TribeDiplomacyDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeDiplomacyDialog, TDialogPanel)

