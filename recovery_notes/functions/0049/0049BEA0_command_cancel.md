# Recovery journal: 0049BEA0 `command_cancel`

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


<!-- recovered:f7baf38dafbc0a00a369 -->
### `a5fb96a1e6de` `src/scratch/0049BEA0_command_cancel.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// target: VA 0049BEA0 TRIBE_Screen_Game::command_cancel()
// first pass: preserve the early-return ladder and direct global/member call order
// probe 1: direct member-call spelling is still pulling the wrong layout basin for main_view/popup-help offsets
// blocker: the remaining drift is in local class surface/layout, not the branch structure
```
<!-- end-recovered:f7baf38dafbc0a00a369 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
