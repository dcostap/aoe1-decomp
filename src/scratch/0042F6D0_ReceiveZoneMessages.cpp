// 0042F6D0 ReceiveZoneMessages
// 334 bytes, __thiscall, RGE_Lobby method
// probe 3: 334/334 bytes, 36.5% diff
// tried: correct member layout (field_00, glpDPL+4, glpDPL2+8, glpDP+C, glpdplConnection+10, lobby_game+14, Err+18)
// tried: COM call via vtable slot 9 (0x24/4), raw function pointer cast
// tried: control flow reordering (result != 0 vs result == 0)
// BLOCKER: Deep VC5 codegen basin. Stack slot reuse pattern differs (original pushes same [esp+14h] 3x,
//   VC5 computes 3 distinct addresses). Register basin differs (original uses ecx for vtable, VC5 uses edx).
//   Stack offsets for COM call params differ ([esp+8]+[esp+14h] vs [esp+8]+[esp+10h]+[esp+14h]).
//   Core logic correct: lobby_game guard, COM call, ShowReturn, 0x887700BE/dwDataSize guards,
//   switch jump table with 4 Log cases (settings/failed/successful/terminated).

class TDebuggingLog;
extern TDebuggingLog* L;

void __stdcall TDebuggingLog_Log(TDebuggingLog* log, const char* format, ...);

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

class RGE_Lobby {
public:
    void* field_00;
    void* glpDPL;
    void* glpDPL2;
    void* glpDP;
    void* glpdplConnection;
    char lobby_game;
    char gap_15[3];
    RGE_Comm_Error* Err;

    long ReceiveZoneMessages();
};

long RGE_Lobby::ReceiveZoneMessages() {
    if (lobby_game == 0) return 0;

    char data[2048];
    unsigned long dwRXFlags = 0x800;
    unsigned long dwDataSize;

    long result = ((long(__stdcall*)(void*, unsigned long, char*, unsigned long*, unsigned long*))(*(unsigned int**)glpDPL + 9))(glpDPL, 0, data, &dwDataSize, &dwRXFlags);

    Err->ShowReturn(result, "RX Lobby Messages");

    if (result == 0x887700BE) return 0;
    if (dwDataSize == 0) return 0;

    if (result != 0) {
        Err->ShowReturn(result, "RxLOBBY MSG");
        return 0;
    }

    if (dwRXFlags != 1) return 0;

    TDebuggingLog_Log(L, "LOBBY: System Message");

    int msgType = (int)dwRXFlags - 1;
    if (msgType > 3) {
        TDebuggingLog_Log(L, "!!! Lobby: Unknown message from lobby. %d", msgType);
        return 0;
    }

    switch (msgType) {
        case 0:
            TDebuggingLog_Log(L, "Lobby connection settings read.");
            break;
        case 1:
            TDebuggingLog_Log(L, "!!! Lobby: Connection failed.");
            break;
        case 2:
            TDebuggingLog_Log(L, "Lobby: Connection successful.");
            break;
        case 3:
            TDebuggingLog_Log(L, "!!! Lobby: Application has been terminated.");
            break;
    }

    return 0;
}
