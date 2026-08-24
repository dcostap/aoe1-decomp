extern void* DAT_0062c4fc;
void __cdecl debug_log_fpe(void* log, const char* msg);
extern char DAT_0058325c[];

struct IDirectPlay_vtbl {
    char gap_00[0x30];
    int (__stdcall *EnumPlayers)(void* thisptr, int flags, void* callback, void* context, int extra);
};

struct IDirectPlay_obj {
    IDirectPlay_vtbl* vtbl;
};

#if !defined(COM_HAND_TU_CONTEXT)
extern IDirectPlay_obj* DAT_0062c5ec;
#endif // COM_HAND_TU_CONTEXT

void __stdcall EnumPlayersCallback(void);

class TCommunications_Handler_fpe {
public:
    void ForcePlayerEnumeration(void);
};


void TCommunications_Handler_fpe::ForcePlayerEnumeration(void) {
    debug_log_fpe(DAT_0062c4fc, DAT_0058325c);
    IDirectPlay_obj* dp = (IDirectPlay_obj*)DAT_0062c5ec;
    dp->vtbl->EnumPlayers(dp, 0, (void*)EnumPlayersCallback, this, 0);
}
