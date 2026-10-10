
#include <windows.h>

#include "../third_party/directplay/include/dplay.h"

#include "../include/com_err.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"

RGE_Comm_Error::RGE_Comm_Error(void* Host) {
    HostHWND = Host;
    LastReportedError = 0;
}

void RGE_Comm_Error::NotifyWindowParam(COMMMESSAGES msg, long lparam) {
    PostMessageA(HostHWND, WM_USER, msg, lparam);
    L->Log("COMM: Send msg to window WM_USER  Msg=%d  Param=%d\n", msg, lparam);
}

RGE_Comm_Error::~RGE_Comm_Error() {
}

// The threshold tree and empty non-match arms preserve the original handler
// layout and shared default fallthrough.
// Some original log texts do not describe their codes: DPERR_UNINITIALIZED logs an unknown
// application, DPERR_NONEWPLAYERS logs connecting, and the NOTLOBBIED and
// AUTHENTICATIONFAILED messages are swapped.
void RGE_Comm_Error::ShowReturn(long hr, char* Text) {
    if (hr == 0) {
        return;
    }

    L->Log("+++COMM______DP CALL FAILED_(Code %u)_____ %s\n", hr, Text);
    this->LastReportedError = hr;

    if (hr <= DPERR_UNSUPPORTED) {
        if (hr != DPERR_UNSUPPORTED) {
            if (hr == DPERR_PENDING) {
                L->Log("COM Error pending");
                return;
            }
        } else {
            L->Log("!!! Unsupported.");
            return;
        }
    } else if (hr <= CLASS_E_NOAGGREGATION) {
        if (hr != CLASS_E_NOAGGREGATION) {
            switch (hr) {
                case DPERR_GENERIC:
                    L->Log("!!! GENERIC (Undefined) ERROR ");
                    this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                    return;
                case DPERR_NOINTERFACE:
                    this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                    L->Log("!!! No Interface");
                    return;
                case E_POINTER:
                    L->Log("COM Invalid Pointer");
                    return;
                case E_ABORT:
                    L->Log("COM Aborted");
                    return;
            }
        } else {
            L->Log("!!! COMM: CLASS NO AGGREGATION.");
            return;
        }
    } else if (hr <= DPERR_OUTOFMEMORY) {
        if (hr != DPERR_OUTOFMEMORY) {
            if (hr != E_ACCESSDENIED) {
                if (hr == E_HANDLE) {
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
    } else if (hr <= DPERR_ALREADYINITIALIZED) {
        if (hr != DPERR_ALREADYINITIALIZED) {
            if (hr == DPERR_INVALIDPARAMS) {
                L->Log("!!! Invalid Params");
                return;
            }
        } else {
            L->Log("!!! Already Initialized");
            return;
        }
    } else if (hr <= DPERR_ACTIVEPLAYERS) {
        if (hr != DPERR_ACTIVEPLAYERS) {
            if (hr == DPERR_ACCESSDENIED) {
                L->Log("!!! Access Denied - busy service or invalid use of host commands.");
                this->NotifyWindowParam(COMM_NO_LINK, 0);
                return;
            }
        } else {
            L->Log("!!! Active Players - command invalid with active players.");
            return;
        }
    } else if (hr <= DPERR_CANTADDPLAYER) {
        if (hr != DPERR_CANTADDPLAYER) {
            if (hr == DPERR_BUFFERTOOSMALL) {
                L->Log("!!! Buffer size failure (SMALL)");
                return;
            }
        } else {
            L->Log("!!! Can't Add Player");
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
    } else if (hr <= DPERR_CANTCREATEPLAYER) {
        if (hr != DPERR_CANTCREATEPLAYER) {
            if (hr == DPERR_CANTCREATEGROUP) {
                L->Log("!!! Can't Create Group");
                return;
            }
        } else {
            L->Log("!!! Can't create player.");
            return;
        }
    } else if (hr <= DPERR_CAPSNOTAVAILABLEYET) {
        if (hr != DPERR_CAPSNOTAVAILABLEYET) {
            if (hr == DPERR_CANTCREATESESSION) {
                L->Log("!!! Can't create session.");
                return;
            }
        } else {
            L->Log("!!! Device caps are not available.");
            L->Log("!!! ERROR!");
            return;
        }
    } else if (hr <= DPERR_INVALIDFLAGS) {
        if (hr != DPERR_INVALIDFLAGS) {
            if (hr == DPERR_EXCEPTION) {
                L->Log("!!! Exception Raised");
                return;
            }
        } else {
            L->Log("!!! Invalid Flags");
            return;
        }
    } else if (hr <= DPERR_INVALIDPLAYER) {
        if (hr != DPERR_INVALIDPLAYER) {
            if (hr == DPERR_INVALIDOBJECT) {
                L->Log("!!! Invalid Object");
                return;
            }
        } else {
            L->Log("!!! Invalid Player");
            return;
        }
    } else if (hr <= DPERR_NOCAPS) {
        if (hr != DPERR_NOCAPS) {
            if (hr == DPERR_INVALIDGROUP) {
                L->Log("!!! Invalid Group");
                return;
            }
        } else {
            L->Log("!!! Not able to do multipayer!");
            return;
        }
    } else if (hr <= DPERR_NOMESSAGES) {
        if (hr != DPERR_NOMESSAGES) {
            if (hr == DPERR_NOCONNECTION) {
                L->Log("!!! No Connection");
                return;
            }
        } else {
            L->Log("!!! No messages");
            return;
        }
    } else if (hr <= DPERR_NOPLAYERS) {
        if (hr != DPERR_NOPLAYERS) {
            if (hr == DPERR_NONAMESERVERFOUND) {
                L->Log("!!! No name server running!");
                return;
            }
        } else {
            L->Log("!!! No players are connected!");
            return;
        }
    } else if (hr <= DPERR_SENDTOOBIG) {
        if (hr != DPERR_SENDTOOBIG) {
            if (hr == DPERR_NOSESSIONS) {
                L->Log("!!! No sessions are available");
                return;
            }
        } else {
            L->Log("!!! Send overflow!");
            return;
        }
    } else if (hr <= DPERR_UNAVAILABLE) {
        if (hr != DPERR_UNAVAILABLE) {
            if (hr == DPERR_TIMEOUT) {
                L->Log("!!! COMM TIMEOUT Rcvd from HOST connection.");
                this->NotifyWindowParam(COMM_HOST_BUSY, 0);
                return;
            }
        } else {
            L->Log("!!! Communications - Session is full");
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
    } else if (hr <= DPERR_USERCANCEL) {
        if (hr != DPERR_USERCANCEL) {
            if (hr == DPERR_BUSY) {
                L->Log("!!! Busy Rcvd");
                return;
            }
        } else {
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            L->Log("!!! User Cancel");
            return;
        }
    } else if (hr <= DPERR_PLAYERLOST) {
        if (hr != DPERR_PLAYERLOST) {
            if (hr == DPERR_CANNOTCREATESERVER) {
                L->Log("!!! Unable to create server");
                return;
            }
        } else {
            L->Log("!!! Player Lost connection.");
            return;
        }
    } else if (hr <= DPERR_UNINITIALIZED) {
        if (hr != DPERR_UNINITIALIZED) {
            if (hr == DPERR_SESSIONLOST) {
                L->Log("!!! Lost connection to session.");
                this->NotifyWindowParam(COMM_CANCEL_GAME, 0);
                return;
            }
        } else {
            L->Log("!!! Unknown application specified");
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;
        }
    } else if (hr <= DPERR_INVALIDPASSWORD) {
        if (hr != DPERR_INVALIDPASSWORD) {
            if (hr == DPERR_NONEWPLAYERS) {
                this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                L->Log("!!! The session is in the process of connecting");
                return;
            }
        } else {
            L->Log("!!! The secure password is invalid.");
            return;
        }
    } else if (hr <= DPERR_BUFFERTOOLARGE) {
        if (hr != DPERR_BUFFERTOOLARGE) {
            if (hr == DPERR_CONNECTING) {
                L->Log("!!! The session is in the process of connecting");
                return;
            }
        } else {
            L->Log("!!! Buffer size failure (LARGE)");
            return;
        }
    } else if (hr <= DPERR_APPNOTSTARTED) {
        if (hr != DPERR_APPNOTSTARTED) {
            if (hr == DPERR_CANTCREATEPROCESS) {
                L->Log("!!! Can't start the application.");
                return;
            }
        } else {
            L->Log("!!! Application has not been started yet.");
            return;
        }
    } else if (hr <= DPERR_UNKNOWNAPPLICATION) {
        if (hr != DPERR_UNKNOWNAPPLICATION) {
            if (hr != DPERR_NOSERVICEPROVIDER) {
            } else {
                return;
            }
        } else {
            L->Log("!!! Unknown application specified");
            return;
        }
    } else if (hr <= DPERR_AUTHENTICATIONFAILED) {
        if (hr != DPERR_AUTHENTICATIONFAILED) {
            if (hr == DPERR_NOTLOBBIED) {
                L->Log("!!! Security authentify failed.");
                return;
            }
        } else {
            L->Log("!!! Not A Lobby Session");
            return;
        }
    } else if (hr <= DPERR_ENCRYPTIONFAILED) {
        if (hr != DPERR_ENCRYPTIONFAILED) {
            if (hr == DPERR_CANTLOADSSPI) {
                L->Log("!!! Can't load security SSPI package.");
                return;
            }
        } else {
            L->Log("!!! The encryption failed.");
            return;
        }
    } else if (hr <= DPERR_CANTLOADSECURITYPACKAGE) {
        if (hr != DPERR_CANTLOADSECURITYPACKAGE) {
            if (hr == DPERR_SIGNFAILED) {
                L->Log("!!! The security sign failed.");
                return;
            }
        } else {
            L->Log("!!! Can't load security package.");
            return;
        }
    } else {
        if (hr != DPERR_CANTLOADCAPI) {
            if (hr != DPERR_LOGONDENIED) {
            } else {
                L->Log("!!! The secure logon failed.");
                return;
            }
        } else {
            L->Log("!!! Can't load CAPI");
            return;
        }
    }

    L->Log("!!! %s: Unhandled DP ERROR/exception in call.  Result=%ld  (%d)", Text, hr, hr);
}
