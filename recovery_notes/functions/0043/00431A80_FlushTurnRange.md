# Recovery journal: 00431A80 `FlushTurnRange`

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


<!-- recovered:175e7f371a9c5b2f7cb5 -->
### `ba2925309130` `src/scratch/00431A80_FlushTurnRange.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00431A80 FlushTurnRange
// 143 bytes, __thiscall, RGE_Communications_Queue method
// probe 1: natural loop through Queue array, clear items in turn range
```
<!-- end-recovered:175e7f371a9c5b2f7cb5 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
