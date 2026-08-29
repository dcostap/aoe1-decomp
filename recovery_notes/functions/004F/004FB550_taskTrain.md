# Recovery journal: 004FB550 `taskTrain`

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


<!-- recovered:a51d61cab2d5feffa213 -->
### `b6e159352e2d` `src/scratch/004FB550_taskTrain.cpp:1-20`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004FB550 TribeTacticalAIModule::taskTrain (448 B)
// PDB source: taitacmd.cpp:9185-9217
// __thiscall, returns 0/1
//
// Attempt log:
// - Fresh typed reconstruction from the taskTrain packet and same-TU task
//   donors. The source models BuildItem, MainDecisionAIModule::object,
//   RGE_Static_Object::unitAI, TRIBE_Player::trainUnit, and the proven
//   unitsTaskedThisUpdate ManagedArray layout.
// - Baseline reached 448/448 bytes, 17/17 ordered calls, and 4 differing
//   bytes. The remaining bytes are four swapped local-home displacements:
//   VC5 stores the found object in the incoming parameter home and the
//   object ID in the compiler local home.
// - Tried early object-ID/object declarations, pointer initialization,
//   assignment-in-condition, long ID types, and parameter reuse. The
//   parameter-reuse form moved two swaps but added prologue drift. The
//   natural baseline remained best. No ABI, call-set, or layout blocker.
// - Mirrored the adjacent taskResearch source order: declare objectID at
//   entry, assign it before the ManagedIntArray alias. This restored all four
//   local-home bytes and produced MATCH (448/448). Default flags; no asm.
```
<!-- end-recovered:a51d61cab2d5feffa213 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
