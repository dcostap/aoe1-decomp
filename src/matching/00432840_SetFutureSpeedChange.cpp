#include "../../include/com_spd_context.h"

void RGE_Communications_Speed::SetFutureSpeedChange(unsigned int buffer_frames,
                                                     unsigned int granularity,
                                                     unsigned long turn_change) {
    if (this->NextLatencyChangeTurn)
        return;
    this->FutureBufferFrames = buffer_frames;
    this->FutureBufferGranularity = granularity;
    this->NextLatencyChangeTurn = turn_change;
}
