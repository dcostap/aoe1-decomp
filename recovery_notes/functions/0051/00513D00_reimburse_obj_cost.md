# Recovery journal: 00513D00 `reimburse_obj_cost`

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


<!-- recovered:fd20702f70d5f0ca3c76 -->
### `5868718576a8` `src/scratch/00513D00_reimburse_obj_cost.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: register usage differs, rebuilt uses lea edx instead of add eax
// attempt 2: better reg usage but loop counter in edi, table in ebx
// attempt 3: hoist table load, counter in ebx now
// attempt 4: do/while loop, same reg alloc
// left in scratch: VC5 picks different registers (ebx counter, ebx/edx for FPU addr)
// original uses esi for counter, edi for table base, edx for FPU addr
// behavior fully correct, size matches (82 bytes), benign codegen drift
```
<!-- end-recovered:fd20702f70d5f0ca3c76 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
