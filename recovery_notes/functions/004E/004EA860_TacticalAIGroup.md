# Recovery journal: 004EA860 `TacticalAIGroup`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:6f6d0292dba861ec2f0e -->
### `d050eea3c` `src/taitacmd.cpp:2-2`

Mapping: `strong`. next mapped function definition is TacticalAIGroup at old line 36.

```text
// Definitions follow the original PDB source order.
```
<!-- end-recovered:6f6d0292dba861ec2f0e -->

<!-- recovered:d514b70b0b8ebed326c9 -->
### `3789ccb1ae1e` `src/matching/004EA860_TacticalAIGroup.cpp:2-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004EA860, TacticalAIGroup::TacticalAIGroup, 292 bytes
// Source: taitacmd.cpp lines 128-139
// MATCH: 292/292 bytes, 0% positional diff
```
<!-- end-recovered:d514b70b0b8ebed326c9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
