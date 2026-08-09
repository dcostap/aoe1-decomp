// VA: 004261E0 TCommunications_Handler::~TCommunications_Handler()
// PDB source: Com_hand.cpp lines 335-380
// Attempt log:
//   baseline: natural scalar cleanup, resend log scan, vector cleanup, and child deletes;
//     exact size/frame/call count but the helper symbol and loop register/address shape drifted.
//   ABI: corrected the cleanup helper to __cdecl-name `eh_vector_destructor_iterator`;
//     all 21 ordered calls and relocation identities then aligned.
//   liveness: removed the local this alias; this improved the broad drift from 300 to 42
//     differing bytes while retaining the original no-frame shape.
//   declaration-scope and typed Resend/DestMap variants were tested; late child-pointer
//     declarations were codegen-identical, while natural pointer/DestMap forms regressed
//     to a 370-byte basin. Restored the best direct-this source.
// Left in scratch: the remaining 42 bytes are a localized VC5 callee-save/address family:
//   rebuilt keeps this in ESI and loop offset/child temporaries in EDI, while original keeps
//   this in EDI and offset/delete pointers in ESI, including its explicit entry LEA. The
//   A volatile/raw-offset Resend diagnostic reproduced the reload but was not
//   retained. Living source uses the owning RESENDER array and named fields.

class RESENDER;
class HOLDER;
void __cdecl operator_delete(void* p);
extern "C" void __stdcall eh_vector_destructor_iterator(void* ptr, unsigned int size, int count, void* dtor);
void __cdecl RESENDER_dtor(RESENDER* p);
void __cdecl HOLDER_dtor(HOLDER* p);

class TDebuggingLog {
public:
    void __cdecl Log(char* fmt, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
};
extern TDebuggingLog* L;
extern char s_resender_status[];

class RESENDER {
public:
    int state;
    int active;
    void* data;
    int field_0C;
    int acknowledgements[10];
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
    this->DestroyMultiplayerGame();
    this->CloseSession();
    this->ReleaseComm();
    this->FreeOptions();
    operator_delete(this->FriendlyName);
    operator_delete(this->FormalName);

    int slot = 0;
    do {
        RESENDER* entry = &this->Resend[slot];
        if (entry->active != 0) {
            L->Log(s_resender_status, slot, entry->active,
                entry->field_0C,
                entry->acknowledgements[1], entry->acknowledgements[2],
                entry->acknowledgements[3], entry->acknowledgements[4],
                entry->acknowledgements[5], entry->acknowledgements[6],
                entry->acknowledgements[7], entry->acknowledgements[8]);
        }
        slot++;
    } while (slot < 502);

    if (this->Resend != 0) {
        void* p = (char*)this->Resend - 4;
        eh_vector_destructor_iterator(this->Resend, 0x38, *(int*)p, (void*)RESENDER_dtor);
        operator_delete(p);
    }
    if (this->OnHold != 0) {
        void* p = (char*)this->OnHold - 4;
        eh_vector_destructor_iterator(this->OnHold, 0x18, *(int*)p, (void*)HOLDER_dtor);
        operator_delete(p);
    }

    RGE_Communications_Queue* q = this->InQ;
    if (q != 0) {
        q->~RGE_Communications_Queue();
        operator_delete(q);
    }

    RGE_Lobby* lobby = this->Lobby;
    if (lobby != 0) {
        lobby->~RGE_Lobby();
        operator_delete(lobby);
    }

    RGE_Communications_Speed* speed = this->Speed;
    if (speed != 0) {
        speed->~RGE_Communications_Speed();
        operator_delete(speed);
    }

    RGE_Communications_Synchronize* sync = this->Sync;
    if (sync != 0) {
        sync->~RGE_Communications_Synchronize();
        operator_delete(sync);
    }

    RGE_Comm_Error* err = this->Err;
    if (err != 0) {
        err->~RGE_Comm_Error();
        operator_delete(err);
    }
}
