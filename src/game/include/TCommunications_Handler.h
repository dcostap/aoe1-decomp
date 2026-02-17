#include <windows.h>
#include "common.h"

enum COMMSTATUS {
    COMM_NONE = 0,
    COMM_IDLE = 1,
    COMM_ACTIVE = 2,
    // ... more values based on ASM
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
    char data[464]; // Adjusted size
};

#pragma pack(pop)

#pragma pack(push, 4)
class TCommunications_Handler {
public:
    int IsPaused();
    void TogglePauseGame();
    int MultiplayerGameStart();
    int IsLobbyLaunched();
    void Update();
    void HandleMessage();
    void UpdatePlayers();
    void UpdatePlayer(uint id, int timeout);
    void NotifyWindow(int message);
    long SendSharedData(int send_mode);
    int GetPlayerHumanity(uint player_number);
    void SetPlayerHumanity(uint player_number, int humanity);
    char* GetPlayerName(uint player_number);
    void SetPlayerName(uint player_number, char* name);
    uint GetRandomSeed();
    uint WhoAmI();
    void ReceiveGameMessages();
    int DoCycle(ulong now);
    void EvaluateSystemMessage(ulong p1, char* p2, ulong p3, ulong p4);
    uint ExecuteIncoming();
    void GetDPLAYMessages();
    void SendIResignMsg();
    void ShutdownGameMessages();
    int CountWaitingMessages();
    void GameOver();
    COMMSTATUS UnlinkToLevel(COMMSTATUS level);
    uchar new_command(void* p1, int p2);
    long CommOut(uchar p1, void* p2, long p3, ulong p4);
    void DropDeadPlayer(uint id, ulong turn);
    void CheckPingTime(int p1);
    void SendStoredMessages();
    int PreprocessMessages(void* p1, ulong p2, void* p3, ulong p4);
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
