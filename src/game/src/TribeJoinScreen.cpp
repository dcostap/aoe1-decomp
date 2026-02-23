#include "../include/TribeJoinScreen.h"

#include "../include/TribeMPCreateDialog.h"
#include "../include/TribeMPSetupScreen.h"
#include "../include/TribeMPStartupScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TButtonPanel.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TCommunications_Sessions.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/RGE_Lobby.h"
#include "../include/TChat.h"
#include "../include/TDebuggingLog.h"
#include "../include/TEditPanel.h"
#include "../include/TListPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRegistry.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"

#include "dialog_forwarders.h"

#include <dplay.h>
#include <new>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace {

static const char kScrCjSourcePath[] = "C:\\msdev\\work\\age1_x1\\scr_cj.cpp";
static const char kComHandSourcePath[] = "C:\\msdev\\work\\age1_x1\\Com_hand.c";

static const char kRegDefaultMpGamename[] = "Default Age Of Empires MP Gamename";

static const char kClosedPwExe[] = "data\\closedpw.exe";
static const char kClosedPwWindow[] = "closedpw";

static const char kFmtSessionLine[] = "%s ( %.1d / %.1d )";

static TCommunications_Sessions* Sess = nullptr;
static DPID s_self_dpid = 0;

static void tribe_mp_set_random_seed(TCommunications_Handler* comm_handler, int seed) {
    // Source of truth: com_hand.cpp.decomp SetRandomSeed @ 0x0042CA20 (minimal)
    if (comm_handler == nullptr) {
        return;
    }

    if (comm_handler->MeHost != 0) {
        if (seed == -1) {
            const ulong t = debug_timeGetTime(kComHandSourcePath, 0x1320);
            debug_srand(kComHandSourcePath, 0x1320, (uint)t);
            seed = debug_rand(kComHandSourcePath, 0x1321);
        }
        comm_handler->PlayerOptions.RandomSeed = (uint)seed;
        comm_handler->PlayerOptions.NeedsToBeSent = 1;
        (void)comm_handler->SendSharedData(0);
    }
}

static long tribe_mp_get_my_multiplayer_caps(TCommunications_Handler* comm_handler) {
    if (comm_handler == nullptr || comm_handler->Lobby == nullptr || comm_handler->Lobby->glpDP == nullptr) {
        return -0x7fffbffb;
    }
    if (s_self_dpid == 0) {
        return -0x7fffbffb;
    }

    DPCAPS caps;
    memset(&caps, 0, sizeof(caps));
    caps.dwSize = sizeof(caps);
    const HRESULT hr = comm_handler->Lobby->glpDP->GetPlayerCaps(s_self_dpid, &caps, 0);
    if (FAILED(hr)) {
        return (long)hr;
    }

    comm_handler->dwFlags = 1;
    comm_handler->dwMaxBufferSize = caps.dwMaxBufferSize;
    comm_handler->dwMaxQueueSize = caps.dwMaxQueueSize;
    comm_handler->dwMaxPlayers = caps.dwMaxPlayers;
    comm_handler->dwHundredBaud = caps.dwHundredBaud;
    comm_handler->dwLatency = caps.dwLatency;
    comm_handler->RGE_Guaranteed_Delivery = 1;
    return 0;
}

static long tribe_mp_comm_get_caps(TCommunications_Handler* comm_handler) {
    if (comm_handler == nullptr || comm_handler->Lobby == nullptr || comm_handler->Lobby->glpDP == nullptr) {
        return -0x7fffbffb;
    }

    DPCAPS caps;
    memset(&caps, 0, sizeof(caps));
    caps.dwSize = sizeof(caps);
    const HRESULT hr = comm_handler->Lobby->glpDP->GetCaps(&caps, 0);
    if (FAILED(hr)) {
        return (long)hr;
    }

    comm_handler->dwFlags = 1;
    comm_handler->dwMaxBufferSize = caps.dwMaxBufferSize;
    comm_handler->dwMaxQueueSize = caps.dwMaxQueueSize;
    comm_handler->dwMaxPlayers = caps.dwMaxPlayers;
    comm_handler->dwHundredBaud = caps.dwHundredBaud;
    comm_handler->dwLatency = caps.dwLatency;

    DPCAPS caps_guaranteed;
    memset(&caps_guaranteed, 0, sizeof(caps_guaranteed));
    caps_guaranteed.dwSize = sizeof(caps_guaranteed);
    const HRESULT hr_guaranteed = comm_handler->Lobby->glpDP->GetCaps(&caps_guaranteed, 1);
    comm_handler->RGE_Guaranteed_Delivery = (FAILED(hr_guaranteed) ? 0 : 1);

    return 0;
}

