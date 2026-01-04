#pragma once
#include "../common.h"
#include "com_q.h"
#include "com_loby.h"
#include "RGE_TSLC.h"
#include "com_spd.h"
#include "com_sync.h"
#include "com_addr.h"

struct NAME {
    char Name[256]; // 0x0
};

class HOLDER {
public:
    uint Serial;                             // 0x4
    uint Length;                             // 0x8
    ulong dcoFromID;                         // 0xC
    ulong dcoReceiveID;                      // 0x10
    uint fromPlayer;                         // 0x14

    HOLDER();
    virtual ~HOLDER();
};

static_assert(sizeof(HOLDER) == 0x18, "HOLDER Size Mismatch");
static_assert(offsetof(HOLDER, fromPlayer) == 0x14, "HOLDER Offset Mismatch");

class RESENDER {
public:
    uint Serial;                             // 0x4
    char* ResendMsg;                         // 0x8
    uint Length;                             // 0xC
    uint DestMap[10];                        // 0x10

    RESENDER();
    virtual ~RESENDER();
};

static_assert(sizeof(RESENDER) == 0x38, "RESENDER Size Mismatch");
static_assert(offsetof(RESENDER, DestMap) == 0x10, "RESENDER Offset Mismatch");

class TCommunications_Handler {
public:
    char* OptionsData;                       // 0x4
    int Steps;                               // 0x8
    ulong TickStart;                         // 0xC
    ulong TickCount;                         // 0x10
    ulong TimeSinceLastCall;                 // 0x14
    TChat* Chat;                             // 0x18
    int MeHost;                              // 0x1C
    int HaveHostInit;                        // 0x20
    char InCommBuff[4001];                   // 0x24
    char TBuff[257];                         // 0xFC5
    ulong current_turn;                      // 0x10C8
    ulong next_command_turn;                 // 0x10CC
    uint sequence;                           // 0x10D0
    long WaitOnPlayer;                       // 0x10D4
    ulong TurnSpeedMsec;                     // 0x10D8
    ulong AcknowledgeAfterMsec;              // 0x10DC
    uint Me;                                 // 0x10E0
    int Multiplayer;                         // 0x10E4
    int OutOfSyncFlag;                       // 0x10E8
    ulong dwStopTime;                        // 0x10EC
    float lastRXDataRate;                    // 0x10F0
    float lastTXDataRate;                    // 0x10F4
    char MyFriendlyName[129];                // 0x10F8
    char MyFormalName[129];                  // 0x1179
    char MyGameTitle[129];                   // 0x11FA
    ulong CurrentPlayers;                    // 0x127C
    int previous_last_world_random;          // 0x1280
    int last_world_random;                   // 0x1284
    int StepMode;                            // 0x1288
    ulong turnstart;                         // 0x128C
    ulong lastcalltick;                      // 0x1290
    ulong mselapsed;                         // 0x1294
    int AvgTurnTime;                         // 0x1298
    int SkipFrames;                          // 0x129C
    int PauseChangePending;                  // 0x12A0
    ulong CommunicationsVersionCode;         // 0x12A4
    int ShuttingDown;                        // 0x12A8
    ulong ReturnElapsed;                     // 0x12AC
    ulong ReturnRXPacketSize;                // 0x12B0
    ulong ReturnTXPacketSize;                // 0x12B4
    ulong RXPacketLength;                    // 0x12B8
    ulong RXPacketLengthHigh;                // 0x12BC
    ulong TXPacketLength;                    // 0x12C0
    ulong TXPacketLengthHigh;                // 0x12C4
    NAME* FriendlyName;                      // 0x12C8
    NAME* FormalName;                        // 0x12CC
    ulong LastTimeoutMessageTime;            // 0x12D0
    COMMSTATUS CommunicationsStatus;         // 0x12D4
    ushort MaxGamePlayers;                   // 0x12D8
    _GUID ServiceGUID;                       // 0x12DC
    _GUID ApplicationGUID;                   // 0x12EC
    _GUID SessionGUID;                       // 0x12FC
    void* HostHWND;                          // 0x130C
    int LobbyLaunched;                       // 0x1310
    ulong MaxReceiveLatency;                 // 0x1314
    _GUID NullGUID;                          // 0x1318
    ulong ResendAcknowledgements;            // 0x1328
    ulong ResentToOther;                     // 0x132C
    ulong DroppedPacketCount;                // 0x1330
    ulong RXPackets;                         // 0x1334
    ulong TXPackets;                         // 0x1338
    int IAmLagging;                          // 0x133C
    ulong ServiceTimeout;                    // 0x1340
    ulong LastPlayerCommunication[10];       // 0x1344
    ulong LastPlayerWarning[10];             // 0x136C
    ulong LastTXPing[10];                    // 0x1394
    ulong PlayerStopTurn[10];                // 0x13BC
    uint LastSerialRequestedTX[10];          // 0x13E4
    ulong LastRequestHonoredTX[10];          // 0x140C
    uint LastSerialRepliedTX[10];            // 0x1434
    ulong LastRequestRepliedTX[10];          // 0x145C
    ulong dwFlags;                           // 0x1484
    ulong dwMaxBufferSize;                   // 0x1488
    ulong dwMaxQueueSize;                    // 0x148C
    ulong dwMaxPlayers;                      // 0x1490
    ulong dwHundredBaud;                     // 0x1494
    ulong dwLatency;                         // 0x1498
    int Kicked[10];                          // 0x149C
    RGE_Communications_Queue* InQ;           // 0x14C4
    RGE_Communications_Queue* OutQ;          // 0x14C8
    RGE_Lobby* Lobby;                        // 0x14CC
    RGE_TimeSinceLastCall* tslc;             // 0x14D0
    RGE_Communications_Speed* Speed;         // 0x14D4
    RGE_Communications_Synchronize* Sync;    // 0x14D8
    RGE_Communications_Addresses* Addresses; // 0x14DC
    RGE_Comm_Error* Err;                     // 0x14E0
    uint GTDSerialNo;                        // 0x14E4
    uint HighResendStore;                    // 0x14E8
    uint DestMap[10];                        // 0x14EC
    uchar RGE_Guaranteed_Delivery;           // 0x1514
    int IntentionallyDropPackets;            // 0x1518
    uint WaitingForAck;                      // 0x151C
    RESENDER* Resend;                        // 0x1520
    HOLDER* OnHold;                          // 0x1524
    uint PlayerHighSerialNumber[10];         // 0x1528
    COMMPLAYEROPTIONS PlayerOptions;         // 0x1550
    ulong LastTurnAck[10];                   // 0x1720
    uint HoldCount;                          // 0x1748
    int WasKicked[10];                       // 0x174C

