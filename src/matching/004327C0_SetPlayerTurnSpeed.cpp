#include "../../include/com_spd_context.h"

void RGE_Communications_Speed::SetPlayerTurnSpeed(unsigned int player, unsigned char avg_frames_msec, unsigned char high_latency) {
    if (player < 1 || player > 9) {
        return;
    }
    this->PlayerAvgFramesMsec[player] = avg_frames_msec;
    this->PlayerHighLatencyMsec[player] = high_latency * 10;
}
