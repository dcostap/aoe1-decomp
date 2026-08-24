#ifndef AOE1_COM_HAND_CONTEXT_H
#define AOE1_COM_HAND_CONTEXT_H

#include <windows.h>

#ifndef COM_HAND_CONTEXT_SCALAR_ALIASES
#define COM_HAND_CONTEXT_SCALAR_ALIASES
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;
typedef long HRESULT;
struct GUID_LOCAL;
struct _GUID;
struct DPSESSIONDESC2;
struct IDirectPlay2;
#endif

// Canonical Com_hand.cpp context for six grouped owners.
// Evidence: exact 00425A40, 00426350, and 00426530, plus behavior-reviewed
// 004261E0, 00426650, and 00426FC0. The constructor anchor uses Com_hand.cpp
// lines 268-332 with /GX.
// The original FPO/PDB symbol proves protected CommOut(unsigned long,
// unsigned char, void*, int, unsigned char):
// ?CommOut@TCommunications_Handler@@IAEJKEPAXHE@Z.
// The field offsets follow the executable and the exact constructor source.

class TChat;
class TCommunications_Handler;
class RGE_Communications_Addresses;
class RGE_TimeSinceLastCall;
class RGE_Prog_Info;

typedef int COMMSTATUS;
enum {
    UNINITIALIZED = 0,
    INITIALIZED = 1,
    SINGLE_PLAYER = 2,
    MULTIPLAYER_RESET = 3,
    CONVERSATION_OPEN = 4,
    SERVICE_AVAILABLE = 5,
    SESSION_AVAILABLE = 6,
    SESSION_HOSTED = 7,
    COMMSTATUS_UNKNOWN = 8,
    PLAYER_CREATED = 9,
    COMM_SETTINGS_EXCHANGED = 10,
    GAME_PLAYER_SET = 11,
    GAME_OPTIONS_EXCHANGED = 12,
    GAME_IS_LOADING = 13,
    GAME_IS_RUNNING = 14,
    GAME_IS_PAUSED = 15
};

typedef int COMMSTATES;
enum {
    COMM_STATE_JOINNOW = 3,
    COMM_STATE_PAUSE = 4,
    COMM_STATE_RUNNING = 5
};

enum PLAYERHUMANITY {
    ME_ABSENT = 0,
    ME_CLOSED = 1,
    ME_HUMAN = 2,
    ME_ELIMINATED = 3,
    ME_COMPUTER = 4,
    ME_CYBORG = 5,
    ME_VIEWONLY = 6
};

enum COMMMESSAGES {
    COMM_UPDATE_PLAYERS = 0x17A4,
    COMM_PLAYER_KICKED = 0x17AA,
    COMM_PLAYER_SERVICE_ERROR = 0x17B7,
    COMMMESSAGE_SYNC_ERROR = 0x17B0,
    COMMMESSAGE_PLAYER_NOT_RESPONDING = 0x17BD,
    COMMMESSAGE_PLAYER_DROPPED = 0x17B2,
    COMM_OTHER_PLAYER_DROPPED = 0x17B3
};

extern unsigned char DAT_0062c5d0;
extern unsigned long DAT_0062cef0;
extern unsigned long DAT_0062cf14;
extern unsigned long DAT_0062cf18;
extern const char s_Com_hand_cpp[];

class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog* log, const char* format, ...);
    void Log(char* format, ...);
    void Log(const char* format, ...);
    void FlushToDisk(int param_1);
    void FlushLog();
    void Time();
};

extern TDebuggingLog* L;
extern TDebuggingLog* com_hand_global_log;
extern TDebuggingLog* debugging_log;
extern TDebuggingLog* L_global;
extern TDebuggingLog* g_pDebugLog;
extern long g_DAT_0062c5ec;
void Log(TDebuggingLog* log, const char* format, ...);
void Log(void* log, const char* format, ...);
void Log(int log, const char* format, ...);
extern "C" unsigned long debug_timeGetTime(const char* file, int line);

class NAME {
public:
    char Text[128];
};

class RESENDER {
public:
    unsigned int TimeSent;
    unsigned int Serial;
    char* ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];
    RESENDER();
    ~RESENDER();
};

