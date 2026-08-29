# Recovery journal: 004C6740 `make_object_bounds_list`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/stat_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\stat_obj.cpp`.
- Earlier recovery note: `recovery_notes/stat_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:7e91b873e1f788e19d81 -->
### `target-session` `build/target_sessions/004C6740_make_object_bounds_list.json:1-28`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=617; shape=72.93233082706767: Baseline current typed source: exact size/frame/call set, but 617-byte mismatch and structural control-flow drift; first paired mismatch is local stack-home declaration shape.
probe 2 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis 1: declare short bounds in expression order x1,y1,x2,y2, aiming to recover original EBP/EBX/ESI colors and x2/x1 homes. [same emitted code as probe 1]
probe 4 control-flow; result=MISMATCH; diff=630; shape=70.38461538461539: Hypothesis 2: declare and compute dy after the x-sign guard, matching PDB's separate world-x/world-y bands and testing x87 lifetime/layout.
probe 6 other; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis 3: use period-natural promoted assignment flag = flag + 2 instead of a byte cast, testing the target's observed AL load/add/store sequence.
probe 8 liveness; result=MISMATCH; diff=630; shape=70.38461538461539: Hypothesis 4: keep dy at the existing declaration scope but delay its assignment until after the x-sign branch, isolating assignment timing from declaration liveness. [same emitted code as probe 4]
probe 10 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis 5: initialize the four short bounds at declaration, testing whether VC5's local homes and first FTOL result colors match the original declaration-initialization basin. [same emitted code as probe 2]
probe 12 layout; result=MISMATCH; diff=713; shape=66.92307692307692: Hypothesis 6: use a typed map-row pointer cursor and advance it by one row, matching the original's persistent row-offset cursor and 4-byte outer update.
probe 14 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis 7: assign the new list to result first, then alias check_list, testing original allocation-result versus scan-list lifetime order. [same emitted code as probe 10]
probe 16 liveness; result=MISMATCH; diff=618; shape=72.55639097744361: Hypothesis 8: bind object radius fields inside the positive guards, testing whether VC5 preserves the target's radius-load/FPU order without unsupported volatility.
probe 18 layout; result=MISMATCH; diff=657; shape=72.83018867924528: Hypothesis 9: name the master radius_z as a local, testing whether the missing four-byte local-slot basin explains the target's radius and object-radius homes.
probe 20 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis 10: form dy as a raw world-y local followed by compound subtraction, testing the target's delayed world-y fsub and x87 stack topology. [same emitted code as probe 14]
probe 22 abi; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis 11: add explicit int-to-short conversion layers to coordinate bounds, matching the sibling stat_obj source and testing FTOL result-home allocation.
probe 24 liveness; result=MISMATCH; diff=612; shape=68.84615384615384: Hypothesis 12: reread object master radius fields in the final extent expressions instead of naming radius locals, testing direct-member CSE and FPU operand order.
probe 26 variant; result=MISMATCH; diff=612; shape=68.84615384615384: variant lab build\variant_lab\004C6740_make_object_bounds_list\20260817_134215: 24 variants, 0 invariant-eligible, 0 exact
probe 29 layout; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis A: declare bounds in source coordinate order x1,y1,x2,y2, testing original x1/x2 stack-home colors against the first paired hunk. [same emitted code as probe 28]
probe 31 layout; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis B: group all four short bounds in one declaration, testing whether VC5 uses one contiguous short allocation basin and restores the original x1/x2 home colors. [same emitted code as probe 29]
probe 33 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis C: scope the short bounds and map/result locals after the positive radius gate, testing whether original source lifetimes explain the initial radius homes and bound register colors. [same emitted code as probe 31]
probe 35 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis D: move dx, dy, and flag to function scope, matching the decompiler's durable homes and testing whether nested declaration scope causes the broad late FPU schedule drift. [same emitted code as probe 33]
probe 37 liveness; result=MISMATCH; diff=612; shape=68.84615384615384: Hypothesis E: reread object master radii in the final extent expressions, testing direct-member FPU scheduling and the delayed x/y subtraction shape. [same emitted code as probe 24]
probe 39 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis F: move object radius temporaries to function scope, matching the decompiler's durable radius homes and testing whether their scope controls the target's preloaded FPU radius order. [same emitted code as probe 35]
probe 41 layout; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis G: swap the x-bound variable identities while preserving lower/upper behavior, testing whether VC5's source-symbol allocation maps the original lower x to EBP and upper x to the short home. [same emitted code as probe 39]
probe 43 liveness; result=MISMATCH; diff=617; shape=72.93233082706767: Hypothesis H: form both coordinate deltas as raw member loads followed by compound subtraction, testing the target's delayed y subtraction and x87 stack topology with a period-natural update form. [same emitted code as probe 41]
probe 46 baseline; result=MISMATCH; diff=617; shape=74.61538461538461: Baseline after claim: clean typed source, establish current structural and ordered-call evidence before edits.
probe 47 layout; result=MISMATCH; diff=617; shape=74.61538461538461: Swapped short bound declaration order to test target-proven x1 EBP versus x2 stack-home ownership; preserves bounds behavior and fault order. [same emitted code as probe 46]
probe 48 control-flow; result=MISMATCH; diff=614; shape=77.3076923076923: Restructured the invalid-radius guard to publish a zero result through one common return, matching the original shared cleanup/return boundary.
probe 49 control-flow; result=MISMATCH; diff=614; shape=77.3076923076923: Removed the redundant entry result store while retaining invalid-path publication through the shared return; tests target result-home lifetime without changing cleanup. [same emitted code as probe 48]
probe 50 liveness; result=MISMATCH; diff=614; shape=77.3076923076923: Scoped and joined short bound declarations inside the valid-radius branch to test target x1 saved-register and x2 stack-home lifetimes without changing coordinate order. [same emitted code as probe 49]
probe 51 liveness; result=MISMATCH; diff=614; shape=77.3076923076923: Moved the result declaration before map/check locals to test target radius and publication homes while preserving one shared return and cleanup ownership. [same emitted code as probe 50]
```
<!-- end-recovered:7e91b873e1f788e19d81 -->

