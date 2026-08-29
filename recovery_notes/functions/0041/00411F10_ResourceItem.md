# Recovery journal: 00411F10 `ResourceItem`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/airesitm.cpp`.
- PDB source: `C:\msdev\work\age1_x1\airesitm.cpp`.
- Earlier recovery note: `recovery_notes/00411F10_ResourceItem.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8196c7b548534643e4cf -->
### `a5fb96a1e6de` `src/scratch/00411F10_ResourceItem.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt log:
// first pass: natural constructor shape with vptr init, next/prev zero, count save, and the two fill phases
// second pass: switch to the decompiler-shaped do/while form because the first loop basin was slightly too small
// third pass: use sortedValue as the moving pointer base so the three writes land on the observed +/-0x20, 0, +0x20 addresses
// fourth pass: switching back to a top-tested loop changed the register basin too far and blew the diff up
// paused here: the remaining mismatch is still in the first-loop codegen basin / register order around the pointer walk
```
<!-- end-recovered:8196c7b548534643e4cf -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
