// 0052E650 TRIBE_World::effects_init
// EH-framed allocate and construct TRIBE_Effects, store at +0x4C.
// FLAGS: config/flags/0052E650_effects_init.rsp uses /GX for the original EH frame.
//
// HollowSnowdrop pass: direct new expression with /GX gives exact EH frame and call/prologue family; remaining drift is branch/store layout.
// 2026-05-09 GraniteCub: tried 20 focused variants. Direct assignment/new/local/volatile/member-type/do-while/comma/assignment-in-if forms keep the store in the success path and branch over it (21 positional, 15 edit diff). Adding an explicit `if (e == 0) e = 0;` or equivalent goto/two-stage result forms moves to the closest basin: original ctor/null merge and common store shape, but VC5 inserts an extra `test eax,eax; jne +0` before the common store (16 positional, 11 edit diff). Manual operator-new + placement-new forms collapse to a short non-EH body even under /GX. Brief /O1+/GX probe also collapsed short. Best left as direct new rather than keeping the artificial post-merge test.
// 2026-05-10: focused follow-up tries on this VA only:
// - Revalidated direct new: exact prologue/allocation/ctor call, but success path stores at +0x4C before epilogue and null path jumps to a separate tail (edit diff 15).
// - Try 1: explicit `if (e == 0) e = 0;` gives the best common-tail basin: original short null branch, ctor-success `jmp`, null `xor eax,eax`, and common member store; remaining drift is only an inserted no-op `test eax,eax; jne next` before the common store, shifting the epilogue 4 bytes into original padding (edit diff 11).
// - Try 2: `if (e != 0) {} else e = 0`, assignment-in-if, result-local, ternary, volatile result/local, and goto common/null variants either matched try 1's extra join-test basin or regressed to the sunk-store direct-new basin.
// - Try 3: manual `operator new` + explicit ctor / placement-new declarations (with and without initialized locals, reversed if arms) still chose the sunk-store basin; no exact common-tail improvement.
// - Try 4: volatile read of the local after construction kept the common join but spilled `eax` through `[esp+18h]` and stored via `edx`; /Oa reduced edit diff to 14 but is still worse and would be a custom flag.
// - Try 5: flags /Oa, /Ob0, /Ot, /Gf, /Od, /O1, and no-/Oy probes did not find an exact family; restored /GX-only.
// Left in scratch: current source keeps the closest common-tail shape. Behavior-equivalent accepted_drift candidate if Boss approves: one redundant `test eax,eax; jne +0` before `this->effects = e`, with epilogue shifted into padding. No inline asm/hacks used.

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
    if (e == 0) {
        e = 0;
    }
    this->effects = e;
}
