// 0052E5F0 TRIBE_World::scenario_init
// EH-framed allocate and construct T_Scenario, store at +0x5C.
// FLAGS: config/flags/0052E5F0_scenario_init.rsp uses /GX for original SEH/new-expression basin.
//
// BLOCKER: same /GX new-expression common-tail scheduling family as 00541C90,
// 00541D00, and 0052E530. Natural direct new emits exact EH prologue, allocation
// size, constructor call, and early body, but VC5 sinks the member store into the
// non-null path and sends the null path to a cleanup tail after the compared range.
// Explicit common-store shapes reach the original ctor-success jump/null-xor/common
// store family, but insert a redundant post-join `test eax,eax; jne +0`, shifting
// and truncating the EH epilogue inside the 91-byte window.
//
// Attempt log:
// 1. Prior /GX direct new with sizeof(T_Scenario)=0x514C gives exact EH prologue/allocation/ctor family, but store sinks into non-null path; null path goes after ret.
// 2. Volatile read of local: first 75B exact/common join retained, but spills EAX through [esp+18h] and stores EDX.
// 3. Explicit if/else assignment: forced source join but adds unwanted post-join `test eax,eax; jne`.
// 4. variant_lab over direct/local/ternary/ifelse/volatile/slot shapes, member volatility, and vc5-risky flags: no exact. Best edit family was /GX /Oa + volatile read (edit 14) but still stack-spills EAX.
// 5. Slot local/pointer-to-member shape and ternary collapse back to the sunk-store basin.
// 6. 2026-05-10 pass on this VA only: retried 20+ variants: direct/local new, if-null/if-not/goto common-store, assignment-in-condition, zero-init, volatile local, parameter reuse, bool temp, switch, empty-if, ternary, do/for single-pass, and volatile-read. Also probed flags /O1, /Og, /Ob0, /Ox, /Gf, /Gy, /Oa, /Ot with /GX. No exact.
// 7. Best current source below: edit diff 12.0879%, positional 17.5824%; mismatch is redundant join-test plus epilogue truncation (`83c4` incomplete at tail). Not an accepted_drift suggestion under Boss's window/truncation ruling.
// No inline asm/hacks.

void* __cdecl operator new(unsigned int size);

class RGE_Game_World;

class T_Scenario {
public:
    char gap_0[0x514C];
    T_Scenario(RGE_Game_World* param_1);
};

class TRIBE_World {
public:
    char gap_0[0x5C];
    T_Scenario* scenario;

    void scenario_init(RGE_Game_World* param_1);
};

void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    T_Scenario* s = new T_Scenario(param_1);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}
