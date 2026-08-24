// 0042F6D0 ReceiveZoneMessages
// 334 bytes, __thiscall, RGE_Lobby method
// Attempt log (sa6799_r1_ReceiveZone, 10 meaningful hypotheses):
// - Baseline raw slot-9 call/free logging/explicit unknown check: 177 strict
//   differing bytes (52.9940%).
// - SDK-shaped slot-9 ReceiveLobbyMessage, variadic TDebuggingLog member calls,
//   and PDB case order (3, 0, 1, 2, default): 71 diff; all 9 calls aligned.
// - Swapped output arguments worsened to 73; declaration order and IUnknown
//   inheritance were codegen duplicates. A C-style vtable surface worsened to 86.
//   Aggregate local layouts were diagnostic only (71/72 diff) and were rolled
//   back in favor of separate period-plausible locals.
// - The unknown-message vararg is the binary-observed receive-flags value, not
//   the derived switch index. That behavior restores the whole suffix: 3 strict
//   differing bytes (0.8982%), 331/334 equal bytes.
// Prior clean candidate had three output-slot bytes left. Frame 0x808, size
// 334, CFG, ordered calls, slot 0x24, direct targets, and all 23 relocations
// already matched. Default VC5 /O2 /Oy; no inline asm.
// sat2-42F6D0-homes: The period DirectPlay ABI initializes the final data-size
// output to 0x800 and returns message flags through the third output. This
// declaration/order model moved all three homes to the original offsets.
// The lobby system message type is the first DWORD in data. Exact at 334/334.

#ifndef COM_LOBY_CONTEXT
class TDebuggingLog {
public:
    void Log(char* format, ...);
};
extern TDebuggingLog* L;

class IUnknown {
public:
    virtual long __stdcall QueryInterface(void* iid, void** object) = 0;
    virtual unsigned long __stdcall AddRef(void) = 0;
    virtual unsigned long __stdcall Release(void) = 0;
};

class IDirectPlayLobby : public IUnknown {
public:
    virtual long __stdcall Connect(unsigned long flags, void** dplay, void* unknown) = 0;
    virtual long __stdcall CreateAddress(void* guidServiceProvider, void* guidDataType,
                                         const void* data, unsigned long dataSize,
                                         void* address, unsigned long* addressSize) = 0;
    virtual long __stdcall EnumAddress(void* callback, const void* data,
                                       unsigned long dataSize, void* context) = 0;
    virtual long __stdcall EnumAddressTypes(void* callback, void* guid,
                                             void* context, unsigned long flags) = 0;
    virtual long __stdcall EnumLocalApplications(void* callback, void* context,
                                                  unsigned long flags) = 0;
    virtual long __stdcall GetConnectionSettings(unsigned long player, void* settings,
                                                  unsigned long* size) = 0;
    virtual long __stdcall ReceiveLobbyMessage(unsigned long flags, unsigned long messageFlags,
                                               unsigned long* messageFlagsOut, void* message,
                                               unsigned long* messageSize) = 0;
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

class RGE_Lobby {
public:
    void* field_00;
    IDirectPlayLobby* glpDPL;
    void* glpDPL2;
    void* glpDP;
    void* glpdplConnection;
    char lobby_game;
    char gap_15[3];
    RGE_Comm_Error* Err;

    long ReceiveZoneMessages();
};
#endif

long RGE_Lobby::ReceiveZoneMessages() {
    if (lobby_game == 0) return 0;

    unsigned long dwDataSize = 0x800;
    unsigned long dwRXFlags;
    char data[2048];

    long result = glpDPL->ReceiveLobbyMessage(0, 0, &dwRXFlags, data, &dwDataSize);

    Err->ShowReturn(result, (char*)"RX Lobby Messages");

    if (result == 0x887700BE) return 0;
    if (dwDataSize == 0) return 0;

    if (result != 0) {
        Err->ShowReturn(result, (char*)"RxLOBBY MSG");
        return 0;
    }

    if (dwRXFlags != 1) return 0;

    L->Log((char*)"LOBBY: System Message");

    unsigned long dwMessageType = *((unsigned long*)data);
    int msgType = (int)dwMessageType - 1;

    switch (msgType) {
        case 3:
            L->Log((char*)"!!! Lobby: Application has been terminated.");
            break;
        case 0:
            L->Log((char*)"Lobby connection settings read.");
            break;
        case 1:
            L->Log((char*)"!!! Lobby: Connection failed.");
            break;
        case 2:
            L->Log((char*)"Lobby: Connection successful.");
            break;
        default:
            L->Log((char*)"!!! Lobby: Unknown message from lobby. %d", dwMessageType);
            break;
    }

    return 0;
}
