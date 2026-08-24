// Authentic com_spd.cpp owner wrapper.
//
// Module: C:\\msdev\\work\\age1_x1\\com_spd.cpp.
// PDB source order and owner categories:
//   00432620 matching       RGE_Communications_Speed::RGE_Communications_Speed
//   00432780 matching       RGE_Communications_Speed::~RGE_Communications_Speed
//   004327C0 matching       SetPlayerTurnSpeed
//   00432800 observed       SetActualLatency
//   00432840 observed       SetFutureSpeedChange
//   00432870 matching       EnableSpeedControl
//   00432880 matching       GetBufferGranularity
//   00432890 matching       GetAdjustmentCount
//   004328A0 matching       GetBufferGranularityAdjusted
//   004328C0 matching       BufferFramesRemaining
//   004328D0 observed       WaitingOnAcknowledgement
//   004328E0 matching       AdjustLocalSpeed
//   00432940 observed       ReloadBufferFrames
//   00432970 matching       BufferTimeToUse
//   00432A70 matching       Skip
//   00432A90 matching       GetHighLatencyCenti
//   00432B00 matching       GetPlayerLatency
//   00432B20 matching       GetLatencyInfo
//   00432BD0 matching       GetSelfPlayerOptimalSpeedStr
//   00432C10 matching       GetPlayerSpeedStatusStr
//   00432C70 matching       GetMachineSpeedInfo
//   00432D20 matching       GetRecommendedBufferFrames
//   00432D90 observed       GetAvgFrameRate
//   00432DA0 matching       GetRecommendedBufferGranularity
//   00432DE0 accepted_drift AnalyzeGameSpeed
//   00432FB0 matching       SetV1
//   00432FD0 matching       SetV2
// PDB source-line bands are 11-60, 63-67, 70-80, 83-95, 98-112,
// 115-121, 124-126, 129-131, 135-141, 145-148, 151-154, 159-207,
// 210-225, 228-282, 285-289, 293-316, 320-325, 328-343, 346-355,
// 358-374, 377-395, 398-422, 425-427, 431-448, 451-577, 580-582,
// and 585-587, in the same order as the owners above.
//
// No padding-only, compiler-generated, parent-owned, or assembly-region
// entries are in this module packet. The five observed owners are authentic
// compiling sources, but they remain observed until their own body recovery
// work proves exactness. The accepted-drift owner remains accepted drift; this
// wrapper does not promote or retune it.
//
// The shared header is the only class declaration surface. Do not restore
// local duplicate classes or metric-only aliases. Build with the constructor's
// reviewed module flags: config/flags/00432620_RGE_Communications_Speed.rsp
// (/nologo /c /O2 /Oy /GX).

#include "../include/com_spd_context.h"

#include "matching/00432620_RGE_Communications_Speed.cpp"
#include "matching/00432780_RGE_Communications_Speed.cpp"
#include "matching/004327C0_SetPlayerTurnSpeed.cpp"
#include "scratch/00432800_SetActualLatency.cpp"
#include "scratch/00432840_SetFutureSpeedChange.cpp"
#include "matching/00432870_EnableSpeedControl.cpp"
#include "matching/00432880_GetBufferGranularity.cpp"
#include "matching/00432890_GetAdjustmentCount.cpp"
#include "matching/004328A0_GetBufferGranularityAdjusted.cpp"
#include "matching/004328C0_BufferFramesRemaining.cpp"
#include "scratch/004328D0_WaitingOnAcknowledgement.cpp"
#include "matching/004328E0_AdjustLocalSpeed.cpp"
#include "scratch/00432940_ReloadBufferFrames.cpp"
#include "matching/00432970_BufferTimeToUse.cpp"
#include "matching/00432A70_Skip.cpp"
#include "matching/00432A90_GetHighLatencyCenti.cpp"
#include "matching/00432B00_GetPlayerLatency.cpp"
#include "matching/00432B20_GetLatencyInfo.cpp"
#include "matching/00432BD0_GetSelfPlayerOptimalSpeedStr.cpp"
#include "matching/00432C10_GetPlayerSpeedStatusStr.cpp"
#include "matching/00432C70_GetMachineSpeedInfo.cpp"
#include "matching/00432D20_GetRecommendedBufferFrames.cpp"
#include "scratch/00432D90_GetAvgFrameRate.cpp"
#include "matching/00432DA0_GetRecommendedBufferGranularity.cpp"
#include "accepted_drift/00432DE0_AnalyzeGameSpeed.cpp"
#include "matching/00432FB0_SetV1.cpp"
#include "matching/00432FD0_SetV2.cpp"
