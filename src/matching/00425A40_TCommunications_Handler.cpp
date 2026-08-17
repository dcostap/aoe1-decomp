// VA: 00425A40 TCommunications_Handler::TCommunications_Handler
// PDB source: Com_hand.cpp lines 268-332 (1700 bytes, EH-framed /GX ctor)
//
// ATTEMPT LOG (prior owner DS4-425A40; current owner Luna-425A40, 10-probe budget):
// 1 baseline: natural /GX ctor with real new expressions (new NAME[maxPlayers+1],
//   new RGE_Communications_Queue(0x1F5), new RESENDER[0x1F6], new HOLDER[0x1F6],
//   new RGE_Comm_Error(hwnd), new RGE_Lobby(hwnd), new Speed(this), new Sync(this)),
//   memset/strcpy idioms, full ground-truth class layout; /GX response file. Result:
//   1714B (frame 0x28 vs 0x20). EH prologue/state machine (states 0..6) generated
//   exactly like the original; first ~0x140 bytes byte-identical.
// 2 layout fix: class was missing tslc (+0x14D0) and Addresses (+0x14DC) fields, which
//   shifted every offset from 0x14D0 by -8 (Speed/Sync/Err/GTDSerialNo/Resend/OnHold/
//   PlayerOptions/LastTurnAck/HoldCount/WasKicked all wrong). Added both fields;
//   now 1700B exact size; tail (zero block, Time, strcpy trio, PlayerOptions init,
//   InitPlayerInformation loop, ClearAll/FlushAll, Kicked loop, epilogue) byte-exact.
// 3 pointer-walk loop probe (names local + p walker, for i=0..maxPlayers): loop body
//   matches original (pointer increment, no base reload) but VC5 keeps maxPlayers in
//   edi (spill + size spill) -> frame still 0x28.
// 4-7 variant labs over the NAME block (11+5+4+5 cases, one family per run):
//   i<=maxPlayers (any spelling, indexed/pointer/member, ++i/i++) -> maxPlayers in edi,
//   frame 0x28; i<maxPlayers+1 / i>=0 / i>0 / i<count / i<=count-1 -> guard/counter
//   pattern `lea ecx,[count-1]; cmp; jl; inc` matches ORIGINAL exactly for
//   `i <= count - 1`, but count is duplicated into edi + home + size spill -> frame 0x24;
//   while (count > 0) gives frame 0x20 but MUTATES count (second alloc size 0) ->
//   rejected as semantically wrong. Kept the ptr_leq (i<=maxPlayers) form: natural,
//   semantically correct, 1700B, closest valid basin; remaining drift is the NAME block
//   register coloring (2 extra spill locals) which also perturbs the Codestr lea timing.
// Orchestrator follow-up: checker normalization now identifies VC5 ??_L/??_M symbols
//   as the corresponding EH vector helpers. Revalidation has 28/28 ordered calls and
//   no call-target differences; 00424AC0 and the other affected exact donors also
//   revalidate. The remaining blocker is source/codegen, not relocation identity.
//
// Luna-425A40 bounded follow-up (2026-08-02):
// 1 baseline: inherited best state, 1700B, frame 0x28 vs 0x20, 28/28 calls,
//    diff 1237B.
// 2 context: restored inventory-proven full field surfaces for the handler and
//    constructed communication subobjects; codegen unchanged.
// 3 context: restored donor-header pack(1)/pack(4) context; codegen unchanged.
// 4 layout: scoped each NAME allocation/count pair and used count-1 guards;
//    frame reached 0x20, size 1692B, diff 1123B, exact-block coverage 81.76%.
// 5 layout: kept one NAME* across both scopes; frame stayed 0x20 but shape
//    regressed; restored probe 4.
// 6 layout: scoped Codestr/p lifetime; unchanged; retained the scoped form.
// 7 control-flow: explicit null zero arms worsened size/CFG (1704B, diff 1147B);
//    restored.
// 8 control-flow: duplicated NAME member stores worsened size/CFG (1708B,
//    diff 1125B); restored.
// 9 layout: one shared mutable count with an explicit reset before the second
//    allocation and explicit null member stores; recovered exact 1700B/frame
//    0x20 and diff 179B, but NAME block topology remained non-exact.
// 10 control-flow: changed only Codestr to the observed guarded do/while;
//    removed the first extra lea and improved to diff 165B (1648/1700 equal,
//    28/28 ordered calls, exact frame/size). Budget exhausted.
// CURRENT BEST: keep the full class/context surface and the shared count-reset
//   NAME topology. Remaining drift is localized to NAME allocation block shape,
//   starting at 00425C01 (stack-home selection [esp+48] vs [esp+4C]); no EH or
//   call-target blocker remains. Next lead: preserve the frame-0x20 shared-count
//   basin while restoring the original count/pointer parameter-home assignments.
// shardC5-425A40 baseline: current source keeps canonical named ownership and
//   natural typed allocation loops; exact size/frame/calls remain aligned.
// shardC5-425A40 control-flow lead: separate typed remaining counters with
//   do/while loops changed the build to 1676B, removed two CFG conditions, and
//   introduced wrong EH call relocation; restored the clean while-loop source.
//
// Exact-finish retrospective (2026-08-17):
// - First exact checkpoint: probe-019-liveness / first-exact, 1700B, diff 0.
// - Required group: scoped NAME allocation blocks, pointer walks using
//   `i <= count - 1`, and a branch-local result assigned in both arms.
// - Incidental change removed: `NAME* result = names`; an uninitialized
//   declaration stayed exact because both arms assign it before use.
// - Reversions tested: removed nonnull result stores, removed allocation
//   scopes, and restored while loops. Each changed emitted bytes or CFG.
// - Reduced validation: reduced-exact, Result: MATCH, 0.0000%.

