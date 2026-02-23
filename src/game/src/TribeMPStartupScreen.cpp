#include "../include/TribeMPStartupScreen.h"

#include "../include/TribeJoinScreen.h"
#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TCommunications_Services.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TEditPanel.h"
#include "../include/TListPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TRegistry.h"
#include "../include/globals.h"

#include <io.h>
#include <stdio.h>
#include <string.h>

namespace {

static const char kScrMpSourcePath[] = "C:\\msdev\\work\\age1_x1\\scr_mp.cpp";

static const char kRegDefaultPlayerName[] = "Default Age Of Empires Player Name";
static const char kRegDefaultMultiplayerService[] = "Default Age Of Empires Multiplayer Service";
static const char kRegZone[] = "Zone";

static const char kHttpShellOpenCommand[] = "http\\shell\\open\\command";

static const char kNameErrorPanel[] = "Name Error";
static const char kListErrorPanel[] = "List Error";
static const char kStartZonePanel[] = "Start Zone";

} // namespace

namespace tribe_mp_ui {
// Implemented in TribeJoinScreen.cpp (scr_cj/scr_mp depend on these comm helpers).
long InitJoinGame(TCommunications_Handler* comm_handler);
void SetMyPlayerName(TCommunications_Handler* comm_handler, char* name);
void SetServiceGUID(TCommunications_Handler* comm_handler, _GUID guid);
} // namespace tribe_mp_ui

TribeMPStartupScreen::TribeMPStartupScreen() : TScreenPanel((char*)"MP Startup Screen") {
    // Source of truth: scr_mp.cpp.decomp @ 0x0049F370
    this->title = nullptr;
    this->inputTitle = nullptr;
    this->input = nullptr;
    this->connectionTitle = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->help_button = nullptr;
    this->close_button = nullptr;
    this->list = nullptr;
    this->scrollbar = nullptr;
    this->zone_exec[0] = '\0';
    this->browser_exec[0] = '\0';

    if (rge_base_game != nullptr) {
        rge_base_game->setMultiplayerGame(0);
    }

    if (rge_base_game == nullptr || rge_base_game->draw_area == nullptr) {
        this->error_code = 1;
        return;
    }

    if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr3", 0xc385, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    if (!this->create_text((TPanel*)this, &this->title, 0x258b, 0x14, 0x14, 600, 0x1e, 1, 1, 0, 0)) {
        return;
    }
    if (!this->create_text((TPanel*)this, &this->inputTitle, 0x258c, 0x14, 0x4b, 500, 0x14, 4, 0, 0, 0)) {
        return;
    }

    char player_name[256];
    player_name[0] = '\0';
    if (Regs != nullptr) {
        char* saved = Regs->RegGetAscii(1, kRegDefaultPlayerName);
        if (saved != nullptr) {
            strncpy(player_name, saved, sizeof(player_name) - 1);
            player_name[sizeof(player_name) - 1] = '\0';
        }
    }

    if (!this->create_edit((TPanel*)this, &this->input, player_name, 0xf, FormatAny, 0x14, 100, 600, 0x17, 0xb, 1, 0)) {
        return;
    }
    if (this->input != nullptr) {
        this->input->set_help_info(0x7595, -1);
    }

    if (!this->create_text((TPanel*)this, &this->connectionTitle, 0x258d, 0x14, 0xa5, 600, 0x14, 4, 0, 0, 0)) {
        return;
    }
    if (!this->create_list((TPanel*)this, &this->list, 0x14, 0xbe, 600, 0xd2, 0xb)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->scrollbar, (TTextPanel*)this->list, 0x14)) {
        return;
    }
    if (this->list != nullptr) {
        this->list->set_help_info(0x7596, 0x25f08);
    }

    if (!this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x46, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        return;
    }
    if (this->okButton != nullptr) {
        this->okButton->set_help_info(0x7531, -1);
    }

    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x14a, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        return;
    }
    if (this->cancelButton != nullptr) {
        this->cancelButton->set_help_info(0x7532, -1);
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }

    if (!this->create_button((TPanel*)this, &this->help_button, 0xfa9, 0, 0x244, 0x1b8, 0x1e, 0x1e, 0, 0, 0)) {
        return;
    }

    if (!this->create_button((TPanel*)this, &this->close_button, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0)) {
        return;
    }
    if (this->close_button != nullptr) {
        this->close_button->set_active(1);
        this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);
    }

    // Try to resolve the default browser executable from HKCR\http\shell\open\command.
    this->zone_exec[0] = '\0';
    this->browser_exec[0] = '\0';
    {
        HKEY hKey = nullptr;
        DWORD disp = 0;
        LONG rc = RegCreateKeyExA(HKEY_CLASSES_ROOT, kHttpShellOpenCommand, 0, nullptr, 0, KEY_ALL_ACCESS, nullptr, &hKey, &disp);
        if (rc == ERROR_SUCCESS && hKey != nullptr) {
            DWORD type = 1;
            DWORD size = 0xff;
            char data[255];
            data[0] = '\0';
            if (RegQueryValueExA(hKey, nullptr, nullptr, &type, (BYTE*)data, &size) == ERROR_SUCCESS) {
                char temp_str[255];
                strncpy(temp_str, data, sizeof(temp_str) - 1);
                temp_str[sizeof(temp_str) - 1] = '\0';
                char* quote = strchr(temp_str, '"');
                if (quote != nullptr) {
                    const size_t prefix = (size_t)(quote - temp_str);
                    const size_t copy_len = (prefix < sizeof(this->browser_exec) - 1) ? prefix : sizeof(this->browser_exec) - 1;
                    strncpy(this->browser_exec, temp_str, copy_len);
                    this->browser_exec[copy_len] = '\0';
                }
            }
            RegCloseKey(hKey);
        }
    }

    if (Regs != nullptr) {
        char* zone = Regs->RegGetAscii(0, kRegZone);
        if (zone != nullptr) {
            strncpy(this->zone_exec, zone, sizeof(this->zone_exec) - 1);
            this->zone_exec[sizeof(this->zone_exec) - 1] = '\0';
        }
    }

    this->fillList();
    this->set_curr_child((TPanel*)this->input);

    TPanel* tabList[5];
    tabList[0] = (TPanel*)this->input;
    tabList[1] = (TPanel*)this->list;
    tabList[2] = (TPanel*)this->okButton;
    tabList[3] = (TPanel*)this->cancelButton;
    tabList[4] = (TPanel*)this->help_button;
    this->set_tab_order(tabList, 5);
}

