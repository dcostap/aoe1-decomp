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
// Attempt 10: nested threshold guards were farther from the original switch lowering.
// Attempt 11: reordered the four dense HRESULT case bodies; diff improved to 221 bytes.
// Attempts 12-13: final-tail source variants did not improve; restored Attempt 11.
// Final clean reconstruction: typed sparse dispatch, one canonical LastReportedError
// store, original call order, and original EXE message text. Remaining drift is the
// compiler's switch table/case placement and the final two equality tests.

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

    switch (code) {
    case (long)0x80004001:
        Log(L, "!!! Unsupported.");
        return;
    case (long)0x8000000A:
        Log(L, "COM Error pending");
        return;
    case (long)0x80040110:
        Log(L, "!!! COMM: CLASS NO AGGREGATION.");
        return;
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
    case (long)0x8007000E:
        Log(L, "!!! Out Of Memory");
        return;
    case (long)0x80070005:
        Log(L, "COM error Access Denied");
        this->NotifyWindowParam(COMM_NO_LINK, 0);
        return;
    case (long)0x80070006:
        Log(L, "COM Invalid Handle");
        return;
    case (long)0x88770005:
        Log(L, "!!! Already Initialized");
        return;
    case (long)0x80070057:
        Log(L, "!!! Invalid Params");
        return;
    case (long)0x88770014:
        Log(L, "!!! Active Players - command invalid with active players.");
        return;
    case (long)0x8877000A:
        Log(L, "!!! Access Denied - busy service or invalid use of host commands.");
        this->NotifyWindowParam(COMM_NO_LINK, 0);
        return;
    case (long)0x88770028:
        Log(L, "!!! Can't Add Player");
        this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
        return;
    case (long)0x8877001E:
        Log(L, "!!! Buffer size failure (SMALL)");
        return;
    case (long)0x8877003C:
        Log(L, "!!! Can't create player.");
        return;
    case (long)0x88770032:
        Log(L, "!!! Can't Create Group");
        return;
    case (long)0x88770050:
        Log(L, "!!! Device caps are not available.");
        Log(L, "!!! ERROR!");
        return;
    case (long)0x88770046:
        Log(L, "!!! Can't create session.");
        return;
    case (long)0x88770078:
        Log(L, "!!! Invalid Flags");
        return;
    case (long)0x8877005A:
        Log(L, "!!! Exception Raised");
        return;
    case (long)0x88770096:
        Log(L, "!!! Invalid Player");
        return;
    case (long)0x88770082:
        Log(L, "!!! Invalid Object");
        return;
    case (long)0x887700A0:
        Log(L, "!!! Not able to do multipayer!");
        return;
    case (long)0x8877009B:
        Log(L, "!!! Invalid Group");
        return;
    case (long)0x887700BE:
        Log(L, "!!! No messages");
        return;
    case (long)0x887700AA:
        Log(L, "!!! No Connection");
        return;
    case (long)0x887700D2:
        Log(L, "!!! No players are connected!");
        return;
    case (long)0x887700C8:
        Log(L, "!!! No name server running!");
        return;
    case (long)0x887700E6:
        Log(L, "!!! Send overflow!");
        return;
    case (long)0x887700DC:
        Log(L, "!!! No sessions are available");
        return;
    case (long)0x887700FA:
        Log(L, "!!! Communications - Session is full");
        this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
        return;
    case (long)0x887700F0:
        Log(L, "!!! COMM TIMEOUT Rcvd from HOST connection.");
        this->NotifyWindowParam(COMM_CANCEL_GAME, 0);
        return;
    case (long)0x88770118:
        this->NotifyWindowParam(COMM_NO_LINK, 0);
        Log(L, "!!! User Cancel");
        return;
    case (long)0x8877010E:
        Log(L, "!!! Busy Rcvd");
        return;
    case (long)0x8877012C:
        Log(L, "!!! Player Lost connection.");
        return;
    case (long)0x88770122:
        Log(L, "!!! Unable to create server");
        return;
    case (long)0x88770140:
        Log(L, "!!! Unknown application specified");
        this->NotifyWindowParam(COMM_NO_LINK, 0);
        return;
    case (long)0x88770136:
        Log(L, "!!! Lost connection to session.");
        this->NotifyWindowParam(COMM_HOST_BUSY, 0);
        return;
    case (long)0x88770154:
        Log(L, "!!! The secure password is invalid.");
        return;
    case (long)0x8877014A:
        this->NotifyWindowParam(COMM_NO_NEW_PLAYERS, 0);
        Log(L, "!!! The session is in the process of connecting");
        return;
    case (long)0x887703E8:
        Log(L, "!!! Buffer size failure (LARGE)");
        return;
    case (long)0x8877015E:
        Log(L, "!!! The session is in the process of connecting");
        return;
    case (long)0x887703FC:
        Log(L, "!!! Application has not been started yet.");
        return;
    case (long)0x887703F2:
        Log(L, "!!! Can't start the application.");
        return;
    case (long)0x8877041A:
        Log(L, "!!! Unknown application specified");
        return;
    case (long)0x88770410:
        return;
    case (long)0x887707D0:
        Log(L, "!!! Not A Lobby Session");
        return;
    case (long)0x8877042E:
        Log(L, "!!! Security authentify failed.");
        return;
    case (long)0x887707E4:
        Log(L, "!!! The encryption failed.");
        return;
    case (long)0x887707DA:
        Log(L, "!!! Can't load security SSPI package.");
        return;
    case (long)0x887707F8:
        Log(L, "!!! Can't load security package.");
        return;
    case (long)0x887707EE:
        Log(L, "!!! The security sign failed.");
        return;
    case (long)0x8877080C:
        Log(L, "!!! Can't load CAPI");
        return;
    case (long)0x88770820:
        Log(L, "!!! The secure logon failed.");
        return;
    default:
        Log(L, "!!! %s: Unhandled DP ERROR/exception in call.  Result=%ld  (%d)", context, code, code);
        return;
    }
}
