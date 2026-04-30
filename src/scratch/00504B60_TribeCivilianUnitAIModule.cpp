// TribeCivilianUnitAIModule::TribeCivilianUnitAIModule (00504B60)
// PDB source: taiuaimd.cpp:686-705
// Size: 250 bytes
// PARKED - SEH frame type mismatch (EBP vs ESP), TU-context dependent
// FLAGS: /GX

// Attempt log:
// - Probe 1 (unitAIModule + operator_new, /GX flags): 144 bytes, no SEH
//   operator_new alone with /GX doesn't trigger SEH prologue
// - Probe 2 (AllocBlock struct + new expression): 224 bytes
//   SEH triggered via new + constructor, but AllocBlock ctor is inline
// - Probe 3 (__try/__except): 250 bytes! Matches target size, but SEH is
//   EBP-based (push ebp; mov ebp, esp) vs original ESP-based (push -1 only)
//   209 byte diff (83.6%) from fundamentally different SEH frame types
//
// Remaining: Pure VC5 EH frame type mismatch. The original uses ESP-based
// SEH (push -1; push handler; fs[0] save/restore; push ecx) which VC5
// generates for /GX with extern constructor calls (like placeDock's
// new ConstructionItem). This function uses operator_new only, which
// doesn't trigger ESP-based SEH in isolation. TU context (taiuaimd.cpp)
// must have /GX with try/catch or extern dtors in OTHER functions.
//
// Key structural insights:
// - __thiscall, 2 stack params: (RGE_Static_Object* obj, int) → ret 8
// - Base: UnitAIModule (0x124 bytes inherited, ctor at 00412F00)
// - Fields: allocation(+124, void*), subtype_field(+128, int)
// - Vtable: 0x575D48, subtype = 0x0B
// - operator_new(0x2C) → fills 11 ints (3,7,8,9,0xA,0xF,0x11,0x12,0x20,0x21,0x1B)
// - Each field store reloads from this->allocation (+124)

extern "C" void* __cdecl operator_new(unsigned int size);

struct RGE_Static_Object;

struct UnitAIModule {
    unsigned char g0[0x124];
    void ctor(RGE_Static_Object* obj, int param);
};

struct TribeCivilianUnitAIModule : public UnitAIModule {
    void* allocation;          // +124
    int subtype_field;         // +128
    
    TribeCivilianUnitAIModule* constructor(RGE_Static_Object* obj, int param);
};

TribeCivilianUnitAIModule* TribeCivilianUnitAIModule::constructor(RGE_Static_Object* obj, int param)
{
    this->ctor(obj, param);
    
    *(int*)this = 0x575D48;
    subtype_field = 0x0B;
    
    void* p = new char[0x2C];
    allocation = p;
    
    if (p != 0) {
        ((int*)p)[0] = 3;
        ((int*)p)[1] = 7;
        ((int*)p)[2] = 8;
        ((int*)p)[3] = 9;
        ((int*)p)[4] = 0x0A;
        ((int*)p)[5] = 0x0F;
        ((int*)p)[6] = 0x11;
        ((int*)p)[7] = 0x12;
        ((int*)p)[8] = 0x20;
        ((int*)p)[9] = 0x21;
        ((int*)p)[10] = 0x1B;
    }
    
    return this;
}
