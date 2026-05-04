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
    char* del = (char*)this;

    if (flags & 2) {
        int n = *((int*)del - 1);
        del = del - 4;
        eh_vector_destructor_iterator(this, 0xA0, n, (void*)0x424E30);
        operator_delete(del);
        goto done;
    }

    if (flags & 1) {
        operator_delete(del);
    }

done:
    return this;
}
