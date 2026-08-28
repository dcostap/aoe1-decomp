#include "../third_party/directplay/include/dplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new.h>




#include "../include/com_hand.h"
#include "../include/game_globals.h"
#include "../include/debuglog.h"
#include "../include/basegame.h"
#include "../include/chat.h"
#include "../include/com_q.h"
#include "../include/com_err.h"
#include "../include/com_spd.h"
#include "../include/com_sync.h"
#include "../include/com_loby.h"
#include "../include/main.h"
#include "../include/taunt.h"
#include "../include/world.h"
#include "../include/tworld.h"










void TCommunications_Handler::GameOver(void) {
    this->current_turn = 0;
    if (this->InQ)
        this->InQ->FlushAll();
    if (this->OutQ)
        this->OutQ->FlushAll();
}







char* TCommunications_Handler::WaitingOnNamedInfo(unsigned int playerIndex) {
    sprintf(this->TBuff, "[%d] %s - %s", playerIndex,
        this->GetPlayerName(playerIndex),
        this->WaitingOnInfo(playerIndex));

    int timeSince = debug_timeGetTime(com_hand_source_path, 0x8E)
        - this->LastPlayerCommunication[playerIndex];

    sprintf(this->TBuff, "[%d] %s - %s (QUIET=%d msec  T#=%d )",
        playerIndex,
        this->GetPlayerName(playerIndex),
        this->WaitingOnInfo(playerIndex),
        timeSince,
        this->LastTurnAck[playerIndex]);

    return this->TBuff;
}






