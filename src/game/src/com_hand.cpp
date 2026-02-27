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




// BEGIN Task 222 decomp gap implementations
// Enumerated missing wrappers from com_hand.cpp.decomp; transliteration pass in progress.
// TODO: STUB: RESENDER/HOLDER constructor wrappers (0x00426450, 0x004264A0, 0x004265E0, 0x00426600) are tracked for follow-up.

char* TCommunications_Handler::WaitingOnNamedInfo(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425780
    char* wait_info = this->WaitingOnInfo(param_2);
    char* player_name = this->GetPlayerName(param_2);
    ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0x8E);
    int quiet_msec = (int)(now - this->LastPlayerCommunication[param_2]);
    sprintf(this->TBuff, "%d %s : %s QUIET %d msec T# %lu", param_2, player_name, wait_info, quiet_msec,
            this->LastTurnAck[param_2]);
    return this->TBuff;
}

char* TCommunications_Handler::WaitingOnInfo(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425800
    if (this->IsPlayerComputer(param_2) != 0) {
        return (char*)"Computer";
    }
    if (this->IsPlayerHuman(param_2) == 0) {
        return (char*)"Empty";
    }
    if (this->LastTurnAck[param_2] < 4) {
        return (char*)"Loading";
    }
    if (this->LastTurnAck[param_2] < this->current_turn) {
        return (char*)"Waiting";
    }
    return (char*)"Ready";
}

void TCommunications_Handler::StopIfSyncFail(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004258E0
    if (this->Sync == nullptr) {
        return;
    }
    this->Sync->SetDialogOnFail(param_2);
    this->Sync->SetStopOnFail(param_2);
}

void TCommunications_Handler::ShowSyncChatMsgs(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425910
    if (this->Sync != nullptr) {
        this->Sync->SendChatMsgsAtChecksum(param_2);
    }
}

void TCommunications_Handler::DropPacketsIntentionally(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425930
    this->IntentionallyDropPackets = param_2;
}

void TCommunications_Handler::SetStepMode(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425960
    this->StepMode = param_2;
}

void TCommunications_Handler::SetSpeedControl(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425970
    if (this->Speed != nullptr) {
        this->Speed->EnableSpeedControl(param_2);
    }
}

void TCommunications_Handler::Step(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425A20
    this->Steps += param_2;
}

void TCommunications_Handler::KillAnyMissingPlayers(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x00426350
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x00426350
    // void KillAnyMissingPlayers(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: dwSize */
    //     // /* protected: void __thiscall TCommunications_Handler::KillAnyMissingPlayers(void) */
    //     // 
    //     // void __thiscall TCommunications_Handler::KillAnyMissingPlayers(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   int iVar1;
    //     //   void *pvVar2;
    //     //   uint unaff_EBP;
    //     //   ulong *puVar3;
    //     //   uint uVar4;
    //     //   ulong dwSize;
    //     //   long hr;
    //     //   MSGFORMAT_KILL_PLAYER kp;
    //     //   
    //     //   uVar4 = 1;
    //     //   if (this->MaxGamePlayers != 0) {
    //     //     puVar3 = (this->PlayerOptions).dcoID;
    //     //     do {
    //     //       puVar3 = puVar3 + 1;
    //     //       iVar1 = IsPlayerHuman(this,uVar4);
    //     //       if (iVar1 != 0) {
    //     //         hr = 0;
    //     //         (**(code **)(*DAT_0062c5ec + 0x54))(DAT_0062c5ec,*puVar3,0,&hr);
    //     //         pvVar2 = operator_new(unaff_EBP);
    //     //         kp.PlayerNo = (**(code **)(*DAT_0062c5ec + 0x54))
    //     //                                 (DAT_0062c5ec,*puVar3,pvVar2,&stack0xffffffdc);
    //     //         operator_delete(pvVar2);
    //     //         if (kp.PlayerNo != 0) {
    //     //           kp.CurrentTurn = *puVar3;
    //     //           kp.dcoID = uVar4;
    //     //           TDebuggingLog::Log((TDebuggingLog *)this->current_turn,(char *)L,s___>TX_KP___d___d_,uVar4
    //     //                              ,0xc);
    //     //           CommOut(this,0,'K',&kp.dcoID,0xc,'\0');
    //     //           if (puVar3[-0x6a] == 0) {
    //     //             DropDeadPlayer(this,uVar4,*puVar3);
    //     //           }
    //     //         }
    //     //       }
    //     //       uVar4 = uVar4 + 1;
    //     //     } while (uVar4 <= this->MaxGamePlayers);
    //     //   }
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

int TCommunications_Handler::HasKicked(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426D40
    if (param_2 >= 10) {
        return 0;
    }
    return this->Kicked[param_2];
}

long TCommunications_Handler::SendPlayerName(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x00426D50
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x00426D50
    // long SendPlayerName(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: dpnSetName */
    //     // /* protected: long __thiscall TCommunications_Handler::SendPlayerName(void) */
    //     // 
    //     // long __thiscall TCommunications_Handler::SendPlayerName(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   long lVar1;
    //     //   DPNAME dpnSetName;
    //     //   
    //     //   dpnSetName.field2_0x8.lpszShortName = (ushort *)0x0;
    //     //   dpnSetName.field3_0xc.lpszLongName = (ushort *)this->MyFriendlyName;
    //     //   dpnSetName.dwFlags = 0x10;
    //     //   lVar1 = (**(code **)(*DAT_0062c5ec + 0x78))(DAT_0062c5ec,DAT_0062cf04,&dpnSetName.dwFlags,2);
    //     //   RGE_Comm_Error::ShowReturn(this->Err,lVar1,s_Send_Player_Name);
    //     //   return lVar1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

void TCommunications_Handler::LogRXMsg(uint param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x00426DC0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x00426DC0
    // void LogRXMsg(TCommunications_Handler* this_, uint param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* protected: void __thiscall TCommunications_Handler::LogRXMsg(unsigned int,unsigned int,unsigned
    //     //    long,unsigned char,unsigned char) */
    //     // 
    //     // void __thiscall
    //     // TCommunications_Handler::LogRXMsg
    //     //           (TCommunications_Handler *this,uint param_1,uint param_2,ulong param_3,uchar param_4,
    //     //           uchar param_5)
    //     // 
    //     // {
    //     //   if (this->RGE_Guaranteed_Delivery != '\0') {
    //     //     TDebuggingLog::Log(L,(char *)L,s_GTD__RX_Ser__d_From_P__d_T__ld_T,param_1,param_2,
    //     //                        this->current_turn,param_3,param_4,param_4,param_5);
    //     //   }
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

int TCommunications_Handler::TXPing(uint param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x00427390
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x00427390
    // int TXPing(TCommunications_Handler* this_, uint param_2) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* protected: int __thiscall TCommunications_Handler::TXPing(unsigned int) */
    //     // 
    //     // int __thiscall TCommunications_Handler::TXPing(TCommunications_Handler *this,uint param_1)
    //     // 
    //     // {
    //     //   ulong uVar1;
    //     //   long lVar2;
    //     //   TDebuggingLog *pTVar3;
    //     //   ulong *puVar4;
    //     //   
    //     //   uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x470);
    //     //   UNK_0062cef4._4_1_ = 0x31;
    //     //   pTVar3 = (TDebuggingLog *)this->current_turn;
    //     //   UNK_0062cef4._8_4_ = uVar1;
    //     //   UNK_0062cef4._12_4_ = pTVar3;
    //     //   if (param_1 == 0) {
    //     //     pTVar3 = (TDebuggingLog *)0x1;
    //     //     if (this->MaxGamePlayers != 0) {
    //     //       puVar4 = this->LastTXPing;
    //     //       do {
    //     //         puVar4 = puVar4 + 1;
    //     //         *puVar4 = uVar1;
    //     //         pTVar3 = (TDebuggingLog *)((int)&pTVar3->Timestamp + 1);
    //     //       } while (pTVar3 <= (TDebuggingLog *)(uint)this->MaxGamePlayers);
    //     //     }
    //     //     uVar1 = 0;
    //     //   }
    //     //   else {
    //     //     this->LastTXPing[param_1] = uVar1;
    //     //     uVar1 = (this->PlayerOptions).dcoID[param_1];
    //     //   }
    //     //   TDebuggingLog::Log(pTVar3,(char *)L,s___>TX_PING___d___d_,param_1,0xc);
    //     //   lVar2 = FastSend(this,uVar1,&UNK_0062cef4.field_0x4,0xc,0,0);
    //     //   return (uint)(lVar2 == 0);
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::TXDebugPing(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x00427440
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x00427440
    // int TXDebugPing(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: int __thiscall TCommunications_Handler::TXDebugPing(void) */
    //     // 
    //     // int __thiscall TCommunications_Handler::TXDebugPing(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   long lVar1;
    //     //   
    //     //   UNK_0062c5d1._7_1_ = 0x33;
    //     //   UNK_0062c5d1._11_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x496);
    //     //   UNK_0062c5d1._15_4_ = this->current_turn;
    //     //   TDebuggingLog::Log(L,(char *)L,s___>TX_DEBUG_PING___d___d_,0,0xc);
    //     //   lVar1 = FastSend(this,0,&UNK_0062c5d1.field_0x7,0xc,0,0);
    //     //   return (uint)(lVar1 == 0);
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

long TCommunications_Handler::FastSend(ulong param_2, void* param_3, ulong param_4, int param_5, int param_6) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x004274B0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x004274B0
    // long FastSend(TCommunications_Handler* this_, ulong param_2, void* param_3, ulong param_4, int param_5, int param_6) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: long __thiscall TCommunications_Handler::FastSend(unsigned long,void *,unsigned
    //     //    long,int,int) */
    //     // 
    //     // long __thiscall
    //     // TCommunications_Handler::FastSend
    //     //           (TCommunications_Handler *this,ulong param_1,void *param_2,ulong param_3,int param_4,
    //     //           int param_5)
    //     // 
    //     // {
    //     //   ulong uVar1;
    //     //   int iVar2;
    //     //   ulong uVar3;
    //     //   int iVar4;
    //     //   TDebuggingLog *this_00;
    //     //   int iVar5;
    //     //   int unaff_ESI;
    //     //   uint uVar6;
    //     //   
    //     //   if (param_1 == DAT_0062cf04) {
    //     //     TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_No_send_to_self_FastTX);
    //     //     return -0x7fffbffb;
    //     //   }
    //     //   if (DAT_0062cf04 != 0) {
    //     //     uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x4ca);
    //     //     iVar2 = (**(code **)(*DAT_0062c5ec + 0x68))(DAT_0062c5ec,DAT_0062cf04,param_1,0,param_2,param_3)
    //     //     ;
    //     //     uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x4d3);
    //     //     if (0x32 < uVar3 - uVar1) {
    //     //       TDebuggingLog::Log(this_00,(char *)L,s____FastSend_slow____ld_msec,uVar3 - uVar1);
    //     //     }
    //     //     if (param_1 == 0) {
    //     //       uVar6 = 1;
    //     //       iVar5 = 0;
    //     //       if (this->MaxGamePlayers != 0) {
    //     //         do {
    //     //           iVar4 = IsPlayerHuman(this,uVar6);
    //     //           if ((iVar4 != 0) && (uVar6 != this->Me)) {
    //     //             iVar5 = iVar5 + 1;
    //     //           }
    //     //           uVar6 = uVar6 + 1;
    //     //         } while (uVar6 <= this->MaxGamePlayers);
    //     //       }
    //     //     }
    //     //     else {
    //     //       iVar5 = 1;
    //     //     }
    //     //     this->TXPacketLength = this->TXPacketLength + iVar5 * unaff_ESI;
    //     //     if (iVar2 != -0x7ff8ffa9) {
    //     //       if (iVar2 != 0) {
    //     //         RGE_Comm_Error::ShowReturn(this->Err,iVar2,s_FastTX);
    //     //       }
    //     //       return iVar2;
    //     //     }
    //     //     TDebuggingLog::Log(L,(char *)L,s_FastTX_to_invalidparams_ignored);
    //     //     return -0x7ff8ffa9;
    //     //   }
    //     //   TDebuggingLog::Log(L,(char *)L,s____BAD_DCOID_0_NO_TX);
    //     //   return -0x7fffbffb;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::EvaluatePlayerMessage(ulong param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6, char* param_7, uint param_8, ulong param_9, ulong param_10) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x004282C0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x004282C0
    // int EvaluatePlayerMessage(TCommunications_Handler* this_, ulong param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6, char* param_7, uint param_8, ulong param_9, ulong param_10) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* protected: int __thiscall TCommunications_Handler::EvaluatePlayerMessage(unsigned long,unsigned
    //     //    int,unsigned long,unsigned char,unsigned char,char *,unsigned int,unsigned long,unsigned long) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::EvaluatePlayerMessage
    //     //           (TCommunications_Handler *this,ulong param_1,uint param_2,ulong param_3,uchar param_4,
    //     //           uchar param_5,char *param_6,uint param_7,ulong param_8,ulong param_9)
    //     // 
    //     // {
    //     //   TDebuggingLog *pTVar1;
    //     //   ulong uVar2;
    //     //   uint uVar3;
    //     //   ulong *puVar4;
    //     //   uint uVar5;
    //     //   
    //     //   if (this->Multiplayer == 0) {
    //     //     return 0;
    //     //   }
    //     //   uVar3 = (uint)param_4;
    //     //   pTVar1 = (TDebuggingLog *)(uVar3 - 0x2b);
    //     //   switch(uVar3) {
    //     //   case 0x2b:
    //     //     if (this->MeHost != 0) {
    //     //       SendPauseGame(this,0);
    //     //       TDebuggingLog::Log(L,(char *)L,s_Non_host_requested_resume);
    //     //       LocalResumeGame(this,param_2);
    //     //       return 1;
    //     //     }
    //     //     break;
    //     //   default:
    //     //     TDebuggingLog::Log(pTVar1,(char *)L,s_Unknown_message____d___c_,uVar3,uVar3);
    //     //     break;
    //     //   case 0x3e:
    //     //     AddCommand(this,param_3,param_6,param_1,param_2,param_5,0);
    //     //     return 1;
    //     //   case 0x43:
    //     //     TDebuggingLog::Log((TDebuggingLog *)param_2,(char *)L,s_CHAT_RX_from_P__d__d__RXID__d_Ch,param_2
    //     //                        ,param_8,param_9,param_6 + 0x11,*(undefined4 *)(param_6 + 0xc),param_7,
    //     //                        (uint)(byte)param_6[0x10]);
    //     //     if ((param_6[this->Me + 1] == 'Y') || ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW)
    //     //        ) {
    //     //       TChat::AddChatMsg(this->Chat,this->FriendlyName[(byte)*param_6].Text,param_6 + 0x11,'\0');
    //     //       return 1;
    //     //     }
    //     //     break;
    //     //   case 0x44:
    //     //     RGE_Communications_Speed::SetPlayerTurnSpeed(this->Speed,param_2,param_6[9],param_6[8]);
    //     //     if (((int)(this->PlayerOptions).ProgramState < 5) || (this->current_turn < 6)) {
    //     //       pTVar1 = (TDebuggingLog *)this->current_turn;
    //     //       if (*(TDebuggingLog **)(param_6 + 4) < pTVar1) {
    //     //         TDebuggingLog::Log(pTVar1,(char *)L,s____REGRESSION_WARNING__Current__,pTVar1,
    //     //                            *(TDebuggingLog **)(param_6 + 4));
    //     //         return 0;
    //     //       }
    //     //     }
    //     //     uVar3 = *(int *)(param_6 + 4) - (uint)(this->PlayerOptions).CommandTurnIncrement;
    //     //     if (uVar3 <= this->LastTurnAck[param_2]) {
    //     //       uVar3 = this->LastTurnAck[param_2];
    //     //     }
    //     //     this->LastTurnAck[param_2] = uVar3;
    //     //     return 1;
    //     //   case 0x4b:
    //     //     TDebuggingLog::Log(*(TDebuggingLog **)param_6,(char *)L,s_KILL_Message_recieved_from__d_to,
    //     //                        param_2,*(TDebuggingLog **)param_6);
    //     //     uVar2 = *(ulong *)(param_6 + 4);
    //     //     if (uVar2 != 0) {
    //     //       uVar3 = (uint)(this->PlayerOptions).LowPlayerNumber;
    //     //       uVar5 = (uint)(this->PlayerOptions).HighPlayerNumber;
    //     //       if (uVar3 <= uVar5) {
    //     //         puVar4 = (this->PlayerOptions).dcoID + uVar3;
    //     //         do {
    //     //           if (*puVar4 == uVar2) goto LAB_004285e0;
    //     //           uVar3 = uVar3 + 1;
    //     //           puVar4 = puVar4 + 1;
    //     //         } while ((int)uVar3 <= (int)uVar5);
    //     //       }
    //     //     }
    //     //     uVar3 = 0;
    //     // LAB_004285e0:
    //     //     if (uVar3 != 0) {
    //     //       if (this->PlayerStopTurn[uVar3] == 0) {
    //     //         DropDeadPlayer(this,uVar3,uVar2);
    //     //       }
    //     //       if (uVar3 == this->Me) {
    //     //         NotifyWindow(this,COMM_PLAYER_KICKED);
    //     //         return 1;
    //     //       }
    //     //       if (this->PlayerStopTurn[uVar3] == 0) {
    //     //         NotifyWindowParam(this,COMM_OTHER_PLAYER_DROPPED,uVar3);
    //     //         return 1;
    //     //       }
    //     //     }
    //     //     break;
    //     //   case 0x4d:
    //     //     RGE_Communications_Synchronize::Add
    //     //               (this->Sync,param_2,*(ulong *)param_6,*(ulong *)(param_6 + 4),*(ulong *)(param_6 + 8),
    //     //                *(long *)(param_6 + 0xc),*(long *)(param_6 + 0x10),*(long *)(param_6 + 0x14),
    //     //                *(long *)(param_6 + 0x18),*(long *)(param_6 + 0x1c));
    //     //     return 1;
    //     //   case 0x4e:
    //     //     if (this->MeHost == 0) {
    //     //       TDebuggingLog::Log(L,(char *)L,s_Host_requested_we_delete_and_rec);
    //     //       return 1;
    //     //     }
    //     //     break;
    //     //   case 0x50:
    //     //     TDebuggingLog::Log(pTVar1,(char *)L,s_P__d_Requested_pause);
    //     //     LocalPauseGame(this,param_2);
    //     //     RGE_Communications_Synchronize::LogChecksums(this->Sync,0,0,0,0,0,0,0,0,0);
    //     //     return 1;
    //     //   case 0x51:
    //     //     SetPlayerStopTurn(this,param_2,*(ulong *)param_6);
    //     //     return 1;
    //     //   case 0x53:
    //     //     RGE_Communications_Speed::SetFutureSpeedChange
    //     //               (this->Speed,(uint)*(ushort *)param_6,(uint)*(ushort *)(param_6 + 2),param_3);
    //     //     return 1;
    //     //   case 0x55:
    //     //     TDebuggingLog::Log(pTVar1,(char *)L,s_Resume_msg_rcvd);
    //     //     LocalResumeGame(this,param_2);
    //     //     return 1;
    //     //   case 0x57:
    //     //     if (this->MeHost != 0) {
    //     //       SendPauseGame(this,1);
    //     //       LocalPauseGame(this,param_2);
    //     //       return 1;
    //     //     }
    //     //   }
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

void TCommunications_Handler::SetPlayerStopTurn(uint param_2, ulong param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004286F0
    if (param_2 < 10) {
        this->PlayerStopTurn[param_2] = param_3;
    }
}

void TCommunications_Handler::CheckPlayerStopTurn(ulong param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x00428710
    (void)param_2;
}

int TCommunications_Handler::TEST(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x004289A0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x004289A0
    // int TEST(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* protected: int __thiscall TCommunications_Handler::TEST(void) */
    //     // 
    //     // int __thiscall TCommunications_Handler::TEST(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   TTaunt *pTVar1;
    //     //   int iVar2;
    //     //   undefined4 *unaff_FS_OFFSET;
    //     //   undefined4 local_c;
    //     //   code *pcStack_8;
    //     //   undefined4 local_4;
    //     //   
    //     //   local_4 = 0xffffffff;
    //     //   pcStack_8 = FUN_0055ccdb;
    //     //   local_c = *unaff_FS_OFFSET;
    //     //   *unaff_FS_OFFSET = &local_c;
    //     //   pTVar1 = (TTaunt *)operator_new(0x198);
    //     //   local_4 = 0;
    //     //   if (pTVar1 == (TTaunt *)0x0) {
    //     //     pTVar1 = (TTaunt *)0x0;
    //     //   }
    //     //   else {
    //     //     pTVar1 = (TTaunt *)TTaunt::TTaunt(pTVar1,sound_driver);
    //     //   }
    //     //   local_4 = 0xffffffff;
    //     //   iVar2 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x8f2);
    //     //   TDebuggingLog::Log(L,(char *)L,s_Playing_Taunt___d,(iVar2 * 0xf) / 0x7fff);
    //     //   TTaunt::PlayTauntNo(pTVar1,4);
    //     //   if (pTVar1 != (TTaunt *)0x0) {
    //     //     TTaunt::~TTaunt(pTVar1);
    //     //     operator_delete(pTVar1);
    //     //   }
    //     //   *unaff_FS_OFFSET = local_c;
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

ulong TCommunications_Handler::HiTurnAcknowledged(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x00429BD0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x00429BD0
    // ulong HiTurnAcknowledged(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: unsigned long __thiscall TCommunications_Handler::HiTurnAcknowledged(void) */
    //     // 
    //     // ulong __thiscall TCommunications_Handler::HiTurnAcknowledged(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   int iVar1;
    //     //   ulong *puVar2;
    //     //   uint uVar3;
    //     //   
    //     //   DAT_0062c5e8 = 0;
    //     //   uVar3 = (uint)(this->PlayerOptions).LowPlayerNumber;
    //     //   if (uVar3 <= (this->PlayerOptions).HighPlayerNumber) {
    //     //     puVar2 = this->LastTurnAck + uVar3;
    //     //     do {
    //     //       iVar1 = IsPlayerHuman(this,uVar3);
    //     //       if ((iVar1 != 0) && (DAT_0062c5e8 < *puVar2)) {
    //     //         DAT_0062c5e8 = *puVar2;
    //     //       }
    //     //       uVar3 = uVar3 + 1;
    //     //       puVar2 = puVar2 + 1;
    //     //     } while ((int)uVar3 <= (int)(uint)(this->PlayerOptions).HighPlayerNumber);
    //     //   }
    //     //   return DAT_0062c5e8;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

void TCommunications_Handler::ClearRXForPlayer(uint param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042A060
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042A060
    // void ClearRXForPlayer(TCommunications_Handler* this_, uint param_2) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* protected: void __thiscall TCommunications_Handler::ClearRXForPlayer(unsigned int) */
    //     // 
    //     // void __thiscall
    //     // TCommunications_Handler::ClearRXForPlayer(TCommunications_Handler *this,uint param_1)
    //     // 
    //     // {
    //     //   undefined4 *puVar1;
    //     //   uint uVar2;
    //     //   
    //     //   uVar2 = 0;
    //     //   do {
    //     //     puVar1 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar2);
    //     //     if (*(ulong *)((int)&this->OnHold->dcoFromID + uVar2) == (this->PlayerOptions).dcoID[param_1]) {
    //     //       if ((void *)*puVar1 != (void *)0x0) {
    //     //         operator_delete((void *)*puVar1);
    //     //       }
    //     //       *puVar1 = 0;
    //     //       puVar1[1] = 0;
    //     //       puVar1[2] = 0;
    //     //       puVar1[3] = 0;
    //     //       puVar1[4] = 0;
    //     //     }
    //     //     uVar2 = uVar2 + 0x18;
    //     //   } while (uVar2 < 0x2ef9);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

void TCommunications_Handler::ClearTXForPlayer(uint param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042A130
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042A130
    // void ClearTXForPlayer(TCommunications_Handler* this_, uint param_2) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* protected: void __thiscall TCommunications_Handler::ClearTXForPlayer(unsigned int) */
    //     // 
    //     // void __thiscall
    //     // TCommunications_Handler::ClearTXForPlayer(TCommunications_Handler *this,uint param_1)
    //     // 
    //     // {
    //     //   int iVar1;
    //     //   int iVar2;
    //     //   
    //     //   iVar2 = 0x1f6;
    //     //   iVar1 = param_1 * 4 + 0x10;
    //     //   do {
    //     //     iVar2 = iVar2 + -1;
    //     //     *(undefined4 *)((int)this->Resend->DestMap + iVar1 + -0x10) = 0;
    //     //     iVar1 = iVar1 + 0x38;
    //     //   } while (iVar2 != 0);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

void TCommunications_Handler::ClearRXTXForPlayer(uint param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042A160
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042A160
    // void ClearRXTXForPlayer(TCommunications_Handler* this_, uint param_2) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* protected: void __thiscall TCommunications_Handler::ClearRXTXForPlayer(unsigned int) */
    //     // 
    //     // void __thiscall
    //     // TCommunications_Handler::ClearRXTXForPlayer(TCommunications_Handler *this,uint param_1)
    //     // 
    //     // {
    //     //   ClearTXForPlayer(this,param_1);
    //     //   ClearRXForPlayer(this,param_1);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

int TCommunications_Handler::StoreIncoming(uint param_2, char* param_3, uint param_4, ulong param_5, ulong param_6) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A180
    comm_store_incoming(this, param_2, param_3, (ulong)param_4, param_5, param_6);
    return 1;
}

int TCommunications_Handler::StoreForResend(uint param_2, char* param_3, uint param_4, uint* param_5) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042A330
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042A330
    // int StoreForResend(TCommunications_Handler* this_, uint param_2, char* param_3, uint param_4, uint* param_5) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: int __thiscall TCommunications_Handler::StoreForResend(unsigned int,char *,unsigned
    //     //    int,unsigned int *) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::StoreForResend
    //     //           (TCommunications_Handler *this,uint param_1,char *param_2,uint param_3,uint *param_4)
    //     // 
    //     // {
    //     //   RESENDER *pRVar1;
    //     //   char *pcVar2;
    //     //   ulong uVar3;
    //     //   int iVar4;
    //     //   TDebuggingLog *this_00;
    //     //   uint uVar5;
    //     //   int iVar6;
    //     //   int iVar7;
    //     //   uint uVar8;
    //     //   uint *puVar9;
    //     //   uint *puVar10;
    //     //   
    //     //   if (this->Multiplayer != 0) {
    //     //     if (this->RGE_Guaranteed_Delivery == '\0') {
    //     //       TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_____RGEGTD_Store);
    //     //       return 0;
    //     //     }
    //     //     iVar7 = 0;
    //     //     uVar8 = 0;
    //     //     do {
    //     //       pRVar1 = this->Resend;
    //     //       iVar6 = *(int *)((int)pRVar1->DestMap + (uVar8 - 0xc));
    //     //       if (iVar6 == 0) {
    //     //         this->Resend[iVar7].Length = param_3;
    //     //         if (param_3 != 0) {
    //     //           pRVar1 = this->Resend;
    //     //           pcVar2 = (char *)operator_new(pRVar1[iVar7].Length);
    //     //           pRVar1[iVar7].ResendMsg = pcVar2;
    //     //           if (pcVar2 != (char *)0x0) {
    //     //             uVar8 = pRVar1[iVar7].Length;
    //     //             for (uVar5 = uVar8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    //     //               *(undefined4 *)pcVar2 = *(undefined4 *)param_2;
    //     //               param_2 = param_2 + 4;
    //     //               pcVar2 = pcVar2 + 4;
    //     //             }
    //     //             for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    //     //               *pcVar2 = *param_2;
    //     //               param_2 = param_2 + 1;
    //     //               pcVar2 = pcVar2 + 1;
    //     //             }
    //     //             pRVar1[iVar7].Length = param_3;
    //     //           }
    //     //         }
    //     //         this->Resend[iVar7].Serial = param_1;
    //     //         puVar9 = param_4;
    //     //         puVar10 = this->Resend[iVar7].DestMap;
    //     //         for (uVar8 = (uint)this->MaxGamePlayers * 4 + 4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    //     //           *puVar10 = *puVar9;
    //     //           puVar9 = puVar9 + 1;
    //     //           puVar10 = puVar10 + 1;
    //     //         }
    //     //         for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    //     //           *(char *)puVar10 = (char)*puVar9;
    //     //           puVar9 = (uint *)((int)puVar9 + 1);
    //     //           puVar10 = (uint *)((int)puVar10 + 1);
    //     //         }
    //     //         TDebuggingLog::Log((TDebuggingLog *)(uint)this->MaxGamePlayers,(char *)L,
    //     //                            s_Stored__db_for_resend__Slot___d_,param_3,iVar7,param_1,
    //     //                            (TDebuggingLog *)(uint)this->MaxGamePlayers);
    //     //         uVar8 = 1;
    //     //         if (this->MaxGamePlayers != 0) {
    //     //           iVar6 = iVar7 * 0x38 + 0x14;
    //     //           do {
    //     //             param_4 = param_4 + 1;
    //     //             if (*(int *)((int)this->Resend->DestMap + iVar6 + -0x10) != 0) {
    //     //               TDebuggingLog::Log((TDebuggingLog *)*param_4,(char *)L,s_______to__>_P__d__retries__d,
    //     //                                  uVar8,(TDebuggingLog *)*param_4);
    //     //             }
    //     //             uVar8 = uVar8 + 1;
    //     //             iVar6 = iVar6 + 4;
    //     //           } while (uVar8 <= this->MaxGamePlayers);
    //     //         }
    //     //         uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd12);
    //     //         this->Resend[iVar7].TimeSent = uVar3;
    //     //         return 1;
    //     //       }
    //     //       iVar4 = (int)**(char **)((int)pRVar1->DestMap + (uVar8 - 8));
    //     //       TDebuggingLog::Log(L,(char *)L,s_QUEUE_Has_Ser___d__Slot__d__Cmd_,iVar6,iVar7,iVar4,iVar4,
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + (uVar8 - 4)),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 4),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 8),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0xc),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x10),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x14),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x18),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x1c),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + uVar8 + 0x20));
    //     //       uVar8 = uVar8 + 0x38;
    //     //       iVar7 = iVar7 + 1;
    //     //     } while (uVar8 < 0x6d98);
    //     //     TDebuggingLog::Log(this_00,(char *)L,s_RESEND_buffer_filled_up__slots__,iVar7);
    //     //   }
    //     //   return 0;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::TXAcknowledgeMessage(uint param_2, uint param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A540
    comm_tx_ack(this, param_2, param_3);
    return 1;
}