<!-- recovered:048fb763c746bce5490e -->
### `0b3aa46fe5b9` `src/scratch/004C6740_make_object_bounds_list.cpp:1-55`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C6740 RGE_Static_Object::make_object_bounds_list
// stat_obj.cpp
// FLAGS: /GX
// Attempt log:
// clean reconstruction: restored the stat_obj ownership surface (master
// radii, player/world/map, typed map rows/tiles/object nodes) and the
// decompiler-supported bounds/overlap behavior.  This is the first clean
// candidate; later probes will be recorded below.
// probe layout: corrected RGE_Map's vptr/map/width/height/row-table offsets;
// this moved the map accesses to the proven +8/+C/+8D8C fields.
// probe liveness: cached the other-master x/y radii and used z >= -radius;
// this recovered the original 0x40 frame/859-byte size and fcompp topology.
// probe layout: a typed master-object owner local for the initial radius
// precheck was an emitted-code duplicate; restored direct master ownership.
// negative probes: short-bound declaration/identity reorder and register hint
// were codegen duplicates; splitting the x-sign flag, a saved x-start, and an
// int lower-x home did not improve the structural basin.  A precomputed extent
// pair improved x87 shape but grew the function to 876 bytes, so it was
// restored to the typed inline sums.
// structural retry: moving map/check-list/result declarations before the
// radii was a codegen duplicate.  A row-pointer plus byte-offset tile cursor
// worsened the result to 713 bytes with a 0x3C frame, so it was restored.
// A common positive-radius result path improved shape but lost 33 bytes and
// was restored; an explicit invalid-radius else block was also a duplicate.
// fresh structural lead: an exact stat_obj-era nested short-loop donor uses
// direct map_row_offset[row][col].objects.list.  This reduced positional drift
// by 20 bytes, but lost the 0x40 frame and 20 bytes of code, so it was restored.
// left in scratch: all nine calls and frame/size match, but initial float/local
// homes, coordinate register coloring, and the late x/y FPU schedule remain
// broad positional drift (final validation records the restored metrics).
// revisit 2026-08-17: declaration-order and short initialization variants were
// codegen duplicates.  Delayed dy assignment changed the basin to 843 bytes,
// 0x40 was lost, and the result was rejected.  A typed row-pointer cursor
// changed the frame to 0x3C and worsened the result to 713 bytes.  Reversing
// allocation/result assignment and promoted flag addition were duplicates.
// A local radius_z, direct object-radius rereads, and explicit int-to-short
// casts worsened or changed the frame.  Raw-y, direct-member, and extent
// variants were tested in one 24-state lab; no invariant-eligible result.
// Final clean validation: 859 bytes, 0x40 frame, nine aligned calls, 617-byte
// mismatch.  Next evidence should target the original short-bound home colors
// and the target's delayed x/y x87 expression schedule without fake steering.
// revisit claim sa-fc1480bd-r1: grouped and reordered bound declarations,
// scoped the bounds after the radius guard, and moved inner temporaries to
// function scope.  These forms were emitted-code duplicates.  Swapping bound
// identities and using raw coordinate loads with compound subtraction were
// also duplicates.  Direct object-radius rereads reached 612 differing bytes,
// but changed the frame to 0x38 and lost the target size, so the named radius
// locals remain authoritative.  No new natural source basin was found.
// continuation sa-d34ea87b-r1: the PDB owner is RGE_Static_Object in
// stat_obj.cpp, lines 4049-4158.  The original has one shared return, nine
// ordered calls, a 0x40 frame, and the proven object-list cleanup path.
// A natural common invalid-radius guard improved CFG shape but lost 33 bytes;
// declaration, x-start, and flag-lifetime variants were no better.  They were
// restored.  Final clean validation remains 617 differing bytes; the blocker
// is the persistent x1/x2 home coloring and delayed x87 schedule.
```
<!-- end-recovered:048fb763c746bce5490e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
