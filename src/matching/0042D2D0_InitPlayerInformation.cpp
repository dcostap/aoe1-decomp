// TCommunications_Handler::InitPlayerInformation (0042D2D0)
// PDB source: Com_hand.cpp:5449-5491
// Size: 217 bytes
// void __thiscall InitPlayerInformation(uint param_1, ulong param_2, char* param_3, char* param_4)

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

struct RGE_Communications_Queue {
    void FlushForPlayer(int player);
};

struct TCommunications_Handler {
    unsigned char gap_00[0x12D8];
    unsigned short MaxGamePlayers;          // +0x12D8
    unsigned char gap_12DA[0x1AA];
    unsigned long dwFlags;                  // +0x1484
    unsigned long dwMaxBufferSize;          // +0x1488
    unsigned long dwMaxQueueSize;           // +0x148C
    unsigned long dwMaxPlayers;             // +0x1490
    unsigned long dwHundredBaud;            // +0x1494
    unsigned long dwLatency;                // +0x1498
    unsigned char gap_149C[0x28];
    RGE_Communications_Queue* InQ;          // +0x14C4
    unsigned char gap_14C8[0x60];
    unsigned int PlayerHighSerialNumber[10]; // +0x1528
    COMMPLAYEROPTIONS PlayerOptions;        // +0x1550
    unsigned long LastTurnAck[10];          // +0x1720

    void InitPlayerInformation(unsigned int param_1, unsigned long param_2, char* param_3, char* param_4);
};

void __cdecl TDebuggingLog_Log(void* log, const char* fmt, ...);

extern void* g_pLog;

void TCommunications_Handler::InitPlayerInformation(unsigned int param_1, unsigned long param_2, char* param_3, char* param_4)
{
    if (param_1 < 1)
        return;
    if (param_1 > MaxGamePlayers)
        return;

    PlayerOptions.PlayerReady[param_1] = 0;
    PlayerOptions.User1[param_1] = 0;
    PlayerOptions.User2[param_1] = 0;
    PlayerOptions.User3[param_1] = 0;
    PlayerOptions.User4[param_1] = 0;
    PlayerOptions.User5[param_1] = 0;
    PlayerOptions.User6[param_1] = 0;
    PlayerOptions.User7[param_1] = 0;
    PlayerOptions.InvalidPlayer[param_1] = 0;
    LastTurnAck[param_1] = 0;
    PlayerOptions.Humanity[param_1] = 0;
    PlayerOptions.dcoID[param_1] = param_2;
    PlayerHighSerialNumber[param_1] = 0;

    dwFlags = 0;
    dwMaxBufferSize = 0;
    dwMaxQueueSize = 0;
    dwMaxPlayers = 0;
    dwHundredBaud = 0;
    dwLatency = 0;

    if (InQ)
    {
        InQ->FlushForPlayer(param_1);
    }

    TDebuggingLog_Log(g_pLog, "Player %d (%ld) is INITIALIZED as '%s' [%s]", param_1, param_2, param_3, param_4);
}
