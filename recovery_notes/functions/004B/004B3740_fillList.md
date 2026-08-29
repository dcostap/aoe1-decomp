# Recovery journal: 004B3740 `fillList`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sedo.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sedo.cpp`.
- Earlier recovery note: `recovery_notes/scr_sedo_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:fe6b770a7a59bfe12065 -->
### `a5fb96a1e6de` `src/scratch/004B3740_fillList.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004B3740 fillList
// scr_sedo.cpp lines 116-149

// attempt 1: natural translation -> exact size (352), 52% diff
//   remaining diffs: lea [ecx-4] vs mov+sub (codegen), jump offset drifts
//   structurally correct
```
<!-- end-recovered:fe6b770a7a59bfe12065 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
