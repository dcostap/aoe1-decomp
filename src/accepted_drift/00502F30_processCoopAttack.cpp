#ifndef TAITACMD_SHARED_CONTEXT
// VA: 00502F30 TribeTacticalAIModule::processCoopAttack
// PDB: taitacmd.cpp lines 13085-13106
// Attempt log:
// try 1: replaced bogus stub with packet/decompiler-based implementation and local class surfaces: 6-byte localized register mismatch.
// try 2: direct &this->groups loop condition: no change.
// try 3: register sentinel: no change.
// try 4: self local adjusted by +0x9D4, int sentinel, and pointer sentinel variants: no change.
// try 5: register current count: no change.
// try 6: free __thiscall form rejected by VC5; restored member method.
// try 7: declared current outside loop; no improvement, still 6-byte register mismatch.
// try 8: rewrote loop as initial-if plus while/break; worsened branch layout, rolled back.
// try 9: declared sentinel before group; worsened whole register allocation, rolled back.
// try 10: for-loop with explicit null break; no improvement.
// try 11: inverted desired/current compare; worsened compare opcode/polarity, rolled back.
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent register allocation drift.
// Remaining 6 bytes are only sentinel/current-count register choices: original mutates EDI
// to the sentinel and uses EBX for current count; rebuilt keeps sentinel in EBX via LEA
// and uses EDI for current count. Calls, predicates, loop effects, stack cleanup, and
// memory effects otherwise match exactly.

#ifndef TAITACMD_SHARED_CONTEXT
class DiplomacyAIModule { public: void setStance(int player, int stance, int value); };
class TacticalAIGroup {
public:
    TacticalAIGroup* prev;
    TacticalAIGroup* next;
    int type();
    int numberUnits();
    int desiredNumberUnits();
    void setDesiredNumberUnits(int n);
};
class TribeTacticalAIModule {
public:
    char gap_000[0x0F0];
    MasterAI* masterAI;
    char gap_0F4[0x9D4 - 0x0F4];
    TacticalAIGroup groups;
    char gap_9DC[0xE18 - 0x9DC];
    int attackEnabledValue;
    int processCoopAttack(int p1, int player, int p3, int p4);
};
#endif
int TribeTacticalAIModule::processCoopAttack(int p1, int player, int p3, int p4) {
    if (attackEnabledValue == 0) {
        return 0;
    }

    masterAI->diplomacyAI.setStance(player, 0, 100);

    int current;
    TacticalAIGroup* group = groups.next;
    TacticalAIGroup* sentinel = &groups;
    for (; group != sentinel; group = group->next) {
        if (group == 0) break;
        if (group->type() == 100 || group->type() == 0x67) {
            current = group->numberUnits();
            if (group->desiredNumberUnits() > current) {
                group->setDesiredNumberUnits(group->numberUnits());
            }
        }
    }

    return 1;
}
#else
int TribeTacticalAIModule::processCoopAttack(int p1, int player, int p3, int p4) {
    return 0;
}
#endif
