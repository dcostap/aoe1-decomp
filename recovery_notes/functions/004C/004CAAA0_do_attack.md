# Recovery journal: 004CAAA0 `do_attack`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_c_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_c_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_c_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5fce8af320579ca829ee -->
### `0923cad7edb1` `src/matching/004CAAA0_do_attack.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004CAAA0 TRIBE_Combat_Object::do_attack
// Source: t_c_obj.cpp lines 500-542
// Attempt log:
// 1: explicit thiscall vtable pointer typedefs rejected by VC5.
// 2: natural virtual declarations for vtable calls.
```
<!-- end-recovered:5fce8af320579ca829ee -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
