#include "../include/dlg_smsg.h"
#include "../include/asm_draw.h"
#include "../include/Pnl_scr.h"
#include "../include/panel.h"
#include "../include/Pnl_txt.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_edit.h"
#include "../include/basegame.h"
#include "../include/Shape.h"
#include "../include/color.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/com_hand.h"
#include "../include/chat.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include "../include/scr_game.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"
#include <string.h>


TribeSendMessageDialog::TribeSendMessageDialog(TScreenPanel* parentPanel)
    : TDialogPanel("Send Message Dialog") {
    int humanity;
    int world_humanity;
    RGE_Game_World* world;
    int id;
    char temp_str[100];

    int i;
    title = 0;
    for (i = 0; i < 8; ++i) {
        playerName[i] = 0;
        playerCivilization[i] = 0;
        checkButton[i] = 0;
        commPlayers[i] = 0;
    }
    for (i = 0; i < 3; ++i) {
        radioTitle[i] = 0;
        radioButton[i] = 0;
    }
    chatInput = 0;
    chatTitle = 0;
    okButton = 0;
    help_button = 0;
    backgroundPics = 0;

    if ((backgroundPics = new TShape("dlg_plbn.shp", 0xC63A)) == 0)
        return;
    else {
        if (!setup(parentPanel->renderArea(), parentPanel, 520, 465,
                   parentPanel->get_popup_info_file(), parentPanel->get_popup_info_id(), 1))
            return;

        if (!create_text(this, &title, STRING_ID_SEND_MESSAGE_TITLE, 5, 10, this->pnl_wid - 40, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 1, 0))
            return;

        humanity = 1;
        world = rge_base_game->world;
        int y = 40;
        int row = 0;
        do {
            id = rge_base_game->playerID(humanity);
            if (id != 0) {
                int special = 0;
                if (world->players[id]->game_status == 2) {
                    special = 1;
                } else if (rge_base_game->multiplayerGame()) {
                    world_humanity = 0;
                    int j = 1;
                    int count = rge_base_game->numberPlayers();
                    if (j <= count) {
                        do {
                            if (rge_base_game->playerID(j) == id) {
                                int h = comm->GetPlayerHumanity(j);
                                if (h == 2 || h == 4)
                                    world_humanity = h;
                            }
                            ++j;
                            count = rge_base_game->numberPlayers();
                        } while (j <= count);
                    }
                    if (world_humanity != 2 && world_humanity != 4)
                        special = 1;
                }

                int font = special ? RGE_FONT_STRIKEOUT : RGE_FONT_STANDARD;
                if (!create_text(this, &playerName[row], comm->GetPlayerName(humanity), 50, y, 190, 30, font, 0, 1, 0))
                    return;

                rge_base_game->get_string2(RGE_STRING_TYPE_CIVILIZATION, world->players[id]->master_player_id,
                                           0, temp_str, 100);
                if (!create_text(this, &playerCivilization[row], temp_str, 260, y, 120, 30, RGE_FONT_STANDARD, 0, 1, 0))
                    return;

                if (humanity != comm->WhoAmI()) {
                    int h = comm->GetPlayerHumanity(humanity);
                    if (h == 2 || comm->GetPlayerHumanity(humanity) == 4) {
                        if (!create_check_box(this, &checkButton[row], 10, y, 30, 30, 0, 0))
                            return;
                        checkButton[row]->set_help_info(STRING_ID_HELP_CHAT_PLAYER, -1);
                        if (chat->inChatGroup(humanity) != 0)
                            checkButton[row]->set_state(1);
                        else
                            checkButton[row]->set_state(0);
                    }
                }
                commPlayers[row] = humanity;
                ++row;
                y += 30;
            }
            ++humanity;
        } while (humanity < 9);

        if (!create_text(this, &chatTitle, STRING_ID_SEND_MESSAGE_CHAT, 10, 315, 120, 30, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 1, 1, 0))
            return;
        if (!create_edit(this, &chatInput, "", 65, TEditPanel::FormatText, 130, 315, 380, 23, RGE_FONT_STANDARD, 1, 0))
            return;
        chatInput->set_help_info(STRING_ID_HELP_CHAT_INPUT, -1);

        if (!create_radio_button(this, &radioButton[0], 45, 350, 30, 30, 0, 0)) return;
        if (!create_radio_button(this, &radioButton[1], 275, 350, 30, 30, 0, 0)) return;
        if (!create_radio_button(this, &radioButton[2], 45, 385, 30, 30, 0, 0)) return;
        if (!create_radio_button(this, &radioButton[3], 275, 385, 30, 30, 0, 0)) return;

        if (!create_text(this, &radioTitle[0], STRING_ID_SEND_MESSAGE_ALLIES, 75, 350, 200, 30, RGE_FONT_STANDARD, 0, 1, 0)) return;
        radioTitle[0]->set_help_info(-1, -1);
        if (!create_text(this, &radioTitle[1], STRING_ID_SEND_MESSAGE_ENEMIES, 305, 350, 200, 30, RGE_FONT_STANDARD, 0, 1, 0)) return;
        radioTitle[1]->set_help_info(-1, -1);
        if (!create_text(this, &radioTitle[2], STRING_ID_SEND_MESSAGE_EVERYONE, 75, 385, 200, 30, RGE_FONT_STANDARD, 0, 1, 0)) return;
        radioTitle[2]->set_help_info(-1, -1);
        if (!create_text(this, &radioTitle[3], STRING_ID_SEND_MESSAGE_SELECT_PLAYER, 305, 385, 200, 30, RGE_FONT_STANDARD, 0, 1, 0)) return;
        radioTitle[3]->set_help_info(-1, -1);

        for (i = 0; i < 4; ++i)
            radioButton[i]->set_radio_info(radioButton, 4);
        radioButton[3]->set_state(1);
        radioButton[0]->set_help_info(STRING_ID_HELP_CHAT_ALLIES, -1);
        radioButton[1]->set_help_info(STRING_ID_HELP_CHAT_ENEMIES, -1);
        radioButton[2]->set_help_info(STRING_ID_HELP_CHAT_ALL_PLAYERS, -1);
        radioButton[3]->set_help_info(STRING_ID_HELP_CHAT_RECIPIENTS, -1);

        if (!create_button(this, &okButton, STRING_ID_BUTTON_RETURN_TO_GAME, 0, 100, 425, 300, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0))
            return;
        okButton->set_help_info(STRING_ID_HELP_OK, -1);
        okButton->hotkey = VK_ESCAPE;
        okButton->hotkey_shift = 0;
        set_curr_child(chatInput);
    }
}

