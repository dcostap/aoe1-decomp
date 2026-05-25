// VA: 00432C70 RGE_Communications_Speed::GetMachineSpeedInfo
// com_spd.cpp lines 377-395
// 2026-05-24 Boss pass: MATCH. Fixes: model global output and string literals as absolute-address macros, use 24-byte local buffer, loop players 1..9, and pass `buf` (not decompiler-labeled `buf+4`) to sprintf/strcat; transient vararg pushes make it appear as `[esp+20]/[esp+28]` in asm.

#include <string.h>
#include <stdio.h>

class TCommunications_Handler {
public:
    int IsPlayerHuman(int player_index);
};

#define global_buf ((char*)0x0062D070)
#define S_PLRSPEED ((char*)0x005836A8)
#define S_PLAYERFMT ((char*)0x00583694)

class RGE_Communications_Speed {
public:
    char TBuff[255];
    unsigned char _pad_0[1];
    void* TurnTSLC;
    void* FrameTSLC;
    TCommunications_Handler* Comm;
    unsigned char _pad_1[4];
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

    char* GetMachineSpeedInfo();
};

char* RGE_Communications_Speed::GetMachineSpeedInfo() {
    char buf[24];
    strcpy(global_buf, S_PLRSPEED);

    for (int i = 1; i <= 9; i++) {
        if (Comm->IsPlayerHuman(i)) {
            sprintf(buf, S_PLAYERFMT, i, PlayerAvgFramesMsec[i], PlayerHighLatencyMsec[i]);
            strcat(global_buf, buf);
        }
    }

    return global_buf;
}
