# Recovery journal: 004F7590 `numberSoldiersWithPriority`

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


<!-- recovered:fbfb11335dc73a1c05ff -->
### `d050eea3c` `src/taitacmd.cpp:8247-8268`

Mapping: `ambiguous`. next mapped function definition is numberSoldiersWithPriority at old line 8346.

```text
// Probe 2: restored the period ManagedArray operator[]/add bodies, typed
// [non-comment lines omitted during migration]
//   with md->aiPlayer->world ownership. Checking the natural source next.
// Probe 3: added ordinary references to the two array members, mirroring the
// [non-comment lines omitted during migration]
// Probe 4: rewrote the inline indexer return as pointer addition; this is a
//   natural equivalent source spelling to test the two remaining SIB bytes.
// Probe 5: reversed the pointer-addition operands in the indexer return;
// [non-comment lines omitted during migration]
// Probe 6: materialized the array pointer before the indexer return to test
// [non-comment lines omitted during migration]
// Probe 7: restored the compact non-polymorphic local type context used by
//   the exact same-TU ManagedArray donor; the proven field offsets remain
// [non-comment lines omitted during migration]
// Probe 8: focused six-way indexer-return lab; every natural pointer/member
//   spelling stayed in the same two-byte SIB basin.
// Probe 9: focused ensure-then-direct-value lab; the explicit inline growth
//   spelling also stayed in the same two-byte SIB basin.
// Probe 10: restored the canonical indexer return and added the donor-TU
//   <stdlib.h> context as the final translation-unit hypothesis.
```
<!-- end-recovered:fbfb11335dc73a1c05ff -->

<!-- recovered:848f978891626f2af178 -->
### `6a2aef2e2` `src/taitacmd.cpp:7210-7221`

Mapping: `strong`. next mapped function definition is numberSoldiersWithPriority at old line 7261.

```text
// Counts soldiers whose UnitAIModule is idle and records them in workingArea.
//
//   9 calls; helper shims lost the two unitAI calls and all three original
//   decorated member-call identities. Canonical fields were nevertheless the
//   soldiers and workingArea ManagedArray<int> members.
//   RGE_Game_World::object, RGE_Static_Object::unitAI, and UnitAIModule calls,
//   exact same-TU numberUngroupedSoldiers source so the reset precedes the
//   soldiers count load and indexed member expressions retain their address
//   term order.
//   retained only as a focused address-term experiment.
//   whether a natural local pointer changes VC5's base/index encoding.
//   unchanged while testing whether class vptr context affects SIB encoding.
```
<!-- end-recovered:848f978891626f2af178 -->

<!-- recovered:a1af5e84d06edd4c28b4 -->
### `6a2aef2e2` `src/taitacmd.cpp:7412-7458`

Mapping: `ambiguous`. comment lies after mapped function numberSoldiersWithPriority at old line 7261.

