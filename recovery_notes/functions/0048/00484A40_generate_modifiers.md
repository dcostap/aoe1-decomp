# Recovery journal: 00484A40 `generate_modifiers`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/rmm_elev.cpp`.
- PDB source: `C:\msdev\work\age1_x1\rmm_elev.cpp`.
- Earlier recovery note: `recovery_notes/rmm_elev_natural_candidate.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:faa3eb03e111e090d7ac -->
### `bb681882dea6` `src/matching/00484A40_generate_modifiers.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00484A40 RGE_RMM_Elevation_Generator::generate_modifiers
// PDB: rmm_elev.cpp lines 159-193
// Baseline reconstruction: clear the shared search map, then accumulate the
// positive falloff contribution of each elevation hot spot for every tile.
// Attempt log:
// - Natural nested loops matched size/frame/calls but VC5 loaded map_width
//   first for the commutative clear-size expression.
// - A height-first accumulator restored the original clear-size load order.
// - The binary-proven hot-spot cursor is anchored at the y field; declaring
//   that cursor before the scoped count places the count-home store after the
//   LEA, producing the exact VC5 block.
```
<!-- end-recovered:faa3eb03e111e090d7ac -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
