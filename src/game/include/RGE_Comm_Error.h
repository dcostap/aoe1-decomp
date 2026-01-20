#pragma once
#include "common.h"

struct RGE_Comm_Error {
    void* HostHWND;
    long LastReportedError;
};
static_assert(sizeof(RGE_Comm_Error) == 0x8, "Size mismatch");
