#include "../../include/rge_tslc_context.h"

unsigned long RGE_TimeSinceLastCall::Get() {
    return debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x56) - this->LastCall;
}