static long tribe_mp_dplay_get_session_desc(TCommunications_Handler* comm_handler) {
    if (comm_handler == nullptr || comm_handler->Lobby == nullptr || comm_handler->Lobby->glpDP == nullptr) {
        return -0x7fffbffb;
    }

    DWORD size = 0;
    HRESULT hr = comm_handler->Lobby->glpDP->GetSessionDesc(nullptr, &size);
    if (size == 0) {
        return (long)hr;
    }

    void* buf = calloc(size, 1);
    if (buf == nullptr) {
        return -0x7ff8fff2;
    }

    hr = comm_handler->Lobby->glpDP->GetSessionDesc(buf, &size);
    if (SUCCEEDED(hr)) {
        const DPSESSIONDESC2* desc = (const DPSESSIONDESC2*)buf;
        comm_handler->SessionGUID = desc->guidInstance;
        comm_handler->CurrentPlayers = desc->dwCurrentPlayers;
    }

    free(buf);
    return (long)hr;
}

static long tribe_mp_create_direct_play_conversation(TCommunications_Handler* comm_handler) {
    // Source of truth: com_hand.cpp.decomp CreateDirectPlayConversation @ 0x0042D4A0 (minimal)
    if (comm_handler == nullptr || comm_handler->Lobby == nullptr) {
        return -0x7fffbffb;
    }

    LPDIRECTPLAY dp = nullptr;
    const HRESULT hr = DirectPlayCreate(&comm_handler->ServiceGUID, &dp, nullptr);

    // Match decomp's ordering: check for an existing conversation after DirectPlayCreate.
    if (comm_handler->Lobby->glpDP != nullptr) {
        if (dp != nullptr) {
            (void)dp->Release();
        }
        return -0x7788fffb;
    }

    if (FAILED(hr) || dp == nullptr) {
        comm_handler->ServiceGUID = comm_handler->NullGUID;
        return (long)hr;
    }

    IDirectPlay2* dp2 = nullptr;
    const HRESULT hr2 = dp->QueryInterface(IID_IDirectPlay2A, (LPVOID*)&dp2);
    (void)dp->Release();

    if (FAILED(hr2) || dp2 == nullptr) {
        comm_handler->ServiceGUID = comm_handler->NullGUID;
        return (long)hr2;
    }

    comm_handler->Lobby->glpDP = dp2;
    return 0;
}

static int tribe_mp_add_self_player(TCommunications_Handler* comm_handler) {
    // Source of truth: com_hand.cpp.decomp AddSelfPlayer @ 0x0042D960 (minimal)
    if (comm_handler == nullptr || comm_handler->Lobby == nullptr || comm_handler->Lobby->glpDP == nullptr) {
        return 0;
    }

    DPNAME names;
    memset(&names, 0, sizeof(names));
    names.dwSize = sizeof(names);
    names.dwFlags = 0x10;
    names.lpszLongNameA = comm_handler->MyFriendlyName;

    s_self_dpid = 0;
    const HRESULT hr = comm_handler->Lobby->glpDP->CreatePlayer(&s_self_dpid, &names, 0, 0, 0, 0);
    if (FAILED(hr) || s_self_dpid == 0) {
        (void)comm_handler->CloseSession();
        (void)comm_handler->ReleaseComm();
        comm_handler->PlayerOptions.ProgramState = 0;
        return 0;
    }

    (void)tribe_mp_get_my_multiplayer_caps(comm_handler);
    return 1;
}

} // namespace

