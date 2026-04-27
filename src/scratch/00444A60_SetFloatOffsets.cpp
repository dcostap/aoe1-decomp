// SetFloatOffsets — real pass
// VA: 00444A60
#include <stdlib.h>

void __fastcall SetFloatOffsets(void* _this, int _, int param1, int param2)
{
    int size = *(int*)((char*)_this + 0x1C) * 4;
    if (!size) return;
    if (!*(void**)((char*)_this + 0xF8)) return;
    if (param1 < 0) return;
    if (param2 < 0) return;
    
    if (size != *(int*)((char*)_this + 0xE0)) {
        if (*(void**)((char*)_this + 0xC4))
            free(*(void**)((char*)_this + 0xC4));
        *(void**)((char*)_this + 0xC4) = malloc(size);
        *(int*)((char*)_this + 0xE0) = size;
    }
    
    // Fill offset array
    int count = *(int*)((char*)_this + 0x1C);
    int* offsets = *(int**)((char*)_this + 0xC4);
    int idx = 0;
    int cur = param2;
    for (int i = 0; i < count; i++) {
        void* dv = *(void**)((char*)_this + 0xBC);
        int val = *(int*)((char*)dv + cur * 4);
        offsets[idx++] = val + param1;
        cur++;
        if (cur >= count) cur = 0;
    }
    
    *(int*)((char*)_this + 0xD4) = param1;
    *(int*)((char*)_this + 0xD8) = param2;
    *(int*)((char*)_this + 0xC0) = (int)offsets;
}
