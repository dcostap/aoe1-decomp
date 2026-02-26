#include "../include/TCommunications_Handler.h"
#include "../include/NAME.h"
#include "../include/TChat.h"
#include "../include/RGE_Communications_Queue.h"
#include "../include/RGE_Communications_Speed.h"
#include "../include/RGE_Communications_Synchronize.h"
#include "../include/RGE_TimeSinceLastCall.h"
#include "../include/RGE_Lobby.h"
#include "../include/RGE_Comm_Error.h"
#include "../include/TDebuggingLog.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new>
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
static const int kPlayerHumanityClosed = 1;
static const int kPlayerHumanityEliminated = 3;
static const int kPlayerHumanityComputer = 4;
static const int kPlayerHumanityCyborg = 5;
static const int kPlayerHumanityViewOnly = 6;
static const int kCommStatePause = 4;
static const int kCommStateRunning = 5;
static const int kCommWindowMessagePause = 0x17a2;
static const int kCommWindowMessageResume = 0x17a3;

// Source-of-truth constants from com_hand.cpp.asm:
// - COMM_UPDATE_PARAMS literal pushed at SetPlayerHumanity+0x35 (0x0042cc5e): 0x17a6
// - COMM_STATE_JOINNOW compare at SetPlayerHumanity+0x41 (0x0042cc71): 3
static const int kCommMessageUpdateParams = 0x17a6;
static const int kCommMessageUpdatePlayers = 0x17a4;
static const int kCommMessagePlayerKicked = 0x17aa;
static const int kCommMessageSyncError = 0x17b0;
static const int kCommMessagePlayerDropped = 0x17b2;
static const int kCommMessageOtherPlayerDropped = 0x17b3;
static const int kCommMessagePlayerDefeated = 0x17b5;
static const int kCommMessageSharedDataSent = 0x17bb;
static const int kCommMessagePlayerNotResponding = 0x17bd;
static const int kCommMessagePlayerIdSet = 0x17b8;
static const int kCommStateJoinNow = 3;

// Source-of-truth mirror for DAT_0062cf04 (local/self DPID).
// Updated through player/link identity sync paths.
static ulong s_localPlayerDpid = 0;
static ulong s_lastRateUpdateTime = 0;
static ulong s_lastRateTX = 0;
static ulong s_lastRateRX = 0;
static int s_rateInit = 0;
static ulong s_intentionalDropCounter = 0;
static ulong s_nextSequenceTurn = 0;
static uchar s_nextSequence = 1;

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

static uchar comm_get_next_sequence(ulong execute_on_turn, int program_state) {
    // Source of truth: com_hand.cpp.decomp @ 0x0042B200
    if (execute_on_turn != s_nextSequenceTurn) {
        s_nextSequenceTurn = execute_on_turn;
        s_nextSequence = 1;
        return 1;
    }

    uchar next = (uchar)(s_nextSequence + 1);
    s_nextSequence = next;
    if (next == 0xFF) {
        return 0;
    }

    if (program_state == kCommStatePause && next > 100) {
        s_nextSequence = 100;
        return 100;
    }

    return next;
}

static IDirectPlay2* comm_get_dplay(TCommunications_Handler* comm) {
    if (comm == nullptr) {
        return nullptr;
    }

    if (comm->Lobby == nullptr || comm->Lobby->glpDP == nullptr) {
        return nullptr;
    }

    comm->Lobby->glpDP->AddRef();
    return comm->Lobby->glpDP;
}

static uint comm_find_player_by_dpid(TCommunications_Handler* comm, ulong dpid) {
    if (comm == nullptr || dpid == 0) {
        return 0;
    }

    COMMPLAYEROPTIONS* opts = &comm->PlayerOptions;
    uint low = (uint)opts->LowPlayerNumber;
    uint high = (uint)opts->HighPlayerNumber;
    if (low < 1) low = 1;
    if (high > (uint)comm->MaxGamePlayers) high = (uint)comm->MaxGamePlayers;
    if (high > 9) high = 9;
    if (high < low) {
        return 0;
    }

    for (uint p = low; p <= high && p < 10; ++p) {
        if (opts->dcoID[p] == dpid) {
            return p;
        }
    }
    return 0;
}

static long comm_fast_send_raw(TCommunications_Handler* comm, ulong to_dpid, const void* data, ulong len, ulong flags) {
    if (comm == nullptr || data == nullptr) {
        return 0;
    }

    IDirectPlay2* dp = comm_get_dplay(comm);
    if (dp == nullptr) {
        return 0;
    }

    ulong from_dpid = s_localPlayerDpid;
    if (from_dpid == 0 && comm->Me != 0 && comm->Me <= (uint)comm->MaxGamePlayers) {
        from_dpid = comm->PlayerOptions.dcoID[comm->Me];
        if (from_dpid != 0) {
            s_localPlayerDpid = from_dpid;
        }
    }

    if (from_dpid == 0) {
        (void)dp->Release();
        return DPERR_INVALIDPLAYER;
    }

    HRESULT hr = dp->Send((DPID)from_dpid, (DPID)to_dpid, (DWORD)flags, (void*)data, (DWORD)len);
    (void)dp->Release();
    return (long)hr;
}

static long comm_fast_send_player(TCommunications_Handler* comm, uint to_player, const void* data, ulong len) {
    if (comm == nullptr || to_player == 0 || to_player > (uint)comm->MaxGamePlayers) {
        return 0;
    }
    ulong to_dpid = comm->PlayerOptions.dcoID[to_player];
    if (to_dpid == 0) {
        return 0;
    }
    long hr = comm_fast_send_raw(comm, to_dpid, data, len, 0);
    if (hr == 0) {
        comm->TXPacketLength += len;
    }
    return hr;
}

static void comm_store_incoming(TCommunications_Handler* comm, uint serial, const char* msg, ulong len, ulong from_dpid,
                                ulong to_dpid) {
    if (comm == nullptr || comm->OnHold == nullptr || msg == nullptr || len == 0) {
        return;
    }

    unsigned char* on_hold = (unsigned char*)comm->OnHold;
    for (uint offset = 0; offset <= 0x2EF8; offset += 0x18) {
        ulong* slot = (ulong*)(on_hold + offset);
        if (slot[2] == 0) {
            void* copy = ::operator new((size_t)len, std::nothrow);
            if (copy == nullptr) {
                return;
            }
            memcpy(copy, msg, (size_t)len);
            slot[0] = (ulong)copy;
            slot[1] = (ulong)serial;
            slot[2] = (ulong)len;
            slot[3] = (ulong)from_dpid;
            slot[4] = (ulong)to_dpid;
            comm->HoldCount += 1;
            return;
        }
    }
}

static void comm_tx_ack(TCommunications_Handler* comm, uint serial, uint to_player) {
    struct MsgAck {
        uchar cmd;
        uchar _pad0;
        uchar _pad1;
        uchar _pad2;
        uint serial;
    } ack;
    memset(&ack, 0, sizeof(ack));
    ack.cmd = (uchar)'A';
    ack.serial = serial;
    (void)comm_fast_send_player(comm, to_player, &ack, sizeof(ack));
}

static void comm_tx_resend_request(TCommunications_Handler* comm, uint serial, uint to_player) {
    struct MsgResendReq {
        uchar cmd;
        uchar _pad0;
        uchar _pad1;
        uchar _pad2;
        uint serial;
    } req;
    memset(&req, 0, sizeof(req));
    req.cmd = (uchar)'X';
    req.serial = serial;
    (void)comm_fast_send_player(comm, to_player, &req, sizeof(req));
}

static void comm_rx_ack_stored(TCommunications_Handler* comm, uint serial, uint from_player) {
    if (comm == nullptr || comm->Resend == nullptr || serial == 0 || from_player == 0 || from_player >= 10) {
        return;
    }

    unsigned char* resend = (unsigned char*)comm->Resend;
    for (uint offset = 0; offset <= 0x6D98; offset += 0x38) {
        ulong* slot = (ulong*)(resend + offset);
        const uint slot_serial = (uint)slot[1];
        if (slot_serial != serial) {
            continue;
        }
        ulong* dest_map = (ulong*)(resend + offset + 0x10);
        dest_map[from_player] = 0;
        return;
    }
}

static void comm_purge_ackd_stored(TCommunications_Handler* comm) {
    if (comm == nullptr || comm->Resend == nullptr) {
        return;
    }

    comm->WaitingForAck = 0;

    unsigned char* resend = (unsigned char*)comm->Resend;
    for (uint offset = 0; offset <= 0x6D98; offset += 0x38) {
        ulong* slot = (ulong*)(resend + offset);
        const uint serial = (uint)slot[1];
        if (serial == 0) {
            continue;
        }

        int any_pending = 0;
        ulong* dest_map = (ulong*)(resend + offset + 0x10);
        for (uint player = 1; player <= (uint)comm->MaxGamePlayers && player < 10; ++player) {
            if (comm->IsPlayerHuman(player) != 0 && player != comm->Me && dest_map[player] != 0) {
                any_pending = 1;
                break;
            }
        }

        if (!any_pending) {
            void* payload = (void*)slot[2];
            if (payload != nullptr) {
                ::operator delete(payload);
            }
            slot[0] = 0;
            slot[1] = 0;
            slot[2] = 0;
            slot[3] = 0;
            memset(resend + offset + 0x10, 0, 0x28);
        } else {
            comm->WaitingForAck += 1;
        }
    }
}

