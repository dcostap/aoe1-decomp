#pragma once
#include "common.h"

// WM_USER (0x400) wParam message IDs used by the comm layer.
// Source of truth: com_err.cpp.asm (NotifyWindowParam call sites).
enum COMMMESSAGES : int {
    COMM_CANCEL_GAME = 0x17A8,
    COMM_NO_NEW_PLAYERS = 0x17AB,
    COMM_FATAL_ERROR = 0x17AC,
    COMM_NO_LINK = 0x17AE,
    COMM_HOST_BUSY = 0x17B9,

    // Used by the checksum/sync layer.
    COMM_SYNC_ERROR = 0x17B0,
};

struct RGE_Comm_Error {
    RGE_Comm_Error(void* host_hwnd);
    ~RGE_Comm_Error();

    void NotifyWindowParam(COMMMESSAGES msg, long param);
    void ShowReturn(long hr, const char* context);

    void* HostHWND;
    long LastReportedError;
};
static_assert(sizeof(RGE_Comm_Error) == 0x8, "Size mismatch");
