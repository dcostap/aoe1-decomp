# Function notes: 00484160 `add_terrain_module`

Module notes: `decomp_notes/rmm_dbct_module.md`.

## Recovered attempt history

<!-- recovered:71a369424661dbc61105 -->
### `target-session` `build/target_sessions/00484160_add_terrain_module.json:1-36`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=417; shape=45.0: Clean typed baseline: 407-byte rebuild, frame 0xC, one ftol call, CFG 8/8; first structural mismatch is register/loop source shape.
probe 2 layout; result=MISMATCH; diff=410; shape=65.69343065693431: H1 terrain loop: replace source/destination pointers with natural indexed terrain records while retaining map alias; tests whether VC5 recovers EBP byte-offset and EDI output cursor.
probe 3 abi; result=MISMATCH; diff=410; shape=65.69343065693431: H2 map aggregate reference alias: test whether canonical reference ownership assigns map entry to ESI and restores target register roles without raw offsets. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=410; shape=57.66423357664234: H3 terrain output alias: add one named destination line pointer while keeping indexed source, testing target's EDI output cursor and EBP source-offset coloring.
probe 5 liveness; result=MISMATCH; diff=410; shape=65.69343065693431: H4 declaration order: declare terrain loop index before map reference to test VC5 register-color allocation against target EBP offset, ESI map, EDI output roles. [same emitted code as probe 3]
probe 6 variant; result=MISMATCH; diff=410; shape=64.23357664233576: H5 diagnostic only: use the decompiler-proven terrain-type anchored output cursor to test whether target's EDI anchor and loop stride are compiler-active; retain only if natural ownership remains plausible.
probe 7 liveness; result=MISMATCH; diff=410; shape=65.69343065693431: H7 hot-loop declaration order: land index before hot-spot index to test target's EDI land-byte-offset and ECX output-index coloring. [same emitted code as probe 5]
probe 8 context; result=MISMATCH; diff=410; shape=65.69343065693431: H8 split map declaration/assignment: test whether delayed map-pointer initialization changes callee-saved allocation while preserving typed ownership. [same emitted code as probe 7]
probe 9 control-flow; result=MISMATCH; diff=407; shape=76.64233576642336: H9 hot-spot branch polarity: place the by-player loop in the positive arm and simple copy in else, matching target fall-through and cold simple block layout.
probe 10 liveness; result=MISMATCH; diff=397; shape=88.48920863309353: H10 remove branch-local land pointer: use direct typed indexed land members so land byte offset can coalesce into target EDI cursor and hot index into ECX.
probe 11 control-flow; result=MISMATCH; diff=397; shape=88.48920863309353: H11 land preheader predicate: compare the zero land offset against land_num instead of testing land_num, testing target CMP/JLE and preheader zero placement. [same emitted code as probe 10]
probe 12 liveness; result=MISMATCH; diff=397; shape=88.48920863309353: H12 local declaration order: declare land_count before land and hot indices to test target reuse of [esp+10] for terrain/land count and [esp+14] for player count. [same emitted code as probe 11]
probe 13 liveness; result=MISMATCH; diff=397; shape=88.48920863309353: H13 scope model: make player counter function-scope with branch-local reset, matching dossier's persistent local_8 and testing target stack-home reuse. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=397; shape=89.92805755395683: H14 split land-index initialization immediately before hot loop, testing whether VC5 emits target's early XOR/CMP and preserves EDI before the guard.
probe 15 liveness; result=MISMATCH; diff=397; shape=89.92805755395683: H15 swap function-scope counter declaration order, testing VC5 stack-home assignment for target land_count [esp+10] and player_index [esp+14]. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=397; shape=89.92805755395683: H16 merge terrain and outer-land counters into the decompiler-proven land_tile_num local, testing stack-slot reuse and target [esp+10]/[esp+14] assignments. [same emitted code as probe 15]
probe 17 layout; result=MISMATCH; diff=397; shape=89.92805755395683: H17 land-area expression: join width, height, and grown-percent calculation into one natural expression to recover target multiply load order. [same emitted code as probe 16]
probe 18 variant; result=MISMATCH; diff=397; shape=89.92805755395683: H18 named map-area intermediate: force width-height multiplication before grown-percent load to test target early arithmetic schedule. [same emitted code as probe 17]
probe 19 abi; result=MISMATCH; diff=397; shape=89.92805755395683: H19 widen shared land_tile_num to the packet's decompiler-proven long type, testing stack-home and compare lowering without changing behavior. [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=397; shape=89.92805755395683: H20 declaration order: declare land_tile_num after map acquisition, matching decompiler local ordering and testing both early schedule and later stack-home reuse. [same emitted code as probe 19]
probe 21 context; result=MISMATCH; diff=381; shape=92.0863309352518: Post-budget H21 direct map-field area expression: test whether direct owner spelling restores target width-height-grown multiply order while retaining map-entry alias for later loops.
probe 22 layout; result=MISMATCH; diff=390; shape=89.92805755395683: Post-budget H22 move terrain-count store before area calculation, testing target hoisted count load before signed division.
probe 23 liveness; result=MISMATCH; diff=443; shape=86.13138686131387: Post-budget H23 move all loop locals to function entry in decompiler order, testing source-scope-driven stack homes while retaining direct owner fields.
probe 24 liveness; result=MISMATCH; diff=443; shape=86.13138686131387: Post-budget H24 move only player counter declaration to function entry, testing stack-home ordering without extending land/index lifetimes. [same emitted code as probe 23]
probe 25 liveness; result=MISMATCH; diff=443; shape=86.13138686131387: Post-budget H25 separate outer land_count declared before area, while terrain keeps land_tile_num; tests whether source declaration order swaps target outer/player stack homes. [same emitted code as probe 24]
probe 26 abi; result=MISMATCH; diff=443; shape=86.13138686131387: Post-budget H26 widen land byte-offset index to decompiler-proven long, testing register and stack home allocation. [same emitted code as probe 25]
probe 27 other; result=MISMATCH; diff=6; shape=95.62043795620438: Post-budget H27 preserve target duplicate terrain-count read: test map-source condition instead of rereading this->terrain_info after its store.
probe 28 liveness; result=MISMATCH; diff=6; shape=95.62043795620438: Post-budget H28 swap hot-loop zero-assignment statement order, testing target stack-home allocation while checking whether VC5 preserves XOR register order. [same emitted code as probe 27]
probe 29 liveness; result=MISMATCH; diff=6; shape=95.62043795620438: Post-budget H29 reorder post-terrain local declarations to land index, hot index, player index, testing stack allocator ordering. [same emitted code as probe 28]
probe 30 variant; result=MISMATCH; diff=6; shape=95.62043795620438: variant lab build\variant_lab\00484160_add_terrain_module\20260817_103907: 8 variants, 8 invariant-eligible, 0 exact
probe 31 liveness; result=MISMATCH; diff=416; shape=94.8905109489051: Post-budget H30 scope probe: put terrain counter inside terrain guard and use a fresh outer land counter, testing target stack-home reuse from declaration scope.
probe 32 abi; result=MISMATCH; diff=6; shape=95.62043795620438: Post-budget H32 narrow shared land_tile_num to int while retaining direct map-source condition, testing stack-home allocation. [same emitted code as probe 30]
probe 33 abi; result=MISMATCH; diff=6; shape=95.62043795620438: Post-budget H33 widen player counter to long, testing decompiler local_8 width hypothesis and stack-home swap. [same emitted code as probe 32]
probe 35 liveness; result=MISMATCH; diff=11; shape=91.97080291970804: Reuse land_area for by-player hot-spot counter, testing target local_8 home reuse while retaining land_tile_num across terrain and land loops.
probe 37 other; result=MISMATCH; diff=406; shape=83.33333333333333: Replace the redundant land index with a typed advancing land-entry pointer, testing natural pointer ownership for the target outer scan.
probe 39 liveness; result=MATCH; diff=0; shape=100.0: Use one typed land_tile_num for both outer scan count and indexed map-land source, removing the separate dead land_index.
```
<!-- end-recovered:71a369424661dbc61105 -->

<!-- recovered:296b517c0d28e9e8cfc7 -->
### `5aad8dc3cdb0` `src/scratch/00484160_add_terrain_module.cpp:1-33`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00484160 add_terrain_module (448B)
//
// Baseline reconstruction: derive terrain sizes from the map area, copy the
// terrain records, and build hot spots from eligible map-land records.  The
// source keeps the map, terrain, and land ownership typed and named.
// Attempt log:
// - The clean typed baseline matched the single __ftol call, frame, CFG, and
//   hot-spot behavior but was 41 bytes short.
// - Named controller/terrain-data aliases were neutral.  A diagnostic
//   member-anchored/source-offset form reached exact size and improved shape,
//   but was rolled back as raw cursor plumbing.
// - Current source retains canonical typed arrays and natural indexed loops;
//   remaining lead is the source/destination cursor topology and register
//   roles in the terrain copy, with later hot-spot drift dependent on it.
// - Fresh dossier and same-TU donor review confirm the map-entry stride 0x48,
//   terrain record stride 0x18, land stride 0x2C, and the single __ftol call.
// - Fresh direct-map and shared-counter forms changed frame or size but not
//   the first structural hunk; explicit controller ownership was a duplicate.
// - Repeated typed source fields overran the target by 80 bytes.  Hoisted
//   counters recovered EBX as this but grew the frame to 0x14.  Both were
//   rolled back.
// - A terrain_type-anchored output cursor moved shape from 45.71% to 46.43%
//   without positional gain.  It was rolled back as opaque field plumbing.
// - Fresh pass remains paused: exact call parity and frame parity hold, but
//   the terrain-copy topology is still structurally unresolved.
// Fresh pass:
// - Dossier, same-TU donors, and ABI evidence confirm controller offsets
//   0x14/0x18/0x34/0x38, map stride 0x48, and serialized line sizes 0x18/0x2C.
// - Replaced raw object/elevation module blocks with named fixed aggregates
//   and typed map records.  The emitted code moved three bytes farther, but
//   the source now preserves the complete serialized layout.
// - A typed hot-spot pointer loop regressed structure and was rolled back.
//   The indexed source remains the clearer behavior reconstruction.
```
<!-- end-recovered:296b517c0d28e9e8cfc7 -->
