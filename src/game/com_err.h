#pragma once
#include "../common.h"

class RGE_Comm_Error       {
public:
    void* HostHWND;                          // 0x0
    long LastReportedError;                  // 0x4

    RGE_Comm_Error(void* param_1);

    // --- Non-Virtual Members ---
    void NotifyWindowParam(COMMMESSAGES param_1, long param_2);
    // --- Non-Virtual Destructor ---
    ~RGE_Comm_Error() noexcept(false);
    void ShowReturn(long param_1, char* param_2);
};

static_assert(sizeof(RGE_Comm_Error) == 0x8, "RGE_Comm_Error Size Mismatch");
static_assert(offsetof(RGE_Comm_Error, LastReportedError) == 0x4, "RGE_Comm_Error Offset Mismatch");

