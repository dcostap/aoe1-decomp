# Recovery journal: 004F95B0 `highLevelTaskGatherer`

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


<!-- recovered:93f7251856eafcf7a5b1 -->
### `d050eea3c` `src/taitacmd.cpp:9717-9717`

Mapping: `ambiguous`. next mapped function definition is highLevelTaskGatherer at old line 9800.

```text
// - Main-agent audit restored canonical polymorphic object/player/world/AI
```
<!-- end-recovered:93f7251856eafcf7a5b1 -->

<!-- recovered:9052a043c95edbb67d1d -->
### `6a2aef2e2` `src/taitacmd.cpp:8408-8413`

Mapping: `strong`. next mapped function definition is highLevelTaskGatherer at old line 8468.

```text
//   typed explorer predicate: world->object, repeated UnitAI calls, current
//   action/order checks, held-attribute gate, and taskExplorer(this,id,mode).
// - Member-left positive held-attribute rejection recovered the original x87
//   compare/branch. Nesting the final object->unitAI()->hasOrderOnQueue(0x2C1)
//   call restored VC5's push-before-object evaluation order and matched exactly.
//   ownership; exact bytes were revalidated after promotion.
```
<!-- end-recovered:9052a043c95edbb67d1d -->

<!-- recovered:615aad8495f61c9d1cfc -->
### `target-session` `build/target_sessions/004F95B0_highLevelTaskGatherer.json:1-41`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 liveness; result=MISMATCH; diff=944; shape=68.83852691218131: Hypothesis 1: taskResult is uninitialized until the age-3 task call; remove its unsupported entry zero store to recover the original local frame and shipped invalid-path behavior.
probe 3 layout; result=MISMATCH; diff=876; shape=74.5042492917847: Hypothesis 2: the original owns both distribution arrays through one desired pointer and compares desired[-4] to *desired; this preserves the observed D68/D78 paired cursor and avoids compiler pointer-difference lowering.
probe 4 liveness; result=MISMATCH; diff=876; shape=74.5042492917847: Hypothesis 3:  should preserve the read-only unit id in the original EBX color across the scan and task calls, as VC5 permits for non-address-taken parameters. [same emitted code as probe 3]
probe 5 liveness; result=MISMATCH; diff=876; shape=74.5042492917847: Hypothesis 4: reorder locals to the decompiler/PDB lifetime order (gatherer, timestamp, object, AI, result, counters, pointers, index, tried array) to recover original EBX/EBP/ESI/EDI coloring without compiler-steering forms. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=879; shape=74.22096317280453: Hypothesis 5: source initialization order is triedTasking[1..3] then taskResult, matching PDB/assembly stores split by the number-gatherers compare; test whether it restores the original five-word local placement.
probe 7 control-flow; result=MISMATCH; diff=688; shape=78.86904761904762: Hypothesis 6: route only the assembly-proven shared-return arms (actions 25A/26A, order priority 100, action 265/261, and distribution task success) to one late success label while retaining direct returns at 258, held-resource, farmer, order 2BE, and the first task call.
probe 8 liveness; result=MISMATCH; diff=934; shape=72.61904761904762: Hypothesis 7: keep the found UnitData pointer live across timestamp, task, and fallback phases, matching original EBP-based gatherer accesses instead of recomputing this->gatherers[i].
probe 9 control-flow; result=MISMATCH; diff=943; shape=77.19298245614036: Hypothesis 8: the initial gatherer scan is a positive-count guarded do-loop with pointer setup inside the guard, matching the original jle-before-LEA and post-body index/pointer updates.
probe 10 liveness; result=MISMATCH; diff=688; shape=78.86904761904762: Hypothesis 9: place the four-word tried array before the gatherer object local so VC5 can coalesce tried[0] with the proven gathererObj stack slot at entry-relative -0x14 while retaining tried[1..3] at -0x10..-0x8. [same emitted code as probe 7]
probe 11 control-flow; result=MISMATCH; diff=590; shape=78.44827586206897: Hypothesis 10: express object and UnitAI validation as one positive nested guard, so both null failures branch to the late common zero-return tail at 999E instead of compiler-duplicating a local failure epilogue.
probe 12 layout; result=MISMATCH; diff=484; shape=79.82708933717579: Hypothesis 11: spell the proven task-capacity predicate as data2 > data3, making VC5 load the target count before deriving the indexed gatherer pointer as in the original 9782 block.
probe 13 control-flow; result=MISMATCH; diff=490; shape=82.73809523809524: Hypothesis 12: the age-3 pretask success shares the final normal return block at 9983, so route it to an explicit normal_success label instead of emitting an early epilogue.
probe 14 liveness; result=MISMATCH; diff=478; shape=82.14285714285714: Hypothesis 13: taskGatherer results used only as predicates stay in the call result register; only the age-3 pretask assigns taskResult because the original later rereads its initialized home on the skipped path.
probe 15 liveness; result=MISMATCH; diff=478; shape=82.14285714285714: Hypothesis 14: declare the long-lived age-3 result after the tried array and loop locals, matching the original separate high local_4 at entry-relative -0x4 instead of coalescing it with the object slot. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=478; shape=82.14285714285714: Hypothesis 15: explicitly reuse the dead id parameter home for the tried-array pointer phase, reflecting the original 97FF store/reload at the incoming id coordinate. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=915; shape=78.27380952380952: Hypothesis 16: preserve the found gatherer pointer for distribution and age task calls after the loop counter is reset; original assembly uses [EBP+51C] and [EBP+4] rather than gatherers[4].
probe 18 liveness; result=MISMATCH; diff=945; shape=77.51479289940828: Hypothesis 17: preserve the found gatherer index separately from the four-way distribution loop index, preventing final calls from reading gatherers[4] and allowing VC5 to retain the original gatherer identity.
probe 19 liveness; result=MISMATCH; diff=954; shape=78.04154302670624: Hypothesis 18: use the found gatherer pointer only for age-3 and final task calls, where original bytes explicitly reload gatherer->id after the distribution counter reaches four; leave the inner scan source unchanged.
probe 20 liveness; result=MISMATCH; diff=915; shape=78.27380952380952: Hypothesis 20: retain the found UnitData index and use a separate four-way loop counter, with the found gatherer pointer for all later task calls; this models the original distinct iVar8 versus distribution counters and avoids gatherers[4]. [same emitted code as probe 17]
probe 21 context; result=MISMATCH; diff=478; shape=82.14285714285714: Hypothesis 21: the target needs only the reviewed float global, not the broad game_globals header context; replace the SDK-heavy include with a local extern to test translation-unit codegen state.
probe 22 liveness; result=MISMATCH; diff=421; shape=83.92857142857143: Hypothesis 22: explicitly re-anchor the found gatherer pointer after the first task branch, then use it in the four-way and age phases; this preserves the proven final gatherer identity without extending the scan pointer lifetime.
probe 23 layout; result=MISMATCH; diff=803; shape=77.38095238095238: Hypothesis 23: model the binary-proven overlap between gathererObj and triedTasking[0] as one typed union, while keeping the four flag words and result local in their observed stack window.
probe 25 layout; result=MISMATCH; diff=944; shape=84.52380952380952: Hypothesis 24: touch triedTasking[0] to force VC5 to allocate the complete four-word array at the proven object-overlap base; the dead store may be removed while fixing the flag cursor offset.
probe 26 liveness; result=MISMATCH; diff=421; shape=83.92857142857143: Hypothesis 25: move the tried array after gathererObj in the local declaration order so VC5 may place the object at the observed -0x14 slot and flags at -0x10..-0x8. [same emitted code as probe 24]
probe 28 liveness; result=MISMATCH; diff=460; shape=80.6547619047619: Hypothesis 1: initialize all four triedTasking words and test the age-3 task call directly, removing the unsupported separate taskResult lifetime. This tests the target's four zero stores and age-3 result register shape.
probe 30 liveness; result=MISMATCH; diff=426; shape=82.73809523809524: Hypothesis 2: reverse the distribution-cursor assignment order, materializing the tried-array cursor after desiredGathererDistribution. The target emits the tried LEA before desired storage, so this tests whether VC5 schedules the two live cursors in the target homes.
probe 32 liveness; result=MISMATCH; diff=421; shape=83.92857142857143: Hypothesis 3: swap only the declarations of desired and tried while preserving statement order. This tests whether VC5 declaration liveness colors the two observed pointer homes without adding aliases or raw steering. [same emitted code as probe 27]
probe 34 liveness; result=MISMATCH; diff=421; shape=83.92857142857143: Hypothesis 4: move the age-3 result declaration before gathererObj and the tried array. This tests whether the extra scalar consumes the target's low local slot and shifts gathererObj to the proven object/desired cursor home. [same emitted code as probe 32]
probe 36 liveness; result=MISMATCH; diff=421; shape=83.92857142857143: Hypothesis 5: use a branch-local taskObject alias for the two distribution action checks. This tests whether the target's reload into EDI reflects a short-lived object receiver rather than the long-lived gathererObj variable. [same emitted code as probe 34]
probe 38 layout; result=MISMATCH; diff=423; shape=83.33333333333333: Hypothesis 6: replace the two explicit distribution cursors with direct typed array indexing and one natural task-count loop. This tests whether the target's EBX task counter and EDX/EAX cursor homes come from VC5's indexed lowering rather than named cursor locals.
probe 40 behavior; result=MISMATCH; diff=953; shape=80.6547619047619: Hypothesis 7: preserve the binary-observed age-3 pretask call as a discarded return, then test the initialized taskResult local. The target stores tried[1] and reloads another local instead of testing the call result.
probe 42 control-flow; result=MISMATCH; diff=421; shape=83.92857142857143: Hypothesis 8: use the existing task variable as the distribution loop bound and remove the duplicate i increment. This tests the target's single EBX task counter without adding a compiler-only lifetime. [same emitted code as probe 36]
probe 44 layout; result=MISMATCH; diff=944; shape=84.52380952380952: Hypothesis 9: group the four contiguous flag/result words in one typed local aggregate and reuse its fourth word for taskResult. The target proves a contiguous four-word stack window with the late result home overlapping the flag region. [same emitted code as probe 25]
probe 46 layout; result=MISMATCH; diff=478; shape=81.54761904761905: Hypothesis 10: carry gathererObj through triedTasking[0] and reload that proven stack-carried pointer for distribution action checks. The target stores the object pointer in the local window and reloads it before the 0x265/0x261 calls.
probe 48 control-flow; result=MISMATCH; diff=761; shape=78.59154929577464: Hypothesis 11: replace the explicit shared success label with natural early returns. This tests whether VC5 tail-merges the action/distribution success arms into the target's late 0x998F return block.
probe 50 control-flow; result=MISMATCH; diff=920; shape=83.33333333333333: Hypothesis 12: place gatherer-array setup inside an explicit positive-count guard with a natural do-loop. The target's jle precedes the gatherer LEA, proving setup occurs only after the count test.
probe 52 liveness; result=MISMATCH; diff=418; shape=84.22619047619048: Hypothesis 13: initialize taskResult before the three tried flags. This tests whether the target's first zero store is the long-lived result home and whether source statement order controls the prologue store schedule.
probe 53 liveness; result=MISMATCH; diff=418; shape=84.22619047619048: Hypothesis 14: combine taskResult-first initialization with an early taskResult declaration. Probe 13 moved only the store order; this tests whether declaration position shifts the result home from [esp+14] to the target [esp+18]. [same emitted code as probe 52]
probe 54 liveness; result=MISMATCH; diff=418; shape=84.22619047619048: Hypothesis 15: move taskResult initialization into its declaration while retaining the target-like statement order for the three flags. This tests declaration-time initialization as the source of the first prologue store. [same emitted code as probe 53]
probe 55 control-flow; result=MISMATCH; diff=430; shape=83.03571428571429: Hypothesis 16: swap the source order of success and normal_success labels. The target tail orders normal success, success-one, then failure, while the clean compiler output orders success-one before normal success.
probe 56 control-flow; result=MISMATCH; diff=432; shape=84.22619047619048: Hypothesis 17: model the age/final tail as one taskResult state: skip the normal task when the age-3 pretask succeeds, assign the normal call result to taskResult, then conditionally call fallback. This follows the target's line-8208/8218 test blocks.
```
<!-- end-recovered:615aad8495f61c9d1cfc -->

<!-- recovered:e73b276a32bb9dece9b7 -->
### `3789ccb1ae1e` `src/scratch/004F95B0_highLevelTaskGatherer.cpp:2-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004F95B0 TribeTacticalAIModule::highLevelTaskGatherer
// taitacmd.cpp: 7988-8225
// Attempt log:
// - Prior worker left a broad raw-offset reconstruction (885B rebuilt, 24/32
//   calls).  The source was reset to the same-TU typed tactical-AI surface
//   before further code-generation work.
// - Baseline candidate: named UnitData/gatherer ownership, the real world /
//   object / UnitAI member calls, resource-AI member call, and the natural
//   four-distribution task loop.  The five-word tried array models the binary's
//   object slot at element zero and four task flags at elements one through
//   four; the fallback passes element one as the output flag array.
// - Baseline check: 32/32 ordered calls and the 0x18 frame were recovered, but
//   the clean typed candidate is 910B versus 1018B (50.30% shape, 934 strict
//   diff bytes); the remaining structural gap is return/block topology.
// - Probes: reducing the scan to a four-word flag array improved frame-local
//   layout but did not change the 910B basin; a typed object/flag union and
//   shared failure/success labels were diagnostic variants only.  The union
//   reached 900B/926 diff bytes but lost the proven 0x18 frame and was rolled
//   back.  All typed variants kept the complete 32-call multiset/site order.
// - Left in scratch: canonical typed baseline, unresolved broad VC5 block
//   layout and duplicated-epilogue topology; no accepted drift.
// - Direct indexed/typed gatherer fields recovered the original folded
//   this-relative addressing and raised shape to 66.39%; a named gatherer
//   pointer had better register coloring but wrong field displacements.
// - Initializing taskResult with triedTasking[1..3] removed the unsupported
//   fifth flag slot and recovered most structural islands.  A shared null
//   tail improved this to 1030B/916 diff, with all 32 ordered calls aligned.
// - A shared success-tail variant was diagnostic only (937B/936 diff) and was
//   rolled back.  Remaining blocker: 0x1C versus 0x18 frame and stack-home/
//   register-color differences; checker remains in STRUCTURAL RECONSTRUCTION.
// - Replaced the raw debug-file address with the named source string. This does
//   not change code generation.
// - Continued probes: a positive object/UnitAI guard restored the late null
//   return; desired[-4] < *desired restored the paired distribution cursor.
// - Continued probes: direct task-result predicates removed false stack stores.
//   A gatherer pointer re-anchor after the first task branch restored the
//   original register colors and the strongest clean nonexact result: 962B,
//   83.93% shape, 421 strict-diff bytes, and the 0x18 frame.
// - Separate found-index, union-overlay, array-slot, and header-context probes
//   did not improve this result and were rolled back.
// - Current worker probes: taskResult-first flag initialization reduced the
//   strict diff to 418B and raised shape to 84.23% without changing the 0x18
//   frame or 32-call order. Cursor rewrites, direct indexing, object-window
//   overlays, and tail-label variants were worse or codegen duplicates.
// - The remaining structural gap is the target's late success/failure block
//   order and its one extra instruction; no supported exact source was found.
```
<!-- end-recovered:e73b276a32bb9dece9b7 -->

<!-- recovered:e848473d74425368f97a -->
### `3789ccb1ae1e` `src/scratch/004F95B0_highLevelTaskGatherer.cpp:217-217`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // BINARY NOTE: The found record remains live through all later task calls.
```
<!-- end-recovered:e848473d74425368f97a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
