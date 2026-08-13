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
// left in scratch: behavior and layout modeled, but logging argument order/register allocation and copy-loop lowering remain broad; not accepted-drift-safe.

#include <string.h>
class TDebuggingLog { public: void Log(char* fmt, ...); };
extern TDebuggingLog* L;
void* __cdecl operator new(unsigned int size);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

struct ResendEntry {
    unsigned long time;
    unsigned int used;
    char* data;
    unsigned int size;
    unsigned int vals[10];
};

class TCommunications_Handler {
public:
    char gap_0000[0x10E4];
    int active;
    char gap_10E8[0x12D8-0x10E8];
    unsigned short resendPlayerCount;
    char gap_12DA[0x1514-0x12DA];
    unsigned char resendEnabled;
    char gap_1515[0x1520-0x1515];
    ResendEntry* resendTable;

    int StoreForResend(unsigned int param_1, char* param_2, unsigned int param_3, unsigned int* param_4);
};

int TCommunications_Handler::StoreForResend(unsigned int param_1, char* param_2, unsigned int param_3, unsigned int* param_4)
{
    if (this->active != 0) {
        if (this->resendEnabled == 0) {
            L->Log("+++!RGEGTD Store");
        } else {

    unsigned int slot = 0;
    unsigned int off = 0;
    while (off < 0x6D98) {
        ResendEntry* e = (ResendEntry*)((char*)this->resendTable + off);
        if (e->used == 0) {
            unsigned int idxoff = slot;
            idxoff <<= 3;
            idxoff -= slot;
            idxoff <<= 3;
            e = (ResendEntry*)((char*)this->resendTable + idxoff);
            e->size = param_3;
            if (param_3 != 0) {
                e->data = (char*)operator new(e->size);
                if (e->data != 0) {
                    unsigned int n = e->size;
                    char* dst = e->data;
                    for (unsigned int q = n >> 2; q != 0; q--) {
                        *(unsigned int*)dst = *(unsigned int*)param_2;
                        param_2 += 4;
                        dst += 4;
                    }
                    for (n &= 3; n != 0; n--) {
                        *dst++ = *param_2++;
                    }
                    e->size = param_3;
                }
            }
            e->used = param_1;
            unsigned int bytes = (unsigned int)this->resendPlayerCount * 4 + 4;
            memcpy(e->vals, param_4, bytes);

            L->Log("+++RGEGTD Store: %u %u %u", param_3, slot, param_1, this->resendPlayerCount);
            unsigned int i = 1;
            if (i <= this->resendPlayerCount) {
                unsigned int* p = param_4 + 1;
                unsigned int* usedp = &e->vals[1];
                do {
                    if (*usedp != 0) {
                        L->Log("    %u %u", i, *p);
                    }
                    i++;
                    usedp++;
                    p++;
                } while (i <= this->resendPlayerCount);
            }
            e->time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0xD12);
            return 1;
        }

        int flag = e->used;
        char first = e->data[0];
        L->Log("RGEGTD Stored: %u %u %d %u %u %u %u %u %u %u %u %u %u",
               e->used, slot, (int)first, (int)first, e->size,
               e->vals[1], e->vals[2], e->vals[3], e->vals[4], e->vals[5],
               e->vals[6], e->vals[7], e->vals[8]);
        off += 0x38;
        slot++;
    }
            L->Log("+++!RGEGTD Store no room %d", slot);
        }
    }
    return 0;
}
