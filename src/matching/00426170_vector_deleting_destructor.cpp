// 00426170 HOLDER::`vector deleting destructor' (104 bytes)
// VC5 compiler-emitted helper
//
// Attempt log:
// Probe 1: explicit body with member cleanup + zeroing

#include "..\..\include\game_globals.h"

// HOLDER layout (partial):
// +0x00: HoldMsg (char*)
// +0x04: Serial
// +0x08: Length
// +0x0C: dcoFromID
// +0x10: dcoReceiveID
class HOLDER {
public:
    char* HoldMsg;      // +0x00
    int Serial;         // +0x04
    int Length;         // +0x08
    int dcoFromID;      // +0x0C
    int dcoReceiveID;   // +0x10
    
    void* vector_deleting_destructor(unsigned int flags);
};

extern "C" void __cdecl operator_delete(void*);                  // 0054B660
void __stdcall eh_vector_destructor_iterator(                       // 0054D780 (stdcall)
    void* obj, int elemSize, int elemCount, void* dtor);

void* HOLDER::vector_deleting_destructor(unsigned int flags)
{
    if (flags & 2) {
        int elemCount = *(int*)((char*)this - 4);
        void* allocBase = (char*)this - 4;
        eh_vector_destructor_iterator(this, 0x18, elemCount, (void*)0x426600);
        operator_delete(allocBase);
        return this;
    }

    // Scalar cleanup
    if (this->HoldMsg != 0) {
        operator_delete(this->HoldMsg);
    }
    this->HoldMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    this->dcoFromID = 0;
    this->dcoReceiveID = 0;

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