TribeMPStartupScreen::~TribeMPStartupScreen() {
    // Source of truth: scr_mp.cpp.decomp @ 0x0049F890
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->inputTitle);
    this->delete_panel((TPanel**)&this->input);
    this->delete_panel((TPanel**)&this->connectionTitle);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);
    this->delete_panel((TPanel**)&this->close_button);

    if (panel_system != nullptr) {
        panel_system->destroyPanel((char*)"Create Dialog");
        panel_system->destroyPanel((char*)"OKDialog");
        panel_system->destroyPanel((char*)"YesNoDialog");
    }
}

long TribeMPStartupScreen::handle_idle() {
    // Fully verified. Source of truth: scr_mp.cpp.decomp @ 0x0049F9A0
    if (rge_base_game != nullptr && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeMPStartupScreen::handle_user_command(uint /*param_1*/, long /*param_2*/) {
    // Source of truth: scr_mp.cpp.decomp @ 0x004A00A0
    return 1;
}

long TribeMPStartupScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: scr_mp.cpp.decomp @ 0x0049F9D0
    if (param_1 == nullptr) {
        return TEasy_Panel::action(param_1, param_2, param_3, param_4);
    }

    if ((TListPanel*)param_1 == this->list && param_2 == 3) {
        (void)this->action((TPanel*)this->okButton, 1, 0, 0);
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->close_button && param_2 == 1) {
        if (rge_base_game != nullptr) {
            rge_base_game->close();
        }
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->okButton && param_2 == 1) {
        if (rge_base_game != nullptr) {
            rge_base_game->setMultiplayerGame(1);
        }

        char* name_text = (this->input != nullptr) ? this->input->get_text() : (char*)"";
        if (name_text == nullptr || name_text[0] == '\0') {
            this->popupOKDialog(0x258f, (char*)kNameErrorPanel, 0x1c2, 100);
            return 1;
        }

        const int num_lines = (this->list != nullptr) ? this->list->numberLines() : 0;
        if (num_lines == 0) {
            this->popupOKDialog(0x2592, (char*)kListErrorPanel, 0x1c2, 100);
            return 1;
        }

        const long selected_id = (this->list != nullptr) ? this->list->get_id() : -1;
        if (this->zone_exec[0] == '\0' || selected_id != -1) {
            if (rge_base_game != nullptr) {
                rge_base_game->disable_input();
            }

            char* name_line = (this->input != nullptr) ? this->input->currentLine() : name_text;
            if (name_line == nullptr) {
                name_line = (char*)"";
            }

            if (Regs != nullptr) {
                const unsigned long len = (unsigned long)strlen(name_line) + 1;
                (void)Regs->RegSetAscii(1, kRegDefaultPlayerName, (uchar*)name_line, len);
            }

            char* service_name = nullptr;
            if (this->list != nullptr) {
                service_name = this->list->currentLine();
            }
            if (service_name == nullptr) {
                service_name = (char*)"";
            }
            if (Regs != nullptr) {
                const unsigned long len = (unsigned long)strlen(service_name) + 1;
                (void)Regs->RegSetAscii(1, kRegDefaultMultiplayerService, (uchar*)service_name, len);
            }

            TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
            if (comm_handler != nullptr) {
                tribe_mp_ui::SetMyPlayerName(comm_handler, name_line);

                TCommunications_Services services;
                const _GUID guid = services.GetServiceGUID((int)selected_id);
                tribe_mp_ui::SetServiceGUID(comm_handler, guid);
                (void)tribe_mp_ui::InitJoinGame(comm_handler);
            }

            (void)new TribeJoinScreen();
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Join Screen", 0);
                panel_system->destroyPanel((char*)"MP Startup Screen");
            }
            return 1;
        }

        this->popupYesNoDialog(0x2593, (char*)kStartZonePanel, 0x1c2, 100);
        return 1;
    }

    if (((TButtonPanel*)param_1 == this->cancelButton && param_2 == 1) ||
        ((TEditPanel*)param_1 == this->input && param_2 == 1)) {
        if (rge_base_game != nullptr) {
            rge_base_game->disable_input();
        }

        if (comm != nullptr) {
            ((TCommunications_Handler*)comm)->UnlinkToLevel(SINGLE_PLAYER);
        }

        (void)new TRIBE_Screen_Main_Menu();
        if (panel_system != nullptr) {
            panel_system->setCurrentPanel((char*)"Main Menu", 0);
            panel_system->destroyPanel((char*)"MP Startup Screen");
        }
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->help_button && param_2 == 1) {
        this->setup_popup_help();
        return 1;
    }

    // Dialog return handling (panelName compares).
    const char* panel_name = param_1->panelName();
    if (panel_name != nullptr) {
        if (_stricmp(panel_name, kListErrorPanel) == 0) {
            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)kListErrorPanel);
            }
            this->set_curr_child((TPanel*)this->list);
            return 1;
        }

        if (_stricmp(panel_name, kNameErrorPanel) == 0) {
            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)kNameErrorPanel);
            }
            this->set_curr_child((TPanel*)this->input);
            return 1;
        }

        if (_stricmp(panel_name, kStartZonePanel) == 0) {
            if (panel_system != nullptr) {
                panel_system->destroyPanel((char*)kStartZonePanel);
            }
            this->set_curr_child((TPanel*)this->list);

            if (param_2 == 0) {
                if (rge_base_game != nullptr) {
                    rge_base_game->disable_input();
                }
                WinExec(this->zone_exec, 3);
                if (rge_base_game != nullptr) {
                    rge_base_game->close();
                }
            }
            return 1;
        }
    }

    (void)kScrMpSourcePath; // keep file-string parity anchor for debug_timeGetTime usage patterns
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

