# Recovery journal: 0053CAC0 `explore_terrain_sq`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/visible.cpp`.
- PDB source: `C:\msdev\work\age1_x1\visible.cpp`.
- Earlier recovery note: `recovery_notes/visible.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e21f0e512aeccb7695b1 -->
### `target-session` `build/target_sessions/0053CAC0_explore_terrain_sq.json:1-37`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=424; shape=77.5: Current typed terrain visibility source establishes call set, bounds, row/column loop, and 550-byte candidate baseline.
probe 2 context; result=MISMATCH; diff=426; shape=76.73267326732673: Tested period absolute global surfaces for Map_Update_Suppresion and unified_map_offsets; checks relocation/address lowering without changing terrain ownership.
probe 4 context; result=MISMATCH; diff=424; shape=77.5: Tested only the suppression global as a period absolute address while retaining the typed unified-map array; isolates global relocation from terrain source shape.
probe 5 liveness; result=MISMATCH; diff=424; shape=77.5: Reordered checksum before Revealed and moved visibility cursors after the checksum to test the proven [ebp-4] checksum/p cursor overlap and [ebp-8] Revealed home. [same emitted code as probe 1]
probe 7 liveness; result=MISMATCH; diff=423; shape=77.5: Tested direct repeated input_csum member updates instead of a named checksum local; this probes whether the proven checksum/pursor slot is a compiler lifetime merge.
probe 9 control-flow; result=MISMATCH; diff=425; shape=79.0: Tested advancing the typed terrain tile cursor before the visible-byte store; the oracle loads and updates the tile home early in the late cell tail.
probe 10 layout; result=MISMATCH; diff=423; shape=78.7128712871287: Tested named width/height bounds locals so the height load can survive from the y rejection test through the y2 clamp, matching the original +18 field load and reuse.
probe 11 control-flow; result=MISMATCH; diff=423; shape=78.7128712871287: Split the y-axis rejection into two positive early-return statements to test whether the original PDB line bands preserve the height value and branch topology. [same emitted code as probe 10]
probe 12 liveness; result=MISMATCH; diff=423; shape=78.7128712871287: Separated Revealed declaration from its zero assignment immediately before log_map_call to test the original delayed [ebp-8] initialization without changing behavior. [same emitted code as probe 11]
probe 13 context; result=MISMATCH; diff=423; shape=78.7128712871287: Applied the period absolute suppression address to the improved typed bounds/tile-order source; verifies that this context axis preserves the structural gain.
probe 14 context; result=MISMATCH; diff=426; shape=79.1044776119403: Tested both proven absolute globals together against the typed bounds/tile-order candidate; isolates unified-map relocation and row-address lowering.
probe 15 abi; result=MISMATCH; diff=423; shape=78.7128712871287: Tested a bounded 256-row type for the unified terrain visibility array instead of an unsized external array; verifies reviewed array ownership without raw addressing. [same emitted code as probe 13]
probe 16 control-flow; result=MISMATCH; diff=423; shape=78.7128712871287: Tested explicit inner while topology with a function-local x induction variable against the original pretested row/column loop CFG. [same emitted code as probe 15]
probe 18 liveness; result=MISMATCH; diff=423; shape=78.7128712871287: Reordered locals to the binary/decompiler order: isCurPlayer, curVisPlayer, Revealed, p, unified, tile, checksum; tests natural stack-home rotation without changing behavior. [same emitted code as probe 17]
probe 20 liveness; result=MISMATCH; diff=423; shape=78.7128712871287: Used the proven byte-pointer stack owner p for the checksum phase, with explicit integer casts, to test whether the oracle's checksum/p home reuse is source-level pointer reuse. [same emitted code as probe 18]
probe 22 abi; result=MISMATCH; diff=423; shape=78.7128712871287: Restored normal C++ linkage for the proven direct log_map_call target, matching the exact donor declaration and testing symbol-identity/codegen context.
probe 25 abi; result=MISMATCH; diff=423; shape=78.7128712871287: Restored normal C++ linkage for the direct log_map_call declaration, matching the exact visible.cpp donor. [same emitted code as probe 22]
probe 26 liveness; result=MISMATCH; diff=423; shape=78.7128712871287: Scoped row cursors at their first row use, testing whether VC5 coalesces the checksum spill with the later visible cursor home. [same emitted code as probe 25]
probe 27 control-flow; result=MISMATCH; diff=423; shape=78.7128712871287: Replaced four early-return bounds checks with the Ghidra-supported nested positive rectangle guard, preserving one late failure epilogue and original height-load order. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=454; shape=76.11940298507463: Address-took the checksum temporary through a local pointer, testing whether the binary-proven checksum/visible cursor stack home is source-level address-taken liveness.
probe 30 liveness; result=MISMATCH; diff=423; shape=78.7128712871287: Declared the checksum accumulator at its first use after the suppression guard, testing declaration scope as the local-home allocator axis. [same emitted code as probe 24]
probe 31 liveness; result=MISMATCH; diff=423; shape=78.7128712871287: Introduced one natural self alias across the member body, testing whether original this-pointer liveness controls local-home allocation. [same emitted code as probe 30]
probe 33 liveness; result=MISMATCH; diff=423; shape=78.7128712871287: Used one integer local for the checksum and visible cursor through an explicit 32-bit cast, testing whether the binary's proven home reuse is a true source-level value reuse. [same emitted code as probe 31]
probe 35 liveness; result=MISMATCH; diff=447; shape=74.8768472906404: Introduced a distinct row induction local after clamping, testing whether original y1-home reuse comes from a source-level row cursor.
probe 37 control-flow; result=MISMATCH; diff=425; shape=79.20792079207921: Moved the proven zero-tile value assignment before the explored-mask store, matching original AL/store order at visible.cpp:862.
probe 38 liveness; result=MISMATCH; diff=425; shape=79.20792079207921: Named the explored mask at the revealed-cell tail, testing whether a branch-local mask value recovers the oracle's EAX/ECX store topology. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=425; shape=87.5: Declared the inner x induction variable before the conditional tile-row setup, testing whether its early lifetime preserves EBX while tile addressing uses ECX.
probe 40 liveness; result=MISMATCH; diff=425; shape=87.5: Reused the visible cursor pointer p for the checksum phase after moving x lifetime before tile setup, testing the combined original-home hypothesis. [same emitted code as probe 39]
probe 41 liveness; result=MISMATCH; diff=459; shape=81.81818181818181: Forced hash operand rereads from the proven parameter homes, testing whether original memory-form XORs reflect required source-level volatile aliasing.
probe 43 liveness; result=MISMATCH; diff=425; shape=88.0: Moved the existing x declaration before tile setup without changing tail statement order, isolating its contribution to the strong register and block-shape gain.
probe 44 liveness; result=MISMATCH; diff=425; shape=88.0: Added a nonvolatile reference alias only for x2's checksum use, testing whether reference syntax preserves its parameter-home load without volatile codegen. [same emitted code as probe 43]
probe 45 liveness; result=MISMATCH; diff=425; shape=88.0: Moved checksum declaration ahead of cursor and result locals while retaining early x lifetime, testing declaration-order pressure after the shape basin improved. [same emitted code as probe 44]
probe 47 liveness; result=MISMATCH; diff=425; shape=88.0: Used a union to model the binary-proven checksum-to-visible-pointer home overlap, testing whether one four-byte source object recovers the hash spill. [same emitted code as probe 45]
probe 49 control-flow; result=MISMATCH; diff=425; shape=89.0: Moved unconditional tile-cursor advancement after visible, unified, and x updates, matching the original late pointer-update order while retaining early x lifetime.
probe 50 liveness; result=MISMATCH; diff=425; shape=89.0: Made isCurPlayer a declaration initializer immediately after suppression, testing declaration-initialization scheduling for the target's early local stores. [same emitted code as probe 49]
probe 51 liveness; result=MISMATCH; diff=417; shape=88.5: Collapsed the staged checksum updates into one nested expression matching the decompiler's uVar4 shape, testing expression scheduling after loop-shape recovery.
probe 53 context; result=MISMATCH; diff=425; shape=89.0: Temporary full visible.cpp group with PDB-ordered exact anchors. Default preserves anchors but emits 582/550 with 554 diff; /Oy- gives 550/550 with 425 diff but invalidates all anchors. [same emitted code as probe 50]
```
<!-- end-recovered:e21f0e512aeccb7695b1 -->

