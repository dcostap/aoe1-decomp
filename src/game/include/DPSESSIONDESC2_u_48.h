#pragma once
#include "common.h"

struct DPSESSIONDESC2_u_48 {
    ushort* lpszSessionName;
    char* lpszSessionNameA;
};
static_assert(sizeof(DPSESSIONDESC2_u_48) == 0x4, "Size mismatch");
