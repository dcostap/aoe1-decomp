// VA: 00429FD0 TCommunications_Handler::ClearRXandTX
// Source: Com_hand.cpp lines 3161-3170 (136B, 53 asm lines)
// FLAGS: default
//
// Attempt log (2026-05-19):
// try 1: Baseline from earlier session: 32B edit diff (23.53%)
// try 2: Separate rx_base variable to force base-first loading
// try 3: Move offset outside, simple do-while
// try 4: Separate zero/offset declarations -> ebx=zero, ebp=offset correct!
//        But base loading still edx-first (mov edx,[rx]; mov esi,offset; add esi,edx)
//        TX pre-zero missing (post-zero instead)
// try 5: char* cast prefix addition -> same as try 4
// try 6: Array indexing &base[offset] for RX -> TX pre-zero working!
//        But regs swapped again: ebp=zero, ebx=offset
//        RX base still edx-first
// try 7: zero variable declaration + store usage -> compile error (int to ptr)
// try 8: void* zero = 0 -> regs still ebp=zero, ebx=offset
//
// Remaining diff (32B edit, all scheduling/register):
// 1. Register swap: original ebx=zero, ebp=offset; built ebp=zero, ebx=offset
//    (changes every ModRM register field byte)
// 2. Base loading: original mov esi,[base]; add esi,offset (esi direct)
//                 rebuilt mov edx,[base]; mov esi,offset; add esi,edx (edx temp)
// 3. lea edi scheduling: original has lea edi before mov ecx/xor eax
//                        rebuilt has lea edi after mov ecx/xor eax
// 4. TX pre-zero vs post-zero: both correct, just register assignment difference
//
// ACCEPTED_DRIFT 2026-05-19: approved behavior-equivalent register/scheduling drift.
// Remaining differences are register allocation for zero/offset, equivalent base-address
// construction, and harmless lea/rep-stos setup scheduling. Same loops, predicates,
// frees, zero stores, memset range, stack cleanup, and memory effects; exact size 136B.

#include <stdlib.h>
#include <string.h>

extern "C" void __cdecl operator_delete(void* p);

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_1520[0x1520];
    char* tx_array;
    char* rx_array;

    void ClearRXandTX();
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ClearRXandTX()
{
    unsigned int offset = 0;

    do {
        char* entry = (char*)this->OnHold + offset;

        if (*(void**)entry) {
            operator_delete(*(void**)entry);
        }
        offset += 0x18;
        *(void**)entry = 0;
        *(void**)(entry + 4) = 0;
        *(void**)(entry + 8) = 0;
        *(void**)(entry + 0xC) = 0;
        *(void**)(entry + 0x10) = 0;
    } while (offset < 0x2EF8);

    offset = 0;

    do {
        char* tx_base = (char*)this->Resend;
        *(void**)(tx_base + offset) = 0;
        char* entry = tx_base + offset;

        if (*(void**)(entry + 8)) {
            operator_delete(*(void**)(entry + 8));
        }
        offset += 0x38;
        *(void**)(entry + 8) = 0;
        *(void**)(entry + 4) = 0;
        *(void**)(entry + 0xC) = 0;
        memset(&entry[0x10], 0, 0x28);
    } while (offset < 0x6D98);
}