<!-- recovered:6463c0952b28e437af5e -->
### `986b7f44ebfa` `src/scratch/0053CAC0_explore_terrain_sq.cpp:1-32`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0053CAC0 RGE_Visible_Map::explore_terrain_sq
// Source: visible.cpp lines 775-883
// Attempt log:
// baseline candidate: canonical x/y rectangle ownership and natural symmetry with
// explore_terrain/unexplore_terrain_sq; the oracle traverses rows by y1 and columns
// from x1 through x2.
// Hoisting curVis/tile initialization before the checksum recovered the configured
// 550-byte size and the best current basin.  Canonical polymorphic surfaces were
// codegen-neutral; the remaining drift is local-slot/hash operand scheduling and
// the late result/tile tail.  No call or ownership discrepancy remains.
// Full typed RGE_Tile/RGE_Map records, top-level typed row cursors, and an unsigned
// checksum accumulator preserve canonical map ownership but emitted identically.
// Declaration order, initializer form, and p6/curVis zero-store order were likewise
// neutral. Remaining drift begins before the hash: the oracle homes Revealed at
// [ebp-8] and its checksum/visible cursor at [ebp-4], while the default donor basin
// selects the inverse homes; the later checksum/ally scheduling follows that split.
// split the x-axis and y-axis rejection tests to mirror the two original source
// line bands and preserve the height value for the following y clamp.
// Follow-up probes: checksum-before-Revealed declaration order, dead-p6 checksum
// reuse, removal of the explicit _rotl pragma, an explicit zero carried into the
// negative-bound tests, an explicit inner while loop, and an array-backed checksum
// all emitted the same 544-byte code.  The stack spill remains a source/context
// blocker, not a proven ownership or control-flow difference.
// Current pass: typed unified_map_offsets[256], named width/height bounds, and
// the pretested inner while form preserve the terrain-array ownership and 550-byte
// basin.  Claim follow-up moved the x declaration before tile setup, then moved
// unconditional tile advancement after the visible, unified, and x updates.
// These binary-supported lifetime and update-order changes recover 69.00% exact
// blocks and 89.00% shape at the staged-hash basin. Main review rejected a
// nested hash expression that only reduced positional byte differences. Keep
// the clear checksum stages. The remaining blocker is pre-hash local and
// parameter-home scheduling. No call or ownership discrepancy remains.
```
<!-- end-recovered:6463c0952b28e437af5e -->

<!-- recovered:c97c68a07fdb664cc905 -->
### `986b7f44ebfa` `src/scratch/0053CAC0_explore_terrain_sq.cpp:99-100`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Main-agent audit replaced raw absolute globals and retained canonical visible
// map ownership with natural square exploration.
```
<!-- end-recovered:c97c68a07fdb664cc905 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