```text
// taitacmd.cpp: 6953-7056
//   and priority branches into helpers (752B); the packet instead shows two
//   long, source-level near-duplicate loops and the real resize/contains ABI.
//   this->unitsTaskedThisUpdate ownership, the binary's three priority modes, and
//   repeated-loop register and stack-home topology is audited.
// - Duplicating the three warboat priority append arms recovered their six
//   missing resize/contains sites; restoring the negative soldier arm and
//   sharing its binary-proven workingArea tail recovered the full 47-call
// - Separate Ghidra-backed soldier scan variables did not change emitted
//   code.  Left unresolved: source/context needed to keep this in ebp/ebx
// - Reversed the soldier append forms to match the binary call order: the
//   equality arm scans workingArea, while the greater-priority arm uses
//   contains.  This restored the ordered 47-call surface.
// - Using local_8 as the proven byte offset in the warboat tasked-unit test
//   reduced the frame from 0x14 to 0x10.  The remaining prologue still uses
// - A direct workingArea.numberValue store in the greater arm preserves all
//   47 calls.  A separate pointer alias and declaration reorder had no effect.
// - Reordered each dispatch as negative, greater, equal to match the target's
//   jge/jle block layout.  This reduced the size gap to 24 bytes and raised
//   shape similarity, but the compiler merged three warboat append calls.
// - Keeping the binary-backed byte-offset load only in the negative warboat
//   arm restores all 47 calls and gives the best clean structural result:
//   1383 bytes, 67.37% shape, and 23.02% exact-block coverage.  Applying the
//   offset spelling to all arms merges the same calls and loses three calls.
//   duplicates.  Remaining structural gap is target ebp/ebx allocation and
//   an 83-byte tail.
//   `index >= maximum`.  This matches the original CMP operand order, raises
//   shape similarity to 68.53%, and raises exact-block coverage to 31.41%.
//   parameter.  This matches the original CMP operand order, raises shape to
//   70.16%, and raises exact-block coverage to 37.17%.
//   shape and resynchronization, but lost two required calls and the 0x10
//   ordered calls, 70.16% shape, 37.17% exact-block coverage, 1295 strict
//   differing bytes.  The remaining lead is the target EBP/EBX register and
//   stack-home topology, then the 83-byte structural tail.
// MANAGEDARRAY AUDIT: resize, contains, capacity guards, duplicate scans,
// append publication, count increments, and field offsets use the expected
// ABI on both warboat and soldier paths. No shared template change is needed.
//
// - Canonical polymorphic AI/object/master declarations, template
//   ManagedArray<int>, the target-class vptr, and the RGE object id field did
//   two required contains/resize call sites and produced 45 calls. Inline
//   contains and branch-local result pointers did not prevent that merge.
// - Separate array scopes, register-qualified local_c, soldiers/warBoats
// - A workingArea reference moved this to EBX and a 0x14 frame. A count-based
//   greater-arm append restored 47 calls but grew the body to 1463 bytes.
//   frame, 47/47 ordered calls, 70.16% shape, 37.17% exact-block coverage,
//   the target EBP/EBX topology or broad tail CFG.
```
<!-- end-recovered:a1af5e84d06edd4c28b4 -->

