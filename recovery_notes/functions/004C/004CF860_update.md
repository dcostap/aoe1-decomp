# Recovery journal: 004CF860 `update`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_hnt.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_hnt.cpp`.
- Earlier recovery note: `recovery_notes/004CF860_update.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:9ad3e068b1e7bbc540af -->
### `d050eea3c` `src/tact_hnt.cpp:189-189`

Mapping: `ambiguous`. next mapped function definition is update at old line 278.

```text
        // BINARY NOTE: The action master is stored as a static-master pointer.
```
<!-- end-recovered:9ad3e068b1e7bbc540af -->

<!-- recovered:5f5b563c9d0bf81ecc9d -->
### `d050eea3c` `src/tact_hnt.cpp:214-214`

Mapping: `strong`. next mapped function definition is update at old line 278.

```text
        // BINARY NOTE: State 7 reads attribute_type_held (+0x4C), then calls
```
<!-- end-recovered:5f5b563c9d0bf81ecc9d -->

<!-- recovered:c35291fbad268888e1dc -->
### `d050eea3c` `src/tact_hnt.cpp:258-258`

Mapping: `strong`. next mapped function definition is update at old line 278.

```text
        // BINARY NOTE: The shipped check reads target_obj (+0x10), not
```
<!-- end-recovered:c35291fbad268888e1dc -->

<!-- recovered:5c3a52f53658e9d9b4be -->
### `target-session` `build/target_sessions/004CF860_update.json:1-30`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1237; shape=49.92175273865415: Baseline current scratch source: exact size/frame/saved-register parity but call and CFG order mismatch; first structural divergence is switch dispatch table and state-4 arm.
probe 2 control-flow; result=MISMATCH; diff=1185; shape=59.937402190923315: Hypothesis 2: reorder outer switch cases to PDB/jump-table source order: 11/15, 4, 12, 6, 7, 8, 1, 13.
probe 3 control-flow; result=MISMATCH; diff=1178; shape=81.84663536776213: Hypothesis 3: move the shared computer_fallback block before case 1, matching PDB line order before the final state-1 and state-13 arms.
probe 4 control-flow; result=MISMATCH; diff=1178; shape=81.84663536776213: Hypothesis 4: place state_default before outer case 4, as the original emits the set_state(3) block at +0x12B before the state-4 dispatch.
probe 5 control-flow; result=MISMATCH; diff=1176; shape=81.84663536776213: Hypothesis 5: reverse the state-11/15 inner case-4 and case-3 source order; PDB bands place the state-3 fallback block before the computerPlayer case.
probe 6 control-flow; result=MISMATCH; diff=1176; shape=81.84663536776213: Hypothesis 6: route state-11/15 inner case 3 through an explicit label before outer case 4, forcing its direct computerPlayer block to precede the state-4 dispatch as in the original.
probe 7 control-flow; result=MISMATCH; diff=1176; shape=81.84663536776213: Hypothesis 7: keep separate state-11 and state-4 computerPlayer cases, using reversed comparison spelling only to prevent VC5 from merging their identical case blocks. [same emitted code as probe 5]
probe 8 control-flow; result=MISMATCH; diff=1133; shape=84.50704225352112: Hypothesis 8: use the semantically equivalent nonzero computerPlayer test for state 4 to force a separate case block.
probe 9 control-flow; result=MISMATCH; diff=1122; shape=86.85446009389672: Hypothesis 9: reverse state-4 inner case 3 and cases 1/2 source order; PDB lines 528 then 537 and the original places computerPlayer before set_state(6).
probe 10 control-flow; result=MISMATCH; diff=1122; shape=89.0453834115806: Hypothesis 10: reverse state-12 inner case 4 before cases 1/2/5 and 3; original emits the shared set_target/state-11 pair before the target check and state-3 tail.
probe 11 behavior; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis 11: state-7 with no target and positive self-held amount sets state 8 and returns; original +0x2D9 proves this missing call.
probe 12 control-flow; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis 12: give state-12 cases a distinct state12_default set_state(3) label before case 6; original has a separate +0x239 call instead of merging it with the later fallback.
probe 13 control-flow; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis 13: retain the separate state-12 default but use explicit unsigned-byte state and return types to prevent VC5 common-tail merging.
probe 14 abi; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis 14: call set_state(3) for state 12 through a local typed view with the proven +0x5C virtual slot, preventing common-tail merging without changing the emitted slot.
probe 15 control-flow; result=MISMATCH; diff=1277; shape=81.17977528089888: Hypothesis 15: route state-12's set_state(3) through the existing state_default2 return label, testing whether VC5 preserves a separate call block with a common epilogue.
probe 16 control-flow; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis 16: use a local state12_return label immediately after the distinct state-12 call, avoiding the long jump to state_default2 while preserving separate call emission.
probe 17 control-flow; result=MISMATCH; diff=1277; shape=81.60112359550561: Hypothesis 17: spell state-7's positive self-held arm first, then the low-amount fallback; original orders set_state(8) before the shared set_state(3) block.
probe 18 control-flow; result=MISMATCH; diff=1277; shape=81.60112359550561: Hypothesis 18: retain the positive-first state-7 branch but restore the short direct state12 return after removing the long-branch experiment.
probe 21 control-flow; result=MISMATCH; diff=1277; shape=81.60112359550561: Hypothesis 21: isolate the positive-first state-7 branch while keeping the direct state-12 source; test whether its block ordering alone supplies the missing call without size drift.
probe 22 control-flow; result=MISMATCH; diff=1277; shape=81.03932584269663: Hypothesis 22: preserve the positive-first state-7 branch with reversed comparison operands to seek original block order without the size expansion.
probe 25 baseline; result=MISMATCH; diff=1056; shape=88.73239436619718: Claim baseline: restored clean natural source with 1587B/0xC frame and merged state-12 state-3 call; verify current codegen before new source hypothesis. [same emitted code as probe 24]
probe 26 control-flow; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis: place the shared state-3 fallback label after the state-7 block, where original PDB line 620 assigns the shared call; keep state-12 case-3 as a direct return and test whether VC5 preserves its distinct call block. [same emitted code as probe 12]
probe 28 abi; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis: model the state-12 case-3 set_state call through a separate ABI-compatible virtual view while shared fallback calls use TRIBE_Action_Hunt; test whether this source-level static-type distinction preserves the original duplicate vslot+5C call.
probe 30 control-flow; result=MISMATCH; diff=1114; shape=86.07198748043818: Hypothesis: restore the state-8 subaction arm order shown by PDB/assembly: cases 3/4/5 (timer and stop_moving) before cases 1/2; test whether this recovers the original dispatch handler order and late call topology.
probe 32 control-flow; result=MISMATCH; diff=1139; shape=87.48043818466354: Hypothesis: place the shared state-3 fallback at function scope after the outer switch, matching a common-tail source model rather than an early in-switch label; test whether this prevents state-12 case-3 tail merging.
probe 33 control-flow; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis: keep the shared state-3 label after the switch but add an explicit return-zero tail so ordinary switch breaks do not fall through into the fallback; test the semantically natural common-tail layout for duplicate calls without extra state changes.
probe 35 abi; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis: replace the flat Hunt virtual placeholder class with the canonical RGE_Action base and TRIBE_Action_Hunt override surface from exact tact_hnt donors; preserve the proven 0x40 base layout and vslot +0x5C.
probe 36 abi; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis: use the exact donor's RGE_Action_List update() slot and canonical RGE_Action base surface instead of generic placeholder names; test whether reviewed ABI ownership changes target codegen while preserving vslot +0x0C and +0x5C.
probe 37 liveness; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis: place the shared fallback label inside state-7 after its function-scope locals, matching the PDB line-620 common tail while avoiding C++ jumps over local initializers; test whether this gives state-12 case-3 an independent call and original register topology.
probe 38 control-flow; result=MISMATCH; diff=1056; shape=88.73239436619718: Hypothesis: preserve a distinct typed zero return in state-12 case 3 while the shared fallback uses the ordinary return form; test whether VC5 keeps the original standalone state-3 call block.
```
<!-- end-recovered:5c3a52f53658e9d9b4be -->