#include <string.h>

class TChat;
class TDebuggingLog;
class TCommunications_Handler;
class RGE_Communications_Queue;
class RGE_Comm_Error;
class RGE_Lobby;
class RGE_Communications_Speed;
class RGE_Communications_Synchronize;

extern TDebuggingLog* L;
void Log(TDebuggingLog* log, const char* format, ...);
extern "C" unsigned long debug_timeGetTime(char* file, int line);

struct GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

enum COMMSTATUS { UNINITIALIZED = 0, INITIALIZED = 1 };
enum COMMSTATES { COMM_STATE_JOINNOW = 3 };

class TDebuggingLog {
public:
    void FlushToDisk(int param_1);
    void Time();
};

class NAME {
public:
    char Text[128];
};

class RESENDER {
public:
    unsigned long TimeSent;
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

class RGE_Communications_Addresses;
class RGE_TimeSinceLastCall;

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
};

class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;
    RGE_Comm_Error(void* hwnd);
    ~RGE_Comm_Error();
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
};
#pragma pack(push, 1)
class COMMPLAYEROPTIONS {
public:
    unsigned char NeedsToBeSent;      // +0x00
    unsigned char _pad_0[3];
    unsigned long LastSentTime;       // +0x04
    COMMSTATES ProgramState;          // +0x08
    unsigned long CurrentTurn;        // +0x0C
    unsigned char TurnSpeedMsec;      // +0x10
    unsigned char _pad_1[3];
    unsigned long dcoID[10];          // +0x14
    unsigned long AcknowledgeAfterMsec; // +0x3C
    unsigned char CommandTurnIncrement; // +0x40
    unsigned char _pad_2[3];
    int PlayerReady[10];              // +0x44
    unsigned long User1[10];          // +0x6C
    unsigned long User2[10];          // +0x94
    unsigned long User3[10];          // +0xBC
    unsigned long User4[10];          // +0xE4
    unsigned long User5[10];          // +0x10C
    unsigned long User6[10];          // +0x134
    unsigned long User7[10];          // +0x15C
    int Humanity[10];                 // +0x184
    unsigned char InvalidPlayer[10];  // +0x1AC
    unsigned char _pad_3[2];
    unsigned long Initialized;        // +0x1B8
    unsigned long RandomSeed;         // +0x1BC
    unsigned short HighPlayerNumber;  // +0x1C0
    unsigned short LowPlayerNumber;   // +0x1C2
    unsigned int HostPlayerNumber;    // +0x1C4
    int GameHasStarted;               // +0x1C8
    unsigned long DataSizeToFollow;   // +0x1CC
};
#pragma pack(pop)

