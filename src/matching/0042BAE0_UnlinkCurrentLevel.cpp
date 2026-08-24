// TCommunications_Handler::UnlinkCurrentLevel
// VA: 0042BAE0, Com_hand.cpp:4474-4661 (2736 bytes, /GX EH frame)
// FLAGS: config/flags/0042BAE0_UnlinkCurrentLevel.rsp (/GX for the two new expressions)
// Status: MATCH (exact, 0.0000% diff, 71/71 ordered calls) — ready for promotion.
//
// Attempt log (sa-f1926d8e, 2026-08-06):
// baseline: canonical reconstruction from packet/Ghidra + matched siblings
// (0042B860 DestroyMultiplayerGame init block, 00428B10 DropDeadPlayer Log/InitPlayerInformation
// conventions). Big switch on CommunicationsStatus; cases 2/3 share the huge reset block
// (debug_timeGetTime + zero stores + strcpy names + player loop + queue flushes + Kicked loop).
// Cases 6/7 do delete/new of Speed/Sync (EH state 0/1 and 2/3) and GUID copy.
// 1. baseline (/GX): 939B diff; structure right, but delete blocks reloaded Speed/Sync
//    (ecx for test + eax for delete) adding 18B in the case-6/7 region; +84B total incl.
//    trailing jump-table data. Fix: explicit `RGE_Communications_Speed* speed = this->Speed`
//    temps (per 00406010 lesson) keep the pointer in one callee-saved register. -> 19B diff.
// 2. class sizes: RGE_Communications_Speed/Synchronize have no vptr, so gaps must be full
//    0x240 / 0x7EC (the -4 was wrong) to emit operator new(0x240)/new(0x7EC). -> 0 diff.
// 3. case SESSION_HOSTED: Chat->ClearChat() must come AFTER NeedsToBeSent/LastSentTime
//    stores (source order; VC5 hoists the Chat load) to match the binary store/call order.
// 4. Kicked loop: natural indexed `for (i2...) { LastPlayerWarning[i2]=0; Kicked[i2]=0;
//    WasKicked[i2]=0; }` (no volatile) is exact; volatile raw-pointer form from the
//    DestroyMultiplayerGame sibling was not needed here. Kept the natural form.
// The big reset block source shape (debug_timeGetTime before the zero stores, strcpy order
// MyGameTitle/MyFriendlyName/MyFormalName, clear_13c0[9] pointer loop -> rep stosd, do/while
// InitPlayerInformation loop with `i <= MaxGamePlayers`) mirrors the exact 0042B860 sibling.

#include <string.h>

