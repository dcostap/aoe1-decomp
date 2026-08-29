# Recovery journal: 00458600 `load_terrain_obj_types`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\map.cpp`.
- Earlier recovery note: `recovery_notes/map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:021f65fdb1f2211886f1 -->
### `target-session` `build/target_sessions/00458600_load_terrain_obj_types.json:1-47`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=206; shape=91.2621359223301: Baseline clean typed direct-member loop; calls/frame align but rebuilt 354 bytes and count spill/body layout differs.
probe 2 variant; result=MISMATCH; diff=209; shape=84.54545454545455: Body-scoped short count cache used for compare and all three stores; test whether target count spill follows explicit source ownership.
probe 4 liveness; result=MISMATCH; diff=209; shape=84.54545454545455: Declare count only after the direct member bound; compare stays on the loaded field while body uses a scoped cache. [same emitted code as probe 2]
probe 6 variant; result=MISMATCH; diff=246; shape=72.81553398058253: Reference alias for num_obj_type; test whether a named field alias preserves the target count value through the three writes.
probe 8 variant; result=MISMATCH; diff=246; shape=72.81553398058253: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260816_224455: 5 variants, 1 invariant-eligible, 0 exact
probe 9 variant; result=MISMATCH; diff=246; shape=72.81553398058253: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260816_224515: 10 variants, 1 invariant-eligible, 0 exact
probe 10 liveness; result=MISMATCH; diff=209; shape=84.54545454545455: Function-scope uninitialized short count assigned only after direct bound; test target-like direct compare plus cached count lifetime. [same emitted code as probe 4]
probe 12 liveness; result=MISMATCH; diff=206; shape=91.2621359223301: Reordered locals so three scanned short outputs precede the dead four-byte header local; target stack homes are shifted four bytes above the baseline. [same emitted code as probe 1]
probe 14 liveness; result=MISMATCH; diff=209; shape=84.54545454545455: Register-qualified count cache; test whether VC5 assigns the count to EDX and preserves target-like count arithmetic. [same emitted code as probe 10]
probe 16 liveness; result=MISMATCH; diff=209; shape=84.54545454545455: Explicit short count declared before the header local; test declaration-order register coloring while keeping terrain-id source shape. [same emitted code as probe 14]
probe 17 abi; result=MISMATCH; diff=209; shape=84.54545454545455: Diagnostic volatile num_obj_type field; test whether forced field liveness produces the observed count spill. [same emitted code as probe 16]
probe 19 variant; result=MISMATCH; diff=209; shape=84.54545454545455: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260816_224918: 25 variants, 1 invariant-eligible, 0 exact
probe 20 liveness; result=MISMATCH; diff=209; shape=84.54545454545455: Explicit count declaration interleaved between density and object locals, matching decompiler local ordering; test target EDX count color and spill. [same emitted code as probe 17]
probe 23 abi; result=MISMATCH; diff=213; shape=77.66990291262135: Tested a natural short header version with direct typed terrain members; checks whether the dead header home enables the target count spill without a fake count alias.
probe 25 behavior; result=MISMATCH; diff=132; shape=95.0: PDB cvdump_symbols proves locals terr_obj_tbl, id, num, density, flag, obj_id and num at entry -4. Reconstructed the typed loop with header fscanf into num, then num = terrain count.
probe 26 control-flow; result=MISMATCH; diff=121; shape=96.0: Moved the PDB-proven num assignment inside the count-success guard. Target spills num only after jge; this preserves typed field ownership and natural guard order.
probe 27 layout; result=MISMATCH; diff=121; shape=96.0: Tested a typed pointer-plus-index spelling for obj_placement_flags to explain the target's add-this/add-num address order without raw cursors. [same emitted code as probe 26]
probe 28 abi; result=MISMATCH; diff=121; shape=96.0: Removed a redundant short-to-uchar cast from the typed placement assignment; tests whether target CL scheduling follows the original field assignment type. [same emitted code as probe 27]
probe 29 liveness; result=MISMATCH; diff=121; shape=96.0: Swapped flag and density declarations to test whether original local declaration order controls the target placement address schedule; PDB stack homes remain the constraint. [same emitted code as probe 28]
probe 30 context; result=MISMATCH; diff=121; shape=96.0: Aligned the typed member name with PDB RGE_Tile_Set evidence: obj_placement_flag singular. This tests whether source context changes the isolated address lowering. [same emitted code as probe 29]
probe 31 context; result=MISMATCH; diff=121; shape=96.0: Replaced the opaque terrain-set gap with the PDB-proven typed tiles, terrain_to_draw, rows, cols, and borders members at the unchanged offsets. [same emitted code as probe 30]
probe 32 layout; result=MISMATCH; diff=121; shape=96.0: Diagnostic only: reversed typed subscript num[array] tests whether VC5 preserves operand order for the target placement address; source remains reversible. [same emitted code as probe 31]
probe 33 context; result=MISMATCH; diff=121; shape=96.0: Tested implicit this on the placement field only. Original map.cpp style may omit explicit this; compare whether this changes the target's add-this/add-num lowering. [same emitted code as probe 32]
probe 34 context; result=MISMATCH; diff=121; shape=96.0: Tested implicit this on the count assignment. This keeps the PDB local/control-flow model natural while probing expression-tree context. [same emitted code as probe 33]
probe 35 layout; result=MISMATCH; diff=121; shape=96.0: Tested typed pointer-to-terrain indexing for placement only. It preserves class ownership while checking whether the target base-plus-count schedule comes from pointer syntax. [same emitted code as probe 34]
probe 37 layout; result=MISMATCH; diff=121; shape=96.0: Typed pointer-add spelling for placement array; tests whether field-first pointer arithmetic preserves original this-plus-num schedule. [same emitted code as probe 36]
probe 38 layout; result=MISMATCH; diff=121; shape=96.0: Reversed typed pointer-add operands for placement array; tests whether source operand order controls VC5 address schedule. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=121; shape=96.0: Scoped typed placement pointer local; tests whether a natural field pointer preserves the target's live this plus num base. [same emitted code as probe 38]
probe 40 layout; result=MISMATCH; diff=121; shape=96.0: Scoped typed terrain-record pointer for placement only; tests whether member access through a record pointer changes address-tree scheduling. [same emitted code as probe 39]
probe 41 abi; result=MISMATCH; diff=121; shape=96.0: Tested period-plausible signed char placement field; binary store width permits this, and it tests whether field signedness controls address scheduling. [same emitted code as probe 40]
probe 42 liveness; result=MISMATCH; diff=121; shape=96.0: Scoped typed terrain-record reference for placement only; tests whether reference binding changes VC5 expression scheduling without adding ABI state. [same emitted code as probe 41]
probe 44 variant; result=MISMATCH; diff=121; shape=96.0: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260817_122345: 12 variants, 12 invariant-eligible, 0 exact
probe 45 variant; result=MISMATCH; diff=121; shape=96.0: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260817_122443: 17 variants, 17 invariant-eligible, 0 exact
probe 46 context; result=MISMATCH; diff=121; shape=96.0: Restored the reviewed RGE_Map virtual surface through vt[11]; tests whether the canonical map class declaration changes this placement lowering basin. [same emitted code as probe 42]
probe 47 abi; result=MISMATCH; diff=121; shape=96.0: Used canonical reviewed TShape and RGE_Sound pointer member types in RGE_Tile_Set; tests whether full typed class context alters codegen. [same emitted code as probe 46]
probe 48 abi; result=MISMATCH; diff=121; shape=96.0: Restored explicit unsigned-char conversion at the placement store; tests whether source narrowing timing affects the target byte-store schedule. [same emitted code as probe 47]
probe 49 liveness; result=MISMATCH; diff=121; shape=96.0: Scoped typed RGE_Map receiver alias for the placement store; tests whether explicit receiver ownership keeps the target this base live. [same emitted code as probe 48]
probe 50 liveness; result=MISMATCH; diff=121; shape=96.0: Reordered narrow locals to the PDB symbol order id, num, density, flag, obj_id; tests whether source declaration order controls the placement block while preserving typed ownership. [same emitted code as probe 49]
probe 51 abi; result=MISMATCH; diff=121; shape=96.0: Combined signed-char placement member with explicit unsigned-char assignment conversion; tests the remaining period-type combination. [same emitted code as probe 50]
probe 52 layout; result=MISMATCH; diff=121; shape=96.0: Used a natural typed placement cursor with separate pointer increment after correcting its char pointer type; tests whether a real pointer update preserves the target base-plus-num lowering. [same emitted code as probe 51]
probe 53 layout; result=MISMATCH; diff=216; shape=61.0: Tested one natural typed terrain-record pointer for loaded guard and all four stores; this checks whether the original source cached the record across the body.
probe 55 context; result=MISMATCH; diff=121; shape=96.0: Expanded the canonical RGE_Map layout with typed map, tile-size, border-set, and row-offset members; tests whether full map context changes the isolated placement lowering. [same emitted code as probe 52]
probe 56 context; result=MISMATCH; diff=121; shape=96.0: Combined the canonical full map layout with the reviewed map_generate and map_generate2 virtual slots; tests whether donor TU context changes placement lowering. [same emitted code as probe 55]
probe 57 context; result=MISMATCH; diff=121; shape=96.0: Combined full canonical map and terrain type surfaces, including typed shape/sound pointers and vt[11] save; final context probe for the placement lowering basin. [same emitted code as probe 56]
probe 62 variant; result=MISMATCH; diff=121; shape=96.0: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260823_194240: 1 variants, 1 invariant-eligible, 0 exact
probe 63 variant; result=MISMATCH; diff=121; shape=96.0: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260823_194248: 1 variants, 1 invariant-eligible, 1 exact
probe 64 variant; result=MISMATCH; diff=121; shape=96.0: variant lab build\variant_lab\00458600_load_terrain_obj_types\20260823_194305: 1 variants, 0 invariant-eligible, 0 exact
```
<!-- end-recovered:021f65fdb1f2211886f1 -->

