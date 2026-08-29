# Recovery journal: 0050F8D0 `check_tile_for_forest_change`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tmap.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tmap.cpp`.
- Earlier recovery note: `recovery_notes/tmap_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:c27ad5cc98805b99b628 -->
### `target-session` `build/target_sessions/0050F8D0_check_tile_for_forest_change.json:1-41`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=255; shape=76.25: Baseline current clean scratch reconstruction; establish authoritative metrics, call map, block map, and frame.
probe 2 layout; result=MISMATCH; diff=259; shape=75.625: Reordered coordinate declarations to y bounds before x bounds, testing original preamble schedule and parameter colors.
probe 4 liveness; result=MISMATCH; diff=384; shape=76.58227848101266: Reordered object_found before changed to test original BL flag initialization at line 220 and delayed changed-byte store.
probe 6 control-flow; result=MISMATCH; diff=405; shape=71.15384615384616: Replaced indexed neighborhood loops with typed row-pointer and cell-pointer countdown loops, testing original row/cell cursor topology.
probe 8 liveness; result=MISMATCH; diff=255; shape=76.25: Applied period register qualifier to x, testing whether explicit parameter register pressure recovers original EBX x color. [same emitted code as probe 1]
probe 10 liveness; result=MISMATCH; diff=416; shape=73.71794871794872: Moved tile declaration before coordinate locals and assignment after flag declarations, testing original line-212 declaration/initialization ordering.
probe 12 liveness; result=MISMATCH; diff=255; shape=76.25: Added explicit col/row aliases before tile lookup, testing whether source-level coordinate ownership recovers original EBX/EBP colors without behavior change. [same emitted code as probe 8]
probe 16 control-flow; result=MISMATCH; diff=394; shape=79.74683544303798: Natural typed row_tile traversal: cache each row's first tile and advance it across the inner loop, testing whether VC5 hoists the x-stride and matches the oracle row/column cursors.
probe 18 control-flow; result=MISMATCH; diff=293; shape=77.21518987341773: Restored the decompiler-supported natural neighborhood walk: one mutable column cursor, a guarded do-loop over rows, and row reset after each inner scan.
probe 20 layout; result=MISMATCH; diff=406; shape=72.78481012658227: Matched the decompiler's proven evaluation order: initialize y bounds, compute the typed tile, then initialize x bounds.
probe 22 layout; result=MISMATCH; diff=386; shape=78.26086956521739: Named each typed row base before indexed terrain access, testing whether VC5 preserves the oracle's row-pointer ownership without raw cursor plumbing.
probe 24 abi; result=MISMATCH; diff=255; shape=76.25: Added the proven map vtable slot while preserving all reviewed map offsets, testing whether the canonical polymorphic owner changes VC5 member-call or register lowering. [same emitted code as probe 15]
probe 26 liveness; result=MISMATCH; diff=416; shape=74.35897435897436: Moved the typed tile initializer after the x/y bound locals, testing whether longer-lived x bounds recover the oracle EBX/EBP parameter colors without aliases.
probe 28 control-flow; result=MISMATCH; diff=394; shape=79.74683544303798: Used a typed row_tile cursor with the increment in the natural for-loop update clause, testing whether VC5 emits the oracle's tile-stride update order. [same emitted code as probe 16]
probe 30 liveness; result=MISMATCH; diff=255; shape=76.25: Named the typed map-row table once and reused it for tile and neighborhood reads, testing whether explicit owner liveness matches the oracle's retained ECX row-table base. [same emitted code as probe 24]
probe 32 liveness; result=MISMATCH; diff=255; shape=76.25: Applied the period register qualifier to read-only y, testing the remaining natural parameter-color axis after the earlier x qualifier duplicate. [same emitted code as probe 30]
probe 34 control-flow; result=MISMATCH; diff=255; shape=76.25: Made the forest scan's column cursor explicit and reset it after each row, mirroring the oracle's reused inner counter while retaining typed indexed terrain access. [same emitted code as probe 32]
probe 37 layout; result=MISMATCH; diff=255; shape=76.25: Tested signed char terrain field against the original byte-mask lowering; period type hypothesis. [same emitted code as probe 36]
probe 39 control-flow; result=MISMATCH; diff=255; shape=76.1006289308176: Tested the original decompiler-supported row and cell pointer/count shape with int loop counts; checks whether VC5 recovers the oracle's pointer induction.
probe 40 control-flow; result=MISMATCH; diff=424; shape=75.9493670886076: Matched the oracle's precomputed first cell, positive row guard, inner positive guard, and post-row cell recomputation; natural pointer induction shape.
probe 42 behavior; result=MISMATCH; diff=387; shape=74.84662576687117: Tested a named byte terrain local supported by the oracle's AL mask/compare sequence; no raw cursor or steering.
probe 46 liveness; result=MISMATCH; diff=255; shape=76.25: Combined register qualification on both short coordinate formals; tests whether VC5 retains both incoming coordinates in the oracle EBX/EBP entry colors rather than the previously tested single-qualifier basins. [same emitted code as probe 45]
probe 48 abi; result=MISMATCH; diff=255; shape=76.25: Swapped the formal short-coordinate order while preserving external column/row behavior in all tile, bound, change_terrain, and recursive-call expressions; tests whether VC5 formal allocation order explains oracle x=EBX and y=EBP. [same emitted code as probe 46]
probe 50 context; result=MISMATCH; diff=255; shape=76.25: Added the period-supported stdlib header used by an exact-adjacent tmap.cpp donor; tests whether translation-unit header state selects the oracle coordinate register basin without source-model drift. [same emitted code as probe 48]
probe 52 abi; result=MISMATCH; diff=255; shape=76.25: Replaced the raw eight-byte map prefix with a declaration-only virtual RGE_Map destructor plus four-byte gap; tests the proven polymorphic tmap owner surface rather than a raw vptr field. [same emitted code as probe 50]
probe 54 context; result=MISMATCH; diff=255; shape=76.25: Added the full declaration-only RGE_Map virtual prefix from an exact adjacent tmap.cpp donor, retaining the proven +8/+C/+8D8C offsets; tests translation-unit class-surface influence on the unresolved coordinate register basin. [same emitted code as probe 52]
probe 57 context; result=MISMATCH; diff=255; shape=76.25: Added the period-supported stdlib context required by an exact later tmap.cpp anchor. This tests authentic front-end state before changing the reconstructed forest loops. [same emitted code as probe 56]
probe 58 control-flow; result=MISMATCH; diff=419; shape=91.02564102564102: Restored the decompiler-supported y-bound-first declaration order and typed row-pointer/count forest scan. This tests the oracle's retained row table, 24-byte tile cursor, and counted do-loops without raw byte cursors.
probe 59 liveness; result=MISMATCH; diff=296; shape=96.15384615384616: Moved the center tile initializer back to PDB line 212 while retaining the proved y-bound order and counted forest scan. This tests top-level declaration timing after correcting the late loop model.
probe 60 control-flow; result=MISMATCH; diff=289; shape=64.55696202531645: Replaced the promoted switch expression with the decompiler-supported unsigned-byte terrain value and if/else-if dispatch. This tests the oracle's AL mask and byte compares while preserving case order.
probe 61 liveness; result=MISMATCH; diff=78; shape=96.15384615384616: Split the forest row-cursor and first-tile declarations from assignment. This tests the oracle's current-row cursor ownership and offset-before-row-load schedule.
probe 62 liveness; result=MISMATCH; diff=76; shape=96.7948717948718: Initialized the first forest tile before the row cursor, using the same typed row table for both. This tests offset-first scheduling while keeping the cursor at the current row.
probe 63 control-flow; result=MISMATCH; diff=384; shape=75.64102564102564: Advanced the typed row cursor before reading the next row in separate statements. This tests whether statement order recovers the oracle's plus-four load and later cursor update.
probe 64 liveness; result=MISMATCH; diff=76; shape=96.7948717948718: Named the next row pointer before adding the fixed x offset and publishing the cursor advance. This tests the oracle's separate next-row load and pointer update. [same emitted code as probe 62]
probe 66 context; result=MISMATCH; diff=76; shape=96.7948717948718: Replaced duplicated target-local classes with canonical tmap_context.h before grouped owner test; preserves proven map/tile/world offsets and PDB owner ABI. [same emitted code as probe 65]
probe 67 context; result=MISMATCH; diff=76; shape=96.7948717948718: Added real exact 0050F410 constructor owner before 0050F860 and targets in the PDB-ordered wrapper; canonical virtual map surface preserves +8/+C/+8D8C. [same emitted code as probe 66]
probe 69 context; result=MISMATCH; diff=76; shape=96.7948717948718: Fresh grouped check: src/tmap_tu.cpp includes real PDB-ordered owners 0050F410, 0050F760, 0050F7A0, 0050F7B0, 0050F7C0, 0050F7F0, 0050F800, 0050F860, then this owner and 0050FA90. With /nologo /c /O2 /Oy /GX, owner symbol matches PDB and output remains 434B/76-diff; grouped context does not materialize the current row slot. [same emitted code as probe 68]
probe 70 context; result=MISMATCH; diff=76; shape=96.7948717948718: Final grouped wrapper check after restoring the PDB-accurate virtual save surface: /O2 /Oy /GX, owner symbol remains PDB-qualified, and the canonical prefix emits 433B with a 76-byte diff. It still does not recover the current row-slot load; the isolated owner remains 434B.
probe 74 liveness; result=MISMATCH; diff=78; shape=96.15384615384616: Test row-cursor-first initialization so VC5 must materialize the row slot before the first forest tile, as in the oracle.
probe 76 baseline; result=MISMATCH; diff=76; shape=96.7948717948718: Fresh Phase 4 baseline after prior-results review; authentic tmap.cpp wrapper and direct-loop source retained. [same emitted code as probe 75]
probe 77 layout; result=MISMATCH; diff=76; shape=96.7948717948718: Test loop-local row tile with row cursor initialized before the guarded scan. Distinct declaration-scope hypothesis targets the oracle LEA row-slot and spilled tile sequence; prior assignment-order probe was not reused. [same emitted code as probe 76]
```
<!-- end-recovered:c27ad5cc98805b99b628 -->

