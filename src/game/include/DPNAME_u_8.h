#pragma once
#include "common.h"

struct DPNAME_u_8 {
    ushort* lpszShortName;
    char* lpszShortNameA;
};
static_assert(sizeof(DPNAME_u_8) == 0x4, "Size mismatch");
