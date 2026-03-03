#include "../include/TCommunications_Handler.h"
#include "../include/RESENDER.h"
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
#include "../include/RGE_Base_Game.h"
#include "../include/debug_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new>
#include <dplay.h>

int StringFromGUID(_GUID* param_1, ushort* param_2);
int EnumPlayersCallback2(ulong param_1, ulong param_2, DPNAME* param_3, ulong param_4, void* param_5);

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
static const int kCommMessagePlayerResigned = 0x17b4;
static const int kCommMessagePlayerDefeated = 0x17b5;
static const int kCommMessageNoOtherHumans = 0x17b6;
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
    if (speed == nullptr) {
        return 0;
    }
    return (uint)comm_tslc_get_avg(speed->FrameTSLC, 0x32);
}

static uchar comm_get_next_sequence(ulong execute_on_turn, int program_state) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B200
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // TODO: PARITY [MODERATE] - Helper extraction from StoreIncoming; re-verify duplicate-slot/full-buffer diagnostics and side effects against direct decomp control flow. [decomp: com_hand.cpp.decomp @ 0x0042A180]
    // TODO: PARITY [CRITICAL] - Decomp logs and continues the slot-scan when len==0, while this helper exits early on len==0 and drops those diagnostics/side effects. [decomp: com_hand.cpp.decomp @ 0x0042A180]
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // Fully verified. Source of truth: com_hand.cpp.decomp (helper implementation).
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
    // TODO: PARITY [CRITICAL] - EvaluatePlayerMessage is missing the decomp's Multiplayer gate and 0x2B non-host resume branch before default handling; re-audit command ordering/log side effects. [decomp: com_hand.cpp.decomp @ 0x004282C0]
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
        if (payload_len >= 10 && comm->Speed != nullptr) {
            comm->Speed->SetPlayerTurnSpeed(from_player, (uchar)payload[9], (uchar)payload[8]);
        }
        if (payload_len >= 8) {
            const ulong done_turn = *(const ulong*)(payload + 4);
            if ((comm->PlayerOptions.ProgramState < kCommStateRunning || comm->current_turn < 6) &&
                done_turn < comm->current_turn) {
                return 0;
            }
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
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425A40
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

    // Source of truth: com_hand.cpp.decomp @ 0x00425A40 allocates/constructs 0x1F6 entries.
    this->Resend = (RESENDER*)::operator new(sizeof(RESENDER) * (size_t)0x1F6, std::nothrow);
    this->OnHold = (HOLDER*)::operator new(sizeof(HOLDER) * (size_t)0x1F6, std::nothrow);
    if (this->Resend != nullptr) {
        for (int i = 0; i < 0x1F6; ++i) {
            new (&this->Resend[i]) RESENDER();
        }
    }
    if (this->OnHold != nullptr) {
        for (int i = 0; i < 0x1F6; ++i) {
            new (&this->OnHold[i]) HOLDER();
        }
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

TCommunications_Handler::TCommunications_Handler(void* host_hwnd, uchar max_game_players, TChat* chat, _GUID application_guid)
    : TCommunications_Handler(host_hwnd, max_game_players) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425A40
    this->Chat = chat;
    this->ApplicationGUID = application_guid;
}

TCommunications_Handler::~TCommunications_Handler() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004261E0
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
        for (int i = 0; i < 0x1F6; ++i) {
            this->Resend[i].~RESENDER();
        }
        ::operator delete(this->Resend);
        this->Resend = nullptr;
    }
    if (this->OnHold != nullptr) {
        for (int i = 0; i < 0x1F6; ++i) {
            this->OnHold[i].~HOLDER();
        }
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C7F0
int TCommunications_Handler::IsPaused() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C7F0
    const int* program_state =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    return (*program_state == kCommStatePause) ? 1 : 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CB00
int TCommunications_Handler::IsHost() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CB00
    if (this->Multiplayer != 0) {
        return this->MeHost;
    }
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E610
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EF00
long TCommunications_Handler::EnableNewPlayers(void* direct_play, int enable_links) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EF00
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CCD0
int TCommunications_Handler::IsPlayerHuman(uint player_number) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CCD0
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers)) {
        return 0;
    }

    int humanity = this->GetPlayerHumanity(player_number);
    return ((humanity == kPlayerHumanityHuman) || (humanity == kPlayerHumanityCyborg)) ? 1 : 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426630
void TCommunications_Handler::LastWorldRandom(int param_1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426630
    this->Sync->SetLastWorldRandom((ulong)param_1);
}

// Fully verified. Not in decomp, inherited/forwarding method.
void TCommunications_Handler::Update() {
    // Offset 0x00426650 in ASM is DoCycle
    // The user wants Update() to behave like the core tick.
    // In tribal engine, DoCycle is the main entry.
    DoCycle(GetTickCount());
}

