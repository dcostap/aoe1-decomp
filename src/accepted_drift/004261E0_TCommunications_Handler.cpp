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
// Historical result: the remaining 42 bytes were a localized VC5 callee-save/address family:
//   rebuilt keeps this in ESI and loop offset/child temporaries in EDI, while original keeps
//   this in EDI and offset/delete pointers in ESI, including its explicit entry LEA. The
//   narrow volatile Resend reread is retained because the oracle visibly reloads +0x1520 at
//   every loop iteration around the logging call. No inline asm; default /O2 /Oy.
// Follow-up session: complete RESENDER/DestMap and per-slot typed forms moved to a 370-byte
// SIB-address basin or a 300-byte register basin; declaration-only full RESENDER and full
// TCommunications_Handler layouts emitted the same clean 42-byte result. A 12-variant natural
// loop lab found no exact form; its closest edit basin was the known 370-byte local-resend
// variant. Restored the clean direct-this source; remaining gap is still the ESI/EDI coloring
// and entry LEA family, with all 21 ordered calls, size, and frame exact.
// Follow-up probes: loading active through a local resend pointer and forming the log entry
// from the direct member gave a 364-byte, full-shape 38-byte diff. Volatile local, typed-record,
// declaration-order, and register-keyword variants did not improve it. Keep the 38-byte source
// reconstruction; the remaining drift is the this/offset callee-save assignment.
// Main-agent audit rejected the byte-offset cursor and raw string address. The
// canonical 0x38-byte RESENDER record and typed array walk rebuild to 364 bytes
// with all 21 calls aligned; the wider 298-byte diff is accepted in scratch.
// Follow-up: typed slot indexing with an unsigned bound preserves the observed
// per-iteration Resend reload and improves shape to 96.85% with 96% exact blocks;
// declaration order is a codegen duplicate. Keep this natural record form.
// Follow-up probe: in-loop RESENDER base plus entry declarations preserved the
// same 364-byte, 96.85%-shape output; restored the current typed source.
// Follow-up probe: direct typed member indexing forms the original loop block and
// reduces the strict gap to 38 bytes. The remaining gap is only ESI/EDI coloring.
// Pointer-scope, destructor-surface, vector-pointer, ambient-context, header, alias,
// field-type, loop-type, and declaration-order probes did not change that basin.
// Current pass: a 48-variant natural delete[] flag/header lab found that /GX restores
// the 364-byte, 21-call helper basin, but still recolors EDI/ESI. Default flags keep the
// 392-byte inline-destructor basin. Explicit offset/index, counter-width, unwind-macro,
// and destructor exception-spec probes did not improve either basin. The /GX result is
// useful flag evidence. Main-agent review assigned /GX because the executable's two
// eh_vector_destructor_iterator calls directly prove exception-enabled vector cleanup.
// Ownership review: FriendlyName/FormalName are NAME* and HOLDER is the canonical
// six-field 0x18-byte record. Main review keeps source-level delete expressions;
// compiler cleanup helpers and allocation cookies are not original source forms.
// ACCEPTED DRIFT: with the binary-supported /GX context, size, frame, all 125
// instruction shapes, all 21 calls, all CFG blocks, and cleanup agree. Every one
// of the 38 changed bytes is the same consistent ESI/EDI register exchange. EDI
// holds this in the executable while ESI holds it in the rebuild. The inverse
// register owns the same loop and delete values. Calls, predicates, reads, writes,
// destructor order, exception cleanup, fault order, ABI, and results are unchanged.

#include "../../include/com_hand_context.h"

#if 0
class RESENDER;
class HOLDER;
class NAME;

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    void __cdecl Log(char* fmt, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class NAME {
public:
    char Text[128];
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RESENDER {
public:
    unsigned int TimeSent;
    unsigned int Serial;
    char* ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];
    ~RESENDER();
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class HOLDER {
public:
    char* HoldMsg;
    unsigned int Serial;
    unsigned int Length;
    unsigned long dcoFromID;
    unsigned long dcoReceiveID;
    unsigned int fromPlayer;
    ~HOLDER();
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Queue { public: ~RGE_Communications_Queue(); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Lobby { public: ~RGE_Lobby(); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Speed { public: ~RGE_Communications_Speed(); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Synchronize { public: ~RGE_Communications_Synchronize(); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error { public: ~RGE_Comm_Error(); };
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0x12C8];
    NAME* FriendlyName;                 // +0x12C8
    NAME* FormalName;                   // +0x12CC
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
#endif // COM_HAND_TU_CONTEXT

#endif

TCommunications_Handler::~TCommunications_Handler() {
    this->DestroyMultiplayerGame();
    this->CloseSession();
    this->ReleaseComm();
    this->FreeOptions();
    delete this->FriendlyName;
    delete this->FormalName;

    unsigned int slot = 0;
    do {
        if (this->Resend[slot].Serial != 0) {
            L->Log("NO MSG Slot#%d  Ser#%d  Len=%d  DEST=%d,%d,%d,%d,%d,%d,%d,%d",
                slot, this->Resend[slot].Serial, this->Resend[slot].Length,
                this->Resend[slot].DestMap[1], this->Resend[slot].DestMap[2], this->Resend[slot].DestMap[3],
                this->Resend[slot].DestMap[4], this->Resend[slot].DestMap[5], this->Resend[slot].DestMap[6],
                this->Resend[slot].DestMap[7], this->Resend[slot].DestMap[8]);
        }
        slot++;
    } while (slot <= 501);

    delete[] this->Resend;
    delete[] this->OnHold;
    delete this->InQ;
    delete this->Lobby;
    delete this->Speed;
    delete this->Sync;
    delete this->Err;
}
