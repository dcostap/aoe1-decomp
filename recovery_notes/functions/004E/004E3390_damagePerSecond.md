# Recovery journal: 004E3390 `damagePerSecond`

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


<!-- recovered:22a3c92a96e76a539f6e -->
### `30c9a04a1db9` `src/matching/004E3390_damagePerSecond.cpp:1-23`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E3390 TribeInformationAIModule::damagePerSecond (taiinfmd.cpp:7640-7716, 292B)
// Calculates total damage per second against units matching criteria.
// FLAGS: /nologo /c /O2 /Oy
// [non-comment lines omitted during migration]
// 64 dummies for vtable slots 0-63, then real slots at 0x100 and 0x104
```
<!-- end-recovered:22a3c92a96e76a539f6e -->

<!-- recovered:5ba5dc1825ef338b0dae -->
### `30c9a04a1db9` `src/matching/004E3390_damagePerSecond.cpp:69-69`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// InnerType2 with vtable slot 6 for target_method — same layout as InnerType
```
<!-- end-recovered:5ba5dc1825ef338b0dae -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
