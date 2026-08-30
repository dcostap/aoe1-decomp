# Function notes: 00528670 `let_game_begin`

Module notes: `decomp_notes/tribegam_module.md`.

## Recovered attempt history

<!-- recovered:a70b4f46b553cb59b37f -->
### `1f02fa47d8e2` `src/scratch/00528670_let_game_begin.cpp:1-17`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00528670 TRIBE_Game::let_game_begin (1779 bytes)
// PDB source: tribegam.cpp:4208-4359
//
// Baseline reconstruction: natural game-start logging, typed game/world/music
// ownership, and the final input/chat transition from the original call flow.
//
// Attempt log:
// - Baseline matched size, frame, saved registers, call count, and CFG.
// - Added the complete get_string virtual overload surface. This improved the
//   map-string dispatch and exact block coverage.
// - Corrected TMusic_System fields: music_type is +0x104 and track_count is
//   +0x248. This fixed the music field accesses.
// - Pointer, array-address, and declaration-order probes were codegen
//   duplicates. The remaining drift starts at difficulty-string scheduling.
// - A const MapType return from the same-TU/PDB ABI donor was also a codegen
//   duplicate; restored the natural int helper surface.
// - Paused: the natural source has 46 aligned calls and 0x834 frame parity.
```
<!-- end-recovered:a70b4f46b553cb59b37f -->
