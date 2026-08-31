#ifndef AOE1_COM_HAND_H
#define AOE1_COM_HAND_H

#include <windows.h>
#include "com_types.h"
#include "../third_party/directplay/include/dplay.h"

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;
struct IDirectPlay2;
struct IDirectPlay3;
struct _GUID;


class TChat;
class TCommunications_Handler;
class RGE_Communications_Queue;
class RGE_Comm_Error;
class RGE_Base_Game;
class RGE_Lobby;
class RGE_Communications_Speed;
class RGE_Communications_Synchronize;
class RGE_Communications_Addresses;
class RGE_TimeSinceLastCall;
struct RGE_Prog_Info;
class TCommunications_Sessions;
class TribeMPCreateDialog;
class TRIBE_Screen_Game;
class TRIBE_World;

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

struct MSGFORMAT_ONTURN {
    unsigned long ExecuteOnTurn;
};

struct MSGFORMAT_SPEEDCHANGE {
    unsigned short BufferFrames;
    unsigned short FrameSizeMsec;
};

struct MSGFORMAT_ACKNOWLEDGE_GUARANTEED {
    unsigned char Command;
    unsigned int Serialno;
};

struct MSGFORMAT_LATENCY {
    unsigned char Command;
    unsigned long Initiated;
    unsigned long CurrentTurn;
};

struct MSGFORMAT_ALL_DONE {
    unsigned char Command;
    unsigned long ExecuteOnTurn;
    unsigned char HighLatencyCenti;
    unsigned char FrameRateMsec;
};

struct MSGFORMAT_SETREADYOPTIONS {
    unsigned char Command;
    unsigned char Ready;
    unsigned long User1;
    unsigned long User2;
    unsigned long User3;
    unsigned long User4;
    unsigned long User5;
    unsigned long User6;
    unsigned long User7;
    unsigned long Reserved20;
    unsigned long CommunicationsVersionCode;
};

struct MSGFORMAT_CHAT {
    unsigned char FromGamerID;
    unsigned char DestPlayers[10];
    unsigned long TextSize;
    unsigned char Pregame;
    char ChatMsg[256];
};

struct MSGFORMAT_CHECKSUM {
    unsigned long WorldTime;
    unsigned long WorldTurn;
    unsigned int Random;
    long cs1;
    long cs2;
    long cs3;
    long cs4;
    long cs5;
    unsigned long PingInitiated;
};

struct MSGFORMAT_MISSING_PLAYER {
    unsigned char Command;
    unsigned int PlayerID;
};

struct MSGFORMAT_RESEND {
    unsigned char Command;
    unsigned int Serialno;
};

struct MSGFORMAT_HEADER_GUARANTEED {
    unsigned char Command;
    unsigned char Sequence;
    unsigned long ExecuteOnTurn;
    unsigned long Serialno;
};

struct MSGFORMAT_KILL_PLAYER {
    unsigned int PlayerNo;
    unsigned long dcoID;
    unsigned long CurrentTurn;
};

struct COMMPLAYEROPTIONS {
public:
    unsigned char NeedsToBeSent;
    unsigned long LastSentTime;
    COMMSTATES ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    int PlayerReady[10];
    unsigned long User1[10];
    unsigned long User2[10];
    unsigned long User3[10];
    unsigned long User4[10];
    unsigned long User5[10];
    unsigned long User6[10];
    unsigned long User7[10];
    PLAYERHUMANITY Humanity[10];
    unsigned char InvalidPlayer[10];
    unsigned long Initialized;
    unsigned long RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned long DataSizeToFollow;
};

typedef char comm_hand_options_size_check[
    (sizeof(COMMPLAYEROPTIONS) == 0x1D0) ? 1 : -1];

class TCommunications_Handler {
    // com_spd.cpp reads these two source-owned fields in AnalyzeGameSpeed and
    // AdjustLocalSpeed.  Keep that original cross-class access narrow.
    friend class RGE_Communications_Speed;
    friend class TRIBE_World;
    friend class TCommunications_Sessions;
    friend class TribeMPCreateDialog;
    friend class TRIBE_Screen_Game;
    friend int __stdcall EnumPlayersCallback2(unsigned long, unsigned long,
                                              DPNAME*, unsigned long, void*);
protected:
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

private:
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
    int IntentionallyDropPackets;
    unsigned int WaitingForAck;
    RESENDER* Resend;
    HOLDER* OnHold;
    unsigned int PlayerHighSerialNumber[10];
    COMMPLAYEROPTIONS PlayerOptions;
    unsigned long LastTurnAck[10];
    unsigned int HoldCount;
    int WasKicked[10];

public:
    TCommunications_Handler(void* hwnd, unsigned char maxPlayers,
                            TChat* chat, GUID appGUID);
    ~TCommunications_Handler();
    void GameOver();
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ResetLastCommunicationTimes();
    void StopIfSyncFail(int flag);
    void DropPacketsIntentionally(int flag);

