// VA: 00432C70 RGE_Communications_Speed::GetMachineSpeedInfo
// com_spd.cpp lines 377-395

// attempt 1: builds machine speed string for each human player
// 176/176 exact size, 126 diff bytes
// Manual string ops codegen basin
// Left in scratch.

#include <string.h>
#include <stdio.h>

class TCommunications_Handler {
public:
    int IsPlayerHuman(int player_index);
};

char global_buf[256];  // DAT_0062d070

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

    char* GetMachineSpeedInfo();
};

char* RGE_Communications_Speed::GetMachineSpeedInfo() {
    char buf[28];
    char* src = "PlrSpeed> ";
    
    strcpy(buf, src);
    char* buf_ptr = buf + 4;
    
    for (int i = 1; i <= 8; i++) {
        if (Comm->IsPlayerHuman(i)) {
            sprintf(buf_ptr, "P#%1d(fr%d lat%d) ", i, PlayerAvgFramesMsec[i], PlayerHighLatencyMsec[i]);
            strcat(global_buf, buf_ptr);
        }
    }
    
    return global_buf;
}
