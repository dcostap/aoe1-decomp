#ifndef AOE1_COM_HAND_H
#define AOE1_COM_HAND_H

#include <windows.h>
#include <stddef.h>
#include "com_types.h"

// Declarations recovered from the Com_hand.cpp PDB.
// TCommunications_Handler has no base class or virtual source members.
// Its PDB UDT size is 0x1774.  The method order below follows the UDT order.
// The PDB changes access from public to protected at TXPing.

class TChat;
class TCommunications_Handler;
class RGE_Communications_Queue;
class RGE_Comm_Error;
class RGE_Lobby;
class RGE_TimeSinceLastCall;
class RGE_Communications_Speed;
class RGE_Communications_Synchronize;
class RGE_Communications_Addresses;
class RGE_Prog_Info;
struct IDirectPlay2;
struct IDirectPlay3;
struct IDirectPlay4A;
struct DPSESSIONDESC2;
struct GUID_LOCAL;

struct COMMPLAYEROPTIONS {
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

class NAME {
public:
    char Text[128];
};

typedef char comm_hand_name_size_check[(sizeof(NAME) == 0x80) ? 1 : -1];

class RESENDER {
public:
    unsigned long TimeSent;
    unsigned int Serial;
    char* ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];

    RESENDER();
    ~RESENDER();
    void Store(char* message, unsigned int length);
    void Clear();
};

typedef char comm_hand_resender_size_check[
    (sizeof(RESENDER) == 0x38) ? 1 : -1];

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
    void Store(char* message, unsigned int length);
    void Clear();
};

