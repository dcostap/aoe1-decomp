// 0052E5F0 TRIBE_World::scenario_init
// EH-framed allocate and construct T_Scenario, store at +0x5C.
// FLAGS: /GX
//
// BLOCKER: same /GX new-expression common-tail scheduling family as 005414A0
// and 00541BC0. Natural direct new emits exact EH prologue, allocation size,
// constructor call, and early body, but VC5 sinks the member store into the
// non-null path and sends the null path to a cleanup tail after the compared
// function range. Volatile-read variants preserve the original short null branch
// + common join, but spill EAX through [esp+18h] and store EDX rather than direct
// `mov [esi+5Ch], eax`.
//
// Attempt log:
// 1. Prior /GX direct new with sizeof(T_Scenario)=0x514C gives exact EH prologue/allocation/ctor family, but store sinks into non-null path; null path goes after ret.
// 2. Volatile read of local: first 75B exact/common join retained, but spills EAX through [esp+18h] and stores EDX.
// 3. Explicit if/else assignment: forced source join but adds unwanted post-join `test eax,eax; jne`.
// 4. variant_lab over direct/local/ternary/ifelse/volatile/slot shapes, member volatility, and vc5-risky flags: no exact. Best edit family was /GX /Oa + volatile read (edit 14) but still stack-spills EAX; normal /GX volatile read is first-mismatch-deepest under default-compatible flags.
// 5. Slot local/pointer-to-member shape and ternary collapse back to the sunk-store basin.

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
    this->scenario = *(T_Scenario* volatile*)&s;
}
