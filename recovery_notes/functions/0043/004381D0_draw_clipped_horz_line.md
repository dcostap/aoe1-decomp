# Recovery journal: 004381D0 `draw_clipped_horz_line`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/diam_map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\diam_map.cpp`.
- Earlier recovery note: `recovery_notes/diam_map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:cabb62db876b6da832db -->
### `00492347d989` `src/scratch/004381D0_draw_clipped_horz_line.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004381D0 RGE_Diamond_Map::draw_clipped_horz_line
// Source: diam_map.cpp lines 1192-1200. 123 bytes. __thiscall, ret 14h.
//
// Attempt log:
// - probe 1: basic implementation → 75% diff (wrong arg order + reg alloc)
// - probe 2: separate clipped_p1/result locals → 33% diff
// - probe 3: inline expressions → still 33% diff
// - probe 4: fix DrawHorzLine arg order (p1 not p3) + result_x → 11.4% diff
// Remaining: 14 byte-level diffs, ALL register allocation (ESI vs EDI for
// the line pointer). Original: ESI=line, EDI=pnl_x. Rebuilt: EDI=line, ESI=clipped_left.
// VC5 register heuristic. Cannot be forced from C++. Left in scratch.
```
<!-- end-recovered:cabb62db876b6da832db -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
