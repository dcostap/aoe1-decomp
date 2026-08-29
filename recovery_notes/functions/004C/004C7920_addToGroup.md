# Recovery journal: 004C7920 `addToGroup`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/stat_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\stat_obj.cpp`.
- Earlier recovery note: `recovery_notes/stat_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e72aa0b3d5f5d6f6a65a -->
### `9acc26143f36` `src/scratch/004C7920_addToGroup.cpp:1-19`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C7920 RGE_Static_Object::addToGroup
// stat_obj.cpp lines 4868-4880
// Fresh 2026-05-19: replace incorrect 32-byte stub with packet-derived groupMembers logic.
// try 1: decompiler-shaped logic with locals at top: exact-size 162B, 149/162 positional, first mismatch +0;
//        compiler saves EBX/EBP/ESI/EDI at entry instead of original early ESI-only cap check.
// try 2: move local declarations after cap check: no codegen change.
// try 3: invert outer cap into positive guarded body: worsened to near jge and same early saves; rolled back.
// Remaining drift is broad register/prologue/control-flow basin. Original delays EDI/EBP/EBX saves until after
// cap success and uses ECX=count through duplicate scan/realloc; rebuilt saves all callee-saves at entry and
// uses EDX/count plus pointer-walk duplicate scan. Not accepted-drift safe.
// Retry 2026-05-20: 16 more probes. Tried block-scoped locals after cap, positive/goto cap guard,
// shared found return, scan locals to mimic original, for-loop scan, combined/case-body copy loops,
// volatile/raw count guard, late groupIndex alias, parameter stack cast, count-before-cap, and raw
// offset-only member accesses. All close variants still first-mismatch at offset 0 with eager
// EBX/EBP/ESI/EDI save family; best metric remained broad ~91.36% positional / 53.70% edit.
// GIVEUP: exact blocker is VC5 choosing eager callee-saved prologue and pointer-walk scan/copy
// instead of original delayed-save basin. Not accepted_drift: broad prologue/control-flow/register
// allocation mismatch, not localized benign drift.
// Retry 2026-05-21 Boss pass: revalidated baseline (162B, ~91.98% positional, first mismatch 0). Tried direct indexed scan/copy, positive outer cap body, for-loop scan, no count local, goto cap, flags /Ob0 /O2-no-/Oy /Oa /O1 /G5, ManagedArray-style surface, delayed-scope/goto found shape, early count condition, and register this alias. No variant reached the original delayed-save prologue; best edit-only variants still kept broad eager EBX/EBP/ESI/EDI save or otherwise failed to compile cleanly. Left scratch unchanged; not accepted_drift.
```
<!-- end-recovered:e72aa0b3d5f5d6f6a65a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
