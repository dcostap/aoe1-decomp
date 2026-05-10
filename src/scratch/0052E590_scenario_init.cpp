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
// - SpruceGlow tries 8/9/14/15: direct store, separate temp, ternary store, and two-local result all fell back to first mismatch 53
//   (success-path store / null-to-tail family), not the original common-store join.
// - SpruceGlow tries 10-13/16-18/25: if/else store, goto join, negated/nested null tests, assignment-in-condition, self-assign arm,
//   result local, and member-qualified store all stayed in the best common-store basin but kept the redundant `test eax,eax; jne +0`
//   at the join (edit diff 11, first mismatch 75).
// - SpruceGlow tries 19/20: reusing param_1 or param_2 as the zero source for the null arm did not change the redundant join test.
// - SpruceGlow tries 21-23: label/nullcase and while/do loop spellings did not change the redundant join test.
// - SpruceGlow try 24: helper-returned zero worsened codegen (extra call/shape, edit diff 20).
// - 2026-05-10 StarryZephyr pass: rechecked baseline (16.6667% positional, 11.4583% edit), retried direct member new
//   (success-path store/null-to-tail, first mismatch 53, edit 15), `if (!s)` null arm, and positive empty-if/else-null;
//   both null-arm spellings stayed in the redundant join-test basin. Restored current best source.
// 2026-05-10 SpruceGlow Boss-assigned pass: revalidated current best and tried 16 variants:
// direct/local assignment, explicit if-null/if-not null normalization, goto common/null,
// param1 local, param2 local, member reference/pointer alias, store-in-both-arms,
// volatile pointer, bool temp, zero-init, and assignment-in-if. No exact. Direct/local
// forms sink the store into the success path (21 positional/15 edit, first mismatch 53).
// Common-tail forms all keep the redundant `test eax,eax; jne +0` (16 positional/11 edit,
// first mismatch 75) and truncate/shift the EH epilogue inside the function window. Store-in-arm
// forms reduce positional bytes to 14 but have worse edit diff and real branch/store layout drift.
// Left in scratch: behavior and EH/call surface are correct; blocker is VC5 source shaping around null-path/common-store join.
// Not proposing accepted_drift: best object inserts a no-op test/jne and shifts/truncates the compared tail, so exact ownership is not safe.
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
