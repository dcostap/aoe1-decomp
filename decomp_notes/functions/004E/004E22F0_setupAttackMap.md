# Function notes: 004E22F0 `setupAttackMap`

Module notes: `decomp_notes/taiinfmd_module.md`.

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