static int comm_tx_resend_reply(TCommunications_Handler* comm, uint serial, uint requester_player) {
    if (comm == nullptr || comm->Resend == nullptr || serial == 0 || requester_player == 0) {
        return 0;
    }

    unsigned char* resend = (unsigned char*)comm->Resend;
    for (uint offset = 0; offset <= 0x6D98; offset += 0x38) {
        ulong* slot = (ulong*)(resend + offset);
        if ((uint)slot[1] != serial) {
            continue;
        }
        if (slot[2] == 0 || slot[3] == 0) {
            return 0;
        }

        ulong* dest_map = (ulong*)(resend + offset + 0x10);
        if (dest_map[requester_player] != 0) {
            dest_map[requester_player] -= 1;
        }

        long hr = comm_fast_send_raw(comm, comm->PlayerOptions.dcoID[requester_player], (void*)slot[2], slot[3], 0);
        if (hr == 0) {
            comm->TXPacketLength += slot[3];
        }
        return 1;
    }
    return 0;
}

static void comm_tx_ping(TCommunications_Handler* comm, uint to_player) {
    struct MsgPing {
        uchar cmd;
        uchar _pad0;
        uchar _pad1;
        uchar _pad2;
        ulong initiated;
        ulong current_turn;
    } ping;

    if (comm == nullptr) {
        return;
    }

    ulong now = GetTickCount();
    memset(&ping, 0, sizeof(ping));
    ping.cmd = (uchar)'1';
    ping.initiated = now;
    ping.current_turn = comm->current_turn;

    (void)comm_fast_send_player(comm, to_player, &ping, sizeof(ping));
    comm->LastTXPing[to_player] = now;
}

static int comm_all_players_acknowledged(TCommunications_Handler* comm) {
    if (comm == nullptr) {
        return 0;
    }

    COMMPLAYEROPTIONS* opts = &comm->PlayerOptions;
    uint low = (uint)opts->LowPlayerNumber;
    uint high = (uint)opts->HighPlayerNumber;
    if (low < 1) low = 1;
    if (high > (uint)comm->MaxGamePlayers) high = (uint)comm->MaxGamePlayers;

    for (uint p = low; p <= high; ++p) {
        if (comm->IsPlayerHuman(p) == 0) {
            continue;
        }
        if (comm->LastTurnAck[p] < comm->current_turn) {
            return 0;
        }
    }
    return 1;
}

static int comm_evaluate_player_message(TCommunications_Handler* comm, ulong full_len, uint from_player, ulong execute_on_turn,
                                        uchar command, uchar sequence, const char* payload, uint payload_len, ulong from_dpid,
                                        ulong to_dpid) {
    (void)full_len;
    (void)from_dpid;
    (void)to_dpid;

    if (comm == nullptr || payload == nullptr) {
        return 0;
    }

    switch (command) {
    case 0x3E: // '>' command
        comm->AddCommand(execute_on_turn, (void*)payload, (ulong)payload_len, (int)from_player, sequence, 0);
        return 1;
    case 'C': {
        // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004282C0 (EvaluatePlayerMessage case 0x43)
        if (payload_len < 0x11) {
            return 1;
        }

        const uchar pregame = (uchar)payload[0x10];
        if (pregame != 0 && comm->PlayerOptions.ProgramState != kCommStateJoinNow) {
            return 0;
        }

        if (comm->Chat == nullptr || comm->FriendlyName == nullptr) {
            return 1;
        }

        const uint me = comm->Me;
        const int joinNow = (comm->PlayerOptions.ProgramState == kCommStateJoinNow) ? 1 : 0;
        if ((joinNow != 0) || (me != 0 && me <= (uint)comm->MaxGamePlayers && payload[me + 1] == 'Y')) {
            const uint from = (uint)(uchar)payload[0];
            if (from != 0 && from <= (uint)comm->MaxGamePlayers) {
                comm->Chat->AddChatMsg(comm->FriendlyName[from].Text, (char*)(payload + 0x11), 0);
            }
        }

        return 1;
    }
    case 'D': {
        if (payload_len >= 8) {
            ulong done_turn = *(const ulong*)(payload + 4);
            ulong ack_turn = done_turn - (ulong)comm->PlayerOptions.CommandTurnIncrement;
            if (ack_turn > comm->LastTurnAck[from_player]) {
                comm->LastTurnAck[from_player] = ack_turn;
            }
        }
        return 1;
    }
    case 'K': {
        if (payload_len >= 0x0C) {
            const ulong dpid = *(const ulong*)(payload + 4);
            uint victim = comm_find_player_by_dpid(comm, dpid);
            if (victim != 0 && comm->PlayerStopTurn[victim] == 0) {
                comm->DropDeadPlayer(victim, dpid);
            }
            if (victim == comm->Me) {
                comm->NotifyWindow(kCommMessagePlayerKicked);
            } else if (victim != 0 && comm->PlayerStopTurn[victim] == 0) {
                comm->NotifyWindowParam(kCommMessageOtherPlayerDropped, (long)victim);
            }
        }
        return 1;
    }
    default:
        return 1;
    }
}
}

TCommunications_Handler::TCommunications_Handler(void* host_hwnd, uchar max_game_players) {
    // Source of truth: com_hand.cpp.decomp @ 0x00425A40 (constructor)
    memset(this, 0, sizeof(*this));

    this->HostHWND = host_hwnd;
    this->MaxGamePlayers = max_game_players;
    this->CommunicationsStatus = COMM_IDLE;

    this->InQ = new RGE_Communications_Queue(0x1f5);

    this->Lobby = (RGE_Lobby*)calloc(1, sizeof(RGE_Lobby));
    if (this->Lobby != nullptr) {
        this->Lobby->HostHWND = host_hwnd;
        this->Lobby->glpDP = nullptr;
    }

    // Arrays sized like original (0x1f6 entries).
    this->Resend = (RESENDER*)::operator new((size_t)0x6DD0, std::nothrow);
    this->OnHold = (HOLDER*)::operator new((size_t)0x2F10, std::nothrow);
    if (this->Resend != nullptr) {
        memset(this->Resend, 0, 0x6DD0);
    }
    if (this->OnHold != nullptr) {
        memset(this->OnHold, 0, 0x2F10);
    }

    this->FriendlyName = new NAME[(size_t)max_game_players + 1];
    this->FormalName = new NAME[(size_t)max_game_players + 1];
    if (this->FriendlyName != nullptr) {
        memset(this->FriendlyName, 0, sizeof(NAME) * ((size_t)max_game_players + 1));
    }
    if (this->FormalName != nullptr) {
        memset(this->FormalName, 0, sizeof(NAME) * ((size_t)max_game_players + 1));
    }

    this->Err = new (std::nothrow) RGE_Comm_Error(host_hwnd);

    this->Speed = (RGE_Communications_Speed*)calloc(1, sizeof(RGE_Communications_Speed));
    if (this->Speed != nullptr) {
        this->Speed->Comm = this;
    }
    this->Sync = (RGE_Communications_Synchronize*)calloc(1, sizeof(RGE_Communications_Synchronize));
    if (this->Sync != nullptr) {
        this->Sync->Comm = this;
    }

    COMMPLAYEROPTIONS* opts = &this->PlayerOptions;
    memset(opts, 0, sizeof(*opts));
    opts->LowPlayerNumber = 1;
    opts->HighPlayerNumber = max_game_players;
    opts->GameHasStarted = 0;
    opts->ProgramState = kCommStateJoinNow;
    opts->CommandTurnIncrement = 2;
    this->current_turn = 4;
    opts->CurrentTurn = 4;
    this->AcknowledgeAfterMsec = 0x32;
    opts->NeedsToBeSent = 0;

    for (uint p = 1; p <= (uint)max_game_players; ++p) {
        this->InitPlayerInformation(p, 0, (char*)"", (char*)"");
    }

    this->Steps = 1;
    this->ResetLastCommunicationTimes();
    this->WaitingForAck = 0;

    if (this->InQ != nullptr) {
        this->InQ->FlushAll();
    }
}

