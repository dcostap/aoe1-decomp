// VA: 00432620 RGE_Communications_Speed::RGE_Communications_Speed
// com_spd.cpp lines 11-60

// attempt 2: correct full class layout with TBuff[255] at +0x00
// /GX for EH, ret 4

class TCommunications_Handler;

class RGE_TimeSinceLastCall {
public:
    RGE_TimeSinceLastCall();
    char gap_00[0x2B4];
};

class RGE_Communications_Speed {
public:
    char TBuff[255];                       // +0x00
    unsigned char _pad_0[1];               // +0xFF
    RGE_TimeSinceLastCall* TurnTSLC;       // +0x100
    RGE_TimeSinceLastCall* FrameTSLC;      // +0x104
    TCommunications_Handler* Comm;         // +0x108
    unsigned char _pad_1[4];               // +0x10C
    double AccumDiff;                      // +0x110
    int SpeedControlEnabled;               // +0x118 (=1)
    unsigned int CurrentBufferFrames;      // +0x11C (=10)
    unsigned int FutureBufferFrames;       // +0x120 (=0)
    unsigned int TotalBufferFramesRemaining; // +0x124 (=0)
    unsigned int TargetTurnLengthMsec;     // +0x128 (=500)
    unsigned int CurrentBufferGranularity; // +0x12C (=90)
    unsigned int FutureBufferGranularity;  // +0x130 (=0)
    unsigned int OverheadFactor;           // +0x134 (=0)
    unsigned long TimeSinceLastBuffer;     // +0x138 (=0)
    unsigned long FutureSpeedChangeTurn;   // +0x13C (=0)
    unsigned long NextLatencyChangeTurn;   // +0x140 (=0)
    unsigned int ActualLatency[10];        // +0x144
    unsigned int AverageTSLC[10];          // +0x16C
    unsigned char PlayerOptimalFrames[10]; // +0x194
    unsigned char PlayerOptimalGranularity[10]; // +0x19E
    unsigned short RequestFasterOrSlower[10];  // +0x1A8
    unsigned long PlayerAvgFramesMsec[10]; // +0x1BC
    unsigned long PlayerHighLatencyMsec[10]; // +0x1E4
    unsigned long HighestLatencyMsec;      // +0x20C (=500)
    unsigned int SkipFrames;               // +0x210
    unsigned int OptimalBufferFrames;      // +0x214 (=10)
    unsigned int OptimalBufferGranularity; // +0x218 (=90)
    unsigned int DiffOffset;               // +0x21C
    unsigned int AllAcknowledgedBuffersRemaining; // +0x220
    unsigned int LastAdjusted;             // +0x224 (=0)
    unsigned long RealTimePassed;          // +0x228 (=0)
    unsigned long BufferTimePassed;        // +0x22C (=0)
    unsigned int DroppedFrames;            // +0x230 (=0)
    unsigned int DroppedFramesTurn;        // +0x234 (=0)
    unsigned long AdjustmentCount;         // +0x238 (=0)
    int LastFrameHadTime;                  // +0x23C (=0)

    RGE_Communications_Speed(TCommunications_Handler* handler);
};

void* __cdecl operator_new(unsigned int size);

RGE_Communications_Speed::RGE_Communications_Speed(TCommunications_Handler* handler) {
    Comm = handler;
    CurrentBufferGranularity = 90;
    OptimalBufferGranularity = 90;
    CurrentBufferFrames = 10;
    OptimalBufferFrames = 10;
    SpeedControlEnabled = 1;
    OverheadFactor = 0;
    LastAdjusted = 0;
    AdjustmentCount = 0;
    LastFrameHadTime = 0;
    TotalBufferFramesRemaining = 0;
    TimeSinceLastBuffer = 0;
    TargetTurnLengthMsec = 500;
    RealTimePassed = 0;
    BufferTimePassed = 0;
    DroppedFrames = 0;
    DroppedFramesTurn = 0;
    NextLatencyChangeTurn = 0;
    FutureBufferFrames = 0;
    FutureBufferGranularity = 0;
    
    for (int i = 0; i < 10; i++) {
        ActualLatency[i] = 30;
        AverageTSLC[i] = 0;
        RequestFasterOrSlower[i] = 0;
        PlayerAvgFramesMsec[i] = 0;
        PlayerHighLatencyMsec[i] = 0;
    }
    
    HighestLatencyMsec = 500;
    
    FrameTSLC = new RGE_TimeSinceLastCall();
    TurnTSLC = new RGE_TimeSinceLastCall();
}
