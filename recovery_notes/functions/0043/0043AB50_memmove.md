# Recovery journal: 0043AB50 `memmove`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dib.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Dib.cpp`.
- Earlier recovery note: `recovery_notes/Dib_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3b5973f3840b00048124 -->
### `b25c5800db4c` `src/scratch/0043AB50_memmove.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043AB50 memmove (42B)
// PDB source: Dib.cpp lines 1770-1776
// BINARY NOTE: Dib.cpp has already included the CRT memmove declaration when
// this owner is grouped. The canonical return and const source surface avoids
// a C-linkage conflict; the helper's return value is unused by its caller.
// TU captain, 2026-08-26, owner sa-c6a4d383-r1:
// - The original source form with a separate count local and no parameter
//   reload reduced the mismatch from 39 bytes to two LEA SIB bytes.
// - Pointer arithmetic, endpoint indexing, declaration order, and byte-pointer
//   parameter probes were codegen duplicates.
// - Returning the decremented working pointer changed the public return value.
//   It was rejected despite its smaller two-byte mismatch.
```
<!-- end-recovered:3b5973f3840b00048124 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
