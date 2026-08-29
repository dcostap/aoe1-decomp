# Recovery journal: 005245D0 `load_game_data`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tribegam.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tribegam.cpp`.
- Earlier recovery note: `recovery_notes/tribegam_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:4ba1fffd768f7c4c4ea9 -->
### `912332e8f578` `src/matching/005245D0_load_game_data.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 005245D0 TRIBE_Game::load_game_data
// Source: tribegam.cpp lines 1887-1903
// public: int __thiscall TRIBE_Game::load_game_data(void)
//
// Attempt log:
// Probe 1: correct virtual method placement on both TRIBE_Game and RGE_Game_World, default flags
```
<!-- end-recovered:4ba1fffd768f7c4c4ea9 -->

<!-- recovered:2a3e85705102183c77d0 -->
### `912332e8f578` `src/matching/005245D0_load_game_data.cpp:39-39`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Game — needs vtable slot 45 (0xB4): createGameData
```
<!-- end-recovered:2a3e85705102183c77d0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
