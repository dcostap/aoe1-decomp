# Recovery journal: 0049B000 `scr_game_score_compare`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:c8a0bf903b7f06b8b0c8 -->
### `bf81de068f12` `src/matching/0049B000_scr_game_score_compare.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0049B000 scr_game_score_compare
// 121 bytes, __cdecl, qsort comparison callback
// probe 3: param order was wrong - original loads a from [esp+8], b from [esp+4]
```
<!-- end-recovered:c8a0bf903b7f06b8b0c8 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
