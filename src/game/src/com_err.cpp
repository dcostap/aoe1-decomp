#include "../include/RGE_Comm_Error.h"

#include <windows.h>

RGE_Comm_Error::RGE_Comm_Error(void* host_hwnd) {
    // Fully verified. Source of truth: com_err.cpp.decomp @ 0x00424E40
    this->HostHWND = host_hwnd;
    this->LastReportedError = 0;
}

RGE_Comm_Error::~RGE_Comm_Error() {
    // Fully verified. Source of truth: com_err.cpp.decomp @ 0x00424EA0
}

void RGE_Comm_Error::NotifyWindowParam(COMMMESSAGES msg, long param) {
    // Fully verified. Source of truth: com_err.cpp.decomp @ 0x00424E60
    if (this->HostHWND != nullptr) {
        PostMessageA((HWND)this->HostHWND, WM_USER, (WPARAM)msg, (LPARAM)param);
    }
}

void RGE_Comm_Error::ShowReturn(long hr, const char* /*context*/) {
    // Source of truth: com_err.cpp.decomp @ 0x00424EB0
    // Logging strings are not preserved in this codebase; keep only the behavioral notifications.
    if (hr == 0) {
        return;
    }

    this->LastReportedError = hr;

    switch ((unsigned long)hr) {
        case 0x80004002:  // E_NOINTERFACE
        case 0x80004005:  // E_FAIL
        case 0x80004001:  // E_NOTIMPL (treated as fatal in the original)
            this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
            return;

        // Access denied / busy service / unknown application: treat as "no link".
        case 0x80070005:  // E_ACCESSDENIED
        case 0x8877000A:  // DPERR_ACCESSDENIED
        case 0x8877000E:  // DPERR_BUSY
        case 0x8877010E:  // DPERR_BUSY
        case 0x8877012C:  // DPERR_UNKNOWNAPPLICATION
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;

        // Can't add player / session unavailable: treat as "no new players".
        case 0x88770028:  // DPERR_NOSESSIONS
        case 0x88770088:  // DPERR_INVALIDFLAGS (common failure for session join)
        case 0x887700D8:  // DPERR_CANTADDPLAYER
        case 0x8877014A:  // DPERR_SESSIONBUSY / connecting
        case 0x88770156:  // DPERR_USERCANCEL
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;

        // Timeout received from host.
        case 0x887700F0:  // DPERR_CONNECTING (host busy/timeout path in original)
            this->NotifyWindowParam(COMM_HOST_BUSY, 0);
            return;

        // Lost connection to session.
        case 0x88770136:  // DPERR_CONNECTIONLOST
            this->NotifyWindowParam(COMM_CANCEL_GAME, 0);
            return;
    }
}

