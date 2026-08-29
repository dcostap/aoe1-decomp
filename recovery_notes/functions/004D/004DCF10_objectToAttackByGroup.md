# Recovery journal: 004DCF10 `objectToAttackByGroup`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:775372f4db4a1d6035e1 -->
### `target-session` `build/target_sessions/004DCF10_objectToAttackByGroup.json:1-28`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=3381; shape=68.48934198331789: Baseline current scratch reconstruction: exact size and call prefix, frame 0x58 versus original 0x54; stores group and this aliases early.
probe 2 layout; result=MISMATCH; diff=3410; shape=65.51401869158879: Hypothesis 2: use one function-scope ManagedArray wallObjects, as Ghidra shows one wallObjects and original reuses stack window across wonder and candidate paths.
probe 4 liveness; result=MISMATCH; diff=3381; shape=68.48934198331789: Hypothesis 3: reorder function locals to the Ghidra declaration order, with commander object before loop indexes and boat flag before priest flag.
probe 6 control-flow; result=MISMATCH; diff=3420; shape=66.91588785046729: Hypothesis 4: restore the original early destroy scan's explicit !=1 and -1 < count-1 guard with a do/while, matching its single pretest and bottom backedge.
probe 8 liveness; result=MISMATCH; diff=3383; shape=68.48934198331789: Hypothesis 5: split commanderObject declaration from its initialization, testing whether the original line-3778 declaration band delayed the pointer materialization and register color.
probe 10 abi; result=MISMATCH; diff=3412; shape=68.77323420074349: Hypothesis 6: use the executable-proven md->player->visible receiver for get_visible, not target->owner->visible; original loads md player at +0xF0 then visible +0x38.
probe 11 liveness; result=MISMATCH; diff=3407; shape=69.14498141263941: Hypothesis 7: promote scoring and coordinate locals to function scope in the Ghidra-listed order, while preserving their assignments and expressions.
probe 12 liveness; result=MISMATCH; diff=3419; shape=69.08077994428969: Hypothesis 8: remove the wonder pointer's entry initializer; original returns EAX zero directly on done paths and only materializes wonder on selected paths.
probe 13 liveness; result=MISMATCH; diff=3419; shape=69.17363045496751: Hypothesis 9: align the leading declaration order exactly with the Ghidra local list: commanderZone, commanderObject, in-progress count, boat flag, target distance, priest flag, then score factors.
probe 14 control-flow; result=MISMATCH; diff=3565; shape=65.54472984942427: Hypothesis 10: emit the proven invalid-commander zero return directly after state->active=0, testing whether the original early epilogue is a direct return rather than a result-local goto.
probe 16 control-flow; result=MISMATCH; diff=3371; shape=63.55140186915888: Hypothesis 11 retry after syntax repair: one top-tested for loop owns the early destroy scan without the redundant outer guard.
probe 18 liveness; result=MISMATCH; diff=3405; shape=69.14498141263941: Hypothesis 12: mirror the original local stack declaration order (wonder, commander object, in-progress, boat, distance, priest, factor slots, obstruction slot, zone bytes) and reuse tempZone.
probe 20 liveness; result=MISMATCH; diff=3405; shape=68.68029739776952: Hypothesis 13: minimal source-order recovery for the leading locals: commander object, in-progress slot, boat flag, targetDistance, priest flag, then loop indexes.
probe 21 abi; result=MISMATCH; diff=3405; shape=68.49442379182156: Hypothesis 14: use the executable's DAT_00575564 threshold symbol for the distance clamp, not an equal literal; original fcomp relocates to 00575564.
probe 22 liveness; result=MISMATCH; diff=3405; shape=68.49442379182156: Hypothesis 15: reuse the destroy-scan index as the persistent important-memory index, reducing one source local and following the Ghidra single-index mapping.
probe 23 layout; result=MISMATCH; diff=3455; shape=63.40782122905028: Hypothesis 16: use the ground-truth POD ManagedArray surface by removing local constructor/destructor machinery; test whether original manual array lifetime explains the frame and EH gap.
probe 24 liveness; result=MISMATCH; diff=3405; shape=68.49442379182156: Hypothesis 17: reorder score terms to the executable's strategic-number call order 0x50, 0x4D, 0xB8 while preserving the same arithmetic. [same emitted code as probe 22]
probe 25 liveness; result=MISMATCH; diff=3405; shape=68.49442379182156: Hypothesis 18: make the incoming group pointer value-const, testing whether original stack-reload coloring reflects a non-reassigned parameter without changing ABI. [same emitted code as probe 24]
probe 26 context; result=MISMATCH; diff=3405; shape=68.49442379182156: Hypothesis 19: restore period standard-header context with <stdlib.h> alongside <math.h>, testing old-MSVC front-end basin effects without changing behavior. [same emitted code as probe 25]
probe 27 context; result=MISMATCH; diff=3405; shape=68.49442379182156: Hypothesis 20: restore same-TU string-header context with <string.h>, since taiinfmd.cpp contains string routines and VC5 front-end state can alter codegen. [same emitted code as probe 26]
probe 31 layout; result=MISMATCH; diff=3447; shape=66.54205607476635: Hypothesis 1: use one function-scope ManagedArray wallObjects, matching Ghidra's single local and the original reused wall-list stack window.
probe 33 control-flow; result=MISMATCH; diff=3589; shape=64.77876106194691: Hypothesis 2: return zero directly on invalid commander, matching the original branch at 004DDD1E before the common zero-return tail.
probe 35 liveness; result=MISMATCH; diff=3470; shape=67.06864564007421: Hypothesis 3: materialize the memory kills byte as a local immediately before random scoring, matching the original pre-score float home and Ghidra's killsByTarget variable.
probe 37 control-flow; result=MISMATCH; diff=3403; shape=69.42379182156134: Hypothesis 4: accumulate score in three statements, with strategic weights 0x50, 0x4D, then 0xB8, matching the original ordered call and x87 accumulation block.
probe 38 liveness; result=MISMATCH; diff=3403; shape=69.42379182156134: Hypothesis 5: declare commanderZone before commanderObject, matching the original adjacent byte homes at entry-relative +0x14/+0x13 for commander and target zones. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=3404; shape=69.42379182156134: Hypothesis 6: promote the six score-factor locals to function scope in the Ghidra-listed order, matching the original persistent stack-home family without adding unused steering locals.
probe 41 liveness; result=MISMATCH; diff=3403; shape=69.51672862453532: Hypothesis 7: reuse one natural timeKillRatio local for hp/damage, then replace it with killTime/timeKillRatio, preserving the original FPU fault order while removing the extra healthOverDamage lifetime.
probe 42 liveness; result=MISMATCH; diff=3403; shape=69.51672862453532: Hypothesis 8: promote the reused timeKillRatio local to function scope, matching the Ghidra lifetime list while keeping the proven FPU evaluation order. [same emitted code as probe 41]
```
<!-- end-recovered:775372f4db4a1d6035e1 -->

<!-- recovered:815d18dac3738af88a61 -->
### `e60c9ade81a4` `src/scratch/004DCF10_objectToAttackByGroup.cpp:1-54`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004DCF10 TribeInformationAIModule::objectToAttackByGroup
// PDB source: taiinfmd.cpp lines 3771-4247
//
// Baseline reconstruction: the module owns ObjectMemory records, while the
// group owns only the transient destroy list.  The candidate scan is resumed
// through AttackState::iterationIndex/phase; path obstruction lists are local
// ManagedArray<int> values and are folded into the group's destroy list.
//
// Attempt log:
// - baseline candidate pending: period-plausible typed reconstruction with the
//   observed group/object/path/score call order; no compiler steering or asm.
// - probe 2: named the ID-path vtable surface separately from the point-path
//   overload and restored the observed default path argument (vslot +0x194).
// - probe 3: kept separate coordinate conversions for zone, visibility, and
//   score distance; added the observed visibility gate and unit scan.
// - probe 4: shared the fallback and best-target objectToDestroy/objectMemory
//   tail through the current destroy index; ordered calls became exact.
// - probe 5: reused the destroy-loop index; no useful frame improvement.
// - probe 6: restored canonical canPath naming without emitted-code movement.
// - probe 7: propagated ObjectMemory::owner to the group destroy metadata;
//   this also recovered the original 0x54 frame and much deeper alignment.
// - probe 8: tested an explicit long-lived this alias; rolled back (frame and
//   code shape worsened).
// - probe 9: converged early returns and timeout paths through one result/
//   cleanup epilogue, matching the original single-return CFG family.
// - probe 10: reused the function-level wonder/result slot; size is exact,
//   calls and boundary are exact, but bytes remain nonexact.
// - probe 15: moved result-slot zeroing to the binary-observed pre-isBoat
//   point; positional diff improved by one byte, but shape and resync drift
//   worsened, so restored the clean source.
// - probes 16-20: tested local declaration order, loop forms, shared versus
//   block-local ManagedArray objects, POD lifetime, and standard headers.
//   None produced a better clean codegen basin. The block-local arrays keep
//   the original nine operator_delete call sites.
// - probes 21-28: restored the md-player visibility receiver and the
//   DAT_00575564 distance threshold from assembly. Reusing the scan index and
//   moving targetDistance to function scope changed little; no exact result.
// - probe 31: one function-scope wallObjects object removed two required
//   operator_delete sites and worsened the frame. Block-local arrays remain.
// - probe 33: a direct invalid-commander return added cleanup exits and made
//   the function 148 bytes larger. The shared zero-return tail remains.
// - probe 35: a named kills factor added a stack slot and worsened the frame.
// - probe 37: sequential score accumulation in 0x50, 0x4D, 0xB8 order reduced
//   the positional diff by one byte and improved shape and resynchronization.
// - probes 38-39: commanderZone reorder was codegen-neutral; function-scope
//   score factors were one byte worse. Both use the smaller natural form.
// - probe 41: one timeKillRatio local preserves hp/damage-before-time order
//   and improved shape without changing size or calls. Probe 42 was a codegen
//   duplicate after promoting that local to function scope.

// BINARY NOTE: visibility uses this module's md->player map, not the target
// owner's map. The executable loads md->player before visible.
// BINARY NOTE: the distance clamp reads DAT_00575564. Keep the symbol rather
// than replacing it with an equal literal.
```
<!-- end-recovered:815d18dac3738af88a61 -->

<!-- recovered:aba1af0fe6993e60871f -->
### `e60c9ade81a4` `src/scratch/004DCF10_objectToAttackByGroup.cpp:114-116`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// This is the period ManagedArray<int> surface used by the original local
// obstruction lists.  Its inline indexer is intentionally the ordinary
// resizing implementation, not a hand-written vtable/offset scaffold.
```
<!-- end-recovered:aba1af0fe6993e60871f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
