# Recovery journal: 004C4F10 `transform`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/stat_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\stat_obj.cpp`.
- Earlier recovery note: `recovery_notes/stat_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:f97875c66966bda143ef -->
### `912332e8f578` `src/matching/004C4F10_transform.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C4F10 transform (151B)
// stat_obj.cpp: 2508-2536
// void __thiscall RGE_Static_Object::transform(RGE_Master_Static_Object *param_1)
// Pure virtual class (implicit vptr) + fdivr pattern
```
<!-- end-recovered:f97875c66966bda143ef -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
