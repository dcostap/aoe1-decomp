// attempt 7: COM-style vtable and aggregate GUID assignment
#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog { public: void Log(char* fmt, ...); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT
struct CommVtbl { void* f0; void* f4; int (__stdcall *Steps)(void*); };
struct Comm { CommVtbl* vtbl; };
extern Comm* DirectPlay3A;
#if !defined(COM_HAND_TU_CONTEXT)
struct GUID16 { int a,b,c,d; };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x12DC];
    GUID16 ServiceGUID;
    char gap_12EC[0x2C];
    GUID16 NullGUID;
protected:
    long ReleaseComm();
};
#endif // COM_HAND_TU_CONTEXT

long TCommunications_Handler::ReleaseComm() {
    if (DirectPlay3A != 0) {
        int links = DirectPlay3A->vtbl->Steps(DirectPlay3A);
        L->Log("1.Release COMM links=%d", links);
        this->ServiceGUID = this->NullGUID;
        DirectPlay3A = 0;
    }
    return 0;
}