#pragma pack(push, 4)
class TCommunications_Handler {
public:
    int OptionsChanged;                 // +0x00
    char* OptionsData;                  // +0x04
    int Steps;                          // +0x08
    unsigned long TickStart;            // +0x0C
    unsigned long TickCount;            // +0x10
    unsigned long TimeSinceLastCall;    // +0x14
    TChat* Chat;                        // +0x18
    int MeHost;                         // +0x1C
    int HaveHostInit;                   // +0x20
    char InCommBuff[4001];              // +0x24
    char TBuff[257];                    // +0xFC5
    unsigned char _pad_10C6[2];
    unsigned long current_turn;         // +0x10C8
    unsigned long next_command_turn;    // +0x10CC
    unsigned int sequence;              // +0x10D0
    long WaitOnPlayer;                   // +0x10D4
    unsigned long TurnSpeedMsec;         // +0x10D8
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
    unsigned char _pad_127B;
    unsigned long CurrentPlayers;       // +0x127C
    int previous_last_world_random;     // +0x1280
    int last_world_random;              // +0x1284
    int StepMode;                       // +0x1288
    unsigned long turnstart;            // +0x128C
    unsigned long lastcalltick;         // +0x1290
    unsigned long mselapsed;            // +0x1294
    int AvgTurnTime;                    // +0x1298
    int SkipFrames;                     // +0x129C
    int PauseChangePending;             // +0x12A0
    unsigned long CommunicationsVersionCode; // +0x12A4
    int ShuttingDown;                   // +0x12A8
    unsigned long ReturnElapsed;        // +0x12AC
    unsigned long ReturnRXPacketSize;   // +0x12B0
    unsigned long ReturnTXPacketSize;   // +0x12B4
    unsigned long RXPacketLength;       // +0x12B8
    unsigned long RXPacketLengthHigh;   // +0x12BC
    unsigned long TXPacketLength;       // +0x12C0
    unsigned long TXPacketLengthHigh;   // +0x12C4
    NAME* FriendlyName;                 // +0x12C8
    NAME* FormalName;                   // +0x12CC
    unsigned long LastTimeoutMessageTime; // +0x12D0
    COMMSTATUS CommunicationsStatus;    // +0x12D4
    unsigned short MaxGamePlayers;      // +0x12D8
    char gap_12DA[2];
    GUID ServiceGUID;                   // +0x12DC
    GUID ApplicationGUID;               // +0x12EC
    GUID SessionGUID;                   // +0x12FC
    void* HostHWND;                     // +0x130C
    int LobbyLaunched;                  // +0x1310
    unsigned long MaxReceiveLatency;    // +0x1314
    GUID NullGUID;                      // +0x1318
    unsigned long ResendAcknowledgements; // +0x1328
    unsigned long ResentToOther;        // +0x132C
    unsigned long DroppedPacketCount;   // +0x1330
    unsigned long RXPackets;            // +0x1334
    unsigned long TXPackets;            // +0x1338
    int IAmLagging;                     // +0x133C
    unsigned long ServiceTimeout;       // +0x1340
    unsigned long LastPlayerCommunication[10]; // +0x1344
    unsigned long LastPlayerWarning[10]; // +0x136C
    unsigned long LastTXPing[10];       // +0x1394
    unsigned long PlayerStopTurn[10];   // +0x13BC
    unsigned long LastSerialRequestedTX[10]; // +0x13E4
    unsigned long LastRequestHonoredTX[10]; // +0x140C
    unsigned long LastSerialRepliedTX[10]; // +0x1434
    unsigned long LastRequestRepliedTX[10]; // +0x145C
    unsigned long dwFlags;              // +0x1484
    unsigned long dwMaxBufferSize;      // +0x1488
    unsigned long dwMaxQueueSize;       // +0x148C
    unsigned long dwMaxPlayers;         // +0x1490
    unsigned long dwHundredBaud;        // +0x1494
    unsigned long dwLatency;            // +0x1498
    int Kicked[10];                     // +0x149C
    RGE_Communications_Queue* InQ;      // +0x14C4
    RGE_Communications_Queue* OutQ;     // +0x14C8
    RGE_Lobby* Lobby;                   // +0x14CC
    RGE_TimeSinceLastCall* tslc;        // +0x14D0
    RGE_Communications_Speed* Speed;    // +0x14D4
    RGE_Communications_Synchronize* Sync; // +0x14D8
    RGE_Communications_Addresses* Addresses; // +0x14DC
    RGE_Comm_Error* Err;                // +0x14E0
    unsigned int GTDSerialNo;           // +0x14E4
    unsigned int HighResendStore;       // +0x14E8
    unsigned int DestMap[10];           // +0x14EC
    unsigned char RGE_Guaranteed_Delivery; // +0x1514
    unsigned char _pad_1515[3];
    int IntentionallyDropPackets;       // +0x1518
    unsigned int WaitingForAck;         // +0x151C
    RESENDER* Resend;                   // +0x1520
    HOLDER* OnHold;                     // +0x1524
    unsigned int PlayerHighSerialNumber[10]; // +0x1528
    COMMPLAYEROPTIONS PlayerOptions;    // +0x1550
    unsigned long LastTurnAck[10];      // +0x1720
    unsigned int HoldCount;             // +0x1748
    int WasKicked[10];                  // +0x174C

    TCommunications_Handler(void* hwnd, unsigned char maxPlayers, TChat* chat, GUID appGUID);
    ~TCommunications_Handler();
    void InitPlayerInformation(unsigned int player, unsigned long param_2, char* param_3, char* param_4);
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ResetLastCommunicationTimes();
};
#pragma pack(pop)

