# Recovery journal: 004FAAA0 `taskExplorer`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e5f13e5bca2f9c7353bd -->
### `d050eea3c` `src/taitacmd.cpp:10584-10593`

Mapping: `strong`. next mapped function definition is taskExplorer at old line 10653.

```text
// Attempt log:
// - Replaced the decompiler-shaped two-list scaffold with the canonical
// [non-comment lines omitted during migration]
//   natural indexed scan/growth form.  Baseline: exact size/frame/calls with
// [non-comment lines omitted during migration]
// - Probe 1: restored the natural XYPoint x/y argument order in the recursive
//   overload call; MATCH (337/337 bytes).  The source order accounts for VC5's
// [non-comment lines omitted during migration]
// - Final: default /O2 /Oy, typed local layout, no inline asm or codegen-only
//   scaffolding; exact bytes validated.
```
<!-- end-recovered:e5f13e5bca2f9c7353bd -->

<!-- recovered:7bf6f6c467d470bfa363 -->
### `d050eea3c` `src/taitacmd.cpp:10647-10651`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// ---------------------------------------------------------------------------
// PDB source owner: 004FAAA0_taskExplorer.cpp
// ---------------------------------------------------------------------------
// 004FAAA0 TribeTacticalAIModule::taskExplorer (taitacmd.cpp:8897-8913)
// Attempt log:
```
<!-- end-recovered:7bf6f6c467d470bfa363 -->

<!-- recovered:34bd4f10052567bd4448 -->
### `6a2aef2e2` `src/taitacmd.cpp:9214-9223`

Mapping: `strong`. comment lies after mapped function taskExplorer at old line 9212.

```text
// 1: Natural implementation with static add_unique helper emitted helper out-of-line; function only 336B.
// 2: Inline both array-add sequences and use the canonical player surface: size matches, but search loops use pointer-walk/test max; 81.60% positional, 30.47% edit.
// 3: While with max locals improves edit to 21.68 but adds duplicate count tests and function too long.
// 9: Removed the decompiler-only positive-count guards from all bounded scans;
//     output stayed unchanged and the layout is now canonical.
// 12: Explicitly assigned civilian.numberValue before both scans; no code change.
// 13: Guarded do-while repeated scan reduced the byte diff but changed block shape;
//     restored the natural indexed for-loop.
// 14: Separate firstCount and secondCount locals did not change emitted code.
// Final: exact default-flags output, with canonical list ownership and typed dispatch.
```
<!-- end-recovered:34bd4f10052567bd4448 -->

<!-- recovered:1f8f07605085c5b6f425 -->
### `38a465a82032` `src/scratch/004FAAA0_taskExplorer.cpp:1-18`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004FAAA0 TribeTacticalAIModule::taskExplorer (taitacmd.cpp:8897-8913)
// Attempt log:
// 1: Natural implementation with static add_unique helper emitted helper out-of-line; function only 336B.
// 2: Inline both array-add sequences and pad MapThing vtable: size matches, but search loops use pointer-walk/test max; 81.60% positional, 30.47% edit.
// 3: While with max locals improves edit to 21.68 but adds duplicate count tests and function too long.
// 4: Copy loop do/while spelling produced no source change/no codegen change.
// 5: For-loop search spelling no codegen change.
// 6: int task player parameter + cast improved tail (edit 20.04%).
// 7: while(1) copy loops improved edit to 14.31 and copy loops match; function still +3/duplicate search tests.
// 8: Goto-shaped search loops worsened to 23.72 edit; rolled back to for-loop search.
// 9: Removed the decompiler-only positive-count guards from all bounded scans;
//    exact same-TU donors then recovered the target size and first scan blocks.
// 10: Reconstructed both lists as ManagedIntArray members at +104 and +d58;
//     output stayed unchanged and the layout is now canonical.
// Left in scratch: size, calls, first scan, growth copies, removeGatherer, and
// final virtual dispatch are aligned. The only known drift is the second
// civilian scan: VC5 reuses the first count instead of the target's six-byte
// reload of civilian.numberValue, shifting later branch displacements.
```
<!-- end-recovered:1f8f07605085c5b6f425 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
