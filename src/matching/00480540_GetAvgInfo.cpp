#include "../../include/rge_tslc_context.h"

char* RGE_TimeSinceLastCall::GetAvgInfo(int value) {
    unsigned long avg;
    int count;

    count = value;
    avg = GetAvg(count);
    sprintf((char*)this, "Avg %d / %d", avg, count);
    return (char*)this;
}
