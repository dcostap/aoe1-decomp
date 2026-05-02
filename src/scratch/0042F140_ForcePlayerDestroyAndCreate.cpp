// VA: 0042F140 ForcePlayerDestroyAndCreate (78B)
// Original: Log, virtual call, AddSelfPlayer, Log
// Use absolute addresses for global variables

extern "C" void __cdecl Log(void* log, const char* text, ...);

class TCommunications_Handler {
public:
    void ForcePlayerDestroyAndCreate(void);
};

void __cdecl AddSelfPlayer(void*);

void TCommunications_Handler::ForcePlayerDestroyAndCreate() {
    Log(*(void**)0x62C4FC, (const char*)0x583294);
    
    void* com_global = *(void**)0x62C5EC;
    void* param = *(void**)0x62CF04;
    
    void** vtbl = *(void***)com_global;
    ((long (__stdcall*)(void*, void*))vtbl[9])(com_global, param);
    
    *(int*)0x62CF04 = 0;
    
    AddSelfPlayer(this);
    
    Log(*(void**)0x62C4FC, (const char*)0x583284);
}
