// PDB source module: C:\\msdev\\work\\age1_x1\\scr_mp.cpp.
// Definitions follow the original PDB source order.

#include <string.h>
#include <io.h>
#include "../include/com_serv.h"
#include "../include/scr_mp.h"
#include "../include/Pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/pnl_edit.h"
#include "../include/Pnl_scbr.h"
#include "../include/registry.h"
#include "../include/com_hand.h"
#include "../include/basegame.h"
#include "../include/scr_main.h"
#include "../include/scr_cj.h"

extern TRegistry* Regs;
extern TCommunications_Handler* comm;

// VA: 0049F370 TribeMPStartupScreen constructor (1278B)
// FLAGS: config/flags/0049F370_TribeMPStartupScreen.rsp (/GX for EH cleanup).

TribeMPStartupScreen::TribeMPStartupScreen()
    : TScreenPanel("MP Startup Screen")
{
    TButtonPanel** cancel_button;
    TButtonPanel** ok_button;
    TButtonPanel* cancel;
    HKEY ghUserKey;
    unsigned long dwSize;
    unsigned long dwType;
    unsigned long gdwDisp;
    char Data[256];
    char temp_str[256];
    char str[256];
    cancel_button = &this->cancelButton;
    this->help_button = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->close_button = 0;

    rge_base_game->setMultiplayerGame(0);
    if (this->setup(rge_base_game->draw_area, "scr3", 0xC385, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x258B,
                          0x14, 0x14, 600, 0x1E, 1, 1, 0, 0) &&
        this->create_text(this, &this->inputTitle, 0x258C,
                          0x14, 0x4B, 500, 0x14, 4, 0, 0, 0)) {
        char* player_name = Regs->RegGetAscii(
            1, "Default Age Of Empires Player Name");
        if (player_name != 0) {
            strcpy(str, Regs->RegGetAscii(
                1, "Default Age Of Empires Player Name"));
        } else {
            str[0] = 0;
        }

        if (this->create_edit(this, &this->input, str, 0x0F, 0,
                              0x14, 100, 600, 0x17, 0x0B, 1, 0)) {
            this->input->set_help_info(0x7595, -1);
            if (this->create_text(this, &this->connectionTitle, 0x258D,
                                  0x14, 0xA5, 600, 0x14, 4, 0, 0, 0) &&
                this->create_list(this, &this->list,
                                  0x14, 0xBE, 600, 0xD2, 0x0B) &&
                this->create_auto_scrollbar(&this->scrollbar, this->list,
                                            0x14)) {
                this->list->set_help_info(0x7596, 0x25F08);
                ok_button = &this->okButton;
                if (this->create_button(this, ok_button, 0x0FA1,
                                        0, 0x46, 0x1B8, 0xF0, 0x1E,
                                        0, 0, 0)) {
                    (*ok_button)->set_help_info(0x7531, -1);
                    if (this->create_button(this, cancel_button, 0x0FA2,
                                            0, 0x14A, 0x1B8, 0xF0, 0x1E,
                                            0, 0, 0)) {
                        (*cancel_button)->set_help_info(0x7532, -1);
                        cancel = *cancel_button;
                        cancel->hotkey = 0x1B;
                        cancel->hotkey_shift = 0;
                        if (this->create_button(this, &this->help_button,
                                                0x0FA9, 0, 0x244, 0x1B8,
                                                0x1E, 0x1E, 0, 0, 0)) {
                            if (this->create_button(this,
                                                    &this->close_button,
                                                    0x03EA, 0, 0, 0, 0, 0,
                                                    -1, -1, 0)) {
                                this->close_button->set_active(1);
                                this->close_button->set_positioning(
                                    TPanel::PositionRightTop, 4, 4, 4, 4,
                                    0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);

                                this->zone_exec[0] = 0;
                                this->browser_exec[0] = 0;
                                RegCreateKeyExA(
                                    HKEY_CURRENT_USER,
                                    "http\\shell\\open\\command", 0, 0, 0,
                                    0xF003F, 0, &ghUserKey, &gdwDisp);
                                dwType = 1;
                                dwSize = 0xFF;
                                int result = RegQueryValueExA(
                                    ghUserKey, 0, 0, &dwType,
                                    static_cast<unsigned char*>(static_cast<void*>(Data)),
                                    &dwSize);
                                if (ghUserKey != 0) {
                                    RegCloseKey(ghUserKey);
                                    ghUserKey = 0;
                                }

                                if (result == 0) {
                                    char* command = Data;
                                    ++command;
                                    strncpy(temp_str, command, strlen(Data));
                                    char* quote = strchr(temp_str, 0x22);
                                    if (quote != 0) {
                                        int length = quote - temp_str + 1;
                                        strncpy(browser_exec, temp_str,
                                                length - 1);
                                        browser_exec[length - 1] = 0;
                                    }

                                    char* zone = Regs->RegGetAscii(0, "Zone");
                                    if (zone != 0) {
                                        strcpy(Data, zone);
                                        strcpy(this->zone_exec, Data);
                                    }
                                }

                                this->fillList();
                                this->set_curr_child(this->input);
                                TPanel* tabList[5];
                                tabList[0] = this->input;
                                tabList[1] = this->list;
                                tabList[2] = this->okButton;
                                tabList[3] = this->cancelButton;
                                tabList[4] = this->help_button;
                                this->set_tab_order(tabList, 5);
                            }
                        }
                    }
                }
            }
        }
    }
}

