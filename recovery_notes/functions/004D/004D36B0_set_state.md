# Recovery journal: 004D36B0 `set_state`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_wnd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_wnd.cpp`.
- Earlier recovery note: `recovery_notes/tact_wnd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2a4d6f3abf6bc8d951d8 -->
### `d050eea3c` `src/tact_wnd.cpp:111-111`

Mapping: `strong`. next mapped function definition is set_state at old line 117.

```text
// PDB lines 101-104; VA 004D3690; matching before source reunification.
```
<!-- end-recovered:2a4d6f3abf6bc8d951d8 -->

<!-- recovered:f3b1299f95d26e8114d0 -->
### `a5fb96a1e6de` `src/scratch/004D36B0_set_state.cpp:1-10`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Action_Wonder::set_state
// VA: 004D36B0
// PDB: tact_wnd.cpp:108-148
//
// Attempt log:
// - draft 1: direct compare, rge_base_game local, null check → 84.9%
// - draft 2: switch statement, no locals → 85.8%
// - draft 3: all locals at top, sub esp,0C → 86.7%
// - draft 4: while loop with players[i] → 336 bytes (9 too short)
// - draft 5: try pointer arithmetic + for loop + no function pointer typedefs
```
<!-- end-recovered:f3b1299f95d26e8114d0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
