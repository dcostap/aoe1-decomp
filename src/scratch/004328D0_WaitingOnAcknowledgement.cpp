#include "../../include/com_spd_context.h"

unsigned int RGE_Communications_Speed::WaitingOnAcknowledgement() {
    return ++this->SkipFrames;
}
