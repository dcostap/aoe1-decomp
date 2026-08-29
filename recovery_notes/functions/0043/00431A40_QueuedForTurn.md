# Recovery journal: 00431A40 `QueuedForTurn`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_q.cpp`.
- PDB source: `C:\msdev\work\age1_x1\com_q.cpp`.
- Earlier recovery note: `recovery_notes/com_q_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:aef56d802cffc1ed6ed3 -->
### `0a5877c36f57` `src/scratch/00431A40_QueuedForTurn.cpp:2-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// BINARY NOTE: The PDB owner is protected, and the queue record starts with
// Code before ExecTurn at offset 4.
```
<!-- end-recovered:aef56d802cffc1ed6ed3 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
