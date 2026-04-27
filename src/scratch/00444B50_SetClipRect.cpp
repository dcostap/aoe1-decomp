// SetClipRect — real pass (plain, 209 B)
// VA: 00444B50
// TDrawArea method — stores RECT and clamps to surface bounds

void __fastcall SetClipRect_short(void* _this, int _, int* rect)
{
    if (!rect) return;
    
    // Copy rect to this+0x28..0x34
    *(int*)((char*)_this + 0x28) = rect[0];
    *(int*)((char*)_this + 0x2C) = rect[1];
    *(int*)((char*)_this + 0x30) = rect[2];
    *(int*)((char*)_this + 0x34) = rect[3];
    
    // Clamp left (0x28)
    int left = *(int*)((char*)_this + 0x28);
    if (left < 0)
        *(int*)((char*)_this + 0x28) = 0;
    else if (left > *(int*)((char*)_this + 0x18) - 1)
        *(int*)((char*)_this + 0x28) = *(int*)((char*)_this + 0x18) - 1;
    
    // Clamp right (0x30)
    int right = *(int*)((char*)_this + 0x30);
    if (right < 0)
        *(int*)((char*)_this + 0x30) = 0;
    else if (right > *(int*)((char*)_this + 0x18) - 1)
        *(int*)((char*)_this + 0x30) = *(int*)((char*)_this + 0x18) - 1;
    
    // Clamp top (0x2C)
    int top = *(int*)((char*)_this + 0x2C);
    if (top < 0)
        *(int*)((char*)_this + 0x2C) = 0;
    else if (top > *(int*)((char*)_this + 0x1C) - 1)
        *(int*)((char*)_this + 0x2C) = *(int*)((char*)_this + 0x1C) - 1;
    
    // Clamp bottom (0x34)
    int bottom = *(int*)((char*)_this + 0x34);
    if (bottom < 0)
        *(int*)((char*)_this + 0x34) = 0;
    else if (bottom > *(int*)((char*)_this + 0x1C) - 1)
        *(int*)((char*)_this + 0x34) = *(int*)((char*)_this + 0x1C) - 1;
}
