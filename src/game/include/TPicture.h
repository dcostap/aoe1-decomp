#pragma once
#include "common.h"

struct TPicture {
    tagBITMAPINFOHEADER* Dib;
    BITMAPINFO256* BitmapInfo;
    uchar* Bits;
    TRANSINFO* TransInfo;
    int OwnMemory;
    long Width;
    long Height;
    short Orien;
};
static_assert(sizeof(TPicture) == 0x20, "Size mismatch");
