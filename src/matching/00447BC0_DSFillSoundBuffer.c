/* _DSFillSoundBuffer (__cdecl) */
/* VA: 00447BC0 */
/* Dsutil.c:312-332 */
/* 155 bytes */
/* FLAGS: /Oi- (disables intrinsic functions; otherwise memcpy inlined as rep movs) */
/*
 * Matched on attempt 8. Key: /Oi- flag prevents memcpy inlining.
 * Original compiled from C (Dsutil.c), not C++.
 */

#include <string.h>

struct DSFillSoundBuffer {
    int* lpVtbl;
};

int __cdecl _DSFillSoundBuffer(struct DSFillSoundBuffer* dsb, void* data, int size)
{
    int hr;
    void* ptr1;
    int size1;
    void* ptr2;
    int size2;

    if (!dsb || !data || !size)
        return 0;

    hr = ((int (__stdcall *)(struct DSFillSoundBuffer*,int,int,void**,int*,void**,int*,int))
          dsb->lpVtbl[11])(dsb, 0, size, &ptr1, &size1, &ptr2, &size2, 0);
    if (hr < 0)
        return 0;

    memcpy(ptr1, data, size1);
    if (size2)
        memcpy((char*)ptr2, (char*)data + size1, size2);

    ((int (__stdcall *)(struct DSFillSoundBuffer*,void*,int,void*,int))
     dsb->lpVtbl[19])(dsb, ptr1, size1, ptr2, size2);
    return 1;
}
