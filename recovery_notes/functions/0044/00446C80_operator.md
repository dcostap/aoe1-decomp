# Recovery journal: 00446C80 `operator+`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dstring.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dstring.cpp`.
- Earlier recovery note: `recovery_notes/dstring.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:6ab995a31568c350ab1c -->
### `0923cad7edb1` `src/scratch/00446C80_operator.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Matches in the dstring.cpp EH/object-lifetime basin: keep /GX and a visible
// nontrivial DString destructor declaration even though this helper body is small.
```
<!-- end-recovered:6ab995a31568c350ab1c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
