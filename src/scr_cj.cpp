#include "../include/scr_cj.h"
#include "../include/com_hand.h"
#include "../include/com_sess.h"
#include "../include/scr_mp.h"
#include "../include/scr_mps.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/pnl_edit.h"
#include "../include/drawarea.h"
#include "../include/Shape.h"
#include "../include/Picture.h"
#include "../include/registry.h"
#include "../include/debuglog.h"
#include "../include/scr_main.h"
#include <stdio.h>
#include <string.h>


TribeJoinScreen::TribeJoinScreen()
    : TScreenPanel("Join Screen")
{
    this->startedSession = 0;
    this->listFilled = 0;
    Sess = 0;
    this->game_count = 0;
    this->waitingToStart = 0;
    this->joinTime = 0;
    this->close_button = 0;

    comm->SetPlayerHumanity(1, ME_HUMAN);
    for (int player = 2; player <= 9; ++player) {
        comm->SetPlayerHumanity(player, ME_ABSENT);
    }

    if (this->setup(rge_base_game->draw_area, "scr3",
                    0xC385, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x259F,
                          0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0)) {
        this->create_text(this, &this->listTitle, 0x25A8,
                          0x14, 0x41, 0x258, 0x14, 4, 0, 0, 0);
        if (this->create_list(this, &this->list,
                              0x14, 0x5A, 0x258, 0x10E, 0x0B)) {
            if (this->create_auto_scrollbar(&this->scrollbar,
                                            this->list, 0x14)) {
                this->listFilled = 1;
                this->list->set_text(0x25AB);
                if (this->create_button(this, &this->refreshButton,
                                        0x25A1, 0, 0xD2, 0x172,
                                        0xDC, 0x1E, 0, 0, 0)) {
                    if (this->create_button(this, &this->joinButton,
                                            0x25A0, 0, 0x0A, 0x1B8,
                                            0xC8, 0x1E, 0, 0, 0)) {
                        if (this->create_button(this, &this->createButton,
                                                0x25A2, 0, 0xDC, 0x1B8,
                                                0xC8, 0x1E, 0, 0, 0)) {
                            if (this->create_button(this, &this->cancelButton,
                                                    0x0FA2, 0, 0x1AE,
                                                    0x1B8, 0xC8, 0x1E,
                                                    0, 0, 0)) {
                                TButtonPanel* cancel = this->cancelButton;
                                cancel->hotkey = 0x1B;
                                cancel->hotkey_shift = 0;

                                if (this->create_button(this,
                                                        &this->close_button,
                                                        0x03EA, 0, 0, 0, 0,
                                                        0, -1, -1, 0)) {
                                    this->close_button->set_active(1);
                                    this->close_button->set_positioning(
                                        TPanel::PositionRightTop, 4, 4, 4, 4,
                                        0x11, 0x11,
                                        0x11, 0x11, 0, 0, 0, 0);
                                    this->set_curr_child(this->refreshButton);

                                    TPanel* tabList[5];
                                    tabList[0] = this->list;
                                    tabList[1] = this->refreshButton;
                                    tabList[2] = this->joinButton;
                                    tabList[3] = this->createButton;
                                    tabList[4] = this->cancelButton;
                                    this->set_tab_order(tabList, 5);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

TribeJoinScreen::~TribeJoinScreen() {
    TCommunications_Sessions* p = Sess;
    if (p != 0) {
        delete p;
    }
    delete this->title;
    delete this->listTitle;
    delete this->list;
    delete this->scrollbar;
    delete this->refreshButton;
    delete this->joinButton;
    delete this->createButton;
    delete this->cancelButton;
    delete this->close_button;
}

long TribeJoinScreen::handle_idle() {
    if (this->waitingToStart == 0) {
        if ((this->listFilled != 0) && (rge_base_game->input_enabled == 0)) {
            rge_base_game->enable_input();
        }
        if (this->waitingToStart == 0) {
            return TPanel::handle_idle();
        }
    }
    unsigned long now = debug_timeGetTime("scr_cj.cpp", 0xAA);
    if (10000 < now - this->joinTime) {
        comm->UnlinkToLevel(SERVICE_AVAILABLE);
        this->waitingToStart = 0;
        rge_base_game->enable_input();
        TEasy_Panel::popupOKDialog(0x25A3, 0, 0x1C2, 100);
        return 1;
    }
    return TPanel::handle_idle();
}

long TribeJoinScreen::handle_user_command(unsigned int cmd, long param) {
    switch (cmd) {
        case 0x17A4:
            break;
        case 0x17B8:
            if (this->waitingToStart != 0) {
                new TribeMPSetupScreen;
                panel_system.setCurrentPanel("MP Setup Screen", 0);
                panel_system.destroyPanel("Join Screen");
                return 1;
            }
            break;
        case 0x17A8:
        case 0x17A9:
        case 0x17AA:
        case 0x17B2:
            if (this->waitingToStart != 0) {
                comm->UnlinkToLevel(SERVICE_AVAILABLE);
                this->waitingToStart = 0;
                rge_base_game->enable_input();
                TEasy_Panel::popupOKDialog(0x25A3, 0, 0x1C2, 100);
                return 1;
            }
            break;
    }
    return TPanel::handle_user_command(cmd, param);
}

void TribeJoinScreen::fillList() {
    char szTemp[126];

    rge_base_game->disable_input();
    this->listFilled = 0;
    this->game_count = 0;
    this->list->set_text(0x25A9);
    rge_base_game->draw_window();

    if (this->startedSession == 0) {
        Sess = new TCommunications_Sessions(comm);
        if (Sess == 0) {
            this->list->set_text(0x25AB);
            return;
        }
        this->startedSession = 1;
    } else {
        Sess->Refresh();
    }

    this->game_count = Sess->GetSessionCount();

    if (this->game_count > 0) {
        this->list->empty_list();
        int i = 0;
        if (i < this->game_count) {
            do {
                sprintf(szTemp, "%s ( %.1d / %.1d )",
                    Sess->GetSessionName(i),
                    Sess->GetSessionCurrentPlayers(i),
                    Sess->GetSessionMaxPlayers(i));
                this->list->append_line(szTemp, 0);
                i++;
            } while (i < this->game_count);
        }
        this->set_curr_child(this->list);
    } else {
        this->list->set_text(0x25AB);
    }

    this->listFilled = 1;
}

long TribeJoinScreen::action(TPanel* panel, long command,
                             unsigned long param3, unsigned long param4)
{
    if (panel == 0)
        return TEasy_Panel::action(panel, command, param3, param4);

    if (panel == this->list) {
        if (command == 3 && this->game_count > 0) {
            this->action(this->joinButton, 1, 0, 0);
            return 1;
        }
        return 1;
    }

    if (panel == this->joinButton) {
        if (command == 1) {
            if (this->game_count > 0) {
                int line = this->list->currentLineNumber();
                GUID* guid = Sess->GetSessionGUID(line);
                int join_result = comm->JoinMultiplayerGame(guid);
                if (join_result == 0) {
                    char temp[256];
                    char string[256];
                    this->get_string(0x25A3, temp, 0x100);
                    sprintf(string, temp, this->list->currentLine());
                    TEasy_Panel::popupOKDialog(string, 0, 0x1C2, 100);
                    return 1;
                }

                rge_base_game->disable_input();
                this->waitingToStart = 1;
                this->joinTime = debug_timeGetTime(
                    "C:\\msdev\\work\\age1_x1\\scr_cj.cpp", 0x140);
                return 1;
            }

            TEasy_Panel::popupOKDialog(0x25A4, 0, 0x1C2, 100);
            return 1;
        }
        return 1;
    }

    if (panel == this->cancelButton) {
        if (command == 1) {
            rge_base_game->disable_input();
            comm->UnlinkToLevel(SINGLE_PLAYER);
            new TribeMPStartupScreen;
            panel_system.setCurrentPanel("MP Startup Screen", 0);
            panel_system.destroyPanel("Join Screen");
            return 1;
        }
        return 1;
    }

    if (panel == this->createButton && command == 1) {
        new TribeMPCreateDialog(this);
        return 1;
    }

    if (panel == this->refreshButton) {
        if (command == 1) {
            this->fillList();
            return 1;
        }
        return 1;
    }

    if (panel != this->close_button || command != 1)
        return TEasy_Panel::action(panel, command, param3, param4);

    rge_base_game->close();
    return 1;
}

TribeMPCreateDialog::TribeMPCreateDialog(TPanel* parent)
    : TDialogPanel("Create Dialog")
{
    TEditPanel** inputGamename = &this->inputGamename;
    this->title = 0;
    this->input_title = 0;
    *inputGamename = 0;
    this->okButton = 0;
    this->cancelButton = 0;

    if (this->setup(parent->renderArea(), parent, 500, 230,
                    static_cast<TEasy_Panel*>(parent)->get_popup_info_file(),
                    static_cast<TEasy_Panel*>(parent)->get_popup_info_id(), 1)) {
        if (this->create_text(this, &this->title, 0x25a6,
                              20, 20, 0x1cc, 0x1e, 1, 1, 1, 0)) {
            if (this->create_text(this, &this->input_title, 0x25aa,
                                  40, 0x55, 0x1a4, 20, 4, 0, 1, 0)) {
                char str[256];
                char* s = Regs->RegGetAscii(
                    1, "Default Age Of Empires MP Gamename");
                if (s) {
                    strcpy(str, Regs->RegGetAscii(
                        1, "Default Age Of Empires MP Gamename"));
                } else {
                    str[0] = 0;
                }
                if (this->create_edit(this, inputGamename, str,
                                      40, 0, 40, 0x6e, 0x1a4, 0x17,
                                      0xb, 1, 0)) {
                    if (this->create_button(this, &this->okButton,
                                            0x0fa1, 0, 0x3c, 0xb4,
                                            0xb4, 0x1e, 0, 0, 0)) {
                        if (this->create_button(this, &this->cancelButton,
                                                0x0fa2, 0, 0x104, 0xb4,
                                                0xb4, 0x1e, 0, 0, 0)) {
                            TButtonPanel* cancel = this->cancelButton;
                            cancel->hotkey = 0x1b;
                            cancel->hotkey_shift = 0;
                            TPanel* tab_list[3];
                            tab_list[0] = this->inputGamename;
                            tab_list[1] = this->okButton;
                            tab_list[2] = this->cancelButton;
                            this->set_tab_order(tab_list, 3);
                            this->set_curr_child(this->inputGamename);
                        }
                    }
                }
            }
        }
    }
}

TribeMPCreateDialog::~TribeMPCreateDialog() {
    delete this->title;
    delete this->input_title;
    delete this->inputGamename;
    delete this->okButton;
    delete this->cancelButton;
}

long TribeMPCreateDialog::action(TPanel* panel, long command,
                                 unsigned long param3, unsigned long param4)
{
    if (panel != 0) {
        if ((panel == this->okButton && command == 1) ||
            (panel == this->inputGamename && command == 0)) {
            if (this->inputGamename->is_blank()) {
                this->set_curr_child(this->inputGamename);
                return 1;
            }

            rge_base_game->disable_input();
            Regs->RegSetAscii(1, "Default Age Of Empires MP Gamename",
                              static_cast<unsigned char*>(static_cast<void*>(
                                  this->inputGamename->currentLine())),
                              strlen(this->inputGamename->currentLine()) + 1);
            comm->SetGameTitle(this->inputGamename->currentLine());

            TDrawArea* draw_area = this->render_area;
            L->Log("$$$ CALLING CreateMultiplayerGame");
            panel_system.setCurrentPanel("Join Screen", 0);
            rge_base_game->draw_window();

            _GUID service_guid = comm->ServiceGUID;
            if (memcmp(&service_guid, &DPSPGUID_TCPIP, sizeof(_GUID)) == 0)
                static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(
                    0x4C3, "scr3", 0xC385);
            else
                static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(
                    0x4C2, "scr3", 0xC385);
            rge_base_game->draw_window();
            WinExec("data\\closedpw.exe", 0);

            if (draw_area->DrawSystem->DrawType == 2 &&
                draw_area->DrawSystem->ScreenMode == 2)
                draw_area->DrawSystem->DirDraw->FlipToGDISurface();

            memset(&comm->PlayerStopTurn[1], 0,
                   9 * sizeof(comm->PlayerStopTurn[0]));
            int create_result = comm->CreateMultiplayerGame();
            L->Log("$$$ RETURNED FROM CreateMultiplayerGame");

            void* window = FindWindowA("closedpw", "closedpw");
            if (window != 0)
                SendMessageA(window, 0x10, 0, 0);

            if (create_result != 0) {
                new TribeMPSetupScreen;
                panel_system.setCurrentPanel("MP Setup Screen", 0);
                panel_system.destroyPanel("Status Screen");
                panel_system.destroyPanel("Create Dialog");
                panel_system.destroyPanel("Join Screen");
                return 1;
            }

            TEasy_Panel* parent = static_cast<TEasy_Panel*>(
                this->parent_panel);
            panel_system.destroyPanel("Create Dialog");
            panel_system.setCurrentPanel("Join Screen", 0);
            panel_system.destroyPanel("Status Screen");
            parent->popupOKDialog(0x25AD, 0, 0x1C2, 100);
            return 1;
        }

        if ((panel == this->cancelButton && command == 1) ||
            (panel == this->inputGamename && command == 1)) {
            panel_system.setCurrentPanel("Join Screen", 0);
            panel_system.destroyPanel("Create Dialog");
            return 1;
        }
    }

    return TPanel::action(panel, command, param3, param4);
}
