#include <windows.h>
#include "common.h"
#include <dplay.h>

enum COMMSTATUS {
    // Source of truth: com_hand.cpp.asm AnalyzeCommunicationsStatus @ 0x0042C690
    UNINITIALIZED = 0,
    INITIALIZED = 1,
    SINGLE_PLAYER = 2,
    MULTIPLAYER_RESET = 3,
    CONVERSATION_OPEN = 4,
    SERVICE_AVAILABLE = 5,
    SESSION_AVAILABLE = 6,
    SESSION_HOSTED = 7,
    COMM_UNKNOWN_8 = 8,
    PLAYER_CREATED = 9,
    GAME_PLAYER_SET = 10,
    COMM_SETTINGS_EXCHANGED = 11,
    GAME_OPTIONS_EXCHANGED = 12,
    GAME_IS_LOADING = 13,
    GAME_IS_RUNNING = 14,
    GAME_IS_PAUSED = 15,

    // Legacy aliases used by the decomp stub code.
    COMM_NONE = UNINITIALIZED,
    COMM_IDLE = INITIALIZED,
    COMM_ACTIVE = SINGLE_PLAYER,
};

struct TChat;
struct NAME;
struct RGE_Communications_Queue;
struct RGE_Lobby;
struct RGE_TimeSinceLastCall;
struct RGE_Communications_Speed;
struct RGE_Communications_Synchronize;
struct RGE_Communications_Addresses;
struct RGE_Comm_Error;
struct RESENDER;
struct HOLDER;
struct IDirectPlay3;
#pragma pack(push, 1)
struct COMMPLAYEROPTIONS {
    // Source of truth: all_types_ground_truth.h :: COMMPLAYEROPTIONS (Size: 0x1D0)
    uchar NeedsToBeSent;               // +0x0000
    uchar _pad_0[3];                   // +0x0001
    ulong LastSentTime;                // +0x0004
    int ProgramState;                  // +0x0008 (COMMSTATES)
    ulong CurrentTurn;                 // +0x000C
    uchar TurnSpeedMsec;               // +0x0010
    uchar _pad_1[3];                   // +0x0011
    ulong dcoID[10];                   // +0x0014
    ulong AcknowledgeAfterMsec;        // +0x003C
    uchar CommandTurnIncrement;        // +0x0040
    uchar _pad_2[3];                   // +0x0041
    int PlayerReady[10];               // +0x0044
    ulong User1[10];                   // +0x006C
    ulong User2[10];                   // +0x0094
    ulong User3[10];                   // +0x00BC
    ulong User4[10];                   // +0x00E4
    ulong User5[10];                   // +0x010C
    ulong User6[10];                   // +0x0134
    ulong User7[10];                   // +0x015C
    int Humanity[10];                  // +0x0184 (PLAYERHUMANITY)
    uchar InvalidPlayer[10];           // +0x01AC
    uchar _pad_3[2];                   // +0x01B6
    ulong Initialized;                 // +0x01B8
    ulong RandomSeed;                  // +0x01BC
    ushort HighPlayerNumber;           // +0x01C0
    ushort LowPlayerNumber;            // +0x01C2
    uint HostPlayerNumber;             // +0x01C4
    int GameHasStarted;                // +0x01C8
    ulong DataSizeToFollow;            // +0x01CC
};

#pragma pack(pop)

#pragma pack(push, 4)
class TCommunications_Handler {
public:
    TCommunications_Handler(void* host_hwnd, uchar max_game_players);
    ~TCommunications_Handler();

