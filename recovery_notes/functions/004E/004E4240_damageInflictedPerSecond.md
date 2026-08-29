# Recovery journal: 004E4240 `damageInflictedPerSecond`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:73b561684c09f5c42ca5 -->
### `target-session` `build/target_sessions/004E4240_damageInflictedPerSecond.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 2 variant; result=MATCH; diff=0; shape=100.0: Walkback probe: replace compound total += expression with expanded total = total + expression; tests whether current natural assignment spelling is codegen-required while preserving call and x87 order. [same emitted code as probe 1]
```
<!-- end-recovered:73b561684c09f5c42ca5 -->

<!-- recovered:f90b5c98c77df94b6c67 -->
### `fc4b000c6e8f` `src/matching/004E4240_damageInflictedPerSecond.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E4240 TribeInformationAIModule::damageInflictedPerSecond
// Source: taiinfmd.cpp lines 8263-8292
// public: float __thiscall TribeInformationAIModule::damageInflictedPerSecond(int*,int,RGE_Static_Object*)
// PDB-qualified overload: TribeInformationAIModule::damageInflictedPerSecond(int*, int, RGE_Static_Object*).
// BINARY NOTE: The body is 004E4240-004E42A9; 004E42AA-004E42AF are padding before 004E42B0.
// BINARY NOTE: The loop rereads the id pointer, object call, and both virtual slots in this order.
//
// Attempt log:
// Probe 1: natural loop, virtual calls at correct slots, default flags
```
<!-- end-recovered:f90b5c98c77df94b6c67 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
