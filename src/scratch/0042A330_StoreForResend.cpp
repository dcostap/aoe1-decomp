// VA: 0042A330 TCommunications_Handler::StoreForResend
// Attempt log:
// try 1: natural reconstruction from packet/Ghidra; exact size but broad mismatch from struct offsets/log surface/copy loops.
// try 2: switched Log to free DebugLog(TDebuggingLog*,...) to match cdecl push-this surface; removed C++ member-call artifacts.
// try 3: extern memcpy made text too small (464 vs 523), so not viable.
// try 4: <string.h> memcpy still emitted helper-call sized body, too small.
// try 5: restored manual copy loops; exact size returned.
// try 6: corrected resend entry layout: assert/id at +0, used at +4, data at +8, size at +0xC, recipient words at +0x10.
// try 7: changed occupied-entry logging to use +4/+8/+0C/+10 layout; improved edit diff slightly but still broad.
// try 8: /GX tried because of allocation paths; no EH in original and text stayed too small/wrong, removed flag.
// try 9: natural memcpy-like loops compile as scalar loop family, not original rep movsd/rep movsb sequence.
// try 10: slot/off loop modeled as slot*0x38 and off+=0x38; compiler keeps different slot register/liveness than original (edi vs ebp/esi).
// fresh session: flattened active/delivery guards to explicit early returns; emitted code was unchanged, so restored the nested source.
// fresh session: direct typed resendTable[slot] ownership grew the body to 650B/frame 0x10; restored the smaller entry-alias basin.
// session: corrected the entry's +0 timestamp and canonical TDebuggingLog ABI, and
// rebuilt occupied diagnostics with the oracle's 13-vararg push order/8 recipient
// dwords. Parameter-mutating copy loops retain the exact 0x8 frame and near-size
// output; payload-only memcpy was a diagnostic -32B basin and was rolled back.
// session: expressed the recipient-map copy as typed memcpy into ResendEntry::vals;
// this natural field-owned form restores the oracle REP block and improves diff
// 493->359, but leaves a -26B payload-loop size gap and structural CFG drift.
// follow-up: retested typed memcpy lowering for the payload after the recipient-map
// copy reached the REP family; rebuilt size fell 497->467 and the frame disappeared,
// so restored the clean typed-map source.
// follow-up: hoisted scan-state declarations before the delivery gates while keeping
// initialization after the gates; emitted code was unchanged, so restored the clean source.
// follow-up: typed 501-entry array induction, a typed free-slot entry reference, and
// a register-qualified self alias were each codegen duplicates; restored the clean source.
// revisit: restored the binary-local diagnostic strings for occupied entries, stored
// payloads, and the full-buffer tail; canonical RESENDER field names are codegen-neutral.
// policy normalization: the final unresolved source uses a typed RESENDER pointer
// walk instead of a raw byte cursor. This is natural ownership, but it widens the
// codegen gap and relocates the full-buffer log call.
// bounded pass: 11 probes found no better natural basin. The final source is 497B
// versus 523B with 7/7 ordered calls and frame 0x8; REP payload lowering and
// EBX-self/EBP-slot coloring remain unresolved.
// Main review replaced the explicit allocation call and handwritten copy loop
// with ordinary new[] and memcpy ownership.
// Fresh diagnostics used a byte-offset table scan, explicit operator new,
// and handwritten payload-copy loops. Main review rejected these forms as
// compiler-facing plumbing. Keep typed RESENDER iteration, new[], and memcpy.
// left in scratch: behavior and layout modeled, but logging argument order/register allocation and copy-loop lowering remain broad; not accepted-drift-safe.

#include <string.h>
class TDebuggingLog { public: void Log(char* fmt, ...); };
extern TDebuggingLog* L;
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

struct RESENDER {
    unsigned long TimeSent;
    unsigned int Serial;
    char* ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];
};

class TCommunications_Handler {
public:
    char gap_0000[0x10E4];
    int Multiplayer;
    char gap_10E8[0x12D8-0x10E8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x1514-0x12DA];
    unsigned char RGE_Guaranteed_Delivery;
    char gap_1515[0x1520-0x1515];
    RESENDER* Resend;

    int StoreForResend(unsigned int param_1, char* param_2, unsigned int param_3, unsigned int* param_4);
};

int TCommunications_Handler::StoreForResend(unsigned int param_1, char* param_2, unsigned int param_3, unsigned int* param_4)
{
    if (this->Multiplayer != 0) {
        if (this->RGE_Guaranteed_Delivery == 0) {
            L->Log("+++!RGEGTD Store");
        } else {

    unsigned int slot = 0;
    RESENDER* e = this->Resend;
    do {
        if (e->Serial == 0) {
            e->Length = param_3;
            if (param_3 != 0) {
                e->ResendMsg = new char[e->Length];
                if (e->ResendMsg != 0) {
                    memcpy(e->ResendMsg, param_2, e->Length);
                    e->Length = param_3;
                }
            }
            e->Serial = param_1;
            unsigned int bytes = (unsigned int)this->MaxGamePlayers * 4 + 4;
            memcpy(e->DestMap, param_4, bytes);

            L->Log("Stored %db for resend (Slot= %d ) SERIAL=%d  (MaxPlayers=%d)",
                   param_3, slot, param_1, this->MaxGamePlayers);
            unsigned int i = 1;
            if (i <= this->MaxGamePlayers) {
                unsigned int* p = param_4 + 1;
                unsigned int* usedp = &e->DestMap[1];
                do {
                    if (*usedp != 0) {
                        L->Log("    %u %u", i, *p);
                    }
                    i++;
                    usedp++;
                    p++;
                } while (i <= this->MaxGamePlayers);
            }
            e->TimeSent = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0xD12);
            return 1;
        }

        int flag = e->Serial;
        char first = e->ResendMsg[0];
        L->Log("QUEUE Has Ser #%d (Slot=%d) Cmd=%d '%c' Len=%d not ackd yet by %d,%d,%d,%d,%d,%d,%d,%d",
               flag, slot, (int)first, (int)first, e->Length,
               e->DestMap[1], e->DestMap[2], e->DestMap[3], e->DestMap[4], e->DestMap[5],
               e->DestMap[6], e->DestMap[7], e->DestMap[8]);
        e++;
        slot++;
    } while (slot < 502);
            L->Log("RESEND buffer filled up, slots (i=%d).", slot);
        }
    }
    return 0;
}
