// SetAccessOffsets — real pass
// VA: 00444990
// TDrawArea method — allocates/frees offset arrays, computes access offsets

void __fastcall SetAccessOffsets(void* _this, int _)
{
    int count = *(int*)((char*)_this + 0x1C);
    int size = count * 4;
    int currSize = *(int*)((char*)_this + 0xDC);
    
    // Reallocate offset array if size changed
    if (size != currSize) {
        void* oldBuf = *(void**)((char*)_this + 0xBC);
        if (oldBuf) ((void(__fastcall*)(void*,int))0x54B7D0)(oldBuf, 0);
        
        void* newBuf = ((void*(__fastcall*)(int,int))0x54C5A0)(size, 0);
        *(void**)((char*)_this + 0xBC) = newBuf;
        *(int*)((char*)_this + 0xDC) = size;
        *(void**)((char*)_this + 0xC0) = newBuf;
    }
    
    // Compute access offsets
    int startPixel;
    int rowStride;
    int hasColorKey = *(int*)((char*)_this + 0x24);
    if (hasColorKey == 1) {
        if (*(void**)((char*)_this + 0xF8)) {
            startPixel = *(int*)((char*)_this + 0x20) * 5 + *(int*)((char*)_this + 0x08);
            rowStride = *(int*)((char*)_this + 0x18);
        } else {
            startPixel = *(int*)((char*)_this + 0x08);
            rowStride = *(int*)((char*)_this + 0x20);
        }
    } else {
        if (*(void**)((char*)_this + 0xF8)) {
            startPixel = *(int*)((char*)_this + 0x20) * 5 + *(int*)((char*)_this + 0x08);
            rowStride = *(int*)((char*)_this + 0x18);
        } else {
            startPixel = *(int*)((char*)_this + 0x08);
            rowStride = -*(int*)((char*)_this + 0x20);
        }
    }
    
    // Fill offsets array
    int* buf = *(int**)((char*)_this + 0xBC);
    int idx = 0;
    for (int i = 0; i < count; i++) {
        buf[idx++] = startPixel;
        startPixel += rowStride;
    }
}
