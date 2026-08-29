# Recovery journal: 0042C880 `SendPauseGame`

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


<!-- recovered:5dbfbb6a39325fa1ab86 -->
### `912332e8f578` `src/scratch/0042C880_SendPauseGame.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// target: VA 0042C880 TCommunications_Handler::SendPauseGame(int)
// first pass: preserve the multiplayer/host guards, log branch, and CommOut call shape
```
<!-- end-recovered:5dbfbb6a39325fa1ab86 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