char* TCommunications_Handler::WaitingOnInfo(unsigned int param_1)
{
    unsigned int player = param_1;

    if (IsPlayerComputer(player)) {
        rge_base_game->get_string(0x4B1, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (!IsPlayerHuman(player)) {
        rge_base_game->get_string(0x4B2, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (LastTurnAck[player] < 4) {
        rge_base_game->get_string(0x4B3, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (LastTurnAck[player] < current_turn) {
        rge_base_game->get_string(0x4B4, g_status_buffer, 0x20);
        return g_status_buffer;
    }

    rge_base_game->get_string(0x4B0, g_status_buffer, 0x20);
    return g_status_buffer;
}

void TCommunications_Handler::StopIfSyncFail(int flag) {
    this->Sync->SetDialogOnFail(flag);
    this->Sync->SetStopOnFail(flag);
}

void TCommunications_Handler::ShowSyncChatMsgs(int param) {
    this->Sync->SendChatMsgsAtChecksum(param);
}


void TCommunications_Handler::DropPacketsIntentionally(int flag) {
    this->IntentionallyDropPackets = flag;
    if (flag) {
        L->Log("DROPPING PACKETS INTENTIONALLY!!!");
    }
}


void TCommunications_Handler::SetStepMode(int v) { this->StepMode = v; }

void TCommunications_Handler::SetSpeedControl(int param) {
    this->Speed->EnableSpeedControl(param);
}












int TCommunications_Handler::CalculatePlayerRange(void) {
    unsigned int i = 1;
    unsigned short maxPlayers = this->MaxGamePlayers;

    this->PlayerOptions.HighPlayerNumber = 0;
    this->PlayerOptions.LowPlayerNumber = maxPlayers + 1;

    while (static_cast<int>(i) <= static_cast<int>(maxPlayers)) {
        if (this->IsPlayerHuman(i) || this->IsPlayerComputer(i)) {
            int high = static_cast<int>(this->PlayerOptions.HighPlayerNumber);
            if (high <= static_cast<int>(i))
                high = i;
            this->PlayerOptions.HighPlayerNumber = static_cast<unsigned short>(high);

            int low = static_cast<int>(this->PlayerOptions.LowPlayerNumber);
            if (low >= static_cast<int>(i))
                low = i;
            this->PlayerOptions.LowPlayerNumber = static_cast<unsigned short>(low);
        }
        ++i;
    }
    return 1;
}

void TCommunications_Handler::Step(int amount) {
    TEST();
    Steps += amount;
}






























































TCommunications_Handler::TCommunications_Handler(void* hwnd, unsigned char maxPlayers, TChat* chat, GUID appGUID)
{
    L->FlushToDisk(1);

    this->ReturnRXPacketSize = this->RXPacketLength;
    this->RXPacketLengthHigh = this->RXPacketLength > this->RXPacketLengthHigh
        ? this->RXPacketLength : this->RXPacketLengthHigh;
    this->RXPacketLength = 0;

    this->ReturnTXPacketSize = this->TXPacketLength;
    this->TXPacketLengthHigh = this->TXPacketLength > this->TXPacketLengthHigh
        ? this->TXPacketLength : this->TXPacketLengthHigh;

    this->TXPacketLength = 0;
    this->OutQ = 0;
    this->InQ = 0;
    this->GTDSerialNo = 0;
    memset(&this->NullGUID, 0, sizeof(this->NullGUID));

    this->CommunicationsStatus = INITIALIZED;
    this->ApplicationGUID = appGUID;
    this->SessionGUID = this->NullGUID;
    this->ServiceGUID = this->NullGUID;
    this->HostHWND = hwnd;
    this->Chat = chat;
    this->MaxGamePlayers = maxPlayers;

    L->Log("COMM:  RGE COMMUNICTIONS STARTED ---------------%s",
        com_hand_source_path);
    L->Log("COMM:  %s  Version... %s",
        com_hand_source_path, "Fri Jul 17 09:39:38 1998");

    {
        char Codestr[32];
        strcpy(Codestr, "13:17:08");
        if (*Codestr != 0) {
            char* p = Codestr;
            do {
                if (*p == ':') {
                    *p = '0';
                }
                ++p;
            } while (*p != 0);
        }
    }
    this->CommunicationsVersionCode = 0x2E2887;
    int count = maxPlayers + 1;


    {
        NAME* names = new NAME[count];
        NAME* result;
        if (names != 0) {
            NAME* p = names;
            for (int i = 0; i <= count - 1; ++i) {
                strcpy(p->Text, " ");
                ++p;
            }
            result = names;
        } else {
            result = 0;
        }
        this->FriendlyName = result;
    }

    count = maxPlayers + 1;
    {
        NAME* names = new NAME[count];
        NAME* result;
        if (names != 0) {
            NAME* p = names;
            for (int i = 0; i <= count - 1; ++i) {
                strcpy(p->Text, " ");
                ++p;
            }
            result = names;
        } else {
            result = 0;
        }
        this->FormalName = result;
    }


    this->InQ = new RGE_Communications_Queue(0x1F5);
    this->Resend = new RESENDER[0x1F6];
    this->OnHold = new HOLDER[0x1F6];
    this->Err = new RGE_Comm_Error(hwnd);
    this->Lobby = new RGE_Lobby(hwnd);
    this->Speed = new RGE_Communications_Speed(this);
    this->Sync = new RGE_Communications_Synchronize(this);

    unsigned long startTime = debug_timeGetTime(com_hand_source_path, 0x267);

    this->RXPacketLength = 0;
    this->RXPacketLengthHigh = 0;
    this->TXPacketLength = 0;
    this->TXPacketLengthHigh = 0;
    this->lastRXDataRate = 0;
    this->lastTXDataRate = 0;
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

    L->Time();
    this->PlayerOptions.LastSentTime = startTime;

    this->AvgTurnTime = 0;
    this->PauseChangePending = 0;
    this->StepMode = 0;
    this->IntentionallyDropPackets = 0;

    strcpy(this->MyGameTitle, " ");
    strcpy(this->MyFriendlyName, " ");
    strcpy(this->MyFormalName, " ");

    this->TickStart = 0;
    this->TickCount = 0;
    this->LastTimeoutMessageTime = 0;

    this->PlayerOptions.LowPlayerNumber = 1;
    this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
    this->PlayerOptions.GameHasStarted = 0;
    this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
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

    L->Log("Initialize Player List");

    int i;
    for (i = 1; i <= this->MaxGamePlayers; ++i) {
        this->InitPlayerInformation(i, 0, " ", " ");
    }

    this->PlayerOptions.NeedsToBeSent = 0;
    this->PlayerOptions.LastSentTime = 0;

    this->ClearAllSerialNumbers();
    this->ClearRXandTX();

    for (i = 1; i < 10; ++i) {
        this->PlayerStopTurn[i] = 0;
    }

    this->Steps = 1;
    this->ResetLastCommunicationTimes();

    this->WaitingForAck = 0;
    if (this->InQ != 0) {
        this->InQ->FlushAll();
    }
    if (this->OutQ != 0) {
        this->OutQ->FlushAll();
    }

    this->ShuttingDown = 0;

    for (i = 0; i < 10; ++i) {
        this->LastPlayerWarning[i] = 0;
        this->Kicked[i] = 0;
        this->WasKicked[i] = 0;
    }

    this->PlayerOptions.DataSizeToFollow = 0;
    this->OptionsData = 0;
}







































TCommunications_Handler::~TCommunications_Handler() {
    this->DestroyMultiplayerGame();
    this->CloseSession();
    this->ReleaseComm();
    this->FreeOptions();
    delete this->FriendlyName;
    delete this->FormalName;

    unsigned int slot = 0;
    do {
        if (this->Resend[slot].Serial != 0) {
            L->Log("NO MSG Slot#%d  Ser#%d  Len=%d  DEST=%d,%d,%d,%d,%d,%d,%d,%d",
                slot, this->Resend[slot].Serial, this->Resend[slot].Length,
                this->Resend[slot].DestMap[1], this->Resend[slot].DestMap[2], this->Resend[slot].DestMap[3],
                this->Resend[slot].DestMap[4], this->Resend[slot].DestMap[5], this->Resend[slot].DestMap[6],
                this->Resend[slot].DestMap[7], this->Resend[slot].DestMap[8]);
        }
        slot++;
    } while (slot <= 501);

    delete[] this->Resend;
    delete[] this->OnHold;
    delete this->InQ;
    delete this->Lobby;
    delete this->Speed;
    delete this->Sync;
    delete this->Err;
}














void TCommunications_Handler::KillAnyMissingPlayers()
{
    MSGFORMAT_KILL_PLAYER kp;
    char* buf;
    IDirectPlay3* dp;
    unsigned int i = 1;

    if (i <= this->MaxGamePlayers) {
        unsigned long* dcoID = this->PlayerOptions.dcoID + 1;
        do {
            if (this->IsPlayerHuman(i)) {
                dp = direct_play_interface;
                unsigned long name_size = 0;
                dp->GetPlayerName(*dcoID, 0, &name_size);

                buf = new char[name_size];
                dp = direct_play_interface;
                long name_result = dp->GetPlayerName(*dcoID, buf, &name_size);
                delete[] buf;

                if (name_result != 0) {
                    kp.PlayerNo = i;
                    kp.dcoID = *dcoID;
                    kp.CurrentTurn = this->current_turn;
                    L->Log("  >TX KP #%d (%d)", i, 0x0C);
                    this->CommOut(0, 0x4B, &kp.PlayerNo, 0x0C, 0);

                    if (this->PlayerStopTurn[i] == 0) {
                        this->DropDeadPlayer(i, *dcoID);
                    }
                }
            }

            ++i;
            ++dcoID;
        } while (i <= this->MaxGamePlayers);
    }
}
int TCommunications_Handler::AddCommand(unsigned long turn, void* data,
                                        unsigned long size, int from,
                                        unsigned char sequence, int control) {
    return this->InQ->AddItem(turn, data, size, static_cast<unsigned int>(from),
                               sequence, control);
}

RESENDER::RESENDER() {
    this->TimeSent = 0;
    this->Serial = 0;
    this->ResendMsg = 0;
    this->Length = 0;
    for (int i = 0; i < 10; ++i) {
        this->DestMap[i] = 0;
    }
}

void* TCommunications_Handler::get_command(void) {
    if (this->Multiplayer == 0) {
        return this->InQ->GetNextItemSingle();
    }
    if (this->PlayerOptions.ProgramState == 3) {
        return this->InQ->GetNextItemSingle();
    }
    return this->InQ->GetNextItemOrdered(this->current_turn);
}

unsigned char TCommunications_Handler::new_command(void* command, int size) {
    return static_cast<unsigned char>(NewCommand(command, size, 0));
}




int TCommunications_Handler::NewCommand(void* command, int size, int ordered) {
    if (this->Multiplayer != 0) {
        unsigned char command_code;
        memcpy(&command_code, command, sizeof(command_code));
        L->Log("  >TX CMD (%d) Cmd=%d ", size,
               static_cast<int>(command_code));
        long _r = this->CommOut(0, 0x3E, command, size, 0);
        this->Err->ShowReturn(_r, "NewCmnd");
    } else {
        int _t = this->current_turn + this->PlayerOptions.CommandTurnIncrement;
        this->AddCommand(_t, command, size, static_cast<int>(this->Me),
                         this->InQ->GetNextSequence(this->current_turn), ordered);
    }
    return 1;
}



inline RESENDER::~RESENDER() {
    this->TimeSent = 0;
    if (this->ResendMsg != 0) {
        delete[] this->ResendMsg;
    }
    this->ResendMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    for (int i = 0; i < 10; ++i) {
        this->DestMap[i] = 0;
    }
}

HOLDER::HOLDER() {
    this->HoldMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    this->dcoFromID = 0;
    this->dcoReceiveID = 0;
}

void TCommunications_Handler::LastWorldRandom(int param) {
    this->Sync->SetLastWorldRandom(param);
}



inline HOLDER::~HOLDER() {
    if (this->HoldMsg != 0) {
        delete[] this->HoldMsg;
    }
    this->HoldMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    this->dcoFromID = 0;
    this->dcoReceiveID = 0;
}




















































































typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;



int TCommunications_Handler::DoCycle(ulong param_1)
{
    if (this->Multiplayer == 0) {
        return (this->PlayerOptions.ProgramState == COMM_STATE_PAUSE) ? 0 : -1;
    }
    if (this->Me > static_cast<uint>(this->MaxGamePlayers)) {
        return 0;
    }

    ulong now = debug_timeGetTime(com_hand_source_path, 0x20D);
    if (now - comm_last_dump_time >= 5000) {
        L->Log(GetCommInfo(6));
        L->Log(GetCommInfo(5));
        L->Log(GetCommInfo(4));
        L->Log(GetCommInfo(3));
        L->Log(GetCommInfo(2));
        L->Log(GetCommInfo(1));
        comm_last_dump_time = now;
    }

    this->ReceiveGameMessages();
    this->LastPlayerCommunication[this->Me] = now;

    uint doneTurn = static_cast<uint>(this->PlayerOptions.CommandTurnIncrement) + this->current_turn;
    uint turn = this->current_turn;
    if (this->Multiplayer != 0 && this->PlayerOptions.ProgramState != COMM_STATE_JOINNOW &&
        this->LastTurnAck[this->Me] != turn) {
        this->LastTurnAck[this->Me] = turn;
        MSGFORMAT_ALL_DONE doneMsg;
        if (this->current_turn > 6) {

            doneMsg.HighLatencyCenti = this->Speed->GetHighLatencyCenti();
            doneMsg.FrameRateMsec = this->Speed->GetAvgFrameRate();
            this->Speed->SetPlayerTurnSpeed(this->Me, doneMsg.FrameRateMsec,
                                            doneMsg.HighLatencyCenti);
        }
    comm_last_sent_time = debug_timeGetTime(com_hand_source_path, 0xBF9);
        doneMsg.Command = 'D';
        doneMsg.ExecuteOnTurn = doneTurn;
        L->Log("  >TX DONE (%d)", 0x0C);
        this->CommOut(0, 'D', &doneMsg, 0x0C, 0);
    }

    if (this->StepMode != 0) {
        int steps = this->Steps;
        if (steps == 0) {
            return 0;
        }
        this->Steps = steps - 1;
    }

    this->Sync->DoChecksum(this->current_turn);

    if ((this->OutOfSyncFlag == 1) && (param_1 >= this->dwStopTime)) {
        this->NotifyWindowParam(static_cast<COMMMESSAGES>(COMM_SYNC_ERROR), this->dwStopTime);
        return 0;
    }

    uint framesLeft = this->Speed->BufferFramesRemaining();
    if (framesLeft != 0 && this->current_turn > 6) {
        return this->Speed->BufferTimeToUse(this->current_turn);
    }

    uint G = 0;
    int ack = this->AllPlayersAcknowledged();

    if (ack == 0) {
        if (static_cast<int>(this->PlayerOptions.ProgramState) < 5) {
            return 0;
        }

        this->Speed->WaitingOnAcknowledgement();
        now = debug_timeGetTime(com_hand_source_path, 0x259);

        char msg_str[100];
        uint i = 1;
        int selfTimedOutCount;
        int lastAnyPlayerMessage;
        lastAnyPlayerMessage = 0;
        selfTimedOutCount = 0;
        if (this->MaxGamePlayers >= i) {
            do {
                if (this->IsPlayerHuman(i) && i != this->Me) {
                    selfTimedOutCount++;
                    if (G > this->LastPlayerCommunication[i]) {

                    } else {
                        G = this->LastPlayerCommunication[i];
                    }
                    ulong elapsed = now - this->LastPlayerCommunication[i];
                    if (elapsed > 60000) {
                        lastAnyPlayerMessage++;
                    }
                    if (elapsed > 25000 && now - this->LastPlayerWarning[i] > 25000) {
                        this->LastPlayerWarning[i] = now;
                        this->NotifyWindowParam(static_cast<COMMMESSAGES>(COMM_PLAYER_NOT_RESPONDING), i);
                    }
                    int timedOut = 0;
                    if (this->current_turn <= 7 && elapsed > 98000) {
                        L->Log("+++Timeout pregrame, turn=%d PlayerTimeout=%d", this->current_turn, elapsed);
                        timedOut = 1;
                    }
                    if (this->current_turn > 7 && elapsed > 0x1DA9C && this->MeHost != 0) {
                        L->Log("+++Timeout host, turn=%d PlayerTimeout=%d", this->current_turn, elapsed);
                        timedOut = 1;
                    }
                    if (this->current_turn > 7 && elapsed > 0x1D6B4) {
                        L->Log("+++Timeout player, turn=%d PlayerTimeout=%d", this->current_turn, elapsed);
                        timedOut = 1;
                    }
                    if (timedOut) {
                        L->Log("Player timed out with %d msec elapsed", elapsed);
                        L->Log("Recommend player '%d' drop.", i);
                        if (this->MeHost != 0) {
                            L->Log("Player %d Turn#%d  timeout = %d ", i, this->current_turn, elapsed);
                            RGE_Base_Game* base_game = rge_base_game;
                            base_game->get_string(0x4BA, msg_str, 0x64);
                            sprintf(this->TBuff, msg_str, this->GetPlayerName(i), i);
                            if (this->current_turn > 6) {
                                this->SendChatMsgAll(this->TBuff);
                            }
                            L->Log(this->TBuff);
                            this->Kicked[i] = 1;
                            this->Kick(i);
                        }
                        this->LastPlayerCommunication[i] = now;
                        this->LastPlayerWarning[i] = now;
                    }
                }
                i++;
            } while (i <= static_cast<unsigned int>(this->MaxGamePlayers));
        }

        ++selfTimedOutCount;
        if ((selfTimedOutCount == 3 && lastAnyPlayerMessage >= 2) ||
            (selfTimedOutCount != 3 &&
             lastAnyPlayerMessage >= selfTimedOutCount / 2)) {


            L->Log("I Dropped myself.");
            this->NotifyWindowParam(static_cast<COMMMESSAGES>(COMM_PLAYER_DROPPED), this->Me);
            i = 1;
            if (this->MaxGamePlayers >= i) {
                int* wk = &this->WasKicked[1];
                do {
                    *wk = 1;
                    i++;
                    wk++;
                } while (i <= static_cast<uint>(this->MaxGamePlayers));
            }
            static_cast<TRIBE_World*>(rge_base_game->world)->send_zone_score_info();
            L->Log("Initialize Player List");
            i = 1;
            if (this->MaxGamePlayers >= i) {
                do {
                    this->InitPlayerInformation(i, 0, " ", " ");
                    i++;
                } while (static_cast<int>(i) <= static_cast<int>(this->MaxGamePlayers));
            }
            this->PlayerOptions.NeedsToBeSent = 0;
            this->PlayerOptions.LastSentTime = 0;
            this->UpdatePlayers();
            return 0;
        }

        {
            ulong lastTimeout = this->LastTimeoutMessageTime;
            if (G > this->LastTimeoutMessageTime) {
                lastTimeout = G;
            }
            if (now - lastTimeout > 25000) {
                this->CheckPingTime(1);
                this->LastTimeoutMessageTime = debug_timeGetTime(com_hand_source_path, 0x2DF);
            }
            this->Speed->Skip();
            return 0;
        }
    }


    if (this->PlayerOptions.ProgramState != COMM_STATE_RUNNING) {
        return 0;
    }
    this->Speed->ReloadBufferFrames();
    uint WT = 0;
    uint Fr = 0;
    if (this->MeHost != 0) {
        this->Speed->AnalyzeGameSpeed(&WT, &Fr, 1);
    }
    this->current_turn++;
    L->Log("....Starting Turn#%d, WT=%d, Fr=%d, Gr=%d", this->current_turn, param_1, WT, Fr);
    this->CheckPlayerStopTurn(this->current_turn);
    return this->Speed->GetBufferGranularityAdjusted();
}

int TCommunications_Handler::HasKicked(unsigned int idx) { return this->Kicked[idx]; }




































long TCommunications_Handler::SendPlayerName()
{
    DPNAME dpnSetName;
    memset(&dpnSetName, 0, sizeof(dpnSetName));
    dpnSetName.lpszShortNameA = this->MyFriendlyName;
    dpnSetName.lpszLongNameA = this->MyFormalName;
    dpnSetName.dwSize = sizeof(dpnSetName);
    long result = direct_play_interface->SetPlayerName(local_player_dpid, &dpnSetName, 2);
    this->Err->ShowReturn(result, "Send Player Name");
    return result;
}

void TCommunications_Handler::LogRXMsg(unsigned int param_1, unsigned int param_2, unsigned long param_3, unsigned char param_4, unsigned char param_5)
{
    if (this->RGE_Guaranteed_Delivery != 0) {
        L->Log("GTD: RX Ser#%d From P#%d T#%ld ToExecT#%d %d", param_1, param_2, this->current_turn, param_3, param_4, param_4, param_5);
    }
}


























typedef unsigned long ulong;


void TCommunications_Handler::ReceiveGameMessages()
{
    int zero = 0;

    if (this->Multiplayer == zero) {
        return;
    }

    if ((comm_rate_initialized & 1) == 0) {
        comm_rate_initialized = static_cast<unsigned char>(comm_rate_initialized | 1);
        comm_last_rate_update = debug_timeGetTime(com_hand_source_path, 0x396);
    }

    ulong now = debug_timeGetTime(com_hand_source_path, 0x397);
    unsigned int elapsed = now - comm_last_rate_update;
    if (elapsed > 1000) {
        L->Log("TX: %ld  RX: %ld  elapsed: %ld  totTX: %ld  totRX: %ld",
                     this->TXPacketLength - comm_last_tx_bytes,
                     this->RXPacketLength - comm_last_rx_bytes,
                     elapsed,
                     this->TXPacketLength,
                     this->RXPacketLength);
        this->lastTXDataRate = (static_cast<float>(this->TXPacketLength - comm_last_tx_bytes) * 1000.0f) / static_cast<float>(elapsed);
        this->lastRXDataRate = (static_cast<float>(this->RXPacketLength - comm_last_rx_bytes) * 1000.0f) / static_cast<float>(elapsed);
        comm_last_rate_update = now;
        comm_last_tx_bytes = this->TXPacketLength;
        comm_last_rx_bytes = this->RXPacketLength;
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        this->ExecuteIncoming();
    }

    int read_messages = 1;
    unsigned long current_dplay_id = local_player_dpid;
    if (current_dplay_id != 0) {
        IDirectPlay3* current_dplay = direct_play_interface;
        unsigned long wait_count = zero;
        long result = current_dplay->GetMessageCount(current_dplay_id,
                                                      &wait_count);
        if (result != zero) {
            this->Err->ShowReturn(result, "MsgWait");
            read_messages = 0;
        } else if (wait_count == zero) {
            read_messages = 0;
        }
    }

    if (read_messages != 0) {
        this->GetDPLAYMessages();
        if (this->RGE_Guaranteed_Delivery != 0) {
            this->ExecuteIncoming();
        }
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        this->SendStoredMessages();
    }
    this->CheckPingTime(zero);
}

void TCommunications_Handler::ShutdownGameMessages() {
    this->ShuttingDown = 1;
    this->ReceiveGameMessages();
}






































typedef unsigned long ulong;

void TCommunications_Handler::GetDPLAYMessages() {
    ulong dcoFromID;
    ulong dcoReceiveID;
    ulong dwCount;
    ulong dwPreSize;
    ulong dwSize;
    ulong local_4;
    long hr;
    IDirectPlay3* guard_dplay = direct_play_interface;
    dcoFromID = 0;
    dcoReceiveID = 0;
    if (guard_dplay == 0) return;
    dwCount = 4000;
    dwSize = 4000;
    char* buf = this->InCommBuff;
    local_4 = debug_timeGetTime(com_hand_source_path, 0x3d4);
    dwPreSize = 0;
    hr = direct_play_interface->GetMessageCount(local_player_dpid, &dwPreSize);
    if (hr == 0 && dwPreSize > 10) L->Log("!!! DPMsgCount = %u", dwPreSize);
    while (1) {
        ulong t = debug_timeGetTime(com_hand_source_path, 0x3e1);
        hr = direct_play_interface->Receive(&dcoFromID, &dcoReceiveID, 8, 0, &dwCount);
        ulong elapsed = debug_timeGetTime(com_hand_source_path, 0x3ec) - t;
        if (elapsed > 50) L->Log("!!! Receive Peek slow - %u msec", elapsed);

        if (hr == 0 && dwCount >= 4000) { L->Log("True overflow %d requested.  Max = %d", dwSize, 4000); return; }
        dwSize = dwCount;
        if (hr != 0) dwSize = 4000;
        t = debug_timeGetTime(com_hand_source_path, 0x403);
        hr = direct_play_interface->Receive(&dcoFromID, &dcoReceiveID, 1, buf, &dwSize);
        elapsed = debug_timeGetTime(com_hand_source_path, 0x40c) - t;
        if (elapsed > 50) L->Log("!!! Receive slow - %u msec", elapsed);
        elapsed = debug_timeGetTime(com_hand_source_path, 0x417) - local_4;
        if (elapsed > 500) {
            ulong now = debug_timeGetTime(com_hand_source_path, 0x419);
            L->Log("!!! In Receive Loop for %u ms", now - local_4);
        }
        if (hr == static_cast<long>(0x887700BE)) return;
        if (dwSize == 0) return;
        if (hr != 0) { this->Err->ShowReturn(hr, "Rcv MSG"); return; }
        int pno = 0;
        if (dcoFromID != 0) {
            int i = this->PlayerOptions.LowPlayerNumber;
            int hi = this->PlayerOptions.HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->PlayerOptions.dcoID + i;
                for (; i <= hi; i++, p++) {
                    if (*p == dcoFromID) {
                        pno = i;
                        break;
                    }
                }
            }
        }
        L->Log("  >RX #%d %c-%d (%u)", pno, static_cast<int>(*buf), static_cast<int>(*buf), dwSize);
        int pno2 = 0;

        if (dcoFromID != 0) {
            int i = this->PlayerOptions.LowPlayerNumber;
            int hi = this->PlayerOptions.HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->PlayerOptions.dcoID + i;
                for (; i <= hi; i++, p++) {
                    if (*p == dcoFromID) {
                        pno2 = i;
                        break;
                    }
                }
            }
        }
        L->Log("COMM: RX P#%d ID(%ld) siz=%db   MSG=%d '%c'", pno2, dcoFromID, dwSize, static_cast<int>(*buf), static_cast<int>(*buf), debug_timeGetTime(com_hand_source_path, 0x435));
        this->RXPacketLength += dwSize;
        this->RXPackets++;

        this->InCommBuff[dwSize] = 0;
        if (dcoFromID != 0) this->PreprocessMessages(dwSize, buf, dcoFromID, dcoReceiveID, 0);
        else {
            this->EvaluateSystemMessage(dwSize, buf, 0, dcoReceiveID);
            return;
        }
    }
}






void TCommunications_Handler::CheckPingTime(int param_1) {
    if (!this->Multiplayer)
        return;

    unsigned long currentTime = debug_timeGetTime(com_hand_source_path, 0x460);

    unsigned int i = 1;
    if (static_cast<unsigned int>(this->MaxGamePlayers) < i)
        return;

    do {
        if (this->IsPlayerHuman(i) && i != static_cast<unsigned int>(this->Me)) {
            unsigned long elapsed = currentTime - this->LastTXPing[i];
            if (elapsed > 8000 || param_1) {
                this->TXPing(i);
            }
        }
        i++;
    } while (i <= static_cast<unsigned int>(this->MaxGamePlayers));
}

int TCommunications_Handler::TXPing(unsigned int param_1) {
    unsigned long t = debug_timeGetTime(com_hand_source_path, 0x470);
    unsigned int id = param_1;
    unsigned long dco;

    comm_ping_packet.Command = '1';
    comm_ping_packet.Timestamp = t;
    comm_ping_packet.Turn = this->current_turn;

    if (id == 0) {
        unsigned int i = 1;
        if (this->MaxGamePlayers >= 1) {
            do {
                this->LastTXPing[i] = t;
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        dco = 0;
    } else {
        this->LastTXPing[id] = t;
        dco = this->PlayerOptions.dcoID[id];
    }

    L->Log("  >TX PING #%d (%d)", id, 0x0C);

    long result = this->FastSend(dco, &comm_ping_packet, 0x0C, 0, 0);

    return (result == 0) ? 1 : 0;
}




int TCommunications_Handler::TXDebugPing(void) {
    comm_debug_ping.Command = 0x33;

    unsigned long t = debug_timeGetTime(com_hand_source_path, 0x496);
    comm_debug_ping.Timestamp = t;
    comm_debug_ping.Turn = this->current_turn;

    L->Log("  >TX DEBUG PING #%d (%d)", 0, 0x0C);

    long result = this->FastSend(0, &comm_debug_ping.Command, 0x0C, 0, 0);
    return (result == 0);
}







long TCommunications_Handler::FastSend(unsigned long to, void* data, unsigned long size, int param_4, int param_5) {
    unsigned long start;
    long hr;
    unsigned long elapsed;
    int recipients;
    unsigned int i;

    if (to == local_player_dpid) {
        L->Log("No send-to-self FastTX");
        return E_FAIL;
    }
    if (local_player_dpid == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return E_FAIL;
    }

    start = debug_timeGetTime(com_hand_source_path, 0x4CA);
    hr = direct_play_interface->Send(local_player_dpid, to, 0, data, size);
    elapsed = debug_timeGetTime(com_hand_source_path, 0x4D3) - start;
    if (elapsed > 0x32) {
        L->Log("!!!FastSend slow - %ld msec", elapsed);
    }

    recipients = static_cast<int>(to);
    if (recipients == 0) {
        recipients = 0;
        for (i = 1; i <= MaxGamePlayers; ++i) {
            if (IsPlayerHuman(i) != 0 && i != Me) {
                ++recipients;
            }
        }
    } else {
        recipients = 1;
    }

    TXPacketLength += recipients * size;

    if (hr == E_INVALIDARG) {
        L->Log("FastTX to invalidparams ignored");
        return hr;
    }
    if (hr != 0) {
        Err->ShowReturn(hr, "FastTX");
    }
    return hr;
}































































typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned char uchar;








int TCommunications_Handler::PreprocessMessages(ulong param_1, char* message,
                                                 ulong from, ulong to, int cached)
{
    char msg[256];
    char msg_str[100];
    MSGFORMAT_HEADER_GUARANTEED header;
    memcpy(&header, message, sizeof(header));
    unsigned int player = 0;
    if (from != 0) {
        int first = this->PlayerOptions.LowPlayerNumber;
        int last = this->PlayerOptions.HighPlayerNumber;
        for (int i = first; i <= last; ++i) {
            if (this->PlayerOptions.dcoID[i] == from) {
                player = i;
                break;
            }
        }
    }
    if (header.Command == 'I') {
        this->UnlinkToLevel(SERVICE_AVAILABLE);
        this->NotifyWindow(COMM_UPDATE_PLAYERS);
        this->NotifyWindow(COMM_PLAYER_KICKED);
        return 1;
    }
    if (player == 0) {
        MSGFORMAT_ACKNOWLEDGE_GUARANTEED bad_ack;
        bad_ack.Command = 'A';
        bad_ack.Serialno = header.Serialno;
        L->Log("Bad player # for ID=%d", from);
        if (local_player_dpid == 0) {
            L->Log("+++BAD DCOID=0 NO TX");
            return 0;
        }
        direct_play_interface->Send(local_player_dpid, from, 0,
                                    &bad_ack, sizeof(bad_ack));
        this->TXPacketLength += sizeof(bad_ack);
        return 0;
    }
    this->LastPlayerCommunication[player] =
        debug_timeGetTime(com_hand_source_path, 0x543);
    L->Log("PREPRO-Byte0='%c' from=%d(%d) ser#%d timeGetTime=%d",
           static_cast<int>(header.Command), player, from, header.Serialno,
           debug_timeGetTime(com_hand_source_path, 0x54D));
    switch (header.Command) {
    case 'K': {
        MSGFORMAT_KILL_PLAYER kill_message;
        memcpy(&kill_message, message + sizeof(header), sizeof(kill_message));
        L->Log("KILL Message recieved from %d to kill dcoID #%d ",
               from, kill_message.dcoID);
        if (header.Serialno == this->PlayerHighSerialNumber[player] + 1)
            this->PlayerHighSerialNumber[player] = header.Serialno;
        this->TXAcknowledgeMessage(header.Serialno, player);
        this->PlayerHighSerialNumber[kill_message.PlayerNo] =
            kill_message.PlayerNo * 2000;
        if (kill_message.dcoID == local_player_dpid) {
            this->NotifyWindow(COMM_PLAYER_KICKED);
            return 1;
        }
        break;
    }
    case 'C': {
        MSGFORMAT_CHAT chat;
        char* chat_data = message +
            (this->RGE_Guaranteed_Delivery != 0 ? sizeof(header) : 8);
        memcpy(&chat, chat_data, sizeof(chat));
        if (chat.Pregame != 0 && this->PlayerOptions.ProgramState != COMM_STATE_JOINNOW) {
            L->Log("DISCARD: ChtPregame=%d PgmState=%d Msg=%s",
                   chat.Pregame, this->PlayerOptions.ProgramState, chat.ChatMsg);
            return 0;
        }
        L->Log("CHAT: ChtPregame=%d PgmState=%d Msg=%s", chat.Pregame,
               this->PlayerOptions.ProgramState, chat.ChatMsg);
        break;
    }
    case 'A': {
        MSGFORMAT_ONTURN acknowledge;
        memcpy(&acknowledge, message + 4, sizeof(acknowledge));
        this->RXAcknowledgeStoredMessage(acknowledge.ExecuteOnTurn, player);
        this->PurgeAcknowledgedStoredMessages();
        return 1;
    }
    case 'R': {
        MSGFORMAT_SETREADYOPTIONS ready_message;
        memcpy(&ready_message, message, sizeof(ready_message));
        L->Log("PLAYER READY MSG");
        if (this->MeHost == 0)
            return 1;
        this->PlayerOptions.PlayerReady[player] = ready_message.Ready;
        this->PlayerOptions.User1[player] = ready_message.User1;
        this->PlayerOptions.User2[player] = ready_message.User2;
        this->PlayerOptions.User3[player] = ready_message.User3;
        this->PlayerOptions.User4[player] = ready_message.User4;
        this->PlayerOptions.User5[player] = ready_message.User5;
        this->PlayerOptions.User6[player] = ready_message.User6;
        this->PlayerOptions.User7[player] = ready_message.User7;
        if (!this->IsPlayerHuman(player))
            this->SetPlayerHumanity(player, ME_HUMAN);
        if (this->CommunicationsVersionCode == ready_message.CommunicationsVersionCode)
            L->Log("Communications versions for HOST and player %d match (%d)", player, this->CommunicationsVersionCode);
        else {
            this->NotifyWindowParam(COMM_PLAYER_SERVICE_ERROR, player);
            sprintf(this->TBuff, "Player %d has a different Communications Version than you.", player);
            L->Log(this->TBuff);
        }
        this->PlayerOptions.NeedsToBeSent = 1;
        this->SendSharedData(0);
        this->UpdatePlayer(player, 0);
        this->NotifyWindow(COMM_UPDATE_PLAYERS);
        return 1;
    }
    case '1':
    case '3':
    case '2':
    case '4': {
        MSGFORMAT_LATENCY latency;
        memcpy(&latency, message, sizeof(latency));
        ulong turn = this->current_turn;
        latency.CurrentTurn = turn;
        if (header.Command == '1') {
            latency.Command = '2';
            L->Log("  >TX PONG #%d (%d)", player, sizeof(latency));
        } else if (header.Command == '3') {
            latency.Command = '4';
            L->Log("  >TX DEBUG PONG #%d (%d)", player, sizeof(latency));
        } else if (header.Command == '2') {
            this->Speed->SetActualLatency(player,
                debug_timeGetTime(com_hand_source_path, 0x672) - latency.Initiated);
            return 1;
        } else {
            sprintf(msg, "%s #%d Debug ping - elapsed=%d",
                    this->GetPlayerName(player), player,
                    debug_timeGetTime(com_hand_source_path, 0x68B) - latency.Initiated);
            L->Log(msg);
            this->Chat->AddChatMsg("DEBUG", msg, 0);
            return 1;
        }
        long result = this->FastSend(this->PlayerOptions.dcoID[player],
                                     &latency, sizeof(latency), 0, 0);
        this->Err->ShowReturn(result, header.Command == '1' ? "TX Ping" : "TX Debug Ping");
        return 1;
    }
    case '?': {
        MSGFORMAT_ONTURN missing_message;
        memcpy(&missing_message, message + 4, sizeof(missing_message));
        if (this->MeHost == 0)
            return 1;
        unsigned int missing_player = 0;
        for (int i = this->PlayerOptions.LowPlayerNumber;
             i <= this->PlayerOptions.HighPlayerNumber; ++i) {
            if (this->PlayerOptions.dcoID[i] == missing_message.ExecuteOnTurn) {
                missing_player = i;
                break;
            }
        }
        if (this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
            this->PlayerOptions.PlayerReady[missing_player] = 0;
            this->PlayerOptions.InvalidPlayer[missing_player] = 1;
            this->PlayerOptions.NeedsToBeSent = 1;
        } else {
            this->Kick(missing_player);
        }
        return 1;
    }
    case 'Y': {
        MSGFORMAT_ONTURN serial_message;
        memcpy(&serial_message, message + 4, sizeof(serial_message));
        if (this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
            this->PlayerHighSerialNumber[player] = serial_message.ExecuteOnTurn;
            this->ClearRXForPlayer(player);
            return 1;
        }
        break;
    }
    default:
        break;
    }
    if (this->RGE_Guaranteed_Delivery != 0) {
        if (this->IntentionallyDropPackets != 0 && this->current_turn > 6) {
            ++comm_drop_count;
            if (comm_drop_count > 8) {
                rge_base_game->get_string(0x4BC, msg_str, 100);
                sprintf(this->TBuff, msg_str, header.Serialno,
                        static_cast<int>(header.Command), static_cast<int>(header.Command));
                L->Log(this->TBuff);
                comm_drop_count = 0;
                return 1;
            }
        }
        if (header.Command == 'X') {
            this->TXResendReply(header.ExecuteOnTurn, player);
            return 1;
        }
        if (this->PlayerHighSerialNumber[player] == 0)
            this->PlayerHighSerialNumber[player] = header.Serialno - 1;
        unsigned int next_serial = this->PlayerHighSerialNumber[player] + 1;
        if (header.Serialno < next_serial) {
            this->TXAcknowledgeMessage(header.Serialno, player);
            return 1;
        }
        if (next_serial < header.Serialno) {
            ++this->DroppedPacketCount;
            this->StoreIncoming(header.Serialno, message, param_1, from, to);
            this->TXAcknowledgeMessage(header.Serialno, player);
            this->TXResendRequest(next_serial, player);
            return 1;
        }
        if (cached == 0)
            this->TXAcknowledgeMessage(header.Serialno, player);
        comm_receive_base = param_1 - sizeof(header);
        this->PlayerHighSerialNumber[player] = header.Serialno;
        comm_receive_message = message + sizeof(header);
    } else {
        this->LogRXMsg(header.Serialno, player, header.ExecuteOnTurn,
                       header.Command, header.Sequence);
        comm_receive_base = param_1 - 8;
        comm_receive_message = message + 8;
    }
    if (this->ShuttingDown == 0)
        this->EvaluatePlayerMessage(param_1, player, header.ExecuteOnTurn,
                                    header.Command, header.Sequence,
                                    comm_receive_message, comm_receive_base,
                                    from, to);
    return 1;
}

void TCommunications_Handler::NotifyWindow(COMMMESSAGES p) {
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(p), 0);
}

void TCommunications_Handler::NotifyWindowParam(COMMMESSAGES msg, long param) {
    PostMessageA(this->HostHWND, 0x400, msg, param);
    L->Log("COMM: Send msg to window WM_USER  Msg=%d  Param=%d\n", msg, param);
}







































int TCommunications_Handler::EvaluatePlayerMessage(unsigned long size,
                                                   unsigned int player,
                                                   unsigned long turn,
                                                   unsigned char opcode,
                                                   unsigned char flags,
                                                   char* data,
                                                   unsigned int length,
                                                   unsigned long from,
                                                   unsigned long to)
{
    if (!this->Multiplayer)
        return 0;
    switch (opcode) {
    case 0x44: {
        MSGFORMAT_ALL_DONE done;
        memcpy(&done, data, sizeof(done));
        this->Speed->SetPlayerTurnSpeed(player, done.FrameRateMsec,
                                        done.HighLatencyCenti);
        if ((this->PlayerOptions.ProgramState < COMM_STATE_RUNNING ||
             this->current_turn < 6) && done.ExecuteOnTurn < this->current_turn) {
            L->Log("+++REGRESSION WARNING, Current=%d ExecuteOnTurn=%d",
                   this->current_turn, done.ExecuteOnTurn);
            return 0;
        }
        unsigned int next = done.ExecuteOnTurn -
            this->PlayerOptions.CommandTurnIncrement;
        if (next < this->LastTurnAck[player])
            next = this->LastTurnAck[player];
        this->LastTurnAck[player] = next;
        return 1;
    }
    case 0x51: {
        MSGFORMAT_ONTURN stop_turn;
        memcpy(&stop_turn, data, sizeof(stop_turn));
        this->SetPlayerStopTurn(player, stop_turn.ExecuteOnTurn);
        return 1;
    }
    case 0x4D: {
        MSGFORMAT_CHECKSUM checksum;
        memcpy(&checksum, data, sizeof(checksum));
        this->Sync->Add(player, checksum.WorldTime, checksum.WorldTurn,
                        checksum.Random, checksum.cs1, checksum.cs2,
                        checksum.cs3, checksum.cs4, checksum.cs5);
        return 1;
    }
    case 0x3E:
        this->AddCommand(turn, data, size, static_cast<int>(player), flags, 0);
        return 1;
    case 0x53: {
        MSGFORMAT_SPEEDCHANGE speed_change;
        memcpy(&speed_change, data, sizeof(speed_change));
        this->Speed->SetFutureSpeedChange(speed_change.BufferFrames,
                                           speed_change.FrameSizeMsec, turn);
        return 1;
    }
    case 0x43: {
        MSGFORMAT_CHAT chat;
        memcpy(&chat, data, sizeof(chat));
        L->Log("CHAT-RX from P#%d(%d) RXID=%d Chat content='%s' MsgSize=%d TotalSize=%d pregame=%d",
               player, from, to, chat.ChatMsg, chat.TextSize, length,
               chat.Pregame);
        if (chat.DestPlayers[this->Me] == 'Y' ||
            this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
            this->Chat->AddChatMsg(this->FriendlyName[chat.FromGamerID].Text,
                                   chat.ChatMsg, 0);
        }
        return 1;
    }
    case 0x50:
        L->Log("P#%d Requested pause", player);
        this->LocalPauseGame(player);
        this->Sync->LogChecksums(0, 0, 0, 0, 0, 0, 0, 0, 0);
        return 1;
    case 0x55:
        L->Log("Resume msg rcvd");
        this->LocalResumeGame(player);
        return 1;
    case 0x2B:
        if (this->MeHost) {
            this->SendPauseGame(0);
            this->LocalResumeGame(player);
            return 1;
        }
        break;
    case 0x57:
        if (this->MeHost) {
            this->SendPauseGame(1);
            this->LocalPauseGame(player);
            return 1;
        }
        break;
    case 0x4B: {
        MSGFORMAT_KILL_PLAYER kill_message;
        memcpy(&kill_message, data, sizeof(kill_message));
        L->Log("KILL Message recieved from %d to kill P#%d ",
               player, kill_message.PlayerNo);
        int found = 0;
        if (kill_message.dcoID != 0) {
            for (int i = this->PlayerOptions.LowPlayerNumber;
                 i <= this->PlayerOptions.HighPlayerNumber; ++i) {
                if (this->PlayerOptions.dcoID[i] == kill_message.dcoID) {
                    found = i;
                    break;
                }
            }
        }
        if (found != 0) {
            if (this->PlayerStopTurn[found] == 0)
                this->DropDeadPlayer(found, kill_message.dcoID);
            if (found == this->Me) {
                this->NotifyWindow(COMM_PLAYER_KICKED);
                return 1;
            }
            if (this->PlayerStopTurn[found] == 0) {
                this->NotifyWindowParam(COMM_OTHER_PLAYER_DROPPED, found);
                return 1;
            }
        }
        break;
    }
    case 0x4E:
        if (!this->MeHost) {
            L->Log("Host requested we delete and recreate our player");
            return 1;
        }
        break;
    default:
        L->Log("Unknown message : %d '%c'", static_cast<unsigned int>(opcode),
               static_cast<unsigned int>(opcode));
        break;
    }
    return 1;
}

void TCommunications_Handler::SetPlayerStopTurn(unsigned int i, unsigned long v) {
    this->PlayerStopTurn[i] = v;
}









void TCommunications_Handler::CheckPlayerStopTurn(unsigned long turn)
{
    int StopPending = 0;
    unsigned int i = 1;

    if (this->MaxGamePlayers >= i) {
        do {
            if (this->PlayerStopTurn[i] != 0)
                StopPending = 1;

            if (this->PlayerStopTurn[i] == turn) {
                L->Log("CheckPlayerStopTurn: Drop player %d on turn %d", i, turn);
                this->InitPlayerInformation(i, 0, "Resigned", " ");
                this->SetPlayerHumanity(i, static_cast<PLAYERHUMANITY>(3));
                this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B4), i);
                this->PlayerStopTurn[i] = 0;
            }
            ++i;
        } while (i <= this->MaxGamePlayers);
    }

    if (this->current_turn > 6 && StopPending == 0) {
        StopPending = 0;
        i = 1;
        if (this->MaxGamePlayers >= i) {
            do {
                if (this->IsPlayerHuman(i) || this->IsPlayerComputer(i)) {
                    if (i != this->Me)
                        StopPending = 1;
                }
                ++i;
            } while (i <= this->MaxGamePlayers);
        }
        if (StopPending == 0)
            this->NotifyWindow(COMM_NO_OTHER_HUMANS);
    }
}

void TCommunications_Handler::ReleaseSettings() { this->PlayerOptions.NeedsToBeSent = 0; }





long TCommunications_Handler::SendSharedData(int force)
{
    if (direct_play_interface == 0) {
        return 0;
    }
    if (this->MeHost == 0) {
        return 0;
    }

    unsigned long now = debug_timeGetTime(com_hand_source_path, 0x895);

    if (force != 0) {
        this->PlayerOptions.NeedsToBeSent = 1;
    } else {
        if (now - this->PlayerOptions.LastSentTime < 2000) {
            return 0;
        }
    }

    if (this->PlayerOptions.NeedsToBeSent == 0) {
        return 0;
    }

    if (local_player_dpid == 0) {
        L->Log("No DCOID for Send Shared Data");
        return 0x80004005;
    }

    L->Log("Sending Shared Data");

    unsigned int packet_size = this->PlayerOptions.DataSizeToFollow + 0x1D0;
    this->PlayerOptions.LastSentTime = now;
    char* packet = new char[packet_size];

    memcpy(packet, &this->PlayerOptions, sizeof(COMMPLAYEROPTIONS));
    memcpy(packet + sizeof(COMMPLAYEROPTIONS), this->OptionsData,
           this->PlayerOptions.DataSizeToFollow);

    long hr = direct_play_interface->SetPlayerData(local_player_dpid, packet,
                                           packet_size, 2);
    this->Err->ShowReturn(hr, "Send Shared Data");
    delete[] packet;

    this->PlayerOptions.NeedsToBeSent = 0;
    this->NotifyWindow(COMM_SHARED_DATA_SENT);

    unsigned int i = 1;
    if (this->MaxGamePlayers >= 1) {
        do {
            this->PlayerOptions.InvalidPlayer[i] = 0;
            i++;
        } while (i <= this->MaxGamePlayers);
    }

    return hr;
}




int TCommunications_Handler::TEST()
{
    TTaunt* taunt;

    taunt = new TTaunt(sound_driver);

    {
        int rand_val = debug_rand(com_hand_source_path, 0x8F2);
        int log_val = (rand_val * 15) / 0x7FFF;
        L->Log("Playing Taunt #%d", log_val);
    }

    taunt->PlayTauntNo(4);

    if (taunt) {
        delete taunt;
    }

    return 1;
}









void TCommunications_Handler::SetSelfPlayer()
{
    for (unsigned int i = 1; i <= this->MaxGamePlayers; ++i) {


        unsigned long dco = this->PlayerOptions.dcoID[i];
        L->Log("Check dcoID %d to Me %d ?", dco, local_player_dpid);

        if (dco == local_player_dpid) {
            L->Log("Match! - ID set.");
            this->Me = i;
            this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B8), i);
            return;
        }
    }

    L->Log("SET SELF failed.  We are DCOID=%d", local_player_dpid);
}






void TCommunications_Handler::DropDeadPlayer(unsigned int player, unsigned long dpid)
{
    char msg_str[50];
    this->WasKicked[player] = 1;
    L->Log("Drop dead called P#%d and DPID=%d", player, dpid);
    this->PlayerOptions.InvalidPlayer[player] = 0;
    if (player == 0) {
        L->Log("Player number invalid.  Returning.");
        this->UpdatePlayers();
        return;
    }
    if (player == this->Me) {
        L->Log("I Dropped.");
        this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B2), this->Me);
        unsigned int i = 1;
        if (this->MaxGamePlayers >= 1) {
            do {
                this->WasKicked[i] = 1;
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        static_cast<TRIBE_World*>(rge_base_game->world)->send_zone_score_info();
        L->Log("Initialize Player List");
        i = 1;
        if (this->MaxGamePlayers >= 1) {
            do {
                this->InitPlayerInformation(i, 0, " ", " ");
                i++;
                } while (static_cast<int>(i) <= static_cast<int>(this->MaxGamePlayers));
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->UpdatePlayers();
        return;
    }
    if (!this->IsPlayerHuman(player)) {
        this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B5), player);
        L->Log("Player was defeated, was computer, or is invalid.");
        this->InitPlayerInformation(player, 0, "Defeated", "No Other Information");
        this->UpdatePlayers();
        this->CalculatePlayerRange();
        return;
    }
    if (static_cast<int>(this->PlayerOptions.ProgramState) >= 5 && this->current_turn >= 6) {
        L->Log("Player quit the game.");
        rge_base_game->get_string(0x4BD, msg_str, 0x32);
        sprintf(this->TBuff, msg_str, player, this->FriendlyName[player].Text);
        L->Log(this->TBuff);
        this->InitPlayerInformation(player, 0, "Dropped", " ");
        this->SetPlayerHumanity(player, static_cast<PLAYERHUMANITY>(0));
        this->UpdatePlayers();
        this->CalculatePlayerRange();
        if (this->PlayerStopTurn[player] != 0) return;
    } else {
        L->Log("Player dropped before game start");
        this->InitPlayerInformation(player, 0, "Dropped", "No Other Information");
        this->SetPlayerHumanity(player, static_cast<PLAYERHUMANITY>(0));
        this->UpdatePlayers();
        this->CalculatePlayerRange();
    }
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B3), player);
}














