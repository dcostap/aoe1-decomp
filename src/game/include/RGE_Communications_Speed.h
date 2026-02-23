#pragma once
#include "common.h"

struct RGE_TimeSinceLastCall;

struct RGE_Communications_Speed {
    RGE_Communications_Speed(TCommunications_Handler* comm);
    ~RGE_Communications_Speed();

    void SetPlayerTurnSpeed(uint player, uchar avg_frames_msec, uchar high_latency_centi);
    void SetActualLatency(uint player, ulong latency_msec);
    void SetFutureSpeedChange(uint future_frames, uint future_granularity, ulong change_turn);
    void EnableSpeedControl(int enable);
    uint GetBufferGranularity();
    ulong GetAdjustmentCount();
    uint GetBufferGranularityAdjusted();
    uint BufferFramesRemaining();
    uint WaitingOnAcknowledgement();
    void ReloadBufferFrames();
    uint BufferTimeToUse(ulong frame_no);
    void Skip();
    uchar GetHighLatencyCenti();
    ulong GetPlayerLatency(uint player);
    char* GetLatencyInfo();
    char* GetSelfPlayerOptimalSpeedStr();
    char* GetPlayerSpeedStatusStr(int player);
    char* GetMachineSpeedInfo();
    uint GetRecommendedBufferFrames();
    uint GetAvgFrameRate();
    uint GetRecommendedBufferGranularity();
    int AnalyzeGameSpeed(uint* out_granularity, uint* out_frames, int apply_change);
    void SetV1(ulong v);
    void SetV2(ulong v);

    void AdjustLocalSpeed();

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
