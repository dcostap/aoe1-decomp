// VA: 005414A0 RGE_Game_World::data_load_effects
// FLAGS: /GX required for original SEH/new/ctor cleanup basin
//
// BLOCKER: natural /GX new-expression emits the original EH prologue, allocation
// size, null test, EH state store, filename push, constructor call, and null xor.
// Remaining mismatch is tail scheduling: VC5 either sinks the member store into
// the non-null path and places the null cleanup tail after the ret, or (with a
// volatile local read) keeps the original common branch/join but spills/reloads
// EAX through [esp+18h] before storing to [esi+4Ch]. Original has the ideal common
// tail: restore FS source into ECX, direct `mov [esi+4Ch], eax`, FS restore, epilogue.
//
// Attempt log:
// 1. Prior placement-new/volatile source failed extraction (only 64B .text) and/or sunk store.
// 2. Natural direct member new: first 50B exact, then store sinks into non-null path; null path after ret (23.86% pos, 17.05% edit).
// 3. Explicit operator new + placement constructor: no EH new-expression, .text only 64B.
// 4. Natural new into local before member assignment: same sunk-store basin.
// 5. Explicit if/else assignment: forced source join but added unwanted `test eax,eax; jne` after ctor/null join.
// 6. Volatile read of local for final assignment: first 72B exact, common tail retained, but spills EAX to [esp+18h], reloads EDX, and stores EDX.
// 7. Redundant ternary assignment: optimized back to sunk-store basin.
// 8. Explicit goto label before assignment: optimized back to sunk-store basin.
// 9. Register local plus volatile read: same stack spill/reload as volatile read.
// 10. Store through pointer-to-member slot local: optimized back to sunk-store basin.
// 11. Volatile local assigned from natural new: optimized back to sunk-store basin.
// 12. variant_lab over member volatility, direct/local/ternary/ifelse/volatile/goto shapes, and vc5-risky flags: no exact; best default families are sunk-store or volatile-spill; /Oa slightly changes spill ordering but still not exact.
// 13. LemonLily pass: tried direct member assignment, plain local, assignment-expression, empty if(e), goto/common-label, if/else self-assign, slot pointer/ref, volatile member declaration, raw +0x4C store, comma expression, volatile filename/this, int/long volatile reads, and address-escape forms. They collapse to either sunk-store/null-tail or common-tail-with-stack-spill; none produced original direct `mov [esi+4Ch],eax` common tail.
// 14. Additional temporary flag probes on the int-volatile-read family (/Oa, /Ow, /Og, /Oi, /Ox /Oa, no /Oy, /Ob0, /Gs) did not match; /Oa-/Ow reduce edit diff slightly but still keep extra stack traffic. Original /GX flag file kept unchanged.

class RGE_Effects {
public:
    char gap_00[0x0C];
    RGE_Effects(char* filename);
};

class RGE_Game_World {
public:
    char gap_00[0x4C];
    RGE_Effects* effects;

    void data_load_effects(char* filename);
};

void RGE_Game_World::data_load_effects(char* filename) {
    RGE_Effects* e = new RGE_Effects(filename);
    this->effects = *(RGE_Effects* volatile*)&e;
}
