// 0052E590 TRIBE_World::scenario_init(int, RGE_Game_World*)
// EH-framed allocate and construct T_Scenario, store at +0x5C.
// FLAGS: config/flags/0052E590_scenario_init.rsp uses /GX for original EH frame.
//
// Attempt log:
// - HollowSnowdrop pass: /GX + direct new with sizeof(T_Scenario)=0x514C gets exact 96/96 EH prologue/allocation/ctor family including two ctor args.
//   Remaining drift is same common-tail blocker as sibling scenario/effects init helpers: original null branch goes to xor eax and common store;
//   rebuilt stores after ctor and sends null branch to padded/shared epilogue.
// - Try 1: direct new into local plus `if (s == 0) s = 0;` keeps original short null branch/xor/common-store family, but VC5 inserts
//   redundant `test eax,eax; jne +0` at the join before reloading EH saved ecx. Best current basin (edit diff 11).
// - Try 2: volatile local forces stack spill/reload before store; worse.
// - Try 3: explicit `if (s != 0) goto store; s=0;` same redundant join test as try 1.
// - Try 4: manual operator new + explicit constructor call removes EH new-expression lowering, only 64 bytes.
// - Try 5/6: direct assignment and ternary common-store collapse to baseline success-path store/null-to-tail family (edit diff 15).
// - Try 7: /Ob0 flag with try-1 source no effect; restored /GX-only flag.
// Left in scratch: behavior and EH/call surface are correct; blocker is VC5 source shaping around null-path/common-store join.
// No inline asm/hacks.

class RGE_Game_World;
void* operator new(unsigned int size);

class T_Scenario {
public:
    char gap_0[0x514C];
    T_Scenario(int param_1, RGE_Game_World* param_2);
};

class TRIBE_World {
public:
    char gap_0[0x5C];
    T_Scenario* scenario;

    void scenario_init(int param_1, RGE_Game_World* param_2);
};

void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    T_Scenario* s = new T_Scenario(param_1, param_2);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}