class HOLDER {
public:
    char* HoldMsg;
    unsigned int Serial;
    unsigned int Length;
    unsigned long dcoFromID;
    unsigned long dcoReceiveID;
    unsigned int fromPlayer;
    HOLDER();
    ~HOLDER();
};

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[255];
    unsigned char _pad_10B;
    unsigned long LastCurrentTurn;
    unsigned char Sequence;
    unsigned char _pad_111[3];
    void* Queue;
    RGE_Communications_Queue(int maxQSize);
    ~RGE_Communications_Queue();
    void FlushAll();
    void FlushForPlayer(unsigned int player);
    void AddItem(void* item);
    void* GetNextItemSingle();
    void* GetNextItemOrdered();
    void* GetNextItemOrdered(unsigned long turn);
    unsigned char GetNextSequence(unsigned long value);
};

class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;
    RGE_Comm_Error(void* hwnd);
    ~RGE_Comm_Error();
    void ShowReturn(long code, char* context);
    void ShowReturn(long code, const char* context);
    void log(long code, const char* context);
};

struct TRIBE_World {
    void send_zone_score_info();
};

struct RGE_Base_Game {
    char gap[0x3F0];
    TRIBE_World* world;
    char _pad_shutdown[0xEB4];
    int field_12A8;
    unsigned long random_game_seed;
    int field_1558;
    void* ptr;
    RGE_Prog_Info* prog_info;
    // RGE_Base_Game's first virtual slots are known from its reviewed class
    // layout.  Keep the real names and signatures so calls use the canonical
    // get_string slot instead of a synthetic vtable surface.
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* param_1, unsigned int param_2,
                          unsigned int param_3, long param_4);
    virtual void set_prog_mode(int param_1);
    virtual void set_game_mode(int param_1, int param_2);
    virtual void set_player(short param_1);
    virtual int get_error_code();
    virtual char* get_string(long param_1, char* param_2, int param_3);
    virtual char* get_string(int param_1, long param_2, char* param_3,
                             int param_4);
    void ShutdownGameMessages();
    int IsPaused();
    int IsLobbyLaunched();
};

class IDirectPlay4A {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual long __stdcall v44(int id, void* count);
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60();
    virtual long __stdcall Send(unsigned long from, unsigned long to,
                                unsigned long flags, void* data,
                                unsigned long size);
    virtual long __stdcall Receive(unsigned long* from, unsigned long* to,
                                   unsigned long flags, void* data,
                                   unsigned long* size);
    long __stdcall GetMessageCount(unsigned long id, unsigned long* count);
    long __stdcall SetPlayerName(unsigned long player, void* name, unsigned long flags);
    long __stdcall Open(void* a, void* b, unsigned long c);
    long __stdcall Open(void* desc, unsigned long flags);
};

extern IDirectPlay4A* DAT_0062c5ec;
extern unsigned long DAT_0062cf04;
extern RGE_Base_Game* rge_base_game;

struct IDirectPlayVtbl {
    long (__stdcall* QueryInterface)(void*, const GUID*, void**);
    long (__stdcall* AddRef)(void*);
    long (__stdcall* Release)(void*);
    long (__stdcall* GetPlayerName)(void*, unsigned long, void*, void*);
    long (__stdcall* CreatePlayer)(void*, unsigned long*, void*, void*,
                                   unsigned long, unsigned long, void*);
    long (__stdcall* destroyMyPlayer)(void*);
};

struct IDirectPlay {
    IDirectPlayVtbl* vtbl;
};

struct DirectPlay;
struct DirectPlayVtbl {
    char gap_00[0x24];
    long (__stdcall* destroyMyPlayer)(DirectPlay* self, int playerId);
    long (__stdcall* Send)(void* self, unsigned long from, unsigned long to,
                           unsigned long flags, void* data, unsigned long size);
};
struct DirectPlay {
    DirectPlayVtbl* lpVtbl;
};

struct DPVtbl {
    long (__stdcall *QueryInterface)(void*, const _GUID*, void**);
    void* f04;
    long (__stdcall *Steps)(void*);
    void* f0c; void* f10; void* f14; void* f18; void* f1c;
    void* f20; void* f24;
    long (__stdcall *EnableNewPlayers)(void*, int);
    long (__stdcall *Send)(void*, unsigned long, unsigned long, int, void*, unsigned int);
    long (__stdcall *SetPlayerName)(void*, unsigned long, void*, unsigned long);
};
struct IDirectPlay2 {
    DPVtbl* vtbl;
    long Send(unsigned long from, unsigned long to, unsigned long flags,
              void* data, unsigned long size);
    long SetPlayerName(unsigned long player, void* name, unsigned long flags);
};

