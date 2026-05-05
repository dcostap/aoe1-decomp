// 00541C90 RGE_Game_World::effects_init
// EH-framed allocate and construct RGE_Effects, store at +0x4C.
// HollowSnowdrop pass: /GX + 0x0C-sized RGE_Effects direct-new gets exact 88/88 prologue/allocation/ctor family. Remaining drift mirrors 0052E650: original has short null branch to xor eax and common store; rebuilt stores after ctor and branches null to padded epilogue. Placement-new/decompiler null fallback likely collapses out of EH in this context.

void* operator new(unsigned int size);

class RGE_Effects {
public:
    char gap_00[0x0C];
    RGE_Effects(int param_1);
};

class RGE_Game_World {
public:
    char pad_00[0x4C];
    RGE_Effects* effects;

    void effects_init(int param_1);
};

void RGE_Game_World::effects_init(int param_1) {
    RGE_Effects* effects = new RGE_Effects(param_1);
    this->effects = effects;
}
