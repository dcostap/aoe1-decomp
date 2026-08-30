# Function notes: 004992E0 `object_changed`

## Recovered attempt history

<!-- recovered:7e7d10047cd390d81982 -->
### `target-session` `build/target_sessions/004992E0_object_changed.json:1-3`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 context; result=MATCH; diff=0; shape=100.0: Changed the compiler-facing declaration to protected, matching PDB-qualified TRIBE_Screen_Game::object_changed IAEXXZ access; bytes remain exact.
probe 2 context; result=MATCH; diff=0; shape=100.0: Walkback test: removed the protected access qualifier. Bytes remain exact, but PDB-qualified IAEXXZ ownership is no longer represented; restore protected declaration. [same emitted code as probe 1]
probe 5 context; result=MISMATCH; diff=4; shape=95.0: Context hypothesis: mark object_changed protected to emit PDB IAEXXZ symbol; body and existing bytes must stay exact.
```
<!-- end-recovered:7e7d10047cd390d81982 -->

<!-- recovered:65cf7f0a52a438d440e9 -->
### `7f9d273d677d` `src/matching/004992E0_object_changed.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004992E0 object_changed (199B)
// scr_game.cpp
// PDB owner: protected TRIBE_Screen_Game::object_changed, scr_game.cpp:3261-3298.
// Body: 004992E0-004993A6. 00498950 is data, not a function.
// Exact finish: natural player-state publication, mode guards, and reset cleanup
// produce 60 instructions, 7 ordered calls, and the protected IAEXXZ symbol.
```
<!-- end-recovered:65cf7f0a52a438d440e9 -->
