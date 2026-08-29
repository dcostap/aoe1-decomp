# Recovery journal: 00535A80 `pick_multi`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.
- Earlier recovery note: `recovery_notes/view_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5f015dd88716ce26eb04 -->
### `target-session` `build/target_sessions/00535A80_pick_multi.json:1-45`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=213; shape=90.21739130434783: Retained natural typed reconstruction from prior attempts; establish current checker baseline.
probe 2 liveness; result=MISMATCH; diff=213; shape=90.21739130434783: Reuse proven incoming y1/x2 homes for second-pass count and selected object, as Ghidra and original stack writes show. [same emitted code as probe 1]
probe 4 context; result=MISMATCH; diff=213; shape=90.21739130434783: Split the proven 56-slot TPanel base from RGE_View, preserving vslots E0/E4 and +FC layout. [same emitted code as probe 2]
probe 6 liveness; result=MISMATCH; diff=213; shape=90.21739130434783: Match Ghidra declaration order: loop index before picked-any flag and function-scoped picked object. [same emitted code as probe 4]
probe 8 liveness; result=MISMATCH; diff=213; shape=90.21739130434783: Use register-qualified read-only y2 parameter to test the original y1/y2 saved-register coloring. [same emitted code as probe 6]
probe 10 control-flow; result=MISMATCH; diff=315; shape=91.30434782608695: Use explicit dx>=dy branches and if/else assignment to preserve original compare operands and branch topology.
probe 12 control-flow; result=MISMATCH; diff=212; shape=90.76086956521739: Isolate first radius compare operand order as dx>=dy while retaining baseline second arm.
probe 14 liveness; result=MISMATCH; diff=213; shape=90.21739130434783: Introduce explicit call-coordinate aliases to test whether original helper setup uses named coordinate locals. [same emitted code as probe 8]
probe 16 control-flow; result=MISMATCH; diff=213; shape=90.21739130434783: Inline the pick_objects assignment in its nonzero guard, matching the PDB call/test/jump band. [same emitted code as probe 14]
probe 17 layout; result=MISMATCH; diff=429; shape=88.04347826086956: Use the decompiler-proven bool picked-any flag instead of int to test original local width and home behavior.
probe 19 liveness; result=MISMATCH; diff=280; shape=90.27027027027027: Model the decompiler's parameter-home count/object reuse while retaining its pointer local and tail assignment.
probe 21 liveness; result=MISMATCH; diff=213; shape=90.21739130434783: Register-qualify the non-address-taken selected-object local to test original ECX final-call coloring. [same emitted code as probe 16]
probe 23 control-flow; result=MISMATCH; diff=213; shape=90.21739130434783: Split final selected-object short circuit into nested guards to test original ECX pointer load and call tail. [same emitted code as probe 21]
probe 25 liveness; result=MISMATCH; diff=467; shape=87.5: Move selected-object zero initialization to function declaration, testing declaration-site scheduling and original stack-home timing.
probe 27 control-flow; result=MISMATCH; diff=316; shape=91.30434782608695: Make the sub-50 radius arm explicit if/else while retaining baseline first minimum test.
probe 29 liveness; result=MISMATCH; diff=213; shape=90.21739130434783: Reuse only incoming y1 as the second-pass result/count, isolating the original [esp+20] count-home evidence. [same emitted code as probe 23]
probe 32 liveness; result=MISMATCH; diff=54; shape=94.02173913043478: Test a separate remaining loop local to reproduce the original count spill and EBX score lifetime.
probe 33 liveness; result=MISMATCH; diff=54; shape=94.02173913043478: Use the decompiler-supported y1 parameter as the second pick result, then a separate remaining loop local. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=56; shape=94.02173913043478: Reorder remaining before score and selected-object declarations to test natural stack-home allocation.
probe 35 liveness; result=MISMATCH; diff=40; shape=94.02173913043478: Initialize the separate remaining loop count after the positive guard and Picked_Objects cursor setup.
probe 36 liveness; result=MISMATCH; diff=40; shape=94.02173913043478: Split dx and dy declarations from assignments to test VC5 scheduling of the original coordinate loads. [same emitted code as probe 35]
probe 37 liveness; result=MISMATCH; diff=40; shape=94.02173913043478: Reorder count declaration and split its initialization to test call-crossing local pressure. [same emitted code as probe 36]
probe 38 context; result=MISMATCH; diff=40; shape=94.02173913043478: Restore the canonical TPanel base surface with RGE_View slots 0xE0 and 0xE4. [same emitted code as probe 37]
probe 39 control-flow; result=MISMATCH; diff=39; shape=94.56521739130434: Use the binary operand order dx >= dy for the first radius minimum comparison.
probe 40 liveness; result=MISMATCH; diff=47; shape=91.84782608695652: Reverse delta declaration and assignment order to test coordinate register coloring.
probe 41 control-flow; result=MISMATCH; diff=308; shape=95.13513513513513: Spell the sub-50 radius selection as an explicit if/else to match the two original arms.
probe 42 variant; result=MISMATCH; diff=308; shape=95.13513513513513: variant lab build\variant_lab\00535A80_pick_multi\20260817_130234: 4 variants, 4 invariant-eligible, 0 exact
probe 43 variant; result=MISMATCH; diff=308; shape=95.13513513513513: variant lab build\variant_lab\00535A80_pick_multi\20260817_130319: 128 variants, 128 invariant-eligible, 0 exact
probe 44 variant; result=MISMATCH; diff=308; shape=95.13513513513513: variant lab build\variant_lab\00535A80_pick_multi\20260817_130353: 16 variants, 16 invariant-eligible, 0 exact
probe 46 context; result=MISMATCH; diff=39; shape=94.56521739130434: Replace unnamed virtual slots and non-polymorphic overlays with the period RGE_View/TPanel, RGE_Player, RGE_Static_Object, and RGE_World surfaces; rename slots to pick_through_fog/pick_weight. Emitted 495B/39B duplicate, proving the authentic ownership surface is codegen-neutral here.
probe 47 liveness; result=MISMATCH; diff=39; shape=94.56521739130434: Move the Picked_Objects cursor to function scope and assign it inside each positive-count arm, testing the original line-2315 cursor lifetime and register pressure. Compare emitted first hunk and second scan homes. [same emitted code as probe 46]
probe 48 liveness; result=MISMATCH; diff=382; shape=92.3913043478261: Initialize the shared Picked_Objects cursor at function declaration, matching the PDB line-2315 declaration before the line-2317 helper call, then reuse it in both scans. Test whether early cursor liveness selects original y1/coordinate registers.
probe 49 liveness; result=MISMATCH; diff=39; shape=94.56521739130434: Declare the first-pass index and publication flag before count, then declare count before the selected-object pointer. This tests the PDB/decompiler source order without aliases or register controls. [same emitted code as probe 47]
probe 50 liveness; result=MISMATCH; diff=51; shape=95.65217391304348: Reuse dead rectangle parameters as the second-pass remaining count and selected-object pointer, matching the original +0x20 count and +0x24 pointer writes. Keep typed fields and real pick_through_fog/pick_weight calls.
probe 51 liveness; result=MISMATCH; diff=37; shape=94.56521739130434: Reverse the natural second-pass zero assignments so picked_obj is zeroed before bestScore. The original emits xor ECX then xor EBX; test whether matching this source lifetime also recovers parameter-home reuse.
probe 52 liveness; result=MISMATCH; diff=52; shape=94.02173913043478: Keep the selected-object local and swapped zero assignment order, but reuse dead y1 only for the second-pass remaining count. This isolates the original [esp+20] count-home evidence from the selected-pointer hypothesis.
probe 53 liveness; result=MISMATCH; diff=37; shape=94.56521739130434: Introduce one natural y1 copy that feeds the helper and later dy calculation, testing whether a binary-carried coordinate value explains original EBX=y1 without volatility or register controls. [same emitted code as probe 51]
probe 54 liveness; result=MISMATCH; diff=37; shape=94.56521739130434: Join dx/dy declarations with their assignments, testing whether the original coordinate block's dx-first arithmetic comes from VC5 initializer scheduling rather than the retained split declaration form. [same emitted code as probe 53]
probe 58 control-flow; result=MISMATCH; diff=37; shape=94.56521739130434: Remove repeated inner radius assignment: 493B and 312 differing bytes; restored. [same emitted code as probe 57]
probe 59 control-flow; result=MISMATCH; diff=37; shape=94.56521739130434: Use explicit inner radius if/else: 497B and 309 differing bytes; restored. [same emitted code as probe 58]
probe 60 liveness; result=MISMATCH; diff=37; shape=94.56521739130434: Move remaining declaration to function scope: codegen duplicate at 495B and 37 differing bytes; restored. [same emitted code as probe 59]
probe 61 context; result=MISMATCH; diff=37; shape=94.56521739130434: Add the full reviewed RGE_View size surface: codegen duplicate at 495B and 37 differing bytes; restored. [same emitted code as probe 60]
probe 62 liveness; result=MISMATCH; diff=37; shape=94.56521739130434: Reuse y1 as the second-pass result: 495B and 211 differing bytes; restored. [same emitted code as probe 61]
probe 63 liveness; result=MISMATCH; diff=37; shape=94.56521739130434: Mutate x2 and y2 into coordinate deltas: 495B and 56 differing bytes; restored. [same emitted code as probe 62]
probe 64 abi; result=MISMATCH; diff=37; shape=94.56521739130434: Use long coordinate and radius locals from PDB/decompiler evidence: codegen duplicate at 495B and 37 differing bytes; retained natural widths. [same emitted code as probe 63]
```
<!-- end-recovered:5f015dd88716ce26eb04 -->