typedef char comm_hand_holder_size_check[
    (sizeof(HOLDER) == 0x18) ? 1 : -1];

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
    _GUID ServiceGUID;
    _GUID ApplicationGUID;
    _GUID SessionGUID;
    void* HostHWND;
    int LobbyLaunched;
    unsigned long MaxReceiveLatency;
    _GUID NullGUID;
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
    unsigned int LastSerialRequestedTX[10];
    unsigned long LastRequestHonoredTX[10];
    unsigned int LastSerialRepliedTX[10];
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

    TCommunications_Handler(void* host_hwnd, unsigned char max_game_players,
                            TChat* chat, _GUID application_guid);
    ~TCommunications_Handler();

    int RXAcknowledgeStoredMessage(unsigned int serial, unsigned int player);
    int TXAcknowledgeMessage(unsigned int serial, unsigned int player);
    unsigned int CheckResendStoredMessages();
    int SendStoredMessages();
    int StoreForResend(unsigned int serial, char* message,
                       unsigned int length, unsigned int* dest_map);
    unsigned char GetNextSequence(unsigned long turn);
    int TXResendRequest(unsigned int serial, unsigned int player);
    int TXResendReply(unsigned int serial, unsigned int player);
    int StoreIncoming(unsigned int serial, char* message, unsigned int length,
                      unsigned long from, unsigned long receive);
    unsigned int ExecuteIncoming();
    int PurgeAcknowledgedStoredMessages();
    int IsPaused();
    void RequestPauseGame(int player);
    void RequestResumeGame(int player);
    int TogglePauseGame();
    void ForceSpeedControl(COMMSPEEDS speed, COMMSPEEDS frames);
    void SetSpeedControl(int value);
    void SendSpeedRequest(COMMSPEEDS speed);
    void SendSpeedChange(unsigned int frames, unsigned int granularity);
    void SetSpeedV1(unsigned long value);
    void SetSpeedV2(unsigned long value);
    void CheckPingTime(int value);
    long FastSend(unsigned long to, void* data, unsigned long size,
                  int value, int flags);
    void Step(int amount);
    void StopIfSyncFail(int value);
    void SetStepMode(int value);
    void DebugSessionInformation(DPSESSIONDESC2* desc);
    void DropPacketsIntentionally(int value);
    void OutOfSync(int value, unsigned long turn);
    void ForcePlayerEnumeration();
    void ForcePlayerDestroyAndCreate();
    void ForceNameChange();
    int OpenMultiplayerConnection();
    int CreateMultiplayerGame();
    int JoinMultiplayerGame(GUID_LOCAL* guid);
    long InitJoinGame();
    void LaunchMultiplayerGame();
    void SendJoinMsg();
    void SetPlayerHumanity(unsigned int player, PLAYERHUMANITY humanity);
    void SetRandomSeed(int value);
    void SetPlayerName(unsigned int player, char* name);
    void SetMyPlayerName(char* name);
    int SetGameTitle(char* title);
    int IsLobbyLaunched();
    int LaunchLobbyGame();
    int SendZoneMessage(char* data, unsigned long size);
    int MultiplayerGameStart();
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ClearPlayerStopTurn();
    _GUID GetServiceGUID();
    _GUID GetApplicationGUID();
    void SetServiceGUID(_GUID guid);
    void SetApplicationGUID(_GUID guid);
    void* SetWindowHandle(void* window_handle);
    void SetSessionGUID(_GUID guid);
    int ComputerPlayerGameStart();
    int SetMyGameOptions(char* data, unsigned long size);
    void* GetMyGameOptions(unsigned long* size);
    int SetMyReadiness(int ready, unsigned long user1, unsigned long user2,
                       unsigned long user3, unsigned long user4,
                       unsigned long user5, unsigned long user6,
                       unsigned long user7);
    int GetClientReadiness(unsigned int player, int* ready,
                           unsigned long* user1, unsigned long* user2,
                           unsigned long* user3, unsigned long* user4,
                           unsigned long* user5, unsigned long* user6,
                           unsigned long* user7);
    int IsPlayerReady(unsigned int player);
    int AllPlayersReady();
    void SendReadiness();
    long SendSharedData(int value);
    void DestroyMultiplayerGame();
    void ReleaseSettings();
    COMMSTATUS UnlinkCurrentLevel();
    COMMSTATUS GetCommunicationsStatus();
    COMMSTATUS UnlinkToLevel(COMMSTATUS level);
    COMMSTATUS AnalyzeCommunicationsStatus();
    void GameOver();
    void DropDeadPlayer(unsigned int player, unsigned long turn);
    void DropAllHostedPlayers();
    void ResetLastCommunicationTimes();
    void UpdatePlayerInformation(unsigned long player_id, char* name,
                                 char* formal_name);
    void SendGroupChatMsg(char* message);
    void SendChatMsg(unsigned int player, unsigned int to, char* text);
    void SendChatMsgAll(char* message);
    long TXChat(unsigned int player, unsigned char* dest_map, char* text);
    void UpdatePlayers();
    void UpdatePlayer(unsigned int player, int timeout);
    void LastWorldRandom(int value);
    int Kick(unsigned int player);
    void SendIResignMsg();
    void GetDPLAYMessages();
    unsigned char new_command(void* command, int size);
    int NewCommand(void* command, int size, int ordered);
    void* get_command();
    int DoCycle(unsigned long now);
    void ReceiveGameMessages();
    void ShutdownGameMessages();
    IDirectPlay3* GetDPInterface();
    void AllowPlayerJoins(int value);
    void NotifyWindow(COMMMESSAGES message);
    void NotifyWindowParam(COMMMESSAGES message, long param);
    long SendChecksumMessage(unsigned long world_time, unsigned int random,
                             long cs1, long cs2, long cs3, long cs4, long cs5);
    long CommResendAll(unsigned long serial, unsigned long player);
    unsigned int GetRandomSeed();
    unsigned long GetPlayerTurn(unsigned int player);
    unsigned long GetSyncTurn();
    char* GetCommStateStr();
    char* GetPlayerName(unsigned int player);
    char* GetReadyPlayerStr();
    int GetPlayerHumanity(unsigned int player);
    int IsPlayerHuman(unsigned int player);
    int IsPlayerComputer(unsigned int player);
    int GetActivePlayerCount();
    int WhoAmI();
    int host();
    int IsHost();
    unsigned int GetHostPlayerNumber();
    unsigned int GetPlayerNumber(unsigned long dco_id);
    int AllPlayersAcknowledged();
    unsigned long HiTurnAcknowledged();
    int CountWaitingMessages();
    unsigned long GetPlayerAvgFramesMsec(unsigned int player);
    unsigned long GetPlayerHighLatencyMsec(unsigned int player);
    unsigned long GetPlayerLatency(unsigned int player);
    int IsPlayerOutOfSync(unsigned int player, unsigned long turn);
    int HasKicked(unsigned int player);
    char* GetCommInfo(unsigned char index);
    void ShowSyncChatMsgs(int value);
    char* WaitingOnNamedInfo(unsigned int player);
    char* WaitingOnInfo(unsigned int player);
    int TXDebugPing();

