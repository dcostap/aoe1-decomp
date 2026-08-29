# Recovery journal: 0042EF00 `EnableNewPlayers`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_hand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Com_hand.cpp`.
- Earlier recovery note: `recovery_notes/com_hand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:006885ba08a79d1a3728 -->
### `458aaecbc2e6` `src/scratch/0042EF00_EnableNewPlayers.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: direct COM/vtable shape with the null-arg guard and the logging tail
// result: VC5 keeps loading the incoming pointer through ecx instead of the original stack-load eax basin
// attempt 2: try the same body with a plain local alias for the incoming pointer, then stop if the basin stays wrong
```
<!-- end-recovered:006885ba08a79d1a3728 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