<!-- recovered:7cdfea4206a84b52bcad -->
### `abe8883f5ac1` `src/scratch/00535A80_pick_multi.cpp:1-36`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00535A80 RGE_View::pick_multi (view.cpp:2306-2370)
// Attempt log:
// 1: Natural decompiler-shaped implementation: 86.46% diff; RGE_Static_Object fields were 4 bytes early and parameter/register allocation differed.
// 2: Add object vptr pad fixed object_state/master offsets; diff still broad, first mismatch register allocation for params/count.
// 3: Register loop index/named coordinate locals made no codegen change.
// 4: Mutating x2/y2 into deltas made no codegen change.
// 5: Pointer-before-index swapped init order slightly but still wrong registers.
// 6: Register count did not change allocation.
// 7: Negated dy spelling no change.
// 8: Hoisting loop index before pick call improved to 40% positional / 21.6% edit and restored xor ESI/count EBP.
// 9: Register y1 local did not change EBX (still y2).
// 10: Volatile y2 worsened to 87.68% and first mismatch offset 1; rolled back.
// 11: Used the incoming y1 parameter directly in both rectangle calls, matching the packet's direct y1 home reloads; VC5 emitted the same 495-byte code.
// 12: Spelled the first direct selection block as an early failure break followed by picked_any=1; testing the call before the assignment was a natural source-order lead.
// 13: Replaced raw int pick-record access with a typed RGE_Pick_Obj_Info pointer and named confidence field; VC5 was a codegen duplicate.
// 14: Declared the y delta before the x delta to test y1/EBX liveness coloring; diff worsened by 5 bytes, so restored x delta first.
// 15: Reused y1 as the second-pass count and x2 as the selected-object home; this matched the observed parameter writes but was a codegen duplicate, so restored named locals.
// 16: Carried y2 through a named local across both passes; VC5 was a codegen duplicate.
// 17: Removed register qualifiers from count and loop index; both were codegen duplicates, and the natural unqualified locals remain.
// 18: Used a positive second-pass do-while predicate; rebuilt size grew to 501 bytes and strict diff to 276, so restored count != 0.
// Bounded session probes: exact-source ABI correction fixed the two helper
// relocations but did not move bytes; parameter-home reuse, declaration-order,
// natural delta, header-context, and focused score-lifetime variants were
// codegen duplicates or regressed size. The retained source below is the
// simplest typed reconstruction: the PDB-proven picked_obj local is function
// scoped, while the score/count remain ordinary locals.
// Current pass: the 495-byte baseline rebuilt with 9 aligned calls and no
// frame/EH; strict diff is 213 bytes (43.0303%), first mismatch +0x0e.
// Direct y1/x2 parameter-home reuse, a split 56-slot TPanel surface, coordinate
// aliases, and register-qualified locals were codegen duplicates. A bool flag,
// declaration-site pointer initialization, and explicit radius arms regressed.
// The dx>=dy spelling alone reached 212 bytes but was not retained as a metric
// variant. Final source is restored to the clean natural baseline.
// Left in scratch: rebuilt size/calls/frame match, with exact first-pass and
// later loop islands, but broad register/block-layout drift starts at the
// initial y-coordinate load (original keeps y1 in EBX; rebuilt keeps y2).
```
<!-- end-recovered:7cdfea4206a84b52bcad -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
