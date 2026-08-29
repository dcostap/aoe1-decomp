# Recovery journal: 004304B0 `get_armor`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\com_obj.cpp`.
- Earlier recovery note: `recovery_notes/com_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b06aa476289d9c6aabde -->
### `target-session` `build/target_sessions/004304B0_get_armor.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: FPO symbol requires virtual short-reference parameters; body remains exact.
```
<!-- end-recovered:b06aa476289d9c6aabde -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
