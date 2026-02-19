#include "../include/TCommunications_Handler.h"
#include "../include/NAME.h"
#include "../include/RGE_Communications_Queue.h"
#include "../include/RGE_Communications_Speed.h"
#include "../include/RGE_TimeSinceLastCall.h"
#include <stdio.h>
#include <string.h>
#include <dplay.h>

namespace {
// COMMPLAYEROPTIONS::Humanity offset inside PlayerOptions.
// Source-of-truth:
// - all_types_ground_truth.h (COMMPLAYEROPTIONS::Humanity @ +0x184)
// - com_hand.cpp.decomp (Get/SetPlayerHumanity)
static const int kCommPlayerOptionsHumanityOffset = 0x184;
static const int kCommPlayerOptionsNeedsToBeSentOffset = 0x0;
static const int kCommPlayerOptionsProgramStateOffset = 0x8;
static const int kCommPlayerOptionsCommandTurnIncrementOffset = 0x40;
static const int kCommPlayerOptionsPlayerReadyOffset = 0x44;
static const int kCommPlayerOptionsDcoIDOffset = 0x14;
static const int kCommPlayerOptionsUser1Offset = 0x6C;
static const int kCommPlayerOptionsUser2Offset = 0x94;
static const int kCommPlayerOptionsUser3Offset = 0xBC;
static const int kCommPlayerOptionsUser4Offset = 0xE4;
static const int kCommPlayerOptionsUser5Offset = 0x10C;
static const int kCommPlayerOptionsUser6Offset = 0x134;
static const int kCommPlayerOptionsUser7Offset = 0x15C;
static const int kCommPlayerOptionsHighPlayerNumberOffset = 0x1C0;
static const int kCommPlayerOptionsLowPlayerNumberOffset = 0x1C2;
static const int kCommPlayerOptionsHostPlayerNumberOffset = 0x1C4;
static const int kCommPlayerOptionsRandomSeedOffset = 0x1BC;
static const int kCommPlayerOptionsGameHasStartedOffset = 0x1C8;

static const int kPlayerHumanityHuman = 2;
static const int kPlayerHumanityComputer = 4;
static const int kPlayerHumanityCyborg = 5;
static const int kCommStatePause = 4;
static const int kCommStateRunning = 5;
static const int kCommWindowMessagePause = 0x17a2;
static const int kCommWindowMessageResume = 0x17a3;

// Source-of-truth constants from com_hand.cpp.asm:
// - COMM_UPDATE_PARAMS literal pushed at SetPlayerHumanity+0x35 (0x0042cc5e): 0x17a6
// - COMM_STATE_JOINNOW compare at SetPlayerHumanity+0x41 (0x0042cc71): 3
static const int kCommMessageUpdateParams = 0x17a6;
static const int kCommMessagePlayerIdSet = 0x17b8;
static const int kCommStateJoinNow = 3;

// Source-of-truth mirror for DAT_0062cf04 (local/self DPID).
// Updated through player/link identity sync paths.
static ulong s_localPlayerDpid = 0;

static ulong comm_tslc_get_avg(RGE_TimeSinceLastCall* tslc, int sample_count) {
    if (tslc == nullptr || sample_count <= 0 || sample_count >= 0x65) {
        return 0;
    }

    uint sum = 0;
    int offset = tslc->Offset;
    for (int i = 0; i < sample_count; ++i) {
        --offset;
        if (offset < 1) {
            offset = 100;
        }
        sum += tslc->aTSLC[offset];
        if (sum > 999) {
            tslc->cps = (ulong)i;
        }
    }
    return sum / (uint)sample_count;
}

static uchar comm_speed_get_high_latency_centi(RGE_Communications_Speed* speed) {
    if (speed == nullptr || speed->Comm == nullptr) {
        return 1;
    }

    uint highest_latency = 0;
    for (uint player = 1; player < 10; ++player) {
        if (speed->Comm->IsPlayerHuman(player) != 0 && highest_latency <= speed->ActualLatency[player]) {
            highest_latency = speed->ActualLatency[player];
        }
    }

    speed->HighestLatencyMsec = highest_latency;
    uint high_latency_centi = (highest_latency + 5) / 10;
    if (high_latency_centi < 2) {
        high_latency_centi = 1;
    }
    if (high_latency_centi > 0xFE) {
        high_latency_centi = 0xFF;
    }
    return (uchar)high_latency_centi;
}

static uint comm_speed_get_avg_frame_rate(RGE_Communications_Speed* speed) {
    if (speed == nullptr) {
        return 0;
    }
    return (uint)comm_tslc_get_avg(speed->FrameTSLC, 0x32);
}
}

