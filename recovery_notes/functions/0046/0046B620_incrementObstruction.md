# Recovery journal: 0046B620 `incrementObstruction`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/pathsys.cpp`.
- PDB source: `C:\msdev\work\age1_x1\pathsys.cpp`.
- Earlier recovery note: `recovery_notes/pathsys_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:71ad61b18e05d8054ebd -->
### `5868718576a8` `src/scratch/0046B620_incrementObstruction.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: pointer field + pointer math; total mismatch at offset 1 (prologue, all different)
// attempt 2: byte array + extern globals; first 52 bytes match, mismatch at +52 (VC5 saves cl to [esp+14h])
// attempt 3: mask computed early; param order swapped back (edx/eax reversed at offset 1)
// attempt 4: named ob var; same as attempt 2, cl saved to stack
// Original: keeps shift in cl through both shr and shl without spill; VC5 spills cl after shr
// Left in scratch: VC5 register liveness analysis differs, benign codegen drift, behavior correct
```
<!-- end-recovered:71ad61b18e05d8054ebd -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