    int IsPaused();
    int IsHost();
    int AllPlayersReady();
    int TogglePauseGame();
    void RequestPauseGame(int p1);
    void RequestResumeGame(int p1);
    void LocalPauseGame(uint p1);
    void LocalResumeGame(uint p1);
    void SendPauseGame(int p1);
    int MultiplayerGameStart();
    int IsLobbyLaunched();
    void Update();
    void HandleMessage();
    void UpdatePlayers();
    void UpdatePlayer(uint id, int timeout);
    void NotifyWindow(int message);
    void NotifyWindowParam(int message, long param);
    long SendSharedData(int send_mode);
    long EnableNewPlayers(void* direct_play, int enable_links);
    int IsPlayerHuman(uint player_number);
    int GetPlayerHumanity(uint player_number);
    int IsPlayerOutOfSync(uint player_number, ulong comm_turn);
    void SetPlayerHumanity(uint player_number, int humanity);
    char* GetPlayerName(uint player_number);
    void SetPlayerName(uint player_number, char* name);
    uint GetRandomSeed();
    uint WhoAmI();
    void* SetWindowHandle(void* window_handle);
    void LaunchMultiplayerGame();
    void ReceiveGameMessages();
    void LastWorldRandom(int param_1);
    int DoCycle(ulong now);
    void EvaluateSystemMessage(ulong p1, char* p2, ulong p3, ulong p4);
    uint ExecuteIncoming();
    void GetDPLAYMessages();
    void SendIResignMsg();
    void ShutdownGameMessages();
    int CountWaitingMessages();
    void GameOver();
    COMMSTATUS GetCommunicationsStatus();
    COMMSTATUS AnalyzeCommunicationsStatus();
    COMMSTATUS UnlinkCurrentLevel();
    COMMSTATUS UnlinkToLevel(COMMSTATUS level);
    void ClearAllSerialNumbers();
    int Kick(uint player_number);
    void DropAllHostedPlayers();
    void ReleaseSettings();
    long CloseSession();
    long ReleaseComm();
    long DestroyMyPlayer();
    void FreeOptions();
    void* get_command();
    uchar new_command(void* p1, int p2);
    int NewCommand(void* p1, int p2, int p3);
    int AddCommand(ulong p1, void* p2, ulong p3, int p4, uchar p5, int p6);
    long CommOut(uchar p1, void* p2, long p3, ulong p4);
    void DropDeadPlayer(uint id, ulong turn);
    void CalculatePlayerRange();
    void ClearRXandTX();
    void PackPlayersDown();
    void SetSelfPlayer();
    void InitPlayerInformation(uint player_number, ulong dpid, char* friendly_name, char* formal_name);
    void ResetLastCommunicationTimes();
    void CheckPingTime(int p1);
    void SendGroupChatMsg(char* param_1);
    void SendChatMsgAll(char* param_1);
    void SendChatMsg(uint param_1, uint param_2, char* param_3);
    long TXChat(uint param_1, uchar* param_2, char* param_3);
    void SendStoredMessages();
    int PreprocessMessages(ulong p1, char* p2, ulong p3, ulong p4, int p5);

    // DirectPlay helper used by session/service primitives.
    IDirectPlay3* GetDPInterface();

    // Used by RGE_Communications_Speed / RGE_Communications_Synchronize.
    void SendSpeedChange(uint buffer_frames, uint buffer_granularity);
    int AllPlayersAcknowledged();
    long SendChecksumMessage(ulong world_time, uint random, long cs2, long cs3, long cs4, long cs5, long ping_initiated);

