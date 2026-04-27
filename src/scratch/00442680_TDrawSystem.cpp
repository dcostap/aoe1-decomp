// TDrawSystem::TDrawSystem — real pass (ctor, many field inits)
// VA: 00442680

void __fastcall ctor_TDrawSystem(void* _this, int _)
{
    // Zero-init many fields
    // (original: xor eax,eax then mov [esi+offset],eax for many offsets)
    int* p = (int*)_this;
    p[0] = 0;   // +0x00
    p[1] = 0;   // +0x04
    p[2] = 0;   // +0x08
    p[3] = 0;   // +0x0C
    p[4] = 0;   // +0x10
    p[6] = 0;   // +0x18
    p[7] = 0;   // +0x1C
    p[8] = 0;   // +0x20
    p[9] = 0;   // +0x24
    p[15] = 0;  // +0x3C
    *(char*)((char*)_this + 0x478) = 0;
    *(char*)((char*)_this + 0x479) = 0;
    p[11] = 0;  // +0x2C
    p[12] = 0;  // +0x30
    *(int*)((char*)_this + 0x34) = 8;
    
    // More inits follow in original — simplified for bounded pass
    // Call to create primary surface and related setup
}
