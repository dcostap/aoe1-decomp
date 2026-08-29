# Recovery journal: 004C9620 `work_status`

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


<!-- recovered:4b2c234d074943162754 -->
### `target-session` `build/target_sessions/004C9620_work_status.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MISMATCH; diff=1; shape=97.91666666666667: Restore original short-reference parameter ABI from FPO symbol QAEHAAF00PADF.
```
<!-- end-recovered:4b2c234d074943162754 -->

<!-- recovered:b3550f8fdc671ef3e45b -->
### `9f29dc381200` `src/matching/004C9620_work_status.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C9620 TRIBE_Building_Object::work_status(short&, short&, short&, char*, short)
// PDB source: t_b_obj.cpp lines 872-898 (150 B, 48 asm)
// Attempt log:
```
<!-- end-recovered:b3550f8fdc671ef3e45b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
