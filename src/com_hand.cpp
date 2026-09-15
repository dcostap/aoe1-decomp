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







char* TCommunications_Handler::WaitingOnNamedInfo(unsigned int PlayerNo) {
    sprintf(this->TBuff, "[%d] %s - %s", PlayerNo,
        this->GetPlayerName(PlayerNo),
        this->WaitingOnInfo(PlayerNo));

    int timeSince = debug_timeGetTime(com_hand_source_path, 0x8E)
        - this->LastPlayerCommunication[PlayerNo];

    sprintf(this->TBuff, "[%d] %s - %s (QUIET=%d msec  T#=%d )",
        PlayerNo,
        this->GetPlayerName(PlayerNo),
        this->WaitingOnInfo(PlayerNo),
        timeSince,
        this->LastTurnAck[PlayerNo]);

    return this->TBuff;
}






char* TCommunications_Handler::WaitingOnInfo(unsigned int PlayerNo)
{
    unsigned int player = PlayerNo;

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

void TCommunications_Handler::StopIfSyncFail(int b) {
    this->Sync->SetDialogOnFail(b);
    this->Sync->SetStopOnFail(b);
}

void TCommunications_Handler::ShowSyncChatMsgs(int b) {
    this->Sync->SendChatMsgsAtChecksum(b);
}


void TCommunications_Handler::DropPacketsIntentionally(int b) {
    this->IntentionallyDropPackets = b;
    if (b) {
        L->Log("DROPPING PACKETS INTENTIONALLY!!!");
    }
}


void TCommunications_Handler::SetStepMode(int b) { this->StepMode = b; }

void TCommunications_Handler::SetSpeedControl(int b) {
    this->Speed->EnableSpeedControl(b);
}












int TCommunications_Handler::CalculatePlayerRange(void) {
    unsigned int i = 1;
    unsigned short maxPlayers = this->MaxGamePlayers;

    this->PlayerOptions.HighPlayerNumber = 0;
    this->PlayerOptions.LowPlayerNumber = maxPlayers + 1;

    if (static_cast<int>(maxPlayers) < 1)
        goto done;

    do {
        if (this->IsPlayerHuman(i))
            goto update;
        if (!this->IsPlayerComputer(i))
            goto skip;
update:
        {
            int high = static_cast<int>(this->PlayerOptions.HighPlayerNumber);
            if (high <= static_cast<int>(i))
                high = i;
            this->PlayerOptions.HighPlayerNumber = static_cast<unsigned short>(high);

            int low = static_cast<int>(this->PlayerOptions.LowPlayerNumber);
            if (low >= static_cast<int>(i))
                low = i;
            this->PlayerOptions.LowPlayerNumber = static_cast<unsigned short>(low);
        }
skip:
        ++i;
    } while (static_cast<int>(i) <=
             static_cast<int>(static_cast<unsigned short>(this->MaxGamePlayers)));

done:
    return 1;
}

void TCommunications_Handler::Step(int Numsteps) {
    TEST();
    Steps += Numsteps;
}






























































TCommunications_Handler::TCommunications_Handler(void* WinHandle, unsigned char MaxPlayers, TChat* ChatHandle, GUID AppGuid)
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
    this->ApplicationGUID = AppGuid;
    this->SessionGUID = this->NullGUID;
    this->ServiceGUID = this->NullGUID;
    this->HostHWND = WinHandle;
    this->Chat = ChatHandle;
    this->MaxGamePlayers = MaxPlayers;

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
    int count = MaxPlayers + 1;


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

    count = MaxPlayers + 1;
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
    this->Err = new RGE_Comm_Error(WinHandle);
    this->Lobby = new RGE_Lobby(WinHandle);
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
    long hr;
    unsigned long dwSize;
    char* buf;
    unsigned int i = 1;

    if (i <= this->MaxGamePlayers) {
        do {
            if (this->IsPlayerHuman(i)) {
                dwSize = 0;
                direct_play_interface->GetPlayerName(
                    this->PlayerOptions.dcoID[i], 0, &dwSize);

                buf = new char[dwSize];
                hr = direct_play_interface->GetPlayerName(
                    this->PlayerOptions.dcoID[i], buf, &dwSize);
                delete[] buf;

                if (hr != 0) {
                    kp.PlayerNo = i;
                    kp.dcoID = this->PlayerOptions.dcoID[i];
                    kp.CurrentTurn = this->current_turn;
                    L->Log("  >TX KP #%d (%d)", i, 0x0C);
                    this->CommOut(0, 0x4B, &kp.PlayerNo, 0x0C, 0);

                    if (this->PlayerStopTurn[i] == 0) {
                        this->DropDeadPlayer(i, this->PlayerOptions.dcoID[i]);
                    }
                }
            }

            ++i;
        } while (i <= this->MaxGamePlayers);
    }
}
int TCommunications_Handler::AddCommand(unsigned long ExecuteOnTurn, void* command,
                                        unsigned long nBytes, int PFrom,
                                        unsigned char Sequence, int ControlCommand) {
    return this->InQ->AddItem(ExecuteOnTurn, command, nBytes,
                              static_cast<unsigned int>(PFrom), Sequence,
                              ControlCommand);
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

unsigned char TCommunications_Handler::new_command(void* Command, int Size) {
    return static_cast<unsigned char>(NewCommand(Command, Size, 0));
}




int TCommunications_Handler::NewCommand(void* Command, int Size,
                                        int ControlCommand) {
    if (this->Multiplayer != 0) {
        unsigned char command_code;
        memcpy(&command_code, Command, sizeof(command_code));
        L->Log("  >TX CMD (%d) Cmd=%d ", Size,
               static_cast<int>(command_code));
        long _r = this->CommOut(0, 0x3E, Command, Size, 0);
        this->Err->ShowReturn(_r, "NewCmnd");
    } else {
        int _t = this->current_turn + this->PlayerOptions.CommandTurnIncrement;
        this->AddCommand(_t, Command, Size, static_cast<int>(this->Me),
                         this->InQ->GetNextSequence(this->current_turn),
                         ControlCommand);
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

void TCommunications_Handler::LastWorldRandom(int lwr) {
    this->Sync->SetLastWorldRandom(lwr);
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



int TCommunications_Handler::DoCycle(ulong WorldTime)
{
    if (this->Multiplayer == 0) {
        return (this->PlayerOptions.ProgramState == COMM_STATE_PAUSE) ? 0 : -1;
    }
    if (this->Me > static_cast<uint>(this->MaxGamePlayers)) {
        return 0;
    }

    ulong Now = debug_timeGetTime(com_hand_source_path, 0x20D);
    if (Now - comm_last_dump_time >= 5000) {
        L->Log(GetCommInfo(6));
        L->Log(GetCommInfo(5));
        L->Log(GetCommInfo(4));
        L->Log(GetCommInfo(3));
        L->Log(GetCommInfo(2));
        L->Log(GetCommInfo(1));
        comm_last_dump_time = Now;
    }

    this->ReceiveGameMessages();
    this->LastPlayerCommunication[this->Me] = Now;

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

    if ((this->OutOfSyncFlag == 1) && (WorldTime >= this->dwStopTime)) {
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
        Now = debug_timeGetTime(com_hand_source_path, 0x259);

        char msg_str[100];
        uint i = 1;
        int selfTimedOutCount;
        int LastAnyPlayerMessage;
        LastAnyPlayerMessage = 0;
        selfTimedOutCount = 0;
        if (this->MaxGamePlayers >= i) {
            do {
                if (this->IsPlayerHuman(i) && i != this->Me) {
                    selfTimedOutCount++;
                    if (G > this->LastPlayerCommunication[i]) {

                    } else {
                        G = this->LastPlayerCommunication[i];
                    }
                    ulong elapsed = Now - this->LastPlayerCommunication[i];
                    if (elapsed > 60000) {
                        LastAnyPlayerMessage++;
                    }
                    if (elapsed > 25000 && Now - this->LastPlayerWarning[i] > 25000) {
                        this->LastPlayerWarning[i] = Now;
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
                        this->LastPlayerCommunication[i] = Now;
                        this->LastTXPing[i] = Now;
                    }
                }
                i++;
            } while (i <= static_cast<unsigned int>(this->MaxGamePlayers));
        }

        ++selfTimedOutCount;
        if ((selfTimedOutCount == 3 && LastAnyPlayerMessage >= 2) ||
            (selfTimedOutCount != 3 &&
             LastAnyPlayerMessage >= selfTimedOutCount / 2)) {


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
            if (Now - lastTimeout > 25000) {
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
    uint F = 0;
    if (this->MeHost != 0) {
        this->Speed->AnalyzeGameSpeed(&WT, &F, 1);
    }
    this->current_turn++;
    L->Log("....Starting Turn#%d, WT=%d, Fr=%d, Gr=%d", this->current_turn, WorldTime, WT, F);
    this->CheckPlayerStopTurn(this->current_turn);
    return this->Speed->GetBufferGranularityAdjusted();
}

int TCommunications_Handler::HasKicked(unsigned int p) { return this->Kicked[p]; }




































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

void TCommunications_Handler::LogRXMsg(unsigned int Serialno, unsigned int fromPlayer, unsigned long ExecuteOnTurn, unsigned char Command, unsigned char Sequence)
{
    if (this->RGE_Guaranteed_Delivery != 0) {
        L->Log("GTD: RX Ser#%d From P#%d T#%ld ToExecT#%d %d", Serialno, fromPlayer, this->current_turn, ExecuteOnTurn, Command, Command, Sequence);
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

    if (local_player_dpid != 0) {
        unsigned long wait_count = zero;
        long result = direct_play_interface->GetMessageCount(local_player_dpid,
                                                              &wait_count);
        if (result != zero) {
            this->Err->ShowReturn(result, "MsgWait");
            goto done_reading;
        }
        if (wait_count == zero)
            goto done_reading;
    }

    this->GetDPLAYMessages();
    if (this->RGE_Guaranteed_Delivery != 0) {
        this->ExecuteIncoming();
    }

done_reading:

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
    ulong loopStartTime;
    long hr;
    IDirectPlay3* guard_dplay = direct_play_interface;
    dcoFromID = 0;
    dcoReceiveID = 0;
    if (guard_dplay == 0) return;
    dwCount = 4000;
    dwSize = 4000;
    char* buf = this->InCommBuff;
    loopStartTime = debug_timeGetTime(com_hand_source_path, 0x3d4);
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
        elapsed = debug_timeGetTime(com_hand_source_path, 0x417) - loopStartTime;
        if (elapsed > 500) {
            ulong now = debug_timeGetTime(com_hand_source_path, 0x419);
            L->Log("!!! In Receive Loop for %u ms", now - loopStartTime);
        }
        if (hr == static_cast<long>(0x887700BE)) return;
        if (dwSize == 0) return;
        if (hr != 0) { this->Err->ShowReturn(hr, "Rcv MSG"); return; }
        int pno;
        if (dcoFromID != 0) {
            int i = this->PlayerOptions.LowPlayerNumber;
            int hi = this->PlayerOptions.HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->PlayerOptions.dcoID + i;
                for (; i <= hi; i++, p++) {
                    if (*p == dcoFromID)
                        goto found_first_player;
                }
            }
            i = 0;
found_first_player:
            pno = i;
        } else pno = 0;
        L->Log("  >RX #%d %c-%d (%u)", pno, static_cast<int>(*buf), static_cast<int>(*buf), dwSize);
        int pno2;

        if (dcoFromID != 0) {
            int i = this->PlayerOptions.LowPlayerNumber;
            int hi = this->PlayerOptions.HighPlayerNumber;
            if (i <= hi) {
                ulong* p = this->PlayerOptions.dcoID + i;
                for (; i <= hi; i++, p++) {
                    if (*p == dcoFromID) {
                        pno2 = i;
                        goto found_second_player;
                    }
                }
            }
        }
        pno2 = 0;
found_second_player:
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






void TCommunications_Handler::CheckPingTime(int Forced) {
    if (!this->Multiplayer)
        return;

    unsigned long currentTime = debug_timeGetTime(com_hand_source_path, 0x460);

    unsigned int i = 1;
    if (static_cast<unsigned int>(this->MaxGamePlayers) < i)
        return;

    do {
        if (this->IsPlayerHuman(i) && i != static_cast<unsigned int>(this->Me)) {
            unsigned long elapsed = currentTime - this->LastTXPing[i];
            if (elapsed > 8000 || Forced) {
                this->TXPing(i);
            }
        }
        i++;
    } while (i <= static_cast<unsigned int>(this->MaxGamePlayers));
}

int TCommunications_Handler::TXPing(unsigned int ToPlayer) {
    unsigned long t = debug_timeGetTime(com_hand_source_path, 0x470);
    unsigned int id = ToPlayer;
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







long TCommunications_Handler::FastSend(unsigned long ToDPID, void* Buffer, unsigned long BuffLen, int Priority, int Guaranteed) {
    unsigned long start;
    long hr;
    unsigned long elapsed;
    int recipients;
    unsigned int i;

    if (ToDPID == local_player_dpid) {
        L->Log("No send-to-self FastTX");
        return E_FAIL;
    }
    if (local_player_dpid == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return E_FAIL;
    }

    start = debug_timeGetTime(com_hand_source_path, 0x4CA);
    hr = direct_play_interface->Send(local_player_dpid, ToDPID, 0, Buffer, BuffLen);
    elapsed = debug_timeGetTime(com_hand_source_path, 0x4D3) - start;
    if (elapsed > 0x32) {
        L->Log("!!!FastSend slow - %ld msec", elapsed);
    }

    recipients = static_cast<int>(ToDPID);
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

    TXPacketLength += recipients * BuffLen;

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








int TCommunications_Handler::PreprocessMessages(unsigned long dwSize, char* CommBuff,
                                                unsigned long dcoFromID,
                                                unsigned long dcoReceiveID, int fromHold)
{
    unsigned int player = 0;
    if (dcoFromID != 0) {
        unsigned int i = this->PlayerOptions.LowPlayerNumber;
        unsigned int high = this->PlayerOptions.HighPlayerNumber;
        if (static_cast<int>(i) <= static_cast<int>(high)) {
            do {
                if (this->PlayerOptions.dcoID[i] == dcoFromID) {
                    player = i;
                    break;
                }
                ++i;
            } while (static_cast<int>(i) <= static_cast<int>(high));
        }
    }

    if (*CommBuff == 'I') {
        this->UnlinkToLevel(SERVICE_AVAILABLE);
        this->NotifyWindow(COMM_UPDATE_PLAYERS);
        this->NotifyWindow(COMM_PLAYER_KICKED);
        return 1;
    }

    if (player == 0) {
        L->Log("Bad player # for ID=%d", dcoFromID);

        MSGFORMAT_ACKNOWLEDGE_GUARANTEED sack;
        sack.Serialno = *reinterpret_cast<unsigned int*>(CommBuff + 8);
        sack.Command = 'A';
        if (local_player_dpid == 0) {
            L->Log("+++BAD DCOID=0 NO TX");
            return 0;
        }
        direct_play_interface->Send(local_player_dpid, dcoFromID, 0, &sack,
                                    8);
        this->TXPacketLength += 8;
        return 0;
    }

    this->LastPlayerCommunication[player] =
        debug_timeGetTime(com_hand_source_path, 0x543);

    unsigned int log_player = 0;
    if (dcoFromID != 0) {
        unsigned int i = this->PlayerOptions.LowPlayerNumber;
        unsigned int high = this->PlayerOptions.HighPlayerNumber;
        if (static_cast<int>(i) <= static_cast<int>(high)) {
            do {
                if (this->PlayerOptions.dcoID[i] == dcoFromID) {
                    log_player = i;
                    break;
                }
                ++i;
            } while (static_cast<int>(i) <= static_cast<int>(high));
        }
    }

    unsigned int* serial = reinterpret_cast<unsigned int*>(CommBuff + 8);
    L->Log("PREPRO-Byte0='%c' from=%d(%d)  ser#%d  timeGetTime=%d",
           static_cast<int>(*CommBuff), log_player, dcoFromID, *serial,
           debug_timeGetTime(com_hand_source_path, 0x54D));

    if (*CommBuff == 'K' &&
        this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
        L->Log("KILL Message recieved from %d to kill dcoID #%d ", dcoFromID,
               *reinterpret_cast<unsigned long*>(CommBuff + 16));
        if (*serial == this->PlayerHighSerialNumber[player] + 1)
            this->PlayerHighSerialNumber[player] = *serial;
        L->Log("  >TX KP ACK #%d %d (%d)", player, *serial, 8);
        this->TXAcknowledgeMessage(*serial, player);

        unsigned int killed_player =
            *reinterpret_cast<unsigned int*>(CommBuff + 12);
        this->PlayerHighSerialNumber[killed_player] = killed_player * 2000;
        if (*reinterpret_cast<unsigned long*>(CommBuff + 16) == local_player_dpid)
            this->NotifyWindow(COMM_PLAYER_KICKED);
        return 1;
    }

    if (*CommBuff == 'C') {
        MSGFORMAT_CHAT* chat_msg;
        if (this->RGE_Guaranteed_Delivery != 0)
            chat_msg = reinterpret_cast<MSGFORMAT_CHAT*>(CommBuff + 12);
        else
            chat_msg = reinterpret_cast<MSGFORMAT_CHAT*>(CommBuff + 8);

        if (chat_msg->Pregame != 0 &&
            this->PlayerOptions.ProgramState != COMM_STATE_JOINNOW) {
            L->Log("DISCARD: ChtPregame=%d PgmState=%d  Msg=%s",
                   chat_msg->Pregame, this->PlayerOptions.ProgramState,
                   chat_msg->ChatMsg);
            return 0;
        }
        L->Log("CHAT: ChtPregame=%d PgmState=%d  Msg=%s",
               chat_msg->Pregame, this->PlayerOptions.ProgramState,
               chat_msg->ChatMsg);
    }

    unsigned char command = static_cast<unsigned char>(*CommBuff);
    if (command == 'A') {
        this->RXAcknowledgeStoredMessage(
            *reinterpret_cast<unsigned int*>(CommBuff + 4), player);
        this->PurgeAcknowledgedStoredMessages();
        return 1;
    }

    if (command == 'R') {
        L->Log("PLAYER READY MSG");
        if (this->MeHost != 0) {
            this->PlayerOptions.PlayerReady[player] =
                static_cast<unsigned char>(CommBuff[1]);
            L->Log("Rcvd Ready=%d from player %d",
                   static_cast<unsigned char>(CommBuff[1]), player);
            this->PlayerOptions.User1[player] =
                *reinterpret_cast<unsigned long*>(CommBuff + 4);
            this->PlayerOptions.User2[player] =
                *reinterpret_cast<unsigned long*>(CommBuff + 8);
            this->PlayerOptions.User3[player] =
                *reinterpret_cast<unsigned long*>(CommBuff + 12);
            this->PlayerOptions.User4[player] =
                *reinterpret_cast<unsigned long*>(CommBuff + 16);
            this->PlayerOptions.User5[player] =
                *reinterpret_cast<unsigned long*>(CommBuff + 20);
            this->PlayerOptions.User6[player] =
                *reinterpret_cast<unsigned long*>(CommBuff + 24);
            this->PlayerOptions.User7[player] =
                *reinterpret_cast<unsigned long*>(CommBuff + 28);

            if (!this->IsPlayerHuman(player))
                this->SetPlayerHumanity(player, ME_HUMAN);

            unsigned long local_version = this->CommunicationsVersionCode;
            unsigned long version =
                *reinterpret_cast<unsigned long*>(CommBuff + 32);
            if (local_version == version) {
                L->Log("Communications versions for HOST and player %d match (%d)",
                       player, local_version);
            } else {
                this->NotifyWindowParam(COMM_PLAYER_SERVICE_ERROR, player);
                sprintf(this->TBuff,
                        "Player %d has a different Communications Version",
                        player);
                L->Log(this->TBuff);
            }

            this->PlayerOptions.NeedsToBeSent = 1;
            this->SendSharedData(0);
            this->UpdatePlayer(player, 0);
            sprintf(this->TBuff,
                    " Plr Rdy: P1=%d P2=%d P3=%d P4=%d P5=%d P6=%d P7=%d P8=%d",
                    this->PlayerOptions.PlayerReady[1],
                    this->PlayerOptions.PlayerReady[2],
                    this->PlayerOptions.PlayerReady[3],
                    this->PlayerOptions.PlayerReady[4],
                    this->PlayerOptions.PlayerReady[5],
                    this->PlayerOptions.PlayerReady[6],
                    this->PlayerOptions.PlayerReady[7],
                    this->PlayerOptions.PlayerReady[8]);
            L->Log(this->TBuff);
            this->NotifyWindow(COMM_UPDATE_PLAYERS);
        }
        return 1;
    }

    if (command == '1') {
        unsigned long turn = this->current_turn;
        int multiplayer = this->Multiplayer;
        unsigned long initiated =
            *reinterpret_cast<unsigned long*>(CommBuff + 4);
        unsigned char turn_increment =
            this->PlayerOptions.CommandTurnIncrement;
        unsigned int done_turn = turn_increment + turn;

        if (multiplayer != 0 &&
            this->PlayerOptions.ProgramState != COMM_STATE_JOINNOW &&
            this->LastTurnAck[this->Me] != turn) {
            this->LastTurnAck[this->Me] = turn;
            MSGFORMAT_ALL_DONE done;
            if (this->current_turn > 6) {
                done.HighLatencyCenti = this->Speed->GetHighLatencyCenti();
                done.FrameRateMsec =
                    static_cast<unsigned char>(this->Speed->GetAvgFrameRate());
                this->Speed->SetPlayerTurnSpeed(this->Me, done.FrameRateMsec,
                                                done.HighLatencyCenti);
            }
            comm_last_sent_time =
                debug_timeGetTime(com_hand_source_path, 0xBF9);
            done.Command = 'D';
            done.ExecuteOnTurn = done_turn;
            L->Log("  >TX DONE (%d)", 0x0C);
            this->CommOut(0, 'D', &done, 0x0C, 0);
        }

        MSGFORMAT_LATENCY txpingpong;
        txpingpong.Command = '2';
        txpingpong.Initiated = initiated;
        txpingpong.CurrentTurn = this->current_turn;
        L->Log("  >TX PONG #%d (%d)", player, 0x0C);
        long result = this->FastSend(this->PlayerOptions.dcoID[player], &txpingpong,
                                     0x0C, 0, 0);
        this->Err->ShowReturn(result, "TX Ping");
        return 1;
    }

    if (command == '3') {
        MSGFORMAT_LATENCY txpingpong;
        txpingpong.Command = '4';
        txpingpong.Initiated = *reinterpret_cast<unsigned long*>(CommBuff + 4);
        txpingpong.CurrentTurn = this->current_turn;
        L->Log("  >TX DEBUG PONG #%d (%d)", player, 0x0C);
        long result = this->FastSend(this->PlayerOptions.dcoID[player], &txpingpong,
                                     0x0C, 0, 0);
        this->Err->ShowReturn(result, "TX Debug Ping");

        char msg[256];
        sprintf(msg, "Received debug ping from %s (#%d)",
                this->GetPlayerName(player), player);
        L->Log(msg);
        this->Chat->AddChatMsg("DEBUG", msg, 0);
        return 1;
    }

    if (command == '?') {
        if (this->MeHost != 0) {
            unsigned long invalid_dco =
                *reinterpret_cast<unsigned long*>(CommBuff + 4);
            unsigned int invalid_player = 0;
            if (invalid_dco != 0) {
                unsigned int i = this->PlayerOptions.LowPlayerNumber;
                unsigned int high = this->PlayerOptions.HighPlayerNumber;
                if (static_cast<int>(i) <= static_cast<int>(high)) {
                    do {
                        if (this->PlayerOptions.dcoID[i] == invalid_dco) {
                            invalid_player = i;
                            break;
                        }
                        ++i;
                    } while (static_cast<int>(i) <=
                             static_cast<int>(high));
                }
            }

            if (this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
                sprintf(this->TBuff,
                        " P#%d reported P#%d (dco=%d) was invalid ", player,
                        invalid_player, invalid_dco);
                L->Log(this->TBuff);
                L->Log("Rcvd Missing Player report for player #%d, ID=%d from player %d",
                       invalid_player,
                       *reinterpret_cast<unsigned long*>(CommBuff + 4), player);
                this->PlayerOptions.PlayerReady[invalid_player] = 0;
                this->PlayerOptions.InvalidPlayer[invalid_player] = 1;
                this->PlayerOptions.NeedsToBeSent = 1;
            } else {
                L->Log("Rcvd MAX TX report for player #%d, ID=%d from player %d",
                       invalid_player, invalid_dco, player);
                this->Kick(invalid_player);
            }
        }
        return 1;
    }

    if (command == '2') {
        unsigned long now = debug_timeGetTime(com_hand_source_path, 0x672);
        unsigned long initiated =
            *reinterpret_cast<unsigned long*>(CommBuff + 4);
        unsigned char turn_increment =
            this->PlayerOptions.CommandTurnIncrement;
        unsigned long turn = this->current_turn;
        unsigned int done_turn = turn_increment + turn;

        if (this->Multiplayer != 0 &&
            this->PlayerOptions.ProgramState != COMM_STATE_JOINNOW &&
            this->LastTurnAck[this->Me] != turn) {
            this->LastTurnAck[this->Me] = turn;
            MSGFORMAT_ALL_DONE done;
            if (this->current_turn > 6) {
                done.HighLatencyCenti = this->Speed->GetHighLatencyCenti();
                done.FrameRateMsec =
                    static_cast<unsigned char>(this->Speed->GetAvgFrameRate());
                this->Speed->SetPlayerTurnSpeed(this->Me, done.FrameRateMsec,
                                                done.HighLatencyCenti);
            }
            comm_last_sent_time =
                debug_timeGetTime(com_hand_source_path, 0xBF9);
            done.Command = 'D';
            done.ExecuteOnTurn = done_turn;
            L->Log("  >TX DONE (%d)", 0x0C);
            this->CommOut(0, 'D', &done, 0x0C, 0);
        }

        this->Speed->SetActualLatency(player, now - initiated);
        return 1;
    }

    if (command == '4') {
        unsigned long now = debug_timeGetTime(com_hand_source_path, 0x68B);
        unsigned long elapsed =
            now - *reinterpret_cast<unsigned long*>(CommBuff + 4);
        char msg[256];
        sprintf(msg, "%s #%d Debug ping - elapsed=%d",
                this->GetPlayerName(player), player, elapsed);
        L->Log(msg);
        this->Chat->AddChatMsg("DEBUG", msg, 0);
        return 1;
    }

    if (command == 'Y') {
        if (this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
            this->PlayerHighSerialNumber[player] =
                *reinterpret_cast<unsigned int*>(CommBuff + 4);
            this->ClearRXForPlayer(player);
            L->Log("NOSUCHSERIAL - Setting P#%d SER from %d to %d", player,
                   this->PlayerHighSerialNumber[player],
                   *reinterpret_cast<unsigned int*>(CommBuff + 4));
        }
        return 1;
    }

    if (this->RGE_Guaranteed_Delivery == 0) {
        this->LogRXMsg(*serial, player,
                       *reinterpret_cast<unsigned long*>(CommBuff + 4), command,
                       static_cast<unsigned char>(CommBuff[1]));
        comm_receive_message = CommBuff + 8;
        comm_receive_base = dwSize - 8;
    } else {
        if (this->IntentionallyDropPackets != 0 && this->current_turn > 6 &&
            ++comm_drop_count > 8) {
            char msg_str[100];
            rge_base_game->get_string(0x4BC, msg_str, 100);
            sprintf(this->TBuff, msg_str, *serial,
                    static_cast<int>(*CommBuff), static_cast<int>(*CommBuff));
            L->Log(this->TBuff);
            comm_drop_count = 0;
            return 1;
        }

        if (*CommBuff == 'X') {
            this->TXResendReply(
                *reinterpret_cast<unsigned int*>(CommBuff + 4), player);
            return 1;
        }

        if (this->PlayerHighSerialNumber[player] == 0) {
            L->Log("+++First contact with P#%d Next Serial Init to %d",
                   player, *serial);
            this->PlayerHighSerialNumber[player] = *serial - 1;
        }

        unsigned int NextSerialNumber =
            this->PlayerHighSerialNumber[player] + 1;
        if (*serial < NextSerialNumber) {
            sprintf(this->TBuff,
                    "GTD: RX Past Ser#%d rx. Expected %d from P#%d", *serial,
                    NextSerialNumber, player);
            L->Log(this->TBuff);
            L->Log("  >TX R ACK #%d %d (%d)", player, *serial, 8);
            this->TXAcknowledgeMessage(*serial, player);
            return 1;
        }

        if (*serial > NextSerialNumber) {
            ++this->DroppedPacketCount;
            sprintf(this->TBuff, "GTD: RX Future Ser#%d rx from P#%d",
                    *serial, player);
            L->Log(this->TBuff);
            this->StoreIncoming(*serial, CommBuff, dwSize, dcoFromID,
                                dcoReceiveID);
            L->Log("  >TX F ACK #%d %d (%d)", player, *serial, 8);
            this->TXAcknowledgeMessage(*serial, player);
            this->TXResendRequest(NextSerialNumber, player);
            return 1;
        }

        if (fromHold == 0) {
            L->Log("  >TX N ACK #%d %d (%d)", player, *serial, 8);
            this->TXAcknowledgeMessage(*serial, player);
        }
        this->PlayerHighSerialNumber[player] = *serial;
        comm_receive_message = CommBuff + 12;
        comm_receive_base = dwSize - 12;
    }

    L->Log(" PROCESS: Ser#%d  CMD=%d '%c' Seq=%d Turn=%d Size=%d From=%d To=%d",
           *serial, static_cast<unsigned char>(*CommBuff),
           static_cast<unsigned char>(*CommBuff),
           static_cast<unsigned char>(CommBuff[1]),
           *reinterpret_cast<unsigned long*>(CommBuff + 4), dwSize,
           dcoFromID, dcoReceiveID);
    if (this->ShuttingDown == 0) {
        this->EvaluatePlayerMessage(
           dwSize, player, *reinterpret_cast<unsigned long*>(CommBuff + 4),
            static_cast<unsigned char>(*CommBuff),
            static_cast<unsigned char>(CommBuff[1]), comm_receive_message,
            comm_receive_base, dcoFromID, dcoReceiveID);
    }
    return 1;
}

void TCommunications_Handler::NotifyWindow(COMMMESSAGES msg) {
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(msg), 0);
}

void TCommunications_Handler::NotifyWindowParam(COMMMESSAGES msg, long lparam) {
    PostMessageA(this->HostHWND, 0x400, msg, lparam);
    L->Log("COMM: Send msg to window WM_USER  Msg=%d  Param=%d\n", msg, lparam);
}







































int TCommunications_Handler::EvaluatePlayerMessage(unsigned long len,
                                                    unsigned int fromPlayer,
                                                    unsigned long ExecuteOnTurn,
                                                    unsigned char Command,
                                                    unsigned char Sequence,
                                                    char* Content,
                                                    unsigned int ContentSize,
                                                    unsigned long dcoFromID,
                                                    unsigned long dcoReceiveID)
{
    if (this->Multiplayer == 0)
        return 0;

    switch (Command) {
    case 'D': {
        MSGFORMAT_ALL_DONE* done =
            reinterpret_cast<MSGFORMAT_ALL_DONE*>(Content);
        this->Speed->SetPlayerTurnSpeed(fromPlayer, done->FrameRateMsec,
                                        done->HighLatencyCenti);
        if ((this->PlayerOptions.ProgramState < COMM_STATE_RUNNING) ||
            (this->current_turn < 6)) {
            if (done->ExecuteOnTurn < this->current_turn) {
                L->Log("+++REGRESSION WARNING, Current=%d  ExecuteOnTurn=%d",
                       this->current_turn, done->ExecuteOnTurn);
                return 0;
            }
        }

        unsigned long turn = done->ExecuteOnTurn -
                             this->PlayerOptions.CommandTurnIncrement;
        if (turn <= this->LastTurnAck[fromPlayer])
            turn = this->LastTurnAck[fromPlayer];
        this->LastTurnAck[fromPlayer] = turn;
        return 1;
    }

    case 'Q':
        this->SetPlayerStopTurn(
            fromPlayer, *reinterpret_cast<unsigned long*>(Content));
        return 1;

    case 'M': {
        MSGFORMAT_CHECKSUM* checksum =
            reinterpret_cast<MSGFORMAT_CHECKSUM*>(Content);
        this->Sync->Add(fromPlayer, checksum->WorldTime, checksum->WorldTurn,
                        checksum->Random, checksum->cs1, checksum->cs2,
                        checksum->cs3, checksum->cs4, checksum->cs5);
        return 1;
    }

    case '>':
        this->AddCommand(ExecuteOnTurn, Content, len, fromPlayer, Sequence, 0);
        return 1;

    case 'S': {
        MSGFORMAT_SPEEDCHANGE* speed =
            reinterpret_cast<MSGFORMAT_SPEEDCHANGE*>(Content);
        this->Speed->SetFutureSpeedChange(speed->BufferFrames,
                                          speed->FrameSizeMsec, ExecuteOnTurn);
        return 1;
    }

    case 'C': {
        MSGFORMAT_CHAT* chat = reinterpret_cast<MSGFORMAT_CHAT*>(Content);
        L->Log("CHAT-RX from P#%d(%d) RXID=%d Chat content='%s' TextSize=%d TotalSize=%d Pregame=%d",
               fromPlayer, dcoFromID, dcoReceiveID, chat->ChatMsg, chat->TextSize, ContentSize,
               chat->Pregame);
        if ((chat->DestPlayers[this->Me] == 'Y') ||
            (this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW)) {
            this->Chat->AddChatMsg(this->FriendlyName[chat->FromGamerID].Text,
                                   chat->ChatMsg, 0);
            return 1;
        }
        break;
    }

    case 'P':
        L->Log("P#%d Requested pause");
        this->LocalPauseGame(fromPlayer);
        this->Sync->LogChecksums(0, 0, 0, 0, 0, 0, 0, 0, 0);
        return 1;

    case 'U':
        L->Log("Resume msg rcvd");
        this->LocalResumeGame(fromPlayer);
        return 1;

    case '+':
        if (this->MeHost != 0) {
            this->SendPauseGame(0);
            L->Log("Non-host requested resume");
            this->LocalResumeGame(fromPlayer);
            return 1;
        }
        break;

    case 'W':
        if (this->MeHost != 0) {
            this->SendPauseGame(1);
            this->LocalPauseGame(fromPlayer);
            return 1;
        }
        break;

    case 'K': {
        MSGFORMAT_KILL_PLAYER* kill =
            reinterpret_cast<MSGFORMAT_KILL_PLAYER*>(Content);
        L->Log("KILL Message recieved from %d to kill P#%d ", fromPlayer,
               kill->PlayerNo);

        unsigned long dco_id = kill->dcoID;
        unsigned int target = 0;
        if (dco_id != 0) {
            target = this->PlayerOptions.LowPlayerNumber;
            unsigned int high = this->PlayerOptions.HighPlayerNumber;
            if (static_cast<int>(target) <= static_cast<int>(high)) {
                do {
                    if (this->PlayerOptions.dcoID[target] == dco_id)
                        goto kill_target_found;
                    ++target;
                } while (static_cast<int>(target) <= static_cast<int>(high));
            }
            target = 0;
        }

kill_target_found:
        if (target != 0) {
            if (this->PlayerStopTurn[target] == 0)
                this->DropDeadPlayer(target, dco_id);
            if (target == this->Me) {
                this->NotifyWindow(COMM_PLAYER_KICKED);
                return 1;
            }
            if (this->PlayerStopTurn[target] == 0) {
                this->NotifyWindowParam(COMM_OTHER_PLAYER_DROPPED, target);
                return 1;
            }
        }
        break;
    }

    case 'N':
        if (this->MeHost == 0) {
            L->Log("Host requested we delete and recreate our player");
            return 1;
        }
        break;

    default:
        L->Log("Unknown message : %d '%c'", Command, Command);
        break;
    }

    return 1;
}

void TCommunications_Handler::SetPlayerStopTurn(unsigned int player, unsigned long Turn) {
    this->PlayerStopTurn[player] = Turn;
}









void TCommunications_Handler::CheckPlayerStopTurn(unsigned long Turn)
{
    int StopPending = 0;
    unsigned int i = 1;

    if (this->MaxGamePlayers >= i) {
        do {
            if (this->PlayerStopTurn[i] != 0)
                StopPending = 1;

            if (this->PlayerStopTurn[i] == Turn) {
                L->Log("CheckPlayerStopTurn: Drop player %d on turn %d", i, Turn);
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





long TCommunications_Handler::SendSharedData(int SendImmediately)
{
    if (direct_play_interface == 0) {
        return 0;
    }
    if (this->MeHost == 0) {
        return 0;
    }

    unsigned long now = debug_timeGetTime(com_hand_source_path, 0x895);

    if (SendImmediately != 0) {
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
    char* pdata = new char[packet_size];

    memcpy(pdata, &this->PlayerOptions, sizeof(COMMPLAYEROPTIONS));
    memcpy(pdata + sizeof(COMMPLAYEROPTIONS), this->OptionsData,
           this->PlayerOptions.DataSizeToFollow);

    long hr = direct_play_interface->SetPlayerData(local_player_dpid, pdata,
                                           packet_size, 2);
    this->Err->ShowReturn(hr, "Send Shared Data");
    delete[] pdata;

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
    unsigned int i = 1;
    if (i <= this->MaxGamePlayers) {
        unsigned long* dco = this->PlayerOptions.dcoID + 1;
        for (; i <= this->MaxGamePlayers; ++i, ++dco) {
            L->Log("Check dcoID %d to Me %d ?", *dco, local_player_dpid);

            if (*dco == local_player_dpid) {
                L->Log("Match! - ID set.");
                this->Me = i;
                this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B8), i);
                return;
            }
        }
    }

    L->Log("SET SELF failed.  We are DCOID=%d", local_player_dpid);
}






void TCommunications_Handler::DropDeadPlayer(unsigned int PlayerNo, unsigned long PlayerDPID)
{
    char msg_str[50];
    this->WasKicked[PlayerNo] = 1;
    L->Log("Drop dead called P#%d and DPID=%d", PlayerNo, PlayerDPID);
    this->PlayerOptions.InvalidPlayer[PlayerNo] = 0;
    if (PlayerNo == 0) {
        L->Log("Player number invalid.  Returning.");
        this->UpdatePlayers();
        return;
    }
    if (PlayerNo == this->Me) {
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
    if (!this->IsPlayerHuman(PlayerNo)) {
        this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B5), PlayerNo);
        L->Log("Player was defeated, was computer, or is invalid.");
        this->InitPlayerInformation(PlayerNo, 0, "Defeated", "No Other Information");
        this->UpdatePlayers();
        this->CalculatePlayerRange();
        return;
    }
    if (static_cast<int>(this->PlayerOptions.ProgramState) >= 5 && this->current_turn >= 6) {
        L->Log("Player quit the game.");
        rge_base_game->get_string(0x4BD, msg_str, 0x32);
        sprintf(this->TBuff, msg_str, PlayerNo, this->FriendlyName[PlayerNo].Text);
        L->Log(this->TBuff);
        this->InitPlayerInformation(PlayerNo, 0, "Dropped", " ");
        this->SetPlayerHumanity(PlayerNo, static_cast<PLAYERHUMANITY>(0));
        this->UpdatePlayers();
        this->CalculatePlayerRange();
        if (this->PlayerStopTurn[PlayerNo] != 0) return;
    } else {
        L->Log("Player dropped before game start");
        this->InitPlayerInformation(PlayerNo, 0, "Dropped", "No Other Information");
        this->SetPlayerHumanity(PlayerNo, static_cast<PLAYERHUMANITY>(0));
        this->UpdatePlayers();
        this->CalculatePlayerRange();
    }
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17B3), PlayerNo);
}














void TCommunications_Handler::EvaluateSystemMessage(unsigned long type, char* CommBuff,
                                                    unsigned long dcoFromID, unsigned long dcoReceiveID)
{
    DPMSG_GENERIC* message = (DPMSG_GENERIC*)CommBuff;
    DPMSG_DESTROYPLAYERORGROUP* destroy_player =
        (DPMSG_DESTROYPLAYERORGROUP*)message;
    if (this->Multiplayer == 0) {
        L->Log("!MP in DPANALYSIS");
        return;
    }

    L->Log("DP Sys Msg %d", message->dwType);

    switch (message->dwType) {
    case DPSYS_DESTROYPLAYERORGROUP: {
        unsigned long victim = destroy_player->dpId;
        unsigned int i;
        if (victim != 0) {
            int p = this->PlayerOptions.LowPlayerNumber;
            int high = this->PlayerOptions.HighPlayerNumber;
            if (p <= high) {
                for (; p <= high; p++) {
                    if (this->PlayerOptions.dcoID[p] == victim) {
                        i = p;
                        goto found_destroy_player;
                    }
                }
            }
        }
        i = 0;
found_destroy_player:
        L->Log("DPMSG_DESTRPYPLAYERORGROUP  (to debug dropping players)");
        L->Log("FROM Player ID =		%d ", destroy_player->dpId);
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
        kp.dcoID = destroy_player->dpId;
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
        DPMSG_CREATEPLAYERORGROUP* create_player =
            (DPMSG_CREATEPLAYERORGROUP*)message;
        unsigned long newid;
        unsigned int i;

        dcoFromID = create_player->dpId;
        newid = dcoFromID;
        L->Log("RX NEW PLR ID=%d", newid);
        L->Log("COMM: Create Player Request.");
        sprintf(this->TBuff, "Create Player Request.  (MeHost=%d), Programstate=%d DPID=%d ", this->MeHost, this->PlayerOptions.ProgramState, newid);
        L->Log(this->TBuff);
        if (this->PlayerOptions.ProgramState == 5 || this->current_turn > 6) {
            *this->TBuff = 'I';
            L->Log("  >TX GIP %u (1)", create_player->dpId);
            this->FastSend(create_player->dpId, this->TBuff, 1, 0, 0);
            return;
        }
        if (this->MeHost == 0)
            return;
        i = 1;
        for (; i <= this->MaxGamePlayers; i++) {
            if (this->PlayerOptions.Humanity[i] == 0)
                goto found_create_player;
        }
        i = 0;
found_create_player:
        if (i != 0 && this->PlayerOptions.ProgramState == 3) {
            this->InitPlayerInformation(i, static_cast<int>(create_player->dpId),
                                         create_player->dpnName.lpszShortNameA,
                                         create_player->dpnName.lpszLongNameA);
            this->PlayerOptions.dcoID[i] = dcoFromID;
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
        L->Log("  >TX GIP2 %u (1)", create_player->dpId);
        this->FastSend(create_player->dpId, this->TBuff, 1, 0, 0);
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
        DPMSG_SETPLAYERORGROUPDATA* set_player_data =
            (DPMSG_SETPLAYERORGROUPDATA*)message;
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
        if (set_player_data->dwDataSize >= sizeof(this->PlayerOptions)) {
            memcpy(&this->PlayerOptions, set_player_data->lpData,
                   sizeof(this->PlayerOptions));
            if (set_player_data->dwDataSize >= this->PlayerOptions.DataSizeToFollow
                    + sizeof(this->PlayerOptions)) {
                this->SetMyGameOptions(static_cast<char*>(set_player_data->lpData)
                                           + sizeof(this->PlayerOptions),
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
    L->Log("COMM:Unknown system message. %d", message->dwType);
}











void TCommunications_Handler::SendGroupChatMsg(char* Text) {
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

    this->TXChat(this->Me, DestMap, Text);
}

void TCommunications_Handler::SendChatMsgAll(char* Text) {
    unsigned char DestMap[10];

    memset(DestMap, 'Y', 10);
    this->TXChat(this->Me, DestMap, Text);
}














void TCommunications_Handler::SendChatMsg(unsigned int GamerID, unsigned int DestPlayerNo, char* Text) {
    unsigned char DestMap[10];

    L->Log("SendChatMsg FROM=%d  TO=%d Text='%s'", GamerID, DestPlayerNo, Text);
    for (unsigned int i = 0; i < 10; ++i)
        DestMap[i] = 'N';
    DestMap[DestPlayerNo] = 'Y';
    TXChat(GamerID, DestMap, Text);
}
















long TCommunications_Handler::TXChat(unsigned int GamerID, unsigned char* DestMap, char* Text)
{
    MSGFORMAT_CHAT cht;
    if (this->Multiplayer == 0) {
        this->Chat->AddChatMsg(this->FriendlyName[GamerID].Text, Text, 1);
        L->Log("Local chat single player add: %s", Text);
        return 0;
    }

    if (GamerID > static_cast<unsigned int>(this->MaxGamePlayers)) {
        return 0x80004005;
    }

    unsigned int i = 1;
    if (static_cast<unsigned int>(this->MaxGamePlayers) >= i) {
        do {
            if (this->IsPlayerHuman(i) && DestMap[i] == 'Y') {
                cht.DestPlayers[i] = 'Y';
            } else {
                cht.DestPlayers[i] = 'N';
            }
            i++;
        } while (i <= static_cast<unsigned int>(this->MaxGamePlayers));
    }

    if (cht.DestPlayers[this->Me] == 'Y') {
        this->Chat->AddChatMsg(this->FriendlyName[GamerID].Text, Text, 1);
        L->Log("Local chat add: %s", Text);
    }

    unsigned int len = strlen(Text);
    if (len > 0xff) {
        len = 0xff;
    } else {
        len = strlen(Text);
    }

    cht.FromGamerID = static_cast<unsigned char>(GamerID);
    cht.TextSize = len;
    strncpy(cht.ChatMsg, Text, len + 1);
    cht.ChatMsg[255] = 0;
    if (this->PlayerOptions.ProgramState == 3) {
        cht.Pregame = 1;
    } else {
        cht.Pregame = 0;
    }
    L->Log("  >TX CHAT '%s' (%d)", Text, cht.TextSize + 0x16);
    long ret = this->CommOut(0, 0x43, &cht, cht.TextSize + 0x16, 0);
    this->Err->ShowReturn(ret, "TXChat()");
    return ret;
}



void TCommunications_Handler::SendSpeedChange(unsigned int Frames, unsigned int Granularity) {
    if (this->MeHost != 0 && this->Multiplayer != 0) {
        MSGFORMAT_SPEEDCHANGE speed_change;
        speed_change.BufferFrames = static_cast<unsigned short>(Frames);
        speed_change.FrameSizeMsec = static_cast<unsigned short>(Granularity);
        L->Log("  >TX KP SPD (%d)", 4);
        this->CommOut(0, 'S', &speed_change, 4, 0);
    }
}
















void TCommunications_Handler::SendIResignMsg()
{
    if (this->Multiplayer == 0) return;

    MSGFORMAT_ONTURN resign;
    MSGFORMAT_ALL_DONE alldone;

    resign.ExecuteOnTurn = this->current_turn +
                           this->PlayerOptions.CommandTurnIncrement;
    L->Log("  >TX RSGN (%d)", 4);
    this->CommOut(0, 0x51, &resign, sizeof(resign), 0);

    alldone.HighLatencyCenti = this->Speed->GetHighLatencyCenti();
    alldone.FrameRateMsec = this->Speed->GetAvgFrameRate();
    alldone.Command = 'D';

    alldone.ExecuteOnTurn = this->current_turn +
                         this->PlayerOptions.CommandTurnIncrement + 1;
    L->Log("  >TX DONE (%d)", 0x0C);
    this->CommOut(0, 0x44, &alldone, sizeof(alldone), 0);

    alldone.ExecuteOnTurn = this->current_turn +
                         this->PlayerOptions.CommandTurnIncrement + 2;
    L->Log("  >TX DONE (%d)", 0x0C);
    this->CommOut(0, 0x44, &alldone, sizeof(alldone), 0);

    alldone.ExecuteOnTurn = this->current_turn +
                         this->PlayerOptions.CommandTurnIncrement + 3;
    L->Log("  >TX DONE (%d)", 0x0C);
    this->CommOut(0, 0x44, &alldone, sizeof(alldone), 0);
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
    unsigned long worldtime, unsigned int random,
    long csum1, long csum2, long csum3,
    long csum4, long csum5)
{
    MSGFORMAT_CHECKSUM cs;

    cs.WorldTime = worldtime;
    cs.WorldTurn = this->current_turn;
    cs.cs1 = csum1;
    cs.cs2 = csum2;
    cs.cs3 = csum3;
    cs.cs4 = csum4;
    cs.cs5 = csum5;
    cs.Random = random;

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
        for (uint pno = 0; pno <= 501; ++pno) {
            if (this->OnHold[pno].Length != 0) {
                for (uint i = 1; i <= this->MaxGamePlayers; ++i) {
                    if (this->IsPlayerHuman(i) && i != this->Me) {
                        uint humanSerial = this->PlayerHighSerialNumber[i] + 1;
                        uint serial = this->OnHold[pno].Serial;
                        if (serial < humanSerial &&
                            this->OnHold[pno].dcoFromID == this->PlayerOptions.dcoID[i]) {
                            L->Log(s_clear_past, pno, serial,
                                   this->OnHold[pno].Length,
                                   this->OnHold[pno].dcoFromID,
                                   this->OnHold[pno].dcoReceiveID, humanSerial);
                            HOLDER* clear_entry = &this->OnHold[pno];
                            if (clear_entry->HoldMsg != 0) {
                                delete[] clear_entry->HoldMsg;
                            }
                            clear_entry->HoldMsg = 0;
                            clear_entry->Serial = 0;
                            clear_entry->Length = 0;
                            clear_entry->dcoFromID = 0;
                            clear_entry->dcoReceiveID = 0;
                        }
                        if (this->OnHold[pno].Serial == humanSerial &&
                            this->OnHold[pno].dcoFromID == this->PlayerOptions.dcoID[i]) {
                            sprintf(this->TBuff, s_cached, humanSerial, pno);
                            L->Log(this->TBuff);
                            this->PreprocessMessages(this->OnHold[pno].Length,
                                                     this->OnHold[pno].HoldMsg,
                                                     this->OnHold[pno].dcoFromID,
                                                     this->OnHold[pno].dcoReceiveID,
                                                     1);
                            L->Log(s_clearing, pno, this->OnHold[pno].Length,
                                   this->OnHold[pno].dcoFromID,
                                   this->OnHold[pno].dcoReceiveID);
                            HOLDER* clear_entry2 = &this->OnHold[pno];
                            if (clear_entry2->HoldMsg != 0) {
                                delete[] clear_entry2->HoldMsg;
                            }
                            clear_entry2->HoldMsg = 0;
                            clear_entry2->Serial = 0;
                            clear_entry2->Length = 0;
                            clear_entry2->dcoFromID = 0;
                            clear_entry2->dcoReceiveID = 0;
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
    for (unsigned int i = 0; i < 501; ++i) {
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

    for (unsigned int resend_index = 0; resend_index < 501; ++resend_index) {
        RESENDER* entry = &this->Resend[resend_index];
        entry->TimeSent = 0;
        if (entry->ResendMsg != 0) {
            delete[] entry->ResendMsg;
        }
        entry->ResendMsg = 0;
        entry->Serial = 0;
        entry->Length = 0;
        for (unsigned int j = 0; j < 10; ++j) {
            entry->DestMap[j] = 0;
        }
    }
}

void TCommunications_Handler::ClearRXForPlayer(unsigned int player) {
    for (unsigned int i = 0; i <= 501; ++i) {
        if (this->OnHold[i].dcoFromID == this->PlayerOptions.dcoID[player]) {
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
void TCommunications_Handler::ClearTXForPlayer(unsigned int PlayerNo) {
    for (unsigned int i = 0; i < 502; ++i) {
        this->Resend[i].DestMap[PlayerNo] = 0;
    }
}

void TCommunications_Handler::ClearRXTXForPlayer(unsigned int PlayerNo) {
    ClearTXForPlayer(PlayerNo);
    ClearRXForPlayer(PlayerNo);
}










































typedef unsigned int uint;
typedef unsigned long ulong;

int TCommunications_Handler::StoreIncoming(uint SerialNumber,
                                            char* InBuff,
                                            uint Length,
                                            ulong dcoFromID,
                                            ulong dcoReceiveID)
{
    if (Length == 0) {
        L->Log("+++StoreIncoming called for zero-length message");
    }

    uint slot;
    for (slot = 0; slot <= 501; slot++) {
        HOLDER* entry = &this->OnHold[slot];
        if (entry->Serial == SerialNumber &&
            entry->dcoFromID == dcoFromID) {
            L->Log("Future Ser#%d previously stored (Slot#%d)",
                   SerialNumber, slot);
            return 1;
        }
    }

    for (slot = 0; slot < 501; slot++) {
        if (this->OnHold[slot].Length == 0 && Length != 0) {
            this->OnHold[slot].Length = Length;
            HOLDER* entry = &this->OnHold[slot];
            entry->HoldMsg = new char[entry->Length];
            if (entry->HoldMsg != 0) {
                memcpy(entry->HoldMsg, InBuff, entry->Length);
                entry->Length = Length;
            }
            this->OnHold[slot].Serial = SerialNumber;
            this->OnHold[slot].dcoFromID = dcoFromID;
            this->OnHold[slot].dcoReceiveID = dcoReceiveID;
            return 1;
        }
    }

    L->Log("+++ DID NOT STORE:  ");
    if (slot > 491) {
        L->Log("HOLD FULL WARNING.  COUNT=%d", slot);
        for (uint i = 0; i < 501; i++) {
            HOLDER* entry = &this->OnHold[i];
            if (entry->Length != 0) {
                int command = static_cast<signed char>(entry->HoldMsg[0]);
                int byte1 = static_cast<signed char>(entry->HoldMsg[1]);
                L->Log("S#%d  Ser#%d FromID=%d Len=%d  CMD='%c' B0=%d B1=%d",
                       i, entry->Serial, entry->dcoFromID, entry->Length,
                       command, command, byte1);
            }
        }
    }
    return 1;
}

























int TCommunications_Handler::StoreForResend(unsigned int SerialNumber,
                                             char* OutCommBuff,
                                             unsigned int Length,
                                             unsigned int* ResendDestMap)
{
    if (this->Multiplayer == 0) {
        return 0;
    }
    if (this->RGE_Guaranteed_Delivery == 0) {
        L->Log("+++!RGEGTD Store");
        return 0;
    }

    unsigned int i;
    for (i = 0; i < 501; i++) {
        RESENDER* resend = &this->Resend[i];
        if (resend->Serial != 0) {
            int command = static_cast<signed char>(resend->ResendMsg[0]);
            L->Log("QUEUE Has Ser #%d (Slot=%d) Cmd=%d '%c' Len=%d not ackd yet by %d,%d,%d,%d,%d,%d,%d,%d ",
                   resend->Serial, i, command, command, resend->Length,
                   resend->DestMap[1], resend->DestMap[2],
                   resend->DestMap[3], resend->DestMap[4],
                   resend->DestMap[5], resend->DestMap[6],
                   resend->DestMap[7], resend->DestMap[8]);
            continue;
        }

        resend->Length = Length;
        if (Length != 0) {
            resend->ResendMsg = new char[resend->Length];
            if (resend->ResendMsg != 0) {
                memcpy(resend->ResendMsg, OutCommBuff, resend->Length);
                resend->Length = Length;
            }
        }
        resend->Serial = SerialNumber;
        memcpy(resend->DestMap, ResendDestMap,
               this->MaxGamePlayers * sizeof(unsigned int) +
                   sizeof(unsigned int));

        L->Log("Stored %db for resend (Slot= %d ) SERIAL=%d  (MaxPlayers=%d)",
               Length, i, SerialNumber,
               static_cast<unsigned int>(this->MaxGamePlayers));

        for (unsigned int player = 1; player <= this->MaxGamePlayers;
             player++) {
            if (resend->DestMap[player] != 0) {
                L->Log("      to -> P#%d  retries=%d", player,
                       ResendDestMap[player]);
            }
        }

        resend->TimeSent = debug_timeGetTime(com_hand_source_path, 0xD12);
        return 1;
    }

    L->Log("RESEND buffer filled up, slots (i=%d).", i);
    return 0;
}





typedef unsigned int uint;


int TCommunications_Handler::TXAcknowledgeMessage(uint serialno, uint fromPlayer)
{
    if (this->RGE_Guaranteed_Delivery == 0) {
        L->Log("!RGEGTD Ack");
        return 0;
    }

    MSGFORMAT_ACKNOWLEDGE_GUARANTEED* ack =
        static_cast<MSGFORMAT_ACKNOWLEDGE_GUARANTEED*>(operator new(sizeof(*ack)));
    ack->Command = 0x41;
    ack->Serialno = serialno;

    if (local_player_dpid == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return 0;
    }

    unsigned long start = debug_timeGetTime(com_hand_source_path, 0xD53);

    unsigned int dco = this->PlayerOptions.dcoID[fromPlayer];
    long result = direct_play_interface->Send(local_player_dpid, dco, 0,
                                              ack, sizeof(*ack));

    unsigned long elapsed = debug_timeGetTime(com_hand_source_path, 0xD5E) - start;
    if (elapsed > 0x32) {
        L->Log("!!!TXAcknowledgeMessage slow - %ld msec", elapsed);
    }

    this->TXPacketLength += 8;
    operator delete(ack);

    if (result == 0) {
        return 1;
    }

    this->Err->ShowReturn(result, "GTD ACK");
    return 0;
}








int TCommunications_Handler::RXAcknowledgeStoredMessage(unsigned int serialno, unsigned int fromPlayer) {
    if (!this->RGE_Guaranteed_Delivery) {
        L->Log("!RGEGTD RxAck");
        return 0;
    }

    L->Log("COMM: RX ACK from P#%d for Ser#%d", fromPlayer, serialno);
    this->WaitingForAck = 0;

    for (unsigned int slot = 0; slot <= 501; ++slot) {
        if (this->Resend[slot].Serial == serialno &&
            this->Resend[slot].Serial != 0) {
            this->Resend[slot].DestMap[fromPlayer] = 0;
        }
    }
    return 1;
}





















































int TCommunications_Handler::PurgeAcknowledgedStoredMessages()
{
    unsigned int NonAckCount;
    unsigned int i = 0;
    do {
        NonAckCount = 0;
        if (this->Resend[i].Serial != 0) {
            unsigned int player = 1;
            if (player <= this->MaxGamePlayers) {
                do {
                    if (this->IsPlayerHuman(player) &&
                        this->Resend[i].DestMap[player] > 0) {
                        NonAckCount++;
                    }
                    player++;
                } while (player <= this->MaxGamePlayers);
            }

            if (NonAckCount == 0) {
                L->Log("GTD: Ser #%d Slot=%d  Ackd by all. (Released)",
                       this->Resend[i].Serial, i);
                this->Resend[i].~RESENDER();
            }
        }
        i++;
    } while (i <= 501);

    for (i = 0; i <= 501; i++) {
        if (this->Resend[i].Serial != 0) {
            this->WaitingForAck++;
        }
    }
    return 1;
}


















































int TCommunications_Handler::SendStoredMessages()
{
    if (this->RGE_Guaranteed_Delivery == 0) {
        L->Log("!RGEGTD SendStore");
        return 0;
    }

    static unsigned long lastResendBytes = 0;
    static unsigned long lastResendTime =
        debug_timeGetTime(com_hand_source_path, 0xE00);

    unsigned long Now = debug_timeGetTime(com_hand_source_path, 0xE02);
    if (static_cast<float>(lastResendBytes) /
            static_cast<float>(static_cast<long>(Now - lastResendTime)) >
        2.0f) {
        return 0;
    }

    lastResendTime = Now;
    lastResendBytes = 0;

    unsigned int items = 0;
    unsigned long OldestMessageElapsed = 0;
    unsigned int OldestMessageSlot = 0;
    unsigned int mostRetries = 0;

    this->PurgeAcknowledgedStoredMessages();

    unsigned int slot;
    for (slot = 0; slot <= 501; slot++) {
        RESENDER* resend = &this->Resend[slot];
        if (resend->Serial != 0) {
            items++;
            unsigned long elapsed = Now - resend->TimeSent;
            if (elapsed > OldestMessageElapsed) {
                OldestMessageElapsed = elapsed;
                OldestMessageSlot = slot;
            }

            for (unsigned int player = 1;
                 player <= static_cast<unsigned int>(this->MaxGamePlayers);
                 player++) {
                unsigned int retries = 240 - resend->DestMap[player];
                if (retries > mostRetries) {
                    mostRetries = retries;
                }
            }
        }
    }

    if (items == 0) {
        return 0;
    }

    if (this->current_turn <= 6) {
        if (OldestMessageElapsed < 2000) {
            return 0;
        }
    } else if (this->ShuttingDown != 0) {
        if (OldestMessageElapsed < 250) {
            return 0;
        }
    } else {
        unsigned int resendDelay =
            resend_adj2 + this->Speed->HighestLatencyMsec * 2;
        unsigned int minimumDelay = resend_adj1 + 500;
        if (resendDelay < minimumDelay) {
            resendDelay = minimumDelay;
        }
        if (OldestMessageElapsed < resendDelay) {
            return 0;
        }
    }

    this->Resend[OldestMessageSlot].TimeSent =
        debug_timeGetTime(com_hand_source_path, 0xE55);

    for (unsigned int player = 1;
         player <= static_cast<unsigned int>(this->MaxGamePlayers);
         player++) {
        if (this->Resend[OldestMessageSlot].DestMap[player] > 0 &&
            this->IsPlayerHuman(player) &&
            this->PlayerOptions.dcoID[player] != 0 &&
            player != this->Me) {
            if (this->Resend[OldestMessageSlot].DestMap[player] != 0) {
                this->Resend[OldestMessageSlot].DestMap[player]--;
            }

            L->Log(
                "Resending #%d to P#%d dcoid=%d Length=%d  (elapsed=%d timeGetTime=%d) remaining=%d",
                OldestMessageSlot,
                player,
                this->PlayerOptions.dcoID[player],
                this->Resend[OldestMessageSlot].Length,
                OldestMessageElapsed,
                debug_timeGetTime(com_hand_source_path, 0xE69),
                this->Resend[OldestMessageSlot].DestMap[player]);

            if (local_player_dpid == 0) {
                L->Log("+++BAD DCOID=0 NO TX");
                return 0;
            }

            unsigned long sendStart =
                debug_timeGetTime(com_hand_source_path, 0xE76);
            L->Log("  >TX STOR #%d %d (%d)", player,
                   OldestMessageSlot,
                   this->Resend[OldestMessageSlot].Length);

            long hr = direct_play_interface->Send(
                local_player_dpid,
                this->PlayerOptions.dcoID[player],
                0,
                this->Resend[OldestMessageSlot].ResendMsg,
                this->Resend[OldestMessageSlot].Length);

            unsigned long sendElapsed =
                debug_timeGetTime(com_hand_source_path, 0xE86) - sendStart;
            if (sendElapsed > 50) {
                L->Log("!!!SendStoredMessages slow - %ld msec",
                       sendElapsed);
            }

            if (hr == 0) {
                this->ResentToOther++;
                this->TXPacketLength +=
                    this->Resend[OldestMessageSlot].Length;
                lastResendBytes +=
                    this->Resend[OldestMessageSlot].Length;
                L->Log("COMM: RESENT TX Ser#%d To=P#%d Len=%d",
                       this->Resend[OldestMessageSlot].Serial,
                       player,
                       this->Resend[OldestMessageSlot].Length);
            } else {
                this->Err->ShowReturn(hr, "RESEND Transmit");
            }

            if (this->Resend[OldestMessageSlot].DestMap[player] == 0 &&
                this->IsPlayerHuman(player) &&
                this->PlayerOptions.dcoID[player] != 0 &&
                player != this->Me) {
                sprintf(this->TBuff, "Max resends to Player #%d '%s' ",
                        player, this->GetPlayerName(player));
                L->Log(this->TBuff);

                if (this->MeHost != 0) {
                    L->Log("HOST Rcvd MAX TX for player #%d", player);
                    this->Kicked[player] = 1;
                    this->Kick(player);
                } else {
                    MSGFORMAT_MISSING_PLAYER m;
                    m.PlayerID = this->PlayerOptions.dcoID[player];
                    L->Log("TX Missing Player report for player=%d ",
                           m.PlayerID);
                    m.Command = '?';
                    L->Log("  >TX MP (%d)",
                           sizeof(MSGFORMAT_MISSING_PLAYER));
                    this->FastSend(0, &m,
                                   sizeof(MSGFORMAT_MISSING_PLAYER), 0, 0);
                }
            }
        }
    }

    return this->ResentToOther;
}



















































typedef unsigned int uint;


int TCommunications_Handler::TXResendReply(uint serial, uint toPlayer)
{
    char* error_text;
    uint i;
    uint BadTransmitCount;
    uint GoodTransmitCount;
    long hr;
    char* OutCommBuff;
    MSGFORMAT_RESEND nosuch;
    unsigned long now;

    if (this->RGE_Guaranteed_Delivery == 0) {
        return 0;
    }

    if (this->PlayerOptions.dcoID[toPlayer] == 0) {
        error_text = "Invalid player req.";
        goto no_transmit;
    }

    if (local_player_dpid == 0) {
        return 0;
    }

    now = debug_timeGetTime(com_hand_source_path, 0xEE7);
    if (serial == this->LastSerialRepliedTX[toPlayer]) {
        unsigned long elapsed = now - this->LastRequestRepliedTX[toPlayer];
        if (elapsed < 500) {
            L->Log("Res reply too soon #%u %u", serial, elapsed);
            return 0;
        }
    }

    this->LastSerialRepliedTX[toPlayer] = serial;
    this->LastRequestRepliedTX[toPlayer] = now;

    GoodTransmitCount = 0;
    BadTransmitCount = 0;
    i = 0;
    do {
        if (this->Resend[i].Serial == serial) {
            sprintf(this->TBuff, "Found Resend Ser#%d for P#%d",
                    this->Resend[i].Serial, toPlayer);
            L->Log(this->TBuff);

            OutCommBuff = new char[this->Resend[i].Length];
            this->Resend->DestMap[toPlayer]--;

            if (local_player_dpid == 0) {
                error_text = "+++BAD DCOID=0 NO TX";
                goto no_transmit;
            }

            unsigned long send_start =
                debug_timeGetTime(com_hand_source_path, 0xF19);
            L->Log("  >TX RES REP #%d %d (%d)", toPlayer, serial,
                   this->Resend[i].Length);

            hr = direct_play_interface->Send(
                local_player_dpid,
                this->PlayerOptions.dcoID[toPlayer],
                0,
                this->Resend[i].ResendMsg,
                this->Resend[i].Length);

            unsigned long send_elapsed =
                debug_timeGetTime(com_hand_source_path, 0xF28) - send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!TXResendReply slow - %ld msec", send_elapsed);
            }

            if (hr == 0) {
                ++GoodTransmitCount;
                this->TXPacketLength += this->Resend[i].Length;
            } else {
                this->Err->ShowReturn(hr, "Resend TX");
                ++BadTransmitCount;
            }

            L->Log(
                "COMM: >>>>> RETRANSMIT P#%d Ser#%d (Slot#%d) Cmd %d '%c' MsgLength=%d Retx left=%d timeGetTime=%d",
                toPlayer,
                this->Resend[i].Serial,
                i,
                static_cast<int>(static_cast<signed char>(
                    this->Resend[i].ResendMsg[0])),
                static_cast<int>(static_cast<signed char>(
                    this->Resend[i].ResendMsg[0])),
                this->Resend[i].Length,
                this->Resend->DestMap[toPlayer],
                debug_timeGetTime(com_hand_source_path, 0xF42));

            delete[] OutCommBuff;
        }

        ++i;
    } while (i <= 0x1F5);

    if (GoodTransmitCount == 0 && BadTransmitCount == 0) {
        if (this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
            L->Log("+++ Did not have requested Ser#%d for P#%d ",
                   serial, toPlayer);

            nosuch.Command = 0x59;
            nosuch.Serialno = this->GTDSerialNo - 1;
            L->Log("  >TX RNSM #%d %d (%d)", toPlayer, serial, 8);
            this->FastSend(this->PlayerOptions.dcoID[toPlayer], &nosuch,
                           8, 0, 0);
            L->Log("+++ TX: No such message as #%d..resynchronizing ser#s",
                   serial);
            this->ClearTXForPlayer(toPlayer);
        }
    } else {
        L->Log("RESEND to P#%d FULFILLED:  GoodTX=%d BadTX=%d Total=%d",
               toPlayer, GoodTransmitCount, BadTransmitCount,
               GoodTransmitCount + BadTransmitCount);
    }

    this->PurgeAcknowledgedStoredMessages();
    return 1;

no_transmit:
    L->Log(error_text);
    return 0;
}











int TCommunications_Handler::TXResendRequest(unsigned int serial, unsigned int toPlayer) {
    if (!this->RGE_Guaranteed_Delivery) {
        return 0;
    }
    unsigned long now = debug_timeGetTime(com_hand_source_path, 3980);
    if (serial == this->LastSerialRequestedTX[toPlayer]) {
        unsigned long elapsed = now - this->LastRequestHonoredTX[toPlayer];
        if (elapsed < 500) {
            return 0;
        }
    }
    this->LastSerialRequestedTX[toPlayer] = serial;
    this->LastRequestHonoredTX[toPlayer] = now;
    MSGFORMAT_RESEND* msg = new MSGFORMAT_RESEND;
    msg->Command = 0x58;
    msg->Serialno = serial;
    L->Log("GTD: TX RESEND REQ to P#%d  Ser#%d ", toPlayer, serial);
    if (local_player_dpid == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return 0;
    }
    unsigned long sendStart = debug_timeGetTime(com_hand_source_path, 4009);
    L->Log("  >TX RES REQ #%d %d (%d)", toPlayer, serial, 8);
    int to = this->PlayerOptions.dcoID[toPlayer];
    IDirectPlay3* dp = direct_play_interface;
    int ok = dp->Send(local_player_dpid, to, 0, msg, sizeof(*msg));
    unsigned long elapsed2 = debug_timeGetTime(com_hand_source_path, 4024) - sendStart;
    if (elapsed2 > 50) {
        L->Log("  TX RES REQ took %d", elapsed2);
    }
    delete msg;
    if (ok == 0) {
        this->TXPacketLength += 8;
        return 1;
    }
    return 0;
}















unsigned char TCommunications_Handler::GetNextSequence(unsigned long value) {
    static unsigned char Sequence = 1;
    static unsigned long LastCurrentTurn = 0;

    if (value != LastCurrentTurn) {
        Sequence = 1;
        LastCurrentTurn = value;
        return 1;
    }

    ++Sequence;
    if (Sequence >= 0xFF) {
        L->Log("+++Too many commands in one comm turn.  Seq#=%d",
                Sequence);
        return 0;
    }

    if (this->PlayerOptions.ProgramState == 4 && Sequence > 100) {
        Sequence = 100;
        return 100;
    }

    return Sequence;
}














































typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long HRESULT;


long TCommunications_Handler::CommOut(ulong To, uchar MsgType, void* Msg,
                                      int Length, uchar ResendSeq)
{
    uint FullLength;
    uint HeaderLength;
    MSGFORMAT_HEADER_GUARANTEED* txMsg;
    char* OutCommBuff;
    uint OutgoingCount;
    ulong SyncTurn;
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

    txMsg = new MSGFORMAT_HEADER_GUARANTEED;

    if (MsgType == '1' || MsgType == '2' || MsgType == '?' || MsgType == 'A') {
        L->Log("+++BAD Msg type -- ASSERT");
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        txMsg->Serialno = this->GTDSerialNo;
        this->PlayerHighSerialNumber[this->Me] = this->GTDSerialNo;
        ++this->GTDSerialNo;
        HeaderLength = 0x0C;
    } else {
        HeaderLength = 8;
        txMsg->Serialno = 0;
    }

    FullLength = HeaderLength + Length;
    if (FullLength > 0xFA0) {
        L->Log("ERROR: Full length > %d, Header=%d  Length=%d",
               0xFA0, HeaderLength, Length);
    }

    txMsg->Sequence = 0;
    txMsg->Command = 0;
    txMsg->ExecuteOnTurn = this->current_turn +
                         static_cast<uint>(this->PlayerOptions.CommandTurnIncrement);
    SyncTurn = txMsg->ExecuteOnTurn;

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

    if (MsgType == '1' || MsgType == '2' || MsgType == '?' || MsgType == 'A') {
        L->Log("ASSERT - BAD MSG TYPE");
    } else {
        txMsg->Sequence = this->GetNextSequence(SyncTurn);
        if (this->PlayerOptions.ProgramState != 5 &&
            txMsg->Sequence == 0) {
            delete txMsg;
            return static_cast<long>(0x8877010E);
        }
    }

    txMsg->Command = MsgType;
    OutCommBuff = new char[FullLength + 1];
    memcpy(OutCommBuff, txMsg, HeaderLength);
    if (Length != 0) {
        memcpy(OutCommBuff + HeaderLength, Msg, Length);
    }

    OutgoingCount = 0;
    i = 0;
    dest_map = this->DestMap;
    do {
        if (this->IsPlayerHuman(i) == 0 || i == this->Me) {
            dest_map[i] = 0;
        } else {
            dest_map[i] = 0xF0;
            ++OutgoingCount;
        }
        ++i;
    } while (i <= this->MaxGamePlayers);

    if (this->RGE_Guaranteed_Delivery != 0) {
        if (FullLength == 0) {
            L->Log("+++Damaged Msg 0b");
            return static_cast<long>(0x80004005);
        }
        if (OutgoingCount != 0) {
            if (local_player_dpid == 0) {
                L->Log("+++BAD DCOID=0 NO TX");
                --this->GTDSerialNo;
                return static_cast<long>(0x80004005);
            }

            send_start = debug_timeGetTime(com_hand_source_path, 0x10AA);
            play = direct_play_interface;
            hr = play->Send(local_player_dpid, To, 0, OutCommBuff, FullLength);
            send_elapsed = debug_timeGetTime(com_hand_source_path, 0x10B5) -
                           send_start;
            if (send_elapsed > 0x32) {
                L->Log("!!!CommOut slow - %ld msec", send_elapsed);
            }

            if (To == 0) {
                recipient_count = 0;
                if (this->MaxGamePlayers >= 1) {
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
                this->TXPacketLength += recipient_count * FullLength;
            }
            if (hr == 0) {
                this->StoreForResend(
                    txMsg->Serialno, OutCommBuff,
                    FullLength,
                                     this->DestMap);
            } else {
                --this->GTDSerialNo;
                this->Err->ShowReturn(hr, "TX RGTGTD");
            }
            goto sent;
        }
        hr = 0;
    } else if (OutgoingCount != 0) {
        if (local_player_dpid == 0) {
            L->Log("+++BAD DCOID=0 NO TX");
            return static_cast<long>(0x80004005);
        }

        send_start = debug_timeGetTime(com_hand_source_path, 0x10EE);
        play = direct_play_interface;
        hr = play->Send(local_player_dpid, To, 0, OutCommBuff, FullLength);
        send_elapsed = debug_timeGetTime(com_hand_source_path, 0x10F9) -
                       send_start;
        if (send_elapsed > 0x32) {
            L->Log("!!!CommOut2 slow - %ld msec", send_elapsed);
        }

        if (To == 0) {
            recipient_count = 0;
            if (this->MaxGamePlayers >= 1) {
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
            this->TXPacketLength += recipient_count * FullLength;
        }
    } else {
        hr = 0;
    }

sent:
    if (OutgoingCount != 0) {
        if (this->RGE_Guaranteed_Delivery != 0) {
            strcpy(GTDString, "GTD");
        } else {
            strcpy(GTDString, "!GTD");
        }
        L->Log("COMM: Ser#%d %s TX To=%d Len=%d+%d HDR> Seq=%d",
               txMsg->Serialno,
               GTDString, To, Length, HeaderLength,
               txMsg->Sequence, txMsg->ExecuteOnTurn,
               txMsg->Command,
               txMsg->Command,
               static_cast<int>(static_cast<char>(OutCommBuff[HeaderLength])),
               static_cast<int>(static_cast<char>(OutCommBuff[HeaderLength])), OutgoingCount, hr,
               debug_timeGetTime(com_hand_source_path, 0x112B));
    }

    if (hr != 0) {
        this->Err->ShowReturn(hr, "TX");
    } else {
        ++this->TXPackets;
        if (MsgType == '>') {
            this->AddCommand(SyncTurn, Msg, static_cast<unsigned long>(Length),
                             this->Me,
                             txMsg->Sequence,
                             0);
        }
    }

    delete txMsg;
    delete[] OutCommBuff;
    return hr;
}





void TCommunications_Handler::DestroyMultiplayerGame()
{
    this->DestroyMyPlayer();
    long t = debug_timeGetTime(com_hand_source_path, 0x267);
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
    strcpy(this->MyGameTitle, " ");
    strcpy(this->MyFriendlyName, " ");
    strcpy(this->MyFormalName, " ");
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
    L->Log("Initialize Player List");
    int i = 1;
    if (this->MaxGamePlayers >= i) {
        do {
            this->InitPlayerInformation(i, zero, " ", " ");
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





























































































































COMMSTATUS TCommunications_Handler::UnlinkToLevel(COMMSTATUS lvl) {
    COMMSTATUS original_status;
    COMMSTATUS new_status;


    original_status = AnalyzeCommunicationsStatus();


    CommunicationsStatus = original_status;
    L->Log("Unlink to level %d desired, currently at level %d",
        lvl, original_status);


    if (lvl < 1) {
        lvl = INITIALIZED;
    }


    original_status = CommunicationsStatus;
    new_status = original_status;


    while (new_status > lvl) {
        new_status = UnlinkCurrentLevel();
        CommunicationsStatus = new_status;
        if (new_status == original_status)
            goto unlink_failed;
    }

    L->Log("AFTER UNLINKING...Status=%d   Reported=%d",
        this->GetCommunicationsStatus(), this->CommunicationsStatus);
    return AnalyzeCommunicationsStatus();

unlink_failed:
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
    if (memcmp(&this->SessionGUID, &this->NullGUID, 16) != 0) {
        return static_cast<COMMSTATUS>(6);
    }
    if (memcmp(&this->ServiceGUID, &this->NullGUID, 16) != 0) {
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
    for (int i = 1; i <= this->MaxGamePlayers; ++i) {
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

void TCommunications_Handler::LocalResumeGame(unsigned int p) {
    this->PlayerOptions.ProgramState = COMM_STATE_RUNNING;
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17A3), p);
}

void TCommunications_Handler::LocalPauseGame(unsigned int p) {
    this->PlayerOptions.ProgramState = COMM_STATE_PAUSE;
    this->NotifyWindowParam(static_cast<COMMMESSAGES>(0x17A2), p);
}




void TCommunications_Handler::SendPauseGame(int Pause) {
    if (this->Multiplayer == 0) {
        return;
    }
    if (this->MeHost == 0) {
        return;
    }

    if (Pause != 0) {
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




void TCommunications_Handler::RequestPauseGame(int SendChatInfo) {
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









void TCommunications_Handler::RequestResumeGame(int SendChatInfo) {
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





void TCommunications_Handler::SetRandomSeed(int val) {
    if (this->MeHost == 0) {
        return;
    }

    if (val == -1) {
        unsigned long time = debug_timeGetTime(com_hand_source_path, 0x1320);
        debug_srand(com_hand_source_path, 0x1320, time);
        val = debug_rand(com_hand_source_path, 0x1321);
    }

    this->PlayerOptions.RandomSeed = static_cast<unsigned long>(val);
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
        char defc;
        defc = '?';
        do {
            if (this->LastTurnAck[i] >= this->current_turn) {
                ready_player_buffer[i + 6] = 'A';
            } else {
                switch (this->PlayerOptions.Humanity[i]) {
                case 2: ready_player_buffer[i + 6] = 'W'; break;
                case 4: ready_player_buffer[i + 6] = 'C'; break;
                case 0: ready_player_buffer[i + 6] = '-'; break;
                case 6: ready_player_buffer[i + 6] = 'V'; break;
                case 5: ready_player_buffer[i + 6] = 'X'; break;
                default: ready_player_buffer[i + 6] = defc; break;
                }
            }
            ++i;
        } while (i <= this->MaxGamePlayers);
    }
    return ready_player_buffer;
}

int TCommunications_Handler::GetPlayerHumanity(unsigned int PlayerNo) {
    if (PlayerNo >= 1u && PlayerNo <= this->MaxGamePlayers)
        return this->PlayerOptions.Humanity[PlayerNo];
    return 0;
}



void TCommunications_Handler::SetPlayerHumanity(unsigned int PlayerNo, PLAYERHUMANITY Type) {
    if (PlayerNo < 1) {
        return;
    }
    if (PlayerNo > this->MaxGamePlayers) {
        return;
    }

    this->PlayerOptions.Humanity[PlayerNo] = Type;
    this->UpdatePlayer(PlayerNo, 1);
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

int TCommunications_Handler::IsPlayerHuman(unsigned int PlayerNo) {
    int humanity;

    if (PlayerNo >= 1 && PlayerNo <= this->MaxGamePlayers) {
        humanity = this->PlayerOptions.Humanity[PlayerNo];
        if (humanity == 2 || humanity == 5) {
            return 1;
        }
    }
    return 0;
}

int TCommunications_Handler::IsPlayerComputer(unsigned int PlayerNo) {
    int humanity;

    if (PlayerNo >= 1u && PlayerNo <= this->MaxGamePlayers) {
        humanity = this->PlayerOptions.Humanity[PlayerNo];
        return humanity == 4;
    }
    return 0;
}








typedef unsigned long ulong;


char* TCommunications_Handler::GetCommInfo(unsigned char LineNum) {
    char* p = comm_info_buffers;
    char tmp[0x100];
    --LineNum;

    if (this->Multiplayer == 0) {
        do {
            strcpy(p, ">");
            p += 0x100;
        } while (p < comm_info_buffers + 0x700);
        sprintf(comm_info_buffers, "SinglePlayer> T#%d ", this->current_turn);
        return comm_info_buffers + (static_cast<unsigned int>(LineNum) << 8);
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

    ulong dwCount = 0;
    direct_play_interface->GetMessageCount(local_player_dpid, &dwCount);
    sprintf(comm_info_buffers + 0x300, "%s  DPMsgs%d ", this->Speed->GetSelfPlayerOptimalSpeedStr(), dwCount);
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

    return comm_info_buffers + (static_cast<unsigned int>(LineNum) << 8);
}

char* TCommunications_Handler::GetPlayerName(unsigned int PlayerNo) {
    if (PlayerNo > this->MaxGamePlayers) {
        return 0;
    }
    if (static_cast<int>(PlayerNo) == this->Me) {
        return this->MyFriendlyName;
    }
    return this->FriendlyName[PlayerNo].Text;
}

void TCommunications_Handler::UpdatePlayerInformation(unsigned long dpID, char* AFriendlyName, char* AFormalName) {
    int player;
    int high;

    player = 0;
    if (dpID != 0) {
        player = this->PlayerOptions.LowPlayerNumber;
        high = this->PlayerOptions.HighPlayerNumber;
        if (static_cast<int>(player) <= static_cast<int>(high)) {
            for (; static_cast<int>(player) <= static_cast<int>(high); player++) {
                if (this->PlayerOptions.dcoID[player] == dpID) {
                    goto found;
                }
            }
        }
    }
    player = 0;
found:
    if (player == 0) {
        this->InitPlayerInformation(0, dpID, AFriendlyName, AFormalName);
    }
}

int TCommunications_Handler::IsLobbyLaunched() {
    return this->Lobby->IsLobbyLaunched();
}
















int TCommunications_Handler::LaunchLobbyGame()
{
    IDirectPlay3* NewDPConv = 0;
    DPSESSIONDESC2 test;
    char* name;
    int r;

    r = Lobby->CheckForLobbyLaunch(NewDPConv);
    if (r == 0) {
        goto done;
    }
    if (direct_play_interface) {
        int release_count = direct_play_interface->Release();
        L->Log("Release count = %d", release_count);
    }
    direct_play_interface = NewDPConv;
    if (NewDPConv == 0) return 0;
    r = Lobby->GetSessionInfo(test);
    if (r) DebugSessionInformation(&test);
    CommGetCaps();
    Multiplayer = 1;
    DPlayGetSessionDesc();
    Lobby->GetPlayerInfo(&name);
    SetMyPlayerName(name);
    PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
    AddSelfPlayer();
    MeHost = Lobby->IsThisHost();
    if (MeHost) {
        COMMPLAYEROPTIONS& options = PlayerOptions;
        Me = 1;
        options.dcoID[1] = local_player_dpid;
        options.Humanity[this->Me] = ME_HUMAN;
        HaveHostInit = 1;
        PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        SetRandomSeed(rge_base_game->random_game_seed);
        GTDSerialNo = 0x7D1;
    }
    UpdatePlayers();
done:
    LobbyLaunched = r;
    return r;
}






void TCommunications_Handler::InitPlayerInformation(unsigned int PlayerNo, unsigned long dpID, char* FrName, char* FoName)
{
    if (PlayerNo < 1)
        return;
    if (PlayerNo > MaxGamePlayers)
        return;

    PlayerOptions.PlayerReady[PlayerNo] = 0;
    PlayerOptions.User1[PlayerNo] = 0;
    PlayerOptions.User2[PlayerNo] = 0;
    PlayerOptions.User3[PlayerNo] = 0;
    PlayerOptions.User4[PlayerNo] = 0;
    PlayerOptions.User5[PlayerNo] = 0;
    PlayerOptions.User6[PlayerNo] = 0;
    PlayerOptions.User7[PlayerNo] = 0;
    PlayerOptions.InvalidPlayer[PlayerNo] = 0;
    LastTurnAck[PlayerNo] = 0;
    PlayerOptions.Humanity[PlayerNo] = ME_ABSENT;
    PlayerOptions.dcoID[PlayerNo] = dpID;
    PlayerHighSerialNumber[PlayerNo] = 0;

    dwFlags = 0;
    dwMaxBufferSize = 0;
    dwMaxQueueSize = 0;
    dwMaxPlayers = 0;
    dwHundredBaud = 0;
    dwLatency = 0;

    if (InQ)
    {
        InQ->FlushForPlayer(PlayerNo);
    }

    L->Log("Player %d (%ld) is INITIALIZED as '%s' [%s]", PlayerNo, dpID, FrName, FoName);
}

int TCommunications_Handler::SetGameTitle(char* Game) {
    sprintf(this->MyGameTitle, "%s [%s]", Game, this->MyFriendlyName);
    return 1;
}

void TCommunications_Handler::SetMyPlayerName(char* Name) {
    strcpy(this->MyFriendlyName, Name);
    strcpy(this->MyFormalName, "Optional Information");
}


void TCommunications_Handler::SetPlayerName(unsigned int PlayerNo, char* Name) {
    if (PlayerNo == this->Me) {
        this->SetMyPlayerName(Name);
        return;
    }
    char* dest = this->FriendlyName[PlayerNo].Text;
    strcpy(dest, Name);
}

void* TCommunications_Handler::SetWindowHandle(void* hwnd) {
    this->HostHWND = hwnd;
    return hwnd;
}





long TCommunications_Handler::CreateDirectPlayConversation()
{
    IDirectPlay* lpIDC;
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

        hr = lpIDC->QueryInterface(IID_IDirectPlay3A,
                                    reinterpret_cast<void**>(&direct_play_interface));

        if (hr) {
            L->Log("Get glpIDC returns...%ld", hr);
            return hr;
        }

        unsigned long links = lpIDC->Release();
        L->Log("Release: Links=%d", links);
    }

    return 0;
}

int TCommunications_Handler::OpenMultiplayerConnection() { return -1; }
















typedef unsigned long ulong;

int TCommunications_Handler::CreateMultiplayerGame(void)
{
    int one = 1;
    TChat* chat = this->Chat;

    this->Multiplayer = one;
    this->HaveHostInit = 0;
    this->PlayerOptions.CommandTurnIncrement = 2;
    this->current_turn = 4;
    this->PlayerOptions.CurrentTurn = 4;
    chat->ClearChat();

    long result = this->CreateDirectPlayConversation();
    this->Err->ShowReturn(result, "CreateDirectPlayConversation");

    DPSESSIONDESC2 dSess2;
    memset(&dSess2, 0, sizeof(dSess2));
    this->MeHost = one;
    dSess2.dwMaxPlayers = this->MaxGamePlayers;
    dSess2.dwSize = 0x50;
    dSess2.dwCurrentPlayers = one;
    dSess2.guidApplication = this->ApplicationGUID;
    dSess2.dwFlags = 0x44;
    dSess2.lpszSessionNameA = this->MyGameTitle;

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
    int i;
    int save;

    i = 1;
    if (this->MaxGamePlayers >= 1) {
        do {
        if (this->IsPlayerHuman(i) || this->IsPlayerComputer(i)) {
            L->Log("Position %d *LOCKED*.   Plr=%s", i, this->GetPlayerName(i));
        } else {
            int src = i;
            while (src <= static_cast<int>(this->MaxGamePlayers)) {
                if (this->IsPlayerHuman(src) ||
                    this->IsPlayerComputer(src)) {
                    strcpy(this->FriendlyName[i].Text,
                           this->FriendlyName[src].Text);
                    strcpy(this->FormalName[i].Text,
                           this->FormalName[src].Text);

                    this->PlayerOptions.PlayerReady[i] =
                        this->PlayerOptions.PlayerReady[src];
                    this->PlayerOptions.dcoID[i] =
                        this->PlayerOptions.dcoID[src];
                    this->PlayerOptions.User1[i] =
                        this->PlayerOptions.User1[src];
                    this->PlayerOptions.User2[i] =
                        this->PlayerOptions.User2[src];
                    this->PlayerOptions.User3[i] =
                        this->PlayerOptions.User3[src];
                    this->PlayerOptions.User4[i] =
                        this->PlayerOptions.User4[src];
                    this->PlayerOptions.User5[i] =
                        this->PlayerOptions.User5[src];
                    this->PlayerOptions.User6[i] =
                        this->PlayerOptions.User6[src];
                    this->PlayerOptions.User7[i] =
                        this->PlayerOptions.User7[src];
                    this->PlayerOptions.Humanity[i] =
                        this->PlayerOptions.Humanity[src];
                    this->LastTurnAck[i] = this->LastTurnAck[src];
                    this->LastPlayerCommunication[i] =
                        this->LastPlayerCommunication[src];

                    save = i;
                    L->Log("Moved %d->%d", src, save);
                    L->Log("Position %d *LOCKED*.   Plr=%s", save, this->GetPlayerName(save));
                    this->InitPlayerInformation(src, 0, "", "");
                    break;
                }
                ++src;
            }
        }
            ++i;
        } while (i <= static_cast<int>(this->MaxGamePlayers));
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


int TCommunications_Handler::JoinMultiplayerGame(_GUID* GameGuid)
{
    if (direct_play_interface == 0) {
        L->Log("JMPG: Create w/no valid glpIDC");
        return 0;
    }

    DPSESSIONDESC2 dSess2;
    memset(&dSess2, 0, sizeof(dSess2));

    memcpy(&this->SessionGUID, GameGuid, sizeof(this->SessionGUID));
    this->MeHost = 0;

    dSess2.dwSize = 0x50;
    dSess2.guidInstance = *GameGuid;

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
    memset(&dpCaps, 0, sizeof(dpCaps));

    dpCaps.dwSize = 0x28;

    if (local_player_dpid == 0)
        return 0x80004005;

    long result = dp->GetPlayerCaps(local_player_dpid, &dpCaps, 1);

    this->Err->ShowReturn(result, "Get Player Caps");

    if (result != 0)
        return result;

    this->dwFlags = dpCaps.dwFlags;
    if (dpCaps.dwFlags & 0x40) {
        this->RGE_Guaranteed_Delivery = 1;
    } else {
        this->RGE_Guaranteed_Delivery = 1;
    }
    this->dwMaxBufferSize = dpCaps.dwMaxBufferSize;
    this->dwMaxQueueSize = dpCaps.dwMaxQueueSize;
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

void TCommunications_Handler::SetServiceGUID(_GUID inGuid) {
    this->ServiceGUID = inGuid;
}

void TCommunications_Handler::SetSessionGUID(_GUID inGuid) {
    this->SessionGUID = inGuid;
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















































void TCommunications_Handler::UpdatePlayer(unsigned int PlayerNo, int Notify)
{
    unsigned long dcoID = this->PlayerOptions.dcoID[PlayerNo];

    switch (this->PlayerOptions.Humanity[PlayerNo]) {
    case ME_ABSENT:
        L->Log("P#%d ABSENT", PlayerNo);
        this->PlayerOptions.dcoID[PlayerNo] = 0;
        this->PlayerOptions.PlayerReady[PlayerNo] = 0;
        if (Notify)
            this->NotifyWindow(COMM_UPDATE_PLAYERS);
        return;

    case ME_CLOSED:
        L->Log("P#%d CLOSED", PlayerNo);
        this->PlayerOptions.dcoID[PlayerNo] = 0;
        this->PlayerOptions.PlayerReady[PlayerNo] = 1;
        if (Notify)
            this->NotifyWindow(COMM_UPDATE_PLAYERS);
        return;

    case ME_HUMAN:
        L->Log("P#%d HUMAN", PlayerNo);
        break;

    case ME_ELIMINATED:
        L->Log("P#%d ELIMINATED", PlayerNo);
        this->PlayerOptions.dcoID[PlayerNo] = 0;
        this->PlayerOptions.PlayerReady[PlayerNo] = 0;
        if (Notify)
            this->NotifyWindow(COMM_UPDATE_PLAYERS);
        return;

    case ME_COMPUTER:
        L->Log("P#%d COMPUTER", PlayerNo);
        this->PlayerOptions.dcoID[PlayerNo] = 0;
        this->PlayerOptions.PlayerReady[PlayerNo] = 1;
        if (Notify)
            this->NotifyWindow(COMM_UPDATE_PLAYERS);
        return;

    case ME_CYBORG:
        L->Log("P#%d CYBORG", PlayerNo);
        break;

    case ME_VIEWONLY:
        this->PlayerOptions.PlayerReady[PlayerNo] = 1;
        L->Log("P#%d VIEWONLY", PlayerNo);
        break;

    default:
        strcpy(this->FriendlyName[PlayerNo].Text, "Error");
        L->Log("COMM:INVALID P#%d HUMANITY SETTING %d", PlayerNo,
               this->PlayerOptions.Humanity[PlayerNo]);
        return;
    }

    if (dcoID == 0) {
        L->Log("P#%d Not Defined (updateplayers).", PlayerNo);
        return;
    }

    unsigned long dwSize = 0;
    direct_play_interface->GetPlayerName(dcoID, 0, &dwSize);
    void* lpData = calloc(dwSize, 1);
    long result = direct_play_interface->GetPlayerName(dcoID, lpData, &dwSize);
    this->Err->ShowReturn(result, "Get PName Info");

    if (result == 0) {
        DPNAME* name = static_cast<DPNAME*>(lpData);
        strcpy(this->FriendlyName[PlayerNo].Text, name->lpszShortNameA);
        strcpy(this->FormalName[PlayerNo].Text, name->lpszLongNameA);
        this->PlayerOptions.Humanity[PlayerNo] = ME_HUMAN;
    } else if (result == DPERR_BUFFERTOOSMALL ||
               result == DPERR_INVALIDPARAM ||
               result == DPERR_INVALIDOBJECT) {
        L->Log("Fatal error player info %ld", result);
        strcpy(this->FriendlyName[PlayerNo].Text, "Error!");
        this->PlayerOptions.Humanity[PlayerNo] = ME_ABSENT;
    } else if (result == DPERR_INVALIDPLAYER) {
        L->Log("INVALID PLAYER %d.  Removing.", dcoID);
        if (this->PlayerOptions.ProgramState == COMM_STATE_JOINNOW) {
            this->PlayerOptions.Humanity[PlayerNo] = ME_HUMAN;
            if (this->IsPlayerHuman(PlayerNo)) {
                MSGFORMAT_MISSING_PLAYER m;
                L->Log("INVALID PLAYER");
                L->Log("TX Missing Player report for player=%d ", dcoID);
                m.PlayerID = dcoID;
                m.Command = '?';
                L->Log("  >TX MP #%d (%d)", Notify,
                       sizeof(MSGFORMAT_MISSING_PLAYER));
                this->FastSend(0, &m, sizeof(MSGFORMAT_MISSING_PLAYER),
                               0, 0);
            }
        }
    } else {
        L->Log("Unknown fail on updateplayers");
        this->PlayerOptions.Humanity[PlayerNo] = ME_ABSENT;
        this->PlayerOptions.dcoID[PlayerNo] = 0;
    }

    free(lpData);
    if (Notify)
        this->NotifyWindow(COMM_UPDATE_PLAYERS);
}











typedef unsigned long ulong;


int TCommunications_Handler::SetMyReadiness(int Ready, ulong User1, ulong User2, ulong User3, ulong User4, ulong User5, ulong User6, ulong User7)
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

    this->PlayerOptions.PlayerReady[this->Me] = Ready;
    this->PlayerOptions.User1[this->Me] = User1;
    this->PlayerOptions.User2[this->Me] = User2;
    this->PlayerOptions.User3[this->Me] = User3;
    this->PlayerOptions.User4[this->Me] = User4;
    this->PlayerOptions.User5[this->Me] = User5;
    this->PlayerOptions.User6[this->Me] = User6;
    this->PlayerOptions.User7[this->Me] = User7;

    rdy.Ready = static_cast<unsigned char>(Ready);
    rdy.User1 = User1;
    rdy.User4 = User4;
    rdy.User2 = User2;
    rdy.User5 = User5;
    rdy.User3 = User3;
    rdy.User6 = User6;
    rdy.CommunicationsVersionCode = this->CommunicationsVersionCode;
    rdy.User7 = User7;
    rdy.RGEGuaranteed = this->RGE_Guaranteed_Delivery;
    rdy.Command = 0x52;
    int meHost = this->MeHost;

    if (meHost == 0) {
        L->Log("  >TX RDY (%d)", 0x28);
        this->FastSend(0, &rdy, sizeof(rdy), 0, 0);
    }

    this->NotifyWindow(COMM_UPDATE_PARAMS);
    return 1;
}




int TCommunications_Handler::GetClientReadiness(unsigned int PlayerNo, int* Ready, unsigned long* User1, unsigned long* User2, unsigned long* User3, unsigned long* User4, unsigned long* User5, unsigned long* User6, unsigned long* User7) {
    *Ready = this->PlayerOptions.PlayerReady[PlayerNo];
    *User1 = this->PlayerOptions.User1[PlayerNo];
    *User2 = this->PlayerOptions.User2[PlayerNo];
    *User3 = this->PlayerOptions.User3[PlayerNo];
    *User4 = this->PlayerOptions.User4[PlayerNo];
    *User5 = this->PlayerOptions.User5[PlayerNo];
    *User6 = this->PlayerOptions.User6[PlayerNo];
    *User7 = this->PlayerOptions.User7[PlayerNo];
    return 1;
}

int TCommunications_Handler::IsPlayerReady(unsigned int PlayerNo) {
    if (PlayerNo >= 1u && PlayerNo <= this->MaxGamePlayers)
        return this->PlayerOptions.PlayerReady[PlayerNo];
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
    void* buf;

    if (direct_play_interface == 0) {
        return 0x80004005;
    }

    direct_play_interface->GetSessionDesc(0, &dwSize);
    buf = calloc(dwSize, 1);
    if (buf == 0) {
        return 0x8007000E;
    }

    result = direct_play_interface->GetSessionDesc(buf, &dwSize);
    Err->ShowReturn(result, "Get Session Desc");

    if (result == 0) {
        DPSESSIONDESC2* session = static_cast<DPSESSIONDESC2*>(buf);
        SessionGUID = session->guidInstance;
        CurrentPlayers = session->dwCurrentPlayers;
        L->Log("RX Current Players=%d", CurrentPlayers);
    }
    free(buf);
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
    DPCAPS DPCaps;
    HRESULT hr;

    IDirectPlay3* dp = direct_play_interface;
    if (dp == 0) {
        return 0x80004005;
    }

    DPCaps.dwSize = sizeof(DPCAPS);
    hr = dp->GetCaps(&DPCaps, 0);
    this->Err->ShowReturn(hr, s_get_caps);

    dp = direct_play_interface;
    hr = dp->GetCaps(&DPCaps, 1);
    this->Err->ShowReturn(hr, s_get_guaranteed_caps);

    L->Log(s_header);
    L->Log(s_max_buffer, DPCaps.dwMaxBufferSize);
    L->Log(s_max_queue, DPCaps.dwMaxQueueSize);
    L->Log(s_max_players, DPCaps.dwMaxPlayers);
    L->Log(s_baud, DPCaps.dwHundredBaud);
    L->Log(s_latency, DPCaps.dwLatency);
    L->Log(s_header_len, DPCaps.dwHeaderLength);
    L->Log(s_timeout, DPCaps.dwTimeout);

    this->ServiceTimeout = DPCaps.dwTimeout;

    if (DPCaps.dwFlags & 0x20) {
        L->Log(s_guar_opt);
    } else {
        L->Log(s_not_guar_opt);
    }

    if (DPCaps.dwFlags & 2) {
        L->Log(s_session_host_msg);
    } else {
        L->Log(s_not_session_host_msg);
    }

    if (DPCaps.dwFlags & 0x10) {
        L->Log(s_keepalive);
    } else {
        L->Log(s_not_keepalive);
    }

    if (DPCaps.dwFlags & 0x40) {
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



int TCommunications_Handler::Kick(unsigned int PlayerNo)
{
    if (PlayerNo >= 1 && PlayerNo <= this->MaxGamePlayers && direct_play_interface) {
        if (this->IsPlayerHuman(PlayerNo)) {
            if (this->PlayerOptions.dcoID[PlayerNo] != 0) {
                MSGFORMAT_KILL_PLAYER kp;
                kp.PlayerNo = PlayerNo;
                kp.dcoID = this->PlayerOptions.dcoID[PlayerNo];
                kp.CurrentTurn = this->current_turn;

                L->Log("Sent to all - drop player %d ID=%d ", PlayerNo, this->PlayerOptions.dcoID[PlayerNo]);
                L->Log("  >TX KP3 #d (%d)", PlayerNo, 0x0C);

                this->CommOut(0, 'K', &kp.PlayerNo, 0x0C, 0);

                if (this->PlayerStopTurn[PlayerNo] == 0) {
                    this->DropDeadPlayer(PlayerNo, this->PlayerOptions.dcoID[PlayerNo]);
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






int TCommunications_Handler::SetMyGameOptions(char* vpData, unsigned long dwSize) {
    if (dwSize > 2000)
        return 0;

    this->FreeOptions();

    if (vpData != 0 && dwSize != 0) {
        char* buf = new char[dwSize + 1];
        this->OptionsData = buf;
        if (buf == 0)
            return 0;

        memcpy(buf, vpData, dwSize);
        this->PlayerOptions.DataSizeToFollow = dwSize;
    }

    if (this->MeHost != 0) {
        this->PlayerOptions.NeedsToBeSent = 1;
    }

    L->Log("Host Set Options to size %d", dwSize);
    return 1;
}

void* TCommunications_Handler::GetMyGameOptions(unsigned long* dwSize) {
    *dwSize = this->PlayerOptions.DataSizeToFollow;
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

int __cdecl StringFromGUID(_GUID* lpguid, unsigned short* lpwsz)
{
    int i;
    unsigned char* g;

    g = reinterpret_cast<unsigned char*>(lpguid);
    *lpwsz = 0x7b;
    lpwsz = lpwsz + 1;
    i = 0;
    do {
        if (guid_format_positions[i] == '-') {
            *lpwsz = '-';
        } else {
            lpwsz = lpwsz + 1;
            lpwsz[-1] = guid_hex_digits[g[guid_format_positions[i]] >> 4];
            lpwsz[0] = guid_hex_digits[g[guid_format_positions[i]] & 0xf];
        }
        lpwsz = lpwsz + 1;
        i = i + 1;
    } while (static_cast<unsigned int>(i) < 20);
    *lpwsz = '}';
    lpwsz[1] = 0;
    return 0x26;
}

void TCommunications_Handler::SetHostPlayerNumber(unsigned int PlayerNo) { this->PlayerOptions.HostPlayerNumber = PlayerNo; }

unsigned int TCommunications_Handler::GetHostPlayerNumber() { return this->PlayerOptions.HostPlayerNumber; }





typedef unsigned short ushort;

void TCommunications_Handler::DebugSessionInformation(DPSESSIONDESC2* dpsd)
{
    ushort wszSPGuid[40];

    L->Log("--Information in DPSESSIONDESC2 --");
    L->Log("Size DPSESSIONDESC2 =%d", dpsd->dwSize);
    L->Log("Flags               =%d", dpsd->dwFlags);
    L->Log("Instance guid  DATA1=%u", dpsd->guidInstance.Data1);
    L->Log("               DATA2=%d", dpsd->guidInstance.Data2);
    L->Log("               DATA3=%d", dpsd->guidInstance.Data3);
    L->Log("               DATA4=%u", dpsd->guidInstance.Data4);
    StringFromGUID(&dpsd->guidInstance, wszSPGuid);
    L->Log("Instance GUID  str  =%s", wszSPGuid);
    L->Log("Applicatn guid DATA1=%u", dpsd->guidApplication.Data1);
    L->Log("               DATA2=%d", dpsd->guidApplication.Data2);
    L->Log("               DATA3=%d", dpsd->guidApplication.Data3);
    L->Log("               DATA4=%u", dpsd->guidApplication.Data4);
    L->Log("Max Players         =%d", dpsd->dwMaxPlayers);
    L->Log("Current Players     =%d", dpsd->dwCurrentPlayers);
    L->Log("Reserved 1          =%d", dpsd->dwReserved1);
    L->Log("Reserved 2          =%d", dpsd->dwReserved2);
    L->Log("User 1              =%d", dpsd->dwUser1);
    L->Log("User 2              =%d", dpsd->dwUser2);
    L->Log("User 3              =%d", dpsd->dwUser3);
    L->Log("User 4              =%d", dpsd->dwUser4);
    L->Log("--End Info--");
}

long TCommunications_Handler::EnableNewPlayers(IDirectPlay2* lpDP2, int bEnable) {
    if (lpDP2 == 0) return 0x80070057;
    IDirectPlay* lpDP;
    long hr = lpDP2->QueryInterface(IID_IDirectPlay,
                                    reinterpret_cast<void**>(&lpDP));
    if (hr < 0) return hr;
    hr = lpDP->EnableNewPlayers(bEnable);
    unsigned long links = lpDP->Release();
    L->Log("Released to links=%d", links);
    return hr;
}

void TCommunications_Handler::OutOfSync(int Status, unsigned long StopTime) {
    this->OutOfSyncFlag = Status;
    this->dwStopTime = StopTime;
}




int TCommunications_Handler::SendZoneMessage(char* Data, unsigned long dwSize) {
    if (!this->IsLobbyLaunched()) {
        L->Log("NOT LOBBY LAUNCHED.  EXITING");
        return 0;
    }

    L->Log("Sending zone message.");
    L->Log("  >TX ZONE MSG (%u)", dwSize);

    GUID zone_guid = rge_base_game->prog_info->zone_guid;

    long result = this->Lobby->SendZoneMessage(Data, dwSize, zone_guid);

    if (result == 0) {
        return 1;
    }

    this->Err->ShowReturn(result, "SendGameOptions");
    return 0;
}








int __stdcall EnumPlayersCallback2(
    unsigned long pidID,
    unsigned long dwPlayerType,
    DPNAME* lpName,
    unsigned long dwFlags,
    void* lpContext)
{
    TCommunications_Handler* handler =
        static_cast<TCommunications_Handler*>(lpContext);
    int i;
    int foundIndex;
    if (pidID != 0) {
        i = handler->PlayerOptions.LowPlayerNumber;
        int endIndex = handler->PlayerOptions.HighPlayerNumber;
        if (i <= endIndex) {
            unsigned long* array = handler->PlayerOptions.dcoID;
            for (; i <= endIndex; ++i) {
                if (array[i] == pidID) {
                    foundIndex = i;
                    goto logging;
                }
            }
        }
    }
    foundIndex = 0;
logging:
    sprintf(comm_enum_buffer, "ENUM %d name=%s id=%d", pidID, lpName->lpszShortNameA, foundIndex);
    L->Log("ENUM DEBUG: %s", comm_enum_buffer);
    L->Log("FORCEENUM %d name=%s id=%d", pidID, lpName->lpszShortNameA, foundIndex);
    L->Log("FILL PLAYER INFORMATION.");
    static_cast<TCommunications_Handler*>(lpContext)->UpdatePlayerInformation(
        pidID, lpName->lpszShortNameA, lpName->lpszLongNameA);
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

void TCommunications_Handler::SetSpeedV1(unsigned long v1) {
    this->Speed->SetV1(v1);
}

void TCommunications_Handler::SetSpeedV2(unsigned long v2) {
    this->Speed->SetV2(v2);
}

int TCommunications_Handler::IsPlayerOutOfSync(unsigned int pnum,
                                               unsigned long worldturn) {
    return this->Sync->IsPlayerOutOfSync(pnum, worldturn);
}
