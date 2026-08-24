// VA: 0042A180 TCommunications_Handler::StoreIncoming
// Com_hand.cpp lines 3237-3305
// Attempt log:
// 1: natural indexed source: comparable full-size output, but prologue/registers wrong (len in EDI, this in EBP); pos 77.9376%, edit 79.3765%.
// 2: explicit self/length locals and pointer-walk scans worsened; duplicate case returned inline and edit diff >116%.
// 3: declarations delayed until after zero-length log: no prologue improvement; still this=EBX/len=EDI and duplicate inline.
// tried flags /O2 no-/Oy, /Ox, /Ob0: same; /O1 too short.
// session: canonical TDebuggingLog member surface plus memcpy restored REP MOVSD/MOVSB,
// exact prologue/first scans, unsigned jbe/jb bounds, and 99.31% shape. The only
// remaining codegen hunk is the cold full-table base/offset register coloring (+2B).
// left in scratch: behavior modeled, but VC5 standalone register allocation won't produce original len=EBX, this=EDI, late duplicate handler; broad drift, not accepted_drift-safe.
// Follow-up: reordered the cold zero assignments to match xor EBP then EBX and used the
// direct OnHold base expression; this reduced the positional diff from 111 to 109 bytes.
// A direct Length predicate reduced the metric to 96 bytes but changed the exact log-argument
// schedule, so it was rolled back. The current source keeps the natural named scan cursor.
// Main-agent audit replaced both byte-offset HOLDER cursors with typed indexing
// and pointer iteration. Keep canonical 0x18-byte record ownership in scratch.
// Follow-up: direct typed OnHold Length assignment improves the indexed store
// encoding by one byte; separate typed entry/base pointers are compiler duplicates.
// Direct repeated field accesses destroy the earlier CFG, so the simple HOLDER
// entry form remains. Do not reintroduce byte-offset cursors for the cold report.
// Readiness audit found that each cold-report iteration must reload OnHold after
// Log returns. This preserves reuse or invalidation by the callback.
// Follow-up: packet-backed `this->OnHold + i` assignment matched the original
// pHVar9 form but emitted duplicate code; restored the indexed spelling.
// Assigned pass sa-e4d2a8b8, 2026-08-16: baseline retained at 415 bytes, 144
// instructions, 99.31% shape, six ordered calls, and 278 positional diff bytes.
// Probes 1, 3-5, 9, 11-14, 17-18 produced the same code or the same basin.
// Probe 2 repeated typed member access caused a 436-byte control-flow basin.
// Probe 6 used the scan cursor for Length and worsened one store byte.
// Probe 7 reduced diagnostic diff bytes to 128 but changed the cold loop basin.
// Probe 8 moved pointer setup before Length and broke the prologue and CFG.
// Probe 10 used a raw-style Length cursor and added a loop branch.
// Probe 15 failed qualification because volatile OnHold needed unsafe casts.
// Probe 16 reused the scan cursor for the successful slot and broke the frame.
// Natural `new char[]` and the declared HOLDER class are codegen-identical and
// remain the simplest period-plausible source. The remaining mismatch is local
// register and SIB-base coloring around allocation and final record stores.
// Revisit pass sa-b719bbdc-r1, 2026-08-17: restoring a typed cursor with `h += i`
// broke the prologue and CFG. Using `h[i].Length` with typed pointer addition,
// swapping declaration order, and reversing the valid pointer-add operands all
// stayed in the clean basin or worsened it. Keep the pinned typed packet source.
// Revisit pass sa-bce60210-r1, 2026-08-17: PDB type records confirm HOLDER's
// fromPlayer field and Store/Clear member surface; restoring them and using the
// PDB parameter names was codegen-neutral. Natural slot-pointer, reference,
// direct-length, declaration, and base-alias forms did not recover the two-byte
// allocation hunk. A five-variant typed slot family also found no exact result;
// separate slot locals entered a worse prologue basin. Keep this natural source.
// Accepted-drift review: the rebuild loads OnHold directly into EBP and adds
// the slot offset. The executable loads OnHold into EAX, copies the offset into
// EBP, and then adds EAX. Both form the same HOLDER address. All packet reads,
// allocation and REP-copy effects, member stores, callback-time OnHold reloads,
// six calls, arguments, and return values keep the same order.
// Continuation pass sa-7c90eee8, 2026-08-24: complete communications-handler
// declarations, the grouped com_hand wrapper, explicit operator_new calls,
// typed aliases, references, and address forms all stayed in the clean 415-byte
// / 278-diff basin or worsened the CFG. Restored the natural reviewed source.

#include <string.h>

typedef unsigned int uint;
typedef unsigned long ulong;

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog { public: void Log(char* fmt, ...); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class HOLDER {
public:
    char* HoldMsg;
    uint Serial;
    uint Length;
    ulong dcoFromID;
    ulong dcoReceiveID;
    uint fromPlayer;
    HOLDER();
    ~HOLDER();
    void Store(char*, uint);
    void Clear();
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1524];
    HOLDER* OnHold;

    int StoreIncoming(uint SerialNumber, char* InBuff, uint Length, ulong dcoFromID, ulong dcoReceiveID);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::StoreIncoming(uint SerialNumber, char* InBuff, uint Length, ulong dcoFromID, ulong dcoReceiveID)
{
    HOLDER* h;
    unsigned int i;

    if (Length == 0) {
        L->Log("+++StoreIncoming called for zero-length message");
    }

    h = this->OnHold;
    for (i = 0; i <= 0x1F5; i++) {
        if (h[i].Serial == SerialNumber && h[i].dcoFromID == dcoFromID) {
            L->Log("Future Ser#%d previously stored (Slot#%d)", SerialNumber, i);
            return 1;
        }
    }

    for (i = 0; i < 0x1F5; i++) {
        if (h[i].Length == 0 && Length != 0) {
            this->OnHold[i].Length = Length;
            h = &this->OnHold[i];
            h->HoldMsg = new char[h->Length];
            if (h->HoldMsg != 0) {
                memcpy(h->HoldMsg, InBuff, h->Length);
                h->Length = Length;
            }
            this->OnHold[i].Serial = SerialNumber;
            this->OnHold[i].dcoFromID = dcoFromID;
            this->OnHold[i].dcoReceiveID = dcoReceiveID;
            return 1;
        }
    }

    L->Log("+++ DID NOT STORE:  ");
    if (i > 0x1EB) {
        L->Log("HOLD FULL WARNING.  COUNT=%d", i);
        i = 0;
        do {
            HOLDER* scan_h = &this->OnHold[i];
            if (scan_h->Length != 0) {
                L->Log("S#%d  Ser#%d FromID=%d Len=%d  CMD='%c' B0=%d B1=%d", i, scan_h->Serial, scan_h->dcoFromID, scan_h->Length, (int)scan_h->HoldMsg[0], (int)scan_h->HoldMsg[0], (int)scan_h->HoldMsg[1]);
            }
            i++;
        } while (i < 501);
    }
    return 1;
}
