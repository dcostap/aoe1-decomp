# Recovery journal: 0042D120 `UpdatePlayerInformation`

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


<!-- recovered:cff44ae8a8cae330d544 -->
### `5868718576a8` `src/scratch/0042D120_UpdatePlayerInformation.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// tried pointer-walk, direct indexing, and the decompiler-shaped loop; VC5 stayed in the wrong register basin and kept saving ebx
// remaining mismatch is the prolog/register allocation around the first stack arg load
```
<!-- end-recovered:cff44ae8a8cae330d544 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
