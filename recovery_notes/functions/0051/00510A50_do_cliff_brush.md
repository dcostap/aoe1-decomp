# Recovery journal: 00510A50 `do_cliff_brush`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tmap.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tmap.cpp`.
- Earlier recovery note: `recovery_notes/tmap_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e5563f388151f69d96da -->
### `912332e8f578` `src/matching/00510A50_do_cliff_brush.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00510A50 do_cliff_brush (434B)
// tmap.cpp
//
// Attempt log:
// baseline: canonical reconstruction from the RGE_Map brush delegation,
// clipped /3 cliff coordinates, and the TRIBE_Map cliff-state fields.
// probe 2: reused the clipped-y local for the old-cliff fallback; this
// removed the decompiler-shaped temporary and reduced the drift to 2 bytes.
// probe 3: factored the delta bounds into shared control flow; reduced the
// remaining drift to 5 bytes and aligned all five calls and the frame-less CFG.
// probe 4: reversed the x-direction comparison operands; reduced drift to 2.
// probe 5: wrote the equal-x y comparison as old_cliff_y >= cliff_y; MATCH.
```
<!-- end-recovered:e5563f388151f69d96da -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
