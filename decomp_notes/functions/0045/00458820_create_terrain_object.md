# Function notes: 00458820 `create_terrain_object`

Module notes: `decomp_notes/map_module.md`.

## Recovered attempt history

<!-- recovered:c89f3b33b21b7173c66b -->
### `target-session` `build/target_sessions/00458820_create_terrain_object.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=693; shape=72.06477732793522: Current typed source baseline: 794 bytes, frame 0x14 vs original 0x10, 10/10 calls aligned, 72.06% shape; first mismatch prologue and node-loop structural spill.
probe 2 control-flow; result=MISMATCH; diff=693; shape=72.06477732793522: Hypothesis 1: replace do/while node walk with top-tested while to recover original next-pointer lifetime and frame.
probe 3 liveness; result=MISMATCH; diff=693; shape=72.06477732793522: Hypothesis 2: scope placement, density, remaining, and mode inside the placement block to shorten lifetimes and free the extra frame slot. [same emitted code as probe 1]
probe 4 layout; result=MISMATCH; diff=701; shape=72.8395061728395: Hypothesis 3: name the terrain record pointer and reuse it for count, density, and placement, matching the original stored record-base topology.
probe 5 liveness; result=MISMATCH; diff=694; shape=72.06477732793522: Hypothesis 4: introduce a loop-local next pointer after loading object, then assign node=next, to recover the original EBP next-pointer carrier.
probe 6 layout; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 5: cache replacement terrain obj_types as a typed short pointer so the scan computes its base once, matching original loop address arithmetic.
probe 7 layout; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 6: retain only the replacement obj_types pointer alias while restoring direct old-terrain array accesses; test whether the alias alone removes the extra frame without terrain-record lifetime drift. [same emitted code as probe 6]
probe 8 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 7: declare the count before terrain and split its initialization, testing whether VC5 assigns the initial short count to EDX and the record pointer to ECX. [same emitted code as probe 7]
probe 9 layout; result=MISMATCH; diff=697; shape=83.81742738589212: Hypothesis 9: cache the replacement RGE_Tile_Set record, then access its count and obj_types, testing whether a typed record owner recovers original invariant address arithmetic.
probe 10 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 10: move object-scan declarations before terrain/count declarations, following the decompiler's observed variable family order to test natural register-color reassignment. [same emitted code as probe 8]
probe 11 abi; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 11: use natural short-to-float casts instead of explicit int widening, testing whether VC5 preserves incoming row/col homes and original FPU lowering.
probe 12 control-flow; result=MISMATCH; diff=686; shape=84.64730290456431: Hypothesis 12: express the replacement scan as a natural short-circuit while condition, testing whether VC5 emits the oracle's one-compare backedge instead of the repeated-compare do/break basin.
probe 13 control-flow; result=MISMATCH; diff=697; shape=74.27385892116183: Hypothesis 13: combine direct terrain_types indexing with the short-circuit while scan, testing whether VC5 keeps the oracle's offset-base add and one-compare backedge without a pointer alias.
probe 14 control-flow; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 14: split the owner and ID-range predicates into nested guards, matching the exact map.cpp donor style and testing delayed new-terrain loading.
probe 15 abi; result=MISMATCH; diff=688; shape=84.29752066115702: Hypothesis 15: widen object_id to int while retaining the short master field, testing whether original's movsx result and register lifetime use an int source local.
probe 16 control-flow; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 16: make the second positive-count test an explicit early-return guard, preserving the oracle's duplicate test and late epilogue edge in the pointer-alias basin. [same emitted code as probe 14]
probe 17 layout; result=MISMATCH; diff=709; shape=83.40248962655602: Hypothesis 17: combine terrain-record alias with the replacement obj_types alias, testing whether two proven typed record owners swap the count/base register colors while preserving the exact frame.
probe 18 context; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 18: add the donor-supported map.cpp <stdlib.h> context, testing whether standard-header front-end state selects the oracle basin.
probe 19 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 19: materialize separate int row/column values inside random-placement mode 0, testing whether VC5 recovers the oracle's local coordinate-home stores and FPU stack order.
probe 20 context; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 20: add donor-supported string/memory standard headers alongside stdlib, testing the historical map.cpp front-end context basin.
probe 21 variant; result=MISMATCH; diff=686; shape=84.23236514522821: variant lab build\variant_lab\00458820_create_terrain_object\20260817_132711: 6 variants, 6 invariant-eligible, 0 exact
probe 22 abi; result=MISMATCH; diff=710; shape=81.9672131147541: Hypothesis 22: widen the initial terrain object count local to int, testing whether its saved-home width and register class explain the oracle's EDX count carrier.
probe 23 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 23: declare the replacement obj_types pointer before its count, testing source declaration order for the oracle's replacement index/base register colors. [same emitted code as probe 21]
probe 24 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 24: make coordinate integer temporaries function-scope and assign them in mode 0, testing whether longer lifetime preserves the oracle's explicit coordinate home stores. [same emitted code as probe 23]
probe 25 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 25: use function-scope short coordinate copies for mode 0, testing whether narrow locals force the oracle's movsx-word and FPU temporary stores.
probe 29 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 1: declare node/object/object_id before the initial terrain count, testing the decompiler-indicated late count lifetime for target EDX count and ECX terrain-record colors. [same emitted code as probe 28]
probe 31 control-flow; result=MISMATCH; diff=686; shape=84.64730290456431: Hypothesis 2: use the Ghidra-supported short-circuit replacement while, testing the oracle's single compare block and jge backedge under the pinned replacement pointer alias. [same emitted code as probe 12]
probe 33 control-flow; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 3: split owner and ID-range predicates into nested source guards from the decompiler's source-shaped tree, testing whether VC5 delays the new_terrain load until after both checks. [same emitted code as probe 16]
probe 35 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 4: make placement mode function-scope, testing the decompiler-indicated uVar1 lifetime and the oracle's persisted byte home before chance-loop branches. [same emitted code as probe 29]
probe 37 liveness; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 5: name the fetched object owner after object_id, testing whether an explicit owner lifetime restores the oracle's master/id-before-owner load order. [same emitted code as probe 33]
probe 39 abi; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 6: use function-scope int coordinate temporaries in both placement modes, testing the oracle's explicit movsx-word-to-dword homes before x87 loads.
probe 41 control-flow; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 7: split coordinate subtraction into staged accumulator assignments, testing the target's explicit integer stores and separate FPU call boundaries. [same emitted code as probe 35]
probe 43 control-flow; result=MISMATCH; diff=686; shape=83.40248962655602: Hypothesis 8: use the decompiler's max_id-left bound spelling, testing compare operand order and target owner/id branch polarity.
probe 45 layout; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 9 (syntax-corrected): name the address of the row/column tile before reading its object list, testing canonical tile ownership and coordinate-home preservation. [same emitted code as probe 37]
probe 47 control-flow; result=MISMATCH; diff=686; shape=84.23236514522821: Hypothesis 10: use a natural top-tested node while with the pinned replacement alias, testing the oracle's post-body node test and backward edge in this current basin.
```
<!-- end-recovered:c89f3b33b21b7173c66b -->

<!-- recovered:c286ef69740ac278503d -->
### `489810cbdcd9` `src/scratch/00458820_create_terrain_object.cpp:1-59`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00458820 RGE_Map::create_terrain_object
// PDB: map.cpp:1989-2092
//
// Attempt log:
// - Replaced the earlier raw-offset/vtable scaffold with the period map.cpp
//   ownership model: RGE_Map terrain records, row-offset tiles, object nodes,
//   RGE_Player master_objects, and the real master/object virtual surfaces.
// - The world parameter is present in the ABI but is not consumed by the
//   original body; placement calls receive the player as their first argument.
// - The initial clean reconstruction preserves the two terrain-object cleanup
//   paths, the replacement-terrain compatibility scan, and the typed density /
//   placement loop.  First checker run is the session baseline.
// - baseline: clean typed source was 839 bytes/frame 0x20; all 10 calls aligned
//   but the local/control-flow basin was broad.
// - paired density/placement cursors and a short terrain result reduced output
//   to 757-761 bytes/frame 0x14 and aligned the outer pointer loop; assigning
//   placement before density recovered the oracle's address/store order.
// - direct `terrain_types[new_terrain].obj_types[]` restored the natural
//   replacement-table ownership and exact output size (794 bytes), improving
//   shape to 71.54%; the pointer alias was kept only as diagnostic evidence.
// - polymorphic map/player declarations, owner-compare reversal, scan-player
//   alias, do/while node spelling, and top-scoped node were neutral or worse.
//   The final clean candidate keeps the named typed surfaces and no raw vtable
//   plumbing; the density[-30] access is retained as the binary-proven adjacent
//   obj_types/obj_density cursor topology.
// - A typed RGE_Tile_Set* terrain-record alias for the initial count and paired
//   arrays grew output to 795 bytes and worsened positional diff to 704; rolled back.
// - Matched the original place ABI and coordinate order: vslot 0x18 takes
//   player, local_c, x, and one zero argument.  This recovered one exact block.
// - bounded pause: calls are 10/10 aligned and size is exact, but the first
//   mismatch remains the prologue/frame (rebuilt frame 0x14 vs 0x10), followed
//   by broad local/register and shifted block drift. Not accepted-drift-safe.
//
// Revisit sa-8632da43-r1:
// - The direct replacement-table scan keeps the 794-byte size but needs a
//   0x14-byte frame.  A typed short* replacement_types alias removes that
//   frame slot and gives a 0x10-byte frame with 241 instructions.
// - The alias candidate has 10/10 ordered calls and 49.38% exact-block
//   coverage.  Its best check is 686 differing bytes and 759 effective bytes.
// - A natural short-circuit replacement scan improves loop shape but removes
//   one required cleanup call.  It was rejected.
// - Twenty-five source and context probes, plus a six-variant declaration and
//   width lab, did not recover the initial register colors or coordinate FPU
//   homes.  The remaining drift is structural and not accepted-drift-safe.
//
// Revisit sa-0ec82117-r1:
// - The clean pointer-alias candidate remains the smallest checked source with
//   the exact frame and all 10 ordered calls: 759 effective bytes, 686 diff.
// - Rechecked declaration order, function-scope mode and coordinate locals,
//   staged coordinate arithmetic, max-id operand order, a tile alias, and a
//   top-tested node loop. These were duplicates or worse and were discarded.
// - The short-circuit replacement scan gives 742 bytes and 50.62% block
//   coverage, but it removes a target cleanup CFG block. It is not retained.
// - The first structural divergence is +0x3B: the executable carries the
//   initial count in DX and the terrain base in ECX. The clean source emits BP
//   and EDX. The next useful lead is the original map.cpp local lifetime or TU
//   context, not metric-only register steering.
// BINARY NOTE (map TU wave02): The shared master-object surface changes the
// placement ABI in the grouped wrapper.  No grouped-only source fork is retained.
```
<!-- end-recovered:c286ef69740ac278503d -->
