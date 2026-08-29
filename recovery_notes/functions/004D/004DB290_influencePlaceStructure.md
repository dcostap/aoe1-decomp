# Recovery journal: 004DB290 `influencePlaceStructure`

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


<!-- recovered:01257156aef5883a538a -->
### `target-session` `build/target_sessions/004DB290_influencePlaceStructure.json:1-49`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MISMATCH; diff=3558; shape=57.370892018779344: Hypothesis 1: declare scalar operator delete so /GX can emit the original construction cleanup handler and frame.
probe 2 liveness; result=MISMATCH; diff=3597; shape=57.03564727954972: Hypothesis 2: remove the long-lived masterObj alias and use direct master_objects[x] expressions, allowing VC5 to reuse the first four buildingName bytes as original assembly does.
probe 3 layout; result=MISMATCH; diff=3597; shape=56.94183864915572: Hypothesis 3: correct RGE_Player::world to +0x3c, matching the original available-time load through player +0x3c.
probe 4 behavior; result=MISMATCH; diff=3569; shape=59.28705440900563: Hypothesis 4: separate coordinate fallback from currentZone receiver. Original uses townCenter, then builder, then placement for coordinates, but townCenter then placement for currentZone.
probe 5 liveness; result=MISMATCH; diff=3569; shape=59.28705440900563: Hypothesis 5: route all PlacementState field accesses through one pointer alias to reproduce the original early state-pointer register and stack homes.
probe 6 control-flow; result=MISMATCH; diff=3506; shape=59.53051643192488: Hypothesis 6: remove actualBuilderID and express the active/inactive builder object calls directly, matching the original branch-local push sources.
probe 7 control-flow; result=MISMATCH; diff=3620; shape=62.68382352941177: Hypothesis 7: route the loop timeout and unsupported-size exits to late labels, because original places their second strncpy and logCommonHistory blocks after the candidate-result path.
probe 8 control-flow; result=MISMATCH; diff=3504; shape=64.13145539906104: Hypothesis 8: remove the duplicated state writes after moving the loop timeout to its late label, preserving the original three strncpy call count.
probe 9 control-flow; result=MISMATCH; diff=3565; shape=59.248826291079816: Hypothesis 9: reverse the late label source order to test VC5's cold-block placement; original emits second timeout strncpy before unsupported-size logging.
probe 10 behavior; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 10: restore the binary-proven size-3 placement dispatch; placements outside 6,3,4,1,2,8 use the size-5 clear bounds.
probe 11 liveness; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 11: remove the state-pointer alias after later branch edits; direct reference member expressions may restore original this/state/item register colors.
probe 12 liveness; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 12: scope placementRadius inside placement-1 handling, matching its binary-only use and reducing false long-lived liveness. [same emitted code as probe 11]
probe 13 liveness; result=MISMATCH; diff=3425; shape=67.35266604303087: Hypothesis 13: remove coordinateObject and use direct townCenter/builder/placement receiver branches, matching the original three receiver tests without a persistent alias.
probe 14 liveness; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 14: scope ConstructionItem result locals only around each construction path instead of keeping one function-scope result home. [same emitted code as probe 10]
probe 15 abi; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 15: use the reviewed inherited AIModule::logCommonHistory(char*, ...) varargs surface instead of a free extern shim.
probe 16 control-flow; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 16: remove the unsupported no-op self-assignment at the connection early-exit label; it is not a natural source operation. [same emitted code as probe 15]
probe 17 abi; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 17: use the binary-decompiler int type for firstTimeThrough instead of ulong; both are four bytes but signedness may control timeout comparisons. [same emitted code as probe 16]
probe 18 liveness; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 18: scope masterObj inside the proven non-null master branch while retaining one typed pointer for the virtual placement call. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 19: declare blocked before score so VC5 can assign blocked to EBX and score to EBP, matching the original inner-map loop registers.
probe 20 liveness; result=MISMATCH; diff=3480; shape=67.13615023474179: Hypothesis 20: reorder placement and placementType declarations to test the binary-supported VC5 declaration-order register basin. [same emitted code as probe 18]
probe 22 control-flow; result=MISMATCH; diff=3478; shape=67.2300469483568: Hypothesis 1: reverse the inactive item branch so item != 0 is fall-through and the null-item data path is the taken branch, matching original +0099 test polarity and call block order.
probe 23 control-flow; result=MISMATCH; diff=3544; shape=68.19887429643528: Hypothesis 2: duplicate the natural strncpy statement in each state-active, item, and null-item arm, allowing VC5 to tail-merge the call while preserving branch-local argument setup seen at original +0079/+009d/+00c4.
probe 24 liveness; result=MISMATCH; diff=3378; shape=68.53932584269663: Hypothesis 3: replace the persistent coordinateObject alias with direct townCenter, builderObject, and placementObject receiver arms, matching the binary's branch-local coordinate loads and reducing false pointer liveness.
probe 25 control-flow; result=MISMATCH; diff=3388; shape=66.79069767441861: Hypothesis 4: keep direct coordinate receiver arms but use only the binary-supported townCenter-then-placementObject fallback, removing the builderObject coordinate arm that introduced an extra __ftol call.
probe 26 liveness; result=MISMATCH; diff=3544; shape=68.19887429643528: Hypothesis 5: scope coordinateObject inside the coordinate fallback arm, keeping one common world-coordinate conversion path while reducing its lifetime versus a function-scope alias. [same emitted code as probe 23]
probe 27 control-flow; result=MISMATCH; diff=3528; shape=68.63849765258216: Hypothesis 6: express the coordinate fallback as one nested conditional initializer, retaining one common conversion path without the separate assignment sequence.
probe 28 control-flow; result=MISMATCH; diff=3511; shape=69.1231343283582: Hypothesis 7: lower placement-1 age selection as direct predicate calls with radius=1 before the age-4 test, matching the Ghidra-supported original order and avoiding VC5's branchless neg/sbb lowering.
probe 29 behavior; result=MISMATCH; diff=3478; shape=68.85553470919325: Hypothesis 8: assign lookupZone's return to placement on the direct center path; original compares that result at +0240 and dispatches 1/2/3/4 handlers, while the prior source discarded it.
probe 30 abi; result=MISMATCH; diff=3488; shape=68.6623012160898: Hypothesis 9: declare lookupZone as int, not uchar; original preserves its full EAX return for the placement dispatch compare, while uchar inserted an unsupported and eax,0xff.
probe 31 control-flow; result=MISMATCH; diff=3483; shape=67.50700280112045: Hypothesis 10: restore one common strncpy after the item-selection arms, as the Ghidra source shape and single original call support, while retaining the corrected item fall-through and lookupZone dispatch.
probe 32 abi; result=MISMATCH; diff=3420; shape=67.76007497656983: Hypothesis 11: restore lookupZone's reviewed uchar return surface while retaining the binary-proven placement assignment, testing whether the canonical method ABI recovers the caller basin.
probe 33 liveness; result=MISMATCH; diff=3420; shape=67.76007497656983: Hypothesis 12: initialize placementRadius from the dispatch value before the age predicates; original copies EAX into the radius register before inAge(2), and the scoped uninitialized local lacked that source lifetime. [same emitted code as probe 32]
probe 36 control-flow; result=MISMATCH; diff=3551; shape=68.07511737089202: Hypothesis 13: replace only the clean source's age-4 result rewrite with direct predicate selection and an explicit radius=1 default, following the original branch topology and Ghidra semantics.
probe 37 control-flow; result=MISMATCH; diff=3546; shape=67.51173708920187: Hypothesis 14: retain the natural inAge result assignments but use a separate age4 local before radius=1/4, testing the Ghidra-supported two-local source without VC5's direct-call branch basin.
probe 39 control-flow; result=MISMATCH; diff=3478; shape=67.2300469483568: Hypothesis 15: retain only the natural item != 0 fall-through condition; original +0099 uses je for the null-item arm, while the clean item==0 spelling emitted the opposite branch topology. [same emitted code as probe 22]
probe 40 control-flow; result=MISMATCH; diff=3543; shape=66.66666666666667: Hypothesis 16: store local_154=4 before strategicNumber(0x57), matching original +02DB store-before-receiver/call setup and the Ghidra source order.
probe 41 liveness; result=MISMATCH; diff=3478; shape=67.2300469483568: Hypothesis 17: preserve strategicNumber(0x49)'s result in a block-local placementDistance before local_154, matching original EAX-to-ESI-to-home scheduling in the placement 3/4 arm.
probe 42 control-flow; result=MISMATCH; diff=3510; shape=67.98122065727699: Hypothesis 18: inline the unsupported-size log and cleanup at its size branch, matching the decompiler's nested else instead of an explicit goto label that VC5 moved into an early cold block.
probe 43 liveness; result=MISMATCH; diff=3478; shape=67.2300469483568: Hypothesis 19: keep one function-scope ConstructionItem result home, matching Ghidra's pCVar15 and testing whether the shared allocation result restores the original frame and cleanup lifetime.
probe 45 behavior; result=MISMATCH; diff=3480; shape=67.2300469483568: Hypothesis 1: restore original direct-coordinate ordering around placementCode and correct RGE_Player::world to +0x3c, preserving the proven player reread and lookupZone fault order.
probe 46 layout; result=MISMATCH; diff=3478; shape=67.32394366197182: Hypothesis 2: correct only RGE_Player::world to the binary-proven +0x3c field while retaining the pinned direct-coordinate source order.
probe 47 control-flow; result=MISMATCH; diff=3480; shape=67.2300469483568: Hypothesis 3: defer direct centerX and minimumDistance assignments until after placementCode, matching the PDB line bands and original lookupZone fault order. [same emitted code as probe 45]
probe 49 liveness; result=MISMATCH; diff=3544; shape=67.69953051643192: Hypothesis 5 compile result: separate age-4 predicate and radius initialization changed code to 3838 bytes, 3544 diff, 67.70% shape; calls stayed 55. Worse positional result; restore this axis.
probe 50 control-flow; result=MISMATCH; diff=3552; shape=21.877934272300468: Hypothesis 6: restore the original item-null outer split so setupInfluenceMap precedes the item availableLot arm, preserving candidate setup order and fault order.
probe 51 liveness; result=MISMATCH; diff=3480; shape=67.2300469483568: Hypothesis 8: declare placementObject first, matching the original this_00 object lifetime and its early receiver ownership, then test pointer and coordinate stack-home recovery. [same emitted code as probe 47]
probe 52 liveness; result=MISMATCH; diff=3428; shape=67.69953051643192: Hypothesis 9: remove the cached coordinateObject alias and use direct townCenter/builderObject/placementObject rereads, matching the original object fault order and avoiding unsupported pointer liveness.
probe 53 liveness; result=MISMATCH; diff=3480; shape=67.2300469483568: Hypothesis 10: apply period  to the read-only BuildItem parameter to test the binary item/state register-color basin without changing calls or behavior. [same emitted code as probe 51]
probe 54 control-flow; result=MISMATCH; diff=3514; shape=67.98122065727699: Hypothesis 12 compile result: inline unsupported-size logging was tested with a repaired scope; compare its branch topology and call placement.
probe 56 control-flow; result=MISMATCH; diff=3575; shape=66.57276995305165: Hypothesis 13: route unsupported-size logging through a shared placement_fail label, matching the original cold log block's jump into the common active=0 tail.
```
<!-- end-recovered:01257156aef5883a538a -->

<!-- recovered:eb1e2910da59ab468130 -->
### `fc4b000c6e8f` `src/scratch/004DB290_influencePlaceStructure.cpp:1-35`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004DB290 TribeInformationAIModule::influencePlaceStructure
// PDB: taiinfmd.cpp:2532-3206
//
// Attempt log:
// - baseline reconstruction: named information-AI, PlacementState, InfluenceMap,
//   building-lot, and master-building ownership; /GX new ConstructionItem paths;
//   ordered placement/zone/map-bound calls and nested candidate scans.
// - This claim tested 20 meaningful source, ABI, layout, control-flow, and
//   liveness hypotheses.  A diagnostic branch variant reached 3,425 diff bytes.
// - The current source is the best natural reconstruction after the probes.
//   It emits 3,834 of 3,868 bytes, 55 calls, and 67.32% shape similarity.
// - The source keeps /GX, the +0x3c player world field, and the inherited
//   AIModule logCommonHistory varargs surface from binary evidence.
// - A late timeout save label moves the second state strncpy near the original
//   block.  A late unsupported-size label preserves the original cold path.
// - The size-3 placement branch uses size-5 bounds for placements other than
//   6, 3, 4, 1, 2, and 8.  The original branch proves this behavior.
// - Direct builderID/state.builderID calls and separate currentZone fallback
//   receivers match the original branch order and improve call alignment.
// - Tested and rejected: direct master expressions, coordinate receiver
//   branches, state aliases, declaration scopes, label order, and ABI aliases.
// - This claim retested the item-arm polarity against the original +0099 JE;
//   `item != 0` fall-through improved the result from 3480 to 3478 bytes.
// - Rejected: duplicated branch-local strncpy calls, direct age predicates,
//   lookupZone result assignment, inline unsupported-size cleanup, and result
//   lifetime changes. They changed shape without a better natural result.
// - Focused audit: original RGE_Player::world is at +0x3c.  The +0x14 gap
//   change preserved the 55-call set and was retained as the binary-supported
//   field layout.  Direct-coordinate assignment reordering changed only the
//   local codegen basin and was restored; scalar parameter reads have no fault.
// - Removing coordinateObject added one ftol call and broke ordered-call
//   parity.  The common coordinate receiver is retained.  An explicit
//   master-null return changed the CFG without a better exact candidate.
// - Open drift: the frame is 0x188 versus 0x190.  The early register colors,
//   first cold log block, and many stack homes still differ.
```
<!-- end-recovered:eb1e2910da59ab468130 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
