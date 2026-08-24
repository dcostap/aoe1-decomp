#include "../../include/com_spd_context.h"

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
