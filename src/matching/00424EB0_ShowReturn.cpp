// RGE_Comm_Error::ShowReturn (00424EB0, 2184 bytes, com_err.cpp lines 23-380)
//
// Attempt 1: flat if-else-if chain with hex literals -> ja (unsigned) instead of jg
// Attempt 2: added (long) casts -> correct signed jg but block layout differs
// Attempt 3: deeply nested if(code > pivot) binary search tree -> same size but jump targets differ
// Attempt 4: ghidra-style flat if-else-if with <(long)-0x... negative constants -> block layout divergent
// Attempt 5: fold LastReportedError store into first comparison via (this->LastReportedError=code)>pivot -> no improvement
// Attempt 6: if(code != 0) wrapper instead of early return -> slight change but same jle vs jg/je issue
// Attempt 7: goto-based flow -> no improvement
// Attempt 8: TU-context bundle with all 4 com_err functions -> still 65% diff
// Attempt 9: one typed sparse switch corrected the observed error messages and notifications.
// It matched size and call counts, and reduced positional drift to 329 bytes.
// Attempts 10-11: a signed threshold tree with direct inner equality tests was closer
// in control shape but not in emitted layout; the sparse switch remained the clean pin.
// Attempts 12-14: original jg/je blocks showed inverted inner guards and a local dense switch.
// The final source keeps that period-plausible threshold tree and exact call order.
// The empty non-match arms preserve the original shared-default fallthrough and are
// required by the observed branch targets, not by register or volatility steering.

#ifndef COM_ERR_TU_CONTEXT
class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};
extern TDebuggingLog* L;

class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;

    void NotifyWindowParam(int msg, long param);
    void ShowReturn(long code, char* context);
};
#endif

#ifndef COM_ERR_TU_CONTEXT
enum {
    COMM_NO_NEW_PLAYERS = 0x17AB,
    COMM_FATAL_ERROR = 0x17AC,
    COMM_HOST_BUSY = 0x17A8,
    COMM_NO_LINK = 0x17AE,
    COMM_CANCEL_GAME = 0x17B9,
};
#endif

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
