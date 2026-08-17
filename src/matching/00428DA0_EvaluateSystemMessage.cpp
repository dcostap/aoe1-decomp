// 00428DA0 TCommunications_Handler::EvaluateSystemMessage (Com_hand.cpp:2411-2771)
// __thiscall (unused_1, char* system_message_data, unsigned long message_id_home,
//             unsigned long unused_4) -> void, ret 10h
// DPLAY system-message dispatcher: switch on DPMSG_GENERIC::dwType with low-value sub-chain
// (3/5/7) + byte-table jump dispatch for 0x31..0x109; default logs "COMM:Unknown".
//
// BINARY NOTE: The low-value chain and byte-table dispatch are separate compiler
// paths. Keep cases 7 and 0x105 as separate source bodies; VC5 merges their tail.
// BINARY NOTE: Load the message ID into message_id_home before copying it to newid. This recovers
// the original parameter-home stores at the CREATE handler's two call boundaries.
// BINARY NOTE: The reversed current_turn/AcknowledgeAfterMsec source order recovers
// the original member-load and member-store order.

#include <stdio.h>
#include <string.h>

class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog* log, const char* fmt, ...);
    void FlushLog();
};
extern TDebuggingLog* L;                          // 62C4FCh
extern "C" int g_DirectPlayConversation;          // 62C5ECh

struct MSGFORMAT_KILL_PLAYER {
    int dcoID;
    int CurrentTurn;
    int current_turn;
};

struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;       // +0x00 (0x1550)
    unsigned char _pad0[3];
    unsigned long LastSentTime;        // +0x04
    int ProgramState;                  // +0x08
    unsigned long CurrentTurn;         // +0x0C
    unsigned char TurnSpeedMsec;       // +0x10
    unsigned char _pad1[3];
    unsigned long dcoID[10];           // +0x14 (0x1564)
    unsigned long AcknowledgeAfterMsec; // +0x3C (0x158C)
    unsigned char CommandTurnIncrement; // +0x40
    unsigned char _pad2[3];
    int PlayerReady[10];               // +0x44
    unsigned long User1[10];           // +0x6C
    unsigned long User2[10];           // +0x94
    unsigned long User3[10];           // +0xBC
    unsigned long User4[10];           // +0xE4
    unsigned long User5[10];           // +0x10C
    unsigned long User6[10];           // +0x134
    unsigned long User7[10];           // +0x15C
    int Humanity[10];                  // +0x184 (0x16D4)
    unsigned char InvalidPlayer[10];   // +0x1AC (0x16FC)
    unsigned char _pad3[2];
    unsigned long Initialized;         // +0x1B8
    unsigned long RandomSeed;          // +0x1BC
    unsigned short HighPlayerNumber;   // +0x1C0 (0x1710)
    unsigned short LowPlayerNumber;    // +0x1C2 (0x1712)
    unsigned int HostPlayerNumber;     // +0x1C4 (0x1714)
    int GameHasStarted;                // +0x1C8 (0x1718)
    unsigned long DataSizeToFollow;    // +0x1CC (0x171C)
};

