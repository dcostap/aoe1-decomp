#include "../../include/com_spd_context.h"

unsigned int RGE_Communications_Speed::GetBufferGranularityAdjusted() {
    LastFrameHadTime = 1;
    return CurrentBufferGranularity;
}