<!-- recovered:79b70109254232da36f3 -->
### `7219a9ef8fce` `src/scratch/0050F8D0_check_tile_for_forest_change.cpp:1-78`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0050F8D0 check_tile_for_forest_change (434B)
// tmap.cpp
//
// Attempt log:
// baseline: clean reconstruction from the packet's forest/wood object-list
// behavior and the exact tmap.cpp tile layout.
// probes 2-8: switch dispatch, tile initializer order, byte/typed tile
// surfaces, parameter naming, and register declarations were tested; the
// switch form is the best structural basin (0x14 frame, 3 calls, 75.16%
// shape, 388-byte strict diff).
// probe 9: explicit pointer/count neighborhood loops were rejected; they
// increased the code to 454 bytes. Restored the natural nested loops.
// probes 11-13, 17: unqualified/qualified recursive calls, a reversed tile
// address, and an explicit zero guard were codegen duplicates. Probes 14-16
// changed bound declaration/address order but worsened the structural basin.
// probe 20: inlined the one-use terrain expression in the switch; this
// natural local-lifetime change improved strict diff 388 -> 384 bytes but
// left the first prologue hunk and recursive-call relocation unchanged.
// probe 35: declared the changed flag before object_found; VC5 moved the
// flag homes and reduced strict diff 384 -> 255 bytes, but did not fix the
// parameter colors or recursive relocation.
// probes 36-37: swapped parameter identifiers and used native bool flags;
// both were codegen duplicates. Probe 38: explicit row/tile pointers made
// the source less natural and widened the diff to 388 bytes; restored.
// probe 39: unqualified change_terrain calls were a codegen duplicate.
// sa-068dd50f-r1 pass: revalidated the typed tile stride (0x18), terrain byte
// (+5), object-list link (+0x10), master id (+0x14), object field (+0x48),
// map dimensions (+8/+C), and row table (+0x8D8C). Tested coordinate
// declaration order, flag order, pointer/count loops, tile initialization,
// register qualification, and coordinate aliases. Only the current clean
// direct-loop basin remained plausible; final validation is 423/434 bytes,
// 255 differing bytes, 0x14 frame, and 3 calls. The unresolved drift is
// parameter register coloring, forest-loop lowering, and self-call identity.
// sa-0cb5a865-r1 revisit: Ghidra-supported mutable-column traversal improved
// structural resync but worsened strict bytes; typed row cursors, map-row
// aliases, a proven vtable slot, declaration orders, and y/register qualifiers
// were worse or codegen duplicates. Restored the clean direct-loop source.
// sa-86e6c1ab-r1 revisit: signed terrain typing was a codegen duplicate. An
// int row/cell pointer-count loop reduced edit cost but kept 255 strict bytes;
// precomputed pointer guards and a named terrain byte worsened the basin.
// Restored the pinned direct-loop source. Final validation remains 255 differing
// bytes, 423/434 bytes, 0x14 frame, 3 calls, and unresolved self-call identity.
// sa-987bfe3a-r1 probes 46-54: qualifying both coordinate formals, swapping
// their formal order while preserving behavior, adding <stdlib.h>, and adding
// declaration-only polymorphic/full tmap map surfaces were all codegen
// duplicates at 255 differing bytes. Restored the pinned direct-loop source.
// left in scratch: behavior and field ownership are reconstructed; remaining
// drift is prologue/register scheduling plus recursive-call relocation. The
// best validated source is the flag-order variant at 255 differing bytes.
// sa-557c93eb-r1: restored the PDB line-212 center-tile initializer, y-bound
// declaration order, a byte switch selector, and the decompiler-supported
// typed counted forest scan. The result has the exact 434-byte boundary,
// frame, calls, CFG counts, and first 102 instructions through +0x12C.
// The strict diff fell from 255 to 76 bytes. The remaining emitted drift is
// localized to forest row-slot addressing: the executable materializes the
// current row slot, while VC5 folds that slot into the first indexed load and
// biases the later cursor to the next row. Equivalent typed cursor order,
// split assignments, a named row table, and a named next-row pointer were
// duplicates. Pre-increment forms changed the complete register basin.
// sa-13047c13-r1 grouped context: the owner-include wrapper compiled this
// owner and 0050FA90 in PDB order with /O2 /Oy /GX. Exact sibling anchors
// 0050F410, 0050F760, 0050F7A0, 0050F7B0, 0050F7F0, 0050F800, and 0050F860
// stayed exact in fresh standalone checks. The grouped owner symbol is
// PDB-qualified. The context-enabled owner now emits 433 bytes with the same
// 76-byte diff in both isolated and grouped builds. The grouped context does
// not recover the row-slot load; the prior clean source was 434 bytes.
// sa-7e83054e-r1 fresh context gate: module tmap.cpp, source band 210-259,
// owner TRIBE_Map, address sequence 0050F8D0 then 0050FA90, and exact wrapper
// anchors through 0050F860 are proved by the PDB line map and grouped checks.
// The copied prior journal already rejects equivalent cursor-order forms. A
// fresh loop-local scope edit was attempted, then restored after its compile
// error. The remaining drift is the forest row-slot lowering and the
// diagnostic recursive-call identity.
// sa-11e4b4c9-r1 captain validation: the fresh dossier confirms module tmap.cpp,
// band 210-259, TRIBE_Map ownership, and the address sequence above. Wrapper
// anchors remain exact. Baseline is 433 rebuilt bytes versus 434, with 76
// strict differing bytes and 3 calls. The clean source is restored; the
// remaining row-slot and diagnostic self-call differences are unresolved.
```
<!-- end-recovered:79b70109254232da36f3 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
