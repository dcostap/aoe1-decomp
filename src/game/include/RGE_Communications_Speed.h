#pragma once
#include "common.h"

struct RGE_Communications_Speed {
    char TBuff[255];
    RGE_TimeSinceLastCall* TurnTSLC;
    RGE_TimeSinceLastCall* FrameTSLC;
    TCommunications_Handler* Comm;
    double AccumDiff;
    int SpeedControlEnabled;
    uint CurrentBufferFrames;
    uint FutureBufferFrames;
    uint TotalBufferFramesRemaining;
    uint TargetTurnLengthMsec;
    uint CurrentBufferGranularity;
    uint FutureBufferGranularity;
    uint OverheadFactor;
    ulong TimeSinceLastBuffer;
    ulong FutureSpeedChangeTurn;
    ulong NextLatencyChangeTurn;
    uint ActualLatency[10];
    uint AverageTSLC[10];
    uchar PlayerOptimalFrames[10];
    uchar PlayerOptimalGranularity[10];
    ushort RequestFasterOrSlower[10];
    ulong PlayerAvgFramesMsec[10];
    ulong PlayerHighLatencyMsec[10];
    ulong HighestLatencyMsec;
    uint SkipFrames;
    uint OptimalBufferFrames;
    uint OptimalBufferGranularity;
    uint DiffOffset;
    uint AllAcknowledgedBuffersRemaining;
    uint LastAdjusted;
    ulong RealTimePassed;
    ulong BufferTimePassed;
    uint DroppedFrames;
    uint DroppedFramesTurn;
    ulong AdjustmentCount;
    int LastFrameHadTime;
};
static_assert(sizeof(RGE_Communications_Speed) == 0x240, "Size mismatch");