<!-- recovered:867a32e183987df45696 -->
### `a27664f5428e` `src/scratch/00458600_load_terrain_obj_types.cpp:1-31`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00458600 RGE_Map::load_terrain_obj_types
// map.cpp:1916-1942
//
// Binary facts: map.cpp PDB symbols prove short locals named num, density,
// flag, obj_id, and id. The header scan writes num at entry offset -4.
//
// The loop keeps only loaded terrain sets with fewer than 30 entries. It then
// stores the object id, density, and placement flag, and increments the field.
//
// Current reconstruction: the typed terrain ownership and guard order now
// produce the original 341-byte size and 100 instructions. All five calls,
// frame, and call targets align. The checker reports 121 differing bytes.
//
// The remaining mismatch is one placement-byte address lowering. The target
// adds this plus num before the terrain stride. VC5 emits the equivalent tile
// base plus num form from the natural typed member expression.
//
// Tested and rejected: direct pointer syntax, reversed subscripts, implicit
// this, declaration order, cast changes, and a typed terrain-set gap. These
// forms either duplicate the 121-byte result or lack binary support.
// Revisit probes added typed pointer-add, pointer-local, record-reference,
// signed-char, index-cast, and array-pointer forms. A 17-case variant lab
// produced one codegen group. Every case stayed at 341 bytes and 121 bytes
// differed under the authoritative checker.
//
// Canonical full RGE_Map layout, virtual slots, and typed pointer members also
// emitted the same group. A cached typed record across the loop shrank the
// function to 264 bytes and was rejected. No policy-valid exact source was
// found. The typed direct-member source remains the clean reconstruction.
// Keep the typed direct-member source authoritative until new source evidence
// explains this final expression schedule.
```
<!-- end-recovered:867a32e183987df45696 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