TCommunications_Handler::~TCommunications_Handler() {
    // Source of truth: com_hand.cpp.decomp @ 0x004261E0 (destructor)
    this->ClearRXandTX();

    if (this->InQ != nullptr) {
        delete this->InQ;
        this->InQ = nullptr;
    }

    if (this->Lobby != nullptr) {
        free(this->Lobby);
        this->Lobby = nullptr;
    }

    if (this->FriendlyName != nullptr) {
        delete[] this->FriendlyName;
        this->FriendlyName = nullptr;
    }
    if (this->FormalName != nullptr) {
        delete[] this->FormalName;
        this->FormalName = nullptr;
    }

    if (this->Resend != nullptr) {
        ::operator delete(this->Resend);
        this->Resend = nullptr;
    }
    if (this->OnHold != nullptr) {
        ::operator delete(this->OnHold);
        this->OnHold = nullptr;
    }

    if (this->Speed != nullptr) {
        free(this->Speed);
        this->Speed = nullptr;
    }
    if (this->Sync != nullptr) {
        free(this->Sync);
        this->Sync = nullptr;
    }

    if (this->Err != nullptr) {
        delete this->Err;
        this->Err = nullptr;
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

void TCommunications_Handler::LastWorldRandom(int param_1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426630
    this->Sync->SetLastWorldRandom((ulong)param_1);
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
    // Source of truth: com_hand.cpp.decomp @ 0x00426650
    if (this->Multiplayer == 0) {
        return (this->PlayerOptions.ProgramState == kCommStatePause) ? 0 : -1;
    }
    if ((uint)this->MaxGamePlayers < this->Me) {
        return 0;
    }

    ReceiveGameMessages();
    this->LastPlayerCommunication[this->Me] = now;

    if (this->PlayerOptions.ProgramState != kCommStateJoinNow && this->LastTurnAck[this->Me] != this->current_turn) {
        this->LastTurnAck[this->Me] = this->current_turn;

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
        done_msg.execute_on_turn = this->current_turn + (ulong)this->PlayerOptions.CommandTurnIncrement;
        if (this->current_turn > 6 && this->Speed != nullptr) {
            done_msg.high_latency_centi = comm_speed_get_high_latency_centi(this->Speed);
            done_msg.frame_rate_msec = (uchar)comm_speed_get_avg_frame_rate(this->Speed);
        }
        (void)this->CommOut((uchar)'D', (void*)&done_msg, 0x0C, 0);
    }

    if (this->StepMode != 0) {
        if (this->Steps == 0) {
            return 0;
        }
        this->Steps -= 1;
    }

    if (this->OutOfSyncFlag == 1 && this->dwStopTime <= now) {
        this->NotifyWindowParam(kCommMessageSyncError, (long)this->dwStopTime);
        return 0;
    }

    if (this->PlayerOptions.ProgramState == kCommStateRunning && comm_all_players_acknowledged(this) != 0) {
        this->current_turn += 1;
        this->PlayerOptions.CurrentTurn = this->current_turn;
        return 1;
    }

    // If we're waiting on acks in an active game, occasionally force ping checks.
    if (this->PlayerOptions.ProgramState >= kCommStateRunning) {
        if (this->LastTimeoutMessageTime == 0 || now - this->LastTimeoutMessageTime > 25000) {
            this->CheckPingTime(1);
            this->LastTimeoutMessageTime = now;
        }
    }

    return 0;
}

void TCommunications_Handler::ReceiveGameMessages() {
    // Source of truth: com_hand.cpp.decomp @ 0x00426E10
    if (this->Multiplayer == 0) {
        return;
    }

    ulong now = GetTickCount();
    if (s_rateInit == 0) {
        s_rateInit = 1;
        s_lastRateUpdateTime = now;
        s_lastRateTX = this->TXPacketLength;
        s_lastRateRX = this->RXPacketLength;
    }

    ulong elapsed = now - s_lastRateUpdateTime;
    if (elapsed > 1000) {
        const ulong tx_delta = this->TXPacketLength - s_lastRateTX;
        const ulong rx_delta = this->RXPacketLength - s_lastRateRX;
        this->lastTXDataRate = (elapsed != 0) ? ((float)tx_delta * 1000.0f) / (float)elapsed : 0.0f;
        this->lastRXDataRate = (elapsed != 0) ? ((float)rx_delta * 1000.0f) / (float)elapsed : 0.0f;
        s_lastRateTX = this->TXPacketLength;
        s_lastRateRX = this->RXPacketLength;
        s_lastRateUpdateTime = now;
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        (void)this->ExecuteIncoming();
    }

    this->GetDPLAYMessages();

    if (this->RGE_Guaranteed_Delivery != 0) {
        (void)this->ExecuteIncoming();
        this->SendStoredMessages();
    }

    this->CheckPingTime(0);
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
    // Source of truth: com_hand.cpp.decomp @ 0x00426FC0
    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return;
    }

    while (true) {
        DPID from_id = 0;
        DPID to_id = 0;
        DWORD dwSize = sizeof(this->InCommBuff) - 1;

        HRESULT hr = dp->Receive(&from_id, &to_id, 0, this->InCommBuff, &dwSize);
        if (hr == DPERR_NOMESSAGES) {
            break;
        }
        if (hr == DPERR_BUFFERTOOSMALL) {
            char* big = (char*)calloc((size_t)dwSize + 1, 1);
            if (big == nullptr) {
                break;
            }

            DWORD bigSize = dwSize;
            hr = dp->Receive(&from_id, &to_id, 0, big, &bigSize);
            if (hr == 0) {
                big[bigSize] = '\0';
                this->RXPacketLength += bigSize;
                this->RXPackets += 1;
                if (from_id == 0) {
                    this->EvaluateSystemMessage(bigSize, big, (ulong)from_id, (ulong)to_id);
                } else {
                    (void)this->PreprocessMessages(bigSize, big, (ulong)from_id, (ulong)to_id, 0);
                }
            }
            free(big);
            if (hr != 0) {
                break;
            }
            continue;
        }
        if (hr != 0) {
            break;
        }

        this->InCommBuff[dwSize] = '\0';
        this->RXPacketLength += dwSize;
        this->RXPackets += 1;

        if (from_id == 0) {
            this->EvaluateSystemMessage(dwSize, this->InCommBuff, (ulong)from_id, (ulong)to_id);
        } else {
            (void)this->PreprocessMessages(dwSize, this->InCommBuff, (ulong)from_id, (ulong)to_id, 0);
        }
    }

    (void)dp->Release();
}

void TCommunications_Handler::EvaluateSystemMessage(ulong p1, char* p2, ulong p3, ulong p4) {
    // Source of truth: com_hand.cpp.decomp @ 0x00428DA0
    (void)p1;
    (void)p3;
    (void)p4;

    if (this->Multiplayer == 0 || p2 == nullptr) {
        return;
    }

    const DWORD msg_type = *(const DWORD*)p2;
    if (msg_type == DPSYS_CREATEPLAYERORGROUP) {
        DPMSG_CREATEPLAYERORGROUP* m = (DPMSG_CREATEPLAYERORGROUP*)p2;
        if (m->dwPlayerType != DPPLAYERTYPE_PLAYER) {
            return;
        }

        // Reject late-join requests once game is running.
        if (this->PlayerOptions.ProgramState == kCommStateRunning || this->current_turn > 6) {
            const char deny = 'I';
            (void)comm_fast_send_raw(this, (ulong)m->dpId, &deny, 1, 0);
            return;
        }

        if (this->MeHost == 0) {
            return;
        }

        uint free_slot = 0;
        for (uint p = 1; p <= (uint)this->MaxGamePlayers; ++p) {
            if (this->PlayerOptions.Humanity[p] == 0) {
                free_slot = p;
                break;
            }
        }

        if (free_slot != 0 && this->PlayerOptions.ProgramState == kCommStateJoinNow) {
            const char* friendly = m->dpnName.lpszShortNameA ? m->dpnName.lpszShortNameA : "";
            const char* formal = m->dpnName.lpszLongNameA ? m->dpnName.lpszLongNameA : "";
            this->InitPlayerInformation(free_slot, (ulong)m->dpId, (char*)friendly, (char*)formal);
            this->PlayerOptions.dcoID[free_slot] = (ulong)m->dpId;
            this->PlayerOptions.Humanity[free_slot] = kPlayerHumanityHuman;
            this->PlayerOptions.NeedsToBeSent = 1;
            this->PlayerOptions.InvalidPlayer[free_slot] = 0;
            this->CalculatePlayerRange();
            this->UpdatePlayer(free_slot, 1);
            this->PlayerOptions.NeedsToBeSent = 1;
            this->PlayerHighSerialNumber[free_slot] = free_slot * 2000;
            this->ClearRXandTX();
            (void)this->SendSharedData(0);
            return;
        }

        const char deny = 'I';
        (void)comm_fast_send_raw(this, (ulong)m->dpId, &deny, 1, 0);
        this->UpdatePlayers();
        return;
    }

    if (msg_type == DPSYS_DESTROYPLAYERORGROUP) {
        DPMSG_DESTROYPLAYERORGROUP* m = (DPMSG_DESTROYPLAYERORGROUP*)p2;
        if (m->dwPlayerType != DPPLAYERTYPE_PLAYER) {
            return;
        }

        const uint player = comm_find_player_by_dpid(this, (ulong)m->dpId);
        if (player != 0 && this->IsPlayerHuman(player) != 0 && this->PlayerStopTurn[player] == 0) {
            if (player == this->Me) {
                this->NotifyWindow(kCommMessagePlayerDropped);
            } else {
                this->NotifyWindowParam(kCommMessageOtherPlayerDropped, (long)player);
            }
        }

        if (this->MeHost != 0 && player != 0) {
            struct KillPlayerMsg {
                uint PlayerNo;
                ulong dcoID;
                ulong CurrentTurn;
            } kp;
            kp.PlayerNo = player;
            kp.dcoID = (ulong)m->dpId;
            kp.CurrentTurn = this->current_turn;
            (void)this->CommOut((uchar)'K', &kp, 0x0C, 0);
        }

        if (player != 0 && this->PlayerStopTurn[player] == 0) {
            this->DropDeadPlayer(player, (ulong)m->dpId);
        }
        return;
    }
}

void TCommunications_Handler::UpdatePlayers() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042DF40
    uint low = (uint)this->PlayerOptions.LowPlayerNumber;
    uint high = (uint)this->PlayerOptions.HighPlayerNumber;
    if (low <= high) {
        for (uint p = low; p <= high; ++p) {
            this->UpdatePlayer(p, 0);
        }
    }
    this->NotifyWindow(kCommMessageUpdatePlayers);
}