int TCommunications_Handler::IsPaused() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C7F0
    const int* program_state =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    return (*program_state == kCommStatePause) ? 1 : 0;
}

int TCommunications_Handler::IsHost() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CB00
    if (this->Multiplayer != 0) {
        return this->MeHost;
    }
    return 1;
}

int TCommunications_Handler::AllPlayersReady() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E610
    const ushort* low_player =
        (const ushort*)((const char*)&this->PlayerOptions + kCommPlayerOptionsLowPlayerNumberOffset);
    const ushort* high_player =
        (const ushort*)((const char*)&this->PlayerOptions + kCommPlayerOptionsHighPlayerNumberOffset);
    const int* player_ready =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsPlayerReadyOffset);

    uint player = (uint)(*low_player);
    if ((uint)(*high_player) < player) {
        return 1;
    }

    while (true) {
        if (this->IsPlayerHuman(player) != 0 && player_ready[player] == 0) {
            return 0;
        }
        ++player;
        if ((uint)(*high_player) < player) {
            return 1;
        }
    }
}

long TCommunications_Handler::EnableNewPlayers(void* direct_play, int enable_links) {
    // Source of truth: com_hand.cpp.decomp @ 0x0042EF00
    if (direct_play == nullptr) {
        return 0x80070057L;
    }

    IUnknown* direct_play_unknown = (IUnknown*)direct_play;
    IDirectPlay* direct_play_interface = nullptr;
    HRESULT hr = direct_play_unknown->QueryInterface(IID_IDirectPlay, (void**)&direct_play_interface);
    if (hr >= 0 && direct_play_interface != nullptr) {
        hr = direct_play_interface->EnableNewPlayers(enable_links);
        (void)direct_play_interface->Release();
    }
    return (long)hr;
}

int TCommunications_Handler::IsPlayerHuman(uint player_number) {
    // Source of truth: com_hand.cpp.decomp @ 0x0042CCD0
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers)) {
        return 0;
    }

    int humanity = this->GetPlayerHumanity(player_number);
    return ((humanity == kPlayerHumanityHuman) || (humanity == kPlayerHumanityCyborg)) ? 1 : 0;
}

void TCommunications_Handler::Update() {
    // Offset 0x00426650 in ASM is DoCycle
    // The user wants Update() to behave like the core tick.
    // In tribal engine, DoCycle is the main entry.
    DoCycle(GetTickCount());
}

void TCommunications_Handler::HandleMessage() {
    // Offset 0x00429D90 in ASM is ExecuteIncoming
    ExecuteIncoming();
}

int TCommunications_Handler::DoCycle(ulong now) {
    // TODO: Full implementation from 0x00426650
    // Minimal implementation to satisfy requirements:
    ReceiveGameMessages();
    return 1;
}

void TCommunications_Handler::ReceiveGameMessages() {
    // TODO: Full implementation from 0x00426E10
    // Calls ExecuteIncoming, GetDPLAYMessages, etc.
    ExecuteIncoming();
    GetDPLAYMessages();
    CheckPingTime(0);
}