struct DPCAPS {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwMaxBufferSize;
    unsigned long dwMaxQueueSize;
    unsigned long dwMaxPlayers;
    unsigned long dwHundredBaud;
    unsigned long dwLatency;
    unsigned long dwMaxLocalPlayers;
    unsigned long dwHeaderLength;
    unsigned long dwTimeout;
    unsigned long dwMaxLatency;
    unsigned long dwMinThroughput;
    unsigned long dwMaxThroughput;
};

struct DPSESSIONDESC2 {
    unsigned long dwSize;
    unsigned long guidInstance_Data1;
    unsigned long dwFlags;
    GUID guidInstance;
    GUID guidApplication;
    unsigned long dwMaxPlayers;
    unsigned long dwCurrentPlayers;
    char* lpszSessionNameA;
    void* lpszSessionNameW;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
    void* lpUser1;
    void* lpUser2;
    void* lpUser3;
    void* lpUser4;
    unsigned long one;
    const unsigned short* title;
};

class RGE_Lobby {
public:
    void* HostHWND;
    void* glpDPL;
    void* glpDPL2;
    void* glpDP;
    void* glpdplConnection;
    unsigned char lobby_game;
    unsigned char _pad_15[3];
    RGE_Comm_Error* Err;
    RGE_Lobby(void* hwnd);
    ~RGE_Lobby();
    int CheckForLobbyLaunch();
    int CheckForLobbyLaunch(void** out);
    int GetSessionInfo(void* desc);
    int GetSessionInfo(char* desc);
    int GetPlayerInfo(unsigned int player, void* info);
    int GetPlayerInfo(char** info);
    int IsThisHost();
    long SendZoneMessage(const char* msg, unsigned long param, void* zone_guid);
};

class RGE_Communications_Speed {
public:
    char TBuff[255];
    unsigned char _pad_FF;
    void* TurnTSLC;
    void* FrameTSLC;
    TCommunications_Handler* Comm;
    unsigned char _pad_10C[4];
    double AccumDiff;
    int SpeedControlEnabled;
    unsigned int CurrentBufferFrames;
    unsigned int FutureBufferFrames;
    unsigned int TotalBufferFramesRemaining;
    unsigned int TargetTurnLengthMsec;
    unsigned int CurrentBufferGranularity;
    unsigned int FutureBufferGranularity;
    unsigned int OverheadFactor;
    unsigned long TimeSinceLastBuffer;
    unsigned long FutureSpeedChangeTurn;
    unsigned long NextLatencyChangeTurn;
    unsigned int ActualLatency[10];
    unsigned int AverageTSLC[10];
    unsigned char PlayerOptimalFrames[10];
    unsigned char PlayerOptimalGranularity[10];
    unsigned short RequestFasterOrSlower[10];
    unsigned long PlayerAvgFramesMsec[10];
    unsigned long PlayerHighLatencyMsec[10];
    unsigned long HighestLatencyMsec;
    unsigned int SkipFrames;
    unsigned int OptimalBufferFrames;
    unsigned int OptimalBufferGranularity;
    unsigned int DiffOffset;
    unsigned int AllAcknowledgedBuffersRemaining;
    unsigned int LastAdjusted;
    unsigned long RealTimePassed;
    unsigned long BufferTimePassed;
    unsigned int DroppedFrames;
    unsigned int DroppedFramesTurn;
    unsigned long AdjustmentCount;
    int LastFrameHadTime;
    RGE_Communications_Speed(TCommunications_Handler* comm);
    ~RGE_Communications_Speed();
    unsigned char GetHighLatencyCenti();
    unsigned int GetAvgFrameRate();
    void SetPlayerTurnSpeed(unsigned int player, unsigned char avgframe,
                            unsigned char centi);
    void SetFutureSpeedChange(unsigned int speed, unsigned int frames,
                              unsigned long turn);
    void SetActualLatency(unsigned int player, unsigned int latency);
    unsigned int BufferFramesRemaining();
    unsigned int BufferTimeToUse(unsigned long turn);
    unsigned int WaitingOnAcknowledgement();
    void ReloadBufferFrames();
    int AnalyzeGameSpeed(unsigned int* out_gran, unsigned int* out_frames,
                         int param3);
    unsigned int GetBufferGranularityAdjusted();
    void Skip();
    int GetLatencyInfo();
    int GetMachineSpeedInfo();
    unsigned long GetAdjustmentCount();
    char* GetSelfPlayerOptimalSpeedStr();
    char* GetPlayerSpeedStatusStr(unsigned int player);
};

