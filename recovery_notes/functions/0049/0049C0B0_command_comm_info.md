# Recovery journal: 0049C0B0 `command_comm_info`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.
- Earlier recovery note: `recovery_notes/scr_game.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:ae76532539826d1e00ab -->
### `7f9d273d677d` `src/accepted_drift/0049C0B0_command_comm_info.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049C0B0 command_comm_info (165B)
// scr_game.cpp
// Fresh 2026-05-19: implement real command_comm_info panel toggle logic.
// try 1: natural panel/global logic: exact size, only broad diffs from set_visible vslot at +0x10 and final global reload register choices.
// try 2: add the canonical set_active surface: reduced to 30/165 positional.
// try 3: force final else-branch global reloads through a local `game`: reduced to 4/165 positional.
// try 4: first-call temp local; no change.
// try 5: second-call temp local; no change.
// try 6: int-return virtual surface; no change, rolled back.
// Remaining drift is only vtable scratch register selection for two adjacent calls: rebuilt uses EDX then EAX;
// original uses EAX then EDX. Same ECX this pointers, pushed args (0/1), vslot +0x14, calls, and all later bytes exact.
```
<!-- end-recovered:ae76532539826d1e00ab -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