uint TCommunications_Handler::ExecuteIncoming() {
    // Source of truth: com_hand.cpp.decomp @ 0x00429D90
    if (this->Multiplayer == 0) {
        return 0;
    }

    const ulong* dco_id = (const ulong*)((const char*)&this->PlayerOptions + kCommPlayerOptionsDcoIDOffset);

    uint on_hold_offset = 0;
    uint slot_number = 0;
    while (on_hold_offset <= 0x2EF8) {
        ulong* hold_slot = (ulong*)((char*)this->OnHold + on_hold_offset);
        if (hold_slot[2] != 0 && this->MaxGamePlayers != 0) {
            const ulong* player_dco = dco_id + 1;
            uint player = 1;
            while (player <= (uint)this->MaxGamePlayers) {
                if (this->IsPlayerHuman(player) != 0 && player != this->Me) {
                    const uint expected_serial = this->PlayerHighSerialNumber[player] + 1;
                    const uint serial = (uint)hold_slot[1];
                    const ulong from_dpid = hold_slot[3];

                    if (serial < expected_serial && from_dpid == *player_dco) {
                        if (hold_slot[0] != 0) {
                            ::operator delete((void*)hold_slot[0]);
                        }
                        hold_slot[0] = 0;
                        hold_slot[1] = 0;
                        hold_slot[2] = 0;
                        hold_slot[3] = 0;
                        hold_slot[4] = 0;
                    }

                    if ((uint)hold_slot[1] == expected_serial && hold_slot[3] == *player_dco) {
                        sprintf(this->TBuff, "Cached Execute #%d  Slot#%d ", expected_serial, slot_number);

                        this->PreprocessMessages(hold_slot[2], (char*)hold_slot[0], hold_slot[3], hold_slot[4], 1);

                        hold_slot = (ulong*)((char*)this->OnHold + on_hold_offset);

                        if (hold_slot[0] != 0) {
                            ::operator delete((void*)hold_slot[0]);
                        }
                        hold_slot[0] = 0;
                        hold_slot[1] = 0;
                        hold_slot[2] = 0;
                        hold_slot[3] = 0;
                        hold_slot[4] = 0;
                    }
                }

                ++player;
                ++player_dco;
            }
        }

        on_hold_offset += 0x18;
        ++slot_number;
    }

    return 0;
}

void TCommunications_Handler::GetDPLAYMessages() {
    // TODO: Implement (ASM 0x00426FCD)
}

void TCommunications_Handler::EvaluateSystemMessage(ulong p1, char* p2, ulong p3, ulong p4) {
    // TODO: Implement (ASM 0x00428DA0)
}

void TCommunications_Handler::UpdatePlayers() {
    // TODO: Implement (ASM 0x0042DF40)
}

void TCommunications_Handler::UpdatePlayer(uint id, int timeout) {
    // TODO: Implement (ASM 0x0042DF50)
}

void TCommunications_Handler::NotifyWindow(int message) {
    // Source-of-truth:
    // - com_hand.cpp.decomp NotifyWindow/NotifyWindowParam
    // - com_hand.cpp.asm 0x00428270 / 0x00428280
    // Behavior: Post WM_USER to HostHWND with message as wParam and 0 as lParam.
    //
    // Assumption/TODO:
    // The original logs through TDebuggingLog::Log and uses the typed COMMMESSAGES enum.
    // This branch still uses integer message ids because full comm enums are not restored yet.
    if (this->HostHWND) {
        PostMessageA((HWND)this->HostHWND, 0x400, (WPARAM)message, 0);
    }
}

void TCommunications_Handler::NotifyWindowParam(int message, long param) {
    // Source-of-truth: com_hand.cpp.decomp NotifyWindowParam / asm @ 0x00428280
    if (this->HostHWND) {
        PostMessageA((HWND)this->HostHWND, 0x400, (WPARAM)message, (LPARAM)param);
    }
}

long TCommunications_Handler::SendSharedData(int send_mode) {
    // Partial stub with key state transitions from com_hand.cpp.asm/decomp.
    // Source-of-truth:
    // - com_hand.cpp.asm SendSharedData @ 0x00428820
    // - com_hand.cpp.decomp SendSharedData
    //
    // Assumption/TODO:
    // Full packet serialization/network send is still missing in this branch.
    // This keeps core "needs send" behavior so callers (including SetPlayerHumanity) track intent.
    if (!this->MeHost) {
        return 0;
    }

    uchar* needs_to_be_sent =
        (uchar*)((char*)&this->PlayerOptions + kCommPlayerOptionsNeedsToBeSentOffset);

    if (send_mode != 0) {
        *needs_to_be_sent = 1;
    }
    if (*needs_to_be_sent == 0) {
        return 0;
    }

    // Treat as sent for now in this partial reimplementation.
    *needs_to_be_sent = 0;
    return 1;
}