namespace tribe_mp_ui {

long InitJoinGame(TCommunications_Handler* comm_handler) {
    // Source of truth: com_hand.cpp.decomp InitJoinGame @ 0x0042DA50
    if (comm_handler == nullptr) {
        return 0;
    }

    if (comm_handler->Chat != nullptr) {
        comm_handler->Chat->ClearChat();
    }
    comm_handler->Multiplayer = 1;
    comm_handler->HaveHostInit = 0;
    comm_handler->MeHost = 0;
    comm_handler->GTDSerialNo = 0;

    return tribe_mp_create_direct_play_conversation(comm_handler);
}

void SetServiceGUID(TCommunications_Handler* comm_handler, _GUID guid) {
    // Source of truth: com_hand.cpp.decomp SetServiceGUID @ 0x0042DEE0
    if (comm_handler == nullptr) {
        return;
    }
    comm_handler->ServiceGUID = guid;
}

void SetMyPlayerName(TCommunications_Handler* comm_handler, char* name) {
    // Source of truth: com_hand.cpp.decomp SetMyPlayerName @ 0x0042D3E0
    if (comm_handler == nullptr || name == nullptr) {
        return;
    }

    strncpy(comm_handler->MyFriendlyName, name, sizeof(comm_handler->MyFriendlyName) - 1);
    comm_handler->MyFriendlyName[sizeof(comm_handler->MyFriendlyName) - 1] = '\0';

    static const char kOptionalInformation[] = "Optional Information";
    strncpy(comm_handler->MyFormalName, kOptionalInformation, sizeof(comm_handler->MyFormalName) - 1);
    comm_handler->MyFormalName[sizeof(comm_handler->MyFormalName) - 1] = '\0';
}

int SetGameTitle(TCommunications_Handler* comm_handler, char* title) {
    // Source of truth: com_hand.cpp.asm/.decomp SetGameTitle @ 0x0042D3B0
    if (comm_handler == nullptr || title == nullptr) {
        return 0;
    }

    sprintf(comm_handler->MyGameTitle, "%s [%s]", title, comm_handler->MyFriendlyName);
    return 1;
}

int JoinMultiplayerGame(TCommunications_Handler* comm_handler, _GUID* session_guid) {
    // Source of truth: com_hand.cpp.decomp JoinMultiplayerGame @ 0x0042DA80 (minimal)
    if (comm_handler == nullptr || comm_handler->Lobby == nullptr || comm_handler->Lobby->glpDP == nullptr ||
        session_guid == nullptr) {
        return 0;
    }

    DPSESSIONDESC2 desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x50;
    desc.guidInstance = *session_guid;
    desc.guidApplication = comm_handler->ApplicationGUID;

    comm_handler->SessionGUID = *session_guid;
    comm_handler->MeHost = 0;

    const HRESULT hr = comm_handler->Lobby->glpDP->Open(&desc, DPOPEN_JOIN);
    if (FAILED(hr)) {
        return 0;
    }

    if (!tribe_mp_add_self_player(comm_handler)) {
        return 0;
    }

    comm_handler->PlayerOptions.ProgramState = 3;
    return 1;
}

int CreateMultiplayerGame(TCommunications_Handler* comm_handler) {
    // Source of truth: com_hand.cpp.decomp CreateMultiplayerGame @ 0x0042D590 (minimal)
    if (comm_handler == nullptr) {
        return 0;
    }

    if (comm_handler->Chat != nullptr) {
        comm_handler->Chat->ClearChat();
    }
    comm_handler->Multiplayer = 1;
    comm_handler->HaveHostInit = 0;
    comm_handler->PlayerOptions.CommandTurnIncrement = 2;
    comm_handler->current_turn = 4;
    comm_handler->PlayerOptions.CurrentTurn = 4;
    comm_handler->MeHost = 1;

    if (tribe_mp_create_direct_play_conversation(comm_handler) != 0) {
        return 0;
    }

    if (comm_handler->Lobby == nullptr || comm_handler->Lobby->glpDP == nullptr) {
        return 0;
    }

    DPSESSIONDESC2 desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x50;
    desc.guidApplication = comm_handler->ApplicationGUID;
    desc.dwMaxPlayers = (DWORD)comm_handler->MaxGamePlayers;
    desc.lpszSessionNameA = comm_handler->MyGameTitle;

    const HRESULT hr = comm_handler->Lobby->glpDP->Open(&desc, DPOPEN_CREATE);
    if (FAILED(hr)) {
        comm_handler->PlayerOptions.ProgramState = 0;
        return 0;
    }

    if (rge_base_game != nullptr) {
        tribe_mp_set_random_seed(comm_handler, rge_base_game->random_game_seed);
    } else {
        tribe_mp_set_random_seed(comm_handler, -1);
    }

    (void)tribe_mp_add_self_player(comm_handler);

    (void)tribe_mp_comm_get_caps(comm_handler);
    (void)tribe_mp_dplay_get_session_desc(comm_handler);

    comm_handler->Me = 1;
    comm_handler->PlayerOptions.HostPlayerNumber = 1;
    comm_handler->PlayerOptions.dcoID[1] = (ulong)s_self_dpid;
    comm_handler->PlayerOptions.Humanity[comm_handler->Me] = 2;
    comm_handler->HaveHostInit = 1;
    comm_handler->PlayerOptions.ProgramState = 3;
    comm_handler->GTDSerialNo = 0x7d1;
    comm_handler->UpdatePlayers();
    return 1;
}

} // namespace tribe_mp_ui