class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm;
    unsigned long CheckTime;
    unsigned long CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;
    int LastResult;
    unsigned int Offset;
    int DoChecksums;
    unsigned long LastWorldRandom;
    unsigned long GameWorldChecksum;
    char Check[55 * 0x24];
    RGE_Communications_Synchronize(TCommunications_Handler* comm);
    ~RGE_Communications_Synchronize();
    unsigned long DoChecksum(unsigned long turn);
    void Add(unsigned int player, unsigned long a, unsigned long b,
             unsigned long c, long d, long e, long f, long g, long h);
    void LogChecksums(long a, long b, long c, long d, long e, long f,
                      long g, long h, long i);
    void target(int param);
    void target(int a, int b);
};

#pragma pack(push, 1)
class COMMPLAYEROPTIONS {
public:
    unsigned char NeedsToBeSent;
    unsigned char _pad_0[3];
    unsigned long LastSentTime;
    COMMSTATES ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned char _pad_1[3];
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    unsigned char _pad_2[3];
    int PlayerReady[10];
    unsigned long User1[10];
    unsigned long User2[10];
    unsigned long User3[10];
    unsigned long User4[10];
    unsigned long User5[10];
    unsigned long User6[10];
    unsigned long User7[10];
    int Humanity[10];
    unsigned char InvalidPlayer[10];
    unsigned char _pad_3[2];
    unsigned long Initialized;
    unsigned long RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned long DataSizeToFollow;
};
#pragma pack(pop)

#pragma pack(push, 4)
class TCommunications_Handler {
public:
    int OptionsChanged;
    char* OptionsData;
    int Steps;
    unsigned long TickStart;
    unsigned long TickCount;
    unsigned long TimeSinceLastCall;
    TChat* Chat;
    int MeHost;
    int HaveHostInit;
    char InCommBuff[4001];
    char TBuff[257];
    unsigned char _pad_10C6[2];
    unsigned long current_turn;
    unsigned long next_command_turn;
    unsigned int sequence;
    long WaitOnPlayer;
    unsigned long TurnSpeedMsec;
    unsigned long AcknowledgeAfterMsec;
    unsigned int Me;
    int Multiplayer;
    int OutOfSyncFlag;
    unsigned long dwStopTime;
    float lastRXDataRate;
    float lastTXDataRate;
    char MyFriendlyName[129];
    char MyFormalName[129];
    char MyGameTitle[129];
    unsigned char _pad_127B;
    unsigned long CurrentPlayers;
    int previous_last_world_random;
    int last_world_random;
    int StepMode;
    unsigned long turnstart;
    unsigned long lastcalltick;
    unsigned long mselapsed;
    int AvgTurnTime;
    int SkipFrames;
    int PauseChangePending;
    unsigned long CommunicationsVersionCode;
    int ShuttingDown;
    unsigned long ReturnElapsed;
    unsigned long ReturnRXPacketSize;
    unsigned long ReturnTXPacketSize;
    unsigned long RXPacketLength;
    unsigned long RXPacketLengthHigh;
    unsigned long TXPacketLength;
    unsigned long TXPacketLengthHigh;
    NAME* FriendlyName;
    NAME* FormalName;
    unsigned long LastTimeoutMessageTime;
    COMMSTATUS CommunicationsStatus;
    unsigned short MaxGamePlayers;
    unsigned char _pad_12DA[2];
    GUID ServiceGUID;
    GUID ApplicationGUID;
    GUID SessionGUID;
    void* HostHWND;
    int LobbyLaunched;
    unsigned long MaxReceiveLatency;
    GUID NullGUID;
    unsigned long ResendAcknowledgements;
    unsigned long ResentToOther;
    unsigned long DroppedPacketCount;
    unsigned long RXPackets;
    unsigned long TXPackets;
    int IAmLagging;
    unsigned long ServiceTimeout;
    unsigned long LastPlayerCommunication[10];
    unsigned long LastPlayerWarning[10];
    unsigned long LastTXPing[10];
    unsigned long PlayerStopTurn[10];
    unsigned long LastSerialRequestedTX[10];
    unsigned long LastRequestHonoredTX[10];
    unsigned long LastSerialRepliedTX[10];
    unsigned long LastRequestRepliedTX[10];
    unsigned long dwFlags;
    unsigned long dwMaxBufferSize;
    unsigned long dwMaxQueueSize;
    unsigned long dwMaxPlayers;
    unsigned long dwHundredBaud;
    unsigned long dwLatency;
    int Kicked[10];
    RGE_Communications_Queue* InQ;
    RGE_Communications_Queue* OutQ;
    RGE_Lobby* Lobby;
    RGE_TimeSinceLastCall* tslc;
    RGE_Communications_Speed* Speed;
    RGE_Communications_Synchronize* Sync;
    RGE_Communications_Addresses* Addresses;
    RGE_Comm_Error* Err;
    unsigned int GTDSerialNo;
    unsigned int HighResendStore;
    unsigned int DestMap[10];
    unsigned char RGE_Guaranteed_Delivery;
    unsigned char _pad_1515[3];
    int IntentionallyDropPackets;
    unsigned int WaitingForAck;
    RESENDER* Resend;
    HOLDER* OnHold;
    unsigned int PlayerHighSerialNumber[10];
    COMMPLAYEROPTIONS PlayerOptions;
    unsigned long LastTurnAck[10];
    unsigned int HoldCount;
    int WasKicked[10];

