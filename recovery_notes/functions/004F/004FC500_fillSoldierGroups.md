# Recovery journal: 004FC500 `fillSoldierGroups`

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


<!-- recovered:2f27cd03fb85c588fb05 -->
### `d050eea3c` `src/taitacmd.cpp:11659-11676`

Mapping: `ambiguous`. next mapped function definition is fillSoldierGroups at old line 11967.

```text
//    zero-register liveness below; the first strict mismatch is this slot in the
// [non-comment lines omitted during migration]
// No fake volatility, manual vtables, opaque scaffolding or inline asm retained.
// ManagedArray recovery pass, 2026-08-19:
// [non-comment lines omitted during migration]
//   frontier as the former manual scans. It matches the PDB line ownership and
```
<!-- end-recovered:2f27cd03fb85c588fb05 -->

<!-- recovered:eba75f5dd2e9513edaf9 -->
### `d050eea3c` `src/taitacmd.cpp:11916-11920`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// ---------------------------------------------------------------------------
// PDB source owner: 004FC500_fillSoldierGroups.cpp
// ---------------------------------------------------------------------------
// VA: 004FC500 TribeTacticalAIModule::fillSoldierGroups
// Baseline reconstruction: the embedded TacticalAIGroup at +0x9D4 owns the
```
<!-- end-recovered:eba75f5dd2e9513edaf9 -->

<!-- recovered:29fd7a26d1b80df6d985 -->
### `6a2aef2e2` `src/taitacmd.cpp:10007-10055`

Mapping: `ambiguous`. next mapped function definition is fillSoldierGroups at old line 10326.

```text
//
// uses the established inline operator[]/remove surfaces; the local list uses
// the out-of-line resize member, as shown by the original call at 004147A0.
//
// - default flags, no ManagedArray destructor: 2156 bytes, no EH frame; rolled
//   back after confirming the target's FS registration requires a nontrivial
//   local lifetime.
//   body after dead-store elimination.
// - function-scope numPotentialAGroups models the FPU remainder home; the
//   constructor form preserves the original zero-store scheduling and is kept.
//   numAGroups/i before the workingArea loop; the leftover numAGroups is used as
//   the workingArea index (general operator[] growth, no const-fold to element 0).
//   Removed the pre-loop reset; moved `i = 0; numAGroups = 0;` to after the loop.
// - time-check: original computes BOTH /1000 divisions into named locals before
//   the test (rebalance statement first, attack second; test attack-first).
//   The inline && short-circuits in VC5; named locals reproduce the dual mul/shr.
//   while(numEGroups>i), while(local_24>numAGroups), else-arm
//   numPotentialAGroups >= sn[0x24] with a named maxArtifact temp (original loads
//   sn[0x24] on its own source line 9494 first).
// - else-arm i as min(...) (ternary/if-else) stores i after the subtraction;
//   newArtifact=ebx, product=edi CSE across the ceil call via the artifactUnits
//   local).  Current best: 2245/2241 bytes (+4), frame 0x2C/0x2C, 69/69 calls,
// the original balance block keeps numAGroups at [esp+18h],
// newArtifact at [esp+10h], and the zero value in EBP across all three ceil
// VC5 selects the opposite two homes and rematerializes zero after __ftol.
// the original carries numAGroups into the workingArea index;
// there is no reset before that loop.  Keep this shipped behavior.
// LIKELY INTENT: the balance block is a direct group-count calculation with
// short-lived remainder values.  Named product and max-bound locals preserve
//   zero compare, a for-loop removal form, CRT headers, and a register hint
// Remaining leads (allocator coloring, not structure):
// 1. numAGroups/newArtifact stack-home swap: rebuilt homes numAGroups at
//    [esp+10h] and newArtifact at [esp+18h]; original has them swapped.
//    Declaration order (tried 5 orders) does not affect it.  It is tied to the
//    removeGroup loop (+0184).
// 2. zero-register liveness: original keeps the balance-entry zero in ebp live
//    across the ceil calls (`cmp eax,ebp` at the <=0 remainder checks); rebuilt
//    rematerializes `test eax,eax`, which frees ebp for i (mov ebp,eax after
//    __ftol) instead of ecx, and flips the product imuls to loaded-first forms
//    (+4 bytes total).  The imul folding (`imul edi,[esi+1D4h]` vs
//    `mov edi,[esi+1D4h]; imul edi,ebx`) is a scheduling symptom of the same.
// 3. first-path i clamp stores early (default-then-override) in BOTH versions;
//    else path stores i after the sub (min form) - already matched.
// - Replacing the complete local surface with include/utmarray.h made resize
//   inline twice. It added two allocator pairs and 214 bytes. The original
//   calls resize at both add sites, so the shared-header form is not valid in
//   this isolated translation unit.
// - The exact add body with declaration-only resize emits the same 2245-byte
//   removes unsupported caller-side field access. Keep this source model.
```
<!-- end-recovered:29fd7a26d1b80df6d985 -->

<!-- recovered:9751c4c658a5020948f0 -->
### `target-session` `build/target_sessions/004FC500_fillSoldierGroups.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=3085; shape=70.46979865771812: Baseline current scratch source: typed inline ManagedArray model, group repair, type passes, and final redistribution. Establish exact behavior, ordered calls, frame, and positional metrics.
probe 2 control-flow; result=MISMATCH; diff=3060; shape=70.49808429118774: Hypothesis 1: use a do-while outer type pass with a declaration-local group pointer and direct while sentinel walk. Original stores groups.next before sentinel compare and has a shared next/outer increment tail; this should recover that topology.
probe 3 liveness; result=MISMATCH; diff=3060; shape=70.49808429118774: Hypothesis 2: name the second-pass iterator group, matching the first sentinel walk's source variable. This tests whether VC5 reuses the original group's EBP color and emits the original load-group/LEA-sentinel order. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=3060; shape=70.49808429118774: Hypothesis 3: hoist the type-pass iterator declaration to function scope while retaining the direct sentinel while loop. This tests whether a long-lived iterator receives EBP and removes the rebuilt reload/extra compare. [same emitted code as probe 3]
probe 5 control-flow; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 4: restore original branch order from assembly. Fill all same-zone ungrouped units when missing <= ungrouped, then run the nearest add/remove pass only if still underfilled; use nearest grouped redistribution when missingExtra >= extra. Original jg edges prove these polarities and the two staged checks.
probe 6 control-flow; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 5: correct both assembly-proven conditional polarities. The initial direct fill runs when missing >= ungrouped because cmp(ungrouped,missing); the later nearest redistribution runs when missingExtra < extra because cmp(extra,missing) followed jg.
probe 7 liveness; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 6: reuse the proven bestGroup local as the type-pass iterator. Original stores the iterator at [esp+14] under the bestGroup debug name; this tests whether one owner recovers the EBP group color and exact early-list shape.
probe 8 liveness; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 7: remove the first list's explicit sentinel alias and use a direct &groups comparison. This tests whether the prior EBP sentinel lifetime forces the second pass into EAX, while preserving the original direct sentinel ownership.
probe 9 control-flow; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 8: model the original second pass as an explicit group/sentinel pair, assign bestGroup before the sentinel test, then use a while(1) with a bottom sentinel break. This mirrors the original load-group, LEA-sentinel, store-bestGroup, and shared next tail.
probe 10 control-flow; result=MISMATCH; diff=3078; shape=72.60536398467433: Hypothesis 10: replace the explicit bottom sentinel break with a natural do-while(group != sentinel) inside the outer sentinel guard. The original tail has one cmp/jne backedge, which this source form should preserve.
probe 11 behavior; result=MISMATCH; diff=3297; shape=44.5750452079566: Hypothesis 11: restore the proven workingArea removal after each second-stage removeFromGroup/addUnit direct transfer. Original assembly has the scan, shift, count decrement, and clamp immediately after that addUnit tail; the current source omitted this effect.
probe 13 context; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 12: model the proven AIModule primary base (vptr plus 0xEC bytes) instead of a flat 0xF0 gap. Exact same-TU donors use this inherited surface; the offset of md remains +0xF0 while compiler class context may change codegen.
probe 14 liveness; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 13: apply period-plausible register storage to the second-pass group iterator. The original keeps group in EBP while the rebuilt keeps the sentinel in EBP; this tests a focused register-coloring axis after structure is known. [same emitted code as probe 13]
probe 15 liveness; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 14: reverse the second-pass local declaration order, constructing the sentinel before groups.next. This tests VC5 local-color assignment independently from loop topology. [same emitted code as probe 14]
probe 16 layout; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 16: compute the second-pass sentinel from the proven +0x9D4 byte offset instead of the typed member address. This tests whether VC5's address-expression basin emits the original LEA sentinel and reassigns EBP to groups.next.
probe 17 control-flow; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 17: use an explicit empty-sentinel guard with bestGroup assignment before the guard, then retain the null test inside the body. This tests the original compare/store/je/test sequence against the current negated while guard. [same emitted code as probe 15]
probe 18 control-flow; result=MISMATCH; diff=3057; shape=46.985645933014354: Hypothesis 18: express the empty-group case as an early continue after bestGroup assignment, rather than wrapping the full walk in if(group != sentinel). This tests branch layout and whether VC5 emits the original store-before-je topology.
probe 19 liveness; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 20: reuse the earlier desired and number locals for the post-numberUngrouped desired/number calls. Original register trace carries ungrouped in EDI, desired in EBX, then subtracts into EBX; fresh desiredForFill/numberForFill currently reverse these colors.
probe 20 liveness; result=MISMATCH; diff=3056; shape=72.63157894736842: Hypothesis 21: hoist the second-pass group and sentinel declarations outside the outer type do-while, then assign them per type. This tests whether VC5's function-scope local coloring can keep group in EBP across the loop. [same emitted code as probe 19]
probe 21 control-flow; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 22: spell the initial fill predicate as ungrouped <= missing rather than missing >= ungrouped. Original uses cmp(ungrouped,missing) followed by jg, so this tests compare operand order and branch polarity directly.
probe 23 control-flow; result=MISMATCH; diff=3052; shape=72.31208372978116: Hypothesis 1: express the second-pass type filter as an early mismatch advance/continue. The original type compare falls through to group->next and jumps to the common sentinel test, while the current wrapped equality emitted a long skip over the body.
probe 24 control-flow; result=MISMATCH; diff=3027; shape=72.56977863330125: Hypothesis 2: keep one common sentinel test after the type filter by making mismatch and matching paths share group->next. The first probe added a mismatch-local sentinel compare, but original advances then reaches the common +9C9 test.
probe 25 liveness; result=MISMATCH; diff=3027; shape=72.56977863330125: Hypothesis 3: remove the second-pass sentinel local and compare directly with &groups. Original keeps group in EBP and recomputes the sentinel address in EAX at the common loop test; the current sentinel local colors EBP and group EAX.
probe 26 control-flow; result=MISMATCH; diff=3053; shape=73.43599615014438: Hypothesis 4: place the common group->next update inside the matching else arm, with the mismatch arm updating it once. This corrects the prior probe's accidental double advance and tests the original one-advance-per-path CFG.
probe 28 control-flow; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 5: use a natural while (group != sentinel) loop for the second-pass list. The original has one entry sentinel test and one common bottom cmp/jne; the baseline used an outer guard plus while(1) breaks.
probe 30 control-flow; result=MISMATCH; diff=3053; shape=73.43599615014438: Hypothesis 6: combine the natural sentinel-tested inner loop with an early type-mismatch continue. This matches the original compare-je body entry, fallthrough next update, and one loop-condition test without a metric-only branch scaffold.
probe 33 control-flow; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 7: split the final pass's numberUngroupedSoldiers guard from the workingArea count guard. Original has a separate call/test exit, then initializes the index before testing workingArea.numberValue; the combined && can remove that topology.
probe 36 liveness; result=MISMATCH; diff=3091; shape=73.33974975938402: Hypothesis 8: leave first final group-scan bestDifference uninitialized, as the original stores bestGroup=0 but shows no bestDifference zero store before the short-circuit candidate test. Keep the fallback scan's explicit zero.
probe 38 liveness; result=MISMATCH; diff=3057; shape=73.14725697786334: Hypothesis 9: remove the redundant final-pass unit local and pass workingArea[i] directly to the shared addUnit tail. The source does not need a temporary whose value is identical in both selection branches.
probe 40 liveness; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 10: reuse the existing group cursor for the fallback group scan instead of a second candidate cursor. Original reloads groups.next into the same EDI cursor after the first scan; this tests period-plausible cursor ownership.
probe 42 control-flow; result=MISMATCH; diff=3053; shape=73.43599615014438: Hypothesis 11: use a source-level next-group label for the type mismatch and body tail. The original emits cmp/je body, a mismatch advance, and one shared sentinel test; this tests explicit common-tail ownership without duplicate updates.
probe 45 control-flow; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 12: express the final guards as two explicit early returns. The original sends both zero-ungrouped and nonpositive-workingArea paths to one shared epilogue; this tests natural return-tail ownership.
probe 47 control-flow; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 13: express the second-pass list as a natural for initializer/condition/update. The original has a group initialization, one sentinel condition, and a shared group->next update; this tests for-loop lowering against the baseline while(1) scaffold. [same emitted code as probe 28]
probe 49 liveness; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 14: hoist bestDifference to function scope. Original carries one difference value across the first and fallback group scans in the same stack home; the current nested declaration may split its lifetime.
probe 51 liveness; result=MISMATCH; diff=3056; shape=72.72727272727273: Hypothesis 15: use one function-scope group cursor across commander repair, type passes, and final selection. Original reuses EDI/EBP for group cursors while the baseline has separate block-local owners; this tests source ownership and register basin.
```
<!-- end-recovered:9751c4c658a5020948f0 -->

<!-- recovered:514fc0f9f3ef306a8b83 -->
### `3789ccb1ae1e` `src/scratch/004FC500_fillSoldierGroups.cpp:2-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004FC500 TribeTacticalAIModule::fillSoldierGroups
// Baseline reconstruction: the embedded TacticalAIGroup at +0x9D4 owns the
// circular list sentinel; workingArea at +0xD48 is a ManagedArray<int> with
// value/numberValue/desiredNumberValue/maximumSizeValue at +0/+4/+8/+C.
// The function first repairs commander assignments, then fills type 100-102
// groups from ungrouped soldiers, redistributes excess soldiers, and finally
// assigns any remaining ungrouped soldiers to eligible groups.
//
// Attempt log:
// - baseline source is the period-plausible group-list/ManagedArray model; the
//   repeated growth and removal blocks are kept inline because the original
//   emits the canonical utmarray.h operator[]/remove shapes at each use site.
// - restored the commander-zone object/currentZone filter in both fill paths
//   and both excess-redistribution paths; the call set and frame then aligned.
// - added the binary-observed inUse gate before selecting a commander for an
//   underfilled group.
// - kept the initial sentinel walk scoped, and used guarded do/while list
//   traversal for the type loop and the final soldier redistribution scan.
// - matched desiredNumberUnits-before-numberUnits ordering in the final group
//   chooser and preserved its two-stage same-zone/capacity selection.
// - tested the packet-supported separate type-pass iterator; VC5 kept the same
//   bytes, but the named iterator remains the clearer source model.
// - made the final selected and fallback paths use branch-local ManagedArray
//   subscripts into one shared unit value. VC5 kept both growth/delete arms and
//   one shared addUnit tail, matching the original topology.
// - restored the first fill branch order from the binary: direct same-zone fill
//   when ungrouped <= missing, then nearest fill when the group remains short.
//   Reused the desired/number locals for the later missing calculation.
// - modeled the second type pass with explicit group/sentinel locals and the
//   observed store to bestGroup before its sentinel/null checks. The source
//   emits the same 122-call set and exact frame, but VC5 keeps group in EAX and
//   reloads it where the original keeps group in EBP.
// - tested 22 distinct hypotheses across control flow, liveness, layout,
//   class context, and compare spelling. The best clean result is 3523/3554
//   bytes, exact frame and 122/122 calls, 90.16% call alignment, 72.73% shape,
//   and 3056 positional-diff bytes. Remaining drift starts at +0xC2 in the
//   second group-loop register/CFG basin. Direct member spelling, base context,
//   register storage, and sentinel address variants were codegen duplicates.
// - follow-up probes 23-51 tested an early type-mismatch advance, shared and
//   natural sentinel loop forms, split final guards, final cursor ownership,
//   final-pass local scope, and a function-scope group cursor. The probes did
//   not improve the clean source. Several forms changed size or call order;
//   all were restored.
// - final clean validation remains 3523/3554 bytes, exact 0x20 frame,
//   122/122 calls, 90.16% call alignment, 72.73% shape, and 3056 positional
//   diff bytes. No accepted drift is supported by the measured residue.
```
<!-- end-recovered:514fc0f9f3ef306a8b83 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