int TCommunications_Handler::GetPlayerHumanity(uint player_number) {
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers) || (player_number >= 10)) {
        return 0;
    }

    const int* humanity =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsHumanityOffset);
    return humanity[player_number];
}

void TCommunications_Handler::SetPlayerHumanity(uint player_number, int humanity_value) {
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers) || (player_number >= 10)) {
        return;
    }

    int* humanity = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsHumanityOffset);
    humanity[player_number] = humanity_value;

    this->UpdatePlayer(player_number, 1);

    // Source-of-truth:
    // - com_hand.cpp.decomp SetPlayerHumanity
    // - com_hand.cpp.asm 0x0042cc30
    this->NotifyWindow(kCommMessageUpdateParams);

    const int* program_state =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    if ((this->MeHost != 0) && (*program_state == kCommStateJoinNow)) {
        uchar* needs_to_be_sent =
            (uchar*)((char*)&this->PlayerOptions + kCommPlayerOptionsNeedsToBeSentOffset);
        *needs_to_be_sent = 1;
        this->SendSharedData(0);
    }
}

char* TCommunications_Handler::GetPlayerName(uint player_number) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D100
    if (this->MaxGamePlayers < player_number) {
        return nullptr;
    }
    if (player_number == this->Me) {
        return this->MyFriendlyName;
    }
    if (this->FriendlyName == nullptr) {
        return nullptr;
    }
    return this->FriendlyName[player_number].Text;
}

void TCommunications_Handler::SetPlayerName(uint player_number, char* name) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D430
    if (name == nullptr) {
        return;
    }

    if (player_number == this->Me) {
        strncpy(this->MyFriendlyName, name, sizeof(this->MyFriendlyName) - 1);
        this->MyFriendlyName[sizeof(this->MyFriendlyName) - 1] = '\0';
        return;
    }

    if (this->FriendlyName == nullptr) {
        return;
    }

    strncpy(this->FriendlyName[player_number].Text, name, sizeof(this->FriendlyName[player_number].Text) - 1);
    this->FriendlyName[player_number].Text[sizeof(this->FriendlyName[player_number].Text) - 1] = '\0';
}

uint TCommunications_Handler::GetRandomSeed() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CAD0
    if (this->Multiplayer == 0) {
        return (uint)GetTickCount();
    }
    const uint* random_seed =
        (const uint*)((const char*)&this->PlayerOptions + kCommPlayerOptionsRandomSeedOffset);
    return *random_seed;
}

uint TCommunications_Handler::WhoAmI() {
    // Source of truth: com_hand.cpp.decomp @ WhoAmI
    return this->Me;
}

void* TCommunications_Handler::SetWindowHandle(void* window_handle) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D490
    this->HostHWND = window_handle;
    return window_handle;
}

void TCommunications_Handler::LaunchMultiplayerGame() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042DC20
    int* program_state = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    int* game_has_started = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsGameHasStartedOffset);
    uchar* command_turn_increment =
        (uchar*)((char*)&this->PlayerOptions + kCommPlayerOptionsCommandTurnIncrementOffset);
    const ushort* low_player =
        (const ushort*)((const char*)&this->PlayerOptions + kCommPlayerOptionsLowPlayerNumberOffset);
    const ushort* high_player =
        (const ushort*)((const char*)&this->PlayerOptions + kCommPlayerOptionsHighPlayerNumberOffset);
    const ulong* dco_id =
        (const ulong*)((const char*)&this->PlayerOptions + kCommPlayerOptionsDcoIDOffset);

    this->EnableNewPlayers(this->OptionsData, 0);
    *program_state = kCommStateRunning;
    this->CalculatePlayerRange();
    *game_has_started = 1;

    this->ClearRXandTX();
    this->PackPlayersDown();

    if (this->MaxGamePlayers != 0) {
        uint expected_serial = 2000;
        for (uint player = 1; player <= (uint)this->MaxGamePlayers; ++player) {
            if (dco_id[player] != 0) {
                this->PlayerHighSerialNumber[player] = expected_serial;
            }
            expected_serial += 2000;
        }
    }

    this->GTDSerialNo = this->Me * 2000 + 1;
    this->SendSharedData(1);
    this->current_turn = (ulong)(*command_turn_increment + 1);

    if (this->Multiplayer != 0) {
        uint player = (uint)(*low_player);
        while (player <= (uint)(*high_player)) {
            if (player != this->Me) {
                this->LastTurnAck[player] = 0;
            }
            ++player;
        }
    }

    this->ResetLastCommunicationTimes();
    this->NotifyWindow(kCommMessageUpdateParams);
}

