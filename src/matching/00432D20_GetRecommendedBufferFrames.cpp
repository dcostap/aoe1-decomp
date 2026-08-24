#include "../../include/com_spd_context.h"

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
