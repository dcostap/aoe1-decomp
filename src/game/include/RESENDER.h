#pragma once
#include "common.h"

struct RESENDER {
    RESENDER();
    ~RESENDER();
    void* vector_deleting_destructor(uint param_1);

    ulong TimeSent;
    uint Serial;
    char* ResendMsg;
    uint Length;
    uint DestMap[10];
};
static_assert(sizeof(RESENDER) == 0x38, "Size mismatch");