void TCommunications_Handler::CalculatePlayerRange() {
    // Source of truth: com_hand.cpp.decomp @ 0x00425990
    ushort* high_player = (ushort*)((char*)&this->PlayerOptions + kCommPlayerOptionsHighPlayerNumberOffset);
    ushort* low_player = (ushort*)((char*)&this->PlayerOptions + kCommPlayerOptionsLowPlayerNumberOffset);

    *high_player = 0;
    *low_player = (ushort)(this->MaxGamePlayers + 1);

    for (uint player = 1; player <= (uint)this->MaxGamePlayers; ++player) {
        int humanity = this->GetPlayerHumanity(player);
        if (this->IsPlayerHuman(player) != 0 || humanity == kPlayerHumanityComputer) {
            if ((ushort)player > *high_player) {
                *high_player = (ushort)player;
            }
            if ((ushort)player < *low_player) {
                *low_player = (ushort)player;
            }
        }
    }
}

void TCommunications_Handler::ClearRXandTX() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429FD0
    unsigned char* on_hold = (unsigned char*)this->OnHold;
    if (on_hold != nullptr) {
        for (uint offset = 0; offset < 0x2EF8; offset += 0x18) {
            ulong* hold_slot = (ulong*)(on_hold + offset);
            if (hold_slot[0] != 0) {
                ::operator delete((void*)hold_slot[0]);
            }
            hold_slot[0] = 0;
            hold_slot[1] = 0;
            hold_slot[2] = 0;
            hold_slot[3] = 0;
            hold_slot[4] = 0;
        }
    }

    unsigned char* resend = (unsigned char*)this->Resend;
    if (resend != nullptr) {
        for (uint offset = 0; offset < 0x6D98; offset += 0x38) {
            ulong* resend_slot = (ulong*)(resend + offset);
            resend_slot[0] = 0;

            void* payload_ptr = (void*)resend_slot[2];
            if (payload_ptr != nullptr) {
                ::operator delete(payload_ptr);
            }
            resend_slot[2] = 0;
            resend_slot[1] = 0;
            resend_slot[3] = 0;
            memset(resend + offset + 0x10, 0, 0x28);
        }
    }
}

