// attempt 1: direct globals + debug_timeGetTime + log call + send helper, keeping the first arg unused
// attempt 2: tried explicit local temps and a cdecl log wrapper; mismatch stayed localized to the log/current_turn load order
// leaving this in scratch because the remaining diff is a small register/order basin around the debug log call

class TDebuggingLog;
extern TDebuggingLog* L;
extern void __cdecl TDebuggingLog_Log(TDebuggingLog* log, char* text, int a, int b);
extern unsigned long debug_timeGetTime(char* file, int line);

class TCommunications_Handler {
public:
    char gap_0[0x10C8];
    unsigned long current_turn;

    long FastSend(int a, char* buf, int len, int b, int c);
    int TXDebugPing();
};

int TCommunications_Handler::TXDebugPing() {
    long lVar1;
    TDebuggingLog* log;
    unsigned long turn;

    *(unsigned char*)0x62C5D8 = 0x33;
    *(unsigned long*)0x62C5DC = debug_timeGetTime((char*)0x580BF4, 0x496);
    log = L;
    turn = this->current_turn;
    *(unsigned long*)0x62C5E0 = turn;
    TDebuggingLog_Log(log, (char*)0x581050, 0, 0x0C);
    lVar1 = this->FastSend(0, (char*)0x62C5D8, 0x0C, 0, 0);
    return (unsigned int)(lVar1 == 0);
}