class TCommunications_Handler {
public:
    // BINARY NOTE: This field surface follows the canonical communications donor
    // through PlayerOptions. The target uses these members at their proven offsets.
    int OptionsChanged;                         // +0x00
    void* OptionsData;                          // +0x04
    int Steps;                                   // +0x08
    unsigned long TickStart;                    // +0x0C
    unsigned long TickCount;                    // +0x10
    unsigned long TimeSinceLastCall;            // +0x14
    void* Chat;                                  // +0x18
    int MeHost;                                  // +0x1C
    int HaveHostInit;                            // +0x20
    char InCommBuff[4001];                       // +0x24
    char TBuff[257];                             // +0xFC5
    unsigned char _pad_10C6[2];                 // +0x10C6
    unsigned long current_turn;                 // +0x10C8
    unsigned long next_command_turn;            // +0x10CC
    unsigned int sequence;                      // +0x10D0
    long WaitOnPlayer;                           // +0x10D4
    unsigned long TurnSpeedMsec;                // +0x10D8
    unsigned long AcknowledgeAfterMsec;         // +0x10DC
    unsigned int Me;                            // +0x10E0
    int Multiplayer;                            // +0x10E4
    int OutOfSyncFlag;                          // +0x10E8
    unsigned long dwStopTime;                   // +0x10EC
    float lastRXDataRate;                       // +0x10F0
    float lastTXDataRate;                       // +0x10F4
    char MyFriendlyName[129];                   // +0x10F8
    char MyFormalName[129];                     // +0x1179
    char MyGameTitle[129];                      // +0x11FA
    unsigned char _pad_127B;                    // +0x127B
    unsigned long CurrentPlayers;               // +0x127C
    int previous_last_world_random;             // +0x1280
    int last_world_random;                      // +0x1284
    int StepMode;                               // +0x1288
    unsigned long turnstart;                    // +0x128C
    unsigned long lastcalltick;                 // +0x1290
    unsigned long mselapsed;                    // +0x1294
    int AvgTurnTime;                             // +0x1298
    int SkipFrames;                              // +0x129C
    int PauseChangePending;                     // +0x12A0
    unsigned long CommunicationsVersionCode;   // +0x12A4
    int ShuttingDown;                            // +0x12A8
    unsigned long ReturnElapsed;                // +0x12AC
    unsigned long ReturnRXPacketSize;           // +0x12B0
    unsigned long ReturnTXPacketSize;           // +0x12B4
    unsigned long RXPacketLength;               // +0x12B8
    unsigned long RXPacketLengthHigh;           // +0x12BC
    unsigned long TXPacketLength;               // +0x12C0
    unsigned long TXPacketLengthHigh;           // +0x12C4
    void* FriendlyName;                          // +0x12C8
    void* FormalName;                            // +0x12CC
    unsigned long LastTimeoutMessageTime;       // +0x12D0
    int CommunicationsStatus;                   // +0x12D4
    unsigned short MaxGamePlayers;              // +0x12D8
    unsigned char _pad_12DA[2];                 // +0x12DA
    unsigned char ServiceGUID[16];              // +0x12DC
    unsigned char ApplicationGUID[16];          // +0x12EC
    unsigned char SessionGUID[16];               // +0x12FC
    void* HostHWND;                             // +0x130C
    int LobbyLaunched;                           // +0x1310
    unsigned long MaxReceiveLatency;            // +0x1314
    unsigned char NullGUID[16];                 // +0x1318
    unsigned long ResendAcknowledgements;       // +0x1328
    unsigned long ResentToOther;                // +0x132C
    unsigned long DroppedPacketCount;           // +0x1330
    unsigned long RXPackets;                    // +0x1334
    unsigned long TXPackets;                    // +0x1338
    int IAmLagging;                              // +0x133C
    unsigned long ServiceTimeout;               // +0x1340
    unsigned long LastPlayerCommunication[10];  // +0x1344
    unsigned long LastPlayerWarning[10];        // +0x136C
    unsigned long LastTXPing[10];               // +0x1394
    unsigned long PlayerStopTurn[10];           // +0x13BC
    unsigned long LastSerialRequestedTX[10];    // +0x13E4
    unsigned long LastRequestHonoredTX[10];     // +0x140C
    unsigned long LastSerialRepliedTX[10];      // +0x1434
    unsigned long LastRequestRepliedTX[10];     // +0x145C
    unsigned long dwFlags;                      // +0x1484
    unsigned long dwMaxBufferSize;              // +0x1488
    unsigned long dwMaxQueueSize;               // +0x148C
    unsigned long dwMaxPlayers;                 // +0x1490
    unsigned long dwHundredBaud;                // +0x1494
    unsigned long dwLatency;                    // +0x1498
    int Kicked[10];                             // +0x149C
    void* InQ;                                   // +0x14C4
    void* OutQ;                                  // +0x14C8
    void* Lobby;                                 // +0x14CC
    void* tslc;                                  // +0x14D0
    void* Speed;                                 // +0x14D4
    void* Sync;                                  // +0x14D8
    void* Addresses;                             // +0x14DC
    void* Err;                                   // +0x14E0
    unsigned int GTDSerialNo;                    // +0x14E4
    unsigned int HighResendStore;                // +0x14E8
    unsigned int DestMap[10];                    // +0x14EC
    unsigned char RGE_Guaranteed_Delivery;      // +0x1514
    unsigned char _pad_1515[3];                 // +0x1515
    int IntentionallyDropPackets;               // +0x1518
    unsigned int WaitingForAck;                 // +0x151C
    void* Resend;                                // +0x1520
    void* OnHold;                                // +0x1524
    unsigned int PlayerHighSerialNumber[10];    // +0x1528
    COMMPLAYEROPTIONS PlayerOptions;             // +0x1550

