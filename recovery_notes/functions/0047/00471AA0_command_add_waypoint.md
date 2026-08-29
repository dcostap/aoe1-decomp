# Recovery journal: 00471AA0 `command_add_waypoint`

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


<!-- recovered:a773ce260cb7bf63ee87 -->
### `3ee24e94c6d9` `src/scratch/00471AA0_command_add_waypoint.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00471AA0 RGE_Player::command_add_waypoint(float param_1, float param_2, float param_3)
// PDB source: player.cpp lines 2538-2551
// Default flags
//
// __thiscall: this in ecx, 3 stack params (float). ret 0Ch cleanup.
// Returns unsigned char (bool).
```
<!-- end-recovered:a773ce260cb7bf63ee87 -->

<!-- recovered:60a5cd99eda24233bf69 -->
### `3ee24e94c6d9` `src/scratch/00471AA0_command_add_waypoint.cpp:71-74`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Can't use __thiscall on function pointers...
    // Let me try a different approach.

    // Use a helper class for get_selected
```
<!-- end-recovered:60a5cd99eda24233bf69 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
