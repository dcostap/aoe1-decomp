# Recovery journal: 004E22F0 `setupAttackMap`

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


<!-- recovered:8bc9ce6a3a705fc15a5c -->
### `d7b30a95b149` `src/scratch/004E22F0_setupAttackMap.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E22F0 TribeInformationAIModule::setupAttackMap
// Source: taiinfmd.cpp lines 7081-7114
// Attempt log:
// initial: 74% diff — missing vtable pointer on all classes, wrong offsets.
// added virtuals: offsets correct, 75% diff.
// do-while + i at function scope: push edi/ebp now inside if body, 52% diff.
// tried base+offset separation; direct field access via attackMemories[]: 14.5% diff.
// FLAGS: none
// Left in scratch: remaining diff is register allocation (edx vs ecx for md ptr)
// and instruction scheduling (byte read interleaved with md->attackInfo load).
// First condition (targetOwner compare) and full prologue/loop are byte-identical.
// Extern relocations masked (8).
```
<!-- end-recovered:8bc9ce6a3a705fc15a5c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