    void NotifyWindow(int msg);
    void NotifyWindowParam(int msg, int player);
    int IsPlayerHuman(unsigned int player);
    void InitPlayerInformation(unsigned int player, int human, char* status, char* info);
    void UpdatePlayers();
protected:
    int CalculatePlayerRange();
public:
    void DropDeadPlayer(unsigned int player, unsigned long dpid);
    void UpdatePlayer(unsigned int player, int param);
protected:
    void ClearRXTXForPlayer(unsigned int player);
public:
    long SendSharedData(int force);
    long FastSend(unsigned long to, void* data, unsigned long size, int param_4, int param_5);
    void CheckPingTime(int param_1);
    long EnableNewPlayers(int direct_play, int enable_links);
    void KillAnyMissingPlayers();
    int SetMyGameOptions(char* param_1, unsigned long param_2);
    void SetSelfPlayer();
    void ResetLastCommunicationTimes();
    void ClearRXandTX();
    long CommOut(int type, int msg_type, void* data, long size, int flags);
    void EvaluateSystemMessage(unsigned long unused_1, char* system_message_data,
                               unsigned long message_id_home, unsigned long unused_4);
};

// The executable's .rdata labels and addresses identify these reviewed strings.
// Keep the names local to this function. Do not encode their addresses in expressions.
// 00581CD8: s_!MP_in_DPANALYSIS
extern const char s_MP_in_DPANALYSIS_00581cd8[];
// 00581CC8: s_DP_Sys_Msg_%d
extern const char s_DP_Sys_Msg_00581cc8[];
// 00581C90: s_DPMSG_DESTRPYPLAYERORGROUP__(to_
extern const char s_DPMSG_DESTRPYPLAYERORGROUP_00581c90[];
// 00581C78: s_FROM_Player_ID_=__%d_
extern const char s_FROM_Player_ID_00581c78[];
// 00581C5C: s_Equates_to_our_player_#_%d_
extern const char s_Equates_to_our_player_00581c5c[];
// 00581C40: s_Program_state_is________%d_
extern const char s_Program_state_is_00581c40[];
// 00581C14: s_HOST_Send_to_all_-_drop_player_%
extern const char s_HOST_Send_to_all_drop_player_00581c14[];
// 00581C00: s___>TX_KP2_#%d_(%d)
extern const char s_TX_KP2_00581c00[];
// 00581BEC: s_RX_NEW_PLR_ID=%d
extern const char s_RX_NEW_PLR_ID_00581bec[];
// 00581BCC: s_COMM:_Create_Player_Request.
extern const char s_COMM_Create_Player_Request_00581bcc[];
// 00581B8C: s_Create_Player_Request.__(MeHost=
extern const char s_Create_Player_Request_00581b8c[];
// 00581B64: s___>TX_GIP_%u_(1)
extern const char s_TX_GIP_00581b64[];
// 00581B78: s___>TX_GIP2_%u_(1)
extern const char s_TX_GIP2_00581b78[];
// 00581B30: s_Add/delete_player_of_group.
extern const char s_Add_delete_player_of_group_00581b30[];
// 00581B24: s_DP_Chat_Msg
extern const char s_DP_Chat_Msg_00581b24[];
// 00581B4C: s_delete_player_of_group.
extern const char s_delete_player_of_group_00581b4c[];
// 00581B14: s_Assumed_host
extern const char s_Assumed_host_00581b14[];
// 00581AF0: s_Host_(other)_Exit_before_game_st
extern const char s_Host_other_Exit_before_game_start_00581af0[];
// 00581AD8: s_COMM:Host_session_lost.
extern const char s_COMM_Host_session_lost_00581ad8[];
// 00581A98: s__Player_Data>_P1=%d_P2=%d_P3=%d_
extern const char s_Player_Data_00581a98[];
// 00581A70: s_Set_expected_ser#_for_player_%d_
extern const char s_Set_expected_ser_for_player_00581a70[];
// 00581A5C: s_Host_-_no_rcv_opts.
extern const char s_Host_no_rcv_opts_00581a5c[];
// 00581A30: s_Checking_state_for_options_rcvd_
extern const char s_Checking_state_for_options_00581a30[];
// 00581A10: s_Group_options_rcvd_from_host.
extern const char s_Group_options_rcvd_from_host_00581a10[];
// 005819FC: s_Host_Launched_game
extern const char s_Host_Launched_game_005819fc[];
// 005819D8: s_OPTIONS_SET_-_program_state_=_%d
extern const char s_OPTIONS_SET_program_state_005819d8[];
// 005819BC: s_Set_my_serial_number_to_%d
extern const char s_Set_my_serial_number_to_005819bc[];
// 005819A4: s_Game_not_yet_started.
extern const char s_Game_not_yet_started_005819a4[];
// 00581974: s_Serial_#_was_0,_setting_my_seria
extern const char s_Serial_was_0_setting_my_serial_00581974[];
// 00581958: s_Set_player_or_group_name
extern const char s_Set_player_or_group_name_00581958[];
// 00581944: s_Secure_message_dp
extern const char s_Secure_message_dp_00581944[];
// 0058192C: s_Set_Sessino_Description
extern const char s_Set_Sessino_Description_0058192c[];
// 0058190C: s_START_SESSION_MESSAGE_RCVD._
extern const char s_START_SESSION_MESSAGE_RCVD_0058190c[];
// 005818FC: s__***_NOTICE_***
extern const char s_NOTICE_005818fc[];
// 005818DC: s_COMM:Unknown_system_message._%d
extern const char s_COMM_Unknown_system_message_005818dc[];

