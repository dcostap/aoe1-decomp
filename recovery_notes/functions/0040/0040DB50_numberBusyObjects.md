# Recovery journal: 0040DB50 `numberBusyObjects`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/aimdmod.cpp`.
- PDB source: `C:\msdev\work\age1_x1\aimdmod.cpp`.
- Earlier recovery note: `recovery_notes/aimdmod_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:38ffcc850180bb9d375e -->
### `a5fb96a1e6de` `src/scratch/0040DB50_numberBusyObjects.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: 224 vs 218 bytes, 6 bytes too large
// PAUSED: same growth-pattern register allocation issue as save/addObject
// The inlined ManagedArray growth code causes VC5 to use different register allocation
```
<!-- end-recovered:38ffcc850180bb9d375e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