// VA: 0049F890 ~TribeMPStartupScreen dtor (257B)
// FLAGS: config/flags/0049F890_TribeMPStartupScreen.rsp.

TribeMPStartupScreen::~TribeMPStartupScreen() {
    delete this->title;
    delete this->inputTitle;
    delete this->input;
    delete this->connectionTitle;
    delete this->list;
    delete this->scrollbar;
    delete this->okButton;
    delete this->cancelButton;
    delete this->help_button;
    delete this->close_button;

    panel_system.destroyPanel("Create Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");
}

// VA: 0049F9A0 TribeMPStartupScreen::handle_idle (33B)

long TribeMPStartupScreen::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

// VA: 0049F9D0 TribeMPStartupScreen::action (1265B)

long TribeMPStartupScreen::action(TPanel* panel, long event,
                                  unsigned long param3, unsigned long param4)
{
    if (panel != 0) {
        if (panel == this->list && event == 3) {
            this->action(this->okButton, 1, 0, 0);
            return 1;
        }

        if (panel == this->close_button && event == 1) {
            rge_base_game->close();
            return 1;
        }

        if (panel == this->okButton && event == 1) {
            rge_base_game->setMultiplayerGame(1);
            if (*this->input->get_text() == 0) {
                this->popupOKDialog(0x258F, "Name Error", 0x1C2, 100);
                return event;
            } else if (this->list->numberLines() == 0) {
                this->popupOKDialog(0x2592, "List Error", 0x1C2, 100);
                return 1;
            } else if (this->zone_exec[0] == 0 || this->list->get_id() != -1) {
                rge_base_game->disable_input();
                Regs->RegSetAscii(
                    1, "Default Age Of Empires Player Name",
                    static_cast<unsigned char*>(static_cast<void*>(
                        this->input->currentLine())),
                    strlen(this->input->currentLine()) + 1);
                Regs->RegSetAscii(
                    1, "Default Age Of Empires Multiplayer Service",
                    static_cast<unsigned char*>(static_cast<void*>(
                        this->list->get_text())),
                    strlen(this->list->get_text()) + 1);
                comm->SetMyPlayerName(this->input->currentLine());

                TCommunications_Services services;
                comm->SetServiceGUID(
                    services.GetServiceGUID(this->list->get_id()));
                comm->InitJoinGame();

                new TribeJoinScreen;
                panel_system.setCurrentPanel("Join Screen", 0);
                panel_system.destroyPanel("MP Startup Screen");
                return 1;
            } else {
                this->popupYesNoDialog(0x2593, "Start Zone", 0x1C2, 100);
                return 1;
            }
        }

        if ((panel == this->cancelButton && event == 1) ||
            (panel == this->input && event == 1)) {
            rge_base_game->disable_input();
            comm->UnlinkToLevel(SINGLE_PLAYER);
            new TRIBE_Screen_Main_Menu;
            panel_system.setCurrentPanel("Main Menu", 0);
            panel_system.destroyPanel("MP Startup Screen");
            return 1;
        }

        if (panel == this->help_button && event == 1) {
            this->setup_popup_help();
            return event;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "List Error") == 0) {
            panel_system.destroyPanel("List Error");
            this->set_curr_child(this->list);
            event = 1;
            return event;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Name Error") == 0) {
            panel_system.destroyPanel("Name Error");
            this->set_curr_child(this->input);
            event = 1;
            return event;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Start Zone") == 0) {
            panel_system.destroyPanel("Start Zone");
            this->set_curr_child(this->list);
            if (event == 0) {
                rge_base_game->disable_input();
                WinExec(this->zone_exec, 3);
                rge_base_game->close();
            }
            return 1;
        }
    }

    return this->TEasy_Panel::action(panel, event, param3, param4);
}

// VA: 0049FED0 TribeMPStartupScreen::fillList (461B)

void TribeMPStartupScreen::fillList() {
    int lastServiceNumber;
    char lastServiceName[256];
    struct _finddata_t file_info;

    this->list->empty_list();
    TCommunications_Services Serv;
    int serviceCount = Serv.GetServiceCount();

    lastServiceNumber = -1;
    if (Regs->RegGetAscii(1,
                          "Default Age Of Empires Multiplayer Service")) {
        strcpy(lastServiceName, Regs->RegGetAscii(
            1, "Default Age Of Empires Multiplayer Service"));
    } else {
        strcpy(lastServiceName, "");
    }

    int i = 0;
    if (serviceCount > 0) {
        do {
            if (Serv.GetServiceActive(i) && Serv.GetServiceName(i)) {
                this->list->append_line(Serv.GetServiceName(i), i);
                if (strcmp(Serv.GetServiceName(i), lastServiceName) == 0) {
                    lastServiceNumber = i;
                }
            }
            i++;
        } while (i < serviceCount);
    }

    if (_findfirst(this->browser_exec, &file_info) != -1 &&
        this->zone_exec[0]) {
        this->list->append_line(0x258E, -1);
    }

    if (lastServiceNumber != -1) {
        this->list->set_line(this->list->get_line(lastServiceNumber));
    }
}

// VA: 004A00A0 TribeMPStartupScreen::handle_user_command (8B)

long TribeMPStartupScreen::handle_user_command(unsigned int p0, long p1) {
    return 1;
}
