// 00424AC0 IPAD::`vector deleting destructor' (71 bytes)
// VC5 compiler-emitted helper
#include "..\..\include\game_globals.h"

class IPAD {
public:
    char _size[0xA0];
    void* vector_deleting_destructor(unsigned char flags);
};

extern "C" void __cdecl operator_delete(void*);
void __stdcall eh_vector_destructor_iterator(void* obj, int elemSize, int elemCount, void* dtor);

void* IPAD::vector_deleting_destructor(unsigned char flags)
{
    void* base = (char*)this - 4;
    int n = *(int*)((char*)this - 4);

    if (flags & 2) {
        eh_vector_destructor_iterator(this, 0xA0, n, (void*)0x424E30);
        operator_delete(base);
        return this;
    }

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