TCommunications_Handler::TCommunications_Handler(void* hwnd, unsigned char maxPlayers, TChat* chat, GUID appGUID)
{
    L->FlushToDisk(1);

    this->ReturnRXPacketSize = this->RXPacketLength;
    this->RXPacketLengthHigh = this->RXPacketLength > this->RXPacketLengthHigh
        ? this->RXPacketLength : this->RXPacketLengthHigh;
    this->RXPacketLength = 0;

    this->ReturnTXPacketSize = this->TXPacketLength;
    this->TXPacketLengthHigh = this->TXPacketLength > this->TXPacketLengthHigh
        ? this->TXPacketLength : this->TXPacketLengthHigh;

    this->TXPacketLength = 0;
    this->OutQ = 0;
    this->InQ = 0;
    this->GTDSerialNo = 0;
    memset(&this->NullGUID, 0, sizeof(this->NullGUID));

    this->CommunicationsStatus = INITIALIZED;
    this->ApplicationGUID = appGUID;
    this->SessionGUID = this->NullGUID;
    this->ServiceGUID = this->NullGUID;
    this->HostHWND = hwnd;
    this->Chat = chat;
    this->MaxGamePlayers = maxPlayers;

    Log(L, "COMM:  RGE COMMUNICTIONS STARTED ---------------%s",
        "C:\\msdev\\work\\age1_x1\\Com_hand.cpp");
    Log(L, "COMM:  %s  Version... %s",
        "C:\\msdev\\work\\age1_x1\\Com_hand.cpp", "Fri Jul 17 09:39:38 1998");

    {
        char Codestr[32];
        strcpy(Codestr, "13:17:08");
        if (*Codestr != 0) {
            char* p = Codestr;
            do {
                if (*p == ':') {
                    *p = '0';
                }
                ++p;
            } while (*p != 0);
        }
    }
    // LAB-START nameblock (variant-lab splice region; keep identical in both blocks)
    this->CommunicationsVersionCode = 0x2E2887;
    int count = maxPlayers + 1;
    // BINARY NOTE: Each allocation result crosses its guarded fixed-size fill loop.
    // LIKELY INTENT: Initialize one NAME record for every player slot and the extra terminator slot.
    {
        NAME* names = new NAME[count];
        NAME* result;
        if (names != 0) {
            NAME* p = names;
            for (int i = 0; i <= count - 1; ++i) {
                strcpy(p->Text, " ");
                ++p;
            }
            result = names;
        } else {
            result = 0;
        }
        this->FriendlyName = result;
    }

    count = maxPlayers + 1;
    {
        NAME* names = new NAME[count];
        NAME* result;
        if (names != 0) {
            NAME* p = names;
            for (int i = 0; i <= count - 1; ++i) {
                strcpy(p->Text, " ");
                ++p;
            }
            result = names;
        } else {
            result = 0;
        }
        this->FormalName = result;
    }
    // LAB-END nameblock

    this->InQ = new RGE_Communications_Queue(0x1F5);
    this->Resend = new RESENDER[0x1F6];
    this->OnHold = new HOLDER[0x1F6];
    this->Err = new RGE_Comm_Error(hwnd);
    this->Lobby = new RGE_Lobby(hwnd);
    this->Speed = new RGE_Communications_Speed(this);
    this->Sync = new RGE_Communications_Synchronize(this);

    unsigned long startTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\com_hand.h", 0x267);

    this->RXPacketLength = 0;
    this->RXPacketLengthHigh = 0;
    this->TXPacketLength = 0;
    this->TXPacketLengthHigh = 0;
    this->lastRXDataRate = 0;
    this->lastTXDataRate = 0;
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
    this->PlayerOptions.LastSentTime = startTime;

    this->AvgTurnTime = 0;
    this->PauseChangePending = 0;
    this->StepMode = 0;
    this->IntentionallyDropPackets = 0;

    strcpy(this->MyGameTitle, " ");
    strcpy(this->MyFriendlyName, " ");
    strcpy(this->MyFormalName, " ");

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

    Log(L, "Initialize Player List");

    int i;
    for (i = 1; i <= this->MaxGamePlayers; ++i) {
        this->InitPlayerInformation(i, 0, " ", " ");
    }

    this->PlayerOptions.NeedsToBeSent = 0;
    this->PlayerOptions.LastSentTime = 0;

    this->ClearAllSerialNumbers();
    this->ClearRXandTX();

    for (i = 1; i < 10; ++i) {
        this->PlayerStopTurn[i] = 0;
    }

    this->Steps = 1;
    this->ResetLastCommunicationTimes();

    this->WaitingForAck = 0;
    if (this->InQ != 0) {
        this->InQ->FlushAll();
    }
    if (this->OutQ != 0) {
        this->OutQ->FlushAll();
    }

    this->ShuttingDown = 0;

    for (i = 0; i < 10; ++i) {
        this->LastPlayerWarning[i] = 0;
        this->Kicked[i] = 0;
        this->WasKicked[i] = 0;
    }

    this->PlayerOptions.DataSizeToFollow = 0;
    this->OptionsData = 0;
}
