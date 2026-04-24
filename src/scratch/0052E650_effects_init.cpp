// quick-win attempt log:
// no existing work file for 0052E650; the original is a tiny EH-framed allocate-and-ctor
// helper that stores the new TRIBE_Effects pointer at +0x4C.
// tried: direct new expression, then explicit operator new + placement-new, then a
// decompiler-shaped local temp / null-fallback spelling. The remaining mismatch stayed
// in the prolog / ctor-basin, and the placement-new shape collapsed the body too far.

void* operator new(unsigned int size);
void* operator new(unsigned int size, void* ptr);

class RGE_Effects {
public:
    void* vtable_ptr;
    char pad_04[0x8];

    RGE_Effects(int param_1);
};

class TRIBE_Effects : public RGE_Effects {
public:
    TRIBE_Effects(int param_1);
};

class TRIBE_World {
public:
    char pad_00[0x4C];
    TRIBE_Effects* effects;

    void effects_init(int param_1);
};

void TRIBE_World::effects_init(int param_1) {
    TRIBE_Effects* this_00;
    int iVar1;

    this_00 = (TRIBE_Effects*)operator new(0xC);
    if (this_00 == 0) {
        iVar1 = 0;
    } else {
        iVar1 = (int)new (this_00) TRIBE_Effects(param_1);
    }
    this->effects = (TRIBE_Effects*)iVar1;
}