// BINARY NOTE: These VC5 DirectPlay 3 layouts map the observed payload loads to
// DPMSG fields from the repository's period DPLAY.H surface.
enum {
    DPSYS_CREATEPLAYERORGROUP = 0x0003,
    DPSYS_DESTROYPLAYERORGROUP = 0x0005,
    DPSYS_ADDPLAYERTOGROUP = 0x0007,
    DPSYS_DELETEPLAYERFROMGROUP = 0x0021,
    DPSYS_SESSIONLOST = 0x0031,
    DPSYS_HOST = 0x0101,
    DPSYS_SETPLAYERORGROUPDATA = 0x0102,
    DPSYS_SETPLAYERORGROUPNAME = 0x0103,
    DPSYS_SETSESSIONDESC = 0x0104,
    DPSYS_ADDGROUPTOGROUP = 0x0105,
    DPSYS_SECUREMESSAGE = 0x0107,
    DPSYS_STARTSESSION = 0x0108,
    DPSYS_CHAT = 0x0109
};

struct DP_NAME_ANSI {
    unsigned long dwSize;
    unsigned long dwFlags;
    char* lpszShortNameA;
    char* lpszLongNameA;
};

struct DPMSG_GENERIC {
    unsigned long dwType;
};

struct DPMSG_CREATEPLAYERORGROUP {
    unsigned long dwType;
    unsigned long dwPlayerType;
    unsigned long dpId;
    unsigned long dwCurrentPlayers;
    void* lpData;
    unsigned long dwDataSize;
    DP_NAME_ANSI dpnName;
    unsigned long dpIdParent;
    unsigned long dwFlags;
};

struct DPMSG_DESTROYPLAYERORGROUP {
    unsigned long dwType;
    unsigned long dwPlayerType;
    unsigned long dpId;
    void* lpLocalData;
    unsigned long dwLocalDataSize;
    void* lpRemoteData;
    unsigned long dwRemoteDataSize;
    DP_NAME_ANSI dpnName;
    unsigned long dpIdParent;
    unsigned long dwFlags;
};

struct GAME_OPTIONS_TRAILER {
    unsigned char first_byte;
};

struct COMM_SHARED_DATA {
    COMMPLAYEROPTIONS player_options;
    GAME_OPTIONS_TRAILER game_options;
};

// BINARY NOTE: SendSharedData writes OptionsData after the complete
// COMMPLAYEROPTIONS record. game_options names that trailing receiver payload.

