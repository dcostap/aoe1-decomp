# Recovery journal: 004FE950 `fillBoatGroups`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.
- Earlier recovery note: `recovery_notes/taitacmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:f540d766894ee95f66c2 -->
### `d050eea3c` `src/taitacmd.cpp:12634-12651`

Mapping: `ambiguous`. next mapped function definition is fillBoatGroups at old line 12947.

```text
//   Remaining lead is the real local-lifetime/register basin around the target
//   stack homes (especially the saved numPotentialEGroups/numAGroups values).
// - ManagedArray recovery pass, 2026-08-19: the exact add body replaces the
//   manual caller-side scan and emits the same 2887-byte frontier. The complete
// [non-comment lines omitted during migration]
//   is codegen-identical in this basin.
// - current best is 643 positional diff bytes, 98.84% shape, 91.10% exact
// [non-comment lines omitted during migration]
//   and a function-scope product were codegen duplicates or worse. Restored
// [non-comment lines omitted during migration]
// BINARY NOTE: the min clamp loads sn[0x3a] before warBoats.numberValue and
// [non-comment lines omitted during migration]
// Remaining mismatch: the original first balance block loads numAGroups from
```
<!-- end-recovered:f540d766894ee95f66c2 -->

<!-- recovered:36dfcf266b429149db37 -->
### `6a2aef2e2` `src/taitacmd.cpp:10853-10882`

Mapping: `ambiguous`. next mapped function definition is fillBoatGroups at old line 11154.

```text
//
// ManagedArray<int> surface. The three boat lists and workingArea are named
// ManagedArray<int> members, while the group list is the TacticalAIGroup
// sentinel owned by TribeTacticalAIModule. The repeated boat phases are kept
// as ordinary source-level loops; their shared remove/copy topology is visible
// in the original CFG.
//
//   and three ordinary boat-group phases; 2887-byte target rebuilt as 2894
// - negative type guard with explicit continue: matched the original late
// - declaration/local-role reorderings (including the retained type-68 count)
//   emitted the same VC5 code; no further declaration archaeology retained.
//   clamps produced the exact 2887-byte size and exact balance focus range.
// - explicit remainder guards with a separate retained type-68 local restored
// - compact arithmetic with a separate retained local, hoisted product and
//   remainder locals, and the exact setupSoldierGroups scalar declaration order
// - corrected the third balance denominator/cap from sn[0x3d]/sn[0x3c] to
//   from 94.07% to 94.39% and exact blocks from 70.87% to 71.29%, with the
//   numPotentialEGroups restored the 0x2C frame and 81.57% exact blocks, but
//   lifetimes, register hints, function-scope group pointers, and loop-form
//   71.29% exact blocks, 93/93 ordered calls, and frame 0x28 versus 0x2C.
//   shared header inlines resize at this site, adds one allocator pair and 82
//   bytes, and changes the call surface. Keep resize declaration-only here.
//   restores the 0x2C frame and the main balance CFG. Named maximum and count
//   locals preserve the sn-first load order. A function-scope remainder local
//   blocks, and 93/93 ordered calls. The rebuilt size is 2889 versus 2887.
// - compound products, declaration-local call results, a typed balance pair,
//   the smallest natural product and scalar forms.
// the min clamp loads sn[0x3a] before warBoats.numberValue and
//   uses cmp eax,ecx. The ternary source reproduces that local instruction order.
//   [esp+20h]. The best rebuild loads the same source value from [esp+24h].
```
<!-- end-recovered:36dfcf266b429149db37 -->

<!-- recovered:2a770551f030e798d75d -->
### `target-session` `build/target_sessions/004FE950_fillBoatGroups.json:1-38`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 liveness; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 1: reuse the single group local across the second boat-type scan, as original stack home [esp+10] and PDB decomp indicate; test pointer lifetime and block placement.
probe 2 control-flow; result=MISMATCH; diff=2481; shape=92.5: Hypothesis 2: express the second scan as a positive type guard with one shared group increment, matching original skip path store/retest rather than an explicit continue.
probe 4 liveness; result=MISMATCH; diff=2491; shape=92.71899886234357: Hypothesis 3: declare the sentinel before bestUnit, matching original EBP sentinel lifetime from entry and stack bestUnit home; test saved-register colors and full frame.
probe 5 liveness; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 4: scope bestUnit inside the strategic-number guard, matching its first PDB use and stack home while leaving sentinel declaration after setup calls. [same emitted code as probe 3]
probe 6 abi; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 5: use the exact donor ManagedArray indexer copy form with a for loop, because original expansions materialize index+1 before allocation and compare the loop bound in that order.
probe 7 behavior; result=MISMATCH; diff=2472; shape=92.83276450511946: Hypothesis 6: reverse the final nearest-fill loop predicate to desiredNumberUnits() > numberUnits(), matching the original desired-then-number call order and the checker hard discrepancy.
probe 8 control-flow; result=MISMATCH; diff=2509; shape=90.74492099322799: Hypothesis 7: restore the original repeated nearest-fill do loop after the initial underfilled guard; original branches back to the pre-scan desired/number calls after each removal.
probe 9 control-flow; result=MISMATCH; diff=2481; shape=82.0250284414107: Hypothesis 8: keep explicit desiredAgain/numberAgain temporaries at the repeated nearest-loop test, enforcing the original desired-then-number call order while retaining the restored loop.
probe 10 liveness; result=MISMATCH; diff=2481; shape=82.0250284414107: Hypothesis 9: replace the named sentinel local with direct &this->groups comparisons, because original rematerializes the sentinel at loop transitions and may color EBP independently.
probe 11 liveness; result=MISMATCH; diff=2481; shape=82.0250284414107: Hypothesis 10: move bestUnit back to function scope so VC5 spills the type loop selector to its proven [esp+1c] home instead of keeping it in EDI after the repeated nearest loop. [same emitted code as probe 10]
probe 12 liveness; result=MISMATCH; diff=2481; shape=82.0250284414107: Hypothesis 11: use a block-local bestUnit declaration with initializer, testing whether delayed lifetime restores the proven stack selector home despite the repeated nearest loop. [same emitted code as probe 11]
probe 13 behavior; result=MISMATCH; diff=2476; shape=77.0193401592719: Hypothesis 12: correct the first fill split to direct-add when ungrouped > missing, with nearest selection as fall-through; original cmp/jump proves this polarity and block order.
probe 15 behavior; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 13: restore the final excess-boat nearest loop's original numberUnits() < desiredNumberUnits() spelling; prior reversed predicate changed call order without improving the +08e7 mismatch.
probe 16 behavior; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 14: materialize desiredNearest and numberNearest after each excess redistribution, matching original desired-then-number calls before its backedge.
probe 17 abi; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 15: use the exact same-TU donor's reviewed C-linkage operator_new/operator_delete declarations, because original array growth has direct targets and immediate caller cleanup.
probe 18 liveness; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 16: make bestGroup function-scope, matching the original persistent [esp+10] bestGroup home and required zero store at each excess-distribution iteration. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 17: materialize the bestGroup zero through a block-local initialized pointer, testing whether VC5 emits the original [esp+10] reset instead of eliding it.
probe 20 liveness; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 18: reuse group for the fallback candidate scan, matching the original single decompiler pointer and avoiding a second compiler-facing list variable. [same emitted code as probe 18]
probe 21 liveness; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 19: split newSize declaration from assignment in the inline array growth path, testing whether VC5 preserves the original pre-call index+1 LEA and cleanup adjacency. [same emitted code as probe 20]
probe 22 abi; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 20: mirror the exact donor's nested copy-loop bound with an explicit j>=newSize break, testing array-growth LEA order and operator-delete cleanup.
probe 23 abi; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 21: name the array allocation byte count before operator_new, matching the original simultaneous index+1 and index*4 LEAs before each growth call.
probe 24 liveness; result=MISMATCH; diff=2481; shape=82.13879408418657: Hypothesis 22: declare the group cursor before the named sentinel, matching original emitted load-before-LEA order and testing EBP sentinel versus EBX count coloring.
probe 26 control-flow; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 1: mirror the decompiler-proven outer do loop: initial group walk continues until sentinel/null, then runs the type-fill and fallback passes inside that termination branch. This tests source CFG nesting rather than separate sequential loops. [same emitted code as probe 25]
probe 27 liveness; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 2: recover PDB-local ownership by removing the unproven sentinel alias and using one temp TacticalAIGroup pointer across the initial, type-fill, and fallback walks. PDB records temp at entry-relative -0x18 and no sentinel/candidate locals.
probe 29 abi; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 3: use the exact same-TU ManagedArray donor's for-loop copy form instead of the current while form. The original copy blocks use a preexisting new-size register and direct index increment; this tests the array-growth source shape at all six expansion sites.
probe 30 liveness; result=MISMATCH; diff=2475; shape=64.50511945392492: Hypothesis 4: mirror the PDB local surface: one function-scope i, a as the 0x67..0x6A type selector, and one bestUnit reused by both nearest scans. The PDB records i, a, and bestUnit homes, with no bestUnitID local.
probe 32 abi; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 5: mirror the exact ManagedArray donor's declaration style by separating j declaration from the for initializer. This tests the compiler's local-home and copy-loop lowering basin after the declaration-inside-for variant was codegen-neutral. [same emitted code as probe 29]
probe 33 abi; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 6: use the exact same-TU C-linkage operator_new/operator_delete surface from numberUngroupedWarBoats. The target's array-growth blocks share its lea-new-size/copy topology, so this tests allocator declaration semantics rather than a register axis.
probe 35 liveness; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 7: make the type-fill walk use a function-scope temp pointer while retaining the clean initial and final group walks. This tests whether the PDB-proven temp home at -0x18 causes the original spill without changing fallback call ordering.
probe 37 abi; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 8: restore the exact same-TU template ManagedArray<int> type surface and sizeof(T) allocation expression instead of a target-only ManagedArrayInt struct. Matching donors use this template, and the target repeatedly inlines its operator[] growth path.
probe 38 control-flow; result=MISMATCH; diff=2520; shape=81.91126279863481: Hypothesis 9: recover the executable's proven repeated first nearest-fill backedge at 004FEDCA by making the nearest scan/add/remove a do loop with desired-then-number post-test. This tests original behavior and physical CFG rather than the prior outer-continue approximation.
probe 40 behavior; result=MISMATCH; diff=2504; shape=87.03071672354949: Hypothesis 10: replace metric-oriented desired/number/missing temporaries in the second boat pass with direct member expressions. PDB line 10816/10828/10889 groups desired and number calls on one source line, and direct reads are the period-supported form.
probe 42 abi; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 11: copy the exact period ManagedIntArray donor's operator[] source shape: global-qualified C++ allocation, separate j declaration, and for(j=...; j++). The donor emits the target's lea new-size and two-bound copy topology. [same emitted code as probe 32]
probe 43 context; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 12: restore the period standard-header context used by exact same-TU ManagedArray donors with <stddef.h>. This tests front-end context without changing the source model or ABI.
probe 44 liveness; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 13: remove const from the named sentinel pointer. The original keeps a mutable EBP sentinel-like value across the first pass while the clean source colors const sentinel EBX; this tests declaration qualification without changing control flow. [same emitted code as probe 43]
probe 45 context; result=MISMATCH; diff=2472; shape=92.94653014789533: Hypothesis 14: add the period math header used by exact same-TU float/geometry donors. The target has repeated float distance calls and x87 comparisons, so this tests supported header-state effects.
probe 46 behavior; result=MISMATCH; diff=2472; shape=92.83276450511946: Hypothesis 15: reverse the final nearest-fill post-test to desiredNumberUnits() > numberUnits(), matching the original desired-then-number call order at +08E7 while preserving the same predicate.
probe 47 variant; result=MISMATCH; diff=2472; shape=92.83276450511946: variant lab build\variant_lab\004FE950_fillBoatGroups\20260822_162038: 128 variants, 0 invariant-eligible, 0 exact
```
<!-- end-recovered:2a770551f030e798d75d -->

