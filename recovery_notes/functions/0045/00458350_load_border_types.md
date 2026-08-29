# Recovery journal: 00458350 `load_border_types`

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


<!-- recovered:d37b5659f297aa8a6890 -->
### `target-session` `build/target_sessions/00458350_load_border_types.json:1-25`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=492; shape=83.33333333333333: Validate current typed scratch reconstruction before fresh probes.
probe 2 liveness; result=MISMATCH; diff=502; shape=77.31481481481481: Reordered locals to the map.obj PDB symbol surface and restored parsed field ownership.
probe 4 liveness; result=MISMATCH; diff=492; shape=83.33333333333333: Tested the PDB-named function-scope parsed id while retaining the clean field and loop model. [same emitted code as probe 1]
probe 5 liveness; result=MISMATCH; diff=492; shape=83.33333333333333: Tested block-scoped row_start with a function-scope cursor for the nested 19x12 grid. [same emitted code as probe 4]
probe 6 variant; result=MISMATCH; diff=492; shape=83.33333333333333: variant lab build\variant_lab\00458350_load_border_types\20260817_130251: 6 variants, 6 invariant-eligible, 0 exact
probe 7 abi; result=MISMATCH; diff=502; shape=77.31481481481481: Tested canonical PDB-named parsed field ownership and trailing record stores with the existing declaration basin. [same emitted code as probe 2]
probe 9 liveness; result=MISMATCH; diff=492; shape=83.33333333333333: Tested valid-arm declaration initialization for the typed grid cursor. [same emitted code as probe 6]
probe 11 liveness; result=MISMATCH; diff=492; shape=83.33333333333333: Swapped the function-scope typed grid-pointer declarations to test declaration-order effects on the row-anchor home. [same emitted code as probe 9]
probe 12 liveness; result=MISMATCH; diff=492; shape=83.33333333333333: Tested function-scope row and column counters against the target dword loop homes. [same emitted code as probe 11]
probe 13 liveness; result=MISMATCH; diff=492; shape=83.33333333333333: Moved the row-anchor declaration after parsed buffers to test source lifetime and stack-home allocation. [same emitted code as probe 12]
probe 14 layout; result=MISMATCH; diff=492; shape=83.33333333333333: Tested PDB-supported resource_id-before-infile declaration order against the four-byte local-home shift. [same emitted code as probe 13]
probe 15 layout; result=MISMATCH; diff=492; shape=83.33333333333333: Tested the complete PDB-supported interval/resource_id/infile/pause declaration sequence. [same emitted code as probe 14]
probe 20 liveness; result=MISMATCH; diff=492; shape=83.33333333333333: Moved parsed fields, buffers, and grid cursors into the per-record block, matching map.cpp parser scope style. [same emitted code as probe 19]
probe 22 control-flow; result=MISMATCH; diff=408; shape=79.4392523364486: Rewrote the 19x12 grid as nested natural do/while cursors with row anchor and cell cursor, testing original rotated CFG.
probe 24 liveness; result=MISMATCH; diff=408; shape=79.4392523364486: Made row_start the persistent outer cursor and p a per-row cursor, preserving both typed pointer roles while testing home allocation. [same emitted code as probe 22]
probe 26 control-flow; result=MISMATCH; diff=408; shape=78.97196261682242: Used explicit cell and animations cursors for each 19x12 row, matching the binary's separate +0/+2 pointer increments without raw byte cursors.
probe 28 abi; result=MISMATCH; diff=492; shape=83.33333333333333: Changed the positive sound-index expression to typed pointer arithmetic so the sign-extended index can precede the sounds-table load, matching the target block. [same emitted code as probe 20]
probe 30 abi; result=MISMATCH; diff=492; shape=83.33333333333333: Restored the decompiler's separate FILE local and float input naming (local_30/infile/interval) while keeping corrected field ownership. [same emitted code as probe 28]
probe 35 control-flow; result=MISMATCH; diff=492; shape=84.11214953271028: Exact-finish loop-shape family: natural p-outer two-cursor source stayed in the 673-byte basin; row-outer source fell to 656 bytes and 0x54 frame. It did not recover the oracle's +0x24 row-anchor or +0x30 inner/outer homes, so keep the pinned loop source. [same emitted code as probe 34]
probe 36 context; result=MISMATCH; diff=492; shape=84.11214953271028: Exact-finish authentic-context family: unregistered wrappers with real map.cpp constructor/clean_elevation prefixes, windows.h header order, and /GX all emitted the same source basin. No grouped context or EH change is supported. [same emitted code as probe 35]
probe 37 liveness; result=MISMATCH; diff=492; shape=84.11214953271028: Exact-finish pointer-order family: both natural declarations of p and row_start emitted the same 673-byte basin. Do not use the 00457F80 float/filename local alias; target keeps distinct FILE and float parser locals. [same emitted code as probe 36]
probe 39 context; result=MISMATCH; diff=492; shape=84.11214953271028: Added required period map.cpp <windows.h> before the existing CRT headers; test authentic donor context before further structure edits. [same emitted code as probe 38]
probe 40 control-flow; result=MISMATCH; diff=492; shape=84.11214953271028: Restored the period map.cpp do/while row and column counters used by the exact terrain loader donor; test natural two-counter source against the target nested-grid CFG. [same emitted code as probe 39]
probe 41 control-flow; result=MISMATCH; diff=408; shape=79.4392523364486: Made row_start the persistent outer cursor and p the per-row cursor, matching the oracle's explicit reload/reset and +0x48 row advance topology. [same emitted code as probe 24]
probe 42 control-flow; result=MISMATCH; diff=408; shape=79.4392523364486: Tested direct typed 19x12 border array indexing with one cell pointer per iteration; this is a natural alternative to the moving-cursor reconstruction. [same emitted code as probe 41]
```
<!-- end-recovered:d37b5659f297aa8a6890 -->

<!-- recovered:575d18fb4966280bd17f -->
### `489810cbdcd9` `src/scratch/00458350_load_border_types.cpp:1-80`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00458350 RGE_Map::load_border_types
// Attempt log:
// 1: packet/decompiler based implementation had an approximate border record,
//    used strupr instead of convert_us, used the wrong tile shape-index store,
//    and returned before the original unconditional fclose; it was 771 bytes.
// 2: clean reconstruction: use the binary-proven RGE_Border_Set ownership and
//    0x5A0 record stride, the original 16-field fscanf format, convert_us and
//    intrinsic strcpy copies, and the 19x12 RGE_TOB_Picts grid.
// 3: guard the full record body instead of breaking on malformed/out-of-range
//    records; this restored the original seven ordered call sites and shared
//    resource-count tail.  The remaining structural gap is local pointer/frame
//    placement around the nested grid.
// 4: tested the binary-proven four-byte input-buffer payload offset
//    (name+4/pict_name+4 in the giant fscanf); the final clean source keeps
//    ordinary name/pict copies because that spelling emits the better basin.
// 5: the clean typed row-anchor pair reached exact size/frame but the anchor
//    spilled at +0x3C instead of the oracle's +0x24.  Test a binary-backed
//    pointer/float local overlay to let VC5 classify that proven stack slot.
// 6: final ABI/local-home probe follows the listing's true ownership: the
//    second %f is a float local named infile, while local_30 is the FILE* used
//    by all stream calls (the decompiler had these names crossed).
// 7: declaration reordering, the period CRT header combination, the 17-byte
//    prefixed-buffer variant, a typed pointer/float union, and the corrected
//    FILE*/float naming all either duplicated the 679-byte result or worsened
//    it.  Best clean reconstruction is exact in size/frame and all seven
//    ordered calls; remaining drift is VC5 local-home/register/block placement
//    around the row anchor and downstream field scheduling.
// 8: left in scratch after the 10-hypothesis budget.  The executable proves
//    the 0x338C map base, 0x5A0 border stride, +0x42 19x12 record grid, and
//    +0x28..+0x41 animation fields; do not replace these with raw decompiler
//    offsets.  Next lead is a fresh map.cpp donor/TU-local declaration-order
//    reconstruction for the +0x24 row-anchor versus +0x28 frame-rate homes.
// Fresh pass: a single cursor with p += 12 reduced the diagnostic diff but
// removed the target row-anchor spill and frame bytes, so it was restored.
// Reversed cursor roles, declaration order, and explicit count-down loops did
// not change or improve the exact-size clean basin. The typed two-cursor source
// remains the best period-plausible reconstruction; the row-anchor home is the
// open blocker.
// 9: packet-backed parser surface: restored the original semantic FILE* `infile`
// name and separate float `pause_between_loops` local before the resource loop;
// this tests the natural map.cpp declaration/use shape at the first fopen hunk.
// Fresh pass, probes 2-12: map.obj PDB local declaration order and canonical
// parsed field names worsened or duplicated the clean basin. Function-scope and
// block-scope row anchors, pointer declaration order, valid-arm cursor init,
// function-scope row/column counters, late row-anchor declaration, and the
// PDB-supported resource_id/infile orders all emitted the same 679-byte group.
// A six-variant row-anchor lab tested function/block scope, typed indexing, and
// cursor rebasing. All six matched the clean group; none moved the +0x24 home.
// The PDB confirms RGE_Border_Set size 0x5A0, RGE_TOB_Picts size 6, and all
// member offsets used here. The remaining binary-backed gap is local-home and
// register placement, not ownership, size, calls, or cleanup.
// Fresh pass: per-record parser scope duplicated the clean 679-byte result.
// Nested do/while cursors reduced the raw diff to 408 bytes, but removed the
// target frame and two-pointer loop shape (656 bytes versus 679); restore it.
// Persistent outer-cursor and explicit animation-pointer variants stayed in
// that same 656-byte basin. The decompiler's separate FILE/float local names
// also duplicated the clean 679-byte result. Keep the typed for-loop source.
// 10: exact-finish context checks used unregistered wrappers with real map.cpp
// constructor and clean_elevation prefixes, windows.h order, and /GX. They
// emitted the same basin. Natural p-outer and row-outer loop forms emitted
// 673 and 656 bytes; pointer declaration order did not change the result.
// Keep the target's distinct FILE/float parser locals. Do not copy the
// 00457F80 donor's invalid float/filename alias. Fresh validation still shows
// seven ordered calls, the correct owner symbol, 0x58 frame, and 673 rebuilt
// bytes against the 679-byte target boundary.
// Exact-finish validation: <windows.h> is required by the period map.cpp
// context, but it is codegen-neutral here. The natural nested do/while and
// persistent row-cursor forms were tested and restored: they emit a 656-byte,
// 0x54-frame basin with the same seven calls. Keep the clean p-outer form.
// Accepted-drift blocker: the giant fscanf writes unbounded strings at name+4
// and pict_name+4, then convert_us/strcpy consume each buffer from its base.
// Different stack homes can change the four-byte prefixes and malformed-input
// overflow fault addresses. Keep this parser in scratch.
//
// The border record layout is shared with the exact map.cpp constructors and
// update routine.  The map file's signed color/index locals intentionally retain
// their narrow input widths; only the resource id and timing values are widened
// at the operations where the original ABI requires it.
// BINARY NOTE (map TU wave02): The authentic grouped wrapper keeps the same
// 492-byte parser basin.  No source-only repair is supported.
```
<!-- end-recovered:575d18fb4966280bd17f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