int TCommunications_Handler::RXAcknowledgeStoredMessage(uint param_2, uint param_3) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042A650
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042A650
    // int RXAcknowledgeStoredMessage(TCommunications_Handler* this_, uint param_2, uint param_3) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: int __thiscall TCommunications_Handler::RXAcknowledgeStoredMessage(unsigned int,unsigned
    //     //    int) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::RXAcknowledgeStoredMessage
    //     //           (TCommunications_Handler *this,uint param_1,uint param_2)
    //     // 
    //     // {
    //     //   uint uVar1;
    //     //   uint uVar2;
    //     //   int iVar3;
    //     //   
    //     //   if (this->RGE_Guaranteed_Delivery == '\0') {
    //     //     TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s__RGEGTD_RxAck);
    //     //     return 0;
    //     //   }
    //     //   TDebuggingLog::Log(L,(char *)L,s_COMM__RX_ACK_from_P__d_for_Ser__,param_2,param_1);
    //     //   this->WaitingForAck = 0;
    //     //   uVar2 = 0;
    //     //   iVar3 = param_2 * 4 + 0x10;
    //     //   do {
    //     //     uVar1 = *(uint *)((int)this->Resend->DestMap + (uVar2 - 0xc));
    //     //     if ((uVar1 == param_1) && (uVar1 != 0)) {
    //     //       *(undefined4 *)((int)this->Resend->DestMap + iVar3 + -0x10) = 0;
    //     //     }
    //     //     uVar2 = uVar2 + 0x38;
    //     //     iVar3 = iVar3 + 0x38;
    //     //   } while (uVar2 < 0x6d99);
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::PurgeAcknowledgedStoredMessages(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042A6E0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042A6E0
    // int PurgeAcknowledgedStoredMessages(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: NonAckCount */
    //     // /* public: int __thiscall TCommunications_Handler::PurgeAcknowledgedStoredMessages(void) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::PurgeAcknowledgedStoredMessages(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   int iVar1;
    //     //   uint *puVar2;
    //     //   int iVar3;
    //     //   uint uVar4;
    //     //   undefined4 *puVar5;
    //     //   uint NonAckCount;
    //     //   uint i;
    //     //   int local_8;
    //     //   uint local_4;
    //     //   
    //     //   iVar3 = 0;
    //     //   local_8 = 0;
    //     //   local_4 = 4;
    //     //   do {
    //     //     i = 0;
    //     //     if (*(int *)((int)this->Resend->DestMap + iVar3 + -0xc) != 0) {
    //     //       uVar4 = 1;
    //     //       if (this->MaxGamePlayers != 0) {
    //     //         do {
    //     //           iVar1 = IsPlayerHuman(this,uVar4);
    //     //           if ((iVar1 != 0) && (this->Resend->DestMap[uVar4 + local_4 + -4] != 0)) {
    //     //             i = i + 1;
    //     //           }
    //     //           uVar4 = uVar4 + 1;
    //     //         } while (uVar4 <= this->MaxGamePlayers);
    //     //       }
    //     //       if (i == 0) {
    //     //         TDebuggingLog::Log(L,(char *)L,s_GTD__Ser___d_Slot__d__Ackd_by_al,
    //     //                            *(undefined4 *)((int)this->Resend->DestMap + iVar3 + -0xc),local_8);
    //     //         puVar5 = (undefined4 *)((int)this->Resend->DestMap + iVar3 + -0x10);
    //     //         *puVar5 = 0;
    //     //         if ((void *)puVar5[2] != (void *)0x0) {
    //     //           operator_delete((void *)puVar5[2]);
    //     //         }
    //     //         puVar5[2] = 0;
    //     //         puVar5[1] = 0;
    //     //         puVar5[3] = 0;
    //     //         puVar5 = puVar5 + 4;
    //     //         for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    //     //           *puVar5 = 0;
    //     //           puVar5 = puVar5 + 1;
    //     //         }
    //     //       }
    //     //     }
    //     //     local_4 = local_4 + 0xe;
    //     //     local_8 = local_8 + 1;
    //     //     iVar3 = iVar3 + 0x38;
    //     //   } while (local_4 < 0x1b6b);
    //     //   iVar3 = 0x1f6;
    //     //   puVar2 = &this->Resend->Serial;
    //     //   do {
    //     //     if (*puVar2 != 0) {
    //     //       this->WaitingForAck = this->WaitingForAck + 1;
    //     //     }
    //     //     puVar2 = puVar2 + 0xe;
    //     //     iVar3 = iVar3 + -1;
    //     //   } while (iVar3 != 0);
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::TXResendReply(uint param_2, uint param_3) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042AD10
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042AD10
    // int TXResendReply(TCommunications_Handler* this_, uint param_2, uint param_3) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: BadTransmitCount */
    //     // /* public: int __thiscall TCommunications_Handler::TXResendReply(unsigned int,unsigned int) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::TXResendReply(TCommunications_Handler *this,uint param_1,uint param_2)
    //     // 
    //     // {
    //     //   TDebuggingLog *this_00;
    //     //   RESENDER *pRVar1;
    //     //   uint uVar2;
    //     //   ulong uVar3;
    //     //   ulong uVar4;
    //     //   uint uVar5;
    //     //   TCommunications_Handler *this_01;
    //     //   TDebuggingLog *this_02;
    //     //   TDebuggingLog *this_03;
    //     //   TDebuggingLog *this_04;
    //     //   uint uVar6;
    //     //   char *pcVar7;
    //     //   uint BadTransmitCount;
    //     //   uint i;
    //     //   uint GoodTransmitCount;
    //     //   long hr;
    //     //   MSGFORMAT_RESEND nosuch;
    //     //   
    //     //   uVar2 = param_2;
    //     //   if (this->RGE_Guaranteed_Delivery == '\0') {
    //     //     return 0;
    //     //   }
    //     //   uVar6 = 0;
    //     //   if ((this->PlayerOptions).dcoID[param_2] == 0) {
    //     //     pcVar7 = s_Invalid_player_req_;
    //     //     this_01 = this;
    //     // LAB_0042b07b:
    //     //     TDebuggingLog::Log((TDebuggingLog *)this_01,(char *)L,pcVar7);
    //     //     return 0;
    //     //   }
    //     //   if (DAT_0062cf04 == 0) {
    //     //     return 0;
    //     //   }
    //     //   uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xee7);
    //     //   if ((param_1 == this->LastSerialRepliedTX[param_2]) &&
    //     //      (uVar5 = uVar3 - this->LastRequestRepliedTX[param_2], uVar5 < 500)) {
    //     //     TDebuggingLog::Log(L,(char *)L,s_Res_reply_too_soon___u__u,param_1,uVar5);
    //     //     return 0;
    //     //   }
    //     //   this->LastSerialRepliedTX[param_2] = param_1;
    //     //   this->LastRequestRepliedTX[param_2] = uVar3;
    //     //   hr = 0;
    //     //   i = 0;
    //     //   GoodTransmitCount = 0;
    //     //   param_2 = param_2 * 4 + 0x10;
    //     //   do {
    //     //     uVar5 = *(uint *)((int)this->Resend->DestMap + (uVar6 - 0xc));
    //     //     if (uVar5 == param_1) {
    //     //       sprintf(this->TBuff,s_Found_Resend_Ser__d_for_P__d,uVar5,uVar2);
    //     //       TDebuggingLog::Log(L,(char *)L,this->TBuff);
    //     //       nosuch.Serialno = (uint)operator_new(*(uint *)((int)this->Resend->DestMap + (uVar6 - 4)));
    //     //       this_01 = (TCommunications_Handler *)
    //     //                 (*(int *)((int)this->Resend->DestMap + (param_2 - 0x10)) + -1);
    //     //       *(TCommunications_Handler **)((int)this->Resend->DestMap + (param_2 - 0x10)) = this_01;
    //     //       if (DAT_0062cf04 == 0) {
    //     //         pcVar7 = s____BAD_DCOID_0_NO_TX;
    //     //         goto LAB_0042b07b;
    //     //       }
    //     //       uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf19);
    //     //       this_00 = *(TDebuggingLog **)((int)this->Resend->DestMap + (uVar6 - 4));
    //     //       TDebuggingLog::Log(this_00,(char *)L,s___>TX_RES_REP___d__d___d_,uVar2,param_1,this_00);
    //     //       nosuch._0_4_ = (**(code **)(*DAT_0062c5ec + 0x68))
    //     //                                (DAT_0062c5ec,DAT_0062cf04,(this->PlayerOptions).dcoID[uVar2],0,
    //     //                                 *(undefined4 *)((int)this->Resend->DestMap + (uVar6 - 8)),
    //     //                                 *(undefined4 *)((int)this->Resend->DestMap + (uVar6 - 4)));
    //     //       uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf28);
    //     //       if (0x32 < uVar4 - uVar3) {
    //     //         TDebuggingLog::Log(this_02,(char *)L,s____TXResendReply_slow____ld_msec,uVar4 - uVar3);
    //     //       }
    //     //       if (nosuch._0_4_ == 0) {
    //     //         hr = hr + 1;
    //     //         this->TXPacketLength =
    //     //              this->TXPacketLength + *(int *)((int)this->Resend->DestMap + (uVar6 - 4));
    //     //       }
    //     //       else {
    //     //         RGE_Comm_Error::ShowReturn(this->Err,nosuch._0_4_,s_Resend_TX);
    //     //         i = i + 1;
    //     //       }
    //     //       pRVar1 = this->Resend;
    //     //                     /* language.dll match for 0xf42: "Right-click to board this transport." */
    //     //       nosuch._0_4_ = SEXT14(**(char **)((int)pRVar1->DestMap + (uVar6 - 8)));
    //     //       uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf42);
    //     //       TDebuggingLog::Log(L,(char *)L,s_COMM__>>>>>_RETRANSMIT_P__d_Ser_,uVar2,
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + (uVar6 - 0xc)),GoodTransmitCount,
    //     //                          nosuch._0_4_,nosuch._0_4_,
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + (uVar6 - 4)),
    //     //                          *(undefined4 *)((int)pRVar1->DestMap + (param_2 - 0x10)),uVar3);
    //     //       operator_delete((void *)nosuch.Serialno);
    //     //     }
    //     //     uVar6 = uVar6 + 0x38;
    //     //     GoodTransmitCount = GoodTransmitCount + 1;
    //     //     param_2 = param_2 + 0x38;
    //     //     if (0x6d98 < uVar6) {
    //     //       if ((hr == 0) && (i == 0)) {
    //     //         if ((this->PlayerOptions).ProgramState == COMM_STATE_JOINNOW) {
    //     //           TDebuggingLog::Log(L,(char *)L,s_____Did_not_have_requested_Ser__,param_1,uVar2);
    //     //           nosuch.Serialno = CONCAT31(nosuch.Serialno._1_3_,0x59);
    //     //           TDebuggingLog::Log(this_03,(char *)L,s___>TX_RNSM___d__d___d_,uVar2,param_1,8);
    //     //           FastSend(this,(this->PlayerOptions).dcoID[uVar2],&nosuch.Serialno,8,0,0);
    //     //           TDebuggingLog::Log(this_04,(char *)L,s_____TX__No_such_message_as___d__,param_1);
    //     //           ClearTXForPlayer(this,uVar2);
    //     //         }
    //     //       }
    //     //       else {
    //     //         TDebuggingLog::Log((TDebuggingLog *)hr,(char *)L,s_RESEND_to_P__d_FULFILLED___GoodT,uVar2,hr
    //     //                            ,i,i + hr);
    //     //       }
    //     //       PurgeAcknowledgedStoredMessages(this);
    //     //       return 1;
    //     //     }
    //     //   } while( true );
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::TXResendRequest(uint param_2, uint param_3) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042B0A0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042B0A0
    // int TXResendRequest(TCommunications_Handler* this_, uint param_2, uint param_3) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: int __thiscall TCommunications_Handler::TXResendRequest(unsigned int,unsigned int) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::TXResendRequest(TCommunications_Handler *this,uint param_1,uint param_2)
    //     // 
    //     // {
    //     //   ulong uVar1;
    //     //   undefined1 *puVar2;
    //     //   int iVar3;
    //     //   TDebuggingLog *this_00;
    //     //   TDebuggingLog *this_01;
    //     //   TDebuggingLog *this_02;
    //     //   int unaff_EDI;
    //     //   
    //     //   if (this->RGE_Guaranteed_Delivery != '\0') {
    //     //     uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xf8c);
    //     //     if ((param_1 != this->LastSerialRequestedTX[param_2]) ||
    //     //        (499 < uVar1 - this->LastRequestHonoredTX[param_2])) {
    //     //       this->LastSerialRequestedTX[param_2] = param_1;
    //     //       this->LastRequestHonoredTX[param_2] = uVar1;
    //     //       puVar2 = (undefined1 *)operator_new(8);
    //     //       *puVar2 = 0x58;
    //     //       *(uint *)(puVar2 + 4) = param_1;
    //     //       TDebuggingLog::Log(this_00,(char *)L,s_GTD__TX_RESEND_REQ_to_P__d__Ser_,param_2,param_1);
    //     //       if (DAT_0062cf04 == 0) {
    //     //         TDebuggingLog::Log(this_01,(char *)L,s____BAD_DCOID_0_NO_TX);
    //     //         return 0;
    //     //       }
    //     //                     /* language.dll match for 0xfa9: "?" */
    //     //       debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xfa9);
    //     //       TDebuggingLog::Log(L,(char *)L,s___>TX_RES_REQ___d__d___d_,param_2,param_1,8);
    //     //       iVar3 = (**(code **)(*DAT_0062c5ec + 0x68))
    //     //                         (DAT_0062c5ec,DAT_0062cf04,(this->PlayerOptions).dcoID[param_2],0,puVar2,8);
    //     //       uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xfb8);
    //     //       if (0x32 < uVar1 - unaff_EDI) {
    //     //         TDebuggingLog::Log(this_02,(char *)L,s____GetNextSequence_slow____ld_ms,uVar1 - unaff_EDI);
    //     //       }
    //     //       operator_delete(puVar2);
    //     //       if (iVar3 == 0) {
    //     //         this->TXPacketLength = this->TXPacketLength + 8;
    //     //         return 1;
    //     //       }
    //     //     }
    //     //   }
    //     //   return 0;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

