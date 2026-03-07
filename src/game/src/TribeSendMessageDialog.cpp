#include "../include/TribeSendMessageDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TChat.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TDebuggingLog.h"
#include "../include/TEditPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TShape.h"
#include "../include/TScreenPanel.h"
#include "../include/TRIBE_Screen_Game.h"
#include "../include/TribeSendQuickMessageDialog.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

#include <cstring>

extern "C" void _ASMSet_Color_Xform(int v);

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x004407A0
TribeSendMessageDialog::TribeSendMessageDialog(TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Send Message Dialog") {
    this->title = nullptr;
    this->chatInput = nullptr;
    this->chatTitle = nullptr;
    this->okButton = nullptr;
    this->help_button = nullptr;
    this->radioButtonShapes = nullptr;
    this->backgroundPics = nullptr;
    for (int i = 0; i < 8; ++i) {
        this->playerName[i] = nullptr;
        this->playerCivilization[i] = nullptr;
        this->checkButton[i] = nullptr;
        this->commPlayers[i] = 0;
        if (i < 4) {
            this->radioTitle[i] = nullptr;
            this->radioButton[i] = nullptr;
        }
    }

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 0x208, 0x1d1, popup_file, popup_id, 1)) {
        return;
    }

    this->create_text((TPanel*)this, &this->title, 0x2667, 5, 10, this->width() - 0x28, 0x1e, 1, 1, 1, 0);
    this->create_edit((TPanel*)this, &this->chatInput, (char*)"", 0xff, FormatAny, 0x14, 0x16d, 0x1cc, 0x17, 0xb, 1, 1);
    this->create_text((TPanel*)this, &this->chatTitle, 0x2668, 0x14, 0x152, 0x1cc, 0x17, 4, 0, 1, 0);
    this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x14, 0x18b, 0xf0, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->help_button, 0x23f5, 0, 0x124, 0x18b, 0xf0, 0x1e, 0, 0, 0);
    if (this->okButton != nullptr) {
        this->okButton->hotkey = 0x0d;
        this->okButton->hotkey_shift = 0;
    }
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00440E20
TribeSendMessageDialog::~TribeSendMessageDialog() {
    this->delete_panel((TPanel**)&this->title);
    for (int i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->playerName[i]);
        this->delete_panel((TPanel**)&this->playerCivilization[i]);
        this->delete_panel((TPanel**)&this->checkButton[i]);
        if (i < 4) {
            this->delete_panel((TPanel**)&this->radioTitle[i]);
            this->delete_panel((TPanel**)&this->radioButton[i]);
        }
    }
    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->help_button);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00440F20
long TribeSendMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 == nullptr) {
        return TPanel::action(nullptr, param_2, param_3, param_4);
    }

    char save_msg[66];
    char* msg = save_msg + 4;
    char* current = nullptr;
    TRIBE_Screen_Game* game_screen = nullptr;
    int cheat = 0;

    if ((TEditPanel*)param_1 == this->chatInput) {
        if (param_2 == 0) {
            game_screen = (TRIBE_Screen_Game*)this->parent_panel;
            current = (this->chatInput != nullptr) ? this->chatInput->currentLine() : nullptr;
            if (current == nullptr || current[0] == '\0') {
                msg[0] = '\0';
            } else {
                std::memcpy(msg, current, std::strlen(current) + 1);
            }

            if (msg[0] != '\0') {
                cheat = rge_base_game->processCheatCode((int)rge_base_game->world->curr_player, msg);
                if (cheat == 0) {
                    if (rge_base_game->multiplayerGame() == 0) {
                        rge_base_game->play_sound(2);
                        game_screen->display_system_message(msg);
                    } else if (rge_base_game->prog_mode != 5) {
                        ((TCommunications_Handler*)comm)->SendGroupChatMsg(msg);
                        L->Log("$$$ SEND CHAT @%u: %s", rge_base_game->world->world_time, msg);
                    }
                }

                if (this->chatInput != nullptr) {
                    this->chatInput->set_text((char*)"");
                }
                return 1;
            }
        }
    } else {
        if ((TButtonPanel*)param_1 == this->okButton) {
            if (param_2 == 1) {
                this->checkButtons();
                game_screen = (TRIBE_Screen_Game*)this->parent_panel;
                current = (this->chatInput != nullptr) ? this->chatInput->currentLine() : nullptr;
                if (current == nullptr || current[0] == '\0') {
                    msg[0] = '\0';
                } else {
                    std::memcpy(msg, current, std::strlen(current) + 1);
                }

                panel_system->setCurrentPanel((char*)"Game Screen", 0);
                panel_system->destroyPanel((char*)"Send Message Dialog");
                if (msg[0] == '\0') {
                    return 1;
                }

                cheat = rge_base_game->processCheatCode((int)rge_base_game->world->curr_player, msg);
                if (cheat != 0) {
                    return 1;
                }

                if (rge_base_game->multiplayerGame() == 0) {
                    rge_base_game->play_sound(2);
                    game_screen->display_system_message(msg);
                    return 1;
                }

                if (rge_base_game->prog_mode == 5) {
                    return 1;
                }

                ((TCommunications_Handler*)comm)->SendGroupChatMsg(msg);
                L->Log("$$$ SEND CHAT @%u: %s", rge_base_game->world->world_time, msg);
                return 1;
            }
        } else {
            if ((TButtonPanel*)param_1 == this->help_button) {
                this->setup_popup_help();
                return 1;
            }

            bool clicked_check = false;
            for (int i = 0; i < 8; ++i) {
                if ((TButtonPanel*)param_1 == this->checkButton[i]) {
                    clicked_check = true;
                    break;
                }
            }

            if (clicked_check) {
                this->radioButton[0]->set_state(0);
                this->radioButton[1]->set_state(0);
                this->radioButton[2]->set_state(0);
                this->radioButton[3]->set_state(1);
            } else {
                if ((TButtonPanel*)param_1 == this->radioButton[0]) {
                    RGE_Player* current_player = rge_base_game->world->players[rge_base_game->world->curr_player];
                    for (int i = 0; i < 8; ++i) {
                        if (this->checkButton[i] != nullptr) {
                            const int player_id = rge_base_game->playerID(this->commPlayers[i]);
                            if (player_id == current_player->id || current_player->isAlly(player_id) != 0) {
                                this->checkButton[i]->set_state(1);
                            } else {
                                this->checkButton[i]->set_state(0);
                            }
                        }
                    }
                    this->checkButtons();
                    return 1;
                }

                if ((TButtonPanel*)param_1 == this->radioButton[1]) {
                    RGE_Player* current_player = rge_base_game->world->players[rge_base_game->world->curr_player];
                    for (int i = 0; i < 8; ++i) {
                        if (this->checkButton[i] != nullptr) {
                            const int player_id = rge_base_game->playerID(this->commPlayers[i]);
                            if (player_id == current_player->id || current_player->isEnemy(player_id) == 0) {
                                this->checkButton[i]->set_state(0);
                            } else {
                                this->checkButton[i]->set_state(1);
                            }
                        }
                    }
                    this->checkButtons();
                    return 1;
                }

                if ((TButtonPanel*)param_1 != this->radioButton[2]) {
                    this->checkButtons();
                    return 1;
                }

                if (param_2 == 1) {
                    for (int i = 0; i < 8; ++i) {
                        if (this->checkButton[i] != nullptr) {
                            this->checkButton[i]->set_state(1);
                        }
                    }
                    this->checkButtons();
                    return 1;
                }
            }
        }

        this->checkButtons();
    }

    return 1;
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441410
void TribeSendMessageDialog::checkButtons() {
    TChat* chat_system = (TChat*)chat;
    for (int i = 0; i < 8; ++i) {
        if (this->commPlayers[i] != 0 && this->checkButton[i] != nullptr && chat_system != nullptr) {
            chat_system->setInChatGroup(this->commPlayers[i], this->checkButton[i]->get_state() != 0);
        }
    }
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441460
void TribeSendMessageDialog::draw() {
    TEasy_Panel::draw();

    if (this->backgroundPics != nullptr && rge_base_game != nullptr && rge_base_game->world != nullptr) {
        const RGE_Game_World* world = rge_base_game->world;
        this->draw_setup(0);

        int row_y = 0;
        for (int i = 1; i < 9; ++i) {
            const int player_id = rge_base_game->playerID(i);
            if (player_id != 0) {
                RGE_Player* player = world->players[player_id];
                if (player != nullptr && player->color_table != nullptr) {
                    _ASMSet_Color_Xform((player->color_table->id + 1) * 0x10);
                    this->backgroundPics->shape_draw(this->render_area, this->pnl_x + 0x32, this->pnl_y + 0x28 + row_y, 0, '\x01', player->color_table->table);
                }
                row_y += 0x1e;
            }
        }

        this->draw_finish();
    }
}

long TribeSendMessageDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeSendMessageDialog, TDialogPanel)

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441530
TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(TScreenPanel* parent_screen, Mode mode)
    : TDialogPanel((char*)"Send Quick Message Dialog") {
    this->chatInput = nullptr;
    this->chatTitle = nullptr;
    this->modeValue = mode;

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;
    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 0x190, 0x96, popup_file, popup_id, 1)) {
        return;
    }

    this->create_edit((TPanel*)this, &this->chatInput, (char*)"", 0xff, FormatAny, 0x14, 0x2d, 0x168, 0x17, 0xb, 1, 1);
    this->create_text((TPanel*)this, &this->chatTitle, 0x2668, 0x14, 0x14, 0x168, 0x14, 4, 0, 1, 0);
    this->set_curr_child((TPanel*)this->chatInput);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441650
TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog() {
    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x004416C0
long TribeSendQuickMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_2 == 1 || (param_1 == (TPanel*)this->chatInput && param_2 == 0)) {
        if (panel_system != nullptr) {
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            panel_system->destroyPanel((char*)"Send Quick Message Dialog");
        }
        return 1;
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: dlg_smsg.cpp.decomp @ 0x00441840
long TribeSendQuickMessageDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

void TribeSendQuickMessageDialog::draw() {
    TDialogPanel::draw();
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeSendQuickMessageDialog, TDialogPanel)

