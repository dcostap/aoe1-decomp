// 0042F830 SendZoneMessage
// 245 bytes, __thiscall, RGE_Lobby method
// probe 3: 245/245 bytes, 66.9% diff
// tried: correct member layout (glpDPL+4, glpDPL2+8, glpDP+C, glpdplConnection+10, lobby_game+14, Err+18)
// tried: COM call via vtable slot 7 (SendMessage), raw function pointer cast
// tried: memmove for data copy block
// BLOCKER: Deep VC5 codegen basin at offset 0. Original pushes ecx at entry (no frame pointer),
//   VC5 generates push ebp/mov ebp,ecx. Original saves this at [esp] (below return addr),
//   VC5 uses ebp for frame. This cascades through entire function. Core logic correct:
//   lobby_game guard, TDebuggingLog_Log, operator new/delete, GUID copy to buf,
//   memmove for data, COM call slot 7, operator delete, ShowReturn.

#include <string.h>

class TDebuggingLog;
extern TDebuggingLog* L;

void __stdcall TDebuggingLog_Log(TDebuggingLog* log, const char* format, ...);
void* operator new(size_t size);
void operator delete(void* ptr);

struct _GUID {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

extern _GUID GUID_NULL;

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

    long SendZoneMessage(char* data, unsigned long dataSize, _GUID guid);
};

long RGE_Lobby::SendZoneMessage(char* data, unsigned long dataSize, _GUID guid) {
    if (lobby_game == 0) return 0;

    unsigned total = dataSize + 0x30;
    TDebuggingLog_Log(L, "Sending %d bytes to the Zone (Total message size = %d)", dataSize, total);

    char* buf = (char*)operator new(total);
    *(unsigned int*)buf = 5;
    *(unsigned int*)(buf + 4) = 0;
    *(unsigned int*)(buf + 8) = GUID_NULL.Data1;
    *(unsigned int*)(buf + 0xC) = GUID_NULL.Data2;
    *(unsigned int*)(buf + 0x10) = GUID_NULL.Data3;
    *(unsigned int*)(buf + 0x14) = GUID_NULL.Data4[0];
    *(unsigned int*)(buf + 0x18) = GUID_NULL.Data4[2];
    *(unsigned int*)(buf + 0x1C) = GUID_NULL.Data4[4];
    *(unsigned int*)(buf + 0x20) = GUID_NULL.Data4[6];
    *(unsigned int*)(buf + 0x28) = total;

    memmove(buf + 0x2C, data, dataSize);

    long result;
    result = ((long(__stdcall*)(void*, int, int, void*, unsigned))(*(unsigned int**)glpDPL2 + 7))(glpDPL2, 0, 0, buf, total);
    operator delete(buf);

    if (result == 0) {
        TDebuggingLog_Log(L, "SendLobbyMessage returns OK");
    }
    Err->ShowReturn(result, "Send Lobby Msg");
    return result;
}
