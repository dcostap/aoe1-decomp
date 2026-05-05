struct _GUID { unsigned long Data1; unsigned short Data2; unsigned short Data3; unsigned char Data4[8]; };
struct DPVtbl { long (__stdcall *QueryInterface)(void*, const _GUID*, void**); void* f04; long (__stdcall *Steps)(void*); void* f0c; void* f10; void* f14; void* f18; void* f1c; void* f20; void* f24; long (__stdcall *EnableNewPlayers)(void*, int); };
struct IDirectPlay2 { DPVtbl* vtbl; };
class TDebuggingLog;
extern TDebuggingLog* L;
void Log(TDebuggingLog* log, char* text, unsigned long value);
class TCommunications_Handler { public: long EnableNewPlayers(IDirectPlay2* dp, int enable); };
long TCommunications_Handler::EnableNewPlayers(IDirectPlay2* dp, int enable) {
    if (dp == 0) return 0x80070057;
    IDirectPlay2* dp2;
    long hr = dp->vtbl->QueryInterface(dp, (const _GUID*)0x56F0D0, (void**)&dp2);
    if (hr < 0) return hr;
    hr = dp2->vtbl->EnableNewPlayers(dp2, enable);
    unsigned long links = dp2->vtbl->Steps(dp2);
    Log(L, "Released to links=%d", links);
    return hr;
}