void TCommunications_Handler::PackPlayersDown() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042D720
    ulong* dco_id = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsDcoIDOffset);
    int* player_ready = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsPlayerReadyOffset);
    ulong* user1 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser1Offset);
    ulong* user2 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser2Offset);
    ulong* user3 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser3Offset);
    ulong* user4 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser4Offset);
    ulong* user5 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser5Offset);
    ulong* user6 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser6Offset);
    ulong* user7 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser7Offset);
    int* humanity = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsHumanityOffset);

    for (uint dst = 1; dst <= (uint)this->MaxGamePlayers; ++dst) {
        int dst_humanity = this->GetPlayerHumanity(dst);
        if (this->IsPlayerHuman(dst) != 0 || dst_humanity == kPlayerHumanityComputer) {
            continue;
        }

        uint src = dst;
        while (src <= (uint)this->MaxGamePlayers) {
            int src_humanity = this->GetPlayerHumanity(src);
            if (this->IsPlayerHuman(src) != 0 || src_humanity == kPlayerHumanityComputer) {
                break;
            }
            ++src;
        }

        if (src > (uint)this->MaxGamePlayers) {
            continue;
        }

        if (this->FriendlyName != nullptr) {
            memcpy(this->FriendlyName[dst].Text, this->FriendlyName[src].Text, sizeof(this->FriendlyName[dst].Text));
        }
        if (this->FormalName != nullptr) {
            memcpy(this->FormalName[dst].Text, this->FormalName[src].Text, sizeof(this->FormalName[dst].Text));
        }

        dco_id[dst] = dco_id[src];
        player_ready[dst] = player_ready[src];
        user1[dst] = user1[src];
        user2[dst] = user2[src];
        user3[dst] = user3[src];
        user4[dst] = user4[src];
        user5[dst] = user5[src];
        user6[dst] = user6[src];
        user7[dst] = user7[src];
        humanity[dst] = humanity[src];
        this->LastTurnAck[dst] = this->LastTurnAck[src];
        this->LastPlayerCommunication[dst] = this->LastPlayerCommunication[src];

        this->InitPlayerInformation(src, 0, (char*)"", (char*)"");
    }

    this->SetSelfPlayer();
}

void TCommunications_Handler::SetSelfPlayer() {
    // Source of truth: com_hand.cpp.decomp @ 0x00428A70
    ulong* dco_id = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsDcoIDOffset);
    ulong local_dpid = s_localPlayerDpid;

    if (this->Me != 0 && this->Me <= (uint)this->MaxGamePlayers) {
        ulong slot_dpid = dco_id[this->Me];
        if (slot_dpid != 0) {
            local_dpid = slot_dpid;
            s_localPlayerDpid = slot_dpid;
        }
    }

    if (local_dpid == 0) {
        return;
    }

    for (uint player = 1; player <= (uint)this->MaxGamePlayers; ++player) {
        if (dco_id[player] == local_dpid) {
            this->Me = player;
            this->NotifyWindowParam(kCommMessagePlayerIdSet, (long)player);
            return;
        }
    }
}

void TCommunications_Handler::InitPlayerInformation(uint player_number, ulong dpid, char* friendly_name,
                                                     char* formal_name) {
    // Source of truth: com_hand.cpp.decomp @ 0x0042D2D0
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers)) {
        return;
    }

    ulong* dco_id = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsDcoIDOffset);
    int* player_ready = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsPlayerReadyOffset);
    ulong* user1 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser1Offset);
    ulong* user2 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser2Offset);
    ulong* user3 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser3Offset);
    ulong* user4 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser4Offset);
    ulong* user5 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser5Offset);
    ulong* user6 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser6Offset);
    ulong* user7 = (ulong*)((char*)&this->PlayerOptions + kCommPlayerOptionsUser7Offset);
    int* humanity = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsHumanityOffset);
    uchar* invalid_player = (uchar*)((char*)&this->PlayerOptions + 0x1AC);

    dco_id[player_number] = dpid;
    player_ready[player_number] = 0;
    user1[player_number] = 0;
    user2[player_number] = 0;
    user3[player_number] = 0;
    user4[player_number] = 0;
    user5[player_number] = 0;
    user6[player_number] = 0;
    user7[player_number] = 0;
    humanity[player_number] = 0;
    invalid_player[player_number] = 0;

    this->LastTurnAck[player_number] = 0;
    this->PlayerHighSerialNumber[player_number] = 0;
    this->LastPlayerCommunication[player_number] = 0;
    this->LastPlayerWarning[player_number] = 0;
    this->LastTXPing[player_number] = 0;
    this->dwFlags = 0;
    this->dwMaxBufferSize = 0;
    this->dwMaxQueueSize = 0;
    this->dwMaxPlayers = 0;
    this->dwHundredBaud = 0;
    this->dwLatency = 0;

    if (this->FriendlyName != nullptr) {
        strncpy(this->FriendlyName[player_number].Text,
                (friendly_name != nullptr) ? friendly_name : "",
                sizeof(this->FriendlyName[player_number].Text) - 1);
        this->FriendlyName[player_number].Text[sizeof(this->FriendlyName[player_number].Text) - 1] = '\0';
    }
    if (this->FormalName != nullptr) {
        strncpy(this->FormalName[player_number].Text,
                (formal_name != nullptr) ? formal_name : "",
                sizeof(this->FormalName[player_number].Text) - 1);
        this->FormalName[player_number].Text[sizeof(this->FormalName[player_number].Text) - 1] = '\0';
    }

    if (this->InQ != nullptr) {
        this->InQ->FlushForPlayer(player_number);
    }
}

