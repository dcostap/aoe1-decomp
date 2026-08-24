#include "../../include/com_spd_context.h"

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
