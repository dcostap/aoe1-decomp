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
class TDebuggingLog;
extern TDebuggingLog* L;
extern void Log(TDebuggingLog* log, char* fmt, ...);

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

    Log(L, "+++COMM______DP CALL FAILED_(Code %u)_____ %s\n", code, context);
    this->LastReportedError = code;

    if (code <= (long)0x80004001) {
        if (code != (long)0x80004001) {
            if (code == (long)0x8000000A) {
                Log(L, "COM Error pending");
                return;
            }
        } else {
            Log(L, "!!! Unsupported.");
            return;
        }
    } else if (code <= (long)0x80040110) {
        if (code != (long)0x80040110) {
            switch (code) {
            case (long)0x80004005:
                Log(L, "!!! GENERIC (Undefined) ERROR ");
                this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                return;
            case (long)0x80004002:
                this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                Log(L, "!!! No Interface");
                return;
            case (long)0x80004003:
                Log(L, "COM Invalid Pointer");
                return;
            case (long)0x80004004:
                Log(L, "COM Aborted");
                return;
            }
        } else {
            Log(L, "!!! COMM: CLASS NO AGGREGATION.");
            return;
        }
    } else if (code <= (long)0x8007000E) {
        if (code != (long)0x8007000E) {
            if (code != (long)0x80070005) {
                if (code == (long)0x80070006) {
                    Log(L, "COM Invalid Handle");
                    return;
                }
            } else {
                Log(L, "COM error Access Denied");
                this->NotifyWindowParam(COMM_NO_LINK, 0);
                return;
            }
        } else {
            Log(L, "!!! Out Of Memory");
            return;
        }
    } else if (code <= (long)0x88770005) {
        if (code != (long)0x88770005) {
            if (code == (long)0x80070057) {
                Log(L, "!!! Invalid Params");
                return;
            }
        } else {
            Log(L, "!!! Already Initialized");
            return;
        }
    } else if (code <= (long)0x88770014) {
        if (code != (long)0x88770014) {
            if (code == (long)0x8877000A) {
                Log(L, "!!! Access Denied - busy service or invalid use of host commands.");
                this->NotifyWindowParam(COMM_NO_LINK, 0);
                return;
            }
        } else {
            Log(L, "!!! Active Players - command invalid with active players.");
            return;
        }
    } else if (code <= (long)0x88770028) {
        if (code != (long)0x88770028) {
            if (code == (long)0x8877001E) {
                Log(L, "!!! Buffer size failure (SMALL)");
                return;
            }
        } else {
            Log(L, "!!! Can't Add Player");
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
    } else if (code <= (long)0x8877003C) {
        if (code != (long)0x8877003C) {
            if (code == (long)0x88770032) {
                Log(L, "!!! Can't Create Group");
                return;
            }
        } else {
            Log(L, "!!! Can't create player.");
            return;
        }
    } else if (code <= (long)0x88770050) {
        if (code != (long)0x88770050) {
            if (code == (long)0x88770046) {
                Log(L, "!!! Can't create session.");
                return;
            }
        } else {
            Log(L, "!!! Device caps are not available.");
            Log(L, "!!! ERROR!");
            return;
        }
    } else if (code <= (long)0x88770078) {
        if (code != (long)0x88770078) {
            if (code == (long)0x8877005A) {
                Log(L, "!!! Exception Raised");
                return;
            }
        } else {
            Log(L, "!!! Invalid Flags");
            return;
        }
    } else if (code <= (long)0x88770096) {
        if (code != (long)0x88770096) {
            if (code == (long)0x88770082) {
                Log(L, "!!! Invalid Object");
                return;
            }
        } else {
            Log(L, "!!! Invalid Player");
            return;
        }
    } else if (code <= (long)0x887700A0) {
        if (code != (long)0x887700A0) {
            if (code == (long)0x8877009B) {
                Log(L, "!!! Invalid Group");
                return;
            }
        } else {
            Log(L, "!!! Not able to do multipayer!");
            return;
        }
    } else if (code <= (long)0x887700BE) {
        if (code != (long)0x887700BE) {
            if (code == (long)0x887700AA) {
                Log(L, "!!! No Connection");
                return;
            }
        } else {
            Log(L, "!!! No messages");
            return;
        }
    } else if (code <= (long)0x887700D2) {
        if (code != (long)0x887700D2) {
            if (code == (long)0x887700C8) {
                Log(L, "!!! No name server running!");
                return;
            }
        } else {
            Log(L, "!!! No players are connected!");
            return;
        }
    } else if (code <= (long)0x887700E6) {
        if (code != (long)0x887700E6) {
            if (code == (long)0x887700DC) {
                Log(L, "!!! No sessions are available");
                return;
            }
        } else {
            Log(L, "!!! Send overflow!");
            return;
        }
    } else if (code <= (long)0x887700FA) {
        if (code != (long)0x887700FA) {
            if (code == (long)0x887700F0) {
                Log(L, "!!! COMM TIMEOUT Rcvd from HOST connection.");
                this->NotifyWindowParam(COMM_CANCEL_GAME, 0);
                return;
            }
        } else {
            Log(L, "!!! Communications - Session is full");
            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
            return;
        }
    } else if (code <= (long)0x88770118) {
        if (code != (long)0x88770118) {
            if (code == (long)0x8877010E) {
                Log(L, "!!! Busy Rcvd");
                return;
            }
        } else {
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            Log(L, "!!! User Cancel");
            return;
        }
    } else if (code <= (long)0x8877012C) {
        if (code != (long)0x8877012C) {
            if (code == (long)0x88770122) {
                Log(L, "!!! Unable to create server");
                return;
            }
        } else {
            Log(L, "!!! Player Lost connection.");
            return;
        }
    } else if (code <= (long)0x88770140) {
        if (code != (long)0x88770140) {
            if (code == (long)0x88770136) {
                Log(L, "!!! Lost connection to session.");
                this->NotifyWindowParam(COMM_HOST_BUSY, 0);
                return;
            }
        } else {
            Log(L, "!!! Unknown application specified");
            this->NotifyWindowParam(COMM_NO_LINK, 0);
            return;
        }
    } else if (code <= (long)0x88770154) {
        if (code != (long)0x88770154) {
            if (code == (long)0x8877014A) {
                this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                Log(L, "!!! The session is in the process of connecting");
                return;
            }
        } else {
            Log(L, "!!! The secure password is invalid.");
            return;
        }
    } else if (code <= (long)0x887703E8) {
        if (code != (long)0x887703E8) {
            if (code == (long)0x8877015E) {
                Log(L, "!!! The session is in the process of connecting");
                return;
            }
        } else {
            Log(L, "!!! Buffer size failure (LARGE)");
            return;
        }
    } else if (code <= (long)0x887703FC) {
        if (code != (long)0x887703FC) {
            if (code == (long)0x887703F2) {
                Log(L, "!!! Can't start the application.");
                return;
            }
        } else {
            Log(L, "!!! Application has not been started yet.");
            return;
        }
    } else if (code <= (long)0x8877041A) {
        if (code != (long)0x8877041A) {
            if (code != (long)0x88770410) {
            } else {
                return;
            }
        } else {
            Log(L, "!!! Unknown application specified");
            return;
        }
    } else if (code <= (long)0x887707D0) {
        if (code != (long)0x887707D0) {
            if (code == (long)0x8877042E) {
                Log(L, "!!! Security authentify failed.");
                return;
            }
        } else {
            Log(L, "!!! Not A Lobby Session");
            return;
        }
    } else if (code <= (long)0x887707E4) {
        if (code != (long)0x887707E4) {
            if (code == (long)0x887707DA) {
                Log(L, "!!! Can't load security SSPI package.");
                return;
            }
        } else {
            Log(L, "!!! The encryption failed.");
            return;
        }
    } else if (code <= (long)0x887707F8) {
        if (code != (long)0x887707F8) {
            if (code == (long)0x887707EE) {
                Log(L, "!!! The security sign failed.");
                return;
            }
        } else {
            Log(L, "!!! Can't load security package.");
            return;
        }
    } else {
        if (code != (long)0x8877080C) {
            if (code != (long)0x88770820) {
            } else {
                Log(L, "!!! The secure logon failed.");
                return;
            }
        } else {
            Log(L, "!!! Can't load CAPI");
            return;
        }
    }

    Log(L, "!!! %s: Unhandled DP ERROR/exception in call.  Result=%ld  (%d)", context, code, code);
}
