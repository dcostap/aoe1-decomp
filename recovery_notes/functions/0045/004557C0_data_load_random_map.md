# Recovery journal: 004557C0 `data_load_random_map`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\map.cpp`.
- Earlier recovery note: `recovery_notes/map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:6ffb7338c78915435f3a -->
### `489810cbdcd9` `src/matching/004557C0_data_load_random_map.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// first pass: keep the allocation/ctor as a natural direct new-expression and preserve the single assignment
// with /GX this should be the right EH/new basin if the constructor shape is the same as the packet
// BINARY NOTE (map TU wave02): The target allocates a 0x4F5C controller.
// The shared map TU declaration lacks that storage.  No source-only repair is supported.
```
<!-- end-recovered:6ffb7338c78915435f3a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
