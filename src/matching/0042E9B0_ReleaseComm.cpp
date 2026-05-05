// attempt 7: COM-style vtable and aggregate GUID assignment
class TDebuggingLog { public: void Log(char* fmt, ...); };
extern TDebuggingLog* L;
struct CommVtbl { void* f0; void* f4; int (__stdcall *Steps)(void*); };
struct Comm { CommVtbl* vtbl; };
extern Comm* DirectPlay3A;
struct GUID16 { int a,b,c,d; };
class TCommunications_Handler {
public:
    char gap_00[0x12DC];
    GUID16 ServiceGUID;
    char gap_12EC[0x2C];
    GUID16 NullGUID;
    long ReleaseComm();
};
long TCommunications_Handler::ReleaseComm() {
    if (DirectPlay3A != 0) {
        int links = DirectPlay3A->vtbl->Steps(DirectPlay3A);
        L->Log("1.Release COMM links=%d", links);
        this->ServiceGUID = this->NullGUID;
        DirectPlay3A = 0;
    }
    return 0;
}
