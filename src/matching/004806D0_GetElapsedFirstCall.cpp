#include "../../include/rge_tslc_context.h"

char* RGE_TimeSinceLastCall::GetElapsedFirstCall()
{
    long hours = 0;
    long minutes = 0;
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0xB5);
    Now = now;
    int elapsed = (int)((now - FirstCall) / 1000);

    if (elapsed > 59) {
        minutes = elapsed / 60;
        elapsed = elapsed - minutes * 60;
        if (minutes > 59) {
            hours = minutes / 60;
            minutes = minutes - hours * 60;
        }
    }

    sprintf(TBuff, "%02ld:%02ld:%02ld", hours, minutes, elapsed);
    return TBuff;
}
