#include "../../include/com_spd_context.h"

void operator_delete(void* ptr);

RGE_Communications_Speed::~RGE_Communications_Speed(void) {
    RGE_TimeSinceLastCall* tslc;

    tslc = this->FrameTSLC;
    if (tslc != 0) {
        tslc->~RGE_TimeSinceLastCall();
        operator_delete(tslc);
    }

    tslc = this->TurnTSLC;
    if (tslc != 0) {
        tslc->~RGE_TimeSinceLastCall();
        operator_delete(tslc);
    }
}
