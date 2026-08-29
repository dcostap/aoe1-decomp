# Recovery journal: 00484C80 `remove_area_from_lists`

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


<!-- recovered:6a028a3e25a33d319680 -->
### `70d829c1e6f9` `src/scratch/00484C80_remove_area_from_lists.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00484C80 RGE_RMM_Elevation_Generator::remove_area_from_lists
// HollowSnowdrop pass: natural clipped rectangle loop reaches exact size 128/128 and correct prologue/call shape. Best diff 71.1% positional / 47.7% edit. Remaining drift starts after computing end/start bounds: rebuilt stores start_y early and uses slightly different stack-param slots; parameter-slot reuse/source-shape issue.
```
<!-- end-recovered:6a028a3e25a33d319680 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