    void DestroyMultiplayerGame();
protected:
    long ReleaseComm();
    void FreeOptions();
public:
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
    int GetPlayerHumanity(unsigned int player);
    int IsLobbyLaunched();
protected:
    long CloseSession();
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
protected:
    int AddCommand(unsigned long a, void* b, unsigned long c, int d,
                   unsigned char e, int f);
public:
    int NewCommand(void* command, int size, int ordered);
    int DoCycle(unsigned long param_1);
    char* WaitingOnNamedInfo(unsigned int playerIndex);
    char* WaitingOnInfo(unsigned int param_1);
    void ShowSyncChatMsgs(int param);
    void SetStepMode(int v);
    void SetSpeedControl(int param);
protected:
    int CalculatePlayerRange(void);
public:
    void Step(int amount);
    void* get_command(void);
    unsigned char new_command(void* command, int size);
    void LastWorldRandom(int param);
    int HasKicked(unsigned int idx);
protected:
    long SendPlayerName();
    void LogRXMsg(unsigned int param_1, unsigned int param_2, unsigned long param_3, unsigned char param_4, unsigned char param_5);
public:
    int GetWasKicked(unsigned int player);
    unsigned long GetCurrentTurn();
    unsigned long GetRXPacketSize();
    unsigned long GetTXPacketSize();
protected:
    int TXPing(unsigned int param_1);
public:
    int TXDebugPing(void);
    long FastSend(unsigned long to, void* data, unsigned long size, int param_4, int param_5);
    void NotifyWindow(COMMMESSAGES message);
protected:
    int EvaluatePlayerMessage(unsigned long a1, unsigned int player, unsigned long a3, unsigned char opcode, unsigned char p5, char* data, unsigned int p7, unsigned long p8, unsigned long p9);
    void SetPlayerStopTurn(unsigned int i, unsigned long v);
public:
    void ReleaseSettings();
    long SendSharedData(int force);
protected:
    int TEST();
public:
protected:
    void SetSelfPlayer();
public:
    void SendGroupChatMsg(char* param_1);
    void SendChatMsg(unsigned int player, unsigned int to, char* text);
    void SendIResignMsg();
    long TXChat(unsigned int player, unsigned char* destMap, char* text);
    void SendSpeedChange(unsigned int param_1, unsigned int param_2);
    unsigned long HiTurnAcknowledged();
    long SendChecksumMessage(unsigned long param_1, unsigned int param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    uint ExecuteIncoming();
protected:
    void ClearRXForPlayer(unsigned int player);
    void ClearRXTXForPlayer(unsigned int player);
    void ClearTXForPlayer(unsigned int player);
public:
    int CountWaitingMessages();
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
    COMMSTATUS AnalyzeCommunicationsStatus(void);
    void DropAllHostedPlayers(void);
protected:
    void LocalResumeGame(unsigned int player);
    void LocalPauseGame(unsigned int player);
    void SendPauseGame(int param_1);
public:
    int TogglePauseGame();
    void RequestPauseGame(int);
    void RequestResumeGame(int);
    void SetRandomSeed(int seed);
    unsigned int GetRandomSeed();
    int WhoAmI();
    int IsHost(void);
    char* GetCommStateStr();
    char* GetReadyPlayerStr();
    void SetPlayerHumanity(unsigned int player, PLAYERHUMANITY humanity);
    int GetActivePlayerCount();
    void UpdatePlayerInformation(unsigned long player_id, char* name, char* formal_name);
    int LaunchLobbyGame();
    void SetMyPlayerName(char* name);
    void SetPlayerName(unsigned int player, char* name);
    void* SetWindowHandle(void* v);
protected:
    long CreateDirectPlayConversation();
public:
    int OpenMultiplayerConnection();
    int CreateMultiplayerGame(void);
protected:
    void PackPlayersDown();
public:
protected:
    int AddSelfPlayer();
public:
    int JoinMultiplayerGame(_GUID* guid);
    void LaunchMultiplayerGame();
    long InitJoinGame();
    int IsPlayerReady(unsigned int player);
    int ComputerPlayerGameStart();
    int MultiplayerGameStart();
protected:
    long GetMyMultiPlayerCaps();
public:
    void SetApplicationGUID(_GUID guid);
    IDirectPlay3* GetDPInterface();
    void SetServiceGUID(_GUID guid);
    void SetSessionGUID(_GUID guid);
    void UpdatePlayer(unsigned int player, int do_update);
    int SetMyReadiness(int ready, ulong user1, ulong user2, ulong user3, ulong user4, ulong user5, ulong user6, ulong user7);
    int GetClientReadiness(unsigned int index, int* out0, unsigned long* out1, unsigned long* out2, unsigned long* out3, unsigned long* out4, unsigned long* out5, unsigned long* out6, unsigned long* out7);
    int AllPlayersReady();
protected:
    long DPlayGetSessionDesc();
    HRESULT CommGetCaps();
    long DestroyMyPlayer();
public:
    int SetMyGameOptions(char* param_1, unsigned long param_2);
    void* GetMyGameOptions(unsigned long* param);
protected:
    void SetHostPlayerNumber(unsigned int v);
public:
    unsigned int GetHostPlayerNumber();
    void DebugSessionInformation(DPSESSIONDESC2* desc);
protected:
    long EnableNewPlayers(IDirectPlay2* dp, int enable);
public:
    void OutOfSync(int a, unsigned long b);
    int SendZoneMessage(char* msg, unsigned long param_2);
    void ForcePlayerDestroyAndCreate();
    void ForcePlayerEnumeration();
    int SetGameTitle(char* title);
    void ForceNameChange(void);
    void SetSpeedV1(unsigned long param);
    void SetSpeedV2(unsigned long param);
    int IsPlayerOutOfSync(unsigned int player, unsigned long turn);
    int IsPaused();


};

typedef char comm_hand_size_check[
    (sizeof(TCommunications_Handler) == 0x1774) ? 1 : -1];

#endif
