# Recovery journal: 00421110 `handle_mouse_move`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/basegame.cpp`.
- PDB source: `C:\msdev\work\age1_x1\basegame.cpp`.
- Earlier recovery note: `recovery_notes/basegame_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:676ec32c7f075c97d76a -->
### `d050eea3c` `src/basegame.cpp:3198-3198`

Mapping: `strong`. comment lies after mapped function handle_mouse_move at old line 3183.

```text
    // ORIGINAL BUG: 00421110 passes this local without a write.
```
<!-- end-recovered:676ec32c7f075c97d76a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
