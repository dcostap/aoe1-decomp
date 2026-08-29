# Recovery journal: 004C7D00 `commanderDestroyGroup`

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


<!-- recovered:eea2174569fb70def963 -->
### `61f308393398` `src/scratch/004C7D00_commanderDestroyGroup.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004C7D00 RGE_Static_Object::commanderDestroyGroup
// Source: stat_obj.cpp lines 4988-5005
// Attempt log:
// Probe 1: raw-offset ManagedArray growth and recursive destroy; wrong EBX/EBP roles and copy-loop shape.
// Probe 2: decompiler-shaped iVar locals and post-increment copy loop; worse, still EBP outer index.
// Probe 3: register-qualified outer index; no change.
// Probe 4: top-declared newMax before outer i to probe register coloring.
// Probe 5: unsigned outer index probe; only changes signed branches, still EBP outer index.
// Probe 6: temporary /O1 flag probe produced too-small 150B object; removed flag.
// Probe 7: operator_new/operator_delete helper names instead of C++ operators; no register-family change.
// Probe 8: /O2 without /Oy flag; no improvement.
// Probe 9: /Ob0 flag; no improvement.
// Probe 10: /G5 flag; no improvement.
// GIVEUP: best C source still chooses EBP for outer group index and EBX for newMax, while original uses EBX for outer index and EBP for newMax with delayed EBP save. This causes broad register/prologue and loop-body drift, not accepted-drift safe.
// Retry 2026-05-24 Boss pass: 20 more probes. Revalidated baseline (170B, 50.0000% positional / 34.1176% edit, first mismatch 0). Tried declaring i before newMax, block-scoped newMax, for-loop/no-outer-if/while/goto outer loops, decompiler iVar shape, several copy-loop spellings (positive/combined/postinc), register/volatile i and newMax, self alias, top-declared j/obj, count/max locals, direct raw group_value indexing, and operator-size `(i+1)*4` form. Most stayed in the same EBP=i / EBX=newMax basin; volatile/count/max/copy-loop variants regressed broadly. No accepted_drift: remaining drift is still structural prologue/register allocation and loop-body topology.
```
<!-- end-recovered:eea2174569fb70def963 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
