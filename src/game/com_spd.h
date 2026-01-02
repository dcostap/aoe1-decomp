#pragma once
#include "../common.h"

class RGE_Communications_Speed {
public:
    RGE_TimeSinceLastCall* TurnTSLC;         // 0x100
    RGE_TimeSinceLastCall* FrameTSLC;        // 0x104
    TCommunications_Handler* Comm;           // 0x108
    double AccumDiff;                        // 0x110
    int SpeedControlEnabled;                 // 0x118
    uint CurrentBufferFrames;                // 0x11C
    uint FutureBufferFrames;                 // 0x120
    uint TotalBufferFramesRemaining;         // 0x124
    uint TargetTurnLengthMsec;               // 0x128
    uint CurrentBufferGranularity;           // 0x12C
    uint FutureBufferGranularity;            // 0x130
    uint OverheadFactor;                     // 0x134
    ulong TimeSinceLastBuffer;               // 0x138
    ulong FutureSpeedChangeTurn;             // 0x13C
    ulong NextLatencyChangeTurn;             // 0x140
    uint ActualLatency[10];                  // 0x144
    uint AverageTSLC[10];                    // 0x16C
    uchar PlayerOptimalFrames[10];           // 0x194
    uchar PlayerOptimalGranularity[10];      // 0x19E
    ushort RequestFasterOrSlower[10];        // 0x1A8
    ulong PlayerAvgFramesMsec[10];           // 0x1BC
    ulong PlayerHighLatencyMsec[10];         // 0x1E4
    ulong HighestLatencyMsec;                // 0x20C
    uint SkipFrames;                         // 0x210
    uint OptimalBufferFrames;                // 0x214
    uint OptimalBufferGranularity;           // 0x218
    uint DiffOffset;                         // 0x21C
    uint AllAcknowledgedBuffersRemaining;    // 0x220
    uint LastAdjusted;                       // 0x224
    ulong RealTimePassed;                    // 0x228
    ulong BufferTimePassed;                  // 0x22C
    uint DroppedFrames;                      // 0x230
    uint DroppedFramesTurn;                  // 0x234
    ulong AdjustmentCount;                   // 0x238
    int LastFrameHadTime;                    // 0x23C

    RGE_Communications_Speed(TCommunications_Handler* param_1);
    virtual ~RGE_Communications_Speed();
    virtual void SetPlayerTurnSpeed(uint param_1, uchar param_2, uchar param_3);
    virtual void SetActualLatency(uint param_1, ulong param_2);
    virtual void SetFutureSpeedChange(uint param_1, uint param_2, ulong param_3);
    virtual void EnableSpeedControl(int param_1);
    virtual uint GetBufferGranularity();
    virtual ulong GetAdjustmentCount();
    virtual uint GetBufferGranularityAdjusted();
    virtual uint BufferFramesRemaining();
    virtual uint WaitingOnAcknowledgement();
    virtual void AdjustLocalSpeed();
    virtual void ReloadBufferFrames();
    virtual uint BufferTimeToUse(ulong param_1);
    virtual void Skip();
    virtual uchar GetHighLatencyCenti();
    virtual ulong GetPlayerLatency(uint param_1);
    virtual char* GetLatencyInfo();
    virtual char* GetSelfPlayerOptimalSpeedStr();
    virtual char* GetPlayerSpeedStatusStr(int param_1);
    virtual char* GetMachineSpeedInfo();
    virtual uint GetRecommendedBufferFrames();
    virtual uint GetAvgFrameRate();
    virtual uint GetRecommendedBufferGranularity();
    virtual int AnalyzeGameSpeed(uint* param_1, uint* param_2, int param_3);
    virtual void SetV1(ulong param_1);
    virtual void SetV2(ulong param_1);
};

static_assert(sizeof(RGE_Communications_Speed) == 0x240, "RGE_Communications_Speed Size Mismatch");
static_assert(offsetof(RGE_Communications_Speed, LastFrameHadTime) == 0x23C, "RGE_Communications_Speed Offset Mismatch");

