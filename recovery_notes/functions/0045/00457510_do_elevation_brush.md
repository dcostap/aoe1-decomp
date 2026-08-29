# Recovery journal: 00457510 `do_elevation_brush`

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


<!-- recovered:6a1388e226a4039498c8 -->
### `9acc26143f36` `src/scratch/00457510_do_elevation_brush.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00457510 RGE_Map::do_elevation_brush
// GIVEUP 2026-05-21: best retained source is behaviorally correct and exact-sized (171B) but broad mismatch remains.
// Best validation: 171B, 89.4737% positional / 41.5205% edit, first mismatch 12.
// Tried natural for-loop, char-pointer no-division loop, while/do outer forms, parameter-reuse for minY/maxY,
// row local vs per-iteration row reload, no elevation temp, unsigned-char row pointer surface, y-local-first,
// and flags /Ob0, /O2-no-/Oy, /Oa, /O1, /G5. Parameter-reuse recovers the original first two arg loads and
// exact size, but VC5 still orders the y load after saving EDI and keeps minY in ESI instead of EDX, causing
// broad register/topology drift through the loops. Not accepted_drift-safe.
```
<!-- end-recovered:6a1388e226a4039498c8 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