<!-- recovered:c5f967f662b9d4cf0874 -->
### `3789ccb1ae1e` `src/scratch/004FE950_fillBoatGroups.cpp:2-45`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004FE950 TribeTacticalAIModule::fillBoatGroups
// Attempt log:
// baseline: natural period-plausible reconstruction using the real group list,
// ManagedArray<int> workingArea ownership, and the three boat-filling passes.
// Bounded pass: restored the group-sentinel walk, commander assignment for
// empty/nonempty boat groups, workingArea growth/removal, three type-based fill
// passes, nearest-unit selection, and excess-unit redistribution. Declaration,
// loop, predicate, count-cache, and selection-tail probes did not recover the
// original physical block order. Final validation is 2924/2959 bytes with the
// exact 0x18 frame and exact 103-call target multiset, but only 87.38% ordered
// alignment; the remaining issue is broad CFG placement around the best-unit
// loop and transition back to the group list, not a codegen-only local axis.
// Later structural probes inverted direct-fill/nearest branches and the final
// best-group fallback, then scoped the second boat iterator. Ordered calls now
// align 103/103 with a 2935-byte rebuild; the remaining drift is register and
// block placement at the second boat pass, not call or memory-effect coverage.
// The final candidate keeps these natural source shapes and remains in scratch.
// Integration check: the ordered call map is aligned, but the checker still
// reports one direct-target difference at +08E7 (desiredNumberUnits versus
// numberUnits). Treat that site as the next binary-behavior lead.
// Tried the proven same-TU AIModule base surface with md at +0xF0; emitted
// code was unchanged, so restored the clean source.
// Tried a natural for-loop increment for the second boat-type scan because
// the original has separate type-skip and underfilled-false increment blocks;
// it changed diff 2472 to 2481 and was rolled back.
// Managed pass 2026-08-17: ran 22 meaningful hypotheses. The clean baseline
// remains the best codegen result: 2935 bytes, 2472 differing bytes, 92.95%
// shape, exact frame, and 103 aligned calls. The pass tested group-local
// reuse, loop polarity and do-loop forms, scope and declaration order, the
// repeated nearest-fill loop, desired/number call order, exact ManagedArray
// copy forms, C-linkage allocation helpers, and fallback cursor reuse.
// The original proves a repeated nearest-fill backedge at 004FEDCA and a
// desired-then-number call order at 004FF156. Adding that loop improved the
// behavior model but moved the result to 2937 bytes and 2481 differing bytes;
// it was restored because it did not preserve the original physical layout.
// All array, pointer, and candidate-local variants were codegen-neutral or
// worse. The remaining lead is the compiler's second-pass register and block
// allocation: original uses EBP for the sentinel and EDI for the boat group,
// while the clean source uses EBX for the sentinel and EBP for that group.
// Worker pass: the exact ManagedIntArray donor loop, global allocation
// spelling, <stddef.h> context, and mutable sentinel all emit this same
// 2935-byte baseline. An ambient declaration lab with 128 samples found one
// codegen group and no context lead. The unresolved first nearest-fill loop
// still has the proven executable backedge at 004FEDCA.
```
<!-- end-recovered:c5f967f662b9d4cf0874 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
