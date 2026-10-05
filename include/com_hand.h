#ifndef AOE1_COM_HAND_H
#define AOE1_COM_HAND_H

#include <windows.h>
#include "com_types.h"
#include "../third_party/directplay/include/dplay.h"

// C++ globals used by the communications resend paths.
extern int resend_adj1;
extern int resend_adj2;

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
    RESENDER() {
        this->TimeSent = 0;
        this->ResendMsg = 0;
        this->Serial = 0;
        this->Length = 0;
        ZeroMemory(this->DestMap, sizeof(this->DestMap));
    }
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
    unsigned short Reserved;
    unsigned long User1;
    unsigned long User2;
    unsigned long User3;
    unsigned long User4;
    unsigned long User5;
    unsigned long User6;
    unsigned long User7;
    unsigned long CommunicationsVersionCode;
    unsigned char RGEGuaranteed;
    unsigned char Reserved25[3];
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

typedef char comm_hand_options_size_check[(sizeof(COMMPLAYEROPTIONS) == 0x1D0) ? 1 : -1];

class TCommunications_Handler {
    // com_spd.cpp reads these two source-owned fields in AnalyzeGameSpeed and
    // AdjustLocalSpeed.  Keep that original cross-class access narrow.
    friend class RGE_Communications_Speed;
    friend class TRIBE_World;
    friend class TCommunications_Sessions;
    friend class TribeMPCreateDialog;
    friend class TRIBE_Screen_Game;
    friend int __stdcall EnumPlayersCallback2(unsigned long, unsigned long, DPNAME*, unsigned long, void*);

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
    TCommunications_Handler(void* WinHandle, unsigned char MaxPlayers, TChat* ChatHandle, GUID AppGuid);
    ~TCommunications_Handler();
    void GameOver();
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ResetLastCommunicationTimes();
    void StopIfSyncFail(int b);
    void DropPacketsIntentionally(int b);

    void DestroyMultiplayerGame();

  protected:
    long ReleaseComm();
    void FreeOptions();

  public:
    char* GetCommInfo(unsigned char LineNum);
    void ReceiveGameMessages();
    void ShutdownGameMessages();
    void GetDPLAYMessages();
    char* GetPlayerName(unsigned int PlayerNo);
    int AllPlayersAcknowledged();
    void CheckPingTime(int Forced);
    void SendChatMsgAll(char* Text);
    int Kick(unsigned int PlayerNo);
    void UpdatePlayers();

    int IsPlayerHuman(unsigned int PlayerNo);
    int IsPlayerComputer(unsigned int PlayerNo);
    int GetPlayerHumanity(unsigned int PlayerNo);
    int IsLobbyLaunched();

  protected:
    long CloseSession();
    long CommOut(unsigned long To, unsigned char MsgType, void* Msg, int Length, unsigned char ResendSeq);
    void KillAnyMissingPlayers();
    void InitPlayerInformation(unsigned int PlayerNo, unsigned long dpID, char* FrName, char* FoName);
    void CheckPlayerStopTurn(unsigned long Turn);
    void EvaluateSystemMessage(unsigned long type, char* CommBuff, unsigned long dcoFromID, unsigned long dcoReceiveID);
    int PreprocessMessages(
        unsigned long dwSize, char* CommBuff, unsigned long dcoFromID, unsigned long dcoReceiveID, int fromHold
    );

  public:
    void DropDeadPlayer(unsigned int PlayerNo, unsigned long PlayerDPID);
    void NotifyWindowParam(COMMMESSAGES msg, long lparam);

  protected:
    int AddCommand(
        unsigned long ExecuteOnTurn, void* command, unsigned long nBytes, int PFrom, unsigned char Sequence,
        int ControlCommand
    );

  public:
    int NewCommand(void* Command, int Size, int ControlCommand);
    int DoCycle(unsigned long WorldTime);
    char* WaitingOnNamedInfo(unsigned int PlayerNo);
    char* WaitingOnInfo(unsigned int PlayerNo);
    void ShowSyncChatMsgs(int b);
    void SetStepMode(int b);
    void SetSpeedControl(int b);

  protected:
    int CalculatePlayerRange(void);

  public:
    void Step(int Numsteps);
    void* get_command(void);
    unsigned char new_command(void* Command, int Size);
    void LastWorldRandom(int lwr);
    int HasKicked(unsigned int p);

  protected:
    long SendPlayerName();
    void LogRXMsg(
        unsigned int Serialno, unsigned int fromPlayer, unsigned long ExecuteOnTurn, unsigned char Command,
        unsigned char Sequence
    );

  public:
    int GetWasKicked(unsigned int player);
    unsigned long GetCurrentTurn();
    unsigned long GetRXPacketSize();
    unsigned long GetTXPacketSize();

  protected:
    int TXPing(unsigned int ToPlayer);

  public:
    int TXDebugPing(void);
    long FastSend(unsigned long ToDPID, void* Buffer, unsigned long BuffLen, int Priority, int Guaranteed);
    void NotifyWindow(COMMMESSAGES msg);

  protected:
    int EvaluatePlayerMessage(
        unsigned long len, unsigned int fromPlayer, unsigned long ExecuteOnTurn, unsigned char Command,
        unsigned char Sequence, char* Content, unsigned int ContentSize, unsigned long dcoFromID,
        unsigned long dcoReceiveID
    );
    void SetPlayerStopTurn(unsigned int player, unsigned long Turn);

