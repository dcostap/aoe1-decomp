#pragma once
#include "common.h"

struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO* LineInfo;
};
static_assert(sizeof(TRANSINFO) == 0x18, "Size mismatch");
