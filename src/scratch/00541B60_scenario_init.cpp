// VA: 00541B60 RGE_Game_World::scenario_init(int, RGE_Game_World*)
// PDB source: World.cpp lines 820-822 (96 bytes, 29 asm lines)
// FLAGS: config/flags/00541B60_scenario_init.rsp uses /GX for original EH frame.
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// SEH-framed, allocates RGE_Scenario (0x1990 bytes), constructs if non-null,
// stores at this->scenario (+0x5C).
//
// Attempt log:
// - Baseline (direct new + store) matches exact EH prologue/allocation/ctor family but stores on success path
//   and branches null to padded epilogue. 96/96, edit diff 15.
// - Try 1: explicit null normalization (`if (p == 0) p = 0;`) forces original short null branch/xor/common-store
//   family, but VC5 inserts redundant `test eax,eax; jne +0` at join before EH saved-ecx reload. Best basin,
//   96/96, positional 16.6667%, edit diff 11.
// - Try 2: non-virtual RGE_Scenario with same sizeof: no change from try 1.
// - Try 3: volatile local: spills/reloads through stack before store, worse.
// - Try 4: manual operator new + explicit constructor call loses EH new-expression lowering, only 64-byte text.
// - Try 5/6: direct assignment and ternary common-store collapse to baseline success-path store/null-to-tail family.
// - Try 7: /Ob0 with explicit null normalization: no effect, restored /GX-only flag.
// - Try 8: /O1 /GX probe wrong size/family (75-byte text), restored /GX-only flag.
// - Try 9: separate declaration then assignment with explicit null normalization: same redundant join test as try 1.
// Left in scratch: behavior, EH frame, allocation size, ctor args/call, and stack cleanup are correct; blocker is
// VC5 source shaping around the null-path/common-store join, same as sibling init helpers. No inline asm/hacks.

class RGE_Game_World;

class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_04[0x1990 - 0x04];
    RGE_Scenario(int, RGE_Game_World*);
};

class RGE_Game_World {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario;  // +0x5C

    void scenario_init(int param1, RGE_Game_World* param2);
};

void RGE_Game_World::scenario_init(int param1, RGE_Game_World* param2) {
    RGE_Scenario* p = new RGE_Scenario(param1, param2);
    if (p == 0) {
        p = 0;
    }
    scenario = p;
}
