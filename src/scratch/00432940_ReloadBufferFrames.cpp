#include "../../include/com_spd_context.h"

void RGE_Communications_Speed::ReloadBufferFrames(void) {
    this->TurnTSLC->Set();
    this->DroppedFramesTurn = 0;
    this->AdjustLocalSpeed();
    this->TotalBufferFramesRemaining = this->CurrentBufferFrames;
}
