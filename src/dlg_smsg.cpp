#include "../include/dlg_smsg.h"
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
#include <new.h>
#include <string.h>

extern "C" void __cdecl _ASMSet_Color_Xform(int);

// Source order follows the original PDB module.

TribeSendMessageDialog::TribeSendMessageDialog(TScreenPanel* parent)
    : TDialogPanel("Send Message Dialog")
{
    int humanity;
    int world_humanity;
    RGE_Game_World* world;
    int id;
    char temp_str[100];

    int n;
    title = 0;
    for (n = 0; n < 8; ++n) {
        playerName[n] = 0;
        playerCivilization[n] = 0;
        checkButton[n] = 0;
        commPlayers[n] = 0;
    }
    for (n = 0; n < 3; ++n) {
        radioTitle[n] = 0;
        radioButton[n] = 0;
    }
    chatInput = 0;
    chatTitle = 0;
    okButton = 0;
    help_button = 0;
    backgroundPics = 0;

    if ((backgroundPics = new TShape("dlg_plbn.shp", 0xC63A)) == 0)
        return;
    else {
        if (!setup(parent->renderArea(), parent, 0x208, 0x1D1,
                   parent->get_popup_info_file(), parent->get_popup_info_id(), 1))
            return;

    if (!create_text(this, &title, 0x2667, 5, 10,
                     this->pnl_wid - 0x28, 0x1E, 1, 1, 1, 0))
        return;

    humanity = 1;
    world = rge_base_game->world;
    int y = 0x28;
    int row = 0;
    do {
        id = rge_base_game->playerID(humanity);
        if (id != 0) {
            int special = 0;
            if (world->players[id]->game_status == 2) {
                special = 1;
            }
            else if (rge_base_game->multiplayerGame()) {
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

            int font = special ? 8 : 11;
            if (!create_text(this, &playerName[row],
                             comm->GetPlayerName(humanity), 0x32, y, 0xBE, 0x1E,
                             font, 0, 1, 0))
                return;

            rge_base_game->get_string2(0x69, world->players[id]->master_player_id,
                                       0, temp_str, 100);
            if (!create_text(this, &playerCivilization[row],
                             temp_str, 0x104, y, 0x78, 0x1E, 0x0B, 0, 1, 0))
                return;

            if (humanity != comm->WhoAmI()) {
                int h = comm->GetPlayerHumanity(humanity);
                if (h == 2 || comm->GetPlayerHumanity(humanity) == 4) {
                    if (!create_check_box(this, &checkButton[row], 10, y, 0x1E, 0x1E, 0, 0))
                        return;
                    checkButton[row]->set_help_info(0x767F, -1);
                    if (chat->inChatGroup(humanity) != 0)
                        checkButton[row]->set_state(1);
                    else
                        checkButton[row]->set_state(0);
                }
            }
            commPlayers[row] = humanity;
            ++row;
            y += 0x1E;
        }
        ++humanity;
    } while (humanity < 9);

    if (!create_text(this, &chatTitle, 0x2668, 10, 0x13B, 0x78, 0x1E, 4, 1, 1, 0))
        return;
    if (!create_edit(this, &chatInput, "", 0x41, TEditPanel::FormatText, 0x82,
                     0x13B, 0x17C, 0x17, 0x0B, 1, 0))
        return;
    chatInput->set_help_info(0x767A, -1);

    if (!create_radio_button(this, &radioButton[0], 0x2D, 0x15E, 0x1E, 0x1E, 0, 0)) return;
    if (!create_radio_button(this, &radioButton[1], 0x113, 0x15E, 0x1E, 0x1E, 0, 0)) return;
    if (!create_radio_button(this, &radioButton[2], 0x2D, 0x181, 0x1E, 0x1E, 0, 0)) return;
    if (!create_radio_button(this, &radioButton[3], 0x113, 0x181, 0x1E, 0x1E, 0, 0)) return;

    if (!create_text(this, &radioTitle[0], 0x2669, 0x4B, 0x15E, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[0]->set_help_info(-1, -1);
    if (!create_text(this, &radioTitle[1], 0x266A, 0x131, 0x15E, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[1]->set_help_info(-1, -1);
    if (!create_text(this, &radioTitle[2], 0x266B, 0x4B, 0x181, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[2]->set_help_info(-1, -1);
    if (!create_text(this, &radioTitle[3], 0x266E, 0x131, 0x181, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[3]->set_help_info(-1, -1);

    for (n = 0; n < 4; ++n)
        radioButton[n]->set_radio_info(radioButton, 4);
    radioButton[3]->set_state(1);
    radioButton[0]->set_help_info(0x767B, -1);
    radioButton[1]->set_help_info(0x767C, -1);
    radioButton[2]->set_help_info(0x767D, -1);
    radioButton[3]->set_help_info(0x767E, -1);

    if (!create_button(this, &okButton, 0x266C, 0, 100, 0x1A9, 0x12C, 0x1E, 0, 0, 0))
        return;
    okButton->set_help_info(0x7531, -1);
    okButton->hotkey = 0x1B;
    okButton->hotkey_shift = 0;
        set_curr_child(chatInput);
    }
}

TribeSendMessageDialog::~TribeSendMessageDialog()
{
    this->delete_panel(reinterpret_cast<TPanel**>(&this->title));

    int i;
    for (i = 0; i < 8; ++i) {
        this->delete_panel(reinterpret_cast<TPanel**>(&this->playerName[i]));
        this->delete_panel(reinterpret_cast<TPanel**>(&this->playerCivilization[i]));
        this->delete_panel(reinterpret_cast<TPanel**>(&this->checkButton[i]));
    }

    for (i = 0; i < 4; ++i) {
        this->delete_panel(reinterpret_cast<TPanel**>(&this->radioTitle[i]));
        this->delete_panel(reinterpret_cast<TPanel**>(&this->radioButton[i]));
    }

    this->delete_panel(reinterpret_cast<TPanel**>(&this->chatInput));
    this->delete_panel(reinterpret_cast<TPanel**>(&this->chatTitle));
    this->delete_panel(reinterpret_cast<TPanel**>(&this->okButton));
    this->delete_panel(reinterpret_cast<TPanel**>(&this->help_button));

    TShape* shape = this->backgroundPics;
    if (shape != 0) {
        shape->~TShape();
        operator delete(shape);
    }
}

long TribeSendMessageDialog::action(TPanel* panel, long code,
                                    unsigned long a, unsigned long b)
{
    char save_msg[66];

    if (panel != 0) {
    if (panel == this->chatInput) {
        if (code == 0) {
            TRIBE_Screen_Game* screen =
                static_cast<TRIBE_Screen_Game*>(this->parent_panel);

            if (this->chatInput->currentLine() == 0 ||
                *this->chatInput->currentLine() == 0)
                save_msg[0] = 0;
            else
                strcpy(save_msg, this->chatInput->currentLine());

            if (save_msg[0] == 0)
                goto done;

            if (rge_base_game->processCheatCode(
                    rge_base_game->world->curr_player, save_msg) == 0) {
                if (rge_base_game->multiplayerGame() != 0) {
                    if (rge_base_game->prog_mode != 5) {
                        comm->SendGroupChatMsg(save_msg);
                        L->Log("$$$ SEND CHAT @%u: %s",
                               rge_base_game->world->world_time, save_msg);
                    }
                }
                else {
                    rge_base_game->play_sound(2);
                    screen->display_system_message(save_msg);
                }
            }

            this->chatInput->set_text("");
            return 1;
        }
    }

    else {
    if (panel == this->okButton) {
        if (code != 1)
            goto check_buttons_return;

        this->checkButtons();
        TRIBE_Screen_Game* screen =
            static_cast<TRIBE_Screen_Game*>(this->parent_panel);

        if (this->chatInput->currentLine() == 0 ||
            *this->chatInput->currentLine() == 0)
            save_msg[0] = 0;
        else
            strcpy(save_msg, this->chatInput->currentLine());

        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Send Message Dialog");

        if (save_msg[0] == 0)
            goto done;

        if (rge_base_game->processCheatCode(
                rge_base_game->world->curr_player, save_msg) != 0)
            goto done;

        if (rge_base_game->multiplayerGame() != 0) {
            if (rge_base_game->prog_mode == 5)
                goto done;
            comm->SendGroupChatMsg(save_msg);
            L->Log("$$$ SEND CHAT @%u: %s",
                   rge_base_game->world->world_time, save_msg);
            return 1;
        }

        rge_base_game->play_sound(2);
        screen->display_system_message(save_msg);
        return 1;
    }

    if (panel == this->help_button) {
        this->setup_popup_help();
        return 1;
    }

    if (panel == this->checkButton[0] ||
        panel == this->checkButton[1] ||
        panel == this->checkButton[2] ||
        panel == this->checkButton[3] ||
        panel == this->checkButton[4] ||
        panel == this->checkButton[5] ||
        panel == this->checkButton[6] ||
        panel == this->checkButton[7]) {
        this->radioButton[0]->set_state(0);
        this->radioButton[1]->set_state(0);
        this->radioButton[2]->set_state(0);
        this->radioButton[3]->set_state(1);
    }

    else if (panel == this->radioButton[0]) {
        RGE_Player* player = rge_base_game->world->players[
            rge_base_game->world->curr_player];
        int i = 0;
        do {
            if (this->checkButton[i] != 0) {
                int player_id = rge_base_game->playerID(
                    this->commPlayers[i]);
                if (player_id == player->id || player->isAlly(player_id))
                    this->checkButton[i]->set_state(1);
                else
                    this->checkButton[i]->set_state(0);
            }
            ++i;
        } while (i < 8);
    }

    else if (panel == this->radioButton[1]) {
        RGE_Player* player = rge_base_game->world->players[
            rge_base_game->world->curr_player];
        int i = 0;
        do {
            if (this->checkButton[i] != 0) {
                int player_id = rge_base_game->playerID(
                    this->commPlayers[i]);
                if (player_id == player->id || player->isEnemy(player_id) == 0)
                    this->checkButton[i]->set_state(0);
                else
                    this->checkButton[i]->set_state(1);
            }
            ++i;
        } while (i < 8);
    }

    else if (panel == this->radioButton[2]) {
        if (code == 1) {
            int i = 0;
            do {
                if (this->checkButton[i] != 0)
                    this->checkButton[i]->set_state(1);
                ++i;
            } while (i < 8);
        }
    }

    // ORIGINAL BUG: preserve the shipped fourth-button read.
    else if (panel == this->radioButton[3]) {
    }

check_buttons_return:
    this->checkButtons();
    }
done:
    return 1;
    }

    return TPanel::action(panel, code, a, b);
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

void TribeSendMessageDialog::draw()
{
    TEasy_Panel::draw();

    if (this->backgroundPics != 0) {
        RGE_Game_World* world = rge_base_game->world;
        this->draw_setup(0);

        int y = 0;
        int i = 1;
        do {
            int id = rge_base_game->playerID(i);
            if (id != 0) {
                if (world->players[id]->color_table != 0) {
                    _ASMSet_Color_Xform(
                        (world->players[id]->color_table->id + 1) * 0x10);
                    this->backgroundPics->shape_draw(
                        this->render_area,
                        this->pnl_x + 0x32,
                        this->pnl_y + y + 0x28,
                        0, 1, world->players[id]->color_table->table);
                }
                y += 0x1E;
            }
            ++i;
        } while (i < 9);

        this->draw_finish();
    }
}

TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(TScreenPanel* parent,
                                                         Mode mode)
    : TDialogPanel("Send Quick Message Dialog"), modeValue(mode)
{
    if (!this->setup(parent->renderArea(), parent, 0x21C, 0x23,
                     parent->get_popup_info_file(),
                     parent->get_popup_info_id(), 1)) {
        return;
    }

    int title_id;
    if (this->modeValue == AsChat)
        title_id = 0x2668;
    else
        title_id = 0x266D;
    if (!this->create_text(this, &this->chatTitle, title_id,
                           5, 5, 0x78, 0x19, 4, 1, 1, 0)) {
        return;
    }

    if (!this->create_edit(this, &this->chatInput, "", 0x41, 0,
                           0x82, 5, 0x195, 0x19, 0x0B, 1, 0)) {
        return;
    }

    this->set_curr_child(this->chatInput);
}

TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog() {
    delete this->chatInput;
    delete this->chatTitle;
}

long TribeSendQuickMessageDialog::action(TPanel* panel, long code,
                                         unsigned long a, unsigned long b)
{
    char save_msg[66];

    if (panel != 0 && panel == this->chatInput) {
        if (code == 0) {
            char* line = this->chatInput->currentLine();
            if (line != 0 && *this->chatInput->currentLine() != 0) {
                TRIBE_Screen_Game* screen =
                    static_cast<TRIBE_Screen_Game*>(this->parent_panel);
                strcpy(save_msg, this->chatInput->currentLine());

                panel_system.setCurrentPanel("Game Screen", 0);
                panel_system.destroyPanel("Send Quick Message Dialog");

                if (rge_base_game->processCheatCode(
                        rge_base_game->world->curr_player, save_msg) != 0)
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
        }
        else if (code != 1)
            goto base_action;

        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Send Quick Message Dialog");
        goto success;
    }

    goto base_action;

success:
    return 1;

base_action:
    return TEasy_Panel::action(panel, code, a, b);
}

long TribeSendQuickMessageDialog::handle_mouse_down(unsigned char button,
                                                     long x, long y,
                                                     int flags, int area) {
    if (this->is_inside(x, y) == 0) {
        this->action(this->chatInput, 1, 0, 0);
        return 1;
    }

    return TEasy_Panel::handle_mouse_down(button, x, y, flags, area);
}
