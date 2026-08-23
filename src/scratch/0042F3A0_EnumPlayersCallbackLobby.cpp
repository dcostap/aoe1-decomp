// 0042F3A0 EnumPlayersCallbackLobby
// 136 bytes, __stdcall, 5 params
// probe 1: natural callback with TDebuggingLog::Log calls

class TDebuggingLog;
extern TDebuggingLog* L;

struct DPNAME {
    int field_00;
    int field_04;
    const char* lpszShortName;
};

void __stdcall TDebuggingLog_Log(TDebuggingLog* log, const char* format, ...);

int __stdcall EnumPlayersCallbackLobby(unsigned long param_1, unsigned long param_2, DPNAME* param_3, unsigned long param_4, void* param_5) {
    TDebuggingLog_Log(L, "ENUMPLAYER: DPID = %ld", param_1);
    TDebuggingLog_Log(L, "ENUMPLAYER: NAME = %s", param_3->lpszShortName);
    TDebuggingLog_Log(L, "+++ Enumeration not done");
    if (param_4 & 0x10) {
        TDebuggingLog_Log(L, "Remote Player");
    }
    if (param_4 & 8) {
        TDebuggingLog_Log(L, "Local Player");
    }
    return 1;
}
