# Recovery journal: 00500AD0 `numberItemsToDefend`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.
- Earlier recovery note: `recovery_notes/taitacmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b45a870cbf844abf2d05 -->
### `6a2aef2e2` `src/taitacmd.cpp:12138-12138`

Mapping: `strong`. comment lies after mapped function numberItemsToDefend at old line 12136.

```text
// Observed body remains unresolved. This source keeps the owner callable.
```
<!-- end-recovered:b45a870cbf844abf2d05 -->

<!-- recovered:073fa659c7d223b7d5f4 -->
### `c5490d3e3209` `src/scratch/00500AD0_numberItemsToDefend.cpp:2-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00500AD0 TribeTacticalAIModule::numberItemsToDefend
// Observed body remains unresolved. This source keeps the owner callable.
// [non-comment lines omitted during migration]
// BLOCKER: The shared context omits TribeInformationAIModule::numberItemsToDefend.
// A natural member call needs that shared declaration to preserve the direct tail target.
```
<!-- end-recovered:073fa659c7d223b7d5f4 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