void TCommunications_Handler::EvaluateSystemMessage(unsigned long unused_1, char* system_message_data,
                                                    unsigned long message_id_home, unsigned long unused_4)
{
    DPMSG_GENERIC message;
    DPMSG_DESTROYPLAYERORGROUP destroy_player;
    DPMSG_CREATEPLAYERORGROUP create_player;
    DPMSG_SETPLAYERORGROUPDATA set_player_data;
    memcpy(&message, system_message_data, sizeof(message));
    memcpy(&destroy_player, system_message_data, sizeof(destroy_player));
    memcpy(&create_player, system_message_data, sizeof(create_player));
    memcpy(&set_player_data, system_message_data, sizeof(set_player_data));
    if (this->Multiplayer == 0) {
        L->Log("!MP in DPANALYSIS");
        return;
    }

    L->Log("DP Sys Msg %d", message.dwType);

    switch (message.dwType) {
    case DPSYS_DESTROYPLAYERORGROUP: {
        unsigned long victim = destroy_player.dpId;
        unsigned int i = 0;
        if (victim != 0) {
            int p = this->PlayerOptions.LowPlayerNumber;
            int high = this->PlayerOptions.HighPlayerNumber;
            if (p <= high) {
                for (; p <= high; p++) {
                    if (this->PlayerOptions.dcoID[p] == victim) {
                        i = p;
                        break;
                    }
                }
            }
        }
        L->Log("DPMSG_DESTRPYPLAYERORGROUP  (to debug dropping players)");
        L->Log("FROM Player ID =		%d ", destroy_player.dpId);
        L->Log("Equates to our player # %d ", i);
        L->Log("Program state is        %d ", this->PlayerOptions.ProgramState);
        L->FlushLog();
        if (this->IsPlayerHuman(i) != 0 && this->PlayerStopTurn[i] == 0) {
            if (i == this->Me)
                this->NotifyWindow(COMM_PLAYER_DROPPED);
            else
                this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B3), i);
        }
        if (this->MeHost == 0)
            return;
        MSGFORMAT_KILL_PLAYER kp;
        kp.PlayerNo = i;
        kp.dcoID = destroy_player.dpId;
        kp.CurrentTurn = this->current_turn;
        L->Log("HOST Send to all - drop player %d ID=%d ", i, kp.dcoID);
        L->Log("  >TX KP2 #%d (%d)", i, 0xC);
        this->CommOut(0, 'K', &kp.PlayerNo, 0xC, 0);
        if (i <= 0)
            return;
        if (this->PlayerStopTurn[kp.PlayerNo] != 0)
            return;
        this->DropDeadPlayer(i, victim);
        return;
    }

    case DPSYS_CREATEPLAYERORGROUP: {
        unsigned long newid;
        unsigned int i;

        message_id_home = create_player.dpId;
        newid = message_id_home;
        L->Log("RX NEW PLR ID=%d", newid);
        L->Log("COMM: Create Player Request.");
        sprintf(this->TBuff, "Create Player Request.  (MeHost=%d), Programstate=%d DPID=%d ", this->MeHost, this->PlayerOptions.ProgramState, newid);
        L->Log(this->TBuff);
        if (this->PlayerOptions.ProgramState == 5 || this->current_turn > 6) {
            *this->TBuff = 'I';
            L->Log("  >TX GIP %u (1)", create_player.dpId);
            this->FastSend(create_player.dpId, this->TBuff, 1, 0, 0);
            return;
        }
        if (this->MeHost == 0)
            return;
        i = 1;
        for (; i <= this->MaxGamePlayers; i++) {
            if (this->PlayerOptions.Humanity[i] == 0)
                break;
        }
        if (i > this->MaxGamePlayers)
            i = 0;
        if (i != 0 && this->PlayerOptions.ProgramState == 3) {
            this->InitPlayerInformation(i, static_cast<int>(create_player.dpId),
                                         create_player.dpnName.lpszShortNameA,
                                         create_player.dpnName.lpszLongNameA);
            this->PlayerOptions.dcoID[i] = message_id_home;
            this->PlayerOptions.Humanity[i] = ME_HUMAN;
            this->PlayerOptions.NeedsToBeSent = 1;
            this->PlayerOptions.InvalidPlayer[i] = 0;
            this->CalculatePlayerRange();
            this->UpdatePlayer(i, 1);
            this->PlayerOptions.NeedsToBeSent = 1;
            this->PlayerHighSerialNumber[i] = i * 2000;
            this->ClearRXTXForPlayer(i);
            this->SendSharedData(0);
            return;
        }
        *this->TBuff = 'I';
        L->Log("  >TX GIP2 %u (1)", create_player.dpId);
        this->FastSend(create_player.dpId, this->TBuff, 1, 0, 0);
        this->UpdatePlayers();
        return;
    }


    case DPSYS_ADDPLAYERTOGROUP:
        L->Log("Add/delete player of group.");
        return;

    case DPSYS_ADDGROUPTOGROUP:
        L->Log("Add/delete player of group.");
        return;

    case DPSYS_CHAT:
        L->Log("DP Chat Msg");
        return;

    case DPSYS_DELETEPLAYERFROMGROUP:
        L->Log("delete player of group.");
        return;

    case DPSYS_HOST:
        if (this->PlayerOptions.ProgramState != 3 && this->current_turn >= 6) {
            L->Log("Assumed host");
            this->MeHost = 1;
            this->PlayerOptions.HostPlayerNumber = this->Me;
            this->CheckPingTime(1);
            this->UpdatePlayers();
            this->EnableNewPlayers(direct_play_interface, 0);
            this->CalculatePlayerRange();
            this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B1), this->Me);
            this->KillAnyMissingPlayers();
            return;
        }
        L->Log("Host (other) Exit before game start");
        this->NotifyWindow(COMM_HOST_EXITED);
        this->EnableNewPlayers(direct_play_interface, 1);
        return;

    case DPSYS_SESSIONLOST:
        L->Log("COMM:Host session lost.");
        this->PlayerOptions.NeedsToBeSent = 1;
        this->UpdatePlayers();
        this->NotifyWindow(COMM_HOST_EXITED);
        return;

    case DPSYS_SETPLAYERORGROUPDATA: {
        sprintf(this->TBuff, " Player Data> P1=%d P2=%d P3=%d P4=%d P5=%d P6=%d P7=%d P8=%d ",
                this->PlayerOptions.dcoID[1], this->PlayerOptions.dcoID[2],
                this->PlayerOptions.dcoID[3], this->PlayerOptions.dcoID[4],
                this->PlayerOptions.dcoID[5], this->PlayerOptions.dcoID[6],
                this->PlayerOptions.dcoID[7], this->PlayerOptions.dcoID[8]);
        L->Log(this->TBuff);
        unsigned int i = 1;
        if (this->MaxGamePlayers >= i) {
            unsigned int ser = 2000;
            do {
                if (this->PlayerHighSerialNumber[i] == 0 && this->PlayerOptions.dcoID[i] != 0) {
                    this->ClearRXTXForPlayer(i);
                    this->PlayerHighSerialNumber[i] = ser;
                    L->Log("Set expected ser# for player %d to %d", i, ser + 1);
                }
                i++;
                ser += 2000;
            } while (i <= this->MaxGamePlayers);
        }
        if (this->MeHost != 0) {
            L->Log("Host - no rcv opts.");
            return;
        }
        L->Log("Checking state for options rcvd from host.");
        if (this->PlayerOptions.ProgramState != 3)
            return;
        L->Log("Group options rcvd from host.");
        char* shared_data = static_cast<char*>(set_player_data.lpData);
        if (set_player_data.dwDataSize >= sizeof(this->PlayerOptions)) {
            memcpy(&this->PlayerOptions, shared_data,
                   sizeof(this->PlayerOptions));
            char* byte_tail = shared_data + sizeof(this->PlayerOptions);
            if (set_player_data.dwDataSize >= this->PlayerOptions.DataSizeToFollow
                    + sizeof(this->PlayerOptions)) {
                this->SetMyGameOptions(byte_tail,
                                       this->PlayerOptions.DataSizeToFollow);
            }
            this->NotifyWindow(COMM_UPDATE_PARAMS);
        }

        this->current_turn = this->PlayerOptions.CurrentTurn;
        this->AcknowledgeAfterMsec = this->PlayerOptions.AcknowledgeAfterMsec;
        this->SetSelfPlayer();
        if (this->PlayerOptions.GameHasStarted != 0) {
            L->Log("Host Launched game");
            this->CalculatePlayerRange();
            L->Log("OPTIONS SET - program state = %d", this->PlayerOptions.ProgramState);
            this->PlayerOptions.ProgramState = COMM_STATE_RUNNING;
            this->ResetLastCommunicationTimes();
            this->ClearRXandTX();
            for (int j = 1; j <= 9; j++)
                this->PlayerStopTurn[j] = 0;
            {
                unsigned int k = 1;
                if (this->MaxGamePlayers >= k) {
                    unsigned int ser2 = 2000;
                    do {
                        if (this->PlayerOptions.dcoID[k] != 0) {
                            this->PlayerHighSerialNumber[k] = ser2;
                            L->Log("Set expected ser# for player %d to %d", k, ser2 + 1);
                        }
                        k++;
                        ser2 += 2000;
                    } while (k <= this->MaxGamePlayers);
                }
            }
            this->GTDSerialNo = this->Me * 2000 + 1;
            L->Log("Set my serial number to %d", this->GTDSerialNo);
            this->NotifyWindow(COMM_UPDATE_PARAMS);
            this->NotifyWindow(COMM_LAUNCH_GAME);
        } else {
            L->Log("Game not yet started.");
        }
        if (this->PlayerOptions.GameHasStarted == 0 && this->GTDSerialNo == 0 && this->Me != 0) {
            this->GTDSerialNo = this->Me * 2000 + 1;
            L->Log("Serial # was 0, setting my serial number to %d", this->GTDSerialNo);
        }
        this->UpdatePlayers();
            this->NotifyWindow(COMM_UPDATE_PARAMS);
        return;
    }

    case DPSYS_SETPLAYERORGROUPNAME:
        this->UpdatePlayers();
        L->Log("Set player or group name");
            this->NotifyWindow(COMM_UPDATE_PARAMS);
        return;

    case DPSYS_SECUREMESSAGE:
        L->Log("Secure message dp");
        return;

    case DPSYS_SETSESSIONDESC:
        L->Log("Set Sessino Description");
        return;

    case DPSYS_STARTSESSION:
        L->Log("START SESSION MESSAGE RCVD. ");
        L->Log(" *** NOTICE ***");
        return;
    }
    L->Log("COMM:Unknown system message. %d", message.dwType);
}