protected:
    int TXPing(unsigned int player);
    int GetWasKicked(unsigned int player);
    unsigned long GetCurrentTurn();
    unsigned long GetRXPacketSize();
    unsigned long GetTXPacketSize();
    void ResetAll();
    int AddSelfPlayer();
    void SetSelfPlayer();
    unsigned int GetNextNewPlayer();
    void SetHostPlayerNumber(unsigned int player);
    int CalculatePlayerRange();
    long SendPlayerName();
    long CommGetCaps();
    long DPlayGetSessionDesc();
    long CreateDirectPlayConversation();
    void InitializePlayers();
    void InitPlayerInformation(unsigned int player, unsigned long dpid,
                               char* friendly_name, char* formal_name);
    void PackPlayersDown();
    long CloseSession();
    long DestroyMyPlayer();
    long ReleaseComm();
    long GetMyMultiPlayerCaps();
    int SetPlayerReadiness(unsigned int player, int ready);
    void FreeOptions();
    void ClearPlayersAcknowledged();
    long EnableNewPlayers(IDirectPlay2* direct_play, int enable);
    void SetPlayerStopTurn(unsigned int player, unsigned long turn);
    void CheckPlayerStopTurn(unsigned long turn);
    void SendPauseGame(int value);
    void LocalPauseGame(unsigned int player);
    void LocalResumeGame(unsigned int player);
    void SendSyncMsg(long value);
    void SendLatentMsg();
    void SendEchoMsg();
    void TEST();
    void LogRXMsg(unsigned int player, unsigned int serial,
                  unsigned long turn, unsigned char type,
                  unsigned char flags);
    long CommOut(unsigned long to, unsigned char type, void* data,
                 int length, unsigned char flags);
    int EvaluatePlayerMessage(unsigned long size, unsigned int player,
                              unsigned long from, unsigned char opcode,
                              unsigned char flags, char* data,
                              unsigned int length, unsigned long arg1,
                              unsigned long arg2);
    void EvaluateSystemMessage(unsigned long size, char* data,
                               unsigned long from, unsigned long to);
    void CommResend(unsigned long serial, unsigned long player,
                    unsigned char type);
    void EvaluateGuaranteedAcknowledge(unsigned long serial,
                                       unsigned int player,
                                       unsigned long turn,
                                       unsigned char type);
    int IsMessageWaiting();
    int PreprocessMessages(unsigned long size, char* data,
                           unsigned long from, unsigned long to,
                           int cached);
    void ClearRXForPlayer(unsigned int player);
    void ClearTXForPlayer(unsigned int player);
    void ClearRXTXForPlayer(unsigned int player);
    void KillAnyMissingPlayers();
    int AddCommand(unsigned long turn, void* data, unsigned long size,
                   int from, unsigned char sequence, int control);
    long SendAllDoneMsg(unsigned long turn);
};

typedef char comm_hand_size_check[
    (sizeof(TCommunications_Handler) == 0x1774) ? 1 : -1];
typedef char comm_hand_current_turn_offset_check[
    (offsetof(TCommunications_Handler, current_turn) == 0x10C8) ? 1 : -1];
typedef char comm_hand_options_offset_check[
    (offsetof(TCommunications_Handler, PlayerOptions) == 0x1550) ? 1 : -1];

#endif