<!-- recovered:a7351f07f4f97e1a87c9 -->
### `target-session` `build/target_sessions/004F7590_numberSoldiersWithPriority.json:1-41`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=647; shape=73.38709677419355: Baseline current scratch reconstruction before new probes; compare exact size, frame, call order, and block map.
probe 2 variant; result=MISMATCH; diff=769; shape=43.95161290322581: Hypothesis 1: remove self and member-reference aliases; use direct typed this-member expressions to test whether original aliases were compiler artifacts.
probe 4 liveness; result=MISMATCH; diff=661; shape=74.59677419354838: Hypothesis 2: scope self, soldiers, and workingArea aliases inside the positive count guard; test whether original delayed aliases after the outer test.
probe 5 liveness; result=MISMATCH; diff=683; shape=62.5: Hypothesis 3: keep only a scoped soldiers alias and direct workingArea accesses; test whether persistent working alias caused result/register drift.
probe 7 liveness; result=MISMATCH; diff=649; shape=73.38709677419355: Hypothesis 4: declare result before self and array references, matching exact sibling counter declaration order to test EBX/EDI/EBP coloring.
probe 9 control-flow; result=MISMATCH; diff=801; shape=73.38129496402878: Hypothesis 5: restore period do-while duplicate scans with an explicit max break, instead of combined bounded for conditions, to match observed two-test scan CFG.
probe 11 variant; result=MISMATCH; diff=808; shape=43.77104377104377: Hypothesis 6: replace manual negative/positive append tails with the period inline ManagedArray::add surface; test whether compiler inlining recovers shared scan/append topology.
probe 13 liveness; result=MISMATCH; diff=732; shape=81.0077519379845: Hypothesis 7: make workingArea references branch-local in each priority arm, matching original repeated LEA of workingArea and avoiding one persistent alias.
probe 14 liveness; result=MISMATCH; diff=730; shape=81.0077519379845: Hypothesis 8: in branch-local workingArea model, declare result before self and soldiers to test natural callee-save color swap toward original EBX=self and EDI=result.
probe 15 liveness; result=MISMATCH; diff=730; shape=81.0077519379845: Hypothesis 9: remove the persistent self alias while retaining soldiers and branch-local workingArea references; test whether direct this ownership restores original self/result register use. [same emitted code as probe 14]
probe 17 liveness; result=MISMATCH; diff=732; shape=81.0077519379845: Hypothesis 10: combine branch-local workingArea references with a function-scope object temporary; test whether original object and self lifetimes prevent register reuse. [same emitted code as probe 13]
probe 20 control-flow; result=MISMATCH; diff=647; shape=73.38709677419355: Hypothesis 11: use a top-tested while loop under the positive soldier-count guard, testing whether original bottom rotation came from while rather than do-while source. [same emitted code as probe 1]
probe 22 control-flow; result=MISMATCH; diff=647; shape=73.38709677419355: Hypothesis 12: express the outer scan as a header-updated for loop, with nextSoldier falling through to the loop update, to test source update placement. [same emitted code as probe 20]
probe 24 control-flow; result=MISMATCH; diff=648; shape=69.56521739130434: Hypothesis 13: model the busy-list duplicate scan as a do-while with an explicit maximum break, matching its observed test order while leaving working scans unchanged.
probe 26 abi; result=MISMATCH; diff=647; shape=73.38709677419355: Hypothesis 14: restore exact same-TU donor operator_new/operator_delete C++ declarations instead of extern-C wrappers; test relocation and ABI identity.
probe 28 liveness; result=MISMATCH; diff=686; shape=73.79032258064517: Hypothesis 15: use direct this->workingArea only for the reset store while retaining aliases in later arms; test whether original early store timing prevents a persistent alias.
probe 30 liveness; result=MISMATCH; diff=647; shape=73.38709677419355: Hypothesis 16: use natural postfix result increments at both count sites instead of expanded addition, testing VC5 increment lowering and local home choice. [same emitted code as probe 22]
probe 32 liveness; result=MISMATCH; diff=732; shape=81.0077519379845: Hypothesis 17: use branch-local workingArea aliases and declare working count before soldier value, matching original negative/positive load order. [same emitted code as probe 17]
probe 35 behavior; result=MISMATCH; diff=649; shape=72.8: Hypothesis 18: place countedSoldier inside the valid-object/unitAI block; original null guards jump directly to iteration, while duplicate/accepted paths alone increment the result.
probe 36 control-flow; result=MISMATCH; diff=678; shape=92.03187250996017: Hypothesis 19: retain the corrected valid-object counting scope but share one negative/positive working-area append tail through a local value/number and common label, matching original 7750 join.
probe 37 liveness; result=MISMATCH; diff=678; shape=92.03187250996017: Hypothesis 20: swap shared-tail value/number declaration order to test original EBX value, ECX count, EDI working pointer coloring. [same emitted code as probe 36]
probe 38 liveness; result=MISMATCH; diff=354; shape=93.95161290322581: Hypothesis 21: delay the soldiers alias until after the outer count guard while retaining shared append tail; original sets ESI only after the guard.
probe 39 liveness; result=MISMATCH; diff=672; shape=68.95161290322581: Hypothesis 22: use direct this->workingArea only in the shared append tail, testing whether the original self reload plus LEA owner form is source-driven.
probe 40 liveness; result=MISMATCH; diff=353; shape=93.54838709677419: Hypothesis 23: assign shared-tail working count before soldier value in both arms, matching original count-before-value load sequence.
probe 41 liveness; result=MISMATCH; diff=682; shape=62.096774193548384: Hypothesis 24: remove the persistent workingArea reference and use direct typed member accesses throughout the corrected shared-tail source.
probe 42 liveness; result=MISMATCH; diff=656; shape=77.01612903225806: Hypothesis 25: use a branch-assigned ManagedArrayInt* area pointer for duplicate scans and the shared append tail, matching repeated original working-area LEAs.
probe 45 liveness; result=MISMATCH; diff=786; shape=40.61302681992337: Hypothesis 26: mirror the complete PDB/Ghidra source shape: soldiers pointer, do-while bounded scans, direct workingArea accesses in negative/positive arms, and local working-area pointer only for zero-priority contains.
probe 47 liveness; result=MISMATCH; diff=353; shape=93.54838709677419: Hypothesis 27: remove only the persistent self alias while retaining the workingArea reference and soldiers reference, to let VC5 reload this after object-pointer clobber. [same emitted code as probe 44]
probe 48 liveness; result=MISMATCH; diff=682; shape=62.096774193548384: Hypothesis 28: remove the persistent workingArea reference and use direct this->workingArea fields, testing whether direct member ownership recovers original reload and register colors. [same emitted code as probe 41]
probe 50 liveness; result=MISMATCH; diff=353; shape=93.54838709677419: Hypothesis 29: retain the persistent this and workingArea aliases but model the soldier collection as a pointer, matching the original Ghidra this_00 owner surface. [same emitted code as probe 47]
probe 52 liveness; result=MISMATCH; diff=712; shape=81.45161290322581: Hypothesis 30: use branch-local working-area references after the observed negative and positive number/value loads, with direct this->workingArea in the shared append tail.
probe 54 liveness; result=MISMATCH; diff=698; shape=64.51612903225806: Hypothesis 31: retain natural top-level this and soldiers aliases, but make value/number/index function-scope locals and keep workingArea direct except for a zero-arm pointer.
probe 56 liveness; result=MISMATCH; diff=353; shape=93.54838709677419: Hypothesis 32: use a local working-area pointer only in the zero-priority contains/append arm, matching the Ghidra this_01 ownership without changing the shared negative/positive aliases. [same emitted code as probe 50]
probe 58 control-flow; result=MISMATCH; diff=473; shape=81.88976377952756: Hypothesis 33: use the binary-shaped negative working-area do-while with an explicit capacity break, while leaving all other source structure unchanged.
probe 61 liveness; result=MISMATCH; diff=353; shape=93.54838709677419: Hypothesis 34: model workingArea as a natural ManagedArray pointer instead of a reference, matching the decompiler this_01 surface while retaining all existing loop topology. [same emitted code as probe 56]
probe 63 liveness; result=MISMATCH; diff=638; shape=82.93650793650794: Hypothesis 35: move the repeated value, working count, scan index, and zero-growth pointer to function scope, matching Ghidra's cross-arm local declarations while preserving clean control flow.
probe 65 liveness; result=MISMATCH; diff=680; shape=77.29083665338645: Hypothesis 36: use direct this->workingArea.numberValue loads in both duplicate scans, while retaining the workingArea alias for value/capacity accesses.
probe 67 control-flow; result=MISMATCH; diff=586; shape=80.1526717557252: Hypothesis 37: use the PDB/decompiler-supported explicit else-if priority < 1 dispatch instead of an implicit else.
probe 69 liveness; result=MISMATCH; diff=442; shape=93.95161290322581: Hypothesis 38: reload the soldier count through this->soldiers at the loop backedge, matching the original final mov [this+118] rather than the soldiers-pointer count read.
probe 71 liveness; result=MISMATCH; diff=353; shape=93.54838709677419: Hypothesis 39: declare the zero-arm working-area pointer before the soldier value, matching the original LEA order: area pointer, local value address, then soldier load. [same emitted code as probe 61]
probe 73 liveness; result=MISMATCH; diff=485; shape=84.4621513944223: Hypothesis 40: change only the negative-arm working count to direct this->workingArea.numberValue, matching the original D4C load while retaining the positive alias form.
```
<!-- end-recovered:a7351f07f4f97e1a87c9 -->

<!-- recovered:111afa52f289b0260973 -->
### `3789ccb1ae1e` `src/scratch/004F7590_numberSoldiersWithPriority.cpp:1-72`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004F7590 TribeTacticalAIModule::numberSoldiersWithPriority
// Attempt log:
// try 1: adapted dynamic-array/scanning shape from numberUngroupedSoldiers and packet: reset working list, scan soldiers, resolve object, filter valid/busy/grouped/priority, count unique working soldiers.
// try 2: fixed local layout for busy array near +0xD58 so source compiles.
// try 3: minimal behavioral source compiled but only 400B vs 726B.
// try 4: /Od probe still too small (584B) and wrong basin; removed.
// try 5: inlined soldier array growth at scan index like original dynamic-array pattern.
// try 6: inlined working array growth/copy/delete before adding accepted soldier.
// try 7: modeled reset flag clearing workingNumber at +0xD4C.
// try 8: modeled busy-list duplicate exclusion loop using busyValue/busyNumber/busyMaximum.
// try 9: modeled negative/positive/zero priority comparisons via UnitAI priority/taskPriority calls.
// try 10: /GX probe no size/codegen change; removed.
// left in scratch: the best source reconstruction is 833B vs original 726B;
//   ordered calls and behavior-backed array/priority topology align, but the
//   frame/prologue and several branch/register blocks remain structurally
//   unresolved, so this is not accepted_drift-safe.
// probe 11: restored the PDB-backed parameter order (threshold, priority, reset),
//   the out-of-line ManagedArray resize/contains surface, and the repeated
//   source-level priority arms shown by the original line bands.  This also
//   restores the inline operator[] only for the zero-priority soldiers read.
// probe 12: shared the binary-proven working-area append tail and restored the
//   zero-priority soldier growth as the one inline allocation/copy/delete path;
//   the other soldier reads retain the six out-of-line resize call sites.
// probe 13: laid out the positive-priority arm before the zero-priority arm,
//   matching the original inline positive block and late zero block.
// probe 14: added the period local owner used to preserve this across the
//   busy-array register reuse; no byte-stride cursor was retained yet.
// probe 15: made the repeated int-array element address an explicit proven
//   byte-stride cursor, matching the original EBP offset and zero-arm
//   allocation-size topology.
// probe 16: moved the result declaration ahead of the owner/array locals to
//   test the original EBX=this, EDI=result, EBP=offset callee-save coloring.
// probe 17: corrected the positive-arm threshold ownership and mirrored the
//   original compare operand spellings for bounds/duplicate scans.
// probe 18: restored a natural typed count loop with direct ManagedArray
//   element access; removed the byte-stride cursor and excess owner alias.
//   Result: size moved 833->832 and exact-block coverage improved, but the
//   frame stayed 0x10 and the first structural hunk remained unchanged.
// probe 19: delayed the soldiers pointer until after the count guard; frame
//   stayed exact, but the natural branch source moved to 808B and diff 719.
// probe 20: retained a local byte-size expression for the zero-arm growth;
//   it broke tail merging and added a seventh resize call. Rolled back.
// probe 22: changed busy and working duplicate scans to bounded for loops;
//   frame stayed 0xC, calls stayed aligned, and size moved to 688B with diff
//   649. Probe 23 kept the pre-loop index initialization and reached diff 647.
// probe 24: restored one shared append tail; size became exactly 726B, but
//   compiler layout moved one resize call before the positive arm.
// probe 25: placed that tail in the positive PDB band; shape improved to
//   76.10%, but the label-crossing source was not a clean original model.
// left in scratch: natural branch-local append source, 688B vs 726B, diff
//   647, exact calls and frame. The remaining structural gap is register
//   coloring, block placement, and the original shared append tail order.
// revisit probes:
// - The old countedSoldier label was outside the valid-object block.  The
//   original null object and null UnitAI paths skip the result increment, so
//   the label now stays inside that block.
// - A shared negative/positive append tail restored the original 726-byte
//   size and raised shape similarity to 92.03%; calls and frame also match.
// - Delaying the soldiers alias until after the outer count guard, then
//   assigning the working count before the soldier value, restored the exact
//   prologue and 248-instruction size.  The best current result is 353 strict
//   differing bytes, 93.55% shape similarity, and 78.63% exact-block coverage.
// - Direct working-area expressions, a branch pointer alias, an inline add
//   helper, alternate loop forms, ABI declaration changes, and local-order
//   variants were tested.  They were worse or codegen duplicates.
// MANAGEDARRAY AUDIT: resize guards, inline growth, copies, publication,
// contains bounds, append count, and field offsets match the executable. No
// shared template change is required.
// BLOCKER: After a soldier resize, the executable reads the soldier value
// pointer before the working-area count. The rebuild reads the count first.
// Soldier element and working-array reads therefore have different mutation
// and fault order.
```
<!-- end-recovered:111afa52f289b0260973 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
