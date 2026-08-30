# Function notes: 004FB710 `taskResearch`

## Recovered attempt history

<!-- recovered:b8b4295f826bb3bbe32c -->
### `d050eea3c` `src/taitacmd.cpp:11234-11249`

Mapping: `strong`. next mapped function definition is taskResearch at old line 11308.

```text
// Attempt log:
// - Fresh typed reconstruction from the taskTrain packet and same-TU task
//   donors. The source models BuildItem, MainDecisionAIModule::object,
// [non-comment lines omitted during migration]
// - Baseline reached 448/448 bytes, 17/17 ordered calls, and 4 differing
// [non-comment lines omitted during migration]
//   parameter-reuse form moved two swaps but added prologue drift. The
//   natural baseline remained best. No ABI, call-set, or layout blocker.
// - Mirrored the adjacent taskResearch source order: declare objectID at
// [non-comment lines omitted during migration]
//   local-home bytes and produced MATCH (448/448). Default flags; no asm.
```
<!-- end-recovered:b8b4295f826bb3bbe32c -->

<!-- recovered:7d531a6e0f996fae510d -->
### `6a2aef2e2` `src/taitacmd.cpp:9694-9703`

Mapping: `strong`. next mapped function definition is taskResearch at old line 9756.

```text
// __thiscall, returns 0/1
//
//   RGE_Static_Object::unitAI, TRIBE_Player::trainUnit, and the proven
//   this->unitsTaskedThisUpdate ManagedArray layout.
//   bytes. The remaining bytes are four swapped local-home displacements:
//   VC5 stores the found object in the incoming parameter home and the
//   object ID in the compiler local home.
// - Tried early object-ID/object declarations, pointer initialization,
//   assignment-in-condition, long ID types, and parameter reuse. The
//   entry, assign it before the ManagedArray<int> alias. This restored all four
```
<!-- end-recovered:7d531a6e0f996fae510d -->

<!-- recovered:d4478bd8cf4f2fd04a67 -->
### `b6e159352e2d` `src/scratch/004FB710_taskResearch.cpp:1-25`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004FB710 TribeTacticalAIModule::taskResearch (448 B)
// PDB source: taitacmd.cpp:9222-9253
// __thiscall, returns 0/1
//
// Fresh reconstruction from the exact taskTrain/taskWaterFisher donors.
// The target uses the same building lookup, BuildItem state changes, and
// ManagedIntArray growth. The final dispatch is TRIBE_Player::research.
//
// Attempt log:
// - Baseline: natural typed BuildItem/MainDecision/RGE object reconstruction;
//   448 bytes and 17 calls, but broad register and block drift.
// - Cached object-id probe improved the metric by 10 bytes, but changed the
//   source shape and introduced a wrong direct-call identity; rolled back.
// - Split lookup declaration and assignment restored the exact 448-byte
//   topology except for four stack-home displacement bytes.
// - Entry-local, assignment-in-condition, and object-alias variants emitted
//   duplicate code. The remaining gap is the object spill slot at 004FB75E
//   and 004FB843: target [esp+18], rebuilt [esp+10].
// - Reused the scan index for the array-copy loop, matching the original EAX
//   loop topology; emitted code was unchanged, so the spill-home gap remains.
// - Declared objectID at its first natural use after the item state updates to
//   test whether its shorter lifetime restored the original object spill home;
//   emitted code was unchanged, so the probe was rolled back.
// - Best source keeps named ownership and natural bounded array growth.
//   It remains in scratch because exact bytes are not complete.
```
<!-- end-recovered:d4478bd8cf4f2fd04a67 -->