struct DPMSG_SETPLAYERORGROUPDATA {
    unsigned long dwType;
    unsigned long dwPlayerType;
    unsigned long dpId;
    union {
        void* lpData;
        COMM_SHARED_DATA* shared_data;
    };
    unsigned long dwDataSize;
};

union DPMSG_SYSTEM_MESSAGE {
    DPMSG_GENERIC generic;
    DPMSG_CREATEPLAYERORGROUP create_player;
    DPMSG_DESTROYPLAYERORGROUP destroy_player;
    DPMSG_SETPLAYERORGROUPDATA set_player_data;
};

void TCommunications_Handler::EvaluateSystemMessage(unsigned long unused_1, char* system_message_data,
                                                    unsigned long message_id_home, unsigned long unused_4)
{
    DPMSG_SYSTEM_MESSAGE* message = (DPMSG_SYSTEM_MESSAGE*)system_message_data;
    if (this->Multiplayer == 0) {
        TDebuggingLog::Log(L, s_MP_in_DPANALYSIS_00581cd8);          // "!MP in DPANALYSIS"
        return;
    }

    TDebuggingLog::Log(L, s_DP_Sys_Msg_00581cc8, message->generic.dwType);         // "DP Sys Msg %d"

    switch (message->generic.dwType) {
    case DPSYS_DESTROYPLAYERORGROUP: {
        unsigned long victim = message->destroy_player.dpId;
        unsigned int i;
        if (victim != 0) {
            int p = this->PlayerOptions.LowPlayerNumber;
            int high = this->PlayerOptions.HighPlayerNumber;
            if (p <= high) {
                for (; p <= high; p++) {
                    if (this->PlayerOptions.dcoID[p] == victim) {
                        i = p;
                        goto found2;
                    }
                }
            }
        }
        i = 0;
found2:
        TDebuggingLog::Log(L, s_DPMSG_DESTRPYPLAYERORGROUP_00581c90);          // "DPMSG_DESTRPYPLAYERORGROUP  (to debug drop player)"
        TDebuggingLog::Log(L, s_FROM_Player_ID_00581c78, message->destroy_player.dpId);  // "FROM Player ID =..."
        TDebuggingLog::Log(L, s_Equates_to_our_player_00581c5c, i);       // "Equates to our player # %d "
        TDebuggingLog::Log(L, s_Program_state_is_00581c40, this->PlayerOptions.ProgramState);  // "Program state is..."
        L->FlushLog();
        if (this->IsPlayerHuman(i) != 0 && this->PlayerStopTurn[i] == 0) {
            if (i == this->Me)
                this->NotifyWindow(0x17B2);
            else
                this->NotifyWindowParam(0x17B3, i);
        }
        if (this->MeHost == 0)
            return;
        MSGFORMAT_KILL_PLAYER kp;
        kp.dcoID = i;
        kp.CurrentTurn = message->destroy_player.dpId;
        kp.current_turn = this->current_turn;
        TDebuggingLog::Log(L, s_HOST_Send_to_all_drop_player_00581c14, i, kp.CurrentTurn);  // "HOST Send to all - drop player %d ID=%d "
        TDebuggingLog::Log(L, s_TX_KP2_00581c00, i, 0xC);             // "  >TX KP2 #%d (%d)"
        this->CommOut(0, 'K', &kp, 0xC, 0);
        if (i <= 0)
            return;
        if (this->PlayerStopTurn[kp.dcoID] != 0)
            return;
        this->DropDeadPlayer(i, victim);
        return;
    }

    case DPSYS_CREATEPLAYERORGROUP: {
        unsigned long newid;
        unsigned int i;
        // BINARY NOTE: Assign message_id_home first. The copy to newid preserves its original home.
        message_id_home = message->create_player.dpId;
        newid = message_id_home;
        TDebuggingLog::Log(L, s_RX_NEW_PLR_ID_00581bec, newid);   // "RX NEW PLR ID=%d"
        TDebuggingLog::Log(L, s_COMM_Create_Player_Request_00581bcc);          // "COMM: Create Player Request."
        sprintf(this->TBuff, s_Create_Player_Request_00581b8c, this->MeHost, this->PlayerOptions.ProgramState, newid);
        TDebuggingLog::Log(L, this->TBuff);
        if (this->PlayerOptions.ProgramState == 5 || this->current_turn > 6) {
            *this->TBuff = 'I';
            TDebuggingLog::Log(L, s_TX_GIP_00581b64, message->create_player.dpId);   // "  >TX GIP %u (1)"
            this->FastSend(message->create_player.dpId, this->TBuff, 1, 0, 0);
            return;
        }
        if (this->MeHost == 0)
            return;
        i = 1;
        for (; i <= this->MaxGamePlayers; i++) {
            if (this->PlayerOptions.Humanity[i] == 0)
                goto found;
        }
        i = 0;
found:
        if (i != 0 && this->PlayerOptions.ProgramState == 3) {
            this->InitPlayerInformation(i, (int)message->create_player.dpId,
                                         message->create_player.dpnName.lpszShortNameA,
                                         message->create_player.dpnName.lpszLongNameA);
            this->PlayerOptions.dcoID[i] = message_id_home;
            this->PlayerOptions.Humanity[i] = 2;
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
        TDebuggingLog::Log(L, s_TX_GIP2_00581b78, message->create_player.dpId);   // "  >TX GIP2 %u (1)"
        this->FastSend(message->create_player.dpId, this->TBuff, 1, 0, 0);
        this->UpdatePlayers();
        return;
    }

    // BINARY NOTE: Keep separate bodies. VC5 tail-merges the case 7 and 0x105 handlers.
    case DPSYS_ADDPLAYERTOGROUP:
        TDebuggingLog::Log(L, s_Add_delete_player_of_group_00581b30);          // "Add/delete player of group."
        return;

    case DPSYS_ADDGROUPTOGROUP:
        TDebuggingLog::Log(L, s_Add_delete_player_of_group_00581b30);          // "Add/delete player of group."
        return;

    case DPSYS_CHAT:
        TDebuggingLog::Log(L, s_DP_Chat_Msg_00581b24);          // "DP Chat Msg"
        return;

    case DPSYS_DELETEPLAYERFROMGROUP:
        TDebuggingLog::Log(L, s_delete_player_of_group_00581b4c);          // "delete player of group."
        return;

    case DPSYS_HOST:
        if (this->PlayerOptions.ProgramState != 3 && this->current_turn >= 6) {
            TDebuggingLog::Log(L, s_Assumed_host_00581b14);      // "Assumed host"
            this->MeHost = 1;
            this->PlayerOptions.HostPlayerNumber = this->Me;
            this->CheckPingTime(1);
            this->UpdatePlayers();
            this->EnableNewPlayers(g_DirectPlayConversation, 0);
            this->CalculatePlayerRange();
            this->NotifyWindowParam(0x17B1, this->Me);
            this->KillAnyMissingPlayers();
            return;
        }
        TDebuggingLog::Log(L, s_Host_other_Exit_before_game_start_00581af0);          // "Host (other) Exit before game start"
        this->NotifyWindow(0x17A9);
        this->EnableNewPlayers(g_DirectPlayConversation, 1);
        return;

    case DPSYS_SESSIONLOST:
        TDebuggingLog::Log(L, s_COMM_Host_session_lost_00581ad8);          // "COMM:Host session lost."
        this->PlayerOptions.NeedsToBeSent = 1;
        this->UpdatePlayers();
        this->NotifyWindow(0x17A9);
        return;

    case DPSYS_SETPLAYERORGROUPDATA: {
        sprintf(this->TBuff, s_Player_Data_00581a98,
                this->PlayerOptions.dcoID[1], this->PlayerOptions.dcoID[2],
                this->PlayerOptions.dcoID[3], this->PlayerOptions.dcoID[4],
                this->PlayerOptions.dcoID[5], this->PlayerOptions.dcoID[6],
                this->PlayerOptions.dcoID[7], this->PlayerOptions.dcoID[8]);
        TDebuggingLog::Log(L, this->TBuff);
        unsigned int i = 1;
        if (this->MaxGamePlayers >= i) {
            unsigned int ser = 2000;
            do {
                if (this->PlayerHighSerialNumber[i] == 0 && this->PlayerOptions.dcoID[i] != 0) {
                    this->ClearRXTXForPlayer(i);
                    this->PlayerHighSerialNumber[i] = ser;
                    TDebuggingLog::Log(L, s_Set_expected_ser_for_player_00581a70, i, ser + 1);
                }
                i++;
                ser += 2000;
            } while (i <= this->MaxGamePlayers);
        }
        if (this->MeHost != 0) {
            TDebuggingLog::Log(L, s_Host_no_rcv_opts_00581a5c);      // "Host - no rcv opts."
            return;
        }
        TDebuggingLog::Log(L, s_Checking_state_for_options_00581a30);          // "Checking state for options rcvd from host."
        if (this->PlayerOptions.ProgramState != 3)
            return;
        TDebuggingLog::Log(L, s_Group_options_rcvd_from_host_00581a10);          // "Group options rcvd from host."
        if (message->set_player_data.dwDataSize >= sizeof(message->set_player_data.shared_data->player_options)) {
            memcpy(&this->PlayerOptions, &message->set_player_data.shared_data->player_options,
                   sizeof(message->set_player_data.shared_data->player_options));
            if (message->set_player_data.dwDataSize >= this->PlayerOptions.DataSizeToFollow
                    + sizeof(message->set_player_data.shared_data->player_options)) {
                this->SetMyGameOptions((char*)&message->set_player_data.shared_data->game_options, this->PlayerOptions.DataSizeToFollow);
            }
            this->NotifyWindow(0x17A6);
        }
        // BINARY NOTE: This source order preserves the original member-store order.
        this->current_turn = this->PlayerOptions.CurrentTurn;
        this->AcknowledgeAfterMsec = this->PlayerOptions.AcknowledgeAfterMsec;
        this->SetSelfPlayer();
        if (this->PlayerOptions.GameHasStarted != 0) {
            TDebuggingLog::Log(L, s_Host_Launched_game_005819fc);      // "Host Launched game"
            this->CalculatePlayerRange();
            TDebuggingLog::Log(L, s_OPTIONS_SET_program_state_005819d8, this->PlayerOptions.ProgramState);  // "OPTIONS SET - program state = %d"
            this->PlayerOptions.ProgramState = 5;
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
                            TDebuggingLog::Log(L, s_Set_expected_ser_for_player_00581a70, k, ser2 + 1);
                        }
                        k++;
                        ser2 += 2000;
                    } while (k <= this->MaxGamePlayers);
                }
            }
            this->GTDSerialNo = this->Me * 2000 + 1;
            TDebuggingLog::Log(L, s_Set_my_serial_number_to_005819bc, this->GTDSerialNo);  // "Set my serial number to %d"
            this->NotifyWindow(0x17A6);
            this->NotifyWindow(0x17A7);
        } else {
            TDebuggingLog::Log(L, s_Game_not_yet_started_005819a4);      // "Game not yet started."
        }
        if (this->PlayerOptions.GameHasStarted == 0 && this->GTDSerialNo == 0 && this->Me != 0) {
            this->GTDSerialNo = this->Me * 2000 + 1;
            TDebuggingLog::Log(L, s_Serial_was_0_setting_my_serial_00581974, this->GTDSerialNo);  // "Serial # was 0, setting my serial number to %d"
        }
        this->UpdatePlayers();
        this->NotifyWindow(0x17A6);
        return;
    }

    case DPSYS_SETPLAYERORGROUPNAME:
        this->UpdatePlayers();
        TDebuggingLog::Log(L, s_Set_player_or_group_name_00581958);          // "Set player or group name"
        this->NotifyWindow(0x17A6);
        return;

    case DPSYS_SECUREMESSAGE:
        TDebuggingLog::Log(L, s_Secure_message_dp_00581944);          // "Secure message dp"
        return;

    case DPSYS_SETSESSIONDESC:
        TDebuggingLog::Log(L, s_Set_Sessino_Description_0058192c);          // "Set Sessino Description"
        return;

    case DPSYS_STARTSESSION:
        TDebuggingLog::Log(L, s_START_SESSION_MESSAGE_RCVD_0058190c);          // "START SESSION MESSAGE RCVD. "
        TDebuggingLog::Log(L, s_NOTICE_005818fc);          // " *** NOTICE ***"
        return;
    }
    TDebuggingLog::Log(L, s_COMM_Unknown_system_message_005818dc, message->generic.dwType);     // "COMM:Unknown system message. %d"
}
