// VA: 004261E0 TCommunications_Handler::~TCommunications_Handler()
// PDB source: Com_hand.cpp lines 335-380
// attempt 1: natural destructor sequence, explicit scalar dtors/deletes, delete[] for two vector arrays, unsigned byte-offset log loop; mismatch: VC5 inlined vector delete loops and saved EBP.
// attempt 2: call vector-destructor iterator explicitly and reload Resend through a volatile field each loop to avoid cached EBP base; fixed no-EBP prologue but swapped this/offset ESI/EDI.
// attempt 3: introduce a local this alias and use it throughout; no change, still ESI=this/EDI=offset.
// attempt 4: declare offset before slot; worsened init order and still ESI=this/EDI=offset.
// attempt 5: use register hints with slot first, offset second; no register-color change.
// attempt 6: vector destructor iterator is stdcall/callee-cleanup like original; removed cleanup drift but ESI/EDI coloring still swapped.
// attempt 7: predeclare scalar cleanup pointer locals at function top; no register-color change.
// attempt 8: /O1 probe produced too-small .text; removed flags and kept default /O2 /Oy.
// left in scratch: behavior/call set are modeled, no inline asm. Main blocker is VC5 callee-saved register coloring: rebuilt keeps this in ESI and loop/delete temps in EDI, while original keeps this in EDI and uses ESI for the resend offset/delete pointers. Explicit stdcall vector-destructor helper fixed cleanup shape but not coloring.

class RESENDER;
class HOLDER;
void __cdecl operator_delete(void* p);
void __stdcall vector_destructor_iterator(void* ptr, unsigned int size, int count, void* dtor);
void __cdecl RESENDER_dtor(RESENDER* p);
void __cdecl HOLDER_dtor(HOLDER* p);

class TDebuggingLog {
public:
    void __cdecl Log(char* fmt, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
};
extern TDebuggingLog* L;

class RESENDER {
public:
    char data[0x38];
    ~RESENDER();
};

class HOLDER {
public:
    char data[0x18];
    ~HOLDER();
};

class RGE_Communications_Queue { public: ~RGE_Communications_Queue(); };
class RGE_Lobby { public: ~RGE_Lobby(); };
class RGE_Communications_Speed { public: ~RGE_Communications_Speed(); };
class RGE_Communications_Synchronize { public: ~RGE_Communications_Synchronize(); };
class RGE_Comm_Error { public: ~RGE_Comm_Error(); };

class TCommunications_Handler {
public:
    char gap_0000[0x12C8];
    void* FriendlyName;                 // +0x12C8
    void* FormalName;                   // +0x12CC
    char gap_12D0[0x1F4];
    RGE_Communications_Queue* InQ;      // +0x14C4
    char gap_14C8[4];
    RGE_Lobby* Lobby;                   // +0x14CC
    char gap_14D0[4];
    RGE_Communications_Speed* Speed;    // +0x14D4
    RGE_Communications_Synchronize* Sync;// +0x14D8
    char gap_14DC[4];
    RGE_Comm_Error* Err;                // +0x14E0
    char gap_14E4[0x3C];
    RESENDER* Resend;                   // +0x1520
    HOLDER* OnHold;                     // +0x1524

    void DestroyMultiplayerGame();
    long CloseSession();
    long ReleaseComm();
    void FreeOptions();
    ~TCommunications_Handler();
};

TCommunications_Handler::~TCommunications_Handler() {
    RGE_Communications_Queue* q;
    RGE_Lobby* lobby;
    RGE_Communications_Speed* speed;
    RGE_Communications_Synchronize* sync;
    RGE_Comm_Error* err;
    TCommunications_Handler* th = this;

    th->DestroyMultiplayerGame();
    th->CloseSession();
    th->ReleaseComm();
    th->FreeOptions();
    operator_delete(th->FriendlyName);
    operator_delete(th->FormalName);

    int slot = 0;
    unsigned int offset = 0;
    do {
        char* entry = (char*)*(RESENDER* volatile*)((char*)th + 0x1520) + offset;
        int active = *(int*)(entry + 4);
        if (active != 0) {
            L->Log((char*)0x580D00, slot, active,
                *(int*)(entry + 0x0C),
                *(int*)(entry + 0x14),
                *(int*)(entry + 0x18),
                *(int*)(entry + 0x1C),
                *(int*)(entry + 0x20),
                *(int*)(entry + 0x24),
                *(int*)(entry + 0x28),
                *(int*)(entry + 0x2C),
                *(int*)(entry + 0x30));
        }
        offset += 0x38;
        slot++;
    } while (offset <= 0x6D98);

    if (th->Resend != 0) {
        void* p = (char*)th->Resend - 4;
        vector_destructor_iterator(th->Resend, 0x38, *(int*)p, (void*)RESENDER_dtor);
        operator_delete(p);
    }
    if (th->OnHold != 0) {
        void* p = (char*)th->OnHold - 4;
        vector_destructor_iterator(th->OnHold, 0x18, *(int*)p, (void*)HOLDER_dtor);
        operator_delete(p);
    }

    q = th->InQ;
    if (q != 0) {
        q->~RGE_Communications_Queue();
        operator_delete(q);
    }

    lobby = th->Lobby;
    if (lobby != 0) {
        lobby->~RGE_Lobby();
        operator_delete(lobby);
    }

    speed = th->Speed;
    if (speed != 0) {
        speed->~RGE_Communications_Speed();
        operator_delete(speed);
    }

    sync = th->Sync;
    if (sync != 0) {
        sync->~RGE_Communications_Synchronize();
        operator_delete(sync);
    }

    err = th->Err;
    if (err != 0) {
        err->~RGE_Comm_Error();
        operator_delete(err);
    }
}
