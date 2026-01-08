#pragma once
#include "../common.h"
#include "RGE_TSLC.h"

class TCommunications_Handler;

class RGE_Communications_Speed       {
public:
    char TBuff[255];                         // 0x0
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

    // --- Non-Virtual Destructor ---
    ~RGE_Communications_Speed() noexcept(false);
    // --- Non-Virtual Members ---
    void SetPlayerTurnSpeed(uint param_1, uchar param_2, uchar param_3);
    void SetActualLatency(uint param_1, ulong param_2);
    void SetFutureSpeedChange(uint param_1, uint param_2, ulong param_3);
    void EnableSpeedControl(int param_1);
    uint GetBufferGranularity();
    ulong GetAdjustmentCount();
    uint GetBufferGranularityAdjusted();
    uint BufferFramesRemaining();
    uint WaitingOnAcknowledgement();
    void AdjustLocalSpeed();
    void ReloadBufferFrames();
    uint BufferTimeToUse(ulong param_1);
    void Skip();
    uchar GetHighLatencyCenti();
    ulong GetPlayerLatency(uint param_1);
    char* GetLatencyInfo();
    char* GetSelfPlayerOptimalSpeedStr();
    char* GetPlayerSpeedStatusStr(int param_1);
    char* GetMachineSpeedInfo();
    uint GetRecommendedBufferFrames();
    uint GetAvgFrameRate();
    uint GetRecommendedBufferGranularity();
    int AnalyzeGameSpeed(uint* param_1, uint* param_2, int param_3);
    void SetV1(ulong param_1);
    void SetV2(ulong param_1);
};

static_assert(sizeof(RGE_Communications_Speed) == 0x240, "RGE_Communications_Speed Size Mismatch");
static_assert(offsetof(RGE_Communications_Speed, LastFrameHadTime) == 0x23C, "RGE_Communications_Speed Offset Mismatch");

