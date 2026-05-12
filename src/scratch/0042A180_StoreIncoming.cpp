// VA: 0042A180 TCommunications_Handler::StoreIncoming
// Com_hand.cpp lines 3237-3305
// Attempt log:
// 1: natural indexed source: comparable full-size output, but prologue/registers wrong (len in EDI, this in EBP); pos 77.9376%, edit 79.3765%.
// 2: explicit self/length locals and pointer-walk scans worsened; duplicate case returned inline and edit diff >116%.
// 3: declarations delayed until after zero-length log: no prologue improvement; still this=EBX/len=EDI and duplicate inline.
// tried flags /O2 no-/Oy, /Ox, /Ob0: same; /O1 too short.
// left in scratch: behavior modeled, but VC5 standalone register allocation won't produce original len=EBX, this=EDI, late duplicate handler; broad drift, not accepted_drift-safe.

typedef unsigned int uint;
typedef unsigned long ulong;

class TDebuggingLog;
extern TDebuggingLog* g_debug_log;
extern void Log(TDebuggingLog* log, char* fmt, ...);
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
    int i;
    int off;
    HOLDER* h;

    if (len == 0) {
        Log(g_debug_log, "+++StoreIncoming called for zero-length message");
    }

    h = this->OnHold;
    for (i = 0; i <= 0x1F5; i++) {
        if (h[i].Serial == serial && h[i].dcoFromID == from) {
            Log(g_debug_log, "Future Ser#%d previously stored (Slot#%d)", serial, i);
            return 1;
        }
    }

    for (i = 0; i < 0x1F5; i++) {
        if (h[i].Length == 0 && len != 0) {
            off = i * 24;
            h[i].Length = len;
            h = (HOLDER*)((char*)this->OnHold + off);
            h->HoldMsg = (char*)operator_new(h->Length);
            if (h->HoldMsg != 0) {
                unsigned int n = h->Length;
                char* dst = h->HoldMsg;
                char* src = msg;
                unsigned int dwords = n >> 2;
                while (dwords--) {
                    *(unsigned int*)dst = *(unsigned int*)src;
                    dst += 4;
                    src += 4;
                }
                n &= 3;
                while (n--) {
                    *dst++ = *src++;
                }
                h->Length = len;
            }
            this->OnHold[i].Serial = serial;
            this->OnHold[i].dcoFromID = from;
            this->OnHold[i].dcoReceiveID = recv;
            return 1;
        }
    }

    Log(g_debug_log, "+++ DID NOT STORE:  ");
    if (i > 0x1EB) {
        Log(g_debug_log, "HOLD FULL WARNING.  COUNT=%d", i);
        off = 0;
        i = 0;
        do {
            h = (HOLDER*)((char*)this->OnHold + off);
            if (h->Length != 0) {
                Log(g_debug_log, "S#%d  Ser#%d FromID=%d Len=%d  CMD='%c' B0=%d B1=%d", i, h->Serial, h->dcoFromID, h->Length, (int)h->HoldMsg[0], (int)h->HoldMsg[0], (int)h->HoldMsg[1]);
            }
            off += 24;
            i++;
        } while (off < 0x2EF8);
    }
    return 1;
}
