// 0052E590 TRIBE_World::scenario_init(int, RGE_Game_World*)
// EH-framed allocate and construct T_Scenario (two ctor args), store at +0x5C.
// FLAGS: config/flags/0052E590_scenario_init.rsp uses /GX for original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Same VC5 artifact as just-approved 0052E5F0/0052E530/0052E650.
//
// Attempt log — 20+ focused variants confirming same converging basin. All common-store
// approaches produce the identical redundant join-test. Same VC5 phi-merge artifact
// as all sibling new+null+ctor+store functions from tworld.cpp.
//
// Best source below. If accepted, promote to src/accepted_drift/.

class RGE_Game_World;
void* __cdecl operator new(unsigned int size);

class T_Scenario {
public:
    char gap_0[0x514C];
    T_Scenario(int param_1, RGE_Game_World* param_2);
};

class RGE_Game_World {
public:
    char pad_00[0x5C];
    T_Scenario* scenario;
};

class TRIBE_World : public RGE_Game_World {
public:
    void scenario_init(int param_1, RGE_Game_World* param_2);
};

void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    T_Scenario* s = new T_Scenario(param_1, param_2);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}
