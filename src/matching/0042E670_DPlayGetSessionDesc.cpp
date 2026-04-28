struct GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

void* __cdecl calloc(unsigned int count, unsigned int size);
void __cdecl free(void* ptr);

class RGE_Comm_Error {
public:
    void* HostHWND;            // +0x00
    long LastReportedError;    // +0x04

    void ShowReturn(long result, const char* msg);
};

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

// COM-like interface with GetSessionDesc at vtable[22] (offset 0x58)
struct ISession {
    virtual long __stdcall v00() = 0;
    virtual long __stdcall v01() = 0;
    virtual long __stdcall v02() = 0;
    virtual long __stdcall v03() = 0;
    virtual long __stdcall v04() = 0;
    virtual long __stdcall v05() = 0;
    virtual long __stdcall v06() = 0;
    virtual long __stdcall v07() = 0;
    virtual long __stdcall v08() = 0;
    virtual long __stdcall v09() = 0;
    virtual long __stdcall v10() = 0;
    virtual long __stdcall v11() = 0;
    virtual long __stdcall v12() = 0;
    virtual long __stdcall v13() = 0;
    virtual long __stdcall v14() = 0;
    virtual long __stdcall v15() = 0;
    virtual long __stdcall v16() = 0;
    virtual long __stdcall v17() = 0;
    virtual long __stdcall v18() = 0;
    virtual long __stdcall v19() = 0;
    virtual long __stdcall v20() = 0;
    virtual long __stdcall v21() = 0;
    virtual long __stdcall GetSessionDesc(void* buf, unsigned long* dwSize) = 0;
};

class TCommunications_Handler {
public:
    // Fields we care about:
    char gap_0000[0x127C];
    unsigned long CurrentPlayers;   // +0x127C
    char gap_1280[0x7C];
    GUID SessionGUID;               // +0x12FC
    char gap_130C[0x1D4];
    RGE_Comm_Error* Err;            // +0x14E0

    long DPlayGetSessionDesc();
};

long TCommunications_Handler::DPlayGetSessionDesc() {
    unsigned long dwSize;
    long result;
    void* buf;

    if (*(void**)0x62C5EC == 0) {
        return 0x80004005;
    }

    ((ISession*)*(void**)0x62C5EC)->GetSessionDesc(0, &dwSize);
    buf = calloc(dwSize, 1);
    if (buf == 0) {
        return 0x8007000E;
    }

    result = ((ISession*)*(void**)0x62C5EC)->GetSessionDesc(buf, &dwSize);
    Err->ShowReturn(result, (const char*)0x582D40);

    if (result == 0) {
        SessionGUID = *(GUID*)((char*)buf + 8);
        unsigned long players = *(unsigned long*)((char*)buf + 0x2C);
        CurrentPlayers = players;
        ((TDebuggingLog*)*(void**)0x62C4FC)->Log((const char*)0x582D28, players);
    }

    free(buf);
    return result;
}

void* __cdecl calloc(unsigned int count, unsigned int size) { return 0; }
void __cdecl free(void* ptr) { }
void RGE_Comm_Error::ShowReturn(long result, const char* msg) { }
void TDebuggingLog::Log(const char* format, ...) { }
