// attempt 1: direct COM/vtable shape with the null-arg guard and the logging tail
// result: VC5 keeps loading the incoming pointer through ecx instead of the original stack-load eax basin
// attempt 2: try the same body with a plain local alias for the incoming pointer, then stop if the basin stays wrong

struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

class IDirectPlay2 {
public:
    virtual long QueryInterface(const _GUID* riid, void** outObject);
    virtual long vf04();
    virtual long vf08();
    virtual long vf0C();
    virtual long vf10();
    virtual long vf14();
    virtual long vf18();
    virtual long vf1C();
    virtual long vf20();
    virtual long vf24();
    virtual long EnableNewPlayers(int param_2);
    virtual long vf2C();
    virtual long vf30();
};

class TDebuggingLog {
public:
    void Log(char* text, unsigned long value);
};

extern TDebuggingLog* g_debug_log;
class TCommunications_Handler {
public:
    long EnableNewPlayers(IDirectPlay2* param_1, int param_2);
};

long TCommunications_Handler::EnableNewPlayers(IDirectPlay2* param_1, int param_2) {
    IDirectPlay2* pDirectPlay;
    IDirectPlay2* pNewObj;
    long hr;
    long log_value;

    pDirectPlay = param_1;
    if (pDirectPlay == 0) {
        return 0x80070057;
    }

    pNewObj = 0;
    hr = pDirectPlay->QueryInterface((const _GUID*)0x56F0D0, (void**)&pNewObj);
    if (hr < 0) {
        return hr;
    }

    hr = pNewObj->EnableNewPlayers(param_2);
    log_value = pNewObj->vf08();
    g_debug_log->Log((char*)0x583188, (unsigned long)log_value);
    return hr;
}