#if !defined(COM_HAND_TU_CONTEXT)
enum COMMSTATUS {
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
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
enum { COMM_STATE_JOINNOW = 3 };
enum { ME_HUMAN = 2 };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    void Log(char* format, ...);
    void Time();
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned long debug_timeGetTime(const char* file, int line);
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062cf04;
#endif // COM_HAND_TU_CONTEXT

class TCommunications_Handler;

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Speed {
public:
    RGE_Communications_Speed(TCommunications_Handler* handler);
    ~RGE_Communications_Speed();
    char gap_00[0x240];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Synchronize {
public:
    RGE_Communications_Synchronize(TCommunications_Handler* handler);
    ~RGE_Communications_Synchronize();
    char gap_00[0x7EC];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Queue {
public:
    void FlushAll();
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TChat {
public:
    void ClearChat();
};
#endif // COM_HAND_TU_CONTEXT


struct GUID16 {
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long d;
};

#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;
    unsigned char _pad0[3];
    unsigned long LastSentTime;
    int ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned char _pad1[3];
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    unsigned char _pad2[3];
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
    unsigned char _pad3[2];
    unsigned long Initialized;
    unsigned long RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned long DataSizeToFollow;
};
#endif // COM_HAND_TU_CONTEXT


void operator_delete(void* ptr);
void* __cdecl operator new(unsigned int size);

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0x0008];
    int Steps;                          // +0x08
    unsigned long TickStart;            // +0x0C
    unsigned long TickCount;            // +0x10
    char gap_0014[0x0018 - 0x0014];
    TChat* Chat;                        // +0x18
    int MeHost;                         // +0x1C
    int HaveHostInit;                   // +0x20
    char gap_0024[0x10C8 - 0x0024];
    unsigned long current_turn;         // +0x10C8
    char gap_10CC[0x10DC - 0x10CC];
    unsigned long AcknowledgeAfterMsec; // +0x10DC
    unsigned int Me;                    // +0x10E0
    int Multiplayer;                    // +0x10E4
    int OutOfSyncFlag;                  // +0x10E8
    unsigned long dwStopTime;           // +0x10EC
    float lastRXDataRate;               // +0x10F0
    float lastTXDataRate;               // +0x10F4
    char MyFriendlyName[129];           // +0x10F8
    char MyFormalName[129];             // +0x1179
    char MyGameTitle[129];              // +0x11FA
    char gap_127B[0x1288 - 0x127B];
    int StepMode;                       // +0x1288
    unsigned long turnstart;            // +0x128C
    char gap_1290[0x1294 - 0x1290];
    unsigned long mselapsed;            // +0x1294
    int AvgTurnTime;                    // +0x1298
    char gap_129C[0x12A0 - 0x129C];
    int PauseChangePending;             // +0x12A0
    char gap_12A4[0x12A8 - 0x12A4];
    int ShuttingDown;                   // +0x12A8
    char gap_12AC[0x12B8 - 0x12AC];
    unsigned long RXPacketLength;       // +0x12B8
    unsigned long RXPacketLengthHigh;   // +0x12BC
    unsigned long TXPacketLength;       // +0x12C0
    unsigned long TXPacketLengthHigh;   // +0x12C4
    char gap_12C8[0x12D0 - 0x12C8];
    unsigned long LastTimeoutMessageTime; // +0x12D0
    COMMSTATUS CommunicationsStatus;    // +0x12D4
    unsigned short MaxGamePlayers;      // +0x12D8
    char gap_12DA[0x12FC - 0x12DA];
    GUID16 SessionGUID;                 // +0x12FC
    char gap_130C[0x1310 - 0x130C];
    int LobbyLaunched;                  // +0x1310
    char gap_1314[0x1318 - 0x1314];
    GUID16 NullGUID;                    // +0x1318
    unsigned long ResendAcknowledgements; // +0x1328
    unsigned long ResentToOther;        // +0x132C
    unsigned long DroppedPacketCount;   // +0x1330
    unsigned long RXPackets;            // +0x1334
    unsigned long TXPackets;            // +0x1338
    char gap_133C[0x1340 - 0x133C];
    unsigned long ServiceTimeout;       // +0x1340
    char gap_1344[0x136C - 0x1344];
    unsigned long LastPlayerWarning[10]; // +0x136C
    char gap_1394[0x13C0 - 0x1394];
    int clear_13c0[9];                  // +0x13C0
    char gap_13E4[0x149C - 0x13E4];
    int Kicked[10];                     // +0x149C
    RGE_Communications_Queue* InQ;      // +0x14C4
    RGE_Communications_Queue* OutQ;     // +0x14C8
    char gap_14CC[0x14D4 - 0x14CC];
    RGE_Communications_Speed* Speed;    // +0x14D4
    RGE_Communications_Synchronize* Sync; // +0x14D8
    char gap_14DC[0x14E4 - 0x14DC];
    unsigned int GTDSerialNo;           // +0x14E4
    char gap_14E8[0x1514 - 0x14E8];
    unsigned char RGE_Guaranteed_Delivery; // +0x1514
    char gap_1515[0x1518 - 0x1515];
    int IntentionallyDropPackets;       // +0x1518
    unsigned int WaitingForAck;         // +0x151C
    char gap_1520[0x1550 - 0x1520];
    COMMPLAYEROPTIONS PlayerOptions;    // +0x1550
    char gap_1720[0x1748 - 0x1720];
    int HoldCount;                      // +0x1748
    int WasKicked[10];                  // +0x174C

    void InitPlayerInformation(unsigned int player_number, unsigned long dpid, char* friendly_name, char* formal_name);
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ResetLastCommunicationTimes();
    void DropAllHostedPlayers();
    long ReleaseComm();
    long CloseSession();
    long DestroyMyPlayer();
    void FreeOptions();
    void ReleaseSettings();
    COMMSTATUS AnalyzeCommunicationsStatus();
    COMMSTATUS UnlinkCurrentLevel();
};
#endif // COM_HAND_TU_CONTEXT


COMMSTATUS TCommunications_Handler::UnlinkCurrentLevel() {
    L->Log((char*)0x582750, this->CommunicationsStatus);

    switch (this->CommunicationsStatus) {
    case UNINITIALIZED:
    case INITIALIZED:
        break;

    case SINGLE_PLAYER: {
        this->Multiplayer = 0;
        unsigned long t = debug_timeGetTime((char*)0x580C64, 0x267);
        this->RXPacketLength = 0;
        this->RXPacketLengthHigh = 0;
        this->TXPacketLength = 0;
        this->TXPacketLengthHigh = 0;
        this->lastRXDataRate = 0.0f;
        this->lastTXDataRate = 0.0f;
        this->HoldCount = 0;
        this->ServiceTimeout = 0;
        this->TXPackets = 0;
        this->RXPackets = 0;
        this->RGE_Guaranteed_Delivery = 0;
        this->ResendAcknowledgements = 0;
        this->ResentToOther = 0;
        this->DroppedPacketCount = 0;
        this->LobbyLaunched = 0;
        this->GTDSerialNo = 0;
        this->dwStopTime = 0;
        this->OutOfSyncFlag = 0;
        L->Time();
        this->AvgTurnTime = 0;
        this->PauseChangePending = 0;
        this->StepMode = 0;
        this->IntentionallyDropPackets = 0;
        this->PlayerOptions.LastSentTime = t;
        strcpy(this->MyGameTitle, (char*)0x580460);
        strcpy(this->MyFriendlyName, (char*)0x580460);
        strcpy(this->MyFormalName, (char*)0x580460);
        this->TickStart = 0;
        this->TickCount = 0;
        this->LastTimeoutMessageTime = 0;
        this->PlayerOptions.LowPlayerNumber = 1;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.GameHasStarted = 0;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        this->MeHost = 0;
        this->HaveHostInit = 0;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->PlayerOptions.NeedsToBeSent = 0;
        this->AcknowledgeAfterMsec = 0x32;
        this->Me = 0;
        this->Multiplayer = 0;
        this->turnstart = 0;
        this->mselapsed = 0;
        L->Log((char*)0x580C4C);
        int i = 1;
        if (this->MaxGamePlayers >= i) {
            do {
                this->InitPlayerInformation(i, 0, (char*)0x580460, (char*)0x580460);
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->ClearAllSerialNumbers();
        this->ClearRXandTX();
        int* q = (int*)&this->PlayerStopTurn[1];
        for (int k = 9; k != 0; k--) *q++ = 0;
        this->Steps = 1;
        this->ResetLastCommunicationTimes();
        this->WaitingForAck = 0;
        if (this->InQ != 0) this->InQ->FlushAll();
        if (this->OutQ != 0) this->OutQ->FlushAll();
        this->ShuttingDown = 0;
        for (int i2 = 0; i2 < 10; i2++) {
            this->LastPlayerWarning[i2] = 0;
            this->Kicked[i2] = 0;
            this->WasKicked[i2] = 0;
        }
        this->Me = 1;
        this->MyFriendlyName[0] = '\0';
        this->MyFormalName[0] = '\0';
        break;
    }

    case MULTIPLAYER_RESET: {
        this->Multiplayer = 0;
        unsigned long t = debug_timeGetTime((char*)0x580C64, 0x267);
        this->RXPacketLength = 0;
        this->RXPacketLengthHigh = 0;
        this->TXPacketLength = 0;
        this->TXPacketLengthHigh = 0;
        this->lastRXDataRate = 0.0f;
        this->lastTXDataRate = 0.0f;
        this->HoldCount = 0;
        this->ServiceTimeout = 0;
        this->TXPackets = 0;
        this->RXPackets = 0;
        this->RGE_Guaranteed_Delivery = 0;
        this->ResendAcknowledgements = 0;
        this->ResentToOther = 0;
        this->DroppedPacketCount = 0;
        this->LobbyLaunched = 0;
        this->GTDSerialNo = 0;
        this->dwStopTime = 0;
        this->OutOfSyncFlag = 0;
        L->Time();
        this->AvgTurnTime = 0;
        this->PauseChangePending = 0;
        this->StepMode = 0;
        this->IntentionallyDropPackets = 0;
        this->PlayerOptions.LastSentTime = t;
        strcpy(this->MyGameTitle, (char*)0x580460);
        strcpy(this->MyFriendlyName, (char*)0x580460);
        strcpy(this->MyFormalName, (char*)0x580460);
        this->TickStart = 0;
        this->TickCount = 0;
        this->LastTimeoutMessageTime = 0;
        this->PlayerOptions.LowPlayerNumber = 1;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.GameHasStarted = 0;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        this->MeHost = 0;
        this->HaveHostInit = 0;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->PlayerOptions.NeedsToBeSent = 0;
        this->AcknowledgeAfterMsec = 0x32;
        this->Me = 0;
        this->Multiplayer = 0;
        this->turnstart = 0;
        this->mselapsed = 0;
        L->Log((char*)0x580C4C);
        int i = 1;
        if (this->MaxGamePlayers >= i) {
            do {
                this->InitPlayerInformation(i, 0, (char*)0x580460, (char*)0x580460);
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->ClearAllSerialNumbers();
        this->ClearRXandTX();
        int* q = (int*)&this->PlayerStopTurn[1];
        for (int k = 9; k != 0; k--) *q++ = 0;
        this->Steps = 1;
        this->ResetLastCommunicationTimes();
        this->WaitingForAck = 0;
        if (this->InQ != 0) this->InQ->FlushAll();
        if (this->OutQ != 0) this->OutQ->FlushAll();
        this->ShuttingDown = 0;
        for (int i2 = 0; i2 < 10; i2++) {
            this->LastPlayerWarning[i2] = 0;
            this->Kicked[i2] = 0;
            this->WasKicked[i2] = 0;
        }
        this->Me = 1;
        this->PlayerOptions.Humanity[1] = ME_HUMAN;
        break;
    }

    case CONVERSATION_OPEN:
        this->TXPackets = 0;
        this->RXPackets = 0;
        this->RGE_Guaranteed_Delivery = 1;
        this->ResendAcknowledgements = 0;
        this->ResentToOther = 0;
        this->DroppedPacketCount = 0;
        this->LobbyLaunched = 0;
        this->ShuttingDown = 0;
        L->Log((char*)0x58273C);
        this->ReleaseComm();
        break;

    case SERVICE_AVAILABLE:
        L->Log((char*)0x582724);
        this->ReleaseComm();
        L->Log((char*)0x580C4C);
        if (this->MaxGamePlayers >= 1) {
            int i = 1;
            do {
                this->InitPlayerInformation(i, 0, (char*)0x580460, (char*)0x580460);
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->Chat->ClearChat();
        this->MyGameTitle[0] = '\0';
        this->Me = 0;
        DAT_0062cf04 = 0;
        this->ShuttingDown = 0;
        break;

    case SESSION_AVAILABLE: {
        this->ClearRXandTX();
        this->DropAllHostedPlayers();
        L->Log((char*)0x58270C);
        this->Chat->ClearChat();
        this->CloseSession();
        this->GTDSerialNo = 0;
        L->Log((char*)0x580C4C);
        if (this->MaxGamePlayers >= 1) {
            int i = 1;
            do {
                this->InitPlayerInformation(i, 0, (char*)0x580460, (char*)0x580460);
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        unsigned short n = this->MaxGamePlayers;
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->PlayerOptions.HighPlayerNumber = n;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->Me = 0;
        DAT_0062cf04 = 0;
        this->ClearAllSerialNumbers();
        RGE_Communications_Speed* speed = this->Speed;
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        if (speed != 0) {
            speed->~RGE_Communications_Speed();
            operator_delete(speed);
        }
        RGE_Communications_Synchronize* sync = this->Sync;
        if (sync != 0) {
            sync->~RGE_Communications_Synchronize();
            operator_delete(sync);
        }
        this->Speed = new RGE_Communications_Speed(this);
        this->Sync = new RGE_Communications_Synchronize(this);
        this->SessionGUID = this->NullGUID;
        break;
    }

    case SESSION_HOSTED: {
        L->Log((char*)0x5826F4);
        this->MeHost = 0;
        this->PlayerOptions.HostPlayerNumber = 0;
        this->PlayerOptions.HighPlayerNumber = this->MaxGamePlayers;
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        this->PlayerOptions.CommandTurnIncrement = 2;
        this->current_turn = 4;
        this->PlayerOptions.CurrentTurn = 4;
        this->HaveHostInit = 0;
        this->CloseSession();
        L->Log((char*)0x580C4C);
        if (this->MaxGamePlayers >= 1) {
            int i = 1;
            do {
                this->InitPlayerInformation(i, 0, (char*)0x580460, (char*)0x580460);
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        this->PlayerOptions.NeedsToBeSent = 0;
        this->PlayerOptions.LastSentTime = 0;
        this->Chat->ClearChat();
        DAT_0062cf04 = 0;
        RGE_Communications_Speed* speed = this->Speed;
        this->Me = 0;
        this->current_turn = this->PlayerOptions.CommandTurnIncrement + 2;
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        if (speed != 0) {
            speed->~RGE_Communications_Speed();
            operator_delete(speed);
        }
        RGE_Communications_Synchronize* sync = this->Sync;
        if (sync != 0) {
            sync->~RGE_Communications_Synchronize();
            operator_delete(sync);
        }
        this->Speed = new RGE_Communications_Speed(this);
        this->Sync = new RGE_Communications_Synchronize(this);
        break;
    }

    case PLAYER_CREATED:
        L->Log((char*)0x5826DC);
        this->DestroyMyPlayer();
        this->Me = 0;
        DAT_0062cf04 = 0;
        this->InQ->FlushAll();
        this->ShuttingDown = 0;
        break;

    case GAME_PLAYER_SET:
        L->Log((char*)0x5826C8);
        this->Me = 0;
        DAT_0062cf04 = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_OPTIONS_EXCHANGED:
        L->Log((char*)0x5826AC);
        this->FreeOptions();
        this->PlayerOptions.NeedsToBeSent = 0;
        this->ShuttingDown = 0;
        break;

    case COMM_SETTINGS_EXCHANGED:
        L->Log((char*)0x58268C);
        this->ReleaseSettings();
        this->ResetLastCommunicationTimes();
        this->ShuttingDown = 0;
        break;

    case GAME_IS_LOADING:
        this->PlayerOptions.ProgramState = COMM_STATE_JOINNOW;
        L->Log((char*)0x582674);
        this->ShuttingDown = 0;
        break;

    case GAME_IS_RUNNING:
        this->Chat->ClearChat();
        L->Log((char*)0x58265C);
        this->LastTimeoutMessageTime = 0;
        this->InQ->FlushAll();
        this->PlayerOptions.GameHasStarted = 0;
        this->ShuttingDown = 0;
        break;

    case GAME_IS_PAUSED:
        L->Log((char*)0x582648);
        break;

    default:
        L->Log((char*)0x582638);
        break;
    }

    L->Log((char*)0x582624, this->CommunicationsStatus - 1);
    return this->AnalyzeCommunicationsStatus();
}
