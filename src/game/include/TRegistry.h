#pragma once
#include "common.h"

struct TRegistry {
    void* ghMachineKey;
    void* ghUserKey;
    void* ghMachineKeyRead;
    ulong gdwDisp;
    char Data[255];
};
static_assert(sizeof(TRegistry) == 0x110, "Size mismatch");
