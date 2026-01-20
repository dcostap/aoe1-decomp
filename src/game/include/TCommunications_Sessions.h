#pragma once
#include "common.h"

struct TCommunications_Sessions {
    int SessionCount;
    SEs Session[501];
    _GUID glpGuid;
    IDirectPlay2* glpIDC;
};
static_assert(sizeof(TCommunications_Sessions) == 0x457B0, "Size mismatch");
