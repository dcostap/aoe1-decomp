#include "../../include/com_spd_context.h"

unsigned long RGE_Communications_Speed::GetPlayerLatency(unsigned int player) {
    if (player < 1 || player > 9) {
        return 0;
    }
    return this->ActualLatency[player];
}
