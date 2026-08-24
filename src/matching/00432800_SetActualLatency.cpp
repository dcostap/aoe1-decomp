#include "../../include/com_spd_context.h"

void RGE_Communications_Speed::SetActualLatency(unsigned int player, unsigned long latency) {
    if (player >= 1 && player <= 9) {
        if (latency < 30)
            latency = 30;
        if (latency > 6000)
            latency = 6000;
        this->ActualLatency[player] = latency;
    }
}