void TCommunications_Handler::SendGroupChatMsg(char* param_1) {
    unsigned char DestMap[10];

    for (int j = 0; j < 10; j++) {
        DestMap[j] = 'N';
    }

    unsigned int i = 1;
    if (i <= this->MaxGamePlayers) {
        do {
            if (this->Chat->inChatGroup(i)) {
                DestMap[i] = 'Y';
            }
            i++;
        } while (i <= this->MaxGamePlayers);
    }

    this->TXChat(this->Me, DestMap, param_1);
}

void TCommunications_Handler::SendChatMsgAll(char* msg) {
    unsigned char dest[10];

    memset(dest, 'Y', 10);
    this->TXChat(this->Me, dest, msg);
}














void TCommunications_Handler::SendChatMsg(unsigned int player, unsigned int to, char* text) {
    unsigned char destMap[10];

    L->Log("SendChatMsg FROM=%d  TO=%d Text='%s'", player, to, text);
    for (unsigned int i = 0; i < 10; ++i)
        destMap[i] = 'N';
    destMap[to] = 'Y';
    TXChat(player, destMap, text);
}
















long TCommunications_Handler::TXChat(unsigned int player, unsigned char* destMap, char* text)
{
    MSGFORMAT_CHAT cht;
    if (this->Multiplayer == 0) {
        this->Chat->AddChatMsg(this->FriendlyName[player].Text, text, 1);
        L->Log("Local chat single player add: %s", text);
        return 0;
    }

    if (player > static_cast<unsigned int>(this->MaxGamePlayers)) {
        return 0x80004005;
    }

    unsigned int i = 1;
    if (static_cast<unsigned int>(this->MaxGamePlayers) >= i) {
        do {
            if (this->IsPlayerHuman(i) && destMap[i] == 'Y') {
                cht.DestPlayers[i] = 'Y';
            } else {
                cht.DestPlayers[i] = 'N';
            }
            i++;
        } while (i <= static_cast<unsigned int>(this->MaxGamePlayers));
    }

    if (cht.DestPlayers[this->Me] == 'Y') {
        this->Chat->AddChatMsg(this->FriendlyName[player].Text, text, 1);
        L->Log("Local chat add: %s", text);
    }

    unsigned int len = strlen(text);
    if (len > 0xff) {
        len = 0xff;
    } else {
        len = strlen(text);
    }

    cht.FromGamerID = static_cast<unsigned char>(player);
    cht.TextSize = len;
    strncpy(cht.ChatMsg, text, len + 1);
    cht.ChatMsg[255] = 0;
    if (this->PlayerOptions.ProgramState == 3) {
        cht.Pregame = 1;
    } else {
        cht.Pregame = 0;
    }
    L->Log("  >TX CHAT '%s' (%d)", text, cht.TextSize + 0x16);
    long ret = this->CommOut(0, 0x43, &cht, cht.TextSize + 0x16, 0);
    this->Err->ShowReturn(ret, "TXChat()");
    return ret;
}



void TCommunications_Handler::SendSpeedChange(unsigned int param_1, unsigned int param_2) {
    if (this->MeHost != 0 && this->Multiplayer != 0) {
        MSGFORMAT_SPEEDCHANGE speed_change;
        speed_change.BufferFrames = static_cast<unsigned short>(param_1);
        speed_change.FrameSizeMsec = static_cast<unsigned short>(param_2);
        L->Log("  >TX KP SPD (%d)", 4);
        this->CommOut(0, 'S', &speed_change, 4, 0);
    }
}
















void TCommunications_Handler::SendIResignMsg()
{
    if (this->Multiplayer == 0) return;

    MSGFORMAT_ONTURN resign;
    MSGFORMAT_ALL_DONE done;

    resign.ExecuteOnTurn = this->current_turn +
                           this->PlayerOptions.CommandTurnIncrement;
    L->Log("  >TX RSGN (%d)", 4);
    this->CommOut(0, 0x51, &resign, sizeof(resign), 0);

    done.Command = 'D';
    done.HighLatencyCenti = this->Speed->GetHighLatencyCenti();
    done.FrameRateMsec = this->Speed->GetAvgFrameRate();

    done.ExecuteOnTurn = this->current_turn +
                         this->PlayerOptions.CommandTurnIncrement + 1;
    L->Log("  >TX DONE (%d)", 0x0C);
    this->CommOut(0, 0x44, &done, sizeof(done), 0);

    done.ExecuteOnTurn = this->current_turn +
                         this->PlayerOptions.CommandTurnIncrement + 2;
    L->Log("  >TX DONE (%d)", 0x0C);
    this->CommOut(0, 0x44, &done, sizeof(done), 0);

    done.ExecuteOnTurn = this->current_turn +
                         this->PlayerOptions.CommandTurnIncrement + 3;
    L->Log("  >TX DONE (%d)", 0x0C);
    this->CommOut(0, 0x44, &done, sizeof(done), 0);
}



unsigned long TCommunications_Handler::HiTurnAcknowledged() {
    unsigned long* ack;
    int player;

    comm_highest_acknowledged_turn = 0;
    player = this->PlayerOptions.LowPlayerNumber;
    if (player <= this->PlayerOptions.HighPlayerNumber) {
        ack = this->LastTurnAck + player;
        do {
            if (this->IsPlayerHuman(player) != 0 && *ack > comm_highest_acknowledged_turn) {
                comm_highest_acknowledged_turn = *ack;
            }
            player++;
            ack++;
        } while (player <= this->PlayerOptions.HighPlayerNumber);
    }
    return comm_highest_acknowledged_turn;
}










int TCommunications_Handler::AllPlayersAcknowledged(void)
{
    if (this->Multiplayer == 0)
        return 0;

    if (this->ShuttingDown != 0)
        return 0;

    if (this->PlayerOptions.ProgramState == 4)
        return 0;

    unsigned int i = this->PlayerOptions.LowPlayerNumber;

    if (i > this->PlayerOptions.HighPlayerNumber)
        return 1;

    for (; i <= this->PlayerOptions.HighPlayerNumber; i++) {
        if (IsPlayerHuman(i)) {
            if (static_cast<unsigned int>(this->LastTurnAck[i]) < static_cast<unsigned int>(this->current_turn))
                return 0;
        }
    }

    return 1;
}

long TCommunications_Handler::SendChecksumMessage(
    unsigned long param_1, unsigned int param_2,
    long param_3, long param_4, long param_5,
    long param_6, long param_7)
{
    MSGFORMAT_CHECKSUM cs;

    cs.WorldTime = param_1;
    cs.WorldTurn = this->current_turn;
    cs.cs1 = param_3;
    cs.cs2 = param_4;
    cs.cs3 = param_5;
    cs.cs4 = param_6;
    cs.cs5 = param_7;
    cs.Random = param_2;

    cs.PingInitiated = debug_timeGetTime(com_hand_source_path, 0xBC0);

    L->Log("  >TX CKSUM (%d)", 0x24);

    long result = this->CommOut(0, 0x4D, &cs, 0x24, 0);

    this->Err->ShowReturn(result, "Send Checksum");

    return result;
}























































typedef unsigned int uint;

static char s_clear_past[] = "+++Clearing PAST OnHold Slot=%d  Serial#%d Len=%d  From=%d  To=%d  HumanSerial#%d";
static char s_cached[] = "Cached Execute #%d  Slot#%d ";
static char s_clearing[] = "Clearing OnHold Slot=%d  Len=%d  From=%d  To=%d";