void TCommunications_Handler::UpdatePlayer(uint id, int timeout) {
    // Source of truth: com_hand.cpp.decomp/.asm @ 0x0042DF90
    COMMPLAYEROPTIONS* opts = &this->PlayerOptions;
    const int humanity = opts->Humanity[id];
    const ulong dpid = opts->dcoID[id];

    switch (humanity) {
    case 0: // ME_ABSENT
        L->Log("P#%d ABSENT", id);
        opts->dcoID[id] = 0;
        opts->PlayerReady[id] = 0;
        goto done;
    case kPlayerHumanityEliminated: // ME_ELIMINATED
        L->Log("P#%d ELIMINATED", id);
        opts->dcoID[id] = 0;
        opts->PlayerReady[id] = 0;
        goto done;
    case kPlayerHumanityClosed: // ME_CLOSED
        L->Log("P#%d CLOSED", id);
        opts->dcoID[id] = 0;
        opts->PlayerReady[id] = 1;
        goto done;
    case kPlayerHumanityHuman: // ME_HUMAN
        L->Log("P#%d HUMAN", id);
        break;
    case kPlayerHumanityComputer: // ME_COMPUTER
        L->Log("P#%d COMPUTER", id);
        opts->dcoID[id] = 0;
        opts->PlayerReady[id] = 1;
        goto done;
    case kPlayerHumanityCyborg: // ME_CYBORG
        L->Log("P#%d CYBORG", id);
        break;
    case kPlayerHumanityViewOnly: // ME_VIEWONLY
        opts->PlayerReady[id] = 1;
        L->Log("P#%d VIEWONLY", id);
        break;
    default:
        strcpy(this->FriendlyName[id].Text, "Error");
        L->Log("COMM:INVALID P#%d HUMANITY SETTING %d", id, humanity);
        return;
    }

    if (dpid == 0) {
        L->Log("P#%d Not Defined (updateplayers).", id);
        return;
    }

    IDirectPlay3* dp = this->GetDPInterface();
    if (dp == nullptr) {
        return;
    }

    DWORD size = 0;
    (void)dp->GetPlayerName((DPID)dpid, nullptr, &size);
    void* lpData = calloc((size_t)size, 1);

    HRESULT hr = dp->GetPlayerName((DPID)dpid, lpData, &size);
    this->Err->ShowReturn((long)hr, "Get PName Info");

    const long lhr = (long)hr;
    const long kHrBufferTooSmall = (long)0x8877001e;
    const long kHrInvalidArg = (long)0x80070057;
    const long kHrFatalOther = (long)0x88770082;
    const long kHrInvalidPlayer = (long)0x88770096;

    if (lhr <= kHrBufferTooSmall) {
        if (lhr == kHrBufferTooSmall || lhr == kHrInvalidArg) {
            L->Log("Fatal error player info %ld", lhr);
            strcpy(this->FriendlyName[id].Text, "Error!");
            opts->Humanity[id] = 0;
        } else {
            L->Log("Unknown fail on updateplayers");
            opts->Humanity[id] = 0;
            opts->dcoID[id] = 0;
        }
    } else {
        if (lhr == kHrFatalOther) {
            L->Log("Fatal error player info %ld", lhr);
            strcpy(this->FriendlyName[id].Text, "Error!");
            opts->Humanity[id] = 0;
        } else if (lhr == kHrInvalidPlayer) {
            L->Log("INVALID PLAYER %d.  Removing.", (long)dpid);
            if (opts->ProgramState == kCommStateJoinNow) {
                opts->Humanity[id] = kPlayerHumanityHuman;
                if (this->IsPlayerHuman(id) != 0) {
                    L->Log("INVALID PLAYER");
                    L->Log("TX Missing Player report for player=%d ", (long)dpid);
                    struct MsgMissingPlayer {
                        uchar cmd;
                        uchar _pad0;
                        uchar _pad1;
                        uchar _pad2;
                        ulong dpid;
                    } m;
                    memset(&m, 0, sizeof(m));
                    m.cmd = (uchar)'?';
                    m.dpid = dpid;
                    L->Log("  >TX MP #%d (%d)", (long)dpid, 8);
                    (void)comm_fast_send_raw(this, 0, &m, 8, 0);
                }
            }
        } else if (lhr == 0) {
            const DPNAME* name = (const DPNAME*)lpData;
            memcpy(this->FriendlyName[id].Text, name->lpszShortNameA, strlen(name->lpszShortNameA) + 1);
            memcpy(this->FormalName[id].Text, name->lpszLongNameA, strlen(name->lpszLongNameA) + 1);
            opts->Humanity[id] = kPlayerHumanityHuman;
        } else {
            L->Log("Unknown fail on updateplayers");
            opts->Humanity[id] = 0;
            opts->dcoID[id] = 0;
        }
    }

    free(lpData);
    (void)dp->Release();

done:
    if (timeout != 0) {
        this->NotifyWindow(kCommMessageUpdatePlayers);
    }
}

void TCommunications_Handler::NotifyWindow(int message) {
    // Source-of-truth:
    // - com_hand.cpp.decomp NotifyWindow/NotifyWindowParam
    // - com_hand.cpp.asm 0x00428270 / 0x00428280
    // Behavior: Post WM_USER to HostHWND with message as wParam and 0 as lParam.
    // Note: we use integer ids because the full COMMMESSAGES enum is not restored yet.
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
    // Source of truth: com_hand.cpp.decomp @ 0x00428820
    if (this->MeHost == 0) {
        return 0;
    }

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return 0;
    }

    ulong now = GetTickCount();
    if (send_mode == 0) {
        if (now - this->PlayerOptions.LastSentTime < 2000) {
            (void)dp->Release();
            return 0;
        }
    } else {
        this->PlayerOptions.NeedsToBeSent = 1;
    }

    if (this->PlayerOptions.NeedsToBeSent == 0) {
        (void)dp->Release();
        return 0;
    }

    ulong local_dpid = s_localPlayerDpid;
    if (local_dpid == 0 && this->Me != 0 && this->Me <= (uint)this->MaxGamePlayers) {
        local_dpid = this->PlayerOptions.dcoID[this->Me];
        if (local_dpid != 0) {
            s_localPlayerDpid = local_dpid;
        }
    }
    if (local_dpid == 0) {
        (void)dp->Release();
        return DPERR_INVALIDPLAYER;
    }

    const ulong extra_len = this->PlayerOptions.DataSizeToFollow;
    const ulong total_len = extra_len + (ulong)sizeof(COMMPLAYEROPTIONS);
    char* buf = (char*)::operator new((size_t)total_len, std::nothrow);
    if (buf == nullptr) {
        (void)dp->Release();
        return 0;
    }

    memcpy(buf, &this->PlayerOptions, sizeof(COMMPLAYEROPTIONS));
    if (extra_len != 0 && this->OptionsData != nullptr) {
        memcpy(buf + sizeof(COMMPLAYEROPTIONS), this->OptionsData, (size_t)extra_len);
    }

    this->PlayerOptions.LastSentTime = now;
    HRESULT hr = dp->SetPlayerData((DPID)local_dpid, buf, (DWORD)total_len, DPSET_GUARANTEED);

    ::operator delete(buf);
    (void)dp->Release();

    this->PlayerOptions.NeedsToBeSent = 0;
    this->NotifyWindow(kCommMessageSharedDataSent);

    for (uint p = 1; p <= (uint)this->MaxGamePlayers; ++p) {
        this->PlayerOptions.InvalidPlayer[p] = 0;
    }

    return (long)hr;
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

