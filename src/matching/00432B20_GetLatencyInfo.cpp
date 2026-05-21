// VA: 00432B20 RGE_Communications_Speed::GetLatencyInfo
// com_spd.cpp lines 328-343

// attempt 1: builds latency string for each human player
// 167/167 exact size, 123 diff bytes
// Manual string ops codegen basin (strlen/memcpy/sprintf pattern differs)
// Left in scratch.

#include <string.h>
#include <stdio.h>

class TCommunications_Handler {
public:
    int IsPlayerHuman(int player_index);
};

class RGE_Communications_Speed {
public:
    char TBuff[255];                       // +0x00
    unsigned char _pad_0[1];               // +0xFF
    void* TurnTSLC;                        // +0x100
    void* FrameTSLC;                       // +0x104
    TCommunications_Handler* Comm;         // +0x108
    unsigned char _pad_1[4];               // +0x10C
    double AccumDiff;                      // +0x110
    int SpeedControlEnabled;               // +0x118
    unsigned int CurrentBufferFrames;      // +0x11C
    unsigned int FutureBufferFrames;       // +0x120
    unsigned int TotalBufferFramesRemaining; // +0x124
    unsigned int TargetTurnLengthMsec;     // +0x128
    unsigned int CurrentBufferGranularity; // +0x12C
    unsigned int FutureBufferGranularity;  // +0x130
    unsigned int OverheadFactor;           // +0x134
    unsigned long TimeSinceLastBuffer;     // +0x138
    unsigned long FutureSpeedChangeTurn;   // +0x13C
    unsigned long NextLatencyChangeTurn;   // +0x140
    unsigned int ActualLatency[10];        // +0x144
    unsigned int AverageTSLC[10];          // +0x16C
    unsigned char PlayerOptimalFrames[10]; // +0x194
    unsigned char PlayerOptimalGranularity[10]; // +0x19E
    unsigned short RequestFasterOrSlower[10];  // +0x1A8
    unsigned long PlayerAvgFramesMsec[10]; // +0x1BC
    unsigned long PlayerHighLatencyMsec[10]; // +0x1E4
    unsigned long HighestLatencyMsec;      // +0x20C
    unsigned int SkipFrames;               // +0x210
    unsigned int OptimalBufferFrames;      // +0x214
    unsigned int OptimalBufferGranularity; // +0x218
    unsigned int DiffOffset;               // +0x21C
    unsigned int AllAcknowledgedBuffersRemaining; // +0x220
    unsigned int LastAdjusted;             // +0x224
    unsigned long RealTimePassed;          // +0x228
    unsigned long BufferTimePassed;        // +0x22C
    unsigned int DroppedFrames;            // +0x230
    unsigned int DroppedFramesTurn;        // +0x234
    unsigned long AdjustmentCount;         // +0x238
    int LastFrameHadTime;                  // +0x23C

    char* GetLatencyInfo();
};

char* RGE_Communications_Speed::GetLatencyInfo() {
    char buf[24];
    strcpy(this->TBuff, "Latency> ");
    for (unsigned int i = 1; i <= 9; i++) {
        if (this->Comm->IsPlayerHuman(i)) {
            sprintf(buf, "P%d=%d ", i, this->ActualLatency[i]);
            strcat(this->TBuff, buf);
        }
    }
    return this->TBuff;
}
