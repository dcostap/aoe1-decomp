#pragma once
#include "common.h"

struct VSpanMiniList {
    uchar Y_delta;
    uchar X_start;
    uchar X_end;
};
static_assert(sizeof(VSpanMiniList) == 0x3, "Size mismatch");
