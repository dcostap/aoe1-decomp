// 004260F0 RESENDER::`vector deleting destructor' (114 bytes)
// VC5 compiler-emitted helper
//
// Attempt log:
// Probe 1: explicit body with member cleanup + zeroing + memset

#include "..\..\include\game_globals.h"

// RESENDER layout (partial):
// +0x00: TimeSent
// +0x04: Serial
// +0x08: ResendMsg (char*)
// +0x0C: Length
// +0x10: DestMap[10] (0x28 bytes)
class RESENDER {
public:
    int TimeSent;           // +0x00
    int Serial;             // +0x04
    char* ResendMsg;        // +0x08
    int Length;             // +0x0C
    int DestMap[10];        // +0x10 (10 ints)
    
    void* vector_deleting_destructor(unsigned int flags);
};

extern "C" void __cdecl operator_delete(void*);                  // 0054B660
void __stdcall eh_vector_destructor_iterator(                       // 0054D780 (stdcall)
    void* obj, int elemSize, int elemCount, void* dtor);

void* RESENDER::vector_deleting_destructor(unsigned int flags)
{
    if (flags & 2) {
        int elemCount = *(int*)((char*)this - 4);
        void* allocBase = (char*)this - 4;
        eh_vector_destructor_iterator(this, 0x38, elemCount, (void*)0x4264A0);
        operator_delete(allocBase);
        return this;
    }

    // Scalar cleanup
    this->TimeSent = 0;
    if (this->ResendMsg != 0) {
        operator_delete(this->ResendMsg);
    }
    this->ResendMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    for (int i = 0; i < 10; i++) {
        this->DestMap[i] = 0;
    }

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
