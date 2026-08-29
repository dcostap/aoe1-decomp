# Recovery journal: 00527830 `create_game_screen`

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


<!-- recovered:ccbd52e20e387ff41078 -->
### `bf81de068f12` `src/scratch/00527830_create_game_screen.cpp:15-22`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Call TRIBE_Screen_Game::TRIBE_Screen_Game constructor
    // (**(void(**)(void*, void*))(*(int**)gameScreen + ...))(gameScreen, this);
    // ...

    // Store game screen in self
    *(void**)((char*)self + 0xC24) = gameScreen;

    // Set current panel
```
<!-- end-recovered:ccbd52e20e387ff41078 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