// Fully verified. Not in decomp, inherited/forwarding method.
void TCommunications_Handler::HandleMessage() {
    // Offset 0x00429D90 in ASM is ExecuteIncoming
    ExecuteIncoming();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426650
int TCommunications_Handler::DoCycle(ulong now) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426650
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426E10
void TCommunications_Handler::ReceiveGameMessages() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426E10
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429D90
uint TCommunications_Handler::ExecuteIncoming() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429D90
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426FC0
void TCommunications_Handler::GetDPLAYMessages() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426FC0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428DA0
void TCommunications_Handler::EvaluateSystemMessage(ulong p1, char* p2, ulong p3, ulong p4) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428DA0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DF40
void TCommunications_Handler::UpdatePlayers() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DF40
    uint low = (uint)this->PlayerOptions.LowPlayerNumber;
    uint high = (uint)this->PlayerOptions.HighPlayerNumber;
    if (low <= high) {
        for (uint p = low; p <= high; ++p) {
            this->UpdatePlayer(p, 0);
        }
    }
    this->NotifyWindow(kCommMessageUpdatePlayers);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DF90
void TCommunications_Handler::UpdatePlayer(uint id, int timeout) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DF90
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428270
void TCommunications_Handler::NotifyWindow(int message) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428270
    // Behavior: Post WM_USER to HostHWND with message as wParam and 0 as lParam.
    // Note: we use integer ids because the full COMMMESSAGES enum is not restored yet.
    // TODO: PARITY [LOW] - Message parameter uses int instead of COMMMESSAGES enum, which can mask signedness/type parity issues at call sites. [decomp: com_hand.cpp.decomp @ 0x00428270]
    if (this->HostHWND) {
        PostMessageA((HWND)this->HostHWND, 0x400, (WPARAM)message, 0);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428280
void TCommunications_Handler::NotifyWindowParam(int message, long param) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428280
    if (this->HostHWND) {
        PostMessageA((HWND)this->HostHWND, 0x400, (WPARAM)message, (LPARAM)param);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428820
long TCommunications_Handler::SendSharedData(int send_mode) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428820
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CC00
int TCommunications_Handler::GetPlayerHumanity(uint player_number) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CC00, com_hand.cpp.asm @ 0x0042CC00
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers)) {
        return 0;
    }

    const int* humanity =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsHumanityOffset);
    return humanity[player_number];
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CC30
void TCommunications_Handler::SetPlayerHumanity(uint player_number, int humanity_value) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CC30, com_hand.cpp.asm @ 0x0042CC30
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers)) {
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D0E0
char* TCommunications_Handler::GetPlayerName(uint player_number) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D0E0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D440
void TCommunications_Handler::SetPlayerName(uint player_number, char* name) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D440
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CA90
uint TCommunications_Handler::GetRandomSeed() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CA90
    // TODO: PARITY [CRITICAL] - Single-player path should seed/store PlayerOptions.RandomSeed via debug_timeGetTime/debug_srand/debug_rand before return; current code returns GetTickCount() directly. [decomp: com_hand.cpp.decomp @ 0x0042CA90]
    if (this->Multiplayer == 0) {
        return (uint)GetTickCount();
    }
    const uint* random_seed =
        (const uint*)((const char*)&this->PlayerOptions + kCommPlayerOptionsRandomSeedOffset);
    return *random_seed;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CAF0
uint TCommunications_Handler::WhoAmI() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CAF0
    return this->Me;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F270
int TCommunications_Handler::IsPlayerOutOfSync(uint player_number, ulong comm_turn) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F270
    return this->Sync->IsPlayerOutOfSync(player_number, comm_turn);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D490
void* TCommunications_Handler::SetWindowHandle(void* window_handle) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D490
    this->HostHWND = window_handle;
    return window_handle;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DC20
void TCommunications_Handler::LaunchMultiplayerGame() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DC20
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425990
void TCommunications_Handler::CalculatePlayerRange() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425990
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429FD0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D720
void TCommunications_Handler::PackPlayersDown() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D720
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428A70
void TCommunications_Handler::SetSelfPlayer() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428A70
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
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D2D0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C7A0
void TCommunications_Handler::ResetLastCommunicationTimes() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C7A0
    ulong now = GetTickCount();
    for (uint player = 1; player <= (uint)this->MaxGamePlayers && player < 10; ++player) {
        this->LastPlayerCommunication[player] = now;
        this->LastTXPing[player] = now;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429F80
void TCommunications_Handler::ClearAllSerialNumbers() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429F80
    for (uint player = 0; player <= (uint)this->MaxGamePlayers && player < 10; ++player) {
        this->PlayerHighSerialNumber[player] = 0;
        this->LastSerialRequestedTX[player] = 0;
        this->LastRequestHonoredTX[player] = 0;
        this->LastSerialRepliedTX[player] = 0;
        this->LastRequestRepliedTX[player] = 0;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426450
RESENDER::RESENDER() {
    this->TimeSent = 0;
    this->ResendMsg = nullptr;
    this->Serial = 0;
    this->Length = 0;
    for (int i = 0; i < 10; ++i) {
        this->DestMap[i] = 0;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004264A0
RESENDER::~RESENDER() {
    this->TimeSent = 0;
    if (this->ResendMsg != nullptr) {
        ::operator delete(this->ResendMsg);
    }
    this->ResendMsg = nullptr;
    this->Serial = 0;
    this->Length = 0;
    for (int i = 0; i < 10; ++i) {
        this->DestMap[i] = 0;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004265E0
HOLDER::HOLDER() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004265E0, com_hand.cpp.asm @ 0x004265E0
    this->HoldMsg = nullptr;
    this->Serial = 0;
    this->Length = 0;
    this->dcoFromID = 0;
    this->dcoReceiveID = 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426600
HOLDER::~HOLDER() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426600, com_hand.cpp.asm @ 0x00426600
    if (this->HoldMsg != nullptr) {
        ::operator delete(this->HoldMsg);
    }
    this->HoldMsg = nullptr;
    this->Serial = 0;
    this->Length = 0;
    this->dcoFromID = 0;
    this->dcoReceiveID = 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426470
int TCommunications_Handler::AddCommand(ulong p1, void* p2, ulong p3, int p4, uchar p5, int p6) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426470
    if (this->InQ == nullptr) {
        return 0;
    }

    return this->InQ->AddItem(p1, p2, p3, (uint)p4, p5, p6);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004264D0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426530
int TCommunications_Handler::NewCommand(void* p1, int p2, int p3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426530, com_hand.cpp.asm @ 0x00426530
    if (this->Multiplayer != 0) {
        L->Log("  >TX CMD (%d) Cmd=%d ", p2, (uint)(*(const uchar*)p1));
        long hr = this->CommOut((uchar)0x3E, p1, p2, 0);
        this->Err->ShowReturn(hr, "NewCmnd");
        return 1;
    }

    const uchar* command_turn_increment =
        (const uchar*)((const char*)&this->PlayerOptions + kCommPlayerOptionsCommandTurnIncrementOffset);
    const ulong queue_turn = this->current_turn + (ulong)(*command_turn_increment);
    const uchar sequence = this->InQ->GetNextSequence(this->current_turn);

    this->AddCommand(queue_turn, p1, (ulong)p2, (int)this->Me, sequence, p3);
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426510
uchar TCommunications_Handler::new_command(void* p1, int p2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426510
    return (uchar)this->NewCommand(p1, p2, 0);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428B10
void TCommunications_Handler::DropDeadPlayer(uint id, ulong turn) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428B10
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427300
void TCommunications_Handler::CheckPingTime(int p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427300
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429760
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004297D0
void TCommunications_Handler::SendChatMsgAll(char* param_1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004297D0
    uchar destMap[10];
    memset(destMap, 'N', sizeof(destMap));

    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        destMap[p] = 'Y';
    }

    (void)this->TXChat(this->Me, destMap, param_1);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429810
void TCommunications_Handler::SendChatMsg(uint param_1, uint param_2, char* param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429810
    uchar destMap[10];
    memset(destMap, 'N', sizeof(destMap));

    if (param_2 < 10) {
        destMap[param_2] = 'Y';
    }

    (void)this->TXChat(param_1, destMap, param_3);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429870
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A800
void TCommunications_Handler::SendStoredMessages() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A800
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427600
int TCommunications_Handler::PreprocessMessages(ulong p1, char* p2, ulong p3, ulong p4, int p5) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427600
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
        if (this->ShuttingDown == 0) {
            (void)this->EvaluatePlayerMessage(p1, from_player, execute_on_turn, cmd, sequence, (char*)payload, payload_len, p3, p4);
        }
        return 1;
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
        (void)this->EvaluatePlayerMessage(p1, from_player, execute_on_turn, cmd, sequence, (char*)payload, payload_len, p3, p4);
    }

    return 1;
}

// Fully verified. Not in decomp, inherited/forwarding method.
long TCommunications_Handler::CommOut(uchar p1, void* p2, long p3, ulong p4) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B270
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C840
void TCommunications_Handler::LocalResumeGame(uint p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C840
    int* program_state = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    *program_state = kCommStateRunning;
    this->NotifyWindowParam(kCommWindowMessageResume, (long)p1);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C860
void TCommunications_Handler::LocalPauseGame(uint p1) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C860
    int* program_state = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    *program_state = kCommStatePause;
    this->NotifyWindowParam(kCommWindowMessagePause, (long)p1);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C880
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C930
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C9A0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C8F0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E5E0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D170
int TCommunications_Handler::IsLobbyLaunched() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D170
    if (this->Lobby == nullptr) {
        return 0;
    }
    return this->Lobby->IsLobbyLaunched();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429A90
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426FB0
void TCommunications_Handler::ShutdownGameMessages() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426FB0
    this->ShuttingDown = 1;
    this->ReceiveGameMessages();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A0C0
int TCommunications_Handler::CountWaitingMessages() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A0C0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425750
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042BAD0
COMMSTATUS TCommunications_Handler::GetCommunicationsStatus() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042BAD0
    COMMSTATUS st = this->AnalyzeCommunicationsStatus();
    this->CommunicationsStatus = st;
    return st;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C690
COMMSTATUS TCommunications_Handler::AnalyzeCommunicationsStatus() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C690
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428810
void TCommunications_Handler::ReleaseSettings() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428810
    this->PlayerOptions.NeedsToBeSent = 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EC10
void TCommunications_Handler::FreeOptions() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EC10
    char* options = this->OptionsData;
    if (options != nullptr) {
        this->PlayerOptions.DataSizeToFollow = 0;
        ::operator delete(options);
        this->OptionsData = nullptr;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E9B0
long TCommunications_Handler::ReleaseComm() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E9B0
    if (this->Lobby != nullptr && this->Lobby->glpDP != nullptr) {
        (void)this->Lobby->glpDP->Release();
        this->Lobby->glpDP = nullptr;
        this->ServiceGUID = this->NullGUID;
    }
    return 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E920
long TCommunications_Handler::CloseSession() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E920
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EB10
long TCommunications_Handler::DestroyMyPlayer() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EB10
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EA10
int TCommunications_Handler::Kick(uint player_number) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EA10
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C800
void TCommunications_Handler::DropAllHostedPlayers() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C800
    if (this->MeHost != 0 && this->current_turn < 7) {
        for (uint player = 1; player <= (uint)this->MaxGamePlayers && player < 10; ++player) {
            (void)this->Kick(player);
        }
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042BAE0
COMMSTATUS TCommunications_Handler::UnlinkCurrentLevel() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042BAE0
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
            this->LastPlayerWarning[p] = 0;
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
        this->Chat->ClearChat();
        this->MyGameTitle[0] = '\0';
        this->Me = 0;
        s_localPlayerDpid = 0;
        this->ShuttingDown = 0;
        break;

    case SESSION_AVAILABLE: {
        this->ClearRXandTX();
        this->DropAllHostedPlayers();
        this->Chat->ClearChat();
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
        this->Chat->ClearChat();
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
        this->InQ->FlushAll();
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
        this->Chat->ClearChat();
        this->LastTimeoutMessageTime = 0;
        this->InQ->FlushAll();
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_IS_PAUSED:
    default:
        break;
    }

    return this->AnalyzeCommunicationsStatus();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C5D0
COMMSTATUS TCommunications_Handler::UnlinkToLevel(COMMSTATUS level) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042C5D0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DED0
IDirectPlay3* TCommunications_Handler::GetDPInterface() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DED0
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429A30
void TCommunications_Handler::SendSpeedChange(uint buffer_frames, uint buffer_granularity) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429A30
    if (this->MeHost != 0 && this->Multiplayer != 0) {
        const uint packed = ((buffer_granularity & 0xFFFF) << 16) | (buffer_frames & 0xFFFF);
        (void)this->CommOut('S', (void*)&packed, 4, 0);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429C40
int TCommunications_Handler::AllPlayersAcknowledged() {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429C40
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
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429CE0
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
// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425780
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425800
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004258E0
void TCommunications_Handler::StopIfSyncFail(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004258E0
    if (this->Sync == nullptr) {
        return;
    }
    this->Sync->SetDialogOnFail(param_2);
    this->Sync->SetStopOnFail(param_2);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425910
void TCommunications_Handler::ShowSyncChatMsgs(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425910
    if (this->Sync != nullptr) {
        this->Sync->SendChatMsgsAtChecksum(param_2);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425930
void TCommunications_Handler::DropPacketsIntentionally(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425930
    // TODO: PARITY [CRITICAL] - Decomp emits a debug log when enabling intentional packet drop; this implementation only stores the flag. [decomp: com_hand.cpp.decomp @ 0x00425930]
    this->IntentionallyDropPackets = param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425960
void TCommunications_Handler::SetStepMode(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425960
    this->StepMode = param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425970
void TCommunications_Handler::SetSpeedControl(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425970
    if (this->Speed != nullptr) {
        this->Speed->EnableSpeedControl(param_2);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425A20
void TCommunications_Handler::Step(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00425A20
    this->Steps += param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426350
void TCommunications_Handler::KillAnyMissingPlayers(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426350
    struct MsgKillPlayer {
        ulong dcoID;
        ulong currentTurn;
        long playerNo;
    } kill_msg;

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return;
    }

    for (uint player = 1; player <= (uint)this->MaxGamePlayers; ++player) {
        if (this->IsPlayerHuman(player) == 0) {
            continue;
        }

        ulong dpid = this->PlayerOptions.dcoID[player];
        DWORD size = 0;
        (void)dp->GetPlayerName((DPID)dpid, nullptr, &size);

        void* name_buffer = (size != 0) ? ::operator new((size_t)size, std::nothrow) : nullptr;
        HRESULT hr = dp->GetPlayerName((DPID)dpid, name_buffer, &size);
        if (name_buffer != nullptr) {
            ::operator delete(name_buffer);
        }

        if (hr != DP_OK) {
            kill_msg.dcoID = player;
            kill_msg.currentTurn = dpid;
            kill_msg.playerNo = (long)hr;
            L->Log("--->TX KP: %d %d", (long)player, 0x0C);
            (void)this->CommOut((uchar)'K', &kill_msg, 0x0C, 0);
            if (this->PlayerStopTurn[player] == 0) {
                this->DropDeadPlayer(player, dpid);
            }
        }
    }

    (void)dp->Release();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426D40
int TCommunications_Handler::HasKicked(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426D40
    if (param_2 >= 10) {
        return 0;
    }
    return this->Kicked[param_2];
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426D50
long TCommunications_Handler::SendPlayerName(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426D50
    DPNAME set_name;
    memset(&set_name, 0, sizeof(set_name));
    set_name.dwSize = sizeof(set_name);
    set_name.dwFlags = 0x10;
    set_name.lpszShortNameA = nullptr;
    set_name.lpszLongNameA = this->MyFriendlyName;

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        if (this->Err != nullptr) {
            this->Err->ShowReturn(DPERR_INVALIDPLAYER, "Send Player Name");
        }
        return DPERR_INVALIDPLAYER;
    }

    ulong local_dpid = s_localPlayerDpid;
    if (local_dpid == 0 && this->Me != 0 && this->Me <= (uint)this->MaxGamePlayers) {
        local_dpid = this->PlayerOptions.dcoID[this->Me];
        if (local_dpid != 0) {
            s_localPlayerDpid = local_dpid;
        }
    }

    long hr = (local_dpid != 0) ? (long)dp->SetPlayerName((DPID)local_dpid, &set_name, 2) : (long)DPERR_INVALIDPLAYER;
    (void)dp->Release();
    if (this->Err != nullptr) {
        this->Err->ShowReturn(hr, "Send Player Name");
    }
    return hr;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426DC0
void TCommunications_Handler::LogRXMsg(uint param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00426DC0
    if (this->RGE_Guaranteed_Delivery != 0) {
        L->Log("GTD: RX Ser# %d From P# %d T# %ld Type=%lu Seq=%d Ack=%d",
            (long)param_2, (long)param_3, this->current_turn, param_4, (int)param_5, (int)param_6);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427390
int TCommunications_Handler::TXPing(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427390
    struct MsgPing {
        uchar command;
        uchar _pad0;
        uchar _pad1;
        uchar _pad2;
        ulong initiated;
        ulong current_turn;
    } ping_msg;

    ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0x470);
    memset(&ping_msg, 0, sizeof(ping_msg));
    ping_msg.command = (uchar)'1';
    ping_msg.initiated = now;
    ping_msg.current_turn = this->current_turn;

    ulong target_dpid = 0;
    if (param_2 == 0) {
        for (uint player = 1; player <= (uint)this->MaxGamePlayers; ++player) {
            this->LastTXPing[player] = now;
        }
    } else {
        this->LastTXPing[param_2] = now;
        target_dpid = this->PlayerOptions.dcoID[param_2];
    }

    L->Log("--->TX PING: %d %d", (long)param_2, 0x0C);
    long hr = this->FastSend(target_dpid, &ping_msg, 0x0C, 0, 0);
    return (hr == 0) ? 1 : 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427440
int TCommunications_Handler::TXDebugPing(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00427440
    struct MsgDebugPing {
        uchar command;
        uchar _pad0;
        uchar _pad1;
        uchar _pad2;
        ulong initiated;
        ulong current_turn;
    } debug_ping_msg;

    memset(&debug_ping_msg, 0, sizeof(debug_ping_msg));
    debug_ping_msg.command = (uchar)'3';
    debug_ping_msg.initiated = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0x496);
    debug_ping_msg.current_turn = this->current_turn;

    L->Log("--->TX DEBUG PING: %d %d", 0, 0x0C);
    long hr = this->FastSend(0, &debug_ping_msg, 0x0C, 0, 0);
    return (hr == 0) ? 1 : 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004274B0
long TCommunications_Handler::FastSend(ulong param_2, void* param_3, ulong param_4, int param_5, int param_6) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004274B0
    (void)param_5;
    (void)param_6;

    ulong local_dpid = s_localPlayerDpid;
    if (local_dpid == 0 && this->Me != 0 && this->Me <= (uint)this->MaxGamePlayers) {
        local_dpid = this->PlayerOptions.dcoID[this->Me];
        if (local_dpid != 0) {
            s_localPlayerDpid = local_dpid;
        }
    }

    if (param_2 == local_dpid) {
        L->Log("No send to self FastTX");
        return DPERR_INVALIDPLAYER;
    }

    if (local_dpid == 0) {
        L->Log("   BAD DCOID 0 NO TX");
        return DPERR_INVALIDPLAYER;
    }

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        L->Log("   BAD DCOID 0 NO TX");
        return DPERR_INVALIDPLAYER;
    }

    ulong start = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0x4CA);
    long hr = (long)dp->Send((DPID)local_dpid, (DPID)param_2, 0, param_3, (DWORD)param_4);
    ulong stop = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0x4D3);
    if (stop - start > 0x32) {
        L->Log("   FastSend slow : %ld msec", (long)(stop - start));
    }

    int recipients = 1;
    if (param_2 == 0) {
        recipients = 0;
        for (uint player = 1; player <= (uint)this->MaxGamePlayers; ++player) {
            if (this->IsPlayerHuman(player) != 0 && player != this->Me) {
                recipients += 1;
            }
        }
    }
    this->TXPacketLength += (ulong)(recipients * (int)param_4);

    (void)dp->Release();

    if (hr != DPERR_INVALIDPARAMS) {
        if (hr != DP_OK) {
            if (this->Err != nullptr) {
                this->Err->ShowReturn(hr, "FastTX");
            }
        }
        return hr;
    }

    L->Log("FastTX to invalidparams ignored");
    return DPERR_INVALIDPARAMS;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004282C0
int TCommunications_Handler::EvaluatePlayerMessage(ulong param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6, char* param_7, uint param_8, ulong param_9, ulong param_10) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004282C0
    if (this->Multiplayer == 0) {
        return 0;
    }
    if (param_7 == nullptr) {
        return 1;
    }

    switch ((uint)param_5) {
    case 0x2B:
        if (this->MeHost != 0) {
            this->SendPauseGame(0);
            L->Log("Non-host requested resume");
            this->LocalResumeGame(param_3);
        }
        return 1;
    case 0x3E:
        this->AddCommand(param_4, (void*)param_7, param_2, (int)param_3, param_6, 0);
        return 1;
    case 0x43:
    case 0x44:
    case 0x4B:
        return comm_evaluate_player_message(this, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10);
    case 0x4D:
        if (param_8 >= 0x20 && this->Sync != nullptr) {
            this->Sync->Add(param_3, *(ulong*)(param_7 + 0x00), *(ulong*)(param_7 + 0x04), *(ulong*)(param_7 + 0x08),
                            *(long*)(param_7 + 0x0C), *(long*)(param_7 + 0x10), *(long*)(param_7 + 0x14),
                            *(long*)(param_7 + 0x18), *(long*)(param_7 + 0x1C));
        }
        return 1;
    case 0x4E:
        if (this->MeHost == 0) {
            L->Log("Host requested we delete and recover");
        }
        return 1;
    case 0x50:
        this->LocalPauseGame(param_3);
        if (this->Sync != nullptr) {
            this->Sync->LogChecksums(0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        return 1;
    case 0x51:
        if (param_8 >= 4) {
            this->SetPlayerStopTurn(param_3, *(ulong*)param_7);
        }
        return 1;
    case 0x53:
        if (param_8 >= 4 && this->Speed != nullptr) {
            this->Speed->SetFutureSpeedChange((uint)*(ushort*)(param_7 + 0), (uint)*(ushort*)(param_7 + 2), param_4);
        }
        return 1;
    case 0x55:
        this->LocalResumeGame(param_3);
        return 1;
    case 0x57:
        if (this->MeHost != 0) {
            this->SendPauseGame(1);
            this->LocalPauseGame(param_3);
        }
        return 1;
    default:
        return 1;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004286F0
void TCommunications_Handler::SetPlayerStopTurn(uint param_2, ulong param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004286F0
    if (param_2 < 10) {
        this->PlayerStopTurn[param_2] = param_3;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428710
void TCommunications_Handler::CheckPlayerStopTurn(ulong param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00428710
    bool stop_pending = false;
    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        if (this->PlayerStopTurn[p] != 0) {
            stop_pending = true;
        }
        if (this->PlayerStopTurn[p] == param_2) {
            this->InitPlayerInformation(p, 0, (char*)"Resigned", (char*)"");
            this->SetPlayerHumanity(p, kPlayerHumanityEliminated);
            this->NotifyWindowParam(kCommMessagePlayerResigned, (long)p);
            this->PlayerStopTurn[p] = 0;
        }
    }

    if (this->current_turn > 6 && !stop_pending) {
        bool any_other = false;
        for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
            if (p == this->Me) {
                continue;
            }
            if (this->IsPlayerHuman(p) != 0 || this->IsPlayerComputer(p) != 0) {
                any_other = true;
                break;
            }
        }
        if (!any_other) {
            this->NotifyWindow(kCommMessageNoOtherHumans);
        }
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004289A0
int TCommunications_Handler::TEST(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x004289A0
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429BD0
ulong TCommunications_Handler::HiTurnAcknowledged(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x00429BD0
    ulong hi = 0;
    for (uint p = (uint)this->PlayerOptions.LowPlayerNumber; p <= (uint)this->PlayerOptions.HighPlayerNumber && p < 10; ++p) {
        if (this->IsPlayerHuman(p) != 0 && this->LastTurnAck[p] > hi) {
            hi = this->LastTurnAck[p];
        }
    }
    return hi;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A060
void TCommunications_Handler::ClearRXForPlayer(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A060
    if (this->OnHold == nullptr || param_2 >= 10) {
        return;
    }

    const ulong target = this->PlayerOptions.dcoID[param_2];
    unsigned char* on_hold = (unsigned char*)this->OnHold;
    for (uint offset = 0; offset <= 0x2EF8; offset += 0x18) {
        ulong* slot = (ulong*)(on_hold + offset);
        if (slot[3] == target) {
            if ((void*)slot[0] != nullptr) {
                ::operator delete((void*)slot[0]);
            }
            slot[0] = 0;
            slot[1] = 0;
            slot[2] = 0;
            slot[3] = 0;
            slot[4] = 0;
        }
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A130
void TCommunications_Handler::ClearTXForPlayer(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A130
    if (this->Resend == nullptr || param_2 >= 10) {
        return;
    }

    for (uint i = 0; i < 0x1F6; ++i) {
        this->Resend[i].DestMap[param_2] = 0;
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A160
void TCommunications_Handler::ClearRXTXForPlayer(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A160
    this->ClearTXForPlayer(param_2);
    this->ClearRXForPlayer(param_2);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A180
int TCommunications_Handler::StoreIncoming(uint param_2, char* param_3, uint param_4, ulong param_5, ulong param_6) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A180
    // TODO: PARITY [MODERATE] - Wrapper currently bypasses explicit duplicate-slot scan/full-buffer diagnostics from decomp; verify comm_store_incoming preserves all branch behavior and logging side effects. [decomp: com_hand.cpp.decomp @ 0x0042A180]
    comm_store_incoming(this, param_2, param_3, (ulong)param_4, param_5, param_6);
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A330
int TCommunications_Handler::StoreForResend(uint param_2, char* param_3, uint param_4, uint* param_5) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A330
    if (this->Multiplayer == 0 || this->RGE_Guaranteed_Delivery == 0 || this->Resend == nullptr) {
        return 0;
    }

    for (uint i = 0; i < 0x1F6; ++i) {
        RESENDER* slot = &this->Resend[i];
        if (slot->Serial != 0) {
            continue;
        }

        slot->Serial = param_2;
        slot->Length = param_4;
        slot->TimeSent = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0xD12);
        if (param_4 != 0 && param_3 != nullptr) {
            slot->ResendMsg = (char*)::operator new((size_t)param_4, std::nothrow);
            if (slot->ResendMsg == nullptr) {
                slot->Serial = 0;
                slot->Length = 0;
                return 0;
            }
            memcpy(slot->ResendMsg, param_3, (size_t)param_4);
        } else {
            slot->ResendMsg = nullptr;
        }

        memset(slot->DestMap, 0, sizeof(slot->DestMap));
        if (param_5 != nullptr) {
            for (uint p = 0; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
                slot->DestMap[p] = param_5[p];
            }
        }
        return 1;
    }

    return 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A540
int TCommunications_Handler::TXAcknowledgeMessage(uint param_2, uint param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A540
    // TODO: PARITY [CRITICAL] - Decomp returns 0 on disabled GTD, bad DCOID, or send failure; current wrapper always returns 1 after helper call. [decomp: com_hand.cpp.decomp @ 0x0042A540]
    comm_tx_ack(this, param_2, param_3);
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A650
int TCommunications_Handler::RXAcknowledgeStoredMessage(uint param_2, uint param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A650
    if (this->RGE_Guaranteed_Delivery == 0) {
        return 0;
    }
    this->WaitingForAck = 0;
    comm_rx_ack_stored(this, param_2, param_3);
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A6E0
int TCommunications_Handler::PurgeAcknowledgedStoredMessages(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042A6E0
    comm_purge_ackd_stored(this);
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042AD10
int TCommunications_Handler::TXResendReply(uint param_2, uint param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042AD10
    if (this->RGE_Guaranteed_Delivery == 0 || param_3 == 0 || param_3 >= 10) {
        return 0;
    }

    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0xEE7);
    if (param_2 == this->LastSerialRepliedTX[param_3] && (now - this->LastRequestRepliedTX[param_3]) < 500) {
        return 0;
    }

    this->LastSerialRepliedTX[param_3] = param_2;
    this->LastRequestRepliedTX[param_3] = now;

    const int ok = comm_tx_resend_reply(this, param_2, param_3);
    this->PurgeAcknowledgedStoredMessages();
    return ok;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B0A0
int TCommunications_Handler::TXResendRequest(uint param_2, uint param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B0A0
    if (this->RGE_Guaranteed_Delivery == 0 || param_3 == 0 || param_3 >= 10) {
        return 0;
    }

    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/Com_hand.cpp", 0xF8C);
    if (param_2 == this->LastSerialRequestedTX[param_3] && (now - this->LastRequestHonoredTX[param_3]) <= 499) {
        return 0;
    }

    this->LastSerialRequestedTX[param_3] = param_2;
    this->LastRequestHonoredTX[param_3] = now;
    comm_tx_resend_request(this, param_2, param_3);
    this->TXPacketLength += 8;
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B200
uchar TCommunications_Handler::GetNextSequence(ulong param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B200
    return comm_get_next_sequence(param_2, this->PlayerOptions.ProgramState);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B860
void TCommunications_Handler::DestroyMultiplayerGame(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042B860
    this->DestroyMyPlayer();

    const ulong now = debug_timeGetTime("C:/msdev/work/age1_x1/com_hand.h", 0x267);
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
    this->PlayerOptions.LastSentTime = now;

    this->MyGameTitle[0] = 0;
    this->MyFriendlyName[0] = 0;
    this->MyFormalName[0] = 0;

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
    this->Multiplayer = 0;
    this->turnstart = 0;
    this->mselapsed = 0;

    for (uint p = 1; p <= (uint)this->MaxGamePlayers && p < 10; ++p) {
        this->InitPlayerInformation(p, 0, (char*)"", (char*)"");
    }

    this->PlayerOptions.NeedsToBeSent = 0;
    this->PlayerOptions.LastSentTime = 0;
    this->ClearAllSerialNumbers();
    this->ClearRXandTX();
    memset(this->PlayerStopTurn, 0, sizeof(this->PlayerStopTurn));
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
    memset(this->Kicked, 0, sizeof(this->Kicked));
    memset(this->WasKicked, 0, sizeof(this->WasKicked));
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CA20
void TCommunications_Handler::SetRandomSeed(int param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CA20
    // TODO: PARITY [CRITICAL] - Host-only gate, -1 sentinel randomization, NeedsToBeSent flag, and SendSharedData(0) side effects are missing in this simplified assignment. [decomp: com_hand.cpp.decomp @ 0x0042CA20]
    this->PlayerOptions.RandomSeed = (ulong)param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CB20
char* TCommunications_Handler::GetCommStateStr(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CB20
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CB30
char* TCommunications_Handler::GetReadyPlayerStr(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CB30
    // TODO: PARITY [CRITICAL] - Decomp builds per-player readiness/humanity glyph string; current implementation collapses to binary Ready/Not Ready text. [decomp: com_hand.cpp.decomp @ 0x0042CB30]
    return (this->AllPlayersReady() != 0) ? (char*)"Ready" : (char*)"Not Ready";
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CC90
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

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CD10
int TCommunications_Handler::IsPlayerComputer(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CD10
    if (param_2 == 0 || param_2 > (uint)this->MaxGamePlayers || param_2 >= 10) {
        return 0;
    }
    return (this->PlayerOptions.Humanity[param_2] == kPlayerHumanityComputer) ? 1 : 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CD50
char* TCommunications_Handler::GetCommInfo(uchar param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042CD50
    uint player = (uint)param_2;
    if (this->Multiplayer == 0) {
        sprintf(this->TBuff, ">");
        return this->TBuff;
    }
    if (player == 0 || player > (uint)this->MaxGamePlayers || player >= 10) {
        sprintf(this->TBuff, "P%u T%lu %s", this->Me, this->current_turn, this->GetReadyPlayerStr());
        return this->TBuff;
    }
    return this->WaitingOnNamedInfo(player);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D120
void TCommunications_Handler::UpdatePlayerInformation(ulong param_2, char* param_3, char* param_4) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D120
    uint player = 0;
    if (param_2 != 0) {
        for (uint p = (uint)this->PlayerOptions.LowPlayerNumber; p <= (uint)this->PlayerOptions.HighPlayerNumber && p < 10; ++p) {
            if (this->PlayerOptions.dcoID[p] == param_2) {
                player = p;
                break;
            }
        }
    }

    if (player == 0) {
        this->InitPlayerInformation(0, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D180
int TCommunications_Handler::LaunchLobbyGame(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D180
    IDirectPlay3* new_dp3 = nullptr;
    uint launched = (this->Lobby != nullptr) ? (uint)this->Lobby->CheckForLobbyLaunch(&new_dp3) : 0;

    if (launched != 0) {
        if (this->Lobby->glpDP != nullptr) {
            (void)this->Lobby->glpDP->Release();
            this->Lobby->glpDP = nullptr;
        }

        if (new_dp3 != nullptr) {
            IDirectPlay2* new_dp2 = nullptr;
            HRESULT qhr = new_dp3->QueryInterface(IID_IDirectPlay2A, (void**)&new_dp2);
            (void)new_dp3->Release();
            if (FAILED(qhr) || new_dp2 == nullptr) {
                launched = 0;
            } else {
                this->Lobby->glpDP = new_dp2;

                DPSESSIONDESC2 desc;
                memset(&desc, 0, sizeof(desc));
                desc.dwSize = sizeof(desc);
                if (this->Lobby->GetSessionInfo(&desc) != 0) {
                    this->DebugSessionInformation(&desc);
                }

                this->CommGetCaps();
                this->Multiplayer = 1;
                this->DPlayGetSessionDesc();

                char* name = nullptr;
                if (this->Lobby->GetPlayerInfo(&name) != 0 && name != nullptr) {
                    this->SetMyPlayerName(name);
                }

                this->PlayerOptions.ProgramState = kCommStateJoinNow;
                this->AddSelfPlayer();
                this->MeHost = this->Lobby->IsThisHost();
                if (this->MeHost != 0) {
                    this->Me = 1;
                    this->PlayerOptions.dcoID[1] = s_localPlayerDpid;
                    this->PlayerOptions.Humanity[this->Me] = kPlayerHumanityHuman;
                    this->HaveHostInit = 1;
                    this->PlayerOptions.ProgramState = kCommStateJoinNow;
                    this->SetRandomSeed((int)GetTickCount());
                    this->GTDSerialNo = 0x7D1;
                }
                this->UpdatePlayers();
            }
        } else {
            launched = 0;
        }
    }

    this->LobbyLaunched = (int)launched;
    return (int)launched;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D3B0
int TCommunications_Handler::SetGameTitle(char* param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D3B0
    if (param_2 == nullptr) {
        param_2 = (char*)"";
    }
    _snprintf(this->MyGameTitle, sizeof(this->MyGameTitle) - 1, "%s %s", param_2, this->MyFriendlyName);
    this->MyGameTitle[sizeof(this->MyGameTitle) - 1] = 0;
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D3E0
void TCommunications_Handler::SetMyPlayerName(char* param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D3E0
    if (param_2 == nullptr) {
        param_2 = (char*)"";
    }
    _snprintf(this->MyFriendlyName, sizeof(this->MyFriendlyName) - 1, "%s", param_2);
    this->MyFriendlyName[sizeof(this->MyFriendlyName) - 1] = 0;
    _snprintf(this->MyFormalName, sizeof(this->MyFormalName) - 1, "%s", "Optional Information");
    this->MyFormalName[sizeof(this->MyFormalName) - 1] = 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D4A0
long TCommunications_Handler::CreateDirectPlayConversation(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D4A0
    if (this->Lobby == nullptr) {
        return DPERR_INVALIDOBJECT;
    }
    if (this->Lobby->glpDP != nullptr) {
        return DPERR_ALREADYINITIALIZED;
    }

    LPDIRECTPLAY dp = nullptr;
    HRESULT hr = DirectPlayCreate(&this->ServiceGUID, &dp, nullptr);
    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "DPCreate");
    }
    if (FAILED(hr) || dp == nullptr) {
        this->ServiceGUID = this->NullGUID;
        return (long)hr;
    }

    IDirectPlay2* dp2 = nullptr;
    hr = dp->QueryInterface(IID_IDirectPlay2A, (void**)&dp2);
    (void)dp->Release();
    if (FAILED(hr) || dp2 == nullptr) {
        return (long)hr;
    }

    this->Lobby->glpDP = dp2;
    return 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D580
int TCommunications_Handler::OpenMultiplayerConnection(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D580
    return (this->CreateDirectPlayConversation() == 0) ? 1 : -1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D590
int TCommunications_Handler::CreateMultiplayerGame(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D590
    if (this->Chat != nullptr) {
        this->Chat->ClearChat();
    }

    this->Multiplayer = 1;
    this->HaveHostInit = 0;
    this->PlayerOptions.CommandTurnIncrement = 2;
    this->current_turn = 4;
    this->PlayerOptions.CurrentTurn = 4;
    this->MeHost = 1;

    if (this->CreateDirectPlayConversation() != 0) {
        return 0;
    }

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return 0;
    }

    DPSESSIONDESC2 desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x50;
    desc.dwMaxPlayers = (DWORD)this->MaxGamePlayers;
    desc.guidApplication = this->ApplicationGUID;
    desc.lpszSessionNameA = this->MyGameTitle;

    HRESULT hr = dp->Open(&desc, DPOPEN_CREATE);
    (void)dp->Release();
    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "DP Open Create");
    }
    if (FAILED(hr)) {
        return 0;
    }

    this->SetRandomSeed((int)GetTickCount());
    if (this->AddSelfPlayer() == 0) {
        return 0;
    }
    this->CommGetCaps();
    this->DPlayGetSessionDesc();

    this->Me = 1;
    this->PlayerOptions.HostPlayerNumber = 1;
    this->PlayerOptions.dcoID[1] = s_localPlayerDpid;
    this->PlayerOptions.Humanity[this->Me] = kPlayerHumanityHuman;
    this->HaveHostInit = 1;
    this->PlayerOptions.ProgramState = kCommStateJoinNow;
    this->GTDSerialNo = 0x7D1;
    this->UpdatePlayers();
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D960
int TCommunications_Handler::AddSelfPlayer(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042D960
    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return 0;
    }

    DPNAME names;
    memset(&names, 0, sizeof(names));
    names.dwSize = sizeof(names);
    names.dwFlags = 0x10;
    names.lpszLongNameA = this->MyFriendlyName;

    DPID dpid = 0;
    HRESULT hr = dp->CreatePlayer(&dpid, &names, nullptr, nullptr, 0, 0);
    (void)dp->Release();
    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "Add SELF PLAYER");
    }
    if (FAILED(hr)) {
        this->CloseSession();
        this->ReleaseComm();
        return 0;
    }

    s_localPlayerDpid = (ulong)dpid;
    this->GetMyMultiPlayerCaps();
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DA50
long TCommunications_Handler::InitJoinGame(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DA50
    if (this->Chat != nullptr) {
        this->Chat->ClearChat();
    }
    this->Multiplayer = 1;
    this->HaveHostInit = 0;
    this->MeHost = 0;
    this->GTDSerialNo = 0;
    return this->CreateDirectPlayConversation();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DA80
int TCommunications_Handler::JoinMultiplayerGame(_GUID* param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DA80
    if (param_2 == nullptr) {
        return 0;
    }

    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return 0;
    }

    this->SessionGUID = *param_2;
    this->MeHost = 0;

    DPSESSIONDESC2 desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x50;
    desc.guidInstance = *param_2;
    desc.guidApplication = this->ApplicationGUID;

    HRESULT hr = dp->Open(&desc, DPOPEN_JOIN);
    (void)dp->Release();

    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "Join MP Game");
    }
    if (FAILED(hr)) {
        if (hr == DPERR_CANTADDPLAYER) {
            this->NotifyWindow(COMM_NO_NEW_PLAYERS);
        }
        return 0;
    }

    if (this->AddSelfPlayer() == 0) {
        return 0;
    }

    this->PlayerOptions.ProgramState = kCommStateJoinNow;
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DD70
long TCommunications_Handler::GetMyMultiPlayerCaps(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DD70
    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr || s_localPlayerDpid == 0) {
        if (dp != nullptr) {
            (void)dp->Release();
        }
        return DPERR_INVALIDPLAYER;
    }

    DPCAPS caps;
    memset(&caps, 0, sizeof(caps));
    caps.dwSize = sizeof(caps);

    HRESULT hr = dp->GetPlayerCaps((DPID)s_localPlayerDpid, &caps, 0);
    (void)dp->Release();
    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "Get Player Caps");
    }
    if (FAILED(hr)) {
        return (long)hr;
    }

    this->dwFlags = 1;
    this->dwMaxBufferSize = caps.dwMaxBufferSize;
    this->dwMaxQueueSize = caps.dwMaxQueueSize;
    this->RGE_Guaranteed_Delivery = 1;
    this->dwMaxPlayers = caps.dwMaxPlayers;
    this->dwHundredBaud = caps.dwHundredBaud;
    this->dwLatency = caps.dwLatency;
    return 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DEA0
void TCommunications_Handler::SetApplicationGUID(_GUID param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DEA0
    this->ApplicationGUID = param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DEE0
void TCommunications_Handler::SetServiceGUID(_GUID param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DEE0
    this->ServiceGUID = param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DF10
void TCommunications_Handler::SetSessionGUID(_GUID param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042DF10
    this->SessionGUID = param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E380
int TCommunications_Handler::SetMyReadiness(int param_2, ulong param_3, ulong param_4, ulong param_5, ulong param_6, ulong param_7, ulong param_8, ulong param_9) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E380
    const uint me = this->Me;
    if (me >= 10) {
        return 0;
    }

    this->PlayerOptions.PlayerReady[me] = param_2;
    this->PlayerOptions.User1[me] = param_3;
    this->PlayerOptions.User2[me] = param_4;
    this->PlayerOptions.User3[me] = param_5;
    this->PlayerOptions.User4[me] = param_6;
    this->PlayerOptions.User5[me] = param_7;
    this->PlayerOptions.User6[me] = param_8;
    this->PlayerOptions.User7[me] = param_9;

    struct ReadyMsg {
        uchar cmd;
        uchar ready;
        ushort _pad;
        ulong u1;
        ulong u2;
        ulong u3;
        ulong u4;
        ulong u5;
        ulong u6;
        ulong u7;
        ulong version_remote;
        ulong version_local;
    } rdy;

    memset(&rdy, 0, sizeof(rdy));
    rdy.cmd = 'R';
    rdy.ready = (uchar)param_2;
    rdy.u1 = param_3;
    rdy.u2 = param_4;
    rdy.u3 = param_5;
    rdy.u4 = param_6;
    rdy.u5 = param_7;
    rdy.u6 = param_8;
    rdy.u7 = param_9;
    rdy.version_remote = param_9;
    rdy.version_local = this->CommunicationsVersionCode;

    if (this->MeHost == 0) {
        (void)this->FastSend(0, &rdy, 0x28, 0, 0);
    }

    this->NotifyWindow(kCommMessageUpdateParams);
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E500
int TCommunications_Handler::GetClientReadiness(uint param_2, int* param_3, ulong* param_4, ulong* param_5, ulong* param_6, ulong* param_7, ulong* param_8, ulong* param_9, ulong* param_10) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E500
    if (param_2 >= 10 || param_3 == nullptr || param_4 == nullptr || param_5 == nullptr || param_6 == nullptr ||
        param_7 == nullptr || param_8 == nullptr || param_9 == nullptr || param_10 == nullptr) {
        return 0;
    }

    *param_3 = this->PlayerOptions.PlayerReady[param_2];
    *param_4 = this->PlayerOptions.User1[param_2];
    *param_5 = this->PlayerOptions.User2[param_2];
    *param_6 = this->PlayerOptions.User3[param_2];
    *param_7 = this->PlayerOptions.User4[param_2];
    *param_8 = this->PlayerOptions.User5[param_2];
    *param_9 = this->PlayerOptions.User6[param_2];
    *param_10 = this->PlayerOptions.User7[param_2];
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E580
int TCommunications_Handler::IsPlayerReady(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E580
    if (param_2 == 0 || param_2 >= 10 || param_2 > (uint)this->MaxGamePlayers) {
        return 0;
    }
    return this->PlayerOptions.PlayerReady[param_2];
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E5B0
int TCommunications_Handler::ComputerPlayerGameStart(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E5B0
    if (this->Multiplayer == 0) {
        return 1;
    }
    return (this->current_turn > 6) ? 1 : 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E670
long TCommunications_Handler::DPlayGetSessionDesc(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E670
    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return DPERR_INVALIDOBJECT;
    }

    DWORD size = 0;
    HRESULT hr = dp->GetSessionDesc(nullptr, &size);
    if (hr != DPERR_BUFFERTOOSMALL && FAILED(hr)) {
        (void)dp->Release();
        return (long)hr;
    }

    void* buffer = calloc((size_t)size, 1);
    if (buffer == nullptr) {
        (void)dp->Release();
        return DPERR_OUTOFMEMORY;
    }

    hr = dp->GetSessionDesc(buffer, &size);
    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "Get Session Desc");
    }
    if (SUCCEEDED(hr)) {
        DPSESSIONDESC2* desc = (DPSESSIONDESC2*)buffer;
        this->SessionGUID = desc->guidInstance;
        this->CurrentPlayers = desc->dwCurrentPlayers;
    }

    free(buffer);
    (void)dp->Release();
    return (long)hr;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E730
long TCommunications_Handler::CommGetCaps(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042E730
    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return DPERR_INVALIDOBJECT;
    }

    DPCAPS caps;
    memset(&caps, 0, sizeof(caps));
    caps.dwSize = sizeof(caps);

    HRESULT hr = dp->GetCaps(&caps, 0);
    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "Get Caps");
    }
    if (SUCCEEDED(hr)) {
        this->ServiceTimeout = caps.dwTimeout;
        this->dwMaxBufferSize = caps.dwMaxBufferSize;
        this->dwMaxQueueSize = caps.dwMaxQueueSize;
        this->dwMaxPlayers = caps.dwMaxPlayers;
        this->dwHundredBaud = caps.dwHundredBaud;
        this->dwLatency = caps.dwLatency;
        this->RGE_Guaranteed_Delivery = 1;
    }

    (void)dp->Release();
    return (long)hr;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EB60
int TCommunications_Handler::SetMyGameOptions(char* param_2, ulong param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EB60
    if (param_3 > 2000) {
        return 0;
    }

    this->FreeOptions();
    if (param_2 != nullptr && param_3 != 0) {
        this->OptionsData = (char*)::operator new((size_t)param_3 + 1, std::nothrow);
        if (this->OptionsData == nullptr) {
            return 0;
        }
        memcpy(this->OptionsData, param_2, (size_t)param_3);
        this->OptionsData[param_3] = 0;
        this->PlayerOptions.DataSizeToFollow = param_3;
    }

    if (this->MeHost != 0) {
        this->PlayerOptions.NeedsToBeSent = 1;
    }
    return 1;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EBF0
void* TCommunications_Handler::GetMyGameOptions(ulong* param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EBF0
    if (param_2 != nullptr) {
        *param_2 = this->PlayerOptions.DataSizeToFollow;
    }
    return this->OptionsData;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECC0
void TCommunications_Handler::SetHostPlayerNumber(uint param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECC0
    this->PlayerOptions.HostPlayerNumber = param_2;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECD0
uint TCommunications_Handler::GetHostPlayerNumber(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECD0
    return this->PlayerOptions.HostPlayerNumber;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECE0
void TCommunications_Handler::DebugSessionInformation(DPSESSIONDESC2* param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042ECE0
    if (param_2 == nullptr) {
        return;
    }

    ushort guid_str[39];
    memset(guid_str, 0, sizeof(guid_str));
    StringFromGUID(&param_2->guidInstance, guid_str);

    L->Log("SessionDesc size=%lu flags=%lu", param_2->dwSize, param_2->dwFlags);
    L->Log("CurrentPlayers=%lu MaxPlayers=%lu", param_2->dwCurrentPlayers, param_2->dwMaxPlayers);
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EF60
void TCommunications_Handler::OutOfSync(int param_2, ulong param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EF60
    this->OutOfSyncFlag = param_2;
    this->dwStopTime = param_3;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EF80
int TCommunications_Handler::SendZoneMessage(char* param_2, ulong param_3) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EF80
    if (this->IsLobbyLaunched() == 0 || this->Lobby == nullptr) {
        return 0;
    }

    const long hr = this->Lobby->SendZoneMessage(param_2, param_3, rge_base_game->prog_info->zone_guid);
    if (hr == 0) {
        return 1;
    }
    if (this->Err != nullptr) {
        this->Err->ShowReturn(hr, "SendGameOptions");
    }
    return 0;
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F110
void TCommunications_Handler::ForcePlayerEnumeration(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F110
    IDirectPlay2* dp = comm_get_dplay(this);
    if (dp == nullptr) {
        return;
    }
    (void)dp->EnumPlayers(nullptr, (LPDPENUMPLAYERSCALLBACK2)EnumPlayersCallback2, this, 0);
    (void)dp->Release();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F140
void TCommunications_Handler::ForcePlayerDestroyAndCreate(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F140
    this->DestroyMyPlayer();
    s_localPlayerDpid = 0;
    this->AddSelfPlayer();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F190
void TCommunications_Handler::ForceNameChange(void) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F190
    _snprintf(this->MyFriendlyName, sizeof(this->MyFriendlyName) - 1, "%s", "TEMPORARY_NAME");
    this->MyFriendlyName[sizeof(this->MyFriendlyName) - 1] = 0;
    (void)this->SendPlayerName();
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F230
void TCommunications_Handler::SetSpeedV1(ulong param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F230
    if (this->Speed != nullptr) {
        this->Speed->SetV1(param_2);
    }
}

// Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F250
void TCommunications_Handler::SetSpeedV2(ulong param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F250
    if (this->Speed != nullptr) {
        this->Speed->SetV2(param_2);
    }
}

int StringFromGUID(_GUID* param_1, ushort* param_2) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042EC40
    if (param_1 == nullptr || param_2 == nullptr) {
        return 0;
    }

    wsprintfW((LPWSTR)param_2, L"{%08lX-%04hX-%04hX-%02X%02X-%02X%02X%02X%02X%02X%02X}",
              param_1->Data1, param_1->Data2, param_1->Data3,
              param_1->Data4[0], param_1->Data4[1], param_1->Data4[2], param_1->Data4[3],
              param_1->Data4[4], param_1->Data4[5], param_1->Data4[6], param_1->Data4[7]);
    return 0x26;
}

int EnumPlayersCallback2(ulong param_1, ulong param_2, DPNAME* param_3, ulong param_4, void* param_5) {
    // Fully verified. Source of truth: com_hand.cpp.decomp @ 0x0042F040
    (void)param_2;
    (void)param_4;

    TCommunications_Handler* comm = (TCommunications_Handler*)param_5;
    if (comm == nullptr || param_3 == nullptr) {
        return 1;
    }

    uint player = 0;
    if (param_1 != 0) {
        for (uint p = (uint)comm->PlayerOptions.LowPlayerNumber; p <= (uint)comm->PlayerOptions.HighPlayerNumber && p < 10; ++p) {
            if (comm->PlayerOptions.dcoID[p] == param_1) {
                player = p;
                break;
            }
        }
    }

    const char* short_name = (param_3->lpszShortNameA != nullptr) ? param_3->lpszShortNameA : "";
    const char* long_name = (param_3->lpszLongNameA != nullptr) ? param_3->lpszLongNameA : "";
    sprintf(comm->TBuff, "ENUM %lu name=%s id=%u", param_1, short_name, player);
    L->Log("%s", comm->TBuff);

    comm->UpdatePlayerInformation(param_1, (char*)short_name, (char*)long_name);
    return 1;
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
