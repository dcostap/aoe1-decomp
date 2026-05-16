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
// left in scratch: behavior and layout modeled, but logging argument order/register allocation and copy-loop lowering remain broad; not accepted-drift-safe.

#include <string.h>
class TDebuggingLog;
extern TDebuggingLog* L;
extern "C" void __cdecl DebugLog(TDebuggingLog*, char*, ...);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);
extern "C" int __cdecl assert_func(char* file, int line);

struct ResendEntry {
    int assertVal;
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
    if (this->active == 0) {
        return 0;
    }
    if (this->resendEnabled == 0) {
        DebugLog(L, "+++!RGEGTD Store");
        return 0;
    }

    int slot = 0;
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
                    char* src = param_2;
                    char* dst = e->data;
                    while (n >= 4) { *(int*)dst = *(int*)src; dst += 4; src += 4; n -= 4; }
                    while (n != 0) { *dst++ = *src++; n--; }
                    e->size = param_3;
                }
            }
            e->used = param_1;
            unsigned int bytes = (unsigned int)this->resendPlayerCount * 4 + 4;
            char* dst2 = (char*)&e->vals[0];
            char* src2 = (char*)param_4;
            unsigned int n2 = bytes;
            while (n2 >= 4) { *(int*)dst2 = *(int*)src2; dst2 += 4; src2 += 4; n2 -= 4; }
            while (n2 != 0) { *dst2++ = *src2++; n2--; }

            DebugLog(L, "+++RGEGTD Store: %u %u %u", param_3, slot, param_1, this->resendPlayerCount);
            unsigned int i = 1;
            if (i <= this->resendPlayerCount) {
                unsigned int* p = param_4 + 1;
                unsigned int* usedp = &e->vals[1];
                do {
                    if (*usedp != 0) {
                        DebugLog(L, "    %u %u", i, *p);
                    }
                    i++;
                    usedp++;
                    p++;
                } while (i <= this->resendPlayerCount);
            }
            e->assertVal = assert_func("c:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0xD12);
            return 1;
        }

        int flag = e->used;
        char first = e->data[0];
        DebugLog(L, "RGEGTD Stored: %u %u %d %u %u %u %u %u %u %u %u", e->size, e->used, (int)first, (int)first, slot,
               e->vals[0], e->vals[1], e->vals[2], e->vals[3], e->vals[4], e->vals[5]);
        off += 0x38;
        slot++;
    }
    DebugLog(L, "+++!RGEGTD Store no room %d", slot);
    return 0;
}
