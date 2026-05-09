// 00541C90 RGE_Game_World::effects_init
// EH-framed allocate and construct RGE_Effects, store at +0x4C.
// FLAGS: config/flags/00541C90_effects_init.rsp uses /GX for original EH frame.
//
// Attempt log:
// - HollowSnowdrop pass: /GX + 0x0C-sized RGE_Effects direct-new gets exact 88/88 prologue/allocation/ctor family.
//   Remaining drift mirrors 0052E650: original has short null branch to xor eax and common store; rebuilt stores
//   after ctor and branches null to padded epilogue. Placement-new/decompiler null fallback likely collapses out of EH.
// - MidnightLily baseline recheck: direct `this->effects = new RGE_Effects(param_1)` preserves EH/new/ctor but stores on
//   success path before SEH cleanup; null path jumps to cleanup tail (edit diff 15).
// - Try 1: explicit operator new + inline placement new + common store removed the EH new-expression lowering, only 48 bytes.
// - Try 2: direct new into local plus `if (effects == 0) effects = 0;` kept original short null branch/xor/common store,
//   but VC5 inserted a redundant `test eax,eax; jne +0` at the join before loading EH saved ecx. Best current basin
//   (edit diff 11, first mismatch at join offset 67).
// - Try 3: explicit `if (effects != 0) goto store; effects = 0;` same redundant join test as try 2.
// - Try 4: manual operator new + explicit constructor call removed EH new-expression lowering, only 64 bytes.
// - Try 5: volatile local after direct new preserved join but forced stack spill/reload before store (worse, edit diff 17).
// - Try 6/7/9: direct assignment expression, ternary common store, and separate pointer declaration all collapsed to baseline
//   success-path store/null-to-tail family (edit diff 15).
// - Try 8: /Ob0 flag with direct-new variants had no effect; restored /GX-only flag.
// Left in scratch: behavior and EH/call surface are correct; blocker is VC5 source shaping around null-path/common-store join.
// No inline asm/hacks.

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
    if (effects == 0) {
        effects = 0;
    }
    this->effects = effects;
}