TribeJoinScreen::TribeJoinScreen() : TScreenPanel((char*)"Join Screen") {
    // Source of truth: scr_cj.cpp.decomp @ 0x00491650
    this->startedSession = 0;
    this->listFilled = 0;
    Sess = nullptr;
    this->game_count = 0;
    this->waitingToStart = 0;
    this->joinTime = 0;
    this->title = nullptr;
    this->listTitle = nullptr;
    this->list = nullptr;
    this->scrollbar = nullptr;
    this->joinButton = nullptr;
    this->createButton = nullptr;
    this->cancelButton = nullptr;
    this->refreshButton = nullptr;
    this->close_button = nullptr;

    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
    if (comm_handler != nullptr) {
        comm_handler->SetPlayerHumanity(1, 2);
        for (uint p = 2; p < 10; ++p) {
            comm_handler->SetPlayerHumanity(p, 0);
        }
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

    if (!this->create_text((TPanel*)this, &this->title, 0x259f, 0x14, 0x14, 600, 0x1e, 1, 1, 0, 0)) {
        return;
    }

    (void)this->create_text((TPanel*)this, &this->listTitle, 0x25a8, 0x14, 0x41, 600, 0x14, 4, 0, 0, 0);
    if (!this->create_list((TPanel*)this, &this->list, 0x14, 0x5a, 600, 0x10e, 0xb)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->scrollbar, (TTextPanel*)this->list, 0x14)) {
        return;
    }

    this->listFilled = 1;
    if (this->list != nullptr) {
        this->list->set_text(0x25ab);
    }

    if (!this->create_button((TPanel*)this, &this->refreshButton, 0x25a1, 0, 0xd2, 0x172, 0xdc, 0x1e, 0, 0, 0)) {
        return;
    }
    if (!this->create_button((TPanel*)this, &this->joinButton, 0x25a0, 0, 10, 0x1b8, 200, 0x1e, 0, 0, 0)) {
        return;
    }
    if (!this->create_button((TPanel*)this, &this->createButton, 0x25a2, 0, 0xdc, 0x1b8, 200, 0x1e, 0, 0, 0)) {
        return;
    }
    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x1ae, 0x1b8, 200, 0x1e, 0, 0, 0)) {
        return;
    }
    if (this->cancelButton != nullptr) {
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }

    if (!this->create_button((TPanel*)this, &this->close_button, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0)) {
        return;
    }
    if (this->close_button != nullptr) {
        this->close_button->set_active(1);
        this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);
    }

    this->set_curr_child((TPanel*)this->refreshButton);
    TPanel* tabList[5];
    tabList[0] = (TPanel*)this->list;
    tabList[1] = (TPanel*)this->refreshButton;
    tabList[2] = (TPanel*)this->joinButton;
    tabList[3] = (TPanel*)this->createButton;
    tabList[4] = (TPanel*)this->cancelButton;
    this->set_tab_order(tabList, 5);
}

TribeJoinScreen::~TribeJoinScreen() {
    // Source of truth: scr_cj.cpp.decomp @ 0x00491990
    if (Sess != nullptr) {
        delete Sess;
        Sess = nullptr;
    }

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->listTitle);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->refreshButton);
    this->delete_panel((TPanel**)&this->joinButton);
    this->delete_panel((TPanel**)&this->createButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->close_button);
}

