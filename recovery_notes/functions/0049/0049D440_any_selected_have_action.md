# Recovery journal: 0049D440 `any_selected_have_action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.
- Earlier recovery note: `recovery_notes/scr_game.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:a94f3f640135b4cea15a -->
### `a5fb96a1e6de` `src/scratch/0049D440_any_selected_have_action.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// scr_game.cpp:5882-5902, 101 bytes
// attempt 1: 81.2%, prolog too different (eax vs ecx, no ebp push)
// attempt 2: 77.2%, sel_count loaded early into ebp, extra test+jle
// attempt 3: 84.2%, sel_count inside loop worse
// attempt 4: 96 bytes, nested while+break too small
// attempt 5: 77.2%, int sel_count same as short
// BEST: 77.2% (attempts 2,5). Prolog matches (mov ecx + 4 pushes + call).
// BLOCKER: VC5 hoists sel_count load outside loop (into ebp), adds
//   early-exit test+jle guard, and uses ebp for sel_count (not eax).
//   Original loads sel_count inside loop each iteration via [ebp+19C].
//   23 bytes match; 78 bytes differ (mainly loop body shift from prolog diff).
```
<!-- end-recovered:a94f3f640135b4cea15a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
