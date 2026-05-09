// 00541BC0 RGE_Game_World::scenario_init
// EH-framed allocate and construct RGE_Scenario, store at +0x5C.
// FLAGS: /GX
//
// BLOCKER: same /GX new-expression common-tail scheduling family as 005414A0.
// Natural direct new emits exact EH prologue, allocation size, constructor call,
// and early body, but VC5 sinks the member store into the non-null path and sends
// the null path to a cleanup tail after the compared function range. Volatile-read
// variants preserve the original short null branch + common join, but spill EAX
// through [esp+18h] and store EDX rather than direct `mov [esi+5Ch], eax`.
//
// Attempt log:
// 1. Prior /GX direct new with sizeof(RGE_Scenario)=0x1990 gives exact EH prologue/allocation/ctor family, but store sinks into non-null path; 23.08% pos / 16.48% edit.
// 2. Volatile read of local: first 75B exact/common join retained, but spills EAX through [esp+18h] and stores EDX.
// 3. Explicit if/else assignment: forced source join but adds unwanted post-join `test eax,eax; jne`.
// 4. variant_lab over direct/local/ternary/ifelse/volatile/slot shapes, member volatility, and vc5-risky flags: no exact. Best edit family was /GX /Oa + volatile read (edit 14) but still stack-spills EAX; normal /GX volatile read is first-mismatch-deepest under default-compatible flags.
// 5. Slot local/pointer-to-member shape and ternary collapse back to the sunk-store basin.

class RGE_Game_World;

class RGE_Scenario {
public:
    char gap_0[0x1990];
    RGE_Scenario(RGE_Game_World* param_1);
};

class RGE_Game_World {
public:
    char gap_0[0x5C];
    RGE_Scenario* scenario;

    void scenario_init(RGE_Game_World* param_1);
};

void RGE_Game_World::scenario_init(RGE_Game_World* param_1) {
    RGE_Scenario* s = new RGE_Scenario(param_1);
    this->scenario = *(RGE_Scenario* volatile*)&s;
}
