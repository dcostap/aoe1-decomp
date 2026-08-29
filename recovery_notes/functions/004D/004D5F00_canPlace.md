# Recovery journal: 004D5F00 `canPlace`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiconmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiconmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1ba00afbbd9540a5dbb6 -->
### `d4bc51c85cfb` `src/scratch/004D5F00_canPlace.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004D5F00 TribeConstructionAIModule::canPlace
// Attempt log:
// 1: Natural reconstruction from packet/decompiler with local stubs and /GX for EH temp ConstructionItem; compiled close but ConstructionItem was 0x74 not 0x80, shifting fields/frame by -0xC.
// 2: Add ConstructionItem tail pad to exact 0x80: frame/offsets now match, but compiler omitted original manual temp list self-link stores.
// 3: Explicitly initialize tempLots.next/tempLots.prev to &tempLots after construction: main body 464 bytes, now only helper call context missing.
// 4: Model fallback placement helper as subobject at `[this+314h] + 0xCEC`, not direct pointer: only four FPU test-mask bytes differ.
// 5: Spell bounds checks as negated >= to get VC5 test ah,41 instead of test ah,01.
// FLAGS: config/flags/004D5F00_canPlace.rsp uses /GX for original EH frame.
```
<!-- end-recovered:1ba00afbbd9540a5dbb6 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