uint TCommunications_Handler::ExecuteIncoming()
{
    if (this->Multiplayer == 0) {
        return 0;
    } else {
        for (uint pno = 0; pno < 502; ++pno) {
            HOLDER* entry = &this->OnHold[pno];
            if (entry->Length != 0) {
                for (uint player = 1; player <= this->MaxGamePlayers; ++player) {
                    if (this->IsPlayerHuman(player) && player != this->Me) {
                        uint humanSerial = this->PlayerHighSerialNumber[player] + 1;
                        uint dco = this->PlayerOptions.dcoID[player];
                        if (entry->Serial < humanSerial && entry->dcoFromID == dco) {
                            L->Log(s_clear_past, pno, entry->Serial, entry->Length,
                                   entry->dcoFromID, entry->dcoReceiveID, humanSerial);
                            if (entry->HoldMsg != 0) {
                                delete[] entry->HoldMsg;
                            }
                            entry->HoldMsg = 0;
                            entry->Serial = 0;
                            entry->Length = 0;
                            entry->dcoFromID = 0;
                            entry->dcoReceiveID = 0;
                        }
                        if (entry->Serial == humanSerial && entry->dcoFromID == dco) {
                            sprintf(this->TBuff, s_cached, humanSerial, pno);
                            L->Log(this->TBuff);
                            this->PreprocessMessages(entry->Length, entry->HoldMsg,
                                                     entry->dcoFromID,
                                                     entry->dcoReceiveID, 1);
                            L->Log(s_clearing, pno, entry->Length,
                                   entry->dcoFromID, entry->dcoReceiveID);
                            if (entry->HoldMsg != 0) {
                                delete[] entry->HoldMsg;
                            }
                            entry->HoldMsg = 0;
                            entry->Serial = 0;
                            entry->Length = 0;
                            entry->dcoFromID = 0;
                            entry->dcoReceiveID = 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}






void TCommunications_Handler::ClearAllSerialNumbers() {
    unsigned int i;

    L->Log("Cleared all serial numbers.");
    i = 0;
    do {
        this->LastSerialRequestedTX[i + 0x51] = 0;
        this->LastSerialRequestedTX[i] = 0;
        this->LastSerialRequestedTX[i + 0xA] = 0;
        this->LastSerialRequestedTX[i + 0x14] = 0;
        this->LastSerialRequestedTX[i + 0x1E] = 0;
        i = i + 1;
    } while (i <= this->MaxGamePlayers);
}
























void TCommunications_Handler::ClearRXandTX()
{
    for (unsigned int i = 0; i < 502; ++i) {
        HOLDER* entry = &this->OnHold[i];
        if (entry->HoldMsg != 0) {
            delete[] entry->HoldMsg;
        }
        entry->HoldMsg = 0;
        entry->Serial = 0;
        entry->Length = 0;
        entry->dcoFromID = 0;
        entry->dcoReceiveID = 0;
    }

    for (unsigned int resend_index = 0; resend_index < 502; ++resend_index) {
        RESENDER* entry = &this->Resend[resend_index];
        entry->TimeSent = 0;
        if (entry->ResendMsg != 0) {
            delete[] entry->ResendMsg;
        }
        entry->ResendMsg = 0;
        entry->Serial = 0;
        entry->Length = 0;
        memset(entry->DestMap, 0, sizeof(entry->DestMap));
    }
}

void TCommunications_Handler::ClearRXForPlayer(unsigned int player) {
    for (unsigned int i = 0; i < 502; ++i) {
        HOLDER* entry = &this->OnHold[i];
        if (entry->dcoFromID == this->PlayerOptions.dcoID[player]) {
            if (entry->HoldMsg != 0) {
                delete[] entry->HoldMsg;
            }
            entry->HoldMsg = 0;
            entry->Serial = 0;
            entry->Length = 0;
            entry->dcoFromID = 0;
            entry->dcoReceiveID = 0;
        }
    }
}






class RESENDER;

int TCommunications_Handler::CountWaitingMessages() {
    int count = 0;
    unsigned int slot = 0;

    do {
        RESENDER* entry = &this->Resend[slot];
        if (entry->Serial != 0) {
            L->Log(
                "GTD: Ser #%d Slot=%d Cmd='%c' Len=%d not acknowledged",
                entry->Serial,
                slot,
                static_cast<int>(static_cast<signed char>(entry->ResendMsg[0])),
                entry->Length,
                entry->DestMap[1], entry->DestMap[2], entry->DestMap[3],
                entry->DestMap[4], entry->DestMap[5], entry->DestMap[6],
                entry->DestMap[7], entry->DestMap[8]);
            count++;
        }
        slot++;
    } while (slot <= 501);

    return count;
}
void TCommunications_Handler::ClearTXForPlayer(unsigned int player) {
    for (unsigned int i = 0; i < 502; ++i) {
        this->Resend[i].DestMap[player] = 0;
    }
}

void TCommunications_Handler::ClearRXTXForPlayer(unsigned int player) {
    ClearTXForPlayer(player);
    ClearRXForPlayer(player);
}










































typedef unsigned int uint;
typedef unsigned long ulong;

int TCommunications_Handler::StoreIncoming(uint SerialNumber, char* InBuff, uint Length, ulong dcoFromID, ulong dcoReceiveID)
{
    HOLDER* h;
    unsigned int i;

    if (Length == 0) {
        L->Log("+++StoreIncoming called for zero-length message");
    }

    h = this->OnHold;
    for (i = 0; i <= 0x1F5; i++) {
        if (h[i].Serial == SerialNumber && h[i].dcoFromID == dcoFromID) {
            L->Log("Future Ser#%d previously stored (Slot#%d)", SerialNumber, i);
            return 1;
        }
    }

    for (i = 0; i < 0x1F5; i++) {
        if (h[i].Length == 0 && Length != 0) {
            this->OnHold[i].Length = Length;
            h = &this->OnHold[i];
            h->HoldMsg = new char[h->Length];
            if (h->HoldMsg != 0) {
                memcpy(h->HoldMsg, InBuff, h->Length);
                h->Length = Length;
            }
            this->OnHold[i].Serial = SerialNumber;
            this->OnHold[i].dcoFromID = dcoFromID;
            this->OnHold[i].dcoReceiveID = dcoReceiveID;
            return 1;
        }
    }

    L->Log("+++ DID NOT STORE:  ");
    if (i > 0x1EB) {
        L->Log("HOLD FULL WARNING.  COUNT=%d", i);
        i = 0;
        do {
            HOLDER* scan_h = &this->OnHold[i];
            if (scan_h->Length != 0) {
                L->Log("S#%d  Ser#%d FromID=%d Len=%d  CMD='%c' B0=%d B1=%d", i, scan_h->Serial, scan_h->dcoFromID, scan_h->Length, static_cast<int>(scan_h->HoldMsg[0]), static_cast<int>(scan_h->HoldMsg[0]), static_cast<int>(scan_h->HoldMsg[1]));
            }
            i++;
        } while (i < 501);
    }
    return 1;
}

























int TCommunications_Handler::StoreForResend(unsigned int param_1, char* param_2, unsigned int param_3, unsigned int* param_4)
{
    if (this->Multiplayer != 0) {
        if (this->RGE_Guaranteed_Delivery == 0) {
            L->Log("+++!RGEGTD Store");
        } else {

    unsigned int slot = 0;
    RESENDER* e = this->Resend;
    do {
        if (e->Serial == 0) {
            e->Length = param_3;
            if (param_3 != 0) {
                e->ResendMsg = new char[e->Length];
                if (e->ResendMsg != 0) {
                    memcpy(e->ResendMsg, param_2, e->Length);
                    e->Length = param_3;
                }
            }
            e->Serial = param_1;
            unsigned int bytes = static_cast<unsigned int>(this->MaxGamePlayers) * 4 + 4;
            memcpy(e->DestMap, param_4, bytes);

            L->Log("Stored %db for resend (Slot= %d ) SERIAL=%d  (MaxPlayers=%d)",
                   param_3, slot, param_1, this->MaxGamePlayers);
            unsigned int i = 1;
            if (i <= this->MaxGamePlayers) {
                unsigned int* p = param_4 + 1;
                unsigned int* usedp = &e->DestMap[1];
                do {
                    if (*usedp != 0) {
                        L->Log("    %u %u", i, *p);
                    }
                    i++;
                    usedp++;
                    p++;
                } while (i <= this->MaxGamePlayers);
            }
            e->TimeSent = debug_timeGetTime(com_hand_source_path, 0xD12);
            return 1;
        }

        int flag = e->Serial;
        char first = e->ResendMsg[0];
        L->Log("QUEUE Has Ser #%d (Slot=%d) Cmd=%d '%c' Len=%d not ackd yet by %d,%d,%d,%d,%d,%d,%d,%d",
               flag, slot, static_cast<int>(first), static_cast<int>(first), e->Length,
               e->DestMap[1], e->DestMap[2], e->DestMap[3], e->DestMap[4], e->DestMap[5],
               e->DestMap[6], e->DestMap[7], e->DestMap[8]);
        e++;
        slot++;
    } while (slot < 502);
            L->Log("RESEND buffer filled up, slots (i=%d).", slot);
        }
    }
    return 0;
}





typedef unsigned int uint;


int TCommunications_Handler::TXAcknowledgeMessage(uint param_1, uint param_2)
{
    if (this->RGE_Guaranteed_Delivery == 0) {
        L->Log("!RGEGTD Ack");
        return 0;
    }

    MSGFORMAT_ACKNOWLEDGE_GUARANTEED ack;
    ack.Command = 0x41;
    ack.Serialno = param_1;

    if (local_player_dpid == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return 0;
    }

    unsigned long start = debug_timeGetTime(com_hand_source_path, 0xD53);

    unsigned int dco = this->PlayerOptions.dcoID[param_2];
    long result = direct_play_interface->Send(local_player_dpid, dco, 0,
                                              &ack, sizeof(ack));

    unsigned long elapsed = debug_timeGetTime(com_hand_source_path, 0xD5E) - start;
    if (elapsed > 0x32) {
        L->Log("!!!TXAcknowledgeMessage slow - %ld msec", elapsed);
    }

    this->TXPacketLength += 8;

    if (result == 0) {
        return 1;
    }

    this->Err->ShowReturn(result, "GTD ACK");
    return 0;
}








int TCommunications_Handler::RXAcknowledgeStoredMessage(unsigned int param_1, unsigned int param_2) {
    if (!this->RGE_Guaranteed_Delivery) {
        L->Log("!RGEGTD RxAck");
        return 0;
    }

    L->Log("COMM: RX ACK from P#%d for Ser#%d", param_2, param_1);
    this->WaitingForAck = 0;

    for (unsigned int slot = 0; slot < 502; ++slot) {
        RESENDER* resend = &this->Resend[slot];
        if (resend->Serial == param_1 && resend->Serial != 0) {
            resend->DestMap[param_2] = 0;
        }
    }
    return 1;
}





















































int TCommunications_Handler::PurgeAcknowledgedStoredMessages()
{
    int slot = 0;
    do {
        int nonAckCount = 0;
        RESENDER* resend = &this->Resend[slot];

        if (resend->Serial != 0) {
            unsigned int player;

            for (player = 1; player <= static_cast<unsigned int>(this->MaxGamePlayers); player++) {
                if (this->IsPlayerHuman(player)) {
                    if (resend->DestMap[player] > 0) {
                        nonAckCount++;
                    }
                }
            }

            if (nonAckCount == 0) {
                L->Log("GTD: Ser #%d Slot=%d  Ackd by all. (Released)",
                    resend->Serial, slot);

                resend->TimeSent = 0;
                if (resend->ResendMsg != 0) {
                    delete[] resend->ResendMsg;
                }
                resend->ResendMsg = 0;
                resend->Serial = 0;
                resend->Length = 0;

                for (int i = 0; i < 10; i++) {
                    resend->DestMap[i] = 0;
                }
            }
        }

        slot++;
    } while (slot < 502);


    {
        RESENDER* resend = this->Resend;
        int i = 502;

        do {
            if (resend->Serial != 0) {
                this->WaitingForAck++;
            }
            resend++;
            i--;
        } while (i != 0);
    }

    return 1;
}


















































int TCommunications_Handler::SendStoredMessages()
{
    unsigned long now;
    unsigned int items;
    unsigned int oldest_message_slot;
    unsigned int resend_slot;
    unsigned int max_dest_delay;
    unsigned int player;
    long hr;
    MSGFORMAT_MISSING_PLAYER m;
    RESENDER* selected;
    unsigned int* map;
    unsigned int* dest;
    unsigned long* dco;
    unsigned int slot;
    unsigned int count;
    unsigned int elapsed;
    unsigned int limit;
    unsigned long send_start;
    unsigned long send_elapsed;
    char* name;

    if (this->RGE_Guaranteed_Delivery == 0) {
        L->Log("RGEGTD SendStore");
        return 0;
    }

    if ((comm_messages_initialized & 1) == 0) {
        comm_messages_initialized |= 1;
        comm_resend_last_time = debug_timeGetTime(com_hand_source_path, 0xE00);
    }

    now = debug_timeGetTime(com_hand_source_path, 0xE02);
    if (!(static_cast<float>(comm_resent_bytes) / (now - comm_resend_last_time) <=
          comm_resend_rate_limit)) {
        return 0;
    }

    comm_resend_last_time = now;
    comm_resent_bytes = 0;
    oldest_message_slot = 0;
    resend_slot = 0;
    items = 0;
    this->PurgeAcknowledgedStoredMessages();

    slot = 0;
    max_dest_delay = 0;
    do {
        RESENDER* entry = &this->Resend[slot];
        if (entry->Serial != 0) {
            ++items;
            elapsed = now - entry->TimeSent;
            if (elapsed > oldest_message_slot) {
                oldest_message_slot = elapsed;
                resend_slot = slot;
            }

            map = entry->DestMap + 1;
            count = this->MaxGamePlayers;
            while (count != 0) {
                int free_delay = 0xF0 - *map;
                if (free_delay > static_cast<int>(max_dest_delay)) {
                    max_dest_delay = free_delay;
                }
                ++map;
                --count;
            }
        }
        ++slot;
    } while (slot <= 0x1F5);

    if (items == 0) {
        return 0;
    }

    if (this->PlayerOptions.CurrentTurn <= 6) {
        if (oldest_message_slot < 2000) {
            return 0;
        }
    } else if (this->ShuttingDown != 0) {
        if (oldest_message_slot < 0xFA) {
            return 0;
        }
    } else {
        limit = comm_resend_latency_base + this->Speed->GetHighestLatencyMsec() * 2;
        if (limit < comm_resend_min_delay + 500U) {
            limit = comm_resend_min_delay + 500U;
        }
        if (oldest_message_slot < limit) {
            return 0;
        }
    }

    selected = &this->Resend[resend_slot];
    selected->TimeSent =
        debug_timeGetTime(com_hand_source_path, 0xE55);

    if (this->MaxGamePlayers < 1) {
        return this->ResentToOther;
    }

    dest = selected->DestMap + 1;
    dco = this->PlayerOptions.dcoID + 1;
    player = 1;

    do {
        if (dest[0] != 0 && this->IsPlayerHuman(player) != 0 &&
            dco[0] != 0 && player != this->Me) {
            if (dest[0] != 0) {
                --dest[0];
            }

            L->Log("Resending #%d to P#%d dcoid=%d Length=%d  (elapsed=%d)",
                   resend_slot, player, dco[0], selected->Length,
                   oldest_message_slot,
                   debug_timeGetTime(com_hand_source_path, 0xE69));

            if (local_player_dpid == 0) {
                L->Log("+++BAD DCOID=0 NO TX");
                return 0;
            }

            send_start = debug_timeGetTime(com_hand_source_path, 0xE76);
            L->Log("  >TX STOR #%d %d (%d)", player, resend_slot,
                   selected->Length);
            hr = direct_play_interface->Send(local_player_dpid, dco[0], 0,
                                    selected->ResendMsg, selected->Length);
            send_elapsed = debug_timeGetTime(com_hand_source_path, 0xE86) - send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!SendStoredMessages slow - %ld msec",
                       send_elapsed);
            }

            if (hr == 0) {
                ++this->ResentToOther;
                this->TXPacketLength += selected->Length;
                comm_resent_bytes += selected->Length;
                L->Log("COMM: RESENT TX Ser#%d To=P#%d Len=%d",
                       selected->Serial, player, selected->Length);
            } else {
                this->Err->ShowReturn(hr, "RESEND Transmit");
            }

            if (dest[0] == 0 && this->IsPlayerHuman(player) != 0 &&
                dco[0] != 0 && player != this->Me) {
                name = this->GetPlayerName(player);
                sprintf(this->TBuff,
                        "Max resends to Player #%d '%s' ", player, name);
                L->Log(this->TBuff);
                if (this->MeHost != 0) {
                    L->Log("HOST Rcvd MAX TX for player #%d", player);
                    this->Kicked[player] = 1;
                    this->Kick(player);
                } else {
                    L->Log("TX Missing Player report for player=%d ",
                           dco[0]);
                    m.Command = '?';
                    L->Log("  >TX MP (%d)", 8);
                    this->FastSend(0, &m, 8, 0, 0);
                }
            }
        }

        ++player;
        ++dest;
        ++dco;
    } while (player <= this->MaxGamePlayers);

    return this->ResentToOther;
}



















































typedef unsigned int uint;


int TCommunications_Handler::TXResendReply(uint serial, uint player)
{
    uint playerNumber;
    unsigned long now;
    uint GoodTransmitCount;
    uint i;
    long hr;
    MSGFORMAT_RESEND nosuch;

    if (this->RGE_Guaranteed_Delivery == 0) {
        return 0;
    }

    if (this->PlayerOptions.dcoID[player] == 0) {
        L->Log("Invalid player req.");
        return 0;
    }

    playerNumber = player;

    if (local_player_dpid == 0) {
        return 0;
    }
    now = debug_timeGetTime(com_hand_source_path, 0xEE7);
    if (serial == this->LastSerialRepliedTX[player]) {
        unsigned long elapsed = now - this->LastRequestRepliedTX[player];
        if (elapsed < 500) {
            L->Log("Res reply too soon #%u %u", serial, elapsed);
            return 0;
        }
    }

    this->LastSerialRepliedTX[player] = serial;
    this->LastRequestRepliedTX[player] = now;

    hr = 0;
    i = 0;
    GoodTransmitCount = 0;

    do {
        RESENDER* entry = &this->Resend[GoodTransmitCount];
        if (entry->Serial == serial) {
            sprintf(this->TBuff, "Found Resend Ser#%d for P#%d",
                    entry->Serial, playerNumber);
            L->Log(this->TBuff);

            char* allocated = new char[entry->Length];
            entry->DestMap[playerNumber]--;

            if (local_player_dpid == 0) {
                delete[] allocated;
                L->Log("+++BAD DCOID=0 NO TX");
                return 0;
            }

            unsigned long send_start =
                debug_timeGetTime(com_hand_source_path, 0xF19);
            L->Log("  >TX RES REP #%d %d (%d)", playerNumber, serial,
                   entry->Length);
            int send_result = direct_play_interface->Send(
                local_player_dpid,
                this->PlayerOptions.dcoID[playerNumber], 0,
                entry->ResendMsg, entry->Length);
            unsigned long send_elapsed =
                debug_timeGetTime(com_hand_source_path, 0xF28)
                - send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!TXResendReply slow - %ld msec", send_elapsed);
            }

            if (send_result == 0) {
                ++hr;
                this->TXPacketLength += entry->Length;
            } else {
                this->Err->ShowReturn(send_result, "Resend TX");
                ++i;
            }

            nosuch.Serialno = static_cast<uint>(
                static_cast<signed char>(entry->ResendMsg[0]));
            unsigned long log_time =
                debug_timeGetTime(com_hand_source_path, 0xF42);
            L->Log("COMM: >>>>> RETRANSMIT P#%d Ser#%d (Slot#%d) Cmd %d '%c' MsgLength=%d Retx left=%d timeGetTime=%d",
                   playerNumber,
                   entry->Serial,
                   GoodTransmitCount, nosuch.Serialno, nosuch.Serialno,
                   entry->Length, entry->DestMap[playerNumber],
                   log_time);
            delete[] allocated;
        }
        ++GoodTransmitCount;
    } while (GoodTransmitCount <= 501);

    if ((hr == 0) && (i == 0)) {
        if (this->PlayerOptions.ProgramState == 3) {
            L->Log("+++ Did not have requested Ser#%d for P#%d ",
                   serial, playerNumber);
            nosuch.Command = 'Y';
            nosuch.Serialno = this->GTDSerialNo - 1;
            L->Log("  >TX RNSM #%d %d (%d)",
                   playerNumber, serial, 8);
            this->FastSend(this->PlayerOptions.dcoID[playerNumber], &nosuch,
                           8, 0, 0);
            L->Log("+++ TX: No such message as #%d..resynchronizing ser#s", serial);
            this->ClearTXForPlayer(playerNumber);
        }
    } else {
        L->Log("RESEND to P#%d FULFILLED:  GoodTX=%d BadTX=%d Total=%d",
               playerNumber, hr, i, hr + i);
    }

    this->PurgeAcknowledgedStoredMessages();
    return 1;
}











int TCommunications_Handler::TXResendRequest(unsigned int serial, unsigned int player) {
    if (!this->RGE_Guaranteed_Delivery) {
        return 0;
    }
    unsigned long now = debug_timeGetTime(com_hand_source_path, 3980);
    if (serial == this->LastSerialRequestedTX[player]) {
        unsigned long elapsed = now - this->LastRequestHonoredTX[player];
        if (elapsed < 500) {
            return 0;
        }
    }
    this->LastSerialRequestedTX[player] = serial;
    this->LastRequestHonoredTX[player] = now;
    MSGFORMAT_RESEND msg;
    msg.Command = 0x58;
    msg.Serialno = serial;
    L->Log("GTD: TX RESEND REQ to P#%d  Ser#%d ", player, serial);
    if (local_player_dpid == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return 0;
    }
    unsigned long sendStart = debug_timeGetTime(com_hand_source_path, 4009);
    L->Log("  >TX RES REQ #%d %d (%d)", player, serial, 8);
    int to = this->PlayerOptions.dcoID[player];
    IDirectPlay3* dp = direct_play_interface;
    int ok = dp->Send(local_player_dpid, to, 0, &msg, sizeof(msg));
    unsigned long elapsed2 = debug_timeGetTime(com_hand_source_path, 4024) - sendStart;
    if (elapsed2 > 50) {
        L->Log("  TX RES REQ took %d", elapsed2);
    }
    if (ok == 0) {
        this->TXPacketLength += 8;
        return 1;
    }
    return 0;
}















unsigned char TCommunications_Handler::GetNextSequence(unsigned long value) {
    if (value != comm_ping_sequence_turn) {
        comm_ping_sequence_turn = value;
        comm_ping_sequence = 1;
        return 1;
    }

    unsigned char seq = comm_ping_sequence;
    ++seq;
    comm_ping_sequence = seq;

    if (seq >= 0xFF) {
        L->Log("+++Too many commands in one comm turn.  Seq#=%d",
                static_cast<unsigned int>(comm_ping_sequence));
        return 0;
    }

    if (this->PlayerOptions.ProgramState == 4 && seq > 100) {
        comm_ping_sequence = 100;
        return 100;
    }

    return seq;
}














































typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long HRESULT;


long TCommunications_Handler::CommOut(ulong to, uchar type, void* data,
                                      int length, uchar flags)
{
    uint full_length;
    uint header_length;
    MSGFORMAT_HEADER_GUARANTEED* out;
    char* packet;
    int outgoing_count;
    ulong sync_turn;
    char GTDString[10];
    uint i;
    int recipient_count;
    uint send_start;
    uint send_elapsed;
    long hr;
    IDirectPlay3* play;

    i = 0;
    if (this->Multiplayer == 0) {
        return 0;
    }
    if (direct_play_interface == 0) {
        return 0;
    }
    if (this->GTDSerialNo == 0) {
        L->Log("SER Not set - no transmit done.");
        return 0;
    }

    out = new MSGFORMAT_HEADER_GUARANTEED;

    if (type == '1' || type == '2' || type == '?' || type == 'A') {
        L->Log("+++BAD Msg type -- ASSERT");
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        out->Serialno = this->GTDSerialNo;
        this->PlayerHighSerialNumber[this->Me] = this->GTDSerialNo;
        ++this->GTDSerialNo;
        header_length = 0x0C;
    } else {
        header_length = 8;
        out->Serialno = 0;
    }

    full_length = header_length + length;
    if (full_length > 0xFA0) {
        L->Log("ERROR: Full length > %d, Header=%d  Length=%d",
               0xFA0, header_length, length);
    }

    out->Sequence = 0;
    out->Command = 0;
    sync_turn = this->current_turn +
                static_cast<uint>(this->PlayerOptions.CommandTurnIncrement);
    out->ExecuteOnTurn = sync_turn;

    uint* dest_map = this->DestMap;
    i = 0;
    do {
        if (this->IsPlayerHuman(i) == 0 || i == this->Me) {
            dest_map[i] = 0;
        } else {
            dest_map[i] = 0xF0;
        }
        ++i;
    } while (i <= this->MaxGamePlayers);

    if (type == '1' || type == '2' || type == '?' || type == 'A') {
        L->Log("ASSERT - BAD MSG TYPE");
    } else {
        out->Sequence = this->GetNextSequence(sync_turn);
        if (this->PlayerOptions.ProgramState != 5 &&
            out->Sequence == 0) {
            delete out;
            return static_cast<long>(0x8877010E);
        }
    }

    out->Command = type;
    packet = new char[full_length + 1];
    memcpy(packet, out, header_length);
    if (length != 0) {
        memcpy(packet + header_length, data, length);
    }

    outgoing_count = 0;
    i = 0;
    dest_map = this->DestMap;
    do {
        if (this->IsPlayerHuman(i) == 0 || i == this->Me) {
            dest_map[i] = 0;
        } else {
            dest_map[i] = 0xF0;
            ++outgoing_count;
        }
        ++i;
    } while (i <= this->MaxGamePlayers);

    if (this->RGE_Guaranteed_Delivery != 0) {
        if (full_length == 0) {
            L->Log("+++Damaged Msg 0b");
            return static_cast<long>(0x80004005);
        }
        if (outgoing_count != 0) {
            if (local_player_dpid == 0) {
                L->Log("+++BAD DCOID=0 NO TX");
                --this->GTDSerialNo;
                return static_cast<long>(0x80004005);
            }

            send_start = debug_timeGetTime(com_hand_source_path, 0x10AA);
            play = direct_play_interface;
            hr = play->Send(local_player_dpid, to, 0, packet, full_length);
            send_elapsed = debug_timeGetTime(com_hand_source_path, 0x10B5) -
                           send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!CommOut slow - %ld msec", send_elapsed);
            }

            if (to == 0) {
                recipient_count = 0;
                if (this->MaxGamePlayers != 0) {
                    i = 1;
                    do {
                        if (this->IsPlayerHuman(i) != 0 &&
                            i != this->Me) {
                            ++recipient_count;
                        }
                        ++i;
                    } while (i <= this->MaxGamePlayers);
                }
            } else {
                recipient_count = 1;
            }


            if (hr == 0) {
                this->TXPacketLength += recipient_count * full_length;
            }
            if (hr == 0) {
                this->StoreForResend(
                    out->Serialno, packet,
                    full_length,
                                     this->DestMap);
            } else {
                --this->GTDSerialNo;
                this->Err->ShowReturn(hr, "TX RGTGTD");
            }
        }
        hr = 0;
    } else if (outgoing_count != 0) {
        if (local_player_dpid == 0) {
            L->Log("+++BAD DCOID=0 NO TX");
            return static_cast<long>(0x80004005);
        }

        send_start = debug_timeGetTime(com_hand_source_path, 0x10EE);
        play = direct_play_interface;
        hr = play->Send(local_player_dpid, to, 0, packet, full_length);
        send_elapsed = debug_timeGetTime(com_hand_source_path, 0x10F9) -
                       send_start;
        if (send_elapsed > 0x32) {
            L->Log("!!!CommOut2 slow - %ld msec", send_elapsed);
        }

        if (to == 0) {
            recipient_count = 0;
            if (this->MaxGamePlayers != 0) {
                i = 1;
                do {
                    if (this->IsPlayerHuman(i) != 0 &&
                        i != this->Me) {
                        ++recipient_count;
                    }
                    ++i;
                } while (i <= this->MaxGamePlayers);
            }
        } else {
            recipient_count = 1;
        }

        if (hr == 0) {
            this->TXPacketLength += recipient_count * full_length;
        }
    } else {
        hr = 0;
    }

    if (outgoing_count != 0) {
        if (this->RGE_Guaranteed_Delivery != 0) {
            strcpy(GTDString, "GTD");
        } else {
            strcpy(GTDString, "!GTD");
        }
        L->Log("COMM: Ser#%d %s TX To=%d Len=%d+%d HDR> Seq=%d",
               out->Serialno,
               GTDString + 4, to, length, header_length,
               out->Sequence, sync_turn,
               out->Command,
               out->Command,
               static_cast<int>(static_cast<char>(packet[header_length])),
               static_cast<int>(static_cast<char>(packet[header_length])), outgoing_count, hr,
               debug_timeGetTime(com_hand_source_path, 0x112B));
    }

    if (hr != 0) {
        this->Err->ShowReturn(hr, "TX");
    } else {
        ++this->TXPackets;
        if (type == '>') {
            this->AddCommand(sync_turn, data, static_cast<unsigned long>(length),
                             this->Me,
                             out->Sequence,
                             0);
        }
    }

    delete out;
    delete[] packet;
    return hr;
}





static char* const empty_string = " ";
static char* const log_string = "Initialize Player List";
static char* const com_hand_h = com_hand_source_path;

void TCommunications_Handler::DestroyMultiplayerGame()
{
    this->DestroyMyPlayer();
    long t = debug_timeGetTime(com_hand_h, 0x267);
    int zero = 0;
    this->RXPacketLength = zero;
    this->RXPacketLengthHigh = zero;
    this->TXPacketLength = zero;
    this->TXPacketLengthHigh = zero;
    this->lastRXDataRate = zero;
    this->lastTXDataRate = zero;
    this->HoldCount = zero;
    this->ServiceTimeout = zero;
    this->TXPackets = zero;
    this->RXPackets = zero;
    this->RGE_Guaranteed_Delivery = static_cast<unsigned char>(zero);
    this->ResendAcknowledgements = zero;
    this->ResentToOther = zero;
    this->DroppedPacketCount = zero;
    this->LobbyLaunched = zero;
    this->GTDSerialNo = zero;
    this->dwStopTime = zero;
    this->OutOfSyncFlag = zero;
    L->Time();
    this->AvgTurnTime = zero;
    this->PauseChangePending = zero;
    this->StepMode = zero;
    this->IntentionallyDropPackets = zero;
    this->PlayerOptions.LastSentTime = t;
    strcpy(this->MyGameTitle, empty_string);
    strcpy(this->MyFriendlyName, empty_string);
    strcpy(this->MyFormalName, empty_string);
    unsigned short cx = this->MaxGamePlayers;
    this->TickStart = zero;
    this->TickCount = zero;
    this->LastTimeoutMessageTime = zero;
    this->PlayerOptions.LowPlayerNumber = 1;
    this->PlayerOptions.HighPlayerNumber = cx;
    this->PlayerOptions.GameHasStarted = zero;
    this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
    this->MeHost = zero;
    this->HaveHostInit = zero;
    this->PlayerOptions.CommandTurnIncrement = 2;
    this->current_turn = 4;
    this->PlayerOptions.CurrentTurn = 4;
    this->PlayerOptions.NeedsToBeSent = static_cast<unsigned char>(zero);
    this->AcknowledgeAfterMsec = 0x32;
    this->Me = zero;
    this->Multiplayer = zero;
    this->turnstart = zero;
    this->mselapsed = zero;
    L->Log(log_string);
    int i = 1;
    if (this->MaxGamePlayers >= i) {
        do {
            this->InitPlayerInformation(i, zero, empty_string, empty_string);
            i++;
        } while (i <= this->MaxGamePlayers);
    }
    this->PlayerOptions.NeedsToBeSent = static_cast<unsigned char>(zero);
    this->PlayerOptions.LastSentTime = zero;
    this->ClearAllSerialNumbers();
    this->ClearRXandTX();
    for (int k = 1; k < 10; ++k) {
        this->PlayerStopTurn[k] = zero;
    }
    this->Steps = 1;
    this->ResetLastCommunicationTimes();
    this->WaitingForAck = zero;
    if (this->InQ != 0) this->InQ->FlushAll();
    if (this->OutQ != 0) this->OutQ->FlushAll();
    this->ShuttingDown = zero;
    for (int j = 0; j < 10; ++j) {
        this->LastPlayerWarning[j] = zero;
        this->Kicked[j] = zero;
        this->WasKicked[j] = zero;
    }
}

COMMSTATUS TCommunications_Handler::GetCommunicationsStatus() {
    this->CommunicationsStatus = this->AnalyzeCommunicationsStatus();
    return this->CommunicationsStatus;
}
























COMMSTATUS TCommunications_Handler::UnlinkCurrentLevel() {
    L->Log("Unlinking current level (%d)", this->CommunicationsStatus);

    switch (this->CommunicationsStatus) {
    case UNINITIALIZED:
    case INITIALIZED:
        break;

    case SINGLE_PLAYER: {
        this->Multiplayer = 0;
        unsigned long t = debug_timeGetTime(com_hand_source_path, 0x267);
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
        L->Time();
        this->AvgTurnTime = 0;
        this->PauseChangePending = 0;
        this->StepMode = 0;
        this->IntentionallyDropPackets = 0;
        this->PlayerOptions.LastSentTime = t;
        strcpy(this->MyGameTitle, " ");
        strcpy(this->MyFriendlyName, " ");
        strcpy(this->MyFormalName, " ");
        this->TickStart = 0;
        this->TickCount = 0;
        this->LastTimeoutMessageTime = 0;
        this->PlayerOptions.LowPlayerNumber = 1;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.GameHasStarted = 0;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
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
        L->Log("Initialize Player List");
        int i = 1;
        if (this->MaxGamePlayers >= i) {
            do {
                this->InitPlayerInformation(i, 0, " ", " ");
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->ClearAllSerialNumbers();
        this->ClearRXandTX();
        for (int k = 1; k < 10; ++k) {
            this->PlayerStopTurn[k] = 0;
        }
        this->Steps = 1;
        this->ResetLastCommunicationTimes();
        this->WaitingForAck = 0;
        if (this->InQ != 0) this->InQ->FlushAll();
        if (this->OutQ != 0) this->OutQ->FlushAll();
        this->ShuttingDown = 0;
        for (int i2 = 0; i2 < 10; i2++) {
            this->LastPlayerWarning[i2] = 0;
            this->Kicked[i2] = 0;
            this->WasKicked[i2] = 0;
        }
        this->Me = 1;
        this->MyFriendlyName[0] = '\0';
        this->MyFormalName[0] = '\0';
        break;
    }

    case MULTIPLAYER_RESET: {
        this->Multiplayer = 0;
        unsigned long t = debug_timeGetTime(com_hand_source_path, 0x267);
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
        L->Time();
        this->AvgTurnTime = 0;
        this->PauseChangePending = 0;
        this->StepMode = 0;
        this->IntentionallyDropPackets = 0;
        this->PlayerOptions.LastSentTime = t;
        strcpy(this->MyGameTitle, " ");
        strcpy(this->MyFriendlyName, " ");
        strcpy(this->MyFormalName, " ");
        this->TickStart = 0;
        this->TickCount = 0;
        this->LastTimeoutMessageTime = 0;
        this->PlayerOptions.LowPlayerNumber = 1;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.GameHasStarted = 0;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
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
        L->Log("Initialize Player List");
        int i = 1;
        if (this->MaxGamePlayers >= i) {
            do {
                this->InitPlayerInformation(i, 0, " ", " ");
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->ClearAllSerialNumbers();
        this->ClearRXandTX();
        for (int k = 1; k < 10; ++k) {
            this->PlayerStopTurn[k] = 0;
        }
        this->Steps = 1;
        this->ResetLastCommunicationTimes();
        this->WaitingForAck = 0;
        if (this->InQ != 0) this->InQ->FlushAll();
        if (this->OutQ != 0) this->OutQ->FlushAll();
        this->ShuttingDown = 0;
        for (int i2 = 0; i2 < 10; i2++) {
            this->LastPlayerWarning[i2] = 0;
            this->Kicked[i2] = 0;
            this->WasKicked[i2] = 0;
        }
        this->Me = 1;
        this->PlayerOptions.Humanity[1] = ME_HUMAN;
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
        L->Log("UNLINK ReleaseComm");
        this->ReleaseComm();
        break;

    case SERVICE_AVAILABLE:
        L->Log("UNLINK ServiceAvailable");
        this->ReleaseComm();
        L->Log("Initialize Player List");
        if (this->MaxGamePlayers >= 1) {
            int i = 1;
            do {
                this->InitPlayerInformation(i, 0, " ", " ");
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->Chat->ClearChat();
        this->MyGameTitle[0] = '\0';
        this->Me = 0;
        local_player_dpid = 0;
        this->ShuttingDown = 0;
        break;

    case SESSION_AVAILABLE: {
        this->ClearRXandTX();
        this->DropAllHostedPlayers();
        L->Log("UNLINK SessionAvailable");
        this->Chat->ClearChat();
        this->CloseSession();
        this->GTDSerialNo = 0;
        L->Log("Initialize Player List");
        if (this->MaxGamePlayers >= 1) {
            int i = 1;
            do {
                this->InitPlayerInformation(i, 0, " ", " ");
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        unsigned short n = this->MaxGamePlayers;
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->PlayerOptions.HighPlayerNumber = n;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->Me = 0;
        local_player_dpid = 0;
        this->ClearAllSerialNumbers();
        RGE_Communications_Speed* speed = this->Speed;
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        if (speed != 0) {
            delete speed;
        }
        RGE_Communications_Synchronize* sync = this->Sync;
        if (sync != 0) {
            delete sync;
        }
        this->Speed = new RGE_Communications_Speed(this);
        this->Sync = new RGE_Communications_Synchronize(this);
        this->SessionGUID = this->NullGUID;
        break;
    }

    case SESSION_HOSTED: {
        L->Log("UNLINK SerssionHosted");
        this->MeHost = 0;
        this->PlayerOptions.HostPlayerNumber = 0;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->HaveHostInit = 0;
        this->CloseSession();
        L->Log("Initialize Player List");
        if (this->MaxGamePlayers >= 1) {
            int i = 1;
            do {
                this->InitPlayerInformation(i, 0, " ", " ");
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->Chat->ClearChat();
        local_player_dpid = 0;
        RGE_Communications_Speed* speed = this->Speed;
        this->Me = 0;
        this->current_turn = this->PlayerOptions.CommandTurnIncrement + 2;
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        if (speed != 0) {
            delete speed;
        }
        RGE_Communications_Synchronize* sync = this->Sync;
        if (sync != 0) {
            delete sync;
        }
        this->Speed = new RGE_Communications_Speed(this);
        this->Sync = new RGE_Communications_Synchronize(this);
        break;
    }

    case PLAYER_CREATED:
        L->Log("UNLINK PlayerCreated");
        this->DestroyMyPlayer();
        this->Me = 0;
        local_player_dpid = 0;
        this->InQ->FlushAll();
        this->ShuttingDown = 0;
        break;

    case GAME_PLAYER_SET:
        L->Log("UNLINK PlayerSet");
        this->Me = 0;
        local_player_dpid = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_OPTIONS_EXCHANGED:
        L->Log("UNLINK GameOptionsExchanged");
        this->FreeOptions();
        this->PlayerOptions.NeedsToBeSent = 0;
        this->ShuttingDown = 0;
        break;

    case COMM_SETTINGS_EXCHANGED:
        L->Log("UNLINK CommSettingsExcahanged");
        this->ReleaseSettings();
        this->ResetLastCommunicationTimes();
        this->ShuttingDown = 0;
        break;

    case GAME_IS_LOADING:
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        L->Log("UNLINK GameIsLoading");
        this->ShuttingDown = 0;
        break;

    case GAME_IS_RUNNING:
        this->Chat->ClearChat();
        L->Log("UNLINK GameIsRunning");
        this->LastTimeoutMessageTime = 0;
        this->InQ->FlushAll();
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_IS_PAUSED:
        L->Log("UNLINK GameIsPaused");
        break;

    default:
        L->Log("UNLINK Unknown");
        break;
    }

    L->Log("Level is now...(%d)", this->CommunicationsStatus - 1);
    return this->AnalyzeCommunicationsStatus();
}





























































































































COMMSTATUS TCommunications_Handler::UnlinkToLevel(COMMSTATUS param_1) {
    COMMSTATUS original_status;
    COMMSTATUS new_status;


    original_status = AnalyzeCommunicationsStatus();


    CommunicationsStatus = original_status;
    L->Log("Unlink to level %d desired, currently at level %d",
        param_1, original_status);


    if (param_1 < 1) {
        param_1 = INITIALIZED;
    }


    original_status = CommunicationsStatus;
    new_status = original_status;


    do {
        if (new_status <= param_1) {
            L->Log("AFTER UNLINKING...Status=%d   Reported=%d",
                this->GetCommunicationsStatus(), this->CommunicationsStatus);
            return AnalyzeCommunicationsStatus();
        }

        new_status = UnlinkCurrentLevel();
        CommunicationsStatus = new_status;
    } while (new_status != original_status);

    sprintf(TBuff, "Unlink from level [ %d ] Failed.\n Stopping connections",
            original_status);
    L->Log(TBuff);
    return AnalyzeCommunicationsStatus();
}




COMMSTATUS TCommunications_Handler::AnalyzeCommunicationsStatus(void) {
    if (this->IsPaused() && this->current_turn >= 6) {
        return static_cast<COMMSTATUS>(15);
    }
    if (this->PlayerOptions.ProgramState == 5 && this->current_turn >= 6) {
        return static_cast<COMMSTATUS>(14);
    }
    if (this->PlayerOptions.ProgramState == 5 && this->current_turn < 6) {
        return static_cast<COMMSTATUS>(13);
    }
    if (this->PlayerOptions.NeedsToBeSent) {
        return static_cast<COMMSTATUS>(12);
    }
    if (local_player_dpid != 0) {
        return static_cast<COMMSTATUS>(9);
    }
    if (this->MeHost != 0) {
        return static_cast<COMMSTATUS>(7);
    }
    if (memcmp(&this->NullGUID, &this->SessionGUID, 16) != 0) {
        return static_cast<COMMSTATUS>(6);
    }
    if (memcmp(&this->ServiceGUID, &this->SessionGUID, 16) != 0) {
        return static_cast<COMMSTATUS>(5);
    }
    if (direct_play_interface != 0) {
        return static_cast<COMMSTATUS>(4);
    }
    if (this->Multiplayer != 0) {
        return static_cast<COMMSTATUS>(3);
    }
    return static_cast<COMMSTATUS>(2 + (this->Me - 1 ? -1 : 0));
}





void TCommunications_Handler::ResetLastCommunicationTimes(void) {
    unsigned long now = debug_timeGetTime(com_hand_source_path, 0x1282);
    for (unsigned int i = 1; i <= this->MaxGamePlayers; ++i) {
        this->LastPlayerCommunication[i] = now;
        this->LastTXPing[i] = now;
    }
}

int TCommunications_Handler::IsPaused() {
    return this->PlayerOptions.ProgramState == 4;
}




void TCommunications_Handler::DropAllHostedPlayers(void) {
    if (MeHost != 0 && current_turn <= 6) {
        unsigned int player = 1;
        if (player <= MaxGamePlayers) {
            do {
                Kick(player);
                player = player + 1;
            } while (static_cast<int>(player) <= static_cast<int>(MaxGamePlayers));
        }
    }
}

void TCommunications_Handler::LocalResumeGame(unsigned int player) {
    this->PlayerOptions.ProgramState = COMM_STATE_RUNNING;
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17A3), player);
}

void TCommunications_Handler::LocalPauseGame(unsigned int player) {
    this->PlayerOptions.ProgramState = COMM_STATE_PAUSE;
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17A2), player);
}




void TCommunications_Handler::SendPauseGame(int param_1) {
    if (this->Multiplayer == 0) {
        return;
    }
    if (this->MeHost == 0) {
        return;
    }

    if (param_1 != 0) {
        L->Log("  >TX PAUSE");
        this->CommOut(0, 0x50, 0, 0, 0);
        return;
    }

    L->Log("  >TX RESUME");
    this->CommOut(0, 0x55, 0, 0, 0);
}

int TCommunications_Handler::TogglePauseGame() {
    if (PauseChangePending != 0) {
        return 0;
    }
    if (IsPaused() != 0) {
        RequestResumeGame(0);
    } else {
        RequestPauseGame(0);
    }
    return 1;
}




void TCommunications_Handler::RequestPauseGame(int param_1) {
    if (this->Multiplayer == 0) {
        this->LocalPauseGame(this->Me);
        return;
    }

    if (this->MeHost != 0) {
        this->SendPauseGame(1);
        this->LocalPauseGame(this->Me);
        return;
    }

    L->Log("  >TX_REQ_PAUSE");
    this->CommOut(0, 0x57, 0, 0, 0);
}









void TCommunications_Handler::RequestResumeGame(int param_1) {
    if (this->Multiplayer == 0) {
        L->Log("Resume requested");
        this->LocalResumeGame(this->Me);
        return;
    }

    if (this->MeHost != 0) {
        this->SendPauseGame(0);
        this->LocalResumeGame(this->Me);
        return;
    }

    L->Log("  >TX REQ RES");
    this->CommOut(0, 0x2B, 0, 0, 0);
}





void TCommunications_Handler::SetRandomSeed(int seed) {
    if (this->MeHost == 0) {
        return;
    }

    if (seed == -1) {
        unsigned long time = debug_timeGetTime(com_hand_source_path, 0x1320);
        debug_srand(com_hand_source_path, 0x1320, time);
        seed = debug_rand(com_hand_source_path, 0x1321);
    }

    this->PlayerOptions.RandomSeed = static_cast<unsigned long>(seed);
    this->PlayerOptions.NeedsToBeSent = 1;
    this->SendSharedData(0);
}

unsigned int TCommunications_Handler::GetRandomSeed() {
    if (this->Multiplayer == 0) {
        unsigned long t = debug_timeGetTime(com_hand_source_path, 0x1336);
        debug_srand(com_hand_source_path, 0x1336, t);
        unsigned long r = debug_rand(com_hand_source_path, 0x1337);
        this->PlayerOptions.RandomSeed = r;
    }
    return this->PlayerOptions.RandomSeed;
}

int TCommunications_Handler::WhoAmI() { return this->Me; }

int TCommunications_Handler::IsHost(void) {
    if (Multiplayer != 0) {
        return MeHost;
    }
    return 1;
}

char* TCommunications_Handler::GetCommStateStr() { return 0; }











char* TCommunications_Handler::GetReadyPlayerStr() {
    strcpy(ready_player_buffer, ready_player_template);

    unsigned int i = 1;
    if (i <= this->MaxGamePlayers) {
        PLAYERHUMANITY* humanity = this->PlayerOptions.Humanity + 1;
        unsigned long* ack = this->LastTurnAck + 1;
        char defc;
        defc = '?';
        do {
            if (*ack >= this->current_turn) {
                ready_player_buffer[i + 6] = 'A';
            } else {
                switch (*humanity) {
                case 2: ready_player_buffer[i + 6] = 'W'; break;
                case 4: ready_player_buffer[i + 6] = 'C'; break;
                case 0: ready_player_buffer[i + 6] = '-'; break;
                case 6: ready_player_buffer[i + 6] = 'V'; break;
                case 5: ready_player_buffer[i + 6] = 'X'; break;
                default: ready_player_buffer[i + 6] = defc; break;
                }
            }
            ++i;
            ++humanity;
            ++ack;
        } while (i <= this->MaxGamePlayers);
    }
    return ready_player_buffer;
}

int TCommunications_Handler::GetPlayerHumanity(unsigned int player) {
    if (player >= 1u && player <= this->MaxGamePlayers)
        return this->PlayerOptions.Humanity[player];
    return 0;
}



void TCommunications_Handler::SetPlayerHumanity(unsigned int player, PLAYERHUMANITY humanity) {
    if (player < 1) {
        return;
    }
    if (player > this->MaxGamePlayers) {
        return;
    }

    this->PlayerOptions.Humanity[player] = humanity;
    this->UpdatePlayer(player, 1);
        this->NotifyWindow(COMM_UPDATE_PARAMS);
    if (this->MeHost != 0 && this->PlayerOptions.ProgramState == 3) {
        this->PlayerOptions.NeedsToBeSent = 1;
        this->SendSharedData(0);
    }
}









int TCommunications_Handler::GetActivePlayerCount() {
    int count = 0;

    for (int player = 0; player <= MaxGamePlayers; player++) {
        if (IsPlayerHuman(player)) {
            ++count;
        } else if (IsPlayerComputer(player)) {
            ++count;
        }
    }

    return count;
}

int TCommunications_Handler::IsPlayerHuman(unsigned int player) {
    int humanity;

    if (player >= 1 && player <= this->MaxGamePlayers) {
        humanity = this->PlayerOptions.Humanity[player];
        if (humanity == 2 || humanity == 5) {
            return 1;
        }
    }
    return 0;
}

int TCommunications_Handler::IsPlayerComputer(unsigned int player) {
    int humanity;

    if (player >= 1u && player <= this->MaxGamePlayers) {
        humanity = this->PlayerOptions.Humanity[player];
        return humanity == 4;
    }
    return 0;
}








typedef unsigned long ulong;


char* TCommunications_Handler::GetCommInfo(unsigned char which) {
    char* p = comm_info_buffers;
    char tmp[0x100];
    --which;

    if (this->Multiplayer == 0) {
        do {
            strcpy(p, ">");
            p += 0x100;
        } while (p < comm_info_buffers + 0x700);
        sprintf(comm_info_buffers, "SinglePlayer> T#%d ", this->current_turn);
        return comm_info_buffers + (static_cast<unsigned int>(which) << 8);
    }

    do {
        strcpy(p, " ");
        p += 0x100;
    } while (p < comm_info_buffers + 0x700);
    strcpy(tmp, "");
    if (this->MeHost != 0) {
        strcpy(tmp, "Host");
    } else {
        strcpy(tmp, "Client");
    }
    sprintf(comm_info_buffers, "P%d T#%6ld [%.7s] %s  TX: %0.1f  RX: %0.1f", this->Me, this->current_turn, tmp, this->GetReadyPlayerStr(), static_cast<double>(this->lastTXDataRate), static_cast<double>(this->lastRXDataRate));
    sprintf(comm_info_buffers + 0x100, "%s ", this->Speed->GetLatencyInfo());
    sprintf(comm_info_buffers + 0x200, "%s  Speed Adjusts=%d ", this->Speed->GetMachineSpeedInfo(), this->Speed->GetAdjustmentCount());

    ulong dpid = 0;
    direct_play_interface->GetMessageCount(local_player_dpid, &dpid);
    sprintf(comm_info_buffers + 0x300, "%s  DPMsgs%d ", this->Speed->GetSelfPlayerOptimalSpeedStr(), dpid);
    sprintf(comm_info_buffers + 0x400, "%s ", this->Speed->GetPlayerSpeedStatusStr(0));

    unsigned long now = debug_timeGetTime(com_hand_source_path, 0x1468);
    unsigned long t8, t7, t6, t5, t4, t3, t2, t1;
    if (this->IsPlayerHuman(8) && this->Me != 8) t8 = now - this->LastPlayerCommunication[8]; else t8 = 0;
    if (this->IsPlayerHuman(7) && this->Me != 7) t7 = now - this->LastPlayerCommunication[7]; else t7 = 0;
    if (this->IsPlayerHuman(6) && this->Me != 6) t6 = now - this->LastPlayerCommunication[6]; else t6 = 0;
    if (this->IsPlayerHuman(5) && this->Me != 5) t5 = now - this->LastPlayerCommunication[5]; else t5 = 0;
    if (this->IsPlayerHuman(4) && this->Me != 4) t4 = now - this->LastPlayerCommunication[4]; else t4 = 0;
    if (this->IsPlayerHuman(3) && this->Me != 3) t3 = now - this->LastPlayerCommunication[3]; else t3 = 0;
    if (this->IsPlayerHuman(2) && this->Me != 2) t2 = now - this->LastPlayerCommunication[2]; else t2 = 0;
    if (this->IsPlayerHuman(1) && this->Me != 1) t1 = now - this->LastPlayerCommunication[1]; else t1 = 0;
    sprintf(comm_info_buffers + 0x500, "LastComm: P1=%-5d  P2=%-5d  P3=%-5d  P4=%-5d P5=%-5d P6=%-5d P7=%-5d P8=%-5d", t1, t2, t3, t4, t5, t6, t7, t8);

    return comm_info_buffers + (static_cast<unsigned int>(which) << 8);
}

char* TCommunications_Handler::GetPlayerName(unsigned int player) {
    if (player > this->MaxGamePlayers) {
        return 0;
    }
    if (static_cast<int>(player) == this->Me) {
        return this->MyFriendlyName;
    }
    return this->FriendlyName[player].Text;
}

void TCommunications_Handler::UpdatePlayerInformation(unsigned long player_id, char* name, char* formal_name) {
    int player;
    int high;

    player = 0;
    if (player_id != 0) {
        player = this->PlayerOptions.LowPlayerNumber;
        high = this->PlayerOptions.HighPlayerNumber;
        if (static_cast<int>(player) <= static_cast<int>(high)) {
            for (; static_cast<int>(player) <= static_cast<int>(high); player++) {
                if (this->PlayerOptions.dcoID[player] == player_id) {
                    break;
                }
            }
        }
    }
    if (player == 0) {
        this->InitPlayerInformation(0, player_id, name, formal_name);
    }
}

int TCommunications_Handler::IsLobbyLaunched() {
    return this->Lobby->IsLobbyLaunched();
}
















int TCommunications_Handler::LaunchLobbyGame()
{
    IDirectPlay3* np = 0;
    DPSESSIONDESC2 session;
    char* pn = 0;
    int r;

    r = Lobby->CheckForLobbyLaunch(np);
    if (r == 0) {
        LobbyLaunched = r;
        return r;
    }
    if (direct_play_interface) {
        r = direct_play_interface->Release();
        L->Log("Release count = %d", r);
    }
    direct_play_interface = np;
    if (np == 0) return 0;
    r = Lobby->GetSessionInfo(session);
    if (r) DebugSessionInformation(&session);
    CommGetCaps();
    Multiplayer = 1;
    DPlayGetSessionDesc();
    Lobby->GetPlayerInfo(&pn);
    SetMyPlayerName(pn);
    PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
    AddSelfPlayer();
    MeHost = Lobby->IsThisHost();
    if (MeHost) {
        Me = 1;
        PlayerOptions.dcoID[1] = local_player_dpid;



        unsigned int& me = this->Me;
        PlayerOptions.Humanity[me] = ME_HUMAN;
        HaveHostInit = 1;
        PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        SetRandomSeed(rge_base_game->random_game_seed);
        GTDSerialNo = 0x7D1;
    }
    UpdatePlayers();
    LobbyLaunched = r;
    return r;
}






void TCommunications_Handler::InitPlayerInformation(unsigned int param_1, unsigned long param_2, char* param_3, char* param_4)
{
    if (param_1 < 1)
        return;
    if (param_1 > MaxGamePlayers)
        return;

    PlayerOptions.PlayerReady[param_1] = 0;
    PlayerOptions.User1[param_1] = 0;
    PlayerOptions.User2[param_1] = 0;
    PlayerOptions.User3[param_1] = 0;
    PlayerOptions.User4[param_1] = 0;
    PlayerOptions.User5[param_1] = 0;
    PlayerOptions.User6[param_1] = 0;
    PlayerOptions.User7[param_1] = 0;
    PlayerOptions.InvalidPlayer[param_1] = 0;
    LastTurnAck[param_1] = 0;
    PlayerOptions.Humanity[param_1] = ME_ABSENT;
    PlayerOptions.dcoID[param_1] = param_2;
    PlayerHighSerialNumber[param_1] = 0;

    dwFlags = 0;
    dwMaxBufferSize = 0;
    dwMaxQueueSize = 0;
    dwMaxPlayers = 0;
    dwHundredBaud = 0;
    dwLatency = 0;

    if (InQ)
    {
        InQ->FlushForPlayer(param_1);
    }

    L->Log("Player %d (%ld) is INITIALIZED as '%s' [%s]", param_1, param_2, param_3, param_4);
}

int TCommunications_Handler::SetGameTitle(char* title) {
    sprintf(this->MyGameTitle, "%s [%s]", title, this->MyFriendlyName);
    return 1;
}

void TCommunications_Handler::SetMyPlayerName(char* name) {
    strcpy(this->MyFriendlyName, name);
    strcpy(this->MyFormalName, "Optional Information");
}


void TCommunications_Handler::SetPlayerName(unsigned int player, char* name) {
    if (player == this->Me) {
        this->SetMyPlayerName(name);
        return;
    }
    char* dest = this->FriendlyName[player].Text;
    strcpy(dest, name);
}

void* TCommunications_Handler::SetWindowHandle(void* v) {
    this->HostHWND = v;
    return v;
}





long TCommunications_Handler::CreateDirectPlayConversation()
{
    IDirectPlay* lpIDC = 0;
    long result;

    result = DirectPlayCreate(&this->ServiceGUID, &lpIDC, 0);
    this->Err->ShowReturn(result, "DPCreate");

    if (direct_play_interface) {
        L->Log("Already have conversation.");
        return 0x88770005;
    }

    if (result) {
        this->ServiceGUID = this->NullGUID;
        return result;
    }

    if (lpIDC) {
        long hr;
        void* queried_object = 0;

        hr = lpIDC->QueryInterface(IID_IDirectPlay3A, &queried_object);

        if (hr) {
            L->Log("Get glpIDC returns...%ld", hr);
            return hr;
        }

        direct_play_interface = static_cast<IDirectPlay3*>(queried_object);

        unsigned long links = lpIDC->Release();
        L->Log("Release: Links=%d", links);
    }

    return 0;
}

int TCommunications_Handler::OpenMultiplayerConnection() { return -1; }
















typedef unsigned long ulong;

int TCommunications_Handler::CreateMultiplayerGame(void)
{
    DPSESSIONDESC2 dSess2 = {0};
    int one = 1;

    this->Multiplayer = one;
    this->HaveHostInit = 0;
    this->PlayerOptions.ProgramState = COMM_STATE_INITIALIZE;
    this->current_turn = 4;
    this->PlayerOptions.ProgramState = COMM_STATE_PAUSE;
    this->Chat->ClearChat();

    long result = this->CreateDirectPlayConversation();
    this->Err->ShowReturn(result, "CreateDirectPlayConversation");

    this->HaveHostInit = one;
    dSess2.dwMaxPlayers = this->MaxGamePlayers;
    dSess2.dwSize = 0x50;
    dSess2.dwCurrentPlayers = one;
    dSess2.guidApplication = this->ApplicationGUID;
    dSess2.guidInstance.Data1 = 0x44;
    dSess2.lpszPasswordA = this->MyGameTitle;

    this->DebugSessionInformation(&dSess2);

    result = direct_play_interface->Open(&dSess2, 2);
    this->Err->ShowReturn(result, "DirectPlay Open Create");

    if (result != 0) {
        if (result == static_cast<long>(0x887700AA)) {
            this->NotifyWindow(COMM_NO_LINK);
            return 0;
        }
        this->PlayerOptions.ProgramState = static_cast<COMMSTATES>(one);
        return 0;
    }

    this->SetRandomSeed(rge_base_game->random_game_seed);
    this->AddSelfPlayer();
    this->CommGetCaps();
    this->DPlayGetSessionDesc();
    this->Me = one;
    this->PlayerOptions.HostPlayerNumber = one;
    this->PlayerOptions.dcoID[this->Me] = local_player_dpid;
    this->PlayerOptions.Humanity[this->Me] = ME_HUMAN;
    this->HaveHostInit = one;
    this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
    this->GTDSerialNo = 0x7D1;
    this->UpdatePlayers();
    return one;
}





























typedef unsigned short ushort;

void TCommunications_Handler::PackPlayersDown()
{
    int pos;
    int save;

    pos = 1;
    if (this->MaxGamePlayers >= 1) {
        do {
        if (this->IsPlayerHuman(pos) || this->IsPlayerComputer(pos)) {
            L->Log("Position %d *LOCKED*.   Plr=%s", pos, this->GetPlayerName(pos));
        } else {
            int src = pos;
            while (src <= static_cast<int>(this->MaxGamePlayers)) {
                if (this->IsPlayerHuman(src) || this->IsPlayerComputer(src))
                    break;
                ++src;
            }
            if (src <= static_cast<int>(this->MaxGamePlayers)) {
                strcpy(this->FriendlyName[pos].Text,
                       this->FriendlyName[src].Text);
                strcpy(this->FormalName[pos].Text,
                       this->FormalName[src].Text);

                this->PlayerOptions.PlayerReady[pos] =
                    this->PlayerOptions.PlayerReady[src];
                this->PlayerOptions.dcoID[pos] =
                    this->PlayerOptions.dcoID[src];
                this->PlayerOptions.User1[pos] =
                    this->PlayerOptions.User1[src];
                this->PlayerOptions.User2[pos] =
                    this->PlayerOptions.User2[src];
                this->PlayerOptions.User3[pos] =
                    this->PlayerOptions.User3[src];
                this->PlayerOptions.User4[pos] =
                    this->PlayerOptions.User4[src];
                this->PlayerOptions.User5[pos] =
                    this->PlayerOptions.User5[src];
                this->PlayerOptions.User6[pos] =
                    this->PlayerOptions.User6[src];
                this->PlayerOptions.User7[pos] =
                    this->PlayerOptions.User7[src];
                this->PlayerOptions.Humanity[pos] =
                    this->PlayerOptions.Humanity[src];
                this->LastTurnAck[pos] = this->LastTurnAck[src];
                this->LastPlayerCommunication[pos] =
                    this->LastPlayerCommunication[src];

                save = pos;
                L->Log("Moved %d->%d", src, save);
                L->Log("Position %d *LOCKED*.   Plr=%s", save, this->GetPlayerName(save));
                this->InitPlayerInformation(src, 0, "", "");
            }
        }
            ++pos;
        } while (pos <= static_cast<int>(this->MaxGamePlayers));
    }

    this->SetSelfPlayer();
}










































int TCommunications_Handler::AddSelfPlayer()
{
    L->Log("Create the player");

    DPNAME dpid;
    memset(&dpid, 0, sizeof(dpid));
    dpid.lpszShortNameA = this->MyFriendlyName;
    dpid.dwSize = sizeof(dpid);
    dpid.lpszLongNameA = this->MyFormalName;

    L->Log("Adding player [%s]", this->MyFriendlyName);

    IDirectPlay3* dp = direct_play_interface;
    if (dp == 0) {
        return 0;
    }

    long retval = dp->CreatePlayer(&local_player_dpid, &dpid,
                                   0, 0, 0, 0);
    this->Err->ShowReturn(retval, "Add SELF PLAYER");

    if (retval != 0) {
        this->CloseSession();
        this->ReleaseComm();
        this->PlayerOptions.ProgramState = COMM_STATE_ERROR;
        return 0;
    }

    L->Log("Rcvd DPID of %d", local_player_dpid);
    this->GetMyMultiPlayerCaps();
    return 1;
}

long TCommunications_Handler::InitJoinGame(void) {
    this->Chat->ClearChat();
    this->Multiplayer = 1;
    this->HaveHostInit = 0;
    this->MeHost = 0;
    this->GTDSerialNo = 0;
    return this->CreateDirectPlayConversation();
}

















typedef unsigned long ulong;


int TCommunications_Handler::JoinMultiplayerGame(_GUID* guid)
{
    DPSESSIONDESC2 dSess2 = {0};

    if (direct_play_interface == 0) {
        L->Log("JMPG: Create w/no valid glpIDC");
        return 0;
    }

    memcpy(&this->SessionGUID, guid, sizeof(this->SessionGUID));
    this->MeHost = 0;

    dSess2.dwSize = 0x50;
    dSess2.guidInstance = *guid;

    memcpy(&dSess2.guidApplication, &this->ApplicationGUID,
           sizeof(dSess2.guidApplication));

    L->Log("Open session for JOIN  (Session Data1=%ld) ", this->SessionGUID.Data1);

    IDirectPlay3* dp = direct_play_interface;
    long result = dp->Open(&dSess2, 1);
    if (result == static_cast<long>(0x8877015E)) {
        this->Err->ShowReturn(result, "Join MP Game");
        return 0;
    }
    if (result == static_cast<long>(0x88770005)) {
        this->Err->ShowReturn(result, "Join MP Game");
        return 0;
    }
    if (result == static_cast<long>(0x8877014A)) {
        this->Err->ShowReturn(result, "Join MP Game");
        this->NotifyWindow(COMM_NO_NEW_PLAYERS);
        return 0;
    }
    if (result != 0) {
        this->Err->ShowReturn(result, "Join MP Game");
        this->PlayerOptions.ProgramState = COMM_STATE_ERROR;
        return 0;
    }
    if (this->AddSelfPlayer() == 0) {
        return 0;
    }
    this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
    return 1;
}





typedef unsigned char uchar;
typedef unsigned short ushort;

void TCommunications_Handler::LaunchMultiplayerGame()
{
    this->EnableNewPlayers(direct_play_interface, 0);
    this->PlayerOptions.ProgramState = COMM_STATE_RUNNING;
    this->CalculatePlayerRange();
    unsigned int idx = 1;
    this->PlayerOptions.GameHasStarted = 1;
    this->ClearRXandTX();
    this->PackPlayersDown();


    if (this->MaxGamePlayers >= 1) {
        int base_serial = 2000;
        do {
            if (this->PlayerOptions.dcoID[idx] != 0) {
                this->PlayerHighSerialNumber[idx] = base_serial;
                L->Log("Set expected ser# for player %d to %d",
                                   idx, base_serial + 1);
            }
            idx++;
            base_serial += 2000;
        } while (idx <= this->MaxGamePlayers);
    }


    this->GTDSerialNo = this->Me * 2000 + 1;
    L->Log("HOST Set own serial to =%d", this->GTDSerialNo);
    this->SendSharedData(1);
    this->current_turn = this->PlayerOptions.CommandTurnIncrement + 1;


    if (this->Multiplayer != 0) {
        L->Log("Clear player acknowledgements");
        unsigned int low = this->PlayerOptions.LowPlayerNumber;
        unsigned int i = low;
        if (i <= this->PlayerOptions.HighPlayerNumber) {

            do {
                if (i != static_cast<unsigned int>(this->Me)) {
                    this->LastTurnAck[i] = 0;
                }
                i++;
            } while (i <= this->PlayerOptions.HighPlayerNumber);
        }
    }

    this->ResetLastCommunicationTimes();
    this->NotifyWindow(COMM_UPDATE_PARAMS);
}

















typedef unsigned long ulong;

long TCommunications_Handler::GetMyMultiPlayerCaps()
{
    IDirectPlay3* dp = direct_play_interface;
    if (dp == 0)
        return 0x80004005;

    DPCAPS dpCaps;
    { unsigned long* p = &dpCaps.dwSize; int i; for (i = 0; i < 10; i++) *p++ = 0; }

    dpCaps.dwSize = 0x28;

    if (local_player_dpid == 0)
        return 0x80004005;

    long result = dp->GetPlayerCaps(local_player_dpid, &dpCaps, 1);

    this->Err->ShowReturn(result, "Get Player Caps");

    if (result != 0)
        return result;

    this->dwFlags = dpCaps.dwFlags;
    if (dpCaps.dwFlags & 0x40) {}
    this->dwMaxBufferSize = dpCaps.dwMaxBufferSize;
    this->dwMaxQueueSize = dpCaps.dwMaxQueueSize;
    this->RGE_Guaranteed_Delivery = 1;
    this->dwMaxPlayers = dpCaps.dwMaxPlayers;
    this->dwHundredBaud = dpCaps.dwHundredBaud;
    this->dwLatency = dpCaps.dwLatency;


    L->Log("Enumerated player caps...");
    L->Log("Latency = %d", this->dwLatency);
    L->Log("MaxQueueSize=%d", this->dwMaxQueueSize);
    L->Log("RGE_Gtd Delivery=%d", static_cast<unsigned long>(this->RGE_Guaranteed_Delivery));

    return 0;
}

void TCommunications_Handler::SetApplicationGUID(_GUID guid) {
    this->ApplicationGUID = guid;
}

IDirectPlay3* TCommunications_Handler::GetDPInterface() {
    return direct_play_interface;
}

void TCommunications_Handler::SetServiceGUID(_GUID guid) {
    this->ServiceGUID = guid;
}

void TCommunications_Handler::SetSessionGUID(_GUID guid) {
    this->SessionGUID = guid;
}




void TCommunications_Handler::UpdatePlayers() {
    int low = this->PlayerOptions.LowPlayerNumber;
    int high = this->PlayerOptions.HighPlayerNumber;
    if (low <= high) {
        do {
            UpdatePlayer(low, 0);
        } while (++low <= this->PlayerOptions.HighPlayerNumber);
    }
    NotifyWindow(COMM_UPDATE_PLAYERS);
}















































void TCommunications_Handler::UpdatePlayer(unsigned int player, int do_update)
{
    unsigned int dcoID = this->PlayerOptions.dcoID[player];
    unsigned long size;
    char* lpData = 0;
    MSGFORMAT_MISSING_PLAYER m;

    switch (this->PlayerOptions.Humanity[player]) {
    case ME_ABSENT:
        L->Log("P#%d ABSENT", player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 0;
        break;

    case ME_ELIMINATED:
        L->Log("P#%d ELIMINATED", player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 0;
        break;

    case ME_HUMAN:
        L->Log("P#%d HUMAN", player);
        break;

    case ME_COMPUTER:
        L->Log("P#%d COMPUTER", player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 1;
        break;

    case ME_CYBORG:
        L->Log("P#%d CYBORG", player);
        break;

    case ME_VIEWONLY:
        this->PlayerOptions.PlayerReady[player] = 1;
        L->Log("P#%d VIEWONLY", player);
        break;

    case ME_CLOSED:
        L->Log("P#%d CLOSED", player);
        this->PlayerOptions.dcoID[player] = 0;
        this->PlayerOptions.PlayerReady[player] = 1;
        break;

    default:
        strcpy(this->FriendlyName[player].Text, "Error");
        L->Log("COMM:INVALID P#%d HUMANITY SETTING %d", player,
               this->PlayerOptions.Humanity[player]);
        return;
    }

    if (dcoID != 0) {
        IDirectPlay3* dp;

        dp = direct_play_interface;
        size = 0;
        dp->GetPlayerName(dcoID, 0, &size);
        lpData = new char[size];

        dp = direct_play_interface;
        long result = dp->GetPlayerName(dcoID, lpData, &size);
        this->Err->ShowReturn(result, "Get PName Info");

        if (result <= static_cast<long>(0x8877001E)) {
            if (result != static_cast<long>(0x8877001E) &&
                result != static_cast<long>(0x80070057)) {
                L->Log("Unknown fail on updateplayers");
                this->PlayerOptions.Humanity[player] = ME_ABSENT;
                this->PlayerOptions.dcoID[player] = 0;
            }
            else {
                L->Log("Fatal error player info %ld", result);
                strcpy(this->FriendlyName[player].Text, "Error!");
                this->PlayerOptions.Humanity[player] = ME_ABSENT;
            }
        } else if (result == static_cast<long>(0x88770082)) {
            L->Log("Fatal error player info %ld", result);
            strcpy(this->FriendlyName[player].Text, "Error!");
            this->PlayerOptions.Humanity[player] = ME_ABSENT;
        } else if (result == static_cast<long>(0x88770096)) {
            L->Log("INVALID PLAYER %d.  Removing.", dcoID);
            if (this->PlayerOptions.ProgramState == 3) {
                this->PlayerOptions.Humanity[player] = ME_HUMAN;
                if (this->IsPlayerHuman(player)) {
                    L->Log("INVALID PLAYER");
                    L->Log("TX Missing Player report for player=%d ", dcoID);
                    m.Command = '?';
                    m.PlayerID = dcoID;
                    L->Log("  >TX MP #%d (%d)", dcoID, 8);
                    this->FastSend(0, &m, 8, 0, 0);
                }
            }
        } else if (result == 0) {
            DPNAME name;
            memcpy(&name, lpData, sizeof(name));
            strcpy(this->FriendlyName[player].Text, name.lpszShortNameA);
            strcpy(this->FormalName[player].Text, name.lpszLongNameA);
            this->PlayerOptions.Humanity[player] = ME_HUMAN;
        } else {
            L->Log("Unknown fail on updateplayers");
            this->PlayerOptions.Humanity[player] = ME_ABSENT;
            this->PlayerOptions.dcoID[player] = 0;
        }
        delete[] lpData;
    } else {
        L->Log("P#%d Not Defined (updateplayers).", player);
    }
    if (do_update != 0) {
        this->NotifyWindow(COMM_UPDATE_PLAYERS);
    }
}











typedef unsigned long ulong;


int TCommunications_Handler::SetMyReadiness(int ready, ulong user1, ulong user2, ulong user3, ulong user4, ulong user5, ulong user6, ulong user7)
{
    MSGFORMAT_SETREADYOPTIONS rdy;

    unsigned int me = this->Me;
    L->Log("SET-MY-READINESS: P#%d RDY=%d O1=%d O2=%d O3=%d O4=%d O5=%d O6=%d O7=%d ",
           me,
           this->PlayerOptions.PlayerReady[me],
           this->PlayerOptions.User1[me],
           this->PlayerOptions.User2[me],
           this->PlayerOptions.User3[me],
           this->PlayerOptions.User4[me],
           this->PlayerOptions.User5[me],
           this->PlayerOptions.User6[me],
           this->PlayerOptions.User7[me]);

    this->PlayerOptions.PlayerReady[this->Me] = ready;
    this->PlayerOptions.User1[this->Me] = user1;
    this->PlayerOptions.User2[this->Me] = user2;
    this->PlayerOptions.User3[this->Me] = user3;
    this->PlayerOptions.User4[this->Me] = user4;
    this->PlayerOptions.User5[this->Me] = user5;
    this->PlayerOptions.User6[this->Me] = user6;
    this->PlayerOptions.User7[this->Me] = user7;

    rdy.Command = 0x52;
    rdy.Ready = static_cast<unsigned char>(ready);
    rdy.User1 = user1;
    rdy.User2 = user2;
    rdy.User3 = user3;
    rdy.User4 = user4;
    rdy.User5 = user5;
    rdy.User6 = user6;
    rdy.User7 = user7;
    rdy.CommunicationsVersionCode = this->CommunicationsVersionCode;
    int meHost = this->MeHost;

    if (meHost == 0) {
        L->Log("  >TX RDY (%d)", 0x28);
        this->FastSend(0, &rdy, sizeof(rdy), 0, 0);
    }

    this->NotifyWindow(COMM_UPDATE_PARAMS);
    return 1;
}




int TCommunications_Handler::GetClientReadiness(unsigned int index, int* out0, unsigned long* out1, unsigned long* out2, unsigned long* out3, unsigned long* out4, unsigned long* out5, unsigned long* out6, unsigned long* out7) {
    *out0 = this->PlayerOptions.PlayerReady[index];
    *out1 = this->PlayerOptions.User1[index];
    *out2 = this->PlayerOptions.User2[index];
    *out3 = this->PlayerOptions.User3[index];
    *out4 = this->PlayerOptions.User4[index];
    *out5 = this->PlayerOptions.User5[index];
    *out6 = this->PlayerOptions.User6[index];
    *out7 = this->PlayerOptions.User7[index];
    return 1;
}

int TCommunications_Handler::IsPlayerReady(unsigned int player) {
    if (player >= 1u && player <= this->MaxGamePlayers)
        return this->PlayerOptions.PlayerReady[player];
    return 0;
}

int TCommunications_Handler::ComputerPlayerGameStart(void) {
    if (!this->Multiplayer)
        return 1;

    return static_cast<unsigned int>(6) < static_cast<unsigned int>(this->current_turn);
}

int TCommunications_Handler::MultiplayerGameStart(void) {
    if (!this->Multiplayer)
        return 1;
    if (static_cast<unsigned int>(this->current_turn) > 6u)
        return 1;
    this->DoCycle(0);
    return 0;
}




int TCommunications_Handler::AllPlayersReady() {
    int player = this->PlayerOptions.LowPlayerNumber;
    if (player > this->PlayerOptions.HighPlayerNumber) return 1;
    int* ready = &this->PlayerOptions.PlayerReady[player];
    for (; player <= this->PlayerOptions.HighPlayerNumber; ready++) {
        if (this->IsPlayerHuman(player)) {
            if (*ready == 0) return 0;
        }
        player++;
    }
    return 1;
}

long TCommunications_Handler::DPlayGetSessionDesc() {
    unsigned long dwSize;
    long result;
    DPSESSIONDESC2 session_record;
    DPSESSIONDESC2* session = &session_record;

    IDirectPlay3* dp = direct_play_interface;
    if (dp == 0) {
        return 0x80004005;
    }

    dwSize = sizeof(session_record);
    result = dp->GetSessionDesc(session, &dwSize);
    Err->ShowReturn(result, "Get Session Desc");

    if (result == 0) {
        SessionGUID = session->guidInstance;
        CurrentPlayers = session->dwCurrentPlayers;
        L->Log("RX Current Players=%d", CurrentPlayers);
    }
    return result;
}







typedef long HRESULT;

static char s_get_caps[] = "Get Caps";
static char s_get_guaranteed_caps[] = "Get guaranteed Caps";
static char s_header[] = "-----------Direct Play III Capabilities -----------";
static char s_max_buffer[] = "Max Buffer Size = %d";
static char s_max_queue[] = "Max Queue Size  = %d";
static char s_max_players[] = "Max Players     = %d";
static char s_baud[] = "Baud Rate       = %d00";
static char s_latency[] = "Latency         = %d";
static char s_header_len[] = "Header Length   = %d";
static char s_timeout[] = "Timeout         = %d";
static char s_guar_opt[] = "Guaranteed Optimized.";
static char s_not_guar_opt[] = "NOT Guaranteed Optimized.";
static char s_session_host_msg[] = "This player is the Session Host.";
static char s_not_session_host_msg[] = "Not the host.";
static char s_keepalive[] = "Optimized keepalive detection.";
static char s_not_keepalive[] = "Not optimized for keepalive.";
static char s_guar_delivery[] = "Guaranteed delivery is Supported";
static char s_not_guar_service[] = "NOT Guaranteed Service!";

HRESULT TCommunications_Handler::CommGetCaps()
{
    DPCAPS caps;
    HRESULT hr;

    IDirectPlay3* dp = direct_play_interface;
    if (dp == 0) {
        return 0x80004005;
    }

    caps.dwSize = sizeof(DPCAPS);
    hr = dp->GetCaps(&caps, 0);
    this->Err->ShowReturn(hr, s_get_caps);

    dp = direct_play_interface;
    hr = dp->GetCaps(&caps, 1);
    this->Err->ShowReturn(hr, s_get_guaranteed_caps);

    L->Log(s_header);
    L->Log(s_max_buffer, caps.dwMaxBufferSize);
    L->Log(s_max_queue, caps.dwMaxQueueSize);
    L->Log(s_max_players, caps.dwMaxPlayers);
    L->Log(s_baud, caps.dwHundredBaud);
    L->Log(s_latency, caps.dwLatency);
    L->Log(s_header_len, caps.dwHeaderLength);
    L->Log(s_timeout, caps.dwTimeout);

    this->ServiceTimeout = caps.dwTimeout;

    if (caps.dwFlags & 0x20) {
        L->Log(s_guar_opt);
    } else {
        L->Log(s_not_guar_opt);
    }

    if (caps.dwFlags & 2) {
        L->Log(s_session_host_msg);
    } else {
        L->Log(s_not_session_host_msg);
    }

    if (caps.dwFlags & 0x10) {
        L->Log(s_keepalive);
    } else {
        L->Log(s_not_keepalive);
    }

    if (caps.dwFlags & 0x40) {
        L->Log(s_guar_delivery);
    } else {
        L->Log(s_not_guar_service);
    }

    this->RGE_Guaranteed_Delivery = 1;
    return hr;
}






long TCommunications_Handler::CloseSession(void) {
    long result = 0;

    L->Log("Close Session Call");

    IDirectPlay3* dp = direct_play_interface;
    if (dp != 0) {
        result = dp->Close();
    }

    this->SessionGUID = this->NullGUID;

    this->Err->ShowReturn(result, "Close Session");

    for (int i = 1; i <= static_cast<int>(this->MaxGamePlayers); i++) {
        this->LastTurnAck[i] = 0;
    }

    return result;
}

long TCommunications_Handler::ReleaseComm() {
    if (direct_play_interface != 0) {
        unsigned long links = direct_play_interface->Release();
        L->Log("1.Release COMM links=%d", links);
        this->ServiceGUID = this->NullGUID;
        direct_play_interface = 0;
    }
    return 0;
}



int TCommunications_Handler::Kick(unsigned int param_1)
{
    if (param_1 >= 1 && param_1 <= this->MaxGamePlayers && direct_play_interface) {
        if (this->IsPlayerHuman(param_1)) {
            if (this->PlayerOptions.dcoID[param_1] != 0) {
                MSGFORMAT_KILL_PLAYER kp;
                kp.PlayerNo = param_1;
                kp.dcoID = this->PlayerOptions.dcoID[param_1];
                kp.CurrentTurn = this->current_turn;

                L->Log("Sent to all - drop player %d ID=%d ", param_1, this->PlayerOptions.dcoID[param_1]);
                L->Log("  >TX KP3 #d (%d)", param_1, 0x0C);

                this->CommOut(0, 'K', &kp.PlayerNo, 0x0C, 0);

                if (this->PlayerStopTurn[param_1] == 0) {
                    this->DropDeadPlayer(param_1, this->PlayerOptions.dcoID[param_1]);
                }
            }

        this->NotifyWindow(COMM_UPDATE_PLAYERS);

            if (this->MeHost != 0 && this->current_turn <= 6) {
                this->SendSharedData(1);
            }

            return 1;
        }
    }
    return 0;
}




long TCommunications_Handler::DestroyMyPlayer()
{
    long result;

    if (direct_play_interface == 0)
        return 0;

    if (local_player_dpid == 0)
        return 0;

    result = direct_play_interface->DestroyPlayer(local_player_dpid);
    this->Err->ShowReturn(result, "Release Player");
    if (result == 0) {
        local_player_dpid = result;
        this->Me = result;
    }
    return result;
}






int TCommunications_Handler::SetMyGameOptions(char* param_1, unsigned long param_2) {
    if (param_2 > 2000)
        return 0;

    this->FreeOptions();

    if (param_1 != 0 && param_2 != 0) {
        char* buf = new char[param_2 + 1];
        this->OptionsData = buf;
        if (buf == 0)
            return 0;

        memcpy(buf, param_1, param_2);
        this->PlayerOptions.DataSizeToFollow = param_2;
    }

    if (this->MeHost != 0) {
        this->PlayerOptions.NeedsToBeSent = 1;
    }

    L->Log("Host Set Options to size %d", param_2);
    return 1;
}

void* TCommunications_Handler::GetMyGameOptions(unsigned long* param) {
    *param = this->PlayerOptions.DataSizeToFollow;
    return this->OptionsData;
}

void TCommunications_Handler::FreeOptions(void) {
    if (this->OptionsData != 0) {
        this->PlayerOptions.DataSizeToFollow = 0;
        operator delete(this->OptionsData);
        this->OptionsData = 0;
    }
}












struct _GUID;

int __cdecl StringFromGUID(_GUID* guid, unsigned short* output)
{
    int i;
    unsigned char* g;

    // BINARY NOTE: StringFromGUID reads the proven byte view of the GUID.
    g = reinterpret_cast<unsigned char*>(guid);
    *output = 0x7b;
    output = output + 1;
    i = 0;
    do {
        if (guid_format_positions[i] == '-') {
            *output = '-';
        } else {
            output = output + 1;
            output[-1] = guid_hex_digits[g[guid_format_positions[i]] >> 4];
            output[0] = guid_hex_digits[g[guid_format_positions[i]] & 0xf];
        }
        output = output + 1;
        i = i + 1;
    } while (static_cast<unsigned int>(i) < 20);
    *output = '}';
    output[1] = 0;
    return 0x26;
}

void TCommunications_Handler::SetHostPlayerNumber(unsigned int v) { this->PlayerOptions.HostPlayerNumber = v; }

unsigned int TCommunications_Handler::GetHostPlayerNumber() { return this->PlayerOptions.HostPlayerNumber; }





typedef unsigned short ushort;

void TCommunications_Handler::DebugSessionInformation(DPSESSIONDESC2* desc)
{
    ushort wszSPGuid[40];

    L->Log("--Information in DPSESSIONDESC2 --");
    L->Log("Size DPSESSIONDESC2 =%d", desc->dwSize);
    L->Log("Flags               =%d", desc->dwFlags);
    L->Log("Instance guid  DATA1=%u", desc->guidInstance.Data1);
    L->Log("               DATA2=%d", desc->guidInstance.Data2);
    L->Log("               DATA3=%d", desc->guidInstance.Data3);
    L->Log("               DATA4=%u", desc->guidInstance.Data4);
    StringFromGUID(&desc->guidInstance, wszSPGuid);
    L->Log("Instance GUID  str  =%s", wszSPGuid);
    L->Log("Applicatn guid DATA1=%u", desc->guidApplication.Data1);
    L->Log("               DATA2=%d", desc->guidApplication.Data2);
    L->Log("               DATA3=%d", desc->guidApplication.Data3);
    L->Log("               DATA4=%u", desc->guidApplication.Data4);
    L->Log("Max Players         =%d", desc->dwMaxPlayers);
    L->Log("Current Players     =%d", desc->dwCurrentPlayers);
    L->Log("Reserved 1          =%d", desc->dwReserved1);
    L->Log("Reserved 2          =%d", desc->dwReserved2);
    L->Log("User 1              =%d", desc->dwUser1);
    L->Log("User 2              =%d", desc->dwUser2);
    L->Log("User 3              =%d", desc->dwUser3);
    L->Log("User 4              =%d", desc->dwUser4);
    L->Log("--End Info--");
}

long TCommunications_Handler::EnableNewPlayers(IDirectPlay2* dp, int enable) {
    if (dp == 0) return 0x80070057;
    void* queried_object;
    long hr = dp->QueryInterface(IID_IDirectPlay, &queried_object);
    if (hr < 0) return hr;
    IDirectPlay* base = static_cast<IDirectPlay*>(queried_object);
    hr = base->EnableNewPlayers(enable);
    unsigned long links = base->Release();
    L->Log("Released to links=%d", links);
    return hr;
}

void TCommunications_Handler::OutOfSync(int a, unsigned long b) {
    this->OutOfSyncFlag = a;
    this->dwStopTime = b;
}




int TCommunications_Handler::SendZoneMessage(char* msg, unsigned long param_2) {
    if (!this->LobbyLaunched) {
        L->Log("NOT LOBBY LAUNCHED.  EXITING");
        return 0;
    }

    L->Log("Sending zone message.");
    L->Log("  >TX ZONE MSG (%u)", param_2);

    GUID zone_guid = rge_base_game->prog_info->zone_guid;

    long result = this->Lobby->SendZoneMessage(msg, param_2, zone_guid);

    if (result == 0) {
        return 1;
    }

    this->Err->ShowReturn(result, "SendGameOptions");
    return 0;
}








int __stdcall EnumPlayersCallback2(
    unsigned long param_1,
    unsigned long param_2,
    DPNAME* param_3,
    unsigned long param_4,
    void* param_5)
{
    TCommunications_Handler* handler =
        static_cast<TCommunications_Handler*>(param_5);
    int foundIndex = 0;
    if (param_1 != 0) {
        int first = handler->PlayerOptions.LowPlayerNumber;
        int last = handler->PlayerOptions.HighPlayerNumber;
        for (int i = first; i <= last; ++i) {
            if (handler->PlayerOptions.dcoID[i] == param_1) {
                foundIndex = i;
                break;
            }
        }
    }
    sprintf(comm_enum_buffer, "ENUM %d name=%s id=%d", param_1, param_3->lpszShortNameA, foundIndex);
    L->Log("ENUM DEBUG: %s", comm_enum_buffer);
    L->Log("FORCEENUM %d name=%s id=%d", param_1, param_3->lpszShortNameA, foundIndex);
    L->Log("FILL PLAYER INFORMATION.");
    static_cast<TCommunications_Handler*>(param_5)->UpdatePlayerInformation(
        param_1, param_3->lpszShortNameA, param_3->lpszLongNameA);
    return 1;
}


void TCommunications_Handler::ForcePlayerEnumeration(void) {
    L->Log("Force Calling enumeration of players.");


    direct_play_interface->EnumPlayers(0,
                              (LPDPENUMPLAYERSCALLBACK2)EnumPlayersCallback2,
                              this, 0);
}


void TCommunications_Handler::ForcePlayerDestroyAndCreate() {
    L->Log("Force Self player destroy and create!");
    direct_play_interface->DestroyPlayer(local_player_dpid);
    local_player_dpid = 0;
    this->AddSelfPlayer();
    L->Log("Create called.");
}





























































void TCommunications_Handler::ForceNameChange(void) {
    DPNAME dpn;

    L->Log("Force Name Change");

    char test[32] = "TEMPORARY NAME";

    dpn.lpszShortNameA = test;
    dpn.lpszLongNameA = test;
    dpn.dwSize = 0x10;

    direct_play_interface->SetPlayerName(local_player_dpid, &dpn, 2);
}

void TCommunications_Handler::SetSpeedV1(unsigned long param) {
    this->Speed->SetV1(param);
}

void TCommunications_Handler::SetSpeedV2(unsigned long param) {
    this->Speed->SetV2(param);
}

int TCommunications_Handler::IsPlayerOutOfSync(unsigned int player,
                                               unsigned long turn) {
    return this->Sync->IsPlayerOutOfSync(player, turn);
}
