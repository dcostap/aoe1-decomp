#pragma once
#include "common.h"

struct DPSESSIONDESC2_u_52 {
    ushort* lpszPassword;
    char* lpszPasswordA;
};
static_assert(sizeof(DPSESSIONDESC2_u_52) == 0x4, "Size mismatch");