int TCommunications_Handler::IsPlayerOutOfSync(uint player_number, ulong comm_turn) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F270
    return this->Sync->IsPlayerOutOfSync(player_number, comm_turn);
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

    void* dp_base = (this->Lobby != nullptr) ? (void*)this->Lobby->glpDP : nullptr;
    if (dp_base != nullptr) {
        this->EnableNewPlayers(dp_base, 0);
    }
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
    for (uint player = 1; player <= (uint)this->MaxGamePlayers && player < 10; ++player) {
        this->LastPlayerCommunication[player] = now;
        this->LastTXPing[player] = now;
    }
}

void TCommunications_Handler::ClearAllSerialNumbers() {
    // Source of truth: com_hand.cpp.decomp @ 0x00429F80
    for (uint player = 0; player <= (uint)this->MaxGamePlayers && player < 10; ++player) {
        this->PlayerHighSerialNumber[player] = 0;
        this->LastSerialRequestedTX[player] = 0;
        this->LastRequestHonoredTX[player] = 0;
        this->LastSerialRepliedTX[player] = 0;
        this->LastRequestRepliedTX[player] = 0;
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
    // Source of truth: com_hand.cpp.decomp @ 0x00428B10
    (void)turn;

    this->WasKicked[id] = 1;
    this->PlayerOptions.InvalidPlayer[id] = 0;

    if (id == 0) {
        this->UpdatePlayers();
        return;
    }

    if (id != this->Me) {
        if (this->IsPlayerHuman(id) == 0) {
            this->NotifyWindowParam(kCommMessagePlayerDefeated, (long)id);
            this->InitPlayerInformation(id, 0, (char*)"Defeated", (char*)"No Other Information");
            this->UpdatePlayers();
            this->CalculatePlayerRange();
            return;
        }

        if (this->PlayerOptions.ProgramState < kCommStateRunning || this->current_turn < 6) {
            this->InitPlayerInformation(id, 0, (char*)"Dropped", (char*)"No Other Information");
            this->SetPlayerHumanity(id, 0);
            this->UpdatePlayers();
            this->CalculatePlayerRange();
        } else {
            this->InitPlayerInformation(id, 0, (char*)"Dropped", (char*)"");
            this->SetPlayerHumanity(id, 0);
            this->UpdatePlayers();
            this->CalculatePlayerRange();
            if (this->PlayerStopTurn[id] != 0) {
                return;
            }
        }

        this->NotifyWindowParam(kCommMessageOtherPlayerDropped, (long)id);
        return;
    }

    // Dropped self: re-init player list.
    this->NotifyWindowParam(kCommMessagePlayerDropped, (long)this->Me);
    for (uint p = 1; p <= (uint)this->MaxGamePlayers; ++p) {
        this->WasKicked[p] = 1;
    }

    for (uint p = 1; p <= (uint)this->MaxGamePlayers; ++p) {
        this->InitPlayerInformation(p, 0, (char*)"", (char*)"");
    }

    this->PlayerOptions.NeedsToBeSent = 0;
    this->PlayerOptions.LastSentTime = 0;
    this->UpdatePlayers();
}

void TCommunications_Handler::CheckPingTime(int p1) {
    // Source of truth: com_hand.cpp.decomp @ 0x00427300
    if (this->Multiplayer == 0) {
        return;
    }

    ulong now = GetTickCount();
    for (uint p = 1; p <= (uint)this->MaxGamePlayers; ++p) {
        if (this->IsPlayerHuman(p) == 0 || p == this->Me) {
            continue;
        }
        if ((now - this->LastTXPing[p] > 8000) || (p1 != 0)) {
            comm_tx_ping(this, p);
        }
    }
}

void TCommunications_Handler::SendGroupChatMsg(char* param_1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429760
    uchar destMap[10];
    memset(destMap, 'N', sizeof(destMap));

    if (this->MaxGamePlayers != 0 && this->Chat != nullptr) {
        for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
            if (this->Chat->inChatGroup((int)p) != 0) {
                destMap[p] = 'Y';
            }
        }
    }

    (void)this->TXChat(this->Me, destMap, param_1);
}

void TCommunications_Handler::SendChatMsgAll(char* param_1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004297D0
    uchar destMap[10];
    memset(destMap, 'N', sizeof(destMap));

    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        destMap[p] = 'Y';
    }

    (void)this->TXChat(this->Me, destMap, param_1);
}

void TCommunications_Handler::SendChatMsg(uint param_1, uint param_2, char* param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429810
    uchar destMap[10];
    memset(destMap, 'N', sizeof(destMap));

    if (param_2 < 10) {
        destMap[param_2] = 'Y';
    }

    (void)this->TXChat(param_1, destMap, param_3);
}

long TCommunications_Handler::TXChat(uint param_1, uchar* param_2, char* param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429870
    if (param_3 == nullptr) {
        return 0;
    }

    if (this->Multiplayer == 0) {
        if (this->Chat != nullptr && this->FriendlyName != nullptr && param_1 <= (uint)this->MaxGamePlayers) {
            this->Chat->AddChatMsg(this->FriendlyName[param_1].Text, param_3, 1);
        }
        return 0;
    }

    if (param_1 > (uint)this->MaxGamePlayers) {
        return 0x80004005; // E_FAIL
    }

    unsigned char cht[0x16 + 0x100];
    memset(cht, 0, sizeof(cht));

    // Build dest map filtered to human players only.
    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        if (this->IsPlayerHuman(p) != 0 && param_2 != nullptr && param_2[p] == 'Y') {
            cht[p + 1] = 'Y';
        } else {
            cht[p + 1] = 'N';
        }
    }

    // Add local chat line if we are one of the destinations.
    if (this->Chat != nullptr && this->FriendlyName != nullptr &&
        this->Me != 0 && this->Me <= (uint)this->MaxGamePlayers &&
        cht[this->Me + 1] == 'Y') {
        this->Chat->AddChatMsg(this->FriendlyName[param_1].Text, param_3, 1);
    }

    size_t msgLen = strlen(param_3);
    if (msgLen > 0xFF) {
        msgLen = 0xFF;
    }

    cht[0] = (uchar)param_1;
    *(uint*)(cht + 0x0C) = (uint)msgLen;
    cht[0x10] = (this->PlayerOptions.ProgramState == kCommStateJoinNow) ? 1 : 0;
    strncpy((char*)(cht + 0x11), param_3, msgLen + 1);

    long ret = this->CommOut((uchar)'C', (void*)cht, (long)((uint)msgLen + 0x16), 0);
    return ret;
}

void TCommunications_Handler::SendStoredMessages() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042A800 (simplified resend loop)
    if (this->RGE_Guaranteed_Delivery == 0 || this->Resend == nullptr) {
        return;
    }

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return;
    }

    comm_purge_ackd_stored(this);

    const ulong now = GetTickCount();
    ulong best_elapsed = 0;
    uint best_offset = 0xFFFFFFFF;

    unsigned char* resend = (unsigned char*)this->Resend;
    for (uint offset = 0; offset <= 0x6D98; offset += 0x38) {
        ulong* slot = (ulong*)(resend + offset);
        if (slot[1] == 0) {
            continue;
        }
        const ulong elapsed = now - slot[0];
        if (elapsed >= best_elapsed) {
            best_elapsed = elapsed;
            best_offset = offset;
        }
    }

    if (best_offset == 0xFFFFFFFF) {
        (void)dp->Release();
        return;
    }

    ulong min_elapsed = 500;
    if (this->current_turn < 7) {
        min_elapsed = 2000;
    } else if (this->ShuttingDown != 0) {
        min_elapsed = 250;
    } else if (this->Speed != nullptr) {
        min_elapsed = this->Speed->HighestLatencyMsec * 2;
        if (min_elapsed < 500) min_elapsed = 500;
    }

    if (best_elapsed < min_elapsed) {
        (void)dp->Release();
        return;
    }

    ulong* best = (ulong*)(resend + best_offset);
    best[0] = now; // TimeSent

    const ulong serial = best[1];
    char* msg = (char*)best[2];
    const DWORD len = (DWORD)best[3];
    if (msg == nullptr || len == 0) {
        (void)dp->Release();
        return;
    }

    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        if (this->IsPlayerHuman(p) == 0 || p == this->Me) {
            continue;
        }
        if (this->PlayerOptions.dcoID[p] == 0) {
            continue;
        }

        ulong* dest_map = (ulong*)(resend + best_offset + 0x10);
        if (dest_map[p] == 0) {
            continue;
        }

        if (dest_map[p] != 0) {
            dest_map[p] -= 1;
        }

        HRESULT hr = dp->Send((DPID)s_localPlayerDpid, (DPID)this->PlayerOptions.dcoID[p], 0, msg, len);
        if (hr == 0) {
            this->ResentToOther += 1;
            this->TXPacketLength += (ulong)len;
        }
    }

    (void)serial;
    (void)dp->Release();
}

