# Recovery journal: 00439D80 `DibCreatePalette`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dib.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Dib.cpp`.
- Earlier recovery note: `recovery_notes/Dib_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8e49f82f12e591bb831d -->
### `7c763b452295` `src/matching/00439D80_DibCreatePalette.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00439D80 DibCreatePalette (203 bytes)
// PDB source: Dib.cpp, lines 1105-1155
//
// Canonical source reconstruction: build a LOGPALETTE from the RGBQUAD table
// immediately following the bitmap header, or ask GDI for a halftone palette
// when the bitmap has no usable color table.
// Attempt log:
// - baseline natural Windows palette reconstruction matched size, calls, and
//   the setup blocks but used the wrong bit-depth threshold and block topology.
// - positive allocation/late fallback source shape plus LPTR fixed the outer
//   block order; the remaining gap was the redundant entry-loop guard and the
//   byte cursor's base.
// - focused variant lab found exact code with `0 < colors` and a cursor at the
//   palette entry's peGreen byte; this preserves the proven +5 destination
//   anchor and RGBQUAD-to-PALETTEENTRY byte mapping.
```
<!-- end-recovered:8e49f82f12e591bb831d -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
