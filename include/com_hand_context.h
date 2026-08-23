#ifndef AOE1_COM_HAND_CONTEXT_H
#define AOE1_COM_HAND_CONTEXT_H

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

struct GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

enum COMMSTATUS {
    UNINITIALIZED = 0,
    INITIALIZED = 1
};

enum COMMSTATES {
    COMM_STATE_JOINNOW = 3
};

enum COMMMESSAGES {
    COMMMESSAGE_SYNC_ERROR = 0x17B0,
    COMMMESSAGE_PLAYER_NOT_RESPONDING = 0x17BD,
    COMMMESSAGE_PLAYER_DROPPED = 0x17B2
};

class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog* log, const char* format, ...);
    void Log(char* format, ...);
    void FlushToDisk(int param_1);
    void Time();
};

extern TDebuggingLog* L;
void Log(TDebuggingLog* log, const char* format, ...);
void Log(void* log, const char* format, ...);
extern "C" unsigned long debug_timeGetTime(char* file, int line);

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
    unsigned char GetNextSequence(unsigned long value);
};

class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;
    RGE_Comm_Error(void* hwnd);
    ~RGE_Comm_Error();
    void ShowReturn(long code, char* context);
};

struct TRIBE_World {
    void send_zone_score_info();
};

struct RGE_Base_Game {
    char gap[0x3F0];
    TRIBE_World* world;
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void language(int id, char* text, int length);
};

class IDirectPlay4A {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual long __stdcall GetMessageCount(unsigned long id, unsigned long* count);
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60();
    virtual long __stdcall Receive(unsigned long* from, unsigned long* to,
                                   unsigned long flags, void* data,
                                   unsigned long* size);
};

extern IDirectPlay4A* DAT_0062c5ec;
extern unsigned long DAT_0062cf04;

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
    unsigned int BufferFramesRemaining();
    unsigned int BufferTimeToUse(unsigned long turn);
    unsigned int WaitingOnAcknowledgement();
    void ReloadBufferFrames();
    int AnalyzeGameSpeed(unsigned int* out_gran, unsigned int* out_frames,
                         int param3);
    unsigned int GetBufferGranularityAdjusted();
    void Skip();
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
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ResetLastCommunicationTimes();

    void DestroyMultiplayerGame();
    long CloseSession();
    long ReleaseComm();
    void FreeOptions();
    char* GetCommInfo(unsigned char index);
    void ReceiveGameMessages();
    void GetDPLAYMessages();
    char* GetPlayerName(unsigned int player);
    int AllPlayersAcknowledged();
    void CheckPingTime(int param);
    void SendChatMsgAll(char* msg);
    int Kick(unsigned int player);
    void UpdatePlayers();

    int IsPlayerHuman(unsigned int player);
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
    int AddCommand(int a, int b, int c, int d, unsigned char e, int f);
    int NewCommand(void* command, int size, int ordered);
    int DoCycle(unsigned long param_1);
};
#pragma pack(pop)

#endif
