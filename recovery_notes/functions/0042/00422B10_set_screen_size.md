# Recovery journal: 00422B10 `set_screen_size`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/basegame.cpp`.
- PDB source: `C:\msdev\work\age1_x1\basegame.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:9fd7f20bbae01fb98b2c -->
### `bf81de068f12` `src/scratch/00422B10_set_screen_size.cpp:21-23`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// OFF-DECLARATION-ORDER struct: fields sorted by ascending offset
// Actual offsets: prog_window(+0x10), window_style(+0x24), draw_system(+0x48),
//   draw_area(+0x4C), mouse_pointer(+0x1C0)
```
<!-- end-recovered:9fd7f20bbae01fb98b2c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