long TribeJoinScreen::handle_idle() {
    // Source of truth: scr_cj.cpp.decomp @ 0x00491A80
    if (this->waitingToStart == 0) {
        if (this->listFilled != 0 && rge_base_game != nullptr && rge_base_game->input_enabled == 0) {
            rge_base_game->enable_input();
        }
    } else {
        const ulong now = debug_timeGetTime(kScrCjSourcePath, 0xaa);
        if (10000 < now - this->joinTime) {
            if (comm != nullptr) {
                ((TCommunications_Handler*)comm)->UnlinkToLevel(SERVICE_AVAILABLE);
            }
            this->waitingToStart = 0;
            if (rge_base_game != nullptr) {
                rge_base_game->enable_input();
            }
            this->popupOKDialog(0x25a3, (char*)0, 0x1c2, 100);
            return 1;
        }
    }

    return TPanel::handle_idle();
}

long TribeJoinScreen::handle_user_command(uint param_1, long param_2) {
    // Source of truth: scr_cj.cpp.decomp @ 0x00491B20
    switch (param_1) {
    case 0x17a8:
    case 0x17a9:
    case 0x17aa:
    case 0x17b2:
        if (this->waitingToStart != 0) {
            if (comm != nullptr) {
                ((TCommunications_Handler*)comm)->UnlinkToLevel(SERVICE_AVAILABLE);
            }
            this->waitingToStart = 0;
            if (rge_base_game != nullptr) {
                rge_base_game->enable_input();
            }
            this->popupOKDialog(0x25a3, (char*)0, 0x1c2, 100);
            return 1;
        }
        break;

    case 0x17b8:
        if (this->waitingToStart != 0) {
            (void)new TribeMPSetupScreen();
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"MP Setup Screen", 0);
                panel_system->destroyPanel((char*)"Join Screen");
            }
            return 1;
        }
        break;
    }

    return TPanel::handle_user_command(param_1, param_2);
}

void TribeJoinScreen::fillList() {
    // Source of truth: scr_cj.cpp.decomp @ 0x00491C70
    if (rge_base_game != nullptr) {
        rge_base_game->disable_input();
    }

    this->listFilled = 0;
    this->game_count = 0;
    if (this->list != nullptr) {
        this->list->set_text(0x25a9);
    }
    if (rge_base_game != nullptr) {
        rge_base_game->draw_window();
    }

    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
    if (this->startedSession == 0) {
        Sess = (comm_handler != nullptr) ? new TCommunications_Sessions(comm_handler) : nullptr;
        if (Sess == nullptr) {
            if (this->list != nullptr) {
                this->list->set_text(0x25ab);
            }
            return;
        }
        this->startedSession = 1;
    } else if (Sess != nullptr) {
        (void)Sess->Refresh();
    }

    const int count = (Sess != nullptr) ? Sess->GetSessionCount() : 0;
    this->game_count = count;
    if (count < 1) {
        if (this->list != nullptr) {
            this->list->set_text(0x25ab);
        }
    } else if (this->list != nullptr) {
        this->list->empty_list();
        for (int i = 0; i < this->game_count; ++i) {
            const ulong max_players = Sess->GetSessionMaxPlayers(i);
            const ulong cur_players = Sess->GetSessionCurrentPlayers(i);
            char* name = Sess->GetSessionName(i);

            char temp[126];
            sprintf(temp, kFmtSessionLine, (name != nullptr) ? name : "", cur_players, max_players);
            this->list->append_line(temp, 0);
        }
        this->set_curr_child((TPanel*)this->list);
    }

    this->listFilled = 1;
}

long TribeJoinScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: scr_cj.cpp.decomp @ 0x00491E20
    if (param_1 == nullptr) {
        return TEasy_Panel::action(param_1, param_2, param_3, param_4);
    }

    if ((TListPanel*)param_1 == this->list) {
        if (param_2 == 3 && 0 < this->game_count) {
            (void)this->action((TPanel*)this->joinButton, 1, 0, 0);
            return 1;
        }
    } else if ((TButtonPanel*)param_1 == this->joinButton) {
        if (param_2 == 1) {
            if (this->game_count < 1) {
                this->popupOKDialog(0x25a4, (char*)0, 0x1c2, 100);
                return 1;
            }

            const int line = (this->list != nullptr) ? this->list->currentLineNumber() : 0;
            _GUID* guid = (Sess != nullptr) ? Sess->GetSessionGUID(line) : nullptr;
            const int ok = tribe_mp_ui::JoinMultiplayerGame((TCommunications_Handler*)comm, guid);
            if (ok == 0) {
                char fmt[256];
                fmt[0] = '\0';
                this->get_string(0x25a3, fmt, sizeof(fmt));

                char string[256];
                string[0] = '\0';
                char* game = (this->list != nullptr) ? this->list->currentLine() : nullptr;
                sprintf(string, fmt, (game != nullptr) ? game : "");

                this->popupOKDialog(string, (char*)0, 0x1c2, 100);
                return 1;
            }

            if (rge_base_game != nullptr) {
                rge_base_game->disable_input();
            }
            this->waitingToStart = 1;
            this->joinTime = debug_timeGetTime(kScrCjSourcePath, 0x140);
            return 1;
        }
    } else if ((TButtonPanel*)param_1 == this->cancelButton) {
        if (param_2 == 1) {
            if (rge_base_game != nullptr) {
                rge_base_game->disable_input();
            }
            if (comm != nullptr) {
                ((TCommunications_Handler*)comm)->UnlinkToLevel(SINGLE_PLAYER);
            }
            (void)new TribeMPStartupScreen();
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"MP Startup Screen", 0);
                panel_system->destroyPanel((char*)"Join Screen");
            }
            return 1;
        }
    } else if ((TButtonPanel*)param_1 == this->createButton) {
        if (param_2 == 1) {
            (void)new TribeMPCreateDialog((TPanel*)this);
            return 1;
        }
    } else if ((TButtonPanel*)param_1 == this->refreshButton) {
        if (param_2 == 1) {
            this->fillList();
            return 1;
        }
    } else if ((TButtonPanel*)param_1 == this->close_button && param_2 == 1) {
        if (rge_base_game != nullptr) {
            rge_base_game->close();
        }
        return 1;
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

TribeMPCreateDialog::TribeMPCreateDialog(TPanel* parent) : TDialogPanel((char*)"Create Dialog") {
    // Source of truth: scr_cj.cpp.decomp @ 0x004920C0
    this->title = nullptr;
    this->input_title = nullptr;
    this->inputGamename = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;

    const long info_id = (parent != nullptr) ? ((TEasy_Panel*)parent)->get_popup_info_id() : 0;
    char* info_file = (parent != nullptr) ? ((TEasy_Panel*)parent)->get_popup_info_file() : nullptr;

    if (!this->setup(parent ? parent->render_area : nullptr, parent, 500, 0xe6, info_file, info_id, 1)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_text((TPanel*)this, &this->title, 0x25a6, 0x14, 0x14, 0x1cc, 0x1e, 1, 1, 1, 0)) {
        this->error_code = 1;
        return;
    }
    if (!this->create_text((TPanel*)this, &this->input_title, 0x25aa, 0x28, 0x55, 0x1a4, 0x14, 4, 0, 1, 0)) {
        this->error_code = 1;
        return;
    }

    char game_name[256];
    game_name[0] = '\0';
    if (Regs != nullptr) {
        char* saved = Regs->RegGetAscii(1, kRegDefaultMpGamename);
        if (saved != nullptr) {
            strncpy(game_name, saved, sizeof(game_name) - 1);
            game_name[sizeof(game_name) - 1] = '\0';
        }
    }

    if (!this->create_edit((TPanel*)this, &this->inputGamename, game_name, 0x28, FormatAny, 0x28, 0x6e, 0x1a4, 0x17, 0xb, 1, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0x3c, 0xb4, 0xb4, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x104, 0xb4, 0xb4, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    if (this->cancelButton != nullptr) {
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }

    TPanel* tab_list[3];
    tab_list[0] = (TPanel*)this->inputGamename;
    tab_list[1] = (TPanel*)this->okButton;
    tab_list[2] = (TPanel*)this->cancelButton;
    this->set_tab_order(tab_list, 3);
    this->set_curr_child((TPanel*)this->inputGamename);
}

TribeMPCreateDialog::~TribeMPCreateDialog() {
    // Source of truth: scr_cj.cpp.decomp @ 0x00492330
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->input_title);
    this->delete_panel((TPanel**)&this->inputGamename);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
}

long TribeMPCreateDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Source of truth: scr_cj.cpp.decomp @ 0x004923C0
    if (param_1 != nullptr) {
        if ((((TButtonPanel*)param_1 == this->okButton) && (param_2 == 1)) ||
            (((TEditPanel*)param_1 == this->inputGamename) && (param_2 == 0))) {
            char* text = (this->inputGamename != nullptr) ? this->inputGamename->get_text() : nullptr;
            if (text != nullptr) {
                // `is_blank` parity: treat empty string as blank.
                int blank = (text[0] == '\0') ? 1 : 0;
                if (blank == 0) {
                    if (rge_base_game != nullptr) {
                        rge_base_game->disable_input();
                    }

                    if (Regs != nullptr) {
                        const unsigned long len = (unsigned long)strlen(text) + 1;
                        (void)Regs->RegSetAscii(1, kRegDefaultMpGamename, (uchar*)text, len);
                    }

                    tribe_mp_ui::SetGameTitle((TCommunications_Handler*)comm, text);

                    if (L != nullptr) {
                        L->Log((char*)"$$$ CALLING CreateMultiplayerGame");
                    }

                    if (panel_system != nullptr) {
                        panel_system->setCurrentPanel((char*)"Join Screen", 0);
                    }
                    if (rge_base_game != nullptr) {
                        rge_base_game->draw_window();
                    }

                    int status_resid = 0x4c2;
                    if (comm != nullptr) {
                        // If service == TCPIP, use alternate status message.
                        if (memcmp(&((TCommunications_Handler*)comm)->ServiceGUID, &DPSPGUID_TCPIP, sizeof(_GUID)) == 0) {
                            status_resid = 0x4c3;
                        }
                    }

                    if (rge_base_game != nullptr) {
                        ((TRIBE_Game*)rge_base_game)->show_status_message(status_resid, (char*)"scr3", 0xc385);
                        rge_base_game->draw_window();
                    }

                    WinExec((char*)kClosedPwExe, 0);

                    // If we are in fullscreen DDRAW mode, flip to GDI surface before spawning network ops.
                    if (this->render_area != nullptr) {
                        TDrawArea* area = (TDrawArea*)this->render_area;
                        if (area->DrawSystem != nullptr && area->DrawSystem->DrawType == 2 && area->DrawSystem->ScreenMode == 2 &&
                            area->DrawSystem->DirDraw != nullptr) {
                            (void)area->DrawSystem->DirDraw->FlipToGDISurface();
                        }
                    }

                    if (comm != nullptr) {
                        for (int i = 1; i < 10; ++i) {
                            ((TCommunications_Handler*)comm)->PlayerStopTurn[i] = 0;
                        }
                    }

                    const int ok = tribe_mp_ui::CreateMultiplayerGame((TCommunications_Handler*)comm);

                    if (L != nullptr) {
                        L->Log((char*)"$$$ RETURNED FROM CreateMultiplayerGame");
                    }

                    const HWND hwnd = FindWindowA(kClosedPwWindow, kClosedPwWindow);
                    if (hwnd != nullptr) {
                        (void)SendMessageA(hwnd, WM_CLOSE, 0, 0);
                    }

                    if (ok == 0) {
                        if (panel_system != nullptr) {
                            panel_system->destroyPanel((char*)"Create Dialog");
                            panel_system->setCurrentPanel((char*)"Join Screen", 0);
                            panel_system->destroyPanel((char*)"Status Screen");
                        }

                        TEasy_Panel* owner = (TEasy_Panel*)this->parent_panel;
                        if (owner != nullptr) {
                            owner->popupOKDialog(0x25ad, (char*)0, 0x1c2, 100);
                        }
                        return 1;
                    }

                    (void)new TribeMPSetupScreen();
                    if (panel_system != nullptr) {
                        panel_system->setCurrentPanel((char*)"MP Setup Screen", 0);
                        panel_system->destroyPanel((char*)"Status Screen");
                        panel_system->destroyPanel((char*)"Create Dialog");
                        panel_system->destroyPanel((char*)"Join Screen");
                    }
                    return 1;
                }
            }

            this->set_curr_child((TPanel*)this->inputGamename);
            return 1;
        }

        if ((((TButtonPanel*)param_1 == this->cancelButton) && (param_2 == 1)) ||
            (((TEditPanel*)param_1 == this->inputGamename) && (param_2 == 1))) {
            if (panel_system != nullptr) {
                panel_system->setCurrentPanel((char*)"Join Screen", 0);
                panel_system->destroyPanel((char*)"Create Dialog");
            }
            return 1;
        }
    }

    return TPanel::action(param_1, param_2, param_3, param_4);
}

void TribeMPCreateDialog::draw() { TDialogPanel::draw(); }

long TribeMPCreateDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeMPCreateDialog, TDialogPanel)

