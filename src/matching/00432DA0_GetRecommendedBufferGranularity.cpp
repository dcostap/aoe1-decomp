#include "../../include/com_spd_context.h"

unsigned int RGE_Communications_Speed::GetRecommendedBufferGranularity(void) {
    unsigned int granularity;

    granularity = this->FrameTSLC->GetAvg(0x32);
    this->OptimalBufferGranularity = granularity;
    if (granularity > 0x96) {
        granularity = 0x96;
    }
    this->OptimalBufferGranularity = granularity;
    if (granularity < 10) {
        granularity = 10;
    }
    this->OptimalBufferGranularity = granularity;
    return granularity;
}
