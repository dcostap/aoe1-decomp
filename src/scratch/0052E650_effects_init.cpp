// 0052E650 TRIBE_World::effects_init
// EH-framed allocate and construct TRIBE_Effects, store at +0x4C.
// Requires config/flags/0052E650_effects_init.rsp with /GX for the original EH frame.
// HollowSnowdrop pass: direct new expression with /GX gives exact 88/88 EH frame and call/prologue family; remaining drift is branch/store layout.
// 2026-05-09 GraniteCub: tried 20 focused variants. Direct assignment/new/local/volatile/member-type/do-while/comma/assignment-in-if forms keep the store in the success path and branch over it (21 positional, 15 edit diff). Adding an explicit `if (e == 0) e = 0;` or equivalent goto/two-stage result forms moves to the closest basin: original ctor/null merge and common store shape, but VC5 inserts an extra `test eax,eax; jne +0` before the common store (16 positional, 11 edit diff). Manual operator-new + placement-new forms collapse to a short non-EH body even under /GX. Brief /O1+/GX probe also collapsed short. Best left as direct new rather than keeping the artificial post-merge test.
// Blocker: need original post-constructor `jmp; xor eax,eax; mov ecx,[esp+8]; mov [esi+4c],eax` common store without either success-path store or a redundant post-merge test. No inline asm/hacks used.

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
