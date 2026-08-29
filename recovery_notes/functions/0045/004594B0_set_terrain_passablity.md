# Recovery journal: 004594B0 `set_terrain_passablity`

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


<!-- recovered:6a911a2e9e5b3a37a201 -->
### `target-session` `build/target_sessions/004594B0_set_terrain_passablity.json:1-21`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=247; shape=67.9245283018868: Clean typed rectangle source from prior attempt log; establish current mismatch and frame.
probe 2 control-flow; result=MISMATCH; diff=290; shape=71.55963302752293: Explicit byte-offset/count loops with row and tile cursors; tests target's observed offset/count lowering.
probe 3 liveness; result=MISMATCH; diff=293; shape=73.39449541284404: Move row offset/count initialization inside the outer guard to match target setup after CMP and allow parameter-home reuse.
probe 4 liveness; result=MISMATCH; diff=293; shape=73.39449541284404: Declare outer cursor/count at function scope before clipping, testing target's early push-ecx local allocation and home reuse. [same emitted code as probe 3]
probe 5 liveness; result=MISMATCH; diff=293; shape=73.39449541284404: Narrow volatile outer-count diagnostic to force the observed entry-relative local home and load/decrement/store loop. [same emitted code as probe 4]
probe 6 abi; result=MISMATCH; diff=293; shape=72.07207207207207: Use a short x-swap temporary, matching the target's 16-bit swap values and checking whether full-width home stores are compiler-generated.
probe 7 liveness; result=MISMATCH; diff=293; shape=72.07207207207207: Initialize the function-scope outer count before clipping, testing whether VC5 retains the target's early stack local without a visible zero store. [same emitted code as probe 6]
probe 8 liveness; result=MISMATCH; diff=293; shape=72.07207207207207: Make inner count function-scope and outer count separate, testing VC5 live-range allocation for target's local outer count versus y2 inner home. [same emitted code as probe 7]
probe 9 layout; result=MISMATCH; diff=293; shape=72.07207207207207: Use the exact typed row-pointer plus byte-offset expression from the matching map donor, testing pointer lowering and register colors. [same emitted code as probe 8]
probe 12 control-flow; result=MISMATCH; diff=298; shape=68.86792452830188: Use index-based for loops with explicit row and tile byte offsets, testing whether VC5 strength-reduces source loops into the target countdown topology.
probe 14 liveness; result=MISMATCH; diff=293; shape=70.27027027027027: Reverse inner count and tile-offset declaration order while retaining typed countdown loops, testing target's x1/x2 register colors.
probe 17 baseline; result=MISMATCH; diff=247; shape=67.9245283018868: Reconfirm pinned clean typed RGE_Tile ownership and ordinary nested for loops before new natural-loop probes; target remains structural mismatch. [same emitted code as probe 16]
probe 18 control-flow; result=MISMATCH; diff=294; shape=61.607142857142854: Use typed row-pointer and tile-pointer do-while loops with ordinary RGE_Tile ownership; test countdown topology without raw byte cursor plumbing.
probe 20 control-flow; result=MISMATCH; diff=297; shape=66.97247706422019: Use typed indexed row ownership with ordinary do-while countdowns and no raw pointer casts; test compiler strength reduction of row and tile traversal.
probe 22 control-flow; result=MISMATCH; diff=294; shape=73.39449541284404: Keep typed terrain and ordinary nested for loops, but use short row and column indices matching the original endpoint widths; test VC5 countdown strength reduction.
probe 24 control-flow; result=MISMATCH; diff=272; shape=73.87387387387388: Use ordinary for loops controlled by explicit typed row and column counts, keeping short indices and typed tile ownership; test whether natural count locals reproduce target homes.
probe 26 control-flow; result=MISMATCH; diff=266; shape=79.81651376146789: Use short row and column locals with ordinary do-while count loops and typed indexed tiles; test a natural source form with target's unconditional inner and outer backedges.
probe 27 layout; result=MISMATCH; diff=292; shape=62.5: Keep short outer index and explicit count, but traverse each row through a typed RGE_Tile pointer increment; avoid raw byte cursors while testing target tile-stride lowering.
probe 29 abi; result=MISMATCH; diff=294; shape=66.98113207547169: Use a short x-endpoint swap temporary and direct typed tile row loops, testing whether the target's full-width swap stores are compiler-emitted from narrow endpoint ownership.
probe 31 abi; result=MISMATCH; diff=289; shape=61.607142857142854: Mirror the decompiler-supported asymmetric endpoint ownership: y2 upper local, x1 lower local, mutated y1 and x2, with ordinary typed tile loops.
probe 33 control-flow; result=MISMATCH; diff=293; shape=70.64220183486239: Use int loop indices with explicit natural row and column count do-loops while retaining typed map indexing and terrain members; test whether target count lowering needs wide indices.
```
<!-- end-recovered:6a911a2e9e5b3a37a201 -->

<!-- recovered:f5d36d87e08d85afd12f -->
### `b3d4a0963041` `src/scratch/004594B0_set_terrain_passablity.cpp:1-51`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004594B0 RGE_Map::set_terrain_passablity
//
// Binary-supported ownership: the method clips a rectangle to the map, then
// replaces the low five terrain bits in every covered tile with the selected
// terrain set's passable or impassable value.
//
// Attempt log:
// - Baseline: typed rectangle loops matched size (303B) and saved registers;
//   the prologue and loop register/stack-home topology remained broad drift.
// - Explicit row/column offset-count cursors and a typed row base preserved
//   the observed map-row/0x18-tile ownership but initially worsened structure.
// - Reversing each swap to use the upper bound as the temporary was a useful
//   local lead; a full-width x temporary gave the best emitted result (291
//   positional bytes differing), but did not repair the opening stack home.
// - Shared swap temporary, named min/max locals, and declaration-order
//   variants were duplicate or broader basins; restored the best typed source.
// - Remaining mismatch is broad VC5 register allocation and local stack-home
//   placement (target begins with push ecx and keeps distinct row/column
//   counters). No calls or behavior/layout facts remain unresolved.
// - Main-agent audit restored ordinary row/column subscripting and named tile
//   ownership; byte-offset cursors from the codegen experiments were removed.
// - Current worker: adding the complete same-TU RGE_Map virtual prefix was a
//   codegen duplicate; it did not create the target's opening push-ecx/local
//   home or change the broad 247-byte structural gap. Restored the clean
//   natural source.
// - Session sa-f2589ce1-r1 dossier confirms no calls, map_row_offset at +8D8C,
//   terrain-set stride 0x198, tile stride 0x18, and a distinct outer-count
//   spill at entry-relative -4. A typed byte-offset/count-loop reconstruction
//   reached exact size and 70.9% shape (295 positional bytes, 139-byte edit
//   cost), but remained a broad register/home mismatch and was diagnostic only.
// - Reordered inner/outer cursor initialization, reused y2 as the inner count,
//   changed the x-bound predicate, scoped the row locals, and tested a narrow
//   volatile-count diagnostic; the latter groups were duplicates or worse.
//   Restored the clean natural tile-row source; final unresolved lead is the
//   target's compiler-selected stack-home/register basin, not behavior/layout.
// - Exact 004C9360-style row/column offset-count countdown loops with typed
//   row and tile pointers reached exact size and improved shape to 73.39%, but
//   positional drift worsened to 293 bytes from the clean 247-byte basin.
// - Removing the x-bound swap narrowing cast was an emitted-code duplicate.
//   Restored the clean natural tile-row source; the donor loop pattern is not
//   a better living reconstruction for this target.
// - Current worker: rechecked the clean source (288B, 247 differing bytes).
//   Explicit row/tile byte-offset countdown loops reached exact size and 73.39%
//   shape, but remained 293 differing bytes. Declaration order, short swap,
//   pointer spelling, volatile count, and index-loop variants were duplicates
//   or worse. Restored the clean source; the unresolved issue is VC5 register
//   and stack-home allocation, not behavior or layout.
// - Session sa-cbc3d2f1-r1: typed short-index count do-loops improved structure
//   to 79.82% shape and 266 differing bytes, but added five bytes and changed
//   the target's tile/count register basin. Int-count and asymmetric-bound
//   variants were worse. Restored the clean ordinary-loop source.
```
<!-- end-recovered:f5d36d87e08d85afd12f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
