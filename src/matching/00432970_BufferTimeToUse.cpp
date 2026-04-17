class RGE_TimeSinceLastCall {
public:
    unsigned long Set(void);
    void Skip(void);
    unsigned long Get(void);
};

class TCommunications_Handler {
public:
    int AllPlayersAcknowledged(void);
};

class RGE_Communications_Speed {
public:
    char TBuff[255];
    unsigned char gap_0FF;
    RGE_TimeSinceLastCall* TurnTSLC;
    RGE_TimeSinceLastCall* FrameTSLC;
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
    unsigned int DiffOffset;
    unsigned int AllAcknowledgedBuffersRemaining;
    unsigned int LastAdjusted;
    unsigned long RealTimePassed;
    unsigned long BufferTimePassed;
    unsigned int DroppedFrames;
    unsigned int DroppedFramesTurn;
    unsigned long AdjustmentCount;
    int LastFrameHadTime;

    unsigned int BufferTimeToUse(unsigned long param_1);
};

unsigned int RGE_Communications_Speed::BufferTimeToUse(unsigned long param_1) {
    if (this->LastFrameHadTime != 0) {
        this->FrameTSLC->Set();
    } else {
        this->FrameTSLC->Skip();
    }

    this->LastFrameHadTime = 0;
    if (this->TotalBufferFramesRemaining <= 0) {
        this->LastFrameHadTime = 0;
        return 0;
    }

    this->RealTimePassed = this->TurnTSLC->Get();
    if (this->Comm->AllPlayersAcknowledged() != 0) {
        this->AllAcknowledgedBuffersRemaining = this->AllAcknowledgedBuffersRemaining + this->TotalBufferFramesRemaining;
    }

    this->BufferTimePassed = (this->CurrentBufferFrames - this->TotalBufferFramesRemaining) * this->CurrentBufferGranularity;
    if (this->OverheadFactor + this->RealTimePassed < this->BufferTimePassed) {
        if (param_1 > 6) {
            this->DroppedFrames = this->DroppedFrames + 1;
            this->DroppedFramesTurn = this->DroppedFramesTurn + 1;
        }
        this->LastFrameHadTime = 0;
        return 0;
    }

    this->LastFrameHadTime = 1;
    this->TotalBufferFramesRemaining = this->TotalBufferFramesRemaining - 1;
    return this->CurrentBufferGranularity;
}
