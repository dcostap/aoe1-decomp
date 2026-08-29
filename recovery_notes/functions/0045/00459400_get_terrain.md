# Recovery journal: 00459400 `get_terrain`

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


<!-- recovered:be13374849cdc80547ea -->
### `5868718576a8` `src/scratch/00459400_get_terrain.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: 2D int array indexing with >> 24 & 0x1F; wrong map_row_offset type (int** vs int*)
// attempt 2: (unsigned char*) cast on row ptr; extra push edi at +20, terrain_types access differs
// attempt 3: same as 2; VC5 always pushes edi for cast expr, loads [ecx+8C] into ecx
```
<!-- end-recovered:be13374849cdc80547ea -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
