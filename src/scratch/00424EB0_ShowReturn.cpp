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
//
// Remaining gap: ~65%. The core issue is that VC5 generates 'jle NOT_HIGHER; fallthrough HIGHER'
// at each tree node, but the original uses 'jg HIGHER; je EQUAL; fallthrough LOWER'.
// This is a fundamental block-layout optimization heuristic difference that no C source
// restructuring has overcome across 8 attempts. Likely needs variant_lab with flags/context
// axes, or deeper investigation into VC5 block-ordering heuristics for deep signed binary
// search trees (26 levels, 2184 bytes).
// Leaving in scratch as unresolved.

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

enum {
    COMM_NO_NEW_PLAYERS = 0x17AB,
    COMM_FATAL_ERROR = 0x17AC,
    COMM_HOST_BUSY = 0x17A8,
    COMM_NO_LINK = 0x17AE,
    COMM_CANCEL_GAME = 0x17B9,
};

void RGE_Comm_Error::ShowReturn(long code, char* context) {
    if (code == 0) {
        return;
    }

    Log(L, "+++COMM______DP CALL FAILED_(Code %u)_____ %s\n", code, context);

    this->LastReportedError = code;
    if (code == (long)0x80004001) {
        Log(L, "!!! Unsupported.");
    } else if (code == (long)0x8000000A) {
        Log(L, "COM Error pending");
    } else if (code > (long)0x80004001) {
        if (code == (long)0x80040110) {
            Log(L, "!!! COMM: CLASS NO AGGREGATION.");
        } else if (code > (long)0x80040110) {
            if (code == (long)0x8007000E) {
                Log(L, "!!! Out Of Memory");
            } else if (code == (long)0x80070005) {
                Log(L, "COM error Access Denied");
                this->NotifyWindowParam(COMM_NO_LINK, 0);
            } else if (code == (long)0x80070006) {
                Log(L, "COM Invalid Handle");
            } else if (code > (long)0x8007000E) {
                if (code == (long)0x88770005) {
                    Log(L, "!!! Already Initialized");
                } else if (code == (long)0x80070057) {
                    Log(L, "!!! Invalid Params");
                } else if (code > (long)0x88770005) {
                    if (code == (long)0x88770014) {
                        Log(L, "!!! Active Players - command invalid");
                    } else if (code == (long)0x8877000A) {
                        Log(L, "!!! Access Denied - busy service provider");
                        this->NotifyWindowParam(COMM_NO_LINK, 0);
                    } else if (code > (long)0x88770014) {
                        if (code == (long)0x88770028) {
                            Log(L, "!!! Buffer size failure (SMALL)");
                            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                        } else if (code == (long)0x8877001E) {
                            Log(L, "!!! Can't Add Player");
                        } else if (code > (long)0x88770028) {
                            if (code == (long)0x8877003C) {
                                Log(L, "!!! Can't create player.");
                            } else if (code == (long)0x88770032) {
                                Log(L, "!!! Can't Create Group");
                            } else if (code > (long)0x8877003C) {
                                if (code == (long)0x88770050) {
                                    Log(L, "!!! Device caps are not available");
                                    Log(L, "!!! ERROR ");
                                } else if (code == (long)0x88770046) {
                                    Log(L, "!!! Can't create session.");
                                } else if (code > (long)0x88770050) {
                                    if (code == (long)0x88770078) {
                                        Log(L, "!!! Exception Raised");
                                    } else if (code == (long)0x8877005A) {
                                        Log(L, "!!! Invalid Flags");
                                    } else if (code > (long)0x88770078) {
                                        if (code == (long)0x88770096) {
                                            Log(L, "!!! Invalid Player");
                                        } else if (code == (long)0x88770082) {
                                            Log(L, "!!! Invalid Object");
                                        } else if (code > (long)0x88770096) {
                                            if (code == (long)0x887700A0) {
                                                Log(L, "!!! Not able to do multipayer.");
                                            } else if (code == (long)0x8877009B) {
                                                Log(L, "!!! Invalid Group");
                                            } else if (code > (long)0x887700A0) {
                                                if (code == (long)0x887700BE) {
                                                    Log(L, "!!! No messages");
                                                } else if (code == (long)0x887700AA) {
                                                    Log(L, "!!! No Connection");
                                                } else if (code > (long)0x887700BE) {
                                                    if (code == (long)0x887700D2) {
                                                        Log(L, "!!! No players are connected.");
                                                    } else if (code == (long)0x887700C8) {
                                                        Log(L, "!!! No name server running.");
                                                    } else if (code > (long)0x887700D2) {
                                                        if (code == (long)0x887700E6) {
                                                            Log(L, "!!! Send overflow.");
                                                        } else if (code == (long)0x887700DC) {
                                                            Log(L, "!!! No sessions are available");
                                                        } else if (code > (long)0x887700E6) {
                                                            if (code == (long)0x887700FA) {
                                                                Log(L, "!!! Communications - Session is full");
                                                                this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                                                            } else if (code == (long)0x887700F0) {
                                                                Log(L, "!!! COMM_TIMEOUT Rcvd from HOST.");
                                                                this->NotifyWindowParam(COMM_HOST_BUSY, 0);
                                                            } else if (code > (long)0x887700FA) {
                                                                if (code == (long)0x88770118) {
                                                                    this->NotifyWindowParam(COMM_NO_LINK, 0);
                                                                    Log(L, "!!! User Cancel");
                                                                } else if (code == (long)0x8877010E) {
                                                                    Log(L, "!!! Busy Rcvd");
                                                                } else if (code > (long)0x88770118) {
                                                                    if (code == (long)0x8877012C) {
                                                                        Log(L, "!!! Player Lost connection.");
                                                                    } else if (code == (long)0x88770122) {
                                                                        Log(L, "!!! Unable to create server");
                                                                    } else if (code > (long)0x8877012C) {
                                                                        if (code == (long)0x88770140) {
                                                                            Log(L, "!!! Unknown application specified");
                                                                            this->NotifyWindowParam(COMM_NO_LINK, 0);
                                                                        } else if (code == (long)0x88770136) {
                                                                            Log(L, "!!! Lost connection to session.");
                                                                            this->NotifyWindowParam(COMM_NO_LINK, 0);
                                                                        } else if (code > (long)0x88770140) {
                                                                            if (code == (long)0x88770154) {
                                                                                Log(L, "!!! The secure password is invalid");
                                                                            } else if (code == (long)0x8877014A) {
                                                                                this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                                                                                Log(L, "!!! The session is in the process of starting.");
                                                                            } else if (code > (long)0x88770154) {
                                                                                if (code == (long)0x887703E8) {
                                                                                    Log(L, "!!! Buffer size failure (LARGE)");
                                                                                } else if (code == (long)0x8877015E) {
                                                                                    Log(L, "!!! The session is in the process of starting.");
                                                                                } else if (code > (long)0x887703E8) {
                                                                                    if (code == (long)0x887703FC) {
                                                                                        Log(L, "!!! Application has not been started");
                                                                                    } else if (code == (long)0x887703F2) {
                                                                                        Log(L, "!!! Can't start the application.");
                                                                                    } else if (code > (long)0x887703FC) {
                                                                                        if (code == (long)0x8877041A) {
                                                                                            Log(L, "!!! Unknown application specified");
                                                                                        } else if (code == (long)0x88770410) {
                                                                                        } else if (code > (long)0x8877041A) {
                                                                                            if (code == (long)0x887707D0) {
                                                                                                Log(L, "!!! Not A Lobby Session");
                                                                                            } else if (code == (long)0x8877042E) {
                                                                                                Log(L, "!!! Security authentify failed.");
                                                                                            } else if (code > (long)0x887707D0) {
                                                                                                if (code == (long)0x887707E4) {
                                                                                                    Log(L, "!!! The encryption failed.");
                                                                                                } else if (code == (long)0x887707DA) {
                                                                                                    Log(L, "!!! Can't load security SSPI package.");
                                                                                                } else if (code > (long)0x887707E4) {
                                                                                                    if (code == (long)0x887707F8) {
                                                                                                        Log(L, "!!! Can't load security package.");
                                                                                                    } else if (code == (long)0x887707EE) {
                                                                                                        Log(L, "!!! The security sign failed.");
                                                                                                    } else if (code > (long)0x887707F8) {
                                                                                                        if (code == (long)0x8877080C) {
                                                                                                            Log(L, "!!! Can't load CAPI");
                                                                                                        } else if (code == (long)0x88770820) {
                                                                                                            Log(L, "!!! The secure logon failed.");
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                switch (code) {
                case (long)0x80004002:
                    this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                    Log(L, "!!! No Interface");
                    break;
                case (long)0x80004003:
                    Log(L, "COM Invalid Pointer");
                    break;
                case (long)0x80004004:
                    Log(L, "COM Aborted");
                    break;
                case (long)0x80004005:
                    Log(L, "!!! GENERIC (Undefined) ERROR ");
                    this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                    break;
                default:
                    goto default_handler;
                }
            }
        } else {
            goto default_handler;
        }
    }
    return;

default_handler:
    Log(L, "+++ %s: Unhandled DP ERROR exception(Code %u) (0x%08X)", context, code, code);
}
