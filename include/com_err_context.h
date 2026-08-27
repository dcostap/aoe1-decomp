#ifndef AOE1_COM_ERR_CONTEXT_H
#define AOE1_COM_ERR_CONTEXT_H

// Canonical com_err.cpp surface for the four contiguous owners below.
// The enum spelling is required by the PDB-qualified NotifyWindowParam symbol.

enum COMMMESSAGES {
    COMM_NO_NEW_PLAYERS = 0x17AB,
    COMM_FATAL_ERROR = 0x17AC,
    COMM_HOST_BUSY = 0x17A8,
    COMM_NO_LINK = 0x17AE,
    COMM_CANCEL_GAME = 0x17B9,
};

class TDebuggingLog;
extern TDebuggingLog* L;
// The PDB-qualified 00436610 target is TDebuggingLog::Log(char*, ...).
// Its QAAX decoration proves the cdecl member surface, with L passed on the
// stack.  Keep the owner declaration aligned with include/debuglog.h.
class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern "C" __declspec(dllimport) int __stdcall PostMessageA(
    void* hWnd, unsigned int message, unsigned int wParam, long lParam);

class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;

    RGE_Comm_Error(void* param);
    ~RGE_Comm_Error();
    void NotifyWindowParam(COMMMESSAGES message, long param);
    void ShowReturn(long code, char* context);
};

#endif
