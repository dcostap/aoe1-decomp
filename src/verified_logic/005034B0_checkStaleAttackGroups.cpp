#ifndef TAITACMD_SHARED_CONTEXT
// 005034B0 TribeTacticalAIModule::checkStaleAttackGroups
// Source: taitacmd.cpp lines 13274-13312
// Attempt log:
// - Baseline direct expression: 182 bytes; VC5 evaluated desiredUnits before
//   numberUnits, unlike the executable.
// - Function-scope number/desired locals: 184 bytes, all six direct calls in
//   order; retained as the clean period-plausible reconstruction.
// - Volatile stack-home diagnostics reached 192 bytes and restored push ecx,
//   but stored the first result before desiredUnits rather than at the observed
//   post-call site; rolled back. Named time/world and comparison variants did
//   not improve emitted code. A 24-variant lab found no exact source.
// - Fresh pass (orch-luna-5034b0-w2): declaration-order, desired/difference
//   expression, compound-assignment, direct-predicate, full typed-layout, and
//   initialized-inner-local probes added no exact basin. The best fresh result
//   was the volatile-number diagnostic at 192 bytes (110 positional diff,
//   95.38% shape); it still spills before desiredUnits and has the wrong time
//   register basin. A 270-variant lab over storage/declaration/calculation/
//   compare/time surfaces found no exact or size-valid candidate. Full binary
//   TacticalAIGroup/RGE time/player fields were codegen-neutral. Restored the
//   clean natural source.
// - Normalization-only audit: replaced raw vtable_ptr with the exact-donor-backed
//   virtual TacticalAIGroup destructor surface; emitted code was unchanged. No
//   new matching hypothesis was introduced.
// - Paused: remaining drift is the VC5 local spill/liveness and time-expression
//   basin; no ABI/call-set or behavioral uncertainty is known.
// - Fresh bounded pass (orch-taitcmd-01): elapsed-first comparison plus the
//   known volatile stack-home surface reached 192 bytes / 111 positional diff
//   with target time-chain registers; a PDB-style for loop was codegen-duplicate.
//   Reused-value, compound-assignment, initializer-scope, and three-local
//   declaration permutations were duplicate or worse. Adding/removing an
//   owning-module virtual surface was also codegen-neutral; the donor vtable
//   word did not improve the remaining local spill. Restored this clean source.
// - Paused: ten fresh hypotheses exhausted; best diagnostic remains the prior
//   192-byte / 110-diff volatile-number basin, while the retained source is the
//   natural 184-byte reconstruction. Calls, layout, and behavior are understood.
// - Fresh final pass (orch-taitacmd-fresh-04): inner ordered result
//   initializers plus elapsed-first comparison were unchanged structurally;
//   inner volatile-number plus elapsed-first reached 192 bytes / 111 diff.
//   Desired-before-number declarations, reference alias, comma assignment,
//   ordinary desired-minus-number reuse, and register-qualified desired were
//   duplicate or worse. Re-establishing the prior diagnostic best confirmed
//   192 bytes / 110 diff; its spill still occurs before desiredUnits rather
//   than at the oracle's post-call site. Restored clean natural source.
// - Paused: fresh ten-hypothesis budget exhausted; exact calls and typed
//   ownership remain established, while the local spill/liveness and time-chain
//   register basin remain unresolved.
// - Fresh bounded pass (wave21-taitacmd-01): revalidated the clean source, then
//   tested the actual AIModule/TacticalAIModule base chain, polymorphic
//   RGE_Game_World/RGE_Player surfaces, and the inherited
//   MainDecisionAIModule -> TribeMainDecisionAIModule player ownership; all
//   were codegen-duplicate. Function-scope desired compound reuse, const
//   number, full Ghidra iVar1/iVar2 lifetime including the final setter temp,
//   a named elapsed quotient, and unsigned world_time were duplicate or
//   repeated prior basins. Restored the natural source.
// - Paused: canonical ownership, six ordered calls, CFG, and behavior remain
//   established; the only unresolved gap is the original delayed number spill
//   ([esp+10] after desiredNumberUnits) plus its associated time-register
//   basin. No further natural source/layout lead remains in this assignment.
// - Fresh bounded pass (sa42836b2c-r1-005034B0): a negative
//   elapsed<difference guard with a natural for-update reproduced the oracle's
//   cmp edx,edi / jl branch; combining inner volatile number with the
//   desired-minus-number local reached the prior 192-byte / 110-diff basin.
//   A late volatile copy followed by a separate difference local reached exact
//   size (194) and 27 positional-diff bytes with all six calls and CFG aligned,
//   but selected the wrong subtraction order and time-chain register coloring.
//   This compiler-steering diagnostic was not retained; restored the clean
//   natural source.
// - Paused: ten meaningful hypotheses exhausted. Best retained source remains
//   the natural 184-byte reconstruction; next lead is combining the late
//   post-desired spill topology with the target EDI time-chain basin without
//   retaining redundant volatile/copy scaffolding.
// - Fresh bounded pass (orch-005034B0-L): ten liveness/context probes tested
//   split subtraction, address-taken number storage, world caching, and
//   stdlib/string header context. Inner volatile number plus the natural
//   inverted elapsed guard reproduced the prior best at 194 bytes / 27 diff;
//   all other probes were duplicate or worse. The best diagnostic still uses
//   the wrong desired subtraction order and time-chain register allocation.
// - Paused: restored and validated the clean natural source. Calls, layout,
//   CFG, and behavior remain established; delayed number spill and time-chain
//   allocation remain unresolved.
// - Current TU pass: dossier and original assembly confirm the only structural
//   gap is the 4-byte local home (`push ecx`, post-desired spill at [esp+10]).
//   Same-TU exact donors and the canonical 00501D70 nested layout add no new
//   source ownership fact. The clean typed source remains authoritative; no
//   natural, evidence-backed spill lead remains without compiler steering.

#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Game_World {
public:
    char gap_00[4];
    int world_time;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char gap_0C[0x32C - 0x0C];
    unsigned long lastAddedUnitTimeValue;

    int type() const;
    int inUse() const;
    int numberUnits() const;
    int desiredNumberUnits() const;
    void setDesiredNumberUnits(int value);
};

// Main-agent audit confirmed canonical tactical/group/time ownership and kept
// the natural stale-group scan.
class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0x9D4 - 0x0F4];
    TacticalAIGroup groups;
    char gap_D04[0xE18 - 0xD04];
    int attackEnabledValue;

    void checkStaleAttackGroups();
};

#endif
void TribeTacticalAIModule::checkStaleAttackGroups()
{
    int number;
    int desired;

    if (this->attackEnabledValue != 0) {
        TacticalAIGroup* group = this->groups.next;
        TacticalAIGroup* sentinel = &this->groups;

        while (group != sentinel && group != 0) {
            if (group->type() == 100 && group->inUse() != 1) {
                number = group->numberUnits();
                desired = group->desiredNumberUnits();
                int difference = desired - number;
                if (difference > 0) {
                    if (difference > 5) {
                        difference = 5;
                    }
                    if (difference <=
                        (int)(this->md->player->world->world_time -
                              group->lastAddedUnitTimeValue) / 60000) {
                        group->setDesiredNumberUnits(group->numberUnits());
                    }
                }
            }
            group = group->next;
        }
    }
}
#else
void TribeTacticalAIModule::checkStaleAttackGroups() {}
#endif
