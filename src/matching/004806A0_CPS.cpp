#include "../../include/rge_tslc_context.h"

unsigned long RGE_TimeSinceLastCall::CPS() {
    this->cps = 0;
    GetAvg(100);
    return this->cps;
}
