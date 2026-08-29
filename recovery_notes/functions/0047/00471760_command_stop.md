# Recovery journal: 00471760 `command_stop`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/player.cpp`.
- PDB source: `C:\msdev\work\age1_x1\player.cpp`.
- Earlier recovery note: `recovery_notes/player_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e13b1e0b0a6caf284be1 -->
### `de90bbea477a` `src/matching/00471760_command_stop.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt log:
// first pass: natural local list/list_num spelling around the selection helper and follow-up command dispatch
// second pass: switch to the decompiler-ish local_4 array spelling to mirror the helper call/stack shape
// third pass: explicitly copy the returned short into list_num before the command dispatch
// fourth pass: revert to the original fallthrough success block so the branch layout matches the asm
// target shape: get selected objects, call the selected object's +0xAC vfunc, forward to command_stop, free the list, return 1/0
```
<!-- end-recovered:e13b1e0b0a6caf284be1 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