    virtual void GameOver();
    virtual char* WaitingOnNamedInfo(uint param_1);
    virtual char* WaitingOnInfo(uint param_1);
    virtual void StopIfSyncFail(int param_1);
    virtual void ShowSyncChatMsgs(int param_1);
    virtual void DropPacketsIntentionally(int param_1);
    virtual void SetStepMode(int param_1);
    virtual void SetSpeedControl(int param_1);
    virtual int CalculatePlayerRange();
    virtual void Step(int param_1);
    TCommunications_Handler(void* param_1, uchar param_2, TChat* param_3, _GUID param_4);
    virtual ~TCommunications_Handler();
    virtual void KillAnyMissingPlayers();
    virtual int AddCommand(ulong param_1, void* param_2, ulong param_3, int param_4, uchar param_5, int param_6);
    virtual void* get_command();
    virtual uchar new_command(void* param_1, int param_2);
    virtual int NewCommand(void* param_1, int param_2, int param_3);
    virtual void LastWorldRandom(int param_1);
    virtual int DoCycle(ulong param_1);
    virtual int HasKicked(uint param_1);
    virtual long SendPlayerName();
    virtual void LogRXMsg(uint param_1, uint param_2, ulong param_3, uchar param_4, uchar param_5);
    virtual void ReceiveGameMessages();
    virtual void ShutdownGameMessages();
    virtual void GetDPLAYMessages();
    virtual void CheckPingTime(int param_1);
    virtual int TXPing(uint param_1);
    virtual int TXDebugPing();
    virtual long FastSend(ulong param_1, void* param_2, ulong param_3, int param_4, int param_5);
    virtual int PreprocessMessages(ulong param_1, char* param_2, ulong param_3, ulong param_4, int param_5);
    virtual void NotifyWindow(COMMMESSAGES param_1);
    virtual void NotifyWindowParam(COMMMESSAGES param_1, long param_2);
    virtual int EvaluatePlayerMessage(ulong param_1, uint param_2, ulong param_3, uchar param_4, uchar param_5, char* param_6, uint param_7, ulong param_8, ulong param_9);
    virtual void SetPlayerStopTurn(uint param_1, ulong param_2);
    virtual void CheckPlayerStopTurn(ulong param_1);
    virtual void ReleaseSettings();
    virtual long SendSharedData(int param_1);
    virtual int TEST();
    virtual void SetSelfPlayer();
    virtual void DropDeadPlayer(uint param_1, ulong param_2);
    virtual void EvaluateSystemMessage(ulong param_1, char* param_2, ulong param_3, ulong param_4);
    virtual void SendGroupChatMsg(char* param_1);
    virtual void SendChatMsgAll(char* param_1);
    virtual void SendChatMsg(uint param_1, uint param_2, char* param_3);
    virtual long TXChat(uint param_1, uchar* param_2, char* param_3);
    virtual void SendSpeedChange(uint param_1, uint param_2);
    virtual void SendIResignMsg();
    virtual ulong HiTurnAcknowledged();
    virtual int AllPlayersAcknowledged();
    virtual long SendChecksumMessage(ulong param_1, uint param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    virtual uint ExecuteIncoming();
    virtual void ClearAllSerialNumbers();
    virtual void ClearRXandTX();
    virtual void ClearRXForPlayer(uint param_1);
    virtual int CountWaitingMessages();
    virtual void ClearTXForPlayer(uint param_1);
    virtual void ClearRXTXForPlayer(uint param_1);
    virtual int StoreIncoming(uint param_1, char* param_2, uint param_3, ulong param_4, ulong param_5);
    virtual int StoreForResend(uint param_1, char* param_2, uint param_3, uint* param_4);
    virtual int TXAcknowledgeMessage(uint param_1, uint param_2);
    virtual int RXAcknowledgeStoredMessage(uint param_1, uint param_2);
    virtual int PurgeAcknowledgedStoredMessages();
    virtual int SendStoredMessages();
    virtual int TXResendReply(uint param_1, uint param_2);
    virtual int TXResendRequest(uint param_1, uint param_2);
    virtual uchar GetNextSequence(ulong param_1);
    virtual long CommOut(ulong param_1, uchar param_2, void* param_3, int param_4, uchar param_5);
    virtual void DestroyMultiplayerGame();
    virtual COMMSTATUS GetCommunicationsStatus();
    virtual COMMSTATUS UnlinkCurrentLevel();
    virtual COMMSTATUS UnlinkToLevel(COMMSTATUS param_1);
    virtual COMMSTATUS AnalyzeCommunicationsStatus();
    virtual void ResetLastCommunicationTimes();
    virtual int IsPaused();
    virtual void DropAllHostedPlayers();
    virtual void LocalResumeGame(uint param_1);
    virtual void LocalPauseGame(uint param_1);
    virtual void SendPauseGame(int param_1);
    virtual int TogglePauseGame();
    virtual void RequestPauseGame(int param_1);
    virtual void RequestResumeGame(int param_1);
    virtual void SetRandomSeed(int param_1);
    virtual uint GetRandomSeed();
    virtual int WhoAmI();
    virtual int IsHost();
    virtual char* GetCommStateStr();
    virtual char* GetReadyPlayerStr();
    virtual int GetPlayerHumanity(uint param_1);
    virtual void SetPlayerHumanity(uint param_1, PLAYERHUMANITY param_2);
    virtual int GetActivePlayerCount();
    virtual int IsPlayerHuman(uint param_1);
    virtual int IsPlayerComputer(uint param_1);
    virtual char* GetCommInfo(uchar param_1);
    virtual char* GetPlayerName(uint param_1);
    virtual void UpdatePlayerInformation(ulong param_1, char* param_2, char* param_3);
    virtual int IsLobbyLaunched();
    virtual int LaunchLobbyGame();
    virtual void InitPlayerInformation(uint param_1, ulong param_2, char* param_3, char* param_4);
    virtual int SetGameTitle(char* param_1);
    virtual void SetMyPlayerName(char* param_1);
    virtual void SetPlayerName(uint param_1, char* param_2);
    virtual void* SetWindowHandle(void* param_1);
    virtual long CreateDirectPlayConversation();
    virtual int OpenMultiplayerConnection();
    virtual int CreateMultiplayerGame();
    virtual void PackPlayersDown();
    virtual int AddSelfPlayer();
    virtual long InitJoinGame();
    virtual int JoinMultiplayerGame(_GUID* param_1);
    virtual void LaunchMultiplayerGame();
    virtual long GetMyMultiPlayerCaps();
    virtual void SetApplicationGUID(_GUID param_1);
    virtual IDirectPlay3* GetDPInterface();
    virtual void SetServiceGUID(_GUID param_1);
    virtual void SetSessionGUID(_GUID param_1);
    virtual void UpdatePlayers();
    virtual void UpdatePlayer(uint param_1, int param_2);
    virtual int SetMyReadiness(int param_1, ulong param_2, ulong param_3, ulong param_4, ulong param_5, ulong param_6, ulong param_7, ulong param_8);
    virtual int GetClientReadiness(uint param_1, int* param_2, ulong* param_3, ulong* param_4, ulong* param_5, ulong* param_6, ulong* param_7, ulong* param_8, ulong* param_9);
    virtual int IsPlayerReady(uint param_1);
    virtual int ComputerPlayerGameStart();
    virtual int MultiplayerGameStart();
    virtual int AllPlayersReady();
    virtual long DPlayGetSessionDesc();
    virtual long CommGetCaps();
    virtual long CloseSession();
    virtual long ReleaseComm();
    virtual int Kick(uint param_1);
    virtual long DestroyMyPlayer();
    virtual int SetMyGameOptions(char* param_1, ulong param_2);
    virtual void* GetMyGameOptions(ulong* param_1);
    virtual void FreeOptions();
    virtual void SetHostPlayerNumber(uint param_1);
    virtual uint GetHostPlayerNumber();
    virtual void DebugSessionInformation(DPSESSIONDESC2* param_1);
    virtual long EnableNewPlayers(IDirectPlay2* param_1, int param_2);
    virtual void OutOfSync(int param_1, ulong param_2);
    virtual int SendZoneMessage(char* param_1, ulong param_2);
    virtual void ForcePlayerEnumeration();
    virtual void ForcePlayerDestroyAndCreate();
    virtual void ForceNameChange();
    virtual void SetSpeedV1(ulong param_1);
    virtual void SetSpeedV2(ulong param_1);
    virtual int IsPlayerOutOfSync(uint param_1, ulong param_2);
};

static_assert(sizeof(TCommunications_Handler) == 0x1774, "TCommunications_Handler Size Mismatch");
static_assert(offsetof(TCommunications_Handler, WasKicked) == 0x174C, "TCommunications_Handler Offset Mismatch");

inline RESENDER::RESENDER() {
    /* TODO: Stub */
//                              undefined __thiscall RESENDER(RESENDER * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              RESENDER *        ECX:4 (auto)   this
//                               ??0RESENDER@@QAE@XZ                                          XREF[1]:     TCommunications_Handler:00425d26(*
//                               RESENDER::RESENDER
//                              com_hand.h:293 (3)
//         00426450     MOV        EDX,this
//         00426452     PUSH       EDI
//                              com_hand.h:296 (23)
//         00426453     XOR        EAX,EAX
//         00426455     MOV        this,0xa
//         0042645a     LEA        EDI,[EDX + 0x10]
//         0042645d     MOV        dword ptr [EDX],EAX
//         0042645f     MOV        dword ptr [EDX + 0x8],EAX
//         00426462     MOV        dword ptr [EDX + 0x4],EAX
//         00426465     MOV        dword ptr [EDX + 0xc],EAX
//         00426468     STOSD.REP  ES:EDI
//                              com_hand.h:297 (4)
//         0042646a     MOV        EAX,EDX
//         0042646c     POP        EDI
//         0042646d     RET
//         0042646e     ??         90h
//         0042646f     NOP
}

inline RESENDER::~RESENDER() {
    /* TODO: Stub */
//                              void __thiscall ~RESENDER(RESENDER * this)
//              void              <VOID>         <RETURN>
//              RESENDER *        ECX:4 (auto)   this
//                               ??1RESENDER@@QAE@XZ                                          XREF[3]:     TCommunications_Handler:00425d21(*
//                               RESENDER::~RESENDER                                                       `vector_deleting_destructor':00426
//                                                                                                         ~TCommunications_Handler:00426288(
//                              com_hand.h:300 (4)
//         004264a0     PUSH       ESI
//         004264a1     MOV        ESI,this
//         004264a3     PUSH       EDI
//                              com_hand.h:301 (41)
//         004264a4     XOR        EDI,EDI
//         004264a6     MOV        EAX,dword ptr [ESI + 0x8]
//         004264a9     MOV        dword ptr [ESI],EDI
//         004264ab     CMP        EAX,EDI
//         004264ad     JZ         LAB_004264b8
//         004264af     PUSH       EAX
//         004264b0     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004264b5     ADD        ESP,0x4
//                               LAB_004264b8                                                 XREF[1]:     004264ad(j)
//         004264b8     MOV        dword ptr [ESI + 0x8],EDI
//         004264bb     MOV        dword ptr [ESI + 0x4],EDI
//         004264be     MOV        dword ptr [ESI + 0xc],EDI
//         004264c1     LEA        EDI,[ESI + 0x10]
//         004264c4     MOV        this,0xa
//         004264c9     XOR        EAX,EAX
//         004264cb     STOSD.REP  ES:EDI
//                              com_hand.h:302 (3)
//         004264cd     POP        EDI
//         004264ce     POP        ESI
//         004264cf     RET
}

inline HOLDER::HOLDER() {
    /* TODO: Stub */
//                              undefined __thiscall HOLDER(HOLDER * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              HOLDER *          ECX:4 (auto)   this
//                               ??0HOLDER@@QAE@XZ                                            XREF[1]:     TCommunications_Handler:00425d73(*
//                               HOLDER::HOLDER
//                              com_hand.h:336 (2)
//         004265e0     MOV        EAX,this
//                              com_hand.h:339 (16)
//         004265e2     XOR        this,this
//         004265e4     MOV        dword ptr [EAX],this
//         004265e6     MOV        dword ptr [EAX + 0x4],this
//         004265e9     MOV        dword ptr [EAX + 0x8],this
//         004265ec     MOV        dword ptr [EAX + 0xc],this
//         004265ef     MOV        dword ptr [EAX + 0x10],this
//                              com_hand.h:340 (1)
//         004265f2     RET
//         004265f3     ??         90h
//         004265f4     NOP
//         004265f5     NOP
//         004265f6     NOP
//         004265f7     NOP
//         004265f8     NOP
//         004265f9     NOP
//         004265fa     NOP
//         004265fb     NOP
//         004265fc     NOP
//         004265fd     NOP
//         004265fe     NOP
//         004265ff     NOP
}

inline HOLDER::~HOLDER() {
    /* TODO: Stub */
//                              void __thiscall ~HOLDER(HOLDER * this)
//              void              <VOID>         <RETURN>
//              HOLDER *          ECX:4 (auto)   this
//                               ??1HOLDER@@QAE@XZ                                            XREF[3]:     TCommunications_Handler:00425d6e(*
//                               HOLDER::~HOLDER                                                           `vector_deleting_destructor':00426
//                                                                                                         ~TCommunications_Handler:004262af(
//                              com_hand.h:343 (4)
//         00426600     PUSH       ESI
//         00426601     MOV        ESI,this
//         00426603     PUSH       EDI
//                              com_hand.h:344 (31)
//         00426604     XOR        EDI,EDI
//         00426606     MOV        EAX,dword ptr [ESI]
//         00426608     CMP        EAX,EDI
//         0042660a     JZ         LAB_00426615
//         0042660c     PUSH       EAX
//         0042660d     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00426612     ADD        ESP,0x4
//                               LAB_00426615                                                 XREF[1]:     0042660a(j)
//         00426615     MOV        dword ptr [ESI],EDI
//         00426617     MOV        dword ptr [ESI + 0x4],EDI
//         0042661a     MOV        dword ptr [ESI + 0x8],EDI
//         0042661d     MOV        dword ptr [ESI + 0xc],EDI
//         00426620     MOV        dword ptr [ESI + 0x10],EDI
//                              com_hand.h:345 (3)
//         00426623     POP        EDI
//         00426624     POP        ESI
//         00426625     RET
//         00426626     ??         90h
//         00426627     NOP
//         00426628     NOP
//         00426629     NOP
//         0042662a     NOP
//         0042662b     NOP
//         0042662c     NOP
//         0042662d     NOP
//         0042662e     NOP
//         0042662f     NOP
}

