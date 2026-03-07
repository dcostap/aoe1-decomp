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
    // Fully verified. Source of truth: com_err.cpp.decomp @ 0x00424E60, com_err.cpp.asm @ 0x00424E60
    PostMessageA((HWND)this->HostHWND, WM_USER, (WPARAM)msg, (LPARAM)param);
}

void RGE_Comm_Error::ShowReturn(long hr, const char* context) {
    // Fully verified. Source of truth: com_err.cpp.decomp @ 0x00424EB0, com_err.cpp.asm @ 0x00424EB0
    (void)context;

    if (hr == 0) {
        return;
    }

    this->LastReportedError = hr;

    if (hr < -0x7FFFBFFE) {
        if (hr == -0x7FFFBFFF) {
            return;
        }
        if (hr == -0x7FFFFFF6) {
            return;
        }
    } else if (hr < -0x7FFBFEEF) {
        if (hr == -0x7FFBFEF0) {
            return;
        }
        switch (hr) {
        case -0x7FFFBFFE:
            this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
            return;
        case -0x7FFFBFFD:
            return;
        case -0x7FFFBFFC:
            return;
        case -0x7FFFBFFB:
            this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
            return;
        default:
            break;
        }
    } else if (hr < -0x7FF8FFF1) {
        if (hr == -0x7FF8FFF2) {
            return;
        }
        if (hr == -0x7FF8FFFB) {
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;
        }
        if (hr == -0x7FF8FFFA) {
            return;
        }
    } else if (hr < -0x7788FFFA) {
        if (hr == -0x7788FFFB) {
            return;
        }
        if (hr == -0x7FF8FFA9) {
            return;
        }
    } else if (hr < -0x7788FFEB) {
        if (hr == -0x7788FFEC) {
            return;
        }
        if (hr == -0x7788FFF6) {
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;
        }
    } else if (hr < -0x7788FFD7) {
        if (hr == -0x7788FFD8) {
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
        if (hr == -0x7788FFE2) {
            return;
        }
    } else if (hr < -0x7788FFC3) {
        if (hr == -0x7788FFC4) {
            return;
        }
        if (hr == -0x7788FFCE) {
            return;
        }
    } else if (hr < -0x7788FFAF) {
        if (hr == -0x7788FFB0) {
            return;
        }
        if (hr == -0x7788FFBA) {
            return;
        }
    } else if (hr < -0x7788FF87) {
        if (hr == -0x7788FF88) {
            return;
        }
        if (hr == -0x7788FFA6) {
            return;
        }
    } else if (hr < -0x7788FF69) {
        if (hr == -0x7788FF6A) {
            return;
        }
        if (hr == -0x7788FF7E) {
            return;
        }
    } else if (hr < -0x7788FF5F) {
        if (hr == -0x7788FF60) {
            return;
        }
        if (hr == -0x7788FF65) {
            return;
        }
    } else if (hr < -0x7788FF41) {
        if (hr == -0x7788FF42) {
            return;
        }
        if (hr == -0x7788FF56) {
            return;
        }
    } else if (hr < -0x7788FF2D) {
        if (hr == -0x7788FF2E) {
            return;
        }
        if (hr == -0x7788FF38) {
            return;
        }
    } else if (hr < -0x7788FF19) {
        if (hr == -0x7788FF1A) {
            return;
        }
        if (hr == -0x7788FF24) {
            return;
        }
    } else if (hr < -0x7788FF05) {
        if (hr == -0x7788FF06) {
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
        if (hr == -0x7788FF10) {
            this->NotifyWindowParam(COMM_HOST_BUSY, 0);
            return;
        }
    } else if (hr < -0x7788FEE7) {
        if (hr == -0x7788FEE8) {
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;
        }
        if (hr == -0x7788FEF2) {
            return;
        }
    } else if (hr < -0x7788FED3) {
        if (hr == -0x7788FED4) {
            return;
        }
        if (hr == -0x7788FEDE) {
            return;
        }
    } else if (hr < -0x7788FEBF) {
        if (hr == -0x7788FEC0) {
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;
        }
        if (hr == -0x7788FECA) {
            this->NotifyWindowParam(COMM_CANCEL_GAME, 0);
            return;
        }
    } else if (hr < -0x7788FEAB) {
        if (hr == -0x7788FEAC) {
            return;
        }
        if (hr == -0x7788FEB6) {
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
    } else if (hr < -0x7788FC17) {
        if (hr == -0x7788FC18) {
            return;
        }
        if (hr == -0x7788FEA2) {
            return;
        }
    } else if (hr < -0x7788FC03) {
        if (hr == -0x7788FC04) {
            return;
        }
        if (hr == -0x7788FC0E) {
            return;
        }
    } else if (hr < -0x7788FBE5) {
        if (hr == -0x7788FBE6) {
            return;
        }
        if (hr == -0x7788FBF0) {
            return;
        }
    } else if (hr < -0x7788F82F) {
        if (hr == -0x7788F830) {
            return;
        }
        if (hr == -0x7788FBD2) {
            return;
        }
    } else if (hr < -0x7788F81B) {
        if (hr == -0x7788F81C) {
            return;
        }
        if (hr == -0x7788F826) {
            return;
        }
    } else if (hr < -0x7788F807) {
        if (hr == -0x7788F808) {
            return;
        }
        if (hr == -0x7788F812) {
            return;
        }
    } else {
        if (hr == -0x7788F7F4) {
            return;
        }
        if (hr == -0x7788F7E0) {
            return;
        }
    }
}


