# Recovery journal: 00526DC0 `do_game_over`

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


<!-- recovered:f911e79a33725a10dbf6 -->
### `912332e8f578` `src/matching/00526DC0_do_game_over.cpp:1-21`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Game::do_game_over
// VA: 00526DC0
// tribegam.cpp:3191-3220
// 149 bytes
// [non-comment lines omitted during migration]
    // Flat layout; RGE_Base_Game base occupies 0x000 to 0xA23
    // Fields of interest within that range:
    //   +0x1B0: int game_type
    //   +0x3F4: void* some_video_object
    // +0xAE8: unsigned char testing_scenario (TRIBE_Game-specific)
```
<!-- end-recovered:f911e79a33725a10dbf6 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