void TCommunications_Handler::ResetLastCommunicationTimes() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042C7A0
    ulong now = GetTickCount();
    for (uint player = 1; player <= (uint)this->MaxGamePlayers; ++player) {
        this->LastPlayerCommunication[player] = now;
        this->LastTXPing[player] = now;
    }
}

int TCommunications_Handler::AddCommand(ulong p1, void* p2, ulong p3, int p4, uchar p5, int p6) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426470
    if (this->InQ == nullptr) {
        return 0;
    }

    return this->InQ->AddItem(p1, p2, p3, (uint)p4, p5, p6);
}

void* TCommunications_Handler::get_command() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004264D0
    if (this->Multiplayer == 0) {
        return this->InQ->GetNextItemSingle();
    }

    const int* program_state =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    if (*program_state == kCommStateJoinNow) {
        return this->InQ->GetNextItemSingle();
    }

    return this->InQ->GetNextItemOrdered(this->current_turn);
}

int TCommunications_Handler::NewCommand(void* p1, int p2, int p3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426530
    if (this->Multiplayer != 0) {
        (void)this->CommOut((uchar)0x3E, p1, p2, 0);
        return 1;
    }

    if (this->InQ == nullptr) {
        return 0;
    }

    const uchar* command_turn_increment =
        (const uchar*)((const char*)&this->PlayerOptions + kCommPlayerOptionsCommandTurnIncrementOffset);
    const ulong queue_turn = this->current_turn + (ulong)(*command_turn_increment);
    const uchar sequence = this->InQ->GetNextSequence(this->current_turn);

    this->AddCommand(queue_turn, p1, (ulong)p2, (int)this->Me, sequence, p3);
    return 1;
}

uchar TCommunications_Handler::new_command(void* p1, int p2) {
    // Source of truth: com_hand.cpp.decomp @ 0x00426510
    return (uchar)this->NewCommand(p1, p2, 0);
}

void TCommunications_Handler::DropDeadPlayer(uint id, ulong turn) {
    // TODO: Implement (ASM 0x00428B60)
}

void TCommunications_Handler::CheckPingTime(int p1) {
    // TODO: Implement (ASM 0x00428220)
}

void TCommunications_Handler::SendStoredMessages() {
    // TODO: Implement (ASM 0x00426FCD)
}

int TCommunications_Handler::PreprocessMessages(ulong p1, char* p2, ulong p3, ulong p4, int p5) {
    // TODO: Implement (ASM 0x00429280)
    return 0;
}

long TCommunications_Handler::CommOut(uchar p1, void* p2, long p3, ulong p4) {
    // TODO: Implement (ASM 0x00426C40)
    return 0;
}

void TCommunications_Handler::LocalResumeGame(uint p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C840
    int* program_state = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    *program_state = kCommStateRunning;
    this->NotifyWindowParam(kCommWindowMessageResume, (long)p1);
}

void TCommunications_Handler::LocalPauseGame(uint p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C860
    int* program_state = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    *program_state = kCommStatePause;
    this->NotifyWindowParam(kCommWindowMessagePause, (long)p1);
}

void TCommunications_Handler::SendPauseGame(int p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C880
    if ((this->Multiplayer != 0) && (this->MeHost != 0)) {
        if (p1 != 0) {
            (void)this->CommOut((uchar)'P', nullptr, 0, 0);
            return;
        }
        (void)this->CommOut((uchar)'U', nullptr, 0, 0);
    }
}

