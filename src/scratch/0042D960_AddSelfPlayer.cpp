// TCommunications_Handler::AddSelfPlayer (0042D960)
// PDB source: Com_hand.cpp:5717-5759
// Size: 230 bytes
// PARKED - pure VC5 instruction scheduling drift

// Attempt log:
// - Probe 1 (DPNAME struct + DPVT abstract class + void return): 208 bytes
//   Issues: void return type (no eax set), wrong vtable dispatch (ecx=this not stack)
// - Probe 2 (int return + manual vtable dispatch): 224 bytes (6 short)
//   Major progress! Fixed return value and COM __stdcall vtable dispatch
//   Remaining: missing xor ecx,ecx (2 bytes), lea [esi+1179h] (6 bytes), 
//   temp stores (6 bytes) — all VC5 scheduling choices
// - Probe 3 (added dwFlags=0x10 + scope-based zero init): 224 bytes
//   Schedule unchanged; compiler still uses mov [esp+N],0 instead of xor+mov
// - Probe 4 (int[] array instead of struct + direct derefs): 224 bytes
//   Same result
//
// Remaining: Pure VC5 scheduling/register drift. The DECLARATION ORDER and 
// interleaving of Log-call arg setup with DPNAME field stores is tightly 
// coupled to the original's TU context and inline scheduling.
// 
// Key structural insights:
// - COM __stdcall CreatePlayer requires manual vtable dispatch (this on stack)
// - TDebuggingLog::Log is __cdecl with 2-3+ stack args (caller cleans)
// - DPNAME fields: dwFlags final=0x10, lpszB=&MyFriendlyName(+0x10F8)
// - Send/Recv error path uses another field at +0x1179 (lea/not used directly)
// - 3 return paths: early(ret 0), error(ret 0), success(ret 1)

extern "C" void __cdecl _Log(void* log, char* fmt, ...);

struct RGE_Comm_Error {
    void ShowReturn(long retval, char* msg);
};

struct TCommunications_Handler {
    unsigned char g0[0x10F8];
    char name_friendly[0x81];
    unsigned char g1[0x2C7];
    RGE_Comm_Error* err;
    unsigned char g2[0x78];
    int program_state;
    
    int AddSelfPlayer();
    void CloseSession();
    void ReleaseComm();
    void GetMyMultiPlayerCaps();
};

typedef int (__stdcall *CreatePlayerFn)(void* self, void* id, void* name,
                                        int a, int b, int c, int d);

int TCommunications_Handler::AddSelfPlayer()
{
    int names_[4];
    int* nf = (int*)((char*)this + 0x10F8);
    
    _Log(*(void**)0x62C4FC, "Create the player");
    names_[0] = 0;
    names_[1] = 0;
    names_[2] = 0;
    names_[3] = (int)nf;
    names_[0] = 0x10;
    
    _Log(*(void**)0x62C4FC, "Adding player [%s]", (char*)nf);
    
    void* dp = *(void**)0x62C5EC;
    if (dp == 0) {
        return 0;
    }
    
    void** vt = *(void***)dp;
    CreatePlayerFn create = (CreatePlayerFn)vt[6];
    int retval = create(dp, (void*)0x62CF04, names_, 0, 0, 0, 0);
    
    err->ShowReturn(retval, "Add SELF PLAYER");
    
    if (retval != 0) {
        CloseSession();
        ReleaseComm();
        program_state = 1;
        return 0;
    }
    
    _Log(*(void**)0x62C4FC, "Rcvd DPID of %d", *(int*)0x62CF04);
    GetMyMultiPlayerCaps();
    return 1;
}
