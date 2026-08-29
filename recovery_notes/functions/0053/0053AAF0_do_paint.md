# Recovery journal: 0053AAF0 `do_paint`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e5c4fa670f44650246a5 -->
### `3ee24e94c6d9` `src/scratch/0053AAF0_do_paint.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0053AAF0 RGE_View::do_paint | view.cpp:6226-6301
// compiles at original size. Conversion/local pick_info offsets fixed by using f0/y; remaining mismatch is mode-dispatch/source-shape (original subtract chain keeps game in ECX and brush in DX before dispatch).
```
<!-- end-recovered:e5c4fa670f44650246a5 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