uchar TCommunications_Handler::GetNextSequence(ulong param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B200
    return comm_get_next_sequence(param_2, this->PlayerOptions.ProgramState);
}

void TCommunications_Handler::DestroyMultiplayerGame(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042B860
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042B860
    // void DestroyMultiplayerGame(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: void __thiscall TCommunications_Handler::DestroyMultiplayerGame(void) */
    //     // 
    //     // void __thiscall TCommunications_Handler::DestroyMultiplayerGame(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   char cVar1;
    //     //   ushort uVar2;
    //     //   ulong uVar3;
    //     //   int *piVar4;
    //     //   uint uVar5;
    //     //   uint uVar6;
    //     //   int iVar7;
    //     //   char *pcVar8;
    //     //   char *pcVar9;
    //     //   ulong *puVar10;
    //     //   
    //     //   DestroyMyPlayer(this);
    //     //   uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_com_hand_h,0x267);
    //     //   this->RXPacketLength = 0;
    //     //   this->RXPacketLengthHigh = 0;
    //     //   this->TXPacketLength = 0;
    //     //   this->TXPacketLengthHigh = 0;
    //     //   this->lastRXDataRate = 0.0;
    //     //   this->lastTXDataRate = 0.0;
    //     //   this->HoldCount = 0;
    //     //   this->ServiceTimeout = 0;
    //     //   this->TXPackets = 0;
    //     //   this->RXPackets = 0;
    //     //   this->RGE_Guaranteed_Delivery = '\0';
    //     //   this->ResendAcknowledgements = 0;
    //     //   this->ResentToOther = 0;
    //     //   this->DroppedPacketCount = 0;
    //     //   this->LobbyLaunched = 0;
    //     //   this->GTDSerialNo = 0;
    //     //   this->dwStopTime = 0;
    //     //   this->OutOfSyncFlag = 0;
    //     //   TDebuggingLog::Time(L);
    //     //   uVar5 = 0xffffffff;
    //     //   this->AvgTurnTime = 0;
    //     //   this->PauseChangePending = 0;
    //     //   this->StepMode = 0;
    //     //   this->IntentionallyDropPackets = 0;
    //     //   (this->PlayerOptions).LastSentTime = uVar3;
    //     //   pcVar8 = &s__;
    //     //   do {
    //     //     pcVar9 = pcVar8;
    //     //     if (uVar5 == 0) break;
    //     //     uVar5 = uVar5 - 1;
    //     //     pcVar9 = pcVar8 + 1;
    //     //     cVar1 = *pcVar8;
    //     //     pcVar8 = pcVar9;
    //     //   } while (cVar1 != '\0');
    //     //   uVar5 = ~uVar5;
    //     //   pcVar8 = pcVar9 + -uVar5;
    //     //   pcVar9 = this->MyGameTitle;
    //     //   for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    //     //     *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    //     //     pcVar8 = pcVar8 + 4;
    //     //     pcVar9 = pcVar9 + 4;
    //     //   }
    //     //   for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    //     //     *pcVar9 = *pcVar8;
    //     //     pcVar8 = pcVar8 + 1;
    //     //     pcVar9 = pcVar9 + 1;
    //     //   }
    //     //   uVar5 = 0xffffffff;
    //     //   pcVar8 = &s__;
    //     //   do {
    //     //     pcVar9 = pcVar8;
    //     //     if (uVar5 == 0) break;
    //     //     uVar5 = uVar5 - 1;
    //     //     pcVar9 = pcVar8 + 1;
    //     //     cVar1 = *pcVar8;
    //     //     pcVar8 = pcVar9;
    //     //   } while (cVar1 != '\0');
    //     //   uVar5 = ~uVar5;
    //     //   pcVar8 = pcVar9 + -uVar5;
    //     //   pcVar9 = this->MyFriendlyName;
    //     //   for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    //     //     *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    //     //     pcVar8 = pcVar8 + 4;
    //     //     pcVar9 = pcVar9 + 4;
    //     //   }
    //     //   for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    //     //     *pcVar9 = *pcVar8;
    //     //     pcVar8 = pcVar8 + 1;
    //     //     pcVar9 = pcVar9 + 1;
    //     //   }
    //     //   uVar5 = 0xffffffff;
    //     //   pcVar8 = &s__;
    //     //   do {
    //     //     pcVar9 = pcVar8;
    //     //     if (uVar5 == 0) break;
    //     //     uVar5 = uVar5 - 1;
    //     //     pcVar9 = pcVar8 + 1;
    //     //     cVar1 = *pcVar8;
    //     //     pcVar8 = pcVar9;
    //     //   } while (cVar1 != '\0');
    //     //   uVar5 = ~uVar5;
    //     //   pcVar8 = pcVar9 + -uVar5;
    //     //   pcVar9 = this->MyFormalName;
    //     //   for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    //     //     *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    //     //     pcVar8 = pcVar8 + 4;
    //     //     pcVar9 = pcVar9 + 4;
    //     //   }
    //     //   for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    //     //     *pcVar9 = *pcVar8;
    //     //     pcVar8 = pcVar8 + 1;
    //     //     pcVar9 = pcVar9 + 1;
    //     //   }
    //     //   uVar2 = this->MaxGamePlayers;
    //     //   this->TickStart = 0;
    //     //   this->TickCount = 0;
    //     //   this->LastTimeoutMessageTime = 0;
    //     //   (this->PlayerOptions).LowPlayerNumber = 1;
    //     //   (this->PlayerOptions).HighPlayerNumber = uVar2;
    //     //   (this->PlayerOptions).GameHasStarted = 0;
    //     //   (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    //     //   this->MeHost = 0;
    //     //   this->HaveHostInit = 0;
    //     //   (this->PlayerOptions).CommandTurnIncrement = '\x02';
    //     //   this->current_turn = 4;
    //     //   (this->PlayerOptions).CurrentTurn = 4;
    //     //   (this->PlayerOptions).NeedsToBeSent = '\0';
    //     //   this->AcknowledgeAfterMsec = 0x32;
    //     //   this->Me = 0;
    //     //   this->Multiplayer = 0;
    //     //   this->turnstart = 0;
    //     //   this->mselapsed = 0;
    //     //   TDebuggingLog::Log((TDebuggingLog *)(uint)uVar2,(char *)L,s_Initialize_Player_List);
    //     //   uVar5 = 1;
    //     //   if (this->MaxGamePlayers != 0) {
    //     //     do {
    //     //       InitPlayerInformation(this,uVar5,0,&s__,&s__);
    //     //       uVar5 = uVar5 + 1;
    //     //     } while ((int)uVar5 <= (int)(uint)this->MaxGamePlayers);
    //     //   }
    //     //   (this->PlayerOptions).NeedsToBeSent = '\0';
    //     //   (this->PlayerOptions).LastSentTime = 0;
    //     //   ClearAllSerialNumbers(this);
    //     //   ClearRXandTX(this);
    //     //   puVar10 = this->PlayerStopTurn;
    //     //   for (iVar7 = 9; puVar10 = puVar10 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    //     //     *puVar10 = 0;
    //     //   }
    //     //   this->Steps = 1;
    //     //   ResetLastCommunicationTimes(this);
    //     //   this->WaitingForAck = 0;
    //     //   if (this->InQ != (RGE_Communications_Queue *)0x0) {
    //     //     RGE_Communications_Queue::FlushAll(this->InQ);
    //     //   }
    //     //   if (this->OutQ != (RGE_Communications_Queue *)0x0) {
    //     //     RGE_Communications_Queue::FlushAll(this->OutQ);
    //     //   }
    //     //   this->ShuttingDown = 0;
    //     //   piVar4 = this->Kicked;
    //     //   iVar7 = 10;
    //     //   do {
    //     //     piVar4[-0x4c] = 0;
    //     //     *piVar4 = 0;
    //     //     piVar4[0xac] = 0;
    //     //     piVar4 = piVar4 + 1;
    //     //     iVar7 = iVar7 + -1;
    //     //   } while (iVar7 != 0);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

void TCommunications_Handler::SetRandomSeed(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CA20
    this->PlayerOptions.RandomSeed = (ulong)param_2;
}

char* TCommunications_Handler::GetCommStateStr(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042CB20
    switch (this->PlayerOptions.ProgramState) {
    case 0: return (char*)"None";
    case 1: return (char*)"Init";
    case 2: return (char*)"Loading";
    case 3: return (char*)"JoinNow";
    case 4: return (char*)"Paused";
    case 5: return (char*)"Running";
    default: return (char*)"Unknown";
    }
}

char* TCommunications_Handler::GetReadyPlayerStr(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042CB30
    if (this->AllPlayersReady() != 0) {
        return (char*)"Ready";
    }
    return (char*)"Not Ready";
}

int TCommunications_Handler::GetActivePlayerCount(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CC90
    int count = 0;
    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        if (this->IsPlayerHuman(p) != 0 || this->IsPlayerComputer(p) != 0) {
            ++count;
        }
    }
    return count;
}

int TCommunications_Handler::IsPlayerComputer(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CD10
    if (param_2 == 0 || param_2 > (uint)this->MaxGamePlayers || param_2 >= 10) {
        return 0;
    }
    return (this->PlayerOptions.Humanity[param_2] == kPlayerHumanityComputer) ? 1 : 0;
}

