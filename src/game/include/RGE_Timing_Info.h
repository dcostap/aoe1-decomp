#pragma once
#include "common.h"

struct RGE_Timing_Info {
    ulong accum_time;
    ulong last_time;
    ulong start_time;
    int include_in_total;
    int is_summary;
    ulong last_single_time;
    ulong max_time;
    ulong last_max_time;
};
static_assert(sizeof(RGE_Timing_Info) == 0x20, "Size mismatch");
