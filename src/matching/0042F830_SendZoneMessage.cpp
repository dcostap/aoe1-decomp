// 0042F830 RGE_Lobby::SendZoneMessage
// 245 bytes, __thiscall, com_loby.cpp lines 360-400
// Attempt log (orch-0042F830-D):
// - Baseline reconstruction with canonical layout (HostHWND+0, glpDPL+4,
//   glpDPL2+8, glpDP+C, glpdplConnection+10, lobby_game+14, Err+18),
//   flat dword GUID copies, inline memcpy, and lobby vtable slot 11
//   SendLobbyMessage (SDK-shaped __stdcall virtual surface like the
//   0042F190 donor). Prior scratch had glpDPL2 at +4, lobby_game at +0x10,
//   field-wise GUID_NULL short/byte stores, a memmove CALL instead of the
//   inline rep movsd/movsb, and vtable slot 7 instead of 0x2C.
// EXACT MATCH: validated at 245/245 bytes with aligned calls and relocations.

#include <string.h>

class TDebuggingLog {
public:
    void Log(char* format, ...);
};
extern TDebuggingLog* L;

void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void*);

struct _GUID {
    unsigned long Data1;
    unsigned long Data2;
    unsigned long Data3;
    unsigned long Data4;
};

extern const _GUID GUID_NULL;

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
    virtual long __stdcall GetLobbyMessage(unsigned long flags, void* message,
                                           unsigned long* messageSize) = 0;
    virtual long __stdcall SendLobbyMessage(unsigned long flags, unsigned long appId,
                                            void* data, unsigned long dataSize) = 0;
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

class RGE_Lobby {
public:
    void* HostHWND;            // +0x00
    void* glpDPL;              // +0x04
    IDirectPlayLobby* glpDPL2; // +0x08
    void* glpDP;               // +0x0C
    void* glpdplConnection;    // +0x10
    unsigned char lobby_game;  // +0x14
    unsigned char gap_15[3];
    RGE_Comm_Error* Err;       // +0x18

    long SendZoneMessage(char* data, unsigned long dataSize, _GUID guid);
};

long RGE_Lobby::SendZoneMessage(char* data, unsigned long dataSize, _GUID guid) {
    if (lobby_game == 0) return 0;

    unsigned long total = dataSize + 0x30;

    L->Log("Sending %d bytes to the Zone (Total message size = %d)", dataSize, total);

    char* buf = (char*)operator_new(total);
    *((unsigned long*)buf) = 5;
    *((unsigned long*)(buf + 4)) = 0;
    *((_GUID*)(buf + 8)) = GUID_NULL;
    *((_GUID*)(buf + 0x18)) = guid;
    *((unsigned long*)(buf + 0x28)) = total;

    memcpy(buf + 0x2C, data, dataSize);

    long result = glpDPL2->SendLobbyMessage(0, 0, buf, total);
    operator_delete(buf);

    if (result == 0) {
        L->Log("SendLobbyMessage returns OK");
    }
    Err->ShowReturn(result, "Send Lobby Msg");
    return result;
}
