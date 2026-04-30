// 00485CB0 add_quick_obj
// rmm_obj.cpp:46-62, 266 bytes, __thiscall

class RMVault {
public:
    unsigned char gap_00[0x34];
    void add_quick_obj(void* p1, int p2, int p3);
};

void RMVault::add_quick_obj(void* p1, int p2, int p3) {
    int c;
    int z;
    (void)p3;
    
    c = *(int*)((int)this + 0x12C4);
    *(void**)((int)this + c * 48 + 0x34) = p1;
    z = (int)p1 - (int)p1;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x38) = -1;
    
    c = *(int*)((int)this + 0x12C4);
    *(unsigned char*)((int)this + c * 48 + 0x3C) = (unsigned char)z;
    
    c = *(int*)((int)this + 0x12C4);
    *(unsigned char*)((int)this + c * 48 + 0x3D) = (unsigned char)z;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x40) = 1;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x44) = 1;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x48) = p2;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x4C) = 2;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x50) = z;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x54) = -1;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x58) = z;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + c * 48 + 0x5C) = 1;
    
    c = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + (c + 2) * 48) = p2;
    
    *(int*)((int)this + 0x12C4) = *(int*)((int)this + 0x12C4) + 1;
}
