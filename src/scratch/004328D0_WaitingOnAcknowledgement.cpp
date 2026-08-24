#include "../../include/com_spd_context.h"

void RGE_Communications_Speed::WaitingOnAcknowledgement() {
    this->SkipFrames = this->SkipFrames + 1;
}
