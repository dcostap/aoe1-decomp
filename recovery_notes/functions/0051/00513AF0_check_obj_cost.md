# Recovery journal: 00513AF0 `check_obj_cost`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tplayer.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tplayer.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:7b5e5947a9bac85bed35 -->
### `a341ac75bfb5` `src/scratch/00513AF0_check_obj_cost.cpp:1-10`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00513AF0 TRIBE_Player::check_obj_cost | tplayer.cpp:1327-1406
// Attempt log:
// - baseline used decompiler-shaped pointer/boolean plumbing and was 7 bytes too large.
// - canonicalized ownership to TRIBE_Player::object_types (+0x24), resources (+0x50),
//   and ObjectType's 6-byte cost records anchored at the amount field (+0x14A).
// - moving the loop index declaration before the amount cursor reproduces xor edi
//   before the cursor lea; the natural candidate is now exact size and 4 bytes off.
// - expression/comparison/guard spellings and a focused FPU lab did not change the
//   remaining four-byte fld-st0 versus fld-resource/fadd-st1 hunk. A resources local
//   and a named total were rejected as broad or farther codegen.
```
<!-- end-recovered:7b5e5947a9bac85bed35 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
