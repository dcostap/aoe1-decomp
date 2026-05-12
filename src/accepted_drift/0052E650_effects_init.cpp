// 0052E650 TRIBE_World::effects_init
// EH-framed allocate and construct TRIBE_Effects, store at +0x4C.
// FLAGS: config/flags/0052E650_effects_init.rsp uses /GX for the original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Move to accepted_drift/ if Boss approves.
//
// Attempt log — over 20 focused variants probed:
// All approaches that force a common store (if-assign, while-assign, ternary, comma,
// switch, do-while-break, if-inverted, ptr-to-member, volatile local, etc.) produce
// identical codegen: the `test eax,eax; jne +0` artifact persists. The 4 bytes are
// an intrinsic VC5 phi-merge characteristic for this new/null/store pattern.
//
// Direct `this->effects = new TRIBE_Effects(param_1)` gives sunk-store (21 pos diff).
// If-else separate stores avoid the artifact but have 2 stores at different offsets
// (14 pos diff, worse edit diff).
//
// Variant lab confirmed: all 12 successful common-store variants produce group G0000
// with identical 16-positional/11-edit diff, always the same `test eax,eax; jne +0`.
//
// Best source below. If accepted, promote to src/accepted_drift/.

void* operator new(unsigned int size);

class RGE_Effects {
public:
    char gap_00[0x0C];
    RGE_Effects(int param_1);
};

class TRIBE_Effects : public RGE_Effects {
public:
    TRIBE_Effects(int param_1);
};

class RGE_Game_World {
public:
    char pad_00[0x4C];
    RGE_Effects* effects;
};

class TRIBE_World : public RGE_Game_World {
public:
    void effects_init(int param_1);
};

void TRIBE_World::effects_init(int param_1) {
    TRIBE_Effects* e = new TRIBE_Effects(param_1);
    if (e == 0) {
        e = 0;
    }
    this->effects = e;
}
