# Recovery journal: 0040D580 `numberObjectsWithTargetType`

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


<!-- recovered:06ed1613b8e08c95a0c4 -->
### `c1651ee04f47` `src/matching/0040D580_numberObjectsWithTargetType.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0040D580 MainDecisionAIModule::numberObjectsWithTargetType
// PDB: aimdmod.cpp:153-163, 221 bytes
// __thiscall, ret 4
// FLAGS: default
//
// Probe 5: inline unitAI calls, no extra locals
```
<!-- end-recovered:06ed1613b8e08c95a0c4 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
