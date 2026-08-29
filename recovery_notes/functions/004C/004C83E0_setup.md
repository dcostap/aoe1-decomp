# Recovery journal: 004C83E0 `setup`

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


<!-- recovered:dddf10f5bf6e8fa48cab -->
### `target-session` `build/target_sessions/004C83E0_setup.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MISMATCH; diff=133; shape=75.0: Protected virtual setup access now emits original MAEH symbol; wrapper declaration repair.
```
<!-- end-recovered:dddf10f5bf6e8fa48cab -->

<!-- recovered:19a015deda790658662a -->
### `fa987c10075f` `src/matching/004C83E0_setup.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C83E0 TRIBE_Building_Object::setup
// t_b_obj.cpp:176-199
// Retry 2026-05-24: replaced stale stub with packet-derived building setup body.
```
<!-- end-recovered:19a015deda790658662a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