// Virtual wrappers: forward to TScreenPanel unless overridden above.
long TribeJoinScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6,
                           uchar param_7) {
    return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void TribeJoinScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeJoinScreen::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TScreenPanel::set_rect(param_1, param_2, param_3, param_4);
}
void TribeJoinScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeJoinScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeJoinScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5,
                                      long param_6, long param_7, long param_8, long param_9, TPanel* param_10,
                                      TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                  param_10, param_11, param_12, param_13);
}
void TribeJoinScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {
    TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4);
}
void TribeJoinScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeJoinScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) {
    TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3);
}
void TribeJoinScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeJoinScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeJoinScreen::draw() { TScreenPanel::draw(); }
void TribeJoinScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeJoinScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) {
    TScreenPanel::draw_offset(param_1, param_2, param_3);
}
void TribeJoinScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeJoinScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) {
    TScreenPanel::draw_offset2(param_1, param_2, param_3);
}
void TribeJoinScreen::paint() { TScreenPanel::paint(); }
long TribeJoinScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeJoinScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeJoinScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5);
}
long TribeJoinScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeJoinScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeJoinScreen::handle_timer_command(uint param_1, long param_2) {
    return TScreenPanel::handle_timer_command(param_1, param_2);
}
long TribeJoinScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeJoinScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}
long TribeJoinScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5);
}
long TribeJoinScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5);
}
long TribeJoinScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4);
}
long TribeJoinScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5);
}
long TribeJoinScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeJoinScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeJoinScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeJoinScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeJoinScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeJoinScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeJoinScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4);
}
void TribeJoinScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeJoinScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeJoinScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeJoinScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeJoinScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeJoinScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeJoinScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5,
                                  long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                       param_10, param_11);
}
int TribeJoinScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5,
                                  long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                       param_10, param_11);
}
int TribeJoinScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5,
                                     long param_6, long param_7, long param_8) {
    return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TribeJoinScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5,
                                        long param_6, long param_7, long param_8) {
    return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TribeJoinScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5,
                                long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11);
}
int TribeJoinScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5,
                                long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) {
    return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11);
}
int TribeJoinScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5,
                                long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11);
}
int TribeJoinScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5,
                                 long param_6, long param_7, long param_8, long param_9, long param_10) {
    return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                      param_10);
}
int TribeJoinScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5,
                                long param_6, long param_7, long param_8, long param_9, long param_10, int param_11,
                                int param_12) {
    return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9,
                                     param_10, param_11, param_12);
}
int TribeJoinScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5,
                                     long param_6, long param_7, long param_8, long param_9) {
    return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int TribeJoinScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5,
                                long param_6, long param_7) {
    return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
int TribeJoinScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4,
                                     long param_5, long param_6, long param_7, long param_8) {
    return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int TribeJoinScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) {
    return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3);
}
int TribeJoinScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4,
                                       long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8,
                                           param_9);
}
int TribeJoinScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4,
                                       long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8,
                                           param_9);
}
void TribeJoinScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) {
    TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5);
}