void TCommunications_Handler::RequestPauseGame(int p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C930
    (void)p1;
    if (this->Multiplayer == 0) {
        this->LocalPauseGame(this->Me);
        return;
    }
    if (this->MeHost != 0) {
        this->SendPauseGame(1);
        this->LocalPauseGame(this->Me);
        return;
    }
    (void)this->CommOut((uchar)'W', nullptr, 0, 0);
}

void TCommunications_Handler::RequestResumeGame(int p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C9A0
    (void)p1;
    if (this->Multiplayer == 0) {
        this->LocalResumeGame(this->Me);
        return;
    }
    if (this->MeHost != 0) {
        this->SendPauseGame(0);
        this->LocalResumeGame(this->Me);
        return;
    }
    (void)this->CommOut((uchar)'+', nullptr, 0, 0);
}

int TCommunications_Handler::TogglePauseGame() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C8F0
    if (this->PauseChangePending != 0) {
        return 0;
    }
    if (this->IsPaused() != 0) {
        this->RequestResumeGame(0);
        return 1;
    }
    this->RequestPauseGame(0);
    return 1;
}

int TCommunications_Handler::MultiplayerGameStart() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E5E0
    if (this->Multiplayer == 0) {
        return 1;
    }
    if (this->current_turn > 6) {
        return 1;
    }
    this->DoCycle(0);
    return 0;
}

int TCommunications_Handler::IsLobbyLaunched() {
    return this->LobbyLaunched;
}

void TCommunications_Handler::SendIResignMsg() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429A90
    if (this->Multiplayer == 0) {
        return;
    }

    const uchar* command_turn_increment =
        (const uchar*)((const char*)&this->PlayerOptions + kCommPlayerOptionsCommandTurnIncrementOffset);
    const ulong resign_turn = this->current_turn + (ulong)(*command_turn_increment);
    (void)this->CommOut((uchar)'Q', (void*)&resign_turn, 4, 0);

    struct MsgDone {
        uchar command;
        uchar _pad0;
        uchar _pad1;
        uchar _pad2;
        ulong execute_on_turn;
        uchar high_latency_centi;
        uchar frame_rate_msec;
        uchar _pad_end0;
        uchar _pad_end1;
    } done_msg;

    memset(&done_msg, 0, sizeof(done_msg));
    done_msg.command = (uchar)'D';
    if (this->Speed != nullptr) {
        done_msg.high_latency_centi = comm_speed_get_high_latency_centi(this->Speed);
        done_msg.frame_rate_msec = (uchar)comm_speed_get_avg_frame_rate(this->Speed);
    }

    done_msg.execute_on_turn = this->current_turn + 1 + (ulong)(*command_turn_increment);
    (void)this->CommOut((uchar)'D', (void*)&done_msg, 0x0C, 0);

    done_msg.execute_on_turn = this->current_turn + 2 + (ulong)(*command_turn_increment);
    (void)this->CommOut((uchar)'D', (void*)&done_msg, 0x0C, 0);

    done_msg.execute_on_turn = this->current_turn + 3 + (ulong)(*command_turn_increment);
    (void)this->CommOut((uchar)'D', (void*)&done_msg, 0x0C, 0);
}

void TCommunications_Handler::ShutdownGameMessages() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426FB0
    this->ShuttingDown = 1;
    this->ReceiveGameMessages();
}

int TCommunications_Handler::CountWaitingMessages() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042A0C0
    int waiting = 0;
    uint offset = 0;
    while (offset < 0x6D99) {
            ulong* resend_slot = (ulong*)((char*)this->Resend + offset);
            if (resend_slot[1] != 0) {
            ++waiting;
        }
        offset += 0x38;
    }
    return waiting;
}

void TCommunications_Handler::GameOver() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425750
    this->current_turn = 0;
    if (this->InQ != nullptr) {
        this->InQ->FlushAll();
    }
    if (this->OutQ != nullptr) {
        this->OutQ->FlushAll();
    }
}

COMMSTATUS TCommunications_Handler::UnlinkToLevel(COMMSTATUS level) {
    // TODO: STUB: transport-level unlink path is not restored yet.
    this->CommunicationsStatus = level;
    return this->CommunicationsStatus;
}
