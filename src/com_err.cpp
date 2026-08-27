// PDB source module: C:\\msdev\\work\\age1_x1\\com_err.cpp.
// The four handwritten owners stay in PDB source order.

#include <windows.h>

#include "../include/com_err.h"
#include "../include/debuglog.h"

// 00424E40; com_err.cpp lines 6-9.
RGE_Comm_Error::RGE_Comm_Error(void* param) {
    HostHWND = param;
    LastReportedError = 0;
}

// 00424E60; com_err.cpp lines 12-15.
void RGE_Comm_Error::NotifyWindowParam(COMMMESSAGES msg, long param) {
    PostMessageA(HostHWND, 0x400, msg, param);
    L->Log("COMM: Send msg to window WM_USER  Msg=%d  Param=%d\n", msg, param);
}

// 00424EA0; com_err.cpp line 19.
RGE_Comm_Error::~RGE_Comm_Error() {}

// 00424EB0; com_err.cpp lines 23-380.
// The threshold tree and empty non-match arms preserve the original handler
// layout and shared default fallthrough.
void RGE_Comm_Error::ShowReturn(long code, char* context) {
    if (code == 0) {
        return;
    }

    L->Log("+++COMM______DP CALL FAILED_(Code %u)_____ %s\n", code, context);
    this->LastReportedError = code;

    if (code <= (long)0x80004001) {
        if (code != (long)0x80004001) {
            if (code == (long)0x8000000A) {
                L->Log("COM Error pending");
                return;
            }
        } else {
            L->Log("!!! Unsupported.");
            return;
        }
    } else if (code <= (long)0x80040110) {
        if (code != (long)0x80040110) {
            switch (code) {
            case (long)0x80004005:
                L->Log("!!! GENERIC (Undefined) ERROR ");
                this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                return;
            case (long)0x80004002:
                this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                L->Log("!!! No Interface");
                return;
            case (long)0x80004003:
                L->Log("COM Invalid Pointer");
                return;
            case (long)0x80004004:
                L->Log("COM Aborted");
                return;
            }
        } else {
            L->Log("!!! COMM: CLASS NO AGGREGATION.");
            return;
        }
    } else if (code <= (long)0x8007000E) {
        if (code != (long)0x8007000E) {
            if (code != (long)0x80070005) {
                if (code == (long)0x80070006) {
                    L->Log("COM Invalid Handle");
                    return;
                }
            } else {
                L->Log("COM error Access Denied");
                this->NotifyWindowParam(COMM_NO_LINK, 0);
                return;
            }
        } else {
            L->Log("!!! Out Of Memory");
            return;
        }
    } else if (code <= (long)0x88770005) {
        if (code != (long)0x88770005) {
            if (code == (long)0x80070057) {
                L->Log("!!! Invalid Params");
                return;
            }
        } else {
            L->Log("!!! Already Initialized");
            return;
        }
    } else if (code <= (long)0x88770014) {
        if (code != (long)0x88770014) {
            if (code == (long)0x8877000A) {
                L->Log("!!! Access Denied - busy service or invalid use of host commands.");
                this->NotifyWindowParam(COMM_NO_LINK, 0);
                return;
            }
        } else {
            L->Log("!!! Active Players - command invalid with active players.");
            return;
        }
    } else if (code <= (long)0x88770028) {
        if (code != (long)0x88770028) {
            if (code == (long)0x8877001E) {
                L->Log("!!! Buffer size failure (SMALL)");
                return;
            }
        } else {
            L->Log("!!! Can't Add Player");
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
    } else if (code <= (long)0x8877003C) {
        if (code != (long)0x8877003C) {
            if (code == (long)0x88770032) {
                L->Log("!!! Can't Create Group");
                return;
            }
        } else {
            L->Log("!!! Can't create player.");
            return;
        }
    } else if (code <= (long)0x88770050) {
        if (code != (long)0x88770050) {
            if (code == (long)0x88770046) {
                L->Log("!!! Can't create session.");
                return;
            }
        } else {
            L->Log("!!! Device caps are not available.");
            L->Log("!!! ERROR!");
            return;
        }
    } else if (code <= (long)0x88770078) {
        if (code != (long)0x88770078) {
            if (code == (long)0x8877005A) {
                L->Log("!!! Exception Raised");
                return;
            }
        } else {
            L->Log("!!! Invalid Flags");
            return;
        }
    } else if (code <= (long)0x88770096) {
        if (code != (long)0x88770096) {
            if (code == (long)0x88770082) {
                L->Log("!!! Invalid Object");
                return;
            }
        } else {
            L->Log("!!! Invalid Player");
            return;
        }
    } else if (code <= (long)0x887700A0) {
        if (code != (long)0x887700A0) {
            if (code == (long)0x8877009B) {
                L->Log("!!! Invalid Group");
                return;
            }
        } else {
            L->Log("!!! Not able to do multipayer!");
            return;
        }
    } else if (code <= (long)0x887700BE) {
        if (code != (long)0x887700BE) {
            if (code == (long)0x887700AA) {
                L->Log("!!! No Connection");
                return;
            }
        } else {
            L->Log("!!! No messages");
            return;
        }
    } else if (code <= (long)0x887700D2) {
        if (code != (long)0x887700D2) {
            if (code == (long)0x887700C8) {
                L->Log("!!! No name server running!");
                return;
            }
        } else {
            L->Log("!!! No players are connected!");
            return;
        }
    } else if (code <= (long)0x887700E6) {
        if (code != (long)0x887700E6) {
            if (code == (long)0x887700DC) {
                L->Log("!!! No sessions are available");
                return;
            }
        } else {
            L->Log("!!! Send overflow!");
            return;
        }
    } else if (code <= (long)0x887700FA) {
        if (code != (long)0x887700FA) {
            if (code == (long)0x887700F0) {
                L->Log("!!! COMM TIMEOUT Rcvd from HOST connection.");
                this->NotifyWindowParam(COMM_CANCEL_GAME, 0);
                return;
            }
        } else {
            L->Log("!!! Communications - Session is full");
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
    } else if (code <= (long)0x88770118) {
        if (code != (long)0x88770118) {
            if (code == (long)0x8877010E) {
                L->Log("!!! Busy Rcvd");
                return;
            }
        } else {
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            L->Log("!!! User Cancel");
            return;
        }
    } else if (code <= (long)0x8877012C) {
        if (code != (long)0x8877012C) {
            if (code == (long)0x88770122) {
                L->Log("!!! Unable to create server");
                return;
            }
        } else {
            L->Log("!!! Player Lost connection.");
            return;
        }
    } else if (code <= (long)0x88770140) {
        if (code != (long)0x88770140) {
            if (code == (long)0x88770136) {
                L->Log("!!! Lost connection to session.");
                this->NotifyWindowParam(COMM_HOST_BUSY, 0);
                return;
            }
        } else {
            L->Log("!!! Unknown application specified");
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;
        }
    } else if (code <= (long)0x88770154) {
        if (code != (long)0x88770154) {
            if (code == (long)0x8877014A) {
                this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                L->Log("!!! The session is in the process of connecting");
                return;
            }
        } else {
            L->Log("!!! The secure password is invalid.");
            return;
        }
    } else if (code <= (long)0x887703E8) {
        if (code != (long)0x887703E8) {
            if (code == (long)0x8877015E) {
                L->Log("!!! The session is in the process of connecting");
                return;
            }
        } else {
            L->Log("!!! Buffer size failure (LARGE)");
            return;
        }
    } else if (code <= (long)0x887703FC) {
        if (code != (long)0x887703FC) {
            if (code == (long)0x887703F2) {
                L->Log("!!! Can't start the application.");
                return;
            }
        } else {
            L->Log("!!! Application has not been started yet.");
            return;
        }
    } else if (code <= (long)0x8877041A) {
        if (code != (long)0x8877041A) {
            if (code != (long)0x88770410) {
            } else {
                return;
            }
        } else {
            L->Log("!!! Unknown application specified");
            return;
        }
    } else if (code <= (long)0x887707D0) {
        if (code != (long)0x887707D0) {
            if (code == (long)0x8877042E) {
                L->Log("!!! Security authentify failed.");
                return;
            }
        } else {
            L->Log("!!! Not A Lobby Session");
            return;
        }
    } else if (code <= (long)0x887707E4) {
        if (code != (long)0x887707E4) {
            if (code == (long)0x887707DA) {
                L->Log("!!! Can't load security SSPI package.");
                return;
            }
        } else {
            L->Log("!!! The encryption failed.");
            return;
        }
    } else if (code <= (long)0x887707F8) {
        if (code != (long)0x887707F8) {
            if (code == (long)0x887707EE) {
                L->Log("!!! The security sign failed.");
                return;
            }
        } else {
            L->Log("!!! Can't load security package.");
            return;
        }
    } else {
        if (code != (long)0x8877080C) {
            if (code != (long)0x88770820) {
            } else {
                L->Log("!!! The secure logon failed.");
                return;
            }
        } else {
            L->Log("!!! Can't load CAPI");
            return;
        }
    }

    L->Log("!!! %s: Unhandled DP ERROR/exception in call.  Result=%ld  (%d)", context, code, code);
}
