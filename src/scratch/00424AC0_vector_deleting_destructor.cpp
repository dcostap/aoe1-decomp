// 00424AC0 IPAD::`vector deleting destructor' (71 bytes)
// VC5 compiler-emitted helper
//
// Attempt log:
// Probe 1: 50% diff — wrong calling convention on eh_vector_dtor
// Probe 2: 18% diff — fixed __stdcall, edi push inside if-block (last remaining diff)
// Probe 3: 5 bytes → moved allocBase computation outside if-block; EDI now saved at 
//   entry (good) but elemCount access uses [edi] instead of [esi-4] (bad), and prologue
//   ordering moved mov esi,ecx before push edi. Total diff increased to 19 bytes.
// Probe 4: Back to base; remaining diff is pure edi save/restore placement
// (unconditional in orig, conditional in rebuilt) — TU-context register allocation.
// Parked at 5 bytes.

#include "..\..\include\game_globals.h"

class IPAD {
public:
    char _size[0xA0];
    void* vector_deleting_destructor(unsigned int flags);
};

extern "C" void __cdecl operator_delete(void*);                  // 0054B660 (cdecl)
void __stdcall eh_vector_destructor_iterator(                     // 0054D780 (stdcall)
    void* obj, int elemSize, int elemCount, void* dtor);

void* IPAD::vector_deleting_destructor(unsigned int flags)
{
    if (flags & 2) {
        int elemCount = *(int*)((char*)this - 4);
        void* allocBase = (char*)this - 4;
        eh_vector_destructor_iterator(this, 0xA0, elemCount, (void*)0x424E30);
        operator_delete(allocBase);
        return this;
    }

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
