// 0042F430 CheckForLobbyLaunch
// 514 bytes, __thiscall, RGE_Lobby method
// probe 5: 480/514 bytes (34 short)
// tried: natural virtual calls (448B), raw vtable pointer casts (480B), function pointer casts (464B)
// tried: correct member layout (glpDPL+4, glpDPL2+8, glpDP+C, glpdplConnection+10, lobby_game+14, Err+18)
// tried: DPLCONNECTION allocation with operator new(41), session desc field setup
// BLOCKER: 34 bytes short despite correct core logic. Original has extra stack setup
//   (mov [esp+10h],29h), extra push instructions before DirectPlayLobbyCreateA call,
//   and different COM vtable dispatch pattern (call dword [edx+20h] vs natural vcall).
//   Core logic correct: ClearLobbyInfo, DirectPlayLobbyCreateA, QI for IDirectPlayLobby2A,
//   Connect, Log calls, DPLCONNECTION alloc, SendMessage, second Connect, QI for IDirectPlay3A,
//   EnumPlayersCallbackLobby call.

class TDebuggingLog;
extern TDebuggingLog* L;

void __stdcall TDebuggingLog_Log(TDebuggingLog* log, const char* format, ...);
void* operator new(size_t size);
void operator delete(void* ptr);

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

class RGE_Lobby {
public:
    void* glpDPL;
    void* glpDPL2;
    void* glpDP;
    void* glpdplConnection;
    char lobby_game;
    char gap_15[3];
    RGE_Comm_Error* Err;

    unsigned char CheckForLobbyLaunch(void** param_1);
    void ClearLobbyInfo();
};

unsigned char RGE_Lobby::CheckForLobbyLaunch(void** param_1) {
    *param_1 = 0;
    ClearLobbyInfo();

    long hr = ((long(__stdcall*)(void*, void*))0x5478EA)(0, &glpDPL);
    Err->ShowReturn(hr, "Lobby Create");
    if (hr < 0) return 0;

    // QI for IDirectPlayLobby2: vtable[0]
    void* vtbl = *(void**)glpDPL;
    hr = ((long(__stdcall*)(void*, void*, void**))vtbl)(glpDPL, (void*)0x56F110, (void**)&glpDPL2);
    if (glpDPL2 == 0) return 0;

    // Connect via vtable slot at +0x20 (slot 5)
    void* vtbl2 = *(void**)glpDPL2;
    hr = ((long(__stdcall*)(void*, void*, void*, void*))(*(unsigned int**)vtbl2 + 5))(glpDPL2, 0, (void**)&glpDP, 0);
    if (hr < 0) {
        lobby_game = 0;
        return 0;
    }

    TDebuggingLog_Log(L, "LOBBY LAUNCHED GAME.");

    // Allocate and store DPLCONNECTION
    glpdplConnection = operator new(41);

    // Set session desc fields
    void* sessionDesc = *(void**)((unsigned char*)glpdplConnection + 8);
    *(unsigned int*)((unsigned char*)sessionDesc + 4) = 0x44;
    *(unsigned int*)((unsigned char*)sessionDesc + 0x28) = 9;

    // SendMessage via slot 5 (same as Connect, original uses slot 5)
    hr = ((long(__stdcall*)(void*, void*, void*, void*))(*(unsigned int**)vtbl2 + 5))(glpDPL2, 0, glpdplConnection, 0);
    TDebuggingLog_Log(L, "Pre-connect");

    // Second Connect via slot 5
    hr = ((long(__stdcall*)(void*, void*, void*, void*))(*(unsigned int**)vtbl2 + 5))(glpDPL2, 0, (void**)&glpDP, 0);
    TDebuggingLog_Log(L, "Post Connect");

    if (hr < 0) {
        if (hr == 0x887700F0) return 0xFF;
        TDebuggingLog_Log(L, "Failed to connect!");
        Err->ShowReturn(hr, "Connect");
        return 0xFF;
    }

    TDebuggingLog_Log(L, "Pre QI");
    // QI for IDirectPlay3 via vtable[0]
    void* vtbl3 = *(void**)glpDP;
    hr = ((long(__stdcall*)(void*, void*, void**))vtbl3)(glpDP, (void*)0x56F114, param_1);
    Err->ShowReturn(hr, "Lobby QI");

    if (hr < 0) {
        TDebuggingLog_Log(L, "Queryinterface failed.");
        return 0xFF;
    }

    TDebuggingLog_Log(L, "Calling enumeration of players.");
    // EnumPlayers via slot 6
    ((void(__stdcall*)(void*, void*, void*, void*, void*))(*(unsigned int**)(*param_1) + 6))(*param_1, 0, (void*)0x42F3A0, this, 0);
    TDebuggingLog_Log(L, "Post ENUMP");
    lobby_game = 1;
    return 1;
}
