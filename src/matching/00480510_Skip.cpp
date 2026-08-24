#include "../../include/rge_tslc_context.h"

void RGE_TimeSinceLastCall::Skip(void) {
    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x78);
    this->LastCall = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x79);
}
