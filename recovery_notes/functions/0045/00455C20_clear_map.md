# Recovery journal: 00455C20 `clear_map`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\map.cpp`.
- Earlier recovery note: `recovery_notes/map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5b51fab0f43a31184721 -->
### `3719bc4b64cd` `src/scratch/00455C20_clear_map.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00455C20 RGE_Map::clear_map
// Source: map.cpp lines 382-410
// 136 bytes, 59 asm instructions
// __thiscall, void, params: unsigned char param_1, unsigned char param_2 (ret 8)
// Attempt 1: natural reconstruction with proper struct definitions
```
<!-- end-recovered:5b51fab0f43a31184721 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