    // BEGIN Task 222 decomp gap declarations
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00425780
    char* WaitingOnNamedInfo(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00425800
    char* WaitingOnInfo(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x004258E0
    void StopIfSyncFail(int param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00425910
    void ShowSyncChatMsgs(int param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00425930
    void DropPacketsIntentionally(int param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00425960
    void SetStepMode(int param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00425970
    void SetSpeedControl(int param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00425A20
    void Step(int param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00426350
    void KillAnyMissingPlayers(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00426D40
    int HasKicked(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00426D50
    long SendPlayerName(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00426DC0
    void LogRXMsg(uint param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00427390
    int TXPing(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00427440
    int TXDebugPing(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x004274B0
    long FastSend(ulong param_2, void* param_3, ulong param_4, int param_5, int param_6);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x004282C0
    int EvaluatePlayerMessage(ulong param_2, uint param_3, ulong param_4, uchar param_5, uchar param_6, char* param_7, uint param_8, ulong param_9, ulong param_10);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x004286F0
    void SetPlayerStopTurn(uint param_2, ulong param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00428710
    void CheckPlayerStopTurn(ulong param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x004289A0
    int TEST(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x00429BD0
    ulong HiTurnAcknowledged(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A060
    void ClearRXForPlayer(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A130
    void ClearTXForPlayer(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A160
    void ClearRXTXForPlayer(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A180
    int StoreIncoming(uint param_2, char* param_3, uint param_4, ulong param_5, ulong param_6);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A330
    int StoreForResend(uint param_2, char* param_3, uint param_4, uint* param_5);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A540
    int TXAcknowledgeMessage(uint param_2, uint param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A650
    int RXAcknowledgeStoredMessage(uint param_2, uint param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042A6E0
    int PurgeAcknowledgedStoredMessages(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042AD10
    int TXResendReply(uint param_2, uint param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042B0A0
    int TXResendRequest(uint param_2, uint param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042B200
    uchar GetNextSequence(ulong param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042B860
    void DestroyMultiplayerGame(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042CA20
    void SetRandomSeed(int param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042CB20
    char* GetCommStateStr(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042CB30
    char* GetReadyPlayerStr(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042CC90
    int GetActivePlayerCount(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042CD10
    int IsPlayerComputer(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042CD50
    char* GetCommInfo(uchar param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D120
    void UpdatePlayerInformation(ulong param_2, char* param_3, char* param_4);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D180
    int LaunchLobbyGame(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D3B0
    int SetGameTitle(char* param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D3E0
    void SetMyPlayerName(char* param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D4A0
    long CreateDirectPlayConversation(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D580
    int OpenMultiplayerConnection(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D590
    int CreateMultiplayerGame(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042D960
    int AddSelfPlayer(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042DA50
    long InitJoinGame(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042DA80
    int JoinMultiplayerGame(_GUID* param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042DD70
    long GetMyMultiPlayerCaps(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042DEA0
    void SetApplicationGUID(_GUID param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042DEE0
    void SetServiceGUID(_GUID param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042DF10
    void SetSessionGUID(_GUID param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042E380
    int SetMyReadiness(int param_2, ulong param_3, ulong param_4, ulong param_5, ulong param_6, ulong param_7, ulong param_8, ulong param_9);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042E500
    int GetClientReadiness(uint param_2, int* param_3, ulong* param_4, ulong* param_5, ulong* param_6, ulong* param_7, ulong* param_8, ulong* param_9, ulong* param_10);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042E580
    int IsPlayerReady(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042E5B0
    int ComputerPlayerGameStart(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042E670
    long DPlayGetSessionDesc(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042E730
    long CommGetCaps(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042EB60
    int SetMyGameOptions(char* param_2, ulong param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042EBF0
    void* GetMyGameOptions(ulong* param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042ECC0
    void SetHostPlayerNumber(uint param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042ECD0
    uint GetHostPlayerNumber(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042ECE0
    void DebugSessionInformation(DPSESSIONDESC2* param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042EF60
    void OutOfSync(int param_2, ulong param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042EF80
    int SendZoneMessage(char* param_2, ulong param_3);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042F110
    void ForcePlayerEnumeration(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042F140
    void ForcePlayerDestroyAndCreate(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042F190
    void ForceNameChange(void);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042F230
    void SetSpeedV1(ulong param_2);
    // TODO: Source of truth: com_hand.cpp.decomp @ 0x0042F250
    void SetSpeedV2(ulong param_2);
    // END Task 222 decomp gap declarations

    int OptionsChanged;
    char* OptionsData;
    int Steps;
    ulong TickStart;
    ulong TickCount;
    ulong TimeSinceLastCall;
    TChat* Chat;
    int MeHost;
    int HaveHostInit;
    char InCommBuff[4001];
    char TBuff[257];
    ulong current_turn;
    ulong next_command_turn;
    uint sequence;
    long WaitOnPlayer;
    ulong TurnSpeedMsec;
    ulong AcknowledgeAfterMsec;
    uint Me;
    int Multiplayer;
    int OutOfSyncFlag;
    ulong dwStopTime;
    float lastRXDataRate;
    float lastTXDataRate;
    char MyFriendlyName[129];
    char MyFormalName[129];
    char MyGameTitle[129];
    ulong CurrentPlayers;
    int previous_last_world_random;
    int last_world_random;
    int StepMode;
    ulong turnstart;
    ulong lastcalltick;
    ulong mselapsed;
    int AvgTurnTime;
    int SkipFrames;
    int PauseChangePending;
    ulong CommunicationsVersionCode;
    int ShuttingDown;
    ulong ReturnElapsed;
    ulong ReturnRXPacketSize;
    ulong ReturnTXPacketSize;
    ulong RXPacketLength;
    ulong RXPacketLengthHigh;
    ulong TXPacketLength;
    ulong TXPacketLengthHigh;
    NAME* FriendlyName;
    NAME* FormalName;
    ulong LastTimeoutMessageTime;
    COMMSTATUS CommunicationsStatus;
    ushort MaxGamePlayers;
    _GUID ServiceGUID;
    _GUID ApplicationGUID;
    _GUID SessionGUID;
    void* HostHWND;
    int LobbyLaunched;
    ulong MaxReceiveLatency;
    _GUID NullGUID;
    ulong ResendAcknowledgements;
    ulong ResentToOther;
    ulong DroppedPacketCount;
    ulong RXPackets;
    ulong TXPackets;
    int IAmLagging;
    ulong ServiceTimeout;
    ulong LastPlayerCommunication[10];
    ulong LastPlayerWarning[10];
    ulong LastTXPing[10];
    ulong PlayerStopTurn[10];
    uint LastSerialRequestedTX[10];
    ulong LastRequestHonoredTX[10];
    uint LastSerialRepliedTX[10];
    ulong LastRequestRepliedTX[10];
    ulong dwFlags;
    ulong dwMaxBufferSize;
    ulong dwMaxQueueSize;
    ulong dwMaxPlayers;
    ulong dwHundredBaud;
    ulong dwLatency;
    int Kicked[10];
    RGE_Communications_Queue* InQ;
    RGE_Communications_Queue* OutQ;
    RGE_Lobby* Lobby;
    RGE_TimeSinceLastCall* tslc;
    RGE_Communications_Speed* Speed;
    RGE_Communications_Synchronize* Sync;
    RGE_Communications_Addresses* Addresses;
    RGE_Comm_Error* Err;
    uint GTDSerialNo;
    uint HighResendStore;
    uint DestMap[10];
    uchar RGE_Guaranteed_Delivery;
    int IntentionallyDropPackets;
    uint WaitingForAck;
    RESENDER* Resend;
    HOLDER* OnHold;
    uint PlayerHighSerialNumber[10];
    COMMPLAYEROPTIONS PlayerOptions;
    ulong LastTurnAck[10];
    uint HoldCount;
    int WasKicked[10];
};
#pragma pack(pop)
static_assert(sizeof(TCommunications_Handler) == 0x1774, "Size mismatch");