int TCommunications_Handler::PreprocessMessages(ulong p1, char* p2, ulong p3, ulong p4, int p5) {
    // Source of truth: com_hand.cpp.decomp @ 0x00427600
    if (p2 == nullptr || p1 == 0) {
        return 0;
    }

    const uint from_player = comm_find_player_by_dpid(this, p3);
    const uchar cmd = (uchar)p2[0];
    if (cmd == 'I') {
        // Fully verified. Source of truth: com_hand.cpp.asm @ 0x0042764f
        (void)this->UnlinkToLevel(SERVICE_AVAILABLE);
        this->NotifyWindow(kCommMessageUpdatePlayers);
        this->NotifyWindow(kCommMessagePlayerKicked);
        return 1;
    }

    if (from_player == 0) {
        // Unknown sender: still send an ACK (matches original behavior).
        struct MsgAck {
            uchar cmd;
            uchar _pad0;
            uchar _pad1;
            uchar _pad2;
            uint serial;
        } ack;
        ack.cmd = (uchar)'A';
        ack._pad0 = 0;
        ack._pad1 = 0;
        ack._pad2 = 0;
        ack.serial = *(const uint*)(p2 + 8);

        if (s_localPlayerDpid != 0) {
            IDirectPlay2* dp = comm_get_dplay(this);
            if (dp != nullptr) {
                const HRESULT hr = dp->Send((DPID)s_localPlayerDpid, (DPID)p3, 0, &ack, 8);
                if (hr == 0) {
                    this->TXPacketLength += 8;
                }
                (void)dp->Release();
            }
        }
        return 0;
    }

    this->LastPlayerCommunication[from_player] = GetTickCount();

    if (cmd == 'A' && p1 >= 8) {
        const uint serial = *(const uint*)(p2 + 4);
        comm_rx_ack_stored(this, serial, from_player);
        comm_purge_ackd_stored(this);
        return 1;
    }

    if (cmd == 'X' && p1 >= 8) {
        const uint serial = *(const uint*)(p2 + 4);
        comm_tx_resend_reply(this, serial, from_player);
        return 1;
    }

    if (cmd == 'R' && this->MeHost != 0 && p1 >= 0x24) {
        this->PlayerOptions.PlayerReady[from_player] = (int)(uchar)p2[1];
        this->PlayerOptions.User1[from_player] = *(const ulong*)(p2 + 4);
        this->PlayerOptions.User2[from_player] = *(const ulong*)(p2 + 8);
        this->PlayerOptions.User3[from_player] = *(const ulong*)(p2 + 0x0C);
        this->PlayerOptions.User4[from_player] = *(const ulong*)(p2 + 0x10);
        this->PlayerOptions.User5[from_player] = *(const ulong*)(p2 + 0x14);
        this->PlayerOptions.User6[from_player] = *(const ulong*)(p2 + 0x18);
        this->PlayerOptions.User7[from_player] = *(const ulong*)(p2 + 0x1C);
        if (this->IsPlayerHuman(from_player) == 0) {
            this->SetPlayerHumanity(from_player, kPlayerHumanityHuman);
        }
        this->PlayerOptions.NeedsToBeSent = 1;
        (void)this->SendSharedData(0);
        this->UpdatePlayer(from_player, 0);
        this->NotifyWindow(kCommMessageUpdatePlayers);
        return 1;
    }

    if (cmd == '1' && p1 >= 0x0C) {
        struct MsgPong {
            uchar cmd;
            uchar _pad0;
            uchar _pad1;
            uchar _pad2;
            ulong initiated;
            ulong current_turn;
        } pong;
        memset(&pong, 0, sizeof(pong));
        pong.cmd = (uchar)'2';
        pong.initiated = *(const ulong*)(p2 + 4);
        pong.current_turn = this->current_turn;
        (void)comm_fast_send_player(this, from_player, &pong, sizeof(pong));
        return 1;
    }

    if (cmd == '2' && p1 >= 8) {
        if (this->Speed != nullptr) {
            const ulong initiated = *(const ulong*)(p2 + 4);
            const ulong now = GetTickCount();
            this->Speed->ActualLatency[from_player] = (uint)(now - initiated);
        }
        return 1;
    }

    // Non-guaranteed path: evaluate payload directly.
    if (this->RGE_Guaranteed_Delivery == 0) {
        if (p1 < 8) {
            return 1;
        }
        const ulong execute_on_turn = *(const ulong*)(p2 + 4);
        const uchar sequence = (uchar)p2[1];
        const char* payload = p2 + 8;
        const uint payload_len = (uint)(p1 - 8);
        return comm_evaluate_player_message(this, p1, from_player, execute_on_turn, cmd, sequence, payload, payload_len, p3, p4);
    }

    // Guaranteed delivery path.
    if (this->IntentionallyDropPackets != 0 && this->current_turn > 6) {
        s_intentionalDropCounter += 1;
        if (s_intentionalDropCounter > 8) {
            s_intentionalDropCounter = 0;
            return 1;
        }
    }

    if (p1 < 0x0C) {
        return 1;
    }

    const ulong execute_on_turn = *(const ulong*)(p2 + 4);
    const uint serial = *(const uint*)(p2 + 8);
    const uint expected = this->PlayerHighSerialNumber[from_player] + 1;

    if (this->PlayerHighSerialNumber[from_player] == 0) {
        this->PlayerHighSerialNumber[from_player] = serial - 1;
    }

    if (serial < expected) {
        comm_tx_ack(this, serial, from_player);
        return 1;
    }

    if (serial > expected) {
        this->DroppedPacketCount += 1;
        comm_store_incoming(this, serial, p2, p1, p3, p4);
        comm_tx_ack(this, serial, from_player);
        comm_tx_resend_request(this, expected, from_player);
        return 1;
    }

    if (p5 == 0) {
        comm_tx_ack(this, serial, from_player);
    }

    this->PlayerHighSerialNumber[from_player] = serial;
    const uchar sequence = (uchar)p2[1];
    const char* payload = p2 + 0x0C;
    const uint payload_len = (uint)(p1 - 0x0C);

    if (this->ShuttingDown == 0) {
        (void)comm_evaluate_player_message(this, p1, from_player, execute_on_turn, cmd, sequence, payload, payload_len, p3, p4);
    }

    return 1;
}

long TCommunications_Handler::CommOut(uchar p1, void* p2, long p3, ulong p4) {
    // Source of truth: com_hand.cpp.decomp @ 0x0042B270
    if (this->Multiplayer == 0) {
        return 0;
    }

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return 0;
    }

    if (this->GTDSerialNo == 0) {
        (void)dp->Release();
        return 0;
    }

    const ulong execute_on_turn = this->current_turn + (ulong)this->PlayerOptions.CommandTurnIncrement;

    uint header_len = (this->RGE_Guaranteed_Delivery != 0) ? 0x0C : 8;
    uint full_len = header_len + (uint)p3;
    if (full_len == 0 || full_len > 4000) {
        (void)dp->Release();
        return DPERR_INVALIDPARAM;
    }

    struct HeaderGTD {
        uchar Command;
        uchar Sequence;
        ushort _pad;
        ulong ExecuteOnTurn;
        uint Serialno;
    } hdr;
    memset(&hdr, 0, sizeof(hdr));
    hdr.Command = p1;
    hdr.ExecuteOnTurn = execute_on_turn;
    if (this->RGE_Guaranteed_Delivery != 0) {
        hdr.Serialno = this->GTDSerialNo;
        this->PlayerHighSerialNumber[this->Me] = this->GTDSerialNo;
        this->GTDSerialNo += 1;
    }

    hdr.Sequence = comm_get_next_sequence(execute_on_turn, this->PlayerOptions.ProgramState);
    if (hdr.Sequence == 0 && this->PlayerOptions.ProgramState != kCommStateRunning) {
        (void)dp->Release();
        return -0x7788fef2;
    }

    char* out = (char*)::operator new(full_len, std::nothrow);
    if (out == nullptr) {
        (void)dp->Release();
        return DPERR_OUTOFMEMORY;
    }

    memcpy(out, &hdr, header_len);
    if (p3 != 0 && p2 != nullptr) {
        memcpy(out + header_len, p2, (size_t)p3);
    }

    ulong from_dpid = s_localPlayerDpid;
    if (from_dpid == 0 && this->Me != 0 && this->Me <= (uint)this->MaxGamePlayers) {
        from_dpid = this->PlayerOptions.dcoID[this->Me];
        if (from_dpid != 0) {
            s_localPlayerDpid = from_dpid;
        }
    }

    if (from_dpid == 0) {
        ::operator delete(out);
        (void)dp->Release();
        if (this->RGE_Guaranteed_Delivery != 0) {
            this->GTDSerialNo -= 1;
        }
        return DPERR_INVALIDPLAYER;
    }

    // Build dest map for resend bookkeeping.
    memset(this->DestMap, 0, sizeof(this->DestMap));
    int outgoing_count = 0;
    for (uint p = 0; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        if (this->IsPlayerHuman(p) != 0 && p != this->Me) {
            this->DestMap[p] = 0xF0;
            outgoing_count += 1;
        }
    }

    const int recipient_count = (p4 == 0) ? outgoing_count : 1;
    HRESULT hr = 0;
    bool did_send = false;
    if (outgoing_count != 0) {
        hr = dp->Send((DPID)from_dpid, (DPID)p4, 0, out, (DWORD)full_len);
        did_send = true;
    }

    if (hr == 0) {
        this->TXPackets += 1;
        if (did_send) {
            this->TXPacketLength += (ulong)(recipient_count * (int)full_len);
        }

        if (did_send && this->RGE_Guaranteed_Delivery != 0) {
            // Store a copy for resend.
            unsigned char* resend = (unsigned char*)this->Resend;
            if (resend != nullptr) {
                for (uint offset = 0; offset <= 0x6D98; offset += 0x38) {
                    ulong* slot = (ulong*)(resend + offset);
                    if (slot[1] != 0) {
                        continue;
                    }

                    char* copy = (char*)::operator new(full_len, std::nothrow);
                    if (copy == nullptr) {
                        break;
                    }
                    memcpy(copy, out, full_len);

                    slot[0] = GetTickCount();       // TimeSent
                    slot[1] = (ulong)hdr.Serialno;  // Serial
                    slot[2] = (ulong)copy;          // ResendMsg
                    slot[3] = (ulong)full_len;      // Length

                    ulong* dest_map = (ulong*)(resend + offset + 0x10);
                    for (uint i = 0; i < 10; ++i) {
                        dest_map[i] = this->DestMap[i];
                    }
                    break;
                }
            }
        }

        if (p1 == (uchar)'>') {
            // Local echo for commands, matching original behavior.
            this->AddCommand(execute_on_turn, p2, (ulong)p3, (int)this->Me, hdr.Sequence, 0);
        }
    } else {
        if (this->RGE_Guaranteed_Delivery != 0) {
            this->GTDSerialNo -= 1;
        }
    }

    ::operator delete(out);
    (void)dp->Release();
    return (long)hr;
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

