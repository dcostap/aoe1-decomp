# Function notes: 00471AA0 `command_add_waypoint`

Module notes: `decomp_notes/player_module.md`.

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
