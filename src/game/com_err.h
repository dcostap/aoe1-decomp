#pragma once
#include "../common.h"

class RGE_Comm_Error {
public:
    long LastReportedError;                  // 0x4

    RGE_Comm_Error(void* param_1);
    virtual void NotifyWindowParam(COMMMESSAGES param_1, long param_2);
    virtual ~RGE_Comm_Error();
    virtual void ShowReturn(long param_1, char* param_2);
};

static_assert(sizeof(RGE_Comm_Error) == 0x8, "RGE_Comm_Error Size Mismatch");
static_assert(offsetof(RGE_Comm_Error, LastReportedError) == 0x4, "RGE_Comm_Error Offset Mismatch");

