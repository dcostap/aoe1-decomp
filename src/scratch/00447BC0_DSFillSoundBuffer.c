/* VA: 00447BC0 _DSFillSoundBuffer */
/* Dsutil.c lines 312-332, 155 bytes */

#include <string.h>

typedef struct {
    int* lpVtbl;
} IDirectSoundBuffer;

int __cdecl _DSFillSoundBuffer(IDirectSoundBuffer* dsb, void* data, int size) {
    int hr;
    void* ptr1;
    int size1;
    void* ptr2;
    int size2;

    if (!dsb || !data || !size) return 0;

    hr = ((int (__stdcall*)(IDirectSoundBuffer*,int,int,void**,int*,void**,int*,int))(dsb->lpVtbl[11]))(dsb, 0, size, &ptr1, &size1, &ptr2, &size2, 0);
    if (hr < 0) return 0;

    memcpy(ptr1, data, size1);
    if (size2) {
        memcpy(ptr2, (char*)data + size1, size2);
    }

    ((int (__stdcall*)(IDirectSoundBuffer*,void*,int,void*,int))(dsb->lpVtbl[19]))(dsb, ptr1, size1, ptr2, size2);
    return 1;
}
