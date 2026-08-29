# Recovery journal: 0042C7A0 `ResetLastCommunicationTimes`

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


<!-- recovered:58e0903e889a36b20828 -->
### `037950f4de84` `src/scratch/0042C7A0_ResetLastCommunicationTimes.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// tried a direct time refresh with the ping arrays laid out at 0x1348/0x1398
// tried the asm-shaped loop pointer; remaining mismatch is the first loop body scheduling, specifically the xor edi / second-store order
```
<!-- end-recovered:58e0903e889a36b20828 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
