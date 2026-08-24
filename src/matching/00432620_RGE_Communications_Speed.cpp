// VA: 00432620 RGE_Communications_Speed::RGE_Communications_Speed
// com_spd.cpp lines 11-60

#include "../../include/com_spd_context.h"

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
