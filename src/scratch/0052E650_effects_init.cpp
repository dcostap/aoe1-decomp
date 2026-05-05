// 0052E650 TRIBE_World::effects_init
// EH-framed allocate and construct TRIBE_Effects, store at +0x4C.
// HollowSnowdrop pass: direct new expression with /GX gives exact 88/88 EH frame and call/prologue family; remaining drift is branch/store layout. Original null path xors EAX then falls through a common store, while VC5 direct-new stores immediately after ctor and sends null branch to shared epilogue. Explicit placement-new/decompiler-shaped null fallback collapses to a 64-byte non-EH body even with /GX. Current best: 23.86% positional / 17.05% edit, with config/flags/0052E650_effects_init.rsp.

void* operator new(unsigned int size);

class TRIBE_Effects {
public:
    char gap_00[0x0C];
    TRIBE_Effects(int param_1);
};

class TRIBE_World {
public:
    char pad_00[0x4C];
    TRIBE_Effects* effects;

    void effects_init(int param_1);
};

void TRIBE_World::effects_init(int param_1) {
    TRIBE_Effects* e;
    e = new TRIBE_Effects(param_1);
    this->effects = e;
}
