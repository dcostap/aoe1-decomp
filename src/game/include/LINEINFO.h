#pragma once
#include "common.h"

struct LINEINFO {
    int AllTrans;
    int MidSolid;
    long StartX;
    long EndX;
};
static_assert(sizeof(LINEINFO) == 0x10, "Size mismatch");
