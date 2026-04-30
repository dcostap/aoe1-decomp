// 00485CB0 add_quick_obj
// rmm_obj.cpp:46-62, 266 bytes, __thiscall
// Best attempt: edit_diff=27, pos_diff=115, first_mismatch=10
// PAUSED: only remaining diff is register allocation:
//   original: ebx=p2, edx=0 (xor edx,edx after using edx for p1 store)
//   rebuilt:  esi=p2, ebx=0 (xor ebx,ebx)
// This is a pure VC5 register allocation heuristic — no source-level
// trick (int z=0, p1 reuse, z = p1-p1, etc.) flips ebx↔esi.
// Variant lab: 1620 variants across 7 axes, 16 asm groups, 0 exact matches.
// Best group G0008 (240 variants, 256 bytes, edit_diff=27).

class RMVault {
public:
    unsigned char gap_00[0x34];
    void add_quick_obj(void* p1, int p2, int p3);
};

void RMVault::add_quick_obj(void* p1, int p2, int p3) {
    int i = *(int*)((int)this + 0x12C4);
    (void)p3;
    
    *(void**)((int)this + i * 48 + 0x34) = p1;
    int z = 0;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x38) = -1;
    
    i = *(int*)((int)this + 0x12C4);
    *(unsigned char*)((int)this + i * 48 + 0x3C) = (unsigned char)z;
    
    i = *(int*)((int)this + 0x12C4);
    *(unsigned char*)((int)this + i * 48 + 0x3D) = (unsigned char)z;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x40) = 1;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x44) = 1;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x48) = p2;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x4C) = 2;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x50) = z;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x54) = -1;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x58) = z;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + i * 48 + 0x5C) = 1;
    
    i = *(int*)((int)this + 0x12C4);
    *(int*)((int)this + (i + 2) * 48) = p2;
    
    *(int*)((int)this + 0x12C4) = i + 1;
}
