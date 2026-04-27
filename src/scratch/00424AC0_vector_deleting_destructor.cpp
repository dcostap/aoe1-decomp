// 00424AC0 IPAD::`vector deleting destructor' (71 bytes)
// VC5 compiler-emitted helper
//
// Attempt log:
// Probe 1: 50% diff — wrong calling convention on eh_vector_dtor
// Probe 2: 18% diff — fixed __stdcall, edi push inside if-block (last remaining diff)
//   Remaining: edi push/pop reordering (instruction order only), call relocs masked
// Left in scratch: the remaining diff is VC5 register-save reordering, behavior equivalent.

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