COMMSTATUS TCommunications_Handler::GetCommunicationsStatus() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042BAD0
    COMMSTATUS st = this->AnalyzeCommunicationsStatus();
    this->CommunicationsStatus = st;
    return st;
}

COMMSTATUS TCommunications_Handler::AnalyzeCommunicationsStatus() {
    // Source of truth: com_hand.cpp.asm @ 0x0042C690
    if (this->IsPaused() != 0 && this->current_turn >= 6) {
        return GAME_IS_PAUSED;
    }

    if (this->PlayerOptions.ProgramState == kCommStateRunning) {
        if (this->current_turn >= 6) {
            return GAME_IS_RUNNING;
        }
        if (this->current_turn < 6) {
            return GAME_IS_LOADING;
        }
    }

    if (this->PlayerOptions.NeedsToBeSent != 0) {
        return GAME_OPTIONS_EXCHANGED;
    }
    if (s_localPlayerDpid != 0) {
        return PLAYER_CREATED;
    }
    if (this->MeHost != 0) {
        return SESSION_HOSTED;
    }
    if (memcmp(&this->SessionGUID, &this->NullGUID, sizeof(this->NullGUID)) != 0) {
        return SESSION_AVAILABLE;
    }
    if (memcmp(&this->ServiceGUID, &this->NullGUID, sizeof(this->NullGUID)) != 0) {
        return SERVICE_AVAILABLE;
    }
    if (this->Lobby != nullptr && this->Lobby->glpDP != nullptr) {
        return CONVERSATION_OPEN;
    }

    if (this->Multiplayer == 0) {
        return (this->Me == 1) ? SINGLE_PLAYER : INITIALIZED;
    }
    return MULTIPLAYER_RESET;
}

void TCommunications_Handler::ReleaseSettings() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428810
    this->PlayerOptions.NeedsToBeSent = 0;
}

void TCommunications_Handler::FreeOptions() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EC10
    char* options = this->OptionsData;
    if (options != nullptr) {
        this->PlayerOptions.DataSizeToFollow = 0;
        ::operator delete(options);
        this->OptionsData = nullptr;
    }
}

long TCommunications_Handler::ReleaseComm() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042E9B0
    if (this->Lobby != nullptr && this->Lobby->glpDP != nullptr) {
        (void)this->Lobby->glpDP->Release();
        this->Lobby->glpDP = nullptr;
        this->ServiceGUID = this->NullGUID;
    }
    return 0;
}

long TCommunications_Handler::CloseSession() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042E920
    long hr = 0;
    if (this->Lobby != nullptr && this->Lobby->glpDP != nullptr) {
        hr = (long)this->Lobby->glpDP->Close();
    }

    this->SessionGUID = this->NullGUID;

    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        this->LastTurnAck[p] = 0;
    }
    return hr;
}

long TCommunications_Handler::DestroyMyPlayer() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042EB10
    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return 0;
    }

    if (s_localPlayerDpid == 0) {
        (void)dp->Release();
        return 0;
    }

    long hr = (long)dp->DestroyPlayer((DPID)s_localPlayerDpid);
    if (hr == 0) {
        s_localPlayerDpid = 0;
        this->Me = 0;
    }

    (void)dp->Release();
    return hr;
}

int TCommunications_Handler::Kick(uint player_number) {
    // Source of truth: com_hand.cpp.decomp @ 0x0042EA10
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers)) {
        return 0;
    }
    if (this->Lobby == nullptr || this->Lobby->glpDP == nullptr) {
        return 0;
    }

    if (this->IsPlayerHuman(player_number) == 0) {
        return 0;
    }

    const ulong victim_dpid = this->PlayerOptions.dcoID[player_number];
    if (victim_dpid == 0) {
        return 0;
    }

    struct KillPlayerMsg {
        uint PlayerNo;
        ulong dcoID;
        ulong CurrentTurn;
    } kp;
    kp.PlayerNo = player_number;
    kp.dcoID = victim_dpid;
    kp.CurrentTurn = this->current_turn;

    (void)this->CommOut((uchar)'K', &kp, 0x0C, 0);

    if (this->PlayerStopTurn[player_number] == 0) {
        this->DropDeadPlayer(player_number, victim_dpid);
    }

    this->NotifyWindow(kCommMessageUpdatePlayers);
    if (this->MeHost != 0 && this->current_turn < 7) {
        (void)this->SendSharedData(1);
    }
    return 1;
}

void TCommunications_Handler::DropAllHostedPlayers() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042C800
    if (this->MeHost != 0 && this->current_turn < 7) {
        for (uint player = 1; player <= (uint)this->MaxGamePlayers && player < 10; ++player) {
            (void)this->Kick(player);
        }
    }
}