  public:
    void ReleaseSettings();
    long SendSharedData(int SendImmediately);

  protected:
    int TEST();

  public:
  protected:
    void SetSelfPlayer();

  public:
    void SendGroupChatMsg(char* Text);
    void SendChatMsg(unsigned int GamerID, unsigned int DestPlayerNo, char* Text);
    void SendIResignMsg();
    long TXChat(unsigned int GamerID, unsigned char* DestMap, char* Text);
    void SendSpeedChange(unsigned int Frames, unsigned int Granularity);
    unsigned long HiTurnAcknowledged();
    long SendChecksumMessage(
        unsigned long worldtime, unsigned int random, long csum1, long csum2, long csum3, long csum4, long csum5
    );
    uint ExecuteIncoming();

  protected:
    void ClearRXForPlayer(unsigned int player);
    void ClearRXTXForPlayer(unsigned int PlayerNo);
    void ClearTXForPlayer(unsigned int PlayerNo);

  public:
    int CountWaitingMessages();
    int StoreIncoming(uint SerialNumber, char* InBuff, uint Length, ulong dcoFromID, ulong dcoReceiveID);
    int StoreForResend(unsigned int SerialNumber, char* OutCommBuff, unsigned int Length, unsigned int* ResendDestMap);
    int TXAcknowledgeMessage(uint serialno, uint fromPlayer);
    int RXAcknowledgeStoredMessage(unsigned int serialno, unsigned int fromPlayer);
    int PurgeAcknowledgedStoredMessages();
    int SendStoredMessages();
    int TXResendReply(uint serial, uint toPlayer);
    int TXResendRequest(unsigned int serial, unsigned int toPlayer);
    unsigned char GetNextSequence(unsigned long value);
    COMMSTATUS GetCommunicationsStatus();
    COMMSTATUS UnlinkCurrentLevel();
    COMMSTATUS UnlinkToLevel(COMMSTATUS lvl);
    COMMSTATUS AnalyzeCommunicationsStatus(void);
    void DropAllHostedPlayers(void);

  protected:
    void LocalResumeGame(unsigned int p);
    void LocalPauseGame(unsigned int p);
    void SendPauseGame(int Pause);

  public:
    int TogglePauseGame();
    void RequestPauseGame(int SendChatInfo);
    void RequestResumeGame(int SendChatInfo);
    void SetRandomSeed(int val);
    unsigned int GetRandomSeed();
    int WhoAmI();
    int IsHost(void);
    char* GetCommStateStr();
    char* GetReadyPlayerStr();
    void SetPlayerHumanity(unsigned int PlayerNo, PLAYERHUMANITY Type);
    int GetActivePlayerCount();
    void UpdatePlayerInformation(unsigned long dpID, char* AFriendlyName, char* AFormalName);
    int LaunchLobbyGame();
    void SetMyPlayerName(char* Name);
    void SetPlayerName(unsigned int PlayerNo, char* Name);
    void* SetWindowHandle(void* hwnd);

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
    int JoinMultiplayerGame(_GUID* GameGuid);
    void LaunchMultiplayerGame();
    long InitJoinGame();
    int IsPlayerReady(unsigned int PlayerNo);
    int ComputerPlayerGameStart();
    int MultiplayerGameStart();

  protected:
    long GetMyMultiPlayerCaps();

  public:
    void SetApplicationGUID(_GUID guid);
    IDirectPlay3* GetDPInterface();
    void SetServiceGUID(_GUID inGuid);
    void SetSessionGUID(_GUID inGuid);
    void UpdatePlayer(unsigned int PlayerNo, int Notify);
    int SetMyReadiness(
        int Ready, ulong User1, ulong User2, ulong User3, ulong User4, ulong User5, ulong User6, ulong User7
    );
    int GetClientReadiness(
        unsigned int PlayerNo, int* Ready, unsigned long* User1, unsigned long* User2, unsigned long* User3,
        unsigned long* User4, unsigned long* User5, unsigned long* User6, unsigned long* User7
    );
    int AllPlayersReady();

  protected:
    long DPlayGetSessionDesc();
    HRESULT CommGetCaps();
    long DestroyMyPlayer();

  public:
    int SetMyGameOptions(char* vpData, unsigned long dwSize);
    void* GetMyGameOptions(unsigned long* dwSize);

  protected:
    void SetHostPlayerNumber(unsigned int PlayerNo);

  public:
    unsigned int GetHostPlayerNumber();
    void DebugSessionInformation(DPSESSIONDESC2* dpsd);

  protected:
    long EnableNewPlayers(IDirectPlay2* lpDP2, int bEnable);

  public:
    void OutOfSync(int Status, unsigned long StopTime);
    int SendZoneMessage(char* Data, unsigned long dwSize);
    void ForcePlayerDestroyAndCreate();
    void ForcePlayerEnumeration();
    int SetGameTitle(char* Game);
    void ForceNameChange(void);
    void SetSpeedV1(unsigned long v1);
    void SetSpeedV2(unsigned long v2);
    int IsPlayerOutOfSync(unsigned int pnum, unsigned long worldturn);
    int IsPaused();
};

typedef char comm_hand_size_check[(sizeof(TCommunications_Handler) == 0x1774) ? 1 : -1];

#endif
