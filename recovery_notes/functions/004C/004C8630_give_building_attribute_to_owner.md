# Recovery journal: 004C8630 `give_building_attribute_to_owner`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:026fd540b2e98431296a -->
### `5868718576a8` `src/scratch/004C8630_give_building_attribute_to_owner.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: base draft, size 80 (1 byte short of 81)
// attempt 2: manual vtable cast, compile error
// attempt 3: natural C++ vcall through owner->method(), still 80
// attempt 4: use this->pManager inside loop (no mgr local), still 80
// attempt 5: fix checks (>= 4, >= 0), still 80
// attempt 6: separate if/goto checks, still 80
// left in scratch: 1 byte size drift, behavior correct, source basin not found
```
<!-- end-recovered:026fd540b2e98431296a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
