class TCommunications_Handler {
public:
    int IsPlayerHuman(unsigned int player);
};

class RGE_Communications_Speed {
public:
    char TBuff[255];
    unsigned char gap_0FF;
    void* TurnTSLC;
    void* FrameTSLC;
    TCommunications_Handler* Comm;
    char gap_10C[0x04];
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

    unsigned int GetRecommendedBufferFrames(void);
};

unsigned int RGE_Communications_Speed::GetRecommendedBufferFrames(void) {
    unsigned int high_latency;
    unsigned int player;
    unsigned int* latency;

    high_latency = 0;
    player = 1;
    latency = &this->ActualLatency[1];
    do {
        if (this->Comm->IsPlayerHuman(player) != 0) {
            if (high_latency <= *latency) {
                high_latency = *latency;
            }
        }
        player++;
        latency++;
    } while ((int)player <= 9);

    high_latency = high_latency / this->CurrentBufferGranularity;
    this->OptimalBufferFrames = high_latency;
    if (high_latency >= 0x14) {
        high_latency = 0x14;
    }
    this->OptimalBufferFrames = high_latency;
    if (high_latency <= 4) {
        high_latency = 4;
    }
    this->OptimalBufferFrames = high_latency + 1;
    return high_latency + 1;
}