TribeSendMessageDialog::~TribeSendMessageDialog() {
    this->delete_panel((TPanel**)&this->title);

    int i;
    for (i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->playerName[i]);
        this->delete_panel((TPanel**)&this->playerCivilization[i]);
        this->delete_panel((TPanel**)&this->checkButton[i]);
    }

    for (i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->radioTitle[i]);
        this->delete_panel((TPanel**)&this->radioButton[i]);
    }

    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->help_button);

    delete this->backgroundPics;
}

long TribeSendMessageDialog::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    char save_msg[66];

    if (fromPanel != 0) {
        if (fromPanel == this->chatInput) {
            if (actionIn == 0) {
                TRIBE_Screen_Game *screen = static_cast<TRIBE_Screen_Game *>(this->parent_panel);

                if (this->chatInput->currentLine() == 0 || *this->chatInput->currentLine() == 0)
                    save_msg[0] = 0;
                else
                    strcpy(save_msg, this->chatInput->currentLine());

                if (save_msg[0] == 0)
                    goto done;

                if (rge_base_game->processCheatCode(rge_base_game->world->curr_player, save_msg) == 0) {
                    if (rge_base_game->multiplayerGame() != 0) {
                        if (rge_base_game->prog_mode != 5) {
                            comm->SendGroupChatMsg(save_msg);
                            L->Log("$$$ SEND CHAT @%u: %s", rge_base_game->world->world_time, save_msg);
                        }
                    } else {
                        rge_base_game->play_sound(2);
                        screen->display_system_message(save_msg);
                    }
                }

                this->chatInput->set_text("");
                return 1;
            }
        } else {
            if (fromPanel == this->okButton) {
                if (actionIn != 1) {
                    goto check_buttons_return;
                }

                this->checkButtons();
                TRIBE_Screen_Game *screen = static_cast<TRIBE_Screen_Game *>(this->parent_panel);

                if (this->chatInput->currentLine() == 0 || *this->chatInput->currentLine() == 0)
                    save_msg[0] = 0;
                else
                    strcpy(save_msg, this->chatInput->currentLine());

                panel_system.setCurrentPanel("Game Screen", 0);
                panel_system.destroyPanel("Send Message Dialog");

                if (save_msg[0] == 0)
                    goto done;

                if (rge_base_game->processCheatCode(rge_base_game->world->curr_player, save_msg) != 0)
                    goto done;

                if (rge_base_game->multiplayerGame() != 0) {
                    if (rge_base_game->prog_mode == 5)
                        goto done;
                    comm->SendGroupChatMsg(save_msg);
                    L->Log("$$$ SEND CHAT @%u: %s", rge_base_game->world->world_time, save_msg);
                    return 1;
                }

                rge_base_game->play_sound(2);
                screen->display_system_message(save_msg);
                return 1;
            }

            if (fromPanel == this->help_button) {
                this->setup_popup_help();
                return 1;
            }

            if (fromPanel == this->checkButton[0] || fromPanel == this->checkButton[1] ||
                fromPanel == this->checkButton[2] || fromPanel == this->checkButton[3] ||
                fromPanel == this->checkButton[4] || fromPanel == this->checkButton[5] ||
                fromPanel == this->checkButton[6] || fromPanel == this->checkButton[7]) {
                this->radioButton[0]->set_state(0);
                this->radioButton[1]->set_state(0);
                this->radioButton[2]->set_state(0);
                this->radioButton[3]->set_state(1);
            } else if (fromPanel == this->radioButton[0]) {
                RGE_Player *player = rge_base_game->world->players[rge_base_game->world->curr_player];
                int i = 0;
                do {
                    if (this->checkButton[i] != 0) {
                        int player_id = rge_base_game->playerID(this->commPlayers[i]);
                        if (player_id == player->id || player->isAlly(player_id))
                            this->checkButton[i]->set_state(1);
                        else
                            this->checkButton[i]->set_state(0);
                    }
                    ++i;
                } while (i < 8);
            } else if (fromPanel == this->radioButton[1]) {
                RGE_Player *player = rge_base_game->world->players[rge_base_game->world->curr_player];
                int i = 0;
                do {
                    if (this->checkButton[i] != 0) {
                        int player_id = rge_base_game->playerID(this->commPlayers[i]);
                        if (player_id == player->id || player->isEnemy(player_id) == 0)
                            this->checkButton[i]->set_state(0);
                        else
                            this->checkButton[i]->set_state(1);
                    }
                    ++i;
                } while (i < 8);
            } else if (fromPanel == this->radioButton[2]) {
                if (actionIn == 1) {
                    int i = 0;
                    do {
                        if (this->checkButton[i] != 0)
                            this->checkButton[i]->set_state(1);
                        ++i;
                    } while (i < 8);
                }
            } else if (fromPanel == this->radioButton[3]) {
                // The original fourth-button branch is intentionally empty.
            }

        check_buttons_return:
            this->checkButtons();
        }
    done:
        return 1;
    }

    return TPanel::action(fromPanel, actionIn, a1, a2);
}

