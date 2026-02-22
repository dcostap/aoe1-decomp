#include <windows.h>
#include "common.h"

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
    void SetPlayerHumanity(uint player_number, int humanity);
    char* GetPlayerName(uint player_number);
    void SetPlayerName(uint player_number, char* name);
    uint GetRandomSeed();
    uint WhoAmI();
    void* SetWindowHandle(void* window_handle);
    void LaunchMultiplayerGame();
    void ReceiveGameMessages();
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