    TCommunications_Handler(void* hwnd, unsigned char maxPlayers,
                            TChat* chat, GUID appGUID);
    ~TCommunications_Handler();
    void GameOver();
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ResetLastCommunicationTimes();

    void DestroyMultiplayerGame();
    long CloseSession();
    long ReleaseComm();
    void FreeOptions();
    char* GetCommInfo(unsigned char index);
    void ReceiveGameMessages();
    void ShutdownGameMessages();
    void GetDPLAYMessages();
    char* GetPlayerName(unsigned int player);
    int AllPlayersAcknowledged();
    void CheckPingTime(int param);
    void SendChatMsgAll(char* msg);
    int Kick(unsigned int player);
    void UpdatePlayers();

    int IsPlayerHuman(unsigned int player);
    int IsPlayerComputer(unsigned int player);
    void target_func(int p0, int p1);
protected:
    long CommOut(unsigned long to, unsigned char type, void* data,
                 int length, unsigned char flags);
    void KillAnyMissingPlayers();
    void InitPlayerInformation(unsigned int player, unsigned long param_2,
                               char* param_3, char* param_4);
    void CheckPlayerStopTurn(unsigned long turn);
    void EvaluateSystemMessage(unsigned long size, char* msg,
                               unsigned long from, unsigned long to);
    int PreprocessMessages(unsigned long size, char* msg,
                           unsigned long from, unsigned long to, int cached);
public:
    void DropDeadPlayer(unsigned int player, unsigned long dcoID);
    void NotifyWindowParam(COMMMESSAGES msg, long param);
    void NotifyWindowParam(int msg, long param);
    int AddCommand(int a, int b, int c, int d, unsigned char e, int f);
    int AddCommand(unsigned long a, void* b, unsigned long c, int d,
                   unsigned char e, int f);
    int NewCommand(void* command, int size, int ordered);
    int DoCycle(unsigned long param_1);
    // Module-local declarations for the complete PDB method sequence.
    char* WaitingOnNamedInfo(int playerIndex);
    char* WaitingOnInfo(unsigned int param_1);
    void ShowSyncChatMsgs(int param);
    void SetStepMode(int v);
    void SetSpeedControl(int param);
    int CalculatePlayerRange(void);
    void Step(int amount);
    void* get_command(void);
    unsigned char new_command(void* command, int size);
    void LastWorldRandom(int param);
    int HasKicked(int idx);
    long SendPlayerName();
    void LogRXMsg(unsigned int param_1, unsigned int param_2, unsigned long param_3, unsigned char param_4, unsigned char param_5);
    int TXPing(unsigned int param_1);
    int TXDebugPing(void);
    long FastSend(unsigned long to, void* data, unsigned long size, int param_4, int param_5);
    void NotifyWindow(int p);
    int EvaluatePlayerMessage(unsigned long a1, unsigned int player, unsigned long a3, unsigned char opcode, unsigned char p5, char* data, unsigned int p7, unsigned long p8, unsigned long p9);
    void SetPlayerStopTurn(int i, int v);
    void ReleaseSettings();
    long SendSharedData(int force);
    int TEST();
    void SetSelfPlayer();
    void SendGroupChatMsg(char* param_1);
    void SendChatMsg(unsigned int player, unsigned int to, const char* text);
    long TXChat(unsigned int player, unsigned char* destMap, char* text);
    long TXChat(unsigned int player, char* destMap, char* text);
    long TXChat(unsigned int player, const unsigned char* destMap,
                const char* text);
    void SendSpeedChange(unsigned int param_1, unsigned int param_2);
    unsigned long HiTurnAcknowledged();
    long SendChecksumMessage(unsigned long param_1, unsigned int param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    uint ExecuteIncoming();
    void ClearRXForPlayer(unsigned int player);
    void ClearTXForPlayer(unsigned int player);
    int CountWaitingMessages();
    void ClearRXTXForPlayer(unsigned int player);
    int StoreIncoming(uint SerialNumber, char* InBuff, uint Length, ulong dcoFromID, ulong dcoReceiveID);
    int StoreForResend(unsigned int param_1, char* param_2, unsigned int param_3, unsigned int* param_4);
    int TXAcknowledgeMessage(uint param_1, uint param_2);
    int RXAcknowledgeStoredMessage(unsigned int param_1, unsigned int param_2);
    int PurgeAcknowledgedStoredMessages();
    int SendStoredMessages();
    int TXResendReply(uint serial, uint player);
    int TXResendRequest(unsigned int serial, unsigned int player);
    unsigned char GetNextSequence(unsigned long value);
    COMMSTATUS GetCommunicationsStatus();
    COMMSTATUS UnlinkCurrentLevel();
    COMMSTATUS UnlinkToLevel(COMMSTATUS param_1);
    int AnalyzeCommunicationsStatus(void);
    void DropAllHostedPlayers(void);
    void LocalResumeGame(unsigned int player);
    void LocalPauseGame(unsigned int player);
    void SendPauseGame(int param_1);
    int TogglePauseGame();
    void RequestPauseGame(int);
    void RequestResumeGame(int);
    void SetRandomSeed(int seed);
    unsigned long GetRandomSeed();
    int WhoAmI();
    int IsHost(void);
    int GetCommStateStr();
    char* GetReadyPlayerStr();
    void SetPlayerHumanity(unsigned int player, int humanity);
    int GetActivePlayerCount();
    void UpdatePlayerInformation(unsigned long player_id, char* name, char* formal_name);
    int LaunchLobbyGame();
    void SetMyPlayerName(char* name);
    void SetPlayerName(unsigned int player, char* name);
    void SetWindowHandle(int v);
    long CreateDirectPlayConversation();
    int OpenMultiplayerConnection();
    int CreateMultiplayerGame(void);
    void PackPlayersDown();
    int AddSelfPlayer();
    int JoinMultiplayerGame(GUID_LOCAL* guid);
    void LaunchMultiplayerGame();
    long GetMyMultiPlayerCaps();
    void SetApplicationGUID(_GUID guid);
    int GetDPInterface();
    void SetServiceGUID(_GUID guid);
    void SetSessionGUID(_GUID guid);
    void UpdatePlayer(unsigned int player, int do_update);
    int SetMyReadiness(int ready, ulong user1, ulong user2, ulong user3, ulong user4, ulong user5, ulong user6, ulong user7);
    int GetClientReadiness(unsigned int index, int* out0, unsigned long* out1, unsigned long* out2, unsigned long* out3, unsigned long* out4, unsigned long* out5, unsigned long* out6, unsigned long* out7);
    int AllPlayersReady();
    long DPlayGetSessionDesc();
    HRESULT CommGetCaps();
    long DestroyMyPlayer();
    int SetMyGameOptions(char* param_1, unsigned long param_2);
    void* GetMyGameOptions(unsigned long* param);
    void SetHostPlayerNumber(int v);
    int GetHostPlayerNumber();
    void DebugSessionInformation(DPSESSIONDESC2* desc);
    void DebugSessionInformation(void* desc);
    long EnableNewPlayers(IDirectPlay2* dp, int enable);
    long EnableNewPlayers(int dp, int enable);
    void OutOfSync(int a, int b);
    int SendZoneMessage(const char* msg, unsigned long param_2);
    void ForcePlayerDestroyAndCreate();
    void AddPlayer(long a, long b, char* c, char* d);
    void sub_00429F80();
    void sub_00429FD0();
    void sub_0042C7A0();
    void ForceNameChange(void);
    void SetSpeedV1(int param);
    void SetSpeedV2(int param);
    void IsPlayerOutOfSync(int a, int b);
    int IsPaused();


};
#pragma pack(pop)

#endif
