// tried unsigned-char and unsigned-int flag surfaces plus top-declared base/count locals.
// Best variant matches almost everything, but VC5 still keeps `push edi` inside the (flags & 2)
// path instead of unconditionally before `mov esi,ecx`, which shifts the first branch by 1 byte
// and removes the final `pop edi` in the non-vector path. Remaining mismatch looks like a small
// register-save scheduling issue in this compiler-emitted helper, not a behavior/model gap.
#include "..\..\include\game_globals.h"

class IPAD {
public:
    char _size[0xA0];
    void* vector_deleting_destructor(unsigned int flags);
};

extern "C" void __cdecl operator_delete(void*);
void __stdcall eh_vector_destructor_iterator(void* obj, int elemSize, int elemCount, void* dtor);

void* IPAD::vector_deleting_destructor(unsigned int flags)
{
    int n;
    char* base;

    if (flags & 2) {
        n = *(int*)((char*)this - 4);
        base = (char*)this - 4;
        eh_vector_destructor_iterator(this, 0xA0, n, (void*)0x424E30);
        operator_delete(base);
        return this;
    }

    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