void TribeMPStartupScreen::fillList() {
    // Source of truth: scr_mp.cpp.decomp @ 0x0049FED0
    if (this->list == nullptr) {
        return;
    }

    this->list->empty_list();

    TCommunications_Services services;
    const int service_count = services.GetServiceCount();

    int lastServiceNumber = -1;
    char lastServiceName[256];
    lastServiceName[0] = '\0';

    if (Regs != nullptr) {
        char* saved = Regs->RegGetAscii(1, kRegDefaultMultiplayerService);
        if (saved != nullptr) {
            strncpy(lastServiceName, saved, sizeof(lastServiceName) - 1);
            lastServiceName[sizeof(lastServiceName) - 1] = '\0';
        }
    }

    for (int i = 0; i < service_count; ++i) {
        if (services.GetServiceActive(i) == 0) {
            continue;
        }

        char* name = services.GetServiceName(i);
        if (name == nullptr) {
            continue;
        }

        this->list->append_line(name, i);
        if (strcmp(name, lastServiceName) == 0) {
            lastServiceNumber = i;
        }
    }

    _finddata_t file_info;
    const int browser_found = _findfirst(this->browser_exec, &file_info);
    if (browser_found != -1 && this->zone_exec[0] != '\0') {
        this->list->append_line(0x258e, -1);
    }

    if (lastServiceNumber != -1) {
        const long line = this->list->get_line(lastServiceNumber);
        if (line != -1) {
            this->list->set_line(line);
        }
    }
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TribeMPStartupScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5,
                                long param_6, uchar param_7) {
    return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void TribeMPStartupScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeMPStartupScreen::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TScreenPanel::set_rect(param_1, param_2, param_3, param_4);
}
void TribeMPStartupScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeMPStartupScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeMPStartupScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5,
                                           long param_6, long param_7, long param_8, long param_9, TPanel* param_10,
                                           TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                  param_10, param_11, param_12, param_13);
}
void TribeMPStartupScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {
    TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4);
}
void TribeMPStartupScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeMPStartupScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) {
    TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3);
}
void TribeMPStartupScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeMPStartupScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeMPStartupScreen::draw() { TScreenPanel::draw(); }
void TribeMPStartupScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeMPStartupScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) {
    TScreenPanel::draw_offset(param_1, param_2, param_3);
}
void TribeMPStartupScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeMPStartupScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) {
    TScreenPanel::draw_offset2(param_1, param_2, param_3);
}
void TribeMPStartupScreen::paint() { TScreenPanel::paint(); }
long TribeMPStartupScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeMPStartupScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeMPStartupScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5);
}
long TribeMPStartupScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeMPStartupScreen::handle_command(uint param_1, long param_2) {
    return TScreenPanel::handle_command(param_1, param_2);
}
long TribeMPStartupScreen::handle_timer_command(uint param_1, long param_2) {
    return TScreenPanel::handle_timer_command(param_1, param_2);
}
long TribeMPStartupScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeMPStartupScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}
long TribeMPStartupScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5);
}
long TribeMPStartupScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5);
}
long TribeMPStartupScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4);
}
long TribeMPStartupScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5);
}
long TribeMPStartupScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeMPStartupScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeMPStartupScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeMPStartupScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeMPStartupScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeMPStartupScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeMPStartupScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4);
}
void TribeMPStartupScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeMPStartupScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeMPStartupScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeMPStartupScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeMPStartupScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeMPStartupScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeMPStartupScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5,
                                       long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                       param_10, param_11);
}
int TribeMPStartupScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5,
                                       long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                       param_10, param_11);
}
int TribeMPStartupScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5,
                                          long param_6, long param_7, long param_8) {
    return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TribeMPStartupScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4,
                                             long param_5, long param_6, long param_7, long param_8) {
    return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TribeMPStartupScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5,
                                     long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11);
}
int TribeMPStartupScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5,
                                     long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) {
    return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11);
}
int TribeMPStartupScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5,
                                     long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11);
}
int TribeMPStartupScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4,
                                      FormatType param_5, long param_6, long param_7, long param_8, long param_9,
                                      long param_10) {
    return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                      param_10);
}
int TribeMPStartupScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5,
                                     long param_6, long param_7, long param_8, long param_9, long param_10, int param_11,
                                     int param_12) {
    return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11, param_12);
}
int TribeMPStartupScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4,
                                          long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int TribeMPStartupScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5,
                                     long param_6, long param_7) {
    return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
int TribeMPStartupScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4,
                                          long param_5, long param_6, long param_7, long param_8) {
    return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TribeMPStartupScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) {
    return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3);
}
int TribeMPStartupScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4,
                                            long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8,
                                           param_9);
}
int TribeMPStartupScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4,
                                            long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8,
                                           param_9);
}
void TribeMPStartupScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) {
    TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5);
}

