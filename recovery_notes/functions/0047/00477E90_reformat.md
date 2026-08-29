# Recovery journal: 00477E90 `reformat`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Pnl_inp.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_inp.cpp`.
- Earlier recovery note: `recovery_notes/Pnl_inp_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d90bf041e4af9126b42b -->
### `bf81de068f12` `src/scratch/00477E90_reformat.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: natural save/clamp/scroll shape from the asm
// result: close, but the saved short register assignment landed swapped
// attempt 2: swap the local birth/order so old_cur stays with the first clamp and old_top with scroll
// attempt 3: restore the original save order after the vtable/layout fix; that should put the saved shorts back in the right registers
// attempt 4: try a single saved line-count temp so both clamps share the same compare source
// still stuck: only the saved-short register assignment is swapped; the branch/body shape is otherwise aligned
```
<!-- end-recovered:d90bf041e4af9126b42b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
