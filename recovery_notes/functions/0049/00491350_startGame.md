# Recovery journal: 00491350 `startGame`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_cams.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_cams.cpp`.
- Earlier recovery note: `recovery_notes/scr_cams_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:6f7fa93e5d7532c04d19 -->
### `e8a60cf496b7` `src/matching/00491350_startGame.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00491350 TRIBE_Screen_Campaign_Selection::startGame
// Attempt log:
// 1: natural reconstruction from packet with local UI/game/scenario surfaces.
// 2: added full body; compiles size-equal but broad mismatch, first diff is saved-this register (rebuilt ESI, original EDI).
// 3: explicit self local did not change saved-this register; original likely uses EDI because ESI is taken by scenario/player count liveness early.
// 4: moving player_count declaration/init to function top forced this into EDI, but emitted early xor esi before original; rolled to delayed init.
// 5: split rge_base_game->game_info into a local to encourage original ESI=game_info before set_current_scenario.
```
<!-- end-recovered:6f7fa93e5d7532c04d19 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
