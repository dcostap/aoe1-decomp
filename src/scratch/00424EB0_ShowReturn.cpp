// VA: 00424EB0
// RGE_Comm_Error::ShowReturn(long, char*)
// Source: com_err.cpp lines 23-380

// attempt 1: flat if-else-if chain with hex literals -> ja (unsigned) instead of jg
// attempt 2: added (long) casts -> correct signed jg but block layout differs (null return goes mid-function)
// attempt 3: deeply nested if(code > pivot) binary search tree -> same sized (2184) but jump targets differ
// attempt 4: ghidra-style flat if-else-if with <(long)-0x... negative constants -> block layout still divergent
// attempt 5: fold LastReportedError store into first comparison via (this->LastReportedError=code)>pivot -> no improvement
// 
// Remaining gap: 63% diff. VC5 generates a different block layout for the 26-level signed binary search tree.
// The original asm's cmp/jg/je/jne pattern at each level is regular but VC5 with any C control-flow structure
// I've tested reorders the blocks differently. This may be a TU-context issue (com_err.cpp had ~400 lines
// with multiple functions that provided neighbor context) or a compiler-heuristic depth limit.
// For a function this large (2184 bytes, 26 levels), variant_lab or donor-TU context reconstruction
// would be the next escalation. Leaving in scratch per BOSS escalation rules.

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

    // Store folded into the first comparison to match original cmp/mov/jg interleaving
    // Original: cmp esi,80004001h; mov [edi+4],esi; jg ... (all on same source line)
    if ((this->LastReportedError = code) > (long)0x80004001) {
        if ((this->LastReportedError = code) > (long)0x80040110) {
            if ((this->LastReportedError = code) > (long)0x8007000E) {
                if ((this->LastReportedError = code) > (long)0x88770005) {
                    if ((this->LastReportedError = code) > (long)0x88770014) {
                        if ((this->LastReportedError = code) > (long)0x88770028) {
                            if ((this->LastReportedError = code) > (long)0x8877003C) {
                                if ((this->LastReportedError = code) > (long)0x88770050) {
                                    if ((this->LastReportedError = code) > (long)0x88770078) {
                                        if ((this->LastReportedError = code) > (long)0x88770096) {
                                            if ((this->LastReportedError = code) > (long)0x887700A0) {
                                                if ((this->LastReportedError = code) > (long)0x887700BE) {
                                                    if ((this->LastReportedError = code) > (long)0x887700D2) {
                                                        if ((this->LastReportedError = code) > (long)0x887700E6) {
                                                            if ((this->LastReportedError = code) > (long)0x887700FA) {
                                                                if ((this->LastReportedError = code) > (long)0x88770118) {
                                                                    if ((this->LastReportedError = code) > (long)0x8877012C) {
                                                                        if ((this->LastReportedError = code) > (long)0x88770140) {
                                                                            if ((this->LastReportedError = code) > (long)0x88770154) {
                                                                                if ((this->LastReportedError = code) > (long)0x887703E8) {
                                                                                    if ((this->LastReportedError = code) > (long)0x887703FC) {
                                                                                        if ((this->LastReportedError = code) > (long)0x8877041A) {
                                                                                            if ((this->LastReportedError = code) > (long)0x887707D0) {
                                                                                                if ((this->LastReportedError = code) > (long)0x887707E4) {
                                                                                                    if ((this->LastReportedError = code) > (long)0x887707F8) {
                                                                                                        if (code == (long)0x8877080C) {
                                                                                                            Log(L, "!!! Can't load CAPI");
                                                                                                            return;
                                                                                                        }
                                                                                                        if (code == (long)0x88770820) {
                                                                                                            Log(L, "!!! The secure logon failed.");
                                                                                                            return;
                                                                                                        }
                                                                                                    } else if (code == (long)0x887707F8) {
                                                                                                        Log(L, "!!! Can't load security package.");
                                                                                                        return;
                                                                                                    } else if (code == (long)0x887707EE) {
                                                                                                        Log(L, "!!! The security sign failed.");
                                                                                                        return;
                                                                                                    }
                                                                                                } else if (code == (long)0x887707E4) {
                                                                                                    Log(L, "!!! The encryption failed.");
                                                                                                    return;
                                                                                                } else if (code == (long)0x887707DA) {
                                                                                                    Log(L, "!!! Can't load security SSPI package.");
                                                                                                    return;
                                                                                                }
                                                                                            } else if (code == (long)0x887707D0) {
                                                                                                Log(L, "!!! Not A Lobby Session");
                                                                                                return;
                                                                                            } else if (code == (long)0x8877042E) {
                                                                                                Log(L, "!!! Security authentify failed.");
                                                                                                return;
                                                                                            }
                                                                                        } else if (code == (long)0x8877041A) {
                                                                                            Log(L, "!!! Unknown application specified");
                                                                                            return;
                                                                                        } else if (code == (long)0x88770410) {
                                                                                            return;
                                                                                        }
                                                                                    } else if (code == (long)0x887703FC) {
                                                                                        Log(L, "!!! Application has not been started");
                                                                                        return;
                                                                                    } else if (code == (long)0x887703F2) {
                                                                                        Log(L, "!!! Can't start the application.");
                                                                                        return;
                                                                                    }
                                                                                } else if (code == (long)0x887703E8) {
                                                                                    Log(L, "!!! Buffer size failure (LARGE)");
                                                                                    return;
                                                                                } else if (code == (long)0x8877015E) {
                                                                                    Log(L, "!!! The session is in the process of starting.");
                                                                                    return;
                                                                                }
                                                                            } else if (code == (long)0x88770154) {
                                                                                Log(L, "!!! The secure password is invalid");
                                                                                return;
                                                                            } else if (code == (long)0x8877014A) {
                                                                                this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                                                                                Log(L, "!!! The session is in the process of starting.");
                                                                                return;
                                                                            }
                                                                        } else if (code == (long)0x88770140) {
                                                                            Log(L, "!!! Unknown application specified");
                                                                            this->NotifyWindowParam(COMM_NO_LINK, 0);
                                                                            return;
                                                                        } else if (code == (long)0x88770136) {
                                                                            Log(L, "!!! Lost connection to session.");
                                                                            this->NotifyWindowParam(COMM_NO_LINK, 0);
                                                                            return;
                                                                        }
                                                                    } else if (code == (long)0x8877012C) {
                                                                        Log(L, "!!! Player Lost connection.");
                                                                        return;
                                                                    } else if (code == (long)0x88770122) {
                                                                        Log(L, "!!! Unable to create server");
                                                                        return;
                                                                    }
                                                                } else if (code == (long)0x88770118) {
                                                                    this->NotifyWindowParam(COMM_NO_LINK, 0);
                                                                    Log(L, "!!! User Cancel");
                                                                    return;
                                                                } else if (code == (long)0x8877010E) {
                                                                    Log(L, "!!! Busy Rcvd");
                                                                    return;
                                                                }
                                                            } else if (code == (long)0x887700FA) {
                                                                Log(L, "!!! Communications - Session is full");
                                                                this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                                                                return;
                                                            } else if (code == (long)0x887700F0) {
                                                                Log(L, "!!! COMM_TIMEOUT Rcvd from HOST.");
                                                                this->NotifyWindowParam(COMM_HOST_BUSY, 0);
                                                                return;
                                                            }
                                                        } else if (code == (long)0x887700E6) {
                                                            Log(L, "!!! Send overflow.");
                                                            return;
                                                        } else if (code == (long)0x887700DC) {
                                                            Log(L, "!!! No sessions are available");
                                                            return;
                                                        }
                                                    } else if (code == (long)0x887700D2) {
                                                        Log(L, "!!! No players are connected.");
                                                        return;
                                                    } else if (code == (long)0x887700C8) {
                                                        Log(L, "!!! No name server running.");
                                                        return;
                                                    }
                                                } else if (code == (long)0x887700BE) {
                                                    Log(L, "!!! No messages");
                                                    return;
                                                } else if (code == (long)0x887700AA) {
                                                    Log(L, "!!! No Connection");
                                                    return;
                                                }
                                            } else if (code == (long)0x887700A0) {
                                                Log(L, "!!! Not able to do multipayer.");
                                                return;
                                            } else if (code == (long)0x8877009B) {
                                                Log(L, "!!! Invalid Group");
                                                return;
                                            }
                                        } else if (code == (long)0x88770096) {
                                            Log(L, "!!! Invalid Player");
                                            return;
                                        } else if (code == (long)0x88770082) {
                                            Log(L, "!!! Invalid Object");
                                            return;
                                        }
                                    } else if (code == (long)0x88770078) {
                                        Log(L, "!!! Exception Raised");
                                        return;
                                    } else if (code == (long)0x8877005A) {
                                        Log(L, "!!! Invalid Flags");
                                        return;
                                    }
                                } else if (code == (long)0x88770050) {
                                    Log(L, "!!! Device caps are not available");
                                    Log(L, "!!! ERROR ");
                                    return;
                                } else if (code == (long)0x88770046) {
                                    Log(L, "!!! Can't create session.");
                                    return;
                                }
                            } else if (code == (long)0x8877003C) {
                                Log(L, "!!! Can't create player.");
                                return;
                            } else if (code == (long)0x88770032) {
                                Log(L, "!!! Can't Create Group");
                                return;
                            }
                        } else if (code == (long)0x88770028) {
                            Log(L, "!!! Buffer size failure (SMALL)");
                            this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
                            return;
                        } else if (code == (long)0x8877001E) {
                            Log(L, "!!! Can't Add Player");
                            return;
                        }
                    } else if (code == (long)0x88770014) {
                        Log(L, "!!! Active Players - command invalid");
                        return;
                    } else if (code == (long)0x8877000A) {
                        Log(L, "!!! Access Denied - busy service provider");
                        this->NotifyWindowParam(COMM_NO_LINK, 0);
                        return;
                    }
                } else if (code == (long)0x88770005) {
                    Log(L, "!!! Already Initialized");
                    return;
                } else if (code == (long)0x80070057) {
                    Log(L, "!!! Invalid Params");
                    return;
                }
            } else if (code == (long)0x8007000E) {
                Log(L, "!!! Out Of Memory");
                return;
            } else if (code == (long)0x80070005) {
                Log(L, "COM error Access Denied");
                this->NotifyWindowParam(COMM_NO_LINK, 0);
                return;
            } else if (code == (long)0x80070006) {
                Log(L, "COM Invalid Handle");
                return;
            }
        } else if (code == (long)0x80040110) {
            Log(L, "!!! COMM: CLASS NO AGGREGATION.");
            return;
        } else {
            switch (code) {
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
            case (long)0x80004005:
                Log(L, "!!! GENERIC (Undefined) ERROR ");
                this->NotifyWindowParam(COMM_FATAL_ERROR, 0);
                return;
            }
        }
    } else if (code == (long)0x80004001) {
        Log(L, "!!! Unsupported.");
        return;
    } else if (code == (long)0x8000000A) {
        Log(L, "COM Error pending");
        return;
    }

    // Default unhandled error
    Log(L, "+++ %s: Unhandled DP ERROR exception(Code %u) (0x%08X)", context, code, code);
}
