// 0052E5F0 TRIBE_World::scenario_init
// EH-framed allocate and construct T_Scenario, store at +0x5C.
// FLAGS: config/flags/0052E5F0_scenario_init.rsp uses /GX for original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Same VC5 artifact as just-approved 0052E650/0052E530.
//
// Attempt log — 20+ focused variants confirming same converging basin as effects_init
// and command_init. All common-store approaches produce the identical redundant join-test.
// Direct `this->scenario = new T_Scenario(param_1)` gives sunk-store (21 pos diff).
// Variant lab previously confirmed same convergence (G0000, same `test/jne` artifact).
//
// Best source below. If accepted, promote to src/accepted_drift/.

void* __cdecl operator new(unsigned int size);

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Game_World;

class T_Scenario {
public:
    char gap_0[0x514C];
    T_Scenario(RGE_Game_World* param_1);
};

class RGE_Game_World {
public:
    char pad_00[0x5C];
    T_Scenario* scenario;
};

class TRIBE_World : public RGE_Game_World {
public:
    void scenario_init(RGE_Game_World* param_1);
};
#endif

void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    T_Scenario* s = new T_Scenario(param_1);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}
