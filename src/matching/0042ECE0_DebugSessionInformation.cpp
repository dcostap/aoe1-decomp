// VA: 0042ECE0 TCommunications_Handler::DebugSessionInformation
// Source: Com_hand.cpp lines 6689-6718
// Attempt log:
// 1: initial direct reconstruction from packet: sequence of debugging log calls and StringFromGUID.

typedef unsigned short ushort;

typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;

struct DPSESSIONDESC2 {
    unsigned long dwSize;
    unsigned long dwFlags;
    GUID guidInstance;
    GUID guidApplication;
    unsigned long dwMaxPlayers;
    unsigned long dwCurrentPlayers;
    char* lpszSessionNameA;
    void* lpszSessionNameW;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
    void* lpUser1;
    void* lpUser2;
    void* lpUser3;
    void* lpUser4;
};

class TDebuggingLog {
public:
    void Log(char* fmt, ...);
};

class TCommunications_Handler {
public:
    void DebugSessionInformation(DPSESSIONDESC2* desc);
};

extern TDebuggingLog* L;
extern "C" int __cdecl StringFromGUID(GUID* guid, ushort* out);

void TCommunications_Handler::DebugSessionInformation(DPSESSIONDESC2* desc)
{
    ushort wszSPGuid[40];

    L->Log((char*)"--Information in DPSESSIONDESC2 --");
    L->Log((char*)"Size DPSESSIONDESC2 =%d", desc->dwSize);
    L->Log((char*)"Flags               =%d", desc->dwFlags);
    L->Log((char*)"Instance guid  DATA1=%u", desc->guidInstance.Data1);
    L->Log((char*)"               DATA2=%d", desc->guidInstance.Data2);
    L->Log((char*)"               DATA3=%d", desc->guidInstance.Data3);
    L->Log((char*)"               DATA4=%u", desc->guidInstance.Data4);
    StringFromGUID(&desc->guidInstance, wszSPGuid);
    L->Log((char*)"Instance GUID  str  =%s", wszSPGuid);
    L->Log((char*)"Applicatn guid DATA1=%u", desc->guidApplication.Data1);
    L->Log((char*)"               DATA2=%d", desc->guidApplication.Data2);
    L->Log((char*)"               DATA3=%d", desc->guidApplication.Data3);
    L->Log((char*)"               DATA4=%u", desc->guidApplication.Data4);
    L->Log((char*)"Max Players         =%d", desc->dwMaxPlayers);
    L->Log((char*)"Current Players     =%d", desc->dwCurrentPlayers);
    L->Log((char*)"Reserved 1          =%d", desc->dwReserved1);
    L->Log((char*)"Reserved 2          =%d", desc->dwReserved2);
    L->Log((char*)"User 1              =%d", desc->lpUser1);
    L->Log((char*)"User 2              =%d", desc->lpUser2);
    L->Log((char*)"User 3              =%d", desc->lpUser3);
    L->Log((char*)"User 4              =%d", desc->lpUser4);
    L->Log((char*)"--End Info--");
}
