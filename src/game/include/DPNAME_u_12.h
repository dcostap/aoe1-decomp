#pragma once
#include "common.h"

struct DPNAME_u_12 {
    ushort* lpszLongName;
    char* lpszLongNameA;
};
static_assert(sizeof(DPNAME_u_12) == 0x4, "Size mismatch");
