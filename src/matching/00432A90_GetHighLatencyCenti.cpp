#include "../../include/com_spd_context.h"

unsigned char RGE_Communications_Speed::GetHighLatencyCenti(void) {
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
    } while (player <= 9);

    this->HighestLatencyMsec = high_latency;
    high_latency = (high_latency + 5) / 10;
    if (high_latency <= 1) {
        high_latency = 1;
    }
    if (high_latency >= 0xFF) {
        high_latency = 0xFF;
    }
    return (unsigned char)high_latency;
}