char* TCommunications_Handler::GetCommInfo(uchar param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042CD50
    uint player = (uint)param_2;
    if (player == 0 || player > (uint)this->MaxGamePlayers) {
        sprintf(this->TBuff, "Player %u invalid", player);
        return this->TBuff;
    }
    return this->WaitingOnNamedInfo(player);
}

void TCommunications_Handler::UpdatePlayerInformation(ulong param_2, char* param_3, char* param_4) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D120
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042D120
    // void UpdatePlayerInformation(TCommunications_Handler* this_, ulong param_2, char* param_3, char* param_4) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: void __thiscall TCommunications_Handler::UpdatePlayerInformation(unsigned long,char
    //     //    *,char *) */
    //     // 
    //     // void __thiscall
    //     // TCommunications_Handler::UpdatePlayerInformation
    //     //           (TCommunications_Handler *this,ulong param_1,char *param_2,char *param_3)
    //     // 
    //     // {
    //     //   uint uVar1;
    //     //   ulong *puVar2;
    //     //   uint uVar3;
    //     //   
    //     //   if (param_1 != 0) {
    //     //     uVar1 = (uint)(this->PlayerOptions).LowPlayerNumber;
    //     //     uVar3 = (uint)(this->PlayerOptions).HighPlayerNumber;
    //     //     if (uVar1 <= uVar3) {
    //     //       puVar2 = (this->PlayerOptions).dcoID + uVar1;
    //     //       do {
    //     //         if (*puVar2 == param_1) goto LAB_0042d155;
    //     //         uVar1 = uVar1 + 1;
    //     //         puVar2 = puVar2 + 1;
    //     //       } while ((int)uVar1 <= (int)uVar3);
    //     //     }
    //     //   }
    //     //   uVar1 = 0;
    //     // LAB_0042d155:
    //     //   if (uVar1 == 0) {
    //     //     InitPlayerInformation(this,0,param_1,param_2,param_3);
    //     //   }
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

int TCommunications_Handler::LaunchLobbyGame(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D180
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042D180
    // int LaunchLobbyGame(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: NewDPConv */
    //     // /* public: int __thiscall TCommunications_Handler::LaunchLobbyGame(void) */
    //     // 
    //     // int __thiscall TCommunications_Handler::LaunchLobbyGame(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   byte bVar1;
    //     //   undefined4 uVar3;
    //     //   TDebuggingLog *this_00;
    //     //   IDirectPlay3 *NewDPConv;
    //     //   char *name;
    //     //   DPSESSIONDESC2 test;
    //     //   uint uVar2;
    //     //   
    //     //   name = (char *)0x0;
    //     //   bVar1 = RGE_Lobby::CheckForLobbyLaunch(this->Lobby,(IDirectPlay3 **)&name);
    //     //   uVar2 = (uint)bVar1;
    //     //   if (uVar2 != 0) {
    //     //     if (DAT_0062c5ec != (int *)0x0) {
    //     //       uVar3 = (**(code **)(*DAT_0062c5ec + 8))(DAT_0062c5ec);
    //     //       TDebuggingLog::Log(this_00,(char *)L,s_Release_count____d,uVar3);
    //     //     }
    //     //     DAT_0062c5ec = (int *)name;
    //     //     if (name == (char *)0x0) {
    //     //       return (int)name;
    //     //     }
    //     //     bVar1 = RGE_Lobby::GetSessionInfo(this->Lobby,(DPSESSIONDESC2 *)&test.dwFlags);
    //     //     uVar2 = (uint)bVar1;
    //     //     if (uVar2 != 0) {
    //     //       DebugSessionInformation(this,(DPSESSIONDESC2 *)&test.dwFlags);
    //     //     }
    //     //     CommGetCaps(this);
    //     //     this->Multiplayer = 1;
    //     //     DPlayGetSessionDesc(this);
    //     //     RGE_Lobby::GetPlayerInfo(this->Lobby,(char **)&test);
    //     //     SetMyPlayerName(this,(char *)test.dwSize);
    //     //     (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    //     //     AddSelfPlayer(this);
    //     //     bVar1 = RGE_Lobby::IsThisHost(this->Lobby);
    //     //     this->MeHost = (uint)bVar1;
    //     //     if (bVar1 != 0) {
    //     //       this->Me = 1;
    //     //       (this->PlayerOptions).dcoID[1] = DAT_0062cf04;
    //     //       (this->PlayerOptions).Humanity[this->Me] = ME_HUMAN;
    //     //       this->HaveHostInit = 1;
    //     //       (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    //     //       SetRandomSeed(this,rge_base_game->random_game_seed);
    //     //                     /* language.dll match for 0x7d1: "Error" */
    //     //       this->GTDSerialNo = 0x7d1;
    //     //     }
    //     //     UpdatePlayers(this);
    //     //   }
    //     //   this->LobbyLaunched = uVar2;
    //     //   return uVar2;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::SetGameTitle(char* param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D3B0
    if (param_2 == nullptr) {
        this->MyGameTitle[0] = '\0';
        return 0;
    }
    strncpy(this->MyGameTitle, param_2, sizeof(this->MyGameTitle) - 1);
    this->MyGameTitle[sizeof(this->MyGameTitle) - 1] = '\0';
    return 1;
}

void TCommunications_Handler::SetMyPlayerName(char* param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D3E0
    if (param_2 == nullptr) {
        this->MyFriendlyName[0] = '\0';
        this->MyFormalName[0] = '\0';
        return;
    }
    strncpy(this->MyFriendlyName, param_2, sizeof(this->MyFriendlyName) - 1);
    this->MyFriendlyName[sizeof(this->MyFriendlyName) - 1] = '\0';
    strncpy(this->MyFormalName, param_2, sizeof(this->MyFormalName) - 1);
    this->MyFormalName[sizeof(this->MyFormalName) - 1] = '\0';
}

long TCommunications_Handler::CreateDirectPlayConversation(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D4A0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042D4A0
    // long CreateDirectPlayConversation(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: lpIDC */
    //     // /* protected: long __thiscall TCommunications_Handler::CreateDirectPlayConversation(void) */
    //     // 
    //     // long __thiscall TCommunications_Handler::CreateDirectPlayConversation(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   ushort uVar1;
    //     //   int iVar2;
    //     //   undefined4 uVar3;
    //     //   TDebuggingLog *this_00;
    //     //   TDebuggingLog *this_01;
    //     //   int *unaff_EDI;
    //     //   IDirectPlay *lpIDC;
    //     //   TCommunications_Handler *local_4;
    //     //   
    //     //   local_4 = this;
    //     //   iVar2 = _DirectPlayCreate_12(&this->ServiceGUID,&local_4,0);
    //     //   RGE_Comm_Error::ShowReturn(this->Err,iVar2,s_DPCreate);
    //     //   if (DAT_0062c5ec != 0) {
    //     //     TDebuggingLog::Log(L,(char *)L,s_Already_have_conversation_);
    //     //     return -0x7788fffb;
    //     //   }
    //     //   if (iVar2 != 0) {
    //     //     (this->ServiceGUID).Data1 = (this->NullGUID).Data1;
    //     //     uVar1 = (this->NullGUID).Data3;
    //     //     (this->ServiceGUID).Data2 = (this->NullGUID).Data2;
    //     //     (this->ServiceGUID).Data3 = uVar1;
    //     //     *(undefined4 *)(this->ServiceGUID).Data4 = *(undefined4 *)(this->NullGUID).Data4;
    //     //     *(undefined4 *)((this->ServiceGUID).Data4 + 4) = *(undefined4 *)((this->NullGUID).Data4 + 4);
    //     //     return iVar2;
    //     //   }
    //     //   if (local_4 != (TCommunications_Handler *)0x0) {
    //     //     iVar2 = (**(code **)local_4->OptionsChanged)(local_4,&_IID_IDirectPlay3A,&DAT_0062c5ec);
    //     //     if (iVar2 != 0) {
    //     //       TDebuggingLog::Log(this_00,(char *)L,s_Get_glpIDC_returns____ld,iVar2);
    //     //       return iVar2;
    //     //     }
    //     //     uVar3 = (**(code **)(*unaff_EDI + 8))(unaff_EDI);
    //     //     TDebuggingLog::Log(this_01,(char *)L,s_Release__Links__d,uVar3);
    //     //   }
    //     //   return 0;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::OpenMultiplayerConnection(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D580
    if (this->CreateDirectPlayConversation() != 0) {
        return -1;
    }
    return 1;
}

int TCommunications_Handler::CreateMultiplayerGame(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D590
    if (this->OpenMultiplayerConnection() <= 0) {
        return 0;
    }
    return (this->AddSelfPlayer() != 0) ? 1 : 0;
}

