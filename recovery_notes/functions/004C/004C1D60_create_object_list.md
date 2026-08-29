# Recovery journal: 004C1D60 `create_object_list`

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


<!-- recovered:f08940f138a4d79c8ef1 -->
### `6e3d5b45eb37` `src/scratch/004C1D60_create_object_list.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// quick-win attempt log:
// no existing work file for 004C1D60; the oracle is an EH-framed new-expression helper
// from stat_obj.cpp. Tried direct `new`, `try/catch`, and placement-new shapes; the
// remaining mismatch stayed at the prolog / first instruction basin.
// Tried moving the target function first in the TU; that changed the emitted basin
// but still did not reproduce the original `push -1` / FS:[0] EH entry sequence.
```
<!-- end-recovered:f08940f138a4d79c8ef1 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
