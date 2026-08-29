# Recovery journal: 0041FDE0 `check_expiration`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/basegame.cpp`.
- PDB source: `C:\msdev\work\age1_x1\basegame.cpp`.
- Earlier recovery note: `recovery_notes/basegame_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:ea3479ddd2ffcf097977 -->
### `e636174a8eb4` `src/matching/0041FDE0_check_expiration.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: zeroed tm-like local, build the expiration date, then compare current time against it
// exact match landed once the tm-like layout started at tm_min and memset zeroed the 9-dword local block before the date fields were filled
```
<!-- end-recovered:ea3479ddd2ffcf097977 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