void TribeSendMessageDialog::checkButtons(void) {
    int i = 0;

    do {
        if (this->commPlayers[i] != 0 && this->checkButton[i] != 0) {
            int state = this->checkButton[i]->get_state();
            if (state == 0) {
                chat->setInChatGroup(this->commPlayers[i], 0);
            } else {
                chat->setInChatGroup(this->commPlayers[i], 1);
            }
        }
        ++i;
    } while (i < 8);
}

void TribeSendMessageDialog::draw() {
    TEasy_Panel::draw();

    if (this->backgroundPics != 0) {
        RGE_Game_World *world = rge_base_game->world;
        this->draw_setup(0);

        int y = 0;
        int i = 1;
        do {
            int id = rge_base_game->playerID(i);
            if (id != 0) {
                if (world->players[id]->color_table != 0) {
                    ASMSet_Color_Xform((world->players[id]->color_table->id + 1) * 16);
                    this->backgroundPics->shape_draw(this->render_area, this->pnl_x + 50, this->pnl_y + y + 40, 0, 1,
                                                     world->players[id]->color_table->table);
                }
                y += 30;
            }
            ++i;
        } while (i < 9);

        this->draw_finish();
    }
}

TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(TScreenPanel* parentPanel,
                                                         Mode m)
    : TDialogPanel("Send Quick Message Dialog"), modeValue(m) {
    if (!this->setup(parentPanel->renderArea(), parentPanel, 540, 35, parentPanel->get_popup_info_file(),
                     parentPanel->get_popup_info_id(), 1)) {
        return;
    }

    int title_id;
    if (this->modeValue == AsChat)
        title_id = STRING_ID_SEND_MESSAGE_CHAT;
    else
        title_id = STRING_ID_QUICK_MESSAGE_COMMENT;
    if (!this->create_text(this, &this->chatTitle, title_id, 5, 5, 120, 25, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 1, 1, 0)) {
        return;
    }

    if (!this->create_edit(this, &this->chatInput, "", 65, TEditPanel::FormatText,
                           130, 5, 405, 25, RGE_FONT_STANDARD, 1, 0)) {
        return;
    }

    this->set_curr_child(this->chatInput);
}

TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog() {
    delete this->chatInput;
    delete this->chatTitle;
}

long TribeSendQuickMessageDialog::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    char save_msg[66];

    if (fromPanel != 0 && fromPanel == this->chatInput) {
        if (actionIn == 0) {
            char* line = this->chatInput->currentLine();
            if (line != 0 && *this->chatInput->currentLine() != 0) {
                TRIBE_Screen_Game* screen =
                    static_cast<TRIBE_Screen_Game*>(this->parent_panel);
                strcpy(save_msg, this->chatInput->currentLine());

                panel_system.setCurrentPanel("Game Screen", 0);
                panel_system.destroyPanel("Send Quick Message Dialog");

                if (rge_base_game->processCheatCode(rge_base_game->world->curr_player, save_msg) != 0)
                    goto success;

                if (rge_base_game->multiplayerGame() != 0) {
                    if (rge_base_game->prog_mode == 5)
                        goto success;
                    comm->SendGroupChatMsg(save_msg);
                    return 1;
                }

                rge_base_game->play_sound(2);
                screen->display_system_message(save_msg);
                return 1;
            }
        } else if (actionIn != 1)
            goto base_action;

        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Send Quick Message Dialog");
        goto success;
    }

    goto base_action;

success:
    return 1;

base_action:
    return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}

long TribeSendQuickMessageDialog::handle_mouse_down(unsigned char mouse_button_in, long x, long y,
                                                     int ctrl_key, int shift_key) {
    if (this->is_inside(x, y) == 0) {
        this->action(this->chatInput, 1, 0, 0);
        return 1;
    }

    return TEasy_Panel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}