int TCommunications_Handler::AddSelfPlayer(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042D960
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042D960
    // int AddSelfPlayer(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: names */
    //     // /* protected: int __thiscall TCommunications_Handler::AddSelfPlayer(void) */
    //     // 
    //     // int __thiscall TCommunications_Handler::AddSelfPlayer(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   int iVar1;
    //     //   DPNAME names;
    //     //   
    //     //   TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Create_the_player);
    //     //   names.field3_0xc.lpszLongName = (ushort *)this->MyFriendlyName;
    //     //   names.field2_0x8.lpszShortName = (ushort *)0x0;
    //     //   names.dwFlags = 0x10;
    //     //   TDebuggingLog::Log((TDebuggingLog *)0x0,(char *)L,s_Adding_player___s_,
    //     //                      names.field3_0xc.lpszLongName);
    //     //   if (DAT_0062c5ec == (int *)0x0) {
    //     //     return 0;
    //     //   }
    //     //   iVar1 = (**(code **)(*DAT_0062c5ec + 0x18))(DAT_0062c5ec,&DAT_0062cf04,&names.dwFlags,0,0,0,0);
    //     //   RGE_Comm_Error::ShowReturn(this->Err,iVar1,s_Add_SELF_PLAYER);
    //     //   if (iVar1 != 0) {
    //     //     CloseSession(this);
    //     //     ReleaseComm(this);
    //     //     (this->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    //     //     return 0;
    //     //   }
    //     //   TDebuggingLog::Log(L,(char *)L,s_Rcvd_DPID_of__d,DAT_0062cf04);
    //     //   GetMyMultiPlayerCaps(this);
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

long TCommunications_Handler::InitJoinGame(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042DA50
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042DA50
    // long InitJoinGame(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: long __thiscall TCommunications_Handler::InitJoinGame(void) */
    //     // 
    //     // long __thiscall TCommunications_Handler::InitJoinGame(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   long lVar1;
    //     //   
    //     //   TChat::ClearChat(this->Chat);
    //     //   this->Multiplayer = 1;
    //     //   this->HaveHostInit = 0;
    //     //   this->MeHost = 0;
    //     //   this->GTDSerialNo = 0;
    //     //   lVar1 = CreateDirectPlayConversation(this);
    //     //   return lVar1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::JoinMultiplayerGame(_GUID* param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042DA80
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042DA80
    // int JoinMultiplayerGame(TCommunications_Handler* this_, _GUID* param_2) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: dSess2 */
    //     // /* public: int __thiscall TCommunications_Handler::JoinMultiplayerGame(struct _GUID *) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::JoinMultiplayerGame(TCommunications_Handler *this,_GUID *param_1)
    //     // 
    //     // {
    //     //   undefined4 uVar1;
    //     //   ushort uVar2;
    //     //   int iVar3;
    //     //   DPSESSIONDESC2 *pDVar4;
    //     //   DPSESSIONDESC2 dSess2;
    //     //   
    //     //   if (DAT_0062c5ec == (int *)0x0) {
    //     //     TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_JMPG__Create_w_no_valid_glpIDC);
    //     //     return 0;
    //     //   }
    //     //   pDVar4 = &dSess2;
    //     //   for (iVar3 = 0x14; pDVar4 = (DPSESSIONDESC2 *)&pDVar4->dwFlags, iVar3 != 0; iVar3 = iVar3 + -1) {
    //     //     *(ulong *)pDVar4 = 0;
    //     //   }
    //     //   dSess2.dwFlags = 0x50;
    //     //   (this->SessionGUID).Data1 = param_1->Data1;
    //     //   uVar2 = param_1->Data3;
    //     //   (this->SessionGUID).Data2 = param_1->Data2;
    //     //   (this->SessionGUID).Data3 = uVar2;
    //     //   *(undefined4 *)(this->SessionGUID).Data4 = *(undefined4 *)param_1->Data4;
    //     //   uVar1 = *(undefined4 *)(param_1->Data4 + 4);
    //     //   this->MeHost = 0;
    //     //   *(undefined4 *)((this->SessionGUID).Data4 + 4) = uVar1;
    //     //   dSess2.guidInstance._4_4_ = param_1->Data1;
    //     //   dSess2.guidInstance.Data4._0_4_ = *(undefined4 *)&param_1->Data2;
    //     //   dSess2.guidInstance.Data4._4_4_ = *(undefined4 *)param_1->Data4;
    //     //   dSess2.guidApplication.Data1 = *(ulong *)(param_1->Data4 + 4);
    //     //   dSess2.guidApplication._4_4_ = (this->ApplicationGUID).Data1;
    //     //   dSess2.guidApplication.Data4._0_4_ = *(undefined4 *)&(this->ApplicationGUID).Data2;
    //     //   dSess2.guidApplication.Data4._4_4_ = *(undefined4 *)(this->ApplicationGUID).Data4;
    //     //   dSess2.dwMaxPlayers = *(ulong *)((this->ApplicationGUID).Data4 + 4);
    //     //   TDebuggingLog::Log(L,(char *)L,s_Open_session_for_JOIN___Session_,(this->SessionGUID).Data1);
    //     //   iVar3 = (**(code **)(*DAT_0062c5ec + 0x60))(DAT_0062c5ec,&dSess2.dwFlags,1);
    //     //   if (iVar3 == -0x7788fea2) {
    //     //     RGE_Comm_Error::ShowReturn(this->Err,-0x7788fea2,s_Join_MP_Game);
    //     //     return 0;
    //     //   }
    //     //   if (iVar3 == -0x7788fffb) {
    //     //     RGE_Comm_Error::ShowReturn(this->Err,-0x7788fffb,s_Join_MP_Game);
    //     //     return 0;
    //     //   }
    //     //   if (iVar3 == -0x7788feb6) {
    //     //     RGE_Comm_Error::ShowReturn(this->Err,-0x7788feb6,s_Join_MP_Game);
    //     //     NotifyWindow(this,COMM_NO_NEW_PLAYERS);
    //     //     return 0;
    //     //   }
    //     //   if (iVar3 != 0) {
    //     //     RGE_Comm_Error::ShowReturn(this->Err,iVar3,s_Join_MP_Game);
    //     //     (this->PlayerOptions).ProgramState = COMM_STATE_ERROR;
    //     //     return 0;
    //     //   }
    //     //   iVar3 = AddSelfPlayer(this);
    //     //   if (iVar3 == 0) {
    //     //     return 0;
    //     //   }
    //     //   (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

long TCommunications_Handler::GetMyMultiPlayerCaps(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042DD70
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042DD70
    // long GetMyMultiPlayerCaps(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: dpCaps */
    //     // /* protected: long __thiscall TCommunications_Handler::GetMyMultiPlayerCaps(void) */
    //     // 
    //     // long __thiscall TCommunications_Handler::GetMyMultiPlayerCaps(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   int iVar1;
    //     //   TDebuggingLog *this_00;
    //     //   ulong unaff_ESI;
    //     //   ulong unaff_EDI;
    //     //   ulong *puVar2;
    //     //   DPCAPS dpCaps;
    //     //   
    //     //   if (DAT_0062c5ec == (int *)0x0) {
    //     //     return -0x7fffbffb;
    //     //   }
    //     //   puVar2 = &dpCaps.dwFlags;
    //     //   for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    //     //     *puVar2 = 0;
    //     //     puVar2 = puVar2 + 1;
    //     //   }
    //     //   dpCaps.dwFlags = 0x28;
    //     //   if (DAT_0062cf04 == 0) {
    //     //     return -0x7fffbffb;
    //     //   }
    //     //   dpCaps.dwSize = unaff_ESI;
    //     //   iVar1 = (**(code **)(*DAT_0062c5ec + 0x4c))(DAT_0062c5ec,DAT_0062cf04,&dpCaps.dwFlags);
    //     //   RGE_Comm_Error::ShowReturn(this->Err,iVar1,s_Get_Player_Caps);
    //     //   if (iVar1 != 0) {
    //     //     return iVar1;
    //     //   }
    //     //   this->dwFlags = 1;
    //     //   this->dwMaxBufferSize = unaff_EDI;
    //     //   this->dwMaxQueueSize = dpCaps.dwSize;
    //     //   this->RGE_Guaranteed_Delivery = '\x01';
    //     //   this->dwMaxPlayers = dpCaps.dwFlags;
    //     //   this->dwHundredBaud = dpCaps.dwMaxBufferSize;
    //     //   this->dwLatency = dpCaps.dwMaxQueueSize;
    //     //   TDebuggingLog::Log(L,(char *)L,s_Enumerated_player_caps___);
    //     //   TDebuggingLog::Log(this_00,(char *)L,s_Latency____d,this->dwLatency);
    //     //   TDebuggingLog::Log((TDebuggingLog *)this->dwMaxQueueSize,(char *)L,s_MaxQueueSize__d,
    //     //                      (TDebuggingLog *)this->dwMaxQueueSize);
    //     //   TDebuggingLog::Log(L,(char *)L,s_RGE_Gtd_Delivery__d,(uint)this->RGE_Guaranteed_Delivery);
    //     //   return 0;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

void TCommunications_Handler::SetApplicationGUID(_GUID param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DEA0
    this->ApplicationGUID = param_2;
}

void TCommunications_Handler::SetServiceGUID(_GUID param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DEE0
    this->ServiceGUID = param_2;
}

void TCommunications_Handler::SetSessionGUID(_GUID param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DF10
    this->SessionGUID = param_2;
}

int TCommunications_Handler::SetMyReadiness(int param_2, ulong param_3, ulong param_4, ulong param_5, ulong param_6, ulong param_7, ulong param_8, ulong param_9) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042E380
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042E380
    // int SetMyReadiness(TCommunications_Handler* this_, int param_2, ulong param_3, ulong param_4, ulong param_5, ulong param_6, ulong param_7, ulong param_8, ulong param_9) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: rdy */
    //     // /* public: int __thiscall TCommunications_Handler::SetMyReadiness(int,unsigned long,unsigned
    //     //    long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::SetMyReadiness
    //     //           (TCommunications_Handler *this,int param_1,ulong param_2,ulong param_3,ulong param_4,
    //     //           ulong param_5,ulong param_6,ulong param_7,ulong param_8)
    //     // 
    //     // {
    //     //   uint uVar1;
    //     //   TDebuggingLog *this_00;
    //     //   MSGFORMAT_SETREADYOPTIONS rdy;
    //     //   
    //     //   uVar1 = this->Me;
    //     //   this_00 = (TDebuggingLog *)(this->PlayerOptions).User1[uVar1];
    //     //   TDebuggingLog::Log(this_00,(char *)L,s_SET_MY_READINESS__P__d_RDY__d_O1,uVar1,
    //     //                      (this->PlayerOptions).PlayerReady[uVar1],this_00,
    //     //                      (this->PlayerOptions).User2[uVar1],(this->PlayerOptions).User3[uVar1],
    //     //                      (this->PlayerOptions).User4[uVar1],(this->PlayerOptions).User5[uVar1],
    //     //                      (this->PlayerOptions).User6[uVar1],(this->PlayerOptions).User7[uVar1]);
    //     //   (this->PlayerOptions).PlayerReady[this->Me] = param_1;
    //     //   (this->PlayerOptions).User1[this->Me] = param_2;
    //     //   (this->PlayerOptions).User2[this->Me] = param_3;
    //     //   (this->PlayerOptions).User3[this->Me] = param_4;
    //     //   (this->PlayerOptions).User4[this->Me] = param_5;
    //     //   (this->PlayerOptions).User5[this->Me] = param_6;
    //     //   (this->PlayerOptions).User6[this->Me] = param_7;
    //     //   (this->PlayerOptions).User7[this->Me] = param_8;
    //     //   rdy.User1._1_1_ = (undefined1)param_1;
    //     //   rdy.User2 = param_2;
    //     //   rdy.User5 = param_5;
    //     //   rdy._36_4_ = this->CommunicationsVersionCode;
    //     //   rdy.User3 = param_3;
    //     //   rdy.User6 = param_6;
    //     //   rdy.User4 = param_4;
    //     //   rdy.User7 = param_7;
    //     //   rdy.CommunicationsVersionCode = param_8;
    //     //   rdy.User1._0_1_ = 0x52;
    //     //   if (this->MeHost == 0) {
    //     //     TDebuggingLog::Log((TDebuggingLog *)CONCAT31((int3)(param_6 >> 8),this->RGE_Guaranteed_Delivery)
    //     //                        ,(char *)L,s___>TX_RDY___d_,0x28);
    //     //     FastSend(this,0,&rdy.User1,0x28,0,0);
    //     //   }
    //     //   NotifyWindow(this,COMM_UPDATE_PARAMS);
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::GetClientReadiness(uint param_2, int* param_3, ulong* param_4, ulong* param_5, ulong* param_6, ulong* param_7, ulong* param_8, ulong* param_9, ulong* param_10) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042E500
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042E500
    // int GetClientReadiness(TCommunications_Handler* this_, uint param_2, int* param_3, ulong* param_4, ulong* param_5, ulong* param_6, ulong* param_7, ulong* param_8, ulong* param_9, ulong* param_10) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: int __thiscall TCommunications_Handler::GetClientReadiness(unsigned int,int *,unsigned
    //     //    long *,unsigned long *,unsigned long *,unsigned long *,unsigned long *,unsigned long *,unsigned
    //     //    long *) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::GetClientReadiness
    //     //           (TCommunications_Handler *this,uint param_1,int *param_2,ulong *param_3,ulong *param_4,
    //     //           ulong *param_5,ulong *param_6,ulong *param_7,ulong *param_8,ulong *param_9)
    //     // 
    //     // {
    //     //   *param_2 = (this->PlayerOptions).PlayerReady[param_1];
    //     //   *param_3 = (this->PlayerOptions).User1[param_1];
    //     //   *param_4 = (this->PlayerOptions).User2[param_1];
    //     //   *param_5 = (this->PlayerOptions).User3[param_1];
    //     //   *param_6 = (this->PlayerOptions).User4[param_1];
    //     //   *param_7 = (this->PlayerOptions).User5[param_1];
    //     //   *param_8 = (this->PlayerOptions).User6[param_1];
    //     //   *param_9 = (this->PlayerOptions).User7[param_1];
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::IsPlayerReady(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E580
    if (param_2 == 0 || param_2 >= 10 || param_2 > (uint)this->MaxGamePlayers) {
        return 0;
    }
    return this->PlayerOptions.PlayerReady[param_2];
}

int TCommunications_Handler::ComputerPlayerGameStart(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042E5B0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042E5B0
    // int ComputerPlayerGameStart(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: int __thiscall TCommunications_Handler::ComputerPlayerGameStart(void) */
    //     // 
    //     // int __thiscall TCommunications_Handler::ComputerPlayerGameStart(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   if (this->Multiplayer == 0) {
    //     //     return 1;
    //     //   }
    //     //   return (uint)(6 < this->current_turn);
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

long TCommunications_Handler::DPlayGetSessionDesc(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042E670
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042E670
    // long DPlayGetSessionDesc(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: dwSize */
    //     // /* protected: long __thiscall TCommunications_Handler::DPlayGetSessionDesc(void) */
    //     // 
    //     // long __thiscall TCommunications_Handler::DPlayGetSessionDesc(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   undefined4 uVar1;
    //     //   ulong uVar2;
    //     //   int iVar3;
    //     //   int iVar4;
    //     //   undefined4 unaff_EDI;
    //     //   ulong dwSize;
    //     //   TCommunications_Handler *local_4;
    //     //   
    //     //   if (DAT_0062c5ec == (int *)0x0) {
    //     //     return -0x7fffbffb;
    //     //   }
    //     //   local_4 = this;
    //     //   (**(code **)(*DAT_0062c5ec + 0x58))(DAT_0062c5ec,0,&local_4);
    //     //   iVar3 = calloc(unaff_EDI,1);
    //     //   if (iVar3 == 0) {
    //     //     return -0x7ff8fff2;
    //     //   }
    //     //   iVar4 = (**(code **)(*DAT_0062c5ec + 0x58))(DAT_0062c5ec,iVar3,&stack0xfffffff0);
    //     //   RGE_Comm_Error::ShowReturn(this->Err,iVar4,s_Get_Session_Desc);
    //     //   if (iVar4 == 0) {
    //     //     (this->SessionGUID).Data1 = *(ulong *)(iVar3 + 8);
    //     //     uVar1 = *(undefined4 *)(iVar3 + 0xc);
    //     //     (this->SessionGUID).Data2 = (short)uVar1;
    //     //     (this->SessionGUID).Data3 = (short)((uint)uVar1 >> 0x10);
    //     //     *(undefined4 *)(this->SessionGUID).Data4 = *(undefined4 *)(iVar3 + 0x10);
    //     //     *(undefined4 *)((this->SessionGUID).Data4 + 4) = *(undefined4 *)(iVar3 + 0x14);
    //     //     uVar2 = *(ulong *)(iVar3 + 0x2c);
    //     //     this->CurrentPlayers = uVar2;
    //     //     TDebuggingLog::Log(L,(char *)L,s_RX_Current_Players__d,uVar2);
    //     //   }
    //     //   free(iVar3);
    //     //   return iVar4;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

long TCommunications_Handler::CommGetCaps(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042E730
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042E730
    // long CommGetCaps(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: DPCaps */
    //     // /* protected: long __thiscall TCommunications_Handler::CommGetCaps(void) */
    //     // 
    //     // long __thiscall TCommunications_Handler::CommGetCaps(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   int *piVar1;
    //     //   long lVar2;
    //     //   TDebuggingLog *this_00;
    //     //   TDebuggingLog *this_01;
    //     //   TDebuggingLog *this_02;
    //     //   TDebuggingLog *extraout_ECX;
    //     //   TDebuggingLog *extraout_ECX_00;
    //     //   TDebuggingLog *this_03;
    //     //   TDebuggingLog *extraout_ECX_01;
    //     //   TDebuggingLog *pTVar3;
    //     //   ulong unaff_ESI;
    //     //   undefined4 unaff_EDI;
    //     //   char *pcVar4;
    //     //   undefined4 uStack_34;
    //     //   DPCAPS DPCaps;
    //     //   
    //     //   piVar1 = DAT_0062c5ec;
    //     //   if (DAT_0062c5ec == (int *)0x0) {
    //     //     return -0x7fffbffb;
    //     //   }
    //     //   uStack_34 = 0;
    //     //   DPCaps.dwFlags = 0x28;
    //     //   DPCaps.dwSize = unaff_ESI;
    //     //   lVar2 = (**(code **)(*DAT_0062c5ec + 0x38))();
    //     //   RGE_Comm_Error::ShowReturn(this->Err,lVar2,s_Get_Caps);
    //     //   lVar2 = (**(code **)(*DAT_0062c5ec + 0x38))(DAT_0062c5ec,&uStack_34,1);
    //     //   RGE_Comm_Error::ShowReturn(this->Err,lVar2,s_Get_guaranteed_Caps);
    //     //   TDebuggingLog::Log(this_00,(char *)L,s____________Direct_Play_III_Capab);
    //     //   TDebuggingLog::Log((TDebuggingLog *)&DPCaps.dwFlags,(char *)L,s_Max_Buffer_Size____d,
    //     //                      &DPCaps.dwFlags);
    //     //   TDebuggingLog::Log(L,(char *)L,s_Max_Queue_Size_____d,uStack_34);
    //     //   TDebuggingLog::Log(this_01,(char *)L,s_Max_Players________d,unaff_EDI);
    //     //   TDebuggingLog::Log((TDebuggingLog *)DPCaps.dwSize,(char *)L,s_Baud_Rate__________d00,DPCaps.dwSize
    //     //                     );
    //     //   TDebuggingLog::Log(L,(char *)L,s_Latency____________d,DPCaps.dwFlags);
    //     //   TDebuggingLog::Log(this_02,(char *)L,s_Header_Length______d,DPCaps.dwMaxQueueSize);
    //     //   TDebuggingLog::Log((TDebuggingLog *)DPCaps.dwMaxPlayers,(char *)L,s_Timeout____________d,
    //     //                      DPCaps.dwMaxPlayers);
    //     //   this->ServiceTimeout = DPCaps.dwMaxPlayers;
    //     //   if (((uint)piVar1 & 0x20) == 0) {
    //     //     pcVar4 = s_NOT_Guaranteed_Optimized_;
    //     //     pTVar3 = extraout_ECX;
    //     //   }
    //     //   else {
    //     //     pcVar4 = s_Guaranteed_Optimized_;
    //     //     pTVar3 = L;
    //     //   }
    //     //   TDebuggingLog::Log(pTVar3,(char *)L,pcVar4);
    //     //   if (((uint)piVar1 & 2) == 0) {
    //     //     pcVar4 = s_Not_the_host_;
    //     //     pTVar3 = L;
    //     //   }
    //     //   else {
    //     //     pcVar4 = s_This_player_is_the_Session_Host_;
    //     //     pTVar3 = extraout_ECX_00;
    //     //   }
    //     //   TDebuggingLog::Log(pTVar3,(char *)L,pcVar4);
    //     //   if (((uint)piVar1 & 0x10) == 0) {
    //     //     pcVar4 = s_Not_optimized_for_keepalive_;
    //     //   }
    //     //   else {
    //     //     pcVar4 = s_Optimized_keepalive_detection_;
    //     //   }
    //     //   TDebuggingLog::Log(this_03,(char *)L,pcVar4);
    //     //   if (((uint)piVar1 & 0x40) == 0) {
    //     //     pcVar4 = s_NOT_Guaranteed_Service_;
    //     //     pTVar3 = extraout_ECX_01;
    //     //   }
    //     //   else {
    //     //     pcVar4 = s_Guaranteed_delivery_is_Supported;
    //     //     pTVar3 = L;
    //     //   }
    //     //   TDebuggingLog::Log(pTVar3,(char *)L,pcVar4);
    //     //   this->RGE_Guaranteed_Delivery = '\x01';
    //     //   return lVar2;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int TCommunications_Handler::SetMyGameOptions(char* param_2, ulong param_3) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042EB60
    this->FreeOptions();
    if (param_2 == nullptr || param_3 == 0) {
        this->PlayerOptions.DataSizeToFollow = 0;
        return 1;
    }
    this->OptionsData = (char*)::operator new((size_t)param_3, std::nothrow);
    if (this->OptionsData == nullptr) {
        this->PlayerOptions.DataSizeToFollow = 0;
        return 0;
    }
    memcpy(this->OptionsData, param_2, (size_t)param_3);
    this->PlayerOptions.DataSizeToFollow = param_3;
    this->PlayerOptions.NeedsToBeSent = 1;
    return 1;
}

void* TCommunications_Handler::GetMyGameOptions(ulong* param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042EBF0
    if (param_2 != nullptr) {
        *param_2 = this->PlayerOptions.DataSizeToFollow;
    }
    return this->OptionsData;
}

void TCommunications_Handler::SetHostPlayerNumber(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECC0
    this->PlayerOptions.HostPlayerNumber = param_2;
}

uint TCommunications_Handler::GetHostPlayerNumber(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECD0
    return this->PlayerOptions.HostPlayerNumber;
}

void TCommunications_Handler::DebugSessionInformation(DPSESSIONDESC2* param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042ECE0
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042ECE0
    // void DebugSessionInformation(TCommunications_Handler* this_, DPSESSIONDESC2* param_2) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: wszSPGuid */
    //     // /* public: void __thiscall TCommunications_Handler::DebugSessionInformation(struct DPSESSIONDESC2 *)
    //     //     */
    //     // 
    //     // void __thiscall
    //     // TCommunications_Handler::DebugSessionInformation
    //     //           (TCommunications_Handler *this,DPSESSIONDESC2 *param_1)
    //     // 
    //     // {
    //     //   uchar *this_00;
    //     //   TDebuggingLog *this_01;
    //     //   TDebuggingLog *pTVar1;
    //     //   TDebuggingLog *this_02;
    //     //   TDebuggingLog *this_03;
    //     //   TDebuggingLog *this_04;
    //     //   TDebuggingLog *this_05;
    //     //   TDebuggingLog *this_06;
    //     //   TDebuggingLog *this_07;
    //     //   ushort wszSPGuid [39];
    //     //   
    //     //   TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s___Information_in_DPSESSIONDESC2_);
    //     //   TDebuggingLog::Log((TDebuggingLog *)param_1->dwSize,(char *)L,s_Size_DPSESSIONDESC2___d,
    //     //                      (TDebuggingLog *)param_1->dwSize);
    //     //   TDebuggingLog::Log(L,(char *)L,s_Flags_________________d,param_1->dwFlags);
    //     //   TDebuggingLog::Log(this_01,(char *)L,s_Instance_guid__DATA1__u,(param_1->guidInstance).Data1);
    //     //   pTVar1 = (TDebuggingLog *)(uint)(param_1->guidInstance).Data2;
    //     //   TDebuggingLog::Log(pTVar1,(char *)L,s________________DATA2__d,pTVar1);
    //     //   TDebuggingLog::Log(L,(char *)L,s________________DATA3__d,(uint)(param_1->guidInstance).Data3);
    //     //   TDebuggingLog::Log(this_02,(char *)L,s________________DATA4__u,(param_1->guidInstance).Data4);
    //     //   StringFromGUID(&param_1->guidInstance,wszSPGuid + 2);
    //     //   TDebuggingLog::Log(this_03,(char *)L,s_Instance_GUID__str____s,wszSPGuid + 2);
    //     //   pTVar1 = (TDebuggingLog *)(param_1->guidApplication).Data1;
    //     //   TDebuggingLog::Log(pTVar1,(char *)L,s_Applicatn_guid_DATA1__u,pTVar1);
    //     //   TDebuggingLog::Log(L,(char *)L,s________________DATA2__d,(uint)(param_1->guidApplication).Data2);
    //     //   TDebuggingLog::Log(this_04,(char *)L,s________________DATA3__d,
    //     //                      (uint)(param_1->guidApplication).Data3);
    //     //   this_00 = (param_1->guidApplication).Data4;
    //     //   TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s________________DATA4__u,this_00);
    //     //   TDebuggingLog::Log(L,(char *)L,s_Max_Players___________d,param_1->dwMaxPlayers);
    //     //   TDebuggingLog::Log(this_05,(char *)L,s_Current_Players_______d,param_1->dwCurrentPlayers);
    //     //   TDebuggingLog::Log((TDebuggingLog *)param_1->dwReserved1,(char *)L,s_Reserved_1____________d,
    //     //                      (TDebuggingLog *)param_1->dwReserved1);
    //     //   TDebuggingLog::Log(L,(char *)L,s_Reserved_2____________d,param_1->dwReserved2);
    //     //   TDebuggingLog::Log(this_06,(char *)L,s_User_1________________d,param_1->dwUser1);
    //     //   TDebuggingLog::Log((TDebuggingLog *)param_1->dwUser2,(char *)L,s_User_2________________d,
    //     //                      (TDebuggingLog *)param_1->dwUser2);
    //     //   TDebuggingLog::Log(L,(char *)L,s_User_3________________d,param_1->dwUser3);
    //     //   TDebuggingLog::Log(this_07,(char *)L,s_User_4________________d,param_1->dwUser4);
    //     //   TDebuggingLog::Log(L,(char *)L,s______end____);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

void TCommunications_Handler::OutOfSync(int param_2, ulong param_3) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042EF60
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042EF60
    // void OutOfSync(TCommunications_Handler* this_, int param_2, ulong param_3) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: void __thiscall TCommunications_Handler::OutOfSync(int,unsigned long) */
    //     // 
    //     // void __thiscall
    //     // TCommunications_Handler::OutOfSync(TCommunications_Handler *this,int param_1,ulong param_2)
    //     // 
    //     // {
    //     //   this->OutOfSyncFlag = param_1;
    //     //   this->dwStopTime = param_2;
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

int TCommunications_Handler::SendZoneMessage(char* param_2, ulong param_3) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042EF80
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042EF80
    // int SendZoneMessage(TCommunications_Handler* this_, char* param_2, ulong param_3) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: int __thiscall TCommunications_Handler::SendZoneMessage(char *,unsigned long) */
    //     // 
    //     // int __thiscall
    //     // TCommunications_Handler::SendZoneMessage(TCommunications_Handler *this,char *param_1,ulong param_2)
    //     // 
    //     // {
    //     //   int iVar1;
    //     //   long lVar2;
    //     //   TDebuggingLog *this_00;
    //     //   TDebuggingLog *this_01;
    //     //   
    //     //   iVar1 = IsLobbyLaunched(this);
    //     //   if (iVar1 == 0) {
    //     //     TDebuggingLog::Log(this_00,(char *)L,s_NOT_LOBBY_LAUNCHED___EXITING);
    //     //     return 0;
    //     //   }
    //     //   TDebuggingLog::Log(L,(char *)L,s_Sending_zone_message_);
    //     //   TDebuggingLog::Log(this_01,(char *)L,s___>TX_ZONE_MSG___u_,param_2);
    //     //   lVar2 = RGE_Lobby::SendZoneMessage
    //     //                     (this->Lobby,param_1,param_2,rge_base_game->prog_info->zone_guid);
    //     //   if (lVar2 == 0) {
    //     //     return 1;
    //     //   }
    //     //   RGE_Comm_Error::ShowReturn(this->Err,lVar2,s_SendGameOptions);
    //     //   return 0;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

void TCommunications_Handler::ForcePlayerEnumeration(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042F110
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042F110
    // void ForcePlayerEnumeration(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: void __thiscall TCommunications_Handler::ForcePlayerEnumeration(void) */
    //     // 
    //     // void __thiscall TCommunications_Handler::ForcePlayerEnumeration(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Force_Calling_enumeration_of_pla);
    //     //   (**(code **)(*DAT_0062c5ec + 0x30))(DAT_0062c5ec,0,EnumPlayersCallback2,this,0);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

void TCommunications_Handler::ForcePlayerDestroyAndCreate(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042F140
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042F140
    // void ForcePlayerDestroyAndCreate(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* public: void __thiscall TCommunications_Handler::ForcePlayerDestroyAndCreate(void) */
    //     // 
    //     // void __thiscall TCommunications_Handler::ForcePlayerDestroyAndCreate(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   TDebuggingLog *this_00;
    //     //   
    //     //   TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Force_Self_player_destroy_and_cr);
    //     //   (**(code **)(*DAT_0062c5ec + 0x24))(DAT_0062c5ec,DAT_0062cf04);
    //     //   DAT_0062cf04 = 0;
    //     //   AddSelfPlayer(this);
    //     //   TDebuggingLog::Log(this_00,(char *)L,s_Create_called_);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

void TCommunications_Handler::ForceNameChange(void) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042F190
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042F190
    // void ForceNameChange(TCommunications_Handler* this_) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* WARNING: Variable defined which should be unmapped: dpn */
    //     // /* public: void __thiscall TCommunications_Handler::ForceNameChange(void) */
    //     // 
    //     // void __thiscall TCommunications_Handler::ForceNameChange(TCommunications_Handler *this)
    //     // 
    //     // {
    //     //   DPNAME dpn;
    //     //   char test [32];
    //     //   
    //     //   dpn.dwSize = (ulong)s_Force_Name_Change;
    //     //   TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Force_Name_Change);
    //     //   test[0xc] = (char)DAT_005832c4;
    //     //   test[0xd] = DAT_005832c4._1_1_;
    //     //   test[0xe] = DAT_005832c4._2_1_;
    //     //   test[0xf] = DAT_005832c4._3_1_;
    //     //   test[8] = (char)DAT_005832c0;
    //     //   test[9] = DAT_005832c0._1_1_;
    //     //   test[10] = DAT_005832c0._2_1_;
    //     //   test[0xb] = DAT_005832c0._3_1_;
    //     //   test[0x13] = '\0';
    //     //   test[0x14] = '\0';
    //     //   test[0x15] = '\0';
    //     //   test[0x16] = '\0';
    //     //   test[0x17] = '\0';
    //     //   test[0x18] = '\0';
    //     //   test[0x19] = '\0';
    //     //   test[0x1a] = '\0';
    //     //   test[0x12] = DAT_005832ca;
    //     //   test[0x1b] = '\0';
    //     //   test[0x1c] = '\0';
    //     //   test[0x1d] = '\0';
    //     //   test[0x1e] = '\0';
    //     //   test._0_4_ = test + 4;
    //     //   test[4] = (char)s_TEMPORARY_NAME;
    //     //   test[5] = s_TEMPORARY_NAME._1_1_;
    //     //   test[6] = s_TEMPORARY_NAME._2_1_;
    //     //   test[7] = s_TEMPORARY_NAME._3_1_;
    //     //   stack0xfffffffb = 0;
    //     //   test[0x10] = (char)DAT_005832c8;
    //     //   test[0x11] = DAT_005832c8._1_1_;
    //     //   dpn.dwSize = 2;
    //     //   dpn.field3_0xc.lpszLongName = (ushort *)(test + 4);
    //     //   dpn.dwFlags = 0x10;
    //     //   (**(code **)(*DAT_0062c5ec + 0x78))(DAT_0062c5ec,DAT_0062cf04,&dpn.dwFlags,2);
    //     //   return;
    //     // }
    //     // 
    //     // 
    // }
    // 
}

void TCommunications_Handler::SetSpeedV1(ulong param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F230
    if (this->Speed != nullptr) {
        this->Speed->SetV1(param_2);
    }
}

void TCommunications_Handler::SetSpeedV2(ulong param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F250
    if (this->Speed != nullptr) {
        this->Speed->SetV2(param_2);
    }
}

int StringFromGUID(_GUID* param_1, ushort* param_2) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042EC40
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042EC40
    // int StringFromGUID(_GUID* param_1, ushort* param_2) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* int __cdecl StringFromGUID(struct _GUID *,unsigned short *) */
    //     // 
    //     // int __cdecl StringFromGUID(_GUID *param_1,ushort *param_2)
    //     // 
    //     // {
    //     //   wchar_t *pwVar1;
    //     //   wchar_t *pwVar2;
    //     //   uint uVar3;
    //     //   
    //     //   *param_2 = 0x7b;
    //     //   pwVar1 = (wchar_t *)(param_2 + 1);
    //     //   uVar3 = 0;
    //     //   do {
    //     //     if ((&DAT_0056f218)[uVar3] == 0x2d) {
    //     //       *pwVar1 = L'-';
    //     //       pwVar2 = pwVar1;
    //     //     }
    //     //     else {
    //     //       pwVar2 = pwVar1 + 1;
    //     //       *pwVar1 = L"0123456789ABCDEF"[param_1->Data4[(byte)(&DAT_0056f218)[uVar3] - 8] >> 4];
    //     //       *pwVar2 = L"0123456789ABCDEF"[param_1->Data4[(byte)(&DAT_0056f218)[uVar3] - 8] & 0xf];
    //     //     }
    //     //     pwVar1 = pwVar2 + 1;
    //     //     uVar3 = uVar3 + 1;
    //     //   } while (uVar3 < 0x14);
    //     //   *pwVar1 = L'}';
    //     //   pwVar2[2] = L'\0';
    //     //   return 0x26;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

int EnumPlayersCallback2(ulong param_1, ulong param_2, DPNAME* param_3, ulong param_4, void* param_5) {
    // TODO: partial transliteration. Source of truth: com_hand.cpp.decomp @ 0x0042F040
    // --- Ghidra decompiler output kept inline for parity audit ---
    // // Offset: 0x0042F040
    // int EnumPlayersCallback2(ulong param_1, ulong param_2, DPNAME* param_3, ulong param_4, void* param_5) {
    //     // --- Ghidra decompiler output ---
    //     // 
    //     // /* int __stdcall EnumPlayersCallback2(unsigned long,unsigned long,struct DPNAME *,unsigned long,void
    //     //    *) */
    //     // 
    //     // int EnumPlayersCallback2(ulong param_1,ulong param_2,DPNAME *param_3,ulong param_4,void *param_5)
    //     // 
    //     // {
    //     //   uint uVar1;
    //     //   ulong *puVar2;
    //     //   TDebuggingLog *this;
    //     //   
    //     //   if (param_1 != 0) {
    //     //     uVar1 = (uint)*(ushort *)((int)param_5 + 0x1712);
    //     //     if (uVar1 <= *(ushort *)((int)param_5 + 0x1710)) {
    //     //       puVar2 = (ulong *)((int)param_5 + uVar1 * 4 + 0x1564);
    //     //       do {
    //     //         if (*puVar2 == param_1) goto LAB_0042f07f;
    //     //         uVar1 = uVar1 + 1;
    //     //         puVar2 = puVar2 + 1;
    //     //       } while ((int)uVar1 <= (int)(uint)*(ushort *)((int)param_5 + 0x1710));
    //     //     }
    //     //   }
    //     //   uVar1 = 0;
    //     // LAB_0042f07f:
    //     //   sprintf(&DAT_0062c5f0,s_ENUM__d_name__s_id__d,param_1,(param_3->field2_0x8).lpszShortName,uVar1);
    //     //   TDebuggingLog::Log(L,(char *)L,s_ENUM_DEBUG___s,&DAT_0062c5f0);
    //     //   TDebuggingLog::Log(this,(char *)L,s_FORCEENUM__d_name__s_id__d,param_1,
    //     //                      (param_3->field2_0x8).lpszShortName,uVar1);
    //     //   TDebuggingLog::Log(L,(char *)L,s_FILL_PLAYER_INFORMATION_);
    //     //   TCommunications_Handler::UpdatePlayerInformation
    //     //             ((TCommunications_Handler *)param_5,param_1,(param_3->field2_0x8).lpszShortNameA,
    //     //              (param_3->field3_0xc).lpszLongNameA);
    //     //   return 1;
    //     // }
    //     // 
    //     // 
    // }
    // 
    return 0;
}

// BEGIN Task 222 decomp reference bundle
// Inline preserved decomp snippets for implemented wrappers (audit trail).
// ---- WaitingOnNamedInfo ----
// // Offset: 0x00425780
// char* WaitingOnNamedInfo(TCommunications_Handler* this_, uint param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: char * __thiscall TCommunications_Handler::WaitingOnNamedInfo(unsigned int) */
//     // 
//     // char * __thiscall
//     // TCommunications_Handler::WaitingOnNamedInfo(TCommunications_Handler *this,uint param_1)
//     // 
//     // {
//     //   char *pcVar1;
//     //   char *pcVar2;
//     //   char *pcVar3;
//     //   ulong uVar4;
//     //   int iVar5;
//     //   
//     //   pcVar1 = this->TBuff;
//     //   pcVar2 = WaitingOnInfo(this,param_1);
//     //   pcVar3 = GetPlayerName(this,param_1);
//     //   sprintf(pcVar1,s___d___s____s,param_1,pcVar3,pcVar2);
//     //   uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x8e);
//     //   iVar5 = uVar4 - this->LastPlayerCommunication[param_1];
//     //   uVar4 = this->LastTurnAck[param_1];
//     //   pcVar2 = WaitingOnInfo(this,param_1);
//     //   pcVar3 = GetPlayerName(this,param_1);
//     //   sprintf(pcVar1,s___d___s____s__QUIET__d_msec__T__,param_1,pcVar3,pcVar2,iVar5,uVar4);
//     //   return pcVar1;
//     // }
//     // 
//     // 
// }
// 
//
// ---- WaitingOnInfo ----
// // Offset: 0x00425800
// char* WaitingOnInfo(TCommunications_Handler* this_, uint param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: char * __thiscall TCommunications_Handler::WaitingOnInfo(unsigned int) */
//     // 
//     // char * __thiscall TCommunications_Handler::WaitingOnInfo(TCommunications_Handler *this,uint param_1)
//     // 
//     // {
//     //   int iVar1;
//     //   
//     //   iVar1 = IsPlayerComputer(this,param_1);
//     //   if (iVar1 != 0) {
//     //                     /* language.dll match for 0x4b1: "Computer" */
//     //     (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b1,0x62c588,0x20);
//     //     return &UNK_0062c585.field_0x3;
//     //   }
//     //   iVar1 = IsPlayerHuman(this,param_1);
//     //   if (iVar1 == 0) {
//     //                     /* language.dll match for 0x4b2: "Empty" */
//     //     (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b2,0x62c588,0x20);
//     //     return &UNK_0062c585.field_0x3;
//     //   }
//     //   if (this->LastTurnAck[param_1] < 4) {
//     //                     /* language.dll match for 0x4b3: "Loading" */
//     //     (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b3,0x62c588,0x20);
//     //     return &UNK_0062c585.field_0x3;
//     //   }
//     //   if (this->LastTurnAck[param_1] < this->current_turn) {
//     //                     /* language.dll match for 0x4b4: "Waiting" */
//     //     (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b4,0x62c588,0x20);
//     //     return &UNK_0062c585.field_0x3;
//     //   }
//     //                     /* language.dll match for 0x4b0: "Ready" */
//     //   (**(code **)(rge_base_game->_padding_ + 0x20))(0x4b0,0x62c588,0x20);
//     //   return &UNK_0062c585.field_0x3;
//     // }
//     // 
//     // 
// }
// 
//
// ---- StopIfSyncFail ----
// // Offset: 0x004258E0
// void StopIfSyncFail(TCommunications_Handler* this_, int param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::StopIfSyncFail(int) */
//     // 
//     // void __thiscall TCommunications_Handler::StopIfSyncFail(TCommunications_Handler *this,int param_1)
//     // 
//     // {
//     //   RGE_Communications_Synchronize::SetDialogOnFail(this->Sync,param_1);
//     //   RGE_Communications_Synchronize::SetStopOnFail(this->Sync,param_1);
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- ShowSyncChatMsgs ----
// // Offset: 0x00425910
// void ShowSyncChatMsgs(TCommunications_Handler* this_, int param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::ShowSyncChatMsgs(int) */
//     // 
//     // void __thiscall TCommunications_Handler::ShowSyncChatMsgs(TCommunications_Handler *this,int param_1)
//     // 
//     // {
//     //   RGE_Communications_Synchronize::SendChatMsgsAtChecksum(this->Sync,param_1);
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- DropPacketsIntentionally ----
// // Offset: 0x00425930
// void DropPacketsIntentionally(TCommunications_Handler* this_, int param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::DropPacketsIntentionally(int) */
//     // 
//     // void __thiscall
//     // TCommunications_Handler::DropPacketsIntentionally(TCommunications_Handler *this,int param_1)
//     // 
//     // {
//     //   this->IntentionallyDropPackets = param_1;
//     //   if (param_1 != 0) {
//     //     TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_DROPPING_PACKETS_INTENTIONALLY__);
//     //   }
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetStepMode ----
// // Offset: 0x00425960
// void SetStepMode(TCommunications_Handler* this_, int param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetStepMode(int) */
//     // 
//     // void __thiscall TCommunications_Handler::SetStepMode(TCommunications_Handler *this,int param_1)
//     // 
//     // {
//     //   this->StepMode = param_1;
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetSpeedControl ----
// // Offset: 0x00425970
// void SetSpeedControl(TCommunications_Handler* this_, int param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetSpeedControl(int) */
//     // 
//     // void __thiscall TCommunications_Handler::SetSpeedControl(TCommunications_Handler *this,int param_1)
//     // 
//     // {
//     //   RGE_Communications_Speed::EnableSpeedControl(this->Speed,param_1);
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- Step ----
// // Offset: 0x00425A20
// void Step(TCommunications_Handler* this_, int param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::Step(int) */
//     // 
//     // void __thiscall TCommunications_Handler::Step(TCommunications_Handler *this,int param_1)
//     // 
//     // {
//     //   TEST(this);
//     //   this->Steps = this->Steps + param_1;
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- HasKicked ----
// // Offset: 0x00426D40
// int HasKicked(TCommunications_Handler* this_, uint param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::HasKicked(unsigned int) */
//     // 
//     // int __thiscall TCommunications_Handler::HasKicked(TCommunications_Handler *this,uint param_1)
//     // 
//     // {
//     //   return this->Kicked[param_1];
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetPlayerStopTurn ----
// // Offset: 0x004286F0
// void SetPlayerStopTurn(TCommunications_Handler* this_, uint param_2, ulong param_3) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* protected: void __thiscall TCommunications_Handler::SetPlayerStopTurn(unsigned int,unsigned long)
//     //     */
//     // 
//     // void __thiscall
//     // TCommunications_Handler::SetPlayerStopTurn(TCommunications_Handler *this,uint param_1,ulong param_2)
//     // 
//     // {
//     //   this->PlayerStopTurn[param_1] = param_2;
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- StoreIncoming ----
// // Offset: 0x0042A180
// int StoreIncoming(TCommunications_Handler* this_, uint param_2, char* param_3, uint param_4, ulong param_5, ulong param_6) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::StoreIncoming(unsigned int,char *,unsigned
//     //    int,unsigned long,unsigned long) */
//     // 
//     // int __thiscall
//     // TCommunications_Handler::StoreIncoming
//     //           (TCommunications_Handler *this,uint param_1,char *param_2,uint param_3,ulong param_4,
//     //           ulong param_5)
//     // 
//     // {
//     //   ulong *puVar1;
//     //   uint *puVar2;
//     //   char *pcVar3;
//     //   undefined4 *puVar4;
//     //   uint uVar5;
//     //   uint uVar6;
//     //   uint uVar7;
//     //   TDebuggingLog *this_00;
//     //   int iVar8;
//     //   HOLDER *pHVar9;
//     //   int iVar10;
//     //   
//     //   if (param_3 == 0) {
//     //     TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s____StoreIncoming_called_for_zero);
//     //   }
//     //   pHVar9 = this->OnHold;
//     //   uVar5 = 0;
//     //   puVar1 = &pHVar9->dcoFromID;
//     //   while ((puVar1[-2] != param_1 || (*puVar1 != param_4))) {
//     //     uVar5 = uVar5 + 1;
//     //     puVar1 = puVar1 + 6;
//     //     if (0x1f5 < uVar5) {
//     //       uVar5 = 0;
//     //       puVar2 = &pHVar9->Length;
//     //       while ((*puVar2 != 0 || (param_3 == 0))) {
//     //         uVar5 = uVar5 + 1;
//     //         puVar2 = puVar2 + 6;
//     //         if (500 < uVar5) {
//     //           TDebuggingLog::Log(L,(char *)L,s_____DID_NOT_STORE___);
//     //           if (0x1eb < uVar5) {
//     //             TDebuggingLog::Log(this_00,(char *)L,s_HOLD_FULL_WARNING___COUNT__d,uVar5);
//     //             iVar10 = 0;
//     //             uVar5 = 0;
//     //             do {
//     //               puVar4 = (undefined4 *)((int)&this->OnHold->HoldMsg + uVar5);
//     //               if (puVar4[2] != 0) {
//     //                 iVar8 = (int)*(char *)*puVar4;
//     //                 TDebuggingLog::Log(L,(char *)L,s_S__d__Ser__d_FromID__d_Len__d__C,iVar10,puVar4[1],
//     //                                    puVar4[3],puVar4[2],iVar8,iVar8,(int)((char *)*puVar4)[1]);
//     //               }
//     //               uVar5 = uVar5 + 0x18;
//     //               iVar10 = iVar10 + 1;
//     //             } while (uVar5 < 0x2ef8);
//     //           }
//     //           return 1;
//     //         }
//     //       }
//     //       pHVar9[uVar5].Length = param_3;
//     //       pHVar9 = this->OnHold + uVar5;
//     //       pcVar3 = (char *)operator_new(pHVar9->Length);
//     //       pHVar9->HoldMsg = pcVar3;
//     //       if (pcVar3 != (char *)0x0) {
//     //         uVar7 = pHVar9->Length;
//     //         for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
//     //           *(undefined4 *)pcVar3 = *(undefined4 *)param_2;
//     //           param_2 = param_2 + 4;
//     //           pcVar3 = pcVar3 + 4;
//     //         }
//     //         for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
//     //           *pcVar3 = *param_2;
//     //           param_2 = param_2 + 1;
//     //           pcVar3 = pcVar3 + 1;
//     //         }
//     //         pHVar9->Length = param_3;
//     //       }
//     //       this->OnHold[uVar5].Serial = param_1;
//     //       this->OnHold[uVar5].dcoFromID = param_4;
//     //       this->OnHold[uVar5].dcoReceiveID = param_5;
//     //       return 1;
//     //     }
//     //   }
//     //   TDebuggingLog::Log(L,(char *)L,s_Future_Ser__d_previously_stored_,param_1,uVar5);
//     //   return 1;
//     // }
//     // 
//     // 
// }
// 
//
// ---- TXAcknowledgeMessage ----
// // Offset: 0x0042A540
// int TXAcknowledgeMessage(TCommunications_Handler* this_, uint param_2, uint param_3) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::TXAcknowledgeMessage(unsigned int,unsigned int)
//     //     */
//     // 
//     // int __thiscall
//     // TCommunications_Handler::TXAcknowledgeMessage
//     //           (TCommunications_Handler *this,uint param_1,uint param_2)
//     // 
//     // {
//     //   undefined1 *puVar1;
//     //   ulong uVar2;
//     //   int iVar3;
//     //   ulong uVar4;
//     //   TDebuggingLog *this_00;
//     //   
//     //   if (this->RGE_Guaranteed_Delivery == '\0') {
//     //     TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s__RGEGTD_Ack);
//     //     return 0;
//     //   }
//     //   puVar1 = (undefined1 *)operator_new(8);
//     //   *puVar1 = 0x41;
//     //   *(uint *)(puVar1 + 4) = param_1;
//     //   if (DAT_0062cf04 == 0) {
//     //     TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s____BAD_DCOID_0_NO_TX);
//     //     return 0;
//     //   }
//     //   uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd53);
//     //   iVar3 = (**(code **)(*DAT_0062c5ec + 0x68))
//     //                     (DAT_0062c5ec,DAT_0062cf04,(this->PlayerOptions).dcoID[param_2],0,puVar1,8);
//     //   uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0xd5e);
//     //   if (0x32 < uVar4 - uVar2) {
//     //     TDebuggingLog::Log(this_00,(char *)L,s____TXAcknowledgeMessage_slow____,uVar4 - uVar2);
//     //   }
//     //   this->TXPacketLength = this->TXPacketLength + 8;
//     //   operator_delete(puVar1);
//     //   if (iVar3 == 0) {
//     //     return 1;
//     //   }
//     //   RGE_Comm_Error::ShowReturn(this->Err,iVar3,s_GTD_ACK);
//     //   return 0;
//     // }
//     // 
//     // 
// }
// 
//
// ---- GetNextSequence ----
// // Offset: 0x0042B200
// uchar GetNextSequence(TCommunications_Handler* this_, ulong param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: unsigned char __thiscall TCommunications_Handler::GetNextSequence(unsigned long) */
//     // 
//     // uchar __thiscall
//     // TCommunications_Handler::GetNextSequence(TCommunications_Handler *this,ulong param_1)
//     // 
//     // {
//     //   byte bVar1;
//     //   
//     //   if (param_1 != DAT_0062cf30) {
//     //     DAT_0062cf30 = param_1;
//     //     DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,1);
//     //     return '\x01';
//     //   }
//     //   bVar1 = (char)DAT_0062cf2c + 1;
//     //   DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,bVar1);
//     //   if (bVar1 == 0xff) {
//     //     TDebuggingLog::Log(L,(char *)L,s____Too_many_commands_in_one_comm,0xff);
//     //     return '\0';
//     //   }
//     //   if (((this->PlayerOptions).ProgramState == COMM_STATE_PAUSE) && (100 < bVar1)) {
//     //     DAT_0062cf2c = CONCAT31(DAT_0062cf2c._1_3_,100);
//     //     bVar1 = 100;
//     //   }
//     //   return bVar1;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetRandomSeed ----
// // Offset: 0x0042CA20
// void SetRandomSeed(TCommunications_Handler* this_, int param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetRandomSeed(int) */
//     // 
//     // void __thiscall TCommunications_Handler::SetRandomSeed(TCommunications_Handler *this,int param_1)
//     // 
//     // {
//     //   ulong uVar1;
//     //   
//     //   if (this->MeHost != 0) {
//     //     if (param_1 == -1) {
//     //       uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1320);
//     //       debug_srand(s_C__msdev_work_age1_x1_Com_hand_c,0x1320,uVar1);
//     //       param_1 = debug_rand(s_C__msdev_work_age1_x1_Com_hand_c,0x1321);
//     //     }
//     //     (this->PlayerOptions).RandomSeed = param_1;
//     //     (this->PlayerOptions).NeedsToBeSent = '\x01';
//     //     SendSharedData(this,0);
//     //   }
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- GetActivePlayerCount ----
// // Offset: 0x0042CC90
// int GetActivePlayerCount(TCommunications_Handler* this_) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::GetActivePlayerCount(void) */
//     // 
//     // int __thiscall TCommunications_Handler::GetActivePlayerCount(TCommunications_Handler *this)
//     // 
//     // {
//     //   int iVar1;
//     //   int iVar2;
//     //   uint uVar3;
//     //   
//     //   uVar3 = 0;
//     //   iVar2 = 0;
//     //   do {
//     //     iVar1 = IsPlayerHuman(this,uVar3);
//     //     if ((iVar1 != 0) || (iVar1 = IsPlayerComputer(this,uVar3), iVar1 != 0)) {
//     //       iVar2 = iVar2 + 1;
//     //     }
//     //     uVar3 = uVar3 + 1;
//     //   } while ((int)uVar3 <= (int)(uint)this->MaxGamePlayers);
//     //   return iVar2;
//     // }
//     // 
//     // 
// }
// 
//
// ---- IsPlayerComputer ----
// // Offset: 0x0042CD10
// int IsPlayerComputer(TCommunications_Handler* this_, uint param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::IsPlayerComputer(unsigned int) */
//     // 
//     // int __thiscall TCommunications_Handler::IsPlayerComputer(TCommunications_Handler *this,uint param_1)
//     // 
//     // {
//     //   if ((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) {
//     //     return (uint)((this->PlayerOptions).Humanity[param_1] == ME_COMPUTER);
//     //   }
//     //   return 0;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetGameTitle ----
// // Offset: 0x0042D3B0
// int SetGameTitle(TCommunications_Handler* this_, char* param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::SetGameTitle(char *) */
//     // 
//     // int __thiscall TCommunications_Handler::SetGameTitle(TCommunications_Handler *this,char *param_1)
//     // 
//     // {
//     //   sprintf(this->MyGameTitle,s__s___s_,param_1,this->MyFriendlyName);
//     //   return 1;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetMyPlayerName ----
// // Offset: 0x0042D3E0
// void SetMyPlayerName(TCommunications_Handler* this_, char* param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetMyPlayerName(char *) */
//     // 
//     // void __thiscall
//     // TCommunications_Handler::SetMyPlayerName(TCommunications_Handler *this,char *param_1)
//     // 
//     // {
//     //   char cVar1;
//     //   uint uVar2;
//     //   uint uVar3;
//     //   char *pcVar4;
//     //   char *pcVar5;
//     //   
//     //   uVar2 = 0xffffffff;
//     //   do {
//     //     pcVar4 = param_1;
//     //     if (uVar2 == 0) break;
//     //     uVar2 = uVar2 - 1;
//     //     pcVar4 = param_1 + 1;
//     //     cVar1 = *param_1;
//     //     param_1 = pcVar4;
//     //   } while (cVar1 != '\0');
//     //   uVar2 = ~uVar2;
//     //   pcVar4 = pcVar4 + -uVar2;
//     //   pcVar5 = this->MyFriendlyName;
//     //   for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
//     //     *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
//     //     pcVar4 = pcVar4 + 4;
//     //     pcVar5 = pcVar5 + 4;
//     //   }
//     //   for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
//     //     *pcVar5 = *pcVar4;
//     //     pcVar4 = pcVar4 + 1;
//     //     pcVar5 = pcVar5 + 1;
//     //   }
//     //   uVar2 = 0xffffffff;
//     //   pcVar4 = &s_Optional_Information;
//     //   do {
//     //     pcVar5 = pcVar4;
//     //     if (uVar2 == 0) break;
//     //     uVar2 = uVar2 - 1;
//     //     pcVar5 = pcVar4 + 1;
//     //     cVar1 = *pcVar4;
//     //     pcVar4 = pcVar5;
//     //   } while (cVar1 != '\0');
//     //   uVar2 = ~uVar2;
//     //   pcVar4 = pcVar5 + -uVar2;
//     //   pcVar5 = this->MyFormalName;
//     //   for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
//     //     *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
//     //     pcVar4 = pcVar4 + 4;
//     //     pcVar5 = pcVar5 + 4;
//     //   }
//     //   for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
//     //     *pcVar5 = *pcVar4;
//     //     pcVar4 = pcVar4 + 1;
//     //     pcVar5 = pcVar5 + 1;
//     //   }
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetApplicationGUID ----
// // Offset: 0x0042DEA0
// void SetApplicationGUID(TCommunications_Handler* this_, _GUID param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetApplicationGUID(struct _GUID) */
//     // 
//     // void __thiscall
//     // TCommunications_Handler::SetApplicationGUID(TCommunications_Handler *this,_GUID param_1)
//     // 
//     // {
//     //   (this->ApplicationGUID).Data1 = param_1.Data1;
//     //   (this->ApplicationGUID).Data2 = param_1.Data2;
//     //   (this->ApplicationGUID).Data3 = param_1.Data3;
//     //   *(undefined4 *)(this->ApplicationGUID).Data4 = param_1.Data4._0_4_;
//     //   *(undefined4 *)((this->ApplicationGUID).Data4 + 4) = param_1.Data4._4_4_;
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetServiceGUID ----
// // Offset: 0x0042DEE0
// void SetServiceGUID(TCommunications_Handler* this_, _GUID param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetServiceGUID(struct _GUID) */
//     // 
//     // void __thiscall TCommunications_Handler::SetServiceGUID(TCommunications_Handler *this,_GUID param_1)
//     // 
//     // {
//     //   (this->ServiceGUID).Data1 = param_1.Data1;
//     //   (this->ServiceGUID).Data2 = param_1.Data2;
//     //   (this->ServiceGUID).Data3 = param_1.Data3;
//     //   *(undefined4 *)(this->ServiceGUID).Data4 = param_1.Data4._0_4_;
//     //   *(undefined4 *)((this->ServiceGUID).Data4 + 4) = param_1.Data4._4_4_;
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetSessionGUID ----
// // Offset: 0x0042DF10
// void SetSessionGUID(TCommunications_Handler* this_, _GUID param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetSessionGUID(struct _GUID) */
//     // 
//     // void __thiscall TCommunications_Handler::SetSessionGUID(TCommunications_Handler *this,_GUID param_1)
//     // 
//     // {
//     //   (this->SessionGUID).Data1 = param_1.Data1;
//     //   (this->SessionGUID).Data2 = param_1.Data2;
//     //   (this->SessionGUID).Data3 = param_1.Data3;
//     //   *(undefined4 *)(this->SessionGUID).Data4 = param_1.Data4._0_4_;
//     //   *(undefined4 *)((this->SessionGUID).Data4 + 4) = param_1.Data4._4_4_;
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- IsPlayerReady ----
// // Offset: 0x0042E580
// int IsPlayerReady(TCommunications_Handler* this_, uint param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::IsPlayerReady(unsigned int) */
//     // 
//     // int __thiscall TCommunications_Handler::IsPlayerReady(TCommunications_Handler *this,uint param_1)
//     // 
//     // {
//     //   if ((param_1 != 0) && (param_1 <= this->MaxGamePlayers)) {
//     //     return (this->PlayerOptions).PlayerReady[param_1];
//     //   }
//     //   return 0;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetHostPlayerNumber ----
// // Offset: 0x0042ECC0
// void SetHostPlayerNumber(TCommunications_Handler* this_, uint param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* protected: void __thiscall TCommunications_Handler::SetHostPlayerNumber(unsigned int) */
//     // 
//     // void __thiscall
//     // TCommunications_Handler::SetHostPlayerNumber(TCommunications_Handler *this,uint param_1)
//     // 
//     // {
//     //   (this->PlayerOptions).HostPlayerNumber = param_1;
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- GetHostPlayerNumber ----
// // Offset: 0x0042ECD0
// uint GetHostPlayerNumber(TCommunications_Handler* this_) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: unsigned int __thiscall TCommunications_Handler::GetHostPlayerNumber(void) */
//     // 
//     // uint __thiscall TCommunications_Handler::GetHostPlayerNumber(TCommunications_Handler *this)
//     // 
//     // {
//     //   return (this->PlayerOptions).HostPlayerNumber;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetSpeedV1 ----
// // Offset: 0x0042F230
// void SetSpeedV1(TCommunications_Handler* this_, ulong param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetSpeedV1(unsigned long) */
//     // 
//     // void __thiscall TCommunications_Handler::SetSpeedV1(TCommunications_Handler *this,ulong param_1)
//     // 
//     // {
//     //   RGE_Communications_Speed::SetV1(this->Speed,param_1);
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetSpeedV2 ----
// // Offset: 0x0042F250
// void SetSpeedV2(TCommunications_Handler* this_, ulong param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void __thiscall TCommunications_Handler::SetSpeedV2(unsigned long) */
//     // 
//     // void __thiscall TCommunications_Handler::SetSpeedV2(TCommunications_Handler *this,ulong param_1)
//     // 
//     // {
//     //   RGE_Communications_Speed::SetV2(this->Speed,param_1);
//     //   return;
//     // }
//     // 
//     // 
// }
// 
//
// ---- GetCommStateStr ----
// // Offset: 0x0042CB20
// char* GetCommStateStr(TCommunications_Handler* this_) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: char * __thiscall TCommunications_Handler::GetCommStateStr(void) */
//     // 
//     // char * __thiscall TCommunications_Handler::GetCommStateStr(TCommunications_Handler *this)
//     // 
//     // {
//     //   return (char *)0x0;
//     // }
//     // 
//     // 
// }
// 
//
// ---- GetReadyPlayerStr ----
// // Offset: 0x0042CB30
// char* GetReadyPlayerStr(TCommunications_Handler* this_) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: char * __thiscall TCommunications_Handler::GetReadyPlayerStr(void) */
//     // 
//     // char * __thiscall TCommunications_Handler::GetReadyPlayerStr(TCommunications_Handler *this)
//     // 
//     // {
//     //   char cVar1;
//     //   uint uVar2;
//     //   uint uVar3;
//     //   PLAYERHUMANITY *pPVar4;
//     //   char *pcVar5;
//     //   char *pcVar6;
//     //   
//     //   uVar2 = 0xffffffff;
//     //   pcVar5 = &s_Ready_________________________;
//     //   do {
//     //     pcVar6 = pcVar5;
//     //     if (uVar2 == 0) break;
//     //     uVar2 = uVar2 - 1;
//     //     pcVar6 = pcVar5 + 1;
//     //     cVar1 = *pcVar5;
//     //     pcVar5 = pcVar6;
//     //   } while (cVar1 != '\0');
//     //   uVar2 = ~uVar2;
//     //   pcVar5 = pcVar6 + -uVar2;
//     //   pcVar6 = (char *)&DAT_0062c5b0;
//     //   for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
//     //     *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
//     //     pcVar5 = pcVar5 + 4;
//     //     pcVar6 = pcVar6 + 4;
//     //   }
//     //   uVar3 = 1;
//     //   for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
//     //     *pcVar6 = *pcVar5;
//     //     pcVar5 = pcVar5 + 1;
//     //     pcVar6 = pcVar6 + 1;
//     //   }
//     //   if (this->MaxGamePlayers != 0) {
//     //     pPVar4 = (this->PlayerOptions).Humanity;
//     //     do {
//     //       pPVar4 = pPVar4 + 1;
//     //       if (pPVar4[0x13] < this->current_turn) {
//     //         switch(*pPVar4) {
//     //         case ME_ABSENT:
//     //           (&UNK_0062c5b6)[uVar3] = 0x2d;
//     //           break;
//     //         default:
//     //           (&UNK_0062c5b6)[uVar3] = 0x3f;
//     //           break;
//     //         case ME_HUMAN:
//     //           (&UNK_0062c5b6)[uVar3] = 0x57;
//     //           break;
//     //         case ME_COMPUTER:
//     //           (&UNK_0062c5b6)[uVar3] = 0x43;
//     //           break;
//     //         case ME_CYBORG:
//     //           (&UNK_0062c5b6)[uVar3] = 0x58;
//     //           break;
//     //         case ME_VIEWONLY:
//     //           (&UNK_0062c5b6)[uVar3] = 0x56;
//     //         }
//     //       }
//     //       else {
//     //         (&UNK_0062c5b6)[uVar3] = 0x41;
//     //       }
//     //       uVar3 = uVar3 + 1;
//     //     } while (uVar3 <= this->MaxGamePlayers);
//     //   }
//     //   return (char *)&DAT_0062c5b0;
//     // }
//     // 
//     // 
// }
// 
//
// ---- GetCommInfo ----
// // Offset: 0x0042CD50
// char* GetCommInfo(TCommunications_Handler* this_, uchar param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: char * __thiscall TCommunications_Handler::GetCommInfo(unsigned char) */
//     // 
//     // char * __thiscall TCommunications_Handler::GetCommInfo(TCommunications_Handler *this,uchar param_1)
//     // 
//     // {
//     //   float fVar1;
//     //   char cVar2;
//     //   ulong uVar3;
//     //   int iVar4;
//     //   int iVar5;
//     //   uint uVar6;
//     //   uint uVar7;
//     //   char *pcVar8;
//     //   int iVar9;
//     //   char *pcVar10;
//     //   char *pcVar11;
//     //   char *pcVar12;
//     //   double dVar13;
//     //   double dVar14;
//     //   ulong dwCount;
//     //   int iStack_110;
//     //   int iStack_10c;
//     //   int iStack_108;
//     //   char tmp [255];
//     //   
//     //   iVar9 = 0;
//     //   pcVar12 = (char *)&DAT_0062c6f0;
//     //   if (this->Multiplayer == 0) {
//     //     do {
//     //       uVar6 = 0xffffffff;
//     //       pcVar10 = &s_>;
//     //       do {
//     //         pcVar11 = pcVar10;
//     //         if (uVar6 == 0) break;
//     //         uVar6 = uVar6 - 1;
//     //         pcVar11 = pcVar10 + 1;
//     //         cVar2 = *pcVar10;
//     //         pcVar10 = pcVar11;
//     //       } while (cVar2 != '\0');
//     //       uVar6 = ~uVar6;
//     //       pcVar8 = pcVar12 + 0x100;
//     //       pcVar10 = pcVar11 + -uVar6;
//     //       for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
//     //         *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
//     //         pcVar10 = pcVar10 + 4;
//     //         pcVar12 = pcVar12 + 4;
//     //       }
//     //       for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
//     //         *pcVar12 = *pcVar10;
//     //         pcVar10 = pcVar10 + 1;
//     //         pcVar12 = pcVar12 + 1;
//     //       }
//     //       pcVar12 = pcVar8;
//     //     } while ((int)pcVar8 < 0x62cdf0);
//     //     sprintf();
//     //   }
//     //   else {
//     //     do {
//     //       uVar6 = 0xffffffff;
//     //       pcVar10 = &s__;
//     //       do {
//     //         pcVar11 = pcVar10;
//     //         if (uVar6 == 0) break;
//     //         uVar6 = uVar6 - 1;
//     //         pcVar11 = pcVar10 + 1;
//     //         cVar2 = *pcVar10;
//     //         pcVar10 = pcVar11;
//     //       } while (cVar2 != '\0');
//     //       uVar6 = ~uVar6;
//     //       pcVar8 = pcVar12 + 0x100;
//     //       pcVar10 = pcVar11 + -uVar6;
//     //       for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
//     //         *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
//     //         pcVar10 = pcVar10 + 4;
//     //         pcVar12 = pcVar12 + 4;
//     //       }
//     //       for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
//     //         *pcVar12 = *pcVar10;
//     //         pcVar10 = pcVar10 + 1;
//     //         pcVar12 = pcVar12 + 1;
//     //       }
//     //       pcVar12 = pcVar8;
//     //     } while ((int)pcVar8 < 0x62cdf0);
//     //     uVar6 = 0xffffffff;
//     //     pcVar12 = tmp;
//     //     pcVar10 = s_;
//     //     do {
//     //       pcVar11 = pcVar10;
//     //       if (uVar6 == 0) break;
//     //       uVar6 = uVar6 - 1;
//     //       pcVar11 = pcVar10 + 1;
//     //       cVar2 = *pcVar10;
//     //       pcVar10 = pcVar11;
//     //     } while (cVar2 != '\0');
//     //     uVar6 = ~uVar6;
//     //     pcVar10 = tmp;
//     //     pcVar11 = pcVar11 + -uVar6;
//     //     for (uVar7 = uVar6 >> 2; pcVar12 = pcVar12 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
//     //       *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
//     //       pcVar11 = pcVar11 + 4;
//     //     }
//     //     iVar4 = this->MeHost;
//     //     for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
//     //       *pcVar12 = *pcVar11;
//     //       pcVar11 = pcVar11 + 1;
//     //       pcVar12 = pcVar12 + 1;
//     //     }
//     //     pcVar12 = s_Host;
//     //     if (iVar4 == 0) {
//     //       pcVar12 = &s_Client;
//     //     }
//     //     uVar6 = 0xffffffff;
//     //     do {
//     //       pcVar11 = pcVar12;
//     //       if (uVar6 == 0) break;
//     //       uVar6 = uVar6 - 1;
//     //       pcVar11 = pcVar12 + 1;
//     //       cVar2 = *pcVar12;
//     //       pcVar12 = pcVar11;
//     //     } while (cVar2 != '\0');
//     //     fVar1 = this->lastRXDataRate;
//     //     uVar6 = ~uVar6;
//     //     pcVar12 = pcVar11 + -uVar6;
//     //     for (uVar7 = uVar6 >> 2; pcVar10 = pcVar10 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
//     //       *(undefined4 *)pcVar10 = *(undefined4 *)pcVar12;
//     //       pcVar12 = pcVar12 + 4;
//     //     }
//     //     dVar14 = (double)fVar1;
//     //     dVar13 = (double)this->lastTXDataRate;
//     //     for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
//     //       *pcVar10 = *pcVar12;
//     //       pcVar12 = pcVar12 + 1;
//     //       pcVar10 = pcVar10 + 1;
//     //     }
//     //     pcVar12 = GetReadyPlayerStr(this);
//     //     sprintf(&DAT_0062c6f0,s_P_d_T__6ld____7s___s__TX___0_1f_,this->Me,this->current_turn,tmp + 4,
//     //             pcVar12,dVar13,dVar14);
//     //     RGE_Communications_Speed::GetLatencyInfo(this->Speed);
//     //     sprintf();
//     //     RGE_Communications_Speed::GetAdjustmentCount(this->Speed);
//     //     pcVar12 = RGE_Communications_Speed::GetMachineSpeedInfo(this->Speed);
//     //     sprintf(0x62c8f0,s__s__Speed_Adjusts__d_,pcVar12);
//     //     (**(code **)(*DAT_0062c5ec + 0x44))();
//     //     pcVar12 = RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(this->Speed);
//     //     sprintf(0x62c9f0,s__s__DPMsgs_d_,pcVar12);
//     //     RGE_Communications_Speed::GetPlayerSpeedStatusStr(this->Speed,0);
//     //     sprintf();
//     //                     /* language.dll match for 0x1468: "Stone path 5" */
//     //     uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Com_hand_c,0x1468);
//     //     iVar4 = IsPlayerHuman(this,8);
//     //     if ((iVar4 == 0) || (this->Me == 8)) {
//     //       tmp[0] = '\0';
//     //       tmp[1] = '\0';
//     //       tmp[2] = '\0';
//     //       tmp[3] = '\0';
//     //     }
//     //     else {
//     //       tmp._0_4_ = uVar3 - this->LastPlayerCommunication[8];
//     //     }
//     //     iVar4 = IsPlayerHuman(this,7);
//     //     if ((iVar4 == 0) || (this->Me == 7)) {
//     //       iStack_10c = 0;
//     //     }
//     //     else {
//     //       iStack_10c = uVar3 - this->LastPlayerCommunication[7];
//     //     }
//     //     iVar4 = IsPlayerHuman(this,6);
//     //     if ((iVar4 == 0) || (this->Me == 6)) {
//     //       dwCount = 0;
//     //     }
//     //     else {
//     //       dwCount = uVar3 - this->LastPlayerCommunication[6];
//     //     }
//     //     iVar4 = IsPlayerHuman(this,5);
//     //     if ((iVar4 == 0) || (this->Me == 5)) {
//     //       iStack_110 = 0;
//     //     }
//     //     else {
//     //       iStack_110 = uVar3 - this->LastPlayerCommunication[5];
//     //     }
//     //     iVar4 = IsPlayerHuman(this,4);
//     //     if ((iVar4 == 0) || (this->Me == 4)) {
//     //       iStack_108 = 0;
//     //     }
//     //     else {
//     //       iStack_108 = uVar3 - this->LastPlayerCommunication[4];
//     //     }
//     //     iVar4 = IsPlayerHuman(this,3);
//     //     if ((iVar4 != 0) && (this->Me != 3)) {
//     //       iVar9 = uVar3 - this->LastPlayerCommunication[3];
//     //     }
//     //     iVar4 = IsPlayerHuman(this,2);
//     //     if ((iVar4 == 0) || (this->Me == 2)) {
//     //       iVar4 = 0;
//     //     }
//     //     else {
//     //       iVar4 = uVar3 - this->LastPlayerCommunication[2];
//     //     }
//     //     iVar5 = IsPlayerHuman(this,1);
//     //     if ((iVar5 == 0) || (this->Me == 1)) {
//     //       iVar5 = 0;
//     //     }
//     //     else {
//     //       iVar5 = uVar3 - this->LastPlayerCommunication[1];
//     //     }
//     //     sprintf(0x62cbf0,s_LastComm__P1___5d__P2___5d__P3__,iVar5,iVar4,iVar9,iStack_108,iStack_110,
//     //             dwCount,iStack_10c,tmp._0_4_);
//     //   }
//     //   return (char *)(&DAT_0062c6f0 + (uint)(byte)(param_1 - 1) * 0x40);
//     // }
//     // 
//     // 
// }
// 
//
// ---- OpenMultiplayerConnection ----
// // Offset: 0x0042D580
// int OpenMultiplayerConnection(TCommunications_Handler* this_) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::OpenMultiplayerConnection(void) */
//     // 
//     // int __thiscall TCommunications_Handler::OpenMultiplayerConnection(TCommunications_Handler *this)
//     // 
//     // {
//     //   return -1;
//     // }
//     // 
//     // 
// }
// 
//
// ---- CreateMultiplayerGame ----
// // Offset: 0x0042D590
// int CreateMultiplayerGame(TCommunications_Handler* this_) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* WARNING: Variable defined which should be unmapped: dSess2 */
//     // /* public: int __thiscall TCommunications_Handler::CreateMultiplayerGame(void) */
//     // 
//     // int __thiscall TCommunications_Handler::CreateMultiplayerGame(TCommunications_Handler *this)
//     // 
//     // {
//     //   TChat *this_00;
//     //   long lVar1;
//     //   int iVar2;
//     //   DPSESSIONDESC2 *pDVar3;
//     //   DPSESSIONDESC2 dSess2;
//     //   
//     //   this_00 = this->Chat;
//     //   this->Multiplayer = 1;
//     //   this->HaveHostInit = 0;
//     //   (this->PlayerOptions).CommandTurnIncrement = '\x02';
//     //   this->current_turn = 4;
//     //   (this->PlayerOptions).CurrentTurn = 4;
//     //   TChat::ClearChat(this_00);
//     //   lVar1 = CreateDirectPlayConversation(this);
//     //   RGE_Comm_Error::ShowReturn(this->Err,lVar1,s_DPCreateConv);
//     //   pDVar3 = &dSess2;
//     //   this->MeHost = 1;
//     //   for (iVar2 = 0x14; pDVar3 = (DPSESSIONDESC2 *)&pDVar3->dwFlags, iVar2 != 0; iVar2 = iVar2 + -1) {
//     //     *(ulong *)pDVar3 = 0;
//     //   }
//     //   dSess2.dwCurrentPlayers = (ulong)this->MaxGamePlayers;
//     //   dSess2.dwFlags = 0x50;
//     //   dSess2.guidApplication._4_4_ = (this->ApplicationGUID).Data1;
//     //   dSess2.field6_0x30 = (DPSESSIONDESC2_u_48)0x1;
//     //   dSess2.guidInstance.Data1 = 0x44;
//     //   dSess2.guidApplication.Data4._0_4_ = *(undefined4 *)&(this->ApplicationGUID).Data2;
//     //   dSess2.guidApplication.Data4._4_4_ = *(undefined4 *)(this->ApplicationGUID).Data4;
//     //   dSess2.dwMaxPlayers = *(ulong *)((this->ApplicationGUID).Data4 + 4);
//     //   dSess2.field7_0x34.lpszPassword = (ushort *)this->MyGameTitle;
//     //   DebugSessionInformation(this,(DPSESSIONDESC2 *)&dSess2.dwFlags);
//     //   iVar2 = (**(code **)(*DAT_0062c5ec + 0x60))(DAT_0062c5ec,&dSess2.dwFlags,2);
//     //   RGE_Comm_Error::ShowReturn(this->Err,iVar2,s_DP_Open_Create);
//     //   if (iVar2 != 0) {
//     //     if (iVar2 == -0x7788ff56) {
//     //       NotifyWindow(this,COMM_NO_LINK);
//     //       return 0;
//     //     }
//     //     (this->PlayerOptions).ProgramState = COMM_STATE_ERROR;
//     //     return 0;
//     //   }
//     //   SetRandomSeed(this,rge_base_game->random_game_seed);
//     //   AddSelfPlayer(this);
//     //   CommGetCaps(this);
//     //   DPlayGetSessionDesc(this);
//     //   this->Me = 1;
//     //   (this->PlayerOptions).HostPlayerNumber = 1;
//     //   (this->PlayerOptions).dcoID[1] = DAT_0062cf04;
//     //   (this->PlayerOptions).Humanity[this->Me] = ME_HUMAN;
//     //   this->HaveHostInit = 1;
//     //   (this->PlayerOptions).ProgramState = COMM_STATE_JOINNOW;
//     //                     /* language.dll match for 0x7d1: "Error" */
//     //   this->GTDSerialNo = 0x7d1;
//     //   UpdatePlayers(this);
//     //   return 1;
//     // }
//     // 
//     // 
// }
// 
//
// ---- SetMyGameOptions ----
// // Offset: 0x0042EB60
// int SetMyGameOptions(TCommunications_Handler* this_, char* param_2, ulong param_3) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: int __thiscall TCommunications_Handler::SetMyGameOptions(char *,unsigned long) */
//     // 
//     // int __thiscall
//     // TCommunications_Handler::SetMyGameOptions(TCommunications_Handler *this,char *param_1,ulong param_2)
//     // 
//     // {
//     //   char *pcVar1;
//     //   TDebuggingLog *extraout_ECX;
//     //   uint uVar2;
//     //   TDebuggingLog *this_00;
//     //   
//     //   if (2000 < param_2) {
//     //     return 0;
//     //   }
//     //   FreeOptions(this);
//     //   this_00 = extraout_ECX;
//     //   if ((param_1 != (char *)0x0) && (param_2 != 0)) {
//     //     pcVar1 = (char *)operator_new(param_2 + 1);
//     //     this->OptionsData = pcVar1;
//     //     if (pcVar1 == (char *)0x0) {
//     //       return 0;
//     //     }
//     //     for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
//     //       *(undefined4 *)pcVar1 = *(undefined4 *)param_1;
//     //       param_1 = param_1 + 4;
//     //       pcVar1 = pcVar1 + 4;
//     //     }
//     //     for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
//     //       *pcVar1 = *param_1;
//     //       param_1 = param_1 + 1;
//     //       pcVar1 = pcVar1 + 1;
//     //     }
//     //     (this->PlayerOptions).DataSizeToFollow = param_2;
//     //     this_00 = (TDebuggingLog *)0x0;
//     //   }
//     //   if (this->MeHost != 0) {
//     //     (this->PlayerOptions).NeedsToBeSent = '\x01';
//     //   }
//     //   TDebuggingLog::Log(this_00,(char *)L,s_Host_Set_Options_to_size__d,param_2);
//     //   return 1;
//     // }
//     // 
//     // 
// }
// 
//
// ---- GetMyGameOptions ----
// // Offset: 0x0042EBF0
// void* GetMyGameOptions(TCommunications_Handler* this_, ulong* param_2) {
//     // --- Ghidra decompiler output ---
//     // 
//     // /* public: void * __thiscall TCommunications_Handler::GetMyGameOptions(unsigned long *) */
//     // 
//     // void * __thiscall
//     // TCommunications_Handler::GetMyGameOptions(TCommunications_Handler *this,ulong *param_1)
//     // 
//     // {
//     //   *param_1 = (this->PlayerOptions).DataSizeToFollow;
//     //   return this->OptionsData;
//     // }
//     // 
//     // 
// }
// 
//
// END Task 222 decomp reference bundle
// END Task 222 decomp gap implementations
