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
// Log returns. This preserves replacement or invalidation by the callback.

#include <string.h>

typedef unsigned int uint;
typedef unsigned long ulong;

class TDebuggingLog { public: void Log(char* fmt, ...); };
extern TDebuggingLog* L;
extern void* operator_new(unsigned int size);

struct HOLDER {
    char* HoldMsg;
    uint Serial;
    uint Length;
    ulong dcoFromID;
    ulong dcoReceiveID;
    int unused;
};

class TCommunications_Handler {
public:
    char gap_00[0x1524];
    HOLDER* OnHold;

    int StoreIncoming(uint serial, char* msg, uint len, ulong from, ulong recv);
};

int TCommunications_Handler::StoreIncoming(uint serial, char* msg, uint len, ulong from, ulong recv)
{
    HOLDER* h;
    unsigned int i;

    if (len == 0) {
        L->Log("+++StoreIncoming called for zero-length message");
    }

    h = this->OnHold;
    for (i = 0; i <= 0x1F5; i++) {
        if (h[i].Serial == serial && h[i].dcoFromID == from) {
            L->Log("Future Ser#%d previously stored (Slot#%d)", serial, i);
            return 1;
        }
    }

    for (i = 0; i < 0x1F5; i++) {
        if (h[i].Length == 0 && len != 0) {
            this->OnHold[i].Length = len;
            h = &this->OnHold[i];
            h->HoldMsg = (char*)operator_new(h->Length);
            if (h->HoldMsg != 0) {
                memcpy(h->HoldMsg, msg, h->Length);
                h->Length = len;
            }
            this->OnHold[i].Serial = serial;
            this->OnHold[i].dcoFromID = from;
            this->OnHold[i].dcoReceiveID = recv;
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