COMMSTATUS TCommunications_Handler::UnlinkCurrentLevel() {
    // Source of truth: com_hand.cpp.decomp @ 0x0042BAE0
    switch (this->CommunicationsStatus) {
    case UNINITIALIZED:
    case INITIALIZED:
        break;

    case SINGLE_PLAYER:
    case MULTIPLAYER_RESET: {
        this->Multiplayer = 0;
        this->RXPacketLength = 0;
        this->RXPacketLengthHigh = 0;
        this->TXPacketLength = 0;
        this->TXPacketLengthHigh = 0;
        this->lastRXDataRate = 0.0f;
        this->lastTXDataRate = 0.0f;
        this->HoldCount = 0;
        this->ServiceTimeout = 0;
        this->TXPackets = 0;
        this->RXPackets = 0;
        this->RGE_Guaranteed_Delivery = 0;
        this->ResendAcknowledgements = 0;
        this->ResentToOther = 0;
        this->DroppedPacketCount = 0;
        this->LobbyLaunched = 0;
        this->GTDSerialNo = 0;
        this->dwStopTime = 0;
        this->OutOfSyncFlag = 0;
        this->AvgTurnTime = 0;
        this->PauseChangePending = 0;
        this->StepMode = 0;
        this->IntentionallyDropPackets = 0;
        this->PlayerOptions.LastSentTime = GetTickCount();

        this->MyGameTitle[0] = '\0';
        this->MyFriendlyName[0] = '\0';
        this->MyFormalName[0] = '\0';

        this->TickStart = 0;
        this->TickCount = 0;
        this->LastTimeoutMessageTime = 0;

        this->PlayerOptions.LowPlayerNumber = 1;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.GameHasStarted = 0;
        this->PlayerOptions.ProgramState = kCommStateJoinNow;
        this->MeHost = 0;
        this->HaveHostInit = 0;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->PlayerOptions.NeedsToBeSent = 0;
        this->AcknowledgeAfterMsec = 0x32;
        this->Me = 0;
        s_localPlayerDpid = 0;
        this->turnstart = 0;
        this->mselapsed = 0;

        for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
            this->InitPlayerInformation(p, 0, (char*)"", (char*)"");
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;

        this->ClearAllSerialNumbers();
        this->ClearRXandTX();

        for (uint p = 1; p < 10; ++p) {
            this->PlayerStopTurn[p] = 0;
        }

        this->Steps = 1;
        this->ResetLastCommunicationTimes();
        this->WaitingForAck = 0;

        if (this->InQ != nullptr) {
            this->InQ->FlushAll();
        }
        if (this->OutQ != nullptr) {
            this->OutQ->FlushAll();
        }

        this->ShuttingDown = 0;
        for (uint p = 0; p < 10; ++p) {
            this->Kicked[p] = 0;
            this->WasKicked[p] = 0;
        }

        this->Me = 1;
        this->PlayerOptions.Humanity[1] = kPlayerHumanityHuman;
        break;
    }

    case CONVERSATION_OPEN:
        this->TXPackets = 0;
        this->RXPackets = 0;
        this->RGE_Guaranteed_Delivery = 1;
        this->ResendAcknowledgements = 0;
        this->ResentToOther = 0;
        this->DroppedPacketCount = 0;
        this->LobbyLaunched = 0;
        this->ShuttingDown = 0;
        (void)this->ReleaseComm();
        break;

    case SERVICE_AVAILABLE:
        (void)this->ReleaseComm();
        for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
            this->InitPlayerInformation(p, 0, (char*)"", (char*)"");
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        if (this->Chat != nullptr) {
            this->Chat->ClearChat();
        }
        this->MyGameTitle[0] = '\0';
        this->Me = 0;
        s_localPlayerDpid = 0;
        this->ShuttingDown = 0;
        break;

    case SESSION_AVAILABLE: {
        this->ClearRXandTX();
        this->DropAllHostedPlayers();
        if (this->Chat != nullptr) {
            this->Chat->ClearChat();
        }
        (void)this->CloseSession();
        this->GTDSerialNo = 0;

        for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
            this->InitPlayerInformation(p, 0, (char*)"", (char*)"");
        }

        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.ProgramState = kCommStateJoinNow;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->Me = 0;
        s_localPlayerDpid = 0;
        this->ClearAllSerialNumbers();
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;

        if (this->Speed != nullptr) {
            free(this->Speed);
        }
        this->Speed = (RGE_Communications_Speed*)calloc(1, sizeof(RGE_Communications_Speed));
        if (this->Speed != nullptr) {
            this->Speed->Comm = this;
        }

        if (this->Sync != nullptr) {
            free(this->Sync);
        }
        this->Sync = (RGE_Communications_Synchronize*)calloc(1, sizeof(RGE_Communications_Synchronize));
        if (this->Sync != nullptr) {
            this->Sync->Comm = this;
        }

        this->SessionGUID = this->NullGUID;
        break;
    }

    case SESSION_HOSTED: {
        this->MeHost = 0;
        this->PlayerOptions.HostPlayerNumber = 0;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.ProgramState = kCommStateJoinNow;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->HaveHostInit = 0;
        (void)this->CloseSession();

        for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
            this->InitPlayerInformation(p, 0, (char*)"", (char*)"");
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        if (this->Chat != nullptr) {
            this->Chat->ClearChat();
        }
        s_localPlayerDpid = 0;
        this->Me = 0;
        this->current_turn = (ulong)this->PlayerOptions.CommandTurnIncrement + 2;
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;

        if (this->Speed != nullptr) {
            free(this->Speed);
        }
        this->Speed = (RGE_Communications_Speed*)calloc(1, sizeof(RGE_Communications_Speed));
        if (this->Speed != nullptr) {
            this->Speed->Comm = this;
        }

        if (this->Sync != nullptr) {
            free(this->Sync);
        }
        this->Sync = (RGE_Communications_Synchronize*)calloc(1, sizeof(RGE_Communications_Synchronize));
        if (this->Sync != nullptr) {
            this->Sync->Comm = this;
        }
        break;
    }

    case PLAYER_CREATED:
        (void)this->DestroyMyPlayer();
        this->Me = 0;
        s_localPlayerDpid = 0;
        if (this->InQ != nullptr) {
            this->InQ->FlushAll();
        }
        this->ShuttingDown = 0;
        break;

    case COMM_SETTINGS_EXCHANGED:
        this->ReleaseSettings();
        this->ResetLastCommunicationTimes();
        this->ShuttingDown = 0;
        break;

    case GAME_PLAYER_SET:
        this->Me = 0;
        s_localPlayerDpid = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_OPTIONS_EXCHANGED:
        this->FreeOptions();
        this->PlayerOptions.NeedsToBeSent = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_IS_LOADING:
        this->PlayerOptions.ProgramState = kCommStateJoinNow;
        this->ShuttingDown = 0;
        break;

    case GAME_IS_RUNNING:
        if (this->Chat != nullptr) {
            this->Chat->ClearChat();
        }
        this->LastTimeoutMessageTime = 0;
        if (this->InQ != nullptr) {
            this->InQ->FlushAll();
        }
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_IS_PAUSED:
    default:
        break;
    }

    return this->AnalyzeCommunicationsStatus();
}

COMMSTATUS TCommunications_Handler::UnlinkToLevel(COMMSTATUS level) {
    // Source of truth: com_hand.cpp.decomp @ 0x0042C5D0
    COMMSTATUS current = this->AnalyzeCommunicationsStatus();
    this->CommunicationsStatus = current;

    if ((int)level < 1) {
        level = INITIALIZED;
    }

    const COMMSTATUS initial = current;
    while ((int)current > (int)level) {
        COMMSTATUS next = this->UnlinkCurrentLevel();
        this->CommunicationsStatus = next;

        // Stuck guard: original ASM stops if UnlinkCurrentLevel returns the starting level again.
        if (next == initial) {
            break;
        }

        current = next;
    }

    return this->AnalyzeCommunicationsStatus();
}

IDirectPlay3* TCommunications_Handler::GetDPInterface() {
    // Source of truth: com_hand.cpp.asm GetDPInterface @ 0x0042DED0
    IDirectPlay2* dp2 = comm_get_dplay(this);
    if (dp2 == nullptr) {
        return nullptr;
    }

    IDirectPlay3* dp3 = nullptr;
    const HRESULT hr = dp2->QueryInterface(IID_IDirectPlay3A, (LPVOID*)&dp3);
    (void)dp2->Release();

    if (FAILED(hr)) {
        return nullptr;
    }
    return dp3;
}

void TCommunications_Handler::SendSpeedChange(uint buffer_frames, uint buffer_granularity) {
    // Source of truth: com_hand.cpp.decomp @ 0x00429A30
    if (this->MeHost != 0 && this->Multiplayer != 0) {
        const uint packed = ((buffer_granularity & 0xFFFF) << 16) | (buffer_frames & 0xFFFF);
        (void)this->CommOut('S', (void*)&packed, 4, 0);
    }
}

int TCommunications_Handler::AllPlayersAcknowledged() {
    // Source of truth: com_hand.cpp.decomp @ 0x00429C40
    if (this->Multiplayer == 0) {
        return 0;
    }
    if (this->ShuttingDown != 0) {
        return 0;
    }
    if (this->PlayerOptions.ProgramState == kCommStatePause) {
        return 0;
    }

    uint low = (uint)this->PlayerOptions.LowPlayerNumber;
    uint high = (uint)this->PlayerOptions.HighPlayerNumber;
    if (low < 1) low = 1;
    if (high > (uint)this->MaxGamePlayers) high = (uint)this->MaxGamePlayers;
    if (high > 9) high = 9;

    for (uint p = low; p <= high; ++p) {
        if (this->IsPlayerHuman(p) != 0) {
            if (this->LastTurnAck[p] < this->current_turn) {
                return 0;
            }
        }
    }
    return 1;
}

long TCommunications_Handler::SendChecksumMessage(ulong world_time, uint random, long cs2, long cs3, long cs4, long cs5,
                                                 long ping_initiated) {
    // Source of truth: com_hand.cpp.asm SendChecksumMessage @ 0x00429CE0
    struct MSGFORMAT_CHECKSUM {
        ulong WorldTurn;
        ulong Random;
        long cs2;
        long cs3;
        long cs4;
        long cs5;
        long PingInitiated;
        long cs1;
        ulong Timestamp;
    } cs;

    memset(&cs, 0, sizeof(cs));
    cs.WorldTurn = world_time;
    cs.Random = this->current_turn;
    cs.cs2 = cs2;
    cs.cs3 = cs3;
    cs.cs4 = cs4;
    cs.cs5 = cs5;
    cs.PingInitiated = ping_initiated;
    cs.cs1 = (long)random;
    cs.Timestamp = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0xBC0);

    const long hr = this->CommOut('M', &cs, 0x24, 0);
    return hr;
}
