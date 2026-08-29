# Recovery journal: 00406C30 `getTask`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/act_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\act_obj.cpp`.
- Earlier recovery note: `recovery_notes/act_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:83ff47974fa4d5ad9b9f -->
### `748d8fedf57a` `src/matching/00406C30_getTask.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00406C30 RGE_Action_Object::getTask
// PDB source: act_obj.cpp lines 764-797
// Attempt log:
// - 2026-05-31: Replaced placeholder stub with natural master/candidate task lookup.
```
<!-- end-recovered:83ff47974fa4d5ad9b9f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
