# Function notes: 00457C50 `save_map`

Module notes: `decomp_notes/map_module.md`.

## Recovered attempt history

<!-- recovered:84cd5a2ebf68527a5a23 -->
### `3d7708d678d3` `src/scratch/00457C50_save_map.cpp:1-48`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_Map::save_map (00457C50, map.cpp:1585-1622)
// Attempt log:
// 1 baseline: typed RGE_Map/RGE_Tile ownership, paired old/new tile formats,
// and direct zone/visibility save methods; 400B, structural mismatch.
// 2 handle local: duplicate codegen; retained the natural descriptor capture.
// 3 version-arm reversal: moved the old bulk-copy block to its late target;
// size became exact and the diff fell to 165B.
// 4 row-counter placement: initializing y inside the positive new-format arm
// after its local height pointer reached 403B with 5 differing bytes.
// 5 negated-less-than spelling: duplicate codegen.
// 6 height pointer/member split: same-size 262B diagnostic variant; rolled
// forward to the cleaner arm-local pointer shape.
// 7 y initialization before the height test: 5-byte best basin (100% shape,
// all calls/CFG/relocations exact); probes 8-10 arithmetic/pointer variants
// were codegen duplicates. Remaining drift is only old-format multiply operand
// order: original loads height then multiplies width, rebuilt reverses them.
// 8 common height pointer after the width write: old-format product became
// exact, but the loop tail swapped the y/map reload order (4 bytes remain).
// 9-10 direct-this and staged-product variants: codegen duplicates; retained
// the typed common-height form as the best period-plausible reconstruction.
// 11 hoisted x/tile declarations: codegen duplicate; restored the clean
// block-scoped form because the four-byte tail reload order did not move.
// 12 outer do-while changed to a for loop to test compiler loop-control
// scheduling at the four-byte tail; no codegen change; rolled back.
// 13 moved the outer increment into the do-while condition as ++y to test
// expression-tree scheduling at the four-byte tail; no codegen change; rolled
// back.
// 14 declared y in a canonical for loop to test scope/lifetime scheduling;
// no codegen change; rolled back.
// 15 hoisted y's declaration to function scope while keeping its branch-local
// initialization to test local lifetime and reload scheduling; no codegen
// change; rolled back.
// 16 restored source-level old-format-first ordering to test whether the
// compiler's branch layout also restores the target loop-tail load order;
// it changed the branch shape and grew the diff to 252 bytes; rolled back.
// 17 reversed the outer bound comparison to *height > y to test operand-order
// scheduling at the four-byte tail; it changed the comparison block and grew
// the diff to 6 bytes; rolled back.
// 18 no further source-backed axis remains after loop-form and scope probes;
// preserve the clean typed reconstruction for final validation.
// 19 direct this ownership for the row lookup was a codegen duplicate.
// 20 removing the explicit map alias throughout was a codegen duplicate.
// 21 moving y before the handle and map declarations was a codegen duplicate.
// 22 passing file directly instead of through handle was a codegen duplicate.
// 23 declaring width before map was a codegen duplicate.
// 24 using *width in both new-format loop bounds was a codegen duplicate.
// All six focused probes left the same four-byte y/map load-order gap; restore
// the clean source because no natural source axis remains evidence-backed.
```
<!-- end-recovered:84cd5a2ebf68527a5a23 -->