<!-- recovered:31b086b0280bf8bfcf32 -->
### `15c48b296138` `src/scratch/004CF860_update.cpp:1-30`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004CF860 TRIBE_Action_Hunt::update
// PDB source: tact_hnt.cpp:384-794
// Attempt log:
// - initial bounded reconstruction from complete packet/Ghidra CFG; exact class offsets and virtual slots modeled locally.
// - validated baseline has exact 1587B size, 0xC frame, and 54/54 call-target counts,
//   but ordered calls are only 70.37% (-12/+12, 4 replacements), shape is 48.83%,
//   and strict diff is 1375B (86.6415%). Remains broad STRUCTURAL RECONSTRUCTION.
// - Direct-state and floating-global probes were no-ops or worse. Restored the
//   baseline. A late state-1 arm probe improved diff to 1282B but moved calls;
//   it was diagnostic only and was restored.
// - Original assembly proves state-8 uses target_obj2 for its distance guard,
//   target_obj after gathering, and task sound/attribute fields; fixed these owners.
// - Original jump tables prove the state-11/15 subaction arms and the state-8
//   no-state-change path; restored those behaviors and moved state 1 late.
// - Reordered the outer and nested arms from PDB line order. This raised shape
//   similarity to 88.73% and ordered-call alignment to 94.44%.
// - Original assembly proves a positive self-held state-7 path sets state 8.
//   The clean source keeps that behavior, but VC5 merges one state-3 call.
// - Twenty-two distinct hypotheses were checked. A positive-first guard gave
//   all 54 calls but added 149 bytes. It was rejected as non-natural and wide.
// - Final clean result: 1587B, 0xC frame, 53/54 calls, 1056B strict diff.
//   Remaining blocker is the merged state-12 state-3 call and block layout.
// - Follow-up probes tested shared-tail placement, state-8 case order, and
//   typed state-12 returns. They were unchanged or worse; the clean body is restored.
// - Replaced generic action and action-list placeholders with the exact donor
//   base surfaces. Emitted code is unchanged, but the source now names proven ABI.
// - TU repair: replaced the absolute rge_base_game view and duplicate local
//   data definitions with reviewed externs. Replaced world +0x84 reads with
//   the named world_time_delta_seconds field. Grouped output stayed at the
//   clean 1587-byte, 53/54-call, 1056-byte-diff result.
```
<!-- end-recovered:31b086b0280bf8bfcf32 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
