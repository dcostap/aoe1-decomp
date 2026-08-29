# Recovery journal: 0050FF20 `find_cliff`

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


<!-- recovered:30bf3437bdc191d8a8ef -->
### `912332e8f578` `src/matching/0050FF20_find_cliff.cpp:1-10`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0050FF20 TRIBE_Map::find_cliff (245 bytes) — MATCHED
// PDB: tmap.cpp lines 463-485
// Calling convention: __thiscall
// Returns: RGE_Static_Object*
// Parameters: (long param_1, long param_2)
//
// Key insight: block-scoping each loop and returning by reading directly
// from node pointer (return *(RGE_Static_Object**)node) produces the exact
// original codegen. Avoiding per-loop temp variables (obj, master) and
// computing grid rows inline (y1 + 1) instead of a y2 local was critical.
```
<!-- end-recovered:30bf3437bdc191d8a8ef -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
