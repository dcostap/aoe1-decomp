class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    unsigned long current_turn;
};

class RGE_Communications_Speed {
public:
    char gap_00[0x108];
    TCommunications_Handler* Comm;
    char gap_10C[0x10];
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
    char gap_144[0xE0];
    unsigned int LastAdjusted;
    char gap_228[0x10];
    unsigned long AdjustmentCount;

    void AdjustLocalSpeed(void);
};

void RGE_Communications_Speed::AdjustLocalSpeed(void) {
    unsigned long next_latency_change_turn;
    TCommunications_Handler* comm;
    unsigned int adjustment_count;

    next_latency_change_turn = this->NextLatencyChangeTurn;
    if (next_latency_change_turn == 0) {
        return;
    }

    comm = this->Comm;
    this->LastAdjusted = 0;
    if (comm->current_turn < next_latency_change_turn) {
        return;
    }

    adjustment_count = this->AdjustmentCount;
    this->NextLatencyChangeTurn = 0;
    adjustment_count++;
    this->AdjustmentCount = adjustment_count;
    this->CurrentBufferFrames = this->FutureBufferFrames;
    this->CurrentBufferGranularity = this->FutureBufferGranularity;
    this->FutureBufferFrames = 0;
    this->FutureBufferGranularity = 0;
}
