# Recovery journal: 004579C0 `load_map`

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


<!-- recovered:730291f529b704c30866 -->
### `target-session` `build/target_sessions/004579C0_load_map.json:1-10`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=312; shape=90.36697247706422: Clean typed source baseline before new evidence; establish behavior, calls, frame, and first mismatch.
probe 2 context; result=MISMATCH; diff=226; shape=91.28440366972477: Add donor-supported <stdlib.h> TU context; exact scenario_load in map.cpp uses it and source remains typed.
probe 3 liveness; result=MISMATCH; diff=226; shape=91.28440366972477: With donor-supported stdlib context, swap natural h/y declaration order to test target stack-home ownership without opaque aliases. [same emitted code as probe 2]
probe 4 control-flow; result=MISMATCH; diff=215; shape=92.20183486238533: Reorder final border reconstruction before its independent draw-state stores, matching map.cpp line bands and preserving typed tile loading.
probe 5 liveness; result=MISMATCH; diff=213; shape=95.87155963302752: Scope each height counter to its format arm, a natural reconstruction of independent old/new loops, to test the proven target h home.
probe 6 control-flow; result=MISMATCH; diff=224; shape=94.95412844036697: With arm-local height scope fixed, restore draw-state-before-border source order to test the target's deferred cleanup and field-store schedule.
probe 7 liveness; result=MISMATCH; diff=213; shape=95.87155963302752: Scope each column counter to its format-loop body, a natural lifetime variant that may reproduce target zero-store and tail scheduling.
probe 8 layout; result=MISMATCH; diff=213; shape=95.87155963302752: Widen the scoped column counters to long to test whether target dword loop-home scheduling reflects map.cpp long dimensions. [same emitted code as probe 7]
probe 9 liveness; result=MISMATCH; diff=191; shape=98.1651376146789: Reverse natural tile and column update statements to test the target's observed add-tile/inc-counter emission order.
probe 10 liveness; result=MATCH; diff=0; shape=100.0: Move draw-state zero stores before typed object-list reset to test whether VC5 emits the target immediate zeros after its x87/tile work.
```
<!-- end-recovered:730291f529b704c30866 -->

<!-- recovered:3e4ca9b7d9a79b4e7f1d -->
### `734c2061d252` `src/scratch/004579C0_load_map.cpp:1-26`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004579C0 RGE_Map::load_map
// Attempt log:
// - Baseline uses the proven RGE_Map offsets, 24-byte RGE_Tile layout, old and
//   new file formats, zone-list replacement, and unified visibility loading.
// - Swapping row and column declaration order was a codegen duplicate.
// - Fresh typed reconstruction below follows the map.cpp tile field names and
//   the executable's error-safe allocation and cleanup path.
// - A function-scope byte scratch improved the typed source by five positional
//   bytes; the remaining row-home mismatch stayed structural.
// - The executable stores tile object counts as words.  Keep the 0x18-byte tile
//   layout and the old-format bulk read with its post-read list reset.
// - Ten meaningful probes completed.  The clean typed source is retained in
//   scratch because the remaining drift is broad loop stack-home scheduling.
// - Initializing the inner column counter before loading the row pointer was a
//   natural map.cpp line-order probe; VC5 emitted the same code, so it was
//   restored.
// - Split the outer long height counter from the inner int column counter,
//   matching the original local types and h/y loop ownership; codegen was a
//   duplicate, so the canonical typed loop form remains unresolved.
// - Swapping h/y declarations and preserving the file parameter in a second
//   int were duplicates. A separate old-format x counter changed no metrics.
// - Modeling the RGE_Object_List vtable and changing h to int were duplicates.
// - Tile bitfields worsened the structural result to 325 bytes; restored the
//   proven byte-field source. Old-format-first source worsened it to 428 bytes.
// - Restored the clean typed source. The first structural gap remains the
//   compiler's h/y stack-home assignment at the modern loop entry.
```
<!-- end-recovered:3e4ca9b7d9a79b4e7f1d -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
